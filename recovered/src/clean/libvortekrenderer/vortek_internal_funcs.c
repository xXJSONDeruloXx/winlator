/*
 * vortek_internal_funcs.c — Internal helpers (compile-tested)
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* Forward declarations for conflicting-type functions */
FUN_00165398(param_1);
FUN_00165274(param_1);
void FUN_0014ce84(uint32_t *p1, uint32_t *p2, long *p3);
void FUN_0014dc68(uint32_t *p1, uint32_t *p2);
void FUN_0014e92c(uint32_t *p1, uint32_t *p2, long *p3);

/* @0012dba0  size=8 */

void FUN_0012dba0(void)

{
  return;
}






/* STUB */
void FUN_0012dbb0(void *param)
{ /* TODO */ }



/* STUB */
void FUN_0012dbc4(uint64_t param_1)
{ /* TODO */ }





/* @0012dbe4  size=16 */

void FUN_0012dbe4(void)

{
  __register_atfork();
  return;
}








/* @0012e900  size=1104 */

void FUN_0012e900(uint32_t *param_1,uint32_t *param_2)

{
  int iVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  size_t sVar5;
  long lVar6;
  uint64_t uVar7;
  uint32_t uVar8;
  
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  *(uint64_t *)(param_2 + 3) = *(uint64_t *)(param_1 + 3);
  sVar5 = strlen((char *)(param_1 + 5));
  iVar1 = (int)sVar5 + 1;
  param_2[5] = iVar1;
  memcpy(param_2 + 6,param_1 + 5,(long)iVar1);
  uVar7 = *(uint64_t *)(param_1 + 0x45);
  lVar6 = sVar5 << 0x20;
  puVar4 = (uint64_t *)((long)param_2 + (lVar6 + 0x1900000000 >> 0x20));
  puVar4[1] = *(uint64_t *)(param_1 + 0x47);
  *puVar4 = uVar7;
  puVar2 = (uint32_t *)((long)param_2 + (lVar6 + 0x2900000000 >> 0x20));
  *puVar2 = param_1[0x4a];
  uVar7 = *(uint64_t *)(param_1 + 0x56);
  puVar2[1] = param_1[0x4b];
  uVar3 = param_1[0x4c];
  *(uint64_t *)(puVar2 + 0xb) = uVar7;
  uVar7 = *(uint64_t *)(param_1 + 0x58);
  puVar2[2] = uVar3;
  uVar3 = param_1[0x4d];
  *(uint64_t *)(puVar2 + 0xd) = uVar7;
  puVar2[3] = uVar3;
  puVar2[4] = param_1[0x4e];
  puVar2[5] = param_1[0x4f];
  puVar2[6] = param_1[0x50];
  puVar2[7] = param_1[0x51];
  puVar2[8] = param_1[0x52];
  puVar2[9] = param_1[0x53];
  puVar2[10] = param_1[0x54];
  puVar2[0xf] = param_1[0x5a];
  puVar2[0x10] = param_1[0x5b];
  puVar2[0x11] = param_1[0x5c];
  puVar2[0x12] = param_1[0x5d];
  puVar2[0x13] = param_1[0x5e];
  puVar2[0x14] = param_1[0x5f];
  puVar2[0x15] = param_1[0x60];
  puVar2[0x16] = param_1[0x61];
  puVar2[0x17] = param_1[0x62];
  puVar2[0x18] = param_1[99];
  puVar2[0x19] = param_1[100];
  puVar2[0x1a] = param_1[0x65];
  puVar2[0x1b] = param_1[0x66];
  puVar2[0x1c] = param_1[0x67];
  puVar2[0x1d] = param_1[0x68];
  puVar2[0x1e] = param_1[0x69];
  puVar2[0x1f] = param_1[0x6a];
  puVar2[0x20] = param_1[0x6b];
  puVar2[0x21] = param_1[0x6c];
  puVar2[0x22] = param_1[0x6d];
  puVar2[0x23] = param_1[0x6e];
  puVar2[0x24] = param_1[0x6f];
  puVar2[0x25] = param_1[0x70];
  puVar2[0x26] = param_1[0x71];
  puVar2[0x27] = param_1[0x72];
  puVar2[0x28] = param_1[0x73];
  puVar2[0x29] = param_1[0x74];
  puVar2[0x2a] = param_1[0x75];
  puVar2[0x2b] = param_1[0x76];
  puVar2[0x2c] = param_1[0x77];
  puVar2[0x2d] = param_1[0x78];
  puVar2[0x2e] = param_1[0x79];
  puVar2[0x2f] = param_1[0x7a];
  puVar2[0x30] = param_1[0x7b];
  puVar2[0x31] = param_1[0x7c];
  puVar2[0x32] = param_1[0x7d];
  puVar2[0x33] = param_1[0x7e];
  puVar2[0x34] = param_1[0x7f];
  puVar2[0x35] = param_1[0x80];
  uVar7 = *(uint64_t *)(param_1 + 0x81);
  puVar2[0x38] = param_1[0x83];
  *(uint64_t *)(puVar2 + 0x36) = uVar7;
  puVar2[0x39] = param_1[0x84];
  uVar7 = *(uint64_t *)(param_1 + 0x85);
  puVar2[0x3c] = param_1[0x87];
  *(uint64_t *)(puVar2 + 0x3a) = uVar7;
  uVar8 = param_1[0x8d];
  puVar2[0x3d] = param_1[0x88];
  uVar3 = param_1[0x89];
  puVar2[0x42] = uVar8;
  uVar8 = param_1[0x8e];
  puVar2[0x3e] = uVar3;
  uVar3 = param_1[0x8a];
  puVar2[0x43] = uVar8;
  puVar2[0x3f] = uVar3;
  puVar2[0x40] = param_1[0x8b];
  puVar2[0x41] = param_1[0x8c];
  puVar2[0x44] = param_1[0x8f];
  *(uint64_t *)(puVar2 + 0x45) = *(uint64_t *)(param_1 + 0x90);
  *(uint64_t *)(puVar2 + 0x47) = *(uint64_t *)(param_1 + 0x92);
  uVar7 = *(uint64_t *)(param_1 + 0x96);
  uVar8 = param_1[0xa2];
  puVar2[0x49] = param_1[0x94];
  uVar3 = param_1[0x9e];
  *(uint64_t *)(puVar2 + 0x4a) = uVar7;
  uVar7 = *(uint64_t *)(param_1 + 0x98);
  puVar2[0x56] = uVar8;
  puVar2[0x52] = uVar3;
  uVar3 = param_1[0x9f];
  *(uint64_t *)(puVar2 + 0x4c) = uVar7;
  uVar7 = *(uint64_t *)(param_1 + 0x9a);
  uVar8 = param_1[0xa3];
  puVar2[0x53] = uVar3;
  uVar3 = param_1[0xa0];
  *(uint64_t *)(puVar2 + 0x4e) = uVar7;
  puVar2[0x57] = uVar8;
  uVar7 = *(uint64_t *)(param_1 + 0x9c);
  puVar2[0x54] = uVar3;
  uVar3 = param_1[0xa1];
  uVar8 = param_1[0xb4];
  *(uint64_t *)(puVar2 + 0x50) = uVar7;
  puVar2[0x55] = uVar3;
  uVar3 = param_1[0xa4];
  puVar2[0x68] = uVar8;
  puVar2[0x58] = uVar3;
  puVar2[0x59] = param_1[0xa5];
  puVar2[0x5a] = param_1[0xa6];
  puVar2[0x5b] = param_1[0xa7];
  puVar2[0x5c] = param_1[0xa8];
  puVar2[0x5d] = param_1[0xa9];
  puVar2[0x5e] = param_1[0xaa];
  puVar2[0x5f] = param_1[0xab];
  puVar2[0x60] = param_1[0xac];
  puVar2[0x61] = param_1[0xad];
  puVar2[0x62] = param_1[0xae];
  puVar2[99] = param_1[0xaf];
  puVar2[100] = param_1[0xb0];
  puVar2[0x65] = param_1[0xb1];
  puVar2[0x66] = param_1[0xb2];
  puVar2[0x67] = param_1[0xb3];
  puVar2[0x69] = param_1[0xb5];
  puVar2[0x6a] = param_1[0xb6];
  puVar2[0x6b] = param_1[0xb7];
  puVar2[0x6c] = param_1[0xb8];
  *(uint64_t *)(puVar2 + 0x6d) = *(uint64_t *)(param_1 + 0xb9);
  *(uint64_t *)(puVar2 + 0x6f) = *(uint64_t *)(param_1 + 0xbb);
  param_2 = (uint32_t *)((long)param_2 + (lVar6 + 0x21500000000 >> 0x20));
  puVar2[0x73] = param_1[0xbf];
  uVar7 = *(uint64_t *)(param_1 + 0xc2);
  uVar8 = param_1[0xbd];
  puVar2[0x74] = param_1[0xc0];
  uVar3 = param_1[200];
  *(uint64_t *)(puVar2 + 0x75) = uVar7;
  uVar7 = *(uint64_t *)(param_1 + 0xc4);
  puVar2[0x71] = uVar8;
  *param_2 = uVar3;
  uVar3 = param_1[0xc9];
  uVar8 = param_1[0xbe];
  *(uint64_t *)(puVar2 + 0x77) = uVar7;
  param_2[1] = uVar3;
  uVar3 = param_1[0xca];
  uVar7 = *(uint64_t *)(param_1 + 0xc6);
  puVar2[0x72] = uVar8;
  param_2[2] = uVar3;
  uVar3 = param_1[0xcb];
  *(uint64_t *)(puVar2 + 0x79) = uVar7;
  param_2[3] = uVar3;
  param_2[4] = param_1[0xcc];
  return;
}








/* @00143674  size=692 */

void FUN_00143674(uint64_t *param_1,uint32_t *param_2,long param_3,char *param_4,long *param_5)

{
  long lVar1;
  char *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  void *__s;
  uint64_t uVar9;
  int iVar10;
  unsigned long uVar11;
  uint64_t uVar12;
  long lVar13;
  int *piVar14;
  uint64_t *puVar15;
  unsigned long uVar16;
  uint64_t *puVar17;
  int iVar18;
  size_t __size;
  long lVar19;
  uint64_t *puVar20;
  
  if (*param_4 == '\0') {
    uVar11 = 1;
  }
  else {
    if (param_1 != (uint64_t *)0x0) {
      *param_1 = *(uint64_t *)(param_4 + 1);
    }
    uVar11 = 9;
  }
  if (param_2 != (uint32_t *)0x0) {
    *param_2 = *(uint32_t *)(param_4 + uVar11);
  }
  uVar5 = *(uint32_t *)(param_4 + (uVar11 | 4));
  if ((int)uVar5 < 1) {
    return;
  }
  uVar16 = 0;
  iVar10 = (int)uVar11 + 8;
LAB_00143724:
  iVar6 = *(int *)(param_4 + iVar10);
  lVar1 = (long)iVar10 + 4;
  if (param_3 != 0) {
    piVar14 = (int *)(param_4 + lVar1 + 4);
    *(uint32_t *)(param_3 + uVar16 * 0x28) = *(uint32_t *)(param_4 + lVar1);
    iVar10 = 8;
    puVar20 = (uint64_t *)0x0;
    do {
      if (*piVar14 == 0x3b9bb46d) {
        iVar7 = *(int *)(param_4 + iVar10 + lVar1);
        uVar11 = (long)iVar10 + 4;
        if (iVar7 < 1) goto LAB_00143760;
        iVar10 = (int)param_5[1];
        if ((iVar10 < 0xffe0) && (*param_5 != 0)) {
          puVar15 = (uint64_t *)(*param_5 + (long)iVar10);
          *(int *)(param_5 + 1) = iVar10 + 0x20;
        }
        else {
          puVar15 = malloc(0x20);
          ArrayList_add(param_5 + 2,puVar15);
        }
        puVar15[1] = 0;
        *puVar15 = 0;
        puVar15[3] = 0;
        puVar15[2] = 0;
        pcVar2 = param_4 + uVar11 + lVar1;
        uVar3 = *(uint32_t *)pcVar2;
        uVar4 = *(uint32_t *)(pcVar2 + 4);
        puVar15[1] = 0;
        *(uint32_t *)(puVar15 + 2) = uVar4;
        iVar10 = *(int *)(pcVar2 + 8);
        *(uint32_t *)puVar15 = uVar3;
        if (iVar10 < 1) {
          puVar15[3] = 0;
        }
        else {
          __size = (long)iVar10 << 2;
          iVar18 = (int)__size;
          iVar10 = (int)param_5[1] + iVar18;
          if ((iVar10 < 0x10000) && (*param_5 != 0)) {
            __s = (void *)(*param_5 + (long)(int)param_5[1]);
            __size = (size_t)iVar18;
            *(int *)(param_5 + 1) = iVar10;
          }
          else {
            __s = malloc(__size);
            ArrayList_add(param_5 + 2,__s);
          }
          memset(__s,0,__size);
          if (__s != (void *)0x0) {
            memcpy(__s,pcVar2 + 0xc,(long)iVar18);
          }
          puVar15[3] = __s;
        }
        iVar10 = iVar7 + (int)uVar11;
        puVar15[1] = puVar20;
      }
      else {
        if (*piVar14 == -1) goto LAB_0014388c;
        uVar11 = (unsigned long)(iVar10 + 4);
LAB_00143760:
        iVar10 = (int)uVar11;
        puVar15 = puVar20;
      }
      piVar14 = (int *)(param_4 + iVar10 + lVar1);
      iVar10 = iVar10 + 4;
      puVar20 = puVar15;
    } while( true );
  }
  goto LAB_00143710;
LAB_0014388c:
  if (puVar20 == (uint64_t *)0x0) {
    puVar15 = (uint64_t *)0x0;
  }
  else {
    puVar17 = (uint64_t *)0x0;
    do {
      puVar15 = puVar20;
      puVar20 = (uint64_t *)puVar15[1];
      puVar15[1] = puVar17;
      puVar17 = puVar15;
    } while (puVar20 != (uint64_t *)0x0);
  }
  uVar9 = *(uint64_t *)(param_4 + iVar10 + lVar1);
  lVar19 = param_3 + uVar16 * 0x28;
  *(uint64_t **)(lVar19 + 8) = puVar15;
  uVar9 = VkObject_fromId(uVar9);
  uVar12 = *(uint64_t *)(param_4 + iVar10 + lVar1 + 8);
  *(uint64_t *)(lVar19 + 0x10) = uVar9;
  cVar8 = vortekSerializerCastVkObject;
  lVar19 = VkObject_fromId(uVar12);
  if (cVar8 != '\0') {
    lVar19 = *(long *)(lVar19 + 0x18);
  }
  uVar9 = *(uint64_t *)(param_4 + (long)iVar10 + 0x10 + lVar1);
  lVar13 = param_3 + uVar16 * 0x28;
  *(long *)(lVar13 + 0x18) = lVar19;
  *(uint64_t *)(lVar13 + 0x20) = uVar9;
LAB_00143710:
  uVar16 = uVar16 + 1;
  iVar10 = iVar6 + (int)lVar1;
  if (uVar16 == uVar5) {
    return;
  }
  goto LAB_00143724;
}








/* @0014ba5c  size=5160 */

