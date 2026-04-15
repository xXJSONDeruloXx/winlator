/*
 * gl_framebuffer.c — Framebuffer object management
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

/* @0013e5e4  size=1400 */

void GLFramebuffer_bind(int param_1,int param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  int *piVar5;
  uint64_t *puVar6;
  unsigned long uVar7;
  uint32_t uVar8;
  int *piVar9;
  long lVar10;
  int *piVar11;
  int *piVar12;
  uint32_t local_78 [8];
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar2 + 0x28);
  pthread_mutex_lock((&glx_context_mutex));
  plVar4 = (long *)(&currentRenderer);
  if (param_2 == 0) {
    param_2 = *(int *)(*plVar4 + 0xc);
  }
  piVar5 = (int *)SparseArray_get(*(uint64_t *)(*plVar4 + 0x5d0),param_2);
  if (piVar5 == (int *)0x0) {
    piVar5 = calloc(1,0x84);
    puVar6 = (uint64_t *)(&currentRenderer);
    piVar9 = (int *)*puVar6;
    *piVar5 = *piVar9;
    piVar5[1] = param_2;
    SparseArray_put(*(uint64_t *)(piVar9 + 0x174),param_2,piVar5);
  }
  puVar6 = (uint64_t *)(&currentRenderer);
  piVar12 = (int *)*puVar6;
  piVar9 = piVar12;
  if (param_1 < 0x88eb) {
    lVar10 = 0;
    if (param_1 < 0x8643) {
      if (param_1 < 0x8513) {
        if (1 < param_1 - 0xde0U) {
          iVar3 = 0x806f;
          goto LAB_0013e770;
        }
      }
      else {
        if (param_1 == 0x8513) goto LAB_0013e7f8;
        if (param_1 != 0x8620) goto LAB_0013e7e8;
      }
    }
    else if (param_1 < 0x8892) {
      if (param_1 != 0x8643) {
        iVar3 = 0x8804;
LAB_0013e770:
        if (param_1 != iVar3) goto LAB_0013e7e8;
LAB_0013e778:
        lVar10 = 1;
      }
    }
    else if (param_1 != 0x8892) {
      iVar3 = 0x8893;
      goto LAB_0013e770;
    }
LAB_0013e7fc:
    piVar11 = piVar12 + lVar10 + 0x162;
    piVar12 = piVar9;
  }
  else {
    if (param_1 < 0x8c1a) {
      if (param_1 < 0x8a11) {
        if (param_1 == 0x88eb) goto LAB_0013e7f8;
        iVar3 = 0x88ec;
      }
      else {
        if (param_1 == 0x8a11) {
          lVar10 = 4;
          goto LAB_0013e7fc;
        }
        iVar3 = 0x8c18;
      }
      if (param_1 == iVar3) {
LAB_0013e7d8:
        lVar10 = 3;
        goto LAB_0013e7fc;
      }
LAB_0013e7e8:
      if (param_1 - 0x8515U < 6) {
LAB_0013e7f8:
        lVar10 = 2;
      }
      else {
        __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
        puVar6 = (uint64_t *)(&currentRenderer);
        lVar10 = 0xff;
        piVar9 = (int *)*puVar6;
      }
      goto LAB_0013e7fc;
    }
    if (param_1 < 0x8ca8) {
      if (param_1 == 0x8c1a) goto LAB_0013e7d8;
      if (param_1 == 0x8c2a) {
        lVar10 = 5;
        goto LAB_0013e7fc;
      }
      goto LAB_0013e7e8;
    }
    if (param_1 == 0x8ca8) goto LAB_0013e7f8;
    if (param_1 == 0x8ca9) goto LAB_0013e778;
    if (param_1 != 0x8d40) goto LAB_0013e7e8;
    piVar12[0x162] = param_2;
    piVar12[0x163] = param_2;
    piVar11 = piVar12 + 0x164;
  }
  *piVar11 = param_2;
  iVar3 = *piVar5;
  iVar1 = *piVar12;
  glBindFramebuffer(param_1,piVar5[1]);
  if (iVar1 == iVar3) goto LAB_0013eacc;
  lVar10 = 0;
  piVar9 = piVar5 + 4;
  do {
    iVar3 = piVar9[-2];
    if (iVar3 != 0) {
      if (iVar3 == 0x8d41) {
        glFramebufferRenderbuffer(param_1,(int)lVar10 + 0x8ce0,0x8d41,piVar9[-1]);
      }
      else {
        glFramebufferTexture2D(param_1,(int)lVar10 + 0x8ce0,iVar3,piVar9[-1],(char)*piVar9);
      }
    }
    lVar10 = lVar10 + 1;
    piVar9 = piVar9 + 3;
  } while (lVar10 != 8);
  iVar3 = piVar5[0x1a];
  if (iVar3 == 0) {
LAB_0013e8a8:
    iVar3 = piVar5[0x1d];
    if (iVar3 == 0) goto LAB_0013e8b0;
LAB_0013e908:
    if (iVar3 == 0x8d41) {
      glFramebufferRenderbuffer(param_1,0x8d20,0x8d41,piVar5[0x1e]);
      uVar8 = piVar5[0x20];
      goto joined_r0x0013e92c;
    }
    glFramebufferTexture2D(param_1,0x8d20,iVar3,piVar5[0x1e],(char)piVar5[0x1f]);
    uVar8 = piVar5[0x20];
    if ((uVar8 & 1) == 0) goto LAB_0013e8b8;
LAB_0013e930:
    glReadBuffer(0);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 1 & 1) == 0) goto LAB_0013e8bc;
