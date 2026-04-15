/*
 * glx_context.c — GLX context (EGL wrapper) creation and destruction
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

/* @0011d4f0  size=532 */

uint64_t * createGLXContext(uint32_t param_1,uint64_t *param_2)

{
  uint64_t *puVar1;
  long lVar2;
  uint32_t uVar3;
  long lVar4;
  unsigned long uVar5;
  uint64_t uVar6;
  void *pvVar7;
  uint64_t uVar8;
  uint64_t *puVar9;
  uint64_t uVar10;
  uint64_t uVar11;
  uint64_t uVar12;
  uint64_t uVar13;
  uint64_t local_70;
  int local_64;
  uint8_t auStack_60 [4];
  uint8_t auStack_5c [4];
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar2 + 0x28);
  lVar4 = eglGetDisplay(0);
  uVar5 = 0;
  if ((lVar4 == 0) || (uVar5 = eglInitialize(lVar4,auStack_5c,auStack_60), (int)uVar5 == 0)) {
    puVar9 = (uint64_t *)0x0;
  }
  else {
    uVar5 = eglChooseConfig(lVar4,&DAT_00115688,&local_70,1,&local_64);
    puVar9 = (uint64_t *)0x0;
    if (((int)uVar5 != 0) && (local_64 == 1)) {
      puVar9 = (uint64_t *)&globalEGLContext;
      if (param_2 != (uint64_t *)0x0) {
        puVar9 = param_2;
      }
      puVar1 = (uint64_t *)0x0;
      if (param_2 != (uint64_t *)0x0) {
        puVar1 = param_2 + 0x74;
      }
      uVar6 = eglCreateContext(lVar4,local_70,*puVar9,&DAT_001156b4);
      puVar9 = calloc(1,0x928);
      *puVar9 = uVar6;
      *(uint32_t *)(puVar9 + 1) = param_1;
      GLVertexArrayObject_setBound(puVar9 + 0x74,0);
      if (param_2 == (uint64_t *)0x0) {
        pvVar7 = calloc(1,0x10);
        puVar9[0xac] = pvVar7;
        pvVar7 = calloc(1,0x10);
        puVar9[0xb7] = pvVar7;
        pvVar7 = calloc(1,0x10);
        puVar9[0xb8] = pvVar7;
        pvVar7 = calloc(1,0x10);
        puVar9[0xb9] = pvVar7;
        pvVar7 = calloc(1,0x10);
        puVar9[0xba] = pvVar7;
        pvVar7 = calloc(1,0x10);
        puVar9[0xbc] = pvVar7;
        pvVar7 = calloc(1,0x10);
        puVar9[0xbb] = pvVar7;
      }
      else {
        uVar6 = puVar1[0x45];
        uVar11 = puVar1[0x47];
        uVar10 = puVar1[0x46];
        uVar8 = puVar1[0x48];
        uVar13 = puVar1[0x44];
        uVar12 = puVar1[0x43];
        puVar9[0xac] = puVar1[0x38];
        puVar9[0xb9] = uVar6;
        puVar9[0xbb] = uVar11;
        puVar9[0xba] = uVar10;
        puVar9[0xbc] = uVar8;
        puVar9[0xb8] = uVar13;
        puVar9[0xb7] = uVar12;
      }
      *(bool *)(puVar9 + 0xbd) = param_2 != (uint64_t *)0x0;
      pthread_mutex_lock((&glx_context_mutex));
      eglMakeCurrent(lVar4,0,0,*puVar9);
      GLRenderer_initOnEGLContext(puVar9 + 1);
      eglMakeCurrent(lVar4,0,0,0);
      uVar3 = pthread_mutex_unlock((&glx_context_mutex));
      uVar5 = (unsigned long)uVar3;
    }
  }
  if (*(long *)(lVar2 + 0x28) == local_58) {
    return puVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}


/* @0011d704  size=356 */

void destroyGLXContext(uint64_t *param_1)

{
  uint64_t uVar1;
  
  pthread_mutex_lock((&glx_context_mutex));
  SparseArray_free(param_1 + 0xaa,1);
  if (*(char *)(param_1 + 0xbd) == '\0') {
    GLBuffer_onDestroy(param_1 + 0x74);
    SparseArray_free(param_1[0xac],0);
    if ((void *)param_1[0xac] != (void *)0x0) {
      free((void *)param_1[0xac]);
      param_1[0xac] = 0;
    }
    SparseArray_free(param_1[0xb7],1);
    if ((void *)param_1[0xb7] != (void *)0x0) {
      free((void *)param_1[0xb7]);
      param_1[0xb7] = 0;
    }
    ARBProgram_onDestroy(param_1 + 0x74);
    SparseArray_free(param_1[0xb8],0);
    if ((void *)param_1[0xb8] != (void *)0x0) {
      free((void *)param_1[0xb8]);
      param_1[0xb8] = 0;
    }
    ShaderConverter_onDestroy(param_1 + 0x74);
    SparseArray_free(param_1[0xb9],0);
    if ((void *)param_1[0xb9] != (void *)0x0) {
      free((void *)param_1[0xb9]);
      param_1[0xb9] = 0;
    }
    SparseArray_free(param_1[0xba],0);
    if ((void *)param_1[0xba] != (void *)0x0) {
      free((void *)param_1[0xba]);
      param_1[0xba] = 0;
    }
    SparseArray_free(param_1[0xbb],1);
    if ((void *)param_1[0xbb] != (void *)0x0) {
      free((void *)param_1[0xbb]);
      param_1[0xbb] = 0;
    }
    SparseArray_free(param_1[0xbc],1);
    if ((void *)param_1[0xbc] != (void *)0x0) {
      free((void *)param_1[0xbc]);
      param_1[0xbc] = 0;
    }
  }
  uVar1 = eglGetDisplay(0);
  eglMakeCurrent(uVar1,0,0,*param_1);
  GLRenderer_destroy(param_1 + 1);
  eglMakeCurrent(uVar1,0,0,0);
  pthread_mutex_unlock((&glx_context_mutex));
  eglDestroyContext(uVar1,*param_1);
  return;
}


