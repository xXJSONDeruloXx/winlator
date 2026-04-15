/*
 * texture_decoder.c — Texture format decoding
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015e9a4  size=200 */

void TextureDecoder_addBoundBuffer(long param_1,int *param_2,long param_3,long param_4)

{
  void *__ptr;
  long *plVar1;
  unsigned long uVar2;
  
  if (*param_2 < 1) {
    return;
  }
  if (0 < (int)*(uint32_t *)(param_1 + 0x10)) {
    uVar2 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 0x18) + uVar2 * 8) == param_3) {
        if ((int)uVar2 != -1) {
          __ptr = *(void **)(*(long *)(param_1 + 0x18) + uVar2 * 8);
          if (__ptr != (void *)0x0) {
            free(__ptr);
          }
          ArrayList_removeAt(param_1 + 0x10,uVar2 & 0xffffffff);
        }
        break;
      }
      uVar2 = uVar2 + 1;
    } while (*(uint32_t *)(param_1 + 0x10) != uVar2);
  }
  plVar1 = calloc(1,0x18);
  *plVar1 = param_3;
  plVar1[1] = param_4;
  plVar1[2] = (long)param_2;
  ArrayList_add(param_1 + 0x10);
  return;
}


/* @0015e584  size=68 */

bool TextureDecoder_containsImage(uint32_t *param_1,long param_2)

{
  unsigned long uVar1;
  
  if (0 < (int)*param_1) {
    uVar1 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 2) + uVar1 * 8) == param_2) {
        return (int)uVar1 != -1;
      }
      uVar1 = uVar1 + 1;
    } while (*param_1 != uVar1);
  }
  return false;
}


/* @0015e41c  size=360 */

void TextureDecoder_copyBufferToImage
               (uint32_t *param_1,uint64_t param_2,long param_3,long param_4,uint32_t param_5,
               uint64_t param_6)

{
  long lVar1;
  uint64_t *puVar2;
  unsigned long uVar3;
  uint64_t uVar4;
  long lVar5;
  uint64_t local_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  long lStack_78;
  int local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar1 + 0x28);
  if (0 < (int)param_1[4]) {
    uVar3 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 6) + uVar3 * 8) == param_3) {
        if (((int)uVar3 != -1) && (0 < (int)*param_1)) {
          uVar4 = *(uint64_t *)(*(long *)(param_1 + 6) + uVar3 * 8);
          uVar3 = 0;
          goto LAB_0015e4b0;
        }
        break;
      }
      uVar3 = uVar3 + 1;
    } while (param_1[4] != uVar3);
  }
  goto LAB_0015e550;
  while (uVar3 = uVar3 + 1, *param_1 != uVar3) {
LAB_0015e4b0:
    if (**(long **)(*(long *)(param_1 + 2) + uVar3 * 8) == param_4) {
      if ((int)uVar3 != -1) {
        lVar5 = *(long *)(*(long *)(param_1 + 2) + uVar3 * 8);
        puVar2 = calloc(1,0x18);
        *puVar2 = uVar4;
        puVar2[1] = lVar5;
        puVar2[2] = param_6;
        ArrayDeque_addLast(param_1 + 8,puVar2);
        uStack_80 = 0;
        uStack_98 = 0;
        local_a0 = 0;
        lStack_78 = (unsigned long)(uint32_t)(int)*(short *)(lVar5 + 0xc) << 0x20;
        local_90 = 1;
        uStack_88 = 0x100000000;
        local_70 = ((uint64_t)(1) << 32 | (uint32_t)((int)*(short *)(lVar5 + 0xe)));
        ((generic_fn_t)DAT_00193e78)(param_2,*(uint64_t *)(lVar5 + 0x10),param_4,param_5,1,&local_a0);
      }
      break;
    }
  }