LAB_0013e940:
    glReadBuffer(0x8ce0);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 2 & 1) == 0) goto LAB_0013e8c0;
LAB_0013e950:
    glReadBuffer(0x8ce1);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 3 & 1) == 0) goto LAB_0013e8c4;
LAB_0013e960:
    glReadBuffer(0x8ce2);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 4 & 1) == 0) goto LAB_0013e8c8;
LAB_0013e970:
    glReadBuffer(0x8ce3);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 5 & 1) == 0) goto LAB_0013e8cc;
LAB_0013e980:
    glReadBuffer(0x8ce4);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 6 & 1) == 0) goto LAB_0013e8d0;
LAB_0013e990:
    glReadBuffer(0x8ce5);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 7 & 1) == 0) goto LAB_0013e8d4;
LAB_0013e9a0:
    glReadBuffer(0x8ce6);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 8 & 1) == 0) goto LAB_0013e8d8;
LAB_0013e9b0:
    glReadBuffer(0x8ce7);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 9 & 1) == 0) goto LAB_0013e8dc;
LAB_0013e9c0:
    local_78[0] = 0;
    glDrawBuffers(1,local_78);
    uVar8 = piVar5[0x20];
    if ((uVar8 >> 10 & 1) == 0) goto LAB_0013e8e0;