void FUN_0014ba5c(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  uint64_t *puVar6;
  uint64_t uVar7;
  void *pvVar8;
  void *pvVar9;
  int iVar10;
  long lVar11;
  uint32_t *puVar12;
  uint32_t uVar13;
  uint64_t *puVar14;
  uint64_t *puVar15;
  int iVar16;
  int iVar17;
  unsigned long uVar18;
  size_t sVar19;
  unsigned long uVar20;
  long *plVar21;
  
  puVar15 = (uint64_t *)0x0;
  puVar12 = param_2 + 1;
  iVar10 = 8;
  *param_1 = *param_2;
  do {
    plVar21 = param_3 + 1;
    uVar3 = *puVar12;
    if (0x3b9e38e9 < (int)uVar3) {
      if ((int)uVar3 < 0x3b9f4a58) {
        if ((int)uVar3 < 0x3b9edcf8) {
          if ((int)uVar3 < 0x3b9ea648) {
            if (uVar3 == 0x3b9e38ea) {
LAB_0014bfec:
              iVar16 = *(int *)((long)param_2 + (long)iVar10);
              uVar18 = (long)iVar10 + 4;
              if (iVar16 < 1) goto LAB_0014bacc;
              iVar10 = (int)*plVar21;
              if ((iVar10 < 0xffe8) && (*param_3 != 0)) {
                puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
                *(int *)plVar21 = iVar10 + 0x18;
              }
              else {
                puVar6 = malloc(0x18);
                ArrayList_add(param_3 + 2,puVar6);
              }
              *puVar6 = 0;
              puVar6[1] = 0;
              puVar6[2] = 0;
              puVar1 = (uint32_t *)((long)param_2 + uVar18);
              uVar2 = *puVar1;
              uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
              *(uint32_t *)(puVar6 + 2) = puVar1[1];
              uVar4 = puVar1[2];
              *(uint32_t *)puVar6 = uVar2;
              *(uint32_t *)((long)puVar6 + 0x14) = uVar4;
              goto LAB_0014c1a0;
            }
            if (uVar3 != 0x3b9e7768) {
              uVar13 = 0x9e78;
              goto LAB_0014bd80;
            }
          }
          else {
            if (0x3b9eb5e7 < (int)uVar3) {
              if (uVar3 != 0x3b9eb5e8) {
                uVar13 = 0xc588;
                goto LAB_0014c100;
              }
              goto LAB_0014c028;
            }
            if (uVar3 != 0x3b9ea648) {
              if (uVar3 != 0x3b9eaa30) goto LAB_0014c9f4;
              goto LAB_0014bfec;
            }
          }
        }
        else if ((int)uVar3 < 0x3b9f0fc0) {
          if (uVar3 != 0x3b9edcf8) {
            if (uVar3 != 0x3b9ef080) {
              uVar13 = 0x20;
              goto LAB_0014be80;
            }
            iVar16 = *(int *)((long)param_2 + (long)iVar10);
            goto joined_r0x0014c23c;
          }
        }
        else {
          if (0x3b9f272f < (int)uVar3) {
            if (uVar3 != 0x3b9f2730) {
              uVar13 = 0x2b1a;
LAB_0014bfe0:
              uVar13 = uVar13 | 0x3b9f0000;
              goto joined_r0x0014bfe8;
            }
            goto LAB_0014c028;
          }
          if (uVar3 != 0x3b9f0fc0) {
            uVar13 = 0x13a8;
            goto LAB_0014be80;
          }
        }
      }
      else if ((int)uVar3 < 0x3ba02518) {
        if ((int)uVar3 < 0x3b9f9497) {
          if ((uVar3 != 0x3b9f4a58) && (uVar3 != 0x3b9f4a59)) {
            uVar13 = 0x5228;
LAB_0014be80:
            uVar13 = uVar13 | 0x3b9f0000;
            goto joined_r0x0014c12c;
          }
        }
        else if ((int)uVar3 < 0x3b9fe698) {
          if (uVar3 != 0x3b9f9497) {
            uVar13 = 0xbf88;
            goto LAB_0014be80;
          }
        }
        else if (uVar3 != 0x3b9fe698) {
          uVar13 = 0xfa20;
          goto LAB_0014bfe0;
        }
      }
      else {
        if (0x3ba10f77 < (int)uVar3) {
          if ((int)uVar3 < 0x3ba1bb58) {
            if (uVar3 == 0x3ba10f78) goto LAB_0014bfec;
            uVar13 = 0x1748;
          }
          else {
            if (uVar3 == 0x3ba1bb58) {
              iVar16 = *(int *)((long)param_2 + (long)iVar10);
              uVar18 = (long)iVar10 + 4;
              if (0 < iVar16) {
                iVar10 = (int)*plVar21;
                if ((iVar10 < 0xff70) && (*param_3 != 0)) {
                  puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
                  *(int *)plVar21 = iVar10 + 0x90;
                }
                else {
                  puVar6 = malloc(0x90);
                  ArrayList_add(param_3 + 2,puVar6);
                }
                puVar6[0xf] = 0;
                puVar6[0xe] = 0;
                puVar6[0x11] = 0;
                puVar6[0x10] = 0;
                puVar6[0xb] = 0;
                puVar6[10] = 0;
                puVar6[0xd] = 0;
                puVar6[0xc] = 0;
                puVar6[7] = 0;
                puVar6[6] = 0;
                puVar6[9] = 0;
                puVar6[8] = 0;
                puVar6[3] = 0;
                puVar6[2] = 0;
                puVar6[5] = 0;
                puVar6[4] = 0;
                puVar6[1] = 0;
                *puVar6 = 0;
                puVar1 = (uint32_t *)((long)param_2 + uVar18);
                uVar2 = *puVar1;
                uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
                *(uint32_t *)(puVar6 + 2) = puVar1[1];
                uVar4 = puVar1[2];
                *(uint32_t *)puVar6 = uVar2;
                *(uint32_t *)((long)puVar6 + 0x14) = uVar4;
                *(uint32_t *)(puVar6 + 3) = puVar1[3];
                *(uint32_t *)((long)puVar6 + 0x1c) = puVar1[4];
                *(uint32_t *)(puVar6 + 4) = puVar1[5];
                *(uint32_t *)((long)puVar6 + 0x24) = puVar1[6];
                *(uint32_t *)(puVar6 + 5) = puVar1[7];
                *(uint32_t *)((long)puVar6 + 0x2c) = puVar1[8];
                *(uint32_t *)(puVar6 + 6) = puVar1[9];
                *(uint32_t *)((long)puVar6 + 0x34) = puVar1[10];
                *(uint32_t *)(puVar6 + 7) = puVar1[0xb];
                *(uint32_t *)((long)puVar6 + 0x3c) = puVar1[0xc];
                *(uint32_t *)(puVar6 + 8) = puVar1[0xd];
                *(uint32_t *)((long)puVar6 + 0x44) = puVar1[0xe];
                *(uint32_t *)(puVar6 + 9) = puVar1[0xf];
                *(uint32_t *)((long)puVar6 + 0x4c) = puVar1[0x10];
                *(uint32_t *)(puVar6 + 10) = puVar1[0x11];
                *(uint32_t *)((long)puVar6 + 0x54) = puVar1[0x12];
                *(uint32_t *)(puVar6 + 0xb) = puVar1[0x13];
                *(uint32_t *)((long)puVar6 + 0x5c) = puVar1[0x14];
                *(uint32_t *)(puVar6 + 0xc) = puVar1[0x15];
                *(uint32_t *)((long)puVar6 + 100) = puVar1[0x16];
                *(uint32_t *)(puVar6 + 0xd) = puVar1[0x17];
                *(uint32_t *)((long)puVar6 + 0x6c) = puVar1[0x18];
                *(uint32_t *)(puVar6 + 0xe) = puVar1[0x19];
                *(uint32_t *)((long)puVar6 + 0x74) = puVar1[0x1a];
                *(uint32_t *)(puVar6 + 0xf) = puVar1[0x1b];
                *(uint32_t *)((long)puVar6 + 0x7c) = puVar1[0x1c];
                *(uint32_t *)(puVar6 + 0x10) = puVar1[0x1d];
                *(uint32_t *)((long)puVar6 + 0x84) = puVar1[0x1e];
                *(uint32_t *)(puVar6 + 0x11) = puVar1[0x1f];
                goto LAB_0014c1a0;
              }
              goto LAB_0014bacc;
            }
            uVar13 = 0xd6b0;
          }
          uVar13 = uVar13 | 0x3ba10000;
          goto joined_r0x0014c12c;
        }
        if (((uVar3 != 0x3ba02518) && (uVar3 != 0x3ba034b8)) && (uVar3 != 0x3ba09a48))
        goto LAB_0014c9f4;
      }
      goto LAB_0014c130;
    }
    if ((int)uVar3 < 0x3b9c6fe0) {
      if ((int)uVar3 < 0x3b9bc018) {
        if ((int)uVar3 < 0x3b9b3760) {
          if ((int)uVar3 < 0x33) {
            if (uVar3 != 0x31) {
              if (uVar3 == 0xffffffff) {
                if (puVar15 == (uint64_t *)0x0) {
                  puVar6 = (uint64_t *)0x0;
                }
                else {
                  puVar14 = (uint64_t *)0x0;
                  do {
                    puVar6 = puVar15;
                    puVar15 = (uint64_t *)puVar6[1];
                    puVar6[1] = puVar14;
                    puVar14 = puVar6;
                  } while (puVar15 != (uint64_t *)0x0);
                }
                puVar1 = (uint32_t *)((long)param_2 + (long)iVar10);
                iVar10 = iVar10 + 0xc;
                param_1[4] = *puVar1;
                uVar2 = puVar1[1];
                *(uint64_t **)(param_1 + 2) = puVar6;
                param_1[5] = uVar2;
                uVar3 = puVar1[2];
                uVar18 = (unsigned long)uVar3;
                if ((int)uVar3 < 1) {
                  *(uint64_t *)(param_1 + 6) = 0;
                }
                else {
                  iVar5 = uVar3 * 0x28;
                  iVar16 = (int)*plVar21 + iVar5;
                  if ((iVar16 < 0x10000) && (*param_3 != 0)) {
                    pvVar8 = (void *)(*param_3 + (long)(int)*plVar21);
                    *(int *)plVar21 = iVar16;
                  }
                  else {
                    pvVar8 = malloc((long)iVar5);
                    ArrayList_add(param_3 + 2,pvVar8);
                  }
                  memset(pvVar8,0,(long)iVar5);
                  puVar15 = (uint64_t *)((long)pvVar8 + 0x20);
                  do {
                    iVar16 = *(int *)((long)param_2 + (long)iVar10);
                    lVar11 = (long)iVar10 + 4;
                    if (pvVar8 != (void *)0x0) {
                      puVar1 = (uint32_t *)((long)param_2 + lVar11);
                      uVar2 = *puVar1;
                      uVar4 = puVar1[1];
                      puVar15[-3] = 0;
                      *(uint32_t *)(puVar15 + -2) = uVar4;
                      uVar4 = puVar1[2];
                      *(uint32_t *)(puVar15 + -4) = uVar2;
                      *(uint32_t *)((long)puVar15 + -0xc) = uVar4;
                      *(uint32_t *)(puVar15 + -1) = puVar1[3];
                      if ((int)puVar1[4] < 1) {
                        *puVar15 = 0;
                      }
                      else {
                        iVar5 = (int)param_3[1];
                        sVar19 = (long)(int)puVar1[4] << 2;
                        iVar17 = (int)sVar19;
                        iVar10 = iVar5 + iVar17;
                        if ((iVar10 < 0x10000) && (*param_3 != 0)) {
                          pvVar9 = (void *)(*param_3 + (long)iVar5);
                          sVar19 = (size_t)iVar17;
                          *(int *)(param_3 + 1) = iVar10;
                        }
                        else {
                          pvVar9 = malloc(sVar19);
                          ArrayList_add(param_3 + 2,pvVar9);
                        }
                        memset(pvVar9,0,sVar19);
                        if (pvVar9 != (void *)0x0) {
                          memcpy(pvVar9,puVar1 + 5,(long)iVar17);
                        }
                        *puVar15 = pvVar9;
                      }
                    }
                    iVar10 = iVar16 + (int)lVar11;
                    uVar18 = uVar18 - 1;
                    puVar15 = puVar15 + 5;
                  } while (uVar18 != 0);
                  *(void **)(param_1 + 6) = pvVar8;
                }
                plVar21 = param_3 + 1;
                iVar16 = iVar10 + 8;
                param_1[8] = *(uint32_t *)((long)param_2 + (long)iVar10);
                uVar3 = ((uint32_t *)((long)param_2 + (long)iVar10))[1];
                if ((int)uVar3 < 1) {
                  *(uint64_t *)(param_1 + 10) = 0;
                }
                else {
                  iVar5 = uVar3 * 8;
                  iVar10 = (int)*plVar21 + iVar5;
                  if ((iVar10 < 0x10000) && (*param_3 != 0)) {
                    pvVar8 = (void *)(*param_3 + (long)(int)*plVar21);
                    *(int *)plVar21 = iVar10;
                  }
                  else {
                    pvVar8 = malloc((long)iVar5);
                    ArrayList_add(param_3 + 2,pvVar8);
                  }
                  memset(pvVar8,0,(long)iVar5);
                  uVar18 = 0;
                  do {
                    iVar5 = *(int *)((long)param_2 + (long)iVar16);
                    sVar19 = (size_t)iVar5;
                    iVar10 = (int)*plVar21 + iVar5;
                    if ((iVar10 < 0x10000) && (*param_3 != 0)) {
                      pvVar9 = (void *)(*param_3 + (long)(int)*plVar21);
                      *(int *)plVar21 = iVar10;
                    }
                    else {
                      pvVar9 = malloc(sVar19);
                      ArrayList_add(param_3 + 2,pvVar9);
                    }
                    lVar11 = (long)iVar16 + 4;
                    memset(pvVar9,0,sVar19);
                    *(void **)((long)pvVar8 + uVar18 * 8) = pvVar9;
                    memcpy(pvVar9,(void *)((long)param_2 + lVar11),sVar19);
                    uVar18 = uVar18 + 1;
                    iVar16 = iVar5 + (int)lVar11;
                  } while (uVar3 != uVar18);
                  *(void **)(param_1 + 10) = pvVar8;
                }
                iVar10 = iVar16 + 8;
                param_1[0xc] = *(uint32_t *)((long)param_2 + (long)iVar16);
                uVar3 = ((uint32_t *)((long)param_2 + (long)iVar16))[1];
                if ((int)uVar3 < 1) {
                  *(uint64_t *)(param_1 + 0xe) = 0;
                }
                else {
                  iVar5 = uVar3 * 8;
                  iVar16 = (int)*plVar21 + iVar5;
                  if ((iVar16 < 0x10000) && (*param_3 != 0)) {
                    pvVar8 = (void *)(*param_3 + (long)(int)*plVar21);
                    *(int *)plVar21 = iVar16;
                  }
                  else {
                    pvVar8 = malloc((long)iVar5);
                    ArrayList_add(param_3 + 2,pvVar8);
                  }
                  memset(pvVar8,0,(long)iVar5);
                  uVar18 = 0;
                  do {
                    iVar5 = *(int *)((long)param_2 + (long)iVar10);
                    sVar19 = (size_t)iVar5;
                    iVar16 = (int)*plVar21 + iVar5;
                    if ((iVar16 < 0x10000) && (*param_3 != 0)) {
                      pvVar9 = (void *)(*param_3 + (long)(int)*plVar21);
                      *(int *)plVar21 = iVar16;
                    }
                    else {
                      pvVar9 = malloc(sVar19);
                      ArrayList_add(param_3 + 2,pvVar9);
                    }
                    lVar11 = (long)iVar10 + 4;
                    memset(pvVar9,0,sVar19);
                    *(void **)((long)pvVar8 + uVar18 * 8) = pvVar9;
                    memcpy(pvVar9,(void *)((long)param_2 + lVar11),sVar19);
                    uVar18 = uVar18 + 1;
                    iVar10 = iVar5 + (int)lVar11;
                  } while (uVar3 != uVar18);
                  *(void **)(param_1 + 0xe) = pvVar8;
                }
                if (0 < *(int *)((long)param_2 + (long)iVar10)) {
                  iVar16 = (int)*plVar21;
                  if ((iVar16 < 0xff24) && (*param_3 != 0)) {
                    puVar15 = (uint64_t *)(*param_3 + (long)iVar16);
                    *(int *)plVar21 = iVar16 + 0xdc;
                  }
                  else {
                    puVar15 = malloc(0xdc);
                    ArrayList_add(param_3 + 2,puVar15);
                  }
                  *(uint64_t *)((long)puVar15 + 0xd4) = 0;
                  *(uint64_t *)((long)puVar15 + 0xcc) = 0;
                  puVar15[0x17] = 0;
                  puVar15[0x16] = 0;
                  puVar15[0x19] = 0;
                  puVar15[0x18] = 0;
                  puVar15[0x13] = 0;
                  puVar15[0x12] = 0;
                  puVar15[0x15] = 0;
                  puVar15[0x14] = 0;
                  puVar15[0xf] = 0;
                  puVar15[0xe] = 0;
                  puVar15[0x11] = 0;
                  puVar15[0x10] = 0;
                  puVar15[0xb] = 0;
                  puVar15[10] = 0;
                  puVar15[0xd] = 0;
                  puVar15[0xc] = 0;
                  puVar15[7] = 0;
                  puVar15[6] = 0;
                  puVar15[9] = 0;
                  puVar15[8] = 0;
                  puVar15[3] = 0;
                  puVar15[2] = 0;
                  puVar15[5] = 0;
                  puVar15[4] = 0;
                  puVar15[1] = 0;
                  *puVar15 = 0;
                  *(uint64_t **)(param_1 + 0x10) = puVar15;
                  FUN_0014dc68(puVar15,(long)param_2 + (long)iVar10 + 4);
                  return;
                }
                *(uint64_t *)(param_1 + 0x10) = 0;
                return;
              }
              goto LAB_0014c9f4;
            }
            iVar16 = *(int *)((long)param_2 + (long)iVar10);
            uVar18 = (long)iVar10 + 4;
            if (0 < iVar16) {
              iVar10 = (int)*plVar21;
              if ((iVar10 < 0xffc0) && (*param_3 != 0)) {
                puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
                *(int *)plVar21 = iVar10 + 0x40;
              }
              else {
                puVar6 = malloc(0x40);
                ArrayList_add(param_3 + 2,puVar6);
              }
              puVar6[5] = 0;
              puVar6[4] = 0;
              puVar6[7] = 0;
              puVar6[6] = 0;
              puVar6[1] = 0;
              *puVar6 = 0;
              puVar6[3] = 0;
              puVar6[2] = 0;
              puVar1 = (uint32_t *)((long)param_2 + uVar18);
              uVar2 = *puVar1;
              uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
              *(uint32_t *)(puVar6 + 2) = puVar1[1];
              uVar4 = puVar1[2];
              *(uint32_t *)puVar6 = uVar2;
              *(uint32_t *)((long)puVar6 + 0x14) = uVar4;
              *(uint32_t *)(puVar6 + 3) = puVar1[3];
              *(uint32_t *)((long)puVar6 + 0x1c) = puVar1[4];
              *(uint32_t *)(puVar6 + 4) = puVar1[5];
              *(uint32_t *)((long)puVar6 + 0x24) = puVar1[6];
              *(uint32_t *)(puVar6 + 5) = puVar1[7];
              *(uint32_t *)((long)puVar6 + 0x2c) = puVar1[8];
              *(uint32_t *)(puVar6 + 6) = puVar1[9];
              *(uint32_t *)((long)puVar6 + 0x34) = puVar1[10];
              *(uint32_t *)(puVar6 + 7) = puVar1[0xb];
              *(uint32_t *)((long)puVar6 + 0x3c) = puVar1[0xc];
              goto LAB_0014c1a0;
            }
          }
          else if (uVar3 == 0x33) {
            iVar16 = *(int *)((long)param_2 + (long)iVar10);
            uVar18 = (long)iVar10 + 4;
            if (iVar16 < 1) {
              uVar18 = uVar18 & 0xffffffff;
            }
            else {
              iVar10 = (int)*plVar21;
              if ((iVar10 < 0xff30) && (*param_3 != 0)) {
                puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
                *(int *)plVar21 = iVar10 + 0xd0;
              }
              else {
                puVar6 = malloc(0xd0);
                ArrayList_add(param_3 + 2,puVar6);
              }
              puVar6[0x17] = 0;
              puVar6[0x16] = 0;
              puVar6[0x19] = 0;
              puVar6[0x18] = 0;
              puVar6[0x13] = 0;
              puVar6[0x12] = 0;
              puVar6[0x15] = 0;
              puVar6[0x14] = 0;
              puVar6[0xf] = 0;
              puVar6[0xe] = 0;
              puVar6[0x11] = 0;
              puVar6[0x10] = 0;
              puVar6[0xb] = 0;
              puVar6[10] = 0;
              puVar6[0xd] = 0;
              puVar6[0xc] = 0;
              puVar6[7] = 0;
              puVar6[6] = 0;
              puVar6[9] = 0;
              puVar6[8] = 0;
              puVar6[3] = 0;
              puVar6[2] = 0;
              puVar6[5] = 0;
              puVar6[4] = 0;
              puVar6[1] = 0;
              *puVar6 = 0;
              puVar1 = (uint32_t *)((long)param_2 + uVar18);
              uVar2 = *puVar1;
              uVar4 = puVar1[1];
              uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
              puVar6[1] = puVar15;
              *(uint32_t *)(puVar6 + 2) = uVar4;
              uVar4 = puVar1[2];
              *(uint32_t *)puVar6 = uVar2;
              *(uint32_t *)((long)puVar6 + 0x14) = uVar4;
              *(uint32_t *)(puVar6 + 3) = puVar1[3];
              *(uint32_t *)((long)puVar6 + 0x1c) = puVar1[4];
              *(uint32_t *)(puVar6 + 4) = puVar1[5];
              *(uint32_t *)((long)puVar6 + 0x24) = puVar1[6];
              *(uint32_t *)(puVar6 + 5) = puVar1[7];
              *(uint32_t *)((long)puVar6 + 0x2c) = puVar1[8];
              *(uint32_t *)(puVar6 + 6) = puVar1[9];
              *(uint32_t *)((long)puVar6 + 0x34) = puVar1[10];
              *(uint32_t *)(puVar6 + 7) = puVar1[0xb];
              *(uint32_t *)((long)puVar6 + 0x3c) = puVar1[0xc];
              *(uint32_t *)(puVar6 + 8) = puVar1[0xd];
              *(uint32_t *)((long)puVar6 + 0x44) = puVar1[0xe];
              *(uint32_t *)(puVar6 + 9) = puVar1[0xf];
              *(uint32_t *)((long)puVar6 + 0x4c) = puVar1[0x10];
              *(uint32_t *)(puVar6 + 10) = puVar1[0x11];
              *(uint32_t *)((long)puVar6 + 0x54) = puVar1[0x12];
              *(uint32_t *)(puVar6 + 0xb) = puVar1[0x13];
              *(uint32_t *)((long)puVar6 + 0x5c) = puVar1[0x14];
              *(uint32_t *)(puVar6 + 0xc) = puVar1[0x15];
              *(uint32_t *)((long)puVar6 + 100) = puVar1[0x16];
              *(uint32_t *)(puVar6 + 0xd) = puVar1[0x17];
              *(uint32_t *)((long)puVar6 + 0x6c) = puVar1[0x18];
              *(uint32_t *)(puVar6 + 0xe) = puVar1[0x19];
              *(uint32_t *)((long)puVar6 + 0x74) = puVar1[0x1a];
              *(uint32_t *)(puVar6 + 0xf) = puVar1[0x1b];
              *(uint32_t *)((long)puVar6 + 0x7c) = puVar1[0x1c];
              *(uint32_t *)(puVar6 + 0x10) = puVar1[0x1d];
              *(uint32_t *)((long)puVar6 + 0x84) = puVar1[0x1e];
              *(uint32_t *)(puVar6 + 0x11) = puVar1[0x1f];
              *(uint32_t *)((long)puVar6 + 0x8c) = puVar1[0x20];
              *(uint32_t *)(puVar6 + 0x12) = puVar1[0x21];
              *(uint32_t *)((long)puVar6 + 0x94) = puVar1[0x22];
              *(uint32_t *)(puVar6 + 0x13) = puVar1[0x23];
              *(uint32_t *)((long)puVar6 + 0x9c) = puVar1[0x24];
              *(uint32_t *)(puVar6 + 0x14) = puVar1[0x25];
              *(uint32_t *)((long)puVar6 + 0xa4) = puVar1[0x26];
              *(uint32_t *)(puVar6 + 0x15) = puVar1[0x27];
              *(uint32_t *)((long)puVar6 + 0xac) = puVar1[0x28];
              *(uint32_t *)(puVar6 + 0x16) = puVar1[0x29];
              *(uint32_t *)((long)puVar6 + 0xb4) = puVar1[0x2a];
              *(uint32_t *)(puVar6 + 0x17) = puVar1[0x2b];
              *(uint32_t *)((long)puVar6 + 0xbc) = puVar1[0x2c];
              *(uint32_t *)(puVar6 + 0x18) = puVar1[0x2d];
              *(uint32_t *)((long)puVar6 + 0xc4) = puVar1[0x2e];
              *(uint32_t *)(puVar6 + 0x19) = puVar1[0x2f];
              puVar15 = puVar6;
            }
          }
          else {
            if (uVar3 != 0x35) goto LAB_0014c9f4;
            iVar16 = *(int *)((long)param_2 + (long)iVar10);
            uVar18 = (long)iVar10 + 4;
            if (0 < iVar16) {
              iVar10 = (int)*plVar21;
              if ((iVar10 < 0xffb0) && (*param_3 != 0)) {
                puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
                *(int *)plVar21 = iVar10 + 0x50;
              }
              else {
                puVar6 = malloc(0x50);
                ArrayList_add(param_3 + 2,puVar6);
              }
              puVar6[7] = 0;
              puVar6[6] = 0;
              puVar6[9] = 0;
              puVar6[8] = 0;
              puVar6[3] = 0;
              puVar6[2] = 0;
              puVar6[5] = 0;
              puVar6[4] = 0;
              puVar6[1] = 0;
              *puVar6 = 0;
              puVar1 = (uint32_t *)((long)param_2 + uVar18);
              uVar2 = *puVar1;
              uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
              *(uint32_t *)(puVar6 + 2) = puVar1[1];
              uVar4 = puVar1[2];
              *(uint32_t *)puVar6 = uVar2;
              *(uint32_t *)((long)puVar6 + 0x14) = uVar4;
              *(uint32_t *)(puVar6 + 3) = puVar1[3];
              *(uint32_t *)((long)puVar6 + 0x1c) = puVar1[4];
              *(uint32_t *)(puVar6 + 4) = puVar1[5];
              *(uint32_t *)((long)puVar6 + 0x24) = puVar1[6];
              *(uint32_t *)(puVar6 + 5) = puVar1[7];
              *(uint32_t *)((long)puVar6 + 0x2c) = puVar1[8];
              *(uint32_t *)(puVar6 + 6) = puVar1[9];
              *(uint32_t *)((long)puVar6 + 0x34) = puVar1[10];
              *(uint32_t *)(puVar6 + 7) = puVar1[0xb];
              *(uint32_t *)((long)puVar6 + 0x3c) = puVar1[0xc];
              *(uint32_t *)(puVar6 + 8) = puVar1[0xd];
              *(uint32_t *)((long)puVar6 + 0x44) = puVar1[0xe];
              *(uint32_t *)(puVar6 + 9) = puVar1[0xf];
              goto LAB_0014c1a0;
            }
          }
        }
        else {
          if ((int)uVar3 < 0x3b9b9909) {
            if (uVar3 == 0x3b9b3760) goto LAB_0014bfec;
            if (uVar3 == 0x3b9b75e3) goto LAB_0014c130;
          }
          else {
            if (uVar3 == 0x3b9b9909) goto LAB_0014c028;
            if (uVar3 == 0x3b9bb078) {
              iVar16 = *(int *)((long)param_2 + (long)iVar10);
              uVar18 = (long)iVar10 + 4;
              if (0 < iVar16) {
                iVar10 = (int)*plVar21;
                if ((iVar10 < 0xff10) && (*param_3 != 0)) {
                  puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
                  *(int *)plVar21 = iVar10 + 0xf0;
                }
                else {
                  puVar6 = malloc(0xf0);
                  ArrayList_add(param_3 + 2,puVar6);
                }
                puVar6[0x1b] = 0;
                puVar6[0x1a] = 0;
                puVar6[0x1d] = 0;
                puVar6[0x1c] = 0;
                puVar6[0x17] = 0;
                puVar6[0x16] = 0;
                puVar6[0x19] = 0;
                puVar6[0x18] = 0;
                puVar6[0x13] = 0;
                puVar6[0x12] = 0;
                puVar6[0x15] = 0;
                puVar6[0x14] = 0;
                puVar6[0xf] = 0;
                puVar6[0xe] = 0;
                puVar6[0x11] = 0;
                puVar6[0x10] = 0;
                puVar6[0xb] = 0;
                puVar6[10] = 0;
                puVar6[0xd] = 0;
                puVar6[0xc] = 0;
                puVar6[7] = 0;
                puVar6[6] = 0;
                puVar6[9] = 0;
                puVar6[8] = 0;
                puVar6[3] = 0;
                puVar6[2] = 0;
                puVar6[5] = 0;
                puVar6[4] = 0;
                puVar6[1] = 0;
                *puVar6 = 0;
                FUN_0014ce84(puVar6,(long)param_2 + uVar18,param_3);
                uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
                goto LAB_0014c1a0;
              }
              goto LAB_0014bacc;
            }
          }
LAB_0014c9f4:
          uVar18 = (unsigned long)(iVar10 + 4);
        }
      }
      else if ((int)uVar3 < 0x3b9c0669) {
        if ((uVar3 == 0x3b9bc018) || (uVar3 == 0x3b9bcbd0)) goto LAB_0014c130;
        if (uVar3 != 0x3b9bdb71) goto LAB_0014c9f4;
        lVar11 = (long)iVar10;
        iVar10 = *(int *)((long)param_2 + lVar11);
        uVar18 = lVar11 + 4;
        if (iVar10 < 1) {
          uVar18 = uVar18 & 0xffffffff;
        }
        else {
          iVar16 = (int)*plVar21;
          if ((iVar16 < 0xffe0) && (*param_3 != 0)) {
            puVar6 = (uint64_t *)(*param_3 + (long)iVar16);
            *(int *)plVar21 = iVar16 + 0x20;
          }
          else {
            puVar6 = malloc(0x20);
            ArrayList_add(param_3 + 2,puVar6);
          }
          puVar6[1] = 0;
          *puVar6 = 0;
          puVar6[3] = 0;
          puVar6[2] = 0;
          puVar1 = (uint32_t *)((long)param_2 + uVar18);
          uVar2 = *puVar1;
          uVar4 = puVar1[1];
          puVar6[1] = 0;
          *(uint32_t *)(puVar6 + 2) = uVar4;
          uVar3 = puVar1[2];
          *(uint32_t *)puVar6 = uVar2;
          if ((int)uVar3 < 1) {
            puVar6[3] = 0;
          }
          else {
            iVar5 = uVar3 * 8;
            iVar16 = (int)*plVar21 + iVar5;
            if ((iVar16 < 0x10000) && (*param_3 != 0)) {
              pvVar8 = (void *)(*param_3 + (long)(int)*plVar21);
              *(int *)plVar21 = iVar16;
            }
            else {
              pvVar8 = malloc((long)iVar5);
              ArrayList_add(param_3 + 2,pvVar8);
            }
            memset(pvVar8,0,(long)iVar5);
            uVar20 = 0;
            do {
              if (pvVar8 != (void *)0x0) {
                uVar7 = VkObject_fromId(*(uint64_t *)((long)param_2 + uVar20 * 8 + lVar11 + 0x10))
                ;
                *(uint64_t *)((long)pvVar8 + uVar20 * 8) = uVar7;
              }
              uVar20 = uVar20 + 1;
            } while (uVar3 != uVar20);
            puVar6[3] = pvVar8;
          }
          uVar18 = (unsigned long)(uint32_t)(iVar10 + (int)uVar18);
          puVar6[1] = puVar15;
          puVar15 = puVar6;
        }
      }
      else {
        if ((int)uVar3 < 0x3b9c0e38) {
          if (uVar3 != 0x3b9c0669) {
            uVar13 = 0xa50;
LAB_0014bdb4:
            uVar13 = uVar13 | 0x3b9c0000;
joined_r0x0014bfe8:
            if (uVar3 != uVar13) goto LAB_0014c9f4;
          }
          goto LAB_0014bfec;
        }
        if (uVar3 != 0x3b9c0e38) {
          if (uVar3 == 0x3b9c5870) goto LAB_0014c130;
          goto LAB_0014c9f4;
        }
        iVar16 = *(int *)((long)param_2 + (long)iVar10);
        uVar18 = (long)iVar10 + 4;
        if (0 < iVar16) {
          iVar10 = (int)*plVar21;
          if ((iVar10 < 0xffe0) && (*param_3 != 0)) {
            puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
            *(int *)plVar21 = iVar10 + 0x20;
          }
          else {
            puVar6 = malloc(0x20);
            ArrayList_add(param_3 + 2,puVar6);
          }
          puVar6[1] = 0;
          *puVar6 = 0;
          puVar6[3] = 0;
          puVar6[2] = 0;
          puVar1 = (uint32_t *)((long)param_2 + uVar18);
          uVar2 = *puVar1;
          uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
          *(uint32_t *)(puVar6 + 2) = puVar1[1];
          uVar4 = puVar1[2];
          *(uint32_t *)puVar6 = uVar2;
          *(uint32_t *)((long)puVar6 + 0x14) = uVar4;
          *(uint32_t *)(puVar6 + 3) = puVar1[3];
          *(uint32_t *)((long)puVar6 + 0x1c) = puVar1[4];
          goto LAB_0014c1a0;
        }
      }
    }
    else {
      if ((int)uVar3 < 0x3b9d7d68) {
        if ((int)uVar3 < 0x3b9d0069) {
          if (uVar3 != 0x3b9c6fe0) {
            if (uVar3 != 0x3b9c9ec0) {
              uVar13 = 0xe510;
              goto LAB_0014bdb4;
            }
            goto LAB_0014bfec;
          }
        }
        else {
          if ((int)uVar3 < 0x3b9d3ee9) {
            if (uVar3 == 0x3b9d0069) goto LAB_0014c130;
            uVar13 = 0x2b64;
          }
          else {
            if (uVar3 == 0x3b9d3ee9) {
              iVar16 = *(int *)((long)param_2 + (long)iVar10);
              uVar18 = (long)iVar10 + 4;
              if (0 < iVar16) {
                iVar10 = (int)*plVar21;
                if ((iVar10 < 0xffa0) && (*param_3 != 0)) {
                  puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
                  *(int *)plVar21 = iVar10 + 0x60;
                }
                else {
                  puVar6 = malloc(0x60);
                  ArrayList_add(param_3 + 2,puVar6);
                }
                puVar6[9] = 0;
                puVar6[8] = 0;
                puVar6[0xb] = 0;
                puVar6[10] = 0;
                puVar6[5] = 0;
                puVar6[4] = 0;
                puVar6[7] = 0;
                puVar6[6] = 0;
                puVar6[1] = 0;
                *puVar6 = 0;
                puVar6[3] = 0;
                puVar6[2] = 0;
                puVar1 = (uint32_t *)((long)param_2 + uVar18);
                uVar2 = *puVar1;
                uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
                *(uint32_t *)(puVar6 + 2) = puVar1[1];
                uVar4 = puVar1[2];
                *(uint32_t *)puVar6 = uVar2;
                *(uint32_t *)((long)puVar6 + 0x14) = uVar4;
                *(uint32_t *)(puVar6 + 3) = puVar1[3];
                *(uint32_t *)((long)puVar6 + 0x1c) = puVar1[4];
                *(uint32_t *)(puVar6 + 4) = puVar1[5];
                *(uint32_t *)((long)puVar6 + 0x24) = puVar1[6];
                *(uint32_t *)(puVar6 + 5) = puVar1[7];
                *(uint32_t *)((long)puVar6 + 0x2c) = puVar1[8];
                *(uint32_t *)(puVar6 + 6) = puVar1[9];
                *(uint32_t *)((long)puVar6 + 0x34) = puVar1[10];
                *(uint32_t *)(puVar6 + 7) = puVar1[0xb];
                *(uint32_t *)((long)puVar6 + 0x3c) = puVar1[0xc];
                *(uint32_t *)(puVar6 + 8) = puVar1[0xd];
                *(uint32_t *)((long)puVar6 + 0x44) = puVar1[0xe];
                *(uint32_t *)(puVar6 + 9) = puVar1[0xf];
                *(uint32_t *)((long)puVar6 + 0x4c) = puVar1[0x10];
                *(uint32_t *)(puVar6 + 10) = puVar1[0x11];
                *(uint32_t *)((long)puVar6 + 0x54) = puVar1[0x12];
                *(uint32_t *)(puVar6 + 0xb) = puVar1[0x13];
                *(uint32_t *)((long)puVar6 + 0x5c) = puVar1[0x14];
                goto LAB_0014c1a0;
              }
              goto LAB_0014bacc;
            }
            uVar13 = 0x7598;
          }
          uVar13 = uVar13 | 0x3b9d0000;
joined_r0x0014c12c:
          if (uVar3 != uVar13) goto LAB_0014c9f4;
        }
LAB_0014c130:
        iVar16 = *(int *)((long)param_2 + (long)iVar10);
        uVar18 = (long)iVar10 + 4;
        if (iVar16 < 1) goto LAB_0014bacc;
        iVar10 = (int)*plVar21;
        if ((iVar10 < 0xffe8) && (*param_3 != 0)) {
          puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
          *(int *)plVar21 = iVar10 + 0x18;
        }
        else {
          puVar6 = malloc(0x18);
          ArrayList_add(param_3 + 2,puVar6);
        }
        *puVar6 = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar1 = (uint32_t *)((long)param_2 + uVar18);
        uVar2 = puVar1[1];
        uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
        *(uint32_t *)puVar6 = *puVar1;
        *(uint32_t *)(puVar6 + 2) = uVar2;
      }
      else {
        if (0x3b9df297 < (int)uVar3) {
          if ((int)uVar3 < 0x3b9e11d8) {
            if (uVar3 != 0x3b9df298) {
              uVar13 = 0x238;
LAB_0014bd80:
              if (uVar3 != (uVar13 | 0x3b9e0000)) goto LAB_0014c9f4;
              goto LAB_0014c028;
            }
          }
          else if (uVar3 != 0x3b9e11d8) {
            uVar13 = 0x2948;
LAB_0014c100:
            uVar13 = uVar13 | 0x3b9e0000;
            goto joined_r0x0014c12c;
          }
          goto LAB_0014c130;
        }
        if (uVar3 != 0x3b9d7d68) {
          if ((uVar3 != 0x3b9d8920) && (uVar3 != 0x3b9db032)) goto LAB_0014c9f4;
          goto LAB_0014bfec;
        }
LAB_0014c028:
        iVar16 = *(int *)((long)param_2 + (long)iVar10);
joined_r0x0014c23c:
        uVar18 = (long)iVar10 + 4;
        if (iVar16 < 1) goto LAB_0014bacc;
        iVar10 = (int)*plVar21;
        if ((iVar10 < 0xffe0) && (*param_3 != 0)) {
          puVar6 = (uint64_t *)(*param_3 + (long)iVar10);
          *(int *)plVar21 = iVar10 + 0x20;
        }
        else {
          puVar6 = malloc(0x20);
          ArrayList_add(param_3 + 2,puVar6);
        }
        puVar6[1] = 0;
        *puVar6 = 0;
        puVar6[3] = 0;
        puVar6[2] = 0;
        puVar1 = (uint32_t *)((long)param_2 + uVar18);
        uVar2 = *puVar1;
        uVar18 = (unsigned long)(uint32_t)(iVar16 + (int)uVar18);
        *(uint32_t *)(puVar6 + 2) = puVar1[1];
        *(uint32_t *)((long)puVar6 + 0x14) = puVar1[2];
        uVar4 = puVar1[3];
        *(uint32_t *)puVar6 = uVar2;
        *(uint32_t *)(puVar6 + 3) = uVar4;
      }
LAB_0014c1a0:
      puVar6[1] = puVar15;
      puVar15 = puVar6;
    }
LAB_0014bacc:
    puVar12 = (uint32_t *)((long)param_2 + (long)(int)uVar18);
    iVar10 = (int)uVar18 + 4;
  } while( true );
}








