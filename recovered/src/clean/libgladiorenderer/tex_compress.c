/*
 * tex_compress.c — DXT/BC texture compression/decompression
 *
 * Contains embedded stb_dxt for S3TC block compression.
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include "gladio_data.h"

void stb_compress_dxt_block(uint8_t *param_1, uint32_t *param_2, int param_3, unsigned long param_4);

static void FUN_0013aaa0(void*, void*, void*, void*, void*, int, int);
#include <GLES3/gl32.h>
#include <EGL/egl.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>

/* @0013a5cc  size=332 */

void compressTexImage2D(uint32_t param_1,int param_2,int param_3,long param_4,long param_5)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  long lVar4;
  uint8_t *pbVar5;
  uint32_t uVar6;
  int iVar7;
  int iVar8;
  uint32_t local_a8 [16];
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar2 + 0x28);
  bVar3 = (param_1 & 0xfffffffe) != 0x83f0;
  lVar1 = 8;
  if (bVar3) {
    lVar1 = 0x10;
  }
  if (0 < param_3) {
    iVar8 = 0;
    do {
      if (0 < param_2) {
        iVar7 = 0;
        do {
          lVar4 = 0;
          pbVar5 = &DAT_001161f7;
          do {
            if (((int)(iVar7 + (uint32_t)pbVar5[-1]) < param_2) &&
               ((int)(iVar8 + (uint32_t)*pbVar5) < param_3)) {
              uVar6 = *(uint32_t *)
                       (param_4 +
                       (long)(int)(iVar7 + (uint32_t)pbVar5[-1] + (iVar8 + (uint32_t)*pbVar5) * param_2) * 4
                       );
            }
            else {
              uVar6 = 0;
            }
            *(uint32_t *)((long)local_a8 + lVar4) = uVar6;
            lVar4 = lVar4 + 4;
            pbVar5 = pbVar5 + 2;
          } while (lVar4 != 0x40);
          stb_compress_dxt_block(param_5,local_a8,param_1 != 0x83f0 && bVar3,0);
          iVar7 = iVar7 + 4;
          param_5 = param_5 + lVar1;
        } while (iVar7 < param_2);
      }
      iVar8 = iVar8 + 4;
    } while (iVar8 < param_3);
  }
  if (*(long *)(lVar2 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013a718  size=604 */

void * decompressTexImage2D(int param_1,int param_2,int param_3,long param_4,uint8_t *param_5)

{
  uint32_t uVar1;
  short sVar2;
  uint8_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  void *pvVar6;
  long *__ptr;
  uint64_t *puVar7;
  int iVar8;
  uint32_t uVar9;
  uint8_t *pbVar10;
  uint32_t uVar11;
  unsigned long uVar12;
  long *plVar13;
  unsigned long uVar14;
  
  uVar1 = param_1 - 0x83f0;
  uVar3 = (uint8_t)(0x3020101 >> (unsigned long)(uVar1 * 8 & 0x1f));
  if (uVar1 >= 4) {
    uVar3 = 0;
  }
  pvVar6 = malloc((long)(param_2 * param_3 * 4));
  uVar1 = 3U >> (unsigned long)(uVar1 & 0xf) & (uint32_t)(uVar1 < 4);
  iVar8 = 8;
  if (uVar1 == 0) {
    iVar8 = 0x10;
  }
  uVar9 = 1;
  if (((param_5 != (uint8_t *)0x0) && (0x7f < param_3)) && (uVar9 = (uint32_t)*param_5, 3 < uVar9)) {
    uVar9 = 4;
  }
  __ptr = calloc((unsigned long)uVar9,0x20);
  if (uVar9 != 0) {
    uVar4 = 0;
    if (uVar9 != 0) {
      uVar4 = param_3 / (int)uVar9;
    }
    uVar11 = 0;
    uVar12 = 0;
    uVar14 = (unsigned long)(uVar9 - 1);
    plVar13 = __ptr;
    do {
      *(short *)((long)plVar13 + 0x12) = (short)uVar11;
      *(uint8_t *)(plVar13 + 3) = 0;
      *(uint8_t *)((long)plVar13 + 0x16) = uVar3;
      *(uint8_t *)((long)plVar13 + 0x17) = (uint8_t)uVar1 & param_1 != 0x83f0;
      uVar5 = uVar11 >> 2 & 0x3fff;
      *(short *)(plVar13 + 2) = (short)param_2;
      sVar2 = (short)(uVar4 & 0xfffffffc) + (short)uVar11;
      if (uVar14 <= uVar12) {
        sVar2 = (short)param_3;
      }
      *(short *)((long)plVar13 + 0x14) = sVar2;
      *plVar13 = param_4 + (unsigned long)(iVar8 * ((-param_2 & 3U) + param_2 >> 2) * uVar5);
      plVar13[1] = (long)pvVar6 + (long)(int)(param_2 * 0x10 * uVar5);
      if (uVar9 < 2) {
        FUN_0013aaa0(plVar13, 0, 0, 0, 0, 0, 0);
      }
      else {
        puVar7 = malloc(0x18);
        *puVar7 = FUN_0013aaa0;
        puVar7[1] = plVar13;
        puVar7[2] = 0;
        pthread_mutex_lock((pthread_mutex_t *)(param_5 + 4));
        if (*(long *)(param_5 + 0xb8) == 0) {
          pbVar10 = param_5 + 0xb8;
        }
        else {
          pbVar10 = (uint8_t *)(*(long *)(param_5 + 0xc0) + 0x10);
        }
        *(uint64_t **)pbVar10 = puVar7;
        *(uint64_t **)(param_5 + 0xc0) = puVar7;
        pthread_cond_signal((pthread_cond_t *)(param_5 + 0x2c));
        pthread_mutex_unlock((pthread_mutex_t *)(param_5 + 4));
        uVar14 = (unsigned long)(uVar9 - 1);
      }
      uVar12 = uVar12 + 1;
      plVar13 = plVar13 + 4;
      uVar11 = uVar11 + (uVar4 & 0xfffffffc);
    } while (uVar9 != uVar12);
  }
  if (1 < uVar9) {
    pthread_mutex_lock((pthread_mutex_t *)(param_5 + 0x5c));
    while (((param_5[2] == 0 && (*param_5 != 0)) ||
           ((*(long *)(param_5 + 0xb8) != 0 || (param_5[1] != 0))))) {
      pthread_cond_wait((pthread_cond_t *)(param_5 + 0x84),(pthread_mutex_t *)(param_5 + 0x5c));
    }
    pthread_mutex_unlock((pthread_mutex_t *)(param_5 + 0x5c));
  }
  free(__ptr);
  return pvVar6;
}


/* @0013a590  size=8 */

void stb_compress_bc4_block(uint64_t param_1,uint64_t param_2)

{
  FUN_0013a2dc(param_1,param_2,1);
  return;
}


/* @0013a598  size=52 */

void stb_compress_bc5_block(long param_1,long param_2)

{
  FUN_0013a2dc(param_1,param_2,2);
  FUN_0013a2dc(param_1 + 8,param_2 + 1,2);
  return;
}


/* @0013932c  size=4016 */

void stb_compress_dxt_block(uint8_t *param_1,uint32_t *param_2,int param_3,unsigned long param_4)

{
  /* TODO: stb_dxt block compression — complex bit manipulation needs manual cleanup */
}



// ─────────────────────────────────────────────
// INTERNAL
// ─────────────────────────────────────────────

