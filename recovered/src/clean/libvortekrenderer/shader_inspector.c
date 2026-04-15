/*
 * shader_inspector.c — SPIRV shader analysis
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015f830  size=320 */

void * ShaderInspector_create(long param_1,uint64_t param_2,long param_3)

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  uint8_t bVar7;
  uint64_t local_3a0;
  uint32_t local_398;
  uint8_t auStack_390 [20];
  char acStack_37c [804];
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar1 + 0x28);
  pvVar5 = calloc(1,5);
  *(bool *)pvVar5 = *(int *)(param_3 + 0x94) == 0;
  memset(auStack_390,0,0x338);
  ((generic_fn_t)DAT_00193b08)(param_2,auStack_390);
  pcVar6 = strstr(acStack_37c,"Mali");
  if (*(char **)(param_1 + 0x108) == (char *)0x0) {
    bVar3 = false;
  }
  else {
    iVar4 = strcmp(*(char **)(param_1 + 0x108),"DXVK");
    bVar3 = iVar4 == 0;
  }
  if (pcVar6 == (char *)0x0) {
    bVar7 = 1;
    bVar2 = false;
  }
  else {
    local_398 = 0;
    local_3a0 = 0;
    ((generic_fn_t)DAT_00193b28)(param_2,0x28,&local_3a0);
    bVar7 = ((uint8_t)local_398 >> 6 ^ 0xff) & 1;
    bVar2 = bVar3;
  }
  *(uint8_t *)((long)pvVar5 + 1) = bVar7;
  *(bool *)((long)pvVar5 + 2) = bVar2;
  if (bVar3) {
    *(uint16_t *)((long)pvVar5 + 3) = 0x101;
  }
  if (*(long *)(lVar1 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar5;
}


/* @0015f970  size=680 */

void ShaderInspector_createModule
               (long param_1,uint64_t param_2,int *param_3,unsigned long param_4,uint64_t *param_5)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  uint32_t uVar5;
  bool bVar6;
  void *pvVar7;
  uint64_t uVar8;
  void *__dest;
  int iVar9;
  bool bVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  unsigned long local_68;
  int *piStack_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar4 + 0x28);
  pvVar7 = calloc(1,0x18);
  if ((*param_3 == 0x7230203) && (0x17 < (uint32_t)param_4)) {
    uVar5 = (uint32_t)(param_4 >> 2) & 0x3fffffff;
    iVar9 = 5;
    while( true ) {
      uVar1 = param_3[iVar9] & 0xffff;
      if (uVar1 == 0xf) break;
      iVar9 = iVar9 + ((uint32_t)param_3[iVar9] >> 0x10);
      if (((int)uVar5 <= iVar9) || (uVar1 == 0x36)) goto LAB_0015fb80;
    }
    if (iVar9 != -1) {
      uVar1 = param_3[(long)iVar9 + 1];
      if ((*(char *)(param_1 + 2) == '\0') || ((uVar1 & 0xfffffffb) != 0)) goto LAB_0015fb7c;
      bVar10 = false;
      iVar9 = 5;
      goto LAB_0015fa54;
    }
  }
  goto LAB_0015fb80;
LAB_0015fa54:
  do {
    uVar3 = param_3[iVar9];
    uVar2 = uVar3 & 0xffff;
    bVar6 = true;
    if (uVar2 < 0x5f) {
      if (uVar2 == 0x3e) {
LAB_0015fb68:
        bVar6 = false;
      }
      else if (uVar2 != 0x56) {
LAB_0015fa3c:
        bVar6 = bVar10;
      }
    }
    else if (uVar2 != 0x5f) {
      if ((uVar2 != 0xa9) || (!bVar10)) goto LAB_0015fa3c;
      piVar11 = param_3 + (long)iVar9 + 5;
      iVar13 = 5;
      while( true ) {
        uVar2 = param_3[iVar13];
        piVar12 = piVar11;
        if (((0x2ffff < uVar2) && ((uVar2 & 0xffff) == 0x2c)) &&
           (param_3[(long)iVar13 + 2] == *piVar11)) break;
        iVar13 = (uVar2 >> 0x10) + iVar13;
        if (((int)uVar5 <= iVar13) || ((uVar2 & 0xffff) == 0x36)) goto LAB_0015fb00;
      }
      if (iVar13 != -1) {
        piVar12 = param_3 + (long)iVar13 + 3;
      }
LAB_0015fb00:
      iVar13 = 5;
      while( true ) {
        uVar2 = param_3[iVar13];
        if (((0x2ffff < uVar2) && ((uVar2 & 0xffff) == 0x2b)) &&
           (param_3[(long)iVar13 + 2] == *piVar12)) break;
        iVar13 = (uVar2 >> 0x10) + iVar13;
        bVar6 = false;
        if (((int)uVar5 <= iVar13) || ((uVar2 & 0xffff) == 0x36)) goto LAB_0015fa40;
      }
      if ((iVar13 == -1) || (param_3[(long)iVar13 + 3] != 0)) goto LAB_0015fb68;
      *piVar11 = param_3[(long)iVar9 + 4];
      bVar6 = false;
    }
LAB_0015fa40:
    bVar10 = bVar6;
    iVar9 = (uVar3 >> 0x10) + iVar9;
  } while (iVar9 < (int)uVar5);
