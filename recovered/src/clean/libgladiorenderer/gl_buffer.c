/*
 * gl_buffer.c — Buffer object management
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

/* @0013e000  size=148 */

int GLBuffer_allocateMemory(long param_1,int param_2)

{
  int __fd;
  void *pvVar1;
  
  __fd = ashmemCreateRegion("gl-buffer",(long)param_2);
  if (-1 < __fd) {
    if (*(void **)(param_1 + 8) != (void *)0x0) {
      munmap(*(void **)(param_1 + 8),(long)*(int *)(param_1 + 4));
      *(uint64_t *)(param_1 + 8) = 0;
      *(uint32_t *)(param_1 + 4) = 0;
    }
    pvVar1 = mmap((void *)0x0,(long)param_2,3,1,__fd,0);
    if (pvVar1 != (void *)0xffffffffffffffff) {
      *(void **)(param_1 + 8) = pvVar1;
      *(int *)(param_1 + 4) = param_2;
      return __fd;
    }
  }
  return -1;
}


/* @0013dc1c  size=996 */

long * GLBuffer_bind(int param_1,int param_2)

{
  uint32_t uVar1;
  long *plVar2;
  int *piVar3;
  int iVar4;
  uint64_t uVar5;
  long lVar6;
  long lVar7;
  
  plVar2 = (long *)(&currentRenderer);
  lVar6 = *plVar2;
  if (param_2 == 0) {
    lVar7 = *(long *)(lVar6 + 0x540);
    lVar6 = 0;
    if (param_1 < 0x88eb) {
      if (param_1 < 0x8643) {
        if (param_1 < 0x8513) {
          if (1 < param_1 - 0xde0U) {
            iVar4 = 0x806f;
            goto LAB_0013def8;
          }
        }
        else {
          if (param_1 == 0x8513) goto LAB_0013dec0;
          if (param_1 != 0x8620) goto LAB_0013dfa4;
        }
      }
      else if (param_1 < 0x8892) {
        if (param_1 != 0x8643) {
          iVar4 = 0x8804;
LAB_0013def8:
          if (param_1 != iVar4) goto LAB_0013dfa4;
          lVar6 = 1;
        }
      }
      else if (param_1 != 0x8892) {
        iVar4 = 0x8893;
        goto LAB_0013def8;
      }
    }
    else if (param_1 < 0x8c1a) {
      if (param_1 < 0x8a11) {
        if (param_1 == 0x88eb) goto LAB_0013dec0;
        iVar4 = 0x88ec;
      }
      else {
        if (param_1 == 0x8a11) {
          lVar6 = 4;
          goto LAB_0013dfb8;
        }
        iVar4 = 0x8c18;
      }
      if (param_1 == iVar4) {
LAB_0013df20:
        lVar6 = 3;
      }
      else {
LAB_0013dfa4:
        if (param_1 - 0x8515U < 6) {
          lVar6 = 2;
          goto LAB_0013dfb8;
        }
        plVar2 = (long *)__android_log_print(3,"System.out","gladio: unimplemented gl target %x",
                                             param_1);
        lVar6 = 0xff;
      }
    }
    else {
      if (param_1 < 0x8ca8) {
        if (param_1 == 0x8c1a) goto LAB_0013df20;
        if (param_1 != 0x8c2a) goto LAB_0013dfa4;
        lVar6 = 5;
LAB_0013dfb8:
        param_2 = 0;
        *(uint64_t *)(lVar7 + lVar6 * 8 + 0x168) = 0;
        goto LAB_0013dfc4;
      }
      if (param_1 != 0x8ca8) {
        if (param_1 != 0x8d40) {
          iVar4 = 0x8ca9;
          goto LAB_0013def8;
        }
        goto LAB_0013df24;
      }
LAB_0013dec0:
      lVar6 = 2;
    }
LAB_0013df24:
    *(uint64_t *)(lVar7 + lVar6 * 8 + 0x168) = 0;
    if (param_1 == 0x88ec) {
      return plVar2;
    }
    param_2 = 0;
    goto LAB_0013dfc4;
  }
  pthread_mutex_lock((&glx_context_mutex));
  piVar3 = (int *)SparseArray_get(*(uint64_t *)(lVar6 + 0x558),param_2);
  if (piVar3 == (int *)0x0) {
    piVar3 = calloc(1,0x10);
    uVar5 = *(uint64_t *)(lVar6 + 0x558);
    *piVar3 = param_2;
    SparseArray_put(uVar5,param_2,piVar3);
  }
  uVar1 = pthread_mutex_unlock((&glx_context_mutex));
  plVar2 = (long *)(unsigned long)uVar1;
  lVar7 = *(long *)(lVar6 + 0x540);
  lVar6 = 0;
  if (param_1 < 0x88eb) {
    if (param_1 < 0x8643) {
      if (param_1 < 0x8513) {
        if (1 < param_1 - 0xde0U) {
          iVar4 = 0x806f;
          goto LAB_0013de60;
        }
      }
      else {
        if (param_1 == 0x8513) goto LAB_0013de28;
        if (param_1 != 0x8620) goto LAB_0013df58;
      }
    }
    else if (param_1 < 0x8892) {
      if (param_1 != 0x8643) {
        iVar4 = 0x8804;
LAB_0013de60:
        if (param_1 != iVar4) goto LAB_0013df58;
        lVar6 = 1;
      }
    }
    else if (param_1 != 0x8892) {
      iVar4 = 0x8893;
      goto LAB_0013de60;
    }
  }
  else if (param_1 < 0x8c1a) {
    if (param_1 < 0x8a11) {
      if (param_1 == 0x88eb) goto LAB_0013de28;
      iVar4 = 0x88ec;
    }
    else {
      if (param_1 == 0x8a11) {
        lVar6 = 4;
        goto LAB_0013df6c;
      }
      iVar4 = 0x8c18;
    }
    if (param_1 == iVar4) {
LAB_0013de88:
      lVar6 = 3;
    }
    else {
LAB_0013df58:
      if (param_1 - 0x8515U < 6) {
        lVar6 = 2;
        goto LAB_0013df6c;
      }
      plVar2 = (long *)__android_log_print(3,"System.out","gladio: unimplemented gl target %x",
                                           param_1);
      lVar6 = 0xff;
    }
  }
  else {
    if (param_1 < 0x8ca8) {
      if (param_1 == 0x8c1a) goto LAB_0013de88;
      if (param_1 != 0x8c2a) goto LAB_0013df58;
      lVar6 = 5;
LAB_0013df6c:
      *(int **)(lVar7 + lVar6 * 8 + 0x168) = piVar3;
      goto LAB_0013dfc4;
    }
    if (param_1 != 0x8ca8) {
      if (param_1 != 0x8d40) {
        iVar4 = 0x8ca9;
        goto LAB_0013de60;
      }
      goto LAB_0013de8c;
    }
LAB_0013de28:
    lVar6 = 2;
  }
LAB_0013de8c:
  *(int **)(lVar7 + lVar6 * 8 + 0x168) = piVar3;
  if (param_1 == 0x88ec) {
    return plVar2;
  }
LAB_0013dfc4:
  glBindBuffer(param_1,param_2); plVar2 = (long *)0; /* glBindBuffer returns void */
  return plVar2;
}


