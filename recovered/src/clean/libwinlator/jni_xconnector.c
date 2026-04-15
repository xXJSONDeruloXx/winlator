// jni_xconnector.c — JNI bindings for com.winlator.xconnector.*
// (XConnectorEpoll, XInputStream, XOutputStream)
// Scaffolded from recovered/src/libwinlator/libwinlator.c

#include "collections.h"
#include "winlator_types.h"
#include <jni.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/un.h>
#include <netinet/in.h>

// ─────────────────────────────────────────────────────────────────────────────
// Native struct layouts (inferred from recovered binary)
// ─────────────────────────────────────────────────────────────────────────────

// XInputStream (0x48 = 72 bytes):
//   +0x00  uint32_t  fd             (socket fd)
//   +0x04  uint32_t  _pad
//   +0x08  void     *read_buf       (calloc'd ring buffer data)
//   +0x10  uint32_t  buf_cap        (total buffer capacity)
//   +0x14  uint32_t  _pad14
//   +0x18  uint32_t  buf_cap2       (mirror of buf_cap)
//   +0x1c  uint32_t  _pad1c
//   +0x20  void     *data           (active read pointer into read_buf)
//   +0x28  uint64_t  ancillary_fd
//   +0x2c  int32_t   read_pos       (read cursor into data)
//   +0x30  int32_t   data_end       (end of available data)
//   +0x34  uint32_t  _pad34
//   +0x38  IntArray  pending_fds    (size=16)
typedef struct XInputStream {
    uint32_t  fd;
    uint32_t  _pad04;
    void     *read_buf;
    uint32_t  buf_cap;
    uint32_t  _pad14;
    uint32_t  buf_cap2;
    uint32_t  _pad1c;
    void     *data;
    uint64_t  ancillary_fd;
    int32_t   read_pos;
    int32_t   data_end;
    uint32_t  _pad34;
    IntArray  pending_fds;
} XInputStream; // 0x48 = 72

// XOutputStream (0x20 = 32 bytes):
//   +0x00  int32_t   fd             (socket fd)
//   +0x04  int32_t   ancillary_fd
//   +0x08  void     *buf            (write buffer)
//   +0x10  int32_t   buf_cap
//   +0x14  int32_t   _pad14
//   +0x18  int32_t   buf_cap2
//   +0x1c  int32_t   write_pos
typedef struct XOutputStream {
    int32_t   fd;
    int32_t   ancillary_fd;
    void     *buf;
    int32_t   buf_cap;
    int32_t   _pad14;
    int32_t   buf_cap2;
    int32_t   write_pos;
} XOutputStream; // 0x20 = 32

// XConnectorEpoll (0x58 = 88 bytes): epoll-based Unix socket server
// Fields inferred from nativeAllocate/destroy/startEpollThread
typedef struct XConnectorEpoll {
    uint8_t   _pad00[12];   // +0x00 unknown
    int32_t   epoll_fd;     // +0x0c
    int32_t   server_fd;    // +0x10
    int32_t   event_fd;     // +0x14
    uint8_t   _pad18[8];    // +0x18
    uint8_t   _pad20[16];   // +0x20 (something inited by JNI env call)
    uint64_t  ring_buf_ref; // +0x30
    uint8_t   _pad38[32];   // +0x38
} XConnectorEpoll; // 0x58 = 88

// ─────────────────────────────────────────────────────────────────────────────
// XConnectorEpoll JNI
// ─────────────────────────────────────────────────────────────────────────────

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XConnectorEpoll_closeFd(JNIEnv *env, jclass cls, jint fd) {
    (void)env; (void)cls;
    if (fd >= 0) close((int)fd);
}

JNIEXPORT jlong JNICALL
Java_com_winlator_xconnector_XConnectorEpoll_nativeAllocate(
    JNIEnv *env, jobject obj, jstring socket_path, jlong ring_buf_ref)
{
    (void)env; (void)obj; (void)ring_buf_ref;
    const char *path = (*env)->GetStringUTFChars(env, socket_path, NULL);

    XConnectorEpoll *conn = (XConnectorEpoll *)calloc(1, sizeof(XConnectorEpoll));
    if (!conn) { (*env)->ReleaseStringUTFChars(env, socket_path, path); return 0; }

    conn->epoll_fd = epoll_create(10);
    if (conn->epoll_fd < 0) goto fail;

    conn->server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (conn->server_fd < 0) goto fail;

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, path, sizeof(addr.sun_path) - 1);
    unlink(addr.sun_path);

    if (bind(conn->server_fd, (struct sockaddr *)&addr,
             (socklen_t)(strlen(path) + 2)) < 0) goto fail;
    if (listen(conn->server_fd, 10) < 0) goto fail;

    conn->event_fd = (int)eventfd(0, EFD_NONBLOCK);
    if (conn->event_fd < 0) goto fail;

    struct epoll_event ev = { .events = EPOLLIN };
    ev.data.ptr = &conn->server_fd;
    epoll_ctl(conn->epoll_fd, EPOLL_CTL_ADD, conn->server_fd, &ev);
    ev.data.ptr = &conn->event_fd;
    epoll_ctl(conn->epoll_fd, EPOLL_CTL_ADD, conn->event_fd, &ev);

    conn->ring_buf_ref = (uint64_t)ring_buf_ref;
    (*env)->ReleaseStringUTFChars(env, socket_path, path);
    return (jlong)(uintptr_t)conn;