LAB_0013e9d8:
    uVar7 = 1;
    local_78[0] = 0x8ce0;
  }
  else {
    if (iVar3 == 0x8d41) {
      glFramebufferRenderbuffer(param_1,0x8d00,0x8d41,piVar5[0x1b]);
      goto LAB_0013e8a8;
    }
    glFramebufferTexture2D(param_1,0x8d00,iVar3,piVar5[0x1b],(char)piVar5[0x1c]);
    iVar3 = piVar5[0x1d];
    if (iVar3 != 0) goto LAB_0013e908;
LAB_0013e8b0:
    uVar8 = piVar5[0x20];
joined_r0x0013e92c:
    if ((uVar8 & 1) != 0) goto LAB_0013e930;
LAB_0013e8b8:
    if ((uVar8 >> 1 & 1) != 0) goto LAB_0013e940;
LAB_0013e8bc:
    if ((uVar8 >> 2 & 1) != 0) goto LAB_0013e950;
LAB_0013e8c0:
    if ((uVar8 >> 3 & 1) != 0) goto LAB_0013e960;
LAB_0013e8c4:
    if ((uVar8 >> 4 & 1) != 0) goto LAB_0013e970;
LAB_0013e8c8:
    if ((uVar8 >> 5 & 1) != 0) goto LAB_0013e980;
LAB_0013e8cc:
    if ((uVar8 >> 6 & 1) != 0) goto LAB_0013e990;
LAB_0013e8d0:
    if ((uVar8 >> 7 & 1) != 0) goto LAB_0013e9a0;
LAB_0013e8d4:
    if ((uVar8 >> 8 & 1) != 0) goto LAB_0013e9b0;
LAB_0013e8d8:
    if ((uVar8 >> 9 & 1) != 0) goto LAB_0013e9c0;
LAB_0013e8dc:
    if ((uVar8 >> 10 & 1) != 0) goto LAB_0013e9d8;
LAB_0013e8e0:
    uVar7 = 0;
  }
  if ((uVar8 >> 0xb & 1) != 0) {
    local_78[uVar7] = 0x8ce1;
    uVar7 = (unsigned long)((int)uVar7 + 1);
  }
  if ((uVar8 >> 0xc & 1) == 0) {
    if ((uVar8 >> 0xd & 1) != 0) goto LAB_0013ea38;
LAB_0013ea04:
    if ((uVar8 >> 0xe & 1) != 0) goto LAB_0013ea50;
LAB_0013ea08:
    if ((uVar8 >> 0xf & 1) != 0) goto LAB_0013ea68;
LAB_0013ea0c:
    if ((uVar8 >> 0x10 & 1) != 0) goto LAB_0013ea80;
LAB_0013ea10:
    if ((uVar8 >> 0x11 & 1) != 0) goto LAB_0013ea98;
LAB_0013ea14:
    if ((int)uVar7 != 0) goto LAB_0013eaac;
  }
  else {
    local_78[uVar7] = 0x8ce2;
    uVar7 = (unsigned long)((int)uVar7 + 1);
    if ((uVar8 >> 0xd & 1) == 0) goto LAB_0013ea04;
LAB_0013ea38:
    local_78[uVar7] = 0x8ce3;
    uVar7 = (unsigned long)((int)uVar7 + 1);
    if ((uVar8 >> 0xe & 1) == 0) goto LAB_0013ea08;
LAB_0013ea50:
    local_78[uVar7] = 0x8ce4;
    uVar7 = (unsigned long)((int)uVar7 + 1);
    if ((uVar8 >> 0xf & 1) == 0) goto LAB_0013ea0c;
LAB_0013ea68:
    local_78[uVar7] = 0x8ce5;
    uVar7 = (unsigned long)((int)uVar7 + 1);
    if ((uVar8 >> 0x10 & 1) == 0) goto LAB_0013ea10;
LAB_0013ea80:
    local_78[uVar7] = 0x8ce6;
    uVar7 = (unsigned long)((int)uVar7 + 1);
    if ((uVar8 >> 0x11 & 1) == 0) goto LAB_0013ea14;
LAB_0013ea98:
    local_78[uVar7] = 0x8ce7;
    uVar7 = (unsigned long)((int)uVar7 + 1);
LAB_0013eaac:
    glDrawBuffers(uVar7,local_78);
  }
  puVar6 = (uint64_t *)(&currentRenderer);
  *piVar5 = *(int *)*puVar6;
LAB_0013eacc:
  iVar3 = pthread_mutex_unlock((&glx_context_mutex));
  if (*(long *)(lVar2 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar3);
  }
  return;
}


/* @0013e560  size=132 */

int GLFramebuffer_create(void)