/* @0013e094  size=440 */

void GLBuffer_delete(uint32_t param_1)

{
  uint32_t uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  void *__ptr;
  long lVar5;
  long lVar6;
  long lVar7;
  uint32_t local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar2 + 0x28);
  local_3c = param_1;
  plVar4 = (long *)(&currentRenderer);
  lVar7 = *plVar4;
  pthread_mutex_lock((&glx_context_mutex));
  __ptr = (void *)SparseArray_get(*(uint64_t *)(lVar7 + 0x558),param_1);
  if (__ptr != (void *)0x0) {
    uVar1 = *(uint32_t *)(lVar7 + 0x548);
    if (0 < (int)uVar1) {
      lVar5 = 0;
      do {
        lVar6 = *(long *)(*(long *)(lVar7 + 0x550) + lVar5 + 8);
        if (*(void **)(lVar6 + 0x168) == __ptr) {
          *(uint64_t *)(lVar6 + 0x168) = 0;
        }
        if (*(void **)(lVar6 + 0x170) == __ptr) {
          *(uint64_t *)(lVar6 + 0x170) = 0;
        }
        if (*(void **)(lVar6 + 0x178) == __ptr) {
          *(uint64_t *)(lVar6 + 0x178) = 0;
        }
        if (*(void **)(lVar6 + 0x180) == __ptr) {
          *(uint64_t *)(lVar6 + 0x180) = 0;
        }
        if (*(void **)(lVar6 + 0x188) == __ptr) {
          *(uint64_t *)(lVar6 + 0x188) = 0;
        }
        if (*(void **)(lVar6 + 400) == __ptr) {
          *(uint64_t *)(lVar6 + 400) = 0;
        }
        lVar5 = lVar5 + 0x10;
      } while ((unsigned long)uVar1 * 0x10 - lVar5 != 0);
    }
    if (*(void **)(lVar7 + 0x508) == __ptr) {
      *(uint64_t *)(lVar7 + 0x508) = 0;
    }
    if (*(void **)(lVar7 + 0x510) == __ptr) {
      *(uint64_t *)(lVar7 + 0x510) = 0;
    }
    if (*(void **)(lVar7 + 0x518) == __ptr) {
      *(uint64_t *)(lVar7 + 0x518) = 0;
    }
    if (*(void **)(lVar7 + 0x520) == __ptr) {
      *(uint64_t *)(lVar7 + 0x520) = 0;
    }
    if (*(void **)(lVar7 + 0x528) == __ptr) {
      *(uint64_t *)(lVar7 + 0x528) = 0;
    }
    if (*(void **)(lVar7 + 0x530) == __ptr) {
      *(uint64_t *)(lVar7 + 0x530) = 0;
    }
    if (*(void **)((long)__ptr + 8) != (void *)0x0) {
      munmap(*(void **)((long)__ptr + 8),(long)*(int *)((long)__ptr + 4));
      *(uint64_t *)((long)__ptr + 8) = 0;
      *(uint32_t *)((long)__ptr + 4) = 0;
    }
    free(__ptr);
    SparseArray_remove(*(uint64_t *)(lVar7 + 0x558),param_1);
  }
  glDeleteBuffers(1,&local_3c);
  iVar3 = pthread_mutex_unlock((&glx_context_mutex));
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar3);
}


