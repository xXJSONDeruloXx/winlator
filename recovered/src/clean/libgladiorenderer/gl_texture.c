/*
 * gl_texture.c — Texture object management
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

/* @00137e1c  size=956 */

void GLTexture_bind(int param_1,int param_2)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  if (param_2 == 0) {
    plVar1 = (long *)(&currentRenderer);
    lVar5 = *plVar1;
    lVar4 = 0;
    if (param_1 < 0x88eb) {
      if (param_1 < 0x8643) {
        if (param_1 < 0x8513) {
          if (1 < param_1 - 0xde0U) {
            iVar3 = 0x806f;
            goto LAB_001380f8;
          }
        }
        else {
          if (param_1 == 0x8513) goto LAB_0013818c;
          if (param_1 != 0x8620) goto LAB_0013817c;
        }
      }
      else if (param_1 < 0x8892) {
        if (param_1 != 0x8643) {
          iVar3 = 0x8804;
LAB_001380f8:
          if (param_1 != iVar3) goto LAB_0013817c;
          lVar4 = 1;
        }
      }
      else if (param_1 != 0x8892) {
        iVar3 = 0x8893;
        goto LAB_001380f8;
      }
    }
    else if (param_1 < 0x8c1a) {
      if (param_1 < 0x8a11) {
        if (param_1 == 0x88eb) goto LAB_0013818c;
        iVar3 = 0x88ec;
      }
      else {
        if (param_1 == 0x8a11) {
          lVar4 = 4;
          goto LAB_00138190;
        }
        iVar3 = 0x8c18;
      }
      if (param_1 == iVar3) {
LAB_00138120:
        lVar4 = 3;
      }
      else {
LAB_0013817c:
        if (param_1 - 0x8515U < 6) {
LAB_0013818c:
          lVar4 = 2;
        }
        else {
          __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
          lVar4 = 0xff;
        }
      }
    }
    else if (param_1 < 0x8ca8) {
      if (param_1 == 0x8c1a) goto LAB_00138120;
      if (param_1 != 0x8c2a) goto LAB_0013817c;
      lVar4 = 5;
    }
    else {
      if (param_1 == 0x8ca8) goto LAB_0013818c;
      if (param_1 != 0x8d40) {
        iVar3 = 0x8ca9;
        goto LAB_001380f8;
      }
    }
LAB_00138190:
    param_2 = 0;
    *(uint64_t *)(lVar5 + lVar4 * 8 + 0x568) = 0;
    goto LAB_0013819c;
  }
  pthread_mutex_lock((&glx_context_mutex));
  plVar1 = (long *)(&currentRenderer);
  piVar2 = (int *)SparseArray_get(*(uint64_t *)(*plVar1 + 0x5b0),param_2);
  if (piVar2 == (int *)0x0) {
    piVar2 = calloc(1,0x14);
    *piVar2 = param_2;
    piVar2[1] = param_1;
    plVar1 = (long *)(&currentRenderer);
    SparseArray_put(*(uint64_t *)(*plVar1 + 0x5b0),param_2,piVar2);
  }
  pthread_mutex_unlock((&glx_context_mutex));
  plVar1 = (long *)(&currentRenderer);
  lVar5 = *plVar1;
  lVar4 = 0;
  if (param_1 < 0x88eb) {
    if (param_1 < 0x8643) {
      if (param_1 < 0x8513) {
        if (1 < param_1 - 0xde0U) {
          iVar3 = 0x806f;
          goto LAB_0013807c;
        }
      }
      else {
        if (param_1 == 0x8513) goto LAB_00138140;
        if (param_1 != 0x8620) goto LAB_00138130;
      }
    }
    else if (param_1 < 0x8892) {
      if (param_1 != 0x8643) {
        iVar3 = 0x8804;
LAB_0013807c:
        if (param_1 != iVar3) goto LAB_00138130;
        lVar4 = 1;
      }
    }
    else if (param_1 != 0x8892) {
      iVar3 = 0x8893;
      goto LAB_0013807c;
    }
  }
  else if (param_1 < 0x8c1a) {
    if (param_1 < 0x8a11) {
      if (param_1 == 0x88eb) goto LAB_00138140;
      iVar3 = 0x88ec;
    }
    else {
      if (param_1 == 0x8a11) {
        lVar4 = 4;
        goto LAB_00138144;
      }
      iVar3 = 0x8c18;
    }
    if (param_1 == iVar3) {
LAB_001380a4:
      lVar4 = 3;
    }
    else {
LAB_00138130:
      if (param_1 - 0x8515U < 6) {
LAB_00138140:
        lVar4 = 2;
      }
      else {
        __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
        lVar4 = 0xff;
      }
    }
  }
  else if (param_1 < 0x8ca8) {
    if (param_1 == 0x8c1a) goto LAB_001380a4;
    if (param_1 != 0x8c2a) goto LAB_00138130;
    lVar4 = 5;
  }
  else {
    if (param_1 == 0x8ca8) goto LAB_00138140;
    if (param_1 != 0x8d40) {
      iVar3 = 0x8ca9;
      goto LAB_0013807c;
    }
  }