/* @0014ce84  size=3556 */

void FUN_0014ce84(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  /* STUB: conflicting types */
}








/* @0014dc68  size=444 */

void FUN_0014dc68(uint32_t *param_1,uint32_t *param_2)

{
  /* STUB: conflicting types */
}








/* @0014de24  size=632 */

void FUN_0014de24(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  int iVar3;
  uint32_t uVar4;
  void *__s;
  int iVar5;
  int *piVar6;
  uint64_t *puVar7;
  uint64_t *puVar8;
  uint64_t uVar9;
  int iVar10;
  size_t __size;
  uint64_t *puVar11;
  unsigned long uVar12;
  
  piVar6 = param_2 + 1;
  puVar11 = (uint64_t *)0x0;
  iVar5 = 8;
  *param_1 = *param_2;
  do {
    iVar3 = *piVar6;
    if (iVar3 == 0x3b9be340) {
      iVar3 = *(int *)((long)param_2 + (long)iVar5);
      uVar12 = (long)iVar5 + 4;
      if (0 < iVar3) {
        iVar5 = (int)param_3[1];
        if ((iVar5 < 0xffe8) && (*param_3 != 0)) {
          puVar7 = (uint64_t *)(*param_3 + (long)iVar5);
          *(int *)(param_3 + 1) = iVar5 + 0x18;
        }
        else {
          puVar7 = malloc(0x18);
          ArrayList_add(param_3 + 2,puVar7);
        }
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        uVar4 = ((uint32_t *)((long)param_2 + uVar12))[1];
        uVar1 = iVar3 + (int)uVar12;
        *(uint32_t *)puVar7 = *(uint32_t *)((long)param_2 + uVar12);
        *(uint32_t *)(puVar7 + 2) = uVar4;
LAB_0014deb8:
        uVar12 = (unsigned long)uVar1;
        puVar7[1] = puVar11;
        puVar11 = puVar7;
      }
    }
    else if (iVar3 == 0x3b9eb5ea) {
      iVar3 = *(int *)((long)param_2 + (long)iVar5);
      uVar12 = (long)iVar5 + 4;
      if (0 < iVar3) {
        iVar5 = (int)param_3[1];
        if ((iVar5 < 0xffe8) && (*param_3 != 0)) {
          puVar7 = (uint64_t *)(*param_3 + (long)iVar5);
          *(int *)(param_3 + 1) = iVar5 + 0x18;
        }
        else {
          puVar7 = malloc(0x18);
          ArrayList_add(param_3 + 2,puVar7);
        }
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        uVar9 = *(uint64_t *)((uint32_t *)((long)param_2 + uVar12) + 1);
        uVar1 = iVar3 + (int)uVar12;
        *(uint32_t *)puVar7 = *(uint32_t *)((long)param_2 + uVar12);
        puVar7[2] = uVar9;
        goto LAB_0014deb8;
      }
    }
    else {
      if (iVar3 == -1) {
        if (puVar11 == (uint64_t *)0x0) {
          puVar7 = (uint64_t *)0x0;
        }
        else {
          puVar8 = (uint64_t *)0x0;
          do {
            puVar7 = puVar11;
            puVar11 = (uint64_t *)puVar7[1];
            puVar7[1] = puVar8;
            puVar8 = puVar7;
          } while (puVar11 != (uint64_t *)0x0);
        }
        puVar2 = (uint32_t *)((long)param_2 + (long)iVar5);
        uVar4 = *puVar2;
        uVar9 = *(uint64_t *)(puVar2 + 1);
        *(uint64_t **)(param_1 + 2) = puVar7;
        param_1[4] = uVar4;
        uVar4 = puVar2[3];
        *(uint64_t *)(param_1 + 6) = uVar9;
        param_1[8] = uVar4;
        uVar4 = puVar2[4];
        param_1[10] = puVar2[5];
        iVar3 = puVar2[6];
        param_1[9] = uVar4;
        if (iVar3 < 1) {
          *(uint64_t *)(param_1 + 0xc) = 0;
        }
        else {
          __size = (long)iVar3 << 2;
          iVar10 = (int)__size;
          iVar3 = (int)param_3[1] + iVar10;
          if ((iVar3 < 0x10000) && (*param_3 != 0)) {
            __s = (void *)(*param_3 + (long)(int)param_3[1]);
            __size = (size_t)iVar10;
            *(int *)(param_3 + 1) = iVar3;
          }
          else {
            __s = malloc(__size);
            ArrayList_add(param_3 + 2,__s);
          }
          memset(__s,0,__size);
          if (__s != (void *)0x0) {
            memcpy(__s,(void *)((long)param_2 + (long)iVar5 + 0x1c),(long)iVar10);
          }
          *(void **)(param_1 + 0xc) = __s;
        }
        return;
      }
      uVar12 = (unsigned long)(iVar5 + 4);
    }
    piVar6 = (int *)((long)param_2 + (long)(int)uVar12);
    iVar5 = (int)uVar12 + 4;
  } while( true );
}








/* @0014e09c  size=1176 */

void FUN_0014e09c(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  void *pvVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  int *piVar9;
  uint64_t *puVar10;
  unsigned long uVar11;
  uint64_t *puVar12;
  int iVar13;
  size_t sVar14;
  int iVar15;
  
  piVar9 = param_2 + 1;
  puVar12 = (uint64_t *)0x0;
  iVar6 = 8;
  *param_1 = *param_2;
  do {
    iVar13 = *piVar9;
    if (iVar13 < 0x3b9d0838) {
      if (iVar13 == 0x3b9bb468) {
        iVar13 = *(int *)((long)param_2 + (long)iVar6);
        uVar11 = (long)iVar6 + 4;
        if (0 < iVar13) {
          iVar6 = (int)param_3[1];
          if ((iVar6 < 0xffe8) && (*param_3 != 0)) {
            puVar3 = (uint64_t *)(*param_3 + (long)iVar6);
            *(int *)(param_3 + 1) = iVar6 + 0x18;
          }
          else {
            puVar3 = malloc(0x18);
            ArrayList_add(param_3 + 2,puVar3);
          }
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
          uVar8 = *(uint32_t *)((long)param_2 + uVar11);
          uVar4 = *(uint64_t *)((uint32_t *)((long)param_2 + uVar11) + 1);
          puVar3[1] = 0;
          *(uint32_t *)puVar3 = uVar8;
          uVar4 = VkObject_fromId(uVar4);
          uVar1 = iVar13 + (int)uVar11;
          puVar3[2] = uVar4;
          goto LAB_0014e2f0;
        }
LAB_0014e100:
        uVar11 = uVar11 & 0xffffffff;
      }
      else if (iVar13 == 0x3b9be341) {
        iVar13 = *(int *)((long)param_2 + (long)iVar6);
        uVar11 = (long)iVar6 + 4;
        if (iVar13 < 1) goto LAB_0014e100;
        iVar6 = (int)param_3[1];
        if ((iVar6 < 0xffe8) && (*param_3 != 0)) {
          puVar3 = (uint64_t *)(*param_3 + (long)iVar6);
          *(int *)(param_3 + 1) = iVar6 + 0x18;
        }
        else {
          puVar3 = malloc(0x18);
          ArrayList_add(param_3 + 2,puVar3);
        }
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        uVar8 = *(uint32_t *)((long)param_2 + uVar11);
        uVar7 = ((uint32_t *)((long)param_2 + uVar11))[1];
        uVar1 = iVar13 + (int)uVar11;
LAB_0014e2a4:
        *(uint32_t *)puVar3 = uVar8;
        *(uint32_t *)(puVar3 + 2) = uVar7;
LAB_0014e2f0:
        uVar11 = (unsigned long)uVar1;
        puVar3[1] = puVar12;
        puVar12 = puVar3;
      }
      else {
        if (iVar13 == -1) {
          if (puVar12 == (uint64_t *)0x0) {
            puVar3 = (uint64_t *)0x0;
          }
          else {
            puVar10 = (uint64_t *)0x0;
            do {
              puVar3 = puVar12;
              puVar12 = (uint64_t *)puVar3[1];
              puVar3[1] = puVar10;
              puVar10 = puVar3;
            } while (puVar12 != (uint64_t *)0x0);
          }
          puVar2 = (uint32_t *)((long)param_2 + (long)iVar6);
          uVar8 = *puVar2;
          *(uint64_t **)(param_1 + 2) = puVar3;
          uVar11 = (long)iVar6 + 0x38;
          param_1[4] = uVar8;
          uVar8 = puVar2[3];
          param_1[5] = puVar2[1];
          uVar7 = puVar2[2];
          param_1[7] = uVar8;
          uVar8 = puVar2[4];
          param_1[6] = uVar7;
          param_1[8] = uVar8;
          param_1[9] = puVar2[5];
          param_1[10] = puVar2[6];
          param_1[0xb] = puVar2[7];
          uVar8 = puVar2[10];
          param_1[0xc] = puVar2[8];
          uVar7 = puVar2[9];
          param_1[0xe] = uVar8;
          uVar8 = puVar2[0xc];
          param_1[0xd] = uVar7;
          uVar7 = puVar2[0xb];
          param_1[0x10] = uVar8;
          iVar6 = puVar2[0xd];
          param_1[0xf] = uVar7;
          if (iVar6 < 1) {
            *(uint64_t *)(param_1 + 0x12) = 0;
          }
          else {
            sVar14 = (long)iVar6 << 2;
            iVar13 = (int)sVar14;
            iVar6 = (int)param_3[1] + iVar13;
            if ((iVar6 < 0x10000) && (*param_3 != 0)) {
              pvVar5 = (void *)(*param_3 + (long)(int)param_3[1]);
              sVar14 = (size_t)iVar13;
              *(int *)(param_3 + 1) = iVar6;
            }
            else {
              pvVar5 = malloc(sVar14);
              ArrayList_add(param_3 + 2,pvVar5);
            }
            memset(pvVar5,0,sVar14);
            if (pvVar5 != (void *)0x0) {
              memcpy(pvVar5,(void *)((long)param_2 + uVar11),(long)iVar13);
            }
            uVar11 = (unsigned long)(uint32_t)(iVar13 + (int)uVar11);
            *(void **)(param_1 + 0x12) = pvVar5;
          }
          param_1[0x14] = *(uint32_t *)((long)param_2 + (long)(int)uVar11);
          return;
        }
LAB_0014e23c:
        uVar11 = (unsigned long)(iVar6 + 4);
      }
    }
    else if (iVar13 == 0x3b9d0838) {
      iVar13 = *(int *)((long)param_2 + (long)iVar6);
      uVar11 = (long)iVar6 + 4;
      if (0 < iVar13) {
        iVar6 = (int)param_3[1];
        if ((iVar6 < 0xffe0) && (*param_3 != 0)) {
          puVar3 = (uint64_t *)(*param_3 + (long)iVar6);
          *(int *)(param_3 + 1) = iVar6 + 0x20;
        }
        else {
          puVar3 = malloc(0x20);
          ArrayList_add(param_3 + 2,puVar3);
        }
        puVar3[1] = 0;
        *puVar3 = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        puVar2 = (uint32_t *)((long)param_2 + uVar11);
        uVar8 = *puVar2;
        uVar7 = puVar2[1];
        puVar3[1] = 0;
        *(uint32_t *)(puVar3 + 2) = uVar7;
        iVar6 = puVar2[2];
        *(uint32_t *)puVar3 = uVar8;
        if (iVar6 < 1) {
          puVar3[3] = 0;
        }
        else {
          sVar14 = (long)iVar6 << 2;
          iVar15 = (int)sVar14;
          iVar6 = (int)param_3[1] + iVar15;
          if ((iVar6 < 0x10000) && (*param_3 != 0)) {
            pvVar5 = (void *)(*param_3 + (long)(int)param_3[1]);
            sVar14 = (size_t)iVar15;
            *(int *)(param_3 + 1) = iVar6;
          }
          else {
            pvVar5 = malloc(sVar14);
            ArrayList_add(param_3 + 2,pvVar5);
          }
          memset(pvVar5,0,sVar14);
          if (pvVar5 != (void *)0x0) {
            memcpy(pvVar5,puVar2 + 3,(long)iVar15);
          }
          puVar3[3] = pvVar5;
        }
        uVar11 = (unsigned long)(uint32_t)(iVar13 + (int)uVar11);
        puVar3[1] = puVar12;
        puVar12 = puVar3;
      }
    }
    else {
      if (iVar13 != 0x3b9e8af0) goto LAB_0014e23c;
      iVar13 = *(int *)((long)param_2 + (long)iVar6);
      uVar11 = (long)iVar6 + 4;
      if (0 < iVar13) {
        iVar6 = (int)param_3[1];
        if ((iVar6 < 0xffe8) && (*param_3 != 0)) {
          puVar3 = (uint64_t *)(*param_3 + (long)iVar6);
          *(int *)(param_3 + 1) = iVar6 + 0x18;
        }
        else {
          puVar3 = malloc(0x18);
          ArrayList_add(param_3 + 2,puVar3);
        }
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        uVar8 = *(uint32_t *)((long)param_2 + uVar11);
        uVar7 = ((uint32_t *)((long)param_2 + uVar11))[1];
        uVar1 = iVar13 + (int)uVar11;
        goto LAB_0014e2a4;
      }
    }
    piVar9 = (int *)((long)param_2 + (long)(int)uVar11);
    iVar6 = (int)uVar11 + 4;
  } while( true );
}








