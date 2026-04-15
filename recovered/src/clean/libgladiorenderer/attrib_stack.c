/*
 * attrib_stack.c — glPushAttrib/glPopAttrib emulation
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

/* @00138818  size=996 */

/* WARNING: Type propagation algorithm not settling */

void AttribStack_pop(void)

{
  int iVar1;
  uint32_t uVar2;
  long *plVar3;
  uint32_t *__ptr;
  uint64_t *puVar4;
  long lVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  
  plVar3 = (long *)(&currentRenderer);
  iVar1 = *(int *)(*plVar3 + 0x8e0);
  if (iVar1 == 0) {
    return;
  }
  __ptr = (uint32_t *)ArrayList_removeAt(*plVar3 + 0x8e0,iVar1 + -1);
  uVar2 = *__ptr;
  if ((uVar2 >> 0xe & 1) != 0) {
    plVar3 = (long *)(&currentRenderer);
    GLRenderer_setCapabilityState(*plVar3,0xbc0,(char)__ptr[1] != '\0',0xffffffff);
    uVar2 = __ptr[4];
    lVar5 = *plVar3;
    uVar6 = __ptr[3];
    *(uint32_t *)(lVar5 + 0x5c) = __ptr[2];
    *(uint32_t *)(lVar5 + 0x60) = uVar6;
    GLRenderer_setCapabilityState(lVar5,0xbe2,(char)uVar2 != '\0',0xffffffff);
    glBlendFunc(__ptr[5],__ptr[6]);
    glClearColor(__ptr[7],__ptr[8],__ptr[9],__ptr[10]);
    glColorMask((char)__ptr[0xb],*(uint8_t *)((long)__ptr + 0x2d),
                *(uint8_t *)((long)__ptr + 0x2e),*(uint8_t *)((long)__ptr + 0x2f));
    uVar2 = *__ptr;
  }
  if ((uVar2 & 1) != 0) {
    plVar3 = (long *)(&currentRenderer);
    lVar5 = *plVar3;
    uVar7 = *(uint64_t *)(__ptr + 0xc);
    *(uint64_t *)(lVar5 + 0xb4) = *(uint64_t *)(__ptr + 0xe);
    *(uint64_t *)(lVar5 + 0xac) = uVar7;
    uVar2 = __ptr[0x12];
    *(uint64_t *)(lVar5 + 0xbc) = *(uint64_t *)(__ptr + 0x10);
    *(uint32_t *)(lVar5 + 0xc4) = uVar2;
    uVar7 = *(uint64_t *)(__ptr + 0x13);
    lVar5 = lVar5 + (unsigned long)*(uint8_t *)((long)__ptr + 0xc5) * 0x10;
    *(uint64_t *)(lVar5 + 0xd0) = *(uint64_t *)(__ptr + 0x15);
    *(uint64_t *)(lVar5 + 200) = uVar7;
    uVar2 = *__ptr;
  }
  if ((uVar2 >> 8 & 1) != 0) {
    puVar4 = (uint64_t *)(&currentRenderer);
    GLRenderer_setCapabilityState(*puVar4,0xb71,(char)__ptr[0x17] != '\0',0xffffffff);
    glDepthFunc(__ptr[0x18]);
    glClearDepthf(__ptr[0x19]);
    glDepthMask(__ptr[0x1a]);
    uVar2 = *__ptr;
  }
  if ((uVar2 >> 0xd & 1) != 0) {
    puVar4 = (uint64_t *)(&currentRenderer);
    GLRenderer_setCapabilityState(*puVar4,0xbc0,(char)__ptr[1] != '\0',0xffffffff);
    GLRenderer_setCapabilityState(*puVar4,0xbe2,(char)__ptr[4] != '\0',0xffffffff);
    GLRenderer_setCapabilityState(*puVar4,0xb44,(char)__ptr[0x1b] != '\0',0xffffffff);
    GLRenderer_setCapabilityState(*puVar4,0xb71,(char)__ptr[0x17] != '\0',0xffffffff);
    GLRenderer_setCapabilityState(*puVar4,0xb60,*(char *)((long)__ptr + 0x6d) != '\0',0xffffffff);
    GLRenderer_setCapabilityState(*puVar4,0xc11,(char)__ptr[0x24] != '\0',0xffffffff);
    GLRenderer_setCapabilityState(*puVar4,0xb90,(char)__ptr[0x29] != '\0',0xffffffff);
    uVar2 = *__ptr;
  }
  if ((uVar2 >> 7 & 1) != 0) {
    puVar4 = (uint64_t *)(&currentRenderer);
    GLRenderer_setCapabilityState(*puVar4,0xb60,*(char *)((long)__ptr + 0x6d) != '\0',0xffffffff);
    GLRenderer_setFogParams(*puVar4,0xb66,__ptr + 0x1c);
    GLRenderer_setFogParams(*puVar4,0xb62,__ptr + 0x20);
    GLRenderer_setFogParams(*puVar4,0xb63,__ptr + 0x21);
    GLRenderer_setFogParams(*puVar4,0xb64,__ptr + 0x22);
    GLRenderer_setFogParams(*puVar4,0xb65,__ptr + 0x23);
    uVar2 = *__ptr;
  }
  if ((uVar2 >> 0x13 & 1) != 0) {
    puVar4 = (uint64_t *)(&currentRenderer);
    GLRenderer_setCapabilityState(*puVar4,0xc11,(char)__ptr[0x24] != '\0',0xffffffff);
    glScissor((int)(float)__ptr[0x25],(int)(float)__ptr[0x26],(int)(float)__ptr[0x27],
              (int)(float)__ptr[0x28]);
    uVar2 = *__ptr;
  }
  if ((uVar2 >> 10 & 1) != 0) {
    puVar4 = (uint64_t *)(&currentRenderer);
    GLRenderer_setCapabilityState(*puVar4,0xb90,(char)__ptr[0x29] != '\0',0xffffffff);
    glStencilFunc(__ptr[0x2a],__ptr[0x2b],__ptr[0x2c]);
    glStencilOp(__ptr[0x2e],__ptr[0x2f],__ptr[0x30]);
    glClearStencil(__ptr[0x2d]);
    uVar2 = *__ptr;
  }
  if ((uVar2 >> 0x12 & 1) != 0) {
    glActiveTexture((uint8_t)__ptr[0x31] + 0x84c0);
    GLTexture_bind(0xde1,__ptr[0x32]);
    GLTexture_bind(0x806f,__ptr[0x33]);
    GLTexture_bind(0x8513,__ptr[0x34]);
    GLTexture_bind(0x8c1a,__ptr[0x35]);
    uVar2 = *__ptr;
  }
  if ((uVar2 >> 0xb & 1) != 0) {
    glViewport(__ptr[0x36],__ptr[0x37],__ptr[0x38],__ptr[0x39]);
    glDepthRangef(__ptr[0x3a],__ptr[0x3b]);
  }
  free(__ptr);
  return;
}