LAB_0015fb7c:
  if ((uVar1 & 0xfffffffb) == 0) {
    *(unsigned long *)((long)pvVar7 + 0x10) = param_4;
    __dest = malloc(param_4);
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_3,param_4);
    }
    uVar8 = 0;
    *(void **)((long)pvVar7 + 8) = __dest;
    goto LAB_0015fbb4;
  }
LAB_0015fb80:
  uStack_78 = 0;
  local_80 = 0x10;
  local_70 = 0;
  local_68 = param_4;
  piStack_60 = param_3;
  uVar8 = ((generic_fn_t)DAT_00193cb8)(param_2,&local_80,0,pvVar7);
LAB_0015fbb4:
  *param_5 = pvVar7;
  if (*(long *)(lVar4 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}


/* @0015fc18  size=4028 */

int ShaderInspector_inspectShaderStages
              (char *param_1,uint64_t param_2,long param_3,uint32_t param_4,long param_5)

{
  int iVar1;
  uint32_t *puVar2;
  void *__src;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  short sVar7;
  uint32_t uVar8;
  uint8_t *puVar9;
  int iVar10;
  uint32_t uVar11;
  void *__dest;
  uint64_t extraout_x1;
  uint64_t extraout_x1_00;
  uint64_t extraout_x1_01;
  uint64_t extraout_x1_02;
  uint64_t extraout_x1_03;
  uint32_t uVar12;
  long lVar13;
  uint32_t uVar14;
  uint32_t *puVar15;
  long lVar16;
  uint32_t uVar17;
  long lVar18;
  int iVar19;
  int iVar20;
  uint64_t *puVar21;
  unsigned long uVar22;
  long lVar23;
  int *piVar24;
  uint32_t *puVar25;
  uint64_t *puVar26;
  unsigned long uVar27;
  int iVar28;
  uint32_t uVar29;
  unsigned long uVar30;
  unsigned long uVar31;
  int iVar32;
  long *plVar33;
  long *plVar34;
  size_t __size;
  unsigned long uVar35;
  size_t __n;
  simd128_t auVar36;
  uint64_t auStack_210;
  uint32_t local_208;
  int local_204;
  long local_200;
  unsigned long uStack_1f8;
  uint32_t *local_1f0;
  uint64_t *local_1e8;
  unsigned long local_1e0;
  uint32_t local_1d4;
  long local_1d0;
  uint8_t *local_1c8;
  unsigned long local_1c0;
  long local_1b8;
  long local_1b0;
  uint64_t local_1a8;
  char *local_1a0;
  long *local_198;
  uint32_t local_18c;
  long local_188;
  unsigned long local_180;
  long local_178;
  unsigned long local_170;
  uint64_t *local_168;
  unsigned long local_160;
  void *local_158;
  unsigned long *local_150;
  uint32_t local_148;
  int iStack_144;
  uint64_t local_140;
  uint64_t local_138;
  uint32_t local_130;
  int iStack_12c;
  uint64_t local_128;
  uint32_t local_120;
  int iStack_11c;
  long local_118;
  uint32_t local_110;
  unsigned long *local_108;
  uint32_t local_100;
  int iStack_fc;
  uint64_t local_f8;
  uint64_t local_f0;
  uint32_t local_e8;
  uint32_t uStack_e4;
  uint64_t local_e0;
  uint32_t local_d8;
  int local_d4;
  long local_d0;
  uint64_t uStack_c8;
  unsigned long *local_c0;
  uint64_t local_b8;
  uint64_t local_b0;
  uint64_t local_a8;
  int local_a0;
  uint32_t uStack_9c;
  uint64_t local_98;
  uint64_t local_90;
  long local_80;
  
  puVar9 = auStack_210;
  /* stack canary setup */
  local_80 = *(long *)(lVar13 + 0x28);
  local_1a8 = param_2;
  local_1a0 = param_1;
  if (param_4 != 0) {
    uVar35 = 0;
    plVar34 = (long *)0x0;
    uVar27 = (unsigned long)param_4;
    local_1e8 = (uint64_t *)(local_b0 + 4);
    local_1f0 = &uStack_9c;
    local_1d4 = param_4;
    local_1d0 = lVar13;
    local_1b8 = param_5;
    local_1b0 = param_3;
LAB_0015fd14:
    plVar33 = *(long **)(param_3 + uVar35 * 0x30 + 0x18);
    if ((plVar33 != (long *)0x0) && (*plVar33 == 0)) {
      iVar32 = *(int *)(param_3 + uVar35 * 0x30 + 0x14);
      local_198 = plVar33;
      if (iVar32 == 1) {
        plVar34 = plVar33;
        if (param_5 == 0) goto LAB_0015fcbc;
        local_188 = (long)puVar9 - ((unsigned long)*(uint32_t *)(param_5 + 0x20) * 0x18 + 0xf & 0x3ffffffff0);
        uVar30 = (unsigned long)*(uint32_t *)(param_5 + 0x20);
        local_1c8 = puVar9;
        if (*(uint32_t *)(param_5 + 0x20) == 0) {
          local_18c = 0;
        }
        else {
          local_18c = 0;
          puVar25 = (uint32_t *)(*(long *)(param_5 + 0x28) + 8);
          do {
            uVar11 = *puVar25;
            auVar36 = isFormatScaled(uVar11);
            param_2 = (*(uint64_t*)((char*)&auVar36 + 8));
            if (((*(uint64_t*)((char*)&auVar36 + 0)) & 1) != 0) {
              uVar12 = 0xd;
              switch(uVar11) {
              case 0xb:
                break;
              case 0xc:
                uVar12 = 0xe;
                break;
              default:
                uVar12 = uVar11;
                break;
              case 0x12:
                uVar12 = 0x14;
                break;
              case 0x13:
                uVar12 = 0x15;
                break;
              case 0x27:
                uVar12 = 0x29;
                break;
              case 0x28:
                uVar12 = 0x2a;
                break;
              case 0x48:
                uVar12 = 0x4a;
                break;
              case 0x49:
                uVar12 = 0x4b;
                break;
              case 0x4f:
                uVar12 = 0x51;
                break;
              case 0x50:
                uVar12 = 0x52;
                break;
              case 0x5d:
                uVar12 = 0x5f;
                break;
              case 0x5e:
                uVar12 = 0x60;
              }
              uVar11 = puVar25[-2];
              *puVar25 = uVar12;
              puVar15 = (uint32_t *)(local_188 + (long)(int)local_18c * 0x18);
              puVar15[5] = uVar12;
              *(uint64_t *)(puVar15 + 1) = 0xffffffffffffffff;
              *puVar15 = uVar11;
              puVar15[3] = 0xffffffff;
              local_18c = local_18c + 1;
            }
            uVar30 = uVar30 - 1;
            puVar25 = puVar25 + 4;
          } while (uVar30 != 0);
        }
        local_170 = 0;
        local_168 = (uint64_t *)0x0;
        local_180 = 0;
        local_178 = 0;
        iVar32 = (int)((unsigned long)plVar33[2] >> 2);
        local_1c0 = uVar35;
        if (5 < iVar32) {
          iVar28 = 5;
LAB_0016017c:
          lVar13 = plVar33[1];
          lVar16 = (long)iVar28;
          uVar14 = *(uint32_t *)(lVar13 + (long)iVar28 * 4);
          uVar29 = uVar14 & 0xffff;
          if (uVar29 == 0x47) {
            lVar23 = lVar13 + lVar16 * 4;
            if (*(int *)(lVar23 + 8) == 0xb) {
              iVar19 = *(int *)(lVar23 + 0xc);
              if ((*local_1a0 != '\0') && (iVar19 == 3)) goto LAB_001601e4;
              if ((local_1a0[3] != '\0') && (iVar19 == 1)) {
                uVar17 = *(uint32_t *)(plVar33 + 2) >> 2;
                uVar3 = uVar14;
                iVar19 = iVar28;
                if (iVar28 < (int)uVar17) {
                  while (((uVar3 < 0x30000 || ((uVar3 & 0xffff) != 0x16)) ||
                         (*(int *)(lVar13 + (long)iVar19 * 4 + 8) != 0x20))) {
                    iVar19 = (uVar3 >> 0x10) + iVar19;
                    if (((int)uVar17 <= iVar19) || ((uVar3 & 0xffff) == 0x36)) goto LAB_001601f0;
                    uVar3 = *(uint32_t *)(lVar13 + (long)iVar19 * 4);
                  }
                  if (iVar19 != -1) {
                    uVar3 = uVar14;
                    iVar10 = iVar28;
                    goto LAB_001602a8;
                  }
                }
              }
            }
          }
          else if (((uVar29 == 0x11) && (*local_1a0 != '\0')) &&
                  (*(int *)(lVar13 + lVar16 * 4 + 4) == 0x20)) {
LAB_001601e4:
            IntArray_add(&local_180,iVar28);
            param_2 = extraout_x1_00;
          }
          goto LAB_001601f0;
        }
        goto LAB_00160588;
      }
      if (((iVar32 == 0x10) && (plVar34 != (long *)0x0)) && (local_1a0[4] != '\0')) {
        local_160 = 0;
        local_158 = (void *)0x0;
        local_170 = 0;
        local_168 = (uint64_t *)0x0;
        FUN_00161118(plVar34,3,&local_170);
        local_180 = 0;
        local_178 = 0;
        FUN_00161118(plVar33,1,&local_180);
        if (0 < (int)(uint32_t)local_180) {
          lVar16 = plVar33[1];
          lVar13 = 0;
          iVar32 = (uint32_t)local_180;
LAB_0015fdec:
          piVar24 = *(int **)(local_178 + lVar13 * 8);
          iVar28 = piVar24[3];
          uVar29 = *(uint32_t *)(lVar16 + (long)iVar28 * 4);
          if ((uVar29 & 0xffff) == 0x17) {
            uVar14 = *(uint32_t *)(lVar16 + (long)(iVar28 + 3) * 4);
          }
          else {
            uVar14 = 1;
          }
          uVar30 = local_170 & 0xffffffff;
          if (0 < (int)(uint32_t)local_170) {
            iVar19 = *piVar24;
            lVar23 = plVar34[1];
            puVar21 = local_168;
            do {
              lVar18 = (long)((int *)*puVar21)[3];
              sVar7 = *(short *)(lVar23 + lVar18 * 4);
              if (sVar7 == 0x17) {
                uVar17 = *(uint32_t *)(lVar23 + lVar18 * 4 + 0xc);
              }
              else {
                uVar17 = 1;
              }
              if ((*(int *)(lVar16 + (long)(iVar19 + 3) * 4) ==
                   *(int *)(lVar23 + (long)*(int *)*puVar21 * 4 + 0xc)) && (uVar14 != uVar17)) {
                if (uVar14 < 2) {
                  iVar10 = *(int *)(lVar16 + (long)(iVar28 + 1) * 4);
                  goto LAB_0015ff04;
                }
                if (iVar19 < (int)(*(uint32_t *)(plVar33 + 2) >> 2)) {
                  iVar10 = *(int *)(lVar16 + (long)(iVar28 + 2) * 4);
                  iVar28 = iVar19;
                  goto LAB_0015feac;
                }
                break;
              }
              uVar30 = uVar30 - 1;
              puVar21 = puVar21 + 1;
            } while (uVar30 != 0);
          }
          goto LAB_0015fde0;
        }
LAB_001600ac:
        ArrayList_free(&local_170,1);
        ArrayList_free(&local_180,1);
        param_3 = local_1b0;
        while (0 < (int)(uint32_t)local_160) {
          uVar30 = 0;
          iVar32 = 0;
          iVar28 = -0x7fffffff;
          do {
            iVar19 = **(int **)((long)local_158 + uVar30 * 8);
            iVar10 = (int)uVar30;
            if (iVar19 <= iVar28) {
              iVar19 = iVar28;
              iVar10 = iVar32;
            }
            iVar32 = iVar10;
            uVar30 = uVar30 + 1;
            iVar28 = iVar19;
          } while ((uint32_t)local_160 != uVar30);
          puVar25 = *(uint32_t **)((long)local_158 + (long)iVar32 * 8);
          FUN_00160c08(plVar33,puVar25 + 2,*puVar25);
          free(puVar25);
          ArrayList_removeAt(&local_160,iVar32);
        }
        param_5 = local_1b8;
        if (local_158 != (void *)0x0) {
          free(local_158);
          param_5 = local_1b8;
        }
      }
      goto LAB_0015fcbc;
    }
    goto LAB_0015fd08;
  }
  iVar32 = 0;
LAB_00160b98:
  if (*(long *)(lVar13 + 0x28) == local_80) {
    return iVar32;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_001602a8:
  if (((0x2ffff < uVar3) && ((uVar3 & 0xffff) == 0x2b)) &&
     ((*(int *)(lVar13 + (unsigned long)(iVar10 + 1) * 4) == *(int *)(lVar13 + (long)iVar19 * 4 + 4) &&
      (*(int *)(lVar13 + (unsigned long)(iVar10 + 3) * 4) == 0x3f800000)))) {
    if (iVar10 != -1) {
      iVar20 = *(int *)(lVar13 + lVar16 * 4 + 4);
      iVar19 = iVar28;
      goto LAB_00160330;
    }
    goto LAB_001601f0;
  }
  iVar10 = (uVar3 >> 0x10) + iVar10;
  if (((int)uVar17 <= iVar10) || ((uVar3 & 0xffff) == 0x36)) goto LAB_001601f0;
  uVar3 = *(uint32_t *)(lVar13 + (long)iVar10 * 4);
  goto LAB_001602a8;
  while (iVar19 = (uVar3 >> 0x10) + iVar19, iVar19 < (int)uVar17) {
LAB_00160330:
    uVar3 = *(uint32_t *)(lVar13 + (long)iVar19 * 4);
    if (((0x1ffff < uVar3) && ((uVar3 & 0xffff) == 0x3e)) &&
       (*(int *)(lVar13 + (long)iVar19 * 4 + 4) == iVar20)) {
      if (iVar19 == -1) break;
      uVar8 = uVar14;
      iVar1 = iVar28;
      if (*(int *)(lVar13 + (long)iVar19 * 4 + 8) == *(int *)(lVar13 + (long)(iVar10 + 2) * 4))
      goto LAB_00160390;
      iVar19 = (uVar3 >> 0x10) + iVar19;
      if ((int)uVar17 <= iVar19) break;
      goto LAB_00160330;
    }
  }
LAB_001601f0:
  iVar28 = (uVar14 >> 0x10) + iVar28;
  if (((iVar32 <= iVar28) || (uVar29 == 0x36)) || (uVar29 - 0x13 < 0x15)) goto LAB_001604b4;
  goto LAB_0016017c;
LAB_00160390:
  if (((0x2ffff < uVar8) && ((uVar8 & 0xffff) == 0x3b)) &&
     (*(int *)(lVar13 + (long)iVar1 * 4 + 8) == iVar20)) {
    if (iVar1 != -1) {
      lVar16 = (long)iVar1 + 3;
      if (*(int *)(lVar13 + lVar16 * 4) == 3) {
        lVar23 = (long)iVar1 + 1;
        uVar3 = uVar14;
        iVar19 = iVar28;
        goto LAB_00160404;
      }
    }
    goto LAB_001601f0;
  }
  iVar1 = (uVar8 >> 0x10) + iVar1;
  if (((int)uVar17 <= iVar1) || ((uVar8 & 0xffff) == 0x36)) goto LAB_001601f0;
  uVar8 = *(uint32_t *)(lVar13 + (long)iVar1 * 4);
  goto LAB_00160390;
LAB_00160404:
  if (((0x1ffff < uVar3) && ((uVar3 & 0xffff) == 0x20)) &&
     (*(int *)(lVar13 + (long)iVar19 * 4 + 4) == *(int *)(lVar13 + lVar23 * 4))) {
    if (iVar19 != -1) {
      uStack_9c = *(uint32_t *)(lVar13 + (long)iVar19 * 4 + 0xc);
      local_c0 = &local_170;
      uStack_c8 = ((uint64_t)((*(uint32_t*)((char*)&uStack_c8 + 4))) << 32 | (uint32_t)(*(uint32_t *))(plVar33 + 2));
      local_b8 = ((uint64_t)(iVar28) << 32 | (uint32_t)(iVar19));
      local_b0 = (uint8_t  [8])0x300000002;
      local_a8 = 0;
      local_98 = 0;
      local_a0 = 6;
      local_90 = 2;
      local_d0 = lVar13;
      uVar11 = FUN_00160cb8(&local_d0,param_2,0x20,0xffffffff,6);
      lVar13 = local_198[1];
      *(uint32_t *)(lVar13 + lVar16 * 4) = 6;
      *(uint32_t *)(lVar13 + lVar23 * 4) = uVar11;
      plVar33 = local_198;
      goto LAB_001601e4;
    }
    goto LAB_001601f0;
  }
  iVar19 = (uVar3 >> 0x10) + iVar19;
  if (((int)uVar17 <= iVar19) || ((uVar3 & 0xffff) == 0x36)) goto LAB_001601f0;
  uVar3 = *(uint32_t *)(lVar13 + (long)iVar19 * 4);
  goto LAB_00160404;
LAB_001604b4:
  param_3 = local_1b0;
  if ((uint32_t)local_180 != 0) {
    local_1e0 = uVar27;
    IntArray_sort(&local_180);
    if (0 < (int)(uint32_t)local_180) {
      lVar13 = (local_180 & 0xffffffff) + 1;
      uVar29 = (uint32_t)local_180;
      do {
        uVar29 = uVar29 - 1;
        __n = (long)*(int *)(local_178 + (unsigned long)uVar29 * 4) * 4;
        __src = (void *)plVar33[1];
        puVar2 = (uint32_t *)((long)__src + __n);
        uVar35 = (unsigned long)(*puVar2 >> 0xe) & 0x3fffc;
        iVar32 = (int)plVar33[2] - ((int)__n + (int)uVar35);
        if (0 < iVar32) {
          __size = plVar33[2] - uVar35;
          __dest = malloc(__size);
          memcpy(__dest,__src,__n);
          memcpy((void *)((long)__dest + __n),(void *)((long)puVar2 + uVar35),(long)iVar32);
          plVar34 = local_198;
          if (__dest != (void *)0x0) {
            if ((void *)local_198[1] != (void *)0x0) {
              free((void *)local_198[1]);
            }
            plVar34[1] = (long)__dest;
            plVar34[2] = __size;
          }
        }
        lVar13 = lVar13 + -1;
        plVar33 = local_198;
      } while (1 < lVar13);
    }
    IntArray_clear(&local_180);
    param_2 = extraout_x1_01;
    param_3 = local_1b0;
    uVar27 = local_1e0;
  }
LAB_00160588:
  if ((local_1a0[1] != '\0') && (uVar35 = (unsigned long)plVar33[2] >> 2, 5 < (int)uVar35)) {
    lVar13 = plVar33[1];
    uVar30 = (unsigned long)local_18c;
    iVar32 = 5;
    uVar29 = local_18c;
LAB_001605b4:
    uVar17 = *(uint32_t *)(lVar13 + (long)iVar32 * 4);
    uVar14 = uVar17 & 0xffff;
    if (uVar14 == 0x47) {
      lVar16 = lVar13 + (long)iVar32 * 4;
      if ((*(int *)(lVar16 + 8) == 0x1e) && (0 < (int)uVar29)) {
        piVar24 = (int *)(local_188 + 0xc);
        uVar31 = uVar30;
        do {
          if (piVar24[-3] == *(int *)(lVar16 + 0xc)) {
            uVar3 = *(uint32_t *)(plVar33 + 2);
            uVar8 = uVar3 >> 2;
            if (iVar32 < (int)uVar8) {
              iVar19 = *(int *)(lVar13 + (long)iVar32 * 4 + 4);
              iVar28 = iVar32;
              goto LAB_00160628;
            }
            break;
          }
          uVar31 = uVar31 - 1;
          piVar24 = piVar24 + 6;
        } while (uVar31 != 0);
      }
    }
    goto LAB_00160910;
  }
LAB_00160934:
  puVar9 = local_1c8;
  param_5 = local_1b8;
  plVar34 = plVar33;
  uVar35 = local_1c0;
  if (0 < (int)(uint32_t)local_170) {
    do {
      uVar35 = 0;
      iVar32 = 0;
      iVar28 = -0x7fffffff;
      do {
        iVar19 = *(int *)local_168[uVar35];
        iVar10 = (int)uVar35;
        if (*(int *)local_168[uVar35] <= iVar28) {
          iVar19 = iVar28;
          iVar10 = iVar32;
        }
        iVar32 = iVar10;
        uVar35 = uVar35 + 1;
        iVar28 = iVar19;
      } while ((uint32_t)local_170 != uVar35);
      puVar25 = (uint32_t *)local_168[iVar32];
      FUN_00160c08(plVar33,puVar25 + 2,*puVar25);
      free(puVar25);
      ArrayList_removeAt(&local_170,iVar32);
    } while (0 < (int)(uint32_t)local_170);
    if (local_168 != (uint64_t *)0x0) {
      free(local_168);
      local_168 = (uint64_t *)0x0;
    }
    uVar30 = plVar33[2];
    if (0x17 < (uint32_t)uVar30) {
      iVar32 = 5;
      do {
        uVar29 = *(uint32_t *)(plVar33[1] + (long)iVar32 * 4);
        if ((uVar29 & 0xffff) == 0x36) goto LAB_001609f4;
        iVar32 = iVar32 + (uVar29 >> 0x10);
      } while (iVar32 < (int)((uint32_t)(uVar30 >> 2) & 0x3fffffff));
    }
    iVar32 = -1;
LAB_001609f4:
    local_d0 = 0;
    uStack_c8 = 0;
    puVar9 = local_1c8;
    param_3 = local_1b0;
    param_5 = local_1b8;
    uVar35 = local_1c0;
    if (0 < (int)local_18c) {
      uVar31 = 0;
      uVar22 = (unsigned long)local_18c;
      do {
        iVar28 = *(int *)(local_188 + uVar31 * 0x18 + 8);
        if ((iVar28 != -1) && (uVar35 = uVar30 >> 2 & 0x3fffffff, iVar32 < (int)uVar35)) {
          lVar13 = local_188 + uVar31 * 0x18;
          iVar19 = iVar32;
          do {
            lVar16 = plVar33[1];
            while( true ) {
              uVar29 = *(uint32_t *)(lVar16 + (long)iVar19 * 4);
              if (((0x3ffff < uVar29) && ((uVar29 & 0xffff) == 0x3d)) &&
                 (*(int *)(lVar16 + (long)iVar19 * 4 + 0xc) == iVar28)) break;
              iVar19 = (uVar29 >> 0x10) + iVar19;
              if ((int)uVar35 <= iVar19) goto LAB_00160a10;
            }
            if (iVar19 == -1) break;
            iVar10 = *(int *)(lVar16 + 0xc);
            iVar20 = *(int *)(lVar13 + 0x10);
            uVar11 = *(uint32_t *)(lVar13 + 4);
            lVar23 = lVar16 + (long)iVar19 * 4;
            uVar12 = *(uint32_t *)(lVar23 + 8);
            *(int *)(lVar16 + 0xc) = iVar10 + 1;
            uVar4 = *(uint32_t *)(lVar23 + 4);
            *(uint32_t *)(lVar23 + 4) = uVar11;
            *(int *)(lVar23 + 8) = iVar10;
            uVar11 = 0x4006f;
            if (iVar20 == 0) {
              uVar11 = 0x40070;
            }
            iVar19 = (uint32_t)*(uint16_t *)(lVar23 + 2) + iVar19;
            IntArray_addAll(&local_d0,4,uVar11,uVar4,uVar12);
            FUN_00160c08(plVar33,&local_d0,iVar19);
            uVar30 = plVar33[2];
            uVar35 = uVar30 >> 2 & 0x3fffffff;
          } while (iVar19 < (int)uVar35);
        }
LAB_00160a10:
        uVar31 = uVar31 + 1;
        puVar9 = local_1c8;
        param_3 = local_1b0;
        param_5 = local_1b8;
        uVar35 = local_1c0;
      } while (uVar31 != uVar22);
    }
  }
LAB_0015fcbc:
  uStack_c8 = 0;
  local_c0 = (unsigned long *)0x0;
  local_b0 = (uint8_t  [8])plVar33[1];
  local_b8 = plVar33[2];
  local_d0 = 0x10;
  iVar32 = ((generic_fn_t)DAT_00193cb8)(local_1a8,&local_d0,0,plVar33);
  param_2 = extraout_x1;
  if (iVar32 != 0) {
    lVar13 = local_1d0;
    if (local_1d4 == 0) goto LAB_00160b98;
    goto LAB_00160b44;
  }
LAB_0015fd08:
  uVar35 = uVar35 + 1;
  if (uVar35 == uVar27) goto LAB_00160b38;
  goto LAB_0015fd14;
LAB_00160628:
  uVar5 = *(uint32_t *)(lVar13 + (long)iVar28 * 4);
  uVar29 = local_18c;
  if (((0x2ffff < uVar5) && ((uVar5 & 0xffff) == 0x3b)) &&
     (lVar16 = (long)iVar28, *(int *)(lVar13 + lVar16 * 4 + 8) == iVar19)) {
    if ((iVar28 != -1) && (*(int *)(lVar13 + lVar16 * 4 + 0xc) == 1)) {
      piVar24[-1] = iVar19;
      *piVar24 = iVar28;
      iVar19 = iVar32;
      goto LAB_0016069c;
    }
    goto LAB_00160910;
  }
  iVar28 = (uVar5 >> 0x10) + iVar28;
  if (((int)uVar8 <= iVar28) || ((uVar5 & 0xffff) == 0x36)) goto LAB_00160910;
  goto LAB_00160628;
  while( true ) {
    iVar19 = (uVar5 >> 0x10) + iVar19;
    uVar11 = 4;
    if (((int)uVar8 <= iVar19) || ((uVar5 & 0xffff) == 0x36)) break;
LAB_0016069c:
    uVar5 = *(uint32_t *)(lVar13 + (long)iVar19 * 4);
    if (((0x1ffff < uVar5) && ((uVar5 & 0xffff) == 0x20)) &&
       (*(int *)(lVar13 + (long)iVar19 * 4 + 4) == *(int *)(lVar13 + (lVar16 + 1) * 4))) {
      if (iVar19 == -1) goto LAB_0016075c;
      iVar10 = iVar32;
      goto LAB_001606fc;
    }
  }
LAB_00160760:
  iVar10 = piVar24[2];
  iVar20 = 0;
  iVar19 = iVar32;
  if (((0x3d < iVar10 - 0xdU) ||
      ((1L << ((unsigned long)(iVar10 - 0xdU) & 0x3f) & 0x2000000010000081U) == 0)) &&
     ((iVar10 != 0x51 && (iVar10 != 0x5f)))) {
    iVar20 = 1;
  }
  while( true ) {
    uVar6 = *(uint32_t *)(lVar13 + (long)iVar19 * 4);
    uVar5 = uVar6 & 0xffff;
    param_3 = local_1b0;
    if (uVar5 - 0x13 < 0x15) break;
    iVar19 = iVar19 + (uVar6 >> 0x10);
    if (((int)uVar8 <= iVar19) || (uVar5 == 0x36)) goto LAB_00160910;
  }
  if (iVar19 != -1) {
    local_c0 = &local_170;
    *local_1e8 = 0;
    *(uint32_t *)(local_1e8 + 1) = 0;
    (*(uint32_t*)((char*)&local_b0 + 0)) = 3;
    local_1f0[0] = 0;
    local_1f0[1] = 0;
    local_1f0[2] = 0;
    uStack_c8 = ((uint64_t)((*(uint32_t*)((char*)&uStack_c8 + 4))) << 32 | (uint32_t)(uVar3));
    local_b8 = ((uint64_t)(iVar19) << 32 | (uint32_t)(iVar19));
    local_90 = ((uint64_t)(iVar28) << 32 | (uint32_t)(1));
    local_208 = uVar11;
    local_204 = iVar20;
    local_200 = lVar16 + 1;
    uStack_1f8 = uVar30;
    local_1e0 = uVar35;
    local_d0 = lVar13;
    local_a0 = iVar20;
    auVar36 = FUN_00160cb8(&local_d0,param_2,0x15,0xffffffff,0x20,iVar20);
    local_118 = plVar33[1];
    local_108 = &local_170;
    local_e8 = (*(uint32_t*)((char*)&auVar36 + 0));
    uStack_e4 = local_208;
    local_110 = (uint32_t)plVar33[2];
    local_f8 = 0x300000002;
    local_f0 = 0;
    local_e0 = 0;
    local_100 = (uint32_t)local_b8;
    local_d8 = 2;
    iStack_fc = iVar19;
    local_d4 = iVar28;
    iVar10 = FUN_00160cb8(&local_118,(*(uint64_t*)((char*)&auVar36 + 8)),0x17,0xffffffff,(*(uint64_t*)((char*)&auVar36 + 0)) & 0xffffffff);
    plVar33 = local_198;
    local_160 = local_198[1];
    local_120 = 2;
    local_150 = &local_170;
    local_158 = (void *)((uint64_t)((*(uint32_t*)((char*)&local_158 + 4))) << 32 | (uint32_t)((int)local_198[2]);
    local_130 = 1;
    local_140 = 0x300000002;
    local_138 = 0;
    local_128 = 0;
    local_148 = local_100;
    iStack_144 = iVar19;
    iStack_12c = iVar10;
    iStack_11c = iVar28;
    uVar11 = FUN_00160cb8(&local_160,extraout_x1_02,0x20,0xffffffff,1);
    lVar13 = plVar33[1];
    piVar24[-2] = iVar10;
    piVar24[1] = local_204;
    *(uint32_t *)(lVar13 + local_200 * 4) = uVar11;
    param_2 = extraout_x1_03;
    uVar35 = local_1e0;
    uVar30 = uStack_1f8;
    param_3 = local_1b0;
    uVar29 = local_18c;
  }
LAB_00160910:
  iVar32 = (uVar17 >> 0x10) + iVar32;
  if ((((int)uVar35 <= iVar32) || (uVar14 == 0x36)) || (uVar14 - 0x13 < 0x15)) goto LAB_00160934;
  goto LAB_001605b4;
LAB_001606fc:
  uVar5 = *(uint32_t *)(lVar13 + (long)iVar10 * 4);
  if (((0x1ffff < uVar5) && ((uVar5 & 0xffff) == 0x17)) &&
     (*(int *)(lVar13 + (long)iVar10 * 4 + 4) == *(int *)(lVar13 + (long)iVar19 * 4 + 0xc))) {
    if (iVar10 == -1) {
LAB_0016075c:
      uVar11 = 4;
    }
    else {
      uVar11 = *(uint32_t *)(lVar13 + (long)iVar10 * 4 + 0xc);
    }
    goto LAB_00160760;
  }
  iVar10 = (uVar5 >> 0x10) + iVar10;
  uVar11 = 4;
  if (((int)uVar8 <= iVar10) || ((uVar5 & 0xffff) == 0x36)) goto LAB_00160760;
  goto LAB_001606fc;
  while ((iVar28 = (uVar29 >> 0x10) + iVar28, iVar28 < (int)(*(uint32_t *)(plVar33 + 2) >> 2) &&
         ((uVar29 & 0xffff) != 0x36))) {
LAB_0015feac:
    uVar29 = *(uint32_t *)(lVar16 + (long)iVar28 * 4);
    if ((((uVar29 & 0xffff) - 0x13 < 0x15) && (0x1ffff < uVar29)) &&
       (*(int *)(lVar16 + (long)iVar28 * 4 + 4) == iVar10)) goto LAB_0015ff04;
  }
LAB_0015fde0:
  lVar13 = lVar13 + 1;
  if (iVar32 <= lVar13) goto LAB_001600ac;
  goto LAB_0015fdec;
LAB_0015ff04:
  if (iVar28 != -1) {
    uStack_9c = uVar17;
    if (uVar17 <= uVar14) {
      uStack_9c = uVar14;
    }
    local_b0 = (uint8_t  [8])0x300000002;
    local_a8 = 0;
    local_98 = 0;
    local_b8 = ((uint64_t)(iVar28) << 32 | (uint32_t)(iVar28 + (uVar29 >> 0x10)));
    uStack_c8 = ((uint64_t)((*(uint32_t*)((char*)&uStack_c8 + 4))) << 32 | (uint32_t)((int)plVar33[2]);
    local_90 = ((uint64_t)(piVar24[1]) << 32 | (uint32_t)(2));
    local_d0 = lVar16;
    local_c0 = &local_160;
    local_a0 = iVar10;
    auVar36 = FUN_00160cb8(&local_d0,sVar7,0x17,0xffffffff);
    plVar33 = local_198;
    local_118 = local_198[1];
    local_f8 = 0x300000002;
    local_110 = (uint32_t)local_198[2];
    local_f0 = 0;
    uStack_e4 = (*(uint32_t*)((char*)&auVar36 + 0));
    local_e8 = 1;
    local_e0 = 0;
    local_100 = (uint32_t)local_b8;
    local_d8 = 2;
    local_d4 = piVar24[1];
    local_108 = &local_160;
    iStack_fc = iVar28;
    uVar11 = FUN_00160cb8(&local_118,(*(uint64_t*)((char*)&auVar36 + 8)),0x20,0xffffffff,1,(*(uint64_t*)((char*)&auVar36 + 0)) & 0xffffffff);
    lVar16 = plVar33[1];
    *(uint32_t *)(lVar16 + (long)piVar24[1] * 4 + 4) = uVar11;
    iVar32 = (uint32_t)local_180;
  }
  goto LAB_0015fde0;
LAB_00160b38:
  iVar32 = 0;
  lVar13 = local_1d0;
  if (local_1d4 != 0) {
LAB_00160b44:
    puVar21 = (uint64_t *)(param_3 + 0x18);
    do {
      puVar26 = (uint64_t *)*puVar21;
      if (puVar26 != (uint64_t *)0x0) {
        if ((void *)puVar26[1] != (void *)0x0) {
          free((void *)puVar26[1]);
          puVar26[1] = 0;
        }
        puVar26[2] = 0;
        *puVar21 = *puVar26;
      }
      uVar27 = uVar27 - 1;
      puVar21 = puVar21 + 6;
      lVar13 = local_1d0;
    } while (uVar27 != 0);
  }
  goto LAB_00160b98;
}


