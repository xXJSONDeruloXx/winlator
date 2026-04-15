/*
 * vk_init.c — Vulkan instance/device initialization
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015bc14  size=116 */

void checkDeviceFeatures(long param_1,int *param_2)

{
  *(uint64_t *)(param_1 + 0x94) = 0x100000001;
  *(uint64_t *)(param_1 + 0x58) = 0x100000001;
  *(uint64_t *)(param_1 + 0x48) = 0x100000001;
  *(uint64_t *)(param_1 + 4) = 0x100000001;
  *(uint32_t *)(param_1 + 0x34) = 1;
  *(uint32_t *)(param_1 + 0xc) = 1;
  *(uint32_t *)(param_1 + 0x70) = 1;
  *(uint32_t *)(param_1 + 0xd4) = 1;
  *(uint32_t *)(param_1 + 0x68) = 1;
  *(uint64_t *)(param_1 + 0x2c) = 0x100000001;
  *(uint64_t *)(param_1 + 0x24) = 0x100000001;
  *(uint64_t *)(param_1 + 0x1c) = 0x100000001;
  *(uint64_t *)(param_1 + 0x14) = 0x100000001;
  while( true ) {
    if (param_2 == (int *)0x0) {
      return;
    }
    if (*param_2 == 0x3b9ef080) break;
    param_2 = *(int **)(param_2 + 2);
  }
  param_2[6] = 1;
  param_2[4] = 1;
  param_2[5] = 0;
  return;
}


/* @0015b408  size=212 */

void checkDeviceMemoryProperties(long param_1,long param_2,int *param_3)

{
  unsigned long uVar1;
  unsigned long uVar2;
  unsigned long uVar3;
  uint32_t uVar4;
  unsigned long uVar5;
  long lVar6;
  unsigned long uVar7;
  unsigned long *puVar8;
  unsigned long uVar9;
  
  uVar4 = *(uint32_t *)(param_2 + 0x104);
  uVar5 = (unsigned long)uVar4;
  uVar1 = DAT_00194340;
  if (*(short *)(param_1 + 8) != 0) {
    uVar1 = (long)*(short *)(param_1 + 8) << 0x14;
  }
  if (uVar4 != 0) {
    if (uVar4 == 1) {
      uVar7 = 0;
    }
    else {
      uVar7 = uVar5 & 0xfffffffe;
      uVar9 = uVar5 & 0xfffffffe;
      puVar8 = (unsigned long *)(param_2 + 0x118);
      do {
        uVar2 = puVar8[-2];
        if (uVar1 <= puVar8[-2]) {
          uVar2 = uVar1;
        }
        uVar3 = *puVar8;
        if (uVar1 <= *puVar8) {
          uVar3 = uVar1;
        }
        puVar8[-2] = uVar2;
        uVar9 = uVar9 - 2;
        *puVar8 = uVar3;
        puVar8 = puVar8 + 4;
      } while (uVar9 != 0);
      if (uVar7 == uVar5) goto joined_r0x0015b49c;
    }
    lVar6 = uVar5 - uVar7;
    puVar8 = (unsigned long *)(param_2 + uVar7 * 0x10 + 0x108);
    do {
      uVar5 = *puVar8;
      if (uVar1 <= *puVar8) {
        uVar5 = uVar1;
      }
      lVar6 = lVar6 + -1;
      *puVar8 = uVar5;
      puVar8 = puVar8 + 2;
    } while (lVar6 != 0);
  }
joined_r0x0015b49c:
  while( true ) {
    if (param_3 == (int *)0x0) {
      return;
    }
    if (*param_3 == 0x3b9e67c8) break;
    param_3 = *(int **)(param_3 + 2);
  }
  uVar5 = DAT_00194340;
  if (uVar1 != 0) {
    uVar5 = uVar1;
  }
  *(uint64_t *)(param_3 + 0x24) = *(uint64_t *)(param_1 + 0x20);
  *(unsigned long *)(param_3 + 4) = uVar5;
  return;
}


/* @0015b9a0  size=464 */

void checkDeviceProperties(long param_1,uint32_t *param_2,int *param_3)

{
  int *piVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  uint32_t *puVar5;
  int *piVar6;
  int *piVar7;
  unsigned long uVar8;
  long lVar9;
  uint64_t local_170;
  uint64_t uStack_168;
  uint64_t uStack_160;
  uint64_t uStack_158;
  uint64_t local_150;
  uint64_t uStack_148;
  uint64_t uStack_140;
  uint64_t uStack_138;
  uint64_t local_130;
  uint64_t uStack_128;
  uint64_t uStack_120;
  uint64_t uStack_118;
  uint64_t local_110;
  uint64_t uStack_108;
  uint64_t uStack_100;
  uint64_t uStack_f8;
  uint64_t local_f0;
  uint64_t uStack_e8;
  uint64_t uStack_e0;
  uint64_t uStack_d8;
  uint64_t local_d0;
  uint64_t uStack_c8;
  uint64_t uStack_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t uStack_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  uint64_t uStack_78;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar3 + 0x28);
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  uStack_b8 = 0;
  uStack_c0 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  uStack_d8 = 0;
  uStack_e0 = 0;
  uStack_108 = 0;
  local_110 = 0;
  uStack_f8 = 0;
  uStack_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_168 = 0;
  local_170 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  FUN_0015bb70(&local_170,0x100,"Vortek (%s)",param_2 + 5);
  __strcpy_chk(param_2 + 5,&local_170,0x100);
  *param_2 = *(uint32_t *)(param_1 + 4);
  piVar7 = param_3;
  if (param_3 == (int *)0x0) goto LAB_0015bb3c;
  do {
    piVar6 = param_3;
    if (*piVar7 == 0x34) {
      uVar2 = param_2[1];
      FUN_0015bb70(piVar7 + 0x45,0x100,"%d.%d.%d",uVar2 >> 0x16,uVar2 >> 0xc & 0x3ff,uVar2 & 0xfff);
      puVar5 = *(uint32_t **)(param_1 + 0x18);
      if ((puVar5 != (uint32_t *)0x0) && (uVar2 = *puVar5, 0 < (int)uVar2)) {
        lVar9 = *(long *)(puVar5 + 2);
        uVar8 = 0;
        goto LAB_0015ba98;
      }
      break;
    }
    piVar1 = piVar7 + 2;
    piVar7 = *(int **)piVar1;
  } while (*(int **)piVar1 != (int *)0x0);
  goto LAB_0015bad4;
  while (iVar4 != 0) {
LAB_0015ba98:
    iVar4 = strcmp(*(char **)(lVar9 + uVar8 * 8),"VK_KHR_shader_float_controls");
    uVar8 = uVar8 + 1;
    if (uVar2 <= uVar8) break;
  }
  if (iVar4 == 0) {
    piVar7[0x89] = 0;
    piVar7[0x8a] = 0;
    piVar7[0x8f] = 0;
    piVar7[0x90] = 0;
    piVar7[0x8c] = 0;
    piVar7[0x8d] = 0;
  }