/* @00138370  size=1192 */

/* WARNING: Type propagation algorithm not settling */

void AttribStack_push(uint32_t param_1)

{
  uint32_t *puVar1;
  uint64_t *puVar2;
  long *plVar3;
  long lVar4;
  uint32_t uVar5;
  uint32_t *puVar6;
  
  puVar1 = calloc(1,0xf0);
  *puVar1 = param_1;
  if ((param_1 >> 0xe & 1) != 0) {
    puVar2 = (uint64_t *)(&currentRenderer);
    GLRenderer_getParamsv(*puVar2,0xbc0,0x8b56,puVar1 + 1);
    GLRenderer_getParamsv(*puVar2,0xbc1,0x1404,puVar1 + 2);
    GLRenderer_getParamsv(*puVar2,0xbc2,0x1406,puVar1 + 3);
    GLRenderer_getParamsv(*puVar2,0xbe2,0x8b56,puVar1 + 4);
    GLRenderer_getParamsv(*puVar2,0xbe1,0x1404,puVar1 + 5);
    GLRenderer_getParamsv(*puVar2,0xbe0,0x1404,puVar1 + 6);
    GLRenderer_getParamsv(*puVar2,0xc22,0x1406,puVar1 + 7);
    GLRenderer_getParamsv(*puVar2,0xc23,0x8b56,puVar1 + 0xb);
  }
  if ((param_1 & 1) != 0) {
    plVar3 = (long *)(&currentRenderer);
    lVar4 = *plVar3;
    *(uint8_t *)((long)puVar1 + 0xc5) = *(uint8_t *)(lVar4 + 0x399);
    GLRenderer_getParamsv(lVar4,0xb00,0x1406,puVar1 + 0xc);
    GLRenderer_getParamsv(*plVar3,0xb02,0x1406,puVar1 + 0x10);
    GLRenderer_getParamsv(*plVar3,0xb03,0x1406,puVar1 + 0x13);
  }
  if ((param_1 >> 8 & 1) != 0) {
    puVar2 = (uint64_t *)(&currentRenderer);
    GLRenderer_getParamsv(*puVar2,0xb71,0x8b56,puVar1 + 0x17);
    GLRenderer_getParamsv(*puVar2,0xb74,0x1404,puVar1 + 0x18);
    GLRenderer_getParamsv(*puVar2,0xb73,0x1406,puVar1 + 0x19);
    GLRenderer_getParamsv(*puVar2,0xb72,0x1404,puVar1 + 0x1a);
  }
  if ((param_1 >> 0xd & 1) != 0) {
    puVar2 = (uint64_t *)(&currentRenderer);
    GLRenderer_getParamsv(*puVar2,0xbc0,0x8b56,puVar1 + 1);
    GLRenderer_getParamsv(*puVar2,0xbe2,0x8b56,puVar1 + 4);
    GLRenderer_getParamsv(*puVar2,0xb44,0x8b56,puVar1 + 0x1b);
    GLRenderer_getParamsv(*puVar2,0xb71,0x8b56,puVar1 + 0x17);
    GLRenderer_getParamsv(*puVar2,0xb60,0x8b56,(long)puVar1 + 0x6d);
    GLRenderer_getParamsv(*puVar2,0xc11,0x8b56,puVar1 + 0x24);
    GLRenderer_getParamsv(*puVar2,0xb90,0x8b56,puVar1 + 0x29);
  }
  if ((param_1 >> 7 & 1) != 0) {
    puVar2 = (uint64_t *)(&currentRenderer);
    GLRenderer_getParamsv(*puVar2,0xb60,0x8b56,(long)puVar1 + 0x6d);
    GLRenderer_getParamsv(*puVar2,0xb66,0x1406,puVar1 + 0x1c);
    GLRenderer_getParamsv(*puVar2,0xb62,0x1406,puVar1 + 0x20);
    GLRenderer_getParamsv(*puVar2,0xb63,0x1406,puVar1 + 0x21);
    GLRenderer_getParamsv(*puVar2,0xb64,0x1406,puVar1 + 0x22);
    GLRenderer_getParamsv(*puVar2,0xb65,0x1406,puVar1 + 0x23);
  }
  if ((param_1 >> 0x13 & 1) != 0) {
    puVar2 = (uint64_t *)(&currentRenderer);
    GLRenderer_getParamsv(*puVar2,0xc11,0x8b56,puVar1 + 0x24);
    GLRenderer_getParamsv(*puVar2,0xc10,0x1406,puVar1 + 0x25);
  }
  if ((param_1 >> 10 & 1) != 0) {
    puVar2 = (uint64_t *)(&currentRenderer);
    GLRenderer_getParamsv(*puVar2,0xb90,0x8b56,puVar1 + 0x29);
    GLRenderer_getParamsv(*puVar2,0xb92,0x1404,puVar1 + 0x2a);
    GLRenderer_getParamsv(*puVar2,0xb93,0x1404,puVar1 + 0x2c);
    GLRenderer_getParamsv(*puVar2,0xb97,0x1404,puVar1 + 0x2b);
    GLRenderer_getParamsv(*puVar2,0xb94,0x1404,puVar1 + 0x2e);
    GLRenderer_getParamsv(*puVar2,0xb95,0x1404,puVar1 + 0x2f);
    GLRenderer_getParamsv(*puVar2,0xb96,0x1404,puVar1 + 0x30);
    GLRenderer_getParamsv(*puVar2,0xb91,0x1404,puVar1 + 0x2d);
  }
  if ((param_1 >> 0x12 & 1) != 0) {
    plVar3 = (long *)(&currentRenderer);
    lVar4 = *plVar3;
    puVar6 = *(uint32_t **)(lVar4 + 0x568);
    *(uint8_t *)(puVar1 + 0x31) = *(uint8_t *)(lVar4 + 0x398);
    uVar5 = 0;
    if (puVar6 != (uint32_t *)0x0) {
      uVar5 = *puVar6;
    }
    puVar6 = *(uint32_t **)(lVar4 + 0x570);
    puVar1[0x32] = uVar5;
    if (puVar6 == (uint32_t *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *puVar6;
    }
    puVar6 = *(uint32_t **)(lVar4 + 0x578);
    puVar1[0x33] = uVar5;
    if (puVar6 == (uint32_t *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *puVar6;
    }
    puVar6 = *(uint32_t **)(lVar4 + 0x580);
    puVar1[0x34] = uVar5;
    uVar5 = 0;
    if (puVar6 != (uint32_t *)0x0) {
      uVar5 = *puVar6;
    }
    puVar1[0x35] = uVar5;
  }
  if ((param_1 >> 0xb & 1) != 0) {
    puVar2 = (uint64_t *)(&currentRenderer);
    GLRenderer_getParamsv(*puVar2,0xba2,0x1404,puVar1 + 0x36);
    GLRenderer_getParamsv(*puVar2,0xb70,0x1406,puVar1 + 0x3a);
  }
  plVar3 = (long *)(&currentRenderer);
  ArrayList_add(*plVar3 + 0x8e0,puVar1);
  return;
}