/* @0014e534  size=1016 */

void FUN_0014e534(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  void *pvVar6;
  void *__s;
  uint64_t uVar7;
  int iVar8;
  long lVar9;
  int *piVar10;
  uint64_t *puVar11;
  uint64_t *puVar12;
  uint32_t *puVar13;
  int iVar14;
  int iVar15;
  size_t __size;
  unsigned long uVar16;
  uint64_t *puVar17;
  unsigned long uVar18;
  
  piVar10 = param_2 + 1;
  puVar17 = (uint64_t *)0x0;
  iVar8 = 8;
  *param_1 = *param_2;
  do {
    iVar14 = *piVar10;
    if (iVar14 == 0x3b9d3ee8) {
      iVar14 = *(int *)((long)param_2 + (long)iVar8);
      uVar18 = (long)iVar8 + 4;
      if (0 < iVar14) {
        iVar8 = (int)param_3[1];
        if ((iVar8 < 0xffe0) && (*param_3 != 0)) {
          puVar11 = (uint64_t *)(*param_3 + (long)iVar8);
          *(int *)(param_3 + 1) = iVar8 + 0x20;
        }
        else {
          puVar11 = malloc(0x20);
          ArrayList_add(param_3 + 2,puVar11);
        }
        puVar11[1] = 0;
        *puVar11 = 0;
        puVar11[3] = 0;
        puVar11[2] = 0;
        puVar1 = (uint32_t *)((long)param_2 + uVar18);
        uVar3 = *puVar1;
        uVar2 = puVar1[1];
        puVar11[1] = 0;
        *(uint32_t *)(puVar11 + 2) = uVar2;
        iVar8 = puVar1[2];
        *(uint32_t *)puVar11 = uVar3;
        if (iVar8 < 1) {
          puVar11[3] = 0;
        }
        else {
          __size = (long)iVar8 << 2;
          iVar15 = (int)__size;
          iVar8 = (int)param_3[1] + iVar15;
          if ((iVar8 < 0x10000) && (*param_3 != 0)) {
            pvVar6 = (void *)(*param_3 + (long)(int)param_3[1]);
            __size = (size_t)iVar15;
            *(int *)(param_3 + 1) = iVar8;
          }
          else {
            pvVar6 = malloc(__size);
            ArrayList_add(param_3 + 2,pvVar6);
          }
          memset(pvVar6,0,__size);
          if (pvVar6 != (void *)0x0) {
            memcpy(pvVar6,puVar1 + 3,(long)iVar15);
          }
          puVar11[3] = pvVar6;
        }
LAB_0014e590:
        uVar18 = (unsigned long)(uint32_t)(iVar14 + (int)uVar18);
        puVar11[1] = puVar17;
        puVar17 = puVar11;
      }
    }
    else if (iVar14 == 0x3ba0251a) {
      iVar14 = *(int *)((long)param_2 + (long)iVar8);
      uVar18 = (long)iVar8 + 4;
      if (0 < iVar14) {
        iVar8 = (int)param_3[1];
        if ((iVar8 < 0xffe0) && (*param_3 != 0)) {
          puVar11 = (uint64_t *)(*param_3 + (long)iVar8);
          *(int *)(param_3 + 1) = iVar8 + 0x20;
        }
        else {
          puVar11 = malloc(0x20);
          ArrayList_add(param_3 + 2,puVar11);
        }
        puVar11[1] = 0;
        *puVar11 = 0;
        puVar11[3] = 0;
        puVar11[2] = 0;
        FUN_0014e92c(puVar11,(long)param_2 + uVar18,param_3);
        goto LAB_0014e590;
      }
    }
    else {
      if (iVar14 == -1) {
        if (puVar17 == (uint64_t *)0x0) {
          puVar11 = (uint64_t *)0x0;
        }
        else {
          puVar12 = (uint64_t *)0x0;
          do {
            puVar11 = puVar17;
            puVar17 = (uint64_t *)puVar11[1];
            puVar11[1] = puVar12;
            puVar12 = puVar11;
          } while (puVar17 != (uint64_t *)0x0);
        }
        puVar1 = (uint32_t *)((long)param_2 + (long)iVar8);
        uVar3 = *puVar1;
        *(uint64_t **)(param_1 + 2) = puVar11;
        param_1[4] = uVar3;
        param_1[5] = puVar1[1];
        uVar4 = puVar1[2];
        if ((int)uVar4 < 1) {
          *(uint64_t *)(param_1 + 6) = 0;
        }
        else {
          iVar15 = uVar4 * 0x18;
          iVar8 = iVar8 + 0xc;
          iVar14 = (int)param_3[1] + iVar15;
          if ((iVar14 < 0x10000) && (*param_3 != 0)) {
            pvVar6 = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar14;
          }
          else {
            pvVar6 = malloc((long)iVar15);
            ArrayList_add(param_3 + 2,pvVar6);
          }
          memset(pvVar6,0,(long)iVar15);
          uVar18 = 0;
          do {
            lVar9 = (long)iVar8;
            iVar8 = *(int *)((long)param_2 + lVar9);
            if (pvVar6 != (void *)0x0) {
              puVar1 = (uint32_t *)((long)param_2 + lVar9 + 4);
              puVar13 = (uint32_t *)((long)pvVar6 + uVar18 * 0x18);
              *puVar13 = *puVar1;
              *(uint64_t *)(puVar13 + 1) = *(uint64_t *)(puVar1 + 1);
              puVar13[3] = puVar1[3];
              uVar5 = puVar1[4];
              if ((int)uVar5 < 1) {
                *(uint64_t *)((long)pvVar6 + uVar18 * 0x18 + 0x10) = 0;
              }
              else {
                iVar15 = uVar5 * 8;
                iVar14 = (int)param_3[1] + iVar15;
                if ((iVar14 < 0x10000) && (*param_3 != 0)) {
                  __s = (void *)(*param_3 + (long)(int)param_3[1]);
                  *(int *)(param_3 + 1) = iVar14;
                }
                else {
                  __s = malloc((long)iVar15);
                  ArrayList_add(param_3 + 2,__s);
                }
                memset(__s,0,(long)iVar15);
                uVar16 = 0;
                do {
                  if (__s != (void *)0x0) {
                    uVar7 = VkObject_fromId(*(uint64_t *)
                                             ((long)param_2 + uVar16 * 8 + lVar9 + 0x18));
                    *(uint64_t *)((long)__s + uVar16 * 8) = uVar7;
                  }
                  uVar16 = uVar16 + 1;
                } while (uVar5 != uVar16);
                *(void **)((long)pvVar6 + uVar18 * 0x18 + 0x10) = __s;
              }
            }
            uVar18 = uVar18 + 1;
            iVar8 = iVar8 + (int)(lVar9 + 4);
          } while (uVar18 != uVar4);
          *(void **)(param_1 + 6) = pvVar6;
        }
        return;
      }
      uVar18 = (unsigned long)(iVar8 + 4);
    }
    piVar10 = (int *)((long)param_2 + (long)(int)uVar18);
    iVar8 = (int)uVar18 + 4;
  } while( true );
}








/* @0014e92c  size=396 */

void FUN_0014e92c(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  /* STUB: conflicting types */
}








/* @0014eab8  size=1048 */

void FUN_0014eab8(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  uint64_t uVar7;
  void *pvVar8;
  int *piVar9;
  uint64_t *puVar10;
  uint64_t uVar11;
  uint64_t *puVar12;
  int iVar13;
  unsigned long uVar14;
  unsigned long __size;
  uint32_t *puVar15;
  uint64_t *puVar16;
  
  piVar9 = param_2 + 1;
  iVar13 = 8;
  *param_1 = *param_2;
  puVar16 = (uint64_t *)0x0;
  do {
    if (*piVar9 == 0x3b9ce512) {
      iVar2 = *(int *)((long)param_2 + (long)iVar13);
      uVar14 = (long)iVar13 + 4;
      if (iVar2 < 1) goto LAB_0014eb08;
      iVar13 = (int)param_3[1];
      if ((iVar13 < 0xffe0) && (*param_3 != 0)) {
        puVar10 = (uint64_t *)(*param_3 + (long)iVar13);
        *(int *)(param_3 + 1) = iVar13 + 0x20;
      }
      else {
        puVar10 = malloc(0x20);
        ArrayList_add(param_3 + 2,puVar10);
      }
      puVar10[1] = 0;
      *puVar10 = 0;
      puVar10[3] = 0;
      puVar10[2] = 0;
      puVar15 = (uint32_t *)((long)param_2 + uVar14);
      uVar5 = *puVar15;
      uVar3 = puVar15[1];
      puVar10[1] = 0;
      *(uint32_t *)(puVar10 + 2) = uVar3;
      uVar4 = puVar15[2];
      __size = (unsigned long)uVar4;
      *(uint32_t *)puVar10 = uVar5;
      if ((int)uVar4 < 1) {
        puVar10[3] = 0;
      }
      else {
        iVar13 = (int)param_3[1] + uVar4;
        if ((iVar13 < 0x10000) && (*param_3 != 0)) {
          pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
          *(int *)(param_3 + 1) = iVar13;
        }
        else {
          pvVar8 = malloc(__size);
          ArrayList_add(param_3 + 2,pvVar8);
        }
        memset(pvVar8,0,__size);
        puVar10[3] = pvVar8;
        memcpy(pvVar8,puVar15 + 3,__size);
      }
      iVar13 = iVar2 + (int)uVar14;
      puVar10[1] = puVar16;
    }
    else {
      if (*piVar9 == -1) {
        if (puVar16 == (uint64_t *)0x0) {
          puVar10 = (uint64_t *)0x0;
        }
        else {
          puVar12 = (uint64_t *)0x0;
          do {
            puVar10 = puVar16;
            puVar16 = (uint64_t *)puVar10[1];
            puVar10[1] = puVar12;
            puVar12 = puVar10;
          } while (puVar16 != (uint64_t *)0x0);
        }
        puVar16 = (uint64_t *)((long)param_2 + (long)iVar13);
        uVar7 = *puVar16;
        *(uint64_t **)(param_1 + 2) = puVar10;
        uVar7 = VkObject_fromId(uVar7);
        uVar5 = *(uint32_t *)(puVar16 + 1);
        *(uint64_t *)(param_1 + 4) = uVar7;
        iVar13 = iVar13 + 0x1c;
        param_1[6] = uVar5;
        param_1[7] = *(uint32_t *)((long)puVar16 + 0xc);
        param_1[8] = *(uint32_t *)(puVar16 + 2);
        uVar4 = *(uint32_t *)(puVar16 + 3);
        uVar14 = (unsigned long)uVar4;
        param_1[9] = *(uint32_t *)((long)puVar16 + 0x14);
        if ((int)uVar4 < 1) {
          *(uint64_t *)(param_1 + 10) = 0;
        }
        else {
          iVar6 = uVar4 * 0x18;
          iVar2 = (int)param_3[1] + iVar6;
          if ((iVar2 < 0x10000) && (*param_3 != 0)) {
            pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar2;
          }
          else {
            pvVar8 = malloc((long)iVar6);
            ArrayList_add(param_3 + 2,pvVar8);
          }
          memset(pvVar8,0,(long)iVar6);
          puVar15 = (uint32_t *)((long)pvVar8 + 0x10);
          do {
            iVar2 = *(int *)((long)param_2 + (long)iVar13);
            lVar1 = (long)iVar13 + 4;
            if (pvVar8 != (void *)0x0) {
              puVar16 = (uint64_t *)((long)param_2 + lVar1);
              uVar7 = VkObject_fromId(*puVar16);
              uVar11 = puVar16[1];
              *(uint64_t *)(puVar15 + -4) = uVar7;
              uVar7 = VkObject_fromId(uVar11);
              *(uint64_t *)(puVar15 + -2) = uVar7;
              *puVar15 = *(uint32_t *)(puVar16 + 2);
            }
            iVar13 = iVar2 + (int)lVar1;
            uVar14 = uVar14 - 1;
            puVar15 = puVar15 + 6;
          } while (uVar14 != 0);
          *(void **)(param_1 + 10) = pvVar8;
        }
        uVar4 = *(uint32_t *)((long)param_2 + (long)iVar13);
        uVar14 = (unsigned long)uVar4;
        iVar13 = iVar13 + 4;
        if ((int)uVar4 < 1) {
          *(uint64_t *)(param_1 + 0xc) = 0;
        }
        else {
          iVar6 = uVar4 * 0x18;
          iVar2 = (int)param_3[1] + iVar6;
          if ((iVar2 < 0x10000) && (*param_3 != 0)) {
            pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar2;
          }
          else {
            pvVar8 = malloc((long)iVar6);
            ArrayList_add(param_3 + 2,pvVar8);
          }
          memset(pvVar8,0,(long)iVar6);
          puVar16 = (uint64_t *)((long)pvVar8 + 0x10);
          do {
            iVar2 = *(int *)((long)param_2 + (long)iVar13);
            lVar1 = (long)iVar13 + 4;
            if (pvVar8 != (void *)0x0) {
              puVar10 = (uint64_t *)((long)param_2 + lVar1);
              uVar7 = VkObject_fromId(*puVar10);
              uVar11 = puVar10[1];
              puVar16[-2] = uVar7;
              puVar16[-1] = uVar11;
              *puVar16 = puVar10[2];
            }
            iVar13 = iVar2 + (int)lVar1;
            uVar14 = uVar14 - 1;
            puVar16 = puVar16 + 3;
          } while (uVar14 != 0);
          *(void **)(param_1 + 0xc) = pvVar8;
        }
        uVar4 = *(uint32_t *)((long)param_2 + (long)iVar13);
        if ((int)uVar4 < 1) {
          *(uint64_t *)(param_1 + 0xe) = 0;
        }
        else {
          iVar6 = uVar4 * 8;
          iVar2 = (int)param_3[1] + iVar6;
          if ((iVar2 < 0x10000) && (*param_3 != 0)) {
            pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar2;
          }
          else {
            pvVar8 = malloc((long)iVar6);
            ArrayList_add(param_3 + 2,pvVar8);
          }
          memset(pvVar8,0,(long)iVar6);
          uVar14 = 0;
          do {
            if (pvVar8 != (void *)0x0) {
              uVar7 = VkObject_fromId(*(uint64_t *)
                                       ((long)param_2 + uVar14 * 8 + (long)(iVar13 + 4)));
              *(uint64_t *)((long)pvVar8 + uVar14 * 8) = uVar7;
            }
            uVar14 = uVar14 + 1;
          } while (uVar4 != uVar14);
          *(void **)(param_1 + 0xe) = pvVar8;
        }
        return;
      }
      uVar14 = (unsigned long)(iVar13 + 4);
LAB_0014eb08:
      iVar13 = (int)uVar14;
      puVar10 = puVar16;
    }
    piVar9 = (int *)((long)param_2 + (long)iVar13);
    iVar13 = iVar13 + 4;
    puVar16 = puVar10;
  } while( true );
}








/* @0014eed0  size=632 */

void FUN_0014eed0(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  uint64_t *puVar8;
  void *__s;
  uint64_t uVar9;
  int iVar10;
  uint32_t *puVar11;
  int *piVar12;
  uint64_t *puVar13;
  uint64_t *puVar14;
  unsigned long uVar15;
  int iVar16;
  unsigned long uVar17;
  
  piVar12 = param_2 + 1;
  puVar14 = (uint64_t *)0x0;
  iVar10 = 8;
  *param_1 = *param_2;
  do {
    if (*piVar12 == 0x3b9cf898) {
      iVar16 = *(int *)((long)param_2 + (long)iVar10);
      uVar17 = (long)iVar10 + 4;
      if (iVar16 < 1) goto LAB_0014ef28;
      iVar10 = (int)param_3[1];
      if ((iVar10 < 0xffd8) && (*param_3 != 0)) {
        puVar8 = (uint64_t *)(*param_3 + (long)iVar10);
        *(int *)(param_3 + 1) = iVar10 + 0x28;
      }
      else {
        puVar8 = malloc(0x28);
        ArrayList_add(param_3 + 2,puVar8);
      }
      puVar8[4] = 0;
      puVar8[1] = 0;
      *puVar8 = 0;
      puVar8[3] = 0;
      puVar8[2] = 0;
      puVar2 = (uint32_t *)((long)param_2 + uVar17);
      uVar4 = *puVar2;
      puVar8[1] = 0;
      *(uint32_t *)puVar8 = uVar4;
      puVar8[2] = *(uint64_t *)(puVar2 + 1);
      *(uint32_t *)(puVar8 + 3) = puVar2[3];
      *(uint32_t *)((long)puVar8 + 0x1c) = puVar2[4];
      uVar5 = puVar2[5];
      uVar15 = (unsigned long)uVar5;
      if ((int)uVar5 < 1) {
        puVar8[4] = 0;
      }
      else {
        iVar7 = uVar5 * 8;
        iVar10 = (int)param_3[1] + iVar7;
        if ((iVar10 < 0x10000) && (*param_3 != 0)) {
          __s = (void *)(*param_3 + (long)(int)param_3[1]);
          *(int *)(param_3 + 1) = iVar10;
        }
        else {
          __s = malloc((long)iVar7);
          ArrayList_add(param_3 + 2,__s);
        }
        memset(__s,0,(long)iVar7);
        puVar11 = (uint32_t *)((long)__s + 4);
        iVar10 = 0x18;
        do {
          iVar7 = *(int *)((long)puVar2 + (long)iVar10);
          lVar1 = (long)iVar10 + 4;
          if (__s != (void *)0x0) {
            puVar3 = (uint32_t *)((long)puVar2 + lVar1);
            puVar11[-1] = *puVar3;
            *puVar11 = puVar3[1];
          }
          iVar10 = iVar7 + (int)lVar1;
          uVar15 = uVar15 - 1;
          puVar11 = puVar11 + 2;
        } while (uVar15 != 0);
        puVar8[4] = __s;
      }
      iVar16 = iVar16 + (int)uVar17;
      puVar8[1] = puVar14;
      puVar14 = puVar8;
    }
    else {
      if (*piVar12 == -1) {
        if (puVar14 == (uint64_t *)0x0) {
          puVar8 = (uint64_t *)0x0;
        }
        else {
          puVar13 = (uint64_t *)0x0;
          do {
            puVar8 = puVar14;
            puVar14 = (uint64_t *)puVar8[1];
            puVar8[1] = puVar13;
            puVar13 = puVar8;
          } while (puVar14 != (uint64_t *)0x0);
        }
        param_2 = (uint32_t *)((long)param_2 + (long)iVar10);
        uVar9 = *(uint64_t *)(param_2 + 6);
        param_1[4] = *param_2;
        uVar4 = param_2[1];
        *(uint64_t **)(param_1 + 2) = puVar8;
        param_1[5] = uVar4;
        uVar4 = param_2[4];
        param_1[6] = param_2[2];
        uVar6 = param_2[3];
        param_1[8] = uVar4;
        uVar4 = param_2[5];
        param_1[7] = uVar6;
        param_1[9] = uVar4;
        uVar9 = VkObject_fromId(uVar9);
        uVar4 = param_2[8];
        *(uint64_t *)(param_1 + 10) = uVar9;
        param_1[0xc] = uVar4;
        param_1[0xd] = param_2[9];
        param_1[0xe] = param_2[10];
        param_1[0xf] = param_2[0xb];
        param_1[0x10] = param_2[0xc];
        return;
      }
      uVar17 = (unsigned long)(iVar10 + 4);
LAB_0014ef28:
      iVar16 = (int)uVar17;
    }
    piVar12 = (int *)((long)param_2 + (long)iVar16);
    iVar10 = iVar16 + 4;
  } while( true );
}








/* @0014f148  size=2244 */

