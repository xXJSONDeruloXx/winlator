/*
 * gl_query.c — Query object management
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

/* @00138c64  size=280 */

void GLQuery_begin(int param_1,uint32_t param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  struct timespec local_48;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  lVar2 = (long)FUN_00138d7c(param_2);
  if (lVar2 == 0) goto LAB_00138d54;
  *(uint8_t *)(lVar2 + 8) = 1;
  *(int *)(lVar2 + 0xc) = param_1;
  *(uint32_t *)(lVar2 + 0x10) = 0;
  plVar3 = (long *)(&currentRenderer);
  *(long *)(*plVar3 + 0x900) = lVar2;
  if (param_1 < 0x8c87) {
    if (param_1 == 0x88bf) {
      clock_gettime(0,&local_48);
      plVar3 = (long *)(&currentRenderer);
      *(int *)(lVar2 + 0x10) =
           ((int)local_48.tv_nsec + (int)local_48.tv_sec * 1000000000) - *(int *)(*plVar3 + 0x908);
      goto LAB_00138d54;
    }
    if (param_1 != 0x8914) {
      iVar4 = 0x8c2f;
      goto LAB_00138cf8;
    }
    param_1 = 0x8c2f;
  }
  else if (1 < param_1 - 0x8c87U) {
    iVar4 = 0x8d6a;
LAB_00138cf8:
    if (param_1 != iVar4) goto LAB_00138d54;
  }
  glBeginQuery(param_1,*(uint32_t *)(lVar2 + 4));
LAB_00138d54:
  if (*(long *)(lVar1 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00138bfc  size=104 */

int GLQuery_create(void)

{
  int iVar1;
  long *plVar2;
  
  pthread_mutex_lock((&glx_context_mutex));
  iVar1 = DAT_00144ee8;
  DAT_00144ee8 = DAT_00144ee8 + 1;
  plVar2 = (long *)(&currentRenderer);
  SparseArray_put(*(uint64_t *)(*plVar2 + 0x5d8),iVar1,&DAT_00144f24);
  pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @00139240  size=236 */

int GLQuery_delete(uint32_t param_1)

{
  int iVar1;
  long *plVar2;
  int *__ptr;
  uint64_t *puVar3;
  int *piVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  __ptr = (int *)SparseArray_get(*(uint64_t *)(*plVar2 + 0x5d8),param_1);
  if (__ptr == (int *)&DAT_00144f24) {
    plVar2 = (long *)(&currentRenderer);
    SparseArray_remove(*(uint64_t *)(*plVar2 + 0x5d8),param_1);
  }
  else if (__ptr != (int *)0x0) {
    puVar3 = (uint64_t *)(&currentRenderer);
    piVar4 = (int *)*puVar3;
    if (*(int **)(piVar4 + 0x240) == __ptr) {
      piVar4[0x240] = 0;
      piVar4[0x241] = 0;
    }
    if (*__ptr == *piVar4) {
      if (__ptr[1] != 0) {
        glDeleteQueries(1, (const GLuint*)&iVar1);
        puVar3 = (uint64_t *)(&currentRenderer);
        piVar4 = (int *)*puVar3;
      }
      SparseArray_remove(*(uint64_t *)(piVar4 + 0x176),param_1);
      free(__ptr);
    }
  }
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @00138e28  size=384 */

void GLQuery_end(int param_1)

{
  int iVar1;
  long lVar2;
  uint32_t uVar3;
  long *plVar4;
  unsigned long uVar5;
  uint64_t *puVar6;
  uint8_t *puVar7;
  struct timespec local_58;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar2 + 0x28);
  plVar4 = (long *)(&currentRenderer);
  puVar7 = *(uint8_t **)(*plVar4 + 0x900);
  if ((puVar7 == (uint8_t *)0x0) || (iVar1 = param_1, *(int *)(puVar7 + 0xc) != param_1)) {
    pthread_mutex_lock((&glx_context_mutex));
    plVar4 = (long *)(&currentRenderer);
    uVar3 = **(uint32_t **)(*plVar4 + 0x5d8);
    uVar5 = (unsigned long)uVar3;
    if (0 < (int)uVar3) {
      puVar6 = (uint64_t *)(*(long *)(*(uint32_t **)(*plVar4 + 0x5d8) + 2) + 8);
      do {
        puVar7 = (uint8_t *)*puVar6;
        if (((puVar7 != &DAT_00144f24) && (puVar7[8] != '\0')) &&
           (*(int *)(puVar7 + 0xc) == param_1)) {
          uVar3 = pthread_mutex_unlock((&glx_context_mutex));
          plVar4 = (long *)(unsigned long)uVar3;
          if (puVar7 == (uint8_t *)0x0) goto LAB_00138f7c;
          iVar1 = *(int *)(puVar7 + 0xc);
          goto LAB_00138e78;
        }
        uVar5 = uVar5 - 1;
        puVar6 = puVar6 + 2;
      } while (uVar5 != 0);
    }
    uVar3 = pthread_mutex_unlock((&glx_context_mutex));
    plVar4 = (long *)(unsigned long)uVar3;
  }
  else {
LAB_00138e78:
    puVar7[8] = 0;
    if (iVar1 == 0x88bf) {
      clock_gettime(0,&local_58);
      plVar4 = (long *)(&currentRenderer);
      *(int *)(puVar7 + 0x10) =
           ((int)local_58.tv_nsec + (int)local_58.tv_sec * 1000000000) -
           (*(int *)(*plVar4 + 0x908) + *(int *)(puVar7 + 0x10));
    }
    else {
      iVar1 = 0x8c2f;
      if (param_1 != 0x8914) {
        iVar1 = param_1;
      }
      *(uint32_t *)(puVar7 + 0x10) = 0;
      glEndQuery(iVar1); plVar4 = 0;
    }
  }
LAB_00138f7c:
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(plVar4);
}


/* @001390c8  size=208 */

void GLQuery_getObjectParamsv(uint64_t param_1,int param_2,int *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int local_3c;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  lVar2 = (long)FUN_00138d7c();
  if (lVar2 != 0) {
    if (param_2 == 0x8866) {
      if (*(int *)(lVar2 + 0xc) == 0x88bf) {
        iVar3 = *(int *)(lVar2 + 0x10);
      }
      else {
        local_3c = 0;
        glGetQueryObjectuiv(*(uint32_t *)(lVar2 + 4),0x8866,&local_3c);
        iVar3 = local_3c;
        if ((local_3c == 1) && (*(int *)(lVar2 + 0xc) == 0x8914)) {
          iVar3 = 0xff;
        }
        *(int *)(lVar2 + 0x10) = iVar3;
      }
    }
    else {
      if (param_2 != 0x8867) goto LAB_00139170;
      iVar3 = 1;
    }
    *param_3 = iVar3;
  }
LAB_00139170:
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00138fa8  size=288 */

long * GLQuery_getParamsv(int param_1,int param_2,int *param_3)

{
  uint32_t uVar1;
  long *plVar2;
  int iVar3;
  unsigned long uVar4;
  uint64_t *puVar5;
  uint8_t *puVar6;
  
  plVar2 = (long *)(&currentRenderer);
  puVar6 = *(uint8_t **)(*plVar2 + 0x900);
  if ((puVar6 != (uint8_t *)0x0) && (*(int *)(puVar6 + 0xc) == param_1)) {
LAB_00138fe8:
    if (param_2 == 0x8864) {
      iVar3 = (uint32_t)(*(int *)(puVar6 + 0xc) == 0x88bf) << 5;
    }
    else {
      if (param_2 != 0x8865) {
        return plVar2;
      }
      iVar3 = *(int *)(puVar6 + 0x10);
    }
    *param_3 = iVar3;
    return plVar2;
  }
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  uVar1 = **(uint32_t **)(*plVar2 + 0x5d8);
  uVar4 = (unsigned long)uVar1;
  if (0 < (int)uVar1) {
    puVar5 = (uint64_t *)(*(long *)(*(uint32_t **)(*plVar2 + 0x5d8) + 2) + 8);
    do {
      puVar6 = (uint8_t *)*puVar5;
      if (((puVar6 != &DAT_00144f24) && (puVar6[8] != '\0')) && (*(int *)(puVar6 + 0xc) == param_1))
      {
        uVar1 = pthread_mutex_unlock((&glx_context_mutex));
        plVar2 = (long *)(unsigned long)uVar1;
        if (puVar6 == (uint8_t *)0x0) {
          return plVar2;
        }
        goto LAB_00138fe8;
      }
      uVar4 = uVar4 - 1;
      puVar5 = puVar5 + 2;
    } while (uVar4 != 0);
  }
  uVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return (long *)(unsigned long)uVar1;
}


/* @00139198  size=168 */

void GLQuery_queryCounter(uint64_t param_1,int param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  struct timespec local_48;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar1 + 0x28);
  lVar2 = (long)FUN_00138d7c();
  if ((lVar2 != 0) && (param_2 == 0x8e28)) {
    *(uint32_t *)(lVar2 + 0xc) = 0x88bf;
    clock_gettime(0,&local_48);
    plVar3 = (long *)(&currentRenderer);
    *(int *)(lVar2 + 0x10) =
         ((int)local_48.tv_nsec + (int)local_48.tv_sec * 1000000000) - *(int *)(*plVar3 + 0x908);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