/* @0013da74  size=424 */

uint64_t GLBuffer_getBound(int param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  plVar1 = (long *)(&currentRenderer);
  lVar4 = *(long *)(*plVar1 + 0x540);
  lVar3 = 0;
  if (param_1 < 0x88eb) {
    if (param_1 < 0x8643) {
      if (param_1 < 0x8513) {
        if (param_1 - 0xde0U < 2) goto LAB_0013dbe4;
        iVar2 = 0x806f;
        goto LAB_0013db98;
      }
      if (param_1 == 0x8513) goto LAB_0013dbe0;
      if (param_1 == 0x8620) goto LAB_0013dbe4;
    }
    else {
      if (param_1 < 0x8892) {
        if (param_1 == 0x8643) goto LAB_0013dbe4;
        iVar2 = 0x8804;
      }
      else {
        if (param_1 == 0x8892) goto LAB_0013dbe4;
        iVar2 = 0x8893;
      }
LAB_0013db98:
      if (param_1 == iVar2) {
        lVar3 = 1;
        goto LAB_0013dbe4;
      }
    }
LAB_0013dbd0:
    if (5 < param_1 - 0x8515U) {
      __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
      lVar3 = 0xff;
      goto LAB_0013dbe4;
    }
  }
  else {
    if (param_1 < 0x8c1a) {
      if (param_1 < 0x8a11) {
        if (param_1 == 0x88eb) goto LAB_0013dbe0;
        iVar2 = 0x88ec;
      }
      else {
        if (param_1 == 0x8a11) {
          lVar3 = 4;
          goto LAB_0013dbe4;
        }
        iVar2 = 0x8c18;
      }
      if (param_1 != iVar2) goto LAB_0013dbd0;
LAB_0013dbc0:
      lVar3 = 3;
      goto LAB_0013dbe4;
    }
    if (param_1 < 0x8ca8) {
      if (param_1 != 0x8c1a) {
        if (param_1 == 0x8c2a) {
          lVar3 = 5;
          goto LAB_0013dbe4;
        }
        goto LAB_0013dbd0;
      }
      goto LAB_0013dbc0;
    }
    if (param_1 != 0x8ca8) {
      if (param_1 == 0x8d40) goto LAB_0013dbe4;
      iVar2 = 0x8ca9;
      goto LAB_0013db98;
    }
  }
LAB_0013dbe0:
  lVar3 = 2;
LAB_0013dbe4:
  return *(uint64_t *)(lVar4 + lVar3 * 8 + 0x168);
}


/* @0013e24c  size=128 */

void GLBuffer_onDestroy(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  void *__ptr;
  unsigned long uVar3;
  
  puVar1 = *(uint32_t **)(param_1 + 0x1c0);
  uVar2 = *puVar1;
  uVar3 = (unsigned long)uVar2;
  if (0 < (int)uVar2) {
    while( true ) {
      uVar2 = uVar2 - 1;
      __ptr = *(void **)(*(long *)(puVar1 + 2) + (unsigned long)uVar2 * 0x10 + 8);
      if (*(void **)((long)__ptr + 8) != (void *)0x0) {
        munmap(*(void **)((long)__ptr + 8),(long)*(int *)((long)__ptr + 4));
      }
      free(__ptr);
      SparseArray_removeAt(*(uint64_t *)(param_1 + 0x1c0),uVar2);
      if ((long)uVar3 < 2) break;
      puVar1 = *(uint32_t **)(param_1 + 0x1c0);
      uVar3 = uVar3 - 1;
    }
  }
  return;
}