{
  int iVar1;
  uint32_t *puVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  iVar1 = DAT_00144ef0;
  DAT_00144ef0 = DAT_00144ef0 + 1;
  puVar2 = calloc(1,0x84);
  puVar3 = (uint64_t *)(&currentRenderer);
  uVar4 = *(uint64_t *)((uint32_t *)*puVar3 + 0x174);
  *puVar2 = *(uint32_t *)*puVar3;
  puVar2[1] = iVar1;
  SparseArray_put(uVar4,iVar1,puVar2);
  pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @0013ee88  size=292 */

int GLFramebuffer_delete(int param_1)

{
  int iVar1;
  long *plVar2;
  int *__ptr;
  uint64_t *puVar3;
  long lVar4;
  
  plVar2 = (long *)(&currentRenderer);
  lVar4 = *plVar2;
  if (*(int *)(lVar4 + 0x588) == param_1) {
    GLFramebuffer_bind(0x8d40,0);
    plVar2 = (long *)(&currentRenderer);
    lVar4 = *plVar2;
  }
  if (*(int *)(lVar4 + 0x58c) == param_1) {
    GLFramebuffer_bind(0x8d40,0);
    plVar2 = (long *)(&currentRenderer);
    lVar4 = *plVar2;
  }
  if (*(int *)(lVar4 + 0x590) == param_1) {
    GLFramebuffer_bind(0x8d40,0);
  }
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  __ptr = (int *)SparseArray_get(*(uint64_t *)(*plVar2 + 0x5d0),param_1);
  if (__ptr != (int *)0x0) {
    iVar1 = *__ptr;
    puVar3 = (uint64_t *)(&currentRenderer);
    if (iVar1 == *(int *)*puVar3) {
      glDeleteFramebuffers(1,__ptr + 1);
      plVar2 = (long *)(&currentRenderer);
      SparseArray_remove(*(uint64_t *)(*plVar2 + 0x5d0),param_1);
      free(__ptr);
    }
  }
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @0013eb5c  size=480 */

uint64_t GLFramebuffer_getBound(int param_1)

{
  long *plVar1;
  uint64_t uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar1 = (long *)(&currentRenderer);
  lVar6 = *plVar1;
  lVar5 = 0;
  lVar3 = lVar6;
  if (param_1 < 0x88eb) {
    if (param_1 < 0x8643) {
      if (param_1 < 0x8513) {
        if (param_1 - 0xde0U < 2) goto LAB_0013ecd8;
        iVar4 = 0x806f;
        goto LAB_0013ec8c;
      }
      if (param_1 == 0x8513) goto LAB_0013ecd4;
      if (param_1 == 0x8620) goto LAB_0013ecd8;
    }
    else {
      if (param_1 < 0x8892) {
        if (param_1 == 0x8643) goto LAB_0013ecd8;
        iVar4 = 0x8804;
      }
      else {
        if (param_1 == 0x8892) goto LAB_0013ecd8;
        iVar4 = 0x8893;
      }
LAB_0013ec8c:
      if (param_1 == iVar4) {
        lVar5 = 1;
        goto LAB_0013ecd8;
      }
    }
LAB_0013ecc4:
    if (5 < param_1 - 0x8515U) {
      __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
      plVar1 = (long *)(&currentRenderer);
      lVar5 = 0xff;
      lVar3 = *plVar1;
      goto LAB_0013ecd8;
    }
  }
  else {
    if (param_1 < 0x8c1a) {
      if (param_1 < 0x8a11) {
        if (param_1 == 0x88eb) goto LAB_0013ecd4;
        iVar4 = 0x88ec;
      }
      else {
        if (param_1 == 0x8a11) {
          lVar5 = 4;
          goto LAB_0013ecd8;
        }
        iVar4 = 0x8c18;
      }
      if (param_1 != iVar4) goto LAB_0013ecc4;
LAB_0013ecb4:
      lVar5 = 3;
      goto LAB_0013ecd8;
    }
    if (param_1 < 0x8ca8) {
      if (param_1 != 0x8c1a) {
        if (param_1 == 0x8c2a) {
          lVar5 = 5;
          goto LAB_0013ecd8;
        }
        goto LAB_0013ecc4;
      }
      goto LAB_0013ecb4;
    }
    if (param_1 != 0x8ca8) {
      if (param_1 == 0x8d40) goto LAB_0013ecd8;
      iVar4 = 0x8ca9;
      goto LAB_0013ec8c;
    }
  }
LAB_0013ecd4:
  lVar5 = 2;
LAB_0013ecd8:
  uVar2 = (unsigned long)SparseArray_get(*(uint64_t *)(lVar3 + 0x5d0),*(uint32_t *)(lVar6 + lVar5 * 4 + 0x588))
  ;
  pthread_mutex_unlock((&glx_context_mutex));
  return uVar2;
}


/* @0013ed3c  size=332 */

void GLFramebuffer_setAttachment
               (uint32_t param_1,unsigned long param_2,int param_3,uint32_t param_4,uint8_t param_5)

{
  long lVar1;
  int iVar2;
  unsigned long uVar3;
  
  uVar3 = param_2 & 0xffffffff;
  lVar1 = GLFramebuffer_getBound(0);
  iVar2 = (int)param_2;
  if ((int)(uVar3 >> 5) == 0x467) {
    lVar1 = lVar1 + (unsigned long)(iVar2 - 0x8ce0) * 0xc;
    *(int *)(lVar1 + 8) = param_3;
    *(uint32_t *)(lVar1 + 0xc) = param_4;
    *(uint8_t *)(lVar1 + 0x10) = param_5;
    goto joined_r0x0013ed90;
  }
  if (iVar2 == 0x821a) {
LAB_0013edbc:
    *(int *)(lVar1 + 0x68) = param_3;
    *(uint32_t *)(lVar1 + 0x6c) = param_4;
    *(uint8_t *)(lVar1 + 0x70) = param_5;
    if (param_3 != 0) {
      if (param_3 == 0x8d41) {
        glFramebufferRenderbuffer(param_1,uVar3,0x8d41,param_4);
      }
      else {
        glFramebufferTexture2D(param_1,uVar3,param_3,param_4,param_5);
      }
    }
    if (iVar2 != 0x821a) {
      return;
    }
  }
  else if (iVar2 != 0x8d20) {
    if (iVar2 != 0x8d00) {
      return;
    }
    goto LAB_0013edbc;
  }
  *(int *)(lVar1 + 0x74) = param_3;
  *(uint32_t *)(lVar1 + 0x78) = param_4;
  *(uint8_t *)(lVar1 + 0x7c) = param_5;
joined_r0x0013ed90:
  if (param_3 == 0) {
    return;
  }
  if (param_3 != 0x8d41) {
    glFramebufferTexture2D(param_1,uVar3,param_3,param_4,param_5);
    return;
  }
  glFramebufferRenderbuffer(param_1,uVar3,0x8d41,param_4);
  return;
}


/* @0013f058  size=228 */

unsigned long GLFramebuffer_setDrawBuffers(uint32_t param_1,long param_2)

{
  bool bVar1;
  uint32_t uVar2;
  long *plVar3;
  long lVar4;
  unsigned long uVar5;
  uint32_t uVar6;
  long lVar7;
  uint32_t uVar8;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar3 = (long *)(&currentRenderer);
  lVar4 = SparseArray_get(*(uint64_t *)(*plVar3 + 0x5d0),*(uint32_t *)(*plVar3 + 0x588));
  uVar2 = (unsigned long)pthread_mutex_unlock((&glx_context_mutex));
  uVar6 = *(uint32_t *)(lVar4 + 0x80) & 0xfffc01ff;
  *(uint32_t *)(lVar4 + 0x80) = uVar6;
  if (param_1 != 0) {
    lVar7 = 0;
    bVar1 = false;
    do {
      uVar8 = *(uint32_t *)(param_2 + lVar7);
      if (uVar8 == 0) {
        uVar8 = 0x200;
LAB_0013f0d8:
        uVar6 = uVar6 | uVar8;
        bVar1 = true;
        *(uint32_t *)(lVar4 + 0x80) = uVar6;
      }
      else if (uVar8 >> 5 == 0x467) {
        uVar8 = 1 << (unsigned long)(uVar8 - 0x8cd6 & 0x1f);
        goto LAB_0013f0d8;
      }
      lVar7 = lVar7 + 4;
    } while ((unsigned long)param_1 * 4 - lVar7 != 0);
    if (bVar1) {
      glDrawBuffers(param_1,param_2); uVar5 = 0;
      return uVar5;
    }
  }
  return (unsigned long)uVar2;
}


/* @0013efac  size=172 */

unsigned long GLFramebuffer_setReadBuffer(uint32_t param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long *plVar3;
  long lVar4;
  unsigned long uVar5;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar3 = (long *)(&currentRenderer);
  lVar4 = SparseArray_get(*(uint64_t *)(*plVar3 + 0x5d0),*(uint32_t *)(*plVar3 + 0x588));
  uVar2 = (unsigned long)pthread_mutex_unlock((&glx_context_mutex));
  uVar1 = *(uint32_t *)(lVar4 + 0x80) & 0xfffffe00;
  *(uint32_t *)(lVar4 + 0x80) = uVar1;
  if (param_1 == 0) {
    uVar2 = 1;
  }
  else {
    if (param_1 >> 5 != 0x467) {
      return (unsigned long)uVar2;
    }
    uVar2 = 1 << (unsigned long)(param_1 - 0x8cdf & 0x1f);
  }
  *(uint32_t *)(lVar4 + 0x80) = uVar1 | uVar2;
  glReadBuffer(param_1); uVar5 = 0;
  return uVar5;
}


