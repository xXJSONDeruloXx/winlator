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
  long lVar1;
  uint64_t *puVar2;
  uint8_t *pbVar3;
  uint16_t uVar4;
  uint8_t *pbVar5;
  uint8_t *pbVar6;
  uint8_t *pbVar7;
  uint8_t bVar8;
  uint8_t bVar9;
  uint8_t bVar10;
  uint8_t bVar11;
  uint8_t bVar12;
  uint8_t bVar13;
  uint8_t bVar14;
  uint8_t bVar15;
  uint8_t bVar16;
  uint8_t bVar17;
  uint8_t bVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  long lVar23;
  uint64_t *puVar24;
  uint32_t *puVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  uint32_t *puVar34;
  bool bVar35;
  int iVar36;
  uint32_t uVar37;
  uint32_t uVar38;
  uint32_t uVar39;
  uint32_t uVar40;
  int iVar41;
  uint32_t *puVar42;
  uint32_t *puVar43;
  uint32_t uVar44;
  int iVar45;
  int iVar46;
  unsigned long uVar47;
  uint32_t uVar48;
  int iVar49;
  int iVar50;
  uint32_t uVar51;
  int iVar52;
  int iVar53;
  long lVar54;
  unsigned long uVar55;
  unsigned long uVar56;
  unsigned long uVar57;
  uint32_t uVar58;
  uint32_t uVar59;
  uint32_t *puVar60;
  uint32_t uVar61;
  long lVar62;
  uint32_t uVar63;
  int iVar64;
  float fVar65;
  float fVar66;
  uint64_t uVar67;
  int iVar68;
  int iVar69;
  uint64_t uVar70;
  int iVar71;
  int iVar72;
  float fVar73;
  float fVar74;
  uint8_t bVar76;
  uint64_t uVar75;
  int iVar77;
  int iVar78;
  uint64_t uVar79;
  int iVar80;
  int iVar81;
  float fVar82;
  float fVar83;
  uint8_t bVar85;
  uint64_t uVar84;
  int iVar86;
  int iVar87;
  uint64_t uVar88;
  int iVar89;
  float fVar90;
  int iVar91;
  float fVar92;
  int iVar93;
  int iVar94;
  int iVar95;
  int iVar96;
  float fVar97;
  int iVar98;
  int iVar99;
  int iVar100;
  float fVar101;
  float fVar102;
  int iVar103;
  int iVar104;
  int iVar105;
  int iVar106;
  int iVar107;
  int iVar108;
  int iVar109;
  int iVar110;
  uint32_t local_100;
  uint32_t uStack_fc;
  uint32_t uStack_f8;
  uint8_t uStack_f5;
  uint32_t uStack_f4;
  uint32_t local_f0;
  uint8_t uStack_ed;
  uint32_t local_ec;
  uint32_t local_e8;
  uint8_t uStack_e5;
  uint32_t local_e4;
  uint32_t local_e0;
  uint8_t uStack_dd;
  uint32_t uStack_dc;
  uint32_t uStack_d8;
  uint8_t uStack_d5;
  uint32_t uStack_d4;
  uint8_t uStack_d1;
  uint32_t local_d0;
  uint8_t uStack_cd;
  uint32_t local_cc;
  uint8_t uStack_c9;
  uint8_t local_c8 [4];
  uint32_t local_c4;
  uint8_t uStack_c1;
  uint32_t local_b8;
  uint32_t local_b4;
  uint32_t local_b0;
  uint8_t local_ac;
  uint8_t local_ab;
  uint8_t local_aa;
  uint32_t local_a8 [6];
  long local_90;
  
  /* stack canary setup (elided) */
  local_90 = *(long *)(lVar23 + 0x28);
  if (param_3 != 0) {
    FUN_0013a2dc(param_1,(long)param_2 + 3,4);
    puVar42 = param_2 + 2;
    uVar67 = *(uint64_t *)param_2;
    puVar43 = param_2 + 4;
    puVar60 = param_2 + 6;
    puVar34 = param_2 + 8;
    puVar25 = param_2 + 10;
    param_1 = param_1 + 8;
    puVar2 = (uint64_t *)((long)param_2 + 0x2f);
    puVar24 = (uint64_t *)((long)param_2 + 0x37);
    param_2 = &local_100;
    uStack_c1 = 0xff;
    local_cc = (uint32_t)((unsigned long)*puVar2 >> 0x28);
    uStack_fc = (uint32_t)((unsigned long)uVar67 >> 0x20);
    local_100 = CONCAT13(0xff,(int)uVar67);
    local_100 = CONCAT17(0xff,local_100);
    uStack_f4 = (uint32_t)((unsigned long)*(uint64_t *)puVar42 >> 0x20);
    uStack_f8 = CONCAT13(0xff,(int)*(uint64_t *)puVar42);
    uStack_f8 = CONCAT17(0xff,uStack_f8);
    local_ec = (uint32_t)((unsigned long)*(uint64_t *)puVar43 >> 0x20);
    local_f0 = CONCAT13(0xff,(int)*(uint64_t *)puVar43);
    local_f0 = CONCAT17(0xff,local_f0);
    local_e4 = (uint32_t)((unsigned long)*(uint64_t *)puVar60 >> 0x20);
    local_e8 = CONCAT13(0xff,(int)*(uint64_t *)puVar60);
    local_e8 = CONCAT17(0xff,local_e8);
    uStack_dc = (uint32_t)((unsigned long)*(uint64_t *)puVar34 >> 0x20);
    local_e0 = CONCAT13(0xff,(int)*(uint64_t *)puVar34);
    local_e0 = CONCAT17(0xff,local_e0);
    uStack_d8 = CONCAT13(0xff,(int)*(uint64_t *)puVar25);
    uStack_d4 = CONCAT13(0xff,(int)((unsigned long)*(uint64_t *)puVar25 >> 0x20));
    local_d0 = CONCAT13(0xff,(int)((unsigned long)*puVar2 >> 8));
    uStack_c9 = CONCAT71((int)((unsigned long)*puVar24 >> 8),0xff);
    uVar67 = uStack_c9;
    local_c4 = (uint32_t)((unsigned long)*puVar24 >> 0x28);
    uStack_c9 = CONCAT14(0xff,(int)uVar67);
  }
  uVar44 = *param_2;
  uVar48 = param_2[1];
  uVar51 = 1;
  if ((param_4 & 2) != 0) {
    uVar51 = 2;
  }
  if ((((((uVar48 == uVar44) && (param_2[2] == uVar44)) && (param_2[3] == uVar44)) &&
       ((param_2[4] == uVar44 && (param_2[5] == uVar44)))) &&
      (((param_2[6] == uVar44 && ((param_2[7] == uVar44 && (param_2[8] == uVar44)))) &&
       (param_2[9] == uVar44)))) &&
     ((((param_2[10] == uVar44 && (param_2[0xb] == uVar44)) && (param_2[0xc] == uVar44)) &&
      (((param_2[0xd] == uVar44 && (param_2[0xe] == uVar44)) && (param_2[0xf] == uVar44)))))) {
    lVar54 = (unsigned long)(uint8_t)(uVar44 >> 8) * 2;
    lVar62 = (unsigned long)(uint8_t)uVar44 * 2;
    lVar1 = (unsigned long)(uVar44 >> 0x10 & 0xff) * 2;
    uVar44 = (uint32_t)(uint8_t)(&DAT_00116416)[lVar54] << 5 | (uint32_t)(uint8_t)(&DAT_00116216)[lVar62] << 0xb |
             (uint32_t)(uint8_t)(&DAT_00116216)[lVar1];
    uVar48 = (uint32_t)(uint8_t)(&DAT_00116417)[lVar54] << 5 | (uint32_t)(uint8_t)(&DAT_00116217)[lVar62] << 0xb |
             (uint32_t)(uint8_t)(&DAT_00116217)[lVar1];
    uVar40 = 0xaaaaaaaa;
  }
  else {
    lVar54 = 0;
    while( true ) {
      uVar37 = uVar44 & 0xff;
      uVar63 = uVar48 & 0xff;
      bVar76 = *(uint8_t *)((long)param_2 + lVar54 + 8);
      bVar85 = *(uint8_t *)((long)param_2 + lVar54 + 0xc);
      uVar40 = uVar63;
      if (uVar63 <= uVar37) {
        uVar40 = uVar37;
      }
      bVar8 = *(uint8_t *)((long)param_2 + lVar54 + 0x10);
      if (uVar63 <= uVar37) {
        uVar44 = uVar48;
      }
      uVar48 = uVar37;
      if (uVar37 <= uVar63) {
        uVar48 = uVar40;
      }
      bVar9 = *(uint8_t *)((long)param_2 + lVar54 + 0x14);
      uVar40 = uVar44 & 0xff;
      bVar10 = *(uint8_t *)((long)param_2 + lVar54 + 0x18);
      uVar38 = (uint32_t)bVar76;
      uVar61 = uVar38;
      if (bVar76 <= uVar48) {
        uVar61 = uVar48;
      }
      bVar11 = *(uint8_t *)((long)param_2 + lVar54 + 0x1c);
      if (uVar38 <= uVar40) {
        uVar44 = (uint32_t)bVar76;
      }
      if (uVar40 <= uVar38) {
        uVar48 = uVar61;
      }
      bVar76 = *(uint8_t *)((long)param_2 + lVar54 + 0x20);
      uVar40 = uVar44 & 0xff;
      uVar39 = (uint32_t)bVar85;
      bVar12 = *(uint8_t *)((long)param_2 + lVar54 + 0x24);
      uVar61 = uVar39;
      if (bVar85 <= uVar48) {
        uVar61 = uVar48;
      }
      bVar13 = *(uint8_t *)((long)param_2 + lVar54 + 0x28);
      if (uVar39 <= uVar40) {
        uVar44 = (uint32_t)bVar85;
      }
      if (uVar40 <= uVar39) {
        uVar48 = uVar61;
      }
      bVar14 = *(uint8_t *)((long)param_2 + lVar54 + 0x2c);
      uVar40 = uVar44 & 0xff;
      uVar39 = (uint32_t)bVar8;
      bVar15 = *(uint8_t *)((long)param_2 + lVar54 + 0x30);
      uVar61 = uVar39;
      if (bVar8 <= uVar48) {
        uVar61 = uVar48;
      }
      bVar16 = *(uint8_t *)((long)param_2 + lVar54 + 0x34);
      if (uVar39 <= uVar40) {
        uVar44 = (uint32_t)bVar8;
      }
      if (uVar40 <= uVar39) {
        uVar48 = uVar61;
      }
      bVar17 = *(uint8_t *)((long)param_2 + lVar54 + 0x38);
      uVar40 = uVar44 & 0xff;
      uVar39 = (uint32_t)bVar9;
      bVar18 = *(uint8_t *)((long)param_2 + lVar54 + 0x3c);
      uVar61 = uVar39;
      if (bVar9 <= uVar48) {
        uVar61 = uVar48;
      }
      if (uVar39 <= uVar40) {
        uVar44 = (uint32_t)bVar9;
      }
      if (uVar40 <= uVar39) {
        uVar48 = uVar61;
      }
      uVar40 = uVar44 & 0xff;
      uVar39 = (uint32_t)bVar10;
      uVar61 = uVar39;
      if (bVar10 <= uVar48) {
        uVar61 = uVar48;
      }
      if (uVar39 <= uVar40) {
        uVar44 = (uint32_t)bVar10;
      }
      if (uVar40 <= uVar39) {
        uVar48 = uVar61;
      }
      uVar40 = uVar44 & 0xff;
      uVar39 = (uint32_t)bVar11;
      uVar61 = uVar39;
      if (bVar11 <= uVar48) {
        uVar61 = uVar48;
      }
      (&local_b8)[lVar54] =
           uVar37 + uVar63 + uVar38 + (uint32_t)bVar85 + (uint32_t)bVar8 + (uint32_t)bVar9 + (uint32_t)bVar10 +
           (uint32_t)bVar11 + (uint32_t)bVar76 + (uint32_t)bVar12 + (uint32_t)bVar13 + (uint32_t)bVar14 + (uint32_t)bVar15 +
           (uint32_t)bVar16 + (uint32_t)bVar17 + (uint32_t)bVar18 + 8 >> 4;
      if (uVar39 <= uVar40) {
        uVar44 = (uint32_t)bVar11;
      }
      if (uVar40 <= uVar39) {
        uVar48 = uVar61;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar76;
      uVar63 = uVar40;
      if (bVar76 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar76;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar12;
      uVar63 = uVar40;
      if (bVar12 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar12;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar13;
      uVar63 = uVar40;
      if (bVar13 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar13;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar14;
      uVar63 = uVar40;
      if (bVar14 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar14;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar15;
      uVar63 = uVar40;
      if (bVar15 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar15;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar16;
      uVar63 = uVar40;
      if (bVar16 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar16;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar17;
      uVar63 = uVar40;
      if (bVar17 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar17;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      uVar37 = uVar44 & 0xff;
      uVar40 = (uint32_t)bVar18;
      uVar63 = uVar40;
      if (bVar18 <= uVar48) {
        uVar63 = uVar48;
      }
      if (uVar40 <= uVar37) {
        uVar44 = (uint32_t)bVar18;
      }
      if (uVar37 <= uVar40) {
        uVar48 = uVar63;
      }
      local_a8[lVar54 + 3] = uVar44 & 0xff;
      local_a8[lVar54] = uVar48;
      if (lVar54 == 2) break;
      uVar44 = (uint32_t)*(uint8_t *)((long)param_2 + lVar54 + 1);
      uVar48 = (uint32_t)*(uint8_t *)((long)param_2 + lVar54 + 5);
      lVar54 = lVar54 + 1;
    }
    uVar70 = *(uint64_t *)(param_2 + 2);
    uVar67 = *(uint64_t *)param_2;
    uVar79 = *(uint64_t *)(param_2 + 6);
    uVar75 = *(uint64_t *)(param_2 + 4);
    iVar45 = (uint8_t)param_2[0xc] - local_b8;
    iVar49 = (uint8_t)param_2[0xd] - local_b8;
    iVar52 = (uint8_t)param_2[0xe] - local_b8;
    iVar53 = (uint8_t)param_2[0xf] - local_b8;
    uVar88 = *(uint64_t *)(param_2 + 10);
    uVar84 = *(uint64_t *)(param_2 + 8);
    iVar50 = *(uint8_t *)((long)param_2 + 0x31) - local_b4;
    iVar46 = *(uint8_t *)((long)param_2 + 0x3d) - local_b4;
    bVar85 = (uint8_t)((unsigned long)uVar84 >> 0x20);
    iVar36 = (uint32_t)*(uint8_t *)((long)param_2 + 0x3e) - local_b0;
    bVar76 = (uint8_t)((unsigned long)uVar75 >> 0x20);
    iVar64 = (uint8_t)uVar67 - local_b8;
    iVar68 = (uint8_t)((unsigned long)uVar67 >> 0x20) - local_b8;
    iVar69 = (uint8_t)uVar70 - local_b8;
    iVar71 = (uint8_t)((unsigned long)uVar70 >> 0x20) - local_b8;
    iVar81 = (uint8_t)((unsigned long)uVar67 >> 8) - local_b4;
    iVar86 = (uint8_t)((unsigned long)uVar67 >> 0x28) - local_b4;
    iVar87 = (uint8_t)((unsigned long)uVar70 >> 8) - local_b4;
    iVar89 = (uint8_t)((unsigned long)uVar70 >> 0x28) - local_b4;
    iVar26 = (uint32_t)(uint8_t)((unsigned long)uVar67 >> 0x10) - local_b0;
    iVar27 = (uint32_t)(uint8_t)((unsigned long)uVar67 >> 0x30) - local_b0;
    iVar103 = (uint32_t)(uint8_t)((unsigned long)uVar70 >> 0x10) - local_b0;
    iVar104 = (uint32_t)(uint8_t)((unsigned long)uVar70 >> 0x30) - local_b0;
    iVar41 = *(uint8_t *)((long)param_2 + 0x35) - local_b4;
    iVar19 = *(uint8_t *)((long)param_2 + 0x39) - local_b4;
    iVar28 = ((CONCAT12(bVar76,(short)uVar75) & 0xff00ff) & 0xff) - local_b8;
    iVar29 = bVar76 - local_b8;
    iVar105 = (uint8_t)uVar79 - local_b8;
    iVar106 = (uint8_t)((unsigned long)uVar79 >> 0x20) - local_b8;
    iVar30 = (uint8_t)((unsigned long)uVar75 >> 8) - local_b4;
    iVar31 = (uint8_t)((unsigned long)uVar75 >> 0x28) - local_b4;
    iVar107 = (uint8_t)((unsigned long)uVar79 >> 8) - local_b4;
    iVar108 = (uint8_t)((unsigned long)uVar79 >> 0x28) - local_b4;
    iVar32 = (uint32_t)(uint8_t)((unsigned long)uVar75 >> 0x10) - local_b0;
    iVar33 = (uint32_t)(uint8_t)((unsigned long)uVar75 >> 0x30) - local_b0;
    iVar109 = (uint32_t)(uint8_t)((unsigned long)uVar79 >> 0x10) - local_b0;
    iVar110 = (uint32_t)(uint8_t)((unsigned long)uVar79 >> 0x30) - local_b0;
    iVar96 = (uint8_t)((unsigned long)uVar84 >> 8) - local_b4;
    iVar98 = (uint8_t)((unsigned long)uVar84 >> 0x28) - local_b4;
    iVar99 = (uint8_t)((unsigned long)uVar88 >> 8) - local_b4;
    iVar100 = (uint8_t)((unsigned long)uVar88 >> 0x28) - local_b4;
    iVar72 = (uint32_t)(uint8_t)((unsigned long)uVar84 >> 0x10) - local_b0;
    iVar77 = (uint32_t)(uint8_t)((unsigned long)uVar84 >> 0x30) - local_b0;
    iVar78 = (uint32_t)(uint8_t)((unsigned long)uVar88 >> 0x10) - local_b0;
    iVar80 = (uint32_t)(uint8_t)((unsigned long)uVar88 >> 0x30) - local_b0;
    iVar91 = ((CONCAT12(bVar85,(short)uVar84) & 0xff00ff) & 0xff) - local_b8;
    iVar93 = bVar85 - local_b8;
    iVar94 = (uint8_t)uVar88 - local_b8;
    iVar95 = (uint8_t)((unsigned long)uVar88 >> 0x20) - local_b8;
    iVar20 = (uint32_t)*(uint8_t *)((long)param_2 + 0x32) - local_b0;
    iVar21 = (uint32_t)*(uint8_t *)((long)param_2 + 0x36) - local_b0;
    iVar22 = (uint32_t)*(uint8_t *)((long)param_2 + 0x3a) - local_b0;
    fVar66 = (float)(int)(local_a8[0] - local_a8[3]);
    fVar74 = (float)(int)(local_a8[1] - local_a8[4]);
    fVar65 = (float)(iVar64 * iVar64 + iVar28 * iVar28 + iVar91 * iVar91 +
                     iVar68 * iVar68 + iVar29 * iVar29 + iVar93 * iVar93 +
                     iVar69 * iVar69 + iVar105 * iVar105 + iVar94 * iVar94 +
                     iVar71 * iVar71 + iVar106 * iVar106 + iVar95 * iVar95 + iVar45 * iVar45 +
                     iVar49 * iVar49 + iVar52 * iVar52 + iVar53 * iVar53) / 255.0;
    fVar73 = (float)(iVar81 * iVar64 + iVar30 * iVar28 + iVar96 * iVar91 +
                     iVar86 * iVar68 + iVar31 * iVar29 + iVar98 * iVar93 +
                     iVar87 * iVar69 + iVar107 * iVar105 + iVar99 * iVar94 +
                     iVar89 * iVar71 + iVar108 * iVar106 + iVar100 * iVar95 + iVar50 * iVar45 +
                     iVar41 * iVar49 + iVar19 * iVar52 + iVar46 * iVar53) / 255.0;
    fVar92 = (float)(iVar81 * iVar81 + iVar30 * iVar30 + iVar96 * iVar96 +
                     iVar86 * iVar86 + iVar31 * iVar31 + iVar98 * iVar98 +
                     iVar87 * iVar87 + iVar107 * iVar107 + iVar99 * iVar99 +
                     iVar89 * iVar89 + iVar108 * iVar108 + iVar100 * iVar100 + iVar50 * iVar50 +
                     iVar41 * iVar41 + iVar19 * iVar19 + iVar46 * iVar46) / 255.0;
    fVar102 = (float)(int)(local_a8[2] - local_a8[5]);
    fVar82 = (float)(iVar26 * iVar64 + iVar32 * iVar28 + iVar72 * iVar91 +
                     iVar27 * iVar68 + iVar33 * iVar29 + iVar77 * iVar93 +
                     iVar103 * iVar69 + iVar109 * iVar105 + iVar78 * iVar94 +
                     iVar104 * iVar71 + iVar110 * iVar106 + iVar80 * iVar95 + iVar20 * iVar45 +
                     iVar21 * iVar49 + iVar22 * iVar52 + iVar36 * iVar53) / 255.0;
    fVar97 = (float)(iVar26 * iVar81 + iVar32 * iVar30 + iVar72 * iVar96 +
                     iVar27 * iVar86 + iVar33 * iVar31 + iVar77 * iVar98 +
                     iVar103 * iVar87 + iVar109 * iVar107 + iVar78 * iVar99 +
                     iVar104 * iVar89 + iVar110 * iVar108 + iVar80 * iVar100 + iVar20 * iVar50 +
                     iVar21 * iVar41 + iVar22 * iVar19 + iVar36 * iVar46) / 255.0;
    fVar90 = (float)(iVar26 * iVar26 + iVar32 * iVar32 + iVar72 * iVar72 +
                     iVar27 * iVar27 + iVar33 * iVar33 + iVar77 * iVar77 +
                     iVar103 * iVar103 + iVar109 * iVar109 + iVar78 * iVar78 +
                     iVar104 * iVar104 + iVar110 * iVar110 + iVar80 * iVar80 + iVar20 * iVar20 +
                     iVar21 * iVar21 + iVar22 * iVar22 + iVar36 * iVar36) / 255.0;
    fVar101 = fVar65 * fVar66 + fVar73 * fVar74 + fVar82 * fVar102;
    fVar83 = fVar73 * fVar66 + fVar92 * fVar74 + fVar97 * fVar102;
    fVar74 = fVar82 * fVar66 + fVar97 * fVar74 + fVar90 * fVar102;
    fVar102 = fVar82 * fVar74 + fVar65 * fVar101 + fVar73 * fVar83;
    fVar66 = fVar97 * fVar74 + fVar73 * fVar101 + fVar92 * fVar83;
    fVar101 = fVar90 * fVar74 + fVar82 * fVar101 + fVar97 * fVar83;
    fVar83 = fVar82 * fVar101 + fVar65 * fVar102 + fVar73 * fVar66;
    fVar74 = fVar97 * fVar101 + fVar73 * fVar102 + fVar92 * fVar66;
    fVar102 = fVar90 * fVar101 + fVar82 * fVar102 + fVar97 * fVar66;
    fVar66 = fVar82 * fVar102 + fVar65 * fVar83 + fVar73 * fVar74;
    fVar73 = fVar97 * fVar102 + fVar73 * fVar83 + fVar92 * fVar74;
    fVar65 = fVar90 * fVar102 + fVar82 * fVar83 + fVar97 * fVar74;
    fVar83 = ABS(fVar66);
    fVar74 = ABS(fVar73);
    fVar102 = ABS(fVar65);
    if (fVar74 <= fVar83) {
      fVar74 = fVar83;
    }
    if (fVar102 <= fVar74) {
      fVar102 = fVar74;
    }
    if (4.0 <= fVar102) {
      fVar102 = 512.0 / fVar102;
      iVar45 = (int)(fVar102 * fVar66);
      iVar49 = (int)(fVar102 * fVar73);
      iVar52 = (int)(fVar102 * fVar65);
    }
    else {
      iVar45 = 299;
      iVar49 = 0x24b;
      iVar52 = 0x72;
    }
    iVar53 = iVar45 * (uint32_t)(uint8_t)*param_2 + iVar49 * (uint32_t)*(uint8_t *)((long)param_2 + 1) +
             iVar52 * (uint32_t)*(uint8_t *)((long)param_2 + 2);
    puVar43 = param_2;
    lVar54 = 0;
    puVar34 = param_2;
    iVar50 = iVar53;
    do {
      iVar41 = iVar50;
      iVar36 = iVar53;
      puVar60 = puVar34;
      puVar42 = puVar43;
      puVar43 = (uint32_t *)((long)param_2 + lVar54 + 4);
      lVar62 = lVar54 + 4;
      iVar46 = iVar45 * (uint32_t)(uint8_t)*puVar43 + iVar49 * (uint32_t)*(uint8_t *)((long)param_2 + lVar54 + 5)
               + iVar52 * (uint32_t)*(uint8_t *)((long)param_2 + lVar54 + 6);
      iVar53 = iVar46;
      puVar34 = puVar43;
      if (iVar36 <= iVar46) {
        iVar53 = iVar36;
        puVar34 = puVar60;
      }
      iVar50 = iVar46;
      if (iVar46 <= iVar41) {
        iVar50 = iVar41;
        puVar43 = puVar42;
      }
      lVar54 = lVar62;
    } while (lVar62 != 0x3c);
    pbVar3 = (uint8_t *)((long)param_2 + 0x3d);
    pbVar5 = (uint8_t *)((long)param_2 + 0x3e);
    pbVar7 = pbVar3;
    if (iVar46 <= iVar41) {
      pbVar7 = (uint8_t *)((long)puVar42 + 1);
      pbVar5 = (uint8_t *)((long)puVar42 + 2);
    }
    if (iVar36 <= iVar46) {
      pbVar3 = (uint8_t *)((long)puVar60 + 1);
    }
    pbVar6 = (uint8_t *)((long)param_2 + 0x3e);
    if (iVar36 <= iVar46) {
      pbVar6 = (uint8_t *)((long)puVar60 + 2);
    }
    uVar44 = (uint32_t)(uint8_t)*puVar43 * 0x1f + 0x80;
    uVar48 = (uint32_t)*pbVar7 * 0x3f + 0x80;
    uVar37 = (uint32_t)(uint8_t)*puVar34 * 0x1f + 0x80;
    uVar63 = (uint32_t)*pbVar3 * 0x3f + 0x80;
    uVar40 = (uint32_t)*pbVar5 * 0x1f + 0x80;
    uVar61 = (uint32_t)*pbVar6 * 0x1f + 0x80;
    uVar44 = (uVar48 + (uVar48 >> 8) >> 3 & 0x1fe0) + ((uVar44 + (uVar44 >> 8)) * 8 & 0xf800) +
             (uVar40 + (uVar40 >> 8) >> 8);
    uVar48 = (uVar63 + (uVar63 >> 8) >> 3 & 0x1fe0) + ((uVar37 + (uVar37 >> 8)) * 8 & 0xf800) +
             (uVar61 + (uVar61 >> 8) >> 8);
    if ((uVar44 & 0xffff) == (uVar48 & 0xffff)) {
      uVar37 = 0;
    }
    else {
      uVar37 = uVar44 >> 0xb & 0x1f;
      uVar63 = uVar48 >> 0xb & 0x1f;
      uVar40 = (uVar44 & 0xffff) >> 5 & 0x3f;
      uVar39 = (uVar48 & 0xffff) >> 5 & 0x3f;
      uVar37 = (uVar37 | uVar37 << 5) >> 2;
      uVar63 = (uVar63 | uVar63 << 5) >> 2;
      uVar40 = (uVar40 | uVar40 << 6) >> 4;
      uVar61 = (uVar44 & 0x1f | (uVar44 & 0x1f) << 5) >> 2;
      uVar38 = (uVar48 & 0x1f | (uVar48 & 0x1f) << 5) >> 2;
      uVar39 = (uVar39 | uVar39 << 6) >> 4;
      (*(uint8_t*)((char*)&local_b8 + 0)) = (uint8_t)uVar37;
      (*(uint16_t*)((char*)&local_b8 + 0)) = CONCAT11((char)uVar40,(uint8_t)local_b8);
      (*(uint32_t*)((char*)&local_b8 + 0)) = CONCAT12((char)uVar61,(uint16_t)local_b8);
      (*(uint8_t*)((char*)&local_b4 + 0)) = (uint8_t)uVar63;
      (*(uint16_t*)((char*)&local_b4 + 0)) = CONCAT11((char)uVar39,(uint8_t)local_b4);
      local_b8 = (uint32_t)(uint32_t)local_b8;
      local_b4 = (uint32_t)CONCAT12((char)uVar38,(uint16_t)local_b4);
      local_ac = (uint8_t)((uVar37 + uVar63 * 2) / 3);
      (*(uint16_t*)((char*)&local_b0 + 0)) = CONCAT11((char)((uVar39 + uVar40 * 2) / 3),(char)((uVar63 + uVar37 * 2) / 3))
      ;
      local_b0 = CONCAT22(CONCAT11((*(uint8_t*)((char*)&local_b0 + 3)),(char)((uVar38 + uVar61 * 2) / 3)),
                          (uint16_t)local_b0);
      local_ab = (uint8_t)((uVar40 + uVar39 * 2) / 3);
      local_aa = (uint8_t)((uVar61 + uVar38 * 2) / 3);
      uVar37 = FUN_0013a974(param_2,&local_b8);
    }
    uVar63 = 0;
    while( true ) {
      if ((uVar37 ^ uVar37 << 2) < 4) {
        uVar47 = 8;
        lVar54 = 0;
        uVar55 = 8;
        uVar57 = 8;
        do {
          pbVar3 = (uint8_t *)((long)param_2 + lVar54);
          lVar54 = lVar54 + 4;
          uVar57 = (unsigned long)*pbVar3 + (uVar57 & 0xffffffff);
          uVar55 = (unsigned long)pbVar3[1] + (uVar55 & 0xffffffff);
          uVar47 = (unsigned long)pbVar3[2] + (uVar47 & 0xffffffff);
        } while (lVar54 != 0x40);
        uVar56 = uVar55 >> 3 & 0x3ffffffe;
        uVar55 = uVar57 >> 3 & 0x3ffffffe;
        uVar57 = uVar47 >> 3 & 0x3ffffffe;
        uVar61 = (uint32_t)(uint8_t)(&DAT_00116416)[uVar56] << 5 |
                 (uint32_t)(uint8_t)(&DAT_00116216)[uVar55] << 0xb | (uint32_t)(uint8_t)(&DAT_00116216)[uVar57];
        uVar58 = (uint32_t)(uint8_t)(&DAT_00116417)[uVar56] << 5 |
                 (uint32_t)(uint8_t)(&DAT_00116217)[uVar55] << 0xb | (uint32_t)(uint8_t)(&DAT_00116217)[uVar57];
      }
      else {
        lVar54 = 0;
        uVar40 = 0;
        iVar53 = 0;
        iVar52 = 0;
        iVar49 = 0;
        iVar45 = 0;
        iVar46 = 0;
        iVar50 = 0;
        uVar61 = uVar37;
        do {
          pbVar3 = (uint8_t *)((long)param_2 + lVar54);
          lVar62 = (unsigned long)(uVar61 & 3) * 4;
          iVar36 = *(int *)(&DAT_00115760 + lVar62);
          lVar54 = lVar54 + 4;
          iVar45 = iVar45 + (uint32_t)*pbVar3;
          iVar49 = iVar49 + (uint32_t)pbVar3[1];
          iVar52 = iVar52 + (uint32_t)pbVar3[2];
          uVar40 = *(int *)(&DAT_00115740 + lVar62) + uVar40;
          iVar53 = iVar53 + iVar36 * (uint32_t)*pbVar3;
          iVar50 = iVar50 + iVar36 * (uint32_t)pbVar3[1];
          iVar46 = iVar46 + iVar36 * (uint32_t)pbVar3[2];
          uVar61 = uVar61 >> 2;
        } while (lVar54 != 0x40);
        iVar36 = (int)uVar40 >> 0x10;
        uVar61 = uVar40 >> 8 & 0xff;
        uVar40 = uVar40 & 0xff;
        iVar45 = iVar45 * 3 - iVar53;
        iVar49 = iVar49 * 3 - iVar50;
        iVar52 = iVar52 * 3 - iVar46;
        fVar102 = 0.011764706 / (float)(int)(uVar61 * iVar36 - uVar40 * uVar40);
        fVar74 = fVar102 * (float)(int)(uVar61 * iVar53 - uVar40 * iVar45);
        fVar83 = fVar74;
        if (1.0 < fVar74) {
          fVar83 = 1.0;
        }
        fVar66 = 0.0;
        if (0.0 <= fVar74) {
          fVar66 = fVar83;
        }
        uVar38 = (uint32_t)(fVar66 * 31.0);
        fVar74 = fVar102 * (float)(int)(uVar61 * iVar50 - uVar40 * iVar49);
        fVar83 = fVar74;
        if (1.0 < fVar74) {
          fVar83 = 1.0;
        }
        if (*(float *)(&DAT_00116618 + (unsigned long)uVar38 * 4) < fVar66) {
          uVar38 = uVar38 + 1;
        }
        fVar66 = 0.0;
        if (0.0 <= fVar74) {
          fVar66 = fVar83;
        }
        uVar39 = (uint32_t)(fVar66 * 63.0);
        fVar74 = fVar102 * (float)(int)(uVar61 * iVar46 - iVar52 * uVar40);
        fVar83 = fVar74;
        if (1.0 < fVar74) {
          fVar83 = 1.0;
        }
        if (*(float *)(&DAT_00116698 + (unsigned long)uVar39 * 4) < fVar66) {
          uVar39 = uVar39 + 1;
        }
        fVar66 = 0.0;
        fVar65 = 0.0;
        if (0.0 <= fVar74) {
          fVar65 = fVar83;
        }
        uVar61 = (uint32_t)(fVar65 * 31.0);
        fVar74 = fVar102 * (float)(int)(iVar36 * iVar45 - uVar40 * iVar53);
        fVar83 = fVar74;
        if (1.0 < fVar74) {
          fVar83 = 1.0;
        }
        if (*(float *)(&DAT_00116618 + (unsigned long)uVar61 * 4) < fVar65) {
          uVar61 = uVar61 + 1;
        }
        fVar65 = fVar66;
        if (0.0 <= fVar74) {
          fVar65 = fVar83;
        }
        uVar59 = (uint32_t)(fVar65 * 31.0);
        fVar74 = fVar102 * (float)(int)(iVar36 * iVar49 - uVar40 * iVar50);
        fVar102 = fVar102 * (float)(int)(iVar52 * iVar36 - uVar40 * iVar46);
        fVar83 = fVar74;
        if (1.0 < fVar74) {
          fVar83 = 1.0;
        }
        if (*(float *)(&DAT_00116618 + (unsigned long)uVar59 * 4) < fVar65) {
          uVar59 = uVar59 + 1;
        }
        fVar65 = fVar66;
        if (0.0 <= fVar74) {
          fVar65 = fVar83;
        }
        uVar40 = (uint32_t)(fVar65 * 63.0);
        fVar83 = fVar102;
        if (1.0 < fVar102) {
          fVar83 = 1.0;
        }
        if (*(float *)(&DAT_00116698 + (unsigned long)uVar40 * 4) < fVar65) {
          uVar40 = uVar40 + 1;
        }
        if (0.0 <= fVar102) {
          fVar66 = fVar83;
        }
        uVar58 = (uint32_t)(fVar66 * 31.0);
        uVar61 = uVar39 << 5 | uVar38 << 0xb | uVar61;
        if (*(float *)(&DAT_00116618 + (unsigned long)uVar58 * 4) < fVar66) {
          uVar58 = uVar58 + 1;
        }
        uVar58 = uVar40 << 5 | uVar59 << 0xb | uVar58;
      }
      if (((uVar48 & 0xffff) == (uVar58 & 0xffff)) &&
         (uVar40 = uVar37, (uVar44 & 0xffff) == (uVar61 & 0xffff))) goto LAB_0013a24c;
      uVar44 = uVar61;
      if ((uVar61 & 0xffff) == (uVar58 & 0xffff)) break;
      uVar48 = uVar61 >> 0xb & 0x1f;
      uVar40 = uVar58 >> 0xb & 0x1f;
      uVar38 = (uVar61 & 0xffff) >> 5 & 0x3f;
      uVar59 = (uVar58 & 0xffff) >> 5 & 0x3f;
      uVar48 = (uVar48 | uVar48 << 5) >> 2;
      uVar40 = (uVar40 | uVar40 << 5) >> 2;
      uVar38 = (uVar38 | uVar38 << 6) >> 4;
      uVar61 = (uVar61 & 0x1f | (uVar61 & 0x1f) << 5) >> 2;
      uVar39 = (uVar58 & 0x1f | (uVar58 & 0x1f) << 5) >> 2;
      uVar59 = (uVar59 | uVar59 << 6) >> 4;
      (*(uint8_t*)((char*)&local_b8 + 0)) = (uint8_t)uVar48;
      (*(uint16_t*)((char*)&local_b8 + 0)) = CONCAT11((char)uVar38,(uint8_t)local_b8);
      (*(uint32_t*)((char*)&local_b8 + 0)) = CONCAT12((char)uVar61,(uint16_t)local_b8);
      (*(uint8_t*)((char*)&local_b4 + 0)) = (uint8_t)uVar40;
      (*(uint16_t*)((char*)&local_b4 + 0)) = CONCAT11((char)uVar59,(uint8_t)local_b4);
      local_b8 = (uint32_t)(uint32_t)local_b8;
      local_b4 = (uint32_t)CONCAT12((char)uVar39,(uint16_t)local_b4);
      local_ac = (uint8_t)((uVar48 + uVar40 * 2) / 3);
      (*(uint16_t*)((char*)&local_b0 + 0)) = CONCAT11((char)((uVar59 + uVar38 * 2) / 3),(char)((uVar40 + uVar48 * 2) / 3))
      ;
      local_b0 = CONCAT22(CONCAT11((*(uint8_t*)((char*)&local_b0 + 3)),(char)((uVar39 + uVar61 * 2) / 3)),
                          (uint16_t)local_b0);
      local_ab = (uint8_t)((uVar38 + uVar59 * 2) / 3);
      local_aa = (uint8_t)((uVar61 + uVar39 * 2) / 3);
      uVar40 = FUN_0013a974(param_2,&local_b8);
      uVar48 = uVar58;
      if ((uVar40 == uVar37) || (uVar63 = uVar63 + 1, uVar37 = uVar40, uVar51 <= uVar63))
      goto LAB_0013a24c;
    }
    uVar48 = uVar61;
    uVar40 = 0;
  }
LAB_0013a24c:
  bVar35 = (uVar48 & 0xffff) <= (uVar44 & 0xffff);
  uVar4 = (short)uVar48;
  if (bVar35) {
    uVar4 = (short)uVar44;
  }
  *param_1 = (char)uVar4;
  param_1[1] = (char)((uint16_t)uVar4 >> 8);
  uVar51 = uVar40 ^ 0x55555555;
  uVar4 = (short)uVar44;
  if (bVar35) {
    uVar51 = uVar40;
    uVar4 = (short)uVar48;
  }
  param_1[2] = (char)uVar4;
  param_1[4] = (char)uVar51;
  param_1[3] = (char)((uint16_t)uVar4 >> 8);
  param_1[5] = (char)(uVar51 >> 8);
  param_1[6] = (char)(uVar51 >> 0x10);
  param_1[7] = (char)(uVar51 >> 0x18);
  if (*(long *)(lVar23 + 0x28) != local_90) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ─────────────────────────────────────────────
// INTERNAL
// ─────────────────────────────────────────────