LAB_0015e550:
  if (*(long *)(lVar1 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0015da54  size=72 */

void * TextureDecoder_create(long param_1,long param_2)

{
  void *pvVar1;
  uint64_t uVar2;
  
  if (*(int *)(param_2 + 0x58) == 0) {
    pvVar1 = calloc(1,0x48);
    uVar2 = *(uint64_t *)(param_1 + 0x90);
    *(uint16_t *)((long)pvVar1 + 0x38) = *(uint16_t *)(param_1 + 10);
    *(uint64_t *)((long)pvVar1 + 0x40) = uVar2;
  }
  else {
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}


/* @0015e5c8  size=736 */

/* WARNING: Type propagation algorithm not settling */

int TextureDecoder_createImage(uint64_t param_1,uint64_t param_2,long param_3,long *param_4)

{
  uint32_t uVar1;
  long lVar2;
  int iVar3;
  uint32_t uVar4;
  long *__ptr;
  int *piVar5;
  size_t __n;
  long local_e8 [4];
  uint64_t local_c8;
  uint64_t local_c0;
  uint64_t uStack_b8;
  unsigned long local_b0;
  long local_a8 [5];
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  long local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar2 + 0x28);
  *param_4 = 0;
  iVar3 = *(int *)(param_3 + 0x18);
  if (iVar3 - 0x83U < 0xc) {
    __ptr = calloc(1,0x28);
    uVar4 = *(uint32_t *)(param_3 + 0x20);
    uVar1 = *(uint32_t *)(param_3 + 0x10);
    piVar5 = *(int **)(param_3 + 8);
    *(short *)((long)__ptr + 0xc) = (short)*(uint32_t *)(param_3 + 0x1c);
    *(int *)(__ptr + 1) = iVar3;
    *(uint32_t *)(param_3 + 0x18) = 0x2c;
    *(short *)((long)__ptr + 0xe) = (short)uVar4;
    *(uint32_t *)(param_3 + 0x10) = uVar1 & 0xffffff7f;
    *(uint32_t *)(param_3 + 0x28) = 1;
    for (; piVar5 != (int *)0x0; piVar5 = *(int **)(piVar5 + 2)) {
      if (*piVar5 == 0x3b9d0838) {
        if (*(uint32_t **)(piVar5 + 6) != (uint32_t *)0x0) {
          piVar5[4] = 1;
          **(uint32_t **)(piVar5 + 6) = 0x2c;
        }
        break;
      }
    }
    iVar3 = ((generic_fn_t)DAT_00193c90)(param_2,param_3,0,&local_60);
    if (iVar3 == 0) {
      local_a8[2] = 0;
      local_a8[3] = 0;
      local_a8[1] = 0xc;
      local_a8[4] = (long)(uint32_t)(*(int *)(param_3 + 0x1c) * *(int *)(param_3 + 0x20) * 4);
      local_70 = 0;
      uStack_78 = 0;
      local_80 = 1;
      iVar3 = ((generic_fn_t)DAT_00193c70)(param_2,local_a8 + 1,0,local_a8);
      if (iVar3 == 0) {
        local_c0 = 0;
        uStack_b8 = 0;
        local_b0 = 0;
        ((generic_fn_t)DAT_00193bb8)(param_2,local_a8[0],&local_c0);
        local_e8[2] = 0;
        local_c8 = 0;
        local_e8[1] = 5;
        local_e8[3] = local_c0;
        uVar4 = getMemoryTypeIndex(local_b0 & 0xffffffff,2);
        local_c8 = ((uint64_t)((*(uint32_t*)((char*)&local_c8 + 4))) << 32 | (uint32_t)(uVar4));
        iVar3 = ((generic_fn_t)DAT_00193b80)(param_2,local_e8 + 1,0,local_e8);
        if ((iVar3 == 0) && (iVar3 = ((generic_fn_t)DAT_00193bc0)(param_2,local_a8[0],local_e8[0],0), iVar3 == 0)
           ) {
          __n = (size_t)((int)*(short *)((long)__ptr + 0xc) * (int)*(short *)((long)__ptr + 0xe) * 4
                        );
          iVar3 = ((generic_fn_t)DAT_00193b90)(param_2,local_e8[0],0,__n,0,__ptr + 4);
          if (iVar3 == 0) {
            memset((void *)__ptr[4],0,__n);
            *__ptr = local_60;
            __ptr[2] = local_a8[0];
            __ptr[3] = local_e8[0];
            ArrayList_add(param_1,__ptr);
            *param_4 = local_60;
            goto LAB_0015e838;
          }
        }
      }
    }
    if (__ptr[4] != 0) {
      ((generic_fn_t)DAT_00193b98)(param_2,__ptr[3]);
    }
    if (*__ptr != 0) {
      ((generic_fn_t)DAT_00193c98)(param_2,*__ptr,0);
    }
    if (__ptr[2] != 0) {
      ((generic_fn_t)DAT_00193c78)(param_2,__ptr[2],0);
    }
    if (__ptr[3] != 0) {
      ((generic_fn_t)DAT_00193b88)(param_2,__ptr[3],0);
    }
    free(__ptr);
  }
  else {
    iVar3 = -0xb;
  }
LAB_0015e838:
  if (*(long *)(lVar2 + 0x28) == local_58) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0015dae8  size=2356 */

void TextureDecoder_decodeAll(long param_1)

{
  long lVar1;
  uint16_t uVar2;
  short sVar3;
  short sVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  long lVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  int iVar12;
  unsigned long uVar13;
  long *plVar14;
  void *__addr;
  long *plVar15;
  uint64_t *puVar16;
  char *pcVar17;
  DIR *__dirp;
  dirent *pdVar18;
  FILE *pFVar19;
  size_t sVar20;
  long lVar21;
  uint32_t uVar22;
  unsigned long uVar23;
  uint8_t *pbVar24;
  uint8_t bVar25;
  size_t __n;
  long lVar26;
  long *plVar27;
  uint32_t uVar28;
  unsigned long uVar29;
  void *__ptr;
  uint8_t *pbVar30;
  unsigned long local_2258;
  uint32_t local_2220;
  uint8_t local_2210 [136];
  long lStack_2188;
  char acStack_2180 [8];
  undefined5 uStack_2178;
  uint32_t local_2173;
  uint8_t auStack_2170 [5];
  uint32_t uStack_216b;
  uint64_t uStack_2168;
  uint64_t uStack_2160;
  uint64_t uStack_2158;
  uint64_t local_2150;
  uint64_t uStack_2148;
  uint64_t uStack_2140;
  uint64_t uStack_2138;
  uint64_t local_2130;
  uint64_t uStack_2128;
  uint64_t uStack_2120;
  uint64_t uStack_2118;
  unsigned long local_1190;
  long local_1188;
  uint64_t local_1180;
  uint64_t uStack_1178;
  uint64_t local_1170;
  uint64_t uStack_1168;
  uint64_t local_1160;
  uint64_t uStack_1158;
  uint64_t local_1150;
  uint64_t uStack_1148;
  uint64_t local_1140;
  uint64_t uStack_1138;
  uint64_t local_1130;
  uint64_t uStack_1128;
  uint64_t local_1120;
  uint64_t uStack_1118;
  uint64_t local_1110;
  uint64_t uStack_1108;
  uint64_t local_1100;
  uint64_t uStack_10f8;
  uint64_t local_10f0;
  uint64_t uStack_10e8;
  uint64_t local_10e0;
  uint64_t uStack_10d8;
  uint64_t local_10d0;
  uint64_t uStack_10c8;
  uint64_t local_10c0;
  uint64_t uStack_10b8;
  uint64_t local_10b0;
  uint64_t uStack_10a8;
  uint64_t uStack_10a0;
  undefined7 uStack_1098;
  uint8_t local_1091;
  undefined7 uStack_1090;
  uint64_t uStack_1089;
  char local_1080 [24];
  undefined5 uStack_1068;
  uint32_t uStack_1063;
  uint8_t auStack_1060 [5];
  uint32_t uStack_105b;
  uint64_t uStack_1058;
  uint64_t local_1050;
  uint64_t uStack_1048;
  uint64_t local_1040;
  uint64_t uStack_1038;
  uint64_t local_1030;
  uint64_t uStack_1028;
  uint64_t local_1020;
  uint64_t uStack_1018;
  uint64_t local_1010;
  uint64_t uStack_1008;
  long local_78;
  
  /* stack canary setup */
  local_78 = *(long *)(lVar7 + 0x28);
  uVar13 = ArrayDeque_isEmpty(param_1 + 0x20);
  if ((uVar13 & 1) == 0) {
    do {
      plVar14 = (long *)ArrayDeque_removeFirst(param_1 + 0x20);
      if (plVar14 == (long *)0x0) goto LAB_0015dbac;
      lVar1 = *plVar14;
      lVar21 = plVar14[1];
      lVar26 = plVar14[2];
      free(plVar14);
      if (((lVar1 == 0) || (lVar21 == 0)) ||
         (__addr = mmap((void *)0x0,*(size_t *)(*(int **)(lVar1 + 0x10) + 8),3,1,
                        **(int **)(lVar1 + 0x10),0), __addr == (void *)0xffffffffffffffff))
      goto LAB_0015dbac;
      bVar8 = false;
      bVar9 = true;
      iVar12 = 8;
      bVar25 = 1;
      bVar10 = false;
      bVar11 = false;
      switch(*(uint32_t *)(lVar21 + 8)) {
      case 0x83:
      case 0x84:
        bVar8 = true;
        iVar12 = 8;
        bVar9 = true;
        bVar25 = 1;
        break;
      case 0x85:
      case 0x86:
        break;
      case 0x87:
      case 0x88:
        bVar25 = 2;
        goto LAB_0015dc7c;
      case 0x89:
      case 0x8a:
        bVar25 = 3;
LAB_0015dc7c:
        bVar9 = false;
        bVar8 = false;
        iVar12 = 0x10;
        break;
      case 0x8b:
        bVar10 = true;
      case 0x8c:
        bVar8 = bVar10;
        bVar9 = false;
        bVar25 = 4;
        iVar12 = 8;
        break;
      case 0x8d:
        bVar11 = true;
      case 0x8e:
        bVar8 = bVar11;
        bVar9 = false;
        bVar25 = 5;
        iVar12 = 0x10;
        break;
      default:
        bVar8 = false;
        iVar12 = 0;
        bVar9 = false;
        bVar25 = 0;
      }
      uVar2 = *(uint16_t *)(lVar21 + 0xc);
      local_2220 = (uint32_t)(short)uVar2;
      plVar14 = (long *)((long)__addr + *(long *)(lVar1 + 8) + lVar26);
      if (((short)uVar2 < 0x400) || ((short)*(uint16_t *)(lVar21 + 0xe) < 0x400)) {
        local_2258 = 0;
LAB_0015de24:
        sVar3 = *(short *)(lVar21 + 0xe);
        pbVar30 = *(uint8_t **)(param_1 + 0x40);
        iVar12 = 8;
        if (!bVar9) {
          iVar12 = 0x10;
        }
        uVar22 = 1;
        if (((pbVar30 != (uint8_t *)0x0) && (0x7f < sVar3)) && (uVar22 = (uint32_t)*pbVar30, 3 < uVar22)) {
          uVar22 = 4;
        }
        lVar26 = *(long *)(lVar21 + 0x20);
        plVar15 = calloc((unsigned long)uVar22,0x20);
        if (uVar22 != 0) {
          uVar28 = 0;
          uVar5 = 0;
          if (uVar22 != 0) {
            uVar5 = (int)sVar3 / (int)uVar22;
          }
          uVar13 = 0;
          plVar27 = plVar15;
          do {
            *(short *)((long)plVar27 + 0x12) = (short)uVar28;
            *(char *)((long)plVar27 + 0x17) = !bVar8 & bVar9;
            *(uint8_t *)((long)plVar27 + 0x16) = bVar25;
            uVar6 = uVar28 >> 2 & 0x3fff;
            *(bool *)(plVar27 + 3) = !bVar8 && (bVar25 & 6) == 4;
            *(short *)(plVar27 + 2) = (short)local_2220;
            sVar4 = (short)(uVar5 & 0xfffc) + (short)uVar28;
            if (uVar22 - 1 <= uVar13) {
              sVar4 = sVar3;
            }
            *(short *)((long)plVar27 + 0x14) = sVar4;
            *plVar27 = (long)plVar14 +
                       (unsigned long)(((-local_2220 & 3) + (int)(short)local_2220 >> 2) * iVar12 * uVar6);
            plVar27[1] = lVar26 + (int)((-(local_2220 >> 0xf & 1) & 0xfff00000 |
                                        (local_2220 & 0xffff) << 4) * uVar6);
            if (uVar22 < 2) {
              FUN_0015ecb0(plVar27);
            }
            else {
              puVar16 = malloc(0x18);
              *puVar16 = FUN_0015ecb0;
              puVar16[1] = plVar27;
              puVar16[2] = 0;
              pthread_mutex_lock((pthread_mutex_t *)(pbVar30 + 4));
              if (*(long *)(pbVar30 + 0xb8) == 0) {
                pbVar24 = pbVar30 + 0xb8;
              }
              else {
                pbVar24 = (uint8_t *)(*(long *)(pbVar30 + 0xc0) + 0x10);
              }
              *(uint64_t **)pbVar24 = puVar16;
              *(uint64_t **)(pbVar30 + 0xc0) = puVar16;
              pthread_cond_signal((pthread_cond_t *)(pbVar30 + 0x2c));
              pthread_mutex_unlock((pthread_mutex_t *)(pbVar30 + 4));
            }
            uVar13 = uVar13 + 1;
            plVar27 = plVar27 + 4;
            uVar28 = uVar28 + (uVar5 & 0xfffc);
          } while (uVar22 != uVar13);
        }
        if (1 < uVar22) {
          pthread_mutex_lock((pthread_mutex_t *)(pbVar30 + 0x5c));
          while ((((pbVar30[2] == 0 && (*pbVar30 != 0)) || (*(long *)(pbVar30 + 0xb8) != 0)) ||
                 (pbVar30[1] != 0))) {
            pthread_cond_wait((pthread_cond_t *)(pbVar30 + 0x84),(pthread_mutex_t *)(pbVar30 + 0x5c)
                             );
          }
          pthread_mutex_unlock((pthread_mutex_t *)(pbVar30 + 0x5c));
        }
        free(plVar15);
        if ((local_2258 != 0) && (*(short *)(param_1 + 0x38) != 0)) {
          uStack_2128 = 0;
          local_2130 = 0;
          uStack_2118 = 0;
          uStack_2120 = 0;
          uStack_2148 = 0;
          local_2150 = 0;
          uStack_2138 = 0;
          uStack_2140 = 0;
          uStack_2168 = 0;
          auStack_2170 = (uint8_t  [5])0x0;
          uStack_216b = 0;
          uStack_2158 = 0;
          uStack_2160 = 0;
          lStack_2188 = 0;
          (*(uint64_t*)((char*)&local_2210 + 128)) = 0;
          uStack_2178 = 0;
          local_2173 = 0;
          acStack_2180[0] = '\0';
          acStack_2180[1] = '\0';
          acStack_2180[2] = '\0';
          acStack_2180[3] = '\0';
          acStack_2180[4] = '\0';
          acStack_2180[5] = '\0';
          acStack_2180[6] = '\0';
          acStack_2180[7] = '\0';
          iVar12 = stat("/data/data/com.winlator/cache/vortek",(stat *)(local_2210 + 0x80));
          if (iVar12 == -1) {
            mkdir("/data/data/com.winlator/cache/vortek",0x1f9);
          }
          pcVar17 = (char *)FUN_0015ebd8("/data/data/com.winlator/cache/vortek/.cache-size",0,0);
          if (pcVar17 == (char *)0x0) {
            uVar13 = 0;
          }
          else {
            uVar13 = strtoll(pcVar17,(char **)0x0,10);
            free(pcVar17);
            sVar3 = *(short *)(param_1 + 0x38);
            for (; (unsigned long)((long)sVar3 * 0x100000) < uVar13; uVar13 = uVar13 - local_1188) {
              memset(local_2210 + 0x80,0,0x1010);
              __dirp = opendir("/data/data/com.winlator/cache/vortek");
              (*(uint64_t*)((char*)&local_2210 + 128)) = (*(uint64_t*)((char*)&local_2210 + 128)) & 0xffffffffffffff00;
              local_1190 = 0;
              if (__dirp == (DIR *)0x0) goto LAB_0015db9c;
              memset(local_1080,0,0x1000);
              uStack_1089 = 0;
              uStack_1090 = 0;
              uStack_1098 = 0;
              local_1091 = 0;
              uStack_10a0 = 0;
              uStack_10a8 = 0;
              local_10b0 = 0;
              uStack_10b8 = 0;
              local_10c0 = 0;
              uStack_10c8 = 0;
              local_10d0 = 0;
              uStack_10d8 = 0;
              local_10e0 = 0;
              uStack_10e8 = 0;
              local_10f0 = 0;
              uStack_10f8 = 0;
              local_1100 = 0;
              uStack_1108 = 0;
              local_1110 = 0;
              uStack_1118 = 0;
              local_1120 = 0;
              uStack_1128 = 0;
              local_1130 = 0;
              uStack_1138 = 0;
              local_1140 = 0;
              uStack_1148 = 0;
              local_1150 = 0;
              uStack_1158 = 0;
              local_1160 = 0;
              uStack_1168 = 0;
              local_1170 = 0;
              uStack_1178 = 0;
              local_1180 = 0;
              uVar23 = 0xffffffffffffffff;
              lVar26 = 0;
              while (pdVar18 = readdir(__dirp), pdVar18 != (dirent *)0x0) {
                if (pdVar18->d_name[0] != '.') {
                  auStack_1060 = (uint8_t  [5])0x6b657472;
                  uStack_1068 = 0x6568636163;
                  uStack_1063 = 0x6f762f;
                  builtin_strncpy(local_1080 + 0x10,"inlator/",8);
                  pcVar17 = pdVar18->d_name;
                  (*(uint64_t*)((char*)&local_2210 + 104)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 96)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 120)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 112)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 72)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 64)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 88)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 80)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 40)) = 0;
                  (*(uint32_t*)((char*)&local_2210 + 32)) = 0;
                  (*(uint32_t*)((char*)&local_2210 + 36)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 56)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 48)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 8)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 0)) = 0;
                  (*(uint32_t*)((char*)&local_2210 + 24)) = 0;
                  (*(uint32_t*)((char*)&local_2210 + 28)) = 0;
                  (*(uint64_t*)((char*)&local_2210 + 16)) = 0;
                  builtin_strncpy(local_1080,"/data/data/com.w",0x10);
                  if (*pcVar17 != '/') {
                    __strcat_chk(auStack_1060 + 4,&DAT_0011bdb1,0xfdc);
                  }
                  __strcat_chk(auStack_1060 + 4,pcVar17,0xfdc);
                  iVar12 = stat(local_1080,(stat *)local_2210);
                  if ((iVar12 == 0) &&
                     (uVar29 = (unsigned long)((*(uint64_t*)((char*)&local_2210 + 96)) + (*(uint64_t*)((char*)&local_2210 + 88)) * 1000000000) / 1000000
                     , uVar29 < uVar23)) {
                    __strcpy_chk(&local_1180,pcVar17,0xff);
                    uVar23 = uVar29;
                    lVar26 = (*(uint64_t*)((char*)&local_2210 + 48));
                  }
                }
              }
              closedir(__dirp);
              if (uVar23 == 0xffffffffffffffff) goto LAB_0015db9c;
              (*(uint8_t*)((char*)&lStack_2188 + 0)) = 't';
              (*(uint8_t*)((char*)&lStack_2188 + 1)) = 'a';
              (*(uint8_t*)((char*)&lStack_2188 + 2)) = '/';
              (*(uint8_t*)((char*)&lStack_2188 + 3)) = 'c';
              (*(uint8_t*)((char*)&lStack_2188 + 4)) = 'o';
              (*(uint8_t*)((char*)&lStack_2188 + 5)) = 'm';
              (*(uint8_t*)((char*)&lStack_2188 + 6)) = '.';
              (*(uint8_t*)((char*)&lStack_2188 + 7)) = 'w';
              local_2210[0x80] = '/';
              local_2210[0x81] = 'd';
              local_2210[0x82] = 'a';
              local_2210[0x83] = 't';
              local_2210[0x84] = 'a';
              local_2210[0x85] = '/';
              local_2210[0x86] = 'd';
              local_2210[0x87] = 'a';
              uStack_2178 = 0x6568636163;
              builtin_strncpy(acStack_2180,"inlator/",8);
              local_2173 = 0x6f762f;
              auStack_2170 = (uint8_t  [5])0x6b657472;
              if ((char)local_1180 != '/') {
                __strcat_chk(auStack_2170 + 4,&DAT_0011bdb1,0xfec);
              }
              __strcat_chk(auStack_2170 + 4,&local_1180,0xfec);
              local_1190 = uVar23;
              local_1188 = lVar26;
              iVar12 = remove(local_2210 + 0x80);
              if (iVar12 != 0) goto LAB_0015db9c;
            }
          }
          uStack_2128 = 0;
          local_2130 = 0;
          uStack_2118 = 0;
          uStack_2120 = 0;
          uStack_2148 = 0;
          local_2150 = 0;
          uStack_2138 = 0;
          uStack_2140 = 0;
          uStack_2168 = 0;
          auStack_2170 = (uint8_t  [5])0x0;
          uStack_216b = 0;
          uStack_2158 = 0;
          uStack_2160 = 0;
          lStack_2188 = 0;
          (*(uint64_t*)((char*)&local_2210 + 128)) = 0;
          uStack_2178 = 0;
          local_2173 = 0;
          acStack_2180[0] = '\0';
          acStack_2180[1] = '\0';
          acStack_2180[2] = '\0';
          acStack_2180[3] = '\0';
          acStack_2180[4] = '\0';
          acStack_2180[5] = '\0';
          acStack_2180[6] = '\0';
          acStack_2180[7] = '\0';
          FUN_0015eb34(local_2210 + 0x80,0x80,
                       "/data/data/com.winlator/cache/vortek/%lx-%dx%d-%d.imd",local_2258,
                       (long)*(short *)(lVar21 + 0xc),(long)*(short *)(lVar21 + 0xe),
                       *(uint32_t *)(lVar21 + 8));
          sVar3 = *(short *)(lVar21 + 0xc);
          sVar4 = *(short *)(lVar21 + 0xe);
          __ptr = *(void **)(lVar21 + 0x20);
          pFVar19 = fopen(local_2210 + 0x80,"wb");
          if (pFVar19 != (FILE *)0x0) {
            __n = (size_t)((int)sVar3 * (int)sVar4 * 4);
            sVar20 = fwrite(__ptr,1,__n,pFVar19);
            fclose(pFVar19);
            if (sVar20 == __n) {
              uStack_1068 = 0;
              uStack_1063 = 0;
              local_1080[0x10] = '\0';
              local_1080[0x11] = '\0';
              local_1080[0x12] = '\0';
              local_1080[0x13] = '\0';
              local_1080[0x14] = '\0';
              local_1080[0x15] = '\0';
              local_1080[0x16] = '\0';
              local_1080[0x17] = '\0';
              local_1080[8] = '\0';
              local_1080[9] = '\0';
              local_1080[10] = '\0';
              local_1080[0xb] = '\0';
              local_1080[0xc] = '\0';
              local_1080[0xd] = '\0';
              local_1080[0xe] = '\0';
              local_1080[0xf] = '\0';
              local_1080[0] = '\0';
              local_1080[1] = '\0';
              local_1080[2] = '\0';
              local_1080[3] = '\0';
              local_1080[4] = '\0';
              local_1080[5] = '\0';
              local_1080[6] = '\0';
              local_1080[7] = '\0';
              FUN_0015eb34(local_1080,0x20,&DAT_0011c019,uVar13 + __n);
              lVar21 = __strlen_chk(local_1080,0x20);
              pFVar19 = fopen("/data/data/com.winlator/cache/vortek/.cache-size","wb");
              if (pFVar19 != (FILE *)0x0) {
                lVar26 = __fwrite_chk(local_1080,1,lVar21,pFVar19,0x20);
                fclose(pFVar19);
                if (lVar26 == lVar21) goto LAB_0015db9c;
              }
            }
          }
          remove(local_2210 + 0x80);
        }
      }
      else {
        uVar13 = (unsigned long)(iVar12 * (uint32_t)(uVar2 >> 2) * (uint32_t)(*(uint16_t *)(lVar21 + 0xe) >> 2));
        uVar23 = uVar13 * -0x395b586ca42e166b ^ (unsigned long)*(uint32_t *)(lVar21 + 8);
        plVar15 = plVar14;
        for (; uVar13 != 0; uVar13 = uVar13 - 8) {
          uVar23 = ((*plVar15 * -0x395b586ca42e166b ^
                    (unsigned long)(*plVar15 * -0x395b586ca42e166b) >> 0x2f) * -0x395b586ca42e166b ^ uVar23)
                   * -0x395b586ca42e166b;
          plVar15 = plVar15 + 1;
        }
        uStack_1008 = 0;
        local_1010 = 0;
        uStack_1018 = 0;
        local_1020 = 0;
        uStack_1028 = 0;
        local_1030 = 0;
        uStack_1038 = 0;
        local_1040 = 0;
        uStack_1048 = 0;
        local_1050 = 0;
        uStack_1058 = 0;
        auStack_1060 = (uint8_t  [5])0x0;
        uStack_105b = 0;
        uStack_1068 = 0;
        uStack_1063 = 0;
        local_1080[0x10] = '\0';
        local_1080[0x11] = '\0';
        local_1080[0x12] = '\0';
        local_1080[0x13] = '\0';
        local_1080[0x14] = '\0';
        local_1080[0x15] = '\0';
        local_1080[0x16] = '\0';
        local_1080[0x17] = '\0';
        local_1080[8] = '\0';
        local_1080[9] = '\0';
        local_1080[10] = '\0';
        local_1080[0xb] = '\0';
        local_1080[0xc] = '\0';
        local_1080[0xd] = '\0';
        local_1080[0xe] = '\0';
        local_1080[0xf] = '\0';
        local_1080[0] = '\0';
        local_1080[1] = '\0';
        local_1080[2] = '\0';
        local_1080[3] = '\0';
        local_1080[4] = '\0';
        local_1080[5] = '\0';
        local_1080[6] = '\0';
        local_1080[7] = '\0';
        local_2258 = (uVar23 ^ uVar23 >> 0x2f) * -0x395b586ca42e166b;
        local_2258 = local_2258 ^ local_2258 >> 0x2f;
        FUN_0015eb34(local_1080,0x80,"/data/data/com.winlator/cache/vortek/%lx-%dx%d-%d.imd",
                     local_2258,(long)*(short *)(lVar21 + 0xc),(long)*(short *)(lVar21 + 0xe),
                     *(uint32_t *)(lVar21 + 8));
        uStack_2128 = 0;
        local_2130 = 0;
        uStack_2118 = 0;
        uStack_2120 = 0;
        uStack_2148 = 0;
        local_2150 = 0;
        uStack_2138 = 0;
        uStack_2140 = 0;
        uStack_2168 = 0;
        auStack_2170 = (uint8_t  [5])0x0;
        uStack_216b = 0;
        uStack_2158 = 0;
        uStack_2160 = 0;
        lStack_2188 = 0;
        (*(uint64_t*)((char*)&local_2210 + 128)) = 0;
        uStack_2178 = 0;
        local_2173 = 0;
        acStack_2180[0] = '\0';
        acStack_2180[1] = '\0';
        acStack_2180[2] = '\0';
        acStack_2180[3] = '\0';
        acStack_2180[4] = '\0';
        acStack_2180[5] = '\0';
        acStack_2180[6] = '\0';
        acStack_2180[7] = '\0';
        iVar12 = stat("/data/data/com.winlator/cache/vortek",(stat *)(local_2210 + 0x80));
        if (iVar12 == -1) {
          mkdir("/data/data/com.winlator/cache/vortek",0x1f9);
        }
        (*(uint64_t*)((char*)&local_2210 + 128)) =
             ((int64_t)(int32_t)((int)*(short *)(lVar21 + 0xc) * (int)*(short *)(lVar21 + 0xe) * 4));
        lVar26 = FUN_0015ebd8(local_1080,*(uint64_t *)(lVar21 + 0x20),local_2210 + 0x80);
        if (lVar26 == 0) {
          local_2220 = (uint32_t)*(uint16_t *)(lVar21 + 0xc);
          goto LAB_0015de24;
        }
      }