void FUN_0014f148(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  int iVar8;
  int iVar9;
  uint64_t *puVar10;
  uint64_t uVar11;
  void *pvVar12;
  void *pvVar13;
  int *piVar14;
  long lVar15;
  uint32_t *puVar16;
  uint64_t uVar17;
  uint32_t *puVar18;
  uint64_t *puVar19;
  int iVar20;
  unsigned long uVar21;
  uint64_t *puVar22;
  unsigned long uVar23;
  uint32_t *puVar24;
  int iVar25;
  
  puVar22 = (uint64_t *)0x0;
  piVar14 = param_2 + 1;
  iVar25 = 8;
  *param_1 = *param_2;
  do {
    iVar5 = *piVar14;
    if (iVar5 < 0x3b9c6fe3) {
      if (iVar5 == 0x3b9bb463) {
        iVar5 = *(int *)((long)param_2 + (long)iVar25);
        lVar15 = (long)iVar25 + 4;
        iVar25 = (int)lVar15;
        if (0 < iVar5) {
          iVar20 = (int)param_3[1];
          if ((iVar20 < 0xffe0) && (*param_3 != 0)) {
            puVar10 = (uint64_t *)(*param_3 + (long)iVar20);
            *(int *)(param_3 + 1) = iVar20 + 0x20;
          }
          else {
            puVar10 = malloc(0x20);
            ArrayList_add(param_3 + 2,puVar10);
          }
          puVar10[1] = 0;
          *puVar10 = 0;
          puVar10[3] = 0;
          puVar10[2] = 0;
          puVar2 = (uint32_t *)((long)param_2 + lVar15);
          uVar3 = *puVar2;
          uVar4 = puVar2[1];
          puVar10[1] = 0;
          *(uint32_t *)(puVar10 + 2) = uVar4;
          uVar4 = puVar2[2];
          *(uint32_t *)puVar10 = uVar3;
          *(uint32_t *)((long)puVar10 + 0x14) = uVar4;
          uVar6 = puVar2[3];
          uVar21 = (unsigned long)uVar6;
          if ((int)uVar6 < 1) {
            puVar10[3] = 0;
          }
          else {
            iVar8 = uVar6 * 0x10;
            iVar20 = (int)param_3[1] + iVar8;
            if ((iVar20 < 0x10000) && (*param_3 != 0)) {
              pvVar12 = (void *)(*param_3 + (long)(int)param_3[1]);
              *(int *)(param_3 + 1) = iVar20;
            }
            else {
              pvVar12 = malloc((long)iVar8);
              ArrayList_add(param_3 + 2,pvVar12);
            }
            memset(pvVar12,0,(long)iVar8);
            puVar16 = (uint32_t *)((long)pvVar12 + 8);
            iVar20 = 0x10;
            do {
              iVar8 = *(int *)((long)puVar2 + (long)iVar20);
              lVar15 = (long)iVar20 + 4;
              if (pvVar12 != (void *)0x0) {
                puVar18 = (uint32_t *)((long)puVar2 + lVar15);
                puVar16[-2] = *puVar18;
                puVar16[-1] = puVar18[1];
                *puVar16 = puVar18[2];
                puVar16[1] = puVar18[3];
              }
              iVar20 = iVar8 + (int)lVar15;
              uVar21 = uVar21 - 1;
              puVar16 = puVar16 + 4;
            } while (uVar21 != 0);
            puVar10[3] = pvVar12;
          }
          iVar25 = iVar5 + iVar25;
          goto LAB_0014f1b8;
        }
      }
      else {
        if (iVar5 == -1) {
          if (puVar22 == (uint64_t *)0x0) {
            puVar10 = (uint64_t *)0x0;
          }
          else {
            puVar19 = (uint64_t *)0x0;
            do {
              puVar10 = puVar22;
              puVar22 = (uint64_t *)puVar10[1];
              puVar10[1] = puVar19;
              puVar19 = puVar10;
            } while (puVar22 != (uint64_t *)0x0);
          }
          puVar22 = (uint64_t *)((long)param_2 + (long)iVar25);
          uVar11 = *puVar22;
          *(uint64_t **)(param_1 + 2) = puVar10;
          uVar11 = VkObject_fromId(uVar11);
          uVar17 = puVar22[1];
          *(uint64_t *)(param_1 + 4) = uVar11;
          uVar11 = VkObject_fromId(uVar17);
          uVar3 = *(uint32_t *)(puVar22 + 2);
          *(uint64_t *)(param_1 + 6) = uVar11;
          param_1[8] = uVar3;
          param_1[9] = *(uint32_t *)((long)puVar22 + 0x14);
          param_1[10] = *(uint32_t *)(puVar22 + 3);
          param_1[0xb] = *(uint32_t *)((long)puVar22 + 0x1c);
          param_1[0xc] = *(uint32_t *)(puVar22 + 4);
          uVar6 = *(uint32_t *)((long)puVar22 + 0x24);
          uVar21 = (unsigned long)uVar6;
          if ((int)uVar6 < 1) {
            *(uint64_t *)(param_1 + 0xe) = 0;
          }
          else {
            iVar20 = uVar6 * 0x10;
            iVar25 = iVar25 + 0x28;
            iVar5 = (int)param_3[1] + iVar20;
            if ((iVar5 < 0x10000) && (*param_3 != 0)) {
              puVar22 = (uint64_t *)(*param_3 + (long)(int)param_3[1]);
              *(int *)(param_3 + 1) = iVar5;
            }
            else {
              puVar22 = malloc((long)iVar20);
              ArrayList_add(param_3 + 2,puVar22);
            }
            memset(puVar22,0,(long)iVar20);
            puVar10 = puVar22;
            do {
              iVar5 = *(int *)((long)param_2 + (long)iVar25);
              lVar15 = (long)iVar25 + 4;
              if (puVar22 != (uint64_t *)0x0) {
                puVar19 = (uint64_t *)((long)param_2 + lVar15);
                uVar11 = *puVar19;
                puVar10[1] = puVar19[1];
                *puVar10 = uVar11;
              }
              iVar25 = iVar5 + (int)lVar15;
              uVar21 = uVar21 - 1;
              puVar10 = puVar10 + 2;
            } while (uVar21 != 0);
            *(uint64_t **)(param_1 + 0xe) = puVar22;
          }
          return;
        }
LAB_0014f2c4:
        uVar21 = (unsigned long)(iVar25 + 4);
LAB_0014f2c8:
        iVar25 = (int)uVar21;
      }
    }
    else if (iVar5 == 0x3b9c6fe3) {
      lVar15 = (long)iVar25;
      iVar25 = *(int *)((long)param_2 + lVar15);
      uVar21 = lVar15 + 4;
      if (iVar25 < 1) goto LAB_0014f2c8;
      iVar5 = (int)param_3[1];
      if ((iVar5 < 0xffe0) && (*param_3 != 0)) {
        puVar10 = (uint64_t *)(*param_3 + (long)iVar5);
        *(int *)(param_3 + 1) = iVar5 + 0x20;
      }
      else {
        puVar10 = malloc(0x20);
        ArrayList_add(param_3 + 2,puVar10);
      }
      puVar10[1] = 0;
      *puVar10 = 0;
      puVar10[3] = 0;
      puVar10[2] = 0;
      puVar2 = (uint32_t *)((long)param_2 + uVar21);
      uVar3 = *puVar2;
      uVar4 = puVar2[1];
      puVar10[1] = 0;
      *(uint32_t *)(puVar10 + 2) = uVar4;
      uVar6 = puVar2[2];
      *(uint32_t *)puVar10 = uVar3;
      if ((int)uVar6 < 1) {
        puVar10[3] = 0;
      }
      else {
        iVar20 = uVar6 * 8;
        iVar5 = (int)param_3[1] + iVar20;
        if ((iVar5 < 0x10000) && (*param_3 != 0)) {
          pvVar12 = (void *)(*param_3 + (long)(int)param_3[1]);
          *(int *)(param_3 + 1) = iVar5;
        }
        else {
          pvVar12 = malloc((long)iVar20);
          ArrayList_add(param_3 + 2,pvVar12);
        }
        memset(pvVar12,0,(long)iVar20);
        uVar23 = 0;
        do {
          if (pvVar12 != (void *)0x0) {
            uVar11 = VkObject_fromId(*(uint64_t *)((long)param_2 + uVar23 * 8 + lVar15 + 0x10));
            *(uint64_t *)((long)pvVar12 + uVar23 * 8) = uVar11;
          }
          uVar23 = uVar23 + 1;
        } while (uVar6 != uVar23);
        puVar10[3] = pvVar12;
      }
      iVar25 = iVar25 + (int)uVar21;
LAB_0014f1b8:
      puVar10[1] = puVar22;
      puVar22 = puVar10;
    }
    else {
      if (iVar5 != 0x3b9cf899) goto LAB_0014f2c4;
      iVar5 = *(int *)((long)param_2 + (long)iVar25);
      lVar15 = (long)iVar25 + 4;
      iVar25 = (int)lVar15;
      if (0 < iVar5) {
        iVar20 = (int)param_3[1];
        if ((iVar20 < 0xffd0) && (*param_3 != 0)) {
          puVar10 = (uint64_t *)(*param_3 + (long)iVar20);
          *(int *)(param_3 + 1) = iVar20 + 0x30;
        }
        else {
          puVar10 = malloc(0x30);
          ArrayList_add(param_3 + 2,puVar10);
        }
        puVar10[3] = 0;
        puVar10[2] = 0;
        puVar10[5] = 0;
        puVar10[4] = 0;
        puVar10[1] = 0;
        *puVar10 = 0;
        puVar2 = (uint32_t *)((long)param_2 + lVar15);
        uVar3 = *puVar2;
        uVar4 = puVar2[1];
        puVar10[1] = 0;
        *(uint32_t *)(puVar10 + 2) = uVar4;
        uVar6 = puVar2[2];
        *(uint32_t *)puVar10 = uVar3;
        if ((int)uVar6 < 1) {
          iVar20 = 0xc;
          puVar10[3] = 0;
        }
        else {
          iVar8 = uVar6 * 0x30;
          iVar20 = (int)param_3[1] + iVar8;
          if ((iVar20 < 0x10000) && (*param_3 != 0)) {
            pvVar12 = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar20;
          }
          else {
            pvVar12 = malloc((long)iVar8);
            ArrayList_add(param_3 + 2,pvVar12);
          }
          memset(pvVar12,0,(long)iVar8);
          uVar21 = 0;
          iVar20 = 0xc;
          do {
            iVar8 = *(int *)((long)puVar2 + (long)iVar20);
            lVar15 = (long)iVar20 + 4;
            if (pvVar12 != (void *)0x0) {
              puVar16 = (uint32_t *)((long)puVar2 + lVar15);
              puVar18 = (uint32_t *)((long)pvVar12 + uVar21 * 0x30);
              *puVar18 = *puVar16;
              puVar24 = puVar16 + 1;
              uVar3 = *puVar24;
              *(uint64_t *)(puVar18 + 4) = 0;
              puVar18[2] = uVar3;
              *(uint64_t *)(puVar18 + 6) = *(uint64_t *)(puVar16 + 2);
              puVar18[8] = puVar16[4];
              puVar18[9] = puVar16[5];
              uVar7 = puVar16[6];
              uVar23 = (unsigned long)uVar7;
              if ((int)uVar7 < 1) {
                *(uint64_t *)((long)pvVar12 + uVar21 * 0x30 + 0x28) = 0;
              }
              else {
                iVar9 = uVar7 * 8;
                iVar20 = (int)param_3[1] + iVar9;
                if ((iVar20 < 0x10000) && (*param_3 != 0)) {
                  pvVar13 = (void *)(*param_3 + (long)(int)param_3[1]);
                  *(int *)(param_3 + 1) = iVar20;
                }
                else {
                  pvVar13 = malloc((long)iVar9);
                  ArrayList_add(param_3 + 2,pvVar13);
                }
                memset(pvVar13,0,(long)iVar9);
                puVar16 = (uint32_t *)((long)pvVar13 + 4);
                iVar20 = 0x18;
                do {
                  iVar9 = *(int *)((long)puVar24 + (long)iVar20);
                  lVar1 = (long)iVar20 + 4;
                  if (pvVar13 != (void *)0x0) {
                    puVar18 = (uint32_t *)((long)puVar24 + lVar1);
                    puVar16[-1] = *puVar18;
                    *puVar16 = puVar18[1];
                  }
                  iVar20 = iVar9 + (int)lVar1;
                  uVar23 = uVar23 - 1;
                  puVar16 = puVar16 + 2;
                } while (uVar23 != 0);
                *(void **)((long)pvVar12 + uVar21 * 0x30 + 0x28) = pvVar13;
              }
            }
            uVar21 = uVar21 + 1;
            iVar20 = iVar8 + (int)lVar15;
          } while (uVar21 != uVar6);
          puVar10[3] = pvVar12;
        }
        *(uint32_t *)(puVar10 + 4) = *(uint32_t *)((long)puVar2 + (long)iVar20);
        uVar6 = ((uint32_t *)((long)puVar2 + (long)iVar20))[1];
        if ((int)uVar6 < 1) {
          puVar10[5] = 0;
        }
        else {
          iVar9 = uVar6 * 0x30;
          iVar8 = (int)param_3[1] + iVar9;
          if ((iVar8 < 0x10000) && (*param_3 != 0)) {
            pvVar12 = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar8;
          }
          else {
            pvVar12 = malloc((long)iVar9);
            ArrayList_add(param_3 + 2,pvVar12);
          }
          iVar20 = iVar20 + 8;
          memset(pvVar12,0,(long)iVar9);
          uVar21 = 0;
          do {
            iVar8 = *(int *)((long)puVar2 + (long)iVar20);
            lVar15 = (long)iVar20 + 4;
            if (pvVar12 != (void *)0x0) {
              puVar16 = (uint32_t *)((long)puVar2 + lVar15);
              puVar18 = (uint32_t *)((long)pvVar12 + uVar21 * 0x30);
              *puVar18 = *puVar16;
              puVar24 = puVar16 + 1;
              uVar3 = *puVar24;
              *(uint64_t *)(puVar18 + 4) = 0;
              puVar18[2] = uVar3;
              *(uint64_t *)(puVar18 + 6) = *(uint64_t *)(puVar16 + 2);
              puVar18[8] = puVar16[4];
              puVar18[9] = puVar16[5];
              uVar7 = puVar16[6];
              uVar23 = (unsigned long)uVar7;
              if ((int)uVar7 < 1) {
                *(uint64_t *)((long)pvVar12 + uVar21 * 0x30 + 0x28) = 0;
              }
              else {
                iVar9 = uVar7 * 8;
                iVar20 = (int)param_3[1] + iVar9;
                if ((iVar20 < 0x10000) && (*param_3 != 0)) {
                  pvVar13 = (void *)(*param_3 + (long)(int)param_3[1]);
                  *(int *)(param_3 + 1) = iVar20;
                }
                else {
                  pvVar13 = malloc((long)iVar9);
                  ArrayList_add(param_3 + 2,pvVar13);
                }
                memset(pvVar13,0,(long)iVar9);
                puVar16 = (uint32_t *)((long)pvVar13 + 4);
                iVar20 = 0x18;
                do {
                  iVar9 = *(int *)((long)puVar24 + (long)iVar20);
                  lVar1 = (long)iVar20 + 4;
                  if (pvVar13 != (void *)0x0) {
                    puVar18 = (uint32_t *)((long)puVar24 + lVar1);
                    puVar16[-1] = *puVar18;
                    *puVar16 = puVar18[1];
                  }
                  iVar20 = iVar9 + (int)lVar1;
                  uVar23 = uVar23 - 1;
                  puVar16 = puVar16 + 2;
                } while (uVar23 != 0);
                *(void **)((long)pvVar12 + uVar21 * 0x30 + 0x28) = pvVar13;
              }
            }
            uVar21 = uVar21 + 1;
            iVar20 = iVar8 + (int)lVar15;
          } while (uVar21 != uVar6);
          puVar10[5] = pvVar12;
        }
        puVar10[1] = puVar22;
        iVar25 = iVar5 + iVar25;
        puVar22 = puVar10;
      }
    }
    piVar14 = (int *)((long)param_2 + (long)iVar25);
    iVar25 = iVar25 + 4;
  } while( true );
}








/* @0014fa0c  size=1416 */

void FUN_0014fa0c(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  void *pvVar11;
  void *__s;
  uint64_t uVar12;
  uint32_t *puVar13;
  int iVar14;
  uint64_t *puVar15;
  int *piVar16;
  uint64_t *puVar17;
  uint64_t uVar18;
  unsigned long uVar19;
  unsigned long uVar20;
  int iVar21;
  unsigned long uVar22;
  uint64_t *puVar23;
  
  uVar5 = *param_2;
  uVar6 = param_2[1];
  *(uint64_t *)(param_1 + 2) = 0;
  param_1[4] = uVar6;
  uVar6 = param_2[2];
  *param_1 = uVar5;
  param_1[5] = uVar6;
  uVar7 = param_2[3];
  uVar19 = (unsigned long)uVar7;
  if ((int)uVar7 < 1) {
    iVar14 = 0x10;
    *(uint64_t *)(param_1 + 6) = 0;
  }
  else {
    iVar21 = uVar7 * 0x30;
    iVar14 = (int)param_3[1] + iVar21;
    if ((iVar14 < 0x10000) && (*param_3 != 0)) {
      pvVar11 = (void *)(*param_3 + (long)(int)param_3[1]);
      *(int *)(param_3 + 1) = iVar14;
    }
    else {
      pvVar11 = malloc((long)iVar21);
      ArrayList_add(param_3 + 2,pvVar11);
    }
    memset(pvVar11,0,(long)iVar21);
    puVar23 = (uint64_t *)((long)pvVar11 + 0x18);
    iVar14 = 0x10;
    do {
      iVar21 = *(int *)((long)param_2 + (long)iVar14);
      lVar1 = (long)iVar14 + 4;
      if (pvVar11 != (void *)0x0) {
        puVar3 = (uint32_t *)((long)param_2 + lVar1);
        uVar18 = *(uint64_t *)(puVar3 + 1);
        uVar5 = *puVar3;
        puVar23[-2] = 0;
        puVar23[-1] = uVar18;
        uVar18 = *(uint64_t *)(puVar3 + 3);
        *(uint32_t *)(puVar23 + -3) = uVar5;
        *puVar23 = uVar18;
        puVar23[1] = *(uint64_t *)(puVar3 + 5);
        puVar23[2] = *(uint64_t *)(puVar3 + 7);
      }
      iVar14 = iVar21 + (int)lVar1;
      uVar19 = uVar19 - 1;
      puVar23 = puVar23 + 6;
    } while (uVar19 != 0);
    *(void **)(param_1 + 6) = pvVar11;
  }
  iVar21 = iVar14 + 8;
  param_1[8] = *(uint32_t *)((long)param_2 + (long)iVar14);
  uVar7 = ((uint32_t *)((long)param_2 + (long)iVar14))[1];
  uVar19 = (unsigned long)uVar7;
  if ((int)uVar7 < 1) {
    *(uint64_t *)(param_1 + 10) = 0;
  }
  else {
    iVar9 = uVar7 * 0x50;
    iVar14 = (int)param_3[1] + iVar9;
    if ((iVar14 < 0x10000) && (*param_3 != 0)) {
      pvVar11 = (void *)(*param_3 + (long)(int)param_3[1]);
      *(int *)(param_3 + 1) = iVar14;
    }
    else {
      pvVar11 = malloc((long)iVar9);
      ArrayList_add(param_3 + 2,pvVar11);
    }
    memset(pvVar11,0,(long)iVar9);
    puVar23 = (uint64_t *)((long)pvVar11 + 0x28);
    do {
      iVar14 = *(int *)((long)param_2 + (long)iVar21);
      lVar1 = (long)iVar21 + 4;
      if (pvVar11 != (void *)0x0) {
        puVar3 = (uint32_t *)((long)param_2 + lVar1);
        uVar18 = *(uint64_t *)(puVar3 + 1);
        uVar5 = *puVar3;
        uVar6 = puVar3[9];
        puVar23[-4] = 0;
        puVar23[-3] = uVar18;
        uVar18 = *(uint64_t *)(puVar3 + 3);
        *(uint32_t *)(puVar23 + 1) = uVar6;
        *(uint32_t *)(puVar23 + -5) = uVar5;
        puVar23[-2] = uVar18;
        puVar23[-1] = *(uint64_t *)(puVar3 + 5);
        *puVar23 = *(uint64_t *)(puVar3 + 7);
        uVar18 = *(uint64_t *)(puVar3 + 0xb);
        *(uint32_t *)((long)puVar23 + 0xc) = puVar3[10];
        uVar18 = VkObject_fromId(uVar18);
        uVar12 = *(uint64_t *)(puVar3 + 0xd);
        puVar23[2] = uVar18;
        puVar23[3] = uVar12;
        puVar23[4] = *(uint64_t *)(puVar3 + 0xf);
      }
      iVar21 = iVar14 + (int)lVar1;
      uVar19 = uVar19 - 1;
      puVar23 = puVar23 + 10;
    } while (uVar19 != 0);
    *(void **)(param_1 + 10) = pvVar11;
  }
  param_1[0xc] = *(uint32_t *)((long)param_2 + (long)iVar21);
  uVar7 = ((uint32_t *)((long)param_2 + (long)iVar21))[1];
  if ((int)uVar7 < 1) {
    *(uint64_t *)(param_1 + 0xe) = 0;
    return;
  }
  iVar9 = uVar7 * 0x60;
  iVar21 = iVar21 + 8;
  iVar14 = (int)param_3[1] + iVar9;
  if ((iVar14 < 0x10000) && (*param_3 != 0)) {
    pvVar11 = (void *)(*param_3 + (long)(int)param_3[1]);
    *(int *)(param_3 + 1) = iVar14;
  }
  else {
    pvVar11 = malloc((long)iVar9);
    ArrayList_add(param_3 + 2,pvVar11);
  }
  memset(pvVar11,0,(long)iVar9);
  uVar19 = 0;
LAB_0014fd84:
  iVar14 = *(int *)((long)param_2 + (long)iVar21);
  lVar1 = (long)iVar21 + 4;
  if (pvVar11 != (void *)0x0) {
    piVar16 = (uint32_t *)((long)param_2 + lVar1) + 1;
    puVar23 = (uint64_t *)0x0;
    *(uint32_t *)((long)pvVar11 + uVar19 * 0x60) = *(uint32_t *)((long)param_2 + lVar1);
    iVar21 = 8;
    do {
      if (*piVar16 == 0x3b9cf898) {
        iVar9 = *(int *)((long)param_2 + iVar21 + lVar1);
        uVar22 = (long)iVar21 + 4;
        if (iVar9 < 1) goto LAB_0014fdc8;
        iVar21 = (int)param_3[1];
        if ((iVar21 < 0xffd8) && (*param_3 != 0)) {
          puVar15 = (uint64_t *)(*param_3 + (long)iVar21);
          *(int *)(param_3 + 1) = iVar21 + 0x28;
        }
        else {
          puVar15 = malloc(0x28);
          ArrayList_add(param_3 + 2,puVar15);
        }
        puVar15[4] = 0;
        puVar15[1] = 0;
        *puVar15 = 0;
        puVar15[3] = 0;
        puVar15[2] = 0;
        puVar3 = (uint32_t *)((long)param_2 + uVar22 + lVar1);
        uVar5 = *puVar3;
        puVar15[1] = 0;
        *(uint32_t *)puVar15 = uVar5;
        puVar15[2] = *(uint64_t *)(puVar3 + 1);
        *(uint32_t *)(puVar15 + 3) = puVar3[3];
        *(uint32_t *)((long)puVar15 + 0x1c) = puVar3[4];
        uVar8 = puVar3[5];
        uVar20 = (unsigned long)uVar8;
        if ((int)uVar8 < 1) {
          puVar15[4] = 0;
        }
        else {
          iVar10 = uVar8 * 8;
          iVar21 = (int)param_3[1] + iVar10;
          if ((iVar21 < 0x10000) && (*param_3 != 0)) {
            __s = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar21;
          }
          else {
            __s = malloc((long)iVar10);
            ArrayList_add(param_3 + 2,__s);
          }
          memset(__s,0,(long)iVar10);
          puVar13 = (uint32_t *)((long)__s + 4);
          iVar21 = 0x18;
          do {
            iVar10 = *(int *)((long)puVar3 + (long)iVar21);
            lVar2 = (long)iVar21 + 4;
            if (__s != (void *)0x0) {
              puVar4 = (uint32_t *)((long)puVar3 + lVar2);
              puVar13[-1] = *puVar4;
              *puVar13 = puVar4[1];
            }
            iVar21 = iVar10 + (int)lVar2;
            uVar20 = uVar20 - 1;
            puVar13 = puVar13 + 2;
          } while (uVar20 != 0);
          puVar15[4] = __s;
        }
        iVar21 = iVar9 + (int)uVar22;
        puVar15[1] = puVar23;
        puVar23 = puVar15;
      }
      else {
        if (*piVar16 == -1) goto LAB_0014ff44;
        uVar22 = (unsigned long)(iVar21 + 4);
LAB_0014fdc8:
        iVar21 = (int)uVar22;
      }
      piVar16 = (int *)((long)param_2 + iVar21 + lVar1);
      iVar21 = iVar21 + 4;
    } while( true );
  }
  goto LAB_0014fd74;
LAB_0014ff44:
  if (puVar23 == (uint64_t *)0x0) {
    puVar15 = (uint64_t *)0x0;
  }
  else {
    puVar17 = (uint64_t *)0x0;
    do {
      puVar15 = puVar23;
      puVar23 = (uint64_t *)puVar15[1];
      puVar15[1] = puVar17;
      puVar17 = puVar15;
    } while (puVar23 != (uint64_t *)0x0);
  }
  puVar23 = (uint64_t *)((long)param_2 + iVar21 + lVar1);
  *(uint64_t *)((long)pvVar11 + uVar19 * 0x60 + 0x10) = *puVar23;
  uVar18 = puVar23[1];
  *(uint64_t **)((long)pvVar11 + uVar19 * 0x60 + 8) = puVar15;
  uVar5 = *(uint32_t *)(puVar23 + 5);
  *(uint64_t *)((long)pvVar11 + uVar19 * 0x60 + 0x18) = uVar18;
  *(uint64_t *)((long)pvVar11 + uVar19 * 0x60 + 0x20) = puVar23[2];
  *(uint64_t *)((long)pvVar11 + uVar19 * 0x60 + 0x28) = puVar23[3];
  uVar18 = puVar23[6];
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x30) = *(uint32_t *)(puVar23 + 4);
  uVar6 = *(uint32_t *)((long)puVar23 + 0x24);
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x38) = uVar5;
  uVar5 = *(uint32_t *)((long)puVar23 + 0x2c);
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x34) = uVar6;
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x3c) = uVar5;
  uVar18 = VkObject_fromId(uVar18);
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x48) = *(uint32_t *)(puVar23 + 7);
  uVar5 = *(uint32_t *)((long)puVar23 + 0x3c);
  *(uint64_t *)((long)pvVar11 + uVar19 * 0x60 + 0x40) = uVar18;
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x4c) = uVar5;
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x50) = *(uint32_t *)(puVar23 + 8);
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x54) = *(uint32_t *)((long)puVar23 + 0x44);
  *(uint32_t *)((long)pvVar11 + uVar19 * 0x60 + 0x58) = *(uint32_t *)(puVar23 + 9);
