/*
 * gl_vertex_array.c — Vertex array object management
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

/* @0013e4b8  size=168 */

void GLVertexArrayObject_delete(long param_1,int param_2)

{
  int iVar1;
  void *__ptr;
  
  if (param_2 == 0) {
    __ptr = (void *)(param_1 + 8);
    iVar1 = *(int *)(param_1 + 0x1a0);
  }
  else {
    __ptr = (void *)SparseArray_get(param_1 + 0x1b0,param_2);
    if (*(void **)(param_1 + 0x1a8) == __ptr) {
      *(long *)(param_1 + 0x1a8) = param_1 + 8;
    }
    if (__ptr == (void *)0x0) {
      return;
    }
    iVar1 = *(int *)((long)__ptr + 0x198);
  }
  if (iVar1 != 0) {
    glDeleteBuffers(1,(long)__ptr + 0x198);
    *(uint32_t *)((long)__ptr + 0x198) = 0;
  }
  if (param_2 == 0) {
    return;
  }
  free(__ptr);
  SparseArray_remove(param_1 + 0x1b0,param_2);
  return;
}


/* @0013e2cc  size=384 */

void GLVertexArrayObject_setAttribState(long param_1,uint32_t param_2,uint8_t param_3,uint32_t param_4)

{
  uint8_t *pbVar1;
  uint8_t bVar2;
  uint8_t *pbVar3;
  unsigned long uVar4;
  
  switch(param_2) {
  case 0x8074:
    param_3 = param_3 != 0;
    param_2 = 0;
    break;
  case 0x8075:
    param_3 = param_3 != 0;
    param_2 = 2;
    break;
  case 0x8076:
    param_3 = param_3 != 0;
    param_2 = 1;
    break;
  default:
    if (10 < param_2) {
      return;
    }
    break;
  case 0x8078:
    param_3 = param_3 != 0;
    param_2 = 3;
  }
  pbVar3 = *(uint8_t **)(param_1 + 0x1a8);
  uVar4 = (unsigned long)param_2;
  if ((param_4 & 1) != 0) {
    pbVar3[uVar4 * 0x20 + 8] = 0;
    pbVar1 = pbVar3 + uVar4 * 0x20 + 0x14;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
    pbVar1 = pbVar3 + uVar4 * 0x20 + 0xc;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
    pbVar1 = pbVar3 + uVar4 * 0x20 + 0x1a;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
  }
  pbVar3[uVar4 * 0x20 + 0x22] = param_3;
  if (param_3 == 0) {
    if ((*pbVar3 != 0) && (*pbVar3 - 1 <= param_2)) {
      bVar2 = pbVar3[0x22] != 0;
      if (pbVar3[0x42] != 0) {
        bVar2 = 2;
      }
      if (pbVar3[0x62] != 0) {
        bVar2 = 3;
      }
      if (pbVar3[0x82] != 0) {
        bVar2 = 4;
      }
      if (pbVar3[0xa2] != 0) {
        bVar2 = 5;
      }
      if (pbVar3[0xc2] != 0) {
        bVar2 = 6;
      }
      if (pbVar3[0xe2] != 0) {
        bVar2 = 7;
      }
      if (pbVar3[0x102] != 0) {
        bVar2 = 8;
      }
      if (pbVar3[0x122] != 0) {
        bVar2 = 9;
      }
      if (pbVar3[0x142] != 0) {
        bVar2 = 10;
      }
      if (pbVar3[0x162] != 0) {
        bVar2 = 0xb;
      }
      *pbVar3 = bVar2;
      return;
    }
    return;
  }
  bVar2 = *pbVar3;
  if ((uint32_t)bVar2 < param_2 + 1) {
    bVar2 = (char)param_2 + 1;
  }
  *pbVar3 = bVar2;
  return;
}


/* @0013e44c  size=108 */

void GLVertexArrayObject_setBound(long param_1,int param_2)

{
  void *pvVar1;
  
  if (param_2 == 0) {
    *(long *)(param_1 + 0x1a8) = param_1 + 8;
  }
  else {
    pvVar1 = (void *)SparseArray_get(param_1 + 0x1b0);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = calloc(1,0x1a0);
      SparseArray_put(param_1 + 0x1b0,param_2,pvVar1);
    }
    *(void **)(param_1 + 0x1a8) = pvVar1;
  }
  return;
}