LAB_0015db9c:
      munmap(__addr,*(size_t *)(*(long *)(lVar1 + 0x10) + 0x20));
LAB_0015dbac:
      uVar13 = ArrayDeque_isEmpty(param_1 + 0x20);
    } while ((uVar13 & 1) == 0);
  }
  if (*(long *)(lVar7 + 0x28) == local_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0015da9c  size=76 */

void TextureDecoder_destroy(void *param_1)

{
  if (*(void **)((long)param_1 + 8) != (void *)0x0) {
    free(*(void **)((long)param_1 + 8));
    *(uint64_t *)((long)param_1 + 8) = 0;
  }
  if (*(void **)((long)param_1 + 0x18) != (void *)0x0) {
    free(*(void **)((long)param_1 + 0x18));
    *(uint64_t *)((long)param_1 + 0x18) = 0;
  }
  if (*(void **)((long)param_1 + 0x30) != (void *)0x0) {
    free(*(void **)((long)param_1 + 0x30));
  }
  free(param_1);
  return;
}


/* @0015e8a8  size=252 */

void TextureDecoder_destroyImage(uint32_t *param_1,uint64_t param_2,long param_3)

{
  unsigned long uVar1;
  long *__ptr;
  
  if (0 < (int)*param_1) {
    uVar1 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 2) + uVar1 * 8) == param_3) {
        if ((int)uVar1 == -1) {
          return;
        }
        __ptr = *(long **)(*(long *)(param_1 + 2) + uVar1 * 8);
        if (__ptr[4] != 0) {
          ((generic_fn_t)DAT_00193b98)(param_2,__ptr[3]);
        }
        if (*__ptr != 0) {
          ((generic_fn_t)DAT_00193c98)(param_2,*__ptr,0);
        }
        if (__ptr[2] != 0) {
          ((generic_fn_t)DAT_00193c78)(param_2,__ptr[2],0);
        }
        if (__ptr[3] != 0) {
          ((generic_fn_t)DAT_00193b88)(param_2,__ptr[3],0);
        }
        free(__ptr);
        ArrayList_removeAt(param_1,uVar1 & 0xffffffff);
        return;
      }
      uVar1 = uVar1 + 1;
    } while (*param_1 != uVar1);
  }
  return;
}


/* @0015ea6c  size=124 */

void TextureDecoder_removeBoundBuffer(long param_1,long param_2)

{
  void *__ptr;
  unsigned long uVar1;
  
  if (0 < (int)*(uint32_t *)(param_1 + 0x10)) {
    uVar1 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 0x18) + uVar1 * 8) == param_2) {
        if ((int)uVar1 == -1) {
          return;
        }
        __ptr = *(void **)(*(long *)(param_1 + 0x18) + uVar1 * 8);
        if (__ptr != (void *)0x0) {
          free(__ptr);
        }
        ArrayList_removeAt(param_1 + 0x10,uVar1 & 0xffffffff);
        return;
      }
      uVar1 = uVar1 + 1;
    } while (*(uint32_t *)(param_1 + 0x10) != uVar1);
  }
  return;
}