LAB_0014fd74:
  uVar19 = uVar19 + 1;
  iVar21 = iVar14 + (int)lVar1;
  if (uVar19 == uVar7) {
    *(void **)(param_1 + 0xe) = pvVar11;
    return;
  }
  goto LAB_0014fd84;
}






/* STUB */
void FUN_001516f0(uint64_t param_1)
{ /* TODO */ }



/* STUB */
void FUN_0015bb70(uint64_t param_1,uint64_t param_2,uint64_t param_3,uint64_t param_4,
                 uint64_t param_5,uint64_t param_6,uint64_t param_7,uint64_t param_8)
{ /* TODO */ }



/* STUB */
unsigned long FUN_0015c2b8(long *param_1,uint64_t param_2,uint64_t param_3,uint8_t *param_4)
{ /* TODO */ }



/* STUB */
uint64_t FUN_0015c754(char *param_1)
{ /* TODO */ }



/* STUB */
uint64_t FUN_0015c88c(long param_1)
{ /* TODO */ }



/* STUB */
void FUN_0015eb34(uint64_t param_1,uint64_t param_2,uint64_t param_3,uint64_t param_4,
                 uint64_t param_5,uint64_t param_6,uint64_t param_7,uint64_t param_8)
{ /* TODO */ }





/* @0015ebd8  size=216 */

void * FUN_0015ebd8(char *param_1,void *param_2,size_t *param_3)

{
  FILE *__stream;
  size_t sVar1;
  
  __stream = fopen(param_1,"rb");
  if (__stream == (FILE *)0x0) {
    param_2 = (void *)0x0;
  }
  else if (param_2 == (void *)0x0) {
    fseek(__stream,0,2);
    sVar1 = ftell(__stream);
    fseek(__stream,0,0);
    param_2 = malloc(sVar1 + 1);
    fread(param_2,1,sVar1,__stream);
    *(uint8_t *)((long)param_2 + sVar1) = 0;
    fclose(__stream);
    if (param_3 != (size_t *)0x0) {
      *param_3 = sVar1;
    }
  }
  else {
    sVar1 = fread(param_2,1,*param_3,__stream);
    fclose(__stream);
    if (sVar1 != *param_3) {
      param_2 = (void *)0x0;
    }
  }
  return param_2;
}






/* STUB */
void FUN_0015ecb0(long *param_1)
{ /* TODO */ }



/* STUB */
void FUN_0015f21c(uint16_t *param_1,long param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,unsigned long param_8,uint8_t param_9)
{ /* TODO */ }



/* STUB */
void FUN_0015f470(unsigned long param_1,long param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,uint8_t param_9)
{ /* TODO */ }





/* @00160c08  size=176 */

void FUN_00160c08(long param_1,int *param_2,unsigned long param_3)

{
  size_t __n;
  void *__src;
  unsigned long uVar1;
  void *__dest;
  unsigned long uVar2;
  void *__src_00;
  size_t __n_00;
  
  __src = *(void **)(param_1 + 8);
  uVar1 = *(unsigned long *)(param_1 + 0x10);
  __src_00 = *(void **)(param_2 + 2);
  uVar2 = -(param_3 >> 0x1f & 1) & 0xfffffffc00000000 | (param_3 & 0xffffffff) << 2;
  __n_00 = (long)*param_2 * 4;
  __n = uVar1;
  if (uVar2 <= uVar1) {
    __n = uVar2;
  }
  __dest = malloc(uVar1 + __n_00);
  memcpy(__dest,__src,__n);
  memcpy((void *)((long)__dest + __n),__src_00,__n_00);
  memcpy((void *)((long)((long)__dest + __n) + __n_00),(void *)((long)__src + __n),uVar1 - __n);
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    free(*(void **)(param_1 + 8));
  }
  *(void **)(param_1 + 8) = __dest;
  *(unsigned long *)(param_1 + 0x10) = uVar1 + __n_00;
  IntArray_clear(param_2);
  return;
}








/* @00160cb8  size=1120 */

/* WARNING: Removing unreachable block (ram,0x00160d48) */
/* WARNING: Removing unreachable block (ram,0x00160fb0) */
/* WARNING: Removing unreachable block (ram,0x0016101c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff60 : 0x00160fbc */
/* WARNING: Removing unreachable block (ram,0x00161080) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_00160cb8(long *param_1,uint64_t param_2,uint32_t param_3,int param_4,int param_5,int param_6)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  uint32_t uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  uint32_t *puVar9;
  void *pvVar10;
  uint32_t uVar11;
  long lVar12;
  long lVar13;
  int iVar14;
  long lVar15;
  unsigned long uVar16;
  unsigned long uVar17;
  
  /* stack canary */
  lVar12 = *(long *)(lVar7 + 0x28);
  uVar2 = *(uint32_t *)((long)param_1 + 0x44);
  iVar14 = *(int *)((long)param_1 + 0x1c);
  uVar11 = uVar2;
  if ((int)(*(uint32_t *)(param_1 + 1) >> 2) <= (int)uVar2 || (int)uVar2 < 1) {
    uVar11 = *(uint32_t *)(param_1 + 1) >> 2;
  }
  if (iVar14 < (int)uVar11) {
    lVar13 = *param_1;
    do {
      uVar5 = *(uint32_t *)(lVar13 + (long)iVar14 * 4);
      uVar1 = uVar5 & 0xffff;
      uVar5 = uVar5 >> 0x10;
      if (uVar1 == param_3) {
        uVar3 = *(uint32_t *)(param_1 + 8);
        if (uVar3 < uVar5) {
          if (0 < (int)uVar3) {
            uVar16 = 0;
            do {
              lVar15 = uVar16 * 4;
              iVar4 = *(int *)((long)param_1 + uVar16 * 4 + 0x30);
              uVar16 = uVar16 + 1;
              iVar6 = *(int *)(lVar13 + (unsigned long)(uint32_t)(*(int *)((long)param_1 + lVar15 + 0x20) +
                                                     iVar14) * 4);
              if (uVar3 <= uVar16) break;
            } while (iVar6 == iVar4);
            if (iVar6 != iVar4) goto LAB_00160de0;
          }
          if (iVar14 != -1) {
            lVar13 = lVar13 + (long)iVar14 * 4;
            uVar11 = (uint32_t)*(uint16_t *)(lVar13 + 2) + iVar14;
            iVar14 = *(int *)(lVar13 + 4);
            if (iVar14 != 0) goto LAB_001610e0;
            goto LAB_00160ef4;
          }
          break;
        }
      }
LAB_00160de0:
      iVar14 = uVar5 + iVar14;
      if (((int)uVar11 <= iVar14) || (uVar1 == 0x36)) break;
    } while( true );
  }
  uVar11 = *(uint32_t *)param_1[2];
  if (0 < (int)uVar11) {
    lVar13 = *(long *)((uint32_t *)param_1[2] + 2);
    uVar16 = 0;
    do {
      lVar15 = *(long *)(lVar13 + uVar16 * 8);
      *(uint32_t *)((long)param_1 + 0x44) = 0;
      uVar1 = *(uint32_t *)(lVar15 + 8) & 0x3fffffff;
      if (uVar1 != 0) {
        lVar15 = *(long *)(lVar15 + 0x10);
        iVar14 = 0;
        do {
          uVar5 = *(uint32_t *)(lVar15 + (long)iVar14 * 4);
          uVar3 = uVar5 >> 0x10;
          if (param_3 == (uVar5 & 0xffff)) {
            uVar5 = *(uint32_t *)(param_1 + 8);
            if (uVar5 < uVar3) {
              if (0 < (int)uVar5) {
                uVar17 = 0;
                do {
                  lVar8 = uVar17 * 4;
                  iVar4 = *(int *)((long)param_1 + uVar17 * 4 + 0x30);
                  uVar17 = uVar17 + 1;
                  iVar6 = *(int *)(lVar15 + (unsigned long)(uint32_t)(*(int *)((long)param_1 + lVar8 + 0x20) +
                                                         iVar14) * 4);
                  if (uVar5 <= uVar17) break;
                } while (iVar6 == iVar4);
                if (iVar6 != iVar4) goto LAB_00160e70;
              }
              *(uint32_t *)((long)param_1 + 0x44) = uVar2;
              if (iVar14 == -1) goto LAB_00160e3c;
              uVar11 = ~(uint32_t)uVar16;
              iVar14 = *(int *)(lVar15 + (long)iVar14 * 4 + 4);
              if (iVar14 == 0) goto LAB_00160ef4;
              goto LAB_001610e0;
            }
          }
LAB_00160e70:
          iVar14 = uVar3 + iVar14;
        } while (iVar14 < (int)uVar1);
      }
      *(uint32_t *)((long)param_1 + 0x44) = uVar2;
LAB_00160e3c:
      uVar16 = uVar16 + 1;
    } while (uVar16 != uVar11);
  }
LAB_00160ef4:
  uVar2 = *(uint32_t *)(param_1 + 3);
  uVar11 = ~uVar2;
  if ((int)uVar2 < 0) {
    puVar9 = *(uint32_t **)(*(long *)(param_1[2] + 8) + (long)(int)uVar11 * 8);
  }
  else {
    puVar9 = calloc(1,0x18);
  }
  iVar14 = puVar9[2];
  uVar5 = puVar9[3];
  uVar1 = iVar14 + 4;
  if (uVar5 < uVar1) {
    uVar3 = 4;
    if (3 < (int)uVar5) {
      uVar3 = uVar5 + ((int)uVar5 >> 1);
    }
    if (uVar1 <= uVar3) {
      uVar1 = uVar3;
    }
    pvVar10 = realloc(*(void **)(puVar9 + 4),
                      -(unsigned long)(uVar1 >> 0x1f) & 0xfffffffc00000000 | (unsigned long)uVar1 << 2);
    *(void **)(puVar9 + 4) = pvVar10;
    uVar5 = uVar1 - puVar9[3];
    memset((void *)((long)pvVar10 + (long)(int)puVar9[3] * 4),0,
           -(unsigned long)(uVar5 >> 0x1f) & 0xfffffffc00000000 | (unsigned long)uVar5 << 2);
    iVar14 = puVar9[2];
    puVar9[3] = uVar1;
  }
  puVar9[2] = iVar14 + 1;
  *(uint32_t *)(*(long *)(puVar9 + 4) + (long)iVar14 * 4) = param_3 | 0x40000;
  if (param_4 == -1) {
    iVar14 = *(int *)(*param_1 + 0xc);
    *(int *)(*param_1 + 0xc) = iVar14 + 1;
    param_4 = iVar14;
  }
  else {
    iVar14 = 0;
  }
  iVar4 = puVar9[2];
  puVar9[2] = iVar4 + 1;
  *(int *)(*(long *)(puVar9 + 4) + (long)iVar4 * 4) = param_4;
  if (param_5 == -1) {
    iVar14 = *(int *)(*param_1 + 0xc);
    *(int *)(*param_1 + 0xc) = iVar14 + 1;
    param_5 = iVar14;
  }
  iVar4 = puVar9[2];
  puVar9[2] = iVar4 + 1;
  *(int *)(*(long *)(puVar9 + 4) + (long)iVar4 * 4) = param_5;
  if (param_6 == -1) {
    iVar14 = *(int *)(*param_1 + 0xc);
    *(int *)(*param_1 + 0xc) = iVar14 + 1;
    param_6 = iVar14;
  }
  iVar4 = puVar9[2];
  puVar9[2] = iVar4 + 1;
  *(int *)(*(long *)(puVar9 + 4) + (long)iVar4 * 4) = param_6;
  if (-1 < (int)uVar2) {
    *puVar9 = (int)param_1[3];
    uVar11 = *(uint32_t *)param_1[2];
    ArrayList_add((uint32_t *)param_1[2],puVar9);
  }
  uVar11 = ~uVar11;
LAB_001610e0:
  *(uint32_t *)(param_1 + 3) = uVar11;
  if (*(long *)(lVar7 + 0x28) == lVar12) {
    return iVar14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}






/* STUB */
void FUN_00161118(long param_1,unsigned long param_2,uint64_t param_3)
{ /* TODO */ }



/* STUB */
void FUN_001614b4(uint64_t param_1,uint64_t param_2,uint64_t param_3,uint64_t param_4,
                 uint64_t param_5,uint64_t param_6,uint64_t param_7,uint64_t param_8)
{ /* TODO */ }



/* STUB */
void FUN_00163868(uint64_t *param_1)
{ /* TODO */ }





/* @00163adc  size=1460 */

void FUN_00163adc(uint32_t *param_1,uint32_t *param_2,long *param_3)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  uint32_t uVar5;
  long lVar6;
  uint64_t *puVar7;
  void *pvVar8;
  int iVar9;
  int *piVar10;
  uint64_t uVar11;
  uint64_t *puVar12;
  unsigned long uVar13;
  unsigned long uVar14;
  size_t __size;
  uint64_t *puVar15;
  
  piVar10 = param_2 + 1;
  puVar15 = (uint64_t *)0x0;
  iVar9 = 8;
  *param_1 = *param_2;
  do {
    iVar4 = *piVar10;
    if (iVar4 < 0x3b9e38e9) {
      if (iVar4 == 0x10) {
        iVar4 = *(int *)((long)param_2 + (long)iVar9);
        uVar13 = (long)iVar9 + 4;
        if (iVar4 < 1) {
          uVar13 = uVar13 & 0xffffffff;
        }
        else {
          iVar9 = (int)param_3[1];
          if ((iVar9 < 0xffd8) && (*param_3 != 0)) {
            puVar7 = (uint64_t *)(*param_3 + (long)iVar9);
            *(int *)(param_3 + 1) = iVar9 + 0x28;
          }
          else {
            puVar7 = malloc(0x28);
            ArrayList_add(param_3 + 2,puVar7);
          }
          puVar7[4] = 0;
          puVar7[1] = 0;
          *puVar7 = 0;
          puVar7[3] = 0;
          puVar7[2] = 0;
          puVar1 = (uint32_t *)((long)param_2 + uVar13);
          uVar2 = *puVar1;
          uVar3 = puVar1[1];
          uVar11 = *(uint64_t *)(puVar1 + 2);
          puVar7[1] = 0;
          *(uint32_t *)(puVar7 + 2) = uVar3;
          iVar9 = puVar1[4];
          __size = (size_t)iVar9;
          lVar6 = param_3[1];
          *(uint32_t *)puVar7 = uVar2;
          puVar7[3] = uVar11;
          iVar9 = (int)lVar6 + iVar9;
          if ((iVar9 < 0x10000) && (*param_3 != 0)) {
            pvVar8 = (void *)(*param_3 + (long)(int)lVar6);
            *(int *)(param_3 + 1) = iVar9;
          }
          else {
            pvVar8 = malloc(__size);
            ArrayList_add(param_3 + 2,pvVar8);
          }
          memset(pvVar8,0,__size);
          memcpy(pvVar8,puVar1 + 5,__size);
          puVar7[4] = pvVar8;
          uVar5 = iVar4 + (int)uVar13;
LAB_00163b40:
          uVar13 = (unsigned long)uVar5;
          puVar7[1] = puVar15;
          puVar15 = puVar7;
        }
      }
      else {
        if (iVar4 == -1) {
          if (puVar15 == (uint64_t *)0x0) {
            puVar7 = (uint64_t *)0x0;
          }
          else {
            puVar12 = (uint64_t *)0x0;
            do {
              puVar7 = puVar15;
              puVar15 = (uint64_t *)puVar7[1];
              puVar7[1] = puVar12;
              puVar12 = puVar7;
            } while (puVar15 != (uint64_t *)0x0);
          }
          puVar1 = (uint32_t *)((long)param_2 + (long)iVar9);
          uVar2 = *puVar1;
          *(uint64_t **)(param_1 + 2) = puVar7;
          uVar11 = *(uint64_t *)(puVar1 + 2);
          param_1[4] = uVar2;
          param_1[5] = puVar1[1];
          uVar11 = VkObject_fromId(uVar11);
          uVar5 = puVar1[4];
          uVar14 = (unsigned long)uVar5;
          uVar13 = (long)iVar9 + 0x14;
          *(uint64_t *)(param_1 + 6) = uVar11;
          if (0 < (int)uVar5) {
            iVar9 = (int)param_3[1] + uVar5;
            if ((iVar9 < 0x10000) && (*param_3 != 0)) {
              pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
              *(int *)(param_3 + 1) = iVar9;
            }
            else {
              pvVar8 = malloc(uVar14);
              ArrayList_add(param_3 + 2,pvVar8);
            }
            memset(pvVar8,0,uVar14);
            memcpy(pvVar8,(void *)((long)param_2 + uVar13),uVar14);
            uVar13 = (unsigned long)(uVar5 + (int)uVar13);
            *(void **)(param_1 + 8) = pvVar8;
          }
          if (*(int *)((long)param_2 + (long)(int)uVar13) < 1) {
            *(uint64_t *)(param_1 + 10) = 0;
          }
          else {
            iVar9 = (int)param_3[1];
            if ((iVar9 < 0xffe0) && (*param_3 != 0)) {
              puVar15 = (uint64_t *)(*param_3 + (long)iVar9);
              *(int *)(param_3 + 1) = iVar9 + 0x20;
            }
            else {
              puVar15 = malloc(0x20);
              ArrayList_add(param_3 + 2,puVar15);
            }
            puVar15[1] = 0;
            *puVar15 = 0;
            puVar15[3] = 0;
            puVar15[2] = 0;
            param_2 = (uint32_t *)((long)param_2 + (long)(int)uVar13 + 4);
            uVar2 = *param_2;
            *(uint64_t **)(param_1 + 10) = puVar15;
            *(uint32_t *)puVar15 = uVar2;
            uVar5 = param_2[1];
            uVar13 = (unsigned long)uVar5;
            if ((int)uVar5 < 1) {
              iVar9 = 8;
              puVar15[1] = 0;
            }
            else {
              iVar4 = uVar5 * 0x10;
              iVar9 = (int)param_3[1] + iVar4;
              if ((iVar9 < 0x10000) && (*param_3 != 0)) {
                pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
                *(int *)(param_3 + 1) = iVar9;
              }
              else {
                pvVar8 = malloc((long)iVar4);
                ArrayList_add(param_3 + 2,pvVar8);
              }
              memset(pvVar8,0,(long)iVar4);
              puVar7 = (uint64_t *)((long)pvVar8 + 8);
              iVar9 = 8;
              do {
                iVar4 = *(int *)((long)param_2 + (long)iVar9);
                lVar6 = (long)iVar9 + 4;
                if (pvVar8 != (void *)0x0) {
                  puVar1 = (uint32_t *)((long)param_2 + lVar6);
                  *(uint32_t *)(puVar7 + -1) = *puVar1;
                  uVar11 = *(uint64_t *)(puVar1 + 2);
                  *(uint32_t *)((long)puVar7 + -4) = puVar1[1];
                  *puVar7 = uVar11;
                }
                iVar9 = iVar4 + (int)lVar6;
                uVar13 = uVar13 - 1;
                puVar7 = puVar7 + 2;
              } while (uVar13 != 0);
              puVar15[1] = pvVar8;
            }
            puVar7 = (uint64_t *)((long)param_2 + (long)iVar9);
            uVar5 = *(uint32_t *)(puVar7 + 1);
            uVar13 = (unsigned long)uVar5;
            puVar15[2] = *puVar7;
            if ((int)uVar5 < 1) {
              puVar15[3] = 0;
            }
            else {
              iVar4 = (int)param_3[1] + uVar5;
              if ((iVar4 < 0x10000) && (*param_3 != 0)) {
                pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
                *(int *)(param_3 + 1) = iVar4;
              }
              else {
                pvVar8 = malloc(uVar13);
                ArrayList_add(param_3 + 2,pvVar8);
              }
              memset(pvVar8,0,uVar13);
              puVar15[3] = pvVar8;
              memcpy(pvVar8,(void *)((long)param_2 + (long)iVar9 + 0xc),uVar13);
            }
          }
          return;
        }
LAB_00163c40:
        uVar13 = (unsigned long)(iVar9 + 4);
      }
    }
    else if (iVar4 == 0x3b9e38e9) {
      iVar4 = *(int *)((long)param_2 + (long)iVar9);
      uVar13 = (long)iVar9 + 4;
      if (0 < iVar4) {
        iVar9 = (int)param_3[1];
        if ((iVar9 < 0xffe8) && (*param_3 != 0)) {
          puVar7 = (uint64_t *)(*param_3 + (long)iVar9);
          *(int *)(param_3 + 1) = iVar9 + 0x18;
        }
        else {
          puVar7 = malloc(0x18);
          ArrayList_add(param_3 + 2,puVar7);
        }
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        uVar2 = *(uint32_t *)((long)param_2 + uVar13);
        uVar3 = ((uint32_t *)((long)param_2 + uVar13))[1];
        uVar13 = (unsigned long)(uint32_t)(iVar4 + (int)uVar13);
        puVar7[1] = puVar15;
        *(uint32_t *)puVar7 = uVar2;
        *(uint32_t *)(puVar7 + 2) = uVar3;
        puVar15 = puVar7;
      }
    }
    else {
      if (iVar4 != 0x3ba1d6b2) goto LAB_00163c40;
      iVar4 = *(int *)((long)param_2 + (long)iVar9);
      uVar13 = (long)iVar9 + 4;
      if (0 < iVar4) {
        iVar9 = (int)param_3[1];
        if ((iVar9 < 0xffe0) && (*param_3 != 0)) {
          puVar7 = (uint64_t *)(*param_3 + (long)iVar9);
          *(int *)(param_3 + 1) = iVar9 + 0x20;
        }
        else {
          puVar7 = malloc(0x20);
          ArrayList_add(param_3 + 2,puVar7);
        }
        puVar7[1] = 0;
        *puVar7 = 0;
        puVar7[3] = 0;
        puVar7[2] = 0;
        puVar1 = (uint32_t *)((long)param_2 + uVar13);
        uVar2 = *puVar1;
        uVar3 = puVar1[1];
        puVar7[1] = 0;
        *(uint32_t *)(puVar7 + 2) = uVar3;
        uVar5 = puVar1[2];
        uVar14 = (unsigned long)uVar5;
        *(uint32_t *)puVar7 = uVar2;
        if ((int)uVar5 < 1) {
          pvVar8 = (void *)0x0;
        }
        else {
          iVar9 = (int)param_3[1] + uVar5;
          if ((iVar9 < 0x10000) && (*param_3 != 0)) {
            pvVar8 = (void *)(*param_3 + (long)(int)param_3[1]);
            *(int *)(param_3 + 1) = iVar9;
          }
          else {
            pvVar8 = malloc(uVar14);
            ArrayList_add(param_3 + 2,pvVar8);
          }
          memset(pvVar8,0,uVar14);
          if (pvVar8 != (void *)0x0) {
            memcpy(pvVar8,puVar1 + 3,uVar14);
          }
        }
        uVar5 = iVar4 + (int)uVar13;
        puVar7[3] = pvVar8;
        goto LAB_00163b40;
      }
    }
    piVar10 = (int *)((long)param_2 + (long)(int)uVar13);
    iVar9 = (int)uVar13 + 4;
  } while( true );
}