LAB_00138144:
  *(int **)(lVar5 + lVar4 * 8 + 0x568) = piVar2;
LAB_0013819c:
  glBindTexture(param_1,param_2);
  return;
}


/* @00138274  size=252 */

void GLTexture_delete(uint32_t param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  void *__ptr;
  long lVar4;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  local_3c = param_1;
  pthread_mutex_lock((&glx_context_mutex));
  plVar3 = (long *)(&currentRenderer);
  __ptr = (void *)SparseArray_get(*(uint64_t *)(*plVar3 + 0x5b0),param_1);
  if (__ptr != (void *)0x0) {
    plVar3 = (long *)(&currentRenderer);
    lVar4 = *plVar3;
    if (*(void **)(lVar4 + 0x568) == __ptr) {
      *(uint64_t *)(lVar4 + 0x568) = 0;
    }
    if (*(void **)(lVar4 + 0x570) == __ptr) {
      *(uint64_t *)(lVar4 + 0x570) = 0;
    }
    if (*(void **)(lVar4 + 0x578) == __ptr) {
      *(uint64_t *)(lVar4 + 0x578) = 0;
    }
    if (*(void **)(lVar4 + 0x580) == __ptr) {
      *(uint64_t *)(lVar4 + 0x580) = 0;
    }
    SparseArray_remove(*(uint64_t *)(lVar4 + 0x5b0),param_1);
    free(__ptr);
  }
  glDeleteTextures(1,&local_3c);
  iVar2 = pthread_mutex_unlock((&glx_context_mutex));
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}


/* @00137c78  size=420 */

uint64_t GLTexture_getBound(int param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  plVar1 = (long *)(&currentRenderer);
  lVar4 = *plVar1;
  lVar3 = 0;
  if (param_1 < 0x88eb) {
    if (param_1 < 0x8643) {
      if (param_1 < 0x8513) {
        if (param_1 - 0xde0U < 2) goto LAB_00137de4;
        iVar2 = 0x806f;
        goto LAB_00137d98;
      }
      if (param_1 == 0x8513) goto LAB_00137de0;
      if (param_1 == 0x8620) goto LAB_00137de4;
    }
    else {
      if (param_1 < 0x8892) {
        if (param_1 == 0x8643) goto LAB_00137de4;
        iVar2 = 0x8804;
      }
      else {
        if (param_1 == 0x8892) goto LAB_00137de4;
        iVar2 = 0x8893;
      }
LAB_00137d98:
      if (param_1 == iVar2) {
        lVar3 = 1;
        goto LAB_00137de4;
      }
    }
LAB_00137dd0:
    if (5 < param_1 - 0x8515U) {
      __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
      lVar3 = 0xff;
      goto LAB_00137de4;
    }
  }
  else {
    if (param_1 < 0x8c1a) {
      if (param_1 < 0x8a11) {
        if (param_1 == 0x88eb) goto LAB_00137de0;
        iVar2 = 0x88ec;
      }
      else {
        if (param_1 == 0x8a11) {
          lVar3 = 4;
          goto LAB_00137de4;
        }
        iVar2 = 0x8c18;
      }
      if (param_1 != iVar2) goto LAB_00137dd0;
LAB_00137dc0:
      lVar3 = 3;
      goto LAB_00137de4;
    }
    if (param_1 < 0x8ca8) {
      if (param_1 != 0x8c1a) {
        if (param_1 == 0x8c2a) {
          lVar3 = 5;
          goto LAB_00137de4;
        }
        goto LAB_00137dd0;
      }
      goto LAB_00137dc0;
    }
    if (param_1 != 0x8ca8) {
      if (param_1 == 0x8d40) goto LAB_00137de4;
      iVar2 = 0x8ca9;
      goto LAB_00137d98;
    }
  }
LAB_00137de0:
  lVar3 = 2;
LAB_00137de4:
  return *(uint64_t *)(lVar4 + lVar3 * 8 + 0x568);
}


/* @00138210  size=100 */

uint32_t GLTexture_getType(uint32_t param_1)

{
  uint32_t uVar1;
  long *plVar2;
  long lVar3;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  lVar3 = SparseArray_get(*(uint64_t *)(*plVar2 + 0x5b0),param_1);
  pthread_mutex_unlock((&glx_context_mutex));
  if (lVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint32_t *)(lVar3 + 4);
  }
  return uVar1;
}


/* @001381d8  size=56 */

void GLTexture_setActiveUnit(uint32_t param_1)

{
  long *plVar1;
  
  plVar1 = (long *)(&currentRenderer);
  *(char *)(*plVar1 + 0x398) = (char)param_1 + '@';
  glActiveTexture(param_1);
  return;
}


