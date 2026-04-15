/*
 * gd_handlers.c — GL command dispatch handlers (430 handlers)
 *
 * Each handler reads arguments from the command ArrayBuffer and calls
 * the corresponding OpenGL ES function or helper module.
 *
 * Auto-extracted from Ghidra decompilation, minimally cleaned.
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include "gladio_data.h"
#include <GLES3/gl32.h>
#include <EGL/egl.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>

/* @00123250  size=72 */

void gd_handle_glAccum(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glAccum");
  return;
}


/* @00123298  size=24 */

void gd_handle_glActiveTexture(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  GLTexture_setActiveUnit();
  return;
}


/* @001232b0  size=84 */

void gd_handle_glAlphaFunc(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  long lVar3;
  uint32_t uVar4;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getFloat(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  lVar3 = *plVar2;
  *(uint32_t *)(lVar3 + 0x5c) = uVar1;
  *(uint32_t *)(lVar3 + 0x60) = uVar4;
  return;
}


/* @00123304  size=264 */

void gd_handle_glArrayElement(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  long lVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  readVertexArrayElement(param_1,0,uVar1);
  readVertexArrayElement(param_1,1,uVar1);
  readVertexArrayElement(param_1,2,uVar1);
  readVertexArrayElement(param_1,3,uVar1);
  readVertexArrayElement(param_1,4,uVar1);
  readVertexArrayElement(param_1,5,uVar1);
  readVertexArrayElement(param_1,6,uVar1);
  readVertexArrayElement(param_1,7,uVar1);
  readVertexArrayElement(param_1,8,uVar1);
  readVertexArrayElement(param_1,9,uVar1);
  readVertexArrayElement(param_1,10,uVar1);
  plVar2 = (long *)(&currentRenderer);
  lVar3 = *plVar2;
  if (*(char *)(*(long *)(lVar3 + 0x540) + 0x22) != '\0') {
    GLRenderer_addArrayElement(lVar3,*(int *)(lVar3 + 0x5ec) + -1);
    return;
  }
  return;
}


/* @0012340c  size=56 */

void gd_handle_glAttachShader(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_attachShader(uVar1,uVar2);
  return;
}


/* @00123444  size=56 */

void gd_handle_glBegin(long param_1)

{
  uint32_t uVar1;
  uint64_t *puVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar2 = (uint64_t *)(&currentRenderer);
  GLRenderer_beginImmediate(*puVar2,uVar1);
  return;
}


/* @0012347c  size=72 */

void gd_handle_glBeginConditionalRender(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glBeginConditionalRender");
  return;
}


/* @001234c4  size=56 */

void gd_handle_glBeginQuery(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  GLQuery_begin(uVar1,uVar2);
  return;
}


/* @001234fc  size=24 */

void gd_handle_glBeginTransformFeedback(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glBeginTransformFeedback(0);
  return;
}


/* @00123514  size=68 */

void gd_handle_glBindAttribLocation(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glBindAttribLocation(uVar1,uVar2,*(long *)(param_1 + 0x78) + (long)*(int *)(param_1 + 0x6c));
  return;
}


/* @00123558  size=56 */

void gd_handle_glBindBuffer(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  GLBuffer_bind(uVar1,uVar2);
  return;
}


/* @00123590  size=80 */

void gd_handle_glBindBufferBase(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glBindBufferBase(uVar1,uVar2,uVar3);
  return;
}


/* @001235e0  size=120 */

void gd_handle_glBindBufferRange(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  int iVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  iVar4 = ArrayBuffer_getInt(param_1);
  iVar5 = ArrayBuffer_getInt(param_1);
  glBindBufferRange(uVar1,uVar2,uVar3,(long)iVar4,(long)iVar5);
  return;
}


/* @00123658  size=124 */

void gd_handle_glBindFragDataLocation(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar6 = *(long *)(param_1 + 0x78);
  iVar1 = *(int *)(param_1 + 0x6c);
  lVar4 = ShaderConverter_getProgram(uVar2);
  if (lVar4 != 0) {
    pcVar5 = strdup((char *)(lVar6 + iVar1));
    SparseArray_put(lVar4 + 8,uVar3,pcVar5);
    return;
  }
  return;
}


/* @001236d4  size=32 */

void gd_handle_glBindFragDataLocationIndexed(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glBindFragDataLocationIndexed");
  return;
}


/* @001236f4  size=56 */

void gd_handle_glBindFramebuffer(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  GLFramebuffer_bind(uVar1,uVar2);
  return;
}


/* @0012372c  size=56 */

void gd_handle_glBindProgramARB(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  ARBProgram_bind(uVar1,uVar2);
  return;
}


/* @00123764  size=80 */

void gd_handle_glBindRenderbuffer(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long *plVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar3 = (long *)(&currentRenderer);
  *(uint32_t *)(*plVar3 + 0x5a8) = uVar2;
  glBindRenderbuffer(uVar1,uVar2);
  return;
}


/* @001237b4  size=56 */

void gd_handle_glBindSampler(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glBindSampler(uVar1,uVar2);
  return;
}


/* @001237ec  size=100 */

void gd_handle_glBindTexture(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = 0xde1;
  if (((iVar1 != 0xde0) && (iVar1 != 0x84f5)) && (iVar3 = iVar1, iVar1 == 0x8c18)) {
    iVar3 = 0x8c1a;
  }
  GLTexture_bind(iVar3,uVar2);
  return;
}


/* @00123850  size=68 */

void gd_handle_glBindVertexArray(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  GLVertexArrayObject_setBound(*plVar2 + 0x398,uVar1);
  glBindVertexArray(uVar1);
  return;
}


/* @00123894  size=32 */

void gd_handle_glBitmap(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glBitmap");
  return;
}


/* @001238b4  size=104 */

void gd_handle_glBlendColor(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getFloat(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  glBlendColor(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012391c  size=24 */

void gd_handle_glBlendEquation(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glBlendEquation(0);
  return;
}


/* @00123934  size=56 */

void gd_handle_glBlendEquationSeparate(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glBlendEquationSeparate(uVar1,uVar2);
  return;
}


/* @0012396c  size=80 */

void gd_handle_glBlendEquationSeparatei(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glBlendEquationSeparatei(uVar1,uVar2,uVar3);
  return;
}


/* @001239bc  size=56 */

void gd_handle_glBlendEquationi(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glBlendEquationi(uVar1,uVar2);
  return;
}


/* @001239f4  size=56 */

void gd_handle_glBlendFunc(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glBlendFunc(uVar1,uVar2);
  return;
}


/* @00123a2c  size=96 */

void gd_handle_glBlendFuncSeparate(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  glBlendFuncSeparate(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @00123a8c  size=120 */

void gd_handle_glBlendFuncSeparatei(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  glBlendFuncSeparatei(uVar1,uVar2,uVar3,uVar4,uVar5);
  return;
}


/* @00123b04  size=80 */

void gd_handle_glBlendFunci(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glBlendFunci(uVar1,uVar2,uVar3);
  return;
}


/* @00123b54  size=228 */

void gd_handle_glBlitFramebuffer(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  uVar6 = ArrayBuffer_getInt(param_1);
  uVar7 = ArrayBuffer_getInt(param_1);
  uVar8 = ArrayBuffer_getInt(param_1);
  uVar9 = ArrayBuffer_getInt(param_1);
  uVar10 = ArrayBuffer_getInt(param_1);
  glBlitFramebuffer(uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10);
  return;
}


/* @00123c38  size=184 */

void gd_handle_glBufferData(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  long lVar5;
  uint16_t local_50;
  uint32_t local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar5 = GLBuffer_getBound(uVar2);
  if ((lVar5 != 0) && (*(long *)(lVar5 + 8) != 0)) {
    glBufferData(uVar2,(long)iVar3,*(long *)(lVar5 + 8),uVar4);
  }
  local_50 = 0x84;
  local_4e = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_50,6);
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00123cf0  size=304 */

void gd_handle_glBufferStorage(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int __fd;
  uint32_t uVar4;
  unsigned long uVar5;
  uint64_t uVar6;
  uint32_t uVar7;
  uint8_t local_134 [4];
  struct msghdr local_130;
  struct iovec local_f8;
  uint64_t local_e8;
  uint64_t local_e0;
  int local_d8;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar1 + 0x28);
  iVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = GLBuffer_getBound(iVar2);
  __fd = GLBuffer_allocateMemory(uVar6,iVar3);
  local_134[0] = 0 < __fd;
  if ((0 < __fd) && (iVar2 != 0x88ec)) {
    uVar7 = 0x88e4;
    if ((uVar5 & 0x100) != 0) {
      uVar7 = 0x88e8;
    }
    glBufferData(iVar2,(long)iVar3,0,uVar7);
  }
  local_f8.iov_base = local_134;
  local_130.msg_iov = &local_f8;
  local_130.msg_control = &local_e8;
  local_f8.iov_len = 1;
  local_130.msg_name = (void *)0x0;
  local_130.msg_namelen = 0;
  local_130.msg_iovlen = 1;
  local_130.msg_flags = 0;
  local_130.msg_controllen = 0x14;
  local_e0 = 0x100000001;
  local_e8 = 0x14;
  local_d8 = __fd;
  uVar5 = sendmsg(*(int *)(param_1 + 8),&local_130,0);
  if (0 < __fd) {
    uVar4 = close(__fd);
    uVar5 = (unsigned long)uVar4;
  }
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}


/* @00123e20  size=188 */

void gd_handle_glBufferSubData(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  uint16_t local_50;
  uint32_t local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar5 = GLBuffer_getBound(uVar2);
  if ((lVar5 != 0) && (*(long *)(lVar5 + 8) != 0)) {
    glBufferSubData(uVar2,(long)iVar3,(long)iVar4,*(long *)(lVar5 + 8) + (long)iVar3);
  }
  local_50 = 0x86;
  local_4e = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_50,6);
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00123edc  size=52 */

void gd_handle_glCallList(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glCallList");
  return;
}


/* @00123f10  size=32 */

void gd_handle_glCallLists(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glCallLists");
  return;
}


/* @00123f30  size=140 */

void gd_handle_glCheckFramebufferStatus(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint32_t local_34;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34 = glCheckFramebufferStatus(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x89;
  local_2e = 4;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,&local_34,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00123fbc  size=88 */

void gd_handle_glClampColor(long param_1)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  if (iVar1 == 0x891c) {
    plVar3 = (long *)(&currentRenderer);
    *(bool *)(*plVar3 + 0x390) = iVar2 == 1;
  }
  return;
}


/* @00124014  size=24 */

void gd_handle_glClear(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glClear(0);
  return;
}


/* @0012402c  size=88 */

void gd_handle_glClearAccum(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glClearAccum");
  return;
}


/* @00124084  size=104 */

void gd_handle_glClearBufferfi(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glClearBufferfi(uVar4,uVar1,uVar2,uVar3);
  return;
}


/* @001240ec  size=32 */

void gd_handle_glClearBufferfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glClearBufferfv");
  return;
}


/* @0012410c  size=32 */

void gd_handle_glClearBufferiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glClearBufferiv");
  return;
}


/* @0012412c  size=32 */

void gd_handle_glClearBufferuiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glClearBufferuiv");
  return;
}


/* @0012414c  size=104 */

void gd_handle_glClearColor(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getFloat(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  glClearColor(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @001241b4  size=24 */

void gd_handle_glClearDepthf(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  glClearDepthf(0);
  return;
}


/* @001241cc  size=52 */

void gd_handle_glClearIndex(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glClearIndex");
  return;
}


/* @00124200  size=24 */

void gd_handle_glClearStencil(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glClearStencil(0);
  return;
}


/* @00124218  size=56 */

void gd_handle_glClientActiveTexture(long param_1)

{
  char cVar1;
  long *plVar2;
  
  cVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  *(char *)(*plVar2 + 0x399) = cVar1 + '@';
  return;
}


/* @00124250  size=184 */

void gd_handle_glClientWaitSync(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  unsigned long uVar5;
  uint32_t local_44;
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar3 = ArrayBuffer_getLong(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getLong(param_1 + 0x68);
  local_44 = glClientWaitSync(uVar3,uVar2,uVar4);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x96;
  local_3e = 4;
  uVar5 = RingBuffer_write(uVar3,&local_40,6);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar3,&local_44,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00124308  size=32 */

void gd_handle_glClipPlane(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glClipPlane");
  return;
}


/* @00124328  size=196 */

void gd_handle_glColor4f(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t local_58;
  uint32_t uStack_54;
  uint32_t local_50;
  uint32_t uStack_4c;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  uVar6 = ArrayBuffer_getFloat(param_1);
  uVar7 = ArrayBuffer_getFloat(param_1);
  plVar2 = (long *)(&currentRenderer);
  lVar3 = *plVar2;
  *(uint32_t *)(lVar3 + 0xac) = uVar4;
  *(uint32_t *)(lVar3 + 0xb0) = uVar5;
  *(uint32_t *)(lVar3 + 0xb4) = uVar6;
  *(uint32_t *)(lVar3 + 0xb8) = uVar7;
  *(int *)(lVar3 + 0x604) = *(int *)(lVar3 + 0x604) + 1;
  if (*(char *)(lVar3 + 0x4c) != '\0') {
    local_58 = uVar4;
    uStack_54 = uVar5;
    local_50 = uVar6;
    uStack_4c = uVar7;
    GLRenderer_setMaterialParams
              (lVar3,*(uint32_t *)(lVar3 + 0x50),*(uint32_t *)(lVar3 + 0x54),&local_58);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001243ec  size=96 */

void gd_handle_glColorMask(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_get(param_1);
  uVar2 = ArrayBuffer_get(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_get(param_1);
  glColorMask(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012444c  size=120 */

void gd_handle_glColorMaski(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_get(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_get(param_1);
  uVar5 = ArrayBuffer_get(param_1);
  glColorMaski(uVar1,uVar2,uVar3,uVar4,uVar5);
  return;
}


/* @001244c4  size=72 */

void gd_handle_glColorMaterial(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long *plVar3;
  long lVar4;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar3 = (long *)(&currentRenderer);
  lVar4 = *plVar3;
  *(uint32_t *)(lVar4 + 0x50) = uVar1;
  *(uint32_t *)(lVar4 + 0x54) = uVar2;
  return;
}


/* @0012450c  size=228 */

void gd_handle_glColorPointer(long param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  short sVar7;
  long lVar8;
  
  param_1 = param_1 + 0x68;
  cVar2 = ArrayBuffer_get(param_1);
  iVar3 = ArrayBuffer_getInt(param_1);
  iVar4 = ArrayBuffer_getInt(param_1);
  sVar7 = (short)iVar4;
  plVar5 = (long *)(&currentRenderer);
  lVar8 = *plVar5;
  GLVertexArrayObject_setAttribState(lVar8 + 0x398,1,1,0);
  lVar6 = *(long *)(lVar8 + 0x540);
  bVar1 = false;
  *(int *)(lVar6 + 0x34) = (int)cVar2;
  *(int *)(lVar6 + 0x2c) = iVar3;
  if ((iVar3 != 0x1406) && (iVar3 != 0x140b)) {
    bVar1 = *(long *)(lVar8 + 0x560) != 0;
  }
  *(bool *)(lVar6 + 0x28) = bVar1;
  if ((iVar4 < 1) && (*(long *)(lVar8 + 0x560) == 0)) {
    if (iVar3 - 0x1400U < 0xb) {
      sVar7 = (short)*(uint32_t *)(&DAT_001159d8 + (long)(int)(iVar3 - 0x1400U) * 4);
    }
    else {
      sVar7 = 0;
    }
    sVar7 = sVar7 * cVar2;
  }
  *(short *)(lVar6 + 0x40) = sVar7;
  return;
}


/* @001245f0  size=40 */

void gd_handle_glCompileShader(long param_1)

{
  long lVar1;
  
  ArrayBuffer_getInt(param_1 + 0x68);
  lVar1 = ShaderConverter_getShader();
  if (lVar1 != 0) {
    *(uint8_t *)(lVar1 + 0x7a) = 1;
  }
  return;
}


/* @00124618  size=660 */

void gd_handle_glCompressedTexImage2D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  int iVar11;
  uint32_t uVar12;
  long lVar13;
  void *pvVar14;
  unsigned long uVar15;
  void *__ptr;
  uint16_t local_70;
  uint32_t local_6e;
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar3 + 0x28);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar8 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar9 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar10 = ArrayBuffer_getInt(param_1 + 0x68);
  if ((int)uVar10 < 1) {
    pvVar14 = (void *)0x0;
  }
  else {
    lVar13 = GLBuffer_getBound(0x88ec);
    if (lVar13 == 0) {
      uVar15 = RingBuffer_waitForRead(*(uint64_t *)(param_1 + 0x18),uVar10);
      if ((uVar15 & 1) == 0) {
        iVar11 = 0;
        __ptr = (void *)0x0;
        pvVar14 = (void *)0x0;
      }
      else {
        uVar12 = RingBuffer_getHead(*(uint64_t *)(param_1 + 0x18));
        lVar13 = *(long *)(param_1 + 0x18);
        uVar2 = *(uint32_t *)(lVar13 + 0x28);
        uVar1 = uVar2 - 1 & uVar12;
        if (uVar2 < uVar1 + uVar10) {
          pvVar14 = malloc((unsigned long)uVar10);
          uVar2 = uVar2 - uVar1;
          memcpy(pvVar14,(void *)(*(long *)(lVar13 + 0x18) + (unsigned long)uVar1),(unsigned long)uVar2);
          memcpy((void *)((long)pvVar14 + (unsigned long)uVar2),*(void **)(*(long *)(param_1 + 0x18) + 0x18)
                 ,(unsigned long)(uVar10 - uVar2));
          __ptr = pvVar14;
        }
        else {
          __ptr = (void *)0x0;
          pvVar14 = (void *)(*(long *)(lVar13 + 0x18) + (unsigned long)uVar1);
        }
        iVar11 = uVar12 + uVar10;
      }
      pvVar14 = (void *)decompressTexImage2D
                                  (uVar6,uVar7,uVar8,pvVar14,*(uint64_t *)(param_1 + 0x98));
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      if (iVar11 != 0) {
        RingBuffer_setHead(*(uint64_t *)(param_1 + 0x18),iVar11);
      }
    }
    else {
      iVar11 = ArrayBuffer_getInt(param_1 + 0x68);
      pvVar14 = (void *)decompressTexImage2D
                                  (uVar6,uVar7,uVar8,*(long *)(lVar13 + 8) + (long)iVar11,
                                   *(uint64_t *)(param_1 + 0x98));
      local_70 = 0x9e;
      local_6e = 0;
      RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_70,6);
    }
  }
  iVar11 = 0xde1;
  if (((iVar4 != 0xde0) && (iVar4 != 0x84f5)) && (iVar11 = iVar4, iVar4 == 0x8c18)) {
    iVar11 = 0x8c1a;
  }
  glTexImage2D(iVar11,iVar5,0x80e1,uVar7,uVar8,uVar9,0x80e1,0x1401,pvVar14);
  if (pvVar14 != (void *)0x0) {
    free(pvVar14);
  }
  lVar13 = GLTexture_getBound(iVar11);
  if ((lVar13 != 0) && (iVar5 == 0)) {
    *(short *)(lVar13 + 0xc) = (short)uVar7;
    *(short *)(lVar13 + 0xe) = (short)uVar8;
    *(uint32_t *)(lVar13 + 8) = uVar6;
    if (*(char *)(lVar13 + 0x10) != '\0') {
      glGenerateMipmap(iVar11);
    }
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001248ac  size=620 */

void gd_handle_glCompressedTexSubImage2D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  int iVar12;
  uint32_t uVar13;
  long lVar14;
  void *pvVar15;
  unsigned long uVar16;
  void *__ptr;
  uint16_t local_70;
  uint32_t local_6e;
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar3 + 0x28);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar8 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar9 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar10 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar11 = ArrayBuffer_getInt(param_1 + 0x68);
  if ((int)uVar11 < 1) {
    pvVar15 = (void *)0x0;
  }
  else {
    lVar14 = GLBuffer_getBound(0x88ec);
    if (lVar14 == 0) {
      uVar16 = RingBuffer_waitForRead(*(uint64_t *)(param_1 + 0x18),uVar11);
      if ((uVar16 & 1) == 0) {
        iVar12 = 0;
        __ptr = (void *)0x0;
        pvVar15 = (void *)0x0;
      }
      else {
        uVar13 = RingBuffer_getHead(*(uint64_t *)(param_1 + 0x18));
        lVar14 = *(long *)(param_1 + 0x18);
        uVar2 = *(uint32_t *)(lVar14 + 0x28);
        uVar1 = uVar2 - 1 & uVar13;
        if (uVar2 < uVar1 + uVar11) {
          pvVar15 = malloc((unsigned long)uVar11);
          uVar2 = uVar2 - uVar1;
          memcpy(pvVar15,(void *)(*(long *)(lVar14 + 0x18) + (unsigned long)uVar1),(unsigned long)uVar2);
          memcpy((void *)((long)pvVar15 + (unsigned long)uVar2),*(void **)(*(long *)(param_1 + 0x18) + 0x18)
                 ,(unsigned long)(uVar11 - uVar2));
          __ptr = pvVar15;
        }
        else {
          __ptr = (void *)0x0;
          pvVar15 = (void *)(*(long *)(lVar14 + 0x18) + (unsigned long)uVar1);
        }
        iVar12 = uVar13 + uVar11;
      }
      pvVar15 = (void *)decompressTexImage2D
                                  (uVar10,uVar8,uVar9,pvVar15,*(uint64_t *)(param_1 + 0x98));
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      if (iVar12 != 0) {
        RingBuffer_setHead(*(uint64_t *)(param_1 + 0x18),iVar12);
      }
    }
    else {
      iVar12 = ArrayBuffer_getInt(param_1 + 0x68);
      pvVar15 = (void *)decompressTexImage2D
                                  (uVar10,uVar8,uVar9,*(long *)(lVar14 + 8) + (long)iVar12,
                                   *(uint64_t *)(param_1 + 0x98));
      local_70 = 0x9f;
      local_6e = 0;
      RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_70,6);
    }
  }
  iVar12 = 0xde1;
  if (((iVar4 != 0xde0) && (iVar4 != 0x84f5)) && (iVar12 = iVar4, iVar4 == 0x8c18)) {
    iVar12 = 0x8c1a;
  }
  glTexSubImage2D(iVar12,uVar5,uVar6,uVar7,uVar8,uVar9,0x80e1,0x1401,pvVar15);
  if (pvVar15 != (void *)0x0) {
    free(pvVar15);
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00124b18  size=120 */

void gd_handle_glCopyBufferSubData(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  iVar3 = ArrayBuffer_getInt(param_1);
  iVar4 = ArrayBuffer_getInt(param_1);
  iVar5 = ArrayBuffer_getInt(param_1);
  glCopyBufferSubData(uVar1,uVar2,(long)iVar3,(long)iVar4,(long)iVar5);
  return;
}


/* @00124b90  size=96 */

void gd_handle_glCopyPixels(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glCopyPixels");
  return;
}


/* @00124bf0  size=176 */

void gd_handle_glCopyTexImage2D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  uVar6 = ArrayBuffer_getInt(param_1);
  uVar7 = ArrayBuffer_getInt(param_1);
  uVar8 = ArrayBuffer_getInt(param_1);
  glCopyTexImage2D(uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8);
  return;
}


/* @00124ca0  size=176 */

void gd_handle_glCopyTexSubImage2D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  uVar6 = ArrayBuffer_getInt(param_1);
  uVar7 = ArrayBuffer_getInt(param_1);
  uVar8 = ArrayBuffer_getInt(param_1);
  glCopyTexSubImage2D(uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8);
  return;
}


/* @00124d50  size=212 */

void gd_handle_glCopyTexSubImage3D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  uVar6 = ArrayBuffer_getInt(param_1);
  uVar7 = ArrayBuffer_getInt(param_1);
  uVar8 = ArrayBuffer_getInt(param_1);
  uVar9 = ArrayBuffer_getInt(param_1);
  glCopyTexSubImage3D(uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);
  return;
}


/* @00124e24  size=132 */

void gd_handle_glCreateProgram(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint32_t local_34;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  local_34 = ShaderConverter_createProgram();
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0xa5;
  local_2e = 4;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,&local_34,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00124ea8  size=140 */

void gd_handle_glCreateShader(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint32_t local_34;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34 = ShaderConverter_createShader();
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0xa6;
  local_2e = 4;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,&local_34,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00124f34  size=24 */

void gd_handle_glCullFace(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glCullFace(0);
  return;
}


/* @00124f4c  size=84 */

void gd_handle_glDeleteBuffers(long param_1)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  unsigned long uVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = (unsigned long)uVar1;
  puVar2 = (uint32_t *)ArrayBuffer_getBytes(param_1 + 0x68,uVar1 << 2);
  if (0 < (int)uVar1) {
    do {
      GLBuffer_delete(*puVar2);
      uVar3 = uVar3 - 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 != 0);
  }
  return;
}


/* @00124fa0  size=84 */

void gd_handle_glDeleteFramebuffers(long param_1)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  unsigned long uVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = (unsigned long)uVar1;
  puVar2 = (uint32_t *)ArrayBuffer_getBytes(param_1 + 0x68,uVar1 << 2);
  if (0 < (int)uVar1) {
    do {
      GLFramebuffer_delete(*puVar2);
      uVar3 = uVar3 - 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 != 0);
  }
  return;
}


/* @00124ff4  size=72 */

void gd_handle_glDeleteLists(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glDeleteLists");
  return;
}


/* @0012503c  size=52 */

void gd_handle_glDeleteObjectARB(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glDeleteObjectARB");
  return;
}


/* @00125070  size=80 */

void gd_handle_glDeleteProgram(long param_1)

{
  int iVar1;
  long *plVar2;
  int *piVar3;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  piVar3 = *(int **)(*plVar2 + 0x560);
  if ((piVar3 != (int *)0x0) && (*piVar3 == iVar1)) {
    *(uint64_t *)(*plVar2 + 0x560) = 0;
  }
  ShaderConverter_deleteProgram(iVar1);
  return;
}


/* @001250c0  size=84 */

void gd_handle_glDeleteProgramsARB(long param_1)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  unsigned long uVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = (unsigned long)uVar1;
  puVar2 = (uint32_t *)ArrayBuffer_getBytes(param_1 + 0x68,uVar1 << 2);
  if (0 < (int)uVar1) {
    do {
      ARBProgram_delete(*puVar2);
      uVar3 = uVar3 - 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 != 0);
  }
  return;
}


/* @00125114  size=84 */

void gd_handle_glDeleteQueries(long param_1)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  unsigned long uVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = (unsigned long)uVar1;
  puVar2 = (uint32_t *)ArrayBuffer_getBytes(param_1 + 0x68,uVar1 << 2);
  if (0 < (int)uVar1) {
    do {
      GLQuery_delete(*puVar2);
      uVar3 = uVar3 - 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 != 0);
  }
  return;
}


/* @00125168  size=132 */

void gd_handle_glDeleteRenderbuffers(long param_1)

{
  uint32_t uVar1;
  int *piVar2;
  long *plVar3;
  unsigned long uVar4;
  int *piVar5;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  piVar2 = (int *)ArrayBuffer_getBytes(param_1 + 0x68,uVar1 << 2);
  if (0 < (int)uVar1) {
    plVar3 = (long *)(&currentRenderer);
    uVar4 = (unsigned long)uVar1;
    piVar5 = piVar2;
    do {
      if (*piVar5 == *(int *)(*plVar3 + 0x5a8)) {
        *(uint32_t *)(*plVar3 + 0x5a8) = 0;
        break;
      }
      uVar4 = uVar4 - 1;
      piVar5 = piVar5 + 1;
    } while (uVar4 != 0);
  }
  glDeleteRenderbuffers(uVar1,piVar2);
  return;
}


/* @001251ec  size=60 */

void gd_handle_glDeleteSamplers(long param_1)

{
  int iVar1;
  uint64_t uVar2;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getBytes(param_1 + 0x68,iVar1 << 2);
  glDeleteSamplers(iVar1,uVar2);
  return;
}


/* @00125228  size=24 */

void gd_handle_glDeleteShader(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_deleteShader();
  return;
}


/* @00125240  size=24 */

void gd_handle_glDeleteSync(long param_1)

{
  ArrayBuffer_getLong(param_1 + 0x68);
  glDeleteSync(0);
  return;
}


/* @00125258  size=84 */

void gd_handle_glDeleteTextures(long param_1)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  unsigned long uVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = (unsigned long)uVar1;
  puVar2 = (uint32_t *)ArrayBuffer_getBytes(param_1 + 0x68,uVar1 << 2);
  if (0 < (int)uVar1) {
    do {
      GLTexture_delete(*puVar2);
      uVar3 = uVar3 - 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 != 0);
  }
  return;
}


/* @001252ac  size=136 */

void gd_handle_glDeleteVertexArrays(long param_1)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  long *plVar3;
  unsigned long uVar4;
  uint32_t *puVar5;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar2 = (uint32_t *)ArrayBuffer_getBytes(param_1 + 0x68,uVar1 << 2);
  if (0 < (int)uVar1) {
    uVar4 = (unsigned long)uVar1;
    puVar5 = puVar2;
    do {
      plVar3 = (long *)(&currentRenderer);
      GLVertexArrayObject_delete(*plVar3 + 0x398,*puVar5);
      uVar4 = uVar4 - 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 != 0);
  }
  glDeleteVertexArrays(uVar1,puVar2);
  return;
}


/* @00125334  size=24 */

void gd_handle_glDepthFunc(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glDepthFunc(0);
  return;
}


/* @0012534c  size=24 */

void gd_handle_glDepthMask(long param_1)

{
  ArrayBuffer_get(param_1 + 0x68);
  glDepthMask(0);
  return;
}


/* @00125364  size=64 */

void gd_handle_glDepthRangef(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getFloat(param_1 + 0x68);
  uVar2 = ArrayBuffer_getFloat(param_1 + 0x68);
  glDepthRangef(uVar1,uVar2);
  return;
}


/* @001253a4  size=56 */

void gd_handle_glDetachShader(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_detachShader(uVar1,uVar2);
  return;
}


/* @001253dc  size=64 */

void gd_handle_glDisable(long param_1)

{
  uint32_t uVar1;
  uint64_t *puVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar2 = (uint64_t *)(&currentRenderer);
  GLRenderer_setCapabilityState(*puVar2,uVar1,0,0xffffffff);
  return;
}


/* @0012541c  size=68 */

void gd_handle_glDisableClientState(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  GLVertexArrayObject_setAttribState(*plVar2 + 0x398,uVar1,0,0);
  return;
}


/* @00125460  size=76 */

void gd_handle_glDisableVertexAttribArray(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  GLVertexArrayObject_setAttribState(*plVar2 + 0x398,uVar1,0,0);
  glDisableVertexAttribArray(uVar1);
  return;
}


/* @001254ac  size=80 */

void gd_handle_glDisablei(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t *puVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setCapabilityState(*puVar3,uVar1,0,uVar2);
  return;
}


/* @001254fc  size=80 */

void gd_handle_glDispatchCompute(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glDispatchCompute");
  return;
}


/* @0012554c  size=52 */

void gd_handle_glDispatchComputeIndirect(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glDispatchComputeIndirect");
  return;
}


/* @00125580  size=132 */

void gd_handle_glDrawArrays(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  uVar4 = readUnboundVertexArrays(param_1,uVar1,uVar3,0,0);
  if ((uVar4 & 1) != 0) {
    return;
  }
  glDrawArrays(uVar1,uVar2,uVar3);
  return;
}


/* @00125604  size=160 */

void gd_handle_glDrawArraysInstanced(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  unsigned long uVar5;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  uVar5 = readUnboundVertexArrays(param_1,uVar1,uVar3,0,0);
  if ((uVar5 & 1) != 0) {
    return;
  }
  glDrawArraysInstanced(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @001256a4  size=56 */

void gd_handle_glDrawBuffer(long param_1)

{
  uint32_t uVar1;
  uint64_t *puVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar2 = (uint64_t *)(&currentRenderer);
  GLRenderer_setDrawBuffer(*puVar2,uVar1);
  return;
}


/* @001256dc  size=60 */

void gd_handle_glDrawBuffers(long param_1)

{
  int iVar1;
  uint64_t uVar2;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getBytes(param_1 + 0x68,iVar1 << 2);
  GLFramebuffer_setDrawBuffers(iVar1,uVar2);
  return;
}


/* @00125718  size=176 */

void gd_handle_glDrawElements(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  unsigned long uVar5;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  local_50 = 0;
  uVar5 = readUnboundVertexArrays(param_1,uVar2,uVar3,&local_50,uVar4);
  if ((uVar5 & 1) == 0) {
    glDrawElements(uVar2,uVar3,uVar4,local_50);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001257c8  size=192 */

void gd_handle_glDrawElementsBaseVertex(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  unsigned long uVar6;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  local_50 = 0;
  uVar6 = readUnboundVertexArrays(param_1,uVar2,uVar3,&local_50,uVar4);
  if ((uVar6 & 1) == 0) {
    glDrawElementsBaseVertex(uVar2,uVar3,uVar4,local_50,uVar5);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00125888  size=192 */

void gd_handle_glDrawElementsInstanced(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  unsigned long uVar6;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  local_50 = 0;
  uVar6 = readUnboundVertexArrays(param_1,uVar2,uVar3,&local_50,uVar4);
  if ((uVar6 & 1) == 0) {
    glDrawElementsInstanced(uVar2,uVar3,uVar4,local_50,uVar5);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00125948  size=216 */

void gd_handle_glDrawElementsInstancedBaseVertex(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  unsigned long uVar7;
  uint64_t local_60;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  local_60 = 0;
  uVar7 = readUnboundVertexArrays(param_1,uVar2,uVar3,&local_60,uVar4);
  if ((uVar7 & 1) == 0) {
    glDrawElementsInstancedBaseVertex(uVar2,uVar3,uVar4,local_60,uVar5,uVar6);
  }
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00125a20  size=432 */

void gd_handle_glDrawPixels(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  void *__dest;
  uint64_t *puVar10;
  long lVar11;
  void *pvVar12;
  
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  if ((iVar7 == 0) ||
     (uVar9 = RingBuffer_waitForRead(*(uint64_t *)(param_1 + 0x18),iVar7), (uVar9 & 1) == 0)) {
    puVar10 = (uint64_t *)(&currentRenderer);
    GLRenderer_drawPixels(*puVar10,uVar3,uVar4,uVar5,uVar6,0);
    return;
  }
  uVar8 = RingBuffer_getHead(*(uint64_t *)(param_1 + 0x18));
  lVar11 = *(long *)(param_1 + 0x18);
  uVar2 = *(uint32_t *)(lVar11 + 0x28);
  uVar1 = uVar2 - 1 & uVar8;
  if (uVar2 < uVar1 + iVar7) {
    __dest = malloc((long)iVar7);
    uVar2 = uVar2 - uVar1;
    memcpy(__dest,(void *)(*(long *)(lVar11 + 0x18) + (unsigned long)uVar1),(unsigned long)uVar2);
    memcpy((void *)((long)__dest + (unsigned long)uVar2),*(void **)(*(long *)(param_1 + 0x18) + 0x18),
           (unsigned long)(iVar7 - uVar2));
    pvVar12 = __dest;
  }
  else {
    __dest = (void *)0x0;
    pvVar12 = (void *)(*(long *)(lVar11 + 0x18) + (unsigned long)uVar1);
  }
  puVar10 = (uint64_t *)(&currentRenderer);
  GLRenderer_drawPixels(*puVar10,uVar3,uVar4,uVar5,uVar6,pvVar12);
  if (__dest != (void *)0x0) {
    free(__dest);
  }
  if (uVar8 + iVar7 != 0) {
    RingBuffer_setHead(*(uint64_t *)(param_1 + 0x18),uVar8 + iVar7);
    return;
  }
  return;
}


/* @00125bd0  size=216 */

void gd_handle_glDrawRangeElements(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  unsigned long uVar7;
  uint64_t local_60;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  local_60 = 0;
  uVar7 = readUnboundVertexArrays(param_1,uVar2,uVar5,&local_60,uVar6);
  if ((uVar7 & 1) == 0) {
    glDrawRangeElements(uVar2,uVar3,uVar4,uVar5,uVar6,local_60);
  }
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00125ca8  size=232 */

void gd_handle_glDrawRangeElementsBaseVertex(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  unsigned long uVar8;
  uint64_t local_60;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_updateBoundProgram();
  local_60 = 0;
  uVar8 = readUnboundVertexArrays(param_1,uVar2,uVar5,&local_60,uVar6);
  if ((uVar8 & 1) == 0) {
    glDrawRangeElementsBaseVertex(uVar2,uVar3,uVar4,uVar5,uVar6,local_60,uVar7);
  }
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00125d90  size=52 */

void gd_handle_glEdgeFlag(long param_1)

{
  ArrayBuffer_get(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glEdgeFlag");
  return;
}


/* @00125dc4  size=32 */

void gd_handle_glEdgeFlagPointer(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glEdgeFlagPointer");
  return;
}


/* @00125de4  size=32 */

void gd_handle_glEdgeFlagv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glEdgeFlagv");
  return;
}


/* @00125e04  size=64 */

void gd_handle_glEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t *puVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar2 = (uint64_t *)(&currentRenderer);
  GLRenderer_setCapabilityState(*puVar2,uVar1,1,0xffffffff);
  return;
}


/* @00125e44  size=68 */

void gd_handle_glEnableClientState(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  GLVertexArrayObject_setAttribState(*plVar2 + 0x398,uVar1,1,0);
  return;
}


/* @00125e88  size=24 */

void gd_handle_glEnableVertexAttribArray(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glEnableVertexAttribArray(0);
  return;
}


/* @00125ea0  size=80 */

void gd_handle_glEnablei(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t *puVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setCapabilityState(*puVar3,uVar1,1,uVar2);
  return;
}


/* @00125ef0  size=4 */

void gd_handle_glEnd(void)

{
  readCommandBuffer();
  return;
}


/* @00125ef4  size=32 */

void gd_handle_glEndConditionalRender(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glEndConditionalRender");
  return;
}


/* @00125f14  size=32 */

void gd_handle_glEndList(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glEndList");
  return;
}


/* @00125f34  size=24 */

void gd_handle_glEndQuery(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  GLQuery_end();
  return;
}


/* @00125f4c  size=4 */

void gd_handle_glEndTransformFeedback(void)

{
  glEndTransformFeedback();
  return;
}


/* @00125f50  size=72 */

void gd_handle_glEvalCoord2f(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glEvalCoord2f");
  return;
}


/* @00125f98  size=80 */

void gd_handle_glEvalMesh1(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glEvalMesh1");
  return;
}


/* @00125fe8  size=96 */

void gd_handle_glEvalMesh2(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glEvalMesh2");
  return;
}


/* @00126048  size=52 */

void gd_handle_glEvalPoint1(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glEvalPoint1");
  return;
}


/* @0012607c  size=72 */

void gd_handle_glEvalPoint2(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glEvalPoint2");
  return;
}


/* @001260c4  size=32 */

void gd_handle_glFeedbackBuffer(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glFeedbackBuffer");
  return;
}


/* @001260e4  size=168 */

void gd_handle_glFenceSync(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  uint64_t local_48;
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  local_48 = glFenceSync(uVar2,uVar3);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0xdc;
  local_3e = 8;
  uVar4 = RingBuffer_write(uVar5,&local_40,6);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar5,&local_48,8);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012618c  size=100 */

void gd_handle_glFinish(long param_1)

{
  long lVar1;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  glFinish();
  local_30 = 0xdd;
  local_2e = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_30,6);
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001261f0  size=4 */

void gd_handle_glFlush(void)

{
  glFlush();
  return;
}


/* @001261f4  size=236 */

void gd_handle_glFlushMappedBufferRange(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  void *__dest;
  uint16_t local_60;
  uint32_t local_5e;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar5 = GLBuffer_getBound(uVar2);
  if ((lVar5 != 0) && (*(long *)(lVar5 + 8) != 0)) {
    __dest = (void *)glMapBufferRange(uVar2,(long)iVar3,(long)iVar4,0x22);
    if (__dest != (void *)0x0) {
      memcpy(__dest,(void *)(*(long *)(lVar5 + 8) + (long)iVar3),(long)iVar4);
      glUnmapBuffer(uVar2);
    }
  }
  local_60 = 0xdf;
  local_5e = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_60,6);
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001262e0  size=32 */

void gd_handle_glFogCoordPointer(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glFogCoordPointer");
  return;
}


/* @00126300  size=52 */

void gd_handle_glFogCoordf(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glFogCoordf");
  return;
}


/* @00126334  size=128 */

void gd_handle_glFogf(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint64_t *puVar3;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  local_3c = ArrayBuffer_getFloat(param_1 + 0x68);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setFogParams(*puVar3,uVar2,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001263b4  size=296 */

void gd_handle_glFogfv(long param_1)

{
  int iVar1;
  uint64_t *puVar2;
  uint64_t uVar3;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  if (iVar1 < 0x1204) {
    if (iVar1 < 0x1200) {
      if ((iVar1 == 0xb66) || (iVar1 == 0x1004)) goto LAB_00126478;
    }
    else if ((iVar1 - 0x1200U < 3) || (iVar1 == 0x1203)) {
LAB_00126478:
      uVar3 = 0x10;
      goto LAB_0012647c;
    }
  }
  else {
    if (iVar1 < 0x2201) {
      if (iVar1 == 0x1204) {
LAB_001264cc:
        uVar3 = 0xc;
        goto LAB_0012647c;
      }
      if ((iVar1 != 0x1600) && (iVar1 != 0x1602)) goto LAB_001264c4;
      goto LAB_00126478;
    }
    if (iVar1 < 0x8e73) {
      if (iVar1 == 0x2201) goto LAB_00126478;
      if (iVar1 == 0x8129) goto LAB_001264cc;
    }
    else {
      if (iVar1 == 0x8e73) {
        uVar3 = 8;
        goto LAB_0012647c;
      }
      if (iVar1 == 0x8e74) goto LAB_00126478;
    }
  }
LAB_001264c4:
  uVar3 = 4;
LAB_0012647c:
  uVar3 = ArrayBuffer_getBytes(param_1 + 0x68,uVar3);
  puVar2 = (uint64_t *)(&currentRenderer);
  GLRenderer_setFogParams(*puVar2,iVar1,uVar3);
  return;
}


/* @001264dc  size=100 */

void gd_handle_glFramebufferRenderbuffer(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  GLFramebuffer_setAttachment(uVar1,uVar2,uVar3,uVar4,0);
  return;
}


/* @00126540  size=112 */

void gd_handle_glFramebufferTexture(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = GLTexture_getType(uVar3);
  GLFramebuffer_setAttachment(uVar1,uVar2,uVar5,uVar3,uVar4);
  return;
}


/* @001265b0  size=164 */

void gd_handle_glFramebufferTexture2D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  iVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  iVar6 = 0xde1;
  if (((iVar3 != 0xde0) && (iVar3 != 0x84f5)) && (iVar6 = iVar3, iVar3 == 0x8c18)) {
    iVar6 = 0x8c1a;
  }
  GLFramebuffer_setAttachment(uVar1,uVar2,iVar6,uVar4,uVar5);
  return;
}


/* @00126654  size=176 */

void gd_handle_glFramebufferTexture3D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  iVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  iVar6 = 0xde1;
  if (((iVar3 != 0xde0) && (iVar3 != 0x84f5)) && (iVar6 = iVar3, iVar3 == 0x8c18)) {
    iVar6 = 0x8c1a;
  }
  GLFramebuffer_setAttachment(uVar1,uVar2,iVar6,uVar4,uVar5);
  return;
}


/* @00126704  size=128 */

void gd_handle_glFramebufferTextureLayer(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  uVar5 = GLTexture_getType(uVar3);
  GLFramebuffer_setAttachment(uVar1,uVar2,uVar5,uVar3,uVar4);
  return;
}


/* @00126784  size=24 */

void gd_handle_glFrontFace(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glFrontFace(0);
  return;
}


/* @0012679c  size=344 */

void gd_handle_glFrustum(long param_1)

{
  long lVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  uint64_t *puVar8;
  uint64_t uVar9;
  float fVar10;
  float fVar11;
  float local_98 [6];
  uint64_t local_80;
  float local_78;
  float fStack_74;
  float local_70;
  uint64_t local_6c;
  uint32_t local_64;
  float local_60;
  uint32_t local_5c;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  dVar2 = (double)ArrayBuffer_getDouble(param_1);
  dVar3 = (double)ArrayBuffer_getDouble(param_1);
  dVar4 = (double)ArrayBuffer_getDouble(param_1);
  dVar5 = (double)ArrayBuffer_getDouble(param_1);
  dVar6 = (double)ArrayBuffer_getDouble(param_1);
  dVar7 = (double)ArrayBuffer_getDouble(param_1);
  puVar8 = (uint64_t *)(&currentRenderer);
  uVar9 = GLRenderer_getCurrentMatrix(*puVar8);
  fVar10 = (float)dVar6;
  fVar11 = (float)dVar7;
  local_98[0] = (float)dVar3 - (float)dVar2;
  fStack_74 = (float)dVar5 - (float)dVar4;
  local_78 = ((float)dVar2 + (float)dVar3) / local_98[0];
  local_98[0] = (fVar10 + fVar10) / local_98[0];
  local_98[5] = (fVar10 + fVar10) / fStack_74;
  fStack_74 = ((float)dVar4 + (float)dVar5) / fStack_74;
  local_70 = -(fVar10 + fVar11) / (fVar11 - fVar10);
  local_60 = (fVar11 * -2.0 * fVar10) / (fVar11 - fVar10);
  local_64 = 0;
  local_98[4] = 0.0;
  local_98[2] = 0.0;
  local_98[3] = 0.0;
  local_98[1] = 0.0;
  local_80 = 0;
  local_6c = 0xbf800000;
  local_5c = 0;
  FUN_001268f4(uVar9,uVar9,local_98);
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001269a0  size=196 */

void gd_handle_glGenBuffers(long param_1)

{
  int iVar1;
  long lVar2;
  unsigned long uVar3;
  long lVar4;
  uint64_t uVar5;
  uint16_t local_50;
  int local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar4 = (long)&local_50 - ((uVar3 & 0xffffffff) * 4 + 0xf & 0x7fffffff0);
  glGenBuffers(uVar3,lVar4);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = (int)uVar3 * 4;
  local_50 = 0xeb;
  local_4e = iVar1;
  uVar3 = RingBuffer_write(uVar5,&local_50,6);
  if (((uVar3 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar5,lVar4,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00126a64  size=216 */

void gd_handle_glGenFramebuffers(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  long lVar5;
  uint64_t uVar6;
  unsigned long uVar7;
  uint32_t *puVar8;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = (unsigned long)uVar3;
  lVar5 = uVar7 * 4;
  puVar8 = (uint32_t *)(local_50 + -(lVar5 + 0xfU & 0x7fffffff0));
  if (0 < (int)uVar3) {
    do {
      uVar4 = GLFramebuffer_create();
      uVar7 = uVar7 - 1;
      *puVar8 = uVar4;
      puVar8 = puVar8 + 1;
    } while (uVar7 != 0);
  }
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = uVar3 * 4;
  (*(uint16_t*)((char*)&local_50 + 0)) = 0xec;
  (*(uint32_t*)((char*)&local_50 + 2)) = iVar1;
  uVar7 = RingBuffer_write(uVar6,local_50,6);
  if (((uVar7 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar6,local_50 + -(lVar5 + 0xfU & 0x7fffffff0),iVar1);
  }
  if (*(long *)(lVar2 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00126b3c  size=52 */

void gd_handle_glGenLists(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glGenLists");
  return;
}


/* @00126b70  size=220 */

void gd_handle_glGenProgramsARB(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t *puVar4;
  long lVar5;
  uint64_t uVar6;
  unsigned long uVar7;
  uint32_t *puVar8;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = (unsigned long)uVar3;
  lVar5 = uVar7 * 4;
  puVar8 = (uint32_t *)(local_50 + -(lVar5 + 0xfU & 0x7fffffff0));
  if (0 < (int)uVar3) {
    do {
      puVar4 = (uint32_t *)ARBProgram_create();
      uVar7 = uVar7 - 1;
      *puVar8 = *puVar4;
      puVar8 = puVar8 + 1;
    } while (uVar7 != 0);
  }
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = uVar3 * 4;
  (*(uint16_t*)((char*)&local_50 + 0)) = 0xee;
  (*(uint32_t*)((char*)&local_50 + 2)) = iVar1;
  uVar7 = RingBuffer_write(uVar6,local_50,6);
  if (((uVar7 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar6,local_50 + -(lVar5 + 0xfU & 0x7fffffff0),iVar1);
  }
  if (*(long *)(lVar2 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00126c4c  size=216 */

void gd_handle_glGenQueries(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  long lVar5;
  uint64_t uVar6;
  unsigned long uVar7;
  uint32_t *puVar8;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = (unsigned long)uVar3;
  lVar5 = uVar7 * 4;
  puVar8 = (uint32_t *)(local_50 + -(lVar5 + 0xfU & 0x7fffffff0));
  if (0 < (int)uVar3) {
    do {
      uVar4 = GLQuery_create();
      uVar7 = uVar7 - 1;
      *puVar8 = uVar4;
      puVar8 = puVar8 + 1;
    } while (uVar7 != 0);
  }
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = uVar3 * 4;
  (*(uint16_t*)((char*)&local_50 + 0)) = 0xef;
  (*(uint32_t*)((char*)&local_50 + 2)) = iVar1;
  uVar7 = RingBuffer_write(uVar6,local_50,6);
  if (((uVar7 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar6,local_50 + -(lVar5 + 0xfU & 0x7fffffff0),iVar1);
  }
  if (*(long *)(lVar2 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00126d24  size=196 */

void gd_handle_glGenRenderbuffers(long param_1)

{
  int iVar1;
  long lVar2;
  unsigned long uVar3;
  long lVar4;
  uint64_t uVar5;
  uint16_t local_50;
  int local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar4 = (long)&local_50 - ((uVar3 & 0xffffffff) * 4 + 0xf & 0x7fffffff0);
  glGenRenderbuffers(uVar3,lVar4);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = (int)uVar3 * 4;
  local_50 = 0xf0;
  local_4e = iVar1;
  uVar3 = RingBuffer_write(uVar5,&local_50,6);
  if (((uVar3 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar5,lVar4,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00126de8  size=196 */

void gd_handle_glGenSamplers(long param_1)

{
  int iVar1;
  long lVar2;
  unsigned long uVar3;
  long lVar4;
  uint64_t uVar5;
  uint16_t local_50;
  int local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar4 = (long)&local_50 - ((uVar3 & 0xffffffff) * 4 + 0xf & 0x7fffffff0);
  glGenSamplers(uVar3,lVar4);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = (int)uVar3 * 4;
  local_50 = 0xf1;
  local_4e = iVar1;
  uVar3 = RingBuffer_write(uVar5,&local_50,6);
  if (((uVar3 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar5,lVar4,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00126eac  size=196 */

void gd_handle_glGenTextures(long param_1)

{
  int iVar1;
  long lVar2;
  unsigned long uVar3;
  long lVar4;
  uint64_t uVar5;
  uint16_t local_50;
  int local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar4 = (long)&local_50 - ((uVar3 & 0xffffffff) * 4 + 0xf & 0x7fffffff0);
  glGenTextures(uVar3,lVar4);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = (int)uVar3 * 4;
  local_50 = 0xf2;
  local_4e = iVar1;
  uVar3 = RingBuffer_write(uVar5,&local_50,6);
  if (((uVar3 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar5,lVar4,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00126f70  size=196 */

void gd_handle_glGenVertexArrays(long param_1)

{
  int iVar1;
  long lVar2;
  unsigned long uVar3;
  long lVar4;
  uint64_t uVar5;
  uint16_t local_50;
  int local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar4 = (long)&local_50 - ((uVar3 & 0xffffffff) * 4 + 0xf & 0x7fffffff0);
  glGenVertexArrays(uVar3,lVar4);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = (int)uVar3 * 4;
  local_50 = 0xf3;
  local_4e = iVar1;
  uVar3 = RingBuffer_write(uVar5,&local_50,6);
  if (((uVar3 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar5,lVar4,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127034  size=24 */

void gd_handle_glGenerateMipmap(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glGenerateMipmap(0);
  return;
}


/* @0012704c  size=320 */

void gd_handle_glGetActiveAttrib(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  unsigned long uVar6;
  uint64_t uVar7;
  uint64_t uVar8;
  uint8_t auStack_70 [4];
  uint32_t local_6c;
  uint32_t local_68;
  uint32_t local_64;
  uint16_t local_60;
  int local_5e;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  glGetActiveAttrib(uVar3,uVar4,uVar5,&local_64,&local_68,&local_6c,
                    auStack_70 + -((unsigned long)uVar5 + 0xf & 0x1fffffff0));
  ArrayBuffer_rewind(param_1 + 0x80);
  ArrayBuffer_putInt(param_1 + 0x80,local_64);
  ArrayBuffer_putInt(param_1 + 0x80,local_68);
  ArrayBuffer_putInt(param_1 + 0x80,local_6c);
  ArrayBuffer_putBytes(param_1 + 0x80,auStack_70 + -((unsigned long)uVar5 + 0xf & 0x1fffffff0),uVar5);
  uVar8 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x80);
  uVar7 = *(uint64_t *)(param_1 + 0x90);
  local_60 = 0xf5;
  local_5e = iVar1;
  uVar6 = RingBuffer_write(uVar8,&local_60,6);
  if (((uVar6 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar8,uVar7,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012718c  size=320 */

void gd_handle_glGetActiveUniform(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  unsigned long uVar6;
  uint64_t uVar7;
  uint64_t uVar8;
  uint8_t auStack_70 [4];
  uint32_t local_6c;
  uint32_t local_68;
  uint32_t local_64;
  uint16_t local_60;
  int local_5e;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  glGetActiveUniform(uVar3,uVar4,uVar5,&local_64,&local_68,&local_6c,
                     auStack_70 + -((unsigned long)uVar5 + 0xf & 0x1fffffff0));
  ArrayBuffer_rewind(param_1 + 0x80);
  ArrayBuffer_putInt(param_1 + 0x80,local_64);
  ArrayBuffer_putInt(param_1 + 0x80,local_68);
  ArrayBuffer_putInt(param_1 + 0x80,local_6c);
  ArrayBuffer_putBytes(param_1 + 0x80,auStack_70 + -((unsigned long)uVar5 + 0xf & 0x1fffffff0),uVar5);
  uVar8 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x80);
  uVar7 = *(uint64_t *)(param_1 + 0x90);
  local_60 = 0xf6;
  local_5e = iVar1;
  uVar6 = RingBuffer_write(uVar8,&local_60,6);
  if (((uVar6 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar8,uVar7,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001272cc  size=32 */

void gd_handle_glGetActiveUniformBlockName(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetActiveUniformBlockName");
  return;
}


/* @001272ec  size=32 */

void gd_handle_glGetActiveUniformBlockiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetActiveUniformBlockiv");
  return;
}


/* @0012730c  size=32 */

void gd_handle_glGetActiveUniformName(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetActiveUniformName");
  return;
}


/* @0012732c  size=32 */

void gd_handle_glGetActiveUniformsiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetActiveUniformsiv");
  return;
}


/* @0012734c  size=32 */

void gd_handle_glGetAttachedShaders(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetAttachedShaders");
  return;
}


/* @0012736c  size=152 */

void gd_handle_glGetAttribLocation(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  unsigned long uVar3;
  uint32_t local_34;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  local_34 = glGetAttribLocation(uVar2,*(long *)(param_1 + 0x78) + (long)*(int *)(param_1 + 0x6c));
  uVar2 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0xfc;
  local_2e = 4;
  uVar3 = RingBuffer_write(uVar2,&local_30,6);
  if ((uVar3 & 1) != 0) {
    RingBuffer_write(uVar2,&local_34,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127404  size=32 */

void gd_handle_glGetBooleani_v(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetBooleani_v");
  return;
}


/* @00127424  size=240 */

void gd_handle_glGetBooleanv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  long lVar6;
  uint64_t uVar7;
  uint16_t local_50;
  uint32_t local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar4 = (uint64_t *)(&currentRenderer);
  uVar3 = GLRenderer_getParamsv(*puVar4,uVar2,0x8b56,0);
  lVar6 = (long)&local_50 - ((unsigned long)uVar3 + 0xf & 0x1fffffff0);
  GLRenderer_getParamsv(*puVar4,uVar2,0x8b56,lVar6);
  uVar7 = *(uint64_t *)(param_1 + 0x10);
  local_50 = 0xfe;
  local_4e = uVar3;
  uVar5 = RingBuffer_write(uVar7,&local_50,6);
  if (((uVar5 & 1) != 0) && (0 < (int)uVar3)) {
    RingBuffer_write(uVar7,lVar6,uVar3);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127514  size=32 */

void gd_handle_glGetClipPlane(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetClipPlane");
  return;
}


/* @00127534  size=224 */

void gd_handle_glGetCompressedTexImage(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  void *__ptr;
  unsigned long uVar5;
  uint64_t uVar6;
  int local_44;
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar4 = (uint64_t *)(&currentRenderer);
  __ptr = (void *)GLRenderer_getCompressedTexImage(*puVar4,uVar2,uVar3,&local_44);
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x100;
  local_3e = 4;
  uVar5 = RingBuffer_write(uVar6,&local_40,6);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar6,&local_44,4);
  }
  if (0 < local_44) {
    RingBuffer_write(*(uint64_t *)(param_1 + 0x10),__ptr);
    free(__ptr);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127614  size=132 */

void gd_handle_glGetError(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint32_t local_34;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  local_34 = glGetError();
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x101;
  local_2e = 4;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,&local_34,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127698  size=240 */

void gd_handle_glGetFloatv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  long lVar6;
  uint64_t uVar7;
  uint16_t local_50;
  uint32_t local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar4 = (uint64_t *)(&currentRenderer);
  uVar3 = GLRenderer_getParamsv(*puVar4,uVar2,0x1406,0);
  lVar6 = (long)&local_50 - ((unsigned long)uVar3 + 0xf & 0x1fffffff0);
  GLRenderer_getParamsv(*puVar4,uVar2,0x1406,lVar6);
  uVar7 = *(uint64_t *)(param_1 + 0x10);
  local_50 = 0x102;
  local_4e = uVar3;
  uVar5 = RingBuffer_write(uVar7,&local_50,6);
  if (((uVar5 & 1) != 0) && (0 < (int)uVar3)) {
    RingBuffer_write(uVar7,lVar6,uVar3);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127788  size=32 */

void gd_handle_glGetFragDataIndex(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetFragDataIndex");
  return;
}


/* @001277a8  size=32 */

void gd_handle_glGetFragDataLocation(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetFragDataLocation");
  return;
}


/* @001277c8  size=188 */

void gd_handle_glGetFramebufferAttachmentParameteriv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  unsigned long uVar5;
  uint64_t uVar6;
  uint32_t local_44;
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  local_44 = 0;
  glGetFramebufferAttachmentParameteriv(uVar2,uVar3,uVar4,&local_44);
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x105;
  local_3e = 4;
  uVar5 = RingBuffer_write(uVar6,&local_40,6);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar6,&local_44,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127884  size=52 */

void gd_handle_glGetHandleARB(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glGetHandleARB");
  return;
}


/* @001278b8  size=32 */

void gd_handle_glGetInfoLogARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetInfoLogARB");
  return;
}


/* @001278d8  size=32 */

void gd_handle_glGetInteger64i_v(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetInteger64i_v");
  return;
}


/* @001278f8  size=32 */

void gd_handle_glGetInteger64v(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetInteger64v");
  return;
}


/* @00127918  size=32 */

void gd_handle_glGetIntegeri_v(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetIntegeri_v");
  return;
}


/* @00127938  size=240 */

void gd_handle_glGetIntegerv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  long lVar6;
  uint64_t uVar7;
  uint16_t local_50;
  uint32_t local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar4 = (uint64_t *)(&currentRenderer);
  uVar3 = GLRenderer_getParamsv(*puVar4,uVar2,0x1404,0);
  lVar6 = (long)&local_50 - ((unsigned long)uVar3 + 0xf & 0x1fffffff0);
  GLRenderer_getParamsv(*puVar4,uVar2,0x1404,lVar6);
  uVar7 = *(uint64_t *)(param_1 + 0x10);
  local_50 = 0x10b;
  local_4e = uVar3;
  uVar5 = RingBuffer_write(uVar7,&local_50,6);
  if (((uVar5 & 1) != 0) && (0 < (int)uVar3)) {
    RingBuffer_write(uVar7,lVar6,uVar3);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127a28  size=300 */

void gd_handle_glGetInternalformativ(long param_1)

{
  long lVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  unsigned long uVar7;
  long lVar8;
  uint64_t uVar9;
  uint16_t local_60;
  int local_5e;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar1 + 0x28);
  iVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar8 = (long)&local_60 - ((unsigned long)uVar5 * 4 + 0xf & 0x7fffffff0);
  iVar6 = 0xde1;
  if (((iVar2 != 0xde0) && (iVar2 != 0x84f5)) && (iVar6 = iVar2, iVar2 == 0x8c18)) {
    iVar6 = 0x8c1a;
  }
  GLFormats_queryInternalformat(iVar6,uVar3,uVar4,uVar5,lVar8);
  uVar9 = *(uint64_t *)(param_1 + 0x10);
  iVar6 = uVar5 * 4;
  local_60 = 0x10c;
  local_5e = iVar6;
  uVar7 = RingBuffer_write(uVar9,&local_60,6);
  if (((uVar7 & 1) != 0) && (0 < iVar6)) {
    RingBuffer_write(uVar9,lVar8,iVar6);
  }
  if (*(long *)(lVar1 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00127b54  size=32 */

void gd_handle_glGetLightfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetLightfv");
  return;
}


/* @00127b74  size=32 */

void gd_handle_glGetLightiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetLightiv");
  return;
}


/* @00127b94  size=32 */

void gd_handle_glGetMapdv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetMapdv");
  return;
}


/* @00127bb4  size=32 */

void gd_handle_glGetMapfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetMapfv");
  return;
}


/* @00127bd4  size=32 */

void gd_handle_glGetMapiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetMapiv");
  return;
}


/* @00127bf4  size=32 */

void gd_handle_glGetMaterialfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetMaterialfv");
  return;
}


/* @00127c14  size=32 */

void gd_handle_glGetMaterialiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetMaterialiv");
  return;
}


/* @00127c34  size=32 */

void gd_handle_glGetMultisamplefv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetMultisamplefv");
  return;
}


/* @00127c54  size=32 */

void gd_handle_glGetObjectParameterfvARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetObjectParameterfvARB");
  return;
}


/* @00127c74  size=32 */

void gd_handle_glGetObjectParameterivARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetObjectParameterivARB");
  return;
}


/* @00127c94  size=32 */

void gd_handle_glGetPixelMapfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetPixelMapfv");
  return;
}


/* @00127cb4  size=32 */

void gd_handle_glGetPixelMapuiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetPixelMapuiv");
  return;
}


/* @00127cd4  size=32 */

void gd_handle_glGetPixelMapusv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetPixelMapusv");
  return;
}


/* @00127cf4  size=32 */

void gd_handle_glGetPointerv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetPointerv");
  return;
}


/* @00127d14  size=32 */

void gd_handle_glGetPolygonStipple(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetPolygonStipple");
  return;
}


/* @00127d34  size=32 */

void gd_handle_glGetProgramEnvParameterdvARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetProgramEnvParameterdvARB");
  return;
}


/* @00127d54  size=32 */

void gd_handle_glGetProgramEnvParameterfvARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetProgramEnvParameterfvARB");
  return;
}


/* @00127d74  size=248 */

void gd_handle_glGetProgramInfoLog(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  unsigned long uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  uint8_t auStack_50 [12];
  uint32_t local_44;
  uint16_t local_40;
  int local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  local_44 = 0;
  glGetProgramInfoLog(uVar3,uVar4,&local_44,auStack_50 + -((unsigned long)uVar4 + 0xf & 0x1fffffff0));
  ArrayBuffer_rewind(param_1 + 0x80);
  ArrayBuffer_putInt(param_1 + 0x80,local_44);
  ArrayBuffer_putBytes(param_1 + 0x80,auStack_50 + -((unsigned long)uVar4 + 0xf & 0x1fffffff0),local_44);
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x80);
  uVar7 = *(uint64_t *)(param_1 + 0x90);
  local_40 = 0x11e;
  local_3e = iVar1;
  uVar5 = RingBuffer_write(uVar6,&local_40,6);
  if (((uVar5 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar6,uVar7,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127e6c  size=32 */

void gd_handle_glGetProgramLocalParameterdvARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetProgramLocalParameterdvARB");
  return;
}


/* @00127e8c  size=32 */

void gd_handle_glGetProgramLocalParameterfvARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetProgramLocalParameterfvARB");
  return;
}


/* @00127eac  size=32 */

void gd_handle_glGetProgramStringARB(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetProgramStringARB");
  return;
}


/* @00127ecc  size=168 */

void gd_handle_glGetProgramiv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  uint8_t auStack_44 [4];
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_getProgramiv(uVar2,uVar3,auStack_44);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x122;
  local_3e = 4;
  uVar4 = RingBuffer_write(uVar5,&local_40,6);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar5,auStack_44,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00127f74  size=172 */

void gd_handle_glGetQueryObjectuiv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  uint32_t local_44;
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  local_44 = 0;
  GLQuery_getObjectParamsv(uVar2,uVar3,&local_44);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x123;
  local_3e = 4;
  uVar4 = RingBuffer_write(uVar5,&local_40,6);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar5,&local_44,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128020  size=172 */

void gd_handle_glGetQueryiv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  uint32_t local_44;
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  local_44 = 0;
  GLQuery_getParamsv(uVar2,uVar3,&local_44);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x124;
  local_3e = 4;
  uVar4 = RingBuffer_write(uVar5,&local_40,6);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar5,&local_44,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001280cc  size=32 */

void gd_handle_glGetRenderbufferParameteriv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetRenderbufferParameteriv");
  return;
}


/* @001280ec  size=436 */

void gd_handle_glGetSamplerParameterfv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  int iVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  int iVar6;
  uint64_t uVar7;
  long lVar8;
  uint16_t local_50;
  int local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  if (iVar3 < 0x1204) {
    if (iVar3 < 0x1200) {
      if ((iVar3 == 0xb66) || (iVar3 == 0x1004)) goto LAB_001281d4;
    }
    else if ((iVar3 - 0x1200U < 3) || (iVar3 == 0x1203)) {
LAB_001281d4:
      iVar6 = 4;
      goto LAB_001281d8;
    }
  }
  else {
    if (iVar3 < 0x2201) {
      if (iVar3 == 0x1204) {
LAB_0012828c:
        iVar6 = 3;
        goto LAB_001281d8;
      }
      if ((iVar3 != 0x1600) && (iVar3 != 0x1602)) goto LAB_00128284;
      goto LAB_001281d4;
    }
    if (iVar3 < 0x8e73) {
      if (iVar3 == 0x2201) goto LAB_001281d4;
      if (iVar3 == 0x8129) goto LAB_0012828c;
    }
    else {
      if (iVar3 == 0x8e73) {
        iVar6 = 2;
        goto LAB_001281d8;
      }
      if (iVar3 == 0x8e74) goto LAB_001281d4;
    }
  }
LAB_00128284:
  iVar6 = 1;
LAB_001281d8:
  iVar6 = iVar6 * 4;
  lVar8 = (long)&local_50 - ((unsigned long)(iVar6 + 0xf) & 0x30);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_getSamplerParameter(*puVar4,uVar2,iVar3,lVar8);
  uVar7 = *(uint64_t *)(param_1 + 0x10);
  local_50 = 0x126;
  local_4e = iVar6;
  uVar5 = RingBuffer_write(uVar7,&local_50,6);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar7,lVar8,iVar6);
  }
  if (*(long *)(lVar1 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001282a0  size=248 */

void gd_handle_glGetShaderInfoLog(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  unsigned long uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  uint8_t auStack_50 [12];
  uint32_t local_44;
  uint16_t local_40;
  int local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar2 + 0x28);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  local_44 = 0;
  glGetShaderInfoLog(uVar3,uVar4,&local_44,auStack_50 + -((unsigned long)uVar4 + 0xf & 0x1fffffff0));
  ArrayBuffer_rewind(param_1 + 0x80);
  ArrayBuffer_putInt(param_1 + 0x80,local_44);
  ArrayBuffer_putBytes(param_1 + 0x80,auStack_50 + -((unsigned long)uVar4 + 0xf & 0x1fffffff0),local_44);
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x80);
  uVar7 = *(uint64_t *)(param_1 + 0x90);
  local_40 = 0x127;
  local_3e = iVar1;
  uVar5 = RingBuffer_write(uVar6,&local_40,6);
  if (((uVar5 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar6,uVar7,iVar1);
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128398  size=32 */

void gd_handle_glGetShaderPrecisionFormat(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetShaderPrecisionFormat");
  return;
}


/* @001283b8  size=32 */

void gd_handle_glGetShaderSource(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetShaderSource");
  return;
}


/* @001283d8  size=168 */

void gd_handle_glGetShaderiv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  uint8_t auStack_44 [4];
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_getShaderiv(uVar2,uVar3,auStack_44);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x12a;
  local_3e = 4;
  uVar4 = RingBuffer_write(uVar5,&local_40,6);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar5,auStack_44,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128480  size=304 */

void gd_handle_glGetString(long param_1)

{
  long lVar1;
  int iVar2;
  size_t sVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  char *__s;
  uint64_t uVar6;
  uint16_t local_40;
  int local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  iVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  __s = "3.3";
  switch(iVar2) {
  case 0x1f00:
    __s = (char *)glGetString(0x1f00);
    break;
  case 0x1f01:
    __s = "Gladio";
    break;
  case 0x1f02:
    break;
  case 0x1f03:
    __s = (char *)getGLExtensions(0);
    break;
  default:
    if (iVar2 == 0x8b8c) {
      __s = "3.30";
    }
    else {
      __s = "";
    }
  }
  ArrayBuffer_rewind(param_1 + 0x80);
  sVar3 = strlen(__s);
  ArrayBuffer_putBytes(param_1 + 0x80,__s,sVar3);
  uVar6 = *(uint64_t *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x80);
  uVar5 = *(uint64_t *)(param_1 + 0x90);
  local_40 = 299;
  local_3e = iVar2;
  uVar4 = RingBuffer_write(uVar6,&local_40,6);
  if (((uVar4 & 1) != 0) && (0 < iVar2)) {
    RingBuffer_write(uVar6,uVar5,iVar2);
  }
  if (*(long *)(lVar1 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001285b0  size=32 */

void gd_handle_glGetSynciv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetSynciv");
  return;
}


/* @001285d0  size=32 */

void gd_handle_glGetTexEnvfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetTexEnvfv");
  return;
}


/* @001285f0  size=32 */

void gd_handle_glGetTexEnviv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetTexEnviv");
  return;
}


/* @00128610  size=32 */

void gd_handle_glGetTexGendv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetTexGendv");
  return;
}


/* @00128630  size=32 */

void gd_handle_glGetTexGenfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetTexGenfv");
  return;
}


/* @00128650  size=32 */

void gd_handle_glGetTexGeniv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetTexGeniv");
  return;
}


/* @00128670  size=264 */

void gd_handle_glGetTexImage(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint64_t *puVar6;
  void *__ptr;
  unsigned long uVar7;
  uint64_t uVar8;
  int local_54;
  uint16_t local_50;
  uint32_t local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar6 = (uint64_t *)(&currentRenderer);
  __ptr = (void *)GLRenderer_getTexImage(*puVar6,uVar2,uVar3,uVar4,uVar5,&local_54);
  uVar8 = *(uint64_t *)(param_1 + 0x10);
  local_50 = 0x132;
  local_4e = 4;
  uVar7 = RingBuffer_write(uVar8,&local_50,6);
  if ((uVar7 & 1) != 0) {
    RingBuffer_write(uVar8,&local_54,4);
  }
  if (0 < local_54) {
    RingBuffer_write(*(uint64_t *)(param_1 + 0x10),__ptr);
    free(__ptr);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128778  size=212 */

void gd_handle_glGetTexLevelParameterfv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint64_t *puVar5;
  unsigned long uVar6;
  uint64_t uVar7;
  uint8_t auStack_54 [4];
  uint16_t local_50;
  uint32_t local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar5 = (uint64_t *)(&currentRenderer);
  GLRenderer_getTexParameter(*puVar5,uVar2,uVar3,uVar4,auStack_54);
  uVar7 = *(uint64_t *)(param_1 + 0x10);
  local_50 = 0x133;
  local_4e = 4;
  uVar6 = RingBuffer_write(uVar7,&local_50,6);
  if ((uVar6 & 1) != 0) {
    RingBuffer_write(uVar7,auStack_54,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012884c  size=440 */

void gd_handle_glGetTexParameterfv(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  int iVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  int iVar6;
  uint64_t uVar7;
  long lVar8;
  uint16_t local_50;
  int local_4e;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  if (iVar3 < 0x1204) {
    if (iVar3 < 0x1200) {
      if ((iVar3 == 0xb66) || (iVar3 == 0x1004)) goto LAB_00128934;
    }
    else if ((iVar3 - 0x1200U < 3) || (iVar3 == 0x1203)) {
LAB_00128934:
      iVar6 = 4;
      goto LAB_00128938;
    }
  }
  else {
    if (iVar3 < 0x2201) {
      if (iVar3 == 0x1204) {
LAB_001289f0:
        iVar6 = 3;
        goto LAB_00128938;
      }
      if ((iVar3 != 0x1600) && (iVar3 != 0x1602)) goto LAB_001289e8;
      goto LAB_00128934;
    }
    if (iVar3 < 0x8e73) {
      if (iVar3 == 0x2201) goto LAB_00128934;
      if (iVar3 == 0x8129) goto LAB_001289f0;
    }
    else {
      if (iVar3 == 0x8e73) {
        iVar6 = 2;
        goto LAB_00128938;
      }
      if (iVar3 == 0x8e74) goto LAB_00128934;
    }
  }
LAB_001289e8:
  iVar6 = 1;
LAB_00128938:
  iVar6 = iVar6 * 4;
  lVar8 = (long)&local_50 - ((unsigned long)(iVar6 + 0xf) & 0x30);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_getTexParameter(*puVar4,uVar2,0,iVar3,lVar8);
  uVar7 = *(uint64_t *)(param_1 + 0x10);
  local_50 = 0x134;
  local_4e = iVar6;
  uVar5 = RingBuffer_write(uVar7,&local_50,6);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar7,lVar8,iVar6);
  }
  if (*(long *)(lVar1 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00128a04  size=32 */

void gd_handle_glGetTransformFeedbackVarying(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetTransformFeedbackVarying");
  return;
}


/* @00128a24  size=152 */

void gd_handle_glGetUniformBlockIndex(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  unsigned long uVar3;
  uint32_t local_34;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  local_34 = glGetUniformBlockIndex
                       (uVar2,*(long *)(param_1 + 0x78) + (long)*(int *)(param_1 + 0x6c));
  uVar2 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x136;
  local_2e = 4;
  uVar3 = RingBuffer_write(uVar2,&local_30,6);
  if ((uVar3 & 1) != 0) {
    RingBuffer_write(uVar2,&local_34,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128abc  size=32 */

void gd_handle_glGetUniformIndices(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetUniformIndices");
  return;
}


/* @00128adc  size=152 */

void gd_handle_glGetUniformLocation(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  unsigned long uVar3;
  uint32_t local_34;
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  local_34 = glGetUniformLocation(uVar2,*(long *)(param_1 + 0x78) + (long)*(int *)(param_1 + 0x6c));
  uVar2 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x138;
  local_2e = 4;
  uVar3 = RingBuffer_write(uVar2,&local_30,6);
  if ((uVar3 & 1) != 0) {
    RingBuffer_write(uVar2,&local_34,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128b74  size=32 */

void gd_handle_glGetUniformfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetUniformfv");
  return;
}


/* @00128b94  size=32 */

void gd_handle_glGetUniformiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetUniformiv");
  return;
}


/* @00128bb4  size=32 */

void gd_handle_glGetUniformuiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetUniformuiv");
  return;
}


/* @00128bd4  size=32 */

void gd_handle_glGetVertexAttribIiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetVertexAttribIiv");
  return;
}


/* @00128bf4  size=32 */

void gd_handle_glGetVertexAttribIuiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetVertexAttribIuiv");
  return;
}


/* @00128c14  size=32 */

void gd_handle_glGetVertexAttribPointerv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetVertexAttribPointerv");
  return;
}


/* @00128c34  size=32 */

void gd_handle_glGetVertexAttribdv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetVertexAttribdv");
  return;
}


/* @00128c54  size=32 */

void gd_handle_glGetVertexAttribfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetVertexAttribfv");
  return;
}


/* @00128c74  size=32 */

void gd_handle_glGetVertexAttribiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glGetVertexAttribiv");
  return;
}


/* @00128c94  size=92 */

void gd_handle_glHint(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  if ((iVar1 != 0x8b8b) && (iVar1 != 0x8192)) {
    return;
  }
  glHint(iVar1,uVar2);
  return;
}


/* @00128cf0  size=52 */

void gd_handle_glIndexMask(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glIndexMask");
  return;
}


/* @00128d24  size=32 */

void gd_handle_glIndexPointer(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glIndexPointer");
  return;
}


/* @00128d44  size=52 */

void gd_handle_glIndexf(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glIndexf");
  return;
}


/* @00128d78  size=32 */

void gd_handle_glInitNames(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glInitNames");
  return;
}


/* @00128d98  size=32 */

void gd_handle_glInterleavedArrays(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glInterleavedArrays");
  return;
}


/* @00128db8  size=140 */

void gd_handle_glIsBuffer(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsBuffer(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x148;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128e44  size=176 */

void gd_handle_glIsEnabled(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint64_t *puVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  uint8_t auStack_44 [4];
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_getParamsv(*puVar3,uVar2,0x8b56,auStack_44);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x149;
  local_3e = 1;
  uVar4 = RingBuffer_write(uVar5,&local_40,6);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar5,auStack_44,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128ef4  size=168 */

void gd_handle_glIsEnabledi(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint64_t uVar5;
  uint8_t local_44 [4];
  uint16_t local_40;
  uint32_t local_3e;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  local_44[0] = glIsEnabledi(uVar2,uVar3);
  uVar5 = *(uint64_t *)(param_1 + 0x10);
  local_40 = 0x14a;
  local_3e = 1;
  uVar4 = RingBuffer_write(uVar5,&local_40,6);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar5,local_44,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00128f9c  size=140 */

void gd_handle_glIsFramebuffer(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsFramebuffer(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x14b;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00129028  size=52 */

void gd_handle_glIsList(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glIsList");
  return;
}


/* @0012905c  size=140 */

void gd_handle_glIsProgram(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsProgram(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x14d;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001290e8  size=140 */

void gd_handle_glIsQuery(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsQuery(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x14e;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00129174  size=140 */

void gd_handle_glIsRenderbuffer(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsRenderbuffer(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x14f;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00129200  size=140 */

void gd_handle_glIsSampler(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsSampler(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x150;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012928c  size=140 */

void gd_handle_glIsShader(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsShader(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x151;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00129318  size=140 */

void gd_handle_glIsSync(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getLong(param_1 + 0x68);
  local_34[0] = glIsSync(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x152;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001293a4  size=140 */

void gd_handle_glIsTexture(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsTexture(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x153;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00129430  size=140 */

void gd_handle_glIsVertexArray(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint8_t local_34 [4];
  uint16_t local_30;
  uint32_t local_2e;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  ArrayBuffer_getInt(param_1 + 0x68);
  local_34[0] = glIsVertexArray(0);
  uVar3 = *(uint64_t *)(param_1 + 0x10);
  local_30 = 0x154;
  local_2e = 1;
  uVar2 = RingBuffer_write(uVar3,&local_30,6);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,local_34,1);
  }
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001294bc  size=72 */

void gd_handle_glLightModelf(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glLightModelf");
  return;
}


/* @00129504  size=32 */

void gd_handle_glLightModelfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glLightModelfv");
  return;
}


/* @00129524  size=72 */

void gd_handle_glLightModeli(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glLightModeli");
  return;
}


/* @0012956c  size=32 */

void gd_handle_glLightModeliv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glLightModeliv");
  return;
}


/* @0012958c  size=144 */

void gd_handle_glLightf(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  local_3c = ArrayBuffer_getFloat(param_1);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_setLightParams(*puVar4,uVar2,uVar3,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012961c  size=104 */

void gd_handle_glLightfv(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t *puVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,0x10);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_setLightParams(*puVar4,uVar1,uVar2,uVar3);
  return;
}


/* @00129684  size=72 */

void gd_handle_glLineStipple(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getShort(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glLineStipple");
  return;
}


/* @001296cc  size=24 */

void gd_handle_glLineWidth(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  glLineWidth(0);
  return;
}


/* @001296e4  size=24 */

void gd_handle_glLinkProgram(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ShaderConverter_linkProgram();
  return;
}


/* @001296fc  size=52 */

void gd_handle_glListBase(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glListBase");
  return;
}


/* @00129730  size=76 */

void gd_handle_glLoadIdentity(void)

{
  uint64_t *puVar1;
  uint32_t *puVar2;
  
  puVar1 = (uint64_t *)(&currentRenderer);
  puVar2 = (uint32_t *)GLRenderer_getCurrentMatrix(*puVar1);
  *(uint64_t *)(puVar2 + 3) = 0;
  *(uint64_t *)(puVar2 + 1) = 0;
  *(uint64_t *)(puVar2 + 6) = 0;
  *(uint64_t *)(puVar2 + 8) = 0;
  *(uint64_t *)(puVar2 + 0xd) = 0;
  *(uint64_t *)(puVar2 + 0xb) = 0;
  *puVar2 = 0x3f800000;
  puVar2[5] = 0x3f800000;
  puVar2[10] = 0x3f800000;
  puVar2[0xf] = 0x3f800000;
  return;
}


/* @0012977c  size=76 */

void gd_handle_glLoadMatrixf(long param_1)

{
  uint64_t *puVar1;
  uint64_t *puVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  
  puVar1 = (uint64_t *)ArrayBuffer_getBytes(param_1 + 0x68,0x40);
  puVar2 = (uint64_t *)(&currentRenderer);
  puVar2 = (uint64_t *)GLRenderer_getCurrentMatrix(*puVar2);
  uVar5 = puVar1[4];
  uVar4 = puVar1[7];
  uVar3 = puVar1[6];
  uVar7 = puVar1[1];
  uVar6 = *puVar1;
  uVar9 = puVar1[3];
  uVar8 = puVar1[2];
  puVar2[5] = puVar1[5];
  puVar2[4] = uVar5;
  puVar2[7] = uVar4;
  puVar2[6] = uVar3;
  puVar2[1] = uVar7;
  *puVar2 = uVar6;
  puVar2[3] = uVar9;
  puVar2[2] = uVar8;
  return;
}


/* @001297c8  size=52 */

void gd_handle_glLoadName(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glLoadName");
  return;
}


/* @001297fc  size=128 */

void gd_handle_glLoadTransposeMatrixf(long param_1)

{
  uint64_t *puVar1;
  uint64_t *puVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  uint32_t uVar10;
  uint64_t uVar11;
  uint64_t uVar12;
  uint32_t uVar13;
  uint32_t uVar14;
  
  puVar1 = (uint64_t *)ArrayBuffer_getBytes(param_1 + 0x68,0x40);
  puVar2 = (uint64_t *)(&currentRenderer);
  puVar2 = (uint64_t *)GLRenderer_getCurrentMatrix(*puVar2);
  uVar10 = *(uint32_t *)((long)puVar1 + 0x24);
  uVar13 = *(uint32_t *)((long)puVar1 + 0xc);
  uVar3 = *(uint32_t *)((long)puVar1 + 4);
  uVar6 = *(uint32_t *)(puVar1 + 1);
  uVar14 = *(uint32_t *)((long)puVar1 + 0x1c);
  *(uint32_t *)((long)puVar1 + 4) = *(uint32_t *)(puVar1 + 2);
  *(uint32_t *)(puVar1 + 1) = *(uint32_t *)(puVar1 + 4);
  *(uint32_t *)(puVar1 + 4) = uVar6;
  *(uint32_t *)((long)puVar1 + 0x24) = *(uint32_t *)(puVar1 + 3);
  *(uint32_t *)((long)puVar1 + 0xc) = *(uint32_t *)(puVar1 + 6);
  *(uint32_t *)(puVar1 + 2) = uVar3;
  uVar3 = *(uint32_t *)(puVar1 + 7);
  *(uint32_t *)(puVar1 + 3) = uVar10;
  *(uint32_t *)((long)puVar1 + 0x1c) = *(uint32_t *)((long)puVar1 + 0x34);
  *(uint32_t *)((long)puVar1 + 0x34) = uVar14;
  *(uint32_t *)(puVar1 + 7) = *(uint32_t *)((long)puVar1 + 0x2c);
  uVar9 = *puVar1;
  uVar12 = puVar1[3];
  uVar11 = puVar1[2];
  *(uint32_t *)((long)puVar1 + 0x2c) = uVar3;
  *(uint32_t *)(puVar1 + 6) = uVar13;
  uVar8 = puVar1[5];
  uVar7 = puVar1[4];
  uVar5 = puVar1[7];
  uVar4 = puVar1[6];
  puVar2[1] = puVar1[1];
  *puVar2 = uVar9;
  puVar2[3] = uVar12;
  puVar2[2] = uVar11;
  puVar2[5] = uVar8;
  puVar2[4] = uVar7;
  puVar2[7] = uVar5;
  puVar2[6] = uVar4;
  return;
}


/* @0012987c  size=52 */

void gd_handle_glLogicOp(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glLogicOp");
  return;
}


/* @001298b0  size=32 */

void gd_handle_glMap1d(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glMap1d");
  return;
}


/* @001298d0  size=32 */

void gd_handle_glMap1f(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glMap1f");
  return;
}


/* @001298f0  size=32 */

void gd_handle_glMap2d(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glMap2d");
  return;
}


/* @00129910  size=32 */

void gd_handle_glMap2f(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glMap2f");
  return;
}


/* @00129930  size=80 */

void gd_handle_glMapGrid1d(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getDouble(param_1);
  ArrayBuffer_getDouble(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glMapGrid1d");
  return;
}


/* @00129980  size=80 */

void gd_handle_glMapGrid1f(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glMapGrid1f");
  return;
}


/* @001299d0  size=104 */

void gd_handle_glMapGrid2d(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getDouble(param_1);
  ArrayBuffer_getDouble(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getDouble(param_1);
  ArrayBuffer_getDouble(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glMapGrid2d");
  return;
}


/* @00129a38  size=104 */

void gd_handle_glMapGrid2f(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glMapGrid2f");
  return;
}


/* @00129aa0  size=144 */

void gd_handle_glMaterialf(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  local_3c = ArrayBuffer_getFloat(param_1);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_setMaterialParams(*puVar4,uVar2,uVar3,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00129b30  size=320 */

void gd_handle_glMaterialfv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  if (iVar2 < 0x1204) {
    if (iVar2 < 0x1200) {
      if ((iVar2 == 0xb66) || (iVar2 == 0x1004)) goto LAB_00129c04;
    }
    else if ((iVar2 - 0x1200U < 3) || (iVar2 == 0x1203)) {
LAB_00129c04:
      uVar4 = 0x10;
      goto LAB_00129c08;
    }
  }
  else {
    if (iVar2 < 0x2201) {
      if (iVar2 == 0x1204) {
LAB_00129c60:
        uVar4 = 0xc;
        goto LAB_00129c08;
      }
      if ((iVar2 != 0x1600) && (iVar2 != 0x1602)) goto LAB_00129c58;
      goto LAB_00129c04;
    }
    if (iVar2 < 0x8e73) {
      if (iVar2 == 0x2201) goto LAB_00129c04;
      if (iVar2 == 0x8129) goto LAB_00129c60;
    }
    else {
      if (iVar2 == 0x8e73) {
        uVar4 = 8;
        goto LAB_00129c08;
      }
      if (iVar2 == 0x8e74) goto LAB_00129c04;
    }
  }
LAB_00129c58:
  uVar4 = 4;
LAB_00129c08:
  uVar4 = ArrayBuffer_getBytes(param_1,uVar4);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setMaterialParams(*puVar3,uVar1,iVar2,uVar4);
  return;
}


/* @00129c70  size=60 */

void gd_handle_glMatrixMode(long param_1)

{
  int iVar1;
  long *plVar2;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  *(int *)(*plVar2 + 0x8d0) = iVar1 + -0x1700;
  return;
}


/* @00129cac  size=24 */

void gd_handle_glMinSampleShading(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  glMinSampleShading(0);
  return;
}


/* @00129cc4  size=68 */

void gd_handle_glMultMatrixf(long param_1)

{
  uint64_t uVar1;
  uint64_t *puVar2;
  uint64_t uVar3;
  
  uVar1 = ArrayBuffer_getBytes(param_1 + 0x68,0x40);
  puVar2 = (uint64_t *)(&currentRenderer);
  uVar3 = GLRenderer_getCurrentMatrix(*puVar2);
  FUN_001268f4(uVar3,uVar3,uVar1);
  return;
}


/* @00129d08  size=120 */

void gd_handle_glMultTransposeMatrixf(long param_1)

{
  long lVar1;
  uint64_t *puVar2;
  uint64_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  
  lVar1 = ArrayBuffer_getBytes(param_1 + 0x68,0x40);
  uVar6 = *(uint32_t *)(lVar1 + 0x24);
  uVar7 = *(uint32_t *)(lVar1 + 0xc);
  uVar4 = *(uint32_t *)(lVar1 + 4);
  uVar5 = *(uint32_t *)(lVar1 + 8);
  uVar8 = *(uint32_t *)(lVar1 + 0x1c);
  *(uint32_t *)(lVar1 + 4) = *(uint32_t *)(lVar1 + 0x10);
  *(uint32_t *)(lVar1 + 8) = *(uint32_t *)(lVar1 + 0x20);
  *(uint32_t *)(lVar1 + 0x20) = uVar5;
  *(uint32_t *)(lVar1 + 0x24) = *(uint32_t *)(lVar1 + 0x18);
  *(uint32_t *)(lVar1 + 0xc) = *(uint32_t *)(lVar1 + 0x30);
  *(uint32_t *)(lVar1 + 0x10) = uVar4;
  uVar4 = *(uint32_t *)(lVar1 + 0x38);
  *(uint32_t *)(lVar1 + 0x18) = uVar6;
  *(uint32_t *)(lVar1 + 0x1c) = *(uint32_t *)(lVar1 + 0x34);
  *(uint32_t *)(lVar1 + 0x34) = uVar8;
  *(uint32_t *)(lVar1 + 0x38) = *(uint32_t *)(lVar1 + 0x2c);
  *(uint32_t *)(lVar1 + 0x2c) = uVar4;
  *(uint32_t *)(lVar1 + 0x30) = uVar7;
  puVar2 = (uint64_t *)(&currentRenderer);
  uVar3 = GLRenderer_getCurrentMatrix(*puVar2);
  FUN_001268f4(uVar3,uVar3,lVar1);
  return;
}


/* @00129d80  size=32 */

void gd_handle_glMultiDrawElementsBaseVertex(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glMultiDrawElementsBaseVertex");
  return;
}


/* @00129da0  size=168 */

void gd_handle_glMultiTexCoord4f(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  
  param_1 = param_1 + 0x68;
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  uVar6 = ArrayBuffer_getFloat(param_1);
  uVar7 = ArrayBuffer_getFloat(param_1);
  uVar8 = ArrayBuffer_getFloat(param_1);
  iVar2 = iVar2 + -0x84c0;
  if (iVar2 < 8) {
    plVar3 = (long *)(&currentRenderer);
    lVar1 = *plVar3 + (long)iVar2 * 0x10;
    lVar4 = *plVar3 + (long)iVar2 * 0x18;
    iVar2 = *(int *)(lVar4 + 0x634);
    *(uint32_t *)(lVar1 + 200) = uVar5;
    *(uint32_t *)(lVar1 + 0xcc) = uVar6;
    *(uint32_t *)(lVar1 + 0xd0) = uVar7;
    *(uint32_t *)(lVar1 + 0xd4) = uVar8;
    *(int *)(lVar4 + 0x634) = iVar2 + 1;
  }
  return;
}


/* @00129e48  size=72 */

void gd_handle_glNewList(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glNewList");
  return;
}


/* @00129e90  size=116 */

void gd_handle_glNormal3f(long param_1)

{
  long *plVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  plVar1 = (long *)(&currentRenderer);
  lVar2 = *plVar1;
  *(uint32_t *)(lVar2 + 0xbc) = uVar3;
  *(uint32_t *)(lVar2 + 0xc0) = uVar4;
  *(uint32_t *)(lVar2 + 0xc4) = uVar5;
  *(int *)(lVar2 + 0x61c) = *(int *)(lVar2 + 0x61c) + 1;
  return;
}


/* @00129f04  size=228 */

void gd_handle_glNormalPointer(long param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  short sVar7;
  long lVar8;
  
  param_1 = param_1 + 0x68;
  cVar2 = ArrayBuffer_get(param_1);
  iVar3 = ArrayBuffer_getInt(param_1);
  iVar4 = ArrayBuffer_getInt(param_1);
  sVar7 = (short)iVar4;
  plVar5 = (long *)(&currentRenderer);
  lVar8 = *plVar5;
  GLVertexArrayObject_setAttribState(lVar8 + 0x398,2,1,0);
  lVar6 = *(long *)(lVar8 + 0x540);
  bVar1 = false;
  *(int *)(lVar6 + 0x54) = (int)cVar2;
  *(int *)(lVar6 + 0x4c) = iVar3;
  if ((iVar3 != 0x1406) && (iVar3 != 0x140b)) {
    bVar1 = *(long *)(lVar8 + 0x560) != 0;
  }
  *(bool *)(lVar6 + 0x48) = bVar1;
  if ((iVar4 < 1) && (*(long *)(lVar8 + 0x560) == 0)) {
    if (iVar3 - 0x1400U < 0xb) {
      sVar7 = (short)*(uint32_t *)(&DAT_001159d8 + (long)(int)(iVar3 - 0x1400U) * 4);
    }
    else {
      sVar7 = 0;
    }
    sVar7 = sVar7 * cVar2;
  }
  *(short *)(lVar6 + 0x60) = sVar7;
  return;
}


/* @00129fe8  size=324 */

void gd_handle_glOrtho(long param_1)

{
  long lVar1;
  uint64_t *puVar2;
  uint64_t uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  float fVar10;
  uint64_t uVar11;
  float local_78 [6];
  uint64_t local_60;
  uint64_t uStack_58;
  float local_50;
  uint32_t local_4c;
  uint64_t local_48;
  float local_40;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  dVar4 = (double)ArrayBuffer_getDouble(param_1);
  dVar5 = (double)ArrayBuffer_getDouble(param_1);
  dVar6 = (double)ArrayBuffer_getDouble(param_1);
  dVar7 = (double)ArrayBuffer_getDouble(param_1);
  dVar8 = (double)ArrayBuffer_getDouble(param_1);
  dVar9 = (double)ArrayBuffer_getDouble(param_1);
  puVar2 = (uint64_t *)(&currentRenderer);
  uVar3 = GLRenderer_getCurrentMatrix(*puVar2);
  uVar11 = NEON_fmov(0x3f800000,4);
  local_50 = 1.0 / ((float)dVar9 - (float)dVar8);
  fVar10 = (float)uVar11 / ((float)dVar5 - (float)dVar4);
  local_78[5] = (float)((unsigned long)uVar11 >> 0x20) / ((float)dVar7 - (float)dVar6);
  local_78[3] = 0.0;
  local_78[4] = 0.0;
  local_78[1] = 0.0;
  local_78[2] = 0.0;
  uStack_58 = 0;
  local_60 = 0;
  local_40 = local_50 * -((float)dVar8 + (float)dVar9);
  local_50 = local_50 * -2.0;
  local_78[0] = fVar10 + fVar10;
  local_48 = ((uint64_t)(local_78[5] * (-(float)(dVar6 + (float)dVar7))) << 32 | (uint32_t)
                      (fVar10 * (-(float)(dVar4 + (float)dVar5))));
  local_78[5] = local_78[5] + local_78[5];
  local_4c = 0;
  local_3c = 0x3f800000;
  FUN_001268f4(uVar3,uVar3,local_78);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012a12c  size=52 */

void gd_handle_glPassThrough(long param_1)

{
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glPassThrough");
  return;
}


/* @0012a160  size=292 */

void gd_handle_glPatchParameterfv(long param_1)

{
  int iVar1;
  uint64_t uVar2;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  if (iVar1 < 0x1204) {
    if (iVar1 < 0x1200) {
      if ((iVar1 == 0xb66) || (iVar1 == 0x1004)) goto LAB_0012a220;
    }
    else if ((iVar1 - 0x1200U < 3) || (iVar1 == 0x1203)) {
LAB_0012a220:
      uVar2 = 0x10;
      goto LAB_0012a224;
    }
  }
  else {
    if (iVar1 < 0x2201) {
      if (iVar1 == 0x1204) {
LAB_0012a274:
        uVar2 = 0xc;
        goto LAB_0012a224;
      }
      if ((iVar1 != 0x1600) && (iVar1 != 0x1602)) goto LAB_0012a26c;
      goto LAB_0012a220;
    }
    if (iVar1 < 0x8e73) {
      if (iVar1 == 0x2201) goto LAB_0012a220;
      if (iVar1 == 0x8129) goto LAB_0012a274;
    }
    else {
      if (iVar1 == 0x8e73) {
        uVar2 = 8;
        goto LAB_0012a224;
      }
      if (iVar1 == 0x8e74) goto LAB_0012a220;
    }
  }
LAB_0012a26c:
  uVar2 = 4;
LAB_0012a224:
  ArrayBuffer_getBytes(param_1 + 0x68,uVar2);
  __android_log_print(3,"System.out","%s not implemented yet","glPatchParameterfv");
  return;
}


/* @0012a284  size=56 */

void gd_handle_glPatchParameteri(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glPatchParameteri(uVar1,uVar2);
  return;
}


/* @0012a2bc  size=32 */

void gd_handle_glPixelMapfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPixelMapfv");
  return;
}


/* @0012a2dc  size=32 */

void gd_handle_glPixelMapuiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPixelMapuiv");
  return;
}


/* @0012a2fc  size=32 */

void gd_handle_glPixelMapusv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPixelMapusv");
  return;
}


/* @0012a31c  size=84 */

void gd_handle_glPixelStorei(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  if ((iVar1 != 0xcf5) && (iVar1 != 0xd05)) {
    glPixelStorei(iVar1,uVar2);
    return;
  }
  return;
}


/* @0012a370  size=72 */

void gd_handle_glPixelTransferf(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getFloat(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glPixelTransferf");
  return;
}


/* @0012a3b8  size=72 */

void gd_handle_glPixelTransferi(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glPixelTransferi");
  return;
}


/* @0012a400  size=84 */

void gd_handle_glPixelZoom(long param_1)

{
  uint64_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  uVar2 = ArrayBuffer_getFloat(param_1 + 0x68);
  uVar3 = ArrayBuffer_getFloat(param_1 + 0x68);
  puVar1 = (uint64_t *)(&currentRenderer);
  GLRenderer_setPixelZoom(uVar2,uVar3,*puVar1);
  return;
}


/* @0012a454  size=128 */

void gd_handle_glPointParameterf(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint64_t *puVar3;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  local_3c = ArrayBuffer_getFloat(param_1 + 0x68);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setPointParams(*puVar3,uVar2,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012a4d4  size=296 */

void gd_handle_glPointParameterfv(long param_1)

{
  int iVar1;
  uint64_t *puVar2;
  uint64_t uVar3;
  
  iVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  if (iVar1 < 0x1204) {
    if (iVar1 < 0x1200) {
      if ((iVar1 == 0xb66) || (iVar1 == 0x1004)) goto LAB_0012a598;
    }
    else if ((iVar1 - 0x1200U < 3) || (iVar1 == 0x1203)) {
LAB_0012a598:
      uVar3 = 0x10;
      goto LAB_0012a59c;
    }
  }
  else {
    if (iVar1 < 0x2201) {
      if (iVar1 == 0x1204) {
LAB_0012a5ec:
        uVar3 = 0xc;
        goto LAB_0012a59c;
      }
      if ((iVar1 != 0x1600) && (iVar1 != 0x1602)) goto LAB_0012a5e4;
      goto LAB_0012a598;
    }
    if (iVar1 < 0x8e73) {
      if (iVar1 == 0x2201) goto LAB_0012a598;
      if (iVar1 == 0x8129) goto LAB_0012a5ec;
    }
    else {
      if (iVar1 == 0x8e73) {
        uVar3 = 8;
        goto LAB_0012a59c;
      }
      if (iVar1 == 0x8e74) goto LAB_0012a598;
    }
  }
LAB_0012a5e4:
  uVar3 = 4;
LAB_0012a59c:
  uVar3 = ArrayBuffer_getBytes(param_1 + 0x68,uVar3);
  puVar2 = (uint64_t *)(&currentRenderer);
  GLRenderer_setPointParams(*puVar2,iVar1,uVar3);
  return;
}


/* @0012a5fc  size=128 */

void gd_handle_glPointParameteri(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint64_t *puVar3;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  local_3c = ArrayBuffer_getInt(param_1 + 0x68);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setPointParams(*puVar3,uVar2,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012a67c  size=32 */

void gd_handle_glPointParameteriv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPointParameteriv");
  return;
}


/* @0012a69c  size=56 */

void gd_handle_glPointSize(long param_1)

{
  long *plVar1;
  uint32_t uVar2;
  
  uVar2 = ArrayBuffer_getFloat(param_1 + 0x68);
  plVar1 = (long *)(&currentRenderer);
  *(uint32_t *)(*plVar1 + 0x88) = uVar2;
  return;
}


/* @0012a6d4  size=68 */

void gd_handle_glPolygonMode(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  
  ArrayBuffer_getInt(param_1 + 0x68);
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  *(uint32_t *)(*plVar2 + 0x48) = uVar1;
  return;
}


/* @0012a718  size=64 */

void gd_handle_glPolygonOffset(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getFloat(param_1 + 0x68);
  uVar2 = ArrayBuffer_getFloat(param_1 + 0x68);
  glPolygonOffset(uVar1,uVar2);
  return;
}


/* @0012a758  size=32 */

void gd_handle_glPolygonStipple(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPolygonStipple");
  return;
}


/* @0012a778  size=4 */

void gd_handle_glPopAttrib(void)

{
  AttribStack_pop();
  return;
}


/* @0012a77c  size=32 */

void gd_handle_glPopClientAttrib(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPopClientAttrib");
  return;
}


/* @0012a79c  size=32 */

void gd_handle_glPopMatrix(void)

{
  uint64_t *puVar1;
  
  puVar1 = (uint64_t *)(&currentRenderer);
  GLRenderer_popMatrix(*puVar1);
  return;
}


/* @0012a7bc  size=32 */

void gd_handle_glPopName(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPopName");
  return;
}


/* @0012a7dc  size=32 */

void gd_handle_glPrioritizeTextures(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glPrioritizeTextures");
  return;
}


/* @0012a7fc  size=144 */

void gd_handle_glProgramEnvParameter4fARB(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  uVar6 = ArrayBuffer_getFloat(param_1);
  ARBProgram_setEnvParameter(uVar3,uVar4,uVar5,uVar6,uVar1,uVar2);
  return;
}


/* @0012a88c  size=152 */

void gd_handle_glProgramLocalParameter4fARB(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  uVar6 = ArrayBuffer_getFloat(param_1);
  uVar7 = ArrayBuffer_getFloat(param_1);
  uVar3 = ARBProgram_getBound(uVar1);
  ARBProgram_setLocalParameter(uVar4,uVar5,uVar6,uVar7,uVar3,uVar2);
  return;
}


/* @0012a924  size=104 */

void gd_handle_glProgramStringARB(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint64_t uVar5;
  long lVar6;
  
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar6 = *(long *)(param_1 + 0x78);
  iVar1 = *(int *)(param_1 + 0x6c);
  uVar5 = ARBProgram_getBound(uVar2);
  ARBProgram_setSource(uVar5,uVar3,lVar6 + iVar1,uVar4);
  return;
}


/* @0012a98c  size=52 */

void gd_handle_glProvokingVertex(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glProvokingVertex");
  return;
}


/* @0012a9c0  size=24 */

void gd_handle_glPushAttrib(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  AttribStack_push();
  return;
}


/* @0012a9d8  size=52 */

void gd_handle_glPushClientAttrib(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glPushClientAttrib");
  return;
}


/* @0012aa0c  size=32 */

void gd_handle_glPushMatrix(void)

{
  uint64_t *puVar1;
  
  puVar1 = (uint64_t *)(&currentRenderer);
  GLRenderer_pushMatrix(*puVar1);
  return;
}


/* @0012aa2c  size=52 */

void gd_handle_glPushName(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glPushName");
  return;
}


/* @0012aa60  size=56 */

void gd_handle_glQueryCounter(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  GLQuery_queryCounter(uVar1,uVar2);
  return;
}


/* @0012aa98  size=128 */

void gd_handle_glRasterPos4f(long param_1)

{
  uint64_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  puVar1 = (uint64_t *)(&currentRenderer);
  GLRenderer_setRasterPos(uVar2,uVar3,uVar4,uVar5,*puVar1,1);
  return;
}


/* @0012ab18  size=24 */

void gd_handle_glReadBuffer(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  GLFramebuffer_setReadBuffer();
  return;
}


/* @0012ab30  size=1012 */

void gd_handle_glReadPixels(long param_1)

{
  uint32_t uVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint32_t uVar10;
  long lVar11;
  uint64_t *puVar12;
  uint64_t uVar13;
  unsigned long uVar14;
  void *__src;
  int iVar15;
  int iVar16;
  int iVar17;
  uint32_t uVar18;
  uint32_t local_7c;
  uint32_t local_74;
  uint16_t local_70;
  uint32_t local_6e;
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar2 + 0x28);
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar8 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar9 = ArrayBuffer_getInt(param_1 + 0x68);
  lVar11 = GLBuffer_getBound(0x88eb);
  if (lVar11 == 0) {
    iVar15 = 0;
    if (iVar8 < 0x80e1) {
      switch(iVar8) {
      case 0x1903:
      case 0x1904:
      case 0x1905:
      case 0x1906:
      case 0x1909:
        goto switchD_0012ac58_caseD_8d94;
      case 0x1907:
switchD_0012ac58_caseD_8d98:
        iVar15 = 3;
        break;
      case 0x1908:
        goto switchD_0012ac58_caseD_8d99;
      case 0x190a:
switchD_0012ac80_caseD_190a:
        iVar15 = 2;
        break;
      default:
        if (iVar8 == 0x80e0) goto switchD_0012ac58_caseD_8d98;
      }
    }
    else {
      switch(iVar8) {
      case 0x8d94:
switchD_0012ac58_caseD_8d94:
        iVar15 = 1;
        break;
      case 0x8d95:
      case 0x8d96:
      case 0x8d97:
        break;
      case 0x8d98:
      case 0x8d9a:
        goto switchD_0012ac58_caseD_8d98;
      case 0x8d99:
      case 0x8d9b:
switchD_0012ac58_caseD_8d99:
        iVar15 = 4;
        break;
      default:
        if (iVar8 - 0x8227U < 2) goto switchD_0012ac80_caseD_190a;
        if (iVar8 == 0x80e1) goto switchD_0012ac58_caseD_8d99;
      }
    }
    iVar16 = 0;
    if (iVar9 < 0x8035) {
      uVar18 = iVar9 - 0x1400;
      if (uVar18 < 0xc) {
        uVar1 = 1 << (unsigned long)(uVar18 & 0x1f);
        if ((uVar1 & 0x70) == 0) {
          if ((uVar1 & 0x80c) == 0) {
            if ((1 << (unsigned long)(uVar18 & 0x1f) & 3U) == 0) goto LAB_0012ad6c;
            goto LAB_0012ada0;
          }
          iVar16 = 2;
        }
        else {
          iVar16 = 4;
        }
      }
      else {
LAB_0012ad6c:
        if (1 < iVar9 - 0x8033U) {
          iVar17 = 0x8032;
          goto LAB_0012ad94;
        }
LAB_0012ad7c:
        iVar16 = 2;
        iVar15 = 1;
      }
    }
    else {
      if (iVar9 < 0x8363) {
        if (1 < iVar9 - 0x8035U) {
          iVar17 = 0x8362;
LAB_0012ad94:
          if (iVar9 == iVar17) {
            iVar15 = 1;
LAB_0012ada0:
            iVar16 = 1;
          }
          goto LAB_0012ada4;
        }
      }
      else {
        if (iVar9 - 0x8363U < 4) goto LAB_0012ad7c;
        if (iVar9 != 0x8367) goto LAB_0012ada4;
      }
      iVar16 = 4;
      iVar15 = 1;
    }
LAB_0012ada4:
    uVar13 = *(uint64_t *)(param_1 + 0x10);
    uVar18 = iVar7 * iVar6 * iVar15 * iVar16;
    local_70 = 0x19a;
    local_6e = 4;
    local_74 = uVar18;
    uVar14 = RingBuffer_write(uVar13,&local_70,6);
    if ((uVar14 & 1) != 0) {
      RingBuffer_write(uVar13,&local_74,4);
      uVar18 = local_74;
    }
    if ((int)uVar18 < 1) goto LAB_0012abf4;
    uVar14 = RingBuffer_waitForWrite(*(uint64_t *)(param_1 + 0x10),uVar18);
    if ((uVar14 & 1) != 0) {
      uVar10 = RingBuffer_getTail(*(uint64_t *)(param_1 + 0x10));
      uVar3 = local_74;
      uVar1 = *(uint32_t *)(*(long *)(param_1 + 0x10) + 0x28);
      uVar18 = uVar1 - 1 & uVar10;
      if (uVar1 < uVar18 + local_74) {
        __src = malloc((long)(int)local_74);
        uVar14 = (unsigned long)uVar3;
        local_7c = uVar3;
      }
      else {
        uVar14 = *(unsigned long *)(*(long *)(param_1 + 0x10) + 0x18);
        local_7c = 0;
        __src = (void *)(uVar14 + uVar18);
      }
      puVar12 = (uint64_t *)__emutls_get_address(uVar14,currentRenderer);
      GLRenderer_readPixels(*puVar12,uVar4,uVar5,iVar6,iVar7,iVar8,iVar9,__src);
      if (local_7c != 0) {
        uVar1 = *(int *)(*(long *)(param_1 + 0x10) + 0x28) - uVar18;
        memcpy((void *)(*(long *)(*(long *)(param_1 + 0x10) + 0x18) + (unsigned long)uVar18),__src,
               (unsigned long)uVar1);
        memcpy(*(void **)(*(long *)(param_1 + 0x10) + 0x18),(void *)((long)__src + (unsigned long)uVar1),
               (unsigned long)(local_7c - uVar1));
        free(__src);
      }
      if (uVar3 + uVar10 != 0) {
        RingBuffer_setTail(*(uint64_t *)(param_1 + 0x10),uVar3 + uVar10);
      }
      goto LAB_0012abf4;
    }
    puVar12 = (uint64_t *)(&currentRenderer);
    uVar13 = *puVar12;
    lVar11 = 0;
  }
  else {
    iVar8 = ArrayBuffer_getInt(param_1 + 0x68);
    lVar11 = (long)iVar8;
    puVar12 = (uint64_t *)(&currentRenderer);
    uVar13 = *puVar12;
    iVar8 = 0x1908;
    iVar9 = 0x1401;
  }
  GLRenderer_readPixels(uVar13,uVar4,uVar5,iVar6,iVar7,iVar8,iVar9,lVar11);
LAB_0012abf4:
  if (*(long *)(lVar2 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012af24  size=4 */

void gd_handle_glReleaseShaderCompiler(void)

{
  glReleaseShaderCompiler();
  return;
}


/* @0012af28  size=52 */

void gd_handle_glRenderMode(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glRenderMode");
  return;
}


/* @0012af5c  size=108 */

void gd_handle_glRenderbufferStorage(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getInt(param_1);
  iVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  iVar1 = 0x81a6;
  if (iVar3 != 0x1902) {
    iVar1 = iVar3;
  }
  glRenderbufferStorage(uVar2,iVar1,uVar4,uVar5);
  return;
}


/* @0012afc8  size=132 */

void gd_handle_glRenderbufferStorageMultisample(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  iVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  uVar6 = ArrayBuffer_getInt(param_1);
  iVar1 = 0x81a6;
  if (iVar4 != 0x1902) {
    iVar1 = iVar4;
  }
  glRenderbufferStorageMultisample(uVar2,uVar3,iVar1,uVar5,uVar6);
  return;
}


/* @0012b04c  size=396 */

void gd_handle_glRotatef(long param_1)

{
  uint64_t *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float local_8;
  float fStack_4;
  
  param_1 = param_1 + 0x68;
  fVar2 = (float)ArrayBuffer_getFloat(param_1);
  fVar3 = (float)ArrayBuffer_getFloat(param_1);
  fVar4 = (float)ArrayBuffer_getFloat(param_1);
  fVar5 = (float)ArrayBuffer_getFloat(param_1);
  puVar1 = (uint64_t *)(&currentRenderer);
  puVar1 = (uint64_t *)GLRenderer_getCurrentMatrix(*puVar1);
  fVar6 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);
  if (1e-06 <= ABS(fVar6)) {
    fVar6 = 1.0 / fVar6;
    fVar3 = fVar3 * fVar6;
    fVar4 = fVar4 * fVar6;
    fVar5 = fVar5 * fVar6;
    sincosf(fVar2 * 0.017453292,&fStack_4,&local_8);
    fVar6 = 1.0 - local_8;
    fVar16 = fVar6 * fVar4 * fVar3;
    fVar17 = fVar6 * fVar5 * fVar3;
    fVar2 = fVar6 * fVar5 * fVar4;
    fVar15 = local_8 + fVar6 * fVar3 * fVar3;
    fVar19 = fStack_4 * fVar5 + fVar16;
    fVar21 = fVar17 - fStack_4 * fVar4;
    fVar16 = fVar16 - fStack_4 * fVar5;
    fVar18 = local_8 + fVar6 * fVar4 * fVar4;
    fVar20 = fStack_4 * fVar3 + fVar2;
    fVar17 = fStack_4 * fVar4 + fVar17;
    fVar2 = fVar2 - fStack_4 * fVar3;
    local_8 = local_8 + fVar6 * fVar5 * fVar5;
    fVar3 = (float)*puVar1;
    fVar4 = (float)((unsigned long)*puVar1 >> 0x20);
    fVar5 = (float)puVar1[1];
    fVar6 = (float)((unsigned long)puVar1[1] >> 0x20);
    fVar7 = (float)puVar1[2];
    fVar8 = (float)((unsigned long)puVar1[2] >> 0x20);
    fVar9 = (float)puVar1[3];
    fVar10 = (float)((unsigned long)puVar1[3] >> 0x20);
    fVar11 = (float)puVar1[4];
    fVar12 = (float)((unsigned long)puVar1[4] >> 0x20);
    fVar13 = (float)puVar1[5];
    fVar14 = (float)((unsigned long)puVar1[5] >> 0x20);
    puVar1[1] = ((uint64_t)(fVar6 * fVar15 + fVar10 * fVar19 + fVar14 * fVar21) << 32 | (uint32_t)(
                         fVar5 * fVar15 + fVar9 * fVar19 + fVar13 * fVar21));
    *puVar1 = ((uint64_t)(fVar4 * fVar15 + fVar8 * fVar19 + fVar12 * fVar21) << 32 | (uint32_t)(
                       fVar3 * fVar15 + fVar7 * fVar19 + fVar11 * fVar21));
    puVar1[3] = ((uint64_t)(fVar6 * fVar16 + fVar10 * fVar18 + fVar14 * fVar20) << 32 | (uint32_t)(
                         fVar5 * fVar16 + fVar9 * fVar18 + fVar13 * fVar20));
    puVar1[2] = ((uint64_t)(fVar4 * fVar16 + fVar8 * fVar18 + fVar12 * fVar20) << 32 | (uint32_t)(
                         fVar3 * fVar16 + fVar7 * fVar18 + fVar11 * fVar20));
    puVar1[5] = ((uint64_t)(fVar6 * fVar17 + fVar10 * fVar2 + fVar14 * local_8) << 32 | (uint32_t)(
                         fVar5 * fVar17 + fVar9 * fVar2 + fVar13 * local_8));
    puVar1[4] = ((uint64_t)(fVar4 * fVar17 + fVar8 * fVar2 + fVar12 * local_8) << 32 | (uint32_t)(
                         fVar3 * fVar17 + fVar7 * fVar2 + fVar11 * local_8));
  }
  return;
}


/* @0012b1d8  size=60 */

void gd_handle_glSampleCoverage(long param_1)

{
  uint32_t uVar1;
  
  uVar1 = ArrayBuffer_getFloat(param_1 + 0x68);
  ArrayBuffer_get(param_1 + 0x68);
  glSampleCoverage(uVar1, 0);
  return;
}


/* @0012b214  size=56 */

void gd_handle_glSampleMaski(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glSampleMaski(uVar1,uVar2);
  return;
}


/* @0012b24c  size=144 */

void gd_handle_glSamplerParameterf(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  local_3c = ArrayBuffer_getFloat(param_1);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_setSamplerParameter(*puVar4,uVar2,uVar3,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012b2dc  size=320 */

void gd_handle_glSamplerParameterfv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  if (iVar2 < 0x1204) {
    if (iVar2 < 0x1200) {
      if ((iVar2 == 0xb66) || (iVar2 == 0x1004)) goto LAB_0012b3b0;
    }
    else if ((iVar2 - 0x1200U < 3) || (iVar2 == 0x1203)) {
LAB_0012b3b0:
      uVar4 = 0x10;
      goto LAB_0012b3b4;
    }
  }
  else {
    if (iVar2 < 0x2201) {
      if (iVar2 == 0x1204) {
LAB_0012b40c:
        uVar4 = 0xc;
        goto LAB_0012b3b4;
      }
      if ((iVar2 != 0x1600) && (iVar2 != 0x1602)) goto LAB_0012b404;
      goto LAB_0012b3b0;
    }
    if (iVar2 < 0x8e73) {
      if (iVar2 == 0x2201) goto LAB_0012b3b0;
      if (iVar2 == 0x8129) goto LAB_0012b40c;
    }
    else {
      if (iVar2 == 0x8e73) {
        uVar4 = 8;
        goto LAB_0012b3b4;
      }
      if (iVar2 == 0x8e74) goto LAB_0012b3b0;
    }
  }
LAB_0012b404:
  uVar4 = 4;
LAB_0012b3b4:
  uVar4 = ArrayBuffer_getBytes(param_1,uVar4);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setSamplerParameter(*puVar3,uVar1,iVar2,uVar4);
  return;
}


/* @0012b41c  size=132 */

void gd_handle_glScalef(long param_1)

{
  uint64_t *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  param_1 = param_1 + 0x68;
  fVar2 = (float)ArrayBuffer_getFloat(param_1);
  fVar3 = (float)ArrayBuffer_getFloat(param_1);
  fVar4 = (float)ArrayBuffer_getFloat(param_1);
  puVar1 = (uint64_t *)(&currentRenderer);
  puVar1 = (uint64_t *)GLRenderer_getCurrentMatrix(*puVar1);
  puVar1[1] = ((uint64_t)((float)((unsigned long)puVar1[1] >> 0x20) * fVar2) << 32 | (uint32_t)((float)(puVar1[1]) * fVar2));
  *puVar1 = ((uint64_t)((float)((unsigned long)*puVar1 >> 0x20) * fVar2) << 32 | (uint32_t)((float)*puVar1 * fVar2));
  puVar1[3] = ((uint64_t)((float)((unsigned long)puVar1[3] >> 0x20) * fVar3) << 32 | (uint32_t)((float)(puVar1[3]) * fVar3));
  puVar1[2] = ((uint64_t)((float)((unsigned long)puVar1[2] >> 0x20) * fVar3) << 32 | (uint32_t)((float)(puVar1[2]) * fVar3));
  puVar1[5] = ((uint64_t)((float)((unsigned long)puVar1[5] >> 0x20) * fVar4) << 32 | (uint32_t)((float)(puVar1[5]) * fVar4));
  puVar1[4] = ((uint64_t)((float)((unsigned long)puVar1[4] >> 0x20) * fVar4) << 32 | (uint32_t)((float)(puVar1[4]) * fVar4));
  return;
}


/* @0012b4a0  size=96 */

void gd_handle_glScissor(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  glScissor(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012b500  size=80 */

void gd_handle_glSecondaryColor3f(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  ArrayBuffer_getFloat(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glSecondaryColor3f");
  return;
}


/* @0012b550  size=32 */

void gd_handle_glSecondaryColorPointer(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glSecondaryColorPointer");
  return;
}


/* @0012b570  size=32 */

void gd_handle_glSelectBuffer(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glSelectBuffer");
  return;
}


/* @0012b590  size=56 */

void gd_handle_glShadeModel(long param_1)

{
  uint32_t uVar1;
  long *plVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  plVar2 = (long *)(&currentRenderer);
  *(uint32_t *)(*plVar2 + 0x38c) = uVar1;
  return;
}


/* @0012b5c8  size=32 */

void gd_handle_glShaderBinary(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glShaderBinary");
  return;
}


/* @0012b5e8  size=60 */

void gd_handle_glShaderSource(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  ShaderConverter_setShaderSource(uVar1,uVar2,param_1);
  return;
}


/* @0012b624  size=80 */

void gd_handle_glStencilFunc(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glStencilFunc(uVar1,uVar2,uVar3);
  return;
}


/* @0012b674  size=96 */

void gd_handle_glStencilFuncSeparate(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  glStencilFuncSeparate(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012b6d4  size=24 */

void gd_handle_glStencilMask(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glStencilMask(0);
  return;
}


/* @0012b6ec  size=56 */

void gd_handle_glStencilMaskSeparate(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glStencilMaskSeparate(uVar1,uVar2);
  return;
}


/* @0012b724  size=80 */

void gd_handle_glStencilOp(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glStencilOp(uVar1,uVar2,uVar3);
  return;
}


/* @0012b774  size=96 */

void gd_handle_glStencilOpSeparate(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  glStencilOpSeparate(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012b7d4  size=80 */

void gd_handle_glTexBuffer(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glTexBuffer(uVar1,uVar2,uVar3);
  return;
}


/* @0012b824  size=128 */

void gd_handle_glTexCoord4f(long param_1)

{
  long *plVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  
  param_1 = param_1 + 0x68;
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  uVar6 = ArrayBuffer_getFloat(param_1);
  plVar1 = (long *)(&currentRenderer);
  lVar2 = *plVar1;
  *(uint32_t *)(lVar2 + 200) = uVar3;
  *(uint32_t *)(lVar2 + 0xcc) = uVar4;
  *(uint32_t *)(lVar2 + 0xd0) = uVar5;
  *(uint32_t *)(lVar2 + 0xd4) = uVar6;
  *(int *)(lVar2 + 0x634) = *(int *)(lVar2 + 0x634) + 1;
  return;
}


/* @0012b8a4  size=264 */

void gd_handle_glTexCoordPointer(long param_1)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  
  param_1 = param_1 + 0x68;
  cVar4 = ArrayBuffer_get(param_1);
  iVar5 = ArrayBuffer_getInt(param_1);
  iVar6 = ArrayBuffer_getInt(param_1);
  plVar7 = (long *)(&currentRenderer);
  lVar9 = *plVar7;
  GLVertexArrayObject_setAttribState(lVar9 + 0x398,*(uint8_t *)(lVar9 + 0x399) + 3,1,0);
  bVar3 = false;
  lVar8 = *(long *)(lVar9 + 0x540);
  lVar1 = (unsigned long)*(uint8_t *)(*plVar7 + 0x399) + 3;
  lVar2 = lVar8 + lVar1 * 0x20;
  *(int *)(lVar2 + 0x14) = (int)cVar4;
  *(int *)(lVar2 + 0xc) = iVar5;
  if ((iVar5 != 0x1406) && (iVar5 != 0x140b)) {
    bVar3 = *(long *)(lVar9 + 0x560) != 0;
  }
  *(bool *)(lVar2 + 8) = bVar3;
  if ((iVar6 < 1) && (*(long *)(lVar9 + 0x560) == 0)) {
    if (iVar5 - 0x1400U < 0xb) {
      iVar6 = *(int *)(&DAT_001159d8 + (long)(int)(iVar5 - 0x1400U) * 4);
    }
    else {
      iVar6 = 0;
    }
    iVar6 = iVar6 * cVar4;
  }
  *(short *)(lVar8 + lVar1 * 0x20 + 0x20) = (short)iVar6;
  return;
}


/* @0012b9ac  size=144 */

void gd_handle_glTexEnvf(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  local_3c = ArrayBuffer_getFloat(param_1);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_setTexEnvParams(*puVar4,uVar2,uVar3,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012ba3c  size=320 */

void gd_handle_glTexEnvfv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  if (iVar2 < 0x1204) {
    if (iVar2 < 0x1200) {
      if ((iVar2 == 0xb66) || (iVar2 == 0x1004)) goto LAB_0012bb10;
    }
    else if ((iVar2 - 0x1200U < 3) || (iVar2 == 0x1203)) {
LAB_0012bb10:
      uVar4 = 0x10;
      goto LAB_0012bb14;
    }
  }
  else {
    if (iVar2 < 0x2201) {
      if (iVar2 == 0x1204) {
LAB_0012bb6c:
        uVar4 = 0xc;
        goto LAB_0012bb14;
      }
      if ((iVar2 != 0x1600) && (iVar2 != 0x1602)) goto LAB_0012bb64;
      goto LAB_0012bb10;
    }
    if (iVar2 < 0x8e73) {
      if (iVar2 == 0x2201) goto LAB_0012bb10;
      if (iVar2 == 0x8129) goto LAB_0012bb6c;
    }
    else {
      if (iVar2 == 0x8e73) {
        uVar4 = 8;
        goto LAB_0012bb14;
      }
      if (iVar2 == 0x8e74) goto LAB_0012bb10;
    }
  }
LAB_0012bb64:
  uVar4 = 4;
LAB_0012bb14:
  uVar4 = ArrayBuffer_getBytes(param_1,uVar4);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setTexEnvParams(*puVar3,uVar1,iVar2,uVar4);
  return;
}


/* @0012bb7c  size=80 */

void gd_handle_glTexGend(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getDouble(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glTexGend");
  return;
}


/* @0012bbcc  size=32 */

void gd_handle_glTexGendv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glTexGendv");
  return;
}


/* @0012bbec  size=80 */

void gd_handle_glTexGenf(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getFloat(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glTexGenf");
  return;
}


/* @0012bc3c  size=32 */

void gd_handle_glTexGenfv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glTexGenfv");
  return;
}


/* @0012bc5c  size=80 */

void gd_handle_glTexGeni(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glTexGeni");
  return;
}


/* @0012bcac  size=32 */

void gd_handle_glTexGeniv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glTexGeniv");
  return;
}


/* @0012bccc  size=716 */

void gd_handle_glTexImage2D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  int iVar10;
  uint32_t uVar11;
  long lVar12;
  unsigned long uVar13;
  void *__dest;
  int iVar14;
  void *__ptr;
  uint32_t local_7c;
  uint32_t local_78;
  uint32_t local_74;
  void *local_70;
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar3 + 0x28);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  local_74 = uVar6;
  uVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar8 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar9 = ArrayBuffer_getInt(param_1 + 0x68);
  local_78 = ArrayBuffer_getInt(param_1 + 0x68);
  local_7c = ArrayBuffer_getInt(param_1 + 0x68);
  iVar10 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar14 = 0xde1;
  if (((iVar4 != 0xde0) && (iVar4 != 0x84f5)) && (iVar14 = iVar4, iVar4 == 0x8c18)) {
    iVar14 = 0x8c1a;
  }
  lVar12 = GLBuffer_getBound(0x88ec);
  if (lVar12 == 0) {
    local_70 = (void *)0x0;
    if ((iVar10 == 0) ||
       (uVar13 = RingBuffer_waitForRead(*(uint64_t *)(param_1 + 0x18),iVar10), (uVar13 & 1) == 0))
    {
      __dest = (void *)0x0;
      __ptr = (void *)0x0;
      iVar4 = 0;
    }
    else {
      uVar11 = RingBuffer_getHead(*(uint64_t *)(param_1 + 0x18));
      lVar12 = *(long *)(param_1 + 0x18);
      uVar2 = *(uint32_t *)(lVar12 + 0x28);
      uVar1 = uVar2 - 1 & uVar11;
      if (uVar2 < uVar1 + iVar10) {
        __dest = malloc((long)iVar10);
        uVar2 = uVar2 - uVar1;
        local_70 = __dest;
        memcpy(__dest,(void *)(*(long *)(lVar12 + 0x18) + (unsigned long)uVar1),(unsigned long)uVar2);
        memcpy((void *)((long)__dest + (unsigned long)uVar2),*(void **)(*(long *)(param_1 + 0x18) + 0x18),
               (unsigned long)(iVar10 - uVar2));
        __ptr = __dest;
      }
      else {
        __ptr = (void *)0x0;
        __dest = (void *)(*(long *)(lVar12 + 0x18) + (unsigned long)uVar1);
        local_70 = __dest;
      }
      iVar4 = uVar11 + iVar10;
    }
    FUN_0012bf98(iVar14,&local_74,&local_78,&local_7c,&local_70,iVar10);
    glTexImage2D(iVar14,iVar5,local_74,uVar7,uVar8,uVar9,local_78,local_7c,__dest);
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (iVar4 != 0) {
      RingBuffer_setHead(*(uint64_t *)(param_1 + 0x18),iVar4);
    }
  }
  else {
    iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
    FUN_0012bf98(iVar14,&local_74,&local_78,&local_7c,0,0);
    glTexImage2D(iVar14,iVar5,local_74,uVar7,uVar8,uVar9,local_78,local_7c,
                 *(long *)(lVar12 + 8) + (long)iVar4);
    local_70 = (void *)CONCAT26((*(uint16_t*)((char*)&local_70 + 6)),0x1bd);
    RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_70,6);
  }
  lVar12 = GLTexture_getBound(iVar14);
  if ((lVar12 != 0) && (iVar5 == 0)) {
    *(short *)(lVar12 + 0xc) = (short)uVar7;
    *(short *)(lVar12 + 0xe) = (short)uVar8;
    *(uint32_t *)(lVar12 + 8) = uVar6;
    if (*(char *)(lVar12 + 0x10) != '\0') {
      glGenerateMipmap(iVar14);
    }
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012c630  size=136 */

void gd_handle_glTexImage2DMultisample(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  uVar6 = ArrayBuffer_get(param_1);
  glTexStorage2DMultisample(uVar1,uVar2,uVar3,uVar4,uVar5,uVar6);
  return;
}


/* @0012c6b8  size=680 */

void gd_handle_glTexImage3D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  int iVar10;
  uint32_t uVar11;
  long lVar12;
  unsigned long uVar13;
  void *__dest;
  int iVar14;
  void *__ptr;
  uint32_t local_7c;
  uint32_t local_78;
  uint32_t local_74;
  void *local_70;
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar3 + 0x28);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  local_74 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar8 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar9 = ArrayBuffer_getInt(param_1 + 0x68);
  local_78 = ArrayBuffer_getInt(param_1 + 0x68);
  local_7c = ArrayBuffer_getInt(param_1 + 0x68);
  iVar10 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar14 = 0xde1;
  if (((iVar4 != 0xde0) && (iVar4 != 0x84f5)) && (iVar14 = iVar4, iVar4 == 0x8c18)) {
    iVar14 = 0x8c1a;
  }
  lVar12 = GLBuffer_getBound(0x88ec);
  if (lVar12 == 0) {
    local_70 = (void *)0x0;
    if ((iVar10 == 0) ||
       (uVar13 = RingBuffer_waitForRead(*(uint64_t *)(param_1 + 0x18),iVar10), (uVar13 & 1) == 0))
    {
      __dest = (void *)0x0;
      __ptr = (void *)0x0;
      iVar4 = 0;
    }
    else {
      uVar11 = RingBuffer_getHead(*(uint64_t *)(param_1 + 0x18));
      lVar12 = *(long *)(param_1 + 0x18);
      uVar2 = *(uint32_t *)(lVar12 + 0x28);
      uVar1 = uVar2 - 1 & uVar11;
      if (uVar2 < uVar1 + iVar10) {
        __dest = malloc((long)iVar10);
        uVar2 = uVar2 - uVar1;
        local_70 = __dest;
        memcpy(__dest,(void *)(*(long *)(lVar12 + 0x18) + (unsigned long)uVar1),(unsigned long)uVar2);
        memcpy((void *)((long)__dest + (unsigned long)uVar2),*(void **)(*(long *)(param_1 + 0x18) + 0x18),
               (unsigned long)(iVar10 - uVar2));
        __ptr = __dest;
      }
      else {
        __ptr = (void *)0x0;
        __dest = (void *)(*(long *)(lVar12 + 0x18) + (unsigned long)uVar1);
        local_70 = __dest;
      }
      iVar4 = uVar11 + iVar10;
    }
    FUN_0012bf98(iVar14,&local_74,&local_78,&local_7c,&local_70,iVar10);
    glTexImage3D(iVar14,uVar5,local_74,uVar6,uVar7,uVar8,uVar9,local_78,local_7c,__dest);
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (iVar4 != 0) {
      RingBuffer_setHead(*(uint64_t *)(param_1 + 0x18),iVar4);
    }
  }
  else {
    iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
    FUN_0012bf98(iVar14,&local_74,&local_78,&local_7c,0,0);
    glTexImage3D(iVar14,uVar5,local_74,uVar6,uVar7,uVar8,uVar9,local_78,local_7c,
                 *(long *)(lVar12 + 8) + (long)iVar4);
    local_70 = (void *)CONCAT26((*(uint16_t*)((char*)&local_70 + 6)),0x1bf);
    RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_70,6);
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012c960  size=160 */

void gd_handle_glTexImage3DMultisample(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  uVar6 = ArrayBuffer_getInt(param_1);
  uVar7 = ArrayBuffer_get(param_1);
  glTexStorage3DMultisample(uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7);
  return;
}


/* @0012ca00  size=144 */

void gd_handle_glTexParameterf(long param_1)

{
  long lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  local_3c = ArrayBuffer_getFloat(param_1);
  puVar4 = (uint64_t *)(&currentRenderer);
  GLRenderer_setTexParameter(*puVar4,uVar2,uVar3,&local_3c);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012ca90  size=320 */

void gd_handle_glTexParameterfv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  if (iVar2 < 0x1204) {
    if (iVar2 < 0x1200) {
      if ((iVar2 == 0xb66) || (iVar2 == 0x1004)) goto LAB_0012cb64;
    }
    else if ((iVar2 - 0x1200U < 3) || (iVar2 == 0x1203)) {
LAB_0012cb64:
      uVar4 = 0x10;
      goto LAB_0012cb68;
    }
  }
  else {
    if (iVar2 < 0x2201) {
      if (iVar2 == 0x1204) {
LAB_0012cbc0:
        uVar4 = 0xc;
        goto LAB_0012cb68;
      }
      if ((iVar2 != 0x1600) && (iVar2 != 0x1602)) goto LAB_0012cbb8;
      goto LAB_0012cb64;
    }
    if (iVar2 < 0x8e73) {
      if (iVar2 == 0x2201) goto LAB_0012cb64;
      if (iVar2 == 0x8129) goto LAB_0012cbc0;
    }
    else {
      if (iVar2 == 0x8e73) {
        uVar4 = 8;
        goto LAB_0012cb68;
      }
      if (iVar2 == 0x8e74) goto LAB_0012cb64;
    }
  }
LAB_0012cbb8:
  uVar4 = 4;
LAB_0012cb68:
  uVar4 = ArrayBuffer_getBytes(param_1,uVar4);
  puVar3 = (uint64_t *)(&currentRenderer);
  GLRenderer_setTexParameter(*puVar3,uVar1,iVar2,uVar4);
  return;
}


/* @0012cbd0  size=656 */

void gd_handle_glTexSubImage2D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  int iVar10;
  uint32_t uVar11;
  long lVar12;
  unsigned long uVar13;
  void *__dest;
  int iVar14;
  void *__ptr;
  uint32_t local_78;
  uint32_t local_74;
  void *local_70;
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar3 + 0x28);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar8 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar9 = ArrayBuffer_getInt(param_1 + 0x68);
  local_74 = ArrayBuffer_getInt(param_1 + 0x68);
  local_78 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar10 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar14 = 0xde1;
  if (((iVar4 != 0xde0) && (iVar4 != 0x84f5)) && (iVar14 = iVar4, iVar4 == 0x8c18)) {
    iVar14 = 0x8c1a;
  }
  lVar12 = GLBuffer_getBound(0x88ec);
  if (lVar12 == 0) {
    local_70 = (void *)0x0;
    if ((iVar10 == 0) ||
       (uVar13 = RingBuffer_waitForRead(*(uint64_t *)(param_1 + 0x18),iVar10), (uVar13 & 1) == 0))
    {
      __dest = (void *)0x0;
      __ptr = (void *)0x0;
      iVar4 = 0;
    }
    else {
      uVar11 = RingBuffer_getHead(*(uint64_t *)(param_1 + 0x18));
      lVar12 = *(long *)(param_1 + 0x18);
      uVar2 = *(uint32_t *)(lVar12 + 0x28);
      uVar1 = uVar2 - 1 & uVar11;
      if (uVar2 < uVar1 + iVar10) {
        __dest = malloc((long)iVar10);
        uVar2 = uVar2 - uVar1;
        local_70 = __dest;
        memcpy(__dest,(void *)(*(long *)(lVar12 + 0x18) + (unsigned long)uVar1),(unsigned long)uVar2);
        memcpy((void *)((long)__dest + (unsigned long)uVar2),*(void **)(*(long *)(param_1 + 0x18) + 0x18),
               (unsigned long)(iVar10 - uVar2));
        __ptr = __dest;
      }
      else {
        __ptr = (void *)0x0;
        __dest = (void *)(*(long *)(lVar12 + 0x18) + (unsigned long)uVar1);
        local_70 = __dest;
      }
      iVar4 = uVar11 + iVar10;
    }
    FUN_0012bf98(iVar14,0,&local_74,&local_78,&local_70,iVar10);
    glTexSubImage2D(iVar14,uVar5,uVar6,uVar7,uVar8,uVar9,local_74,local_78,__dest);
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (iVar4 != 0) {
      RingBuffer_setHead(*(uint64_t *)(param_1 + 0x18),iVar4);
    }
  }
  else {
    iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
    FUN_0012bf98(iVar14,0,&local_74,&local_78,0,0);
    glTexSubImage2D(iVar14,uVar5,uVar6,uVar7,uVar8,uVar9,local_74,local_78,
                    *(long *)(lVar12 + 8) + (long)iVar4);
    local_70 = (void *)CONCAT26((*(uint16_t*)((char*)&local_70 + 6)),0x1c3);
    RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_70,6);
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012ce60  size=704 */

void gd_handle_glTexSubImage3D(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  int iVar12;
  uint32_t uVar13;
  long lVar14;
  unsigned long uVar15;
  void *__dest;
  void *pvVar16;
  int iVar17;
  uint32_t local_78;
  uint32_t local_74;
  void *local_70;
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar3 + 0x28);
  iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar7 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar8 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar9 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar10 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar11 = ArrayBuffer_getInt(param_1 + 0x68);
  local_74 = ArrayBuffer_getInt(param_1 + 0x68);
  local_78 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar12 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar17 = 0xde1;
  if (((iVar4 != 0xde0) && (iVar4 != 0x84f5)) && (iVar17 = iVar4, iVar4 == 0x8c18)) {
    iVar17 = 0x8c1a;
  }
  lVar14 = GLBuffer_getBound(0x88ec);
  if (lVar14 == 0) {
    local_70 = (void *)0x0;
    if ((iVar12 == 0) ||
       (uVar15 = RingBuffer_waitForRead(*(uint64_t *)(param_1 + 0x18),iVar12), (uVar15 & 1) == 0))
    {
      pvVar16 = (void *)0x0;
      __dest = (void *)0x0;
      iVar4 = 0;
    }
    else {
      uVar13 = RingBuffer_getHead(*(uint64_t *)(param_1 + 0x18));
      lVar14 = *(long *)(param_1 + 0x18);
      uVar2 = *(uint32_t *)(lVar14 + 0x28);
      uVar1 = uVar2 - 1 & uVar13;
      if (uVar2 < uVar1 + iVar12) {
        __dest = malloc((long)iVar12);
        uVar2 = uVar2 - uVar1;
        local_70 = __dest;
        memcpy(__dest,(void *)(*(long *)(lVar14 + 0x18) + (unsigned long)uVar1),(unsigned long)uVar2);
        memcpy((void *)((long)__dest + (unsigned long)uVar2),*(void **)(*(long *)(param_1 + 0x18) + 0x18),
               (unsigned long)(iVar12 - uVar2));
        pvVar16 = __dest;
      }
      else {
        __dest = (void *)0x0;
        pvVar16 = (void *)(*(long *)(lVar14 + 0x18) + (unsigned long)uVar1);
        local_70 = pvVar16;
      }
      iVar4 = uVar13 + iVar12;
    }
    FUN_0012bf98(iVar17,0,&local_74,&local_78,&local_70,iVar12);
    glTexSubImage3D(iVar17,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,local_74,local_78,pvVar16);
    if (__dest != (void *)0x0) {
      free(__dest);
    }
    if (iVar4 != 0) {
      RingBuffer_setHead(*(uint64_t *)(param_1 + 0x18),iVar4);
    }
  }
  else {
    iVar4 = ArrayBuffer_getInt(param_1 + 0x68);
    FUN_0012bf98(iVar17,0,&local_74,&local_78,0,0);
    glTexSubImage3D(iVar17,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,local_74,local_78,
                    *(long *)(lVar14 + 8) + (long)iVar4);
    local_70 = (void *)CONCAT26((*(uint16_t*)((char*)&local_70 + 6)),0x1c4);
    RingBuffer_write(*(uint64_t *)(param_1 + 0x10),&local_70,6);
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012d120  size=32 */

void gd_handle_glTransformFeedbackVaryings(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glTransformFeedbackVaryings");
  return;
}


/* @0012d140  size=140 */

void gd_handle_glTranslatef(long param_1)

{
  uint64_t *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  param_1 = param_1 + 0x68;
  fVar2 = (float)ArrayBuffer_getFloat(param_1);
  fVar3 = (float)ArrayBuffer_getFloat(param_1);
  fVar4 = (float)ArrayBuffer_getFloat(param_1);
  puVar1 = (uint64_t *)(&currentRenderer);
  puVar1 = (uint64_t *)GLRenderer_getCurrentMatrix(*puVar1);
  puVar1[7] = ((uint64_t)((float)((unsigned long)puVar1[7] >> 0x20) +
                       (float)((unsigned long)puVar1[1] >> 0x20) * fVar2 +
                       (float)((unsigned long)puVar1[3] >> 0x20) * fVar3 +
                       (float)((unsigned long)puVar1[5] >> 0x20) * fVar4) << 32 | (uint32_t)(
                       (float)puVar1[7] +
                       (float)puVar1[1] * fVar2 + (float)puVar1[3] * fVar3 +
                       (float)puVar1[5] * fVar4));
  puVar1[6] = ((uint64_t)((float)((unsigned long)puVar1[6] >> 0x20) +
                       (float)((unsigned long)*puVar1 >> 0x20) * fVar2 +
                       (float)((unsigned long)puVar1[2] >> 0x20) * fVar3 +
                       (float)((unsigned long)puVar1[4] >> 0x20) * fVar4) << 32 | (uint32_t)(
                       (float)puVar1[6] +
                       (float)*puVar1 * fVar2 + (float)puVar1[2] * fVar3 + (float)puVar1[4] * fVar4)
  );
  return;
}


/* @0012d1cc  size=52 */

void gd_handle_glUniform1f(long param_1)

{
  uint32_t uVar1;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getFloat(param_1 + 0x68);
  glUniform1f(uVar1, 0);
  return;
}


/* @0012d200  size=84 */

void gd_handle_glUniform1fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 2);
  glUniform1fv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d254  size=56 */

void gd_handle_glUniform1i(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glUniform1i(uVar1,uVar2);
  return;
}


/* @0012d28c  size=84 */

void gd_handle_glUniform1iv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 2);
  glUniform1iv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d2e0  size=56 */

void gd_handle_glUniform1ui(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glUniform1ui(uVar1,uVar2);
  return;
}


/* @0012d318  size=84 */

void gd_handle_glUniform1uiv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 2);
  glUniform1uiv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d36c  size=80 */

void gd_handle_glUniform2f(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  glUniform2f(uVar2,uVar3,uVar1);
  return;
}


/* @0012d3bc  size=84 */

void gd_handle_glUniform2fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 3);
  glUniform2fv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d410  size=80 */

void gd_handle_glUniform2i(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glUniform2i(uVar1,uVar2,uVar3);
  return;
}


/* @0012d460  size=84 */

void gd_handle_glUniform2iv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 3);
  glUniform2iv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d4b4  size=80 */

void gd_handle_glUniform2ui(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glUniform2ui(uVar1,uVar2,uVar3);
  return;
}


/* @0012d504  size=84 */

void gd_handle_glUniform2uiv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 3);
  glUniform2uiv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d558  size=96 */

void gd_handle_glUniform3f(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  glUniform3f(uVar2,uVar3,uVar4,uVar1);
  return;
}


/* @0012d5b8  size=88 */

void gd_handle_glUniform3fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 * 0xc);
  glUniform3fv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d610  size=96 */

void gd_handle_glUniform3i(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  glUniform3i(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012d670  size=88 */

void gd_handle_glUniform3iv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 * 0xc);
  glUniform3iv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d6c8  size=96 */

void gd_handle_glUniform3ui(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  glUniform3ui(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012d728  size=88 */

void gd_handle_glUniform3uiv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 * 0xc);
  glUniform3uiv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d780  size=120 */

void gd_handle_glUniform4f(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  glUniform4f(uVar2,uVar3,uVar4,uVar5,uVar1);
  return;
}


/* @0012d7f8  size=84 */

void gd_handle_glUniform4fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 4);
  glUniform4fv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d84c  size=120 */

void gd_handle_glUniform4i(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  glUniform4i(uVar1,uVar2,uVar3,uVar4,uVar5);
  return;
}


/* @0012d8c4  size=84 */

void gd_handle_glUniform4iv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 4);
  glUniform4iv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d918  size=120 */

void gd_handle_glUniform4ui(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  glUniform4ui(uVar1,uVar2,uVar3,uVar4,uVar5);
  return;
}


/* @0012d990  size=84 */

void gd_handle_glUniform4uiv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getBytes(param_1,iVar2 << 4);
  glUniform4uiv(uVar1,iVar2,uVar3);
  return;
}


/* @0012d9e4  size=80 */

void gd_handle_glUniformBlockBinding(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  glUniformBlockBinding(uVar1,uVar2,uVar3);
  return;
}


/* @0012da34  size=100 */

void gd_handle_glUniformMatrix2fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 << 4);
  glUniformMatrix2fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012da98  size=104 */

void gd_handle_glUniformMatrix2x3fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 * 0x18);
  glUniformMatrix2x3fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012db00  size=100 */

void gd_handle_glUniformMatrix2x4fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 << 5);
  glUniformMatrix2x4fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012db64  size=104 */

void gd_handle_glUniformMatrix3fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 * 0x24);
  glUniformMatrix3fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012dbcc  size=104 */

void gd_handle_glUniformMatrix3x2fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 * 0x18);
  glUniformMatrix3x2fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012dc34  size=104 */

void gd_handle_glUniformMatrix3x4fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 * 0x30);
  glUniformMatrix3x4fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012dc9c  size=100 */

void gd_handle_glUniformMatrix4fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 << 6);
  glUniformMatrix4fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012dd00  size=100 */

void gd_handle_glUniformMatrix4x2fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 << 5);
  glUniformMatrix4x2fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012dd64  size=104 */

void gd_handle_glUniformMatrix4x3fv(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_get(param_1);
  uVar4 = ArrayBuffer_getBytes(param_1,iVar2 * 0x30);
  glUniformMatrix4x3fv(uVar1,iVar2,uVar3,uVar4);
  return;
}


/* @0012ddcc  size=68 */

void gd_handle_glUseProgram(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  long *plVar3;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ShaderConverter_getProgram();
  plVar3 = (long *)(&currentRenderer);
  *(uint64_t *)(*plVar3 + 0x560) = uVar2;
  glUseProgram(uVar1);
  return;
}


/* @0012de10  size=24 */

void gd_handle_glValidateProgram(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  glValidateProgram(0);
  return;
}


/* @0012de28  size=124 */

void gd_handle_glVertex4f(long param_1)

{
  uint64_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  puVar1 = (uint64_t *)(&currentRenderer);
  GLRenderer_addVertex(uVar2,uVar3,uVar4,uVar5,*puVar1);
  return;
}


/* @0012dea4  size=52 */

void gd_handle_glVertexAttrib1f(long param_1)

{
  uint32_t uVar1;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getFloat(param_1 + 0x68);
  glVertexAttrib1f(uVar1, 0);
  return;
}


/* @0012ded8  size=80 */

void gd_handle_glVertexAttrib2f(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  glVertexAttrib2f(uVar2,uVar3,uVar1);
  return;
}


/* @0012df28  size=96 */

void gd_handle_glVertexAttrib3f(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  glVertexAttrib3f(uVar2,uVar3,uVar4,uVar1);
  return;
}


/* @0012df88  size=32 */

void gd_handle_glVertexAttrib4Nbv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttrib4Nbv");
  return;
}


/* @0012dfa8  size=32 */

void gd_handle_glVertexAttrib4Niv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttrib4Niv");
  return;
}


/* @0012dfc8  size=32 */

void gd_handle_glVertexAttrib4Nsv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttrib4Nsv");
  return;
}


/* @0012dfe8  size=96 */

void gd_handle_glVertexAttrib4Nub(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_get(param_1);
  ArrayBuffer_get(param_1);
  ArrayBuffer_get(param_1);
  ArrayBuffer_get(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttrib4Nub");
  return;
}


/* @0012e048  size=32 */

void gd_handle_glVertexAttrib4Nubv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttrib4Nubv");
  return;
}


/* @0012e068  size=32 */

void gd_handle_glVertexAttrib4Nuiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttrib4Nuiv");
  return;
}


/* @0012e088  size=32 */

void gd_handle_glVertexAttrib4Nusv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttrib4Nusv");
  return;
}


/* @0012e0a8  size=120 */

void gd_handle_glVertexAttrib4f(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  uVar5 = ArrayBuffer_getFloat(param_1);
  glVertexAttrib4f(uVar2,uVar3,uVar4,uVar5,uVar1);
  return;
}


/* @0012e120  size=56 */

void gd_handle_glVertexAttribDivisor(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar2 = ArrayBuffer_getInt(param_1 + 0x68);
  glVertexAttribDivisor(uVar1,uVar2);
  return;
}


/* @0012e158  size=72 */

void gd_handle_glVertexAttribI1i(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI1i");
  return;
}


/* @0012e1a0  size=32 */

void gd_handle_glVertexAttribI1iv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI1iv");
  return;
}


/* @0012e1c0  size=72 */

void gd_handle_glVertexAttribI1ui(long param_1)

{
  ArrayBuffer_getInt(param_1 + 0x68);
  ArrayBuffer_getInt(param_1 + 0x68);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI1ui");
  return;
}


/* @0012e208  size=32 */

void gd_handle_glVertexAttribI1uiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI1uiv");
  return;
}


/* @0012e228  size=80 */

void gd_handle_glVertexAttribI2i(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI2i");
  return;
}


/* @0012e278  size=32 */

void gd_handle_glVertexAttribI2iv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI2iv");
  return;
}


/* @0012e298  size=80 */

void gd_handle_glVertexAttribI2ui(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI2ui");
  return;
}


/* @0012e2e8  size=32 */

void gd_handle_glVertexAttribI2uiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI2uiv");
  return;
}


/* @0012e308  size=88 */

void gd_handle_glVertexAttribI3i(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI3i");
  return;
}


/* @0012e360  size=32 */

void gd_handle_glVertexAttribI3iv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI3iv");
  return;
}


/* @0012e380  size=88 */

void gd_handle_glVertexAttribI3ui(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI3ui");
  return;
}


/* @0012e3d8  size=32 */

void gd_handle_glVertexAttribI3uiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI3uiv");
  return;
}


/* @0012e3f8  size=32 */

void gd_handle_glVertexAttribI4bv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4bv");
  return;
}


/* @0012e418  size=96 */

void gd_handle_glVertexAttribI4i(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4i");
  return;
}


/* @0012e478  size=32 */

void gd_handle_glVertexAttribI4iv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4iv");
  return;
}


/* @0012e498  size=32 */

void gd_handle_glVertexAttribI4sv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4sv");
  return;
}


/* @0012e4b8  size=32 */

void gd_handle_glVertexAttribI4ubv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4ubv");
  return;
}


/* @0012e4d8  size=96 */

void gd_handle_glVertexAttribI4ui(long param_1)

{
  param_1 = param_1 + 0x68;
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  ArrayBuffer_getInt(param_1);
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4ui");
  return;
}


/* @0012e538  size=32 */

void gd_handle_glVertexAttribI4uiv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4uiv");
  return;
}


/* @0012e558  size=32 */

void gd_handle_glVertexAttribI4usv(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribI4usv");
  return;
}


/* @0012e578  size=32 */

void gd_handle_glVertexAttribIPointer(void)

{
  __android_log_print(3,"System.out","%s not implemented yet","glVertexAttribIPointer");
  return;
}


/* @0012e598  size=448 */

void gd_handle_glVertexAttribPointer(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  uint32_t *puVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  iVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_get(param_1);
  uVar5 = ArrayBuffer_getInt(param_1);
  iVar6 = ArrayBuffer_getInt(param_1);
  lVar10 = (long)iVar6;
  plVar7 = (long *)(&currentRenderer);
  lVar11 = *plVar7;
  if (uVar1 < 0xb) {
    lVar12 = *(long *)(lVar11 + 0x540);
    lVar8 = GLBuffer_getBound(0x8892);
    if ((lVar8 == 0) || (iVar2 == 0x80e1)) {
      lVar12 = lVar12 + (unsigned long)uVar1 * 0x20;
      *(uint32_t *)(lVar12 + 0x10) = 0;
      *(int *)(lVar12 + 0x14) = iVar2;
      *(short *)(lVar12 + 0x20) = (short)uVar5;
      if (iVar2 != 0x80e1) {
        lVar10 = 0;
      }
      *(uint32_t *)(lVar12 + 0xc) = uVar3;
      *(bool *)(lVar12 + 8) = (uVar4 & 0xff) != 0;
      *(long *)(lVar12 + 0x18) = lVar10;
      GLVertexArrayObject_setAttribState(lVar11 + 0x398,uVar1,2,0);
      return;
    }
    GLVertexArrayObject_setAttribState(lVar11 + 0x398,uVar1,0,1);
  }
  else if (0x7ffffffe < uVar1) {
    iVar6 = uVar1 + 0x80000001;
    uVar1 = *(uint32_t *)(*(long *)(lVar11 + 0x560) + (long)iVar6 * 4 + 0x2c);
    GLRenderer_enableVertexAttribute(lVar11,uVar1);
    GLVertexArrayObject_setAttribState(lVar11 + 0x398,iVar6,0,1);
    lVar11 = *(long *)(lVar11 + 0x540) + (long)iVar6 * 0x20;
    *(uint32_t *)(lVar11 + 0xc) = uVar3;
    *(int *)(lVar11 + 0x14) = iVar2;
    *(bool *)(lVar11 + 8) = (uVar4 & 0xff) != 0;
    *(short *)(lVar11 + 0x20) = (short)uVar5;
    *(long *)(lVar11 + 0x18) = lVar10;
    puVar9 = (uint32_t *)GLBuffer_getBound(0x8892);
    *(uint32_t *)(lVar11 + 0x10) = *puVar9;
  }
  glVertexAttribPointer(uVar1,iVar2,uVar3,uVar4,uVar5,lVar10);
  return;
}


/* @0012e758  size=228 */

void gd_handle_glVertexPointer(long param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  short sVar7;
  long lVar8;
  
  param_1 = param_1 + 0x68;
  cVar2 = ArrayBuffer_get(param_1);
  iVar3 = ArrayBuffer_getInt(param_1);
  iVar4 = ArrayBuffer_getInt(param_1);
  sVar7 = (short)iVar4;
  plVar5 = (long *)(&currentRenderer);
  lVar8 = *plVar5;
  GLVertexArrayObject_setAttribState(lVar8 + 0x398,0,1,0);
  lVar6 = *(long *)(lVar8 + 0x540);
  bVar1 = false;
  *(int *)(lVar6 + 0x14) = (int)cVar2;
  *(int *)(lVar6 + 0xc) = iVar3;
  if ((iVar3 != 0x1406) && (iVar3 != 0x140b)) {
    bVar1 = *(long *)(lVar8 + 0x560) != 0;
  }
  *(bool *)(lVar6 + 8) = bVar1;
  if ((iVar4 < 1) && (*(long *)(lVar8 + 0x560) == 0)) {
    if (iVar3 - 0x1400U < 0xb) {
      sVar7 = (short)*(uint32_t *)(&DAT_001159d8 + (long)(int)(iVar3 - 0x1400U) * 4);
    }
    else {
      sVar7 = 0;
    }
    sVar7 = sVar7 * cVar2;
  }
  *(short *)(lVar6 + 0x20) = sVar7;
  return;
}


/* @0012e83c  size=96 */

void gd_handle_glViewport(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar2 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getInt(param_1);
  uVar4 = ArrayBuffer_getInt(param_1);
  glViewport(uVar1,uVar2,uVar3,uVar4);
  return;
}


/* @0012e89c  size=80 */

void gd_handle_glWaitSync(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getLong(param_1);
  uVar1 = ArrayBuffer_getInt(param_1);
  uVar3 = ArrayBuffer_getLong(param_1);
  glWaitSync(uVar2,uVar1,uVar3);
  return;
}


/* @0012e8ec  size=116 */

void gd_handle_glWindowPos3f(long param_1)

{
  uint64_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  param_1 = param_1 + 0x68;
  uVar2 = ArrayBuffer_getFloat(param_1);
  uVar3 = ArrayBuffer_getFloat(param_1);
  uVar4 = ArrayBuffer_getFloat(param_1);
  puVar1 = (uint64_t *)(&currentRenderer);
  GLRenderer_setRasterPos(uVar2,uVar3,uVar4,0x3f800000,*puVar1,0);
  return;
}