/* STUB */
void FUN_001641ec(uint32_t *param_1)
{ /* TODO */ }





/* @00164884  size=208 */

int FUN_00164884(void)

{
  long lVar1;
  int iVar2;
  int local_8c;
  int local_84;
  char local_80 [104];
  long local_18;
  
  /* stack canary */
  local_18 = *(long *)(lVar1 + 0x28);
  local_80[0x54] = '\0';
  local_80[0x55] = '\0';
  local_80[0x56] = '\0';
  local_80[0x57] = '\0';
  local_80[0x58] = '\0';
  local_80[0x59] = '\0';
  local_80[0x5a] = '\0';
  local_80[0x5b] = '\0';
  local_80[0x50] = '\0';
  local_80[0x51] = '\0';
  local_80[0x52] = '\0';
  local_80[0x53] = '\0';
  local_80[0x48] = '\0';
  local_80[0x49] = '\0';
  local_80[0x4a] = '\0';
  local_80[0x4b] = '\0';
  local_80[0x4c] = '\0';
  local_80[0x4d] = '\0';
  local_80[0x4e] = '\0';
  local_80[0x4f] = '\0';
  local_80[0x40] = '\0';
  local_80[0x41] = '\0';
  local_80[0x42] = '\0';
  local_80[0x43] = '\0';
  local_80[0x44] = '\0';
  local_80[0x45] = '\0';
  local_80[0x46] = '\0';
  local_80[0x47] = '\0';
  local_80[0x38] = '\0';
  local_80[0x39] = '\0';
  local_80[0x3a] = '\0';
  local_80[0x3b] = '\0';
  local_80[0x3c] = '\0';
  local_80[0x3d] = '\0';
  local_80[0x3e] = '\0';
  local_80[0x3f] = '\0';
  local_80[0x30] = '\0';
  local_80[0x31] = '\0';
  local_80[0x32] = '\0';
  local_80[0x33] = '\0';
  local_80[0x34] = '\0';
  local_80[0x35] = '\0';
  local_80[0x36] = '\0';
  local_80[0x37] = '\0';
  local_80[0x28] = '\0';
  local_80[0x29] = '\0';
  local_80[0x2a] = '\0';
  local_80[0x2b] = '\0';
  local_80[0x2c] = '\0';
  local_80[0x2d] = '\0';
  local_80[0x2e] = '\0';
  local_80[0x2f] = '\0';
  local_80[0x20] = '\0';
  local_80[0x21] = '\0';
  local_80[0x22] = '\0';
  local_80[0x23] = '\0';
  local_80[0x24] = '\0';
  local_80[0x25] = '\0';
  local_80[0x26] = '\0';
  local_80[0x27] = '\0';
  local_80[0x18] = '\0';
  local_80[0x19] = '\0';
  local_80[0x1a] = '\0';
  local_80[0x1b] = '\0';
  local_80[0x1c] = '\0';
  local_80[0x1d] = '\0';
  local_80[0x1e] = '\0';
  local_80[0x1f] = '\0';
  local_80[0x10] = '\0';
  local_80[0x11] = '\0';
  local_80[0x12] = '\0';
  local_80[0x13] = '\0';
  local_80[0x14] = '\0';
  local_80[0x15] = '\0';
  local_80[0x16] = '\0';
  local_80[0x17] = '\0';
  local_80[8] = '\0';
  local_80[9] = '\0';
  local_80[10] = '\0';
  local_80[0xb] = '\0';
  local_80[0xc] = '\0';
  local_80[0xd] = '\0';
  local_80[0xe] = '\0';
  local_80[0xf] = '\0';
  local_80[0] = '\0';
  local_80[1] = '\0';
  local_80[2] = '\0';
  local_80[3] = '\0';
  local_80[4] = '\0';
  local_80[5] = '\0';
  local_80[6] = '\0';
  local_80[7] = '\0';
  iVar2 = __system_property_get("ro.build.version.sdk",local_80);
  if (iVar2 < 1) {
    local_84 = -1;
  }
  else {
    local_8c = atoi(local_80);
    if (local_8c < 1) {
      local_8c = -1;
    }
    local_84 = local_8c;
  }
  /* stack canary */
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar1);
  }
  return local_84;
}






/* STUB */
void FUN_00164954(void)
{ /* TODO */ }





/* @00164a14  size=36 */

void FUN_00164a14(uint64_t param_1)

{
  FUN_00165398(param_1);
  return;
}








/* @00164a38  size=120 */

uint64_t * FUN_00164a38(uint64_t *param_1)

{
  uint64_t *local_18;
  
  if ((*(uint32_t *)*param_1 >> 2 & 1) == 0) {
    local_18 = (uint64_t *)0x0;
  }
  else {
    local_18 = malloc(0x20);
    local_18[1] = 0;
    *local_18 = 0;
    local_18[3] = 0;
    local_18[2] = 0;
    **(uint64_t **)param_1[1] = local_18;
  }
  return local_18;
}






/* STUB */
FUN_00165224(param_1)
{ /* TODO */ }





/* @00165238  size=20 */

void FUN_00165238(void)

{
  return;
}








/* @0016524c  size=40 */

void FUN_0016524c(uint64_t param_1)

{
  FUN_00165274(param_1);
  return;
}








/* STUB: FUN_00165274 skipped */
void FUN_00165274(void) { /* TODO */ }

/* STUB: FUN_00165284 skipped */
void FUN_00165284(void) { /* TODO */ }

/* STUB: FUN_00165298 skipped */
void FUN_00165298(void) { /* TODO */ }

/* STUB: FUN_001652e4 skipped */
void FUN_001652e4(void) { /* TODO */ }

/* STUB: FUN_001652f8 skipped */
void FUN_001652f8(void) { /* TODO */ }

/* STUB: FUN_00165360 skipped */
void FUN_00165360(void) { /* TODO */ }

/* STUB: FUN_00165384 skipped */
void FUN_00165384(void) { /* TODO */ }

/* STUB: FUN_00165398 skipped */
void FUN_00165398(void) { /* TODO */ }

/* STUB: FUN_001653c0 skipped */
void FUN_001653c0(void) { /* TODO */ }

/* STUB: FUN_001653d4 skipped */
void FUN_001653d4(void) { /* TODO */ }

/* STUB: FUN_00165428 skipped */
void FUN_00165428(void) { /* TODO */ }

/* STUB: FUN_0016545c skipped */
void FUN_0016545c(void) { /* TODO */ }

/* STUB: FUN_00165484 skipped */
void FUN_00165484(void) { /* TODO */ }

/* STUB: FUN_001654b0 skipped */
void FUN_001654b0(void) { /* TODO */ }

/* STUB: FUN_001654d4 skipped */
void FUN_001654d4(void) { /* TODO */ }

/* STUB: FUN_001654e8 skipped */
void FUN_001654e8(void) { /* TODO */ }

/* STUB: FUN_0016550c skipped */
void FUN_0016550c(void) { /* TODO */ }

/* STUB: FUN_00165904 skipped */
void FUN_00165904(void) { /* TODO */ }

/* STUB: FUN_00165a2c skipped */
void FUN_00165a2c(void) { /* TODO */ }

/* STUB: FUN_00165b28 skipped */
void FUN_00165b28(void) { /* TODO */ }

/* STUB: FUN_00165b3c skipped */
void FUN_00165b3c(void) { /* TODO */ }

/* STUB: FUN_00165b50 skipped */
void FUN_00165b50(void) { /* TODO */ }

/* STUB: FUN_00165b64 skipped */
void FUN_00165b64(void) { /* TODO */ }

/* STUB: FUN_00165d1c skipped */
void FUN_00165d1c(void) { /* TODO */ }

/* STUB: FUN_00165dec skipped */
void FUN_00165dec(void) { /* TODO */ }

/* STUB: FUN_00165e7c skipped */
void FUN_00165e7c(void) { /* TODO */ }

/* STUB: FUN_00165ebc skipped */
void FUN_00165ebc(void) { /* TODO */ }

/* STUB: FUN_00166340 skipped */
void FUN_00166340(void) { /* TODO */ }

/* STUB: FUN_00166524 skipped */
void FUN_00166524(void) { /* TODO */ }

/* STUB: FUN_00166590 skipped */
void FUN_00166590(void) { /* TODO */ }

/* STUB: FUN_0016e1cc skipped */
void FUN_0016e1cc(void) { /* TODO */ }

/* STUB: FUN_0016e204 skipped */
void FUN_0016e204(void) { /* TODO */ }

/* STUB: FUN_0016e23c skipped */
void FUN_0016e23c(void) { /* TODO */ }

/* STUB: FUN_0016e810 skipped */
void FUN_0016e810(void) { /* TODO */ }

/* STUB: FUN_0016ec34 skipped */
void FUN_0016ec34(void) { /* TODO */ }

/* STUB: FUN_0016ec40 skipped */
void FUN_0016ec40(void) { /* TODO */ }

/* STUB: FUN_0016ec4c skipped */
void FUN_0016ec4c(void) { /* TODO */ }

/* STUB: FUN_0016edac skipped */
void FUN_0016edac(void) { /* TODO */ }

/* STUB: FUN_0016edc8 skipped */
void FUN_0016edc8(void) { /* TODO */ }

/* STUB: FUN_0016ee30 skipped */
void FUN_0016ee30(void) { /* TODO */ }

/* STUB: FUN_0016f348 skipped */
void FUN_0016f348(void) { /* TODO */ }

/* STUB: FUN_0016f708 skipped */
void FUN_0016f708(void) { /* TODO */ }

/* STUB: FUN_0016f854 skipped */
void FUN_0016f854(void) { /* TODO */ }

/* STUB: FUN_0016f8a0 skipped */
void FUN_0016f8a0(void) { /* TODO */ }

/* STUB: FUN_0016f91c skipped */
void FUN_0016f91c(void) { /* TODO */ }

/* STUB: FUN_0016fa3c skipped */
void FUN_0016fa3c(void) { /* TODO */ }

/* STUB: FUN_00170170 skipped */
void FUN_00170170(void) { /* TODO */ }

/* STUB: FUN_00170240 skipped */
void FUN_00170240(void) { /* TODO */ }

/* STUB: FUN_00170af4 skipped */
void FUN_00170af4(void) { /* TODO */ }

/* STUB: FUN_00170b9c skipped */
void FUN_00170b9c(void) { /* TODO */ }

/* STUB: FUN_00171b14 skipped */
void FUN_00171b14(void) { /* TODO */ }

/* STUB: FUN_001726d4 skipped */
void FUN_001726d4(void) { /* TODO */ }

/* STUB: FUN_001728c4 skipped */
void FUN_001728c4(void) { /* TODO */ }

/* STUB: FUN_00172988 skipped */
void FUN_00172988(void) { /* TODO */ }

/* STUB: FUN_00172a18 skipped */
void FUN_00172a18(void) { /* TODO */ }

/* STUB: FUN_00172af0 skipped */
void FUN_00172af0(void) { /* TODO */ }

/* STUB: FUN_00172b90 skipped */
void FUN_00172b90(void) { /* TODO */ }

/* STUB: FUN_00172c30 skipped */
void FUN_00172c30(void) { /* TODO */ }

/* STUB: FUN_00172cd0 skipped */
void FUN_00172cd0(void) { /* TODO */ }

/* STUB: FUN_00172d70 skipped */
void FUN_00172d70(void) { /* TODO */ }

/* STUB: FUN_00172f4c skipped */
void FUN_00172f4c(void) { /* TODO */ }

/* STUB: FUN_00172fec skipped */
void FUN_00172fec(void) { /* TODO */ }

/* STUB: FUN_00173084 skipped */
void FUN_00173084(void) { /* TODO */ }

/* STUB: FUN_00173124 skipped */
void FUN_00173124(void) { /* TODO */ }

/* STUB: FUN_001731c4 skipped */
void FUN_001731c4(void) { /* TODO */ }

/* STUB: FUN_00173264 skipped */
void FUN_00173264(void) { /* TODO */ }

/* STUB: FUN_00173270 skipped */
void FUN_00173270(void) { /* TODO */ }

/* STUB: FUN_0017327c skipped */
void FUN_0017327c(void) { /* TODO */ }

/* STUB: FUN_00173288 skipped */
void FUN_00173288(void) { /* TODO */ }

/* STUB: FUN_00173290 skipped */
void FUN_00173290(void) { /* TODO */ }

/* STUB: FUN_00173370 skipped */
void FUN_00173370(void) { /* TODO */ }

/* STUB: FUN_00173390 skipped */
void FUN_00173390(void) { /* TODO */ }

/* STUB: FUN_00173504 skipped */
void FUN_00173504(void) { /* TODO */ }

/* STUB: FUN_0017389c skipped */
void FUN_0017389c(void) { /* TODO */ }

/* STUB: FUN_00173d24 skipped */
void FUN_00173d24(void) { /* TODO */ }

/* STUB: FUN_00173dbc skipped */
void FUN_00173dbc(void) { /* TODO */ }

/* STUB: FUN_0017412c skipped */
void FUN_0017412c(void) { /* TODO */ }

/* STUB: FUN_0017424c skipped */
void FUN_0017424c(void) { /* TODO */ }

/* STUB: FUN_00174358 skipped */
void FUN_00174358(void) { /* TODO */ }

/* STUB: FUN_00174534 skipped */
void FUN_00174534(void) { /* TODO */ }

/* STUB: FUN_001745e0 skipped */
void FUN_001745e0(void) { /* TODO */ }

/* STUB: FUN_001746e0 skipped */
void FUN_001746e0(void) { /* TODO */ }

/* STUB: FUN_001746fc skipped */
void FUN_001746fc(void) { /* TODO */ }

/* STUB: FUN_00174790 skipped */
void FUN_00174790(void) { /* TODO */ }

/* STUB: FUN_00174854 skipped */
void FUN_00174854(void) { /* TODO */ }

/* STUB: FUN_001748f0 skipped */
void FUN_001748f0(void) { /* TODO */ }

/* STUB: FUN_00174968 skipped */
void FUN_00174968(void) { /* TODO */ }

/* STUB: FUN_001749e0 skipped */
void FUN_001749e0(void) { /* TODO */ }

/* STUB: FUN_00174a58 skipped */
void FUN_00174a58(void) { /* TODO */ }

/* STUB: FUN_00174ab0 skipped */
void FUN_00174ab0(void) { /* TODO */ }

/* STUB: FUN_00174b00 skipped */
void FUN_00174b00(void) { /* TODO */ }

/* STUB: FUN_00174b58 skipped */
void FUN_00174b58(void) { /* TODO */ }

/* STUB: FUN_00175b54 skipped */
void FUN_00175b54(void) { /* TODO */ }

/* STUB: FUN_00175c0c skipped */
void FUN_00175c0c(void) { /* TODO */ }

/* STUB: FUN_001773dc skipped */
void FUN_001773dc(void) { /* TODO */ }

/* STUB: FUN_001776c0 skipped */
void FUN_001776c0(void) { /* TODO */ }

/* STUB: FUN_00177ba4 skipped */
void FUN_00177ba4(void) { /* TODO */ }

/* STUB: FUN_00177c5c skipped */
void FUN_00177c5c(void) { /* TODO */ }

/* STUB: FUN_00177d04 skipped */
void FUN_00177d04(void) { /* TODO */ }

/* STUB: FUN_00177dac skipped */
void FUN_00177dac(void) { /* TODO */ }

/* STUB: FUN_00177e48 skipped */
void FUN_00177e48(void) { /* TODO */ }

/* STUB: FUN_001780bc skipped */
void FUN_001780bc(void) { /* TODO */ }

/* STUB: FUN_0017816c skipped */
void FUN_0017816c(void) { /* TODO */ }

/* STUB: FUN_00178214 skipped */
void FUN_00178214(void) { /* TODO */ }

/* STUB: FUN_001788b4 skipped */
void FUN_001788b4(void) { /* TODO */ }

/* STUB: FUN_0017896c skipped */
void FUN_0017896c(void) { /* TODO */ }

/* STUB: FUN_00178a14 skipped */
void FUN_00178a14(void) { /* TODO */ }

/* STUB: FUN_00178aac skipped */
void FUN_00178aac(void) { /* TODO */ }

/* STUB: FUN_00178ce4 skipped */
void FUN_00178ce4(void) { /* TODO */ }

/* STUB: FUN_00178d78 skipped */
void FUN_00178d78(void) { /* TODO */ }

/* STUB: FUN_00178e20 skipped */
void FUN_00178e20(void) { /* TODO */ }

/* STUB: FUN_00179138 skipped */
void FUN_00179138(void) { /* TODO */ }

/* STUB: FUN_001791e8 skipped */
void FUN_001791e8(void) { /* TODO */ }

/* STUB: FUN_00179294 skipped */
void FUN_00179294(void) { /* TODO */ }

/* STUB: FUN_0017933c skipped */
void FUN_0017933c(void) { /* TODO */ }

/* STUB: FUN_001793e4 skipped */
void FUN_001793e4(void) { /* TODO */ }

/* STUB: FUN_00179474 skipped */
void FUN_00179474(void) { /* TODO */ }

/* STUB: FUN_0017952c skipped */
void FUN_0017952c(void) { /* TODO */ }

/* STUB: FUN_001795bc skipped */
void FUN_001795bc(void) { /* TODO */ }

/* STUB: FUN_0017966c skipped */
void FUN_0017966c(void) { /* TODO */ }

/* STUB: FUN_001796fc skipped */
void FUN_001796fc(void) { /* TODO */ }

/* STUB: FUN_00179798 skipped */
void FUN_00179798(void) { /* TODO */ }

/* STUB: FUN_00179834 skipped */
void FUN_00179834(void) { /* TODO */ }

/* STUB: FUN_001798c4 skipped */
void FUN_001798c4(void) { /* TODO */ }

/* STUB: FUN_00179954 skipped */
void FUN_00179954(void) { /* TODO */ }

/* STUB: FUN_001799ec skipped */
void FUN_001799ec(void) { /* TODO */ }

/* STUB: FUN_00179a7c skipped */
void FUN_00179a7c(void) { /* TODO */ }

/* STUB: FUN_00179b18 skipped */
void FUN_00179b18(void) { /* TODO */ }

/* STUB: FUN_0017a0d4 skipped */
void FUN_0017a0d4(void) { /* TODO */ }

/* STUB: FUN_0017a164 skipped */
void FUN_0017a164(void) { /* TODO */ }

/* STUB: FUN_0017a200 skipped */
void FUN_0017a200(void) { /* TODO */ }

/* STUB: FUN_0017a4ac skipped */
void FUN_0017a4ac(void) { /* TODO */ }

/* STUB: FUN_0017a56c skipped */
void FUN_0017a56c(void) { /* TODO */ }

/* STUB: FUN_0017a75c skipped */
void FUN_0017a75c(void) { /* TODO */ }

/* STUB: FUN_0017a808 skipped */
void FUN_0017a808(void) { /* TODO */ }

/* STUB: FUN_0017aa1c skipped */
void FUN_0017aa1c(void) { /* TODO */ }

/* STUB: FUN_0017acb4 skipped */
void FUN_0017acb4(void) { /* TODO */ }

/* STUB: FUN_0017adc0 skipped */
void FUN_0017adc0(void) { /* TODO */ }

/* STUB: FUN_0017b2ec skipped */
void FUN_0017b2ec(void) { /* TODO */ }

/* STUB: FUN_0017b388 skipped */
void FUN_0017b388(void) { /* TODO */ }

/* STUB: FUN_0017b4d4 skipped */
void FUN_0017b4d4(void) { /* TODO */ }

/* STUB: FUN_0017b598 skipped */
void FUN_0017b598(void) { /* TODO */ }

/* STUB: FUN_0017b818 skipped */
void FUN_0017b818(void) { /* TODO */ }

/* STUB: FUN_0017b8a4 skipped */
void FUN_0017b8a4(void) { /* TODO */ }

/* STUB: FUN_0017b910 skipped */
void FUN_0017b910(void) { /* TODO */ }

/* STUB: FUN_0017b9c4 skipped */
void FUN_0017b9c4(void) { /* TODO */ }

/* STUB: FUN_0017ba40 skipped */
void FUN_0017ba40(void) { /* TODO */ }

/* STUB: FUN_0017bb44 skipped */
void FUN_0017bb44(void) { /* TODO */ }

/* STUB: FUN_0017bbb0 skipped */
void FUN_0017bbb0(void) { /* TODO */ }

/* STUB: FUN_0017bcd0 skipped */
void FUN_0017bcd0(void) { /* TODO */ }

/* STUB: FUN_0017bd64 skipped */
void FUN_0017bd64(void) { /* TODO */ }

/* STUB: FUN_0017bd80 skipped */
void FUN_0017bd80(void) { /* TODO */ }

/* STUB: FUN_0017bedc skipped */
void FUN_0017bedc(void) { /* TODO */ }

/* STUB: FUN_0017c06c skipped */
void FUN_0017c06c(void) { /* TODO */ }

/* STUB: FUN_0017c16c skipped */
void FUN_0017c16c(void) { /* TODO */ }

/* STUB: FUN_0017c2e4 skipped */
void FUN_0017c2e4(void) { /* TODO */ }

/* STUB: FUN_0017c3cc skipped */
void FUN_0017c3cc(void) { /* TODO */ }

/* STUB: FUN_0017c3dc skipped */
void FUN_0017c3dc(void) { /* TODO */ }