LAB_0015bad4:
  do {
    if (*piVar6 == 0x3b9dc7a0) {
      uVar2 = param_2[1];
      FUN_0015bb70(piVar6 + 0x45,0x100,"%d.%d.%d",uVar2 >> 0x16,uVar2 >> 0xc & 0x3ff,uVar2 & 0xfff);
      break;
    }
    piVar7 = piVar6 + 2;
    piVar6 = *(int **)piVar7;
  } while (*(int **)piVar7 != (int *)0x0);
  do {
    if (*param_3 == 0x3b9ef081) {
      iVar4 = getpagesize();
      *(long *)(param_3 + 4) = (long)iVar4;
      break;
    }
    param_3 = *(int **)(param_3 + 2);
  } while (param_3 != (int *)0x0);
LAB_0015bb3c:
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0015b894  size=136 */

void checkFormatProperties(uint64_t param_1,uint32_t param_2,int *param_3)

{
  unsigned long uVar1;
  
  uVar1 = isCompressedFormat(param_2);
  if ((((uVar1 & 1) != 0) && (*param_3 == 0)) && (param_3[1] == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0015b918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ((generic_fn_t)DAT_00193b28)(param_1,0x2c,param_3);
    return;
  }
  uVar1 = isFormatScaled(param_2);
  if ((uVar1 & 1) != 0) {
    param_3[2] = param_3[2] | 0x40;
  }
  return;
}


/* @0015b91c  size=132 */

void checkImageFormatProperties
               (int param_1,int param_2,int param_3,int param_4,uint64_t param_5,long param_6,
               int *param_7)

{
  int iVar1;
  unsigned long uVar2;
  
  if ((((param_3 == 1) && (param_2 == 1)) && (param_1 == 0x25)) && (param_4 == 0x17)) {
    iVar1 = 0;
    *(uint32_t *)(param_6 + 0x14) = 8;
  }
  else {
    if (*param_7 != -0xb) {
      return;
    }
    uVar2 = isCompressedFormat(param_1);
    if ((uVar2 & 1) == 0) {
      return;
    }
    iVar1 = getCompressedImageFormatProperties(param_1,param_6);
  }
  *param_7 = iVar1;
  return;
}


/* @0015b4dc  size=364 */

void disableUnsupportedDeviceFeatures(uint64_t param_1,long param_2)

{
  long lVar1;
  int *piVar2;
  unsigned long uVar3;
  int local_140 [2];
  int *piStack_138;
  uint64_t local_130;
  uint64_t uStack_128;
  uint64_t local_120;
  uint64_t uStack_118;
  uint64_t local_110;
  uint64_t uStack_108;
  uint64_t uStack_100;
  uint64_t uStack_f8;
  uint64_t local_f0;
  uint64_t uStack_e8;
  uint64_t uStack_e0;
  uint64_t uStack_d8;
  uint64_t local_d0;
  uint64_t uStack_c8;
  uint64_t uStack_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t uStack_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  uint32_t uStack_78;
  uint32_t local_74;
  uint32_t uStack_70;
  uint32_t uStack_6c;
  uint32_t uStack_68;
  uint32_t uStack_64;
  uint64_t uStack_60;
  uint64_t uStack_58;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar1 + 0x28);
  for (piVar2 = *(int **)(param_2 + 8); piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 2)) {
    if (*piVar2 == 0x3b9b3760) {
      uStack_128 = 0;
      local_130 = 0;
      local_140[0] = 0x3b9bb078;
      local_140[1] = 0;
      uStack_68 = 0;
      uStack_64 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_58 = 0;
      uStack_60 = 0;
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      local_74 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      local_b0 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      uStack_e0 = 0;
      uStack_108 = 0;
      local_110 = 0;
      uStack_f8 = 0;
      uStack_100 = 0;
      uStack_118 = 0;
      local_120 = 0;
      piStack_138 = piVar2;
      ((generic_fn_t)DAT_00193f78)(param_1,local_140);
      piVar2 = *(int **)(param_2 + 0x40);
      if (piVar2 == (int *)0x0) goto LAB_0015b58c;
      goto LAB_0015b5dc;
    }
  }
  piVar2 = *(int **)(param_2 + 0x40);
  if (piVar2 == (int *)0x0) {
LAB_0015b58c:
    for (piVar2 = *(int **)(param_2 + 8); piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 2)) {
      if (*piVar2 == 0x3b9bb078) {
        piVar2 = piVar2 + 4;
        goto LAB_0015b5dc;
      }
    }
  }
  else {
LAB_0015b5dc:
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    local_74 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_b8 = 0;
    uStack_c0 = 0;
    uStack_e8 = 0;
    local_f0 = 0;
    uStack_d8 = 0;
    uStack_e0 = 0;
    uStack_108 = 0;
    local_110 = 0;
    uStack_f8 = 0;
    uStack_100 = 0;
    uStack_128 = 0;
    local_130 = 0;
    uStack_118 = 0;
    local_120 = 0;
    piStack_138 = (int *)0x0;
    local_140[0] = 0;
    local_140[1] = 0;
    ((generic_fn_t)DAT_00193b20)(param_1,local_140);
    uVar3 = 0;
    do {
      if ((*(int *)((long)piVar2 + uVar3) != 0) && (*(int *)((long)local_140 + uVar3) == 0)) {
        *(uint32_t *)((long)piVar2 + uVar3) = 0;
      }
      uVar3 = (unsigned long)((int)uVar3 + 4);
    } while (uVar3 < 0xdc);
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0015eaf8  size=60 */

uint64_t getCompressedImageFormatProperties(int param_1,uint64_t *param_2)

{
  if (param_1 - 0x83U < 0xc) {
    param_2[1] = 0xf00000001;
    *param_2 = 0x400000004000;
    param_2[2] = 0x100000800;
    param_2[3] = 0x80000000;
    return 0;
  }
  return 0xfffffff5;
}


/* @0015b648  size=588 */

void getExposedDeviceExtensionProperties(long param_1,uint64_t param_2,int *param_3)

{
  uint32_t uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  void *pvVar5;
  uint32_t *puVar6;
  unsigned long uVar7;
  uint64_t *puVar8;
  char *__s2;
  void *pvVar9;
  char *__s1;
  char *pcVar10;
  unsigned long uVar11;
  uint8_t *local_80;
  void *local_78;
  uint32_t local_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar3 + 0x28);
  iVar4 = ((generic_fn_t)DAT_00193b58)(param_2,0,&local_6c,0);
  pvVar5 = (void *)0x0;
  if (iVar4 == 0) {
    pcVar10 = (char *)((long)&local_80 - ((unsigned long)local_6c * 0x104 + 0xf & 0x3fffffffff0));
    iVar4 = ((generic_fn_t)DAT_00193b58)(param_2,0,&local_6c,pcVar10);
    pvVar5 = (void *)0x0;
    if (iVar4 == 0) {
      puVar6 = &local_6c;
      if (*(uint32_t **)(param_1 + 0x10) != (uint32_t *)0x0) {
        puVar6 = *(uint32_t **)(param_1 + 0x10);
      }
      uVar1 = *puVar6;
      iVar2 = uVar1 * 0x104;
      iVar4 = *(int *)(param_1 + 0x48) + iVar2;
      if ((iVar4 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar5 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar4;
        local_80 = (uint8_t *)&local_80;
      }
      else {
        local_80 = (uint8_t *)&local_80;
        pvVar5 = malloc((long)iVar2);
        ArrayList_add(param_1 + 0x50,pvVar5);
      }
      memset(pvVar5,0,(long)iVar2);
      *param_3 = 0;
      local_78 = pvVar5;
      if (0 < (int)uVar1) {
        uVar11 = 0;
        do {
          if (*(long *)(param_1 + 0x10) == 0) {
            __s2 = pcVar10 + uVar11 * 0x104;
LAB_0015b7fc:
            puVar6 = *(uint32_t **)(param_1 + 0x18);
            if ((puVar6 != (uint32_t *)0x0) && (uVar7 = (unsigned long)*puVar6, 0 < (int)*puVar6)) {
              puVar8 = *(uint64_t **)(puVar6 + 2);
              do {
                iVar4 = strcmp(__s2,(char *)*puVar8);
                if (iVar4 == 0) goto LAB_0015b7ac;
                uVar7 = uVar7 - 1;
                puVar8 = puVar8 + 1;
              } while (uVar7 != 0);
            }
            iVar4 = *param_3;
            *param_3 = iVar4 + 1;
            pvVar9 = (void *)((long)pvVar5 + (long)iVar4 * 0x104);
            __strcpy_chk(pvVar9,__s2,0x100);
            *(uint32_t *)((long)pvVar9 + 0x100) = *(uint32_t *)(__s2 + 0x100);
          }
          else {
            uVar7 = (unsigned long)local_6c;
            if (local_6c != 0) {
              __s1 = *(char **)(*(long *)(*(long *)(param_1 + 0x10) + 8) + uVar11 * 8);
              __s2 = pcVar10;
              do {
                iVar4 = strcmp(__s1,__s2);
                if (iVar4 == 0) goto LAB_0015b7fc;
                uVar7 = uVar7 - 1;
                __s2 = __s2 + 0x104;
              } while (uVar7 != 0);
            }
          }
LAB_0015b7ac:
          uVar11 = uVar11 + 1;
        } while (uVar11 != uVar1);
      }
      injectExtensions2(param_1,&local_78,param_3,&PTR_s_VK_KHR_swapchain_00193898,6,0,0);
      pvVar5 = local_78;
    }
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pvVar5);
  }
  return;
}