fail:
    (*env)->ReleaseStringUTFChars(env, socket_path, path);
    free(conn);
    return 0;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XConnectorEpoll_destroy(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XConnectorEpoll *conn = (XConnectorEpoll *)(uintptr_t)ptr;
    if (!conn) return;
    if (conn->epoll_fd >= 0) close(conn->epoll_fd);
    if (conn->server_fd >= 0) close(conn->server_fd);
    if (conn->event_fd >= 0)  close(conn->event_fd);
    free(conn);
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XConnectorEpoll_startEpollThread(
    JNIEnv *env, jclass cls, jlong ptr, jboolean with_input)
{
    // TODO: transplant exact epoll thread + accept/read/write logic
    (void)env; (void)cls; (void)ptr; (void)with_input;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XConnectorEpoll_stopEpollThread(
    JNIEnv *env, jclass cls, jlong ptr)
{
    // TODO: transplant stop-epoll-thread (write eventfd + pthread_join)
    (void)env; (void)cls; (void)ptr;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XConnectorEpoll_killConnection(
    JNIEnv *env, jclass cls, jlong ptr, jint client_fd)
{
    (void)env; (void)cls; (void)ptr;
    if (client_fd >= 0) close((int)client_fd);
}

// ─────────────────────────────────────────────────────────────────────────────
// XInputStream JNI  (native struct methods, param_1 = native ptr)
// ─────────────────────────────────────────────────────────────────────────────

JNIEXPORT jlong JNICALL
Java_com_winlator_xconnector_XInputStream_nativeAllocate(
    JNIEnv *env, jclass cls, jint fd, jint buf_size)
{
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)calloc(1, sizeof(XInputStream));
    if (!s) return 0;
    s->fd        = (uint32_t)fd;
    s->read_buf  = calloc((size_t)buf_size, 1);
    s->buf_cap   = (uint32_t)buf_size;
    s->buf_cap2  = (uint32_t)buf_size;
    s->data      = s->read_buf;
    return (jlong)(uintptr_t)s;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XInputStream_destroy(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    if (!s) return;
    IntArray_clear(&s->pending_fds);
    if (s->read_buf) free(s->read_buf);
    free(s);
}

JNIEXPORT jint JNICALL
Java_com_winlator_xconnector_XInputStream_available(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    return s ? (jint)(s->data_end - s->read_pos) : 0;
}

JNIEXPORT jbyte JNICALL
Java_com_winlator_xconnector_XInputStream_readByte(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    int pos = s->read_pos++;
    return (jbyte)((uint8_t *)s->data)[pos];
}

JNIEXPORT jshort JNICALL
Java_com_winlator_xconnector_XInputStream_readShort(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    uint16_t v; memcpy(&v, (char *)s->data + s->read_pos, 2); s->read_pos += 2;
    return (jshort)v;
}

JNIEXPORT jint JNICALL
Java_com_winlator_xconnector_XInputStream_readInt(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    uint32_t v; memcpy(&v, (char *)s->data + s->read_pos, 4); s->read_pos += 4;
    return (jint)v;
}

JNIEXPORT jlong JNICALL
Java_com_winlator_xconnector_XInputStream_readLong(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    uint64_t v; memcpy(&v, (char *)s->data + s->read_pos, 8); s->read_pos += 8;
    return (jlong)v;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XInputStream_skip(JNIEnv *env, jclass cls, jlong ptr, jint n) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    if (s) s->read_pos += (int32_t)n;
}

JNIEXPORT jlong JNICALL
Java_com_winlator_xconnector_XInputStream_readByteBuffer(
    JNIEnv *env, jclass cls, jlong ptr, jint n)
{
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    if (!s) return 0;
    jlong addr = (jlong)((uintptr_t)((char *)s->data + s->read_pos));
    s->read_pos += (int32_t)n;
    return addr;
}

JNIEXPORT jboolean JNICALL
Java_com_winlator_xconnector_XInputStream_readMoreData(JNIEnv *env, jclass cls, jlong ptr) {
    // TODO: transplant exact epoll-triggered socket read loop
    (void)env; (void)cls; (void)ptr;
    return JNI_FALSE;
}

JNIEXPORT jint JNICALL
Java_com_winlator_xconnector_XInputStream_getActivePosition(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    return s ? (jint)s->read_pos : 0;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XInputStream_setActivePosition(
    JNIEnv *env, jclass cls, jlong ptr, jint pos)
{
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    if (s) s->read_pos = (int32_t)pos;
}

JNIEXPORT jint JNICALL
Java_com_winlator_xconnector_XInputStream_getAncillaryFd(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XInputStream *s = (XInputStream *)(uintptr_t)ptr;
    return s ? (jint)s->ancillary_fd : -1;
}

// ─────────────────────────────────────────────────────────────────────────────
// XOutputStream JNI
// ─────────────────────────────────────────────────────────────────────────────

JNIEXPORT jlong JNICALL
Java_com_winlator_xconnector_XOutputStream_nativeAllocate(
    JNIEnv *env, jclass cls, jint fd, jint buf_size)
{
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)calloc(1, sizeof(XOutputStream));
    if (!s) return 0;
    s->fd       = (int32_t)fd;
    s->buf      = calloc((size_t)buf_size, 1);
    s->buf_cap  = (int32_t)buf_size;
    s->buf_cap2 = (int32_t)buf_size;
    return (jlong)(uintptr_t)s;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_destroy(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s) return;
    if (s->buf) free(s->buf);
    free(s);
}

JNIEXPORT jint JNICALL
Java_com_winlator_xconnector_XOutputStream_length(JNIEnv *env, jclass cls, jlong ptr) {
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    return s ? (jint)s->write_pos : 0;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_setAncillaryFd(
    JNIEnv *env, jclass cls, jlong ptr, jint fd)
{
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (s) s->ancillary_fd = (int32_t)fd;
}

static void _xout_grow(XOutputStream *s, int32_t needed) {
    while (s->buf_cap < needed) {
        s->buf_cap = s->buf_cap < 4 ? 4 : s->buf_cap * 2;
    }
    s->buf = realloc(s->buf, (size_t)s->buf_cap);
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_writeByte(JNIEnv *env, jclass cls, jlong ptr, jbyte v) {
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s) return;
    if (s->write_pos + 1 > s->buf_cap) _xout_grow(s, s->write_pos + 1);
    ((uint8_t *)s->buf)[s->write_pos++] = (uint8_t)v;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_writeShort(
    JNIEnv *env, jclass cls, jlong ptr, jshort v) {
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s) return;
    if (s->write_pos + 2 > s->buf_cap) _xout_grow(s, s->write_pos + 2);
    memcpy((char *)s->buf + s->write_pos, &v, 2); s->write_pos += 2;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_writeInt(
    JNIEnv *env, jclass cls, jlong ptr, jint v) {
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s) return;
    if (s->write_pos + 4 > s->buf_cap) _xout_grow(s, s->write_pos + 4);
    memcpy((char *)s->buf + s->write_pos, &v, 4); s->write_pos += 4;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_writeLong(
    JNIEnv *env, jclass cls, jlong ptr, jlong v) {
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s) return;
    if (s->write_pos + 8 > s->buf_cap) _xout_grow(s, s->write_pos + 8);
    memcpy((char *)s->buf + s->write_pos, &v, 8); s->write_pos += 8;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_writePad(
    JNIEnv *env, jclass cls, jlong ptr, jint n) {
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s) return;
    if (s->write_pos + n > s->buf_cap) _xout_grow(s, s->write_pos + n);
    memset((char *)s->buf + s->write_pos, 0, (size_t)n); s->write_pos += n;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_writeAt(
    JNIEnv *env, jclass cls, jlong ptr, jint offset, jlong src_ptr, jint n)
{
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s || !src_ptr) return;
    if (offset + n > s->buf_cap) _xout_grow(s, offset + n);
    memcpy((char *)s->buf + offset, (void *)(uintptr_t)src_ptr, (size_t)n);
}

JNIEXPORT jlong JNICALL
Java_com_winlator_xconnector_XOutputStream_writeByteBuffer(
    JNIEnv *env, jclass cls, jlong ptr, jint n)
{
    (void)env; (void)cls;
    XOutputStream *s = (XOutputStream *)(uintptr_t)ptr;
    if (!s) return 0;
    if (s->write_pos + n > s->buf_cap) _xout_grow(s, s->write_pos + n);
    jlong addr = (jlong)((uintptr_t)((char *)s->buf + s->write_pos));
    s->write_pos += n;
    return addr;
}

JNIEXPORT void JNICALL
Java_com_winlator_xconnector_XOutputStream_sendData(JNIEnv *env, jclass cls, jlong ptr) {
    // TODO: transplant exact sendmsg logic with ancillary fd passing
    (void)env; (void)cls; (void)ptr;
}