/* STUB: FUN_0017cb00 skipped */
void FUN_0017cb00(void) { /* TODO */ }

/* STUB: FUN_0017ccf4 skipped */
void FUN_0017ccf4(void) { /* TODO */ }

/* STUB: FUN_0017d064 skipped */
void FUN_0017d064(void) { /* TODO */ }

/* STUB: FUN_0017d1e0 skipped */
void FUN_0017d1e0(void) { /* TODO */ }

/* STUB: FUN_0017d39c skipped */
void FUN_0017d39c(void) { /* TODO */ }

/* STUB: FUN_0017d588 skipped */
void FUN_0017d588(void) { /* TODO */ }

/* STUB: FUN_0017d6f8 skipped */
void FUN_0017d6f8(void) { /* TODO */ }

/* STUB: FUN_0017d890 skipped */
void FUN_0017d890(void) { /* TODO */ }

/* STUB: FUN_0017d950 skipped */
void FUN_0017d950(void) { /* TODO */ }

/* STUB: FUN_0017dbc4 skipped */
void FUN_0017dbc4(void) { /* TODO */ }

/* STUB: FUN_0017dda4 skipped */
void FUN_0017dda4(void) { /* TODO */ }

/* STUB: FUN_0017de34 skipped */
void FUN_0017de34(void) { /* TODO */ }

/* STUB: FUN_0017df34 skipped */
void FUN_0017df34(void) { /* TODO */ }

/* STUB: FUN_0017df50 skipped */
void FUN_0017df50(void) { /* TODO */ }

/* STUB: FUN_0017e9a0 skipped */
void FUN_0017e9a0(void) { /* TODO */ }

/* STUB: FUN_0017ea34 skipped */
void FUN_0017ea34(void) { /* TODO */ }

/* STUB: FUN_0017ead0 skipped */
void FUN_0017ead0(void) { /* TODO */ }

/* STUB: FUN_0017eb6c skipped */
void FUN_0017eb6c(void) { /* TODO */ }

/* STUB: FUN_0017ebfc skipped */
void FUN_0017ebfc(void) { /* TODO */ }

/* STUB: FUN_0017ec98 skipped */
void FUN_0017ec98(void) { /* TODO */ }

/* STUB: FUN_0017ed28 skipped */
void FUN_0017ed28(void) { /* TODO */ }

/* STUB: FUN_0017edc4 skipped */
void FUN_0017edc4(void) { /* TODO */ }

/* STUB: FUN_0017ee60 skipped */
void FUN_0017ee60(void) { /* TODO */ }

/* STUB: FUN_0017eefc skipped */
void FUN_0017eefc(void) { /* TODO */ }

/* STUB: FUN_0017efd8 skipped */
void FUN_0017efd8(void) { /* TODO */ }

/* STUB: FUN_0017f0b8 skipped */
void FUN_0017f0b8(void) { /* TODO */ }

/* STUB: FUN_0017f178 skipped */
void FUN_0017f178(void) { /* TODO */ }

/* STUB: FUN_0017f194 skipped */
void FUN_0017f194(void) { /* TODO */ }

/* STUB: FUN_0017f2b0 skipped */
void FUN_0017f2b0(void) { /* TODO */ }

/* STUB: FUN_0017f44c skipped */
void FUN_0017f44c(void) { /* TODO */ }

/* STUB: FUN_0017f694 skipped */
void FUN_0017f694(void) { /* TODO */ }

/* STUB: FUN_0017f8f0 skipped */
void FUN_0017f8f0(void) { /* TODO */ }

/* STUB: FUN_0017fa0c skipped */
void FUN_0017fa0c(void) { /* TODO */ }

/* STUB: FUN_0017fb84 skipped */
void FUN_0017fb84(void) { /* TODO */ }

/* STUB: FUN_0017fed4 skipped */
void FUN_0017fed4(void) { /* TODO */ }

/* STUB: FUN_00180010 skipped */
void FUN_00180010(void) { /* TODO */ }

/* STUB: FUN_00180254 skipped */
void FUN_00180254(void) { /* TODO */ }

/* STUB: FUN_00180398 skipped */
void FUN_00180398(void) { /* TODO */ }

/* STUB: FUN_001803ac skipped */
void FUN_001803ac(void) { /* TODO */ }

/* STUB: FUN_00180484 skipped */
void FUN_00180484(void) { /* TODO */ }

/* STUB: FUN_001805a4 skipped */
void FUN_001805a4(void) { /* TODO */ }

/* STUB: FUN_001808a4 skipped */
void FUN_001808a4(void) { /* TODO */ }

/* STUB: FUN_001809ac skipped */
void FUN_001809ac(void) { /* TODO */ }

/* STUB: FUN_00180a3c skipped */
void FUN_00180a3c(void) { /* TODO */ }

/* STUB: FUN_00180b9c skipped */
void FUN_00180b9c(void) { /* TODO */ }

/* STUB: FUN_00180c74 skipped */
void FUN_00180c74(void) { /* TODO */ }

/* STUB: FUN_00180d24 skipped */
void FUN_00180d24(void) { /* TODO */ }

/* STUB: FUN_00180dbc skipped */
void FUN_00180dbc(void) { /* TODO */ }

/* STUB: FUN_00180ec4 skipped */
void FUN_00180ec4(void) { /* TODO */ }

/* STUB: FUN_001811b0 skipped */
void FUN_001811b0(void) { /* TODO */ }

/* STUB: FUN_00181218 skipped */
void FUN_00181218(void) { /* TODO */ }

/* STUB: FUN_00181280 skipped */
void FUN_00181280(void) { /* TODO */ }

/* STUB: FUN_001812e8 skipped */
void FUN_001812e8(void) { /* TODO */ }

/* STUB: FUN_00181334 skipped */
void FUN_00181334(void) { /* TODO */ }

/* STUB: FUN_00181380 skipped */
void FUN_00181380(void) { /* TODO */ }

/* STUB: FUN_001813d4 skipped */
void FUN_001813d4(void) { /* TODO */ }

/* STUB: FUN_00181514 skipped */
void FUN_00181514(void) { /* TODO */ }

/* STUB: FUN_001815c0 skipped */
void FUN_001815c0(void) { /* TODO */ }

/* STUB: FUN_001815dc skipped */
void FUN_001815dc(void) { /* TODO */ }

/* STUB: FUN_001816ac skipped */
void FUN_001816ac(void) { /* TODO */ }

/* STUB: FUN_001816c8 skipped */
void FUN_001816c8(void) { /* TODO */ }

/* STUB: FUN_001816dc skipped */
void FUN_001816dc(void) { /* TODO */ }

/* STUB: FUN_001817d0 skipped */
void FUN_001817d0(void) { /* TODO */ }

/* STUB: FUN_001817dc skipped */
void FUN_001817dc(void) { /* TODO */ }

/* STUB: FUN_001817e8 skipped */
void FUN_001817e8(void) { /* TODO */ }

/* STUB: FUN_001818e8 skipped */
void FUN_001818e8(void) { /* TODO */ }

/* STUB: FUN_00181c28 skipped */
void FUN_00181c28(void) { /* TODO */ }

/* STUB: FUN_00181d9c skipped */
void FUN_00181d9c(void) { /* TODO */ }

/* STUB: FUN_0018227c skipped */
void FUN_0018227c(void) { /* TODO */ }

/* STUB: FUN_00182634 skipped */
void FUN_00182634(void) { /* TODO */ }

/* STUB: FUN_001826d0 skipped */
void FUN_001826d0(void) { /* TODO */ }

/* STUB: FUN_00182994 skipped */
void FUN_00182994(void) { /* TODO */ }

/* STUB: FUN_00182ac4 skipped */
void FUN_00182ac4(void) { /* TODO */ }

/* STUB: FUN_00182b60 skipped */
void FUN_00182b60(void) { /* TODO */ }

/* STUB: FUN_00182c0c skipped */
void FUN_00182c0c(void) { /* TODO */ }

/* STUB: FUN_00182cac skipped */
void FUN_00182cac(void) { /* TODO */ }

/* STUB: FUN_00182d4c skipped */
void FUN_00182d4c(void) { /* TODO */ }

/* STUB: FUN_00182e6c skipped */
void FUN_00182e6c(void) { /* TODO */ }

/* STUB: FUN_00182f58 skipped */
void FUN_00182f58(void) { /* TODO */ }

/* STUB: FUN_00182f64 skipped */
void FUN_00182f64(void) { /* TODO */ }

/* STUB: FUN_00182f70 skipped */
void FUN_00182f70(void) { /* TODO */ }

/* STUB: FUN_00182ff8 skipped */
void FUN_00182ff8(void) { /* TODO */ }

/* STUB: FUN_00183384 skipped */
void FUN_00183384(void) { /* TODO */ }

/* STUB: FUN_001834f8 skipped */
void FUN_001834f8(void) { /* TODO */ }

/* STUB: FUN_0018361c skipped */
void FUN_0018361c(void) { /* TODO */ }

/* STUB: FUN_00183648 skipped */
void FUN_00183648(void) { /* TODO */ }

/* STUB: FUN_00183674 skipped */
void FUN_00183674(void) { /* TODO */ }

/* STUB: FUN_001836a0 skipped */
void FUN_001836a0(void) { /* TODO */ }

/* STUB: FUN_0018381c skipped */
void FUN_0018381c(void) { /* TODO */ }

/* STUB: FUN_00183838 skipped */
void FUN_00183838(void) { /* TODO */ }

/* STUB: FUN_001838c8 skipped */
void FUN_001838c8(void) { /* TODO */ }

/* STUB: FUN_00183958 skipped */
void FUN_00183958(void) { /* TODO */ }

/* STUB: FUN_001839f0 skipped */
void FUN_001839f0(void) { /* TODO */ }

/* STUB: FUN_00183b10 skipped */
void FUN_00183b10(void) { /* TODO */ }

/* STUB: FUN_00183c68 skipped */
void FUN_00183c68(void) { /* TODO */ }

/* STUB: FUN_00183d00 skipped */
void FUN_00183d00(void) { /* TODO */ }

/* STUB: FUN_00183d0c skipped */
void FUN_00183d0c(void) { /* TODO */ }

/* STUB: FUN_00183d18 skipped */
void FUN_00183d18(void) { /* TODO */ }

/* STUB: FUN_00183d2c skipped */
void FUN_00183d2c(void) { /* TODO */ }

/* STUB: FUN_00183ec0 skipped */
void FUN_00183ec0(void) { /* TODO */ }

/* STUB: FUN_00183f64 skipped */
void FUN_00183f64(void) { /* TODO */ }

/* STUB: FUN_00183f90 skipped */
void FUN_00183f90(void) { /* TODO */ }

/* STUB: FUN_00184148 skipped */
void FUN_00184148(void) { /* TODO */ }

/* STUB: FUN_0018422c skipped */
void FUN_0018422c(void) { /* TODO */ }

/* STUB: FUN_00184364 skipped */
void FUN_00184364(void) { /* TODO */ }

/* STUB: FUN_00184390 skipped */
void FUN_00184390(void) { /* TODO */ }

/* STUB: FUN_001846b4 skipped */
void FUN_001846b4(void) { /* TODO */ }

/* STUB: FUN_00184804 skipped */
void FUN_00184804(void) { /* TODO */ }

/* STUB: FUN_00184830 skipped */
void FUN_00184830(void) { /* TODO */ }

/* STUB: FUN_00184ad4 skipped */
void FUN_00184ad4(void) { /* TODO */ }

/* STUB: FUN_00184c48 skipped */
void FUN_00184c48(void) { /* TODO */ }

/* STUB: FUN_00184ec8 skipped */
void FUN_00184ec8(void) { /* TODO */ }

/* STUB: FUN_001853d8 skipped */
void FUN_001853d8(void) { /* TODO */ }

/* STUB: FUN_00185614 skipped */
void FUN_00185614(void) { /* TODO */ }

/* STUB: FUN_00185788 skipped */
void FUN_00185788(void) { /* TODO */ }

/* STUB: FUN_001858b8 skipped */
void FUN_001858b8(void) { /* TODO */ }

/* STUB: FUN_0018592c skipped */
void FUN_0018592c(void) { /* TODO */ }

/* STUB: FUN_00185a20 skipped */
void FUN_00185a20(void) { /* TODO */ }

/* STUB: FUN_00185a84 skipped */
void FUN_00185a84(void) { /* TODO */ }

/* STUB: FUN_00185ab0 skipped */
void FUN_00185ab0(void) { /* TODO */ }

/* STUB: FUN_00185bb8 skipped */
void FUN_00185bb8(void) { /* TODO */ }

/* STUB: FUN_00185bec skipped */
void FUN_00185bec(void) { /* TODO */ }

/* STUB: FUN_00185bf4 skipped */
void FUN_00185bf4(void) { /* TODO */ }

/* STUB: FUN_00185bfc skipped */
void FUN_00185bfc(void) { /* TODO */ }

/* STUB: FUN_00185c04 skipped */
void FUN_00185c04(void) { /* TODO */ }

/* STUB: FUN_00185c30 skipped */
void FUN_00185c30(void) { /* TODO */ }

/* STUB: FUN_00185c5c skipped */
void FUN_00185c5c(void) { /* TODO */ }

/* STUB: FUN_00185c88 skipped */
void FUN_00185c88(void) { /* TODO */ }

/* STUB: FUN_00185cb4 skipped */
void FUN_00185cb4(void) { /* TODO */ }

/* STUB: FUN_00185ce0 skipped */
void FUN_00185ce0(void) { /* TODO */ }

/* STUB: FUN_00185d0c skipped */
void FUN_00185d0c(void) { /* TODO */ }

/* STUB: FUN_00185d38 skipped */
void FUN_00185d38(void) { /* TODO */ }

/* STUB: FUN_00185d64 skipped */
void FUN_00185d64(void) { /* TODO */ }

/* STUB: FUN_00185d90 skipped */
void FUN_00185d90(void) { /* TODO */ }

/* STUB: FUN_00185dbc skipped */
void FUN_00185dbc(void) { /* TODO */ }

/* STUB: FUN_00185dd4 skipped */
void FUN_00185dd4(void) { /* TODO */ }

/* STUB: FUN_00185de0 skipped */
void FUN_00185de0(void) { /* TODO */ }

/* STUB: FUN_00185dec skipped */
void FUN_00185dec(void) { /* TODO */ }

/* STUB: FUN_00185e04 skipped */
void FUN_00185e04(void) { /* TODO */ }

/* STUB: FUN_00185eec skipped */
void FUN_00185eec(void) { /* TODO */ }

/* STUB: FUN_00185f48 skipped */
void FUN_00185f48(void) { /* TODO */ }

/* STUB: FUN_00185fbc skipped */
void FUN_00185fbc(void) { /* TODO */ }

/* STUB: FUN_0018603c skipped */
void FUN_0018603c(void) { /* TODO */ }

/* STUB: FUN_00186080 skipped */
void FUN_00186080(void) { /* TODO */ }

/* STUB: FUN_001861dc skipped */
void FUN_001861dc(void) { /* TODO */ }

/* STUB: FUN_0018627c skipped */
void FUN_0018627c(void) { /* TODO */ }

/* STUB: FUN_00186540 skipped */
void FUN_00186540(void) { /* TODO */ }

/* STUB: FUN_00186630 skipped */
void FUN_00186630(void) { /* TODO */ }

/* STUB: FUN_001866c4 skipped */
void FUN_001866c4(void) { /* TODO */ }

/* STUB: FUN_00186970 skipped */
void FUN_00186970(void) { /* TODO */ }

/* STUB: FUN_00186a0c skipped */
void FUN_00186a0c(void) { /* TODO */ }

/* STUB: FUN_00186a34 skipped */
void FUN_00186a34(void) { /* TODO */ }

/* STUB: FUN_00186de0 skipped */
void FUN_00186de0(void) { /* TODO */ }

/* STUB: FUN_00186e1c skipped */
void FUN_00186e1c(void) { /* TODO */ }

/* STUB: FUN_00186e58 skipped */
void FUN_00186e58(void) { /* TODO */ }

/* STUB: FUN_00187004 skipped */
void FUN_00187004(void) { /* TODO */ }

/* STUB: FUN_0018712c skipped */
void FUN_0018712c(void) { /* TODO */ }

/* STUB: FUN_00187380 skipped */
void FUN_00187380(void) { /* TODO */ }

/* STUB: FUN_001874c0 skipped */
void FUN_001874c0(void) { /* TODO */ }

/* STUB: FUN_00187d40 skipped */
void FUN_00187d40(void) { /* TODO */ }

/* STUB: FUN_00187d78 skipped */
void FUN_00187d78(void) { /* TODO */ }

/* STUB: FUN_00187db4 skipped */
void FUN_00187db4(void) { /* TODO */ }

/* STUB: FUN_00187e40 skipped */
void FUN_00187e40(void) { /* TODO */ }

/* STUB: FUN_00187f10 skipped */
void FUN_00187f10(void) { /* TODO */ }

/* STUB: FUN_00187f40 skipped */
void FUN_00187f40(void) { /* TODO */ }

/* STUB: FUN_00187f70 skipped */
void FUN_00187f70(void) { /* TODO */ }

/* STUB: FUN_00188068 skipped */
void FUN_00188068(void) { /* TODO */ }

/* STUB: FUN_001881a0 skipped */
void FUN_001881a0(void) { /* TODO */ }

/* STUB: FUN_00188228 skipped */
void FUN_00188228(void) { /* TODO */ }

/* STUB: FUN_0018831c skipped */
void FUN_0018831c(void) { /* TODO */ }

/* STUB: FUN_00188380 skipped */
void FUN_00188380(void) { /* TODO */ }

/* STUB: FUN_001883b4 skipped */
void FUN_001883b4(void) { /* TODO */ }

/* STUB: FUN_001883e8 skipped */
void FUN_001883e8(void) { /* TODO */ }

/* STUB: FUN_00188404 skipped */
void FUN_00188404(void) { /* TODO */ }

/* STUB: FUN_00188438 skipped */
void FUN_00188438(void) { /* TODO */ }

/* STUB: FUN_00188468 skipped */
void FUN_00188468(void) { /* TODO */ }

/* STUB: FUN_00188478 skipped */
void FUN_00188478(void) { /* TODO */ }

/* STUB: FUN_00188520 skipped */
void FUN_00188520(void) { /* TODO */ }

/* STUB: FUN_0018859c skipped */
void FUN_0018859c(void) { /* TODO */ }

/* STUB: FUN_00188688 skipped */
void FUN_00188688(void) { /* TODO */ }

/* STUB: FUN_00188700 skipped */
void FUN_00188700(void) { /* TODO */ }

/* STUB: FUN_00188778 skipped */
void FUN_00188778(void) { /* TODO */ }

/* STUB: FUN_00188788 skipped */
void FUN_00188788(void) { /* TODO */ }

/* STUB: FUN_001887c8 skipped */
void FUN_001887c8(void) { /* TODO */ }

/* STUB: FUN_001887f0 skipped */
void FUN_001887f0(void) { /* TODO */ }

/* STUB: FUN_00188820 skipped */
void FUN_00188820(void) { /* TODO */ }

/* STUB: FUN_00188848 skipped */
void FUN_00188848(void) { /* TODO */ }

/* STUB: FUN_00188858 skipped */
void FUN_00188858(void) { /* TODO */ }

/* STUB: FUN_00188880 skipped */
void FUN_00188880(void) { /* TODO */ }

/* STUB: FUN_001888f0 skipped */
void FUN_001888f0(void) { /* TODO */ }

/* STUB: FUN_00188a00 skipped */
void FUN_00188a00(void) { /* TODO */ }

/* STUB: FUN_00188b80 skipped */
void FUN_00188b80(void) { /* TODO */ }

/* STUB: FUN_00188c10 skipped */
void FUN_00188c10(void) { /* TODO */ }

/* STUB: FUN_00188c18 skipped */
void FUN_00188c18(void) { /* TODO */ }

/* STUB: FUN_00188c20 skipped */
void FUN_00188c20(void) { /* TODO */ }

/* STUB: FUN_00188c64 skipped */
void FUN_00188c64(void) { /* TODO */ }

/* STUB: FUN_00188d80 skipped */
void FUN_00188d80(void) { /* TODO */ }

/* STUB: FUN_00188e9c skipped */
void FUN_00188e9c(void) { /* TODO */ }

/* STUB: FUN_00188ec0 skipped */
void FUN_00188ec0(void) { /* TODO */ }

/* STUB: FUN_00188ed0 skipped */
void FUN_00188ed0(void) { /* TODO */ }

/* STUB: FUN_00188fa0 skipped */
void FUN_00188fa0(void) { /* TODO */ }

/* STUB: FUN_00188fe4 skipped */
void FUN_00188fe4(void) { /* TODO */ }

/* STUB: FUN_00188ff0 skipped */
void FUN_00188ff0(void) { /* TODO */ }

/* STUB: FUN_00188ffc skipped */
void FUN_00188ffc(void) { /* TODO */ }

/* STUB: FUN_00189028 skipped */
void FUN_00189028(void) { /* TODO */ }

/* STUB: FUN_0018923c skipped */
void FUN_0018923c(void) { /* TODO */ }

/* STUB: FUN_00189248 skipped */
void FUN_00189248(void) { /* TODO */ }

/* STUB: FUN_00189364 skipped */
void FUN_00189364(void) { /* TODO */ }

/* STUB: FUN_001895a0 skipped */
void FUN_001895a0(void) { /* TODO */ }

/* STUB: FUN_00189a20 skipped */
void FUN_00189a20(void) { /* TODO */ }

/* STUB: FUN_0018a520 skipped */
void FUN_0018a520(void) { /* TODO */ }

/* STUB: FUN_0018a71c skipped */
void FUN_0018a71c(void) { /* TODO */ }

/* STUB: FUN_0018aa30 skipped */
void FUN_0018aa30(void) { /* TODO */ }

/* STUB: FUN_0018ac04 skipped */
void FUN_0018ac04(void) { /* TODO */ }

/* STUB: FUN_0018b598 skipped */
void FUN_0018b598(void) { /* TODO */ }

/* STUB: FUN_0018b878 skipped */
void FUN_0018b878(void) { /* TODO */ }

/* STUB: FUN_0018ba50 skipped */
void FUN_0018ba50(void) { /* TODO */ }

/* STUB: FUN_0018bc18 skipped */
void FUN_0018bc18(void) { /* TODO */ }

/* STUB: FUN_0018bdf4 skipped */
void FUN_0018bdf4(void) { /* TODO */ }

/* STUB: FUN_0018c0bc skipped */
void FUN_0018c0bc(void) { /* TODO */ }

/* STUB: FUN_0018c1a4 skipped */
void FUN_0018c1a4(void) { /* TODO */ }

/* STUB: FUN_0018c1d4 skipped */
void FUN_0018c1d4(void) { /* TODO */ }

/* STUB: FUN_0018c264 skipped */
void FUN_0018c264(void) { /* TODO */ }

/* STUB: FUN_0018c300 skipped */
void FUN_0018c300(void) { /* TODO */ }