/* @0015ac90  size=52 */

uint32_t getMemoryPropertyFlags(uint32_t param_1)

{
  uint32_t uVar1;
  
  uVar1 = 0;
  if ((DAT_00194338 != 0) && (param_1 < DAT_00194338)) {
    uVar1 = *(uint32_t *)(deviceMemoryInfo + (unsigned long)param_1 * 8);
  }
  return uVar1;
}


/* @0015ac3c  size=84 */

unsigned long getMemoryTypeIndex(unsigned long param_1,uint32_t param_2)

{
  unsigned long uVar1;
  uint32_t *puVar2;
  
  if (DAT_00194338 != 0) {
    uVar1 = 0;
    puVar2 = deviceMemoryInfo;
    do {
      if (((param_1 & 1) != 0) && ((*puVar2 & param_2) != 0)) {
        return uVar1 & 0xffffffff;
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 >> 1 & 0x7fffffff;
      puVar2 = puVar2 + 2;
    } while (DAT_00194338 != uVar1);
  }
  return 0;
}


/* @0015d4fc  size=84 */

void getSurfaceFormats(uint32_t *param_1)

{
  uint32_t *puVar1;
  
  puVar1 = calloc(4,8);
  if (param_1 != (uint32_t *)0x0) {
    *param_1 = 4;
  }
  *puVar1 = 0x2c;
  puVar1[2] = 0x32;
  puVar1[4] = 0x25;
  puVar1[6] = 0x2b;
  return;
}


/* @0015d4f4  size=8 */

uint64_t getSurfaceMinImageCount(void)

{
  return 1;
}


/* @0015d488  size=108 */

void getWindowExtent(long param_1,uint32_t param_2,uint32_t *param_3)

{
  long *plVar1;
  uint64_t uVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  uVar3 = (**(void **)(**(long **)(param_1 + 8) + 0x188))
                    (*(long **)(param_1 + 8),*(uint64_t *)(param_1 + 0x10),
                     *(uint64_t *)(param_1 + 0x18),param_2);
  plVar1 = *(long **)(param_1 + 8);
  uVar2 = *(uint64_t *)(param_1 + 0x10);
  uVar4 = *(uint64_t *)(param_1 + 0x20);
  *param_3 = uVar3;
  uVar3 = ((generic_fn_t)(*(void **)(*plVar1 + 0x188)))(plVar1,uVar2,uVar4,param_2);
  param_3[1] = uVar3;
  return;
}


/* @00151564  size=396 */

void initVulkanDevice(long param_1,uint64_t param_2,uint64_t param_3)

{
  long lVar1;
  uint64_t uVar2;
  long lVar3;
  unsigned long uVar4;
  long lVar5;
  int *piVar6;
  uint64_t local_140;
  uint64_t uStack_138;
  uint64_t local_130;
  uint64_t uStack_128;
  uint64_t uStack_120;
  uint64_t uStack_118;
  uint64_t local_110;
  uint64_t uStack_108;
  uint64_t uStack_100;
  uint64_t uStack_f8;
  uint64_t local_f0;
  uint64_t uStack_e8;
  uint64_t uStack_e0;
  uint64_t uStack_d8;
  uint64_t local_d0;
  uint64_t uStack_c8;
  uint64_t uStack_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t uStack_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  uint32_t uStack_78;
  uint32_t local_74;
  uint32_t uStack_70;
  uint64_t uStack_6c;
  uint32_t local_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar1 + 0x28);
  FUN_001516f0(param_3);
  local_5c = 0;
  ((generic_fn_t)DAT_00193b10)(param_2,&local_5c,0);
  lVar3 = -((unsigned long)local_5c * 0x18 + 0xf & 0x3ffffffff0);
  ((generic_fn_t)DAT_00193b10)(param_2,&local_5c,(long)&local_140 + lVar3);
  *(uint32_t *)(param_1 + 0x7c) = 0;
  if (local_5c != 0) {
    uVar4 = 0;
    piVar6 = (int *)((long)&local_140 + lVar3 + 4);
    do {
      if ((*piVar6 != 0) && ((*(uint8_t *)(piVar6 + -1) & 1) != 0)) {
        *(int *)(param_1 + 0x7c) = (int)uVar4;
        break;
      }
      uVar4 = uVar4 + 1;
      piVar6 = piVar6 + 6;
    } while (local_5c != uVar4);
  }
  uStack_6c = 0;
  uStack_70 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  local_74 = 0;
  uStack_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  uStack_b8 = 0;
  uStack_c0 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  uStack_d8 = 0;
  uStack_e0 = 0;
  uStack_108 = 0;
  local_110 = 0;
  uStack_f8 = 0;
  uStack_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uStack_138 = 0;
  local_140 = 0;
  ((generic_fn_t)DAT_00193b20)(param_2,&local_140);
  lVar3 = *(long *)(param_1 + 0x80);
  if (lVar3 == 0) {
    lVar3 = TextureDecoder_create(param_1,&local_140);
    *(long *)(param_1 + 0x80) = lVar3;
    lVar5 = *(long *)(param_1 + 0x88);
  }
  else {
    lVar5 = *(long *)(param_1 + 0x88);
  }
  if (lVar5 == 0) {
    uVar2 = ShaderInspector_create(param_1,param_2,&local_140);
    lVar3 = *(long *)(param_1 + 0x80);
    *(uint64_t *)(param_1 + 0x88) = uVar2;
  }
  if (lVar3 != 0) {
    *(uint64_t *)(lVar3 + 0x40) = *(uint64_t *)(param_1 + 0x90);
  }
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0014ff94  size=5584 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initVulkanInstance(long param_1,uint64_t param_2,long param_3)

{
  long lVar1;
  simd128_t auVar2;
  simd128_t auVar3;
  simd128_t auVar4;
  simd128_t auVar5;
  simd128_t auVar6;
  unsigned long *puVar7;
  unsigned long *puVar8;
  int iVar9;
  long lVar10;
  void *pcVar11;
  uint64_t uVar12;
  char *pcVar13;
  unsigned long uVar14;
  long lVar15;
  unsigned long uVar16;
  unsigned long *puVar17;
  unsigned long *puVar18;
  size_t __size;
  uint64_t *puVar19;
  simd128_t auVar20;
  simd128_t auVar21;
  uint64_t uStack_2b0;
  uint32_t local_2a4;
  uint64_t local_2a0;
  uint64_t uStack_298;
  unsigned long local_290;
  uint64_t local_288;
  unsigned long local_280;
  uint64_t uStack_278;
  char *local_270;
  uint64_t local_268;
  uint32_t local_17c;
  unsigned long local_178 [4];
  unsigned long local_158 [29];
  long local_70;
  
  /* stack canary setup */
  local_70 = *(long *)(lVar1 + 0x28);
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkDestroyInstance",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkDestroyInstance",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkDestroyInstance",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193af8 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumeratePhysicalDevices",&DAT_0011e91d);
  pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (pcVar11 == (void *)0x0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumeratePhysicalDevices",&DAT_0011d617);
    pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (pcVar11 == (void *)0x0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumeratePhysicalDevices",&DAT_0011efff);
      pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b00 = pcVar11;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceProperties",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceProperties",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceProperties",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b08 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceQueueFamilyProperties",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceQueueFamilyProperties",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceQueueFamilyProperties",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b10 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMemoryProperties",&DAT_0011e91d);
  pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (pcVar11 == (void *)0x0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMemoryProperties",&DAT_0011d617);
    pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (pcVar11 == (void *)0x0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMemoryProperties",&DAT_0011efff
                  );
      pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b18 = pcVar11;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFeatures",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFeatures",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFeatures",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b20 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFormatProperties",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFormatProperties",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFormatProperties",&DAT_0011efff
                  );
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b28 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceImageFormatProperties",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceImageFormatProperties",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceImageFormatProperties",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b30 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkCreateDevice",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkCreateDevice",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkCreateDevice",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b38 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumerateDeviceExtensionProperties",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumerateDeviceExtensionProperties",&DAT_0011d617)
    ;
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumerateDeviceExtensionProperties",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193b58 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSparseImageFormatProperties",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSparseImageFormatProperties",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSparseImageFormatProperties",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193be0 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfaceCapabilities",&DAT_0011e91d)
  ;
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfaceCapabilities",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfaceCapabilities",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f38 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfaceFormats",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfaceFormats",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfaceFormats",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f40 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfacePresentModes",&DAT_0011e91d)
  ;
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfacePresentModes",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSurfacePresentModes",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f48 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFeatures2",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFeatures2",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFeatures2",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f78 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceProperties2",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceProperties2",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceProperties2",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f80 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFormatProperties2",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFormatProperties2",&DAT_0011d617)
    ;
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceFormatProperties2",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f88 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceImageFormatProperties2",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceImageFormatProperties2",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceImageFormatProperties2",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f90 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceQueueFamilyProperties2",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceQueueFamilyProperties2",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceQueueFamilyProperties2",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193f98 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMemoryProperties2",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMemoryProperties2",&DAT_0011d617)
    ;
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMemoryProperties2",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193fa0 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSparseImageFormatProperties2",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSparseImageFormatProperties2",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceSparseImageFormatProperties2",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193fa8 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalBufferProperties",
               &DAT_0011e91d);
  pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (pcVar11 == (void *)0x0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalBufferProperties",
                 &DAT_0011d617);
    pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (pcVar11 == (void *)0x0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalBufferProperties",
                   &DAT_0011efff);
      pcVar11 = (void *)((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193fc0 = pcVar11;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalSemaphoreProperties",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalSemaphoreProperties",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalSemaphoreProperties",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193fd0 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalFenceProperties",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalFenceProperties",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceExternalFenceProperties",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193fe0 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumeratePhysicalDeviceGroups",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumeratePhysicalDeviceGroups",&DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkEnumeratePhysicalDeviceGroups",&DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00193ff0 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDevicePresentRectangles",&DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDevicePresentRectangles",&DAT_0011d617)
    ;
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDevicePresentRectangles",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00194028 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMultisampleProperties",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMultisampleProperties",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceMultisampleProperties",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  DAT_00194050 = lVar10;
  FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceCalibrateableTimeDomains",
               &DAT_0011e91d);
  lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
  if (lVar10 == 0) {
    FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceCalibrateableTimeDomains",
                 &DAT_0011d617);
    lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    if (lVar10 == 0) {
      FUN_0015bb70(&local_280,0x80,&DAT_0011ea8e,"vkGetPhysicalDeviceCalibrateableTimeDomains",
                   &DAT_0011efff);
      lVar10 = ((generic_fn_t)DAT_00193ae8)(param_2,&local_280);
    }
  }
  local_2a4 = 1;
  DAT_001940a8 = lVar10;
  iVar9 = ((generic_fn_t)DAT_00193b00)(param_2,&local_2a4,0);
  if (iVar9 == 0) {
    puVar19 = (uint64_t *)((long)&uStack_2b0 - ((unsigned long)local_2a4 * 8 + 0xf & 0xffffffff0));
    iVar9 = ((generic_fn_t)DAT_00193b00)(param_2,&local_2a4,puVar19);
    if ((iVar9 == 0) && (local_2a4 != 0)) {
      if (DAT_00194338 == 0) {
        ((generic_fn_t)DAT_00193b18)(*puVar19,&local_280);
        __size = (local_280 & 0xffffffff) << 3;
        deviceMemoryInfo = malloc(__size);
        memcpy(deviceMemoryInfo,(void *)((unsigned long)&local_280 | 4),__size);
        uVar14 = (unsigned long)local_17c;
        DAT_00194338 = (int)local_280;
        if (local_17c == 0) {
          DAT_00194340 = 0;
        }
        else {
          if (local_17c < 5) {
            lVar15 = 0;
            uVar16 = 0;
          }
          else {
            uVar16 = 4;
            if ((local_17c & 3) != 0) {
              uVar16 = uVar14 & 3;
            }
            lVar15 = uVar14 - uVar16;
            auVar20 = ((uint64_t /* was __int128 */)(0));
            puVar17 = local_158;
            auVar21 = ((uint64_t /* was __int128 */)(0));
            lVar10 = lVar15;
            do {
              puVar18 = puVar17 + -4;
              uVar16 = *puVar17;
              puVar7 = puVar17 + 2;
              puVar8 = puVar17 + -2;
              lVar10 = lVar10 + -4;
              puVar17 = puVar17 + 8;
              (*(uint64_t*)((char*)&auVar2 + 8)) = *puVar7;
              (*(uint64_t*)((char*)&auVar2 + 0)) = uVar16;
              (*(uint64_t*)((char*)&auVar5 + 8)) = -(unsigned long)(*puVar7 < (*(uint64_t*)((char*)&auVar21 + 8)));
              (*(uint64_t*)((char*)&auVar5 + 0)) = -(unsigned long)(uVar16 < (*(uint64_t*)((char*)&auVar21 + 0)));
              auVar21 = auVar21 ^ (auVar21 ^ auVar2) & ~auVar5;
              (*(uint64_t*)((char*)&auVar4 + 8)) = *puVar8;
              (*(uint64_t*)((char*)&auVar4 + 0)) = *puVar18;
              (*(uint64_t*)((char*)&auVar6 + 8)) = -(unsigned long)(*puVar8 < (*(uint64_t*)((char*)&auVar20 + 8)));
              (*(uint64_t*)((char*)&auVar6 + 0)) = -(unsigned long)(*puVar18 < (*(uint64_t*)((char*)&auVar20 + 0)));
              auVar20 = auVar20 ^ (auVar20 ^ auVar4) & ~auVar6;
            } while (lVar10 != 0);
            (*(uint64_t*)((char*)&auVar3 + 8)) = -(unsigned long)((*(uint64_t*)((char*)&auVar21 + 8)) < (*(uint64_t*)((char*)&auVar20 + 8)));
            (*(uint64_t*)((char*)&auVar3 + 0)) = -(unsigned long)((*(uint64_t*)((char*)&auVar21 + 0)) < (*(uint64_t*)((char*)&auVar20 + 0)));
            auVar20 = auVar20 ^ (auVar20 ^ auVar21) & ~auVar3;
            auVar21 = NEON_ext(auVar20,auVar20,8,1);
            uVar16 = (*(uint64_t*)((char*)&auVar20 + 0));
            uVar16 = uVar16 ^ (uVar16 ^ (*(uint64_t*)((char*)&auVar21 + 0))) & ~-(unsigned long)((*(uint64_t*)((char*)&auVar21 + 0)) < uVar16);
          }
          lVar10 = uVar14 - lVar15;
          puVar17 = local_178 + lVar15 * 2;
          do {
            if (uVar16 <= *puVar17) {
              uVar16 = *puVar17;
            }
            lVar10 = lVar10 + -1;
            puVar17 = puVar17 + 2;
          } while (lVar10 != 0);
          DAT_00194340 = (uVar16 << 1) / 3;
        }
      }
      uStack_278 = 0;
      local_270 = (char *)0x0;
      local_280 = 0x3b9bdf5a;
      local_268 = 1;
      uStack_298 = 0;
      local_288 = 0;
      local_290 = 0;
      local_2a0 = 0x3b9bdf5b;
      ((generic_fn_t)DAT_00193fc0)(*puVar19,&local_280,&local_2a0);
      uVar12 = *puVar19;
      *(uint8_t *)(param_1 + 0x28) = (uint8_t)local_288 & (local_290 & 6) != 0;
      uStack_278 = 0;
      local_270 = (char *)0x0;
      local_280 = 0x3b9bdf5a;
      local_268 = 0x200;
      uStack_298 = 0;
      local_288 = 0;
      local_290 = 0;
      local_2a0 = 0x3b9bdf5b;
      ((generic_fn_t)DAT_00193fc0)(uVar12,&local_280,&local_2a0);
      *(uint8_t *)(param_1 + 0x29) = (local_290 & 6) != 0 & (uint8_t)(((uint32_t)local_288 & 0x200) >> 9);
      if (*(void **)(param_1 + 0x108) != (void *)0x0) {
        free(*(void **)(param_1 + 0x108));
        *(uint64_t *)(param_1 + 0x108) = 0;
      }
      if ((param_3 == 0) || (*(char **)(param_3 + 0x20) == (char *)0x0)) {
        *(uint64_t *)(param_1 + 0x108) = 0;
      }
      else {
        pcVar13 = strdup(*(char **)(param_3 + 0x20));
        *(char **)(param_1 + 0x108) = pcVar13;
        if (pcVar13 != (char *)0x0) {
          ArrayList_free(*(uint64_t *)(param_1 + 0x18),1);
          pcVar13 = *(char **)(param_1 + 0x108);
          *(uint64_t *)(param_1 + 0x18) = 0;
          iVar9 = strcmp(pcVar13,"mesa zink");
          if (iVar9 == 0) {
            uStack_278 = (*(uint64_t*)((char*)&PTR_s_VK_EXT_extended_dynamic_state_0018e3b0 + 8));
            local_280 = PTR_s_VK_EXT_extended_dynamic_state_0018e3b0;
            local_270 = "VK_KHR_push_descriptor";
            ArrayList_free(*(uint64_t *)(param_1 + 0x10),1);
            uVar12 = ArrayList_fromStrings(&local_280,3);
            *(uint64_t *)(param_1 + 0x18) = uVar12;
            uVar12 = ArrayList_fromStrings(&PTR_s_VK_KHR_surface_001938c8,0x37);
            *(uint64_t *)(param_1 + 0x10) = uVar12;
          }
          else {
            iVar9 = strcmp(pcVar13,"DXVK");
            if (iVar9 == 0) {
              uStack_278 = (*(uint64_t*)((char*)&PTR_s_VK_KHR_shader_float_controls_0018e3c8 + 8));
              local_280 = PTR_s_VK_KHR_shader_float_controls_0018e3c8;
              local_270 = "VK_EXT_swapchain_maintenance1";
              uVar12 = ArrayList_fromStrings(&local_280,3);
              *(uint64_t *)(param_1 + 0x18) = uVar12;
            }
          }
        }
      }
    }
  }
  if (*(long *)(lVar1 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0015ad00  size=920 */

void injectExtensions(long param_1,long *param_2,uint32_t *param_3,uint64_t *param_4,uint32_t param_5,
                     uint64_t *param_6,uint32_t param_7)

{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  size_t sVar6;
  long lVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  uint64_t *puVar10;
  unsigned long uVar11;
  char *pcVar12;
  unsigned long uVar13;
  unsigned long uVar14;
  char *pcVar15;
  uint64_t *puVar16;
  char acStack_b0 [8];
  uint8_t *local_a8;
  long local_a0;
  uint32_t local_94;
  uint32_t *local_90;
  long local_88;
  unsigned long local_80;
  uint64_t *local_78;
  long *local_70;
  long local_68;
  
  local_a0 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_a0 + 0x28);
  pcVar15 = acStack_b0;
  local_94 = param_5;
  local_90 = param_3;
  local_88 = param_1;
  local_78 = param_6;
  local_70 = param_2;
  if (param_6 != (uint64_t *)0x0) {
    uVar2 = *param_3;
    uVar14 = (unsigned long)uVar2;
    puVar16 = (uint64_t *)*param_2;
    pcVar15 = acStack_b0 + -(uVar14 + 0xf & 0x1fffffff0);
    if (uVar2 == 0) {
      uVar8 = 0;
      local_a8 = acStack_b0;
    }
    else {
      uVar9 = 0;
      uVar8 = 0;
      local_80 = (unsigned long)param_7;
      local_a8 = acStack_b0;
      do {
        pcVar15[uVar9] = '\0';
        if (param_7 != 0) {
          pcVar12 = (char *)puVar16[uVar9];
          uVar13 = local_80;
          puVar10 = local_78;
          do {
            iVar4 = strcmp((char *)*puVar10,pcVar12);
            if (iVar4 == 0) {
              iVar4 = 0;
              pcVar15[uVar9] = '\x01';
              goto LAB_0015ad90;
            }
            uVar13 = uVar13 - 1;
            puVar10 = puVar10 + 1;
          } while (uVar13 != 0);
        }
        iVar4 = 1;
LAB_0015ad90:
        uVar9 = uVar9 + 1;
        uVar8 = uVar8 + iVar4;
      } while (uVar9 != uVar14);
    }
    lVar7 = local_88;
    iVar3 = uVar8 * 8;
    iVar4 = *(int *)(local_88 + 0x48) + iVar3;
    if ((iVar4 < 0x10000) && (*(long *)(local_88 + 0x40) != 0)) {
      pvVar5 = (void *)(*(long *)(local_88 + 0x40) + (long)*(int *)(local_88 + 0x48));
      *(int *)(local_88 + 0x48) = iVar4;
    }
    else {
      pvVar5 = malloc((long)iVar3);
      ArrayList_add(lVar7 + 0x50,pvVar5);
    }
    param_2 = local_70;
    memset(pvVar5,0,(long)iVar3);
    if (uVar2 != 0) {
      iVar4 = 0;
      do {
        if (*pcVar15 == '\0') {
          *(uint64_t *)((long)pvVar5 + (long)iVar4 * 8) = *puVar16;
          iVar4 = iVar4 + 1;
        }
        puVar16 = puVar16 + 1;
        uVar14 = uVar14 - 1;
        pcVar15 = pcVar15 + 1;
      } while (uVar14 != 0);
    }
    *param_2 = (long)pvVar5;
    *local_90 = uVar8;
    pcVar15 = local_a8;
  }
  uVar14 = (unsigned long)local_94;
  pcVar15 = pcVar15 + -(uVar14 + 0xf & 0x1fffffff0);
  if (local_94 != 0) {
    uVar2 = *local_90;
    uVar9 = 0;
    uVar13 = (unsigned long)uVar2;
    do {
      pcVar15[uVar9] = '\0';
      if (uVar2 == 0) {
        iVar4 = 1;
      }
      else {
        pcVar12 = (char *)param_4[uVar9];
        puVar16 = (uint64_t *)*param_2;
        uVar11 = (unsigned long)uVar2;
        do {
          iVar4 = strcmp(pcVar12,(char *)*puVar16);
          if (iVar4 == 0) {
            iVar4 = 0;
            pcVar15[uVar9] = '\x01';
            param_2 = local_70;
            goto LAB_0015aec8;
          }
          uVar11 = uVar11 - 1;
          puVar16 = puVar16 + 1;
        } while (uVar11 != 0);
        iVar4 = 1;
        param_2 = local_70;
      }
LAB_0015aec8:
      lVar7 = local_88;
      uVar9 = uVar9 + 1;
      uVar8 = (int)uVar13 + iVar4;
      uVar13 = (unsigned long)uVar8;
    } while (uVar9 != uVar14);
    if (uVar8 != uVar2) {
      iVar3 = uVar8 * 8;
      iVar4 = *(int *)(local_88 + 0x48) + iVar3;
      if ((iVar4 < 0x10000) && (*(long *)(local_88 + 0x40) != 0)) {
        pvVar5 = (void *)(*(long *)(local_88 + 0x40) + (long)*(int *)(local_88 + 0x48));
        *(int *)(local_88 + 0x48) = iVar4;
      }
      else {
        pvVar5 = malloc((long)iVar3);
        ArrayList_add(lVar7 + 0x50,pvVar5);
      }
      memset(pvVar5,0,(long)iVar3);
      if (local_94 != 0) {
        iVar4 = 0;
        do {
          if (*pcVar15 == '\0') {
            sVar6 = strlen((char *)*param_4);
            iVar3 = (int)sVar6 + 1;
            iVar1 = iVar3 + *(int *)(lVar7 + 0x48);
            if ((iVar1 < 0x10000) && (*(long *)(lVar7 + 0x40) != 0)) {
              pcVar12 = (char *)(*(long *)(lVar7 + 0x40) + (long)*(int *)(lVar7 + 0x48));
              *(int *)(lVar7 + 0x48) = iVar1;
            }
            else {
              pcVar12 = malloc((long)iVar3);
              ArrayList_add(lVar7 + 0x50,pcVar12);
            }
            memset(pcVar12,0,(long)iVar3);
            strcpy(pcVar12,(char *)*param_4);
            uVar2 = *local_90 + iVar4;
            iVar4 = iVar4 + 1;
            *(char **)((long)pvVar5 + (unsigned long)uVar2 * 8) = pcVar12;
            lVar7 = local_88;
          }
          param_4 = param_4 + 1;
          uVar14 = uVar14 - 1;
          pcVar15 = pcVar15 + 1;
        } while (uVar14 != 0);
      }
      uVar2 = *local_90;
      if (uVar2 != 0) {
        lVar7 = 0;
        do {
          *(uint64_t *)((long)pvVar5 + lVar7) = *(uint64_t *)(*param_2 + lVar7);
          lVar7 = lVar7 + 8;
        } while ((unsigned long)uVar2 * 8 - lVar7 != 0);
      }
      *param_2 = (long)pvVar5;
      *local_90 = uVar8;
    }
  }
  if (*(long *)(local_a0 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0015b098  size=880 */

void injectExtensions2(long param_1,long *param_2,uint32_t *param_3,uint64_t *param_4,uint32_t param_5,
                      uint64_t *param_6,uint32_t param_7)

{
  uint32_t uVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  unsigned long uVar5;
  long lVar6;
  uint32_t *puVar7;
  void *pvVar8;
  uint32_t uVar9;
  unsigned long uVar10;
  void *pvVar11;
  char *__s1;
  char *__s2;
  uint64_t *puVar12;
  unsigned long uVar13;
  unsigned long uVar14;
  char *pcVar15;
  char acStack_b0 [8];
  uint8_t *local_a8;
  long local_a0;
  long local_98;
  uint32_t local_8c;
  uint32_t *local_88;
  unsigned long local_80;
  uint64_t *local_78;
  long *local_70;
  long local_68;
  
  local_a0 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_a0 + 0x28);
  pcVar15 = acStack_b0;
  local_98 = param_1;
  local_8c = param_5;
  local_88 = param_3;
  local_78 = param_6;
  local_70 = param_2;
  if (param_6 != (uint64_t *)0x0) {
    uVar1 = *param_3;
    uVar14 = (unsigned long)uVar1;
    pvVar11 = (void *)*param_2;
    pcVar15 = acStack_b0 + -(uVar14 + 0xf & 0x1fffffff0);
    if (uVar1 == 0) {
      uVar9 = 0;
      local_a8 = acStack_b0;
    }
    else {
      uVar5 = 0;
      uVar9 = 0;
      local_80 = (unsigned long)param_7;
      local_a8 = acStack_b0;
      do {
        pcVar15[uVar5] = '\0';
        if (param_7 != 0) {
          uVar13 = local_80;
          puVar12 = local_78;
          do {
            iVar4 = strcmp((char *)*puVar12,(char *)((long)pvVar11 + uVar5 * 0x104));
            if (iVar4 == 0) {
              iVar4 = 0;
              pcVar15[uVar5] = '\x01';
              goto LAB_0015b120;
            }
            uVar13 = uVar13 - 1;
            puVar12 = puVar12 + 1;
          } while (uVar13 != 0);
        }
        iVar4 = 1;
LAB_0015b120:
        uVar5 = uVar5 + 1;
        uVar9 = uVar9 + iVar4;
      } while (uVar5 != uVar14);
    }
    lVar6 = local_98;
    iVar2 = uVar9 * 0x104;
    iVar4 = *(int *)(local_98 + 0x48) + iVar2;
    if ((iVar4 < 0x10000) && (*(long *)(local_98 + 0x40) != 0)) {
      pvVar8 = (void *)(*(long *)(local_98 + 0x40) + (long)*(int *)(local_98 + 0x48));
      *(int *)(local_98 + 0x48) = iVar4;
    }
    else {
      pvVar8 = malloc((long)iVar2);
      ArrayList_add(lVar6 + 0x50,pvVar8);
    }
    memset(pvVar8,0,(long)iVar2);
    if (uVar1 != 0) {
      iVar4 = 0;
      do {
        if (*pcVar15 == '\0') {
          lVar6 = (long)iVar4;
          iVar4 = iVar4 + 1;
          memcpy((void *)((long)pvVar8 + lVar6 * 0x104),pvVar11,0x104);
        }
        pcVar15 = pcVar15 + 1;
        uVar14 = uVar14 - 1;
        pvVar11 = (void *)((long)pvVar11 + 0x104);
      } while (uVar14 != 0);
    }
    *local_70 = (long)pvVar8;
    *local_88 = uVar9;
    pcVar15 = local_a8;
  }
  uVar14 = (unsigned long)local_8c;
  pcVar15 = pcVar15 + -(uVar14 + 0xf & 0x1fffffff0);
  if (local_8c != 0) {
    uVar1 = *local_88;
    uVar5 = 0;
    uVar13 = (unsigned long)uVar1;
    do {
      pcVar15[uVar5] = '\0';
      if (uVar1 != 0) {
        __s1 = (char *)param_4[uVar5];
        __s2 = (char *)*local_70;
        uVar10 = (unsigned long)uVar1;
        do {
          iVar4 = strcmp(__s1,__s2);
          if (iVar4 == 0) {
            iVar4 = 0;
            pcVar15[uVar5] = '\x01';
            goto LAB_0015b26c;
          }
          uVar10 = uVar10 - 1;
          __s2 = __s2 + 0x104;
        } while (uVar10 != 0);
      }
      iVar4 = 1;
LAB_0015b26c:
      puVar7 = local_88;
      lVar6 = local_98;
      uVar5 = uVar5 + 1;
      uVar9 = (int)uVar13 + iVar4;
      uVar13 = (unsigned long)uVar9;
    } while (uVar5 != uVar14);
    if (uVar9 != uVar1) {
      iVar2 = uVar9 * 0x104;
      iVar4 = *(int *)(local_98 + 0x48) + iVar2;
      if ((iVar4 < 0x10000) && (*(long *)(local_98 + 0x40) != 0)) {
        pvVar11 = (void *)(*(long *)(local_98 + 0x40) + (long)*(int *)(local_98 + 0x48));
        *(int *)(local_98 + 0x48) = iVar4;
      }
      else {
        pvVar11 = malloc((long)iVar2);
        ArrayList_add(lVar6 + 0x50,pvVar11);
      }
      memset(pvVar11,0,(long)iVar2);
      if (local_8c != 0) {
        iVar4 = 0;
        do {
          if (*pcVar15 == '\0') {
            pvVar8 = (void *)((long)pvVar11 + (unsigned long)(*puVar7 + iVar4) * 0x104);
            __strcpy_chk(pvVar8,*param_4,0x100);
            *(uint32_t *)((long)pvVar8 + 0x100) = 1;
            puVar7 = local_88;
            iVar4 = iVar4 + 1;
          }
          param_4 = param_4 + 1;
          uVar14 = uVar14 - 1;
          pcVar15 = pcVar15 + 1;
        } while (uVar14 != 0);
      }
      plVar3 = local_70;
      if (*puVar7 != 0) {
        lVar6 = 0;
        uVar14 = 0;
        do {
          memcpy((void *)((long)pvVar11 + lVar6),(void *)(*plVar3 + lVar6),0x104);
          uVar14 = uVar14 + 1;
          lVar6 = lVar6 + 0x104;
        } while (uVar14 < *puVar7);
      }
      *plVar3 = (long)pvVar11;
      *puVar7 = uVar9;
    }
  }
  if (*(long *)(local_a0 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0015eae8  size=16 */

bool isCompressedFormat(int param_1)

{
  return param_1 - 0x83U < 0x36;
}


/* @00160bd4  size=52 */

uint64_t isFormatScaled(uint32_t param_1)

{
  switch(param_1) {
  case 0xb:
  case 0xc:
  case 0x12:
  case 0x13:
  case 0x27:
  case 0x28:
  case 0x48:
  case 0x49:
  case 0x4f:
  case 0x50:
  case 0x5d:
  case 0x5e:
    return 1;
  default:
    return 0;
  }
}


/* @0015acc4  size=60 */

bool isHostVisibleMemory(uint32_t param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((DAT_00194338 != 0) && (param_1 < DAT_00194338)) {
    bVar1 = (*(uint8_t *)(deviceMemoryInfo + (unsigned long)param_1 * 8) & 0xe) != 0;
  }
  return bVar1;
}


