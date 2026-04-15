/*
 * vk_handlers.c — 254 Vulkan command dispatch handlers
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @00143ef4  size=212 */

void vt_handle_vkAcquireNextImage2KHR(long param_1)

{
  long lVar1;
  int iVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  long lVar7;
  int local_54;
  int local_50 [2];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar1 + 0x28);
  lVar7 = *(long *)(param_1 + 0x30);
  uVar3 = VkObject_fromId(*(uint64_t *)(lVar7 + 4));
  uVar6 = *(uint64_t *)(lVar7 + 0xc);
  uVar4 = VkObject_fromId(*(uint64_t *)(lVar7 + 0x14));
  uVar5 = VkObject_fromId(*(uint64_t *)(lVar7 + 0x1c));
  local_54 = 0;
  iVar2 = XWindowSwapchain_acquireNextImage(uVar3,uVar6,uVar4,uVar5,&local_54);
  if (iVar2 == -4) {
    *(uint32_t *)(param_1 + 0x78) = 0xfffffffc;
  }
  local_50[0] = local_54;
  if (iVar2 != 0) {
    local_50[0] = iVar2;
  }
  local_50[1] = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),local_50,8);
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013c400  size=316 */

void vt_handle_vkAcquireNextImageKHR(long param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  unsigned long uVar9;
  long lVar10;
  unsigned long uVar11;
  uint64_t uVar12;
  uint64_t unaff_x21;
  uint64_t unaff_x22;
  uint64_t unaff_x23;
  int local_54;
  int local_50 [2];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar10 = 1;
    lVar4 = param_1;
  }
  else {
    lVar10 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar9 = lVar10 + 1;
  if (pcVar8[lVar10] != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar8 + uVar9);
    uVar9 = (unsigned long)((int)lVar10 + 9);
  }
  uVar12 = *(uint64_t *)(pcVar8 + uVar9);
  uVar11 = uVar9 + 9;
  if ((pcVar8 + uVar9)[8] == '\0') {
    cVar1 = pcVar8[uVar11];
  }
  else {
    unaff_x22 = *(uint64_t *)(pcVar8 + uVar11);
    uVar11 = (unsigned long)((int)uVar9 + 0x11);
    cVar1 = pcVar8[uVar11];
  }
  if (cVar1 != '\0') {
    unaff_x23 = *(uint64_t *)(pcVar8 + uVar11 + 1);
  }
  VkObject_fromId(lVar4);
  uVar5 = VkObject_fromId(unaff_x21);
  uVar6 = VkObject_fromId(unaff_x22);
  uVar7 = VkObject_fromId(unaff_x23);
  local_54 = 0;
  iVar3 = XWindowSwapchain_acquireNextImage(uVar5,uVar12,uVar6,uVar7,&local_54);
  if (iVar3 == -4) {
    *(uint32_t *)(param_1 + 0x78) = 0xfffffffc;
  }
  local_50[0] = local_54;
  if (iVar3 != 0) {
    local_50[0] = iVar3;
  }
  local_50[1] = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),local_50,8);
  if (*(long *)(lVar2 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00137fc8  size=596 */

void vt_handle_vkAllocateCommandBuffers(long param_1)

{
  int iVar1;
  uint32_t *puVar2;
  int iVar3;
  long lVar4;
  uint64_t *puVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  uint8_t *__s;
  char *pcVar8;
  long lVar9;
  unsigned long uVar10;
  unsigned long uVar11;
  uint64_t *puVar12;
  unsigned long uVar13;
  uint64_t *puVar14;
  unsigned long uVar15;
  uint64_t unaff_x20;
  long lVar16;
  uint64_t uVar17;
  uint64_t uVar18;
  unsigned long local_80 [3];
  uint32_t local_68;
  uint32_t local_64;
  uint32_t local_60;
  int iStack_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  local_80[1] = 0;
  local_80[0] = 0;
  local_68 = 0;
  local_64 = 0;
  local_80[2] = 0;
  if (*pcVar8 == '\0') {
    uVar10 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar8 + 1);
    uVar10 = 9;
  }
  if (*(int *)(pcVar8 + uVar10) < 1) {
    uVar10 = 0;
  }
  else {
    puVar2 = (uint32_t *)(pcVar8 + (uVar10 | 4));
    local_80[1] = 0;
    local_80[0] = (unsigned long)*puVar2;
    local_80[2] = VkObject_fromId(*(uint64_t *)(puVar2 + 1));
    local_68 = puVar2[3];
    local_64 = puVar2[4];
    uVar10 = (unsigned long)local_64;
  }
  uVar7 = VkObject_fromId(unaff_x20);
  lVar9 = -(uVar10 * 8 + 0xf & 0xffffffff0);
  lVar16 = (long)local_80 + lVar9;
  uVar6 = ((generic_fn_t)DAT_00193da0)(uVar7,local_80,lVar16);
  iVar3 = 0x1d;
  if (local_64 != 0) {
    iVar3 = local_64 * 8 + 0x1d;
  }
  iVar1 = iVar3 + *(int *)(param_1 + 0x48);
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s = malloc((long)iVar3);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar3);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 0x14;
  *(uint32_t *)(__s + 5) = (uint32_t)local_80[0];
  *(unsigned long *)(__s + 9) = local_80[2];
  *(uint32_t *)(__s + 0x11) = local_68;
  *(uint32_t *)(__s + 0x15) = local_64;
  *(uint32_t *)(__s + 0x19) = local_64;
  uVar10 = (unsigned long)local_64;
  if (local_64 != 0) {
    if (local_64 < 4) {
      uVar11 = 0;
      uVar13 = 0x1d;
    }
    else {
      uVar11 = uVar10 & 0xfffffffc;
      puVar12 = (uint64_t *)((long)local_80 + lVar9 + 0x10);
      puVar14 = (uint64_t *)(__s + 0x2d);
      uVar13 = uVar10 << 3 | 0x1d;
      uVar15 = uVar10 & 0xfffffffc;
      do {
        puVar5 = puVar12 + -1;
        uVar7 = puVar12[-2];
        uVar18 = puVar12[1];
        uVar17 = *puVar12;
        puVar12 = puVar12 + 4;
        uVar15 = uVar15 - 4;
        puVar14[-1] = *puVar5;
        puVar14[-2] = uVar7;
        puVar14[1] = uVar18;
        *puVar14 = uVar17;
        puVar14 = puVar14 + 4;
      } while (uVar15 != 0);
      if (uVar11 == uVar10) goto LAB_001381b4;
    }
    lVar9 = uVar10 - uVar11;
    puVar12 = (uint64_t *)(lVar16 + uVar11 * 8);
    puVar14 = (uint64_t *)(__s + uVar13);
    do {
      lVar9 = lVar9 + -1;
      *puVar14 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar14 = puVar14 + 1;
    } while (lVar9 != 0);
  }
LAB_001381b4:
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  local_60 = uVar6;
  iStack_5c = iVar3;
  uVar10 = RingBuffer_write(uVar7,&local_60,8);
  if (((uVar10 & 1) != 0) && (0 < iVar3)) {
    RingBuffer_write(uVar7,__s,iVar3);
  }
  if (*(long *)(lVar4 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001362e4  size=1096 */

void vt_handle_vkAllocateDescriptorSets(long param_1)

{
  int iVar1;
  char *pcVar2;
  uint32_t uVar3;
  uint64_t *puVar4;
  uint32_t uVar5;
  uint64_t *puVar6;
  uint64_t uVar7;
  void *pvVar8;
  unsigned long uVar9;
  uint32_t *puVar10;
  long lVar11;
  char *pcVar12;
  long lVar13;
  uint32_t uVar14;
  int iVar15;
  size_t __size;
  long lVar16;
  int iVar17;
  unsigned long uVar18;
  long lVar19;
  uint64_t *puVar20;
  uint64_t uVar21;
  uint64_t uVar22;
  unsigned long local_c0;
  char *local_b8;
  long local_b0 [3];
  uint64_t *puStack_98;
  uint64_t local_90;
  unsigned long local_88;
  void *local_80;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar19 + 0x28);
  pcVar12 = *(char **)(param_1 + 0x30);
  local_80 = (void *)0x0;
  puStack_98 = (uint64_t *)0x0;
  local_b0[2] = 0;
  local_88 = 0;
  local_90 = 0;
  if (*pcVar12 == '\0') {
    uVar9 = 1;
    lVar13 = param_1;
  }
  else {
    uVar9 = 9;
    lVar13 = *(long *)(pcVar12 + 1);
  }
  if (0 < *(int *)(pcVar12 + uVar9)) {
    uVar9 = uVar9 | 4;
    puVar10 = (uint32_t *)((long)(pcVar12 + uVar9) + 4);
    iVar17 = 8;
    local_b0[2] = (long)*(uint32_t *)(pcVar12 + uVar9);
    puVar20 = (uint64_t *)0x0;
    local_c0 = uVar9;
    local_b8 = pcVar12;
    local_b0[0] = lVar13;
    local_b0[1] = lVar19;
    do {
      pcVar2 = local_b8;
      if (*puVar10 == 0x3b9d3eeb) {
        iVar1 = *(int *)(pcVar12 + (long)iVar17 + uVar9);
        uVar18 = (long)iVar17 + 4;
        if (iVar1 < 1) goto LAB_0013637c;
        iVar17 = *(int *)(param_1 + 0x48);
        if ((iVar17 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
          puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar17);
          *(int *)(param_1 + 0x48) = iVar17 + 0x20;
        }
        else {
          puVar6 = malloc(0x20);
          ArrayList_add(param_1 + 0x50,puVar6);
        }
        puVar6[1] = 0;
        *puVar6 = 0;
        puVar6[3] = 0;
        puVar6[2] = 0;
        pcVar2 = pcVar12 + uVar18 + uVar9;
        uVar5 = *(uint32_t *)pcVar2;
        puVar6[1] = 0;
        *(uint32_t *)puVar6 = uVar5;
        *(uint32_t *)(puVar6 + 2) = *(uint32_t *)(pcVar2 + 4);
        if (*(int *)(pcVar2 + 8) < 1) {
          puVar6[3] = 0;
        }
        else {
          __size = (long)*(int *)(pcVar2 + 8) << 2;
          iVar15 = (int)__size;
          iVar17 = *(int *)(param_1 + 0x48) + iVar15;
          if ((iVar17 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar8 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            __size = (size_t)iVar15;
            *(int *)(param_1 + 0x48) = iVar17;
          }
          else {
            pvVar8 = malloc(__size);
            ArrayList_add(param_1 + 0x50,pvVar8);
          }
          memset(pvVar8,0,__size);
          if (pvVar8 != (void *)0x0) {
            memcpy(pvVar8,pcVar2 + 0xc,(long)iVar15);
          }
          puVar6[3] = pvVar8;
        }
        iVar17 = iVar1 + (int)uVar18;
        puVar6[1] = puVar20;
      }
      else {
        if (*puVar10 == 0xffffffff) goto LAB_001364ac;
        uVar18 = (unsigned long)(iVar17 + 4);
LAB_0013637c:
        iVar17 = (int)uVar18;
        puVar6 = puVar20;
      }
      puVar10 = (uint32_t *)(pcVar12 + (long)iVar17 + uVar9);
      iVar17 = iVar17 + 4;
      puVar20 = puVar6;
    } while( true );
  }
  uVar14 = 0;
  pvVar8 = local_80;
LAB_001365b4:
  local_80 = pvVar8;
  uVar7 = VkObject_fromId(lVar13);
  lVar13 = -((unsigned long)uVar14 * 8 + 0xf & 0xffffffff0);
  lVar16 = (long)&local_c0 + lVar13;
  uVar5 = ((generic_fn_t)DAT_00193d48)(uVar7,local_b0 + 2,lVar16);
  iVar1 = (uint32_t)local_88 * 8;
  iVar17 = *(int *)(param_1 + 0x48) + iVar1;
  if ((iVar17 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    pvVar8 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar17;
  }
  else {
    pvVar8 = malloc((long)iVar1);
    ArrayList_add(param_1 + 0x50,pvVar8);
  }
  memset(pvVar8,0,(long)iVar1);
  if ((uint32_t)local_88 != 0) {
    if ((uint32_t)local_88 < 4) {
      uVar18 = 0;
      lVar13 = 0;
    }
    else {
      uVar18 = local_88 & 0xfffffffc;
      puVar20 = (uint64_t *)((long)pvVar8 + 0x10);
      puVar6 = (uint64_t *)((long)local_b0 + lVar13);
      lVar13 = uVar18 << 3;
      uVar9 = local_88 & 0xfffffffc;
      do {
        puVar4 = puVar6 + -1;
        uVar7 = puVar6[-2];
        uVar22 = puVar6[1];
        uVar21 = *puVar6;
        uVar9 = uVar9 - 4;
        puVar6 = puVar6 + 4;
        puVar20[-1] = *puVar4;
        puVar20[-2] = uVar7;
        puVar20[1] = uVar22;
        *puVar20 = uVar21;
        puVar20 = puVar20 + 4;
      } while (uVar9 != 0);
      if (uVar18 == (local_88 & 0xffffffff)) goto LAB_001366c0;
    }
    lVar11 = (local_88 & 0xffffffff) - uVar18;
    puVar20 = (uint64_t *)((long)pvVar8 + lVar13);
    puVar6 = (uint64_t *)(lVar16 + uVar18 * 8);
    do {
      lVar11 = lVar11 + -1;
      *puVar20 = *puVar6;
      puVar20 = puVar20 + 1;
      puVar6 = puVar6 + 1;
    } while (lVar11 != 0);
  }
LAB_001366c0:
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  local_70 = uVar5;
  iStack_6c = iVar1;
  uVar9 = RingBuffer_write(uVar7,&local_70,8);
  if (((uVar9 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar7,pvVar8,iVar1);
  }
  if (*(long *)(lVar19 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_001364ac:
  if (puVar20 == (uint64_t *)0x0) {
    puStack_98 = (uint64_t *)0x0;
  }
  else {
    puVar6 = (uint64_t *)0x0;
    do {
      puStack_98 = puVar20;
      puVar20 = (uint64_t *)puStack_98[1];
      puStack_98[1] = puVar6;
      puVar6 = puStack_98;
    } while (puVar20 != (uint64_t *)0x0);
  }
  pcVar12 = pcVar12 + (long)iVar17 + uVar9;
  local_90 = VkObject_fromId(*(uint64_t *)pcVar12);
  lVar19 = local_b0[1];
  uVar14 = *(uint32_t *)(pcVar12 + 8);
  local_88 = ((uint64_t)((*(uint32_t*)((char*)&local_88 + 4))) << 32 | (uint32_t)(uVar14));
  uVar3 = *(uint32_t *)(pcVar12 + 0xc);
  if ((int)uVar3 < 1) {
    local_80 = (void *)0x0;
    lVar13 = local_b0[0];
    pvVar8 = local_80;
  }
  else {
    iVar15 = uVar3 * 8;
    iVar1 = *(int *)(param_1 + 0x48) + iVar15;
    if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar8 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar1;
    }
    else {
      pvVar8 = malloc((long)iVar15);
      ArrayList_add(param_1 + 0x50,pvVar8);
    }
    memset(pvVar8,0,(long)iVar15);
    uVar9 = 0;
    lVar16 = (long)(iVar17 + 0x10) + local_c0;
    do {
      if (pvVar8 != (void *)0x0) {
        uVar7 = VkObject_fromId(*(uint64_t *)(pcVar2 + uVar9 * 8 + lVar16));
        *(uint64_t *)((long)pvVar8 + uVar9 * 8) = uVar7;
      }
      uVar9 = uVar9 + 1;
      lVar13 = local_b0[0];
    } while (uVar3 != uVar9);
  }
  goto LAB_001365b4;
}


/* @00130bac  size=1224 */

void vt_handle_vkAllocateMemory(long param_1)

{
  /* STUB: vt_handle_vkAllocateMemory — Ghidra artifacts */
}


/* @00138354  size=1228 */

void vt_handle_vkBeginCommandBuffer(long param_1)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  void *__s;
  uint64_t uVar9;
  char *pcVar10;
  unsigned long uVar11;
  uint32_t *puVar12;
  int *piVar13;
  uint64_t *puVar14;
  uint64_t *puVar15;
  uint64_t *puVar16;
  int iVar17;
  size_t __size;
  uint64_t *puVar18;
  uint64_t unaff_x28;
  unsigned long local_90;
  uint64_t *puStack_88;
  uint64_t local_80;
  uint64_t *local_78;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar8 + 0x28);
  pcVar10 = *(char **)(param_1 + 0x30);
  puStack_88 = (uint64_t *)0x0;
  local_90 = 0;
  local_78 = (uint64_t *)0x0;
  local_80 = 0;
  if (*pcVar10 == '\0') {
    uVar11 = 1;
  }
  else {
    unaff_x28 = *(uint64_t *)(pcVar10 + 1);
    uVar11 = 9;
  }
  if (0 < *(int *)(pcVar10 + uVar11)) {
    puVar2 = (uint32_t *)(pcVar10 + (uVar11 | 4));
    puVar12 = puVar2 + 1;
    iVar17 = 8;
    local_90 = (unsigned long)*puVar2;
    puVar16 = (uint64_t *)0x0;
    do {
      puVar18 = puVar16;
      if (*puVar12 == 0x3b9bb464) {
        iVar6 = *(int *)((long)puVar2 + (long)iVar17);
        uVar11 = (long)iVar17 + 4;
        if (0 < iVar6) {
          iVar17 = *(int *)(param_1 + 0x48);
          if ((iVar17 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar18 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar17);
            *(int *)(param_1 + 0x48) = iVar17 + 0x18;
          }
          else {
            puVar18 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar18);
          }
          *puVar18 = 0;
          puVar18[1] = 0;
          puVar18[2] = 0;
          puVar3 = (uint32_t *)((long)puVar2 + uVar11);
          uVar11 = (unsigned long)(uint32_t)(iVar6 + (int)uVar11);
          *(uint32_t *)puVar18 = *puVar3;
          uVar5 = puVar3[1];
          puVar18[1] = puVar16;
          *(uint32_t *)(puVar18 + 2) = uVar5;
        }
      }
      else {
        if (*puVar12 == 0xffffffff) goto LAB_00138480;
        uVar11 = (unsigned long)(iVar17 + 4);
      }
      puVar12 = (uint32_t *)((long)puVar2 + (long)(int)uVar11);
      iVar17 = (int)uVar11 + 4;
      puVar16 = puVar18;
    } while( true );
  }
  goto LAB_001387d0;
LAB_00138754:
  if (puVar18 == (uint64_t *)0x0) {
    puVar14 = (uint64_t *)0x0;
  }
  else {
    puVar15 = (uint64_t *)0x0;
    do {
      puVar14 = puVar18;
      puVar18 = (uint64_t *)puVar14[1];
      puVar14[1] = puVar15;
      puVar15 = puVar14;
    } while (puVar18 != (uint64_t *)0x0);
  }
  puVar18 = (uint64_t *)((long)puVar3 + (long)iVar17);
  puVar16[1] = puVar14;
  uVar9 = VkObject_fromId(*puVar18);
  puVar16[2] = uVar9;
  *(uint32_t *)(puVar16 + 3) = *(uint32_t *)(puVar18 + 1);
  uVar9 = VkObject_fromId(*(uint64_t *)((long)puVar18 + 0xc));
  puVar16[4] = uVar9;
  *(uint32_t *)(puVar16 + 5) = *(uint32_t *)((long)puVar18 + 0x14);
  *(uint32_t *)((long)puVar16 + 0x2c) = *(uint32_t *)(puVar18 + 3);
  *(uint32_t *)(puVar16 + 6) = *(uint32_t *)((long)puVar18 + 0x1c);
  goto LAB_001387d0;
LAB_00138480:
  if (puVar16 == (uint64_t *)0x0) {
    puStack_88 = (uint64_t *)0x0;
  }
  else {
    puVar18 = (uint64_t *)0x0;
    do {
      puStack_88 = puVar16;
      puVar16 = (uint64_t *)puStack_88[1];
      puStack_88[1] = puVar18;
      puVar18 = puStack_88;
    } while (puVar16 != (uint64_t *)0x0);
  }
  puVar3 = (uint32_t *)((long)puVar2 + (long)iVar17);
  local_80 = ((uint64_t)((*(uint32_t*)((char*)&local_80 + 4))) << 32 | (uint32_t)(*puVar3));
  if (0 < (int)puVar3[1]) {
    iVar6 = *(int *)(param_1 + 0x48);
    if ((iVar6 < 0xffc8) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar16 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar6);
      *(int *)(param_1 + 0x48) = iVar6 + 0x38;
    }
    else {
      puVar16 = malloc(0x38);
      ArrayList_add(param_1 + 0x50,puVar16);
    }
    puVar3 = (uint32_t *)((long)puVar2 + (long)iVar17 + 8);
    puVar16[6] = 0;
    puVar16[1] = 0;
    *puVar16 = 0;
    puVar16[3] = 0;
    puVar16[2] = 0;
    puVar16[5] = 0;
    puVar16[4] = 0;
    piVar13 = puVar3 + 1;
    puVar18 = (uint64_t *)0x0;
    iVar17 = 8;
    *(uint32_t *)puVar16 = *puVar3;
    local_78 = puVar16;
    do {
      iVar6 = *piVar13;
      if (iVar6 == 0x3b9b75e4) {
        iVar6 = *(int *)((long)puVar3 + (long)iVar17);
        uVar11 = (long)iVar17 + 4;
        if (iVar6 < 1) goto LAB_00138624;
        iVar17 = *(int *)(param_1 + 0x48);
        if ((iVar17 < 0xffc8) && (*(long *)(param_1 + 0x40) != 0)) {
          puVar14 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar17);
          *(int *)(param_1 + 0x48) = iVar17 + 0x38;
        }
        else {
          puVar14 = malloc(0x38);
          ArrayList_add(param_1 + 0x50,puVar14);
        }
        puVar14[6] = 0;
        puVar14[3] = 0;
        puVar14[2] = 0;
        puVar14[5] = 0;
        puVar14[4] = 0;
        puVar14[1] = 0;
        *puVar14 = 0;
        puVar4 = (uint32_t *)((long)puVar3 + uVar11);
        uVar5 = *puVar4;
        puVar14[1] = 0;
        *(uint32_t *)puVar14 = uVar5;
        *(uint32_t *)(puVar14 + 2) = puVar4[1];
        *(uint32_t *)((long)puVar14 + 0x14) = puVar4[2];
        *(uint32_t *)(puVar14 + 3) = puVar4[3];
        if ((int)puVar4[4] < 1) {
          iVar17 = 0x14;
          puVar14[4] = 0;
        }
        else {
          __size = (long)(int)puVar4[4] << 2;
          iVar17 = (int)__size;
          iVar7 = *(int *)(param_1 + 0x48) + iVar17;
          if ((iVar7 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            __size = (size_t)iVar17;
            *(int *)(param_1 + 0x48) = iVar7;
          }
          else {
            __s = malloc(__size);
            ArrayList_add(param_1 + 0x50,__s);
          }
          memset(__s,0,__size);
          if (__s != (void *)0x0) {
            memcpy(__s,puVar4 + 5,(long)iVar17);
          }
          iVar17 = iVar17 + 0x14;
          puVar14[4] = __s;
        }
        puVar4 = (uint32_t *)((long)puVar4 + (long)iVar17);
        iVar17 = iVar6 + (int)uVar11;
        *(uint32_t *)(puVar14 + 5) = *puVar4;
        *(uint32_t *)((long)puVar14 + 0x2c) = puVar4[1];
        *(uint32_t *)(puVar14 + 6) = puVar4[2];
LAB_00138578:
        puVar14[1] = puVar18;
        puVar18 = puVar14;
      }
      else if (iVar6 == 0x3b9c0668) {
        iVar6 = *(int *)((long)puVar3 + (long)iVar17);
        lVar1 = (long)iVar17 + 4;
        iVar17 = (int)lVar1;
        if (0 < iVar6) {
          iVar7 = *(int *)(param_1 + 0x48);
          if ((iVar7 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar14 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar7);
            *(int *)(param_1 + 0x48) = iVar7 + 0x18;
          }
          else {
            puVar14 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar14);
          }
          *puVar14 = 0;
          puVar14[1] = 0;
          puVar14[2] = 0;
          puVar4 = (uint32_t *)((long)puVar3 + lVar1);
          iVar17 = iVar6 + iVar17;
          *(uint32_t *)puVar14 = *puVar4;
          *(uint32_t *)(puVar14 + 2) = puVar4[1];
          goto LAB_00138578;
        }
      }
      else {
        if (iVar6 == -1) goto LAB_00138754;
        uVar11 = (unsigned long)(iVar17 + 4);
LAB_00138624:
        iVar17 = (int)uVar11;
      }
      piVar13 = (int *)((long)puVar3 + (long)iVar17);
      iVar17 = iVar17 + 4;
    } while( true );
  }
  local_78 = (uint64_t *)0x0;
LAB_001387d0:
  uVar9 = VkObject_fromId(unaff_x28);
  ((generic_fn_t)DAT_00193db0)(uVar9,&local_90);
  if (*(long *)(lVar8 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001316e8  size=288 */

void vt_handle_vkBindBufferMemory(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  long lVar4;
  char *pcVar5;
  unsigned long uVar6;
  long lVar7;
  unsigned long uVar8;
  uint64_t uVar9;
  uint64_t unaff_x21;
  uint64_t unaff_x22;
  int local_50 [2];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar1 + 0x28);
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar7 = 1;
    lVar4 = param_1;
  }
  else {
    lVar7 = 9;
    lVar4 = *(long *)(pcVar5 + 1);
  }
  uVar6 = lVar7 + 1;
  if (pcVar5[lVar7] != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar5 + uVar6);
    uVar6 = (unsigned long)((int)lVar7 + 9);
  }
  uVar8 = uVar6 + 1;
  if (pcVar5[uVar6] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar5 + uVar8);
    uVar8 = (unsigned long)((int)uVar6 + 9);
  }
  uVar9 = *(uint64_t *)(pcVar5 + uVar8);
  uVar2 = VkObject_fromId(lVar4);
  uVar3 = VkObject_fromId(unaff_x21);
  lVar4 = VkObject_fromId(unaff_x22);
  local_50[0] = ((generic_fn_t)DAT_00193bc0)(uVar2,uVar3,*(uint64_t *)(lVar4 + 0x18),uVar9);
  if ((local_50[0] == 0) && (*(long *)(param_1 + 0x80) != 0)) {
    TextureDecoder_addBoundBuffer(*(long *)(param_1 + 0x80),lVar4,uVar3,uVar9);
  }
  local_50[1] = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),local_50,8);
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001434e0  size=404 */

void vt_handle_vkBindBufferMemory2(long param_1)

{
  /* STUB: vt_handle_vkBindBufferMemory2 — Ghidra artifacts */
}


/* @00131950  size=256 */

void vt_handle_vkBindImageMemory(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  long lVar4;
  char *pcVar5;
  unsigned long uVar6;
  long lVar7;
  unsigned long uVar8;
  uint64_t unaff_x20;
  uint64_t unaff_x21;
  uint64_t uVar9;
  uint32_t local_50;
  uint32_t uStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar1 + 0x28);
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar7 = 1;
    lVar4 = param_1;
  }
  else {
    lVar7 = 9;
    lVar4 = *(long *)(pcVar5 + 1);
  }
  uVar6 = lVar7 + 1;
  if (pcVar5[lVar7] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar5 + uVar6);
    uVar6 = (unsigned long)((int)lVar7 + 9);
  }
  uVar8 = uVar6 + 1;
  if (pcVar5[uVar6] != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar5 + uVar8);
    uVar8 = (unsigned long)((int)uVar6 + 9);
  }
  uVar9 = *(uint64_t *)(pcVar5 + uVar8);
  uVar2 = VkObject_fromId(lVar4);
  uVar3 = VkObject_fromId(unaff_x20);
  lVar4 = VkObject_fromId(unaff_x21);
  local_50 = ((generic_fn_t)DAT_00193bd0)(uVar2,uVar3,*(uint64_t *)(lVar4 + 0x18),uVar9);
  uStack_4c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_50,8);
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00143928  size=1408 */

void vt_handle_vkBindImageMemory2(long param_1)

{
  int iVar1;
  char *pcVar2;
  uint32_t uVar3;
  int iVar4;
  char cVar5;
  long lVar6;
  uint64_t uVar7;
  uint64_t *puVar8;
  void *pvVar9;
  uint32_t uVar10;
  char *pcVar11;
  long lVar12;
  uint32_t *puVar13;
  long lVar14;
  int *piVar15;
  uint64_t *puVar16;
  unsigned long uVar17;
  int iVar18;
  size_t __size;
  uint64_t *puVar19;
  int iVar20;
  uint64_t local_c0;
  unsigned long uStack_b8;
  long local_b0;
  long local_a8;
  unsigned long local_a0;
  char *local_98;
  int local_8c;
  long local_88;
  unsigned long local_80;
  char *local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  local_b0 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_b0 + 0x28);
  pcVar11 = *(char **)(param_1 + 0x30);
  if (*pcVar11 == '\0') {
    lVar14 = 1;
    lVar6 = param_1;
  }
  else {
    lVar14 = 9;
    lVar6 = *(long *)(pcVar11 + 1);
  }
  uVar17 = (unsigned long)*(uint32_t *)(pcVar11 + lVar14);
  local_c0 = VkObject_fromId(lVar6);
  lVar6 = (long)&local_c0 - (uVar17 * 0x28 + 0xf & 0x7ffffffff0);
  local_98 = *(char **)(param_1 + 0x30);
  uVar10 = 9;
  if (*local_98 == '\0') {
    uVar10 = 1;
  }
  local_a0 = (unsigned long)*(uint32_t *)(local_98 + (unsigned long)uVar10 + 4);
  uStack_b8 = uVar17;
  if ((int)*(uint32_t *)(local_98 + (unsigned long)uVar10 + 4) < 1) {
LAB_00143e40:
    local_70 = ((generic_fn_t)DAT_00194008)(local_c0,uStack_b8,lVar6);
    uStack_6c = 0;
    RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_70,8);
    if (*(long *)(local_b0 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  uVar17 = 0;
  iVar18 = uVar10 + 8;
  local_a8 = lVar6;
LAB_00143a2c:
  local_88 = (long)iVar18 + 4;
  local_8c = *(int *)(local_98 + iVar18);
  piVar15 = (int *)(local_98 + local_88 + 4);
  pcVar11 = local_98 + local_88;
  iVar18 = 8;
  local_80 = uVar17;
  *(uint32_t *)(lVar6 + uVar17 * 0x28) = *(uint32_t *)(local_98 + local_88);
  puVar19 = (uint64_t *)0x0;
  local_78 = pcVar11;
  do {
    uVar17 = local_80;
    lVar6 = local_a8;
    iVar20 = *piVar15;
    puVar8 = puVar19;
    if (iVar20 < 0x3b9bb46e) {
      if (iVar20 == 0x3b9bb469) {
        iVar20 = *(int *)(pcVar11 + iVar18);
        lVar6 = (long)iVar18 + 4;
        if (0 < iVar20) {
          iVar18 = *(int *)(param_1 + 0x48);
          if ((iVar18 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar18);
            *(int *)(param_1 + 0x48) = iVar18 + 0x20;
          }
          else {
            puVar8 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          puVar8[1] = 0;
          *puVar8 = 0;
          puVar8[3] = 0;
          puVar8[2] = 0;
          pcVar2 = pcVar11 + lVar6;
          uVar3 = *(uint32_t *)pcVar2;
          puVar8[1] = 0;
          *(uint32_t *)puVar8 = uVar3;
          uVar7 = VkObject_fromId(*(uint64_t *)(pcVar2 + 4));
          puVar8[2] = uVar7;
          iVar20 = iVar20 + (int)lVar6;
          *(uint32_t *)(puVar8 + 3) = *(uint32_t *)(pcVar2 + 0xc);
          goto LAB_00143c00;
        }
LAB_00143a6c:
        iVar20 = (int)lVar6;
      }
      else {
        if (iVar20 == -1) break;
LAB_00143b6c:
        uVar17 = (unsigned long)(iVar18 + 4);
LAB_00143b70:
        iVar20 = (int)uVar17;
      }
    }
    else if (iVar20 == 0x3b9d2b62) {
      iVar20 = *(int *)(pcVar11 + iVar18);
      uVar17 = (long)iVar18 + 4;
      if (iVar20 < 1) goto LAB_00143b70;
      iVar18 = *(int *)(param_1 + 0x48);
      if ((iVar18 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
        puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar18);
        *(int *)(param_1 + 0x48) = iVar18 + 0x18;
      }
      else {
        puVar8 = malloc(0x18);
        ArrayList_add(param_1 + 0x50,puVar8);
      }
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar8[2] = 0;
      uVar3 = *(uint32_t *)(pcVar11 + uVar17);
      puVar8[1] = 0;
      iVar20 = iVar20 + (int)uVar17;
      *(uint32_t *)puVar8 = uVar3;
      *(uint32_t *)(puVar8 + 2) = *(uint32_t *)(pcVar11 + uVar17 + 4);
LAB_00143c00:
      puVar8[1] = puVar19;
    }
    else {
      if (iVar20 != 0x3b9bb46e) goto LAB_00143b6c;
      iVar20 = *(int *)(pcVar11 + iVar18);
      lVar6 = (long)iVar18 + 4;
      if (iVar20 < 1) goto LAB_00143a6c;
      iVar18 = *(int *)(param_1 + 0x48);
      if ((iVar18 < 0xffd0) && (*(long *)(param_1 + 0x40) != 0)) {
        puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar18);
        *(int *)(param_1 + 0x48) = iVar18 + 0x30;
      }
      else {
        puVar8 = malloc(0x30);
        ArrayList_add(param_1 + 0x50,puVar8);
      }
      puVar8[3] = 0;
      puVar8[2] = 0;
      puVar8[5] = 0;
      puVar8[4] = 0;
      puVar8[1] = 0;
      *puVar8 = 0;
      pcVar2 = pcVar11 + lVar6;
      uVar3 = *(uint32_t *)pcVar2;
      puVar8[1] = 0;
      *(uint32_t *)puVar8 = uVar3;
      *(uint32_t *)(puVar8 + 2) = *(uint32_t *)(pcVar2 + 4);
      if (*(int *)(pcVar2 + 8) < 1) {
        iVar18 = 0xc;
        puVar8[3] = 0;
      }
      else {
        __size = (long)*(int *)(pcVar2 + 8) << 2;
        iVar18 = (int)__size;
        iVar1 = *(int *)(param_1 + 0x48) + iVar18;
        if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar9 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          __size = (size_t)iVar18;
          *(int *)(param_1 + 0x48) = iVar1;
        }
        else {
          pvVar9 = malloc(__size);
          ArrayList_add(param_1 + 0x50,pvVar9);
        }
        memset(pvVar9,0,__size);
        if (pvVar9 != (void *)0x0) {
          memcpy(pvVar9,pcVar2 + 0xc,(long)iVar18);
        }
        iVar18 = iVar18 + 0xc;
        puVar8[3] = pvVar9;
        pcVar11 = local_78;
      }
      *(uint32_t *)(puVar8 + 4) = *(uint32_t *)(pcVar2 + iVar18);
      uVar10 = *(uint32_t *)(pcVar2 + iVar18 + 4);
      uVar17 = (unsigned long)uVar10;
      if ((int)uVar10 < 1) {
        puVar8[5] = 0;
      }
      else {
        iVar4 = uVar10 * 0x10;
        iVar1 = *(int *)(param_1 + 0x48) + iVar4;
        if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar9 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar1;
        }
        else {
          pvVar9 = malloc((long)iVar4);
          ArrayList_add(param_1 + 0x50,pvVar9);
        }
        iVar18 = iVar18 + 8;
        memset(pvVar9,0,(long)iVar4);
        puVar13 = (uint32_t *)((long)pvVar9 + 8);
        do {
          iVar1 = *(int *)(pcVar2 + iVar18);
          lVar14 = (long)iVar18 + 4;
          if (pvVar9 != (void *)0x0) {
            pcVar11 = pcVar2 + lVar14;
            puVar13[-2] = *(uint32_t *)pcVar11;
            puVar13[-1] = *(uint32_t *)(pcVar11 + 4);
            *puVar13 = *(uint32_t *)(pcVar11 + 8);
            puVar13[1] = *(uint32_t *)(pcVar11 + 0xc);
          }
          iVar18 = iVar1 + (int)lVar14;
          uVar17 = uVar17 - 1;
          puVar13 = puVar13 + 4;
        } while (uVar17 != 0);
        puVar8[5] = pvVar9;
        pcVar11 = local_78;
      }
      iVar20 = iVar20 + (int)lVar6;
      puVar8[1] = puVar19;
    }
    piVar15 = (int *)(pcVar11 + iVar20);
    iVar18 = iVar20 + 4;
    puVar19 = puVar8;
  } while( true );
  if (puVar19 == (uint64_t *)0x0) {
    puVar8 = (uint64_t *)0x0;
  }
  else {
    puVar16 = (uint64_t *)0x0;
    do {
      puVar8 = puVar19;
      puVar19 = (uint64_t *)puVar8[1];
      puVar8[1] = puVar16;
      puVar16 = puVar8;
    } while (puVar19 != (uint64_t *)0x0);
  }
  lVar14 = local_a8 + local_80 * 0x28;
  *(uint64_t **)(lVar14 + 8) = puVar8;
  pcVar11 = local_78 + iVar18;
  uVar7 = VkObject_fromId(*(uint64_t *)pcVar11);
  *(uint64_t *)(lVar14 + 0x10) = uVar7;
  cVar5 = vortekSerializerCastVkObject;
  lVar14 = VkObject_fromId(*(uint64_t *)(pcVar11 + 8));
  if (cVar5 != '\0') {
    lVar14 = *(long *)(lVar14 + 0x18);
  }
  lVar12 = lVar6 + uVar17 * 0x28;
  *(long *)(lVar12 + 0x18) = lVar14;
  uVar17 = uVar17 + 1;
  *(uint64_t *)(lVar12 + 0x20) = *(uint64_t *)(local_78 + (long)iVar18 + 0x10);
  iVar18 = local_8c + (int)local_88;
  if (uVar17 == local_a0) goto LAB_00143e40;
  goto LAB_00143a2c;
}


/* @0013b0b4  size=204 */

void vt_handle_vkCmdBeginConditionalRenderingEXT(long param_1)

{
  uint32_t *puVar1;
  long lVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  uint64_t unaff_x19;
  unsigned long local_60 [4];
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar4 = *(char **)(param_1 + 0x30);
  local_40 = 0;
  local_60[1] = 0;
  local_60[0] = 0;
  local_60[3] = 0;
  local_60[2] = 0;
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar4 + 1);
    uVar5 = 9;
  }
  if (0 < *(int *)(pcVar4 + uVar5)) {
    puVar1 = (uint32_t *)(pcVar4 + (uVar5 | 4));
    local_60[1] = 0;
    local_60[0] = (unsigned long)*puVar1;
    local_60[2] = VkObject_fromId(*(uint64_t *)(puVar1 + 1));
    local_60[3] = *(unsigned long *)(puVar1 + 3);
    local_40 = ((uint64_t)((*(uint32_t*)((char*)&local_40 + 4))) << 32 | (uint32_t)(puVar1[5]));
  }
  uVar3 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_00193ee8)(uVar3,local_60);
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013afa4  size=140 */

void vt_handle_vkCmdBeginQuery(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  unsigned long uVar7;
  uint64_t unaff_x19;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
  }
  uVar7 = lVar6 + 1;
  if (pcVar5[lVar6] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar5 + uVar7);
    uVar7 = (unsigned long)((int)lVar6 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar5 + uVar7);
  uVar2 = *(uint32_t *)(pcVar5 + uVar7 + 4);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013b02c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193ed8)(uVar3,uVar4,uVar1,uVar2);
  return;
}


/* @001483f8  size=156 */

void vt_handle_vkCmdBeginQueryIndexedEXT(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  long lVar7;
  unsigned long uVar8;
  uint64_t unaff_x19;
  
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
  }
  else {
    param_1 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
  }
  uVar8 = lVar7 + 1;
  if (pcVar6[lVar7] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar6 + uVar8);
    uVar8 = (unsigned long)((int)lVar7 + 9);
  }
  pcVar6 = pcVar6 + uVar8;
  uVar1 = *(uint32_t *)pcVar6;
  uVar2 = *(uint32_t *)(pcVar6 + 4);
  uVar3 = *(uint32_t *)(pcVar6 + 8);
  uVar4 = VkObject_fromId(param_1);
  uVar5 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00148490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194120)(uVar4,uVar5,uVar1,uVar2,uVar3);
  return;
}


/* @0013b4dc  size=192 */

void vt_handle_vkCmdBeginRenderPass(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  long lVar3;
  uint64_t uVar4;
  long lVar5;
  uint64_t unaff_x19;
  char *pcVar6;
  uint32_t uVar7;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t uStack_60;
  uint64_t uStack_58;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar3 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  if (*pcVar6 == '\0') {
    lVar5 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar6 + 1);
    lVar5 = 9;
  }
  iVar1 = *(int *)(pcVar6 + lVar5);
  uVar7 = (uint32_t)lVar5 | 4;
  if (0 < iVar1) {
    FUN_0014f148(&local_90,pcVar6 + uVar7,param_1 + 0x40);
    uVar7 = uVar7 + iVar1;
  }
  uVar2 = *(uint32_t *)(pcVar6 + (int)uVar7);
  uVar4 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_00193f18)(uVar4,&local_90,uVar2);
  if (*(long *)(lVar3 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001479e0  size=236 */

void vt_handle_vkCmdBeginRenderPass2(long param_1)

{
  int iVar1;
  long lVar2;
  uint64_t uVar3;
  long lVar4;
  uint64_t unaff_x19;
  char *pcVar5;
  uint32_t uVar6;
  uint64_t local_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t uStack_60;
  uint64_t uStack_58;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  pcVar5 = *(char **)(param_1 + 0x30);
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  if (*pcVar5 == '\0') {
    lVar4 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar5 + 1);
    lVar4 = 9;
  }
  iVar1 = *(int *)(pcVar5 + lVar4);
  uVar6 = (uint32_t)lVar4 | 4;
  if (0 < iVar1) {
    FUN_0014f148(&local_90,pcVar5 + uVar6,param_1 + 0x40);
    uVar6 = uVar6 + iVar1;
  }
  lVar4 = (long)(int)uVar6;
  if (0 < *(int *)(pcVar5 + lVar4)) {
    local_a0 = 0;
    local_a8 = ((uint64_t)((*(uint32_t*)((char*)&local_a8 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar5 + lVar4 + 4)));
    local_98 = ((uint64_t)((*(uint32_t*)((char*)&local_98 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar5 + lVar4 + 8)));
  }
  uVar3 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_001940c0)(uVar3,&local_90,&local_a8);
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0014b084  size=1420 */

void vt_handle_vkCmdBeginRendering(long param_1)

{
  long lVar1;
  int iVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  long lVar8;
  uint64_t *puVar9;
  void *pvVar10;
  uint64_t uVar11;
  char *pcVar12;
  uint32_t *puVar13;
  unsigned long uVar14;
  uint32_t *puVar15;
  int iVar16;
  uint32_t *puVar17;
  unsigned long uVar18;
  uint64_t unaff_x27;
  uint64_t *puVar19;
  unsigned long local_b0;
  uint64_t *puStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  uint64_t uStack_88;
  void *local_80;
  uint64_t *local_78;
  uint64_t *local_70;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar8 + 0x28);
  pcVar12 = *(char **)(param_1 + 0x30);
  local_70 = (uint64_t *)0x0;
  uStack_88 = 0;
  local_90 = 0;
  local_78 = (uint64_t *)0x0;
  local_80 = (void *)0x0;
  puStack_a8 = (uint64_t *)0x0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  if (*pcVar12 == '\0') {
    uVar14 = 1;
  }
  else {
    unaff_x27 = *(uint64_t *)(pcVar12 + 1);
    uVar14 = 9;
  }
  if (0 < *(int *)(pcVar12 + uVar14)) {
    puVar3 = (uint32_t *)(pcVar12 + (uVar14 | 4));
    puVar15 = puVar3 + 1;
    iVar16 = 8;
    local_b0 = (unsigned long)*puVar3;
    puVar19 = (uint64_t *)0x0;
    do {
      if (*puVar15 == 0x3b9bb463) {
        iVar2 = *(int *)((long)puVar3 + (long)iVar16);
        uVar14 = (long)iVar16 + 4;
        if (iVar2 < 1) goto LAB_0014b128;
        iVar16 = *(int *)(param_1 + 0x48);
        if ((iVar16 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
          puVar9 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar16);
          *(int *)(param_1 + 0x48) = iVar16 + 0x20;
        }
        else {
          puVar9 = malloc(0x20);
          ArrayList_add(param_1 + 0x50,puVar9);
        }
        puVar9[1] = 0;
        *puVar9 = 0;
        puVar9[3] = 0;
        puVar9[2] = 0;
        puVar17 = (uint32_t *)((long)puVar3 + uVar14);
        uVar6 = *puVar17;
        puVar9[1] = 0;
        *(uint32_t *)puVar9 = uVar6;
        *(uint32_t *)(puVar9 + 2) = puVar17[1];
        *(uint32_t *)((long)puVar9 + 0x14) = puVar17[2];
        uVar5 = puVar17[3];
        uVar18 = (unsigned long)uVar5;
        if ((int)uVar5 < 1) {
          puVar9[3] = 0;
        }
        else {
          iVar7 = uVar5 * 0x10;
          iVar16 = *(int *)(param_1 + 0x48) + iVar7;
          if ((iVar16 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar10 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar16;
          }
          else {
            pvVar10 = malloc((long)iVar7);
            ArrayList_add(param_1 + 0x50,pvVar10);
          }
          memset(pvVar10,0,(long)iVar7);
          puVar13 = (uint32_t *)((long)pvVar10 + 8);
          iVar16 = 0x10;
          do {
            iVar7 = *(int *)((long)puVar17 + (long)iVar16);
            lVar1 = (long)iVar16 + 4;
            if (pvVar10 != (void *)0x0) {
              puVar4 = (uint32_t *)((long)puVar17 + lVar1);
              puVar13[-2] = *puVar4;
              puVar13[-1] = puVar4[1];
              *puVar13 = puVar4[2];
              puVar13[1] = puVar4[3];
            }
            iVar16 = iVar7 + (int)lVar1;
            uVar18 = uVar18 - 1;
            puVar13 = puVar13 + 4;
          } while (uVar18 != 0);
          puVar9[3] = pvVar10;
        }
        iVar16 = iVar2 + (int)uVar14;
        puVar9[1] = puVar19;
      }
      else {
        if (*puVar15 == 0xffffffff) goto LAB_0014b2a8;
        uVar14 = (unsigned long)(iVar16 + 4);
LAB_0014b128:
        iVar16 = (int)uVar14;
        puVar9 = puVar19;
      }
      puVar15 = (uint32_t *)((long)puVar3 + (long)iVar16);
      iVar16 = iVar16 + 4;
      puVar19 = puVar9;
    } while( true );
  }
LAB_0014b5c0:
  uVar11 = VkObject_fromId(unaff_x27);
  ((generic_fn_t)DAT_001942e0)(uVar11,&local_b0);
  if (*(long *)(lVar8 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0014b2a8:
  if (puVar19 == (uint64_t *)0x0) {
    puStack_a8 = (uint64_t *)0x0;
  }
  else {
    puVar9 = (uint64_t *)0x0;
    do {
      puStack_a8 = puVar19;
      puVar19 = (uint64_t *)puStack_a8[1];
      puStack_a8[1] = puVar9;
      puVar9 = puStack_a8;
    } while (puVar19 != (uint64_t *)0x0);
  }
  puVar19 = (uint64_t *)((long)puVar3 + (long)iVar16);
  iVar16 = iVar16 + 0x24;
  local_a0 = *puVar19;
  local_98 = puVar19[1];
  local_90 = puVar19[2];
  uStack_88 = puVar19[3];
  uVar5 = *(uint32_t *)(puVar19 + 4);
  uVar14 = (unsigned long)uVar5;
  if ((int)uVar5 < 1) {
    local_80 = (void *)0x0;
    pvVar10 = local_80;
  }
  else {
    iVar7 = uVar5 * 0x48;
    iVar2 = *(int *)(param_1 + 0x48) + iVar7;
    if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar10 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar2;
    }
    else {
      pvVar10 = malloc((long)iVar7);
      ArrayList_add(param_1 + 0x50,pvVar10);
    }
    memset(pvVar10,0,(long)iVar7);
    puVar17 = (uint32_t *)((long)pvVar10 + 0x1c);
    do {
      iVar2 = *(int *)((long)puVar3 + (long)iVar16);
      lVar1 = (long)iVar16 + 4;
      if (pvVar10 != (void *)0x0) {
        puVar13 = (uint32_t *)((long)puVar3 + lVar1);
        uVar6 = *puVar13;
        *(uint64_t *)(puVar17 + -5) = 0;
        puVar17[-7] = uVar6;
        uVar11 = VkObject_fromId(*(uint64_t *)(puVar13 + 1));
        *(uint64_t *)(puVar17 + -3) = uVar11;
        puVar17[-1] = puVar13[3];
        *puVar17 = puVar13[4];
        uVar11 = VkObject_fromId(*(uint64_t *)(puVar13 + 5));
        *(uint64_t *)(puVar17 + 1) = uVar11;
        puVar17[3] = puVar13[7];
        puVar17[4] = puVar13[8];
        puVar17[5] = puVar13[9];
        uVar11 = *(uint64_t *)(puVar13 + 10);
        *(uint64_t *)(puVar17 + 8) = *(uint64_t *)(puVar13 + 0xc);
        *(uint64_t *)(puVar17 + 6) = uVar11;
      }
      iVar16 = iVar2 + (int)lVar1;
      uVar14 = uVar14 - 1;
      puVar17 = puVar17 + 0x12;
    } while (uVar14 != 0);
  }
  local_80 = pvVar10;
  iVar2 = *(int *)((long)puVar3 + (long)iVar16);
  uVar14 = (long)iVar16 + 4;
  if (iVar2 < 1) {
    local_78 = (uint64_t *)0x0;
  }
  else {
    iVar16 = *(int *)(param_1 + 0x48);
    if ((iVar16 < 0xffb8) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar19 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar16);
      *(int *)(param_1 + 0x48) = iVar16 + 0x48;
    }
    else {
      puVar19 = malloc(0x48);
      ArrayList_add(param_1 + 0x50,puVar19);
    }
    puVar19[8] = 0;
    puVar17 = (uint32_t *)((long)puVar3 + uVar14);
    puVar19[5] = 0;
    puVar19[4] = 0;
    puVar19[7] = 0;
    puVar19[6] = 0;
    puVar19[1] = 0;
    *puVar19 = 0;
    puVar19[3] = 0;
    puVar19[2] = 0;
    uVar6 = *puVar17;
    puVar19[1] = 0;
    *(uint32_t *)puVar19 = uVar6;
    local_78 = puVar19;
    uVar11 = VkObject_fromId(*(uint64_t *)(puVar17 + 1));
    puVar19[2] = uVar11;
    *(uint32_t *)(puVar19 + 3) = puVar17[3];
    *(uint32_t *)((long)puVar19 + 0x1c) = puVar17[4];
    uVar11 = VkObject_fromId(*(uint64_t *)(puVar17 + 5));
    puVar19[4] = uVar11;
    uVar14 = (unsigned long)(uint32_t)((int)uVar14 + iVar2);
    *(uint32_t *)(puVar19 + 5) = puVar17[7];
    *(uint32_t *)((long)puVar19 + 0x2c) = puVar17[8];
    *(uint32_t *)(puVar19 + 6) = puVar17[9];
    uVar11 = *(uint64_t *)(puVar17 + 10);
    *(uint64_t *)((long)puVar19 + 0x3c) = *(uint64_t *)(puVar17 + 0xc);
    *(uint64_t *)((long)puVar19 + 0x34) = uVar11;
  }
  if (*(int *)((long)puVar3 + (long)(int)uVar14) < 1) {
    local_70 = (uint64_t *)0x0;
  }
  else {
    iVar16 = *(int *)(param_1 + 0x48);
    if ((iVar16 < 0xffb8) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar19 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar16);
      *(int *)(param_1 + 0x48) = iVar16 + 0x48;
    }
    else {
      puVar19 = malloc(0x48);
      ArrayList_add(param_1 + 0x50,puVar19);
    }
    puVar19[8] = 0;
    puVar17 = (uint32_t *)((long)puVar3 + (long)(int)uVar14 + 4);
    puVar19[5] = 0;
    puVar19[4] = 0;
    puVar19[7] = 0;
    puVar19[6] = 0;
    puVar19[1] = 0;
    *puVar19 = 0;
    puVar19[3] = 0;
    puVar19[2] = 0;
    uVar6 = *puVar17;
    puVar19[1] = 0;
    *(uint32_t *)puVar19 = uVar6;
    local_70 = puVar19;
    uVar11 = VkObject_fromId(*(uint64_t *)(puVar17 + 1));
    puVar19[2] = uVar11;
    *(uint32_t *)(puVar19 + 3) = puVar17[3];
    *(uint32_t *)((long)puVar19 + 0x1c) = puVar17[4];
    uVar11 = VkObject_fromId(*(uint64_t *)(puVar17 + 5));
    puVar19[4] = uVar11;
    *(uint32_t *)(puVar19 + 5) = puVar17[7];
    *(uint32_t *)((long)puVar19 + 0x2c) = puVar17[8];
    *(uint32_t *)(puVar19 + 6) = puVar17[9];
    uVar11 = *(uint64_t *)(puVar17 + 10);
    *(uint64_t *)((long)puVar19 + 0x3c) = *(uint64_t *)(puVar17 + 0xc);
    *(uint64_t *)((long)puVar19 + 0x34) = uVar11;
  }
  goto LAB_0014b5c0;
}


/* @00148158  size=336 */

void vt_handle_vkCmdBeginTransformFeedbackEXT(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint32_t uVar7;
  char *pcVar8;
  unsigned long uVar9;
  uint64_t *puVar10;
  void *__dest;
  unsigned long uVar11;
  uint64_t *puVar12;
  long alStack_70 [2];
  
  /* stack canary setup */
  alStack_70[1] = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar9 = 1;
    lVar4 = param_1;
  }
  else {
    uVar9 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar8 + uVar9);
  uVar2 = *(uint32_t *)(pcVar8 + (uVar9 | 4));
  uVar5 = VkObject_fromId(lVar4);
  uVar9 = (unsigned long)uVar2 * 8 + 0xf & 0xffffffff0;
  puVar10 = (uint64_t *)((long)alStack_70 - uVar9);
  __dest = (void *)((long)puVar10 - uVar9);
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar8 == '\0') {
    uVar7 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar7 + 8);
  if ((int)*(uint32_t *)(pcVar8 + (unsigned long)uVar7 + 8) < 1) {
    uVar11 = (unsigned long)(uVar7 + 0xc);
  }
  else {
    uVar11 = (unsigned long)uVar7 + 8 | 4;
    puVar12 = puVar10;
    do {
      uVar6 = VkObject_fromId(*(uint64_t *)(pcVar8 + uVar11));
      *puVar12 = uVar6;
      uVar9 = uVar9 - 1;
      uVar11 = uVar11 + 8;
      puVar12 = puVar12 + 1;
    } while (uVar9 != 0);
  }
  if (0 < *(int *)(pcVar8 + (int)uVar11)) {
    memcpy(__dest,pcVar8 + (long)(int)uVar11 + 4,(long)*(int *)(pcVar8 + (int)uVar11) << 3);
  }
  ((generic_fn_t)DAT_00194110)(uVar5,uVar1,(unsigned long)uVar2,puVar10,__dest);
  if (*(long *)(lVar3 + 0x28) != alStack_70[1]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00138ecc  size=480 */

void vt_handle_vkCmdBindDescriptorSets(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  void *pvVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t uVar9;
  int iVar10;
  unsigned long uVar11;
  unsigned long uVar12;
  uint64_t unaff_x24;
  char *pcVar13;
  uint64_t *puVar14;
  uint64_t *puVar15;
  void *local_80;
  uint32_t local_78;
  uint32_t uStack_74;
  long local_70;
  long local_68;
  
  local_70 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_70 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar12 = 1;
    lVar4 = param_1;
  }
  else {
    uVar12 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar11 = uVar12 + 5;
  if (pcVar8[uVar12 | 4] != '\0') {
    unaff_x24 = *(uint64_t *)(pcVar8 + uVar11);
    uVar11 = (unsigned long)((int)uVar12 + 0xd);
  }
  pcVar13 = pcVar8 + uVar11;
  uVar1 = *(uint32_t *)(pcVar13 + 4);
  local_78 = *(uint32_t *)(pcVar8 + uVar12);
  uStack_74 = *(uint32_t *)pcVar13;
  iVar10 = *(int *)(pcVar13 + 8) << 3;
  if (*(int *)(pcVar13 + 8) < 1) {
    iVar10 = 0;
  }
  uVar2 = *(uint32_t *)(pcVar8 + ((int)uVar11 + iVar10 + 0xc));
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x24);
  puVar14 = (uint64_t *)((long)&local_80 - ((unsigned long)uVar1 * 8 + 0xf & 0xffffffff0));
  local_80 = (void *)((long)puVar14 - ((unsigned long)uVar2 * 4 + 0xf & 0x7fffffff0));
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  iVar10 = 5;
  if (pcVar8[(unsigned long)uVar9 + 4] != '\0') {
    iVar10 = 0xd;
  }
  uVar9 = iVar10 + uVar9;
  uVar12 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 8);
  iVar10 = uVar9 + 0xc;
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 8)) {
    pcVar13 = pcVar8 + (unsigned long)uVar9 + 0xc;
    puVar15 = puVar14;
    do {
      uVar7 = VkObject_fromId(*(uint64_t *)pcVar13);
      *puVar15 = uVar7;
      uVar12 = uVar12 - 1;
      iVar10 = iVar10 + 8;
      pcVar13 = pcVar13 + 8;
      puVar15 = puVar15 + 1;
    } while (uVar12 != 0);
  }
  pvVar3 = local_80;
  if (0 < *(int *)(pcVar8 + (long)iVar10 + 4)) {
    memcpy(local_80,pcVar8 + (long)iVar10 + 8,(long)*(int *)(pcVar8 + (long)iVar10 + 4) << 2);
  }
  ((generic_fn_t)DAT_00193e18)(uVar5,local_78,uVar6,uStack_74,(unsigned long)uVar1,puVar14,(unsigned long)uVar2,pvVar3);
  if (*(long *)(local_70 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001390ac  size=144 */

void vt_handle_vkCmdBindIndexBuffer(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t unaff_x19;
  uint64_t uVar7;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar6 = lVar5 + 1;
  if (pcVar4[lVar5] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 9);
  }
  uVar7 = *(uint64_t *)(pcVar4 + uVar6);
  uVar1 = *(uint32_t *)(pcVar4 + uVar6 + 8);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00139138. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e20)(uVar2,uVar3,uVar7,uVar1);
  return;
}


/* @00138958  size=132 */

void vt_handle_vkCmdBindPipeline(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  uint64_t unaff_x20;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    uVar5 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar5);
  if (pcVar4[uVar5 | 4] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar4 + uVar5 + 5);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x20);
                    /* WARNING: Could not recover jumptable at 0x001389d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193dc8)(uVar2,uVar1,uVar3);
  return;
}


/* @00147fc4  size=404 */

void vt_handle_vkCmdBindTransformFeedbackBuffersEXT(long param_1)

{
  uint32_t uVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  uint32_t uVar6;
  char *pcVar7;
  unsigned long uVar8;
  uint64_t *puVar9;
  uint64_t *puVar10;
  void *__dest;
  unsigned long uVar11;
  size_t __n;
  unsigned long uVar12;
  uint64_t uStack_70;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar2 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar8 = 1;
    lVar3 = param_1;
  }
  else {
    uVar8 = 9;
    lVar3 = *(long *)(pcVar7 + 1);
  }
  (*(uint32_t*)((char*)&uStack_70 + 4)) = *(uint32_t *)(pcVar7 + uVar8);
  uVar1 = *(uint32_t *)(pcVar7 + (uVar8 | 4));
  uVar4 = VkObject_fromId(lVar3);
  uVar8 = (unsigned long)uVar1 * 8 + 0xf & 0xffffffff0;
  puVar9 = (uint64_t *)((long)&uStack_70 - uVar8);
  __dest = (void *)((long)puVar9 - uVar8);
  pcVar7 = *(char **)(param_1 + 0x30);
  uVar6 = 9;
  if (*pcVar7 == '\0') {
    uVar6 = 1;
  }
  uVar11 = (unsigned long)*(uint32_t *)(pcVar7 + (unsigned long)uVar6 + 8);
  if ((int)*(uint32_t *)(pcVar7 + (unsigned long)uVar6 + 8) < 1) {
    uVar12 = (unsigned long)(uVar6 + 0xc);
  }
  else {
    uVar12 = (unsigned long)uVar6 + 8 | 4;
    puVar10 = puVar9;
    do {
      uVar5 = VkObject_fromId(*(uint64_t *)(pcVar7 + uVar12));
      *puVar10 = uVar5;
      uVar11 = uVar11 - 1;
      uVar12 = uVar12 + 8;
      puVar10 = puVar10 + 1;
    } while (uVar11 != 0);
  }
  uVar11 = (long)(int)uVar12 + 4;
  if (0 < *(int *)(pcVar7 + (int)uVar12)) {
    __n = (long)*(int *)(pcVar7 + (int)uVar12) << 3;
    memcpy(__dest,pcVar7 + uVar11,__n);
    uVar11 = (unsigned long)(uint32_t)((int)__n + (int)uVar11);
  }
  if (0 < *(int *)(pcVar7 + (int)uVar11)) {
    memcpy((void *)((long)__dest - uVar8),pcVar7 + (long)(int)uVar11 + 4,
           (long)*(int *)(pcVar7 + (int)uVar11) << 3);
  }
  ((generic_fn_t)DAT_00194108)(uVar4,(*(uint32_t*)((char*)&uStack_70 + 4)),(unsigned long)uVar1,puVar9,__dest,(void *)((long)__dest - uVar8));
  if (*(long *)(lVar2 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0013913c  size=336 */

void vt_handle_vkCmdBindVertexBuffers(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint32_t uVar7;
  char *pcVar8;
  unsigned long uVar9;
  uint64_t *puVar10;
  void *__dest;
  unsigned long uVar11;
  uint64_t *puVar12;
  long alStack_70 [2];
  
  /* stack canary setup */
  alStack_70[1] = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar9 = 1;
    lVar4 = param_1;
  }
  else {
    uVar9 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar8 + uVar9);
  uVar2 = *(uint32_t *)(pcVar8 + (uVar9 | 4));
  uVar5 = VkObject_fromId(lVar4);
  uVar9 = (unsigned long)uVar2 * 8 + 0xf & 0xffffffff0;
  puVar10 = (uint64_t *)((long)alStack_70 - uVar9);
  __dest = (void *)((long)puVar10 - uVar9);
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar8 == '\0') {
    uVar7 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar7 + 8);
  if ((int)*(uint32_t *)(pcVar8 + (unsigned long)uVar7 + 8) < 1) {
    uVar11 = (unsigned long)(uVar7 + 0xc);
  }
  else {
    uVar11 = (unsigned long)uVar7 + 8 | 4;
    puVar12 = puVar10;
    do {
      uVar6 = VkObject_fromId(*(uint64_t *)(pcVar8 + uVar11));
      *puVar12 = uVar6;
      uVar9 = uVar9 - 1;
      uVar11 = uVar11 + 8;
      puVar12 = puVar12 + 1;
    } while (uVar9 != 0);
  }
  if (0 < *(int *)(pcVar8 + (int)uVar11)) {
    memcpy(__dest,pcVar8 + (long)(int)uVar11 + 4,(long)*(int *)(pcVar8 + (int)uVar11) << 3);
  }
  ((generic_fn_t)DAT_00193e28)(uVar5,uVar1,(unsigned long)uVar2,puVar10,__dest);
  if (*(long *)(lVar3 + 0x28) != alStack_70[1]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00148c24  size=484 */

void vt_handle_vkCmdBindVertexBuffers2(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  void *pvVar4;
  long lVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  uint32_t uVar8;
  char *pcVar9;
  unsigned long uVar10;
  unsigned long uVar11;
  uint64_t *puVar12;
  uint64_t *puVar13;
  void *__dest;
  void *__dest_00;
  size_t sVar14;
  void *apvStack_80 [3];
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar3 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    uVar10 = 1;
    lVar5 = param_1;
  }
  else {
    uVar10 = 9;
    lVar5 = *(long *)(pcVar9 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar9 + uVar10);
  uVar2 = *(uint32_t *)(pcVar9 + (uVar10 | 4));
  uVar6 = VkObject_fromId(lVar5);
  uVar10 = (unsigned long)uVar2 * 8 + 0xf & 0xffffffff0;
  puVar12 = (uint64_t *)((long)apvStack_80 - uVar10);
  __dest = (void *)((long)puVar12 - uVar10);
  __dest_00 = (void *)((long)__dest - uVar10);
  apvStack_80[2] = (void *)((long)__dest_00 - uVar10);
  pcVar9 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*pcVar9 == '\0') {
    uVar8 = 1;
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar9 + (unsigned long)uVar8 + 8);
  if ((int)*(uint32_t *)(pcVar9 + (unsigned long)uVar8 + 8) < 1) {
    uVar11 = (unsigned long)(uVar8 + 0xc);
  }
  else {
    uVar11 = (unsigned long)uVar8 + 8 | 4;
    puVar13 = puVar12;
    apvStack_80[1] = __dest_00;
    do {
      uVar7 = VkObject_fromId(*(uint64_t *)(pcVar9 + uVar11));
      *puVar13 = uVar7;
      uVar10 = uVar10 - 1;
      uVar11 = uVar11 + 8;
      puVar13 = puVar13 + 1;
      __dest_00 = apvStack_80[1];
    } while (uVar10 != 0);
  }
  uVar10 = (long)(int)uVar11 + 4;
  if (0 < *(int *)(pcVar9 + (int)uVar11)) {
    sVar14 = (long)*(int *)(pcVar9 + (int)uVar11) << 3;
    memcpy(__dest,pcVar9 + uVar10,sVar14);
    uVar10 = (unsigned long)(uint32_t)((int)sVar14 + (int)uVar10);
  }
  uVar11 = (long)(int)uVar10 + 4;
  if (0 < *(int *)(pcVar9 + (int)uVar10)) {
    sVar14 = (long)*(int *)(pcVar9 + (int)uVar10) << 3;
    memcpy(__dest_00,pcVar9 + uVar11,sVar14);
    uVar11 = (unsigned long)(uint32_t)((int)sVar14 + (int)uVar11);
  }
  pvVar4 = apvStack_80[2];
  if (0 < *(int *)(pcVar9 + (int)uVar11)) {
    memcpy(apvStack_80[2],pcVar9 + (long)(int)uVar11 + 4,(long)*(int *)(pcVar9 + (int)uVar11) << 3);
  }
  ((generic_fn_t)DAT_00194180)(uVar6,uVar1,(unsigned long)uVar2,puVar12,__dest,__dest_00,pvVar4);
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00139958  size=540 */

void vt_handle_vkCmdBlitImage(long param_1)

{
  /* STUB: vt_handle_vkCmdBlitImage — Ghidra artifacts */
}


/* @00149e44  size=528 */

void vt_handle_vkCmdBlitImage2(long param_1)

{
  long lVar1;
  int iVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  long lVar8;
  void *__s;
  uint64_t uVar9;
  char *pcVar10;
  uint32_t *puVar11;
  unsigned long uVar12;
  unsigned long uVar13;
  unsigned long uVar14;
  uint64_t unaff_x19;
  uint64_t uVar15;
  unsigned long local_a0 [3];
  uint64_t local_88;
  uint64_t local_80;
  uint64_t uStack_78;
  void *local_70;
  uint64_t local_68;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar8 + 0x28);
  pcVar10 = *(char **)(param_1 + 0x30);
  uStack_78 = 0;
  local_80 = 0;
  local_68 = 0;
  local_70 = (void *)0x0;
  local_a0[1] = 0;
  local_a0[0] = 0;
  local_88 = 0;
  local_a0[2] = 0;
  if (*pcVar10 == '\0') {
    uVar12 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar10 + 1);
    uVar12 = 9;
  }
  if (0 < *(int *)(pcVar10 + uVar12)) {
    puVar3 = (uint32_t *)(pcVar10 + (uVar12 | 4));
    local_a0[1] = 0;
    local_a0[0] = (unsigned long)*puVar3;
    local_a0[2] = VkObject_fromId(*(uint64_t *)(puVar3 + 1));
    local_88 = ((uint64_t)((*(uint32_t*)((char*)&local_88 + 4))) << 32 | (uint32_t)(puVar3[3]));
    local_80 = VkObject_fromId(*(uint64_t *)(puVar3 + 4));
    uStack_78 = *(uint64_t *)(puVar3 + 6);
    uVar5 = puVar3[8];
    uVar12 = (unsigned long)uVar5;
    if ((int)uVar5 < 1) {
      uVar13 = 0x24;
      local_70 = (void *)0x0;
    }
    else {
      iVar7 = uVar5 * 0x60;
      iVar2 = *(int *)(param_1 + 0x48) + iVar7;
      if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar2;
      }
      else {
        __s = malloc((long)iVar7);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar7);
      puVar11 = (uint32_t *)((long)__s + 0x38);
      uVar14 = 0x24;
      do {
        iVar2 = *(int *)((long)puVar3 + (long)(int)uVar14);
        lVar1 = (long)(int)uVar14 + 4;
        if (__s != (void *)0x0) {
          puVar4 = (uint32_t *)((long)puVar3 + lVar1);
          uVar6 = *puVar4;
          *(uint64_t *)(puVar11 + -0xc) = 0;
          puVar11[-0xe] = uVar6;
          puVar11[-10] = puVar4[1];
          puVar11[-9] = puVar4[2];
          puVar11[-8] = puVar4[3];
          puVar11[-7] = puVar4[4];
          uVar15 = *(uint64_t *)(puVar4 + 7);
          uVar9 = *(uint64_t *)(puVar4 + 5);
          *(uint64_t *)(puVar11 + -2) = *(uint64_t *)(puVar4 + 9);
          *(uint64_t *)(puVar11 + -4) = uVar15;
          *(uint64_t *)(puVar11 + -6) = uVar9;
          *puVar11 = puVar4[0xb];
          puVar11[1] = puVar4[0xc];
          puVar11[2] = puVar4[0xd];
          puVar11[3] = puVar4[0xe];
          uVar15 = *(uint64_t *)(puVar4 + 0x11);
          uVar9 = *(uint64_t *)(puVar4 + 0xf);
          *(uint64_t *)(puVar11 + 8) = *(uint64_t *)(puVar4 + 0x13);
          *(uint64_t *)(puVar11 + 6) = uVar15;
          *(uint64_t *)(puVar11 + 4) = uVar9;
        }
        uVar13 = iVar2 + lVar1;
        uVar12 = uVar12 - 1;
        puVar11 = puVar11 + 0x18;
        uVar14 = uVar13 & 0xffffffff;
        local_70 = __s;
      } while (uVar12 != 0);
    }
    local_68 = ((uint64_t)((*(uint32_t*)((char*)&local_68 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar3 + uVar13)));
  }
  uVar9 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_00194288)(uVar9,local_a0);
  if (*(long *)(lVar8 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0013a4bc  size=432 */

void vt_handle_vkCmdClearAttachments(long param_1)

{
  long lVar1;
  char *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  long lVar5;
  long lVar6;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t uVar9;
  unsigned long uVar10;
  int iVar11;
  unsigned long uVar12;
  uint32_t *puVar13;
  uint64_t *puVar14;
  uint64_t uVar15;
  uint64_t auStack_40;
  uint64_t local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar5 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar12 = 1;
    lVar6 = param_1;
  }
  else {
    uVar12 = 9;
    lVar6 = *(long *)(pcVar8 + 1);
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar8 + (uVar12 | 4));
  uVar3 = *(uint32_t *)(pcVar8 + uVar12);
  iVar11 = (int)uVar12 + 8;
  if (0 < (int)*(uint32_t *)(pcVar8 + (uVar12 | 4))) {
    do {
      uVar10 = uVar10 - 1;
      iVar11 = iVar11 + *(int *)(pcVar8 + iVar11) + 4;
    } while (uVar10 != 0);
  }
  uVar4 = *(uint32_t *)(pcVar8 + iVar11);
  uVar7 = VkObject_fromId(lVar6);
  lVar6 = -((unsigned long)uVar3 * 0x18 + 0xf & 0x3ffffffff0);
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  uVar12 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 4);
  iVar11 = uVar9 + 8;
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 4)) {
    puVar14 = (uint64_t *)((long)&local_38 + lVar6);
    do {
      lVar1 = (long)iVar11 + 4;
      pcVar2 = pcVar8 + lVar1;
      iVar11 = *(int *)(pcVar8 + iVar11);
      uVar12 = uVar12 - 1;
      *(uint32_t *)(puVar14 + -1) = *(uint32_t *)pcVar2;
      iVar11 = iVar11 + (int)lVar1;
      *(uint32_t *)((long)puVar14 + -4) = *(uint32_t *)(pcVar2 + 4);
      uVar15 = *(uint64_t *)(pcVar2 + 8);
      puVar14[1] = *(uint64_t *)(pcVar2 + 0x10);
      *puVar14 = uVar15;
      puVar14 = puVar14 + 3;
    } while (uVar12 != 0);
  }
  uVar12 = (unsigned long)*(uint32_t *)(pcVar8 + (long)iVar11 + 4);
  if (0 < (int)*(uint32_t *)(pcVar8 + (long)iVar11 + 4)) {
    iVar11 = iVar11 + 8;
    puVar13 = (uint32_t *)
              (auStack_40 + lVar6 + (0xc - ((unsigned long)uVar4 * 0x18 + 0xf & 0x3ffffffff0)));
    do {
      lVar1 = (long)iVar11 + 4;
      pcVar2 = pcVar8 + lVar1;
      iVar11 = *(int *)(pcVar8 + iVar11);
      uVar12 = uVar12 - 1;
      puVar13[-3] = *(uint32_t *)pcVar2;
      iVar11 = iVar11 + (int)lVar1;
      puVar13[-2] = *(uint32_t *)(pcVar2 + 4);
      puVar13[-1] = *(uint32_t *)(pcVar2 + 8);
      *puVar13 = *(uint32_t *)(pcVar2 + 0xc);
      puVar13[1] = *(uint32_t *)(pcVar2 + 0x10);
      puVar13[2] = *(uint32_t *)(pcVar2 + 0x14);
      puVar13 = puVar13 + 6;
    } while (uVar12 != 0);
  }
  ((generic_fn_t)DAT_00193ea8)(uVar7,(unsigned long)uVar3,auStack_40 + lVar6,(unsigned long)uVar4);
  if (*(long *)(lVar5 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013a164  size=420 */

void vt_handle_vkCmdClearColorImage(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  long lVar11;
  unsigned long uVar12;
  uint32_t *puVar13;
  int iVar14;
  uint64_t unaff_x23;
  uint64_t local_60;
  uint64_t auStack_58 [2];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  local_60 = 0;
  auStack_58[0] = 0;
  if (*pcVar8 == '\0') {
    lVar11 = 1;
    lVar5 = param_1;
  }
  else {
    lVar11 = 9;
    lVar5 = *(long *)(pcVar8 + 1);
  }
  uVar12 = lVar11 + 1;
  if (pcVar8[lVar11] != '\0') {
    unaff_x23 = *(uint64_t *)(pcVar8 + uVar12);
    uVar12 = (unsigned long)((int)lVar11 + 9);
  }
  uVar2 = *(uint32_t *)(pcVar8 + uVar12);
  iVar14 = *(int *)(pcVar8 + uVar12 + 4);
  uVar9 = (int)uVar12 + 8;
  if (0 < iVar14) {
    auStack_58[0] = *(uint64_t *)(pcVar8 + uVar9 + 8);
    local_60 = *(uint64_t *)(pcVar8 + uVar9);
    uVar9 = iVar14 + uVar9;
  }
  uVar3 = *(uint32_t *)(pcVar8 + uVar9);
  uVar6 = VkObject_fromId(lVar5);
  uVar7 = VkObject_fromId(unaff_x23);
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar10 = 9;
  uVar9 = uVar10;
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  if (pcVar8[uVar9] == '\0') {
    uVar10 = 1;
  }
  iVar14 = uVar10 + uVar9 +
           (*(uint32_t *)(pcVar8 + (unsigned long)(uVar10 + uVar9) + 4) &
           ((int)*(uint32_t *)(pcVar8 + (unsigned long)(uVar10 + uVar9) + 4) >> 0x1f ^ 0xffffffffU));
  uVar12 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)(iVar14 + 8) + 4);
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)(iVar14 + 8) + 4)) {
    iVar14 = iVar14 + 0x10;
    puVar13 = (uint32_t *)((long)auStack_58 - ((unsigned long)uVar3 * 0x14 + 0xf & 0x3ffffffff0));
    do {
      lVar5 = (long)iVar14 + 4;
      pcVar1 = pcVar8 + lVar5;
      iVar14 = *(int *)(pcVar8 + iVar14);
      uVar12 = uVar12 - 1;
      puVar13[-2] = *(uint32_t *)pcVar1;
      iVar14 = iVar14 + (int)lVar5;
      puVar13[-1] = *(uint32_t *)(pcVar1 + 4);
      *puVar13 = *(uint32_t *)(pcVar1 + 8);
      puVar13[1] = *(uint32_t *)(pcVar1 + 0xc);
      puVar13[2] = *(uint32_t *)(pcVar1 + 0x10);
      puVar13 = puVar13 + 5;
    } while (uVar12 != 0);
  }
  ((generic_fn_t)DAT_00193e98)(uVar6,uVar7,uVar2,&local_60,(unsigned long)uVar3);
  if (*(long *)(lVar4 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013a308  size=436 */

void vt_handle_vkCmdClearDepthStencilImage(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  long lVar5;
  long lVar6;
  uint64_t uVar7;
  uint64_t uVar8;
  char *pcVar9;
  uint32_t uVar10;
  long lVar11;
  unsigned long uVar12;
  uint32_t *puVar13;
  int iVar14;
  uint64_t unaff_x23;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar5 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_50 = 0;
  if (*pcVar9 == '\0') {
    lVar11 = 1;
    lVar6 = param_1;
  }
  else {
    lVar11 = 9;
    lVar6 = *(long *)(pcVar9 + 1);
  }
  uVar12 = lVar11 + 1;
  if (pcVar9[lVar11] != '\0') {
    unaff_x23 = *(uint64_t *)(pcVar9 + uVar12);
    uVar12 = (unsigned long)((int)lVar11 + 9);
  }
  uVar3 = *(uint32_t *)(pcVar9 + uVar12);
  iVar14 = *(int *)(pcVar9 + uVar12 + 4);
  uVar12 = uVar12 + 8;
  if (0 < iVar14) {
    pcVar1 = pcVar9 + uVar12;
    uVar12 = (unsigned long)(uint32_t)(iVar14 + (int)uVar12);
    local_50 = *(uint64_t *)pcVar1;
  }
  uVar4 = *(uint32_t *)(pcVar9 + uVar12);
  uVar7 = VkObject_fromId(lVar6);
  uVar8 = VkObject_fromId(unaff_x23);
  pcVar9 = *(char **)(param_1 + 0x30);
  uVar10 = 9;
  uVar2 = uVar10;
  if (*pcVar9 == '\0') {
    uVar2 = 1;
  }
  if (pcVar9[uVar2] == '\0') {
    uVar10 = 1;
  }
  iVar14 = uVar10 + uVar2 +
           (*(uint32_t *)(pcVar9 + (unsigned long)(uVar10 + uVar2) + 4) &
           ((int)*(uint32_t *)(pcVar9 + (unsigned long)(uVar10 + uVar2) + 4) >> 0x1f ^ 0xffffffffU));
  uVar12 = (unsigned long)*(uint32_t *)(pcVar9 + (unsigned long)(iVar14 + 8) + 4);
  if (0 < (int)*(uint32_t *)(pcVar9 + (unsigned long)(iVar14 + 8) + 4)) {
    iVar14 = iVar14 + 0x10;
    puVar13 = (uint32_t *)((long)&local_48 - ((unsigned long)uVar4 * 0x14 + 0xf & 0x3ffffffff0));
    do {
      lVar6 = (long)iVar14 + 4;
      pcVar1 = pcVar9 + lVar6;
      iVar14 = *(int *)(pcVar9 + iVar14);
      uVar12 = uVar12 - 1;
      puVar13[-2] = *(uint32_t *)pcVar1;
      iVar14 = iVar14 + (int)lVar6;
      puVar13[-1] = *(uint32_t *)(pcVar1 + 4);
      *puVar13 = *(uint32_t *)(pcVar1 + 8);
      puVar13[1] = *(uint32_t *)(pcVar1 + 0xc);
      puVar13[2] = *(uint32_t *)(pcVar1 + 0x10);
      puVar13 = puVar13 + 5;
    } while (uVar12 != 0);
  }
  ((generic_fn_t)DAT_00193ea0)(uVar7,uVar8,uVar3,&local_50,(unsigned long)uVar4);
  if (*(long *)(lVar5 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001395b0  size=392 */

void vt_handle_vkCmdCopyBuffer(long param_1)

{
  /* STUB: vt_handle_vkCmdCopyBuffer — Ghidra artifacts */
}


/* @00149a68  size=432 */

void vt_handle_vkCmdCopyBuffer2(long param_1)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  long lVar7;
  void *__s;
  uint64_t uVar8;
  char *pcVar9;
  uint64_t *puVar10;
  int iVar11;
  unsigned long uVar12;
  uint64_t unaff_x19;
  unsigned long local_90 [4];
  uint64_t local_70;
  void *local_68;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar7 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_90[3] = 0;
  local_90[2] = 0;
  local_68 = (void *)0x0;
  local_70 = 0;
  local_90[1] = 0;
  local_90[0] = 0;
  if (*pcVar9 == '\0') {
    uVar12 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar9 + 1);
    uVar12 = 9;
  }
  if (0 < *(int *)(pcVar9 + uVar12)) {
    puVar2 = (uint32_t *)(pcVar9 + (uVar12 | 4));
    local_90[1] = 0;
    local_90[0] = (unsigned long)*puVar2;
    local_90[2] = VkObject_fromId(*(uint64_t *)(puVar2 + 1));
    local_90[3] = VkObject_fromId(*(uint64_t *)(puVar2 + 3));
    local_70 = ((uint64_t)((*(uint32_t*)((char*)&local_70 + 4))) << 32 | (uint32_t)(puVar2[5]));
    uVar4 = puVar2[6];
    uVar12 = (unsigned long)uVar4;
    if ((int)uVar4 < 1) {
      local_68 = (void *)0x0;
    }
    else {
      iVar6 = uVar4 * 0x28;
      iVar11 = *(int *)(param_1 + 0x48) + iVar6;
      if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar11;
      }
      else {
        __s = malloc((long)iVar6);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar6);
      puVar10 = (uint64_t *)((long)__s + 0x10);
      iVar11 = 0x1c;
      do {
        iVar6 = *(int *)((long)puVar2 + (long)iVar11);
        lVar1 = (long)iVar11 + 4;
        if (__s != (void *)0x0) {
          puVar3 = (uint32_t *)((long)puVar2 + lVar1);
          uVar5 = *puVar3;
          puVar10[-1] = 0;
          *(uint32_t *)(puVar10 + -2) = uVar5;
          *puVar10 = *(uint64_t *)(puVar3 + 1);
          puVar10[1] = *(uint64_t *)(puVar3 + 3);
          puVar10[2] = *(uint64_t *)(puVar3 + 5);
        }
        iVar11 = iVar6 + (int)lVar1;
        uVar12 = uVar12 - 1;
        puVar10 = puVar10 + 5;
        local_68 = __s;
      } while (uVar12 != 0);
    }
  }
  uVar8 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_00194278)(uVar8,local_90);
  if (*(long *)(lVar7 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00139b74  size=560 */

void vt_handle_vkCmdCopyBufferToImage(long param_1)

{
  /* STUB: vt_handle_vkCmdCopyBufferToImage — Ghidra artifacts */
}


/* @0014a054  size=636 */

void vt_handle_vkCmdCopyBufferToImage2(long param_1)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  uint64_t uVar7;
  uint64_t uVar8;
  void *pvVar9;
  char *pcVar10;
  uint32_t *puVar11;
  int iVar12;
  unsigned long uVar13;
  uint64_t unaff_x20;
  uint32_t uVar14;
  uint64_t uVar15;
  unsigned long local_a0 [5];
  void *local_78;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar6 + 0x28);
  pcVar10 = *(char **)(param_1 + 0x30);
  local_a0[3] = 0;
  local_a0[2] = 0;
  local_78 = (void *)0x0;
  local_a0[4] = 0;
  local_a0[1] = 0;
  local_a0[0] = 0;
  if (*pcVar10 == '\0') {
    uVar13 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar10 + 1);
    uVar13 = 9;
  }
  if (*(int *)(pcVar10 + uVar13) < 1) {
    uVar14 = 0;
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    puVar2 = (uint32_t *)(pcVar10 + (uVar13 | 4));
    local_a0[1] = 0;
    local_a0[0] = (unsigned long)*puVar2;
    uVar7 = VkObject_fromId(*(uint64_t *)(puVar2 + 1));
    local_a0[2] = uVar7;
    uVar8 = VkObject_fromId(*(uint64_t *)(puVar2 + 3));
    uVar15 = *(uint64_t *)(puVar2 + 5);
    uVar4 = puVar2[7];
    uVar13 = (unsigned long)uVar4;
    local_a0[3] = uVar8;
    local_a0[4] = uVar15;
    if ((int)uVar4 < 1) {
      local_78 = (void *)0x0;
    }
    else {
      iVar5 = uVar4 * 0x48;
      iVar12 = *(int *)(param_1 + 0x48) + iVar5;
      if ((iVar12 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar9 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar12;
      }
      else {
        pvVar9 = malloc((long)iVar5);
        ArrayList_add(param_1 + 0x50,pvVar9);
      }
      memset(pvVar9,0,(long)iVar5);
      puVar11 = (uint32_t *)((long)pvVar9 + 0x24);
      iVar12 = 0x20;
      do {
        iVar5 = *(int *)((long)puVar2 + (long)iVar12);
        lVar1 = (long)iVar12 + 4;
        if (pvVar9 != (void *)0x0) {
          puVar3 = (uint32_t *)((long)puVar2 + lVar1);
          uVar14 = *puVar3;
          *(uint64_t *)(puVar11 + -7) = 0;
          puVar11[-9] = uVar14;
          *(uint64_t *)(puVar11 + -5) = *(uint64_t *)(puVar3 + 1);
          puVar11[-3] = puVar3[3];
          puVar11[-2] = puVar3[4];
          puVar11[-1] = puVar3[5];
          *puVar11 = puVar3[6];
          puVar11[1] = puVar3[7];
          puVar11[2] = puVar3[8];
          puVar11[3] = puVar3[9];
          puVar11[4] = puVar3[10];
          puVar11[5] = puVar3[0xb];
          puVar11[6] = puVar3[0xc];
          puVar11[7] = puVar3[0xd];
          puVar11[8] = puVar3[0xe];
        }
        iVar12 = iVar5 + (int)lVar1;
        uVar13 = uVar13 - 1;
        puVar11 = puVar11 + 0x12;
        local_78 = pvVar9;
      } while (uVar13 != 0);
    }
    uVar14 = (uint32_t)uVar15;
  }
  pvVar9 = local_78;
  uVar15 = VkObject_fromId(unaff_x20);
  if ((*(long *)(param_1 + 0x80) == 0) ||
     (uVar13 = TextureDecoder_containsImage(*(long *)(param_1 + 0x80),uVar8), (uVar13 & 1) == 0)) {
    ((generic_fn_t)DAT_00194290)(uVar15,local_a0);
  }
  else if (*(int *)((long)pvVar9 + 0x24) == 0) {
    TextureDecoder_copyBufferToImage
              (*(uint64_t *)(param_1 + 0x80),uVar15,uVar7,uVar8,uVar14,
               *(uint64_t *)((long)pvVar9 + 0x10));
  }
  if (*(long *)(lVar6 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00139738  size=544 */

void vt_handle_vkCmdCopyImage(long param_1)

{
  /* STUB: vt_handle_vkCmdCopyImage — Ghidra artifacts */
}


/* @00149c18  size=556 */

void vt_handle_vkCmdCopyImage2(long param_1)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  long lVar7;
  void *__s;
  uint64_t uVar8;
  char *pcVar9;
  uint32_t *puVar10;
  int iVar11;
  unsigned long uVar12;
  uint64_t unaff_x19;
  unsigned long local_90 [3];
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t local_68;
  void *local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar7 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_60 = (void *)0x0;
  uStack_78 = 0;
  local_90[2] = 0;
  local_68 = 0;
  local_70 = 0;
  local_90[1] = 0;
  local_90[0] = 0;
  if (*pcVar9 == '\0') {
    uVar12 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar9 + 1);
    uVar12 = 9;
  }
  if (0 < *(int *)(pcVar9 + uVar12)) {
    puVar2 = (uint32_t *)(pcVar9 + (uVar12 | 4));
    local_90[1] = 0;
    local_90[0] = (unsigned long)*puVar2;
    local_90[2] = VkObject_fromId(*(uint64_t *)(puVar2 + 1));
    uStack_78 = ((uint64_t)((*(uint32_t*)((char*)&uStack_78 + 4))) << 32 | (uint32_t)(puVar2[3]));
    local_70 = VkObject_fromId(*(uint64_t *)(puVar2 + 4));
    local_68 = *(uint64_t *)(puVar2 + 6);
    uVar4 = puVar2[8];
    uVar12 = (unsigned long)uVar4;
    if ((int)uVar4 < 1) {
      local_60 = (void *)0x0;
    }
    else {
      iVar6 = uVar4 * 0x58;
      iVar11 = *(int *)(param_1 + 0x48) + iVar6;
      if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar11;
      }
      else {
        __s = malloc((long)iVar6);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar6);
      puVar10 = (uint32_t *)((long)__s + 0x28);
      iVar11 = 0x24;
      do {
        iVar6 = *(int *)((long)puVar2 + (long)iVar11);
        lVar1 = (long)iVar11 + 4;
        if (__s != (void *)0x0) {
          puVar3 = (uint32_t *)((long)puVar2 + lVar1);
          uVar5 = *puVar3;
          *(uint64_t *)(puVar10 + -8) = 0;
          puVar10[-10] = uVar5;
          puVar10[-6] = puVar3[1];
          puVar10[-5] = puVar3[2];
          puVar10[-4] = puVar3[3];
          puVar10[-3] = puVar3[4];
          puVar10[-2] = puVar3[5];
          puVar10[-1] = puVar3[6];
          *puVar10 = puVar3[7];
          puVar10[1] = puVar3[8];
          puVar10[2] = puVar3[9];
          puVar10[3] = puVar3[10];
          puVar10[4] = puVar3[0xb];
          puVar10[5] = puVar3[0xc];
          puVar10[6] = puVar3[0xd];
          puVar10[7] = puVar3[0xe];
          puVar10[8] = puVar3[0xf];
          puVar10[9] = puVar3[0x10];
          puVar10[10] = puVar3[0x11];
        }
        iVar11 = iVar6 + (int)lVar1;
        uVar12 = uVar12 - 1;
        puVar10 = puVar10 + 0x16;
        local_60 = __s;
      } while (uVar12 != 0);
    }
  }
  uVar8 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_00194280)(uVar8,local_90);
  if (*(long *)(lVar7 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00139da4  size=504 */

void vt_handle_vkCmdCopyImageToBuffer(long param_1)

{
  /* STUB: vt_handle_vkCmdCopyImageToBuffer — Ghidra artifacts */
}


/* @0014a2d0  size=524 */

void vt_handle_vkCmdCopyImageToBuffer2(long param_1)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  long lVar7;
  void *__s;
  uint64_t uVar8;
  char *pcVar9;
  uint32_t *puVar10;
  int iVar11;
  unsigned long uVar12;
  uint64_t unaff_x19;
  unsigned long local_90 [3];
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t local_68;
  void *local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar7 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_60 = (void *)0x0;
  uStack_78 = 0;
  local_90[2] = 0;
  local_68 = 0;
  local_70 = 0;
  local_90[1] = 0;
  local_90[0] = 0;
  if (*pcVar9 == '\0') {
    uVar12 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar9 + 1);
    uVar12 = 9;
  }
  if (0 < *(int *)(pcVar9 + uVar12)) {
    puVar2 = (uint32_t *)(pcVar9 + (uVar12 | 4));
    local_90[1] = 0;
    local_90[0] = (unsigned long)*puVar2;
    local_90[2] = VkObject_fromId(*(uint64_t *)(puVar2 + 1));
    uStack_78 = ((uint64_t)((*(uint32_t*)((char*)&uStack_78 + 4))) << 32 | (uint32_t)(puVar2[3]));
    local_70 = VkObject_fromId(*(uint64_t *)(puVar2 + 4));
    local_68 = ((uint64_t)((*(uint32_t*)((char*)&local_68 + 4))) << 32 | (uint32_t)(puVar2[6]));
    uVar4 = puVar2[7];
    uVar12 = (unsigned long)uVar4;
    if ((int)uVar4 < 1) {
      local_60 = (void *)0x0;
    }
    else {
      iVar6 = uVar4 * 0x48;
      iVar11 = *(int *)(param_1 + 0x48) + iVar6;
      if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar11;
      }
      else {
        __s = malloc((long)iVar6);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar6);
      puVar10 = (uint32_t *)((long)__s + 0x24);
      iVar11 = 0x20;
      do {
        iVar6 = *(int *)((long)puVar2 + (long)iVar11);
        lVar1 = (long)iVar11 + 4;
        if (__s != (void *)0x0) {
          puVar3 = (uint32_t *)((long)puVar2 + lVar1);
          uVar5 = *puVar3;
          *(uint64_t *)(puVar10 + -7) = 0;
          puVar10[-9] = uVar5;
          *(uint64_t *)(puVar10 + -5) = *(uint64_t *)(puVar3 + 1);
          puVar10[-3] = puVar3[3];
          puVar10[-2] = puVar3[4];
          puVar10[-1] = puVar3[5];
          *puVar10 = puVar3[6];
          puVar10[1] = puVar3[7];
          puVar10[2] = puVar3[8];
          puVar10[3] = puVar3[9];
          puVar10[4] = puVar3[10];
          puVar10[5] = puVar3[0xb];
          puVar10[6] = puVar3[0xc];
          puVar10[7] = puVar3[0xd];
          puVar10[8] = puVar3[0xe];
        }
        iVar11 = iVar6 + (int)lVar1;
        uVar12 = uVar12 - 1;
        puVar10 = puVar10 + 0x12;
        local_60 = __s;
      } while (uVar12 != 0);
    }
  }
  uVar8 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_00194298)(uVar8,local_90);
  if (*(long *)(lVar7 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0013b2c4  size=224 */

void vt_handle_vkCmdCopyQueryPoolResults(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  char *pcVar10;
  unsigned long uVar11;
  long lVar12;
  unsigned long uVar13;
  uint64_t unaff_x19;
  uint64_t unaff_x22;
  
  pcVar10 = *(char **)(param_1 + 0x30);
  if (*pcVar10 == '\0') {
    lVar12 = 1;
  }
  else {
    param_1 = *(long *)(pcVar10 + 1);
    lVar12 = 9;
  }
  uVar11 = lVar12 + 1;
  if (pcVar10[lVar12] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar10 + uVar11);
    uVar11 = (unsigned long)((int)lVar12 + 9);
  }
  pcVar1 = pcVar10 + uVar11;
  uVar2 = *(uint32_t *)pcVar1;
  uVar3 = *(uint32_t *)(pcVar1 + 4);
  uVar13 = uVar11 + 9;
  if (pcVar1[8] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar10 + uVar13);
    uVar13 = (unsigned long)((int)uVar11 + 0x11);
  }
  pcVar10 = pcVar10 + uVar13;
  uVar4 = *(uint64_t *)pcVar10;
  uVar5 = *(uint64_t *)(pcVar10 + 8);
  uVar6 = *(uint32_t *)(pcVar10 + 0x10);
  uVar7 = VkObject_fromId(param_1);
  uVar8 = VkObject_fromId(unaff_x19);
  uVar9 = VkObject_fromId(unaff_x22);
                    /* WARNING: Could not recover jumptable at 0x0013b3a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193f08)(uVar7,uVar8,uVar2,uVar3,uVar9,uVar4,uVar5,uVar6);
  return;
}


/* @001394bc  size=112 */

void vt_handle_vkCmdDispatch(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  unsigned long uVar6;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    uVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    uVar6 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar5 + uVar6);
  uVar3 = *(uint32_t *)(pcVar5 + (uVar6 | 4));
  uVar2 = *(uint32_t *)(pcVar5 + uVar6 + 8);
  uVar4 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00139528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e50)(uVar4,uVar1,uVar3,uVar2);
  return;
}


/* @00143fc8  size=148 */

void vt_handle_vkCmdDispatchBase(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint64_t uVar8;
  char *pcVar9;
  unsigned long uVar10;
  
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    uVar10 = 1;
  }
  else {
    param_1 = *(long *)(pcVar9 + 1);
    uVar10 = 9;
  }
  pcVar1 = pcVar9 + uVar10;
  uVar4 = *(uint32_t *)pcVar1;
  uVar6 = *(uint32_t *)(pcVar9 + (uVar10 | 4));
  uVar2 = *(uint32_t *)(pcVar1 + 8);
  uVar3 = *(uint32_t *)(pcVar1 + 0xc);
  uVar5 = *(uint32_t *)(pcVar1 + 0x10);
  uVar7 = *(uint32_t *)(pcVar9 + (uVar10 | 0x14));
  uVar8 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00144058. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194020)(uVar8,uVar4,uVar6,uVar2,uVar3,uVar5,uVar7);
  return;
}


/* @0013952c  size=132 */

void vt_handle_vkCmdDispatchIndirect(long param_1)

{
  uint64_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  unsigned long uVar5;
  uint64_t unaff_x19;
  uint64_t uVar6;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar5 = lVar4 + 1;
  if (pcVar3[lVar4] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar3 + uVar5);
    uVar5 = (unsigned long)((int)lVar4 + 9);
  }
  uVar6 = *(uint64_t *)(pcVar3 + uVar5);
  uVar1 = VkObject_fromId(param_1);
  uVar2 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x001395ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e58)(uVar1,uVar2,uVar6);
  return;
}


/* @0013928c  size=116 */

void vt_handle_vkCmdDraw(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint64_t uVar6;
  char *pcVar7;
  unsigned long uVar8;
  
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar8 = 1;
  }
  else {
    param_1 = *(long *)(pcVar7 + 1);
    uVar8 = 9;
  }
  pcVar1 = pcVar7 + uVar8;
  uVar4 = *(uint32_t *)pcVar1;
  uVar5 = *(uint32_t *)(pcVar7 + (uVar8 | 4));
  uVar2 = *(uint32_t *)(pcVar1 + 8);
  uVar3 = *(uint32_t *)(pcVar1 + 0xc);
  uVar6 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001392fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e30)(uVar6,uVar4,uVar5,uVar2,uVar3);
  return;
}


/* @00139300  size=132 */

void vt_handle_vkCmdDrawIndexed(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  unsigned long uVar9;
  
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  else {
    param_1 = *(long *)(pcVar8 + 1);
    uVar9 = 9;
  }
  pcVar1 = pcVar8 + uVar9;
  uVar4 = *(uint32_t *)pcVar1;
  uVar6 = *(uint32_t *)(pcVar8 + (uVar9 | 4));
  uVar2 = *(uint32_t *)(pcVar1 + 8);
  uVar3 = *(uint32_t *)(pcVar1 + 0xc);
  uVar5 = *(uint32_t *)(pcVar1 + 0x10);
  uVar7 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00139380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e38)(uVar7,uVar4,uVar6,uVar2,uVar3,uVar5);
  return;
}


/* @00139420  size=156 */

void vt_handle_vkCmdDrawIndexedIndirect(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  unsigned long uVar7;
  uint64_t unaff_x19;
  uint64_t uVar8;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
  }
  uVar7 = lVar6 + 1;
  if (pcVar5[lVar6] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar5 + uVar7);
    uVar7 = (unsigned long)((int)lVar6 + 9);
  }
  pcVar5 = pcVar5 + uVar7;
  uVar8 = *(uint64_t *)pcVar5;
  uVar1 = *(uint32_t *)(pcVar5 + 8);
  uVar2 = *(uint32_t *)(pcVar5 + 0xc);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x001394b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e48)(uVar3,uVar4,uVar8,uVar1,uVar2);
  return;
}


/* @00147ee8  size=220 */

void vt_handle_vkCmdDrawIndexedIndirectCount(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  unsigned long uVar7;
  long lVar8;
  unsigned long uVar9;
  uint64_t unaff_x19;
  uint64_t uVar10;
  uint64_t unaff_x21;
  uint64_t uVar11;
  
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar8 = 1;
  }
  else {
    param_1 = *(long *)(pcVar6 + 1);
    lVar8 = 9;
  }
  uVar7 = lVar8 + 1;
  if (pcVar6[lVar8] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar6 + uVar7);
    uVar7 = (unsigned long)((int)lVar8 + 9);
  }
  uVar10 = *(uint64_t *)(pcVar6 + uVar7);
  uVar9 = uVar7 + 9;
  if ((pcVar6 + uVar7)[8] != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar6 + uVar9);
    uVar9 = (unsigned long)((int)uVar7 + 0x11);
  }
  pcVar6 = pcVar6 + uVar9;
  uVar11 = *(uint64_t *)pcVar6;
  uVar1 = *(uint32_t *)(pcVar6 + 8);
  uVar2 = *(uint32_t *)(pcVar6 + 0xc);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
  uVar5 = VkObject_fromId(unaff_x21);
                    /* WARNING: Could not recover jumptable at 0x00147fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194100)(uVar3,uVar4,uVar10,uVar5,uVar11,uVar1,uVar2);
  return;
}


/* @00139384  size=156 */

void vt_handle_vkCmdDrawIndirect(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  unsigned long uVar7;
  uint64_t unaff_x19;
  uint64_t uVar8;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
  }
  uVar7 = lVar6 + 1;
  if (pcVar5[lVar6] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar5 + uVar7);
    uVar7 = (unsigned long)((int)lVar6 + 9);
  }
  pcVar5 = pcVar5 + uVar7;
  uVar8 = *(uint64_t *)pcVar5;
  uVar1 = *(uint32_t *)(pcVar5 + 8);
  uVar2 = *(uint32_t *)(pcVar5 + 0xc);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013941c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e40)(uVar3,uVar4,uVar8,uVar1,uVar2);
  return;
}


/* @00148520  size=188 */

void vt_handle_vkCmdDrawIndirectByteCountEXT(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  char *pcVar7;
  unsigned long uVar8;
  unsigned long uVar9;
  uint64_t unaff_x21;
  uint64_t uVar10;
  
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar8 = 1;
  }
  else {
    param_1 = *(long *)(pcVar7 + 1);
    uVar8 = 9;
  }
  uVar3 = *(uint32_t *)(pcVar7 + uVar8);
  uVar4 = *(uint32_t *)(pcVar7 + (uVar8 | 4));
  uVar9 = uVar8 + 9;
  if ((pcVar7 + uVar8)[8] != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar7 + uVar9);
    uVar9 = (unsigned long)((int)uVar8 + 0x11);
  }
  pcVar7 = pcVar7 + uVar9;
  uVar10 = *(uint64_t *)pcVar7;
  uVar1 = *(uint32_t *)(pcVar7 + 8);
  uVar2 = *(uint32_t *)(pcVar7 + 0xc);
  uVar5 = VkObject_fromId(param_1);
  uVar6 = VkObject_fromId(unaff_x21);
                    /* WARNING: Could not recover jumptable at 0x001485d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194130)(uVar5,uVar3,uVar4,uVar6,uVar10,uVar1,uVar2);
  return;
}


/* @00147e0c  size=220 */

void vt_handle_vkCmdDrawIndirectCount(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  unsigned long uVar7;
  long lVar8;
  unsigned long uVar9;
  uint64_t unaff_x19;
  uint64_t uVar10;
  uint64_t unaff_x21;
  uint64_t uVar11;
  
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar8 = 1;
  }
  else {
    param_1 = *(long *)(pcVar6 + 1);
    lVar8 = 9;
  }
  uVar7 = lVar8 + 1;
  if (pcVar6[lVar8] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar6 + uVar7);
    uVar7 = (unsigned long)((int)lVar8 + 9);
  }
  uVar10 = *(uint64_t *)(pcVar6 + uVar7);
  uVar9 = uVar7 + 9;
  if ((pcVar6 + uVar7)[8] != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar6 + uVar9);
    uVar9 = (unsigned long)((int)uVar7 + 0x11);
  }
  pcVar6 = pcVar6 + uVar9;
  uVar11 = *(uint64_t *)pcVar6;
  uVar1 = *(uint32_t *)(pcVar6 + 8);
  uVar2 = *(uint32_t *)(pcVar6 + 0xc);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
  uVar5 = VkObject_fromId(unaff_x21);
                    /* WARNING: Could not recover jumptable at 0x00147ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001940f8)(uVar3,uVar4,uVar10,uVar5,uVar11,uVar1,uVar2);
  return;
}


/* @0013b180  size=40 */

void vt_handle_vkCmdEndConditionalRenderingEXT(long param_1)

{
  VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
                    /* WARNING: Could not recover jumptable at 0x0013b1a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193ef0)();
  return;
}


/* @0013b030  size=132 */

void vt_handle_vkCmdEndQuery(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar6 = lVar5 + 1;
  if (pcVar4[lVar5] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar6);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013b0b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193ee0)(uVar2,uVar3,uVar1);
  return;
}


/* @00148494  size=140 */

void vt_handle_vkCmdEndQueryIndexedEXT(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  unsigned long uVar7;
  uint64_t unaff_x19;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
  }
  uVar7 = lVar6 + 1;
  if (pcVar5[lVar6] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar5 + uVar7);
    uVar7 = (unsigned long)((int)lVar6 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar5 + uVar7);
  uVar2 = *(uint32_t *)(pcVar5 + uVar7 + 4);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0014851c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194128)(uVar3,uVar4,uVar1,uVar2);
  return;
}


/* @0013b5e8  size=40 */

void vt_handle_vkCmdEndRenderPass(long param_1)

{
  VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
                    /* WARNING: Could not recover jumptable at 0x0013b60c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193f28)();
  return;
}


/* @00147ba0  size=152 */

void vt_handle_vkCmdEndRenderPass2(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  char *pcVar3;
  unsigned long uVar4;
  unsigned long local_38 [3];
  
  /* stack canary setup */
  local_38[2] = *(long *)(lVar1 + 0x28);
  pcVar3 = *(char **)(param_1 + 0x30);
  local_38[0] = 0;
  if (*pcVar3 == '\0') {
    uVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    uVar4 = 9;
  }
  if (0 < *(int *)(pcVar3 + uVar4)) {
    local_38[0] = (unsigned long)*(uint32_t *)(pcVar3 + (uVar4 | 4));
  }
  local_38[1] = 0;
  uVar2 = VkObject_fromId(param_1);
  ((generic_fn_t)DAT_001940d0)(uVar2,local_38);
  if (*(long *)(lVar1 + 0x28) == local_38[2]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0014b610  size=40 */

void vt_handle_vkCmdEndRendering(long param_1)

{
  VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
                    /* WARNING: Could not recover jumptable at 0x0014b634. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001942e8)();
  return;
}


/* @001482a8  size=336 */

void vt_handle_vkCmdEndTransformFeedbackEXT(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint32_t uVar7;
  char *pcVar8;
  unsigned long uVar9;
  uint64_t *puVar10;
  void *__dest;
  unsigned long uVar11;
  uint64_t *puVar12;
  long alStack_70 [2];
  
  /* stack canary setup */
  alStack_70[1] = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar9 = 1;
    lVar4 = param_1;
  }
  else {
    uVar9 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar8 + uVar9);
  uVar2 = *(uint32_t *)(pcVar8 + (uVar9 | 4));
  uVar5 = VkObject_fromId(lVar4);
  uVar9 = (unsigned long)uVar2 * 8 + 0xf & 0xffffffff0;
  puVar10 = (uint64_t *)((long)alStack_70 - uVar9);
  __dest = (void *)((long)puVar10 - uVar9);
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar8 == '\0') {
    uVar7 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar7 + 8);
  if ((int)*(uint32_t *)(pcVar8 + (unsigned long)uVar7 + 8) < 1) {
    uVar11 = (unsigned long)(uVar7 + 0xc);
  }
  else {
    uVar11 = (unsigned long)uVar7 + 8 | 4;
    puVar12 = puVar10;
    do {
      uVar6 = VkObject_fromId(*(uint64_t *)(pcVar8 + uVar11));
      *puVar12 = uVar6;
      uVar9 = uVar9 - 1;
      uVar11 = uVar11 + 8;
      puVar12 = puVar12 + 1;
    } while (uVar9 != 0);
  }
  if (0 < *(int *)(pcVar8 + (int)uVar11)) {
    memcpy(__dest,pcVar8 + (long)(int)uVar11 + 4,(long)*(int *)(pcVar8 + (int)uVar11) << 3);
  }
  ((generic_fn_t)DAT_00194118)(uVar5,uVar1,(unsigned long)uVar2,puVar10,__dest);
  if (*(long *)(lVar3 + 0x28) != alStack_70[1]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0013b610  size=252 */

void vt_handle_vkCmdExecuteCommands(long param_1)

{
  uint32_t uVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  uint32_t uVar7;
  long lVar8;
  uint64_t *puVar9;
  unsigned long uVar10;
  uint64_t *puVar11;
  long alStack_60 [2];
  
  /* stack canary setup */
  alStack_60[1] = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar8 = 1;
    lVar3 = param_1;
  }
  else {
    lVar8 = 9;
    lVar3 = *(long *)(pcVar6 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar6 + lVar8);
  uVar4 = VkObject_fromId(lVar3);
  puVar9 = (uint64_t *)((long)alStack_60 - ((unsigned long)uVar1 * 8 + 0xf & 0xffffffff0));
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4);
  if (0 < (int)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4)) {
    pcVar6 = pcVar6 + uVar7;
    puVar11 = puVar9;
    do {
      pcVar6 = pcVar6 + 8;
      uVar5 = VkObject_fromId(*(uint64_t *)pcVar6);
      uVar10 = uVar10 - 1;
      *puVar11 = uVar5;
      puVar11 = puVar11 + 1;
    } while (uVar10 != 0);
  }
  ((generic_fn_t)DAT_00193f30)(uVar4,(unsigned long)uVar1,puVar9);
  if (*(long *)(lVar2 + 0x28) == alStack_60[1]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013a0c8  size=156 */

void vt_handle_vkCmdFillBuffer(long param_1)

{
  uint64_t uVar1;
  uint64_t uVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  long lVar7;
  unsigned long uVar8;
  uint64_t unaff_x19;
  
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
  }
  else {
    param_1 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
  }
  uVar8 = lVar7 + 1;
  if (pcVar6[lVar7] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar6 + uVar8);
    uVar8 = (unsigned long)((int)lVar7 + 9);
  }
  pcVar6 = pcVar6 + uVar8;
  uVar1 = *(uint64_t *)pcVar6;
  uVar2 = *(uint64_t *)(pcVar6 + 8);
  uVar3 = *(uint32_t *)(pcVar6 + 0x10);
  uVar4 = VkObject_fromId(param_1);
  uVar5 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013a160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e90)(uVar4,uVar5,uVar1,uVar2,uVar3);
  return;
}


/* @0013b59c  size=76 */

void vt_handle_vkCmdNextSubpass(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x0013b5e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193f20)(uVar2,uVar1);
  return;
}


/* @00147acc  size=212 */

void vt_handle_vkCmdNextSubpass2(long param_1)

{
  uint32_t *puVar1;
  long lVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  unsigned long uVar6;
  unsigned long local_50 [6];
  
  /* stack canary setup */
  local_50[5] = *(long *)(lVar2 + 0x28);
  pcVar4 = *(char **)(param_1 + 0x30);
  local_50[2] = 0;
  local_50[4] = 0;
  local_50[0] = 0;
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    uVar5 = 9;
  }
  uVar6 = uVar5 | 4;
  if (0 < *(int *)(pcVar4 + uVar5)) {
    puVar1 = (uint32_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)(uint32_t)((int)uVar6 + *(int *)(pcVar4 + uVar5));
    local_50[2] = (unsigned long)*puVar1;
    local_50[4] = (unsigned long)puVar1[1];
  }
  local_50[3] = 0;
  if (0 < *(int *)(pcVar4 + (int)uVar6)) {
    local_50[0] = (unsigned long)*(uint32_t *)(pcVar4 + (long)(int)uVar6 + 4);
  }
  local_50[1] = 0;
  uVar3 = VkObject_fromId(param_1);
  ((generic_fn_t)DAT_001940c8)(uVar3,local_50 + 2,local_50);
  if (*(long *)(lVar2 + 0x28) == local_50[5]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013acd0  size=724 */

void vt_handle_vkCmdPipelineBarrier(long param_1)

{
  long lVar1;
  char *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  uint32_t uVar7;
  long lVar8;
  uint64_t uVar9;
  uint32_t uVar10;
  char *pcVar11;
  unsigned long uVar12;
  uint64_t uVar13;
  uint32_t *puVar14;
  uint32_t uVar15;
  int iVar16;
  unsigned long uVar17;
  unsigned long uVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  uint32_t auStack_b0 [2];
  long lStack_a8;
  long local_a0;
  unsigned long local_98;
  long local_90;
  uint64_t local_88;
  uint32_t local_7c;
  uint32_t local_78;
  uint32_t uStack_74;
  long local_70;
  long local_68;
  
  local_70 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_70 + 0x28);
  pcVar11 = *(char **)(param_1 + 0x30);
  if (*pcVar11 == '\0') {
    uVar17 = 1;
    lVar8 = param_1;
  }
  else {
    uVar17 = 9;
    lVar8 = *(long *)(pcVar11 + 1);
  }
  pcVar2 = pcVar11 + uVar17;
  uVar3 = *(uint32_t *)(pcVar2 + 0xc);
  uVar18 = (unsigned long)*(uint32_t *)(pcVar2 + 0x10);
  uVar10 = (uint32_t)uVar17 | 0x14;
  if (0 < (int)*(uint32_t *)(pcVar2 + 0x10)) {
    do {
      uVar18 = uVar18 - 1;
      uVar10 = uVar10 + *(int *)(pcVar11 + (int)uVar10) + 4;
    } while (uVar18 != 0);
  }
  uVar18 = (unsigned long)*(uint32_t *)(pcVar11 + (int)uVar10);
  uVar15 = *(uint32_t *)((long)(pcVar11 + (int)uVar10) + 4);
  uVar12 = (unsigned long)uVar15;
  iVar16 = uVar10 + 8;
  if (0 < (int)uVar15) {
    do {
      uVar12 = uVar12 - 1;
      iVar16 = iVar16 + *(int *)(pcVar11 + iVar16) + 4;
    } while (uVar12 != 0);
  }
  uStack_74 = *(uint32_t *)pcVar2;
  local_78 = *(uint32_t *)(pcVar11 + (uVar17 | 4));
  local_7c = *(uint32_t *)(pcVar2 + 8);
  uVar17 = (unsigned long)*(uint32_t *)(pcVar11 + iVar16);
  local_88 = VkObject_fromId(lVar8);
  lVar8 = -((unsigned long)uVar3 * 0x18 + 0xf & 0x3ffffffff0);
  local_90 = (long)&local_a0 + lVar8;
  lVar19 = local_90 - (uVar18 * 0x38 + 0xf & 0x7ffffffff0);
  lVar20 = lVar19 - (uVar17 * 0x48 + 0xf & 0xfffffffff0);
  pcVar11 = *(char **)(param_1 + 0x30);
  uVar10 = 9;
  if (*pcVar11 == '\0') {
    uVar10 = 1;
  }
  uVar12 = (unsigned long)*(uint32_t *)(pcVar11 + (unsigned long)uVar10 + 0x10);
  uVar15 = uVar10 | 0x14;
  local_98 = uVar17;
  if (0 < (int)*(uint32_t *)(pcVar11 + (unsigned long)uVar10 + 0x10)) {
    puVar14 = (uint32_t *)((long)&local_90 + lVar8);
    do {
      lVar8 = (long)(int)uVar15 + 4;
      pcVar2 = pcVar11 + lVar8;
      uVar4 = *(uint32_t *)pcVar2;
      uVar5 = *(uint32_t *)(pcVar2 + 4);
      iVar16 = *(int *)(pcVar11 + (int)uVar15);
      uVar12 = uVar12 - 1;
      *(uint64_t *)(puVar14 + -2) = 0;
      *puVar14 = uVar5;
      uVar5 = *(uint32_t *)(pcVar2 + 8);
      uVar15 = iVar16 + (int)lVar8;
      puVar14[-4] = uVar4;
      puVar14[1] = uVar5;
      puVar14 = puVar14 + 6;
    } while (uVar12 != 0);
  }
  uVar17 = (unsigned long)*(uint32_t *)(pcVar11 + (long)(int)uVar15 + 4);
  iVar16 = uVar15 + 8;
  local_a0 = lVar20;
  if (0 < (int)*(uint32_t *)(pcVar11 + (long)(int)uVar15 + 4)) {
    puVar14 = (uint32_t *)(lVar19 + 0x18);
    do {
      lVar8 = (long)iVar16 + 4;
      pcVar2 = pcVar11 + lVar8;
      uVar4 = *(uint32_t *)pcVar2;
      uVar5 = *(uint32_t *)(pcVar2 + 4);
      iVar16 = *(int *)(pcVar11 + iVar16);
      uVar9 = *(uint64_t *)(pcVar2 + 0x14);
      *(uint64_t *)(puVar14 + -4) = 0;
      puVar14[-2] = uVar5;
      uVar5 = *(uint32_t *)(pcVar2 + 8);
      puVar14[-6] = uVar4;
      puVar14[-1] = uVar5;
      *puVar14 = *(uint32_t *)(pcVar2 + 0xc);
      puVar14[1] = *(uint32_t *)(pcVar2 + 0x10);
      uVar9 = VkObject_fromId(uVar9);
      uVar13 = *(uint64_t *)(pcVar2 + 0x1c);
      *(uint64_t *)(puVar14 + 2) = uVar9;
      uVar17 = uVar17 - 1;
      *(uint64_t *)(puVar14 + 4) = uVar13;
      iVar16 = iVar16 + (int)lVar8;
      *(uint64_t *)(puVar14 + 6) = *(uint64_t *)(pcVar2 + 0x24);
      puVar14 = puVar14 + 0xe;
    } while (uVar17 != 0);
  }
  lVar8 = local_a0;
  uVar17 = (unsigned long)*(uint32_t *)(pcVar11 + (long)iVar16 + 4);
  if (0 < (int)*(uint32_t *)(pcVar11 + (long)iVar16 + 4)) {
    iVar16 = iVar16 + 8;
    lVar21 = local_a0;
    do {
      iVar6 = *(int *)(pcVar11 + iVar16);
      lVar1 = (long)iVar16 + 4;
      FUN_0014eed0(lVar21,pcVar11 + lVar1,param_1 + 0x40);
      iVar16 = iVar6 + (int)lVar1;
      uVar17 = uVar17 - 1;
      lVar21 = lVar21 + 0x48;
    } while (uVar17 != 0);
  }
  uVar7 = uStack_74;
  uVar5 = local_78;
  uVar4 = local_7c;
  uVar9 = local_88;
  lVar21 = local_90;
  uVar17 = local_98;
  *(long *)(lVar20 + -8) = lVar8;
  *(int *)(lVar20 + -0x10) = (int)uVar17;
  ((generic_fn_t)DAT_00193ed0)(uVar9,uVar7,uVar5,uVar4,(unsigned long)uVar3,lVar21,uVar18,lVar19);
  if (*(long *)(local_70 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0014aab8  size=164 */

void vt_handle_vkCmdPipelineBarrier2(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  uint64_t unaff_x19;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t uStack_60;
  uint64_t uStack_58;
  uint64_t local_50;
  uint64_t uStack_48;
  uint64_t uStack_40;
  uint64_t uStack_38;
  long local_28;
  
  /* stack canary setup */
  local_28 = *(long *)(lVar1 + 0x28);
  pcVar3 = *(char **)(param_1 + 0x30);
  uStack_48 = 0;
  local_50 = 0;
  uStack_38 = 0;
  uStack_40 = 0;
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar3 + 1);
    lVar4 = 9;
  }
  if (0 < *(int *)(pcVar3 + lVar4)) {
    FUN_0014fa0c(&local_70,pcVar3 + ((uint32_t)lVar4 | 4),param_1 + 0x40);
  }
  uVar2 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_001942c8)(uVar2,&local_70);
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013b3a4  size=312 */

void vt_handle_vkCmdPushConstants(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  long lVar6;
  long lVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  char *pcVar10;
  uint32_t uVar11;
  long lVar12;
  unsigned long uVar13;
  uint64_t unaff_x23;
  uint64_t auStack_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar6 + 0x28);
  pcVar10 = *(char **)(param_1 + 0x30);
  if (*pcVar10 == '\0') {
    lVar12 = 1;
    lVar7 = param_1;
  }
  else {
    lVar12 = 9;
    lVar7 = *(long *)(pcVar10 + 1);
  }
  uVar13 = lVar12 + 1;
  if (pcVar10[lVar12] != '\0') {
    unaff_x23 = *(uint64_t *)(pcVar10 + uVar13);
    uVar13 = (unsigned long)((int)lVar12 + 9);
  }
  puVar1 = (uint32_t *)(pcVar10 + uVar13);
  uVar3 = *puVar1;
  uVar4 = puVar1[1];
  uVar5 = puVar1[2];
  uVar8 = VkObject_fromId(lVar7);
  uVar9 = VkObject_fromId(unaff_x23);
  pcVar10 = *(char **)(param_1 + 0x30);
  uVar11 = 9;
  uVar2 = uVar11;
  if (*pcVar10 == '\0') {
    uVar2 = 1;
  }
  if (pcVar10[uVar2] == '\0') {
    uVar11 = 1;
  }
  if (0 < (int)*(uint32_t *)(pcVar10 + (unsigned long)(uVar11 + uVar2) + 0xc)) {
    memcpy(auStack_60 + -((unsigned long)uVar5 + 0xf & 0x1fffffff0),pcVar10 + (uVar11 + uVar2 + 0x10),
           (unsigned long)*(uint32_t *)(pcVar10 + (unsigned long)(uVar11 + uVar2) + 0xc));
  }
  ((generic_fn_t)DAT_00193f10)(uVar8,uVar9,(uVar3 & 1) << 4 | uVar3,uVar4,(unsigned long)uVar5,
                  auStack_60 + -((unsigned long)uVar5 + 0xf & 0x1fffffff0));
  if (*(long *)(lVar6 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00142588  size=376 */

void vt_handle_vkCmdPushDescriptorSetKHR(long param_1)

{
  int iVar1;
  long lVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  uint32_t uVar6;
  int iVar7;
  unsigned long uVar8;
  unsigned long uVar9;
  uint64_t unaff_x24;
  uint8_t *puVar10;
  uint64_t auStack_80;
  uint32_t local_78;
  uint32_t local_74;
  long local_70;
  long local_68;
  
  local_70 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_70 + 0x28);
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    uVar8 = 1;
    lVar2 = param_1;
  }
  else {
    uVar8 = 9;
    lVar2 = *(long *)(pcVar5 + 1);
  }
  local_74 = *(uint32_t *)(pcVar5 + uVar8);
  uVar9 = uVar8 + 5;
  if (pcVar5[uVar8 | 4] != '\0') {
    unaff_x24 = *(uint64_t *)(pcVar5 + uVar9);
    uVar9 = (unsigned long)((int)uVar8 + 0xd);
  }
  local_78 = *(uint32_t *)(pcVar5 + uVar9);
  uVar8 = (unsigned long)*(uint32_t *)(pcVar5 + uVar9 + 4);
  uVar3 = VkObject_fromId(lVar2);
  uVar4 = VkObject_fromId(unaff_x24);
  pcVar5 = *(char **)(param_1 + 0x30);
  uVar6 = 9;
  if (*pcVar5 == '\0') {
    uVar6 = 1;
  }
  iVar7 = 5;
  if (pcVar5[(unsigned long)uVar6 + 4] != '\0') {
    iVar7 = 0xd;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar5 + (unsigned long)(iVar7 + uVar6) + 8);
  if (0 < (int)*(uint32_t *)(pcVar5 + (unsigned long)(iVar7 + uVar6) + 8)) {
    iVar7 = iVar7 + uVar6 + 0xc;
    puVar10 = auStack_80 + uVar8 * -0x40;
    do {
      iVar1 = *(int *)(pcVar5 + iVar7);
      lVar2 = (long)iVar7 + 4;
      FUN_0014eab8(puVar10,pcVar5 + lVar2,param_1 + 0x40);
      iVar7 = iVar1 + (int)lVar2;
      uVar9 = uVar9 - 1;
      puVar10 = puVar10 + 0x40;
    } while (uVar9 != 0);
  }
  ((generic_fn_t)DAT_00193fb0)(uVar3,local_74,uVar4,local_78,uVar8,auStack_80 + uVar8 * -0x40);
  if (*(long *)(local_70 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013a910  size=132 */

void vt_handle_vkCmdResetEvent(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar6 = lVar5 + 1;
  if (pcVar4[lVar5] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar6);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013a990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193ec0)(uVar2,uVar3,uVar1);
  return;
}


/* @0014a8cc  size=132 */

void vt_handle_vkCmdResetEvent2(long param_1)

{
  uint64_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  unsigned long uVar5;
  uint64_t unaff_x19;
  uint64_t uVar6;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar5 = lVar4 + 1;
  if (pcVar3[lVar4] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar3 + uVar5);
    uVar5 = (unsigned long)((int)lVar4 + 9);
  }
  uVar6 = *(uint64_t *)(pcVar3 + uVar5);
  uVar1 = VkObject_fromId(param_1);
  uVar2 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0014a94c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001942b8)(uVar1,uVar2,uVar6);
  return;
}


/* @0013b1a8  size=140 */

void vt_handle_vkCmdResetQueryPool(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  unsigned long uVar7;
  uint64_t unaff_x19;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
  }
  uVar7 = lVar6 + 1;
  if (pcVar5[lVar6] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar5 + uVar7);
    uVar7 = (unsigned long)((int)lVar6 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar5 + uVar7);
  uVar2 = *(uint32_t *)(pcVar5 + uVar7 + 4);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013b230. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193ef8)(uVar3,uVar4,uVar1,uVar2);
  return;
}


/* @0013a66c  size=544 */

void vt_handle_vkCmdResolveImage(long param_1)

{
  /* STUB: vt_handle_vkCmdResolveImage — Ghidra artifacts */
}


/* @0014a4dc  size=556 */

void vt_handle_vkCmdResolveImage2(long param_1)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  long lVar7;
  void *__s;
  uint64_t uVar8;
  char *pcVar9;
  uint32_t *puVar10;
  int iVar11;
  unsigned long uVar12;
  uint64_t unaff_x19;
  unsigned long local_90 [3];
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t local_68;
  void *local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar7 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_60 = (void *)0x0;
  uStack_78 = 0;
  local_90[2] = 0;
  local_68 = 0;
  local_70 = 0;
  local_90[1] = 0;
  local_90[0] = 0;
  if (*pcVar9 == '\0') {
    uVar12 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar9 + 1);
    uVar12 = 9;
  }
  if (0 < *(int *)(pcVar9 + uVar12)) {
    puVar2 = (uint32_t *)(pcVar9 + (uVar12 | 4));
    local_90[1] = 0;
    local_90[0] = (unsigned long)*puVar2;
    local_90[2] = VkObject_fromId(*(uint64_t *)(puVar2 + 1));
    uStack_78 = ((uint64_t)((*(uint32_t*)((char*)&uStack_78 + 4))) << 32 | (uint32_t)(puVar2[3]));
    local_70 = VkObject_fromId(*(uint64_t *)(puVar2 + 4));
    local_68 = *(uint64_t *)(puVar2 + 6);
    uVar4 = puVar2[8];
    uVar12 = (unsigned long)uVar4;
    if ((int)uVar4 < 1) {
      local_60 = (void *)0x0;
    }
    else {
      iVar6 = uVar4 * 0x58;
      iVar11 = *(int *)(param_1 + 0x48) + iVar6;
      if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar11;
      }
      else {
        __s = malloc((long)iVar6);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar6);
      puVar10 = (uint32_t *)((long)__s + 0x28);
      iVar11 = 0x24;
      do {
        iVar6 = *(int *)((long)puVar2 + (long)iVar11);
        lVar1 = (long)iVar11 + 4;
        if (__s != (void *)0x0) {
          puVar3 = (uint32_t *)((long)puVar2 + lVar1);
          uVar5 = *puVar3;
          *(uint64_t *)(puVar10 + -8) = 0;
          puVar10[-10] = uVar5;
          puVar10[-6] = puVar3[1];
          puVar10[-5] = puVar3[2];
          puVar10[-4] = puVar3[3];
          puVar10[-3] = puVar3[4];
          puVar10[-2] = puVar3[5];
          puVar10[-1] = puVar3[6];
          *puVar10 = puVar3[7];
          puVar10[1] = puVar3[8];
          puVar10[2] = puVar3[9];
          puVar10[3] = puVar3[10];
          puVar10[4] = puVar3[0xb];
          puVar10[5] = puVar3[0xc];
          puVar10[6] = puVar3[0xd];
          puVar10[7] = puVar3[0xe];
          puVar10[8] = puVar3[0xf];
          puVar10[9] = puVar3[0x10];
          puVar10[10] = puVar3[0x11];
        }
        iVar11 = iVar6 + (int)lVar1;
        uVar12 = uVar12 - 1;
        puVar10 = puVar10 + 0x16;
        local_60 = __s;
      } while (uVar12 != 0);
    }
  }
  uVar8 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_001942a0)(uVar8,local_90);
  if (*(long *)(lVar7 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001492ac  size=76 */

void vt_handle_vkCmdSetAlphaToCoverageEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001492f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941f8)(uVar2,uVar1);
  return;
}


/* @001492f8  size=76 */

void vt_handle_vkCmdSetAlphaToOneEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194200)(uVar2,uVar1);
  return;
}


/* @00138cd0  size=140 */

void vt_handle_vkCmdSetBlendConstants(long param_1)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t local_40;
  uint64_t uStack_38;
  long local_28;
  
  /* stack canary setup */
  local_28 = *(long *)(lVar2 + 0x28);
  lVar3 = param_1;
  if (**(char **)(param_1 + 0x30) != '\0') {
    lVar3 = *(long *)(*(char **)(param_1 + 0x30) + 1);
  }
  uVar4 = VkObject_fromId(lVar3);
  lVar3 = 9;
  if (**(char **)(param_1 + 0x30) == '\0') {
    lVar3 = 1;
  }
  pcVar1 = *(char **)(param_1 + 0x30) + lVar3;
  uStack_38 = *(uint64_t *)(pcVar1 + 8);
  local_40 = *(uint64_t *)pcVar1;
  ((generic_fn_t)DAT_00193df0)(uVar4,&local_40);
  if (*(long *)(lVar2 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00149828  size=272 */

void vt_handle_vkCmdSetColorBlendAdvancedEXT(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  char *pcVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  uint64_t *puVar10;
  int iVar11;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar9 = 1;
    lVar5 = param_1;
  }
  else {
    uVar9 = 9;
    lVar5 = *(long *)(pcVar7 + 1);
  }
  uVar2 = *(uint32_t *)(pcVar7 + uVar9);
  uVar3 = *(uint32_t *)(pcVar7 + (uVar9 | 4));
  uVar6 = VkObject_fromId(lVar5);
  pcVar7 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8);
  if (0 < (int)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8)) {
    iVar11 = uVar8 + 0xc;
    puVar10 = (uint64_t *)((long)&local_38 + (4 - ((unsigned long)uVar3 * 0x14 + 0xf & 0x3ffffffff0)));
    do {
      lVar5 = (long)iVar11 + 4;
      pcVar1 = pcVar7 + lVar5;
      iVar11 = *(int *)(pcVar7 + iVar11);
      uVar9 = uVar9 - 1;
      *(uint64_t *)((long)puVar10 + -0xc) = *(uint64_t *)pcVar1;
      iVar11 = iVar11 + (int)lVar5;
      *(uint32_t *)((long)puVar10 + -4) = *(uint32_t *)(pcVar1 + 8);
      *puVar10 = *(uint64_t *)(pcVar1 + 0xc);
      puVar10 = (uint64_t *)((long)puVar10 + 0x14);
    } while (uVar9 != 0);
  }
  ((generic_fn_t)DAT_00194250)(uVar6,uVar2,(unsigned long)uVar3);
  if (*(long *)(lVar4 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00149390  size=248 */

void vt_handle_vkCmdSetColorBlendEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  char *pcVar6;
  uint32_t uVar7;
  unsigned long uVar8;
  uint64_t auStack_50;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar3 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    uVar8 = 1;
    lVar4 = param_1;
  }
  else {
    uVar8 = 9;
    lVar4 = *(long *)(pcVar6 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar6 + uVar8);
  uVar2 = *(uint32_t *)(pcVar6 + (uVar8 | 4));
  uVar5 = VkObject_fromId(lVar4);
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  if (0 < *(int *)(pcVar6 + (unsigned long)uVar7 + 8)) {
    memcpy(auStack_50 + -((unsigned long)uVar2 * 4 + 0xf & 0x7fffffff0),pcVar6 + (uVar7 + 0xc),
           (long)*(int *)(pcVar6 + (unsigned long)uVar7 + 8) << 2);
  }
  ((generic_fn_t)DAT_00194210)(uVar5,uVar1,(unsigned long)uVar2,auStack_50 + -((unsigned long)uVar2 * 4 + 0xf & 0x7fffffff0));
  if (*(long *)(lVar3 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00149488  size=300 */

void vt_handle_vkCmdSetColorBlendEquationEXT(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  char *pcVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  uint32_t *puVar10;
  int iVar11;
  uint64_t local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar9 = 1;
    lVar5 = param_1;
  }
  else {
    uVar9 = 9;
    lVar5 = *(long *)(pcVar7 + 1);
  }
  uVar2 = *(uint32_t *)(pcVar7 + uVar9);
  uVar3 = *(uint32_t *)(pcVar7 + (uVar9 | 4));
  uVar6 = VkObject_fromId(lVar5);
  pcVar7 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8);
  if (0 < (int)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8)) {
    iVar11 = uVar8 + 0xc;
    puVar10 = (uint32_t *)((long)&local_38 + (4 - ((unsigned long)uVar3 * 0x18 + 0xf & 0x3ffffffff0)));
    do {
      lVar5 = (long)iVar11 + 4;
      pcVar1 = pcVar7 + lVar5;
      iVar11 = *(int *)(pcVar7 + iVar11);
      uVar9 = uVar9 - 1;
      puVar10[-3] = *(uint32_t *)pcVar1;
      iVar11 = iVar11 + (int)lVar5;
      puVar10[-2] = *(uint32_t *)(pcVar1 + 4);
      puVar10[-1] = *(uint32_t *)(pcVar1 + 8);
      *puVar10 = *(uint32_t *)(pcVar1 + 0xc);
      puVar10[1] = *(uint32_t *)(pcVar1 + 0x10);
      puVar10[2] = *(uint32_t *)(pcVar1 + 0x14);
      puVar10 = puVar10 + 6;
    } while (uVar9 != 0);
  }
  ((generic_fn_t)DAT_00194218)(uVar6,uVar2,(unsigned long)uVar3);
  if (*(long *)(lVar4 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0014a708  size=232 */

void vt_handle_vkCmdSetColorWriteEnableEXT(long param_1)

{
  uint32_t uVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  char *pcVar5;
  uint32_t uVar6;
  long lVar7;
  uint64_t auStack_50;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar7 = 1;
    lVar3 = param_1;
  }
  else {
    lVar7 = 9;
    lVar3 = *(long *)(pcVar5 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar5 + lVar7);
  uVar4 = VkObject_fromId(lVar3);
  pcVar5 = *(char **)(param_1 + 0x30);
  uVar6 = 9;
  if (*pcVar5 == '\0') {
    uVar6 = 1;
  }
  if (0 < *(int *)(pcVar5 + (unsigned long)uVar6 + 4)) {
    memcpy(auStack_50 + -((unsigned long)uVar1 * 4 + 0xf & 0x7fffffff0),pcVar5 + (uVar6 + 8),
           (long)*(int *)(pcVar5 + (unsigned long)uVar6 + 4) << 2);
  }
  ((generic_fn_t)DAT_001942a8)(uVar4,(unsigned long)uVar1,auStack_50 + -((unsigned long)uVar1 * 4 + 0xf & 0x7fffffff0));
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001495b4  size=248 */

void vt_handle_vkCmdSetColorWriteMaskEXT(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  char *pcVar6;
  uint32_t uVar7;
  unsigned long uVar8;
  uint64_t auStack_50;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar3 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    uVar8 = 1;
    lVar4 = param_1;
  }
  else {
    uVar8 = 9;
    lVar4 = *(long *)(pcVar6 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar6 + uVar8);
  uVar2 = *(uint32_t *)(pcVar6 + (uVar8 | 4));
  uVar5 = VkObject_fromId(lVar4);
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  if (0 < *(int *)(pcVar6 + (unsigned long)uVar7 + 8)) {
    memcpy(auStack_50 + -((unsigned long)uVar2 * 4 + 0xf & 0x7fffffff0),pcVar6 + (uVar7 + 0xc),
           (long)*(int *)(pcVar6 + (unsigned long)uVar7 + 8) << 2);
  }
  ((generic_fn_t)DAT_00194220)(uVar5,uVar1,(unsigned long)uVar2,auStack_50 + -((unsigned long)uVar2 * 4 + 0xf & 0x7fffffff0));
  if (*(long *)(lVar3 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001496f8  size=76 */

void vt_handle_vkCmdSetConservativeRasterizationModeEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194230)(uVar2,uVar1);
  return;
}


/* @00148928  size=76 */

void vt_handle_vkCmdSetCullMode(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148970. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194158)(uVar2,uVar1);
  return;
}


/* @00138c60  size=112 */

void vt_handle_vkCmdSetDepthBias(long param_1)

{
  char *pcVar1;
  unsigned long uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  pcVar1 = *(char **)(param_1 + 0x30);
  if (*pcVar1 == '\0') {
    uVar2 = 1;
  }
  else {
    param_1 = *(long *)(pcVar1 + 1);
    uVar2 = 9;
  }
  uVar3 = *(uint32_t *)(pcVar1 + uVar2);
  uVar4 = *(uint32_t *)(pcVar1 + (uVar2 | 4));
  uVar5 = *(uint32_t *)(pcVar1 + uVar2 + 8);
  VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00138ccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193de8)(uVar3,uVar4,uVar5);
  return;
}


/* @00149054  size=76 */

void vt_handle_vkCmdSetDepthBiasEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x0014909c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941c0)(uVar2,uVar1);
  return;
}


/* @00138d5c  size=92 */

void vt_handle_vkCmdSetDepthBounds(long param_1)

{
  char *pcVar1;
  unsigned long uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  pcVar1 = *(char **)(param_1 + 0x30);
  if (*pcVar1 == '\0') {
    uVar2 = 1;
  }
  else {
    param_1 = *(long *)(pcVar1 + 1);
    uVar2 = 9;
  }
  uVar3 = *(uint32_t *)(pcVar1 + uVar2);
  uVar4 = *(uint32_t *)(pcVar1 + (uVar2 | 4));
  VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00138db4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193df8)(uVar3,uVar4);
  return;
}


/* @00148eec  size=76 */

void vt_handle_vkCmdSetDepthBoundsTestEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148f34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941a0)(uVar2,uVar1);
  return;
}


/* @00149138  size=76 */

void vt_handle_vkCmdSetDepthClampEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941d8)(uVar2,uVar1);
  return;
}


/* @00149790  size=76 */

void vt_handle_vkCmdSetDepthClipEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001497d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194240)(uVar2,uVar1);
  return;
}


/* @00149a1c  size=76 */

void vt_handle_vkCmdSetDepthClipNegativeOneToOneEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149a64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194270)(uVar2,uVar1);
  return;
}


/* @00148ea0  size=76 */

void vt_handle_vkCmdSetDepthCompareOp(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194198)(uVar2,uVar1);
  return;
}


/* @00148e08  size=76 */

void vt_handle_vkCmdSetDepthTestEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148e50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194188)(uVar2,uVar1);
  return;
}


/* @00148e54  size=76 */

void vt_handle_vkCmdSetDepthWriteEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148e9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194190)(uVar2,uVar1);
  return;
}


/* @00143ea8  size=76 */

void vt_handle_vkCmdSetDeviceMask(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00143ef0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194010)(uVar2,uVar1);
  return;
}


/* @0013a88c  size=132 */

void vt_handle_vkCmdSetEvent(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar6 = lVar5 + 1;
  if (pcVar4[lVar5] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar6);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013a90c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193eb8)(uVar2,uVar3,uVar1);
  return;
}


/* @0014a7f0  size=220 */

void vt_handle_vkCmdSetEvent2(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  long lVar6;
  uint64_t unaff_x19;
  uint64_t unaff_x20;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t uStack_70;
  uint64_t uStack_68;
  uint64_t local_60;
  uint64_t uStack_58;
  uint64_t uStack_50;
  uint64_t uStack_48;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar1 + 0x28);
  pcVar4 = *(char **)(param_1 + 0x30);
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  if (*pcVar4 == '\0') {
    lVar6 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar4 + 1);
    lVar6 = 9;
  }
  uVar5 = lVar6 + 1;
  if (pcVar4[lVar6] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar4 + uVar5);
    uVar5 = (unsigned long)((int)lVar6 + 9);
  }
  if (0 < *(int *)(pcVar4 + uVar5)) {
    FUN_0014fa0c(&local_80,pcVar4 + ((int)uVar5 + 4),param_1 + 0x40);
  }
  uVar2 = VkObject_fromId(unaff_x19);
  uVar3 = VkObject_fromId(unaff_x20);
  ((generic_fn_t)DAT_001942b0)(uVar2,uVar3,&local_80);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00149744  size=76 */

void vt_handle_vkCmdSetExtraPrimitiveOverestimationSizeEXT(long param_1)

{
  char *pcVar1;
  long lVar2;
  uint32_t uVar3;
  
  pcVar1 = *(char **)(param_1 + 0x30);
  if (*pcVar1 == '\0') {
    lVar2 = 1;
  }
  else {
    param_1 = *(long *)(pcVar1 + 1);
    lVar2 = 9;
  }
  uVar3 = *(uint32_t *)(pcVar1 + lVar2);
  VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x0014978c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194238)(uVar3);
  return;
}


/* @00148974  size=76 */

void vt_handle_vkCmdSetFrontFace(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001489bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194160)(uVar2,uVar1);
  return;
}


/* @00149984  size=76 */

void vt_handle_vkCmdSetLineRasterizationModeEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001499cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194260)(uVar2,uVar1);
  return;
}


/* @001499d0  size=76 */

void vt_handle_vkCmdSetLineStippleEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194268)(uVar2,uVar1);
  return;
}


/* @001488cc  size=92 */

void vt_handle_vkCmdSetLineStippleKHR(long param_1)

{
  uint32_t uVar1;
  uint16_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    uVar5 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar5);
  uVar2 = *(uint16_t *)(pcVar4 + (uVar5 | 4));
  uVar3 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148924. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194150)(uVar3,uVar1,uVar2);
  return;
}


/* @00138c14  size=76 */

void vt_handle_vkCmdSetLineWidth(long param_1)

{
  char *pcVar1;
  long lVar2;
  uint32_t uVar3;
  
  pcVar1 = *(char **)(param_1 + 0x30);
  if (*pcVar1 == '\0') {
    lVar2 = 1;
  }
  else {
    param_1 = *(long *)(pcVar1 + 1);
    lVar2 = 9;
  }
  uVar3 = *(uint32_t *)(pcVar1 + lVar2);
  VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00138c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193de0)(uVar3);
  return;
}


/* @00149344  size=76 */

void vt_handle_vkCmdSetLogicOpEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x0014938c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194208)(uVar2,uVar1);
  return;
}


/* @00149184  size=76 */

void vt_handle_vkCmdSetPolygonModeEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001491cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941e0)(uVar2,uVar1);
  return;
}


/* @001490a0  size=76 */

void vt_handle_vkCmdSetPrimitiveRestartEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001490e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941c8)(uVar2,uVar1);
  return;
}


/* @001489c0  size=76 */

void vt_handle_vkCmdSetPrimitiveTopology(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194168)(uVar2,uVar1);
  return;
}


/* @00149938  size=76 */

void vt_handle_vkCmdSetProvokingVertexModeEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194258)(uVar2,uVar1);
  return;
}


/* @001491d0  size=76 */

void vt_handle_vkCmdSetRasterizationSamplesEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941e8)(uVar2,uVar1);
  return;
}


/* @001496ac  size=76 */

void vt_handle_vkCmdSetRasterizationStreamEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x001496f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194228)(uVar2,uVar1);
  return;
}


/* @00149008  size=76 */

void vt_handle_vkCmdSetRasterizerDiscardEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941b8)(uVar2,uVar1);
  return;
}


/* @0014425c  size=400 */

void vt_handle_vkCmdSetSampleLocationsEXT(long param_1)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  void *__s;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t *puVar9;
  int iVar10;
  unsigned long uVar11;
  uint64_t unaff_x19;
  unsigned long local_80 [4];
  void *local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar6 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  local_60 = (void *)0x0;
  local_80[1] = 0;
  local_80[0] = 0;
  local_80[3] = 0;
  local_80[2] = 0;
  if (*pcVar8 == '\0') {
    uVar11 = 1;
  }
  else {
    unaff_x19 = *(uint64_t *)(pcVar8 + 1);
    uVar11 = 9;
  }
  if (0 < *(int *)(pcVar8 + uVar11)) {
    puVar2 = (uint32_t *)(pcVar8 + (uVar11 | 4));
    local_80[1] = 0;
    local_80[0] = (unsigned long)*puVar2;
    local_80[2] = *(unsigned long *)(puVar2 + 1);
    local_80[3] = *(unsigned long *)(puVar2 + 3);
    uVar4 = puVar2[5];
    uVar11 = (unsigned long)uVar4;
    if ((int)uVar4 < 1) {
      local_60 = (void *)0x0;
    }
    else {
      iVar5 = uVar4 * 8;
      iVar10 = *(int *)(param_1 + 0x48) + iVar5;
      if ((iVar10 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar10;
      }
      else {
        __s = malloc((long)iVar5);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar5);
      puVar9 = (uint32_t *)((long)__s + 4);
      iVar10 = 0x18;
      do {
        iVar5 = *(int *)((long)puVar2 + (long)iVar10);
        lVar1 = (long)iVar10 + 4;
        if (__s != (void *)0x0) {
          puVar3 = (uint32_t *)((long)puVar2 + lVar1);
          puVar9[-1] = *puVar3;
          *puVar9 = puVar3[1];
        }
        iVar10 = iVar5 + (int)lVar1;
        uVar11 = uVar11 - 1;
        puVar9 = puVar9 + 2;
        local_60 = __s;
      } while (uVar11 != 0);
    }
  }
  uVar7 = VkObject_fromId(unaff_x19);
  ((generic_fn_t)DAT_00194048)(uVar7,local_80);
  if (*(long *)(lVar6 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001497dc  size=76 */

void vt_handle_vkCmdSetSampleLocationsEnableEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149824. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194248)(uVar2,uVar1);
  return;
}


/* @0014921c  size=144 */

void vt_handle_vkCmdSetSampleMaskEXT(long param_1)

{
  uint32_t uVar1;
  long lVar2;
  uint64_t uVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  
  /* stack canary setup */
  lVar4 = *(long *)(lVar2 + 0x28);
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar5 + lVar6);
  uVar3 = VkObject_fromId(param_1);
  ((generic_fn_t)DAT_001941f0)(uVar3,uVar1);
  if (*(long *)(lVar2 + 0x28) == lVar4) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00138b08  size=268 */

void vt_handle_vkCmdSetScissor(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  char *pcVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  long *plVar10;
  int iVar11;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar9 = 1;
    lVar5 = param_1;
  }
  else {
    uVar9 = 9;
    lVar5 = *(long *)(pcVar7 + 1);
  }
  uVar2 = *(uint32_t *)(pcVar7 + uVar9);
  uVar3 = *(uint32_t *)(pcVar7 + (uVar9 | 4));
  uVar6 = VkObject_fromId(lVar5);
  pcVar7 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8);
  if (0 < (int)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8)) {
    iVar11 = uVar8 + 0xc;
    plVar10 = &local_38 + (unsigned long)uVar3 * -2;
    do {
      lVar5 = (long)iVar11 + 4;
      pcVar1 = pcVar7 + lVar5;
      iVar11 = *(int *)(pcVar7 + iVar11);
      uVar9 = uVar9 - 1;
      *(uint32_t *)(plVar10 + -1) = *(uint32_t *)pcVar1;
      iVar11 = iVar11 + (int)lVar5;
      *(uint32_t *)((long)plVar10 + -4) = *(uint32_t *)(pcVar1 + 4);
      *(uint32_t *)plVar10 = *(uint32_t *)(pcVar1 + 8);
      *(uint32_t *)((long)plVar10 + 4) = *(uint32_t *)(pcVar1 + 0xc);
      plVar10 = plVar10 + 2;
    } while (uVar9 != 0);
  }
  ((generic_fn_t)DAT_00193dd8)(uVar6,uVar2,(unsigned long)uVar3);
  if (*(long *)(lVar4 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00148b28  size=252 */

void vt_handle_vkCmdSetScissorWithCount(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  char *pcVar6;
  uint32_t uVar7;
  long lVar8;
  unsigned long uVar9;
  long *plVar10;
  int iVar11;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar8 = 1;
    lVar4 = param_1;
  }
  else {
    lVar8 = 9;
    lVar4 = *(long *)(pcVar6 + 1);
  }
  uVar2 = *(uint32_t *)(pcVar6 + lVar8);
  uVar5 = VkObject_fromId(lVar4);
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4);
  if (0 < (int)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4)) {
    iVar11 = uVar7 + 8;
    plVar10 = &local_38 + (unsigned long)uVar2 * -2;
    do {
      lVar4 = (long)iVar11 + 4;
      pcVar1 = pcVar6 + lVar4;
      iVar11 = *(int *)(pcVar6 + iVar11);
      uVar9 = uVar9 - 1;
      *(uint32_t *)(plVar10 + -1) = *(uint32_t *)pcVar1;
      iVar11 = iVar11 + (int)lVar4;
      *(uint32_t *)((long)plVar10 + -4) = *(uint32_t *)(pcVar1 + 4);
      *(uint32_t *)plVar10 = *(uint32_t *)(pcVar1 + 8);
      *(uint32_t *)((long)plVar10 + 4) = *(uint32_t *)(pcVar1 + 0xc);
      plVar10 = plVar10 + 2;
    } while (uVar9 != 0);
  }
  ((generic_fn_t)DAT_00194178)(uVar5,(unsigned long)uVar2);
  if (*(long *)(lVar3 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00138db8  size=92 */

void vt_handle_vkCmdSetStencilCompareMask(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    uVar5 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar5);
  uVar2 = *(uint32_t *)(pcVar4 + (uVar5 | 4));
  uVar3 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00138e10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e00)(uVar3,uVar1,uVar2);
  return;
}


/* @00148f84  size=132 */

void vt_handle_vkCmdSetStencilOp(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  unsigned long uVar9;
  
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  else {
    param_1 = *(long *)(pcVar8 + 1);
    uVar9 = 9;
  }
  pcVar1 = pcVar8 + uVar9;
  uVar4 = *(uint32_t *)pcVar1;
  uVar6 = *(uint32_t *)(pcVar8 + (uVar9 | 4));
  uVar2 = *(uint32_t *)(pcVar1 + 8);
  uVar3 = *(uint32_t *)(pcVar1 + 0xc);
  uVar5 = *(uint32_t *)(pcVar1 + 0x10);
  uVar7 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941b0)(uVar7,uVar4,uVar6,uVar2,uVar3,uVar5);
  return;
}


/* @00138e70  size=92 */

void vt_handle_vkCmdSetStencilReference(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    uVar5 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar5);
  uVar2 = *(uint32_t *)(pcVar4 + (uVar5 | 4));
  uVar3 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00138ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e10)(uVar3,uVar1,uVar2);
  return;
}


/* @00148f38  size=76 */

void vt_handle_vkCmdSetStencilTestEnable(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00148f80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941a8)(uVar2,uVar1);
  return;
}


/* @00138e14  size=92 */

void vt_handle_vkCmdSetStencilWriteMask(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    uVar5 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar5);
  uVar2 = *(uint32_t *)(pcVar4 + (uVar5 | 4));
  uVar3 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00138e6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193e08)(uVar3,uVar1,uVar2);
  return;
}


/* @001490ec  size=76 */

void vt_handle_vkCmdSetTessellationDomainOriginEXT(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00149134. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001941d0)(uVar2,uVar1);
  return;
}


/* @001389dc  size=300 */

void vt_handle_vkCmdSetViewport(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  char *pcVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  uint32_t *puVar10;
  int iVar11;
  uint64_t local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar9 = 1;
    lVar5 = param_1;
  }
  else {
    uVar9 = 9;
    lVar5 = *(long *)(pcVar7 + 1);
  }
  uVar2 = *(uint32_t *)(pcVar7 + uVar9);
  uVar3 = *(uint32_t *)(pcVar7 + (uVar9 | 4));
  uVar6 = VkObject_fromId(lVar5);
  pcVar7 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8);
  if (0 < (int)*(uint32_t *)(pcVar7 + (unsigned long)uVar8 + 8)) {
    iVar11 = uVar8 + 0xc;
    puVar10 = (uint32_t *)((long)&local_38 + (4 - ((unsigned long)uVar3 * 0x18 + 0xf & 0x3ffffffff0)));
    do {
      lVar5 = (long)iVar11 + 4;
      pcVar1 = pcVar7 + lVar5;
      iVar11 = *(int *)(pcVar7 + iVar11);
      uVar9 = uVar9 - 1;
      puVar10[-3] = *(uint32_t *)pcVar1;
      iVar11 = iVar11 + (int)lVar5;
      puVar10[-2] = *(uint32_t *)(pcVar1 + 4);
      puVar10[-1] = *(uint32_t *)(pcVar1 + 8);
      *puVar10 = *(uint32_t *)(pcVar1 + 0xc);
      puVar10[1] = *(uint32_t *)(pcVar1 + 0x10);
      puVar10[2] = *(uint32_t *)(pcVar1 + 0x14);
      puVar10 = puVar10 + 6;
    } while (uVar9 != 0);
  }
  ((generic_fn_t)DAT_00193dd0)(uVar6,uVar2,(unsigned long)uVar3);
  if (*(long *)(lVar4 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00148a0c  size=284 */

void vt_handle_vkCmdSetViewportWithCount(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  char *pcVar6;
  uint32_t uVar7;
  long lVar8;
  unsigned long uVar9;
  uint32_t *puVar10;
  int iVar11;
  uint64_t local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar8 = 1;
    lVar4 = param_1;
  }
  else {
    lVar8 = 9;
    lVar4 = *(long *)(pcVar6 + 1);
  }
  uVar2 = *(uint32_t *)(pcVar6 + lVar8);
  uVar5 = VkObject_fromId(lVar4);
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  uVar9 = (unsigned long)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4);
  if (0 < (int)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4)) {
    iVar11 = uVar7 + 8;
    puVar10 = (uint32_t *)((long)&local_38 + (4 - ((unsigned long)uVar2 * 0x18 + 0xf & 0x3ffffffff0)));
    do {
      lVar4 = (long)iVar11 + 4;
      pcVar1 = pcVar6 + lVar4;
      iVar11 = *(int *)(pcVar6 + iVar11);
      uVar9 = uVar9 - 1;
      puVar10[-3] = *(uint32_t *)pcVar1;
      iVar11 = iVar11 + (int)lVar4;
      puVar10[-2] = *(uint32_t *)(pcVar1 + 4);
      puVar10[-1] = *(uint32_t *)(pcVar1 + 8);
      *puVar10 = *(uint32_t *)(pcVar1 + 0xc);
      puVar10[1] = *(uint32_t *)(pcVar1 + 0x10);
      puVar10[2] = *(uint32_t *)(pcVar1 + 0x14);
      puVar10 = puVar10 + 6;
    } while (uVar9 != 0);
  }
  ((generic_fn_t)DAT_00194170)(uVar5,(unsigned long)uVar2);
  if (*(long *)(lVar3 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00139f9c  size=300 */

void vt_handle_vkCmdUpdateBuffer(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  char *pcVar7;
  uint32_t uVar8;
  long lVar9;
  unsigned long uVar10;
  uint64_t unaff_x23;
  uint64_t auStack_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar3 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    lVar9 = 1;
    lVar4 = param_1;
  }
  else {
    lVar9 = 9;
    lVar4 = *(long *)(pcVar7 + 1);
  }
  uVar10 = lVar9 + 1;
  if (pcVar7[lVar9] != '\0') {
    unaff_x23 = *(uint64_t *)(pcVar7 + uVar10);
    uVar10 = (unsigned long)((int)lVar9 + 9);
  }
  uVar2 = *(uint64_t *)(pcVar7 + uVar10);
  lVar9 = *(long *)(pcVar7 + uVar10 + 8);
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x23);
  pcVar7 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  uVar1 = uVar8;
  if (*pcVar7 == '\0') {
    uVar1 = 1;
  }
  if (pcVar7[uVar1] == '\0') {
    uVar8 = 1;
  }
  if (0 < (int)*(uint32_t *)(pcVar7 + (unsigned long)(uVar8 + uVar1) + 0x10)) {
    memcpy(auStack_60 + -(lVar9 + 0xfU & 0xfffffffffffffff0),pcVar7 + (uVar8 + uVar1 + 0x14),
           (unsigned long)*(uint32_t *)(pcVar7 + (unsigned long)(uVar8 + uVar1) + 0x10));
  }
  ((generic_fn_t)DAT_00193e88)(uVar5,uVar6,uVar2,lVar9,auStack_60 + -(lVar9 + 0xfU & 0xfffffffffffffff0));
  if (*(long *)(lVar3 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013a994  size=828 */

void vt_handle_vkCmdWaitEvents(long param_1)

{
  long lVar1;
  char *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  uint32_t uVar8;
  char *pcVar9;
  long lVar10;
  uint64_t uVar11;
  unsigned long uVar12;
  uint32_t *puVar13;
  int iVar14;
  int iVar15;
  unsigned long uVar16;
  uint64_t *puVar17;
  unsigned long uVar18;
  long lVar19;
  unsigned long uVar20;
  long lVar21;
  long lStack_d0;
  uint32_t auStack_c8 [2];
  long alStack_c0 [2];
  long alStack_b0 [2];
  long local_a0;
  uint64_t *local_98;
  uint64_t local_90;
  unsigned long local_88;
  uint32_t local_80;
  uint32_t uStack_7c;
  long local_78;
  long local_70;
  long local_68;
  
  local_78 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_78 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    uVar12 = 1;
    lVar10 = param_1;
  }
  else {
    uVar12 = 9;
    lVar10 = *(long *)(pcVar9 + 1);
  }
  uVar5 = *(uint32_t *)(pcVar9 + uVar12);
  iVar15 = *(int *)(pcVar9 + (uVar12 | 4)) << 3;
  if (*(int *)(pcVar9 + (uVar12 | 4)) < 1) {
    iVar15 = 0;
  }
  iVar15 = (int)uVar12 + iVar15;
  uVar12 = (unsigned long)*(uint32_t *)(pcVar9 + (iVar15 + 0x14));
  uVar6 = *(uint32_t *)(pcVar9 + (iVar15 + 0x10));
  iVar14 = iVar15 + 0x18;
  if (0 < (int)*(uint32_t *)(pcVar9 + (iVar15 + 0x14))) {
    do {
      uVar12 = uVar12 - 1;
      iVar14 = iVar14 + *(int *)(pcVar9 + iVar14) + 4;
    } while (uVar12 != 0);
  }
  uVar12 = (unsigned long)*(uint32_t *)(pcVar9 + iVar14);
  uVar8 = *(uint32_t *)((long)(pcVar9 + iVar14) + 4);
  uVar16 = (unsigned long)uVar8;
  iVar14 = iVar14 + 8;
  if (0 < (int)uVar8) {
    do {
      uVar16 = uVar16 - 1;
      iVar14 = iVar14 + *(int *)(pcVar9 + iVar14) + 4;
    } while (uVar16 != 0);
  }
  uStack_7c = *(uint32_t *)(pcVar9 + (iVar15 + 8));
  local_80 = *(uint32_t *)(pcVar9 + (iVar15 + 0xc));
  uVar16 = (unsigned long)*(uint32_t *)(pcVar9 + iVar14);
  local_90 = VkObject_fromId(lVar10);
  puVar17 = (uint64_t *)((long)alStack_b0 - ((unsigned long)uVar5 * 8 + 0xf & 0xffffffff0));
  lVar19 = (long)puVar17 - ((unsigned long)uVar6 * 0x18 + 0xf & 0x3ffffffff0);
  local_70 = lVar19 - (uVar12 * 0x38 + 0xf & 0x7ffffffff0);
  lVar10 = local_70 - (uVar16 * 0x48 + 0xf & 0xfffffffff0);
  pcVar9 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*pcVar9 == '\0') {
    uVar8 = 1;
  }
  uVar20 = (unsigned long)*(uint32_t *)(pcVar9 + (unsigned long)uVar8 + 4);
  uVar18 = (unsigned long)(uVar8 + 8);
  alStack_b0[1] = lVar10;
  local_98 = puVar17;
  local_88 = uVar16;
  if (0 < (int)*(uint32_t *)(pcVar9 + (unsigned long)uVar8 + 4)) {
    do {
      uVar7 = VkObject_fromId(*(uint64_t *)(pcVar9 + uVar18));
      *puVar17 = uVar7;
      uVar20 = uVar20 - 1;
      uVar18 = uVar18 + 8;
      puVar17 = puVar17 + 1;
    } while (uVar20 != 0);
  }
  uVar16 = (unsigned long)*(uint32_t *)(pcVar9 + (long)(int)uVar18 + 0xc);
  iVar15 = (int)uVar18 + 0x10;
  if (0 < (int)*(uint32_t *)(pcVar9 + (long)(int)uVar18 + 0xc)) {
    puVar13 = (uint32_t *)(lVar19 + 0x10);
    do {
      lVar21 = (long)iVar15 + 4;
      pcVar2 = pcVar9 + lVar21;
      uVar3 = *(uint32_t *)pcVar2;
      uVar4 = *(uint32_t *)(pcVar2 + 4);
      iVar15 = *(int *)(pcVar9 + iVar15);
      uVar16 = uVar16 - 1;
      *(uint64_t *)(puVar13 + -2) = 0;
      *puVar13 = uVar4;
      uVar4 = *(uint32_t *)(pcVar2 + 8);
      iVar15 = iVar15 + (int)lVar21;
      puVar13[-4] = uVar3;
      puVar13[1] = uVar4;
      puVar13 = puVar13 + 6;
    } while (uVar16 != 0);
  }
  uVar16 = (unsigned long)*(uint32_t *)(pcVar9 + (long)iVar15 + 4);
  iVar14 = iVar15 + 8;
  local_a0 = lVar19;
  if (0 < (int)*(uint32_t *)(pcVar9 + (long)iVar15 + 4)) {
    puVar13 = (uint32_t *)(local_70 + 0x18);
    do {
      lVar19 = (long)iVar14 + 4;
      pcVar2 = pcVar9 + lVar19;
      uVar3 = *(uint32_t *)pcVar2;
      uVar4 = *(uint32_t *)(pcVar2 + 4);
      iVar14 = *(int *)(pcVar9 + iVar14);
      uVar7 = *(uint64_t *)(pcVar2 + 0x14);
      *(uint64_t *)(puVar13 + -4) = 0;
      puVar13[-2] = uVar4;
      uVar4 = *(uint32_t *)(pcVar2 + 8);
      puVar13[-6] = uVar3;
      puVar13[-1] = uVar4;
      *puVar13 = *(uint32_t *)(pcVar2 + 0xc);
      puVar13[1] = *(uint32_t *)(pcVar2 + 0x10);
      uVar7 = VkObject_fromId(uVar7);
      uVar11 = *(uint64_t *)(pcVar2 + 0x1c);
      *(uint64_t *)(puVar13 + 2) = uVar7;
      uVar16 = uVar16 - 1;
      *(uint64_t *)(puVar13 + 4) = uVar11;
      iVar14 = iVar14 + (int)lVar19;
      *(uint64_t *)(puVar13 + 6) = *(uint64_t *)(pcVar2 + 0x24);
      puVar13 = puVar13 + 0xe;
    } while (uVar16 != 0);
  }
  lVar19 = alStack_b0[1];
  uVar16 = (unsigned long)*(uint32_t *)(pcVar9 + (long)iVar14 + 4);
  if (0 < (int)*(uint32_t *)(pcVar9 + (long)iVar14 + 4)) {
    iVar14 = iVar14 + 8;
    lVar21 = alStack_b0[1];
    do {
      iVar15 = *(int *)(pcVar9 + iVar14);
      lVar1 = (long)iVar14 + 4;
      FUN_0014eed0(lVar21,pcVar9 + lVar1,param_1 + 0x40);
      iVar14 = iVar15 + (int)lVar1;
      uVar16 = uVar16 - 1;
      lVar21 = lVar21 + 0x48;
    } while (uVar16 != 0);
  }
  uVar4 = uStack_7c;
  uVar3 = local_80;
  uVar7 = local_90;
  puVar17 = local_98;
  lVar21 = local_a0;
  *(int *)(lVar10 + -0x18) = (int)local_88;
  lVar1 = local_70;
  *(long *)(lVar10 + -0x10) = lVar19;
  *(long *)(lVar10 + -0x20) = lVar1;
  ((generic_fn_t)DAT_00193ec8)(uVar7,(unsigned long)uVar5,puVar17,uVar4,uVar3,(unsigned long)uVar6,lVar21,uVar12);
  if (*(long *)(local_78 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0014a950  size=360 */

void vt_handle_vkCmdWaitEvents2(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  uint32_t uVar6;
  int iVar7;
  char *pcVar8;
  long lVar9;
  unsigned long uVar10;
  unsigned long uVar11;
  uint64_t *puVar12;
  unsigned long uVar13;
  uint64_t *puVar14;
  uint64_t *local_70;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar2 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar9 = 1;
    lVar3 = param_1;
  }
  else {
    lVar9 = 9;
    lVar3 = *(long *)(pcVar8 + 1);
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar8 + lVar9);
  uVar4 = VkObject_fromId(lVar3);
  puVar14 = (uint64_t *)((long)&local_70 - (uVar10 * 8 + 0xf & 0xffffffff0));
  local_70 = puVar14 + uVar10 * -8;
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar6 = 9;
  if (*pcVar8 == '\0') {
    uVar6 = 1;
  }
  uVar13 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar6 + 4);
  uVar11 = (unsigned long)(uVar6 + 8);
  puVar12 = puVar14;
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)uVar6 + 4)) {
    do {
      uVar5 = VkObject_fromId(*(uint64_t *)(pcVar8 + uVar11));
      *puVar12 = uVar5;
      uVar13 = uVar13 - 1;
      uVar11 = uVar11 + 8;
      puVar12 = puVar12 + 1;
    } while (uVar13 != 0);
  }
  uVar13 = (unsigned long)*(uint32_t *)(pcVar8 + (int)uVar11);
  if (0 < (int)*(uint32_t *)(pcVar8 + (int)uVar11)) {
    iVar7 = (int)uVar11 + 4;
    puVar12 = local_70;
    do {
      iVar1 = *(int *)(pcVar8 + iVar7);
      lVar3 = (long)iVar7 + 4;
      FUN_0014fa0c(puVar12,pcVar8 + lVar3,param_1 + 0x40);
      iVar7 = iVar1 + (int)lVar3;
      uVar13 = uVar13 - 1;
      puVar12 = puVar12 + 8;
    } while (uVar13 != 0);
  }
  ((generic_fn_t)DAT_001942c0)(uVar4,uVar10,puVar14,local_70);
  if (*(long *)(lVar2 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0013b234  size=144 */

void vt_handle_vkCmdWriteTimestamp(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  unsigned long uVar6;
  unsigned long uVar7;
  uint64_t unaff_x20;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    uVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    uVar6 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar5 + uVar6);
  uVar7 = uVar6 + 5;
  if (pcVar5[uVar6 | 4] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar5 + uVar7);
    uVar7 = (unsigned long)((int)uVar6 + 0xd);
  }
  uVar2 = *(uint32_t *)(pcVar5 + uVar7);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x20);
                    /* WARNING: Could not recover jumptable at 0x0013b2c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193f00)(uVar3,uVar1,uVar4,uVar2);
  return;
}


/* @0014aff4  size=144 */

void vt_handle_vkCmdWriteTimestamp2(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t uVar7;
  uint64_t unaff_x20;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar7 = *(uint64_t *)(pcVar4 + lVar5);
  uVar6 = lVar5 + 9;
  if ((pcVar4 + lVar5)[8] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 0x11);
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar6);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x20);
                    /* WARNING: Could not recover jumptable at 0x0014b080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_001942d8)(uVar2,uVar7,uVar3,uVar1);
  return;
}


/* @00133f5c  size=328 */

void vt_handle_vkCreateBuffer(long param_1)

{
  int iVar1;
  long lVar2;
  uint64_t uVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint64_t local_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t uStack_70;
  uint64_t uStack_68;
  uint64_t local_60;
  uint32_t local_50;
  uint32_t uStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  local_60 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_88 = 0;
  local_90 = 0;
  if (*pcVar6 == '\0') {
    lVar7 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar6 + 1);
    lVar7 = 9;
  }
  if (0 < *(int *)(pcVar6 + lVar7)) {
    FUN_0014de24(&local_90,pcVar6 + ((uint32_t)lVar7 | 4),param_1 + 0x40);
  }
  uVar3 = VkObject_fromId(unaff_x20);
  local_50 = ((generic_fn_t)DAT_00193c70)(uVar3,&local_90,0,&local_98);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar4 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 8;
  }
  else {
    puVar4 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar4);
  }
  *puVar4 = 0;
  *puVar4 = local_98;
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  uStack_4c = 8;
  uVar5 = RingBuffer_write(uVar3,&local_50,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar3,puVar4,8);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013413c  size=364 */

void vt_handle_vkCreateBufferView(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t *puVar5;
  char *pcVar6;
  unsigned long uVar7;
  uint64_t unaff_x20;
  uint64_t local_88;
  unsigned long local_80 [4];
  uint64_t local_60;
  uint64_t local_58;
  uint64_t local_50;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  local_50 = 0;
  local_80[3] = 0;
  local_80[2] = 0;
  local_58 = 0;
  local_60 = 0;
  local_80[1] = 0;
  local_80[0] = 0;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar6 + 1);
    uVar7 = 9;
  }
  if (0 < *(int *)(pcVar6 + uVar7)) {
    puVar1 = (uint32_t *)(pcVar6 + (uVar7 | 4));
    local_80[1] = 0;
    local_80[0] = (unsigned long)*puVar1;
    local_80[2] = (unsigned long)puVar1[1];
    local_80[3] = VkObject_fromId(*(uint64_t *)(puVar1 + 2));
    local_60 = ((uint64_t)((*(uint32_t*)((char*)&local_60 + 4))) << 32 | (uint32_t)(puVar1[4]));
    local_58 = *(uint64_t *)(puVar1 + 5);
    local_50 = *(uint64_t *)(puVar1 + 7);
  }
  uVar4 = VkObject_fromId(unaff_x20);
  local_40 = ((generic_fn_t)DAT_00193c80)(uVar4,local_80,0,&local_88);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 8;
  }
  else {
    puVar5 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar5);
  }
  *puVar5 = 0;
  *puVar5 = local_88;
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  uStack_3c = 8;
  uVar7 = RingBuffer_write(uVar4,&local_40,8);
  if ((uVar7 & 1) != 0) {
    RingBuffer_write(uVar4,puVar5,8);
  }
  if (*(long *)(lVar3 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00137d8c  size=324 */

void vt_handle_vkCreateCommandPool(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t *puVar5;
  char *pcVar6;
  unsigned long uVar7;
  uint64_t local_60;
  unsigned long local_58 [3];
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  local_58[0] = 0;
  local_58[2] = 0;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
    lVar3 = param_1;
  }
  else {
    uVar7 = 9;
    lVar3 = *(long *)(pcVar6 + 1);
  }
  if (0 < *(int *)(pcVar6 + uVar7)) {
    local_58[0] = (unsigned long)*(uint32_t *)(pcVar6 + (uVar7 | 4));
    local_58[2] = *(unsigned long *)((long)(pcVar6 + (uVar7 | 4)) + 4);
  }
  local_58[1] = 0;
  uVar4 = VkObject_fromId(lVar3);
  local_40 = ((generic_fn_t)DAT_00193d88)(uVar4,local_58,0,&local_60);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 8;
  }
  else {
    puVar5 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar5);
  }
  *puVar5 = 0;
  *puVar5 = local_60;
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  uStack_3c = 8;
  uVar7 = RingBuffer_write(uVar4,&local_40,8);
  if ((uVar7 & 1) != 0) {
    RingBuffer_write(uVar4,puVar5,8);
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001352c0  size=8 */

void vt_handle_vkCreateComputePipelines(uint64_t param_1)

{
  AsyncPipelineCreator_create(param_1,1);
  return;
}


/* @00135e50  size=924 */

void vt_handle_vkCreateDescriptorPool(long param_1)

{
  long lVar1;
  int iVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint64_t *puVar8;
  void *__s;
  uint64_t uVar9;
  unsigned long uVar10;
  char *pcVar11;
  uint32_t *puVar12;
  uint64_t *puVar13;
  int iVar14;
  uint64_t local_a8;
  unsigned long local_a0;
  uint64_t *puStack_98;
  uint64_t local_90;
  uint64_t local_88;
  void *local_80;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar6 + 0x28);
  pcVar11 = *(char **)(param_1 + 0x30);
  local_80 = (void *)0x0;
  puStack_98 = (uint64_t *)0x0;
  local_a0 = 0;
  local_88 = 0;
  local_90 = 0;
  if (*pcVar11 == '\0') {
    uVar10 = 1;
    lVar7 = param_1;
  }
  else {
    uVar10 = 9;
    lVar7 = *(long *)(pcVar11 + 1);
  }
  if (0 < *(int *)(pcVar11 + uVar10)) {
    puVar3 = (uint32_t *)(pcVar11 + (uVar10 | 4));
    puVar12 = puVar3 + 1;
    puVar13 = (uint64_t *)0x0;
    iVar14 = 8;
    local_a0 = (unsigned long)*puVar3;
    do {
      uVar4 = *puVar12;
      if (uVar4 == 0x3b9ce513) {
        iVar2 = *(int *)((long)puVar3 + (long)iVar14);
        uVar10 = (long)iVar14 + 4;
        if (iVar2 < 1) {
          uVar10 = uVar10 & 0xffffffff;
        }
        else {
          iVar14 = *(int *)(param_1 + 0x48);
          if ((iVar14 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar14);
            *(int *)(param_1 + 0x48) = iVar14 + 0x18;
          }
          else {
            puVar8 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          *puVar8 = 0;
          puVar8[1] = 0;
          puVar8[2] = 0;
          uVar4 = iVar2 + (int)uVar10;
          *(uint32_t *)puVar8 = *(uint32_t *)((long)puVar3 + uVar10);
          *(uint32_t *)(puVar8 + 2) = ((uint32_t *)((long)puVar3 + uVar10))[1];
LAB_00135f28:
          uVar10 = (unsigned long)uVar4;
          puVar8[1] = puVar13;
          puVar13 = puVar8;
        }
      }
      else if (uVar4 == 0x3ba0251a) {
        iVar2 = *(int *)((long)puVar3 + (long)iVar14);
        uVar10 = (long)iVar14 + 4;
        if (0 < iVar2) {
          iVar14 = *(int *)(param_1 + 0x48);
          if ((iVar14 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar14);
            *(int *)(param_1 + 0x48) = iVar14 + 0x20;
          }
          else {
            puVar8 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          puVar8[1] = 0;
          *puVar8 = 0;
          puVar8[3] = 0;
          puVar8[2] = 0;
          FUN_0014e92c(puVar8,(long)puVar3 + uVar10,param_1 + 0x40);
          uVar4 = iVar2 + (int)uVar10;
          goto LAB_00135f28;
        }
      }
      else {
        if (uVar4 == 0xffffffff) goto LAB_00136018;
        uVar10 = (unsigned long)(iVar14 + 4);
      }
      puVar12 = (uint32_t *)((long)puVar3 + (long)(int)uVar10);
      iVar14 = (int)uVar10 + 4;
    } while( true );
  }
LAB_00136114:
  uVar9 = VkObject_fromId(lVar7);
  local_70 = ((generic_fn_t)DAT_00193d30)(uVar9,&local_a0,0,&local_a8);
  iVar14 = *(int *)(param_1 + 0x48);
  if ((iVar14 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar13 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar14);
    *(int *)(param_1 + 0x48) = iVar14 + 8;
  }
  else {
    puVar13 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar13);
  }
  *puVar13 = 0;
  *puVar13 = local_a8;
  uVar9 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar10 = RingBuffer_write(uVar9,&local_70,8);
  if ((uVar10 & 1) != 0) {
    RingBuffer_write(uVar9,puVar13,8);
  }
  if (*(long *)(lVar6 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00136018:
  if (puVar13 == (uint64_t *)0x0) {
    puStack_98 = (uint64_t *)0x0;
  }
  else {
    puVar8 = (uint64_t *)0x0;
    do {
      puStack_98 = puVar13;
      puVar13 = (uint64_t *)puStack_98[1];
      puStack_98[1] = puVar8;
      puVar8 = puStack_98;
    } while (puVar13 != (uint64_t *)0x0);
  }
  puVar13 = (uint64_t *)((long)puVar3 + (long)iVar14);
  local_90 = *puVar13;
  local_88 = ((uint64_t)((*(uint32_t*)((char*)&local_88 + 4))) << 32 | (uint32_t)(*(uint32_t *)(puVar13 + 1)));
  uVar4 = *(uint32_t *)((long)puVar13 + 0xc);
  if ((int)uVar4 < 1) {
    local_80 = (void *)0x0;
  }
  else {
    iVar5 = uVar4 * 8;
    iVar14 = iVar14 + 0x10;
    iVar2 = *(int *)(param_1 + 0x48) + iVar5;
    if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar2;
    }
    else {
      __s = malloc((long)iVar5);
      ArrayList_add(param_1 + 0x50,__s);
    }
    memset(__s,0,(long)iVar5);
    uVar10 = 0;
    do {
      iVar2 = *(int *)((long)puVar3 + (long)iVar14);
      lVar1 = (long)iVar14 + 4;
      if (__s != (void *)0x0) {
        *(uint64_t *)((long)__s + uVar10 * 8) = *(uint64_t *)((long)puVar3 + lVar1);
      }
      uVar10 = uVar10 + 1;
      iVar14 = iVar2 + (int)lVar1;
      local_80 = __s;
    } while (uVar4 != uVar10);
  }
  goto LAB_00136114;
}


/* @00135c9c  size=320 */

void vt_handle_vkCreateDescriptorSetLayout(long param_1)

{
  int iVar1;
  long lVar2;
  uint64_t uVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint64_t local_78;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t uStack_60;
  uint64_t uStack_58;
  uint32_t local_50;
  uint32_t uStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  if (*pcVar6 == '\0') {
    lVar7 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar6 + 1);
    lVar7 = 9;
  }
  if (0 < *(int *)(pcVar6 + lVar7)) {
    FUN_0014e534(&local_70,pcVar6 + ((uint32_t)lVar7 | 4),param_1 + 0x40);
  }
  uVar3 = VkObject_fromId(unaff_x20);
  local_50 = ((generic_fn_t)DAT_00193d20)(uVar3,&local_70,0,&local_78);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar4 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 8;
  }
  else {
    puVar4 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar4);
  }
  *puVar4 = 0;
  *puVar4 = local_78;
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  uStack_4c = 8;
  uVar5 = RingBuffer_write(uVar3,&local_50,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar3,puVar4,8);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012f6c0  size=428 */

void vt_handle_vkCreateDevice(long param_1)

{
  /* STUB: vt_handle_vkCreateDevice — Ghidra artifacts */
}


/* @001336cc  size=316 */

void vt_handle_vkCreateEvent(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t *puVar5;
  char *pcVar6;
  unsigned long uVar7;
  uint64_t local_60;
  unsigned long local_58 [3];
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  local_58[0] = 0;
  local_58[2] = 0;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
    lVar3 = param_1;
  }
  else {
    uVar7 = 9;
    lVar3 = *(long *)(pcVar6 + 1);
  }
  if (0 < *(int *)(pcVar6 + uVar7)) {
    local_58[0] = (unsigned long)*(uint32_t *)(pcVar6 + (uVar7 | 4));
    local_58[2] = (unsigned long)*(uint32_t *)((long)(pcVar6 + (uVar7 | 4)) + 4);
  }
  local_58[1] = 0;
  uVar4 = VkObject_fromId(lVar3);
  local_40 = ((generic_fn_t)DAT_00193c28)(uVar4,local_58,0,&local_60);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 8;
  }
  else {
    puVar5 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar5);
  }
  *puVar5 = 0;
  *puVar5 = local_60;
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  uStack_3c = 8;
  uVar7 = RingBuffer_write(uVar4,&local_40,8);
  if ((uVar7 & 1) != 0) {
    RingBuffer_write(uVar4,puVar5,8);
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00132c3c  size=604 */

void vt_handle_vkCreateFence(long param_1)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  int iVar4;
  long lVar5;
  uint64_t uVar6;
  int iVar7;
  char *pcVar8;
  unsigned long uVar9;
  uint32_t *puVar10;
  uint64_t *puVar11;
  uint64_t unaff_x20;
  uint64_t *puVar12;
  uint64_t *puVar13;
  uint64_t local_a8;
  uint64_t local_a0;
  uint64_t *puStack_98;
  uint64_t local_90;
  unsigned long local_88;
  uint64_t *local_80;
  uint64_t local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar5 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  local_88 = 0;
  local_80 = (uint64_t *)0x0;
  local_78 = 0;
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar8 + 1);
    uVar9 = 9;
  }
  if (0 < *(int *)(pcVar8 + uVar9)) {
    puVar1 = (uint32_t *)(pcVar8 + (uVar9 | 4));
    puVar10 = puVar1 + 1;
    iVar7 = 8;
    local_88 = (unsigned long)*puVar1;
    puVar13 = (uint64_t *)0x0;
    do {
      puVar12 = puVar13;
      if (*puVar10 == 0x3b9c8368) {
        iVar4 = *(int *)((long)puVar1 + (long)iVar7);
        uVar9 = (long)iVar7 + 4;
        if (0 < iVar4) {
          iVar7 = *(int *)(param_1 + 0x48);
          if ((iVar7 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar12 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar7);
            *(int *)(param_1 + 0x48) = iVar7 + 0x18;
          }
          else {
            puVar12 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar12);
          }
          *puVar12 = 0;
          puVar12[1] = 0;
          puVar12[2] = 0;
          puVar2 = (uint32_t *)((long)puVar1 + uVar9);
          uVar9 = (unsigned long)(uint32_t)(iVar4 + (int)uVar9);
          *(uint32_t *)puVar12 = *puVar2;
          uVar3 = puVar2[1];
          puVar12[1] = puVar13;
          *(uint32_t *)(puVar12 + 2) = uVar3;
        }
      }
      else {
        if (*puVar10 == 0xffffffff) goto LAB_00132d68;
        uVar9 = (unsigned long)(iVar7 + 4);
      }
      puVar10 = (uint32_t *)((long)puVar1 + (long)(int)uVar9);
      iVar7 = (int)uVar9 + 4;
      puVar13 = puVar12;
    } while( true );
  }
  puVar12 = (uint64_t *)0x0;
LAB_00132d9c:
  uVar6 = VkObject_fromId(unaff_x20);
  local_a0 = 0x3b9c8368;
  local_90 = 8;
  local_80 = &local_a0;
  puStack_98 = puVar12;
  local_70 = ((generic_fn_t)DAT_00193bf0)(uVar6,&local_88,0,&local_a8);
  iVar7 = *(int *)(param_1 + 0x48);
  if ((iVar7 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar13 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar7);
    *(int *)(param_1 + 0x48) = iVar7 + 8;
  }
  else {
    puVar13 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar13);
  }
  *puVar13 = 0;
  *puVar13 = local_a8;
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar9 = RingBuffer_write(uVar6,&local_70,8);
  if ((uVar9 & 1) != 0) {
    RingBuffer_write(uVar6,puVar13,8);
  }
  if (*(long *)(lVar5 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00132d68:
  if (puVar13 == (uint64_t *)0x0) {
    puVar12 = (uint64_t *)0x0;
  }
  else {
    puVar11 = (uint64_t *)0x0;
    do {
      puVar12 = puVar13;
      puVar13 = (uint64_t *)puVar12[1];
      puVar12[1] = puVar11;
      puVar11 = puVar12;
    } while (puVar13 != (uint64_t *)0x0);
  }
  local_78 = ((uint64_t)((*(uint32_t*)((char*)&local_78 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar1 + (long)iVar7)));
  goto LAB_00132d9c;
}


/* @00136a58  size=1272 */

void vt_handle_vkCreateFramebuffer(long param_1)

{
  long lVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  uint64_t *puVar10;
  void *__s;
  void *pvVar11;
  uint64_t uVar12;
  unsigned long uVar13;
  uint32_t *puVar14;
  uint64_t *puVar15;
  int iVar16;
  int iVar17;
  unsigned long uVar18;
  size_t __size;
  char *pcVar19;
  uint64_t *puVar20;
  unsigned long uVar21;
  uint64_t local_b8;
  unsigned long local_b0;
  uint64_t *puStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  void *pvStack_88;
  uint64_t local_80;
  uint64_t local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar8 + 0x28);
  pcVar19 = *(char **)(param_1 + 0x30);
  pvStack_88 = (void *)0x0;
  local_90 = 0;
  local_78 = 0;
  local_80 = 0;
  puStack_a8 = (uint64_t *)0x0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  if (*pcVar19 == '\0') {
    uVar13 = 1;
    lVar9 = param_1;
  }
  else {
    uVar13 = 9;
    lVar9 = *(long *)(pcVar19 + 1);
  }
  if (0 < *(int *)(pcVar19 + uVar13)) {
    uVar13 = uVar13 | 4;
    puVar14 = (uint32_t *)((long)(pcVar19 + uVar13) + 4);
    puVar15 = (uint64_t *)0x0;
    iVar16 = 8;
    local_b0 = (unsigned long)*(uint32_t *)(pcVar19 + uVar13);
    do {
      if (*puVar14 == 0x3b9c6fe1) {
        iVar3 = *(int *)(pcVar19 + (long)iVar16 + uVar13);
        uVar18 = (long)iVar16 + 4;
        if (iVar3 < 1) goto LAB_00136af8;
        iVar16 = *(int *)(param_1 + 0x48);
        if ((iVar16 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
          puVar10 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar16);
          *(int *)(param_1 + 0x48) = iVar16 + 0x20;
        }
        else {
          puVar10 = malloc(0x20);
          ArrayList_add(param_1 + 0x50,puVar10);
        }
        puVar10[1] = 0;
        *puVar10 = 0;
        puVar10[3] = 0;
        puVar10[2] = 0;
        pcVar2 = pcVar19 + uVar18 + uVar13;
        uVar5 = *(uint32_t *)pcVar2;
        puVar10[1] = 0;
        *(uint32_t *)puVar10 = uVar5;
        *(uint32_t *)(puVar10 + 2) = *(uint32_t *)(pcVar2 + 4);
        uVar6 = *(uint32_t *)(pcVar2 + 8);
        uVar21 = (unsigned long)uVar6;
        if ((int)uVar6 < 1) {
          puVar10[3] = 0;
        }
        else {
          iVar7 = uVar6 * 0x30;
          iVar16 = *(int *)(param_1 + 0x48) + iVar7;
          if ((iVar16 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar11 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar16;
          }
          else {
            pvVar11 = malloc((long)iVar7);
            ArrayList_add(param_1 + 0x50,pvVar11);
          }
          memset(pvVar11,0,(long)iVar7);
          puVar20 = (uint64_t *)((long)pvVar11 + 0x28);
          iVar16 = 0xc;
          do {
            iVar7 = *(int *)(pcVar2 + iVar16);
            lVar1 = (long)iVar16 + 4;
            if (pvVar11 != (void *)0x0) {
              pcVar4 = pcVar2 + lVar1;
              uVar5 = *(uint32_t *)pcVar4;
              puVar20[-4] = 0;
              *(uint32_t *)(puVar20 + -5) = uVar5;
              *(uint32_t *)(puVar20 + -3) = *(uint32_t *)(pcVar4 + 4);
              *(uint32_t *)((long)puVar20 + -0x14) = *(uint32_t *)(pcVar4 + 8);
              *(uint32_t *)(puVar20 + -2) = *(uint32_t *)(pcVar4 + 0xc);
              *(uint32_t *)((long)puVar20 + -0xc) = *(uint32_t *)(pcVar4 + 0x10);
              *(uint32_t *)(puVar20 + -1) = *(uint32_t *)(pcVar4 + 0x14);
              *(uint32_t *)((long)puVar20 + -4) = *(uint32_t *)(pcVar4 + 0x18);
              if (*(int *)(pcVar4 + 0x1c) < 1) {
                *puVar20 = 0;
              }
              else {
                __size = (long)*(int *)(pcVar4 + 0x1c) << 2;
                iVar17 = (int)__size;
                iVar16 = *(int *)(param_1 + 0x48) + iVar17;
                if ((iVar16 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
                  __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
                  __size = (size_t)iVar17;
                  *(int *)(param_1 + 0x48) = iVar16;
                }
                else {
                  __s = malloc(__size);
                  ArrayList_add(param_1 + 0x50,__s);
                }
                memset(__s,0,__size);
                if (__s != (void *)0x0) {
                  memcpy(__s,pcVar4 + 0x20,(long)iVar17);
                }
                *puVar20 = __s;
              }
            }
            iVar16 = iVar7 + (int)lVar1;
            uVar21 = uVar21 - 1;
            puVar20 = puVar20 + 6;
          } while (uVar21 != 0);
          puVar10[3] = pvVar11;
        }
        iVar16 = iVar3 + (int)uVar18;
        puVar10[1] = puVar15;
        puVar15 = puVar10;
      }
      else {
        if (*puVar14 == 0xffffffff) goto LAB_00136d4c;
        uVar18 = (unsigned long)(iVar16 + 4);
LAB_00136af8:
        iVar16 = (int)uVar18;
      }
      puVar14 = (uint32_t *)(pcVar19 + (long)iVar16 + uVar13);
      iVar16 = iVar16 + 4;
    } while( true );
  }
LAB_00136e6c:
  uVar12 = VkObject_fromId(lVar9);
  local_70 = ((generic_fn_t)DAT_00193d60)(uVar12,&local_b0,0,&local_b8);
  iVar16 = *(int *)(param_1 + 0x48);
  if ((iVar16 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar15 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar16);
    *(int *)(param_1 + 0x48) = iVar16 + 8;
  }
  else {
    puVar15 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar15);
  }
  *puVar15 = 0;
  *puVar15 = local_b8;
  uVar12 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar13 = RingBuffer_write(uVar12,&local_70,8);
  if ((uVar13 & 1) != 0) {
    RingBuffer_write(uVar12,puVar15,8);
  }
  if (*(long *)(lVar8 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00136d4c:
  if (puVar15 == (uint64_t *)0x0) {
    puStack_a8 = (uint64_t *)0x0;
  }
  else {
    puVar10 = (uint64_t *)0x0;
    do {
      puStack_a8 = puVar15;
      puVar15 = (uint64_t *)puStack_a8[1];
      puStack_a8[1] = puVar10;
      puVar10 = puStack_a8;
    } while (puVar15 != (uint64_t *)0x0);
  }
  pcVar2 = pcVar19 + (long)iVar16 + uVar13;
  local_a0 = ((uint64_t)((*(uint32_t*)((char*)&local_a0 + 4))) << 32 | (uint32_t)(*(uint32_t *)pcVar2));
  local_98 = VkObject_fromId(*(uint64_t *)(pcVar2 + 4));
  iVar16 = iVar16 + 0x14;
  local_90 = ((uint64_t)((*(uint32_t*)((char*)&local_90 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar2 + 0xc)));
  uVar6 = *(uint32_t *)(pcVar2 + 0x10);
  if ((int)uVar6 < 1) {
    pvStack_88 = (void *)0x0;
    pvVar11 = pvStack_88;
  }
  else {
    iVar7 = uVar6 * 8;
    iVar3 = *(int *)(param_1 + 0x48) + iVar7;
    if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar11 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar3;
    }
    else {
      pvVar11 = malloc((long)iVar7);
      ArrayList_add(param_1 + 0x50,pvVar11);
    }
    memset(pvVar11,0,(long)iVar7);
    uVar18 = 0;
    lVar1 = (long)iVar16;
    do {
      if (pvVar11 != (void *)0x0) {
        uVar12 = VkObject_fromId(*(uint64_t *)(pcVar19 + uVar18 * 8 + lVar1 + uVar13));
        *(uint64_t *)((long)pvVar11 + uVar18 * 8) = uVar12;
      }
      uVar18 = uVar18 + 1;
      iVar16 = iVar16 + 8;
    } while (uVar6 != uVar18);
  }
  pvStack_88 = pvVar11;
  local_80 = *(uint64_t *)(pcVar19 + (long)iVar16 + uVar13);
  local_78 = ((uint64_t)((*(uint32_t*)((char*)&local_78 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar19 + (long)iVar16 + uVar13 + 8)));
  goto LAB_00136e6c;
}


/* @001352b8  size=8 */

void vt_handle_vkCreateGraphicsPipelines(uint64_t param_1)

{
  AsyncPipelineCreator_create(param_1,0);
  return;
}


/* @0013431c  size=396 */

void vt_handle_vkCreateImage(long param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  uint64_t uVar4;
  unsigned long uVar5;
  uint64_t *puVar6;
  char *pcVar7;
  long lVar8;
  uint64_t unaff_x20;
  uint64_t local_a8;
  uint64_t local_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  unsigned long uStack_88;
  uint64_t uStack_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t uStack_60;
  uint64_t uStack_58;
  uint64_t local_50;
  int local_40 [2];
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_50 = 0;
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  if (*pcVar7 == '\0') {
    lVar8 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar7 + 1);
    lVar8 = 9;
  }
  if (0 < *(int *)(pcVar7 + lVar8)) {
    FUN_0014e09c(&local_a0,pcVar7 + ((uint32_t)lVar8 | 4),param_1 + 0x40);
  }
  uVar4 = VkObject_fromId(unaff_x20);
  if ((*(long *)(param_1 + 0x80) == 0) ||
     (uVar5 = isCompressedFormat(uStack_88 & 0xffffffff), (uVar5 & 1) == 0)) {
    iVar3 = ((generic_fn_t)DAT_00193c90)(uVar4,&local_a0,0,&local_a8);
  }
  else {
    iVar3 = TextureDecoder_createImage(*(uint64_t *)(param_1 + 0x80),uVar4,&local_a0,&local_a8);
    if (iVar3 == 0) {
      RingBuffer_setStatus(*(uint64_t *)(param_1 + 0x68),4);
    }
  }
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 8;
  }
  else {
    puVar6 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *puVar6 = 0;
  *puVar6 = local_a8;
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  local_40[1] = 8;
  local_40[0] = iVar3;
  uVar5 = RingBuffer_write(uVar4,local_40,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar4,puVar6,8);
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001346f8  size=876 */

void vt_handle_vkCreateImageView(long param_1)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint64_t *puVar7;
  uint64_t uVar8;
  int iVar9;
  char *pcVar10;
  unsigned long uVar11;
  uint32_t *puVar12;
  uint32_t uVar13;
  uint64_t *puVar14;
  uint64_t local_c8;
  unsigned long local_c0;
  uint64_t *puStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint32_t local_80;
  uint32_t local_7c;
  uint64_t local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar5 + 0x28);
  pcVar10 = *(char **)(param_1 + 0x30);
  uStack_88 = 0;
  local_90 = 0;
  local_78 = 0;
  local_80 = 0;
  local_7c = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  puStack_b8 = (uint64_t *)0x0;
  local_c0 = 0;
  if (*pcVar10 == '\0') {
    uVar11 = 1;
    lVar6 = param_1;
  }
  else {
    uVar11 = 9;
    lVar6 = *(long *)(pcVar10 + 1);
  }
  if (0 < *(int *)(pcVar10 + uVar11)) {
    puVar2 = (uint32_t *)(pcVar10 + (uVar11 | 4));
    puVar12 = puVar2 + 1;
    puVar14 = (uint64_t *)0x0;
    iVar9 = 8;
    local_c0 = (unsigned long)*puVar2;
    do {
      uVar3 = *puVar12;
      if (uVar3 == 0x3b9c930a) {
        iVar4 = *(int *)((long)puVar2 + (long)iVar9);
        uVar11 = (long)iVar9 + 4;
        if (0 < iVar4) {
          iVar9 = *(int *)(param_1 + 0x48);
          if ((iVar9 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar7 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar9);
            *(int *)(param_1 + 0x48) = iVar9 + 0x18;
          }
          else {
            puVar7 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar7);
          }
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7[2] = 0;
          uVar3 = iVar4 + (int)uVar11;
          *(uint32_t *)puVar7 = *(uint32_t *)((long)puVar2 + uVar11);
          *(uint32_t *)(puVar7 + 2) = ((uint32_t *)((long)puVar2 + uVar11))[1];
LAB_001347dc:
          uVar11 = (unsigned long)uVar3;
          puVar7[1] = puVar14;
          puVar14 = puVar7;
        }
      }
      else if (uVar3 == 0x3b9d2b61) {
        iVar4 = *(int *)((long)puVar2 + (long)iVar9);
        uVar11 = (long)iVar9 + 4;
        if (0 < iVar4) {
          iVar9 = *(int *)(param_1 + 0x48);
          if ((iVar9 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar7 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar9);
            *(int *)(param_1 + 0x48) = iVar9 + 0x18;
          }
          else {
            puVar7 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar7);
          }
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7[2] = 0;
          uVar13 = *(uint32_t *)((long)puVar2 + uVar11);
          puVar7[1] = 0;
          *(uint32_t *)puVar7 = uVar13;
          uVar8 = VkObject_fromId(*(uint64_t *)((uint32_t *)((long)puVar2 + uVar11) + 1));
          uVar3 = iVar4 + (int)uVar11;
          puVar7[2] = uVar8;
          goto LAB_001347dc;
        }
      }
      else {
        if (uVar3 == 0xffffffff) goto LAB_001348c0;
        uVar11 = (unsigned long)(iVar9 + 4);
      }
      puVar12 = (uint32_t *)((long)puVar2 + (long)(int)uVar11);
      iVar9 = (int)uVar11 + 4;
    } while( true );
  }
  uVar13 = 0;
LAB_00134964:
  uVar8 = VkObject_fromId(lVar6);
  if ((*(long *)(param_1 + 0x80) != 0) && (uVar11 = isCompressedFormat(uVar13), (uVar11 & 1) != 0))
  {
    local_a0 = ((uint64_t)(0x2c) << 32 | (uint32_t)((uint32_t)local_a0));
    local_80 = 1;
  }
  local_70 = ((generic_fn_t)DAT_00193ca8)(uVar8,&local_c0,0,&local_c8);
  iVar9 = *(int *)(param_1 + 0x48);
  if ((iVar9 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar14 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar9);
    *(int *)(param_1 + 0x48) = iVar9 + 8;
  }
  else {
    puVar14 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar14);
  }
  *puVar14 = 0;
  *puVar14 = local_c8;
  uVar8 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar11 = RingBuffer_write(uVar8,&local_70,8);
  if ((uVar11 & 1) != 0) {
    RingBuffer_write(uVar8,puVar14,8);
  }
  if (*(long *)(lVar5 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_001348c0:
  if (puVar14 == (uint64_t *)0x0) {
    puStack_b8 = (uint64_t *)0x0;
  }
  else {
    puVar7 = (uint64_t *)0x0;
    do {
      puStack_b8 = puVar14;
      puVar14 = (uint64_t *)puStack_b8[1];
      puStack_b8[1] = puVar7;
      puVar7 = puStack_b8;
    } while (puVar14 != (uint64_t *)0x0);
  }
  puVar1 = (uint32_t *)((long)puVar2 + (long)iVar9);
  local_b0 = ((uint64_t)((*(uint32_t*)((char*)&local_b0 + 4))) << 32 | (uint32_t)(*puVar1));
  uStack_a8 = VkObject_fromId(*(uint64_t *)(puVar1 + 1));
  uVar13 = puVar1[4];
  local_a0 = *(uint64_t *)(puVar1 + 3);
  local_98 = *(uint64_t *)(puVar1 + 5);
  local_90 = *(uint64_t *)(puVar1 + 7);
  uStack_88 = *(uint64_t *)(puVar1 + 9);
  local_80 = puVar1[0xb];
  local_7c = puVar1[0xc];
  local_78 = ((uint64_t)((*(uint32_t*)((char*)&local_78 + 4))) << 32 | (uint32_t)(puVar1[0xd]));
  goto LAB_00134964;
}


/* @0012e034  size=1316 */

void vt_handle_vkCreateInstance(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  void *pvVar8;
  uint64_t *puVar9;
  uint32_t uVar10;
  uint64_t uVar11;
  unsigned long uVar12;
  size_t sVar13;
  uint32_t *puVar14;
  int *piVar15;
  uint32_t uVar16;
  int *piVar17;
  uint64_t local_e8;
  unsigned long local_e0 [3];
  int *local_c8;
  uint64_t local_c0;
  void *pvStack_b8;
  uint64_t local_b0;
  void *local_a8;
  char *local_a0;
  char *pcStack_98;
  char *local_90;
  char *local_80;
  char *pcStack_78;
  int local_70 [2];
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  piVar17 = *(int **)(param_1 + 0x30);
  pvStack_b8 = (void *)0x0;
  local_c0 = 0;
  local_a8 = (void *)0x0;
  local_b0 = 0;
  local_e0[1] = 0;
  local_e0[0] = 0;
  local_c8 = (int *)0x0;
  local_e0[2] = 0;
  pvVar7 = local_a8;
  if (0 < *piVar17) {
    puVar14 = (uint32_t *)(piVar17 + 1);
    local_e0[1] = 0;
    local_e0[0] = (unsigned long)*puVar14;
    local_e0[2] = (unsigned long)(uint32_t)piVar17[2];
    iVar5 = piVar17[3];
    if (iVar5 < 1) {
      uVar10 = 0xc;
      local_c8 = (int *)0x0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x48);
      if ((iVar2 < 0xffd0) && (*(long *)(param_1 + 0x40) != 0)) {
        piVar6 = (int *)(*(long *)(param_1 + 0x40) + (long)iVar2);
        *(int *)(param_1 + 0x48) = iVar2 + 0x30;
      }
      else {
        piVar6 = malloc(0x30);
        ArrayList_add(param_1 + 0x50,piVar6);
      }
      piVar6[6] = 0;
      piVar6[7] = 0;
      piVar6[4] = 0;
      piVar6[5] = 0;
      piVar6[10] = 0;
      piVar6[0xb] = 0;
      piVar6[8] = 0;
      piVar6[9] = 0;
      piVar6[2] = 0;
      piVar6[3] = 0;
      piVar6[0] = 0;
      piVar6[1] = 0;
      piVar15 = piVar17 + 4;
      iVar2 = *piVar15;
      piVar6[2] = 0;
      piVar6[3] = 0;
      *piVar6 = iVar2;
      uVar10 = piVar17[5];
      uVar12 = (unsigned long)uVar10;
      local_c8 = piVar6;
      if ((int)uVar10 < 1) {
        uVar10 = 8;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x48) + uVar10;
        if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar7 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar2;
        }
        else {
          pvVar7 = malloc(uVar12);
          ArrayList_add(param_1 + 0x50,pvVar7);
        }
        memset(pvVar7,0,uVar12);
        memcpy(pvVar7,piVar17 + 6,uVar12);
        uVar10 = uVar10 + 8;
        *(void **)(piVar6 + 4) = pvVar7;
      }
      uVar16 = uVar10 + 8;
      piVar6[6] = *(int *)((long)piVar15 + (unsigned long)uVar10);
      uVar10 = ((int *)((long)piVar15 + (unsigned long)uVar10))[1];
      uVar12 = (unsigned long)uVar10;
      if (0 < (int)uVar10) {
        iVar2 = *(int *)(param_1 + 0x48) + uVar10;
        if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar7 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar2;
        }
        else {
          pvVar7 = malloc(uVar12);
          ArrayList_add(param_1 + 0x50,pvVar7);
        }
        memset(pvVar7,0,uVar12);
        memcpy(pvVar7,(void *)((long)piVar15 + (unsigned long)uVar16),uVar12);
        uVar16 = uVar10 + uVar16;
        *(void **)(piVar6 + 8) = pvVar7;
      }
      piVar6[10] = *(int *)((long)piVar15 + (unsigned long)uVar16);
      piVar6[0xb] = ((int *)((long)piVar15 + (unsigned long)uVar16))[1];
      uVar10 = iVar5 + 0xc;
    }
    iVar5 = uVar10 + 8;
    local_c0 = ((uint64_t)((*(uint32_t*)((char*)&local_c0 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar14 + (unsigned long)uVar10)));
    uVar10 = ((uint32_t *)((long)puVar14 + (unsigned long)uVar10))[1];
    if ((int)uVar10 < 1) {
      pvStack_b8 = (void *)0x0;
      pvVar7 = pvStack_b8;
    }
    else {
      iVar3 = uVar10 * 8;
      iVar2 = *(int *)(param_1 + 0x48) + iVar3;
      if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar7 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar2;
      }
      else {
        pvVar7 = malloc((long)iVar3);
        ArrayList_add(param_1 + 0x50,pvVar7);
      }
      memset(pvVar7,0,(long)iVar3);
      uVar12 = 0;
      do {
        iVar3 = *(int *)((long)puVar14 + (long)iVar5);
        sVar13 = (size_t)iVar3;
        iVar2 = *(int *)(param_1 + 0x48) + iVar3;
        if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar8 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar2;
        }
        else {
          pvVar8 = malloc(sVar13);
          ArrayList_add(param_1 + 0x50,pvVar8);
        }
        lVar1 = (long)iVar5 + 4;
        memset(pvVar8,0,sVar13);
        *(void **)((long)pvVar7 + uVar12 * 8) = pvVar8;
        memcpy(pvVar8,(void *)((long)puVar14 + lVar1),sVar13);
        uVar12 = uVar12 + 1;
        iVar5 = iVar3 + (int)lVar1;
      } while (uVar10 != uVar12);
    }
    pvStack_b8 = pvVar7;
    local_b0 = ((uint64_t)((*(uint32_t*)((char*)&local_b0 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar14 + (long)iVar5)));
    uVar10 = ((uint32_t *)((long)puVar14 + (long)iVar5))[1];
    if ((int)uVar10 < 1) {
      local_a8 = (void *)0x0;
      pvVar7 = local_a8;
    }
    else {
      iVar3 = uVar10 * 8;
      iVar5 = iVar5 + 8;
      iVar2 = *(int *)(param_1 + 0x48) + iVar3;
      if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar7 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar2;
      }
      else {
        pvVar7 = malloc((long)iVar3);
        ArrayList_add(param_1 + 0x50,pvVar7);
      }
      memset(pvVar7,0,(long)iVar3);
      uVar12 = 0;
      do {
        iVar3 = *(int *)((long)puVar14 + (long)iVar5);
        sVar13 = (size_t)iVar3;
        iVar2 = *(int *)(param_1 + 0x48) + iVar3;
        if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar8 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar2;
        }
        else {
          pvVar8 = malloc(sVar13);
          ArrayList_add(param_1 + 0x50,pvVar8);
        }
        lVar1 = (long)iVar5 + 4;
        memset(pvVar8,0,sVar13);
        *(void **)((long)pvVar7 + uVar12 * 8) = pvVar8;
        memcpy(pvVar8,(void *)((long)puVar14 + lVar1),sVar13);
        uVar12 = uVar12 + 1;
        iVar5 = iVar3 + (int)lVar1;
      } while (uVar10 != uVar12);
    }
  }
  local_a8 = pvVar7;
  local_90 = "VK_KHR_external_fence_capabilities";
  pcStack_78 = "VK_KHR_xlib_surface";
  local_80 = "VK_KHR_surface";
  pcStack_98 = "VK_KHR_external_memory_capabilities";
  local_a0 = "VK_KHR_get_physical_device_properties2";
  injectExtensions(param_1,&local_a8,&local_b0,&local_a0,3,&local_80,2);
  iVar5 = ((generic_fn_t)DAT_00193af0)(local_e0,0,&local_e8);
  if (iVar5 == 0) {
    initVulkanInstance(param_1,local_e8,local_c8);
  }
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar9 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 8;
  }
  else {
    puVar9 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar9);
  }
  *puVar9 = 0;
  *puVar9 = local_e8;
  uVar11 = *(uint64_t *)(param_1 + 0x68);
  local_70[1] = 8;
  local_70[0] = iVar5;
  uVar12 = RingBuffer_write(uVar11,local_70,8);
  if ((uVar12 & 1) != 0) {
    RingBuffer_write(uVar11,puVar9,8);
  }
  if (*(long *)(lVar4 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00134ce0  size=456 */

void vt_handle_vkCreatePipelineCache(long param_1)

{
  int iVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  long lVar4;
  void *__s;
  uint64_t uVar5;
  uint64_t *puVar6;
  char *pcVar7;
  unsigned long uVar8;
  uint64_t unaff_x20;
  uint64_t local_88;
  unsigned long local_80 [4];
  void *local_60;
  uint32_t local_50;
  uint32_t uStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_60 = (void *)0x0;
  local_80[1] = 0;
  local_80[0] = 0;
  local_80[3] = 0;
  local_80[2] = 0;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar7 + 1);
    uVar8 = 9;
  }
  if (0 < *(int *)(pcVar7 + uVar8)) {
    puVar2 = (uint32_t *)(pcVar7 + (uVar8 | 4));
    local_80[1] = 0;
    local_80[0] = (unsigned long)*puVar2;
    local_80[2] = (unsigned long)puVar2[1];
    local_80[3] = *(unsigned long *)(puVar2 + 2);
    uVar3 = puVar2[4];
    uVar8 = (unsigned long)uVar3;
    if ((int)uVar3 < 1) {
      local_60 = (void *)0x0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x48) + uVar3;
      if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar1;
      }
      else {
        __s = malloc(uVar8);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,uVar8);
      local_60 = __s;
      memcpy(__s,puVar2 + 5,uVar8);
    }
  }
  uVar5 = VkObject_fromId(unaff_x20);
  local_50 = ((generic_fn_t)DAT_00193cc8)(uVar5,local_80,0,&local_88);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 8;
  }
  else {
    puVar6 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *puVar6 = 0;
  *puVar6 = local_88;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uStack_4c = 8;
  uVar8 = RingBuffer_write(uVar5,&local_50,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar6,8);
  }
  if (*(long *)(lVar4 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013533c  size=968 */

/* WARNING: Type propagation algorithm not settling */

void vt_handle_vkCreatePipelineLayout(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  void *__s;
  uint64_t uVar7;
  uint32_t *puVar8;
  uint64_t *puVar9;
  unsigned long uVar10;
  uint32_t *puVar11;
  long lVar12;
  uint32_t *puVar13;
  uint64_t unaff_x20;
  long lVar14;
  char *pcVar15;
  unsigned long uVar16;
  unsigned long uVar17;
  int iVar18;
  uint64_t local_a8;
  unsigned long local_a0 [3];
  void *pvStack_88;
  uint64_t local_80;
  uint32_t *local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar6 + 0x28);
  pcVar15 = *(char **)(param_1 + 0x30);
  pvStack_88 = (void *)0x0;
  local_a0[2] = 0;
  local_78 = (uint32_t *)0x0;
  local_80 = 0;
  local_a0[1] = 0;
  local_a0[0] = 0;
  if (*pcVar15 == '\0') {
    uVar10 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar15 + 1);
    uVar10 = 9;
  }
  if (0 < *(int *)(pcVar15 + uVar10)) {
    puVar13 = (uint32_t *)(pcVar15 + (uVar10 | 4));
    local_a0[1] = 0;
    local_a0[0] = (unsigned long)*puVar13;
    local_a0[2] = *(unsigned long *)(puVar13 + 1);
    uVar2 = puVar13[3];
    uVar17 = (unsigned long)uVar2;
    if ((int)uVar2 < 1) {
      uVar10 = 0x10;
      pvStack_88 = (void *)0x0;
    }
    else {
      iVar4 = uVar2 * 8;
      iVar18 = *(int *)(param_1 + 0x48) + iVar4;
      if ((iVar18 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar18;
      }
      else {
        __s = malloc((long)iVar4);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar4);
      lVar14 = 0;
      do {
        if (__s != (void *)0x0) {
          uVar7 = VkObject_fromId(*(uint64_t *)(pcVar15 + lVar14 + (uVar10 | 4) + 0x10));
          *(uint64_t *)((long)__s + lVar14) = uVar7;
        }
        uVar17 = uVar17 - 1;
        lVar14 = lVar14 + 8;
      } while (uVar17 != 0);
      uVar10 = (unsigned long)((int)lVar14 + 0x10);
      pvStack_88 = __s;
    }
    uVar2 = *(uint32_t *)((long)puVar13 + uVar10);
    uVar16 = (unsigned long)uVar2;
    local_80 = ((uint64_t)((*(uint32_t*)((char*)&local_80 + 4))) << 32 | (uint32_t)(uVar2));
    uVar3 = *(uint32_t *)((long)puVar13 + (uVar10 | 4));
    uVar17 = (unsigned long)uVar3;
    if (0 < (int)uVar3) {
      iVar5 = uVar3 * 0xc;
      iVar18 = (int)uVar10 + 8;
      iVar4 = *(int *)(param_1 + 0x48) + iVar5;
      if ((iVar4 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        puVar8 = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar4;
      }
      else {
        puVar8 = malloc((long)iVar5);
        ArrayList_add(param_1 + 0x50,puVar8);
      }
      memset(puVar8,0,(long)iVar5);
      puVar11 = puVar8 + 2;
      do {
        iVar4 = *(int *)((long)puVar13 + (long)iVar18);
        lVar14 = (long)iVar18 + 4;
        if (puVar8 != (uint32_t *)0x0) {
          puVar1 = (uint32_t *)((long)puVar13 + lVar14);
          puVar11[-2] = *puVar1;
          puVar11[-1] = puVar1[1];
          *puVar11 = puVar1[2];
        }
        iVar18 = iVar4 + (int)lVar14;
        uVar17 = uVar17 - 1;
        puVar11 = puVar11 + 3;
      } while (uVar17 != 0);
      local_78 = puVar8;
      uVar7 = VkObject_fromId(unaff_x20);
      if ((puVar8 != (uint32_t *)0x0) && (uVar2 != 0)) {
        if (uVar2 < 5) {
          lVar14 = 0;
        }
        else {
          uVar10 = 4;
          if ((uVar2 & 3) != 0) {
            uVar10 = uVar16 & 3;
          }
          lVar14 = uVar16 - uVar10;
          lVar12 = lVar14;
          puVar13 = puVar8;
          do {
            if ((*puVar13 & 1) != 0) {
              *puVar13 = *puVar13 | 0x10;
            }
            if ((puVar13[3] & 1) != 0) {
              puVar13[3] = puVar13[3] | 0x10;
            }
            if ((puVar13[6] & 1) != 0) {
              puVar13[6] = puVar13[6] | 0x10;
            }
            if ((puVar13[9] & 1) != 0) {
              puVar13[9] = puVar13[9] | 0x10;
            }
            lVar12 = lVar12 + -4;
            puVar13 = puVar13 + 0xc;
          } while (lVar12 != 0);
        }
        puVar8 = puVar8 + lVar14 * 3;
        lVar14 = uVar16 - lVar14;
        do {
          if ((*puVar8 & 1) != 0) {
            *puVar8 = *puVar8 | 0x10;
          }
          lVar14 = lVar14 + -1;
          puVar8 = puVar8 + 3;
        } while (lVar14 != 0);
      }
      goto LAB_00135590;
    }
  }
  local_78 = (uint32_t *)0x0;
  uVar7 = VkObject_fromId(unaff_x20);
LAB_00135590:
  local_70 = ((generic_fn_t)DAT_00193d00)(uVar7,local_a0,0,&local_a8);
  iVar18 = *(int *)(param_1 + 0x48);
  if ((iVar18 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar9 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar18);
    *(int *)(param_1 + 0x48) = iVar18 + 8;
  }
  else {
    puVar9 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar9);
  }
  *puVar9 = 0;
  *puVar9 = local_a8;
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar10 = RingBuffer_write(uVar7,&local_70,8);
  if ((uVar10 & 1) != 0) {
    RingBuffer_write(uVar7,puVar9,8);
  }
  if (*(long *)(lVar6 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00133abc  size=332 */

void vt_handle_vkCreateQueryPool(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  char *pcVar7;
  unsigned long uVar8;
  uint64_t local_68;
  unsigned long local_60 [2];
  uint32_t local_50;
  uint32_t local_4c;
  uint32_t uStack_48;
  uint32_t local_44;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_60[0] = 0;
  uStack_48 = 0;
  local_44 = 0;
  local_50 = 0;
  local_4c = 0;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
    lVar4 = param_1;
  }
  else {
    uVar8 = 9;
    lVar4 = *(long *)(pcVar7 + 1);
  }
  if (0 < *(int *)(pcVar7 + uVar8)) {
    puVar1 = (uint32_t *)(pcVar7 + (uVar8 | 4));
    local_60[0] = (unsigned long)*puVar1;
    local_50 = puVar1[1];
    local_4c = (uint32_t)*(uint64_t *)(puVar1 + 2);
    uStack_48 = (uint32_t)((unsigned long)*(uint64_t *)(puVar1 + 2) >> 0x20);
    local_44 = puVar1[4];
  }
  local_60[1] = 0;
  uVar5 = VkObject_fromId(lVar4);
  local_40 = ((generic_fn_t)DAT_00193c50)(uVar5,local_60,0,&local_68);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 8;
  }
  else {
    puVar6 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *puVar6 = 0;
  *puVar6 = local_68;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uStack_3c = 8;
  uVar8 = RingBuffer_write(uVar5,&local_40,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar6,8);
  }
  if (*(long *)(lVar3 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00136fc4  size=3100 */

void vt_handle_vkCreateRenderPass(long param_1)

{
  long lVar1;
  long lVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  uint64_t *puVar11;
  void *pvVar12;
  void *pvVar13;
  uint64_t uVar14;
  unsigned long uVar15;
  uint32_t *puVar16;
  char *pcVar17;
  uint32_t *puVar18;
  uint32_t *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  size_t sVar23;
  unsigned long uVar24;
  uint64_t *puVar25;
  uint64_t local_b8;
  unsigned long local_b0;
  uint64_t *puStack_a8;
  uint64_t local_a0;
  void *local_98;
  uint64_t local_90;
  void *pvStack_88;
  uint64_t local_80;
  void *local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar9 + 0x28);
  pcVar17 = *(char **)(param_1 + 0x30);
  pvStack_88 = (void *)0x0;
  local_90 = 0;
  local_78 = (void *)0x0;
  local_80 = 0;
  puStack_a8 = (uint64_t *)0x0;
  local_b0 = 0;
  local_98 = (void *)0x0;
  local_a0 = 0;
  if (*pcVar17 == '\0') {
    uVar15 = 1;
    lVar10 = param_1;
  }
  else {
    uVar15 = 9;
    lVar10 = *(long *)(pcVar17 + 1);
  }
  if (0 < *(int *)(pcVar17 + uVar15)) {
    puVar3 = (uint32_t *)(pcVar17 + (uVar15 | 4));
    puVar18 = puVar3 + 1;
    puVar25 = (uint64_t *)0x0;
    iVar21 = 8;
    local_b0 = (unsigned long)*puVar3;
    do {
      uVar5 = *puVar18;
      if (uVar5 == 0x3b9b9908) {
        iVar20 = *(int *)((long)puVar3 + (long)iVar21);
        uVar15 = (long)iVar21 + 4;
        if (0 < iVar20) {
          iVar21 = *(int *)(param_1 + 0x48);
          if ((iVar21 < 0xffc0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar11 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar21);
            *(int *)(param_1 + 0x48) = iVar21 + 0x40;
          }
          else {
            puVar11 = malloc(0x40);
            ArrayList_add(param_1 + 0x50,puVar11);
          }
          puVar11[5] = 0;
          puVar11[4] = 0;
          puVar11[7] = 0;
          puVar11[6] = 0;
          puVar11[1] = 0;
          *puVar11 = 0;
          puVar11[3] = 0;
          puVar11[2] = 0;
          puVar16 = (uint32_t *)((long)puVar3 + uVar15);
          uVar6 = *puVar16;
          puVar11[1] = 0;
          *(uint32_t *)puVar11 = uVar6;
          *(uint32_t *)(puVar11 + 2) = puVar16[1];
          if ((int)puVar16[2] < 1) {
            iVar21 = 0xc;
            puVar11[3] = 0;
          }
          else {
            sVar23 = (long)(int)puVar16[2] << 2;
            iVar21 = (int)sVar23;
            iVar22 = *(int *)(param_1 + 0x48) + iVar21;
            if ((iVar22 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar13 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar22;
              sVar23 = (size_t)iVar21;
            }
            else {
              pvVar13 = malloc(sVar23);
              ArrayList_add(param_1 + 0x50,pvVar13);
            }
            memset(pvVar13,0,sVar23);
            if (pvVar13 != (void *)0x0) {
              memcpy(pvVar13,puVar16 + 3,(long)iVar21);
            }
            iVar21 = iVar21 + 0xc;
            puVar11[3] = pvVar13;
          }
          puVar19 = (uint32_t *)((long)puVar16 + (long)iVar21);
          uVar24 = (long)iVar21 + 8;
          *(uint32_t *)(puVar11 + 4) = *puVar19;
          iVar21 = puVar19[1];
          if (iVar21 < 1) {
            puVar11[5] = 0;
          }
          else {
            sVar23 = (long)iVar21 << 2;
            iVar22 = (int)sVar23;
            iVar21 = *(int *)(param_1 + 0x48) + iVar22;
            if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar13 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar21;
              sVar23 = (size_t)iVar22;
            }
            else {
              pvVar13 = malloc(sVar23);
              ArrayList_add(param_1 + 0x50,pvVar13);
            }
            memset(pvVar13,0,sVar23);
            if (pvVar13 != (void *)0x0) {
              memcpy(pvVar13,(void *)((long)puVar16 + uVar24),(long)iVar22);
            }
            uVar24 = (unsigned long)(uint32_t)(iVar22 + (int)uVar24);
            puVar11[5] = pvVar13;
          }
          puVar19 = (uint32_t *)((long)puVar16 + (long)(int)uVar24);
          *(uint32_t *)(puVar11 + 6) = *puVar19;
          iVar21 = puVar19[1];
          if (iVar21 < 1) {
            puVar11[7] = 0;
          }
          else {
            sVar23 = (long)iVar21 << 2;
            iVar22 = (int)sVar23;
            iVar21 = *(int *)(param_1 + 0x48) + iVar22;
            if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar13 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar21;
              sVar23 = (size_t)iVar22;
            }
            else {
              pvVar13 = malloc(sVar23);
              ArrayList_add(param_1 + 0x50,pvVar13);
            }
            memset(pvVar13,0,sVar23);
            if (pvVar13 != (void *)0x0) {
              memcpy(pvVar13,(void *)((long)puVar16 + (long)(int)uVar24 + 8),(long)iVar22);
            }
            puVar11[7] = pvVar13;
          }
LAB_0013705c:
          uVar15 = (unsigned long)(uint32_t)(iVar20 + (int)uVar15);
          puVar11[1] = puVar25;
          puVar25 = puVar11;
        }
      }
      else if (uVar5 == 0x3b9c9309) {
        iVar20 = *(int *)((long)puVar3 + (long)iVar21);
        uVar15 = (long)iVar21 + 4;
        if (0 < iVar20) {
          iVar21 = *(int *)(param_1 + 0x48);
          if ((iVar21 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar11 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar21);
            *(int *)(param_1 + 0x48) = iVar21 + 0x20;
          }
          else {
            puVar11 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar11);
          }
          puVar11[1] = 0;
          *puVar11 = 0;
          puVar11[3] = 0;
          puVar11[2] = 0;
          puVar16 = (uint32_t *)((long)puVar3 + uVar15);
          uVar6 = *puVar16;
          puVar11[1] = 0;
          *(uint32_t *)puVar11 = uVar6;
          *(uint32_t *)(puVar11 + 2) = puVar16[1];
          uVar5 = puVar16[2];
          uVar24 = (unsigned long)uVar5;
          if ((int)uVar5 < 1) {
            puVar11[3] = 0;
          }
          else {
            iVar22 = uVar5 * 0xc;
            iVar21 = *(int *)(param_1 + 0x48) + iVar22;
            if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar13 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar21;
            }
            else {
              pvVar13 = malloc((long)iVar22);
              ArrayList_add(param_1 + 0x50,pvVar13);
            }
            memset(pvVar13,0,(long)iVar22);
            puVar19 = (uint32_t *)((long)pvVar13 + 8);
            iVar21 = 0xc;
            do {
              iVar22 = *(int *)((long)puVar16 + (long)iVar21);
              lVar1 = (long)iVar21 + 4;
              if (pvVar13 != (void *)0x0) {
                puVar4 = (uint32_t *)((long)puVar16 + lVar1);
                puVar19[-2] = *puVar4;
                puVar19[-1] = puVar4[1];
                *puVar19 = puVar4[2];
              }
              iVar21 = iVar22 + (int)lVar1;
              uVar24 = uVar24 - 1;
              puVar19 = puVar19 + 3;
            } while (uVar24 != 0);
            puVar11[3] = pvVar13;
          }
          goto LAB_0013705c;
        }
      }
      else {
        if (uVar5 == 0xffffffff) goto LAB_00137458;
        uVar15 = (unsigned long)(iVar21 + 4);
      }
      puVar18 = (uint32_t *)((long)puVar3 + (long)(int)uVar15);
      iVar21 = (int)uVar15 + 4;
    } while( true );
  }
LAB_00137b0c:
  uVar14 = VkObject_fromId(lVar10);
  local_70 = ((generic_fn_t)DAT_00193d70)(uVar14,&local_b0,0,&local_b8);
  iVar21 = *(int *)(param_1 + 0x48);
  if ((iVar21 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar25 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar21);
    *(int *)(param_1 + 0x48) = iVar21 + 8;
  }
  else {
    puVar25 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar25);
  }
  *puVar25 = 0;
  *puVar25 = local_b8;
  uVar14 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar15 = RingBuffer_write(uVar14,&local_70,8);
  if ((uVar15 & 1) != 0) {
    RingBuffer_write(uVar14,puVar25,8);
  }
  if (*(long *)(lVar9 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00137458:
  if (puVar25 == (uint64_t *)0x0) {
    puStack_a8 = (uint64_t *)0x0;
  }
  else {
    puVar11 = (uint64_t *)0x0;
    do {
      puStack_a8 = puVar25;
      puVar25 = (uint64_t *)puStack_a8[1];
      puStack_a8[1] = puVar11;
      puVar11 = puStack_a8;
    } while (puVar25 != (uint64_t *)0x0);
  }
  iVar20 = iVar21 + 0xc;
  local_a0 = *(uint64_t *)((long)puVar3 + (long)iVar21);
  uVar5 = *(uint32_t *)((uint64_t *)((long)puVar3 + (long)iVar21) + 1);
  uVar15 = (unsigned long)uVar5;
  if ((int)uVar5 < 1) {
    local_98 = (void *)0x0;
  }
  else {
    iVar22 = uVar5 * 0x24;
    iVar21 = *(int *)(param_1 + 0x48) + iVar22;
    if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar13 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar21;
    }
    else {
      pvVar13 = malloc((long)iVar22);
      ArrayList_add(param_1 + 0x50,pvVar13);
    }
    memset(pvVar13,0,(long)iVar22);
    puVar16 = (uint32_t *)((long)pvVar13 + 0x10);
    do {
      iVar21 = *(int *)((long)puVar3 + (long)iVar20);
      lVar1 = (long)iVar20 + 4;
      if (pvVar13 != (void *)0x0) {
        puVar19 = (uint32_t *)((long)puVar3 + lVar1);
        puVar16[-4] = *puVar19;
        puVar16[-3] = puVar19[1];
        puVar16[-2] = puVar19[2];
        puVar16[-1] = puVar19[3];
        *puVar16 = puVar19[4];
        puVar16[1] = puVar19[5];
        puVar16[2] = puVar19[6];
        puVar16[3] = puVar19[7];
        puVar16[4] = puVar19[8];
      }
      iVar20 = iVar21 + (int)lVar1;
      uVar15 = uVar15 - 1;
      puVar16 = puVar16 + 9;
      local_98 = pvVar13;
    } while (uVar15 != 0);
  }
  iVar21 = iVar20 + 8;
  local_90 = ((uint64_t)((*(uint32_t*)((char*)&local_90 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar3 + (long)iVar20)));
  uVar5 = ((uint32_t *)((long)puVar3 + (long)iVar20))[1];
  if ((int)uVar5 < 1) {
    pvStack_88 = (void *)0x0;
    pvVar13 = pvStack_88;
  }
  else {
    iVar22 = uVar5 * 0x48;
    iVar20 = *(int *)(param_1 + 0x48) + iVar22;
    if ((iVar20 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar13 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar20;
    }
    else {
      pvVar13 = malloc((long)iVar22);
      ArrayList_add(param_1 + 0x50,pvVar13);
    }
    memset(pvVar13,0,(long)iVar22);
    uVar15 = 0;
    do {
      iVar20 = *(int *)((long)puVar3 + (long)iVar21);
      lVar1 = (long)iVar21 + 4;
      if (pvVar13 != (void *)0x0) {
        puVar16 = (uint32_t *)((long)puVar3 + lVar1);
        puVar19 = (uint32_t *)((long)pvVar13 + uVar15 * 0x48);
        *puVar19 = *puVar16;
        *(uint64_t *)(puVar19 + 1) = *(uint64_t *)(puVar16 + 1);
        uVar7 = puVar16[3];
        uVar24 = (unsigned long)uVar7;
        if ((int)uVar7 < 1) {
          *(uint64_t *)((long)pvVar13 + uVar15 * 0x48 + 0x10) = 0;
          iVar21 = 0x10;
        }
        else {
          iVar22 = uVar7 * 8;
          iVar21 = *(int *)(param_1 + 0x48) + iVar22;
          if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar21;
          }
          else {
            pvVar12 = malloc((long)iVar22);
            ArrayList_add(param_1 + 0x50,pvVar12);
          }
          memset(pvVar12,0,(long)iVar22);
          puVar19 = (uint32_t *)((long)pvVar12 + 4);
          iVar21 = 0x10;
          do {
            iVar22 = *(int *)((long)puVar16 + (long)iVar21);
            lVar2 = (long)iVar21 + 4;
            if (pvVar12 != (void *)0x0) {
              puVar4 = (uint32_t *)((long)puVar16 + lVar2);
              puVar19[-1] = *puVar4;
              *puVar19 = puVar4[1];
            }
            iVar21 = iVar22 + (int)lVar2;
            uVar24 = uVar24 - 1;
            puVar19 = puVar19 + 2;
          } while (uVar24 != 0);
          *(void **)((long)pvVar13 + uVar15 * 0x48 + 0x10) = pvVar12;
        }
        iVar22 = iVar21 + 8;
        *(uint32_t *)((long)pvVar13 + uVar15 * 0x48 + 0x18) =
             *(uint32_t *)((long)puVar16 + (long)iVar21);
        uVar7 = ((uint32_t *)((long)puVar16 + (long)iVar21))[1];
        uVar24 = (unsigned long)uVar7;
        if ((int)uVar7 < 1) {
          *(uint64_t *)((long)pvVar13 + uVar15 * 0x48 + 0x20) = 0;
        }
        else {
          iVar8 = uVar7 * 8;
          iVar21 = *(int *)(param_1 + 0x48) + iVar8;
          if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar21;
          }
          else {
            pvVar12 = malloc((long)iVar8);
            ArrayList_add(param_1 + 0x50,pvVar12);
          }
          memset(pvVar12,0,(long)iVar8);
          puVar19 = (uint32_t *)((long)pvVar12 + 4);
          do {
            iVar21 = *(int *)((long)puVar16 + (long)iVar22);
            lVar2 = (long)iVar22 + 4;
            if (pvVar12 != (void *)0x0) {
              puVar4 = (uint32_t *)((long)puVar16 + lVar2);
              puVar19[-1] = *puVar4;
              *puVar19 = puVar4[1];
            }
            iVar22 = iVar21 + (int)lVar2;
            uVar24 = uVar24 - 1;
            puVar19 = puVar19 + 2;
          } while (uVar24 != 0);
          *(void **)((long)pvVar13 + uVar15 * 0x48 + 0x20) = pvVar12;
        }
        uVar7 = *(uint32_t *)((long)puVar16 + (long)iVar22);
        uVar24 = (unsigned long)uVar7;
        iVar22 = iVar22 + 4;
        if ((int)uVar7 < 1) {
          *(uint64_t *)((long)pvVar13 + uVar15 * 0x48 + 0x28) = 0;
        }
        else {
          iVar8 = uVar7 * 8;
          iVar21 = *(int *)(param_1 + 0x48) + iVar8;
          if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar21;
          }
          else {
            pvVar12 = malloc((long)iVar8);
            ArrayList_add(param_1 + 0x50,pvVar12);
          }
          memset(pvVar12,0,(long)iVar8);
          puVar19 = (uint32_t *)((long)pvVar12 + 4);
          do {
            iVar21 = *(int *)((long)puVar16 + (long)iVar22);
            lVar2 = (long)iVar22 + 4;
            if (pvVar12 != (void *)0x0) {
              puVar4 = (uint32_t *)((long)puVar16 + lVar2);
              puVar19[-1] = *puVar4;
              *puVar19 = puVar4[1];
            }
            iVar22 = iVar21 + (int)lVar2;
            uVar24 = uVar24 - 1;
            puVar19 = puVar19 + 2;
          } while (uVar24 != 0);
          *(void **)((long)pvVar13 + uVar15 * 0x48 + 0x28) = pvVar12;
        }
        iVar21 = *(int *)((long)puVar16 + (long)iVar22);
        uVar24 = (long)iVar22 + 4;
        if (iVar21 < 1) {
          *(uint64_t *)((long)pvVar13 + uVar15 * 0x48 + 0x30) = 0;
        }
        else {
          iVar22 = *(int *)(param_1 + 0x48);
          if ((iVar22 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar25 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar22);
            *(int *)(param_1 + 0x48) = iVar22 + 8;
          }
          else {
            puVar25 = malloc(8);
            ArrayList_add(param_1 + 0x50,puVar25);
          }
          *puVar25 = 0;
          puVar19 = (uint32_t *)((long)puVar16 + uVar24);
          *(uint64_t **)((long)pvVar13 + uVar15 * 0x48 + 0x30) = puVar25;
          uVar24 = (unsigned long)(uint32_t)((int)uVar24 + iVar21);
          *(uint32_t *)puVar25 = *puVar19;
          *(uint32_t *)((long)puVar25 + 4) = puVar19[1];
        }
        puVar19 = (uint32_t *)((long)puVar16 + (long)(int)uVar24);
        *(uint32_t *)((long)pvVar13 + uVar15 * 0x48 + 0x38) = *puVar19;
        iVar21 = puVar19[1];
        if (iVar21 < 1) {
          *(uint64_t *)((long)pvVar13 + uVar15 * 0x48 + 0x40) = 0;
        }
        else {
          sVar23 = (long)iVar21 << 2;
          iVar22 = (int)sVar23;
          iVar21 = *(int *)(param_1 + 0x48) + iVar22;
          if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar21;
            sVar23 = (size_t)iVar22;
          }
          else {
            pvVar12 = malloc(sVar23);
            ArrayList_add(param_1 + 0x50,pvVar12);
          }
          memset(pvVar12,0,sVar23);
          if (pvVar12 != (void *)0x0) {
            memcpy(pvVar12,(void *)((long)puVar16 + (long)(int)uVar24 + 8),(long)iVar22);
          }
          *(void **)((long)pvVar13 + uVar15 * 0x48 + 0x40) = pvVar12;
        }
      }
      uVar15 = uVar15 + 1;
      iVar21 = iVar20 + (int)lVar1;
    } while (uVar15 != uVar5);
  }
  pvStack_88 = pvVar13;
  local_80 = ((uint64_t)((*(uint32_t*)((char*)&local_80 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar3 + (long)iVar21)));
  uVar5 = ((uint32_t *)((long)puVar3 + (long)iVar21))[1];
  uVar15 = (unsigned long)uVar5;
  if ((int)uVar5 < 1) {
    local_78 = (void *)0x0;
  }
  else {
    iVar22 = uVar5 * 0x1c;
    iVar21 = iVar21 + 8;
    iVar20 = *(int *)(param_1 + 0x48) + iVar22;
    if ((iVar20 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar13 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar20;
    }
    else {
      pvVar13 = malloc((long)iVar22);
      ArrayList_add(param_1 + 0x50,pvVar13);
    }
    memset(pvVar13,0,(long)iVar22);
    puVar16 = (uint32_t *)((long)pvVar13 + 0xc);
    do {
      iVar20 = *(int *)((long)puVar3 + (long)iVar21);
      lVar1 = (long)iVar21 + 4;
      if (pvVar13 != (void *)0x0) {
        puVar19 = (uint32_t *)((long)puVar3 + lVar1);
        puVar16[-3] = *puVar19;
        puVar16[-2] = puVar19[1];
        puVar16[-1] = puVar19[2];
        *puVar16 = puVar19[3];
        puVar16[1] = puVar19[4];
        puVar16[2] = puVar19[5];
        puVar16[3] = puVar19[6];
      }
      iVar21 = iVar20 + (int)lVar1;
      uVar15 = uVar15 - 1;
      puVar16 = puVar16 + 7;
      local_78 = pvVar13;
    } while (uVar15 != 0);
  }
  goto LAB_00137b0c;
}


/* @00146788  size=4696 */

void vt_handle_vkCreateRenderPass2(long param_1)

{
  uint32_t *puVar1;
  long lVar2;
  long lVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  void *pvVar11;
  void *pvVar12;
  uint64_t uVar13;
  int iVar14;
  char *pcVar15;
  unsigned long uVar16;
  uint64_t *puVar17;
  int *piVar18;
  uint64_t *puVar19;
  uint64_t *puVar20;
  int iVar21;
  uint64_t *puVar22;
  int iVar23;
  uint64_t *puVar24;
  size_t sVar25;
  uint32_t *puVar26;
  unsigned long uVar27;
  uint64_t *puVar28;
  unsigned long uVar29;
  int *piVar30;
  uint64_t local_138;
  uint64_t local_d8;
  unsigned long local_d0 [3];
  void *pvStack_b8;
  uint64_t local_b0;
  void *local_a8;
  uint64_t local_a0;
  void *pvStack_98;
  uint64_t local_90;
  void *local_88;
  uint32_t local_78;
  uint32_t uStack_74;
  long local_70;
  
  /* stack canary setup */
  local_70 = *(long *)(lVar9 + 0x28);
  pcVar15 = *(char **)(param_1 + 0x30);
  pvStack_98 = (void *)0x0;
  local_a0 = 0;
  local_88 = (void *)0x0;
  local_90 = 0;
  pvStack_b8 = (void *)0x0;
  local_d0[2] = 0;
  local_a8 = (void *)0x0;
  local_b0 = 0;
  local_d0[1] = 0;
  local_d0[0] = 0;
  if (*pcVar15 == '\0') {
    uVar16 = 1;
  }
  else {
    local_138 = *(uint64_t *)(pcVar15 + 1);
    uVar16 = 9;
  }
  pvVar12 = local_88;
  if (0 < *(int *)(pcVar15 + uVar16)) {
    puVar4 = (uint32_t *)(pcVar15 + (uVar16 | 4));
    local_d0[1] = 0;
    local_d0[0] = (unsigned long)*puVar4;
    local_d0[2] = *(unsigned long *)(puVar4 + 1);
    uVar5 = puVar4[3];
    if (0 < (int)uVar5) {
      iVar21 = uVar5 * 0x38;
      iVar14 = *(int *)(param_1 + 0x48) + iVar21;
      if ((iVar14 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar14;
      }
      else {
        pvVar12 = malloc((long)iVar21);
        ArrayList_add(param_1 + 0x50,pvVar12);
      }
      memset(pvVar12,0,(long)iVar21);
      uVar16 = 0;
      iVar14 = 0x10;
LAB_00146930:
      iVar21 = *(int *)((long)puVar4 + (long)iVar14);
      lVar2 = (long)iVar14 + 4;
      if (pvVar12 != (void *)0x0) {
        piVar30 = (uint32_t *)((long)puVar4 + lVar2) + 1;
        *(uint32_t *)((long)pvVar12 + uVar16 * 0x38) = *(uint32_t *)((long)puVar4 + lVar2);
        iVar14 = 8;
        puVar22 = (uint64_t *)0x0;
        do {
          puVar28 = puVar22;
          if (*piVar30 == 0x3b9e776a) {
            iVar23 = *(int *)((long)puVar4 + iVar14 + lVar2);
            uVar29 = (long)iVar14 + 4;
            if (0 < iVar23) {
              iVar14 = *(int *)(param_1 + 0x48);
              if ((iVar14 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
                puVar28 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar14);
                *(int *)(param_1 + 0x48) = iVar14 + 0x18;
              }
              else {
                puVar28 = malloc(0x18);
                ArrayList_add(param_1 + 0x50,puVar28);
              }
              *puVar28 = 0;
              puVar28[1] = 0;
              puVar28[2] = 0;
              puVar1 = (uint32_t *)((long)puVar4 + uVar29 + lVar2);
              uVar7 = *puVar1;
              puVar28[1] = 0;
              uVar29 = (unsigned long)(uint32_t)(iVar23 + (int)uVar29);
              *(uint32_t *)puVar28 = uVar7;
              *(uint32_t *)(puVar28 + 2) = puVar1[1];
              uVar7 = puVar1[2];
              puVar28[1] = puVar22;
              *(uint32_t *)((long)puVar28 + 0x14) = uVar7;
            }
          }
          else {
            if (*piVar30 == -1) goto LAB_00146a14;
            uVar29 = (unsigned long)(iVar14 + 4);
          }
          piVar30 = (int *)((long)puVar4 + (int)uVar29 + lVar2);
          iVar14 = (int)uVar29 + 4;
          puVar22 = puVar28;
        } while( true );
      }
      goto LAB_00146920;
    }
    iVar14 = 0x10;
    pvStack_b8 = (void *)0x0;
    pvVar12 = pvStack_b8;
LAB_00146a48:
    pvStack_b8 = pvVar12;
    iVar21 = iVar14 + 8;
    local_b0 = ((uint64_t)((*(uint32_t*)((char*)&local_b0 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar4 + (long)iVar14)));
    uVar5 = ((uint32_t *)((long)puVar4 + (long)iVar14))[1];
    if (0 < (int)uVar5) {
      piVar30 = (int *)(param_1 + 0x48);
      iVar23 = uVar5 * 0x58;
      iVar14 = *piVar30 + iVar23;
      if ((iVar14 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*piVar30);
        *piVar30 = iVar14;
      }
      else {
        pvVar12 = malloc((long)iVar23);
        ArrayList_add(param_1 + 0x50,pvVar12);
      }
      memset(pvVar12,0,(long)iVar23);
      uVar16 = 0;
LAB_00146b10:
      iVar14 = *(int *)((long)puVar4 + (long)iVar21);
      lVar2 = (long)iVar21 + 4;
      if (pvVar12 != (void *)0x0) {
        piVar18 = (uint32_t *)((long)puVar4 + lVar2) + 1;
        *(uint32_t *)((long)pvVar12 + uVar16 * 0x58) = *(uint32_t *)((long)puVar4 + lVar2);
        puVar22 = (uint64_t *)0x0;
        iVar21 = 8;
LAB_00146b74:
        if (*piVar18 == 0x3b9dd359) {
          uVar29 = (long)iVar21 + 4;
          iVar21 = *(int *)((long)puVar4 + iVar21 + lVar2);
          if (iVar21 < 1) goto LAB_00146b60;
          iVar23 = *piVar30;
          if ((iVar23 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar28 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar23);
            *piVar30 = iVar23 + 0x20;
          }
          else {
            puVar28 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar28);
          }
          puVar28[1] = 0;
          *puVar28 = 0;
          puVar28[3] = 0;
          puVar28[2] = 0;
          puVar1 = (uint32_t *)((long)puVar4 + uVar29 + lVar2);
          uVar7 = *puVar1;
          puVar28[1] = 0;
          *(uint32_t *)puVar28 = uVar7;
          *(uint32_t *)(puVar28 + 2) = puVar1[1];
          *(uint32_t *)((long)puVar28 + 0x14) = puVar1[2];
          if (0 < (int)puVar1[3]) {
            iVar23 = *piVar30;
            if ((iVar23 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
              puVar19 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar23);
              *piVar30 = iVar23 + 0x20;
            }
            else {
              puVar19 = malloc(0x20);
              ArrayList_add(param_1 + 0x50,puVar19);
            }
            puVar19[1] = 0;
            *puVar19 = 0;
            puVar19[3] = 0;
            puVar19[2] = 0;
            puVar28[3] = puVar19;
            puVar26 = puVar1 + 4;
            *(uint32_t *)puVar19 = *puVar26;
            piVar18 = puVar1 + 5;
            iVar23 = 8;
            puVar24 = (uint64_t *)0x0;
            do {
              puVar17 = puVar24;
              if (*piVar18 == 0x3b9e7769) {
                iVar8 = *(int *)((long)puVar26 + (long)iVar23);
                uVar27 = (long)iVar23 + 4;
                if (0 < iVar8) {
                  iVar23 = *piVar30;
                  if ((iVar23 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
                    puVar17 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar23);
                    *piVar30 = iVar23 + 0x18;
                  }
                  else {
                    puVar17 = malloc(0x18);
                    ArrayList_add(param_1 + 0x50,puVar17);
                  }
                  *puVar17 = 0;
                  puVar17[1] = 0;
                  puVar17[2] = 0;
                  puVar1 = (uint32_t *)((long)puVar26 + uVar27);
                  uVar7 = *puVar1;
                  puVar17[1] = 0;
                  uVar27 = (unsigned long)(uint32_t)(iVar8 + (int)uVar27);
                  *(uint32_t *)puVar17 = uVar7;
                  uVar7 = puVar1[1];
                  puVar17[1] = puVar24;
                  *(uint32_t *)(puVar17 + 2) = uVar7;
                }
              }
              else {
                if (*piVar18 == -1) goto LAB_00146d40;
                uVar27 = (unsigned long)(iVar23 + 4);
              }
              piVar18 = (int *)((long)puVar26 + (long)(int)uVar27);
              iVar23 = (int)uVar27 + 4;
              puVar24 = puVar17;
            } while( true );
          }
          puVar28[3] = 0;
          goto LAB_00146da4;
        }
        if (*piVar18 != -1) {
          uVar29 = (unsigned long)(iVar21 + 4);
LAB_00146b60:
          iVar21 = (int)uVar29;
          goto LAB_00146b64;
        }
        if (puVar22 == (uint64_t *)0x0) {
          puVar28 = (uint64_t *)0x0;
        }
        else {
          puVar19 = (uint64_t *)0x0;
          do {
            puVar28 = puVar22;
            puVar22 = (uint64_t *)puVar28[1];
            puVar28[1] = puVar19;
            puVar19 = puVar28;
          } while (puVar22 != (uint64_t *)0x0);
        }
        iVar23 = iVar21 + 0x14;
        *(uint64_t **)((long)pvVar12 + uVar16 * 0x58 + 8) = puVar28;
        puVar1 = (uint32_t *)((long)puVar4 + iVar21 + lVar2);
        *(uint32_t *)((long)pvVar12 + uVar16 * 0x58 + 0x10) = *puVar1;
        *(uint32_t *)((long)pvVar12 + uVar16 * 0x58 + 0x14) = puVar1[1];
        *(uint32_t *)((long)pvVar12 + uVar16 * 0x58 + 0x18) = puVar1[2];
        *(uint32_t *)((long)pvVar12 + uVar16 * 0x58 + 0x1c) = puVar1[3];
        uVar6 = puVar1[4];
        if (0 < (int)uVar6) {
          iVar8 = uVar6 * 0x20;
          iVar21 = *piVar30 + iVar8;
          if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar11 = (void *)(*(long *)(param_1 + 0x40) + (long)*piVar30);
            *piVar30 = iVar21;
          }
          else {
            pvVar11 = malloc((long)iVar8);
            ArrayList_add(param_1 + 0x50,pvVar11);
          }
          memset(pvVar11,0,(long)iVar8);
          uVar29 = 0;
LAB_00146ec8:
          lVar3 = (long)iVar23 + 4;
          iVar23 = *(int *)((long)puVar4 + iVar23 + lVar2);
          if (pvVar11 != (void *)0x0) {
            puVar1 = (uint32_t *)((long)puVar4 + lVar3 + lVar2);
            piVar18 = puVar1 + 1;
            lVar10 = lVar3 + lVar2;
            *(uint32_t *)((long)pvVar11 + uVar29 * 0x20) = *puVar1;
            iVar21 = 8;
            puVar22 = (uint64_t *)0x0;
            do {
              puVar28 = puVar22;
              if (*piVar18 == 0x3b9e7769) {
                iVar8 = *(int *)((long)puVar4 + iVar21 + lVar10);
                uVar27 = (long)iVar21 + 4;
                if (0 < iVar8) {
                  iVar21 = *piVar30;
                  if ((iVar21 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
                    puVar28 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar21);
                    *piVar30 = iVar21 + 0x18;
                  }
                  else {
                    puVar28 = malloc(0x18);
                    ArrayList_add(param_1 + 0x50,puVar28);
                  }
                  *puVar28 = 0;
                  puVar28[1] = 0;
                  puVar28[2] = 0;
                  puVar1 = (uint32_t *)((long)puVar4 + uVar27 + lVar10);
                  uVar7 = *puVar1;
                  puVar28[1] = 0;
                  uVar27 = (unsigned long)(uint32_t)(iVar8 + (int)uVar27);
                  *(uint32_t *)puVar28 = uVar7;
                  uVar7 = puVar1[1];
                  puVar28[1] = puVar22;
                  *(uint32_t *)(puVar28 + 2) = uVar7;
                }
              }
              else {
                if (*piVar18 == -1) goto LAB_00146fb0;
                uVar27 = (unsigned long)(iVar21 + 4);
              }
              piVar18 = (int *)((long)puVar4 + (int)uVar27 + lVar10);
              iVar21 = (int)uVar27 + 4;
              puVar22 = puVar28;
            } while( true );
          }
          goto LAB_00146eb8;
        }
        *(uint64_t *)((long)pvVar12 + uVar16 * 0x58 + 0x20) = 0;
        goto LAB_00146ff0;
      }
      goto LAB_00146b00;
    }
    local_a8 = (void *)0x0;
    pvVar12 = local_a8;
LAB_0014763c:
    local_a8 = pvVar12;
    iVar14 = iVar21 + 8;
    local_a0 = ((uint64_t)((*(uint32_t*)((char*)&local_a0 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar4 + (long)iVar21)));
    uVar5 = ((uint32_t *)((long)puVar4 + (long)iVar21))[1];
    if (0 < (int)uVar5) {
      iVar23 = uVar5 * 0x30;
      iVar21 = *(int *)(param_1 + 0x48) + iVar23;
      if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar21;
      }
      else {
        pvVar12 = malloc((long)iVar23);
        ArrayList_add(param_1 + 0x50,pvVar12);
      }
      memset(pvVar12,0,(long)iVar23);
      uVar16 = 0;
LAB_00147744:
      iVar21 = *(int *)((long)puVar4 + (long)iVar14);
      lVar2 = (long)iVar14 + 4;
      if (pvVar12 != (void *)0x0) {
        piVar30 = (uint32_t *)((long)puVar4 + lVar2) + 1;
        *(uint32_t *)((long)pvVar12 + uVar16 * 0x30) = *(uint32_t *)((long)puVar4 + lVar2);
        iVar14 = 8;
        puVar22 = (uint64_t *)0x0;
        do {
          puVar28 = puVar22;
          if (*piVar30 == 0x3b9f9490) {
            iVar23 = *(int *)((long)puVar4 + iVar14 + lVar2);
            uVar29 = (long)iVar14 + 4;
            if (0 < iVar23) {
              iVar14 = *(int *)(param_1 + 0x48);
              if ((iVar14 < 0xffd0) && (*(long *)(param_1 + 0x40) != 0)) {
                puVar28 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar14);
                *(int *)(param_1 + 0x48) = iVar14 + 0x30;
              }
              else {
                puVar28 = malloc(0x30);
                ArrayList_add(param_1 + 0x50,puVar28);
              }
              puVar28[3] = 0;
              puVar28[2] = 0;
              puVar28[5] = 0;
              puVar28[4] = 0;
              puVar28[1] = 0;
              *puVar28 = 0;
              puVar1 = (uint32_t *)((long)puVar4 + uVar29 + lVar2);
              uVar29 = (unsigned long)(uint32_t)(iVar23 + (int)uVar29);
              *(uint32_t *)puVar28 = *puVar1;
              puVar28[2] = *(uint64_t *)(puVar1 + 1);
              puVar28[3] = *(uint64_t *)(puVar1 + 3);
              puVar28[4] = *(uint64_t *)(puVar1 + 5);
              uVar13 = *(uint64_t *)(puVar1 + 7);
              puVar28[1] = puVar22;
              puVar28[5] = uVar13;
            }
          }
          else {
            if (*piVar30 == -1) goto LAB_00147838;
            uVar29 = (unsigned long)(iVar14 + 4);
          }
          piVar30 = (int *)((long)puVar4 + (int)uVar29 + lVar2);
          iVar14 = (int)uVar29 + 4;
          puVar22 = puVar28;
        } while( true );
      }
      goto LAB_00147734;
    }
    pvStack_98 = (void *)0x0;
    pvVar12 = pvStack_98;
LAB_00147868:
    pvStack_98 = pvVar12;
    puVar1 = (uint32_t *)((long)puVar4 + (long)iVar14);
    local_90 = ((uint64_t)((*(uint32_t*)((char*)&local_90 + 4))) << 32 | (uint32_t)(*puVar1));
    iVar21 = puVar1[1];
    if (iVar21 < 1) {
      local_88 = (void *)0x0;
      pvVar12 = local_88;
    }
    else {
      sVar25 = (long)iVar21 << 2;
      iVar23 = (int)sVar25;
      iVar21 = *(int *)(param_1 + 0x48) + iVar23;
      if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        pvVar12 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        sVar25 = (size_t)iVar23;
        *(int *)(param_1 + 0x48) = iVar21;
      }
      else {
        pvVar12 = malloc(sVar25);
        ArrayList_add(param_1 + 0x50,pvVar12);
      }
      memset(pvVar12,0,sVar25);
      if (pvVar12 != (void *)0x0) {
        memcpy(pvVar12,(void *)((long)puVar4 + (long)iVar14 + 8),(long)iVar23);
      }
    }
  }
  local_88 = pvVar12;
  uVar13 = VkObject_fromId(local_138);
  local_78 = ((generic_fn_t)DAT_001940b8)(uVar13,local_d0,0,&local_d8);
  iVar14 = *(int *)(param_1 + 0x48);
  if ((iVar14 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar22 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar14);
    *(int *)(param_1 + 0x48) = iVar14 + 8;
  }
  else {
    puVar22 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar22);
  }
  *puVar22 = 0;
  *puVar22 = local_d8;
  uVar13 = *(uint64_t *)(param_1 + 0x68);
  uStack_74 = 8;
  uVar16 = RingBuffer_write(uVar13,&local_78,8);
  if ((uVar16 & 1) != 0) {
    RingBuffer_write(uVar13,puVar22,8);
  }
  if (*(long *)(lVar9 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00146a14:
  if (puVar22 == (uint64_t *)0x0) {
    puVar28 = (uint64_t *)0x0;
  }
  else {
    puVar19 = (uint64_t *)0x0;
    do {
      puVar28 = puVar22;
      puVar22 = (uint64_t *)puVar28[1];
      puVar28[1] = puVar19;
      puVar19 = puVar28;
    } while (puVar22 != (uint64_t *)0x0);
  }
  puVar1 = (uint32_t *)((long)puVar4 + iVar14 + lVar2);
  *(uint64_t **)((long)pvVar12 + uVar16 * 0x38 + 8) = puVar28;
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x10) = *puVar1;
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x14) = puVar1[1];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x18) = puVar1[2];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x1c) = puVar1[3];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x20) = puVar1[4];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x24) = puVar1[5];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x28) = puVar1[6];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x2c) = puVar1[7];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x38 + 0x30) = puVar1[8];
LAB_00146920:
  uVar16 = uVar16 + 1;
  iVar14 = iVar21 + (int)lVar2;
  if (uVar16 == uVar5) goto LAB_00146a48;
  goto LAB_00146930;
LAB_00146d40:
  if (puVar24 == (uint64_t *)0x0) {
    puVar17 = (uint64_t *)0x0;
  }
  else {
    puVar20 = (uint64_t *)0x0;
    do {
      puVar17 = puVar24;
      puVar24 = (uint64_t *)puVar17[1];
      puVar17[1] = puVar20;
      puVar20 = puVar17;
    } while (puVar24 != (uint64_t *)0x0);
  }
  puVar26 = (uint32_t *)((long)puVar26 + (long)iVar23);
  puVar19[1] = puVar17;
  *(uint32_t *)(puVar19 + 2) = *puVar26;
  *(uint32_t *)((long)puVar19 + 0x14) = puVar26[1];
  *(uint32_t *)(puVar19 + 3) = puVar26[2];
LAB_00146da4:
  iVar21 = iVar21 + (int)uVar29;
  puVar28[1] = puVar22;
  puVar22 = puVar28;
LAB_00146b64:
  piVar18 = (int *)((long)puVar4 + iVar21 + lVar2);
  iVar21 = iVar21 + 4;
  goto LAB_00146b74;
LAB_00146fb0:
  if (puVar22 == (uint64_t *)0x0) {
    puVar28 = (uint64_t *)0x0;
  }
  else {
    puVar19 = (uint64_t *)0x0;
    do {
      puVar28 = puVar22;
      puVar22 = (uint64_t *)puVar28[1];
      puVar28[1] = puVar19;
      puVar19 = puVar28;
    } while (puVar22 != (uint64_t *)0x0);
  }
  *(uint64_t **)((long)pvVar11 + uVar29 * 0x20 + 8) = puVar28;
  puVar1 = (uint32_t *)((long)puVar4 + iVar21 + lVar10);
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x10) = *puVar1;
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x14) = puVar1[1];
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x18) = puVar1[2];
LAB_00146eb8:
  uVar29 = uVar29 + 1;
  iVar23 = iVar23 + (int)lVar3;
  if (uVar29 == uVar6) goto LAB_00146fd0;
  goto LAB_00146ec8;
LAB_00146fd0:
  *(void **)((long)pvVar12 + uVar16 * 0x58 + 0x20) = pvVar11;
LAB_00146ff0:
  puVar1 = (uint32_t *)((long)puVar4 + iVar23 + lVar2);
  iVar23 = iVar23 + 8;
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x58 + 0x28) = *puVar1;
  uVar6 = puVar1[1];
  if (0 < (int)uVar6) {
    iVar8 = uVar6 * 0x20;
    iVar21 = *piVar30 + iVar8;
    if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar11 = (void *)(*(long *)(param_1 + 0x40) + (long)*piVar30);
      *piVar30 = iVar21;
    }
    else {
      pvVar11 = malloc((long)iVar8);
      ArrayList_add(param_1 + 0x50,pvVar11);
    }
    memset(pvVar11,0,(long)iVar8);
    uVar29 = 0;
LAB_001470b8:
    lVar3 = (long)iVar23 + 4;
    iVar23 = *(int *)((long)puVar4 + iVar23 + lVar2);
    if (pvVar11 != (void *)0x0) {
      puVar1 = (uint32_t *)((long)puVar4 + lVar3 + lVar2);
      piVar18 = puVar1 + 1;
      lVar10 = lVar3 + lVar2;
      *(uint32_t *)((long)pvVar11 + uVar29 * 0x20) = *puVar1;
      iVar21 = 8;
      puVar22 = (uint64_t *)0x0;
      do {
        puVar28 = puVar22;
        if (*piVar18 == 0x3b9e7769) {
          iVar8 = *(int *)((long)puVar4 + iVar21 + lVar10);
          uVar27 = (long)iVar21 + 4;
          if (0 < iVar8) {
            iVar21 = *piVar30;
            if ((iVar21 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
              puVar28 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar21);
              *piVar30 = iVar21 + 0x18;
            }
            else {
              puVar28 = malloc(0x18);
              ArrayList_add(param_1 + 0x50,puVar28);
            }
            *puVar28 = 0;
            puVar28[1] = 0;
            puVar28[2] = 0;
            puVar1 = (uint32_t *)((long)puVar4 + uVar27 + lVar10);
            uVar7 = *puVar1;
            puVar28[1] = 0;
            uVar27 = (unsigned long)(uint32_t)(iVar8 + (int)uVar27);
            *(uint32_t *)puVar28 = uVar7;
            uVar7 = puVar1[1];
            puVar28[1] = puVar22;
            *(uint32_t *)(puVar28 + 2) = uVar7;
          }
        }
        else {
          if (*piVar18 == -1) goto LAB_001471a0;
          uVar27 = (unsigned long)(iVar21 + 4);
        }
        piVar18 = (int *)((long)puVar4 + (int)uVar27 + lVar10);
        iVar21 = (int)uVar27 + 4;
        puVar22 = puVar28;
      } while( true );
    }
    goto LAB_001470a8;
  }
  *(uint64_t *)((long)pvVar12 + uVar16 * 0x58 + 0x30) = 0;
LAB_001471e0:
  uVar6 = *(uint32_t *)((long)puVar4 + iVar23 + lVar2);
  iVar23 = iVar23 + 4;
  if (0 < (int)uVar6) {
    iVar8 = uVar6 * 0x20;
    iVar21 = *piVar30 + iVar8;
    if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar11 = (void *)(*(long *)(param_1 + 0x40) + (long)*piVar30);
      *piVar30 = iVar21;
    }
    else {
      pvVar11 = malloc((long)iVar8);
      ArrayList_add(param_1 + 0x50,pvVar11);
    }
    memset(pvVar11,0,(long)iVar8);
    uVar29 = 0;
LAB_00147294:
    lVar3 = (long)iVar23 + 4;
    iVar23 = *(int *)((long)puVar4 + iVar23 + lVar2);
    if (pvVar11 != (void *)0x0) {
      puVar1 = (uint32_t *)((long)puVar4 + lVar3 + lVar2);
      piVar18 = puVar1 + 1;
      lVar10 = lVar3 + lVar2;
      *(uint32_t *)((long)pvVar11 + uVar29 * 0x20) = *puVar1;
      iVar21 = 8;
      puVar22 = (uint64_t *)0x0;
      do {
        puVar28 = puVar22;
        if (*piVar18 == 0x3b9e7769) {
          iVar8 = *(int *)((long)puVar4 + iVar21 + lVar10);
          uVar27 = (long)iVar21 + 4;
          if (0 < iVar8) {
            iVar21 = *piVar30;
            if ((iVar21 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
              puVar28 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar21);
              *piVar30 = iVar21 + 0x18;
            }
            else {
              puVar28 = malloc(0x18);
              ArrayList_add(param_1 + 0x50,puVar28);
            }
            *puVar28 = 0;
            puVar28[1] = 0;
            puVar28[2] = 0;
            puVar1 = (uint32_t *)((long)puVar4 + uVar27 + lVar10);
            uVar7 = *puVar1;
            puVar28[1] = 0;
            uVar27 = (unsigned long)(uint32_t)(iVar8 + (int)uVar27);
            *(uint32_t *)puVar28 = uVar7;
            uVar7 = puVar1[1];
            puVar28[1] = puVar22;
            *(uint32_t *)(puVar28 + 2) = uVar7;
          }
        }
        else {
          if (*piVar18 == -1) goto LAB_0014737c;
          uVar27 = (unsigned long)(iVar21 + 4);
        }
        piVar18 = (int *)((long)puVar4 + (int)uVar27 + lVar10);
        iVar21 = (int)uVar27 + 4;
        puVar22 = puVar28;
      } while( true );
    }
    goto LAB_00147284;
  }
  *(uint64_t *)((long)pvVar12 + uVar16 * 0x58 + 0x38) = 0;
LAB_001473cc:
  uVar29 = (long)iVar23 + 4;
  iVar21 = *(int *)((long)puVar4 + iVar23 + lVar2);
  if (0 < iVar21) {
    iVar23 = *piVar30;
    if ((iVar23 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar22 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar23);
      *piVar30 = iVar23 + 0x20;
    }
    else {
      puVar22 = malloc(0x20);
      ArrayList_add(param_1 + 0x50,puVar22);
    }
    puVar22[1] = 0;
    *puVar22 = 0;
    puVar22[3] = 0;
    puVar22[2] = 0;
    puVar1 = (uint32_t *)((long)puVar4 + uVar29 + lVar2);
    *(uint64_t **)((long)pvVar12 + uVar16 * 0x58 + 0x40) = puVar22;
    piVar18 = puVar1 + 1;
    lVar3 = uVar29 + lVar2;
    *(uint32_t *)puVar22 = *puVar1;
    iVar23 = 8;
    puVar28 = (uint64_t *)0x0;
    do {
      puVar19 = puVar28;
      if (*piVar18 == 0x3b9e7769) {
        iVar8 = *(int *)((long)puVar4 + iVar23 + lVar3);
        uVar27 = (long)iVar23 + 4;
        if (0 < iVar8) {
          iVar23 = *piVar30;
          if ((iVar23 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar19 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar23);
            *piVar30 = iVar23 + 0x18;
          }
          else {
            puVar19 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar19);
          }
          *puVar19 = 0;
          puVar19[1] = 0;
          puVar19[2] = 0;
          puVar1 = (uint32_t *)((long)puVar4 + uVar27 + lVar3);
          uVar7 = *puVar1;
          puVar19[1] = 0;
          uVar27 = (unsigned long)(uint32_t)(iVar8 + (int)uVar27);
          *(uint32_t *)puVar19 = uVar7;
          uVar7 = puVar1[1];
          puVar19[1] = puVar28;
          *(uint32_t *)(puVar19 + 2) = uVar7;
        }
      }
      else {
        if (*piVar18 == -1) goto LAB_0014750c;
        uVar27 = (unsigned long)(iVar23 + 4);
      }
      piVar18 = (int *)((long)puVar4 + (int)uVar27 + lVar3);
      iVar23 = (int)uVar27 + 4;
      puVar28 = puVar19;
    } while( true );
  }
  *(uint64_t *)((long)pvVar12 + uVar16 * 0x58 + 0x40) = 0;
LAB_00147570:
  puVar1 = (uint32_t *)((long)puVar4 + (int)uVar29 + lVar2);
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x58 + 0x48) = *puVar1;
  iVar21 = puVar1[1];
  if (iVar21 < 1) {
    *(uint64_t *)((long)pvVar12 + uVar16 * 0x58 + 0x50) = 0;
  }
  else {
    sVar25 = (long)iVar21 << 2;
    iVar23 = (int)sVar25;
    iVar21 = *piVar30 + iVar23;
    if ((iVar21 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar11 = (void *)(*(long *)(param_1 + 0x40) + (long)*piVar30);
      sVar25 = (size_t)iVar23;
      *piVar30 = iVar21;
    }
    else {
      pvVar11 = malloc(sVar25);
      ArrayList_add(param_1 + 0x50,pvVar11);
    }
    memset(pvVar11,0,sVar25);
    if (pvVar11 != (void *)0x0) {
      memcpy(pvVar11,(void *)((long)puVar4 + (long)(int)uVar29 + 8 + lVar2),(long)iVar23);
    }
    *(void **)((long)pvVar12 + uVar16 * 0x58 + 0x50) = pvVar11;
  }
LAB_00146b00:
  uVar16 = uVar16 + 1;
  iVar21 = iVar14 + (int)lVar2;
  if (uVar16 == uVar5) goto LAB_0014763c;
  goto LAB_00146b10;
LAB_001471a0:
  if (puVar22 == (uint64_t *)0x0) {
    puVar28 = (uint64_t *)0x0;
  }
  else {
    puVar19 = (uint64_t *)0x0;
    do {
      puVar28 = puVar22;
      puVar22 = (uint64_t *)puVar28[1];
      puVar28[1] = puVar19;
      puVar19 = puVar28;
    } while (puVar22 != (uint64_t *)0x0);
  }
  *(uint64_t **)((long)pvVar11 + uVar29 * 0x20 + 8) = puVar28;
  puVar1 = (uint32_t *)((long)puVar4 + iVar21 + lVar10);
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x10) = *puVar1;
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x14) = puVar1[1];
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x18) = puVar1[2];
LAB_001470a8:
  uVar29 = uVar29 + 1;
  iVar23 = iVar23 + (int)lVar3;
  if (uVar29 == uVar6) goto LAB_001471c0;
  goto LAB_001470b8;
LAB_001471c0:
  *(void **)((long)pvVar12 + uVar16 * 0x58 + 0x30) = pvVar11;
  goto LAB_001471e0;
LAB_0014737c:
  if (puVar22 == (uint64_t *)0x0) {
    puVar28 = (uint64_t *)0x0;
  }
  else {
    puVar19 = (uint64_t *)0x0;
    do {
      puVar28 = puVar22;
      puVar22 = (uint64_t *)puVar28[1];
      puVar28[1] = puVar19;
      puVar19 = puVar28;
    } while (puVar22 != (uint64_t *)0x0);
  }
  *(uint64_t **)((long)pvVar11 + uVar29 * 0x20 + 8) = puVar28;
  puVar1 = (uint32_t *)((long)puVar4 + iVar21 + lVar10);
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x10) = *puVar1;
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x14) = puVar1[1];
  *(uint32_t *)((long)pvVar11 + uVar29 * 0x20 + 0x18) = puVar1[2];
LAB_00147284:
  uVar29 = uVar29 + 1;
  iVar23 = iVar23 + (int)lVar3;
  if (uVar29 == uVar6) goto LAB_0014739c;
  goto LAB_00147294;
LAB_0014739c:
  *(void **)((long)pvVar12 + uVar16 * 0x58 + 0x38) = pvVar11;
  goto LAB_001473cc;
LAB_0014750c:
  if (puVar28 == (uint64_t *)0x0) {
    puVar19 = (uint64_t *)0x0;
  }
  else {
    puVar24 = (uint64_t *)0x0;
    do {
      puVar19 = puVar28;
      puVar28 = (uint64_t *)puVar19[1];
      puVar19[1] = puVar24;
      puVar24 = puVar19;
    } while (puVar28 != (uint64_t *)0x0);
  }
  puVar22[1] = puVar19;
  puVar1 = (uint32_t *)((long)puVar4 + iVar23 + lVar3);
  uVar29 = (unsigned long)(uint32_t)((int)uVar29 + iVar21);
  *(uint32_t *)(puVar22 + 2) = *puVar1;
  *(uint32_t *)((long)puVar22 + 0x14) = puVar1[1];
  *(uint32_t *)(puVar22 + 3) = puVar1[2];
  goto LAB_00147570;
LAB_00147838:
  if (puVar22 == (uint64_t *)0x0) {
    puVar28 = (uint64_t *)0x0;
  }
  else {
    puVar19 = (uint64_t *)0x0;
    do {
      puVar28 = puVar22;
      puVar22 = (uint64_t *)puVar28[1];
      puVar28[1] = puVar19;
      puVar19 = puVar28;
    } while (puVar22 != (uint64_t *)0x0);
  }
  puVar1 = (uint32_t *)((long)puVar4 + iVar14 + lVar2);
  *(uint64_t **)((long)pvVar12 + uVar16 * 0x30 + 8) = puVar28;
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x10) = *puVar1;
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x14) = puVar1[1];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x18) = puVar1[2];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x1c) = puVar1[3];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x20) = puVar1[4];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x24) = puVar1[5];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x28) = puVar1[6];
  *(uint32_t *)((long)pvVar12 + uVar16 * 0x30 + 0x2c) = puVar1[7];
LAB_00147734:
  uVar16 = uVar16 + 1;
  iVar14 = iVar21 + (int)lVar2;
  if (uVar16 == uVar5) goto LAB_00147868;
  goto LAB_00147744;
}


/* @00135778  size=1200 */

void vt_handle_vkCreateSampler(long param_1)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint64_t *puVar8;
  uint64_t uVar9;
  int iVar10;
  unsigned long uVar11;
  char *pcVar12;
  uint32_t *puVar13;
  unsigned long uVar14;
  uint64_t *puVar15;
  uint64_t local_c8;
  unsigned long local_c0;
  uint64_t *puStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t local_80;
  uint64_t local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar6 + 0x28);
  pcVar12 = *(char **)(param_1 + 0x30);
  uStack_88 = 0;
  local_90 = 0;
  local_78 = 0;
  local_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  puStack_b8 = (uint64_t *)0x0;
  local_c0 = 0;
  if (*pcVar12 == '\0') {
    uVar11 = 1;
    lVar7 = param_1;
  }
  else {
    uVar11 = 9;
    lVar7 = *(long *)(pcVar12 + 1);
  }
  if (0 < *(int *)(pcVar12 + uVar11)) {
    puVar1 = (uint32_t *)(pcVar12 + (uVar11 | 4));
    puVar13 = puVar1 + 1;
    puVar15 = (uint64_t *)0x0;
    iVar10 = 8;
    local_c0 = (unsigned long)*puVar1;
    do {
      uVar3 = *puVar13;
      if ((int)uVar3 < 0x3b9f2b18) {
        if (uVar3 == 0x3b9cc5d1) {
          iVar5 = *(int *)((long)puVar1 + (long)iVar10);
          uVar11 = (long)iVar10 + 4;
          if (0 < iVar5) {
            iVar10 = *(int *)(param_1 + 0x48);
            if ((iVar10 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
              puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
              *(int *)(param_1 + 0x48) = iVar10 + 0x18;
            }
            else {
              puVar8 = malloc(0x18);
              ArrayList_add(param_1 + 0x50,puVar8);
            }
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            uVar4 = *(uint32_t *)((long)puVar1 + uVar11);
            puVar8[1] = 0;
            uVar14 = (unsigned long)(uint32_t)(iVar5 + (int)uVar11);
            *(uint32_t *)puVar8 = uVar4;
            *(uint32_t *)(puVar8 + 2) = ((uint32_t *)((long)puVar1 + uVar11))[1];
            goto LAB_00135864;
          }
LAB_00135998:
          uVar14 = uVar11 & 0xffffffff;
        }
        else {
          if (uVar3 == 0x3b9d2b61) {
            iVar5 = *(int *)((long)puVar1 + (long)iVar10);
            uVar11 = (long)iVar10 + 4;
            if (iVar5 < 1) goto LAB_00135998;
            iVar10 = *(int *)(param_1 + 0x48);
            if ((iVar10 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
              puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
              *(int *)(param_1 + 0x48) = iVar10 + 0x18;
            }
            else {
              puVar8 = malloc(0x18);
              ArrayList_add(param_1 + 0x50,puVar8);
            }
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            uVar4 = *(uint32_t *)((long)puVar1 + uVar11);
            puVar8[1] = 0;
            *(uint32_t *)puVar8 = uVar4;
            uVar9 = VkObject_fromId(*(uint64_t *)((uint32_t *)((long)puVar1 + uVar11) + 1));
            uVar14 = (unsigned long)(uint32_t)(iVar5 + (int)uVar11);
            puVar8[2] = uVar9;
            goto LAB_00135864;
          }
          if (uVar3 == 0xffffffff) goto LAB_00135a9c;
LAB_001359a8:
          uVar14 = (unsigned long)(iVar10 + 4);
        }
      }
      else {
        if (uVar3 == 0x3b9f2b18) {
          iVar5 = *(int *)((long)puVar1 + (long)iVar10);
          uVar11 = (long)iVar10 + 4;
          if (iVar5 < 1) goto LAB_00135998;
          iVar10 = *(int *)(param_1 + 0x48);
          if ((iVar10 < 0xffd8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
            *(int *)(param_1 + 0x48) = iVar10 + 0x28;
          }
          else {
            puVar8 = malloc(0x28);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          puVar8[4] = 0;
          puVar8[1] = 0;
          *puVar8 = 0;
          puVar8[3] = 0;
          puVar8[2] = 0;
          puVar2 = (uint32_t *)((long)puVar1 + uVar11);
          uVar4 = *puVar2;
          puVar8[1] = 0;
          uVar14 = (unsigned long)(uint32_t)(iVar5 + (int)uVar11);
          *(uint32_t *)puVar8 = uVar4;
          uVar9 = *(uint64_t *)(puVar2 + 1);
          puVar8[3] = *(uint64_t *)(puVar2 + 3);
          puVar8[2] = uVar9;
          *(uint32_t *)(puVar8 + 4) = puVar2[5];
        }
        else {
          if (uVar3 != 0x3ba10f79) goto LAB_001359a8;
          iVar5 = *(int *)((long)puVar1 + (long)iVar10);
          uVar14 = (long)iVar10 + 4;
          if (iVar5 < 1) goto LAB_0013586c;
          iVar10 = *(int *)(param_1 + 0x48);
          if ((iVar10 < 0xffd8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
            *(int *)(param_1 + 0x48) = iVar10 + 0x28;
          }
          else {
            puVar8 = malloc(0x28);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          puVar8[4] = 0;
          puVar8[1] = 0;
          *puVar8 = 0;
          puVar8[3] = 0;
          puVar8[2] = 0;
          puVar2 = (uint32_t *)((long)puVar1 + uVar14);
          uVar4 = *puVar2;
          puVar8[1] = 0;
          uVar14 = (unsigned long)(uint32_t)(iVar5 + (int)uVar14);
          *(uint32_t *)puVar8 = uVar4;
          *(uint32_t *)(puVar8 + 2) = puVar2[1];
          *(uint32_t *)((long)puVar8 + 0x14) = puVar2[2];
          *(uint32_t *)(puVar8 + 3) = puVar2[3];
          *(uint64_t *)((long)puVar8 + 0x1c) = *(uint64_t *)(puVar2 + 4);
        }
LAB_00135864:
        puVar8[1] = puVar15;
        puVar15 = puVar8;
      }
LAB_0013586c:
      puVar13 = (uint32_t *)((long)puVar1 + (long)(int)uVar14);
      iVar10 = (int)uVar14 + 4;
    } while( true );
  }
LAB_00135b54:
  uVar9 = VkObject_fromId(lVar7);
  local_70 = ((generic_fn_t)DAT_00193d10)(uVar9,&local_c0,0,&local_c8);
  iVar10 = *(int *)(param_1 + 0x48);
  if ((iVar10 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar15 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
    *(int *)(param_1 + 0x48) = iVar10 + 8;
  }
  else {
    puVar15 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar15);
  }
  *puVar15 = 0;
  *puVar15 = local_c8;
  uVar9 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar11 = RingBuffer_write(uVar9,&local_70,8);
  if ((uVar11 & 1) != 0) {
    RingBuffer_write(uVar9,puVar15,8);
  }
  if (*(long *)(lVar6 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00135a9c:
  if (puVar15 == (uint64_t *)0x0) {
    puStack_b8 = (uint64_t *)0x0;
  }
  else {
    puVar8 = (uint64_t *)0x0;
    do {
      puStack_b8 = puVar15;
      puVar15 = (uint64_t *)puStack_b8[1];
      puStack_b8[1] = puVar8;
      puVar8 = puStack_b8;
    } while (puVar15 != (uint64_t *)0x0);
  }
  puVar15 = (uint64_t *)((long)puVar1 + (long)iVar10);
  local_b0 = *puVar15;
  uStack_a8 = puVar15[1];
  local_a0 = puVar15[2];
  local_98 = puVar15[3];
  local_90 = puVar15[4];
  uStack_88 = puVar15[5];
  local_80 = puVar15[6];
  local_78 = puVar15[7];
  goto LAB_00135b54;
}


/* @00145e8c  size=392 */

void vt_handle_vkCreateSamplerYcbcrConversion(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  char *pcVar7;
  unsigned long uVar8;
  uint64_t local_88;
  unsigned long local_80 [6];
  uint32_t local_50;
  uint32_t local_4c;
  uint32_t uStack_48;
  uint32_t uStack_44;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_80[5] = 0;
  local_80[4] = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  local_50 = 0;
  local_4c = 0;
  local_80[0] = 0;
  local_80[3] = 0;
  local_80[2] = 0;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
    lVar4 = param_1;
  }
  else {
    uVar8 = 9;
    lVar4 = *(long *)(pcVar7 + 1);
  }
  if (0 < *(int *)(pcVar7 + uVar8)) {
    puVar1 = (uint32_t *)(pcVar7 + (uVar8 | 4));
    local_80[0] = (unsigned long)*puVar1;
    local_80[2] = *(unsigned long *)(puVar1 + 1);
    local_80[3] = *(unsigned long *)(puVar1 + 3);
    local_80[4] = *(unsigned long *)(puVar1 + 5);
    local_80[5] = *(unsigned long *)(puVar1 + 7);
    local_50 = puVar1[9];
    local_4c = (uint32_t)*(uint64_t *)(puVar1 + 10);
    uStack_48 = (uint32_t)((unsigned long)*(uint64_t *)(puVar1 + 10) >> 0x20);
  }
  local_80[1] = 0;
  uVar5 = VkObject_fromId(lVar4);
  local_40 = ((generic_fn_t)DAT_00194088)(uVar5,local_80,0,&local_88);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 8;
  }
  else {
    puVar6 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *puVar6 = 0;
  *puVar6 = local_88;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uStack_3c = 8;
  uVar8 = RingBuffer_write(uVar5,&local_40,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar6,8);
  }
  if (*(long *)(lVar3 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00133384  size=724 */

void vt_handle_vkCreateSemaphore(long param_1)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint64_t *puVar8;
  uint64_t uVar9;
  int iVar10;
  unsigned long uVar11;
  char *pcVar12;
  uint32_t *puVar13;
  uint64_t *puVar14;
  uint64_t local_90;
  unsigned long local_88;
  uint64_t *local_80;
  uint64_t local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar6 + 0x28);
  pcVar12 = *(char **)(param_1 + 0x30);
  local_88 = 0;
  local_80 = (uint64_t *)0x0;
  local_78 = 0;
  if (*pcVar12 == '\0') {
    uVar11 = 1;
    lVar7 = param_1;
  }
  else {
    uVar11 = 9;
    lVar7 = *(long *)(pcVar12 + 1);
  }
  if (0 < *(int *)(pcVar12 + uVar11)) {
    puVar1 = (uint32_t *)(pcVar12 + (uVar11 | 4));
    puVar13 = puVar1 + 1;
    puVar14 = (uint64_t *)0x0;
    iVar10 = 8;
    local_88 = (unsigned long)*puVar1;
    do {
      uVar4 = *puVar13;
      if (uVar4 == 0x3b9bf6c8) {
        iVar5 = *(int *)((long)puVar1 + (long)iVar10);
        uVar11 = (long)iVar10 + 4;
        if (iVar5 < 1) {
          uVar11 = uVar11 & 0xffffffff;
        }
        else {
          iVar10 = *(int *)(param_1 + 0x48);
          if ((iVar10 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
            *(int *)(param_1 + 0x48) = iVar10 + 0x18;
          }
          else {
            puVar8 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          *puVar8 = 0;
          puVar8[1] = 0;
          puVar8[2] = 0;
          uVar4 = iVar5 + (int)uVar11;
          *(uint32_t *)puVar8 = *(uint32_t *)((long)puVar1 + uVar11);
          *(uint32_t *)(puVar8 + 2) = ((uint32_t *)((long)puVar1 + uVar11))[1];
LAB_00133468:
          uVar11 = (unsigned long)uVar4;
          puVar8[1] = puVar14;
          puVar14 = puVar8;
        }
      }
      else if (uVar4 == 0x3b9df29a) {
        iVar5 = *(int *)((long)puVar1 + (long)iVar10);
        uVar11 = (long)iVar10 + 4;
        if (0 < iVar5) {
          iVar10 = *(int *)(param_1 + 0x48);
          if ((iVar10 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
            *(int *)(param_1 + 0x48) = iVar10 + 0x20;
          }
          else {
            puVar8 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          puVar8[1] = 0;
          *puVar8 = 0;
          puVar8[3] = 0;
          puVar8[2] = 0;
          puVar2 = (uint32_t *)((long)puVar1 + uVar11);
          uVar3 = *puVar2;
          puVar8[1] = 0;
          uVar4 = iVar5 + (int)uVar11;
          *(uint32_t *)puVar8 = uVar3;
          *(uint32_t *)(puVar8 + 2) = puVar2[1];
          puVar8[3] = *(uint64_t *)(puVar2 + 2);
          goto LAB_00133468;
        }
      }
      else {
        if (uVar4 == 0xffffffff) goto LAB_00133550;
        uVar11 = (unsigned long)(iVar10 + 4);
      }
      puVar13 = (uint32_t *)((long)puVar1 + (long)(int)uVar11);
      iVar10 = (int)uVar11 + 4;
    } while( true );
  }
LAB_00133584:
  uVar9 = VkObject_fromId(lVar7);
  local_70 = ((generic_fn_t)DAT_00193c18)(uVar9,&local_88,0,&local_90);
  iVar10 = *(int *)(param_1 + 0x48);
  if ((iVar10 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar14 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
    *(int *)(param_1 + 0x48) = iVar10 + 8;
  }
  else {
    puVar14 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar14);
  }
  *puVar14 = 0;
  *puVar14 = local_90;
  uVar9 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  uVar11 = RingBuffer_write(uVar9,&local_70,8);
  if ((uVar11 & 1) != 0) {
    RingBuffer_write(uVar9,puVar14,8);
  }
  if (*(long *)(lVar6 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00133550:
  if (puVar14 == (uint64_t *)0x0) {
    local_80 = (uint64_t *)0x0;
  }
  else {
    puVar8 = (uint64_t *)0x0;
    do {
      local_80 = puVar14;
      puVar14 = (uint64_t *)local_80[1];
      local_80[1] = puVar8;
      puVar8 = local_80;
    } while (puVar14 != (uint64_t *)0x0);
  }
  local_78 = ((uint64_t)((*(uint32_t*)((char*)&local_78 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar1 + (long)iVar10)));
  goto LAB_00133584;
}


/* @00134ad8  size=416 */

void vt_handle_vkCreateShaderModule(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  long lVar3;
  void *__s;
  uint64_t uVar4;
  uint64_t *puVar5;
  unsigned long uVar6;
  char *pcVar7;
  long lVar8;
  uint64_t unaff_x20;
  uint64_t uVar9;
  size_t __size;
  uint64_t local_68;
  uint32_t local_60;
  uint32_t uStack_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar3 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    lVar8 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar7 + 1);
    lVar8 = 9;
  }
  if (*(int *)(pcVar7 + lVar8) < 1) {
    uVar9 = 0;
    __s = (void *)0x0;
  }
  else {
    uVar2 = (uint32_t)lVar8 | 4;
    __size = (size_t)*(int *)(pcVar7 + (unsigned long)uVar2 + 0x10);
    uVar9 = *(uint64_t *)(pcVar7 + (unsigned long)uVar2 + 8);
    iVar1 = *(int *)(param_1 + 0x48) + *(int *)(pcVar7 + (unsigned long)uVar2 + 0x10);
    if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar1;
    }
    else {
      __s = malloc(__size);
      ArrayList_add(param_1 + 0x50,__s);
    }
    memset(__s,0,__size);
    memcpy(__s,pcVar7 + (unsigned long)uVar2 + 0x14,__size);
  }
  uVar4 = VkObject_fromId(unaff_x20);
  local_60 = ShaderInspector_createModule(*(uint64_t *)(param_1 + 0x88),uVar4,__s,uVar9,&local_68)
  ;
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 8;
  }
  else {
    puVar5 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar5);
  }
  *puVar5 = 0;
  *puVar5 = local_68;
  uVar9 = *(uint64_t *)(param_1 + 0x68);
  uStack_5c = 8;
  uVar6 = RingBuffer_write(uVar9,&local_60,8);
  if ((uVar6 & 1) != 0) {
    RingBuffer_write(uVar9,puVar5,8);
  }
  if (*(long *)(lVar3 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013bc50  size=1236 */

void vt_handle_vkCreateSwapchainKHR(long param_1)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  long lVar4;
  uint64_t *puVar5;
  void *pvVar6;
  uint64_t uVar7;
  long lVar8;
  long *plVar9;
  int iVar10;
  uint32_t uVar11;
  unsigned long uVar12;
  char *pcVar13;
  uint32_t *puVar14;
  int iVar15;
  size_t sVar16;
  int iVar17;
  uint64_t *puVar18;
  int local_f0;
  int local_ec;
  uint32_t local_e8 [2];
  unsigned long local_e0;
  uint64_t *puStack_d8;
  uint64_t local_d0;
  uint64_t *local_c8;
  uint64_t local_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t local_a8;
  uint64_t local_a0;
  void *pvStack_98;
  uint64_t local_90;
  uint64_t local_88;
  uint64_t local_80;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  pcVar13 = *(char **)(param_1 + 0x30);
  local_c8 = (uint64_t *)local_e8;
  local_80 = 0;
  pvStack_98 = (void *)0x0;
  local_a0 = 0;
  local_88 = 0;
  local_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  local_a8 = 0;
  local_b0 = 0;
  puStack_d8 = (uint64_t *)0x0;
  local_e0 = 0;
  local_d0 = 0;
  if (*pcVar13 == '\0') {
    uVar12 = 1;
    lVar8 = param_1;
  }
  else {
    uVar12 = 9;
    lVar8 = *(long *)(pcVar13 + 1);
  }
  if (0 < *(int *)(pcVar13 + uVar12)) {
    puVar1 = (uint32_t *)(pcVar13 + (uVar12 | 4));
    puVar14 = puVar1 + 1;
    puVar18 = (uint64_t *)0x0;
    iVar10 = 8;
    local_e0 = (unsigned long)*puVar1;
    do {
      uVar3 = *puVar14;
      if (uVar3 == 0x3b9bb46c) {
        iVar15 = *(int *)((long)puVar1 + (long)iVar10);
        uVar12 = (long)iVar10 + 4;
        if (0 < iVar15) {
          iVar10 = *(int *)(param_1 + 0x48);
          if ((iVar10 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
            *(int *)(param_1 + 0x48) = iVar10 + 0x18;
          }
          else {
            puVar5 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar5);
          }
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          uVar3 = iVar15 + (int)uVar12;
          *(uint32_t *)puVar5 = *(uint32_t *)((long)puVar1 + uVar12);
          *(uint32_t *)(puVar5 + 2) = ((uint32_t *)((long)puVar1 + uVar12))[1];
LAB_0013bd04:
          uVar12 = (unsigned long)uVar3;
          puVar5[1] = puVar18;
          puVar18 = puVar5;
        }
      }
      else if (uVar3 == 0x3b9d0838) {
        iVar15 = *(int *)((long)puVar1 + (long)iVar10);
        uVar12 = (long)iVar10 + 4;
        if (0 < iVar15) {
          iVar10 = *(int *)(param_1 + 0x48);
          if ((iVar10 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar10);
            *(int *)(param_1 + 0x48) = iVar10 + 0x20;
          }
          else {
            puVar5 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar5);
          }
          puVar5[1] = 0;
          *puVar5 = 0;
          puVar5[3] = 0;
          puVar5[2] = 0;
          puVar2 = (uint32_t *)((long)puVar1 + uVar12);
          uVar11 = *puVar2;
          puVar5[1] = 0;
          *(uint32_t *)puVar5 = uVar11;
          *(uint32_t *)(puVar5 + 2) = puVar2[1];
          if ((int)puVar2[2] < 1) {
            puVar5[3] = 0;
          }
          else {
            sVar16 = (long)(int)puVar2[2] << 2;
            iVar17 = (int)sVar16;
            iVar10 = *(int *)(param_1 + 0x48) + iVar17;
            if ((iVar10 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              sVar16 = (size_t)iVar17;
              *(int *)(param_1 + 0x48) = iVar10;
            }
            else {
              pvVar6 = malloc(sVar16);
              ArrayList_add(param_1 + 0x50,pvVar6);
            }
            memset(pvVar6,0,sVar16);
            if (pvVar6 != (void *)0x0) {
              memcpy(pvVar6,puVar2 + 3,(long)iVar17);
            }
            puVar5[3] = pvVar6;
          }
          uVar3 = iVar15 + (int)uVar12;
          goto LAB_0013bd04;
        }
      }
      else {
        if (uVar3 == 0xffffffff) goto LAB_0013bebc;
        uVar12 = (unsigned long)(iVar10 + 4);
      }
      puVar14 = (uint32_t *)((long)puVar1 + (long)(int)uVar12);
      iVar10 = (int)uVar12 + 4;
    } while( true );
  }
LAB_0013c00c:
  uVar11 = 0xc4653600;
  uVar7 = VkObject_fromId(lVar8);
  getWindowExtent(param_1 + 0xd0,local_e8[0],&local_f0);
  if (((*(uint32_t*)((char*)&uStack_b8 + 4)) == local_f0) && ((int)local_b0 == local_ec)) {
    lVar8 = XWindowSwapchain_create
                      (uVar7,*(uint32_t *)(param_1 + 0x7c),&local_e0,param_1 + 0xd0,local_e8[0]);
    uVar11 = 0xfffffffd;
    if (lVar8 != 0) {
      uVar11 = 0;
    }
  }
  else {
    lVar8 = 0;
  }
  iVar10 = *(int *)(param_1 + 0x48);
  if ((iVar10 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    plVar9 = (long *)(*(long *)(param_1 + 0x40) + (long)iVar10);
    *(int *)(param_1 + 0x48) = iVar10 + 8;
  }
  else {
    plVar9 = malloc(8);
    ArrayList_add(param_1 + 0x50,plVar9);
  }
  *plVar9 = lVar8;
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  uStack_6c = 8;
  local_70 = uVar11;
  uVar12 = RingBuffer_write(uVar7,&local_70,8);
  if ((uVar12 & 1) != 0) {
    RingBuffer_write(uVar7,plVar9,8);
  }
  if (*(long *)(lVar4 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0013bebc:
  if (puVar18 == (uint64_t *)0x0) {
    puStack_d8 = (uint64_t *)0x0;
  }
  else {
    puVar5 = (uint64_t *)0x0;
    do {
      puStack_d8 = puVar18;
      puVar18 = (uint64_t *)puStack_d8[1];
      puStack_d8[1] = puVar5;
      puVar5 = puStack_d8;
    } while (puVar18 != (uint64_t *)0x0);
  }
  puVar2 = (uint32_t *)((long)puVar1 + (long)iVar10);
  uVar12 = (long)iVar10 + 0x34;
  local_d0 = ((uint64_t)((*(uint32_t*)((char*)&local_d0 + 4))) << 32 | (uint32_t)(*puVar2));
  *local_c8 = *(uint64_t *)(puVar2 + 1);
  local_c0 = *(uint64_t *)(puVar2 + 3);
  uStack_b8 = *(uint64_t *)(puVar2 + 5);
  local_b0 = *(uint64_t *)(puVar2 + 7);
  local_a8 = *(uint64_t *)(puVar2 + 9);
  local_a0 = ((uint64_t)((*(uint32_t*)((char*)&local_a0 + 4))) << 32 | (uint32_t)(puVar2[0xb]));
  if ((int)puVar2[0xc] < 1) {
    pvStack_98 = (void *)0x0;
  }
  else {
    sVar16 = (long)(int)puVar2[0xc] << 2;
    iVar15 = (int)sVar16;
    iVar10 = *(int *)(param_1 + 0x48) + iVar15;
    if ((iVar10 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      sVar16 = (size_t)iVar15;
      *(int *)(param_1 + 0x48) = iVar10;
    }
    else {
      pvVar6 = malloc(sVar16);
      ArrayList_add(param_1 + 0x50,pvVar6);
    }
    memset(pvVar6,0,sVar16);
    if (pvVar6 != (void *)0x0) {
      memcpy(pvVar6,(void *)((long)puVar1 + uVar12),(long)iVar15);
    }
    uVar12 = (unsigned long)(uint32_t)(iVar15 + (int)uVar12);
    pvStack_98 = pvVar6;
  }
  puVar18 = (uint64_t *)((long)puVar1 + (long)(int)uVar12);
  local_90 = *puVar18;
  local_88 = puVar18[1];
  local_80 = VkObject_fromId(puVar18[2]);
  goto LAB_0013c00c;
}


/* @001340a4  size=152 */

void vt_handle_vkDestroyBuffer(long param_1)

{
  char cVar1;
  long lVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  uint64_t unaff_x21;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
    cVar1 = pcVar5[1];
    lVar2 = param_1;
  }
  else {
    lVar2 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
    cVar1 = pcVar5[9];
  }
  if (cVar1 != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar5 + lVar6 + 1);
  }
  uVar3 = VkObject_fromId(lVar2);
  uVar4 = VkObject_fromId(unaff_x21);
  if (*(long *)(param_1 + 0x80) != 0) {
    TextureDecoder_removeBoundBuffer(*(long *)(param_1 + 0x80),uVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x00134138. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193c78)(uVar3,uVar4,0);
  return;
}


/* @001342a8  size=116 */

void vt_handle_vkDestroyBufferView(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00134318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193c88)(uVar2,uVar3,0);
  return;
}


/* @00137ed0  size=116 */

void vt_handle_vkDestroyCommandPool(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00137f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d90)(uVar2,uVar3,0);
  return;
}


/* @001361ec  size=116 */

void vt_handle_vkDestroyDescriptorPool(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x0013625c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d38)(uVar2,uVar3,0);
  return;
}


/* @00135ddc  size=116 */

void vt_handle_vkDestroyDescriptorSetLayout(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00135e4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d28)(uVar2,uVar3,0);
  return;
}


/* @0012f86c  size=56 */

void vt_handle_vkDestroyDevice(long param_1)

{
  uint64_t uVar1;
  
  if (**(char **)(param_1 + 0x30) != '\0') {
    param_1 = *(long *)(*(char **)(param_1 + 0x30) + 1);
  }
  uVar1 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x0012f8a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193b40)(uVar1,0);
  return;
}


/* @00133808  size=116 */

void vt_handle_vkDestroyEvent(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00133878. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193c30)(uVar2,uVar3,0);
  return;
}


/* @00132e98  size=116 */

void vt_handle_vkDestroyFence(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00132f08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193bf8)(uVar2,uVar3,0);
  return;
}


/* @00136f50  size=116 */

void vt_handle_vkDestroyFramebuffer(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00136fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d68)(uVar2,uVar3,0);
  return;
}


/* @001344a8  size=184 */

void vt_handle_vkDestroyImage(long param_1)

{
  char cVar1;
  long lVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  unsigned long uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x21;
  
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
    cVar1 = pcVar6[1];
    lVar2 = param_1;
  }
  else {
    lVar2 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
    cVar1 = pcVar6[9];
  }
  if (cVar1 != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar6 + lVar7 + 1);
  }
  uVar3 = VkObject_fromId(lVar2);
  uVar4 = VkObject_fromId(unaff_x21);
  if ((*(long *)(param_1 + 0x80) != 0) &&
     (uVar5 = TextureDecoder_containsImage(*(long *)(param_1 + 0x80),uVar4), (uVar5 & 1) != 0)) {
    TextureDecoder_destroyImage(*(uint64_t *)(param_1 + 0x80),uVar3,uVar4);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0013455c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193c98)(uVar3,uVar4,0);
  return;
}


/* @00134a64  size=116 */

void vt_handle_vkDestroyImageView(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00134ad4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193cb0)(uVar2,uVar3,0);
  return;
}


/* @0012e558  size=56 */

void vt_handle_vkDestroyInstance(long param_1)

{
  uint64_t uVar1;
  
  if (**(char **)(param_1 + 0x30) != '\0') {
    param_1 = *(long *)(*(char **)(param_1 + 0x30) + 1);
  }
  uVar1 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x0012e58c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193af8)(uVar1,0);
  return;
}


/* @001352c8  size=116 */

void vt_handle_vkDestroyPipeline(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00135338. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193cf8)(uVar2,uVar3,0);
  return;
}


/* @00134ea8  size=116 */

void vt_handle_vkDestroyPipelineCache(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00134f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193cd0)(uVar2,uVar3,0);
  return;
}


/* @00135704  size=116 */

void vt_handle_vkDestroyPipelineLayout(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00135774. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d08)(uVar2,uVar3,0);
  return;
}


/* @00133c08  size=116 */

void vt_handle_vkDestroyQueryPool(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00133c78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193c58)(uVar2,uVar3,0);
  return;
}


/* @00137be0  size=116 */

void vt_handle_vkDestroyRenderPass(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00137c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d78)(uVar2,uVar3,0);
  return;
}


/* @00135c28  size=116 */

void vt_handle_vkDestroySampler(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00135c98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d18)(uVar2,uVar3,0);
  return;
}


/* @00146014  size=116 */

void vt_handle_vkDestroySamplerYcbcrConversion(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00146084. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00194090)(uVar2,uVar3,0);
  return;
}


/* @00133658  size=116 */

void vt_handle_vkDestroySemaphore(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x001336c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193c20)(uVar2,uVar3,0);
  return;
}


/* @00134c78  size=104 */

void vt_handle_vkDestroyShaderModule(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
  destroyVkObject(0xf,uVar2,uVar3);
  return;
}


/* @0013c124  size=100 */

void vt_handle_vkDestroySwapchainKHR(long param_1)

{
  char cVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
    cVar1 = pcVar4[1];
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
    cVar1 = pcVar4[9];
  }
  if (cVar1 != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + lVar5 + 1);
  }
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
  XWindowSwapchain_destroy(uVar2,uVar3);
  return;
}


/* @00130b34  size=120 */

void vt_handle_vkDeviceWaitIdle(long param_1)

{
  long lVar1;
  uint32_t local_30;
  uint32_t uStack_2c;
  long local_28;
  
  /* stack canary setup */
  local_28 = *(long *)(lVar1 + 0x28);
  VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
  local_30 = ((generic_fn_t)DAT_00193b78)();
  uStack_2c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_30,8);
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00138820  size=188 */

void vt_handle_vkEndCommandBuffer(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  int iVar5;
  void *pcVar6;
  uint64_t *puVar7;
  int iVar8;
  
  puVar7 = *(uint64_t **)(param_1 + 0x30);
  uVar4 = VkObject_fromId(*puVar7);
  iVar5 = *(int *)(param_1 + 0x38);
  if (8 < iVar5) {
    iVar8 = 8;
    do {
      puVar1 = (uint32_t *)((long)puVar7 + (long)iVar8);
      uVar2 = *puVar1;
      uVar3 = puVar1[1];
      *(uint32_t **)(param_1 + 0x30) = puVar1 + 2;
      if (((uVar2 - 100 & 0xffff) < 0xfe) &&
         (pcVar6 = *(void **)(((unsigned long)uVar2 & 0xffff) * 8 + 0x192d88), pcVar6 != (void *)0x0)) {
        ((generic_fn_t)pcVar6)(param_1);
        iVar5 = *(int *)(param_1 + 0x38);
      }
      iVar8 = iVar8 + uVar3 + 8;
      *(uint64_t **)(param_1 + 0x30) = puVar7;
    } while (iVar8 < iVar5);
  }
                    /* WARNING: Could not recover jumptable at 0x001388d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193db8)(uVar4);
  return;
}


/* @0012fc54  size=668 */

void vt_handle_vkEnumerateDeviceExtensionProperties(long param_1)

{
  int iVar1;
  int *piVar2;
  uint32_t uVar3;
  long lVar4;
  void *__s;
  uint64_t uVar5;
  char *pcVar6;
  size_t sVar7;
  uint8_t *__s_00;
  long lVar8;
  int iVar9;
  uint64_t unaff_x20;
  unsigned long uVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  uint32_t uVar14;
  uint32_t local_74;
  int local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  pcVar13 = *(char **)(param_1 + 0x30);
  if (*pcVar13 == '\0') {
    lVar8 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar13 + 1);
    lVar8 = 9;
  }
  uVar3 = *(uint32_t *)(pcVar13 + lVar8);
  uVar10 = (unsigned long)uVar3;
  uVar14 = (uint32_t)lVar8 | 4;
  if (0 < (int)uVar3) {
    iVar9 = *(int *)(param_1 + 0x48) + uVar3;
    if ((iVar9 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar9;
    }
    else {
      __s = malloc(uVar10);
      ArrayList_add(param_1 + 0x50,__s);
    }
    memset(__s,0,uVar10);
    memcpy(__s,pcVar13 + uVar14,uVar10);
    uVar14 = uVar14 + uVar3;
  }
  if (0 < *(int *)(pcVar13 + (int)uVar14)) {
    local_74 = *(uint32_t *)(pcVar13 + (long)(int)uVar14 + 4);
    uVar10 = (unsigned long)(local_74 == 0);
  }
  uVar5 = VkObject_fromId(unaff_x20);
  pcVar6 = (char *)getExposedDeviceExtensionProperties(param_1,uVar5,&local_74);
  pcVar13 = (char *)0x0;
  if ((uVar10 & 1) == 0) {
    pcVar13 = pcVar6;
  }
  iVar9 = 0x11;
  if ((pcVar13 != (char *)0x0) && (uVar10 = (unsigned long)local_74, 0 < (int)local_74)) {
    iVar9 = 0x11;
    pcVar11 = pcVar13;
    do {
      sVar7 = strlen(pcVar11);
      uVar10 = uVar10 - 1;
      iVar9 = iVar9 + (int)sVar7 + 9;
      pcVar11 = pcVar11 + 0x104;
    } while (uVar10 != 0);
  }
  iVar12 = *(int *)(param_1 + 0x48) + iVar9;
  if ((iVar12 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s_00 = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar12;
  }
  else {
    __s_00 = malloc((long)iVar9);
    ArrayList_add(param_1 + 0x50,__s_00);
  }
  memset(__s_00,0,(long)iVar9);
  *__s_00 = 0;
  uVar10 = (unsigned long)local_74;
  *(uint64_t *)(__s_00 + 1) = 0x400000000;
  *(uint32_t *)(__s_00 + 9) = local_74;
  if (pcVar13 == (char *)0x0) {
    *(uint32_t *)(__s_00 + 0xd) = 0;
  }
  else {
    *(uint32_t *)(__s_00 + 0xd) = local_74;
    if (0 < (int)local_74) {
      iVar12 = 0x11;
      do {
        sVar7 = strlen(pcVar13);
        iVar1 = (int)sVar7 + 5;
        lVar8 = (long)iVar12 + 4;
        *(int *)(__s_00 + iVar12) = iVar1;
        piVar2 = (int *)(__s_00 + lVar8);
        sVar7 = strlen(pcVar13);
        iVar12 = (int)sVar7 + 1;
        *piVar2 = iVar12;
        memcpy(piVar2 + 1,pcVar13,(long)iVar12);
        pcVar11 = pcVar13 + 0x100;
        iVar12 = iVar1 + (int)lVar8;
        uVar10 = uVar10 - 1;
        pcVar13 = pcVar13 + 0x104;
        *(uint32_t *)((long)piVar2 + (long)((int)sVar7 + 5)) = *(uint32_t *)pcVar11;
      } while (uVar10 != 0);
    }
  }
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  local_70 = -(uint32_t)(pcVar6 == (char *)0x0);
  iStack_6c = iVar9;
  uVar10 = RingBuffer_write(uVar5,&local_70,8);
  if (((uVar10 & 1) != 0) && (0 < iVar9)) {
    RingBuffer_write(uVar5,__s_00,iVar9);
  }
  if (*(long *)(lVar4 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012f924  size=816 */

void vt_handle_vkEnumerateInstanceExtensionProperties(long param_1)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  long lVar4;
  uint32_t uVar5;
  void *__s;
  char *pcVar6;
  size_t sVar7;
  uint64_t *__s_00;
  uint32_t uVar8;
  uint64_t uVar9;
  unsigned long uVar10;
  int iVar11;
  uint32_t *puVar12;
  uint32_t unaff_w23;
  char *pcVar13;
  int iVar14;
  char *local_98;
  uint32_t local_8c;
  char *local_88;
  char *local_80;
  char *pcStack_78;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  puVar12 = *(uint32_t **)(param_1 + 0x30);
  uVar8 = *puVar12;
  uVar10 = (unsigned long)uVar8;
  if ((int)uVar8 < 1) {
    uVar8 = 4;
  }
  else {
    iVar11 = *(int *)(param_1 + 0x48) + uVar8;
    if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar11;
    }
    else {
      __s = malloc(uVar10);
      ArrayList_add(param_1 + 0x50,__s);
    }
    memset(__s,0,uVar10);
    memcpy(__s,puVar12 + 1,uVar10);
    uVar8 = uVar8 + 4;
  }
  if (0 < *(int *)((long)puVar12 + (unsigned long)uVar8)) {
    unaff_w23 = *(uint32_t *)((long)puVar12 + (unsigned long)uVar8 + 4);
  }
  ((generic_fn_t)DAT_00193b50)(0,&local_8c,0);
  iVar14 = unaff_w23 * 0x104;
  iVar11 = *(int *)(param_1 + 0x48) + iVar14;
  if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    pcVar6 = (char *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar11;
  }
  else {
    pcVar6 = malloc((long)iVar14);
    ArrayList_add(param_1 + 0x50,pcVar6);
  }
  memset(pcVar6,0,(long)iVar14);
  local_98 = pcVar6;
  uVar5 = ((generic_fn_t)DAT_00193b50)(0,&local_8c,pcVar6);
  pcStack_78 = "VK_KHR_xlib_surface";
  local_80 = "VK_KHR_surface";
  local_88 = "VK_KHR_android_surface";
  injectExtensions2(param_1,&local_98,&local_8c,&local_80,2,&local_88,1);
  iVar11 = 0x10;
  uVar8 = local_8c;
  pcVar6 = (char *)0x0;
  if (unaff_w23 != 0) {
    uVar8 = unaff_w23;
    pcVar6 = local_98;
  }
  if ((pcVar6 != (char *)0x0) && (0 < (int)uVar8)) {
    uVar10 = (unsigned long)uVar8;
    iVar11 = 0x10;
    pcVar13 = pcVar6;
    do {
      sVar7 = strlen(pcVar13);
      uVar10 = uVar10 - 1;
      iVar11 = iVar11 + (int)sVar7 + 9;
      pcVar13 = pcVar13 + 0x104;
    } while (uVar10 != 0);
  }
  iVar14 = *(int *)(param_1 + 0x48) + iVar11;
  if ((iVar14 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s_00 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar14;
  }
  else {
    __s_00 = malloc((long)iVar11);
    ArrayList_add(param_1 + 0x50,__s_00);
  }
  memset(__s_00,0,(long)iVar11);
  *(uint32_t *)(__s_00 + 1) = uVar8;
  *__s_00 = 0x400000000;
  if (pcVar6 == (char *)0x0) {
    *(uint32_t *)((long)__s_00 + 0xc) = 0;
  }
  else {
    *(uint32_t *)((long)__s_00 + 0xc) = uVar8;
    if (0 < (int)uVar8) {
      uVar10 = (unsigned long)uVar8;
      iVar14 = 0x10;
      do {
        sVar7 = strlen(pcVar6);
        iVar1 = (int)sVar7 + 5;
        lVar2 = (long)iVar14 + 4;
        *(int *)((long)__s_00 + (long)iVar14) = iVar1;
        piVar3 = (int *)((long)__s_00 + lVar2);
        sVar7 = strlen(pcVar6);
        iVar14 = (int)sVar7 + 1;
        *piVar3 = iVar14;
        memcpy(piVar3 + 1,pcVar6,(long)iVar14);
        pcVar13 = pcVar6 + 0x100;
        iVar14 = iVar1 + (int)lVar2;
        uVar10 = uVar10 - 1;
        pcVar6 = pcVar6 + 0x104;
        *(uint32_t *)((long)piVar3 + (long)((int)sVar7 + 5)) = *(uint32_t *)pcVar13;
      } while (uVar10 != 0);
    }
  }
  uVar9 = *(uint64_t *)(param_1 + 0x68);
  local_70 = uVar5;
  iStack_6c = iVar11;
  uVar10 = RingBuffer_write(uVar9,&local_70,8);
  if (((uVar10 & 1) != 0) && (0 < iVar11)) {
    RingBuffer_write(uVar9,__s_00,iVar11);
  }
  if (*(long *)(lVar4 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012f8a4  size=128 */

void vt_handle_vkEnumerateInstanceVersion(long param_1)

{
  long lVar1;
  unsigned long uVar2;
  uint64_t uVar3;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar1 + 0x28);
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  local_40 = 0x400000000;
  uVar2 = RingBuffer_write(uVar3,&local_40,8);
  if ((uVar2 & 1) != 0) {
    RingBuffer_write(uVar3,param_1 + 4,4);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00142fbc  size=1088 */

void vt_handle_vkEnumeratePhysicalDeviceGroups(long param_1)

{
  int *piVar1;
  int iVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  long lVar5;
  uint64_t *puVar6;
  uint32_t uVar7;
  uint64_t uVar8;
  uint32_t *__ptr;
  uint64_t *puVar9;
  uint8_t *__s;
  unsigned long uVar10;
  long lVar11;
  unsigned long uVar12;
  uint64_t *puVar13;
  uint64_t *puVar14;
  unsigned long uVar15;
  char *pcVar16;
  unsigned long uVar17;
  unsigned long uVar18;
  long lVar19;
  int *piVar20;
  int iVar21;
  uint32_t *puVar22;
  int iVar23;
  uint32_t *puVar24;
  unsigned long unaff_x20;
  uint64_t uVar25;
  uint64_t uVar26;
  uint32_t local_64;
  uint32_t local_60;
  int iStack_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar5 + 0x28);
  pcVar16 = *(char **)(param_1 + 0x30);
  if (*pcVar16 == '\0') {
    uVar17 = 1;
    lVar19 = param_1;
  }
  else {
    uVar17 = 9;
    lVar19 = *(long *)(pcVar16 + 1);
  }
  if (*(int *)(pcVar16 + uVar17) < 1) {
    uVar8 = VkObject_fromId(lVar19);
LAB_0014304c:
    uVar17 = unaff_x20 & 0xffffffff;
    __ptr = calloc(uVar17,0x120);
    if (__ptr != (uint32_t *)0x0) {
      if ((uint32_t)unaff_x20 < 2) {
        uVar18 = 0;
LAB_00143158:
        puVar22 = __ptr + uVar18 * 0x48;
        lVar19 = uVar17 - uVar18;
        do {
          *puVar22 = 0x3b9bdb70;
          lVar19 = lVar19 + -1;
          puVar22 = puVar22 + 0x48;
        } while (lVar19 != 0);
      }
      else {
        uVar18 = unaff_x20 & 0xfffffffe;
        uVar10 = unaff_x20 & 0xfffffffe;
        puVar22 = __ptr;
        do {
          *puVar22 = 0x3b9bdb70;
          puVar22[0x48] = 0x3b9bdb70;
          uVar10 = uVar10 - 2;
          puVar22 = puVar22 + 0x90;
        } while (uVar10 != 0);
        if (uVar18 != uVar17) goto LAB_00143158;
      }
      uVar7 = ((generic_fn_t)DAT_00193ff0)(uVar8,&local_64,__ptr);
      uVar17 = (unsigned long)local_64;
      if ((int)local_64 < 1) {
        iVar21 = 0xd;
      }
      else {
        if (local_64 == 1) {
          uVar18 = 0;
          iVar21 = 0xd;
        }
        else {
          iVar21 = 0;
          uVar18 = uVar17 & 0xfffffffe;
          iVar23 = 0xd;
          uVar10 = uVar17 & 0xfffffffe;
          puVar22 = __ptr;
          do {
            piVar20 = puVar22 + 4;
            piVar1 = puVar22 + 0x4c;
            uVar10 = uVar10 - 2;
            puVar22 = puVar22 + 0x90;
            iVar23 = iVar23 + *piVar20 * 8 + 0x10;
            iVar21 = iVar21 + *piVar1 * 8 + 0x10;
          } while (uVar10 != 0);
          iVar21 = iVar21 + iVar23;
          if (uVar18 == uVar17) goto LAB_00143228;
        }
        lVar19 = uVar17 - uVar18;
        piVar20 = __ptr + uVar18 * 0x48 + 4;
        do {
          iVar23 = *piVar20;
          lVar19 = lVar19 + -1;
          piVar20 = piVar20 + 0x48;
          iVar21 = iVar21 + iVar23 * 8 + 0x10;
        } while (lVar19 != 0);
      }
LAB_00143228:
      iVar23 = *(int *)(param_1 + 0x48) + iVar21;
      if ((iVar23 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
        __s = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
        *(int *)(param_1 + 0x48) = iVar23;
      }
      else {
        __s = malloc((long)iVar21);
        ArrayList_add(param_1 + 0x50,__s);
      }
      memset(__s,0,(long)iVar21);
      *__s = 0;
      *(uint32_t *)(__s + 1) = 4;
      *(uint32_t *)(__s + 5) = local_64;
      *(uint32_t *)(__s + 9) = local_64;
      if (0 < (int)local_64) {
        uVar17 = 0;
        puVar9 = (uint64_t *)(__ptr + 10);
        puVar22 = __ptr + 6;
        iVar23 = 0xd;
        do {
          puVar24 = __ptr + uVar17 * 0x48;
          iVar2 = puVar24[4] * 8 + 0xc;
          lVar19 = (long)iVar23;
          *(int *)(__s + lVar19) = iVar2;
          puVar3 = (uint32_t *)(__s + lVar19 + 4);
          *puVar3 = *puVar24;
          puVar3[1] = puVar24[4];
          uVar4 = puVar24[4];
          uVar10 = (unsigned long)uVar4;
          if (uVar4 == 0) {
            uVar18 = 8;
          }
          else {
            if (uVar4 < 4) {
              uVar12 = 0;
              uVar18 = 8;
LAB_0014336c:
              lVar11 = uVar10 - uVar12;
              puVar13 = (uint64_t *)(puVar22 + uVar12 * 2);
              do {
                lVar11 = lVar11 + -1;
                *(uint64_t *)((long)puVar3 + uVar18) = *puVar13;
                uVar18 = uVar18 + 8;
                puVar13 = puVar13 + 1;
              } while (lVar11 != 0);
            }
            else {
              uVar12 = uVar10 & 0xfffffffc;
              puVar14 = (uint64_t *)(__s + lVar19 + 0x1c);
              uVar18 = (uVar12 >> 2) << 5 | 8;
              uVar15 = uVar10 & 0xfffffffc;
              puVar13 = puVar9;
              do {
                puVar6 = puVar13 + -1;
                uVar8 = puVar13[-2];
                uVar26 = puVar13[1];
                uVar25 = *puVar13;
                uVar15 = uVar15 - 4;
                puVar13 = puVar13 + 4;
                puVar14[-1] = *puVar6;
                puVar14[-2] = uVar8;
                puVar14[1] = uVar26;
                *puVar14 = uVar25;
                puVar14 = puVar14 + 4;
              } while (uVar15 != 0);
              if (uVar12 != uVar10) goto LAB_0014336c;
            }
            uVar18 = uVar18 & 0xfffffff8;
          }
          iVar23 = iVar2 + (int)(lVar19 + 4);
          lVar19 = uVar17 * 0x48;
          uVar17 = uVar17 + 1;
          puVar9 = puVar9 + 0x24;
          puVar22 = puVar22 + 0x48;
          *(uint32_t *)((long)puVar3 + uVar18) = __ptr[lVar19 + 0x46];
        } while (uVar17 != local_64);
      }
      uVar8 = *(uint64_t *)(param_1 + 0x68);
      local_60 = uVar7;
      iStack_5c = iVar21;
      uVar17 = RingBuffer_write(uVar8,&local_60,8);
      if (((uVar17 & 1) != 0) && (0 < iVar21)) {
        RingBuffer_write(uVar8,__s,iVar21);
      }
      free(__ptr);
      goto LAB_001433cc;
    }
  }
  else {
    uVar4 = *(uint32_t *)(pcVar16 + (uVar17 | 4));
    unaff_x20 = (unsigned long)uVar4;
    local_64 = uVar4;
    uVar8 = VkObject_fromId(lVar19);
    if (uVar4 != 0) goto LAB_0014304c;
  }
  local_60 = ((generic_fn_t)DAT_00193ff0)(uVar8,&local_64,0);
  iVar21 = *(int *)(param_1 + 0x48);
  if ((iVar21 < 0xfff3) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar9 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar21);
    *(int *)(param_1 + 0x48) = iVar21 + 0xd;
  }
  else {
    puVar9 = malloc(0xd);
    ArrayList_add(param_1 + 0x50,puVar9);
  }
  *puVar9 = 0;
  *(uint8_t *)puVar9 = 0;
  *(uint32_t *)((long)puVar9 + 1) = 4;
  *(uint64_t *)((long)puVar9 + 5) = 0;
  *(uint32_t *)((long)puVar9 + 9) = 0;
  *(uint32_t *)((long)puVar9 + 5) = local_64;
  uVar8 = *(uint64_t *)(param_1 + 0x68);
  iStack_5c = 0xd;
  uVar17 = RingBuffer_write(uVar8,&local_60,8);
  if ((uVar17 & 1) != 0) {
    RingBuffer_write(uVar8,puVar9,0xd);
  }
LAB_001433cc:
  if (*(long *)(lVar5 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012e590  size=552 */

void vt_handle_vkEnumeratePhysicalDevices(long param_1)

{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  long lVar4;
  uint64_t *puVar5;
  uint32_t uVar6;
  uint64_t uVar7;
  uint8_t *__s;
  char *pcVar8;
  long lVar9;
  unsigned long uVar10;
  unsigned long uVar11;
  uint64_t *puVar12;
  unsigned long uVar13;
  uint64_t *puVar14;
  unsigned long uVar15;
  unsigned long unaff_x20;
  void *__ptr;
  uint64_t uVar16;
  uint64_t uVar17;
  uint32_t local_64;
  uint32_t local_60;
  int iStack_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar10 = 1;
    lVar9 = param_1;
  }
  else {
    uVar10 = 9;
    lVar9 = *(long *)(pcVar8 + 1);
  }
  if (*(int *)(pcVar8 + uVar10) < 1) {
    uVar7 = VkObject_fromId(lVar9);
LAB_0012e610:
    __ptr = calloc(unaff_x20 & 0xffffffff,8);
  }
  else {
    uVar3 = *(uint32_t *)(pcVar8 + (uVar10 | 4));
    unaff_x20 = (unsigned long)uVar3;
    local_64 = uVar3;
    uVar7 = VkObject_fromId(lVar9);
    if (uVar3 != 0) goto LAB_0012e610;
    __ptr = (void *)0x0;
  }
  uVar6 = ((generic_fn_t)DAT_00193b00)(uVar7,&local_64,__ptr);
  iVar2 = 0xd;
  if (local_64 != 0 && __ptr != (void *)0x0) {
    iVar2 = local_64 * 8 + 0xd;
  }
  iVar1 = iVar2 + *(int *)(param_1 + 0x48);
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s = malloc((long)iVar2);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar2);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 4;
  uVar10 = (unsigned long)local_64;
  *(uint32_t *)(__s + 5) = local_64;
  if (__ptr == (void *)0x0) {
    *(uint32_t *)(__s + 9) = 0;
  }
  else {
    *(uint32_t *)(__s + 9) = local_64;
    if (local_64 != 0) {
      if (local_64 < 4) {
        uVar11 = 0;
        uVar13 = 0xd;
      }
      else {
        uVar11 = uVar10 & 0xfffffffc;
        puVar12 = (uint64_t *)((long)__ptr + 0x10);
        puVar14 = (uint64_t *)(__s + 0x1d);
        uVar13 = (uVar11 >> 2) << 5 | 0xd;
        uVar15 = uVar10 & 0xfffffffc;
        do {
          puVar5 = puVar12 + -1;
          uVar7 = puVar12[-2];
          uVar17 = puVar12[1];
          uVar16 = *puVar12;
          puVar12 = puVar12 + 4;
          uVar15 = uVar15 - 4;
          puVar14[-1] = *puVar5;
          puVar14[-2] = uVar7;
          puVar14[1] = uVar17;
          *puVar14 = uVar16;
          puVar14 = puVar14 + 4;
        } while (uVar15 != 0);
        if (uVar11 == uVar10) goto LAB_0012e748;
      }
      lVar9 = uVar10 - uVar11;
      puVar12 = (uint64_t *)((long)__ptr + uVar11 * 8);
      puVar14 = (uint64_t *)(__s + uVar13);
      do {
        lVar9 = lVar9 + -1;
        *puVar14 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar14 = puVar14 + 1;
      } while (lVar9 != 0);
    }
  }
LAB_0012e748:
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  local_60 = uVar6;
  iStack_5c = iVar2;
  uVar10 = RingBuffer_write(uVar7,&local_60,8);
  if (((uVar10 & 1) != 0) && (0 < iVar2)) {
    RingBuffer_write(uVar7,__s,iVar2);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (*(long *)(lVar4 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001311c8  size=380 */

void vt_handle_vkFlushMappedMemoryRanges(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char cVar4;
  long lVar5;
  uint32_t uVar6;
  int iVar7;
  char *pcVar8;
  long lVar9;
  unsigned long uVar10;
  long *plVar11;
  uint64_t auStack_90;
  uint64_t local_88;
  long local_80;
  uint8_t *local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  local_80 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_80 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar9 = 1;
    lVar5 = param_1;
  }
  else {
    lVar9 = 9;
    lVar5 = *(long *)(pcVar8 + 1);
  }
  uVar3 = *(uint32_t *)(pcVar8 + lVar9);
  local_88 = VkObject_fromId(lVar5);
  lVar5 = -((unsigned long)uVar3 * 0x28 + 0xf & 0x7ffffffff0);
  local_78 = auStack_90 + lVar5;
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar6 = 9;
  if (*pcVar8 == '\0') {
    uVar6 = 1;
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar6 + 4);
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)uVar6 + 4)) {
    iVar7 = uVar6 + 8;
    plVar11 = (long *)((long)&local_80 + lVar5);
    do {
      lVar5 = (long)iVar7 + 4;
      pcVar1 = pcVar8 + lVar5;
      uVar2 = *(uint32_t *)pcVar1;
      iVar7 = *(int *)(pcVar8 + iVar7);
      plVar11[-1] = 0;
      cVar4 = vortekSerializerCastVkObject;
      *(uint32_t *)(plVar11 + -2) = uVar2;
      lVar9 = VkObject_fromId(*(uint64_t *)(pcVar1 + 4));
      if (cVar4 != '\0') {
        lVar9 = *(long *)(lVar9 + 0x18);
      }
      *plVar11 = lVar9;
      uVar10 = uVar10 - 1;
      plVar11[1] = *(long *)(pcVar1 + 0xc);
      iVar7 = iVar7 + (int)lVar5;
      plVar11[2] = *(long *)(pcVar1 + 0x14);
      plVar11 = plVar11 + 5;
    } while (uVar10 != 0);
  }
  local_70 = ((generic_fn_t)DAT_00193ba0)(local_88,(unsigned long)uVar3,local_78);
  uStack_6c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_70,8);
  if (*(long *)(local_80 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013821c  size=312 */

void vt_handle_vkFreeCommandBuffers(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t uVar9;
  long lVar10;
  unsigned long uVar11;
  unsigned long uVar12;
  uint64_t unaff_x22;
  uint64_t *puVar13;
  uint64_t *puVar14;
  long alStack_60 [2];
  
  /* stack canary setup */
  alStack_60[1] = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar10 = 1;
    lVar4 = param_1;
  }
  else {
    lVar10 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar12 = lVar10 + 1;
  if (pcVar8[lVar10] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar8 + uVar12);
    uVar12 = (unsigned long)((int)lVar10 + 9);
  }
  uVar2 = *(uint32_t *)(pcVar8 + uVar12);
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x22);
  puVar13 = (uint64_t *)((long)alStack_60 - ((unsigned long)uVar2 * 8 + 0xf & 0xffffffff0));
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  uVar1 = uVar9;
  if (*pcVar8 == '\0') {
    uVar1 = 1;
  }
  if (pcVar8[uVar1] == '\0') {
    uVar9 = 1;
  }
  uVar11 = (unsigned long)(uVar9 + uVar1) | 4;
  uVar12 = (unsigned long)*(uint32_t *)(pcVar8 + uVar11);
  if (0 < (int)*(uint32_t *)(pcVar8 + uVar11)) {
    pcVar8 = pcVar8 + uVar11 + 4;
    puVar14 = puVar13;
    do {
      uVar7 = VkObject_fromId(*(uint64_t *)pcVar8);
      uVar12 = uVar12 - 1;
      *puVar14 = uVar7;
      pcVar8 = pcVar8 + 8;
      puVar14 = puVar14 + 1;
    } while (uVar12 != 0);
  }
  ((generic_fn_t)DAT_00193da8)(uVar5,uVar6,(unsigned long)uVar2,puVar13);
  if (*(long *)(lVar3 + 0x28) == alStack_60[1]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013672c  size=312 */

void vt_handle_vkFreeDescriptorSets(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t uVar9;
  long lVar10;
  unsigned long uVar11;
  unsigned long uVar12;
  uint64_t unaff_x22;
  uint64_t *puVar13;
  uint64_t *puVar14;
  long alStack_60 [2];
  
  /* stack canary setup */
  alStack_60[1] = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar10 = 1;
    lVar4 = param_1;
  }
  else {
    lVar10 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar12 = lVar10 + 1;
  if (pcVar8[lVar10] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar8 + uVar12);
    uVar12 = (unsigned long)((int)lVar10 + 9);
  }
  uVar2 = *(uint32_t *)(pcVar8 + uVar12);
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x22);
  puVar13 = (uint64_t *)((long)alStack_60 - ((unsigned long)uVar2 * 8 + 0xf & 0xffffffff0));
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  uVar1 = uVar9;
  if (*pcVar8 == '\0') {
    uVar1 = 1;
  }
  if (pcVar8[uVar1] == '\0') {
    uVar9 = 1;
  }
  uVar11 = (unsigned long)(uVar9 + uVar1) | 4;
  uVar12 = (unsigned long)*(uint32_t *)(pcVar8 + uVar11);
  if (0 < (int)*(uint32_t *)(pcVar8 + uVar11)) {
    pcVar8 = pcVar8 + uVar11 + 4;
    puVar14 = puVar13;
    do {
      uVar7 = VkObject_fromId(*(uint64_t *)pcVar8);
      uVar12 = uVar12 - 1;
      *puVar14 = uVar7;
      pcVar8 = pcVar8 + 8;
      puVar14 = puVar14 + 1;
    } while (uVar12 != 0);
  }
  ((generic_fn_t)DAT_00193d50)(uVar5,uVar6,(unsigned long)uVar2,puVar13);
  if (*(long *)(lVar3 + 0x28) == alStack_60[1]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00131074  size=116 */

void vt_handle_vkFreeMemory(long param_1)

{
  char cVar1;
  long lVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  uint64_t unaff_x20;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
    cVar1 = pcVar5[1];
    lVar2 = param_1;
  }
  else {
    lVar2 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
    cVar1 = pcVar5[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar5 + lVar6 + 1);
  }
  uVar3 = VkObject_fromId(lVar2);
  uVar4 = VkObject_fromId(unaff_x20);
  ResourceMemory_free(param_1,uVar3,uVar4);
  return;
}


/* @001486d0  size=244 */

void vt_handle_vkGetBufferDeviceAddress(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  char *pcVar3;
  unsigned long uVar4;
  uint64_t unaff_x20;
  uint64_t local_60;
  unsigned long local_58 [5];
  
  /* stack canary setup */
  local_58[4] = *(long *)(lVar1 + 0x28);
  pcVar3 = *(char **)(param_1 + 0x30);
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  if (*pcVar3 == '\0') {
    uVar4 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar3 + 1);
    uVar4 = 9;
  }
  if (0 < *(int *)(pcVar3 + uVar4)) {
    local_58[1] = 0;
    local_58[0] = (unsigned long)*(uint32_t *)(pcVar3 + (uVar4 | 4));
    local_58[2] = VkObject_fromId(*(uint64_t *)((long)(pcVar3 + (uVar4 | 4)) + 4));
  }
  uVar2 = VkObject_fromId(unaff_x20);
  local_60 = ((generic_fn_t)DAT_00194140)(uVar2,local_58);
  uVar2 = *(uint64_t *)(param_1 + 0x68);
  local_58[3] = 0x800000000;
  uVar4 = RingBuffer_write(uVar2,local_58 + 3,8);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar2,&local_60,8);
  }
  if (*(long *)(lVar1 + 0x28) == local_58[4]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001315a0  size=328 */

void vt_handle_vkGetBufferMemoryRequirements(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t *puVar7;
  unsigned long uVar8;
  char *pcVar9;
  long lVar10;
  uint64_t unaff_x20;
  uint64_t local_58;
  uint64_t local_50;
  uint64_t local_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    lVar10 = 1;
    cVar1 = pcVar9[1];
    lVar4 = param_1;
  }
  else {
    lVar4 = *(long *)(pcVar9 + 1);
    lVar10 = 9;
    cVar1 = pcVar9[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar9 + lVar10 + 1);
  }
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x20);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  ((generic_fn_t)DAT_00193bb8)(uVar5,uVar6,&local_58);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xffec) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar7 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 0x14;
  }
  else {
    puVar7 = malloc(0x14);
    ArrayList_add(param_1 + 0x50,puVar7);
  }
  *puVar7 = 0;
  puVar7[1] = 0;
  *(uint32_t *)(puVar7 + 2) = 0;
  *puVar7 = local_58;
  local_40 = 0x1400000000;
  puVar7[1] = local_50;
  *(uint32_t *)(puVar7 + 2) = (uint32_t)local_48;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uVar8 = RingBuffer_write(uVar5,&local_40,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar7,0x14);
  }
  if (*(long *)(lVar3 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00144510  size=892 */

void vt_handle_vkGetBufferMemoryRequirements2(long param_1)

{
  uint32_t *puVar1;
  long lVar2;
  uint64_t uVar3;
  uint32_t *__s;
  int iVar4;
  uint32_t uVar5;
  unsigned long uVar6;
  long lVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  uint64_t unaff_x20;
  char *pcVar12;
  char *pcVar13;
  int *piVar14;
  uint64_t local_b0;
  int *piStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  unsigned long local_88 [3];
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar2 + 0x28);
  pcVar12 = *(char **)(param_1 + 0x30);
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_90 = 0;
  piStack_a8 = (int *)0x0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  if (*pcVar12 == '\0') {
    uVar6 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar12 + 1);
    uVar6 = 9;
  }
  iVar4 = *(int *)(pcVar12 + uVar6);
  uVar6 = uVar6 | 4;
  if (0 < iVar4) {
    local_88[1] = 0;
    local_88[0] = (unsigned long)*(uint32_t *)(pcVar12 + uVar6);
    local_88[2] = VkObject_fromId(*(uint64_t *)((long)(pcVar12 + uVar6) + 4));
    uVar6 = (unsigned long)(uint32_t)((int)uVar6 + iVar4);
  }
  lVar7 = (long)(int)uVar6;
  if (0 < *(int *)(pcVar12 + lVar7)) {
    pcVar13 = pcVar12 + lVar7 + 4;
    iVar4 = 8;
    local_b0 = ((uint64_t)((*(uint32_t*)((char*)&local_b0 + 4))) << 32 | (uint32_t)(*(uint32_t *)pcVar13));
    piVar11 = (int *)(pcVar12 + lVar7 + 8);
    piVar14 = (int *)0x0;
    do {
      piVar9 = piVar14;
      if (*piVar11 == 0x3b9cba18) {
        iVar8 = *(int *)(pcVar13 + iVar4);
        uVar6 = (long)iVar4 + 4;
        if (0 < iVar8) {
          iVar4 = *(int *)(param_1 + 0x48);
          if ((iVar4 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            piVar9 = (int *)(*(long *)(param_1 + 0x40) + (long)iVar4);
            *(int *)(param_1 + 0x48) = iVar4 + 0x18;
          }
          else {
            piVar9 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,piVar9);
          }
          piVar9[0] = 0;
          piVar9[1] = 0;
          piVar9[2] = 0;
          piVar9[3] = 0;
          piVar9[4] = 0;
          piVar9[5] = 0;
          piVar11 = (int *)(pcVar13 + uVar6);
          uVar6 = (unsigned long)(uint32_t)(iVar8 + (int)uVar6);
          *piVar9 = *piVar11;
          piVar9[4] = piVar11[1];
          iVar4 = piVar11[2];
          *(int **)(piVar9 + 2) = piVar14;
          piVar9[5] = iVar4;
        }
      }
      else {
        if (*piVar11 == -1) goto LAB_00144680;
        uVar6 = (unsigned long)(iVar4 + 4);
      }
      piVar11 = (int *)(pcVar13 + (int)uVar6);
      iVar4 = (int)uVar6 + 4;
      piVar14 = piVar9;
    } while( true );
  }
LAB_001446c4:
  uVar3 = VkObject_fromId(unaff_x20);
  ((generic_fn_t)DAT_00194058)(uVar3,local_88,&local_b0);
  if (piStack_a8 == (int *)0x0) {
    iVar4 = 0x1c;
  }
  else {
    iVar4 = 4;
    piVar11 = piStack_a8;
    do {
      iVar10 = *piVar11;
      piVar11 = *(int **)(piVar11 + 2);
      iVar8 = 0x14;
      if (iVar10 != 0x3b9cba18) {
        iVar8 = 8;
      }
      iVar4 = iVar8 + iVar4;
    } while (piVar11 != (int *)0x0);
    iVar4 = iVar4 + 0x18;
  }
  iVar8 = *(int *)(param_1 + 0x48) + iVar4;
  if ((iVar8 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar8;
  }
  else {
    __s = malloc((long)iVar4);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar4);
  *__s = (uint32_t)local_b0;
  if (piStack_a8 == (int *)0x0) {
    uVar5 = 4;
  }
  else {
    uVar5 = 4;
    piVar11 = piStack_a8;
    do {
      iVar8 = *piVar11;
      *(int *)((long)__s + (unsigned long)uVar5) = iVar8;
      piVar9 = *(int **)(piVar11 + 2);
      piVar14 = (int *)((long)__s + (unsigned long)(uVar5 + 4));
      if (iVar8 == 0x3b9cba18) {
        piVar14[0] = 0xc;
        piVar14[1] = 0x3b9cba18;
        *(int *)((long)__s + (unsigned long)(uVar5 + 8) + 4) = piVar11[4];
        iVar8 = piVar11[5];
        piVar14 = (int *)((long)__s + (unsigned long)(uVar5 + 8) + 8);
        iVar10 = 0x14;
      }
      else {
        iVar8 = 0;
        iVar10 = 8;
      }
      *piVar14 = iVar8;
      uVar5 = iVar10 + uVar5;
      *(int **)(piVar11 + 2) = piVar9;
      piVar11 = piVar9;
    } while (piVar9 != (int *)0x0);
  }
  puVar1 = (uint32_t *)((long)__s + (long)(int)uVar5);
  *puVar1 = 0xffffffff;
  *(uint64_t *)(puVar1 + 1) = local_a0;
  *(uint64_t *)(puVar1 + 3) = local_98;
  puVar1[5] = (uint32_t)local_90;
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  local_70 = 0;
  iStack_6c = iVar4;
  uVar6 = RingBuffer_write(uVar3,&local_70,8);
  if (((uVar6 & 1) != 0) && (0 < iVar4)) {
    RingBuffer_write(uVar3,__s,iVar4);
  }
  if (*(long *)(lVar2 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00144680:
  if (piVar14 == (int *)0x0) {
    piStack_a8 = (int *)0x0;
  }
  else {
    piVar11 = (int *)0x0;
    do {
      piStack_a8 = piVar14;
      piVar14 = *(int **)(piStack_a8 + 2);
      *(int **)(piStack_a8 + 2) = piVar11;
      piVar11 = piStack_a8;
    } while (piVar14 != (int *)0x0);
  }
  pcVar13 = pcVar13 + iVar4;
  local_a0 = *(uint64_t *)pcVar13;
  local_98 = *(uint64_t *)(pcVar13 + 8);
  local_90 = ((uint64_t)((*(uint32_t*)((char*)&local_90 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar13 + 0x10)));
  goto LAB_001446c4;
}


/* @001485dc  size=244 */

void vt_handle_vkGetBufferOpaqueCaptureAddress(long param_1)

{
  long lVar1;
  uint64_t uVar2;
  char *pcVar3;
  unsigned long uVar4;
  uint64_t unaff_x20;
  uint64_t local_60;
  unsigned long local_58 [5];
  
  /* stack canary setup */
  local_58[4] = *(long *)(lVar1 + 0x28);
  pcVar3 = *(char **)(param_1 + 0x30);
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  if (*pcVar3 == '\0') {
    uVar4 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar3 + 1);
    uVar4 = 9;
  }
  if (0 < *(int *)(pcVar3 + uVar4)) {
    local_58[1] = 0;
    local_58[0] = (unsigned long)*(uint32_t *)(pcVar3 + (uVar4 | 4));
    local_58[2] = VkObject_fromId(*(uint64_t *)((long)(pcVar3 + (uVar4 | 4)) + 4));
  }
  uVar2 = VkObject_fromId(unaff_x20);
  local_60 = ((generic_fn_t)DAT_00194138)(uVar2,local_58);
  uVar2 = *(uint64_t *)(param_1 + 0x68);
  local_58[3] = 0x800000000;
  uVar4 = RingBuffer_write(uVar2,local_58 + 3,8);
  if ((uVar4 & 1) != 0) {
    RingBuffer_write(uVar2,&local_60,8);
  }
  if (*(long *)(lVar1 + 0x28) == local_58[4]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00146590  size=504 */

void vt_handle_vkGetCalibratedTimestampsKHR(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  uint8_t *__s;
  uint8_t *puVar7;
  char *pcVar8;
  uint32_t uVar9;
  long lVar10;
  unsigned long uVar11;
  uint32_t *puVar12;
  int iVar13;
  unsigned long uVar14;
  size_t __n;
  uint64_t auStack_70;
  uint64_t local_68;
  int local_60 [2];
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar10 = 1;
    lVar5 = param_1;
  }
  else {
    lVar10 = 9;
    lVar5 = *(long *)(pcVar8 + 1);
  }
  uVar3 = *(uint32_t *)(pcVar8 + lVar10);
  uVar14 = (unsigned long)uVar3;
  uVar6 = VkObject_fromId(lVar5);
  lVar5 = -(uVar14 * 0x18 + 0xf & 0x3ffffffff0);
  puVar7 = auStack_70 + lVar5;
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  uVar11 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 4);
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 4)) {
    iVar13 = uVar9 + 8;
    puVar12 = (uint32_t *)((long)local_60 + lVar5);
    do {
      lVar5 = (long)iVar13 + 4;
      uVar2 = *(uint32_t *)(pcVar8 + lVar5);
      iVar13 = *(int *)(pcVar8 + iVar13);
      *(uint64_t *)(puVar12 + -2) = 0;
      uVar11 = uVar11 - 1;
      puVar12[-4] = uVar2;
      iVar13 = iVar13 + (int)lVar5;
      *puVar12 = *(uint32_t *)(pcVar8 + lVar5 + 4);
      puVar12 = puVar12 + 6;
    } while (uVar11 != 0);
  }
  ((generic_fn_t)DAT_001940b0)(uVar6,uVar14,puVar7,puVar7 + -(uVar14 * 8 + 0xf & 0xffffffff0),&local_68);
  iVar13 = uVar3 * 8 + 0x19;
  iVar1 = *(int *)(param_1 + 0x48) + iVar13;
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s = malloc((long)iVar13);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar13);
  *(uint32_t *)(__s + 1) = uVar3;
  *(uint32_t *)(__s + 9) = uVar3;
  __n = (size_t)(int)(uVar3 * 8);
  *__s = 0;
  *(uint32_t *)(__s + 5) = 0;
  memcpy(__s + 0xd,puVar7 + -(uVar14 * 8 + 0xf & 0xffffffff0),__n);
  *(uint32_t *)(__s + __n + 0xd) = 8;
  *(uint64_t *)(__s + __n + 0x11) = local_68;
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_60[0] = 0;
  local_60[1] = iVar13;
  uVar14 = RingBuffer_write(uVar6,local_60,8);
  if (((uVar14 & 1) != 0) && (0 < iVar13)) {
    RingBuffer_write(uVar6,__s,iVar13);
  }
  if (*(long *)(lVar4 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001461d0  size=528 */

void vt_handle_vkGetDescriptorSetLayoutSupport(long param_1)

{
  int iVar1;
  long lVar2;
  uint64_t uVar3;
  uint32_t *__s;
  int iVar4;
  char *pcVar5;
  long lVar6;
  uint32_t uVar7;
  unsigned long uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint64_t unaff_x20;
  uint64_t local_88;
  int *local_80;
  uint64_t local_78;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t uStack_60;
  uint64_t uStack_58;
  uint32_t local_50;
  int iStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  pcVar5 = *(char **)(param_1 + 0x30);
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar5 + 1);
    lVar6 = 9;
  }
  if (0 < *(int *)(pcVar5 + lVar6)) {
    FUN_0014e534(&local_70,pcVar5 + ((uint32_t)lVar6 | 4),param_1 + 0x40);
  }
  uVar3 = VkObject_fromId(unaff_x20);
  local_88 = 0;
  local_80 = (int *)0x0;
  local_78 = 0;
  ((generic_fn_t)DAT_001940a0)(uVar3,&local_70,&local_88);
  if (local_80 == (int *)0x0) {
    iVar11 = 0xc;
  }
  else {
    iVar4 = 4;
    piVar9 = local_80;
    do {
      iVar1 = *piVar9;
      piVar9 = *(int **)(piVar9 + 2);
      iVar11 = iVar4 + 8;
      if (iVar1 != 0x3b9d3eec) {
        iVar11 = iVar4;
      }
      iVar4 = iVar11 + 8;
    } while (piVar9 != (int *)0x0);
    iVar11 = iVar11 + 0x10;
  }
  iVar4 = *(int *)(param_1 + 0x48) + iVar11;
  if ((iVar4 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar4;
  }
  else {
    __s = malloc((long)iVar11);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar11);
  *__s = (uint32_t)local_88;
  if (local_80 == (int *)0x0) {
    uVar7 = 4;
  }
  else {
    uVar8 = 4;
    piVar9 = local_80;
    do {
      iVar4 = *piVar9;
      lVar6 = (long)(int)uVar8;
      *(int *)((long)__s + lVar6) = iVar4;
      piVar10 = *(int **)(piVar9 + 2);
      if (iVar4 == 0x3b9d3eec) {
        uVar8 = lVar6 + 8;
        *(uint32_t *)((long)__s + lVar6 + 4) = 8;
        *(uint32_t *)((long)__s + uVar8) = 0x3b9d3eec;
        ((uint32_t *)((long)__s + uVar8))[1] = piVar9[4];
      }
      else {
        *(uint32_t *)((long)__s + lVar6 + 4) = 0;
      }
      uVar7 = (int)uVar8 + 8;
      uVar8 = (unsigned long)uVar7;
      *(int **)(piVar9 + 2) = piVar10;
      piVar9 = piVar10;
    } while (piVar10 != (int *)0x0);
  }
  *(uint32_t *)((long)__s + (long)(int)uVar7) = 0xffffffff;
  ((uint32_t *)((long)__s + (long)(int)uVar7))[1] = (uint32_t)local_78;
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  local_50 = 0;
  iStack_4c = iVar11;
  uVar8 = RingBuffer_write(uVar3,&local_50,8);
  if (((uVar8 & 1) != 0) && (0 < iVar11)) {
    RingBuffer_write(uVar3,__s,iVar11);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00145184  size=1008 */

void vt_handle_vkGetDeviceBufferMemoryRequirements(long param_1)

{
  uint32_t *puVar1;
  long *plVar2;
  uint32_t *puVar3;
  long lVar4;
  uint64_t *puVar5;
  uint64_t uVar6;
  uint32_t *__s;
  int iVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  long lVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  char *pcVar15;
  char *pcVar16;
  int *piVar17;
  uint64_t local_b8;
  uint64_t local_b0;
  int *piStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  unsigned long local_88 [2];
  uint64_t *local_78;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  pcVar15 = *(char **)(param_1 + 0x30);
  local_88[0] = 0;
  local_88[1] = 0;
  local_78 = (uint64_t *)0x0;
  local_90 = 0;
  piStack_a8 = (int *)0x0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  if (*pcVar15 == '\0') {
    uVar9 = 1;
  }
  else {
    local_b8 = *(uint64_t *)(pcVar15 + 1);
    uVar9 = 9;
  }
  iVar7 = *(int *)(pcVar15 + uVar9);
  plVar2 = (long *)(param_1 + 0x40);
  uVar9 = uVar9 | 4;
  if (0 < iVar7) {
    puVar3 = (uint32_t *)(pcVar15 + uVar9);
    local_88[1] = 0;
    local_88[0] = (unsigned long)*puVar3;
    if ((int)puVar3[1] < 1) {
      local_78 = (uint64_t *)0x0;
    }
    else {
      iVar11 = *(int *)(param_1 + 0x48);
      if ((iVar11 < 0xffc8) && (*plVar2 != 0)) {
        puVar5 = (uint64_t *)(*plVar2 + (long)iVar11);
        *(int *)(param_1 + 0x48) = iVar11 + 0x38;
      }
      else {
        puVar5 = malloc(0x38);
        ArrayList_add(param_1 + 0x50,puVar5);
      }
      puVar5[6] = 0;
      puVar5[3] = 0;
      puVar5[2] = 0;
      puVar5[5] = 0;
      puVar5[4] = 0;
      puVar5[1] = 0;
      *puVar5 = 0;
      local_78 = puVar5;
      FUN_0014de24(puVar5,puVar3 + 2,param_1 + 0x40);
    }
    uVar9 = (unsigned long)(uint32_t)((int)uVar9 + iVar7);
  }
  lVar10 = (long)(int)uVar9;
  if (0 < *(int *)(pcVar15 + lVar10)) {
    pcVar16 = pcVar15 + lVar10 + 4;
    iVar7 = 8;
    local_b0 = ((uint64_t)((*(uint32_t*)((char*)&local_b0 + 4))) << 32 | (uint32_t)(*(uint32_t *)pcVar16));
    piVar14 = (int *)(pcVar15 + lVar10 + 8);
    piVar17 = (int *)0x0;
    do {
      piVar12 = piVar17;
      if (*piVar14 == 0x3b9cba18) {
        iVar11 = *(int *)(pcVar16 + iVar7);
        uVar9 = (long)iVar7 + 4;
        if (0 < iVar11) {
          iVar7 = *(int *)(param_1 + 0x48);
          if ((iVar7 < 0xffe8) && (*plVar2 != 0)) {
            piVar12 = (int *)(*plVar2 + (long)iVar7);
            *(int *)(param_1 + 0x48) = iVar7 + 0x18;
          }
          else {
            piVar12 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,piVar12);
          }
          piVar12[0] = 0;
          piVar12[1] = 0;
          piVar12[2] = 0;
          piVar12[3] = 0;
          piVar12[4] = 0;
          piVar12[5] = 0;
          piVar14 = (int *)(pcVar16 + uVar9);
          uVar9 = (unsigned long)(uint32_t)(iVar11 + (int)uVar9);
          *piVar12 = *piVar14;
          piVar12[4] = piVar14[1];
          iVar7 = piVar14[2];
          *(int **)(piVar12 + 2) = piVar17;
          piVar12[5] = iVar7;
        }
      }
      else {
        if (*piVar14 == -1) goto LAB_00145368;
        uVar9 = (unsigned long)(iVar7 + 4);
      }
      piVar14 = (int *)(pcVar16 + (int)uVar9);
      iVar7 = (int)uVar9 + 4;
      piVar17 = piVar12;
    } while( true );
  }
LAB_001453ac:
  uVar6 = VkObject_fromId(local_b8);
  ((generic_fn_t)DAT_00194070)(uVar6,local_88,&local_b0);
  if (piStack_a8 == (int *)0x0) {
    iVar7 = 0x1c;
  }
  else {
    iVar7 = 4;
    piVar14 = piStack_a8;
    do {
      iVar13 = *piVar14;
      piVar14 = *(int **)(piVar14 + 2);
      iVar11 = 0x14;
      if (iVar13 != 0x3b9cba18) {
        iVar11 = 8;
      }
      iVar7 = iVar11 + iVar7;
    } while (piVar14 != (int *)0x0);
    iVar7 = iVar7 + 0x18;
  }
  iVar11 = *(int *)(param_1 + 0x48) + iVar7;
  if ((iVar11 < 0x10000) && (*plVar2 != 0)) {
    __s = (uint32_t *)(*plVar2 + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar11;
  }
  else {
    __s = malloc((long)iVar7);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar7);
  *__s = (uint32_t)local_b0;
  if (piStack_a8 == (int *)0x0) {
    uVar8 = 4;
  }
  else {
    uVar8 = 4;
    piVar14 = piStack_a8;
    do {
      iVar11 = *piVar14;
      *(int *)((long)__s + (unsigned long)uVar8) = iVar11;
      piVar12 = *(int **)(piVar14 + 2);
      piVar17 = (int *)((long)__s + (unsigned long)(uVar8 + 4));
      if (iVar11 == 0x3b9cba18) {
        piVar17[0] = 0xc;
        piVar17[1] = 0x3b9cba18;
        *(int *)((long)__s + (unsigned long)(uVar8 + 8) + 4) = piVar14[4];
        iVar11 = piVar14[5];
        piVar17 = (int *)((long)__s + (unsigned long)(uVar8 + 8) + 8);
        iVar13 = 0x14;
      }
      else {
        iVar11 = 0;
        iVar13 = 8;
      }
      *piVar17 = iVar11;
      uVar8 = iVar13 + uVar8;
      *(int **)(piVar14 + 2) = piVar12;
      piVar14 = piVar12;
    } while (piVar12 != (int *)0x0);
  }
  puVar1 = (uint32_t *)((long)__s + (long)(int)uVar8);
  *puVar1 = 0xffffffff;
  *(uint64_t *)(puVar1 + 1) = local_a0;
  *(uint64_t *)(puVar1 + 3) = local_98;
  puVar1[5] = (uint32_t)local_90;
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_70 = 0;
  iStack_6c = iVar7;
  uVar9 = RingBuffer_write(uVar6,&local_70,8);
  if (((uVar9 & 1) != 0) && (0 < iVar7)) {
    RingBuffer_write(uVar6,__s,iVar7);
  }
  if (*(long *)(lVar4 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00145368:
  if (piVar17 == (int *)0x0) {
    piStack_a8 = (int *)0x0;
  }
  else {
    piVar14 = (int *)0x0;
    do {
      piStack_a8 = piVar17;
      piVar17 = *(int **)(piStack_a8 + 2);
      *(int **)(piStack_a8 + 2) = piVar14;
      piVar14 = piStack_a8;
    } while (piVar17 != (int *)0x0);
  }
  pcVar16 = pcVar16 + iVar7;
  local_a0 = *(uint64_t *)pcVar16;
  local_98 = *(uint64_t *)(pcVar16 + 8);
  local_90 = ((uint64_t)((*(uint32_t*)((char*)&local_90 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar16 + 0x10)));
  goto LAB_001453ac;
}


/* @001433fc  size=228 */

void vt_handle_vkGetDeviceGroupPeerMemoryFeatures(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  char *pcVar7;
  unsigned long uVar8;
  uint32_t local_54;
  uint64_t local_50;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar8 = 1;
    lVar5 = param_1;
  }
  else {
    uVar8 = 9;
    lVar5 = *(long *)(pcVar7 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar7 + uVar8);
  uVar3 = *(uint32_t *)(pcVar7 + (uVar8 | 4));
  uVar2 = *(uint32_t *)(pcVar7 + uVar8 + 8);
  uVar6 = VkObject_fromId(lVar5);
  local_54 = 0;
  ((generic_fn_t)DAT_00193ff8)(uVar6,uVar1,uVar3,uVar2,&local_54);
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_50 = 0x400000000;
  uVar8 = RingBuffer_write(uVar6,&local_50,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar6,&local_54,4);
  }
  if (*(long *)(lVar4 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00145574  size=1024 */

void vt_handle_vkGetDeviceImageMemoryRequirements(long param_1)

{
  uint32_t *puVar1;
  long *plVar2;
  uint32_t *puVar3;
  long lVar4;
  uint64_t *puVar5;
  uint64_t uVar6;
  uint32_t *__s;
  int iVar7;
  uint32_t uVar8;
  unsigned long uVar9;
  long lVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  char *pcVar15;
  char *pcVar16;
  int *piVar17;
  uint64_t local_c8;
  uint64_t local_c0;
  int *piStack_b8;
  uint64_t local_b0;
  uint64_t local_a8;
  uint64_t local_a0;
  unsigned long local_90 [2];
  uint64_t *local_80;
  uint64_t local_78;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  pcVar15 = *(char **)(param_1 + 0x30);
  local_90[1] = 0;
  local_90[0] = 0;
  local_78 = 0;
  local_80 = (uint64_t *)0x0;
  local_a0 = 0;
  piStack_b8 = (int *)0x0;
  local_c0 = 0;
  local_a8 = 0;
  local_b0 = 0;
  if (*pcVar15 == '\0') {
    uVar9 = 1;
  }
  else {
    local_c8 = *(uint64_t *)(pcVar15 + 1);
    uVar9 = 9;
  }
  iVar7 = *(int *)(pcVar15 + uVar9);
  plVar2 = (long *)(param_1 + 0x40);
  uVar9 = uVar9 | 4;
  if (0 < iVar7) {
    puVar3 = (uint32_t *)(pcVar15 + uVar9);
    local_90[1] = 0;
    local_90[0] = (unsigned long)*puVar3;
    uVar8 = puVar3[1];
    if ((int)uVar8 < 1) {
      lVar10 = 8;
      local_80 = (uint64_t *)0x0;
    }
    else {
      iVar11 = *(int *)(param_1 + 0x48);
      if ((iVar11 < 0xffa8) && (*plVar2 != 0)) {
        puVar5 = (uint64_t *)(*plVar2 + (long)iVar11);
        *(int *)(param_1 + 0x48) = iVar11 + 0x58;
      }
      else {
        puVar5 = malloc(0x58);
        ArrayList_add(param_1 + 0x50,puVar5);
      }
      puVar5[10] = 0;
      puVar5[1] = 0;
      *puVar5 = 0;
      puVar5[3] = 0;
      puVar5[2] = 0;
      puVar5[7] = 0;
      puVar5[6] = 0;
      puVar5[9] = 0;
      puVar5[8] = 0;
      puVar5[5] = 0;
      puVar5[4] = 0;
      local_80 = puVar5;
      FUN_0014e09c(puVar5,puVar3 + 2,param_1 + 0x40);
      lVar10 = (unsigned long)uVar8 + 8;
    }
    uVar9 = (unsigned long)(uint32_t)((int)uVar9 + iVar7);
    local_78 = ((uint64_t)((*(uint32_t*)((char*)&local_78 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar3 + lVar10)));
  }
  lVar10 = (long)(int)uVar9;
  if (0 < *(int *)(pcVar15 + lVar10)) {
    pcVar16 = pcVar15 + lVar10 + 4;
    iVar7 = 8;
    local_c0 = ((uint64_t)((*(uint32_t*)((char*)&local_c0 + 4))) << 32 | (uint32_t)(*(uint32_t *)pcVar16));
    piVar14 = (int *)(pcVar15 + lVar10 + 8);
    piVar17 = (int *)0x0;
    do {
      piVar12 = piVar17;
      if (*piVar14 == 0x3b9cba18) {
        iVar11 = *(int *)(pcVar16 + iVar7);
        uVar9 = (long)iVar7 + 4;
        if (0 < iVar11) {
          iVar7 = *(int *)(param_1 + 0x48);
          if ((iVar7 < 0xffe8) && (*plVar2 != 0)) {
            piVar12 = (int *)(*plVar2 + (long)iVar7);
            *(int *)(param_1 + 0x48) = iVar7 + 0x18;
          }
          else {
            piVar12 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,piVar12);
          }
          piVar12[0] = 0;
          piVar12[1] = 0;
          piVar12[2] = 0;
          piVar12[3] = 0;
          piVar12[4] = 0;
          piVar12[5] = 0;
          piVar14 = (int *)(pcVar16 + uVar9);
          uVar9 = (unsigned long)(uint32_t)(iVar11 + (int)uVar9);
          *piVar12 = *piVar14;
          piVar12[4] = piVar14[1];
          iVar7 = piVar14[2];
          *(int **)(piVar12 + 2) = piVar17;
          piVar12[5] = iVar7;
        }
      }
      else {
        if (*piVar14 == -1) goto LAB_00145768;
        uVar9 = (unsigned long)(iVar7 + 4);
      }
      piVar14 = (int *)(pcVar16 + (int)uVar9);
      iVar7 = (int)uVar9 + 4;
      piVar17 = piVar12;
    } while( true );
  }
LAB_001457ac:
  uVar6 = VkObject_fromId(local_c8);
  ((generic_fn_t)DAT_00194078)(uVar6,local_90,&local_c0);
  if (piStack_b8 == (int *)0x0) {
    iVar7 = 0x1c;
  }
  else {
    iVar7 = 4;
    piVar14 = piStack_b8;
    do {
      iVar13 = *piVar14;
      piVar14 = *(int **)(piVar14 + 2);
      iVar11 = 0x14;
      if (iVar13 != 0x3b9cba18) {
        iVar11 = 8;
      }
      iVar7 = iVar11 + iVar7;
    } while (piVar14 != (int *)0x0);
    iVar7 = iVar7 + 0x18;
  }
  iVar11 = *(int *)(param_1 + 0x48) + iVar7;
  if ((iVar11 < 0x10000) && (*plVar2 != 0)) {
    __s = (uint32_t *)(*plVar2 + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar11;
  }
  else {
    __s = malloc((long)iVar7);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar7);
  *__s = (uint32_t)local_c0;
  if (piStack_b8 == (int *)0x0) {
    uVar8 = 4;
  }
  else {
    uVar8 = 4;
    piVar14 = piStack_b8;
    do {
      iVar11 = *piVar14;
      *(int *)((long)__s + (unsigned long)uVar8) = iVar11;
      piVar12 = *(int **)(piVar14 + 2);
      piVar17 = (int *)((long)__s + (unsigned long)(uVar8 + 4));
      if (iVar11 == 0x3b9cba18) {
        piVar17[0] = 0xc;
        piVar17[1] = 0x3b9cba18;
        *(int *)((long)__s + (unsigned long)(uVar8 + 8) + 4) = piVar14[4];
        iVar11 = piVar14[5];
        piVar17 = (int *)((long)__s + (unsigned long)(uVar8 + 8) + 8);
        iVar13 = 0x14;
      }
      else {
        iVar11 = 0;
        iVar13 = 8;
      }
      *piVar17 = iVar11;
      uVar8 = iVar13 + uVar8;
      *(int **)(piVar14 + 2) = piVar12;
      piVar14 = piVar12;
    } while (piVar12 != (int *)0x0);
  }
  puVar1 = (uint32_t *)((long)__s + (long)(int)uVar8);
  *puVar1 = 0xffffffff;
  *(uint64_t *)(puVar1 + 1) = local_b0;
  *(uint64_t *)(puVar1 + 3) = local_a8;
  puVar1[5] = (uint32_t)local_a0;
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_70 = 0;
  iStack_6c = iVar7;
  uVar9 = RingBuffer_write(uVar6,&local_70,8);
  if (((uVar9 & 1) != 0) && (0 < iVar7)) {
    RingBuffer_write(uVar6,__s,iVar7);
  }
  if (*(long *)(lVar4 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00145768:
  if (piVar17 == (int *)0x0) {
    piStack_b8 = (int *)0x0;
  }
  else {
    piVar14 = (int *)0x0;
    do {
      piStack_b8 = piVar17;
      piVar17 = *(int **)(piStack_b8 + 2);
      *(int **)(piStack_b8 + 2) = piVar14;
      piVar14 = piStack_b8;
    } while (piVar17 != (int *)0x0);
  }
  pcVar16 = pcVar16 + iVar7;
  local_b0 = *(uint64_t *)pcVar16;
  local_a8 = *(uint64_t *)(pcVar16 + 8);
  local_a0 = ((uint64_t)((*(uint32_t*)((char*)&local_a0 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar16 + 0x10)));
  goto LAB_001457ac;
}


/* @00145974  size=1304 */

/* WARNING: Removing unreachable block (ram,0x00145ca0) */
/* WARNING: Removing unreachable block (ram,0x00145cac) */
/* WARNING: Removing unreachable block (ram,0x00145cb8) */
/* WARNING: Removing unreachable block (ram,0x00145d1c) */

void vt_handle_vkGetDeviceImageSparseMemoryRequirements(long param_1)

{
  long *plVar1;
  uint32_t *puVar2;
  char *pcVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  uint64_t *puVar7;
  uint64_t uVar8;
  void *__ptr;
  uint8_t *puVar9;
  unsigned long uVar10;
  long lVar11;
  uint32_t uVar12;
  uint32_t *puVar13;
  uint32_t *puVar14;
  int iVar15;
  uint64_t unaff_x20;
  char *pcVar16;
  uint32_t local_94;
  unsigned long local_90 [2];
  uint64_t *local_80;
  uint64_t local_78;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar6 + 0x28);
  pcVar16 = *(char **)(param_1 + 0x30);
  local_90[1] = 0;
  local_90[0] = 0;
  local_78 = 0;
  local_80 = (uint64_t *)0x0;
  if (*pcVar16 == '\0') {
    uVar10 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar16 + 1);
    uVar10 = 9;
  }
  iVar15 = *(int *)(pcVar16 + uVar10);
  plVar1 = (long *)(param_1 + 0x40);
  uVar10 = uVar10 | 4;
  if (0 < iVar15) {
    puVar2 = (uint32_t *)(pcVar16 + uVar10);
    local_90[1] = 0;
    local_90[0] = (unsigned long)*puVar2;
    uVar12 = puVar2[1];
    if ((int)uVar12 < 1) {
      lVar11 = 8;
      local_80 = (uint64_t *)0x0;
    }
    else {
      iVar5 = *(int *)(param_1 + 0x48);
      if ((iVar5 < 0xffa8) && (*plVar1 != 0)) {
        puVar7 = (uint64_t *)(*plVar1 + (long)iVar5);
        *(int *)(param_1 + 0x48) = iVar5 + 0x58;
      }
      else {
        puVar7 = malloc(0x58);
        ArrayList_add(param_1 + 0x50,puVar7);
      }
      puVar7[10] = 0;
      puVar7[1] = 0;
      *puVar7 = 0;
      puVar7[3] = 0;
      puVar7[2] = 0;
      puVar7[7] = 0;
      puVar7[6] = 0;
      puVar7[9] = 0;
      puVar7[8] = 0;
      puVar7[5] = 0;
      puVar7[4] = 0;
      local_80 = puVar7;
      FUN_0014e09c(puVar7,puVar2 + 2,param_1 + 0x40);
      lVar11 = (unsigned long)uVar12 + 8;
    }
    uVar10 = (unsigned long)(uint32_t)((int)uVar10 + iVar15);
    local_78 = ((uint64_t)((*(uint32_t*)((char*)&local_78 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar2 + lVar11)));
  }
  if (0 < *(int *)(pcVar16 + (int)uVar10)) {
    local_94 = *(uint32_t *)(pcVar16 + (long)(int)uVar10 + 4);
    pcVar16 = (char *)(unsigned long)local_94;
  }
  uVar8 = VkObject_fromId(unaff_x20);
  if (((int)pcVar16 == 0) ||
     (__ptr = calloc((unsigned long)pcVar16 & 0xffffffff,0x40), __ptr == (void *)0x0)) {
    ((generic_fn_t)DAT_00194080)(uVar8,local_90,&local_94,0);
    iVar15 = *(int *)(param_1 + 0x48) + 0x11;
    if ((iVar15 < 0x10000) && (*plVar1 != 0)) {
      puVar9 = (uint8_t *)(*plVar1 + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar15;
    }
    else {
      puVar9 = malloc(0x11);
      ArrayList_add(param_1 + 0x50,puVar9);
    }
    memset(puVar9,0,0x11);
    *puVar9 = 0;
    *(uint64_t *)(puVar9 + 1) = 0x400000000;
    *(uint32_t *)(puVar9 + 9) = local_94;
    *(uint32_t *)(puVar9 + 0xd) = 0;
    uVar8 = *(uint64_t *)(param_1 + 0x68);
    local_70 = 0;
    iStack_6c = 0x11;
    uVar10 = RingBuffer_write(uVar8,&local_70,8);
    if ((uVar10 & 1) != 0) {
      RingBuffer_write(uVar8,puVar9,0x11);
    }
  }
  else {
    pcVar16 = *(char **)(param_1 + 0x30);
    uVar12 = 9;
    if (*pcVar16 == '\0') {
      uVar12 = 1;
    }
    lVar11 = (unsigned long)(uVar12 | 4) +
             (unsigned long)(*(uint32_t *)(pcVar16 + uVar12) &
                    ((int)*(uint32_t *)(pcVar16 + uVar12) >> 0x1f ^ 0xffffffffU));
    lVar11 = (unsigned long)((int)lVar11 + 4) +
             (unsigned long)(*(uint32_t *)(pcVar16 + lVar11) &
                    ((int)*(uint32_t *)(pcVar16 + lVar11) >> 0x1f ^ 0xffffffffU));
    uVar10 = (unsigned long)*(uint32_t *)(pcVar16 + lVar11);
    if (0 < (int)*(uint32_t *)(pcVar16 + lVar11)) {
      iVar15 = (int)lVar11 + 4;
      puVar13 = (uint32_t *)((long)__ptr + 0x1c);
      do {
        lVar11 = (long)iVar15 + 4;
        pcVar3 = pcVar16 + lVar11;
        uVar4 = *(uint32_t *)pcVar3;
        iVar15 = *(int *)(pcVar16 + iVar15);
        *(uint64_t *)(puVar13 + -5) = 0;
        uVar10 = uVar10 - 1;
        puVar13[-7] = uVar4;
        iVar15 = iVar15 + (int)lVar11;
        puVar13[-3] = *(uint32_t *)(pcVar3 + 4);
        puVar13[-2] = *(uint32_t *)(pcVar3 + 8);
        puVar13[-1] = *(uint32_t *)(pcVar3 + 0xc);
        *puVar13 = *(uint32_t *)(pcVar3 + 0x10);
        puVar13[1] = *(uint32_t *)(pcVar3 + 0x14);
        puVar13[2] = *(uint32_t *)(pcVar3 + 0x18);
        *(uint64_t *)(puVar13 + 3) = *(uint64_t *)(pcVar3 + 0x1c);
        *(uint64_t *)(puVar13 + 5) = *(uint64_t *)(pcVar3 + 0x24);
        *(uint64_t *)(puVar13 + 7) = *(uint64_t *)(pcVar3 + 0x2c);
        puVar13 = puVar13 + 0x10;
      } while (uVar10 != 0);
    }
    ((generic_fn_t)DAT_00194080)(uVar8,local_90,&local_94,__ptr);
    iVar15 = local_94 * 0x38 + 0x11;
    if ((int)local_94 < 1) {
      iVar15 = 0x11;
    }
    iVar5 = iVar15 + *(int *)(param_1 + 0x48);
    if ((iVar5 < 0x10000) && (*plVar1 != 0)) {
      puVar9 = (uint8_t *)(*plVar1 + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar5;
    }
    else {
      puVar9 = malloc((long)iVar15);
      ArrayList_add(param_1 + 0x50,puVar9);
    }
    memset(puVar9,0,(long)iVar15);
    *puVar9 = 0;
    uVar10 = (unsigned long)local_94;
    *(uint64_t *)(puVar9 + 1) = 0x400000000;
    *(uint32_t *)(puVar9 + 9) = local_94;
    *(uint32_t *)(puVar9 + 0xd) = local_94;
    if (0 < (int)local_94) {
      puVar13 = (uint32_t *)((long)__ptr + 0x1c);
      puVar14 = (uint32_t *)(puVar9 + 0x21);
      do {
        puVar14[-4] = 0x34;
        uVar10 = uVar10 - 1;
        puVar14[-3] = puVar13[-7];
        puVar14[-2] = puVar13[-3];
        puVar14[-1] = puVar13[-2];
        *puVar14 = puVar13[-1];
        puVar14[1] = *puVar13;
        puVar14[2] = puVar13[1];
        puVar14[3] = puVar13[2];
        *(uint64_t *)(puVar14 + 4) = *(uint64_t *)(puVar13 + 3);
        *(uint64_t *)(puVar14 + 6) = *(uint64_t *)(puVar13 + 5);
        puVar7 = (uint64_t *)(puVar13 + 7);
        puVar13 = puVar13 + 0x10;
        *(uint64_t *)(puVar14 + 8) = *puVar7;
        puVar14 = puVar14 + 0xe;
      } while (uVar10 != 0);
    }
    uVar8 = *(uint64_t *)(param_1 + 0x68);
    local_70 = 0;
    iStack_6c = iVar15;
    uVar10 = RingBuffer_write(uVar8,&local_70,8);
    if (((uVar10 & 1) != 0) && (0 < iVar15)) {
      RingBuffer_write(uVar8,puVar9,iVar15);
    }
    free(__ptr);
  }
  if (*(long *)(lVar6 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001314c0  size=224 */

void vt_handle_vkGetDeviceMemoryCommitment(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  unsigned long uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint64_t auStack_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
    cVar1 = pcVar6[1];
    lVar3 = param_1;
  }
  else {
    lVar3 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
    cVar1 = pcVar6[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar6 + lVar7 + 1);
  }
  uVar4 = VkObject_fromId(lVar3);
  lVar7 = VkObject_fromId(unaff_x20);
  ((generic_fn_t)DAT_00193bb0)(uVar4,*(uint64_t *)(lVar7 + 0x18),auStack_48);
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  local_40 = 0x800000000;
  uVar5 = RingBuffer_write(uVar4,&local_40,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar4,auStack_48,8);
  }
  if (*(long *)(lVar2 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001487c4  size=264 */

void vt_handle_vkGetDeviceMemoryOpaqueCaptureAddress(long param_1)

{
  long lVar1;
  char cVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  uint64_t unaff_x20;
  uint64_t local_60;
  unsigned long local_58 [5];
  
  cVar2 = vortekSerializerCastVkObject;
  /* stack canary setup */
  local_58[4] = *(long *)(lVar1 + 0x28);
  pcVar4 = *(char **)(param_1 + 0x30);
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar4 + 1);
    uVar5 = 9;
  }
  if (0 < *(int *)(pcVar4 + uVar5)) {
    local_58[1] = 0;
    local_58[0] = (unsigned long)*(uint32_t *)(pcVar4 + (uVar5 | 4));
    local_58[2] = VkObject_fromId(*(uint64_t *)((long)(pcVar4 + (uVar5 | 4)) + 4));
    if (cVar2 != '\0') {
      local_58[2] = *(long *)(local_58[2] + 0x18);
    }
  }
  uVar3 = VkObject_fromId(unaff_x20);
  local_60 = ((generic_fn_t)DAT_00194148)(uVar3,local_58);
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  local_58[3] = 0x800000000;
  uVar5 = RingBuffer_write(uVar3,local_58 + 3,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar3,&local_60,8);
  }
  if (*(long *)(lVar1 + 0x28) != local_58[4]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012fef0  size=280 */

void vt_handle_vkGetDeviceQueue(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  uint64_t *puVar7;
  char *pcVar8;
  unsigned long uVar9;
  uint64_t local_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar9 = 1;
    lVar5 = param_1;
  }
  else {
    uVar9 = 9;
    lVar5 = *(long *)(pcVar8 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar8 + uVar9);
  uVar2 = *(uint32_t *)(pcVar8 + (uVar9 | 4));
  uVar6 = VkObject_fromId(lVar5);
  ((generic_fn_t)DAT_00193b60)(uVar6,uVar1,uVar2,&local_48);
  iVar3 = *(int *)(param_1 + 0x48);
  if ((iVar3 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar7 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar3);
    *(int *)(param_1 + 0x48) = iVar3 + 8;
  }
  else {
    puVar7 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar7);
  }
  *puVar7 = 0;
  *puVar7 = local_48;
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_40 = 0x800000000;
  uVar9 = RingBuffer_write(uVar6,&local_40,8);
  if ((uVar9 & 1) != 0) {
    RingBuffer_write(uVar6,puVar7,8);
  }
  if (*(long *)(lVar4 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00146088  size=328 */

void vt_handle_vkGetDeviceQueue2(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  char *pcVar7;
  unsigned long uVar8;
  uint64_t local_68;
  unsigned long local_60 [6];
  
  /* stack canary setup */
  local_60[5] = *(long *)(lVar3 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_60[0] = 0;
  local_60[3] = 0;
  local_60[2] = 0;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
    lVar4 = param_1;
  }
  else {
    uVar8 = 9;
    lVar4 = *(long *)(pcVar7 + 1);
  }
  if (0 < *(int *)(pcVar7 + uVar8)) {
    puVar1 = (uint32_t *)(pcVar7 + (uVar8 | 4));
    local_60[0] = (unsigned long)*puVar1;
    local_60[2] = *(unsigned long *)(puVar1 + 1);
    local_60[3] = (unsigned long)puVar1[3];
  }
  local_60[1] = 0;
  uVar5 = VkObject_fromId(lVar4);
  ((generic_fn_t)DAT_00194098)(uVar5,local_60,&local_68);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 8;
  }
  else {
    puVar6 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *puVar6 = 0;
  *puVar6 = local_68;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  local_60[4] = 0x800000000;
  uVar8 = RingBuffer_write(uVar5,local_60 + 4,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar6,8);
  }
  if (*(long *)(lVar3 + 0x28) == local_60[5]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013387c  size=192 */

void vt_handle_vkGetEventStatus(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
    cVar1 = pcVar6[1];
    lVar3 = param_1;
  }
  else {
    lVar3 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
    cVar1 = pcVar6[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar6 + lVar7 + 1);
  }
  uVar4 = VkObject_fromId(lVar3);
  uVar5 = VkObject_fromId(unaff_x20);
  local_40 = ((generic_fn_t)DAT_00193c38)(uVar4,uVar5);
  uStack_3c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_40,8);
  if (*(long *)(lVar2 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00142e8c  size=304 */

void vt_handle_vkGetFenceFdKHR(int *param_1)

{
  long lVar1;
  uint64_t uVar2;
  char *pcVar3;
  unsigned long uVar4;
  uint64_t unaff_x20;
  uint32_t local_138;
  int local_134;
  unsigned long local_130 [3];
  uint64_t local_118;
  struct msghdr local_110;
  struct iovec local_d8;
  uint64_t local_c8;
  uint64_t local_c0;
  int local_b8;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar1 + 0x28);
  pcVar3 = *(char **)(param_1 + 0xc);
  local_130[1] = 0;
  local_130[0] = 0;
  local_118 = 0;
  local_130[2] = 0;
  if (*pcVar3 == '\0') {
    uVar4 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar3 + 1);
    uVar4 = 9;
  }
  if (0 < *(int *)(pcVar3 + uVar4)) {
    local_130[1] = 0;
    local_130[0] = (unsigned long)*(uint32_t *)(pcVar3 + (uVar4 | 4));
    local_130[2] = VkObject_fromId(*(uint64_t *)((long)(pcVar3 + (uVar4 | 4)) + 4));
  }
  uVar2 = VkObject_fromId(unaff_x20);
  local_118 = ((uint64_t)((*(uint32_t*)((char*)&local_118 + 4))) << 32 | (uint32_t)(8));
  local_138 = ((generic_fn_t)DAT_00193fe8)(uVar2,local_130,&local_134);
  local_d8.iov_base = &local_138;
  local_d8.iov_len = 4;
  local_110.msg_control = &local_c8;
  local_110.msg_controllen = 0x14;
  local_110.msg_iov = &local_d8;
  local_110.msg_name = (void *)0x0;
  local_110.msg_namelen = 0;
  local_110.msg_iovlen = 1;
  local_c8 = 0x14;
  local_110.msg_flags = 0;
  local_c0 = 0x100000001;
  local_b8 = local_134;
  sendmsg(*param_1,&local_110,0);
  if (0 < local_134) {
    local_134 = close(local_134);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_134);
}


/* @00133008  size=192 */

void vt_handle_vkGetFenceStatus(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
    cVar1 = pcVar6[1];
    lVar3 = param_1;
  }
  else {
    lVar3 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
    cVar1 = pcVar6[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar6 + lVar7 + 1);
  }
  uVar4 = VkObject_fromId(lVar3);
  uVar5 = VkObject_fromId(unaff_x20);
  local_40 = ((generic_fn_t)DAT_00193c08)(uVar4,uVar5);
  uStack_3c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_40,8);
  if (*(long *)(lVar2 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00131808  size=328 */

void vt_handle_vkGetImageMemoryRequirements(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t *puVar7;
  unsigned long uVar8;
  char *pcVar9;
  long lVar10;
  uint64_t unaff_x20;
  uint64_t local_58;
  uint64_t local_50;
  uint64_t local_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    lVar10 = 1;
    cVar1 = pcVar9[1];
    lVar4 = param_1;
  }
  else {
    lVar4 = *(long *)(pcVar9 + 1);
    lVar10 = 9;
    cVar1 = pcVar9[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar9 + lVar10 + 1);
  }
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x20);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  ((generic_fn_t)DAT_00193bc8)(uVar5,uVar6,&local_58);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xffec) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar7 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 0x14;
  }
  else {
    puVar7 = malloc(0x14);
    ArrayList_add(param_1 + 0x50,puVar7);
  }
  *puVar7 = 0;
  puVar7[1] = 0;
  *(uint32_t *)(puVar7 + 2) = 0;
  *puVar7 = local_58;
  local_40 = 0x1400000000;
  puVar7[1] = local_50;
  *(uint32_t *)(puVar7 + 2) = (uint32_t)local_48;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uVar8 = RingBuffer_write(uVar5,&local_40,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar7,0x14);
  }
  if (*(long *)(lVar3 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0014488c  size=1140 */

void vt_handle_vkGetImageMemoryRequirements2(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  long lVar3;
  uint64_t *puVar4;
  uint64_t uVar5;
  uint32_t *__s;
  int iVar6;
  uint32_t uVar7;
  unsigned long uVar8;
  long lVar9;
  uint32_t *puVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  char *pcVar15;
  char *pcVar16;
  unsigned long uVar17;
  int *piVar18;
  uint64_t *puVar19;
  uint64_t unaff_x28;
  uint64_t local_b0;
  int *piStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  unsigned long local_88;
  uint64_t *local_80;
  uint64_t local_78;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar3 + 0x28);
  pcVar15 = *(char **)(param_1 + 0x30);
  local_88 = 0;
  local_80 = (uint64_t *)0x0;
  local_78 = 0;
  local_90 = 0;
  piStack_a8 = (int *)0x0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  if (*pcVar15 == '\0') {
    uVar8 = 1;
  }
  else {
    unaff_x28 = *(uint64_t *)(pcVar15 + 1);
    uVar8 = 9;
  }
  iVar6 = *(int *)(pcVar15 + uVar8);
  uVar8 = uVar8 | 4;
  if (0 < iVar6) {
    puVar10 = (uint32_t *)((long)(pcVar15 + uVar8) + 4);
    iVar11 = 8;
    local_88 = (unsigned long)*(uint32_t *)(pcVar15 + uVar8);
    puVar19 = (uint64_t *)0x0;
    do {
      puVar4 = puVar19;
      if (*puVar10 == 0x3b9d2b63) {
        iVar13 = *(int *)(pcVar15 + (long)iVar11 + uVar8);
        uVar17 = (long)iVar11 + 4;
        if (0 < iVar13) {
          iVar11 = *(int *)(param_1 + 0x48);
          if ((iVar11 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar4 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar11);
            *(int *)(param_1 + 0x48) = iVar11 + 0x18;
          }
          else {
            puVar4 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar4);
          }
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
          lVar9 = uVar17 + uVar8;
          uVar2 = *(uint32_t *)(pcVar15 + lVar9);
          puVar4[1] = 0;
          uVar17 = (unsigned long)(uint32_t)(iVar13 + (int)uVar17);
          *(uint32_t *)puVar4 = uVar2;
          uVar2 = *(uint32_t *)(pcVar15 + lVar9 + 4);
          puVar4[1] = puVar19;
          *(uint32_t *)(puVar4 + 2) = uVar2;
        }
      }
      else {
        if (*puVar10 == 0xffffffff) goto LAB_001449d0;
        uVar17 = (unsigned long)(iVar11 + 4);
      }
      puVar10 = (uint32_t *)(pcVar15 + (long)(int)uVar17 + uVar8);
      iVar11 = (int)uVar17 + 4;
      puVar19 = puVar4;
    } while( true );
  }
LAB_00144a18:
  lVar9 = (long)(int)uVar8;
  if (0 < *(int *)(pcVar15 + lVar9)) {
    pcVar16 = pcVar15 + lVar9 + 4;
    iVar6 = 8;
    local_b0 = ((uint64_t)((*(uint32_t*)((char*)&local_b0 + 4))) << 32 | (uint32_t)(*(uint32_t *)pcVar16));
    piVar14 = (int *)(pcVar15 + lVar9 + 8);
    piVar18 = (int *)0x0;
    do {
      piVar12 = piVar18;
      if (*piVar14 == 0x3b9cba18) {
        iVar11 = *(int *)(pcVar16 + iVar6);
        uVar8 = (long)iVar6 + 4;
        if (0 < iVar11) {
          iVar6 = *(int *)(param_1 + 0x48);
          if ((iVar6 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            piVar12 = (int *)(*(long *)(param_1 + 0x40) + (long)iVar6);
            *(int *)(param_1 + 0x48) = iVar6 + 0x18;
          }
          else {
            piVar12 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,piVar12);
          }
          piVar12[0] = 0;
          piVar12[1] = 0;
          piVar12[2] = 0;
          piVar12[3] = 0;
          piVar12[4] = 0;
          piVar12[5] = 0;
          piVar14 = (int *)(pcVar16 + uVar8);
          uVar8 = (unsigned long)(uint32_t)(iVar11 + (int)uVar8);
          *piVar12 = *piVar14;
          piVar12[4] = piVar14[1];
          iVar6 = piVar14[2];
          *(int **)(piVar12 + 2) = piVar18;
          piVar12[5] = iVar6;
        }
      }
      else {
        if (*piVar14 == -1) goto LAB_00144af4;
        uVar8 = (unsigned long)(iVar6 + 4);
      }
      piVar14 = (int *)(pcVar16 + (int)uVar8);
      iVar6 = (int)uVar8 + 4;
      piVar18 = piVar12;
    } while( true );
  }
LAB_00144b38:
  uVar5 = VkObject_fromId(unaff_x28);
  ((generic_fn_t)DAT_00194060)(uVar5,&local_88,&local_b0);
  if (piStack_a8 == (int *)0x0) {
    iVar6 = 0x1c;
  }
  else {
    iVar6 = 4;
    piVar14 = piStack_a8;
    do {
      iVar13 = *piVar14;
      piVar14 = *(int **)(piVar14 + 2);
      iVar11 = 0x14;
      if (iVar13 != 0x3b9cba18) {
        iVar11 = 8;
      }
      iVar6 = iVar11 + iVar6;
    } while (piVar14 != (int *)0x0);
    iVar6 = iVar6 + 0x18;
  }
  iVar11 = *(int *)(param_1 + 0x48) + iVar6;
  if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar11;
  }
  else {
    __s = malloc((long)iVar6);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar6);
  *__s = (uint32_t)local_b0;
  if (piStack_a8 == (int *)0x0) {
    uVar7 = 4;
  }
  else {
    uVar7 = 4;
    piVar14 = piStack_a8;
    do {
      iVar11 = *piVar14;
      *(int *)((long)__s + (unsigned long)uVar7) = iVar11;
      piVar12 = *(int **)(piVar14 + 2);
      piVar18 = (int *)((long)__s + (unsigned long)(uVar7 + 4));
      if (iVar11 == 0x3b9cba18) {
        piVar18[0] = 0xc;
        piVar18[1] = 0x3b9cba18;
        *(int *)((long)__s + (unsigned long)(uVar7 + 8) + 4) = piVar14[4];
        iVar11 = piVar14[5];
        piVar18 = (int *)((long)__s + (unsigned long)(uVar7 + 8) + 8);
        iVar13 = 0x14;
      }
      else {
        iVar11 = 0;
        iVar13 = 8;
      }
      *piVar18 = iVar11;
      uVar7 = iVar13 + uVar7;
      *(int **)(piVar14 + 2) = piVar12;
      piVar14 = piVar12;
    } while (piVar12 != (int *)0x0);
  }
  puVar1 = (uint32_t *)((long)__s + (long)(int)uVar7);
  *puVar1 = 0xffffffff;
  *(uint64_t *)(puVar1 + 1) = local_a0;
  *(uint64_t *)(puVar1 + 3) = local_98;
  puVar1[5] = (uint32_t)local_90;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  local_70 = 0;
  iStack_6c = iVar6;
  uVar8 = RingBuffer_write(uVar5,&local_70,8);
  if (((uVar8 & 1) != 0) && (0 < iVar6)) {
    RingBuffer_write(uVar5,__s,iVar6);
  }
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_001449d0:
  if (puVar19 == (uint64_t *)0x0) {
    local_80 = (uint64_t *)0x0;
  }
  else {
    puVar4 = (uint64_t *)0x0;
    do {
      local_80 = puVar19;
      puVar19 = (uint64_t *)local_80[1];
      local_80[1] = puVar4;
      puVar4 = local_80;
    } while (puVar19 != (uint64_t *)0x0);
  }
  local_78 = VkObject_fromId(*(uint64_t *)(pcVar15 + (long)iVar11 + uVar8));
  uVar8 = (unsigned long)(uint32_t)((int)uVar8 + iVar6);
  goto LAB_00144a18;
LAB_00144af4:
  if (piVar18 == (int *)0x0) {
    piStack_a8 = (int *)0x0;
  }
  else {
    piVar14 = (int *)0x0;
    do {
      piStack_a8 = piVar18;
      piVar18 = *(int **)(piStack_a8 + 2);
      *(int **)(piStack_a8 + 2) = piVar14;
      piVar14 = piStack_a8;
    } while (piVar18 != (int *)0x0);
  }
  pcVar16 = pcVar16 + iVar6;
  local_a0 = *(uint64_t *)pcVar16;
  local_98 = *(uint64_t *)(pcVar16 + 8);
  local_90 = ((uint64_t)((*(uint32_t*)((char*)&local_90 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar16 + 0x10)));
  goto LAB_00144b38;
}


/* @00131a50  size=580 */

/* WARNING: Type propagation algorithm not settling */

void vt_handle_vkGetImageSparseMemoryRequirements(long param_1)

{
  uint64_t *puVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  void *__ptr;
  uint16_t *__s;
  char *pcVar8;
  long lVar9;
  uint32_t *puVar10;
  unsigned long uVar11;
  uint32_t *puVar12;
  uint64_t unaff_x20;
  uint32_t unaff_w23;
  uint32_t local_54 [3];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar9 = 1;
    lVar5 = param_1;
  }
  else {
    lVar9 = 9;
    lVar5 = *(long *)(pcVar8 + 1);
  }
  uVar11 = lVar9 + 1;
  if (pcVar8[lVar9] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar8 + uVar11);
    uVar11 = (unsigned long)((int)lVar9 + 9);
  }
  if (0 < *(int *)(pcVar8 + uVar11)) {
    local_54[0] = *(uint32_t *)(pcVar8 + uVar11 + 4);
    unaff_w23 = local_54[0];
  }
  uVar6 = VkObject_fromId(lVar5);
  uVar7 = VkObject_fromId(unaff_x20);
  if (unaff_w23 == 0) {
    __ptr = (void *)0x0;
  }
  else {
    __ptr = calloc((unsigned long)unaff_w23,0x30);
  }
  ((generic_fn_t)DAT_00193bd8)(uVar6,uVar7,local_54,__ptr);
  iVar3 = local_54[0] * 0x34 + 0xe;
  if ((int)local_54[0] < 1 || __ptr == (void *)0x0) {
    iVar3 = 0xe;
  }
  iVar2 = iVar3 + *(int *)(param_1 + 0x48);
  if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint16_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar2;
  }
  else {
    __s = malloc((long)iVar3);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar3);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 4;
  uVar11 = (unsigned long)local_54[0];
  *(uint32_t *)(__s + 3) = local_54[0];
  if (__ptr == (void *)0x0) {
    *(uint32_t *)(__s + 5) = 0;
  }
  else {
    *(uint32_t *)(__s + 5) = local_54[0];
    if (0 < (int)local_54[0]) {
      puVar10 = (uint32_t *)((long)__ptr + 0x14);
      puVar12 = (uint32_t *)(__s + 0xf);
      do {
        puVar12[-4] = 0x30;
        uVar11 = uVar11 - 1;
        puVar12[-3] = puVar10[-5];
        puVar12[-2] = puVar10[-4];
        puVar12[-1] = puVar10[-3];
        *puVar12 = puVar10[-2];
        puVar12[1] = puVar10[-1];
        puVar12[2] = *puVar10;
        *(uint64_t *)(puVar12 + 3) = *(uint64_t *)(puVar10 + 1);
        *(uint64_t *)(puVar12 + 5) = *(uint64_t *)(puVar10 + 3);
        puVar1 = (uint64_t *)(puVar10 + 5);
        puVar10 = puVar10 + 0xc;
        *(uint64_t *)(puVar12 + 7) = *puVar1;
        puVar12 = puVar12 + 0xd;
      } while (uVar11 != 0);
    }
  }
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_54[1] = 0;
  local_54[2] = iVar3;
  uVar11 = RingBuffer_write(uVar6,local_54 + 1,8);
  if (((uVar11 & 1) != 0) && (0 < iVar3)) {
    RingBuffer_write(uVar6,__s,iVar3);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (*(long *)(lVar4 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00144d00  size=1156 */

/* WARNING: Removing unreachable block (ram,0x00144fa0) */
/* WARNING: Removing unreachable block (ram,0x00144fac) */
/* WARNING: Removing unreachable block (ram,0x00144fb8) */
/* WARNING: Removing unreachable block (ram,0x0014501c) */

void vt_handle_vkGetImageSparseMemoryRequirements2(long param_1)

{
  uint64_t *puVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  uint32_t uVar5;
  long lVar6;
  uint64_t uVar7;
  void *__ptr;
  uint8_t *puVar8;
  unsigned long uVar9;
  uint32_t uVar10;
  uint32_t *puVar11;
  uint32_t *puVar12;
  int iVar13;
  uint64_t unaff_x20;
  char *pcVar14;
  uint32_t local_6c;
  unsigned long local_68 [3];
  uint32_t local_50;
  int iStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar6 + 0x28);
  pcVar14 = *(char **)(param_1 + 0x30);
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  if (*pcVar14 == '\0') {
    uVar9 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar14 + 1);
    uVar9 = 9;
  }
  iVar13 = *(int *)(pcVar14 + uVar9);
  uVar9 = uVar9 | 4;
  if (0 < iVar13) {
    local_68[1] = 0;
    local_68[0] = (unsigned long)*(uint32_t *)(pcVar14 + uVar9);
    local_68[2] = VkObject_fromId(*(uint64_t *)((long)(pcVar14 + uVar9) + 4));
    uVar9 = (unsigned long)(uint32_t)((int)uVar9 + iVar13);
  }
  uVar10 = (uint32_t)uVar9;
  if (0 < *(int *)(pcVar14 + (int)uVar10)) {
    uVar10 = *(uint32_t *)(pcVar14 + (long)(int)uVar10 + 4);
    local_6c = uVar10;
  }
  uVar7 = VkObject_fromId(unaff_x20);
  if ((uVar10 == 0) || (__ptr = calloc((unsigned long)uVar10,0x40), __ptr == (void *)0x0)) {
    ((generic_fn_t)DAT_00194068)(uVar7,local_68,&local_6c,0);
    iVar13 = *(int *)(param_1 + 0x48) + 0x11;
    if ((iVar13 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar8 = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar13;
    }
    else {
      puVar8 = malloc(0x11);
      ArrayList_add(param_1 + 0x50,puVar8);
    }
    memset(puVar8,0,0x11);
    *puVar8 = 0;
    *(uint64_t *)(puVar8 + 1) = 0x400000000;
    *(uint32_t *)(puVar8 + 9) = local_6c;
    *(uint32_t *)(puVar8 + 0xd) = 0;
    uVar7 = *(uint64_t *)(param_1 + 0x68);
    local_50 = 0;
    iStack_4c = 0x11;
    uVar9 = RingBuffer_write(uVar7,&local_50,8);
    if ((uVar9 & 1) != 0) {
      RingBuffer_write(uVar7,puVar8,0x11);
    }
  }
  else {
    pcVar14 = *(char **)(param_1 + 0x30);
    uVar10 = 9;
    if (*pcVar14 == '\0') {
      uVar10 = 1;
    }
    lVar3 = (unsigned long)(uVar10 | 4) +
            (unsigned long)(*(uint32_t *)(pcVar14 + uVar10) &
                   ((int)*(uint32_t *)(pcVar14 + uVar10) >> 0x1f ^ 0xffffffffU));
    lVar3 = (unsigned long)((int)lVar3 + 4) +
            (unsigned long)(*(uint32_t *)(pcVar14 + lVar3) &
                   ((int)*(uint32_t *)(pcVar14 + lVar3) >> 0x1f ^ 0xffffffffU));
    uVar9 = (unsigned long)*(uint32_t *)(pcVar14 + lVar3);
    if (0 < (int)*(uint32_t *)(pcVar14 + lVar3)) {
      iVar13 = (int)lVar3 + 4;
      puVar11 = (uint32_t *)((long)__ptr + 0x1c);
      do {
        lVar3 = (long)iVar13 + 4;
        pcVar4 = pcVar14 + lVar3;
        uVar5 = *(uint32_t *)pcVar4;
        iVar13 = *(int *)(pcVar14 + iVar13);
        *(uint64_t *)(puVar11 + -5) = 0;
        uVar9 = uVar9 - 1;
        puVar11[-7] = uVar5;
        iVar13 = iVar13 + (int)lVar3;
        puVar11[-3] = *(uint32_t *)(pcVar4 + 4);
        puVar11[-2] = *(uint32_t *)(pcVar4 + 8);
        puVar11[-1] = *(uint32_t *)(pcVar4 + 0xc);
        *puVar11 = *(uint32_t *)(pcVar4 + 0x10);
        puVar11[1] = *(uint32_t *)(pcVar4 + 0x14);
        puVar11[2] = *(uint32_t *)(pcVar4 + 0x18);
        *(uint64_t *)(puVar11 + 3) = *(uint64_t *)(pcVar4 + 0x1c);
        *(uint64_t *)(puVar11 + 5) = *(uint64_t *)(pcVar4 + 0x24);
        *(uint64_t *)(puVar11 + 7) = *(uint64_t *)(pcVar4 + 0x2c);
        puVar11 = puVar11 + 0x10;
      } while (uVar9 != 0);
    }
    ((generic_fn_t)DAT_00194068)(uVar7,local_68,&local_6c,__ptr);
    iVar13 = local_6c * 0x38 + 0x11;
    if ((int)local_6c < 1) {
      iVar13 = 0x11;
    }
    iVar2 = iVar13 + *(int *)(param_1 + 0x48);
    if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar8 = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar2;
    }
    else {
      puVar8 = malloc((long)iVar13);
      ArrayList_add(param_1 + 0x50,puVar8);
    }
    memset(puVar8,0,(long)iVar13);
    *puVar8 = 0;
    uVar9 = (unsigned long)local_6c;
    *(uint64_t *)(puVar8 + 1) = 0x400000000;
    *(uint32_t *)(puVar8 + 9) = local_6c;
    *(uint32_t *)(puVar8 + 0xd) = local_6c;
    if (0 < (int)local_6c) {
      puVar11 = (uint32_t *)((long)__ptr + 0x1c);
      puVar12 = (uint32_t *)(puVar8 + 0x21);
      do {
        puVar12[-4] = 0x34;
        uVar9 = uVar9 - 1;
        puVar12[-3] = puVar11[-7];
        puVar12[-2] = puVar11[-3];
        puVar12[-1] = puVar11[-2];
        *puVar12 = puVar11[-1];
        puVar12[1] = *puVar11;
        puVar12[2] = puVar11[1];
        puVar12[3] = puVar11[2];
        *(uint64_t *)(puVar12 + 4) = *(uint64_t *)(puVar11 + 3);
        *(uint64_t *)(puVar12 + 6) = *(uint64_t *)(puVar11 + 5);
        puVar1 = (uint64_t *)(puVar11 + 7);
        puVar11 = puVar11 + 0x10;
        *(uint64_t *)(puVar12 + 8) = *puVar1;
        puVar12 = puVar12 + 0xe;
      } while (uVar9 != 0);
    }
    uVar7 = *(uint64_t *)(param_1 + 0x68);
    local_50 = 0;
    iStack_4c = iVar13;
    uVar9 = RingBuffer_write(uVar7,&local_50,8);
    if (((uVar9 & 1) != 0) && (0 < iVar13)) {
      RingBuffer_write(uVar7,puVar8,iVar13);
    }
    free(__ptr);
  }
  if (*(long *)(lVar6 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00134560  size=408 */

void vt_handle_vkGetImageSubresourceLayout(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  char *pcVar7;
  long lVar8;
  unsigned long uVar9;
  uint64_t unaff_x20;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t local_68;
  uint64_t local_60;
  uint64_t local_50;
  uint32_t local_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_48 = 0;
  local_50 = 0;
  if (*pcVar7 == '\0') {
    lVar8 = 1;
    lVar3 = param_1;
  }
  else {
    lVar8 = 9;
    lVar3 = *(long *)(pcVar7 + 1);
  }
  uVar9 = lVar8 + 1;
  if (pcVar7[lVar8] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar7 + uVar9);
    uVar9 = (unsigned long)((int)lVar8 + 9);
  }
  if (0 < *(int *)(pcVar7 + uVar9)) {
    local_50 = *(uint64_t *)(pcVar7 + uVar9 + 4);
    local_48 = *(uint32_t *)(pcVar7 + uVar9 + 0xc);
  }
  uVar4 = VkObject_fromId(lVar3);
  uVar5 = VkObject_fromId(unaff_x20);
  local_60 = 0;
  uStack_78 = 0;
  local_80 = 0;
  local_68 = 0;
  local_70 = 0;
  ((generic_fn_t)DAT_00193ca0)(uVar4,uVar5,&local_50,&local_80);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xffd8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 0x28;
  }
  else {
    puVar6 = malloc(0x28);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  puVar6[4] = 0;
  puVar6[1] = 0;
  *puVar6 = 0;
  puVar6[3] = 0;
  puVar6[2] = 0;
  *puVar6 = local_80;
  puVar6[1] = uStack_78;
  puVar6[2] = local_70;
  puVar6[3] = local_68;
  puVar6[4] = local_60;
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  local_40 = 0x2800000000;
  uVar9 = RingBuffer_write(uVar4,&local_40,8);
  if ((uVar9 & 1) != 0) {
    RingBuffer_write(uVar4,puVar6,0x28);
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001428ec  size=188 */

void vt_handle_vkGetMemoryFdKHR(int *param_1)

{
  long lVar1;
  int *piVar2;
  int local_114;
  struct msghdr local_110;
  struct iovec local_d8;
  uint64_t local_c8;
  uint64_t local_c0;
  int local_b8;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar1 + 0x28);
  piVar2 = (int *)VkObject_fromId(**(uint64_t **)(param_1 + 0xc));
  local_d8.iov_base = &local_114;
  local_110.msg_iov = &local_d8;
  local_d8.iov_len = 4;
  local_114 = -(uint32_t)(*piVar2 == -1);
  local_110.msg_iovlen = 1;
  local_110.msg_control = &local_c8;
  local_110.msg_name = (void *)0x0;
  local_110.msg_namelen = 0;
  local_110.msg_flags = 0;
  local_110.msg_controllen = 0x14;
  local_c0 = 0x100000001;
  local_c8 = 0x14;
  local_b8 = *piVar2;
  sendmsg(*param_1,&local_110,0);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001463e0  size=432 */

/* WARNING: Type propagation algorithm not settling */

void vt_handle_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(long param_1)

{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  uint8_t *__s;
  char *pcVar7;
  unsigned long uVar8;
  unsigned long unaff_x21;
  void *__src;
  uint32_t local_54 [3];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    uVar8 = 1;
    lVar5 = param_1;
  }
  else {
    uVar8 = 9;
    lVar5 = *(long *)(pcVar7 + 1);
  }
  if (*(int *)(pcVar7 + uVar8) < 1) {
    uVar6 = VkObject_fromId(lVar5);
  }
  else {
    uVar3 = *(uint32_t *)(pcVar7 + (uVar8 | 4));
    unaff_x21 = (unsigned long)uVar3;
    local_54[0] = uVar3;
    uVar6 = VkObject_fromId(lVar5);
    if (uVar3 == 0) {
      __src = (void *)0x0;
      goto LAB_0014646c;
    }
  }
  __src = calloc(unaff_x21 & 0xffffffff,4);
LAB_0014646c:
  ((generic_fn_t)DAT_001940a8)(uVar6,local_54,__src);
  iVar2 = 0xd;
  if (__src != (void *)0x0) {
    iVar2 = local_54[0] * 4 + 0xd;
  }
  iVar1 = iVar2 + *(int *)(param_1 + 0x48);
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s = malloc((long)iVar2);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar2);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 4;
  *(uint32_t *)(__s + 5) = local_54[0];
  if (__src == (void *)0x0) {
    *(uint32_t *)(__s + 9) = 0;
  }
  else {
    *(uint32_t *)(__s + 9) = local_54[0];
    memcpy(__s + 0xd,__src,(long)(int)local_54[0] << 2);
  }
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_54[1] = 0;
  local_54[2] = iVar2;
  uVar8 = RingBuffer_write(uVar6,local_54 + 1,8);
  if (((uVar8 & 1) != 0) && (0 < iVar2)) {
    RingBuffer_write(uVar6,__s,iVar2);
  }
  if (*(long *)(lVar4 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00142784  size=360 */

void vt_handle_vkGetPhysicalDeviceExternalBufferProperties(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  char *pcVar7;
  unsigned long uVar8;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t local_68;
  unsigned long local_60 [6];
  
  /* stack canary setup */
  local_60[5] = *(long *)(lVar3 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_60[0] = 0;
  local_60[3] = 0;
  local_60[2] = 0;
  if (*pcVar7 == '\0') {
    uVar8 = 1;
    lVar4 = param_1;
  }
  else {
    uVar8 = 9;
    lVar4 = *(long *)(pcVar7 + 1);
  }
  if (0 < *(int *)(pcVar7 + uVar8)) {
    puVar1 = (uint32_t *)(pcVar7 + (uVar8 | 4));
    local_60[0] = (unsigned long)*puVar1;
    local_60[2] = *(unsigned long *)(puVar1 + 1);
    local_60[3] = (unsigned long)puVar1[3];
  }
  local_60[1] = 0;
  uVar5 = VkObject_fromId(lVar4);
  uStack_78 = 0;
  local_80 = 0;
  local_68 = 0;
  local_70 = 0;
  ((generic_fn_t)DAT_00193fc0)(uVar5,local_60,&local_80);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff0) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 0x10;
  }
  else {
    puVar6 = malloc(0x10);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *puVar6 = 0;
  puVar6[1] = 0;
  *(uint32_t *)puVar6 = (uint32_t)local_80;
  *(uint32_t *)((long)puVar6 + 4) = (uint32_t)local_70;
  local_60[4] = 0x1000000000;
  *(uint32_t *)(puVar6 + 1) = (*(uint32_t*)((char*)&local_70 + 4));
  *(uint32_t *)((long)puVar6 + 0xc) = (uint32_t)local_68;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uVar8 = RingBuffer_write(uVar5,local_60 + 4,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar6,0x10);
  }
  if (*(long *)(lVar3 + 0x28) == local_60[5]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00142d34  size=344 */

void vt_handle_vkGetPhysicalDeviceExternalFenceProperties(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t *puVar5;
  char *pcVar6;
  unsigned long uVar7;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t local_68;
  unsigned long local_58 [5];
  
  /* stack canary setup */
  local_58[4] = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  local_58[0] = 0;
  local_58[2] = 0;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
    lVar3 = param_1;
  }
  else {
    uVar7 = 9;
    lVar3 = *(long *)(pcVar6 + 1);
  }
  if (0 < *(int *)(pcVar6 + uVar7)) {
    local_58[0] = (unsigned long)*(uint32_t *)(pcVar6 + (uVar7 | 4));
    local_58[2] = (unsigned long)*(uint32_t *)((long)(pcVar6 + (uVar7 | 4)) + 4);
  }
  local_58[1] = 0;
  uVar4 = VkObject_fromId(lVar3);
  uStack_78 = 0;
  local_80 = 0;
  local_68 = 0;
  local_70 = 0;
  ((generic_fn_t)DAT_00193fe0)(uVar4,local_58,&local_80);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xfff0) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 0x10;
  }
  else {
    puVar5 = malloc(0x10);
    ArrayList_add(param_1 + 0x50,puVar5);
  }
  *puVar5 = 0;
  puVar5[1] = 0;
  *(uint32_t *)puVar5 = (uint32_t)local_80;
  *(uint32_t *)((long)puVar5 + 4) = (uint32_t)local_70;
  local_58[3] = 0x1000000000;
  *(uint32_t *)(puVar5 + 1) = (*(uint32_t*)((char*)&local_70 + 4));
  *(uint32_t *)((long)puVar5 + 0xc) = (uint32_t)local_68;
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  uVar7 = RingBuffer_write(uVar4,local_58 + 3,8);
  if ((uVar7 & 1) != 0) {
    RingBuffer_write(uVar4,puVar5,0x10);
  }
  if (*(long *)(lVar2 + 0x28) == local_58[4]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001429a8  size=604 */

void vt_handle_vkGetPhysicalDeviceExternalSemaphoreProperties(long param_1)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  int iVar4;
  long lVar5;
  uint64_t *puVar6;
  uint64_t uVar7;
  int iVar8;
  char *pcVar9;
  unsigned long uVar10;
  uint32_t *puVar11;
  uint64_t unaff_x20;
  uint64_t *puVar12;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  unsigned long local_88;
  uint64_t *local_80;
  uint64_t local_78;
  uint64_t local_70;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar5 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_88 = 0;
  local_80 = (uint64_t *)0x0;
  local_78 = 0;
  if (*pcVar9 == '\0') {
    uVar10 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar9 + 1);
    uVar10 = 9;
  }
  if (0 < *(int *)(pcVar9 + uVar10)) {
    puVar1 = (uint32_t *)(pcVar9 + (uVar10 | 4));
    puVar11 = puVar1 + 1;
    iVar8 = 8;
    local_88 = (unsigned long)*puVar1;
    puVar12 = (uint64_t *)0x0;
    do {
      puVar6 = puVar12;
      if (*puVar11 == 0x3b9df29a) {
        iVar4 = *(int *)((long)puVar1 + (long)iVar8);
        uVar10 = (long)iVar8 + 4;
        if (0 < iVar4) {
          iVar8 = *(int *)(param_1 + 0x48);
          if ((iVar8 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar8);
            *(int *)(param_1 + 0x48) = iVar8 + 0x20;
          }
          else {
            puVar6 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar6);
          }
          puVar6[1] = 0;
          *puVar6 = 0;
          puVar6[3] = 0;
          puVar6[2] = 0;
          puVar2 = (uint32_t *)((long)puVar1 + uVar10);
          uVar3 = *puVar2;
          puVar6[1] = 0;
          uVar10 = (unsigned long)(uint32_t)(iVar4 + (int)uVar10);
          *(uint32_t *)puVar6 = uVar3;
          *(uint32_t *)(puVar6 + 2) = puVar2[1];
          uVar7 = *(uint64_t *)(puVar2 + 2);
          puVar6[1] = puVar12;
          puVar6[3] = uVar7;
        }
      }
      else {
        if (*puVar11 == 0xffffffff) goto LAB_00142ae0;
        uVar10 = (unsigned long)(iVar8 + 4);
      }
      puVar11 = (uint32_t *)((long)puVar1 + (long)(int)uVar10);
      iVar8 = (int)uVar10 + 4;
      puVar12 = puVar6;
    } while( true );
  }
LAB_00142b10:
  uVar7 = VkObject_fromId(unaff_x20);
  uStack_a8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  ((generic_fn_t)DAT_00193fd0)(uVar7,&local_88,&local_b0);
  iVar8 = *(int *)(param_1 + 0x48);
  if ((iVar8 < 0xfff0) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar12 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar8);
    *(int *)(param_1 + 0x48) = iVar8 + 0x10;
  }
  else {
    puVar12 = malloc(0x10);
    ArrayList_add(param_1 + 0x50,puVar12);
  }
  *puVar12 = 0;
  puVar12[1] = 0;
  *(uint32_t *)puVar12 = (uint32_t)local_b0;
  *(uint32_t *)((long)puVar12 + 4) = (uint32_t)local_a0;
  local_70 = 0x1000000000;
  *(uint32_t *)(puVar12 + 1) = (*(uint32_t*)((char*)&local_a0 + 4));
  *(uint32_t *)((long)puVar12 + 0xc) = (uint32_t)local_98;
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  uVar10 = RingBuffer_write(uVar7,&local_70,8);
  if ((uVar10 & 1) != 0) {
    RingBuffer_write(uVar7,puVar12,0x10);
  }
  if (*(long *)(lVar5 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00142ae0:
  if (puVar12 == (uint64_t *)0x0) {
    local_80 = (uint64_t *)0x0;
  }
  else {
    puVar6 = (uint64_t *)0x0;
    do {
      local_80 = puVar12;
      puVar12 = (uint64_t *)local_80[1];
      local_80[1] = puVar6;
      puVar6 = local_80;
    } while (puVar12 != (uint64_t *)0x0);
  }
  local_78 = ((uint64_t)((*(uint32_t*)((char*)&local_78 + 4))) << 32 | (uint32_t)(*(uint32_t *)((long)puVar1 + (long)iVar8)));
  goto LAB_00142b10;
}


/* @0012f0fc  size=748 */

void vt_handle_vkGetPhysicalDeviceFeatures(long param_1)

{
  int iVar1;
  long lVar2;
  uint64_t uVar3;
  uint64_t *puVar4;
  unsigned long uVar5;
  uint64_t local_120;
  uint64_t uStack_118;
  uint64_t local_110;
  uint64_t uStack_108;
  uint64_t local_100;
  uint64_t local_f8;
  uint64_t local_f0;
  uint64_t uStack_e8;
  uint64_t local_e0;
  uint64_t local_d8;
  uint64_t local_d0;
  uint64_t uStack_c8;
  uint64_t local_c0;
  uint64_t local_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t local_80;
  uint64_t local_78;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t local_60;
  uint32_t local_58;
  uint32_t local_54;
  uint32_t uStack_50;
  uint64_t uStack_4c;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  uVar3 = VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
  uStack_4c = 0;
  uStack_50 = 0;
  uStack_68 = 0;
  local_70 = 0;
  local_58 = 0;
  local_54 = 0;
  local_60 = 0;
  uStack_88 = 0;
  local_90 = 0;
  local_78 = 0;
  local_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_a0 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  local_b8 = 0;
  local_c0 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  local_d8 = 0;
  local_e0 = 0;
  uStack_108 = 0;
  local_110 = 0;
  local_f8 = 0;
  local_100 = 0;
  uStack_118 = 0;
  local_120 = 0;
  ((generic_fn_t)DAT_00193b20)(uVar3,&local_120);
  checkDeviceFeatures(&local_120,0);
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xff24) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar4 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 0xdc;
  }
  else {
    puVar4 = malloc(0xdc);
    ArrayList_add(param_1 + 0x50,puVar4);
  }
  *(uint64_t *)((long)puVar4 + 0xd4) = 0;
  *(uint64_t *)((long)puVar4 + 0xcc) = 0;
  puVar4[0x17] = 0;
  puVar4[0x16] = 0;
  puVar4[0x19] = 0;
  puVar4[0x18] = 0;
  puVar4[0x13] = 0;
  puVar4[0x12] = 0;
  puVar4[0x15] = 0;
  puVar4[0x14] = 0;
  puVar4[0xf] = 0;
  puVar4[0xe] = 0;
  puVar4[0x11] = 0;
  puVar4[0x10] = 0;
  puVar4[0xb] = 0;
  puVar4[10] = 0;
  puVar4[0xd] = 0;
  puVar4[0xc] = 0;
  puVar4[7] = 0;
  puVar4[6] = 0;
  puVar4[9] = 0;
  puVar4[8] = 0;
  puVar4[3] = 0;
  puVar4[2] = 0;
  puVar4[5] = 0;
  puVar4[4] = 0;
  puVar4[1] = 0;
  *puVar4 = 0;
  *(uint32_t *)puVar4 = (uint32_t)local_120;
  *(uint32_t *)((long)puVar4 + 4) = (*(uint32_t*)((char*)&local_120 + 4));
  *(uint32_t *)(puVar4 + 1) = (uint32_t)uStack_118;
  *(uint32_t *)((long)puVar4 + 0xc) = (*(uint32_t*)((char*)&uStack_118 + 4));
  *(uint32_t *)(puVar4 + 2) = (uint32_t)local_110;
  *(uint32_t *)((long)puVar4 + 0x14) = (*(uint32_t*)((char*)&local_110 + 4));
  *(uint32_t *)(puVar4 + 3) = (uint32_t)uStack_108;
  *(uint32_t *)((long)puVar4 + 0x1c) = (*(uint32_t*)((char*)&uStack_108 + 4));
  *(uint32_t *)(puVar4 + 4) = (uint32_t)local_100;
  *(uint32_t *)((long)puVar4 + 0x24) = (*(uint32_t*)((char*)&local_100 + 4));
  *(uint32_t *)(puVar4 + 5) = (uint32_t)local_f8;
  *(uint32_t *)((long)puVar4 + 0x2c) = (*(uint32_t*)((char*)&local_f8 + 4));
  *(uint32_t *)(puVar4 + 6) = (uint32_t)local_f0;
  *(uint32_t *)((long)puVar4 + 0x34) = (*(uint32_t*)((char*)&local_f0 + 4));
  *(uint32_t *)(puVar4 + 7) = (uint32_t)uStack_e8;
  *(uint32_t *)((long)puVar4 + 0x3c) = (*(uint32_t*)((char*)&uStack_e8 + 4));
  *(uint32_t *)(puVar4 + 8) = (uint32_t)local_e0;
  *(uint32_t *)((long)puVar4 + 0x44) = (*(uint32_t*)((char*)&local_e0 + 4));
  *(uint32_t *)(puVar4 + 9) = (uint32_t)local_d8;
  *(uint32_t *)((long)puVar4 + 0x4c) = (*(uint32_t*)((char*)&local_d8 + 4));
  *(uint32_t *)(puVar4 + 10) = (uint32_t)local_d0;
  *(uint32_t *)((long)puVar4 + 0x54) = (*(uint32_t*)((char*)&local_d0 + 4));
  *(uint32_t *)(puVar4 + 0xb) = (uint32_t)uStack_c8;
  *(uint32_t *)((long)puVar4 + 0x5c) = (*(uint32_t*)((char*)&uStack_c8 + 4));
  *(uint32_t *)(puVar4 + 0xc) = (uint32_t)local_c0;
  *(uint32_t *)((long)puVar4 + 100) = (*(uint32_t*)((char*)&local_c0 + 4));
  *(uint32_t *)(puVar4 + 0xd) = (uint32_t)local_b8;
  *(uint32_t *)((long)puVar4 + 0x6c) = (*(uint32_t*)((char*)&local_b8 + 4));
  *(uint32_t *)(puVar4 + 0xe) = (uint32_t)local_b0;
  *(uint32_t *)((long)puVar4 + 0x74) = (*(uint32_t*)((char*)&local_b0 + 4));
  *(uint32_t *)(puVar4 + 0xf) = (uint32_t)uStack_a8;
  *(uint32_t *)((long)puVar4 + 0x7c) = (*(uint32_t*)((char*)&uStack_a8 + 4));
  *(uint32_t *)(puVar4 + 0x10) = (uint32_t)local_a0;
  *(uint32_t *)((long)puVar4 + 0x84) = (*(uint32_t*)((char*)&local_a0 + 4));
  *(uint32_t *)(puVar4 + 0x11) = (uint32_t)local_98;
  *(uint32_t *)((long)puVar4 + 0x8c) = (*(uint32_t*)((char*)&local_98 + 4));
  *(uint32_t *)(puVar4 + 0x12) = (uint32_t)local_90;
  *(uint32_t *)((long)puVar4 + 0x94) = (*(uint32_t*)((char*)&local_90 + 4));
  *(uint32_t *)(puVar4 + 0x13) = (uint32_t)uStack_88;
  *(uint32_t *)((long)puVar4 + 0x9c) = (*(uint32_t*)((char*)&uStack_88 + 4));
  *(uint32_t *)(puVar4 + 0x14) = (uint32_t)local_80;
  *(uint32_t *)((long)puVar4 + 0xa4) = (*(uint32_t*)((char*)&local_80 + 4));
  *(uint32_t *)(puVar4 + 0x15) = (uint32_t)local_78;
  *(uint32_t *)((long)puVar4 + 0xac) = (*(uint32_t*)((char*)&local_78 + 4));
  *(uint32_t *)(puVar4 + 0x16) = (uint32_t)local_70;
  *(uint32_t *)((long)puVar4 + 0xb4) = (*(uint32_t*)((char*)&local_70 + 4));
  *(uint32_t *)(puVar4 + 0x17) = (uint32_t)uStack_68;
  *(uint32_t *)((long)puVar4 + 0xbc) = (*(uint32_t*)((char*)&uStack_68 + 4));
  *(uint32_t *)(puVar4 + 0x18) = (uint32_t)local_60;
  *(uint32_t *)((long)puVar4 + 0xc4) = (*(uint32_t*)((char*)&local_60 + 4));
  *(uint32_t *)(puVar4 + 0x19) = local_58;
  *(uint32_t *)((long)puVar4 + 0xcc) = local_54;
  *(uint32_t *)(puVar4 + 0x1a) = uStack_50;
  *(uint32_t *)((long)puVar4 + 0xd4) = (uint32_t)uStack_4c;
  *(uint32_t *)(puVar4 + 0x1b) = (*(uint32_t*)((char*)&uStack_4c + 4));
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  local_40 = 0xdc00000000;
  uVar5 = RingBuffer_write(uVar3,&local_40,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar3,puVar4,0xdc);
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013c968  size=5360 */

void vt_handle_vkGetPhysicalDeviceFeatures2(long param_1)

{
  uint32_t *puVar1;
  long lVar2;
  uint64_t uVar3;
  uint32_t *__s;
  unsigned long uVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  char *pcVar9;
  uint32_t *puVar10;
  long lVar11;
  uint32_t *puVar12;
  int iVar13;
  uint64_t unaff_x20;
  uint32_t *puVar14;
  int iVar15;
  uint64_t local_1b0;
  uint32_t *puStack_1a8;
  uint64_t local_1a0;
  uint64_t uStack_198;
  uint64_t local_190;
  uint64_t local_188;
  uint64_t local_180;
  uint64_t uStack_178;
  uint64_t local_170;
  uint64_t local_168;
  uint64_t local_160;
  uint64_t uStack_158;
  uint64_t local_150;
  uint64_t local_148;
  uint64_t local_140;
  uint64_t uStack_138;
  uint64_t local_130;
  uint64_t local_128;
  uint64_t local_120;
  uint64_t uStack_118;
  uint64_t local_110;
  uint64_t local_108;
  uint64_t local_100;
  uint64_t uStack_f8;
  uint64_t local_f0;
  uint64_t local_e8;
  uint64_t local_e0;
  uint64_t uStack_d8;
  uint64_t local_d0;
  uint64_t local_c8;
  uint32_t local_b8;
  int iStack_b4;
  long local_b0;
  
  /* stack canary setup */
  local_b0 = *(long *)(lVar2 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  uStack_d8 = 0;
  local_e0 = 0;
  local_c8 = 0;
  local_d0 = 0;
  uStack_f8 = 0;
  local_100 = 0;
  local_e8 = 0;
  local_f0 = 0;
  uStack_118 = 0;
  local_120 = 0;
  local_108 = 0;
  local_110 = 0;
  uStack_138 = 0;
  local_140 = 0;
  local_128 = 0;
  local_130 = 0;
  uStack_158 = 0;
  local_160 = 0;
  local_148 = 0;
  local_150 = 0;
  uStack_178 = 0;
  local_180 = 0;
  local_168 = 0;
  local_170 = 0;
  uStack_198 = 0;
  local_1a0 = 0;
  local_188 = 0;
  local_190 = 0;
  puStack_1a8 = (uint32_t *)0x0;
  local_1b0 = 0;
  if (*pcVar9 == '\0') {
    lVar11 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar9 + 1);
    lVar11 = 9;
  }
  if (0 < *(int *)(pcVar9 + lVar11)) {
    FUN_0014ce84(&local_1b0,pcVar9 + ((uint32_t)lVar11 | 4),param_1 + 0x40);
  }
  uVar3 = VkObject_fromId(unaff_x20);
  ((generic_fn_t)DAT_00193f78)(uVar3,&local_1b0);
  checkDeviceFeatures(&local_1a0,puStack_1a8);
  if (puStack_1a8 == (uint32_t *)0x0) {
    iVar15 = 4;
  }
  else {
    iVar15 = 4;
    puVar10 = puStack_1a8;
    do {
      uVar8 = *puVar10;
      puVar10 = *(uint32_t **)(puVar10 + 2);
      iVar5 = 0x10;
      if ((int)uVar8 < 0x3b9e38ea) {
        if ((int)uVar8 < 0x3b9c9ec0) {
          if ((int)uVar8 < 0x3b9bc018) {
            if ((int)uVar8 < 0x3b9b3760) {
              if (uVar8 == 0x31) {
                iVar5 = 0x3c;
              }
              else if (uVar8 == 0x33) {
                iVar5 = 200;
              }
              else {
                if (uVar8 != 0x35) goto LAB_0013cf04;
                iVar5 = 0x48;
              }
            }
            else {
              if (uVar8 == 0x3b9b3760) goto LAB_0013cb00;
              if (uVar8 != 0x3b9b75e3) {
                if (uVar8 == 0x3b9b9909) goto LAB_0013ce70;
                goto LAB_0013cf04;
              }
            }
          }
          else if ((int)uVar8 < 0x3b9c0a50) {
            if ((uVar8 != 0x3b9bc018) && (uVar8 != 0x3b9bcbd0)) {
              if (uVar8 == 0x3b9c0669) goto LAB_0013cb00;
              goto LAB_0013cf04;
            }
          }
          else if ((int)uVar8 < 0x3b9c5870) {
            if (uVar8 == 0x3b9c0a50) goto LAB_0013cb00;
            if (uVar8 != 0x3b9c0e38) goto LAB_0013cf04;
            iVar5 = 0x1c;
          }
          else if ((uVar8 != 0x3b9c5870) && (uVar8 != 0x3b9c6fe0)) goto LAB_0013cf04;
        }
        else if ((int)uVar8 < 0x3b9d7d68) {
          if ((int)uVar8 < 0x3b9d2b64) {
            if ((uVar8 == 0x3b9c9ec0) || (uVar8 == 0x3b9ce510)) goto LAB_0013cb00;
            if (uVar8 != 0x3b9d0069) goto LAB_0013cf04;
          }
          else if (uVar8 != 0x3b9d2b64) {
            if (uVar8 == 0x3b9d3ee9) {
              iVar5 = 0x5c;
            }
            else if (uVar8 != 0x3b9d7598) goto LAB_0013cf04;
          }
        }
        else if ((int)uVar8 < 0x3b9df298) {
          if (uVar8 != 0x3b9d7d68) {
            if ((uVar8 == 0x3b9d8920) || (uVar8 == 0x3b9db032)) goto LAB_0013cb00;
            goto LAB_0013cf04;
          }
LAB_0013ce70:
          iVar5 = 0x18;
        }
        else if ((int)uVar8 < 0x3b9e11d8) {
          if (uVar8 != 0x3b9df298) {
            uVar6 = 0x238;
            goto LAB_0013cd18;
          }
        }
        else if ((uVar8 != 0x3b9e11d8) && (uVar8 != 0x3b9e2948)) goto LAB_0013cf04;
        goto LAB_0013cb04;
      }
      if ((int)uVar8 < 0x3b9f2b1a) {
        if ((int)uVar8 < 0x3b9ec588) {
          if ((int)uVar8 < 0x3b9ea648) {
            if (uVar8 == 0x3b9e38ea) {
LAB_0013cb00:
              iVar5 = 0x14;
            }
            else if (uVar8 != 0x3b9e7768) {
              uVar6 = 0x9e78;
LAB_0013cd18:
              if (uVar8 == (uVar6 | 0x3b9e0000)) goto LAB_0013ce70;
              goto LAB_0013cf04;
            }
          }
          else if (uVar8 != 0x3b9ea648) {
            if (uVar8 != 0x3b9eaa30) {
              uVar6 = 0xb5e8;
              goto LAB_0013cd18;
            }
            goto LAB_0013cb00;
          }
        }
        else if ((int)uVar8 < 0x3b9f0020) {
          if ((uVar8 != 0x3b9ec588) && (uVar8 != 0x3b9edcf8)) {
            uVar6 = 0xf080;
            goto LAB_0013cd18;
          }
        }
        else if ((int)uVar8 < 0x3b9f13a8) {
          if ((uVar8 != 0x3b9f0020) && (uVar8 != 0x3b9f0fc0)) goto LAB_0013cf04;
        }
        else if (uVar8 != 0x3b9f13a8) {
          if (uVar8 == 0x3b9f2730) goto LAB_0013ce70;
          goto LAB_0013cf04;
        }
      }
      else if ((int)uVar8 < 0x3ba02518) {
        if ((int)uVar8 < 0x3b9f9497) {
          if (uVar8 == 0x3b9f2b1a) goto LAB_0013cb00;
          if ((uVar8 != 0x3b9f4a58) && (uVar8 != 0x3b9f5228)) goto LAB_0013cf04;
        }
        else if ((int)uVar8 < 0x3b9fe698) {
          if ((uVar8 != 0x3b9f9497) && (uVar8 != 0x3b9fbf88)) goto LAB_0013cf04;
        }
        else if (uVar8 != 0x3b9fe698) {
          if (uVar8 == 0x3b9ffa20) goto LAB_0013cb00;
          goto LAB_0013cf04;
        }
      }
      else if ((int)uVar8 < 0x3ba10f78) {
        if (((uVar8 != 0x3ba02518) && (uVar8 != 0x3ba034b8)) && (uVar8 != 0x3ba09a48))
        goto LAB_0013cf04;
      }
      else {
        if ((int)uVar8 < 0x3ba1bb58) {
          if (uVar8 == 0x3ba10f78) goto LAB_0013cb00;
          uVar6 = 0x1748;
        }
        else {
          if (uVar8 == 0x3ba1bb58) {
            iVar5 = 0x88;
            goto LAB_0013cb04;
          }
          uVar6 = 0xd6b0;
        }
        if (uVar8 != (uVar6 | 0x3ba10000)) {
LAB_0013cf04:
          iVar5 = 8;
        }
      }
LAB_0013cb04:
      iVar15 = iVar5 + iVar15;
    } while (puVar10 != (uint32_t *)0x0);
  }
  iVar5 = iVar15 + 0xe0;
  iVar13 = *(int *)(param_1 + 0x48) + iVar5;
  if ((iVar13 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar13;
  }
  else {
    __s = malloc((long)iVar5);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar5);
  *__s = (uint32_t)local_1b0;
  if (puStack_1a8 == (uint32_t *)0x0) {
    uVar8 = 4;
  }
  else {
    uVar8 = 4;
    puVar10 = puStack_1a8;
    do {
      uVar6 = *puVar10;
      uVar4 = (unsigned long)uVar8 + 4;
      *(uint32_t *)((long)__s + (unsigned long)uVar8) = uVar6;
      puVar12 = *(uint32_t **)(puVar10 + 2);
      puVar10[2] = 0;
      puVar10[3] = 0;
      if ((int)uVar6 < 0x3b9e38ea) {
        if (0x3b9c9ebf < (int)uVar6) {
          if ((int)uVar6 < 0x3b9d7d68) {
            if ((int)uVar6 < 0x3b9d2b64) {
              if (uVar6 == 0x3b9c9ec0) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9c9ec00000000c;
              }
              else {
                if (uVar6 != 0x3b9ce510) {
                  if (uVar6 != 0x3b9d0069) goto LAB_0013de44;
                  *(uint64_t *)((long)__s + uVar4) = 0x3b9d006900000008;
                  goto LAB_0013d380;
                }
                *(uint64_t *)((long)__s + uVar4) = 0x3b9ce5100000000c;
              }
              goto LAB_0013de1c;
            }
            if (uVar6 == 0x3b9d2b64) {
              *(uint64_t *)((long)__s + uVar4) = 0x3b9d2b6400000008;
            }
            else {
              if (uVar6 == 0x3b9d3ee9) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9d3ee900000054;
                uVar6 = uVar8 + 8;
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 4) = puVar10[4];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 8) = puVar10[5];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xc) = puVar10[6];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x10) = puVar10[7];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x14) = puVar10[8];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x18) = puVar10[9];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x1c) = puVar10[10];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x20) = puVar10[0xb];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x24) = puVar10[0xc];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x28) = puVar10[0xd];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x2c) = puVar10[0xe];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x30) = puVar10[0xf];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x34) = puVar10[0x10];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x38) = puVar10[0x11];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x3c) = puVar10[0x12];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x40) = puVar10[0x13];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x44) = puVar10[0x14];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x48) = puVar10[0x15];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x4c) = puVar10[0x16];
                uVar7 = puVar10[0x17];
                puVar14 = (uint32_t *)((long)__s + (unsigned long)uVar6 + 0x50);
                iVar13 = 0x5c;
                goto LAB_0013d390;
              }
              if (uVar6 != 0x3b9d7598) goto LAB_0013de44;
              *(uint64_t *)((long)__s + uVar4) = 0x3b9d759800000008;
            }
          }
          else {
            if ((int)uVar6 < 0x3b9df298) {
              if (uVar6 == 0x3b9d7d68) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9d7d6800000010;
LAB_0013dc9c:
                uVar6 = uVar8 + 8;
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 4) = puVar10[4];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 8) = puVar10[5];
                uVar7 = puVar10[6];
                puVar14 = (uint32_t *)((long)__s + (unsigned long)uVar6 + 0xc);
                iVar13 = 0x18;
                goto LAB_0013d390;
              }
              if (uVar6 == 0x3b9d8920) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9d89200000000c;
              }
              else {
                if (uVar6 != 0x3b9db032) goto LAB_0013de44;
                *(uint64_t *)((long)__s + uVar4) = 0x3b9db0320000000c;
              }
              goto LAB_0013de1c;
            }
            if ((int)uVar6 < 0x3b9e11d8) {
              if (uVar6 != 0x3b9df298) {
                if (uVar6 == 0x3b9e0238) {
                  *(uint64_t *)((long)__s + uVar4) = 0x3b9e023800000010;
                  goto LAB_0013dc9c;
                }
                goto LAB_0013de44;
              }
              *(uint64_t *)((long)__s + uVar4) = 0x3b9df29800000008;
            }
            else if (uVar6 == 0x3b9e11d8) {
              *(uint64_t *)((long)__s + uVar4) = 0x3b9e11d800000008;
            }
            else {
              if (uVar6 != 0x3b9e2948) goto LAB_0013de44;
              *(uint64_t *)((long)__s + uVar4) = 0x3b9e294800000008;
            }
          }
          goto LAB_0013d380;
        }
        if (0x3b9bc017 < (int)uVar6) {
          if ((int)uVar6 < 0x3b9c0a50) {
            if (uVar6 == 0x3b9bc018) {
              *(uint64_t *)((long)__s + uVar4) = 0x3b9bc01800000008;
            }
            else {
              if (uVar6 != 0x3b9bcbd0) {
                if (uVar6 != 0x3b9c0669) goto LAB_0013de44;
                *(uint64_t *)((long)__s + uVar4) = 0x3b9c06690000000c;
                goto LAB_0013de1c;
              }
              *(uint64_t *)((long)__s + uVar4) = 0x3b9bcbd000000008;
            }
          }
          else {
            if ((int)uVar6 < 0x3b9c5870) {
              if (uVar6 == 0x3b9c0a50) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9c0a500000000c;
                goto LAB_0013de1c;
              }
              if (uVar6 == 0x3b9c0e38) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9c0e3800000014;
                uVar6 = uVar8 + 8;
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 4) = puVar10[4];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 8) = puVar10[5];
                *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xc) = puVar10[6];
                uVar7 = puVar10[7];
                puVar14 = (uint32_t *)((long)__s + (unsigned long)uVar6 + 0x10);
                iVar13 = 0x1c;
                goto LAB_0013d390;
              }
LAB_0013de44:
              uVar7 = 0;
              puVar14 = (uint32_t *)((long)__s + (uVar4 & 0xffffffff));
              iVar13 = 8;
              goto LAB_0013d390;
            }
            if (uVar6 == 0x3b9c5870) {
              *(uint64_t *)((long)__s + uVar4) = 0x3b9c587000000008;
            }
            else {
              if (uVar6 != 0x3b9c6fe0) goto LAB_0013de44;
              *(uint64_t *)((long)__s + uVar4) = 0x3b9c6fe000000008;
            }
          }
          goto LAB_0013d380;
        }
        if (0x3b9b375f < (int)uVar6) {
          if (uVar6 == 0x3b9b3760) {
            *(uint64_t *)((long)__s + uVar4) = 0x3b9b37600000000c;
            goto LAB_0013de1c;
          }
          if (uVar6 != 0x3b9b75e3) {
            if (uVar6 == 0x3b9b9909) {
              *(uint64_t *)((long)__s + uVar4) = 0x3b9b990900000010;
              goto LAB_0013dc9c;
            }
            goto LAB_0013de44;
          }
          *(uint64_t *)((long)__s + uVar4) = 0x3b9b75e300000008;
          goto LAB_0013d380;
        }
        if (uVar6 == 0x31) {
          *(uint64_t *)((long)__s + uVar4) = 0x3100000034;
          uVar6 = uVar8 + 8;
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 4) = puVar10[4];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 8) = puVar10[5];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xc) = puVar10[6];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x10) = puVar10[7];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x14) = puVar10[8];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x18) = puVar10[9];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x1c) = puVar10[10];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x20) = puVar10[0xb];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x24) = puVar10[0xc];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x28) = puVar10[0xd];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x2c) = puVar10[0xe];
          uVar7 = puVar10[0xf];
          puVar14 = (uint32_t *)((long)__s + (unsigned long)uVar6 + 0x30);
          iVar13 = 0x3c;
        }
        else if (uVar6 == 0x33) {
          *(uint64_t *)((long)__s + uVar4) = 0x33000000c0;
          uVar6 = uVar8 + 8;
          puVar14 = (uint32_t *)((long)__s + (unsigned long)uVar6 + 0xbc);
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 4) = puVar10[4];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 8) = puVar10[5];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xc) = puVar10[6];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x10) = puVar10[7];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x14) = puVar10[8];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x18) = puVar10[9];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x1c) = puVar10[10];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x20) = puVar10[0xb];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x24) = puVar10[0xc];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x28) = puVar10[0xd];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x2c) = puVar10[0xe];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x30) = puVar10[0xf];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x34) = puVar10[0x10];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x38) = puVar10[0x11];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x3c) = puVar10[0x12];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x40) = puVar10[0x13];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x44) = puVar10[0x14];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x48) = puVar10[0x15];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x4c) = puVar10[0x16];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x50) = puVar10[0x17];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x54) = puVar10[0x18];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x58) = puVar10[0x19];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x5c) = puVar10[0x1a];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x60) = puVar10[0x1b];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 100) = puVar10[0x1c];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x68) = puVar10[0x1d];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x6c) = puVar10[0x1e];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x70) = puVar10[0x1f];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x74) = puVar10[0x20];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x78) = puVar10[0x21];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x7c) = puVar10[0x22];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x80) = puVar10[0x23];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x84) = puVar10[0x24];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x88) = puVar10[0x25];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x8c) = puVar10[0x26];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x90) = puVar10[0x27];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x94) = puVar10[0x28];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x98) = puVar10[0x29];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x9c) = puVar10[0x2a];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xa0) = puVar10[0x2b];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xa4) = puVar10[0x2c];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xa8) = puVar10[0x2d];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xac) = puVar10[0x2e];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xb0) = puVar10[0x2f];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xb4) = puVar10[0x30];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xb8) = puVar10[0x31];
          uVar7 = puVar10[0x32];
          iVar13 = 200;
        }
        else {
          if (uVar6 != 0x35) goto LAB_0013de44;
          *(uint64_t *)((long)__s + uVar4) = 0x3500000040;
          uVar6 = uVar8 + 8;
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 4) = puVar10[4];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 8) = puVar10[5];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xc) = puVar10[6];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x10) = puVar10[7];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x14) = puVar10[8];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x18) = puVar10[9];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x1c) = puVar10[10];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x20) = puVar10[0xb];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x24) = puVar10[0xc];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x28) = puVar10[0xd];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x2c) = puVar10[0xe];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x30) = puVar10[0xf];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x34) = puVar10[0x10];
          *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x38) = puVar10[0x11];
          uVar7 = puVar10[0x12];
          puVar14 = (uint32_t *)((long)__s + (unsigned long)uVar6 + 0x3c);
          iVar13 = 0x48;
        }
      }
      else {
        if ((int)uVar6 < 0x3b9f2b1a) {
          if ((int)uVar6 < 0x3b9ec588) {
            if ((int)uVar6 < 0x3b9ea648) {
              if (uVar6 == 0x3b9e38ea) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9e38ea0000000c;
LAB_0013de1c:
                *(uint32_t *)((long)__s + (unsigned long)(uVar8 + 8) + 4) = puVar10[4];
                uVar7 = puVar10[5];
                puVar14 = (uint32_t *)((long)__s + (unsigned long)(uVar8 + 8) + 8);
                iVar13 = 0x14;
                goto LAB_0013d390;
              }
              if (uVar6 != 0x3b9e7768) {
                if (uVar6 == 0x3b9e9e78) {
                  *(uint64_t *)((long)__s + uVar4) = 0x3b9e9e7800000010;
                  goto LAB_0013dc9c;
                }
                goto LAB_0013de44;
              }
              *(uint64_t *)((long)__s + uVar4) = 0x3b9e776800000008;
            }
            else {
              if (uVar6 != 0x3b9ea648) {
                if (uVar6 != 0x3b9eaa30) {
                  if (uVar6 == 0x3b9eb5e8) {
                    *(uint64_t *)((long)__s + uVar4) = 0x3b9eb5e800000010;
                    goto LAB_0013dc9c;
                  }
                  goto LAB_0013de44;
                }
                *(uint64_t *)((long)__s + uVar4) = 0x3b9eaa300000000c;
                goto LAB_0013de1c;
              }
              *(uint64_t *)((long)__s + uVar4) = 0x3b9ea64800000008;
            }
            goto LAB_0013d380;
          }
          if ((int)uVar6 < 0x3b9f0020) {
            if (uVar6 == 0x3b9ec588) {
              uVar3 = 0x3b9ec58800000008;
            }
            else {
              if (uVar6 != 0x3b9edcf8) {
                if (uVar6 == 0x3b9ef080) {
                  *(uint64_t *)((long)__s + uVar4) = 0x3b9ef08000000010;
                  goto LAB_0013dc9c;
                }
                goto LAB_0013de44;
              }
              uVar3 = 0x3b9edcf800000008;
            }
          }
          else if ((int)uVar6 < 0x3b9f13a8) {
            if (uVar6 == 0x3b9f0020) {
              uVar3 = 0x3b9f002000000008;
            }
            else {
              if (uVar6 != 0x3b9f0fc0) goto LAB_0013de44;
              uVar3 = 0x3b9f0fc000000008;
            }
          }
          else {
            if (uVar6 != 0x3b9f13a8) {
              if (uVar6 == 0x3b9f2730) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9f273000000010;
                goto LAB_0013dc9c;
              }
              goto LAB_0013de44;
            }
            uVar3 = 0x3b9f13a800000008;
          }
        }
        else if ((int)uVar6 < 0x3ba02518) {
          if ((int)uVar6 < 0x3b9f9497) {
            if (uVar6 == 0x3b9f2b1a) {
              *(uint64_t *)((long)__s + uVar4) = 0x3b9f2b1a0000000c;
              goto LAB_0013de1c;
            }
            if (uVar6 == 0x3b9f4a58) {
              uVar3 = 0x3b9f4a5800000008;
            }
            else {
              if (uVar6 != 0x3b9f5228) goto LAB_0013de44;
              uVar3 = 0x3b9f522800000008;
            }
          }
          else if ((int)uVar6 < 0x3b9fe698) {
            if (uVar6 == 0x3b9f9497) {
              uVar3 = 0x3b9f949700000008;
            }
            else {
              if (uVar6 != 0x3b9fbf88) goto LAB_0013de44;
              uVar3 = 0x3b9fbf8800000008;
            }
          }
          else {
            if (uVar6 != 0x3b9fe698) {
              if (uVar6 == 0x3b9ffa20) {
                *(uint64_t *)((long)__s + uVar4) = 0x3b9ffa200000000c;
                goto LAB_0013de1c;
              }
              goto LAB_0013de44;
            }
            uVar3 = 0x3b9fe69800000008;
          }
        }
        else if ((int)uVar6 < 0x3ba10f78) {
          if (uVar6 == 0x3ba02518) {
            uVar3 = 0x3ba0251800000008;
          }
          else if (uVar6 == 0x3ba034b8) {
            uVar3 = 0x3ba034b800000008;
          }
          else {
            if (uVar6 != 0x3ba09a48) goto LAB_0013de44;
            uVar3 = 0x3ba09a4800000008;
          }
        }
        else if ((int)uVar6 < 0x3ba1bb58) {
          if (uVar6 == 0x3ba10f78) {
            *(uint64_t *)((long)__s + uVar4) = 0x3ba10f780000000c;
            goto LAB_0013de1c;
          }
          if (uVar6 != 0x3ba11748) goto LAB_0013de44;
          uVar3 = 0x3ba1174800000008;
        }
        else {
          if (uVar6 == 0x3ba1bb58) {
            uVar6 = uVar8 + 8;
            *(uint64_t *)((long)__s + uVar4) = 0x3ba1bb5800000080;
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 4) = puVar10[4];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 8) = puVar10[5];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0xc) = puVar10[6];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x10) = puVar10[7];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x14) = puVar10[8];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x18) = puVar10[9];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x1c) = puVar10[10];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x20) = puVar10[0xb];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x24) = puVar10[0xc];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x28) = puVar10[0xd];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x2c) = puVar10[0xe];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x30) = puVar10[0xf];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x34) = puVar10[0x10];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x38) = puVar10[0x11];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x3c) = puVar10[0x12];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x40) = puVar10[0x13];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x44) = puVar10[0x14];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x48) = puVar10[0x15];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x4c) = puVar10[0x16];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x50) = puVar10[0x17];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x54) = puVar10[0x18];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x58) = puVar10[0x19];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x5c) = puVar10[0x1a];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x60) = puVar10[0x1b];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 100) = puVar10[0x1c];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x68) = puVar10[0x1d];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x6c) = puVar10[0x1e];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x70) = puVar10[0x1f];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x74) = puVar10[0x20];
            *(uint32_t *)((long)__s + (unsigned long)uVar6 + 0x78) = puVar10[0x21];
            uVar7 = puVar10[0x22];
            puVar14 = (uint32_t *)((long)__s + (unsigned long)uVar6 + 0x7c);
            iVar13 = 0x88;
            goto LAB_0013d390;
          }
          if (uVar6 != 0x3ba1d6b0) goto LAB_0013de44;
          uVar3 = 0x3ba1d6b000000008;
        }
        *(uint64_t *)((long)__s + uVar4) = uVar3;
LAB_0013d380:
        uVar7 = puVar10[4];
        puVar14 = (uint32_t *)((long)__s + (unsigned long)(uVar8 + 8) + 4);
        iVar13 = 0x10;
      }
LAB_0013d390:
      *puVar14 = uVar7;
      uVar8 = iVar13 + uVar8;
      *(uint32_t **)(puVar10 + 2) = puVar12;
      puVar10 = puVar12;
    } while (puVar12 != (uint32_t *)0x0);
  }
  puVar1 = (uint32_t *)((long)__s + (long)(int)uVar8);
  *puVar1 = 0xffffffff;
  puVar1[1] = (uint32_t)local_1a0;
  puVar1[2] = (*(uint32_t*)((char*)&local_1a0 + 4));
  puVar1[3] = (uint32_t)uStack_198;
  puVar1[4] = (*(uint32_t*)((char*)&uStack_198 + 4));
  puVar1[5] = (uint32_t)local_190;
  puVar1[6] = (*(uint32_t*)((char*)&local_190 + 4));
  puVar1[7] = (uint32_t)local_188;
  puVar1[8] = (*(uint32_t*)((char*)&local_188 + 4));
  puVar1[9] = (uint32_t)local_180;
  puVar1[10] = (*(uint32_t*)((char*)&local_180 + 4));
  puVar1[0xb] = (uint32_t)uStack_178;
  puVar1[0xc] = (*(uint32_t*)((char*)&uStack_178 + 4));
  puVar1[0xd] = (uint32_t)local_170;
  puVar1[0xe] = (*(uint32_t*)((char*)&local_170 + 4));
  puVar1[0xf] = (uint32_t)local_168;
  puVar1[0x10] = (*(uint32_t*)((char*)&local_168 + 4));
  puVar1[0x11] = (uint32_t)local_160;
  puVar1[0x12] = (*(uint32_t*)((char*)&local_160 + 4));
  puVar1[0x13] = (uint32_t)uStack_158;
  puVar1[0x14] = (*(uint32_t*)((char*)&uStack_158 + 4));
  puVar1[0x15] = (uint32_t)local_150;
  puVar1[0x16] = (*(uint32_t*)((char*)&local_150 + 4));
  puVar1[0x17] = (uint32_t)local_148;
  puVar1[0x18] = (*(uint32_t*)((char*)&local_148 + 4));
  puVar1[0x19] = (uint32_t)local_140;
  puVar1[0x1a] = (*(uint32_t*)((char*)&local_140 + 4));
  puVar1[0x1b] = (uint32_t)uStack_138;
  puVar1[0x1c] = (*(uint32_t*)((char*)&uStack_138 + 4));
  puVar1[0x1d] = (uint32_t)local_130;
  puVar1[0x1e] = (*(uint32_t*)((char*)&local_130 + 4));
  puVar1[0x1f] = (uint32_t)local_128;
  puVar1[0x20] = (*(uint32_t*)((char*)&local_128 + 4));
  puVar1[0x21] = (uint32_t)local_120;
  puVar1[0x22] = (*(uint32_t*)((char*)&local_120 + 4));
  puVar1[0x23] = (uint32_t)uStack_118;
  puVar1[0x24] = (*(uint32_t*)((char*)&uStack_118 + 4));
  puVar1[0x25] = (uint32_t)local_110;
  puVar1[0x26] = (*(uint32_t*)((char*)&local_110 + 4));
  puVar1[0x27] = (uint32_t)local_108;
  puVar1[0x28] = (*(uint32_t*)((char*)&local_108 + 4));
  puVar1[0x29] = (uint32_t)local_100;
  puVar1[0x2a] = (*(uint32_t*)((char*)&local_100 + 4));
  puVar1[0x2b] = (uint32_t)uStack_f8;
  puVar1[0x2c] = (*(uint32_t*)((char*)&uStack_f8 + 4));
  puVar1[0x2d] = (uint32_t)local_f0;
  puVar1[0x2e] = (*(uint32_t*)((char*)&local_f0 + 4));
  puVar1[0x2f] = (uint32_t)local_e8;
  puVar1[0x30] = (*(uint32_t*)((char*)&local_e8 + 4));
  puVar1[0x31] = (uint32_t)local_e0;
  puVar1[0x32] = (*(uint32_t*)((char*)&local_e0 + 4));
  puVar1[0x33] = (uint32_t)uStack_d8;
  puVar1[0x34] = (*(uint32_t*)((char*)&uStack_d8 + 4));
  puVar1[0x35] = (uint32_t)local_d0;
  puVar1[0x36] = (*(uint32_t*)((char*)&local_d0 + 4));
  puVar1[0x37] = (uint32_t)local_c8;
  uVar3 = *(uint64_t *)(param_1 + 0x68);
  local_b8 = 0;
  iStack_b4 = iVar5;
  uVar4 = RingBuffer_write(uVar3,&local_b8,8);
  if (((uVar4 & 1) != 0) && (-0xe0 < iVar15)) {
    RingBuffer_write(uVar3,__s,iVar5);
  }
  if (*(long *)(lVar2 + 0x28) != local_b0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0012f3e8  size=312 */

void vt_handle_vkGetPhysicalDeviceFormatProperties(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  unsigned long uVar7;
  char *pcVar8;
  long lVar9;
  uint64_t local_50;
  uint32_t local_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar9 = 1;
    lVar4 = param_1;
  }
  else {
    lVar9 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar8 + lVar9);
  uVar5 = VkObject_fromId(lVar4);
  local_48 = 0;
  local_50 = 0;
  ((generic_fn_t)DAT_00193b28)(uVar5,uVar1,&local_50);
  checkFormatProperties(uVar5,uVar1,&local_50);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff4) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 0xc;
  }
  else {
    puVar6 = malloc(0xc);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *(uint32_t *)(puVar6 + 1) = 0;
  *puVar6 = 0;
  *(uint32_t *)puVar6 = (uint32_t)local_50;
  *(uint32_t *)((long)puVar6 + 4) = (*(uint32_t*)((char*)&local_50 + 4));
  local_40 = 0xc00000000;
  *(uint32_t *)(puVar6 + 1) = local_48;
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uVar7 = RingBuffer_write(uVar5,&local_40,8);
  if ((uVar7 & 1) != 0) {
    RingBuffer_write(uVar5,puVar6,0xc);
  }
  if (*(long *)(lVar3 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00140e38  size=884 */

void vt_handle_vkGetPhysicalDeviceFormatProperties2(long param_1)

{
  /* STUB: vt_handle_vkGetPhysicalDeviceFormatProperties2 — Ghidra artifacts */
}


/* @0012f520  size=416 */

void vt_handle_vkGetPhysicalDeviceImageFormatProperties(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  uint64_t uVar10;
  uint64_t *puVar11;
  char *pcVar12;
  unsigned long uVar13;
  uint32_t local_84;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t local_68;
  uint32_t local_60;
  uint32_t uStack_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar8 + 0x28);
  pcVar12 = *(char **)(param_1 + 0x30);
  if (*pcVar12 == '\0') {
    uVar13 = 1;
    lVar9 = param_1;
  }
  else {
    uVar13 = 9;
    lVar9 = *(long *)(pcVar12 + 1);
  }
  pcVar1 = pcVar12 + uVar13;
  uVar4 = *(uint32_t *)pcVar1;
  uVar6 = *(uint32_t *)(pcVar12 + (uVar13 | 4));
  uVar2 = *(uint32_t *)(pcVar1 + 8);
  uVar3 = *(uint32_t *)(pcVar1 + 0xc);
  uVar5 = *(uint32_t *)(pcVar1 + 0x10);
  uVar10 = VkObject_fromId(lVar9);
  uStack_78 = 0;
  local_80 = 0;
  local_68 = 0;
  local_70 = 0;
  local_84 = ((generic_fn_t)DAT_00193b30)(uVar10,uVar4,uVar6,uVar2,uVar3,uVar5,&local_80);
  checkImageFormatProperties(uVar4,uVar6,uVar2,uVar3,uVar5,&local_80,&local_84);
  iVar7 = *(int *)(param_1 + 0x48);
  if ((iVar7 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar11 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar7);
    *(int *)(param_1 + 0x48) = iVar7 + 0x20;
  }
  else {
    puVar11 = malloc(0x20);
    ArrayList_add(param_1 + 0x50,puVar11);
  }
  puVar11[1] = 0;
  *puVar11 = 0;
  puVar11[3] = 0;
  puVar11[2] = 0;
  *(uint32_t *)puVar11 = (uint32_t)local_80;
  *(uint32_t *)((long)puVar11 + 4) = (*(uint32_t*)((char*)&local_80 + 4));
  *(uint32_t *)(puVar11 + 1) = (uint32_t)uStack_78;
  *(uint32_t *)((long)puVar11 + 0xc) = (*(uint32_t*)((char*)&uStack_78 + 4));
  *(uint32_t *)(puVar11 + 2) = (uint32_t)local_70;
  *(uint32_t *)((long)puVar11 + 0x14) = (*(uint32_t*)((char*)&local_70 + 4));
  puVar11[3] = local_68;
  uVar10 = *(uint64_t *)(param_1 + 0x68);
  local_60 = local_84;
  uStack_5c = 0x20;
  uVar13 = RingBuffer_write(uVar10,&local_60,8);
  if ((uVar13 & 1) != 0) {
    RingBuffer_write(uVar10,puVar11,0x20);
  }
  if (*(long *)(lVar8 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001411ac  size=1980 */

void vt_handle_vkGetPhysicalDeviceImageFormatProperties2(long param_1)

{
  unsigned long *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  long lVar4;
  uint64_t *puVar5;
  void *__s;
  uint64_t uVar6;
  uint32_t *__s_00;
  int iVar7;
  unsigned long uVar8;
  long lVar9;
  uint32_t uVar10;
  int iVar11;
  uint32_t *puVar12;
  uint32_t uVar13;
  char *pcVar14;
  int *piVar15;
  int *piVar16;
  uint64_t *puVar17;
  char *pcVar18;
  int iVar19;
  int iVar20;
  size_t __size;
  int *piVar21;
  unsigned long uVar22;
  uint64_t local_e8;
  uint32_t local_d4;
  uint64_t local_d0;
  int *piStack_c8;
  uint64_t local_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t local_a8;
  unsigned long local_a0;
  uint64_t *puStack_98;
  uint64_t local_90;
  uint64_t local_88;
  unsigned long local_80;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  pcVar14 = *(char **)(param_1 + 0x30);
  local_80 = 0;
  puStack_98 = (uint64_t *)0x0;
  local_a0 = 0;
  local_88 = 0;
  local_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  local_a8 = 0;
  local_b0 = 0;
  piStack_c8 = (int *)0x0;
  local_d0 = 0;
  if (*pcVar14 == '\0') {
    uVar8 = 1;
  }
  else {
    local_e8 = *(uint64_t *)(pcVar14 + 1);
    uVar8 = 9;
  }
  iVar7 = *(int *)(pcVar14 + uVar8);
  uVar8 = uVar8 | 4;
  if (0 < iVar7) {
    puVar12 = (uint32_t *)((long)(pcVar14 + uVar8) + 4);
    puVar17 = (uint64_t *)0x0;
    iVar11 = 8;
    local_a0 = (unsigned long)*(uint32_t *)(pcVar14 + uVar8);
    do {
      uVar13 = *puVar12;
      if ((int)uVar13 < 0x3b9d0838) {
        if (uVar13 == 0x3b9bdf58) {
          iVar19 = *(int *)(pcVar14 + (long)iVar11 + uVar8);
          uVar22 = (long)iVar11 + 4;
          if (0 < iVar19) {
            iVar11 = *(int *)(param_1 + 0x48);
            if ((iVar11 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
              puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar11);
              *(int *)(param_1 + 0x48) = iVar11 + 0x18;
            }
            else {
              puVar5 = malloc(0x18);
              ArrayList_add(param_1 + 0x50,puVar5);
            }
            *puVar5 = 0;
            puVar5[1] = 0;
            puVar5[2] = 0;
            pcVar18 = pcVar14 + uVar22 + uVar8;
            uVar10 = *(uint32_t *)pcVar18;
            puVar5[1] = 0;
LAB_00141294:
            *(uint32_t *)puVar5 = uVar10;
            uVar10 = *(uint32_t *)(pcVar18 + 4);
            uVar22 = (unsigned long)(uint32_t)(iVar19 + (int)uVar22);
            puVar5[1] = puVar17;
            *(uint32_t *)(puVar5 + 2) = uVar10;
            puVar17 = puVar5;
          }
        }
        else {
          if (uVar13 == 0xffffffff) goto LAB_001414c0;
LAB_00141394:
          uVar22 = (unsigned long)(iVar11 + 4);
        }
      }
      else if (uVar13 == 0x3b9d0838) {
        iVar19 = *(int *)(pcVar14 + (long)iVar11 + uVar8);
        uVar22 = (long)iVar11 + 4;
        if (0 < iVar19) {
          iVar11 = *(int *)(param_1 + 0x48);
          if ((iVar11 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar11);
            *(int *)(param_1 + 0x48) = iVar11 + 0x20;
          }
          else {
            puVar5 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,puVar5);
          }
          puVar5[1] = 0;
          *puVar5 = 0;
          puVar5[3] = 0;
          puVar5[2] = 0;
          pcVar18 = pcVar14 + uVar22 + uVar8;
          uVar10 = *(uint32_t *)pcVar18;
          puVar5[1] = 0;
          *(uint32_t *)puVar5 = uVar10;
          *(uint32_t *)(puVar5 + 2) = *(uint32_t *)(pcVar18 + 4);
          if (*(int *)(pcVar18 + 8) < 1) {
            puVar5[3] = 0;
          }
          else {
            __size = (long)*(int *)(pcVar18 + 8) << 2;
            iVar20 = (int)__size;
            iVar11 = *(int *)(param_1 + 0x48) + iVar20;
            if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              __size = (size_t)iVar20;
              *(int *)(param_1 + 0x48) = iVar11;
            }
            else {
              __s = malloc(__size);
              ArrayList_add(param_1 + 0x50,__s);
            }
            memset(__s,0,__size);
            if (__s != (void *)0x0) {
              memcpy(__s,pcVar18 + 0xc,(long)iVar20);
            }
            puVar5[3] = __s;
          }
          uVar22 = (unsigned long)(uint32_t)(iVar19 + (int)uVar22);
          puVar5[1] = puVar17;
          puVar17 = puVar5;
        }
      }
      else {
        if (uVar13 != 0x3b9e8af0) goto LAB_00141394;
        iVar19 = *(int *)(pcVar14 + (long)iVar11 + uVar8);
        uVar22 = (long)iVar11 + 4;
        if (0 < iVar19) {
          iVar11 = *(int *)(param_1 + 0x48);
          if ((iVar11 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar11);
            *(int *)(param_1 + 0x48) = iVar11 + 0x18;
          }
          else {
            puVar5 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,puVar5);
          }
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          pcVar18 = pcVar14 + uVar22 + uVar8;
          uVar10 = *(uint32_t *)pcVar18;
          goto LAB_00141294;
        }
      }
      puVar12 = (uint32_t *)(pcVar14 + (long)(int)uVar22 + uVar8);
      iVar11 = (int)uVar22 + 4;
    } while( true );
  }
LAB_00141520:
  lVar9 = (long)(int)uVar8;
  if (0 < *(int *)(pcVar14 + lVar9)) {
    pcVar18 = pcVar14 + lVar9 + 4;
    piVar21 = (int *)0x0;
    iVar7 = 8;
    local_d0 = ((uint64_t)((*(uint32_t*)((char*)&local_d0 + 4))) << 32 | (uint32_t)(*(uint32_t *)pcVar18));
    piVar15 = (int *)(pcVar14 + lVar9 + 8);
    do {
      iVar11 = *piVar15;
      if (iVar11 == 0x3b9bdf59) {
        iVar11 = *(int *)(pcVar18 + iVar7);
        uVar8 = (long)iVar7 + 4;
        if (iVar11 < 1) {
          uVar8 = uVar8 & 0xffffffff;
        }
        else {
          iVar7 = *(int *)(param_1 + 0x48);
          if ((iVar7 < 0xffe0) && (*(long *)(param_1 + 0x40) != 0)) {
            piVar15 = (int *)(*(long *)(param_1 + 0x40) + (long)iVar7);
            *(int *)(param_1 + 0x48) = iVar7 + 0x20;
          }
          else {
            piVar15 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,piVar15);
          }
          piVar15[2] = 0;
          piVar15[3] = 0;
          piVar15[0] = 0;
          piVar15[1] = 0;
          piVar15[6] = 0;
          piVar15[7] = 0;
          piVar15[4] = 0;
          piVar15[5] = 0;
          piVar16 = (int *)(pcVar18 + uVar8);
          uVar13 = iVar11 + (int)uVar8;
          *piVar15 = *piVar16;
          piVar15[4] = piVar16[1];
          piVar15[5] = piVar16[2];
          piVar15[6] = piVar16[3];
LAB_0014159c:
          uVar8 = (unsigned long)uVar13;
          *(int **)(piVar15 + 2) = piVar21;
          piVar21 = piVar15;
        }
      }
      else if (iVar11 == 0x3b9d2b65) {
        iVar11 = *(int *)(pcVar18 + iVar7);
        uVar8 = (long)iVar7 + 4;
        if (0 < iVar11) {
          iVar7 = *(int *)(param_1 + 0x48);
          if ((iVar7 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
            piVar15 = (int *)(*(long *)(param_1 + 0x40) + (long)iVar7);
            *(int *)(param_1 + 0x48) = iVar7 + 0x18;
          }
          else {
            piVar15 = malloc(0x18);
            ArrayList_add(param_1 + 0x50,piVar15);
          }
          piVar15[0] = 0;
          piVar15[1] = 0;
          piVar15[2] = 0;
          piVar15[3] = 0;
          piVar15[4] = 0;
          piVar15[5] = 0;
          uVar13 = iVar11 + (int)uVar8;
          *piVar15 = *(int *)(pcVar18 + uVar8);
          piVar15[4] = *(int *)((long)(pcVar18 + uVar8) + 4);
          goto LAB_0014159c;
        }
      }
      else {
        if (iVar11 == -1) goto LAB_00141694;
        uVar8 = (unsigned long)(iVar7 + 4);
      }
      piVar15 = (int *)(pcVar18 + (int)uVar8);
      iVar7 = (int)uVar8 + 4;
    } while( true );
  }
LAB_001416f8:
  uVar6 = VkObject_fromId(local_e8);
  local_d4 = ((generic_fn_t)DAT_00193f90)(uVar6,&local_a0,&local_d0);
  checkImageFormatProperties
            (local_90 & 0xffffffff,(*(uint32_t*)((char*)&local_90 + 4)),local_88 & 0xffffffff,(*(uint32_t*)((char*)&local_88 + 4)),
             local_80 & 0xffffffff,&local_c0,&local_d4);
  if (piStack_c8 == (int *)0x0) {
    iVar7 = 4;
  }
  else {
    iVar7 = 4;
    piVar15 = piStack_c8;
    do {
      iVar19 = *piVar15;
      piVar15 = *(int **)(piVar15 + 2);
      iVar11 = 0x10;
      if (iVar19 != 0x3b9d2b65) {
        iVar11 = 8;
      }
      iVar20 = 0x18;
      if (iVar19 != 0x3b9bdf59) {
        iVar20 = iVar11;
      }
      iVar7 = iVar20 + iVar7;
    } while (piVar15 != (int *)0x0);
  }
  iVar11 = iVar7 + 0x24;
  iVar19 = *(int *)(param_1 + 0x48) + iVar11;
  if ((iVar19 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s_00 = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar19;
  }
  else {
    __s_00 = malloc((long)iVar11);
    ArrayList_add(param_1 + 0x50,__s_00);
  }
  memset(__s_00,0,(long)iVar11);
  *__s_00 = (uint32_t)local_d0;
  if (piStack_c8 == (int *)0x0) {
    uVar13 = 4;
  }
  else {
    uVar13 = 4;
    piVar15 = piStack_c8;
    do {
      iVar19 = *piVar15;
      *(int *)((long)__s_00 + (unsigned long)uVar13) = iVar19;
      piVar21 = *(int **)(piVar15 + 2);
      uVar8 = (unsigned long)uVar13 + 4;
      if (iVar19 == 0x3b9d2b65) {
        *(uint64_t *)((long)__s_00 + uVar8) = 0x3b9d2b6500000008;
        iVar19 = piVar15[4];
        piVar16 = (int *)((long)__s_00 + (unsigned long)(uVar13 + 8) + 4);
        iVar20 = 0x10;
      }
      else if (iVar19 == 0x3b9bdf59) {
        *(uint64_t *)((long)__s_00 + uVar8) = 0x3b9bdf5900000010;
        uVar3 = uVar13 + 8;
        iVar20 = 0x18;
        *(int *)((long)__s_00 + (unsigned long)uVar3 + 4) = piVar15[4];
        *(int *)((long)__s_00 + (unsigned long)uVar3 + 8) = piVar15[5];
        iVar19 = piVar15[6];
        piVar16 = (int *)((long)__s_00 + (unsigned long)uVar3 + 0xc);
      }
      else {
        iVar19 = 0;
        piVar16 = (int *)((long)__s_00 + (uVar8 & 0xffffffff));
        iVar20 = 8;
      }
      *piVar16 = iVar19;
      uVar13 = iVar20 + uVar13;
      *(int **)(piVar15 + 2) = piVar21;
      piVar15 = piVar21;
    } while (piVar21 != (int *)0x0);
  }
  puVar2 = (uint32_t *)((long)__s_00 + (long)(int)uVar13);
  *puVar2 = 0xffffffff;
  puVar2[1] = (uint32_t)local_c0;
  puVar2[2] = (*(uint32_t*)((char*)&local_c0 + 4));
  puVar2[3] = (uint32_t)uStack_b8;
  puVar2[4] = (*(uint32_t*)((char*)&uStack_b8 + 4));
  puVar2[5] = (uint32_t)local_b0;
  puVar2[6] = (*(uint32_t*)((char*)&local_b0 + 4));
  *(uint64_t *)(puVar2 + 7) = local_a8;
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_70 = local_d4;
  iStack_6c = iVar11;
  uVar8 = RingBuffer_write(uVar6,&local_70,8);
  if (((uVar8 & 1) != 0) && (-0x24 < iVar7)) {
    RingBuffer_write(uVar6,__s_00,iVar11);
  }
  if (*(long *)(lVar4 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_001414c0:
  if (puVar17 == (uint64_t *)0x0) {
    puStack_98 = (uint64_t *)0x0;
  }
  else {
    puVar5 = (uint64_t *)0x0;
    do {
      puStack_98 = puVar17;
      puVar17 = (uint64_t *)puStack_98[1];
      puStack_98[1] = puVar5;
      puVar5 = puStack_98;
    } while (puVar17 != (uint64_t *)0x0);
  }
  puVar1 = (unsigned long *)(pcVar14 + (long)iVar11 + uVar8);
  local_90 = *puVar1;
  local_88 = puVar1[1];
  local_80 = ((uint64_t)((*(uint32_t*)((char*)&local_80 + 4))) << 32 | (uint32_t)((int)puVar1[2]));
  uVar8 = (unsigned long)(uint32_t)((int)uVar8 + iVar7);
  goto LAB_00141520;
LAB_00141694:
  if (piVar21 == (int *)0x0) {
    piStack_c8 = (int *)0x0;
  }
  else {
    piVar15 = (int *)0x0;
    do {
      piStack_c8 = piVar21;
      piVar21 = *(int **)(piStack_c8 + 2);
      *(int **)(piStack_c8 + 2) = piVar15;
      piVar15 = piStack_c8;
    } while (piVar21 != (int *)0x0);
  }
  pcVar18 = pcVar18 + iVar7;
  local_c0 = *(uint64_t *)pcVar18;
  uStack_b8 = *(uint64_t *)(pcVar18 + 8);
  local_b0 = *(uint64_t *)(pcVar18 + 0x10);
  local_a8 = *(uint64_t *)(pcVar18 + 0x18);
  goto LAB_001416f8;
}


/* @0012ef58  size=420 */

void vt_handle_vkGetPhysicalDeviceMemoryProperties(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  uint64_t uVar4;
  uint32_t *__s;
  unsigned long uVar5;
  uint32_t local_258 [65];
  uint32_t local_154;
  uint8_t auStack_150 [256];
  uint32_t local_50;
  int iStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar3 + 0x28);
  uVar4 = VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
  memset(local_258,0,0x208);
  ((generic_fn_t)DAT_00193b18)(uVar4,local_258);
  checkDeviceMemoryProperties(param_1,local_258,0);
  iVar1 = local_154 * 0xc + local_258[0] * 8 + 8;
  iVar2 = iVar1 + *(int *)(param_1 + 0x48);
  if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar2;
  }
  else {
    __s = malloc((long)iVar1);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar1);
  *__s = local_258[0];
  if (local_258[0] < 0x21) {
    memcpy(__s + 1,(void *)((unsigned long)local_258 | 4),(unsigned long)local_258[0] << 3);
  }
  *(uint32_t *)((long)__s + (long)(int)(local_258[0] * 8) + 4) = local_154;
  if (local_154 < 0x11) {
    memcpy((void *)((long)__s + (long)(int)(local_258[0] * 8 + 8)),auStack_150,
           (unsigned long)local_154 * 0xc);
  }
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  local_50 = 0;
  iStack_4c = iVar1;
  uVar5 = RingBuffer_write(uVar4,&local_50,8);
  if (((uVar5 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar4,__s,iVar1);
  }
  if (*(long *)(lVar3 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00141d3c  size=1064 */

void vt_handle_vkGetPhysicalDeviceMemoryProperties2(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  uint64_t uVar7;
  uint32_t *__s;
  int iVar8;
  uint32_t uVar9;
  char *pcVar10;
  unsigned long uVar11;
  int *piVar12;
  int iVar13;
  uint64_t unaff_x20;
  uint32_t *puVar14;
  int *piVar15;
  uint64_t uVar16;
  uint32_t local_290 [2];
  int *local_288;
  uint32_t local_280;
  uint8_t auStack_27c [256];
  uint32_t local_17c;
  uint8_t auStack_178 [256];
  uint32_t local_78;
  int iStack_74;
  long local_70;
  
  /* stack canary setup */
  local_70 = *(long *)(lVar5 + 0x28);
  memset(local_290,0,0x218);
  pcVar10 = *(char **)(param_1 + 0x30);
  if (*pcVar10 == '\0') {
    uVar11 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar10 + 1);
    uVar11 = 9;
  }
  if (0 < *(int *)(pcVar10 + uVar11)) {
    pcVar10 = pcVar10 + (uVar11 | 4);
    piVar12 = (int *)(pcVar10 + 4);
    local_290[0] = *(uint32_t *)pcVar10;
    iVar8 = 8;
    piVar15 = (int *)0x0;
    do {
      piVar6 = piVar15;
      if (*piVar12 == 0x3b9e67c8) {
        iVar13 = *(int *)(pcVar10 + iVar8);
        uVar11 = (long)iVar8 + 4;
        if (0 < iVar13) {
          iVar8 = *(int *)(param_1 + 0x48);
          if ((iVar8 < 0xfef0) && (*(long *)(param_1 + 0x40) != 0)) {
            piVar6 = (int *)(*(long *)(param_1 + 0x40) + (long)iVar8);
            *(int *)(param_1 + 0x48) = iVar8 + 0x110;
          }
          else {
            piVar6 = malloc(0x110);
            ArrayList_add(param_1 + 0x50,piVar6);
          }
          piVar6[0x3e] = 0;
          piVar6[0x3f] = 0;
          piVar6[0x3c] = 0;
          piVar6[0x3d] = 0;
          piVar6[0x42] = 0;
          piVar6[0x43] = 0;
          piVar6[0x40] = 0;
          piVar6[0x41] = 0;
          piVar6[0x36] = 0;
          piVar6[0x37] = 0;
          piVar6[0x34] = 0;
          piVar6[0x35] = 0;
          piVar6[0x3a] = 0;
          piVar6[0x3b] = 0;
          piVar6[0x38] = 0;
          piVar6[0x39] = 0;
          piVar6[0x2e] = 0;
          piVar6[0x2f] = 0;
          piVar6[0x2c] = 0;
          piVar6[0x2d] = 0;
          piVar6[0x32] = 0;
          piVar6[0x33] = 0;
          piVar6[0x30] = 0;
          piVar6[0x31] = 0;
          piVar6[0x26] = 0;
          piVar6[0x27] = 0;
          piVar6[0x24] = 0;
          piVar6[0x25] = 0;
          piVar6[0x2a] = 0;
          piVar6[0x2b] = 0;
          piVar6[0x28] = 0;
          piVar6[0x29] = 0;
          piVar6[0x1e] = 0;
          piVar6[0x1f] = 0;
          piVar6[0x1c] = 0;
          piVar6[0x1d] = 0;
          piVar6[0x22] = 0;
          piVar6[0x23] = 0;
          piVar6[0x20] = 0;
          piVar6[0x21] = 0;
          piVar6[0x16] = 0;
          piVar6[0x17] = 0;
          piVar6[0x14] = 0;
          piVar6[0x15] = 0;
          piVar6[0x1a] = 0;
          piVar6[0x1b] = 0;
          piVar6[0x18] = 0;
          piVar6[0x19] = 0;
          piVar6[0xe] = 0;
          piVar6[0xf] = 0;
          piVar6[0xc] = 0;
          piVar6[0xd] = 0;
          piVar6[0x12] = 0;
          piVar6[0x13] = 0;
          piVar6[0x10] = 0;
          piVar6[0x11] = 0;
          piVar6[6] = 0;
          piVar6[7] = 0;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[10] = 0;
          piVar6[0xb] = 0;
          piVar6[8] = 0;
          piVar6[9] = 0;
          piVar6[2] = 0;
          piVar6[3] = 0;
          piVar6[0] = 0;
          piVar6[1] = 0;
          piVar12 = (int *)(pcVar10 + uVar11);
          iVar8 = *piVar12;
          piVar6[2] = 0;
          piVar6[3] = 0;
          uVar11 = (unsigned long)(uint32_t)(iVar13 + (int)uVar11);
          *piVar6 = iVar8;
          uVar7 = *(uint64_t *)(piVar12 + 1);
          *(uint64_t *)(piVar6 + 6) = *(uint64_t *)(piVar12 + 3);
          *(uint64_t *)(piVar6 + 4) = uVar7;
          uVar16 = *(uint64_t *)(piVar12 + 7);
          uVar7 = *(uint64_t *)(piVar12 + 5);
          *(int **)(piVar6 + 2) = piVar15;
          *(uint64_t *)(piVar6 + 0x26) = uVar16;
          *(uint64_t *)(piVar6 + 0x24) = uVar7;
        }
      }
      else {
        if (*piVar12 == -1) goto LAB_00141e9c;
        uVar11 = (unsigned long)(iVar8 + 4);
      }
      piVar12 = (int *)(pcVar10 + (int)uVar11);
      iVar8 = (int)uVar11 + 4;
      piVar15 = piVar6;
    } while( true );
  }
LAB_00141f2c:
  uVar7 = VkObject_fromId(unaff_x20);
  ((generic_fn_t)DAT_00193fa0)(uVar7,local_290);
  checkDeviceMemoryProperties(param_1,&local_280,local_288);
  if (local_288 == (int *)0x0) {
    iVar8 = 0x10;
  }
  else {
    iVar8 = 4;
    piVar12 = local_288;
    do {
      iVar4 = *piVar12;
      piVar12 = *(int **)(piVar12 + 2);
      iVar13 = 0x2c;
      if (iVar4 != 0x3b9e67c8) {
        iVar13 = 8;
      }
      iVar8 = iVar13 + iVar8;
    } while (piVar12 != (int *)0x0);
    iVar8 = iVar8 + 0xc;
  }
  iVar13 = *(int *)(param_1 + 0x48);
  iVar4 = iVar8 + local_280 * 8 + local_17c * 0xc;
  iVar8 = iVar4 + iVar13;
  if ((iVar8 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    *(int *)(param_1 + 0x48) = iVar8;
    __s = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)iVar13);
  }
  else {
    __s = malloc((long)iVar4);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar4);
  *__s = local_290[0];
  if (local_288 == (int *)0x0) {
    uVar9 = 4;
  }
  else {
    uVar9 = 4;
    piVar12 = local_288;
    do {
      iVar8 = *piVar12;
      *(int *)((long)__s + (unsigned long)uVar9) = iVar8;
      piVar15 = *(int **)(piVar12 + 2);
      lVar3 = (unsigned long)uVar9 + 4;
      piVar12[2] = 0;
      piVar12[3] = 0;
      if (iVar8 == 0x3b9e67c8) {
        *(uint64_t *)((long)__s + lVar3) = 0x3b9e67c800000024;
        uVar7 = *(uint64_t *)(piVar12 + 4);
        uVar2 = uVar9 + 8;
        *(uint64_t *)((long)__s + (unsigned long)uVar2 + 0xc) = *(uint64_t *)(piVar12 + 6);
        *(uint64_t *)((long)__s + (unsigned long)uVar2 + 4) = uVar7;
        uVar7 = *(uint64_t *)(piVar12 + 0x24);
        *(uint64_t *)((long)__s + (unsigned long)uVar2 + 0x1c) = *(uint64_t *)(piVar12 + 0x26);
        *(uint64_t *)((long)__s + (unsigned long)uVar2 + 0x14) = uVar7;
        iVar8 = 0x2c;
      }
      else {
        *(uint32_t *)((long)__s + lVar3) = 0;
        iVar8 = 8;
      }
      uVar9 = iVar8 + uVar9;
      *(int **)(piVar12 + 2) = piVar15;
      piVar12 = piVar15;
    } while (piVar15 != (int *)0x0);
  }
  puVar1 = (uint32_t *)((long)__s + (long)(int)uVar9);
  *puVar1 = 0xffffffff;
  puVar14 = puVar1 + 1;
  *puVar14 = local_280;
  if (local_280 < 0x21) {
    memcpy(puVar1 + 2,auStack_27c,(unsigned long)local_280 << 3);
  }
  *(uint32_t *)((long)puVar14 + (long)(int)(local_280 * 8) + 4) = local_17c;
  if (local_17c < 0x11) {
    memcpy((void *)((long)puVar14 + (long)(int)(local_280 * 8 + 8)),auStack_178,
           (unsigned long)local_17c * 0xc);
  }
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  local_78 = 0;
  iStack_74 = iVar4;
  uVar11 = RingBuffer_write(uVar7,&local_78,8);
  if (((uVar11 & 1) != 0) && (0 < iVar4)) {
    RingBuffer_write(uVar7,__s,iVar4);
  }
  if (*(long *)(lVar5 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00141e9c:
  if (piVar15 == (int *)0x0) {
    local_288 = (int *)0x0;
  }
  else {
    piVar12 = (int *)0x0;
    do {
      local_288 = piVar15;
      piVar15 = *(int **)(local_288 + 2);
      *(int **)(local_288 + 2) = piVar12;
      piVar12 = local_288;
    } while (piVar15 != (int *)0x0);
  }
  puVar14 = (uint32_t *)(pcVar10 + iVar8);
  local_280 = *puVar14;
  if (local_280 < 0x21) {
    __memcpy_chk(auStack_27c,puVar14 + 1,(unsigned long)local_280 << 3,0x204);
  }
  local_17c = *(uint32_t *)((long)puVar14 + (long)(int)(local_280 * 8) + 4);
  if (local_17c < 0x11) {
    __memcpy_chk(auStack_178,(long)puVar14 + (long)(int)(local_280 * 8 + 8),(unsigned long)local_17c * 0xc,
                 0x100);
  }
  goto LAB_00141f2c;
}


/* @001443ec  size=292 */

void vt_handle_vkGetPhysicalDeviceMultisamplePropertiesEXT(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  unsigned long uVar7;
  char *pcVar8;
  long lVar9;
  uint64_t local_58;
  uint64_t uStack_50;
  uint64_t local_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar9 = 1;
    lVar4 = param_1;
  }
  else {
    lVar9 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar8 + lVar9);
  uVar5 = VkObject_fromId(lVar4);
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  ((generic_fn_t)DAT_00194050)(uVar5,uVar1,&local_58);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff4) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 0xc;
  }
  else {
    puVar6 = malloc(0xc);
    ArrayList_add(param_1 + 0x50,puVar6);
  }
  *(uint32_t *)(puVar6 + 1) = 0;
  *puVar6 = 0;
  *(uint32_t *)puVar6 = (uint32_t)local_58;
  *(uint32_t *)((long)puVar6 + 4) = (uint32_t)local_48;
  local_40 = 0xc00000000;
  *(uint32_t *)(puVar6 + 1) = (*(uint32_t*)((char*)&local_48 + 4));
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  uVar7 = RingBuffer_write(uVar5,&local_40,8);
  if ((uVar7 & 1) != 0) {
    RingBuffer_write(uVar5,puVar6,0xc);
  }
  if (*(long *)(lVar3 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0014405c  size=512 */

void vt_handle_vkGetPhysicalDevicePresentRectanglesKHR(long param_1)

{
  int iVar1;
  long lVar2;
  uint32_t *__ptr;
  uint64_t *puVar3;
  char *pcVar4;
  uint32_t uVar5;
  unsigned long uVar6;
  uint64_t uVar7;
  uint32_t unaff_w21;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar4 = *(char **)(param_1 + 0x30);
  uVar5 = 9;
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  uVar6 = (unsigned long)uVar5 + 1;
  if (pcVar4[uVar5] != '\0') {
    unaff_w21 = *(uint32_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)(uVar5 + 9);
  }
  if (((*(int *)(pcVar4 + uVar6) < 1) || (*(int *)(pcVar4 + uVar6 + 4) != 0)) &&
     (__ptr = calloc(1,0x120), __ptr != (uint32_t *)0x0)) {
    getWindowExtent(param_1 + 0xd0,unaff_w21,__ptr + 2);
    iVar1 = *(int *)(param_1 + 0x48);
    if ((iVar1 < 0xffde) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar3 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
      *(int *)(param_1 + 0x48) = iVar1 + 0x22;
    }
    else {
      puVar3 = malloc(0x22);
      ArrayList_add(param_1 + 0x50,puVar3);
    }
    puVar3[1] = 0;
    *puVar3 = 0;
    puVar3[3] = 0;
    puVar3[2] = 0;
    *(uint16_t *)(puVar3 + 4) = 0;
    *(uint16_t *)puVar3 = 0;
    *(uint64_t *)((long)puVar3 + 10) = 0x1000000001;
    *(uint64_t *)((long)puVar3 + 2) = 0x100000004;
    *(uint32_t *)((long)puVar3 + 0x12) = *__ptr;
    *(uint32_t *)((long)puVar3 + 0x16) = __ptr[1];
    *(uint32_t *)((long)puVar3 + 0x1a) = __ptr[2];
    *(uint32_t *)((long)puVar3 + 0x1e) = __ptr[3];
    uVar7 = *(uint64_t *)(param_1 + 0x68);
    local_40 = 0x2200000000;
    uVar6 = RingBuffer_write(uVar7,&local_40,8);
    if ((uVar6 & 1) != 0) {
      RingBuffer_write(uVar7,puVar3,0x22);
    }
    free(__ptr);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x48);
    if ((iVar1 < 0xfff2) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar3 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar1);
      *(int *)(param_1 + 0x48) = iVar1 + 0xe;
    }
    else {
      puVar3 = malloc(0xe);
      ArrayList_add(param_1 + 0x50,puVar3);
    }
    *puVar3 = 0;
    *(uint64_t *)((long)puVar3 + 6) = 0;
    *(uint16_t *)puVar3 = 0;
    *(uint32_t *)((long)puVar3 + 10) = 0;
    *(uint64_t *)((long)puVar3 + 2) = 0x100000004;
    uVar7 = *(uint64_t *)(param_1 + 0x68);
    local_40 = 0xe00000000;
    uVar6 = RingBuffer_write(uVar7,&local_40,8);
    if ((uVar6 & 1) != 0) {
      RingBuffer_write(uVar7,puVar3,0xe);
    }
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012e7b8  size=328 */

void vt_handle_vkGetPhysicalDeviceProperties(long param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  uint64_t uVar4;
  void *__s;
  unsigned long uVar5;
  uint8_t auStack_388 [20];
  uint8_t auStack_374 [804];
  uint32_t local_50;
  int iStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  uVar4 = VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
  memset(auStack_388,0,0x338);
  ((generic_fn_t)DAT_00193b08)(uVar4,auStack_388);
  checkDeviceProperties(param_1,auStack_388,0);
  iVar3 = __strlen_chk(auStack_374,0x324);
  iVar3 = iVar3 + 0x225;
  iVar1 = iVar3 + *(int *)(param_1 + 0x48);
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s = malloc((long)iVar3);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar3);
  FUN_0012e900(auStack_388,__s);
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  local_50 = 0;
  iStack_4c = iVar3;
  uVar5 = RingBuffer_write(uVar4,&local_50,8);
  if (((uVar5 & 1) != 0) && (0 < iVar3)) {
    RingBuffer_write(uVar4,__s,iVar3);
  }
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013de58  size=12256 */

void vt_handle_vkGetPhysicalDeviceProperties2(long param_1)

{
  uint8_t *puVar1;
  char *pcVar2;
  long lVar3;
  uint32_t uVar4;
  long lVar5;
  int iVar6;
  uint64_t uVar7;
  size_t sVar8;
  size_t sVar9;
  uint32_t *__s;
  int iVar10;
  uint32_t uVar11;
  unsigned long uVar12;
  int *piVar13;
  uint32_t uVar14;
  int iVar15;
  char *pcVar16;
  int *piVar17;
  int iVar18;
  long lVar19;
  uint64_t unaff_x21;
  int iVar20;
  long *plVar21;
  int *piVar22;
  int *piVar23;
  long *local_3d0;
  uint32_t local_3c0 [2];
  int *local_3b8;
  uint32_t local_3b0;
  uint32_t local_3ac;
  uint32_t local_3a8;
  uint32_t local_3a4;
  uint32_t local_3a0;
  uint8_t auStack_39c [256];
  uint64_t local_29c;
  uint64_t uStack_294;
  uint32_t local_288;
  uint32_t local_284;
  uint32_t local_280;
  uint32_t local_27c;
  uint32_t local_278;
  uint32_t local_274;
  uint32_t local_270;
  uint32_t local_26c;
  uint32_t local_268;
  uint32_t local_264;
  uint32_t local_260;
  uint64_t local_258;
  uint64_t local_250;
  uint32_t local_248;
  uint32_t local_244;
  uint32_t local_240;
  uint32_t local_23c;
  uint32_t local_238;
  uint32_t local_234;
  uint32_t local_230;
  uint32_t local_22c;
  uint32_t local_228;
  uint32_t local_224;
  uint32_t local_220;
  uint32_t local_21c;
  uint32_t local_218;
  uint32_t local_214;
  uint32_t local_210;
  uint32_t local_20c;
  uint32_t local_208;
  uint32_t local_204;
  uint32_t local_200;
  uint32_t local_1fc;
  uint32_t local_1f8;
  uint32_t local_1f4;
  uint32_t local_1f0;
  uint32_t local_1ec;
  uint32_t local_1e8;
  uint32_t local_1e4;
  uint32_t local_1e0;
  uint32_t local_1dc;
  uint32_t local_1d8;
  uint32_t local_1d4;
  uint32_t local_1d0;
  uint32_t local_1cc;
  uint32_t local_1c8;
  uint32_t local_1c4;
  uint32_t local_1c0;
  uint32_t local_1bc;
  uint32_t local_1b8;
  uint32_t local_1b4;
  uint32_t local_1b0;
  uint64_t local_1ac;
  uint32_t local_1a4;
  uint32_t local_1a0;
  uint64_t local_19c;
  uint32_t local_194;
  uint32_t local_190;
  uint32_t local_18c;
  uint32_t local_188;
  uint32_t local_184;
  uint32_t local_180;
  uint32_t local_17c;
  uint32_t local_178;
  uint32_t local_174;
  uint64_t local_170;
  uint64_t local_168;
  uint32_t local_160;
  uint64_t local_158;
  uint64_t local_150;
  uint64_t local_148;
  uint64_t local_140;
  uint32_t local_138;
  uint32_t local_134;
  uint32_t local_130;
  uint32_t local_12c;
  uint32_t local_128;
  uint32_t local_124;
  uint32_t local_120;
  uint32_t local_11c;
  uint32_t local_118;
  uint32_t local_114;
  uint32_t local_110;
  uint32_t local_10c;
  uint32_t local_108;
  uint32_t local_104;
  uint32_t local_100;
  uint32_t local_fc;
  uint32_t local_f8;
  uint32_t local_f4;
  uint32_t local_f0;
  uint32_t local_ec;
  uint32_t local_e8;
  uint32_t local_e4;
  uint32_t local_e0;
  uint32_t local_dc;
  uint32_t local_d8;
  uint32_t local_d4;
  uint32_t local_d0;
  uint64_t local_cc;
  uint64_t local_c4;
  uint32_t local_bc;
  uint32_t local_b8;
  uint32_t local_b4;
  uint32_t local_b0;
  uint64_t local_a8;
  uint64_t local_a0;
  uint64_t local_98;
  uint32_t local_90;
  uint32_t local_8c;
  uint32_t local_88;
  uint32_t local_84;
  uint32_t local_80;
  uint32_t local_78;
  int iStack_74;
  long local_70;
  
  /* stack canary setup */
  local_70 = *(long *)(lVar5 + 0x28);
  memset(local_3c0,0,0x348);
  pcVar16 = *(char **)(param_1 + 0x30);
  if (*pcVar16 == '\0') {
    uVar12 = 1;
  }
  else {
    unaff_x21 = *(uint64_t *)(pcVar16 + 1);
    uVar12 = 9;
  }
  if (0 < *(int *)(pcVar16 + uVar12)) {
    pcVar16 = pcVar16 + (uVar12 | 4);
    piVar17 = (int *)(pcVar16 + 4);
    local_3c0[0] = *(uint32_t *)pcVar16;
    piVar22 = (int *)0x0;
    piVar23 = (int *)(param_1 + 0x48);
    iVar10 = 8;
LAB_0013df64:
    plVar21 = (long *)(param_1 + 0x40);
    iVar6 = *piVar17;
    if (iVar6 < 0x3b9db030) {
      if (iVar6 < 0x3b9c5488) {
        if (0x3b9b9909 < iVar6) {
          if (iVar6 < 0x3b9c0280) {
            if (iVar6 == 0x3b9b990a) {
LAB_0013e430:
              iVar6 = *(int *)(pcVar16 + iVar10);
              uVar12 = (long)iVar10 + 4;
              if (0 < iVar6) {
                iVar10 = *piVar23;
                if ((iVar10 < 0xffe8) && (*plVar21 != 0)) {
                  piVar17 = (int *)(*plVar21 + (long)iVar10);
                  *piVar23 = iVar10 + 0x18;
                }
                else {
                  piVar17 = malloc(0x18);
                  ArrayList_add(param_1 + 0x50,piVar17);
                }
                piVar17[0] = 0;
                piVar17[1] = 0;
                piVar17[2] = 0;
                piVar17[3] = 0;
                piVar17[4] = 0;
                piVar17[5] = 0;
                piVar13 = (int *)(pcVar16 + uVar12);
                uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
                *piVar17 = *piVar13;
                piVar17[4] = piVar13[1];
                piVar17[5] = piVar13[2];
                goto LAB_0013df54;
              }
              goto LAB_0013df5c;
            }
            if (iVar6 == 0x3b9bdf5c) {
              iVar6 = *(int *)(pcVar16 + iVar10);
              uVar12 = (long)iVar10 + 4;
              if (0 < iVar6) {
                iVar10 = *piVar23;
                if ((iVar10 < 0xffc0) && (*plVar21 != 0)) {
                  piVar17 = (int *)(*plVar21 + (long)iVar10);
                  *piVar23 = iVar10 + 0x40;
                }
                else {
                  piVar17 = malloc(0x40);
                  ArrayList_add(param_1 + 0x50,piVar17);
                }
                piVar17[10] = 0;
                piVar17[0xb] = 0;
                piVar17[8] = 0;
                piVar17[9] = 0;
                piVar17[0xe] = 0;
                piVar17[0xf] = 0;
                piVar17[0xc] = 0;
                piVar17[0xd] = 0;
                piVar17[2] = 0;
                piVar17[3] = 0;
                piVar17[0] = 0;
                piVar17[1] = 0;
                piVar17[6] = 0;
                piVar17[7] = 0;
                piVar17[4] = 0;
                piVar17[5] = 0;
                piVar13 = (int *)(pcVar16 + uVar12);
                iVar10 = *piVar13;
                piVar17[2] = 0;
                piVar17[3] = 0;
                uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
                *piVar17 = iVar10;
                uVar7 = *(uint64_t *)(piVar13 + 1);
                *(uint64_t *)(piVar17 + 6) = *(uint64_t *)(piVar13 + 3);
                *(uint64_t *)(piVar17 + 4) = uVar7;
                uVar7 = *(uint64_t *)(piVar13 + 5);
                *(uint64_t *)(piVar17 + 10) = *(uint64_t *)(piVar13 + 7);
                *(uint64_t *)(piVar17 + 8) = uVar7;
                *(uint64_t *)(piVar17 + 0xc) = *(uint64_t *)(piVar13 + 9);
                piVar17[0xe] = piVar13[0xb];
                piVar17[0xf] = piVar13[0xc];
                goto LAB_0013df54;
              }
              goto LAB_0013df5c;
            }
          }
          else {
            if (iVar6 == 0x3b9c0280) goto LAB_0013e300;
            if (iVar6 == 0x3b9c3930) goto LAB_0013e4e8;
          }
          goto LAB_0013f414;
        }
        if (iVar6 < 0x36) {
          if (iVar6 == 0x32) {
            iVar6 = *(int *)(pcVar16 + iVar10);
            uVar12 = (long)iVar10 + 4;
            if (0 < iVar6) {
              iVar10 = *piVar23;
              if ((iVar10 < 0xff90) && (*plVar21 != 0)) {
                piVar17 = (int *)(*plVar21 + (long)iVar10);
                *piVar23 = iVar10 + 0x70;
              }
              else {
                piVar17 = malloc(0x70);
                ArrayList_add(param_1 + 0x50,piVar17);
              }
              piVar17[0x16] = 0;
              piVar17[0x17] = 0;
              piVar17[0x14] = 0;
              piVar17[0x15] = 0;
              piVar17[0x1a] = 0;
              piVar17[0x1b] = 0;
              piVar17[0x18] = 0;
              piVar17[0x19] = 0;
              piVar17[0xe] = 0;
              piVar17[0xf] = 0;
              piVar17[0xc] = 0;
              piVar17[0xd] = 0;
              piVar17[0x12] = 0;
              piVar17[0x13] = 0;
              piVar17[0x10] = 0;
              piVar17[0x11] = 0;
              piVar17[6] = 0;
              piVar17[7] = 0;
              piVar17[4] = 0;
              piVar17[5] = 0;
              piVar17[10] = 0;
              piVar17[0xb] = 0;
              piVar17[8] = 0;
              piVar17[9] = 0;
              piVar17[2] = 0;
              piVar17[3] = 0;
              piVar17[0] = 0;
              piVar17[1] = 0;
              piVar13 = (int *)(pcVar16 + uVar12);
              iVar10 = *piVar13;
              piVar17[2] = 0;
              piVar17[3] = 0;
              uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
              *piVar17 = iVar10;
              uVar7 = *(uint64_t *)(piVar13 + 1);
              *(uint64_t *)(piVar17 + 6) = *(uint64_t *)(piVar13 + 3);
              *(uint64_t *)(piVar17 + 4) = uVar7;
              uVar7 = *(uint64_t *)(piVar13 + 5);
              *(uint64_t *)(piVar17 + 10) = *(uint64_t *)(piVar13 + 7);
              *(uint64_t *)(piVar17 + 8) = uVar7;
              *(uint64_t *)(piVar17 + 0xc) = *(uint64_t *)(piVar13 + 9);
              piVar17[0xe] = piVar13[0xb];
              piVar17[0xf] = piVar13[0xc];
              piVar17[0x10] = piVar13[0xd];
              piVar17[0x11] = piVar13[0xe];
              piVar17[0x12] = piVar13[0xf];
              piVar17[0x13] = piVar13[0x10];
              *(uint64_t *)(piVar17 + 0x14) = *(uint64_t *)(piVar13 + 0x11);
              piVar17[0x16] = piVar13[0x13];
              piVar17[0x17] = piVar13[0x14];
              piVar17[0x18] = piVar13[0x15];
              *(uint64_t *)(piVar17 + 0x1a) = *(uint64_t *)(piVar13 + 0x16);
              goto LAB_0013df54;
            }
          }
          else {
            if (iVar6 != 0x34) {
              if (iVar6 != -1) goto LAB_0013f414;
              if (piVar22 == (int *)0x0) {
                local_3b8 = (int *)0x0;
              }
              else {
                piVar17 = (int *)0x0;
                do {
                  local_3b8 = piVar22;
                  piVar22 = *(int **)(local_3b8 + 2);
                  *(int **)(local_3b8 + 2) = piVar17;
                  piVar17 = local_3b8;
                } while (piVar22 != (int *)0x0);
              }
              pcVar16 = pcVar16 + iVar10;
              local_3b0 = *(uint32_t *)pcVar16;
              local_3ac = *(uint32_t *)(pcVar16 + 4);
              local_3a8 = *(uint32_t *)(pcVar16 + 8);
              local_3a4 = *(uint32_t *)(pcVar16 + 0xc);
              local_3a0 = *(uint32_t *)(pcVar16 + 0x10);
              iVar10 = *(int *)(pcVar16 + 0x14);
              if (iVar10 < 1) {
                uVar11 = 0x18;
              }
              else {
                __memcpy_chk(auStack_39c,pcVar16 + 0x18,iVar10,0x324);
                uVar11 = iVar10 + 0x18;
              }
              uStack_294 = *(uint64_t *)(pcVar16 + uVar11 + 8);
              local_29c = *(uint64_t *)(pcVar16 + uVar11);
              pcVar2 = pcVar16 + (int)(uVar11 + 0x10);
              local_288 = *(uint32_t *)pcVar2;
              pcVar16 = pcVar16 + (int)(uVar11 + 0x1fc);
              local_284 = *(uint32_t *)(pcVar2 + 4);
              local_280 = *(uint32_t *)(pcVar2 + 8);
              local_27c = *(uint32_t *)(pcVar2 + 0xc);
              local_278 = *(uint32_t *)(pcVar2 + 0x10);
              local_274 = *(uint32_t *)(pcVar2 + 0x14);
              local_270 = *(uint32_t *)(pcVar2 + 0x18);
              local_26c = *(uint32_t *)(pcVar2 + 0x1c);
              local_268 = *(uint32_t *)(pcVar2 + 0x20);
              local_264 = *(uint32_t *)(pcVar2 + 0x24);
              local_260 = *(uint32_t *)(pcVar2 + 0x28);
              local_258 = *(uint64_t *)(pcVar2 + 0x2c);
              local_250 = *(uint64_t *)(pcVar2 + 0x34);
              local_248 = *(uint32_t *)(pcVar2 + 0x3c);
              local_244 = *(uint32_t *)(pcVar2 + 0x40);
              local_240 = *(uint32_t *)(pcVar2 + 0x44);
              local_23c = *(uint32_t *)(pcVar2 + 0x48);
              local_238 = *(uint32_t *)(pcVar2 + 0x4c);
              local_234 = *(uint32_t *)(pcVar2 + 0x50);
              local_230 = *(uint32_t *)(pcVar2 + 0x54);
              local_22c = *(uint32_t *)(pcVar2 + 0x58);
              local_228 = *(uint32_t *)(pcVar2 + 0x5c);
              local_224 = *(uint32_t *)(pcVar2 + 0x60);
              local_220 = *(uint32_t *)(pcVar2 + 100);
              local_21c = *(uint32_t *)(pcVar2 + 0x68);
              local_218 = *(uint32_t *)(pcVar2 + 0x6c);
              local_214 = *(uint32_t *)(pcVar2 + 0x70);
              local_210 = *(uint32_t *)(pcVar2 + 0x74);
              local_20c = *(uint32_t *)(pcVar2 + 0x78);
              local_208 = *(uint32_t *)(pcVar2 + 0x7c);
              local_204 = *(uint32_t *)(pcVar2 + 0x80);
              local_200 = *(uint32_t *)(pcVar2 + 0x84);
              local_1fc = *(uint32_t *)(pcVar2 + 0x88);
              local_1f8 = *(uint32_t *)(pcVar2 + 0x8c);
              local_1f4 = *(uint32_t *)(pcVar2 + 0x90);
              local_1f0 = *(uint32_t *)(pcVar2 + 0x94);
              local_1ec = *(uint32_t *)(pcVar2 + 0x98);
              local_1e8 = *(uint32_t *)(pcVar2 + 0x9c);
              local_1e4 = *(uint32_t *)(pcVar2 + 0xa0);
              local_1e0 = *(uint32_t *)(pcVar2 + 0xa4);
              local_1dc = *(uint32_t *)(pcVar2 + 0xa8);
              local_1d8 = *(uint32_t *)(pcVar2 + 0xac);
              local_1d4 = *(uint32_t *)(pcVar2 + 0xb0);
              local_1d0 = *(uint32_t *)(pcVar2 + 0xb4);
              local_1cc = *(uint32_t *)(pcVar2 + 0xb8);
              local_1c8 = *(uint32_t *)(pcVar2 + 0xbc);
              local_1c4 = *(uint32_t *)(pcVar2 + 0xc0);
              local_1c0 = *(uint32_t *)(pcVar2 + 0xc4);
              local_1bc = *(uint32_t *)(pcVar2 + 200);
              local_1b8 = *(uint32_t *)(pcVar2 + 0xcc);
              local_1b4 = *(uint32_t *)(pcVar2 + 0xd0);
              local_1b0 = *(uint32_t *)(pcVar2 + 0xd4);
              local_1ac = *(uint64_t *)(pcVar2 + 0xd8);
              local_1a4 = *(uint32_t *)(pcVar2 + 0xe0);
              local_1a0 = *(uint32_t *)(pcVar2 + 0xe4);
              local_19c = *(uint64_t *)(pcVar2 + 0xe8);
              local_194 = *(uint32_t *)(pcVar2 + 0xf0);
              local_190 = *(uint32_t *)(pcVar2 + 0xf4);
              local_18c = *(uint32_t *)(pcVar2 + 0xf8);
              local_188 = *(uint32_t *)(pcVar2 + 0xfc);
              local_184 = *(uint32_t *)(pcVar2 + 0x100);
              local_180 = *(uint32_t *)(pcVar2 + 0x104);
              local_17c = *(uint32_t *)(pcVar2 + 0x108);
              local_178 = *(uint32_t *)(pcVar2 + 0x10c);
              local_174 = *(uint32_t *)(pcVar2 + 0x110);
              local_170 = *(uint64_t *)(pcVar2 + 0x114);
              local_168 = *(uint64_t *)(pcVar2 + 0x11c);
              local_160 = *(uint32_t *)(pcVar2 + 0x124);
              local_158 = *(uint64_t *)(pcVar2 + 0x128);
              local_150 = *(uint64_t *)(pcVar2 + 0x130);
              local_148 = *(uint64_t *)(pcVar2 + 0x138);
              local_140 = *(uint64_t *)(pcVar2 + 0x140);
              local_138 = *(uint32_t *)(pcVar2 + 0x148);
              local_134 = *(uint32_t *)(pcVar2 + 0x14c);
              local_130 = *(uint32_t *)(pcVar2 + 0x150);
              local_12c = *(uint32_t *)(pcVar2 + 0x154);
              local_128 = *(uint32_t *)(pcVar2 + 0x158);
              local_124 = *(uint32_t *)(pcVar2 + 0x15c);
              local_120 = *(uint32_t *)(pcVar2 + 0x160);
              local_11c = *(uint32_t *)(pcVar2 + 0x164);
              local_118 = *(uint32_t *)(pcVar2 + 0x168);
              local_114 = *(uint32_t *)(pcVar2 + 0x16c);
              local_110 = *(uint32_t *)(pcVar2 + 0x170);
              local_10c = *(uint32_t *)(pcVar2 + 0x174);
              local_108 = *(uint32_t *)(pcVar2 + 0x178);
              local_104 = *(uint32_t *)(pcVar2 + 0x17c);
              local_100 = *(uint32_t *)(pcVar2 + 0x180);
              local_fc = *(uint32_t *)(pcVar2 + 0x184);
              local_f8 = *(uint32_t *)(pcVar2 + 0x188);
              local_f4 = *(uint32_t *)(pcVar2 + 0x18c);
              local_f0 = *(uint32_t *)(pcVar2 + 400);
              local_ec = *(uint32_t *)(pcVar2 + 0x194);
              local_e8 = *(uint32_t *)(pcVar2 + 0x198);
              local_e4 = *(uint32_t *)(pcVar2 + 0x19c);
              local_e0 = *(uint32_t *)(pcVar2 + 0x1a0);
              local_dc = *(uint32_t *)(pcVar2 + 0x1a4);
              local_d8 = *(uint32_t *)(pcVar2 + 0x1a8);
              local_d4 = *(uint32_t *)(pcVar2 + 0x1ac);
              local_d0 = *(uint32_t *)(pcVar2 + 0x1b0);
              local_cc = *(uint64_t *)(pcVar2 + 0x1b4);
              local_c4 = *(uint64_t *)(pcVar2 + 0x1bc);
              local_bc = *(uint32_t *)(pcVar2 + 0x1c4);
              local_b8 = *(uint32_t *)(pcVar2 + 0x1c8);
              local_b4 = *(uint32_t *)(pcVar2 + 0x1cc);
              local_b0 = *(uint32_t *)(pcVar2 + 0x1d0);
              local_a8 = *(uint64_t *)(pcVar2 + 0x1d4);
              local_a0 = *(uint64_t *)(pcVar2 + 0x1dc);
              local_98 = *(uint64_t *)(pcVar2 + 0x1e4);
              local_90 = *(uint32_t *)pcVar16;
              local_8c = *(uint32_t *)(pcVar16 + 4);
              local_88 = *(uint32_t *)(pcVar16 + 8);
              local_84 = *(uint32_t *)(pcVar16 + 0xc);
              local_80 = *(uint32_t *)(pcVar16 + 0x10);
              __strlen_chk(auStack_39c,0x324);
              goto LAB_0013f884;
            }
            iVar6 = *(int *)(pcVar16 + iVar10);
            uVar12 = (long)iVar10 + 4;
            if (iVar6 < 1) {
              uVar12 = uVar12 & 0xffffffff;
            }
            else {
              iVar10 = *piVar23;
              if ((iVar10 < 0xfd20) && (*plVar21 != 0)) {
                piVar17 = (int *)(*plVar21 + (long)iVar10);
                *piVar23 = iVar10 + 0x2e0;
              }
              else {
                piVar17 = malloc(0x2e0);
                ArrayList_add(param_1 + 0x50,piVar17);
              }
              memset(piVar17,0,0x2e0);
              piVar13 = (int *)(pcVar16 + uVar12);
              iVar10 = *piVar13;
              piVar17[2] = 0;
              piVar17[3] = 0;
              *piVar17 = iVar10;
              piVar17[4] = piVar13[1];
              uVar11 = piVar13[2];
              if ((int)uVar11 < 1) {
                uVar11 = 0xc;
              }
              else {
                memcpy(piVar17 + 5,piVar13 + 3,(unsigned long)uVar11);
                uVar11 = uVar11 + 0xc;
              }
              uVar4 = *(uint32_t *)((long)piVar13 + (unsigned long)uVar11);
              uVar11 = uVar11 + 4;
              if (0 < (int)uVar4) {
                memcpy(piVar17 + 0x45,(void *)((long)piVar13 + (unsigned long)uVar11),(unsigned long)uVar4);
                uVar11 = uVar11 + uVar4;
              }
              puVar1 = (uint8_t *)((long)piVar13 + (unsigned long)uVar11);
              uVar11 = iVar6 + (int)uVar12;
              *(uint8_t *)(piVar17 + 0x85) = *puVar1;
              *(uint8_t *)((long)piVar17 + 0x215) = puVar1[1];
              *(uint8_t *)((long)piVar17 + 0x216) = puVar1[2];
              *(uint8_t *)((long)piVar17 + 0x217) = puVar1[3];
              piVar17[0x86] = *(int *)(puVar1 + 4);
              piVar17[0x87] = *(int *)(puVar1 + 8);
              piVar17[0x88] = *(int *)(puVar1 + 0xc);
              piVar17[0x89] = *(int *)(puVar1 + 0x10);
              piVar17[0x8a] = *(int *)(puVar1 + 0x14);
              piVar17[0x8b] = *(int *)(puVar1 + 0x18);
              piVar17[0x8c] = *(int *)(puVar1 + 0x1c);
              piVar17[0x8d] = *(int *)(puVar1 + 0x20);
              piVar17[0x8e] = *(int *)(puVar1 + 0x24);
              piVar17[0x8f] = *(int *)(puVar1 + 0x28);
              piVar17[0x90] = *(int *)(puVar1 + 0x2c);
              piVar17[0x91] = *(int *)(puVar1 + 0x30);
              piVar17[0x92] = *(int *)(puVar1 + 0x34);
              piVar17[0x93] = *(int *)(puVar1 + 0x38);
              piVar17[0x94] = *(int *)(puVar1 + 0x3c);
              piVar17[0x95] = *(int *)(puVar1 + 0x40);
              piVar17[0x96] = *(int *)(puVar1 + 0x44);
              piVar17[0x97] = *(int *)(puVar1 + 0x48);
              piVar17[0x98] = *(int *)(puVar1 + 0x4c);
              piVar17[0x99] = *(int *)(puVar1 + 0x50);
              piVar17[0x9a] = *(int *)(puVar1 + 0x54);
              piVar17[0x9b] = *(int *)(puVar1 + 0x58);
              piVar17[0x9c] = *(int *)(puVar1 + 0x5c);
              piVar17[0x9d] = *(int *)(puVar1 + 0x60);
              piVar17[0x9e] = *(int *)(puVar1 + 100);
              piVar17[0x9f] = *(int *)(puVar1 + 0x68);
              piVar17[0xa0] = *(int *)(puVar1 + 0x6c);
              piVar17[0xa1] = *(int *)(puVar1 + 0x70);
              piVar17[0xa2] = *(int *)(puVar1 + 0x74);
              piVar17[0xa3] = *(int *)(puVar1 + 0x78);
              piVar17[0xa4] = *(int *)(puVar1 + 0x7c);
              piVar17[0xa5] = *(int *)(puVar1 + 0x80);
              piVar17[0xa6] = *(int *)(puVar1 + 0x84);
              piVar17[0xa7] = *(int *)(puVar1 + 0x88);
              piVar17[0xa8] = *(int *)(puVar1 + 0x8c);
              piVar17[0xa9] = *(int *)(puVar1 + 0x90);
              piVar17[0xaa] = *(int *)(puVar1 + 0x94);
              piVar17[0xab] = *(int *)(puVar1 + 0x98);
              piVar17[0xac] = *(int *)(puVar1 + 0x9c);
              piVar17[0xad] = *(int *)(puVar1 + 0xa0);
              piVar17[0xae] = *(int *)(puVar1 + 0xa4);
              piVar17[0xaf] = *(int *)(puVar1 + 0xa8);
              piVar17[0xb0] = *(int *)(puVar1 + 0xac);
              piVar17[0xb1] = *(int *)(puVar1 + 0xb0);
              piVar17[0xb2] = *(int *)(puVar1 + 0xb4);
              piVar17[0xb3] = *(int *)(puVar1 + 0xb8);
              *(uint64_t *)(piVar17 + 0xb4) = *(uint64_t *)(puVar1 + 0xbc);
              piVar17[0xb6] = *(int *)(puVar1 + 0xc4);
LAB_0013f3f4:
              uVar12 = (unsigned long)uVar11;
              *(int **)(piVar17 + 2) = piVar22;
              piVar22 = piVar17;
            }
          }
        }
        else if (iVar6 == 0x36) {
          iVar6 = *(int *)(pcVar16 + iVar10);
          uVar12 = (long)iVar10 + 4;
          if (0 < iVar6) {
            iVar10 = *piVar23;
            if ((iVar10 < 0xff28) && (*plVar21 != 0)) {
              piVar17 = (int *)(*plVar21 + (long)iVar10);
              *piVar23 = iVar10 + 0xd8;
            }
            else {
              piVar17 = malloc(0xd8);
              ArrayList_add(param_1 + 0x50,piVar17);
            }
            piVar17[0x34] = 0;
            piVar17[0x35] = 0;
            piVar17[0x2e] = 0;
            piVar17[0x2f] = 0;
            piVar17[0x2c] = 0;
            piVar17[0x2d] = 0;
            piVar17[0x32] = 0;
            piVar17[0x33] = 0;
            piVar17[0x30] = 0;
            piVar17[0x31] = 0;
            piVar17[0x26] = 0;
            piVar17[0x27] = 0;
            piVar17[0x24] = 0;
            piVar17[0x25] = 0;
            piVar17[0x2a] = 0;
            piVar17[0x2b] = 0;
            piVar17[0x28] = 0;
            piVar17[0x29] = 0;
            piVar17[0x1e] = 0;
            piVar17[0x1f] = 0;
            piVar17[0x1c] = 0;
            piVar17[0x1d] = 0;
            piVar17[0x22] = 0;
            piVar17[0x23] = 0;
            piVar17[0x20] = 0;
            piVar17[0x21] = 0;
            piVar17[0x16] = 0;
            piVar17[0x17] = 0;
            piVar17[0x14] = 0;
            piVar17[0x15] = 0;
            piVar17[0x1a] = 0;
            piVar17[0x1b] = 0;
            piVar17[0x18] = 0;
            piVar17[0x19] = 0;
            piVar17[0xe] = 0;
            piVar17[0xf] = 0;
            piVar17[0xc] = 0;
            piVar17[0xd] = 0;
            piVar17[0x12] = 0;
            piVar17[0x13] = 0;
            piVar17[0x10] = 0;
            piVar17[0x11] = 0;
            piVar17[6] = 0;
            piVar17[7] = 0;
            piVar17[4] = 0;
            piVar17[5] = 0;
            piVar17[10] = 0;
            piVar17[0xb] = 0;
            piVar17[8] = 0;
            piVar17[9] = 0;
            piVar17[2] = 0;
            piVar17[3] = 0;
            piVar17[0] = 0;
            piVar17[1] = 0;
            piVar13 = (int *)(pcVar16 + uVar12);
            uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
            *piVar17 = *piVar13;
            piVar17[4] = piVar13[1];
            piVar17[5] = piVar13[2];
            piVar17[6] = piVar13[3];
            piVar17[7] = piVar13[4];
            piVar17[8] = piVar13[5];
            piVar17[9] = piVar13[6];
            piVar17[10] = piVar13[7];
            piVar17[0xb] = piVar13[8];
            piVar17[0xc] = piVar13[9];
            piVar17[0xd] = piVar13[10];
            piVar17[0xe] = piVar13[0xb];
            piVar17[0xf] = piVar13[0xc];
            piVar17[0x10] = piVar13[0xd];
            piVar17[0x11] = piVar13[0xe];
            piVar17[0x12] = piVar13[0xf];
            piVar17[0x13] = piVar13[0x10];
            piVar17[0x14] = piVar13[0x11];
            piVar17[0x15] = piVar13[0x12];
            piVar17[0x16] = piVar13[0x13];
            piVar17[0x17] = piVar13[0x14];
            piVar17[0x18] = piVar13[0x15];
            piVar17[0x19] = piVar13[0x16];
            piVar17[0x1a] = piVar13[0x17];
            piVar17[0x1b] = piVar13[0x18];
            piVar17[0x1c] = piVar13[0x19];
            piVar17[0x1d] = piVar13[0x1a];
            piVar17[0x1e] = piVar13[0x1b];
            piVar17[0x1f] = piVar13[0x1c];
            piVar17[0x20] = piVar13[0x1d];
            piVar17[0x21] = piVar13[0x1e];
            piVar17[0x22] = piVar13[0x1f];
            piVar17[0x23] = piVar13[0x20];
            piVar17[0x24] = piVar13[0x21];
            piVar17[0x25] = piVar13[0x22];
            piVar17[0x26] = piVar13[0x23];
            piVar17[0x27] = piVar13[0x24];
            piVar17[0x28] = piVar13[0x25];
            piVar17[0x29] = piVar13[0x26];
            piVar17[0x2a] = piVar13[0x27];
            piVar17[0x2b] = piVar13[0x28];
            *(uint64_t *)(piVar17 + 0x2c) = *(uint64_t *)(piVar13 + 0x29);
            piVar17[0x2e] = piVar13[0x2b];
            *(uint64_t *)(piVar17 + 0x30) = *(uint64_t *)(piVar13 + 0x2c);
            piVar17[0x32] = piVar13[0x2e];
            *(uint64_t *)(piVar17 + 0x34) = *(uint64_t *)(piVar13 + 0x2f);
LAB_0013df54:
            *(int **)(piVar17 + 2) = piVar22;
            piVar22 = piVar17;
          }
        }
        else {
          if (iVar6 != 0x3b9b3761) goto LAB_0013f414;
          iVar6 = *(int *)(pcVar16 + iVar10);
          uVar12 = (long)iVar10 + 4;
          if (0 < iVar6) {
            iVar10 = *piVar23;
            if ((iVar10 < 0xffc0) && (*plVar21 != 0)) {
              piVar17 = (int *)(*plVar21 + (long)iVar10);
              *piVar23 = iVar10 + 0x40;
            }
            else {
              piVar17 = malloc(0x40);
              ArrayList_add(param_1 + 0x50,piVar17);
            }
            piVar17[10] = 0;
            piVar17[0xb] = 0;
            piVar17[8] = 0;
            piVar17[9] = 0;
            piVar17[0xe] = 0;
            piVar17[0xf] = 0;
            piVar17[0xc] = 0;
            piVar17[0xd] = 0;
            piVar17[2] = 0;
            piVar17[3] = 0;
            piVar17[0] = 0;
            piVar17[1] = 0;
            piVar17[6] = 0;
            piVar17[7] = 0;
            piVar17[4] = 0;
            piVar17[5] = 0;
            piVar13 = (int *)(pcVar16 + uVar12);
            uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
            *piVar17 = *piVar13;
            piVar17[4] = piVar13[1];
            piVar17[5] = piVar13[2];
            *(uint64_t *)(piVar17 + 6) = *(uint64_t *)(piVar13 + 3);
            piVar17[8] = piVar13[5];
            piVar17[9] = piVar13[6];
            piVar17[10] = piVar13[7];
            piVar17[0xb] = piVar13[8];
            piVar17[0xc] = piVar13[9];
            piVar17[0xd] = piVar13[10];
            piVar17[0xe] = piVar13[0xb];
            goto LAB_0013df54;
          }
        }
      }
      else if (iVar6 < 0x3b9cf89b) {
        if (iVar6 < 0x3b9cc5d0) {
          if (iVar6 == 0x3b9c5488) {
            iVar6 = *(int *)(pcVar16 + iVar10);
            uVar12 = (long)iVar10 + 4;
            if (0 < iVar6) {
              iVar10 = *piVar23;
              if ((iVar10 < 0xffc8) && (*plVar21 != 0)) {
                piVar17 = (int *)(*plVar21 + (long)iVar10);
                *piVar23 = iVar10 + 0x38;
              }
              else {
                piVar17 = malloc(0x38);
                ArrayList_add(param_1 + 0x50,piVar17);
              }
              piVar17[0xc] = 0;
              piVar17[0xd] = 0;
              piVar17[6] = 0;
              piVar17[7] = 0;
              piVar17[4] = 0;
              piVar17[5] = 0;
              piVar17[10] = 0;
              piVar17[0xb] = 0;
              piVar17[8] = 0;
              piVar17[9] = 0;
              piVar17[2] = 0;
              piVar17[3] = 0;
              piVar17[0] = 0;
              piVar17[1] = 0;
              piVar13 = (int *)(pcVar16 + uVar12);
              uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
              *piVar17 = *piVar13;
              piVar17[4] = piVar13[1];
              piVar17[5] = piVar13[2];
              piVar17[6] = piVar13[3];
              piVar17[7] = piVar13[4];
              piVar17[8] = piVar13[5];
              piVar17[9] = piVar13[6];
              piVar17[10] = piVar13[7];
              piVar17[0xb] = piVar13[8];
              piVar17[0xc] = piVar13[9];
              goto LAB_0013df54;
            }
          }
          else {
            if (iVar6 != 0x3b9c9308) goto LAB_0013f414;
            iVar6 = *(int *)(pcVar16 + iVar10);
            uVar12 = (long)iVar10 + 4;
            if (0 < iVar6) {
              iVar10 = *piVar23;
              if ((iVar10 < 0xffe8) && (*plVar21 != 0)) {
                piVar17 = (int *)(*plVar21 + (long)iVar10);
                *piVar23 = iVar10 + 0x18;
              }
              else {
                piVar17 = malloc(0x18);
                ArrayList_add(param_1 + 0x50,piVar17);
              }
              piVar17[0] = 0;
              piVar17[1] = 0;
              piVar17[2] = 0;
              piVar17[3] = 0;
              piVar17[4] = 0;
              piVar17[5] = 0;
              piVar13 = (int *)(pcVar16 + uVar12);
              iVar10 = *piVar13;
              piVar17[2] = 0;
              piVar17[3] = 0;
              goto LAB_0013e364;
            }
          }
        }
        else {
          if (iVar6 == 0x3b9cc5d0) goto LAB_0013e430;
          if (iVar6 != 0x3b9ce511) goto LAB_0013f414;
          iVar6 = *(int *)(pcVar16 + iVar10);
          uVar12 = (long)iVar10 + 4;
          if (0 < iVar6) {
            iVar10 = *piVar23;
            if ((iVar10 < 0xffd8) && (*plVar21 != 0)) {
              piVar17 = (int *)(*plVar21 + (long)iVar10);
              *piVar23 = iVar10 + 0x28;
            }
            else {
              piVar17 = malloc(0x28);
              ArrayList_add(param_1 + 0x50,piVar17);
            }
            piVar17[8] = 0;
            piVar17[9] = 0;
            piVar17[2] = 0;
            piVar17[3] = 0;
            piVar17[0] = 0;
            piVar17[1] = 0;
            piVar17[6] = 0;
            piVar17[7] = 0;
            piVar17[4] = 0;
            piVar17[5] = 0;
            piVar13 = (int *)(pcVar16 + uVar12);
            uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
            *piVar17 = *piVar13;
            piVar17[4] = piVar13[1];
            piVar17[5] = piVar13[2];
            piVar17[6] = piVar13[3];
            piVar17[7] = piVar13[4];
            piVar17[8] = piVar13[5];
            goto LAB_0013df54;
          }
        }
      }
      else if (iVar6 < 0x3b9d3eea) {
        if (iVar6 != 0x3b9cf89b) {
          if (iVar6 == 0x3b9d006a) goto LAB_0013e300;
          goto LAB_0013f414;
        }
        iVar6 = *(int *)(pcVar16 + iVar10);
        uVar12 = (long)iVar10 + 4;
        if (0 < iVar6) {
          iVar10 = *piVar23;
          if ((iVar10 < 0xffd0) && (*plVar21 != 0)) {
            piVar17 = (int *)(*plVar21 + (long)iVar10);
            *piVar23 = iVar10 + 0x30;
          }
          else {
            piVar17 = malloc(0x30);
            ArrayList_add(param_1 + 0x50,piVar17);
          }
          piVar17[6] = 0;
          piVar17[7] = 0;
          piVar17[4] = 0;
          piVar17[5] = 0;
          piVar17[10] = 0;
          piVar17[0xb] = 0;
          piVar17[8] = 0;
          piVar17[9] = 0;
          piVar17[2] = 0;
          piVar17[3] = 0;
          piVar17[0] = 0;
          piVar17[1] = 0;
          piVar13 = (int *)(pcVar16 + uVar12);
          iVar10 = *piVar13;
          piVar17[2] = 0;
          piVar17[3] = 0;
          *piVar17 = iVar10;
          piVar17[4] = piVar13[1];
          piVar17[5] = piVar13[2];
          piVar17[6] = piVar13[3];
          *(uint64_t *)(piVar17 + 7) = *(uint64_t *)(piVar13 + 4);
          piVar17[9] = piVar13[6];
          iVar10 = piVar13[7];
LAB_0013f06c:
          uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
          piVar17[10] = iVar10;
          goto LAB_0013df54;
        }
      }
      else if (iVar6 == 0x3b9d3eea) {
        iVar6 = *(int *)(pcVar16 + iVar10);
        uVar12 = (long)iVar10 + 4;
        if (0 < iVar6) {
          iVar10 = *piVar23;
          if ((iVar10 < 0xff90) && (*plVar21 != 0)) {
            piVar17 = (int *)(*plVar21 + (long)iVar10);
            *piVar23 = iVar10 + 0x70;
          }
          else {
            piVar17 = malloc(0x70);
            ArrayList_add(param_1 + 0x50,piVar17);
          }
          piVar17[0x16] = 0;
          piVar17[0x17] = 0;
          piVar17[0x14] = 0;
          piVar17[0x15] = 0;
          piVar17[0x1a] = 0;
          piVar17[0x1b] = 0;
          piVar17[0x18] = 0;
          piVar17[0x19] = 0;
          piVar17[0xe] = 0;
          piVar17[0xf] = 0;
          piVar17[0xc] = 0;
          piVar17[0xd] = 0;
          piVar17[0x12] = 0;
          piVar17[0x13] = 0;
          piVar17[0x10] = 0;
          piVar17[0x11] = 0;
          piVar17[6] = 0;
          piVar17[7] = 0;
          piVar17[4] = 0;
          piVar17[5] = 0;
          piVar17[10] = 0;
          piVar17[0xb] = 0;
          piVar17[8] = 0;
          piVar17[9] = 0;
          piVar17[2] = 0;
          piVar17[3] = 0;
          piVar17[0] = 0;
          piVar17[1] = 0;
          piVar13 = (int *)(pcVar16 + uVar12);
          uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
          *piVar17 = *piVar13;
          piVar17[4] = piVar13[1];
          piVar17[5] = piVar13[2];
          piVar17[6] = piVar13[3];
          piVar17[7] = piVar13[4];
          piVar17[8] = piVar13[5];
          piVar17[9] = piVar13[6];
          piVar17[10] = piVar13[7];
          piVar17[0xb] = piVar13[8];
          piVar17[0xc] = piVar13[9];
          piVar17[0xd] = piVar13[10];
          piVar17[0xe] = piVar13[0xb];
          piVar17[0xf] = piVar13[0xc];
          piVar17[0x10] = piVar13[0xd];
          piVar17[0x11] = piVar13[0xe];
          piVar17[0x12] = piVar13[0xf];
          piVar17[0x13] = piVar13[0x10];
          piVar17[0x14] = piVar13[0x11];
          piVar17[0x15] = piVar13[0x12];
          piVar17[0x16] = piVar13[0x13];
          piVar17[0x17] = piVar13[0x14];
          piVar17[0x18] = piVar13[0x15];
          piVar17[0x19] = piVar13[0x16];
          piVar17[0x1a] = piVar13[0x17];
          goto LAB_0013df54;
        }
      }
      else {
        if (iVar6 != 0x3b9d5a40) goto LAB_0013f414;
        iVar6 = *(int *)(pcVar16 + iVar10);
        uVar12 = (long)iVar10 + 4;
        if (0 < iVar6) {
          iVar10 = *piVar23;
          if ((iVar10 < 0xffe0) && (*plVar21 != 0)) {
            piVar17 = (int *)(*plVar21 + (long)iVar10);
            *piVar23 = iVar10 + 0x20;
          }
          else {
            piVar17 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,piVar17);
          }
          piVar17[2] = 0;
          piVar17[3] = 0;
          piVar17[0] = 0;
          piVar17[1] = 0;
          piVar17[6] = 0;
          piVar17[7] = 0;
          piVar17[4] = 0;
          piVar17[5] = 0;
          piVar13 = (int *)(pcVar16 + uVar12);
          *piVar17 = *piVar13;
          piVar17[4] = piVar13[1];
          uVar7 = *(uint64_t *)(piVar13 + 2);
          goto LAB_0013f140;
        }
      }
    }
    else if (iVar6 < 0x3b9f0fc1) {
      if (iVar6 < 0x3b9df299) {
        if (iVar6 < 0x3b9dcb88) {
          if (iVar6 == 0x3b9db030) goto LAB_0013e300;
          if (iVar6 != 0x3b9dc7a0) goto LAB_0013f414;
          iVar6 = *(int *)(pcVar16 + iVar10);
          uVar12 = (long)iVar10 + 4;
          if (0 < iVar6) {
            iVar10 = *piVar23;
            if ((iVar10 < 65000) && (*plVar21 != 0)) {
              piVar17 = (int *)(*plVar21 + (long)iVar10);
              *piVar23 = iVar10 + 0x218;
            }
            else {
              piVar17 = malloc(0x218);
              ArrayList_add(param_1 + 0x50,piVar17);
            }
            memset(piVar17,0,0x218);
            piVar13 = (int *)(pcVar16 + uVar12);
            iVar10 = *piVar13;
            piVar17[2] = 0;
            piVar17[3] = 0;
            *piVar17 = iVar10;
            piVar17[4] = piVar13[1];
            uVar11 = piVar13[2];
            if ((int)uVar11 < 1) {
              uVar11 = 0xc;
            }
            else {
              memcpy(piVar17 + 5,piVar13 + 3,(unsigned long)uVar11);
              uVar11 = uVar11 + 0xc;
            }
            uVar4 = *(uint32_t *)((long)piVar13 + (unsigned long)uVar11);
            uVar11 = uVar11 + 4;
            if (0 < (int)uVar4) {
              memcpy(piVar17 + 0x45,(void *)((long)piVar13 + (unsigned long)uVar11),(unsigned long)uVar4);
              uVar11 = uVar11 + uVar4;
            }
            puVar1 = (uint8_t *)((long)piVar13 + (unsigned long)uVar11);
            uVar11 = iVar6 + (int)uVar12;
            *(uint8_t *)(piVar17 + 0x85) = *puVar1;
            *(uint8_t *)((long)piVar17 + 0x215) = puVar1[1];
            *(uint8_t *)((long)piVar17 + 0x216) = puVar1[2];
            *(uint8_t *)((long)piVar17 + 0x217) = puVar1[3];
            goto LAB_0013f3f4;
          }
          uVar12 = uVar12 & 0xffffffff;
        }
        else {
          if (iVar6 != 0x3b9dcb88) {
            if (iVar6 == 0x3b9dd358) goto LAB_0013e4e8;
            goto LAB_0013f414;
          }
          iVar6 = *(int *)(pcVar16 + iVar10);
          uVar12 = (long)iVar10 + 4;
          if (0 < iVar6) {
            iVar10 = *piVar23;
            if ((iVar10 < 0xffa8) && (*plVar21 != 0)) {
              piVar17 = (int *)(*plVar21 + (long)iVar10);
              *piVar23 = iVar10 + 0x58;
            }
            else {
              piVar17 = malloc(0x58);
              ArrayList_add(param_1 + 0x50,piVar17);
            }
            piVar17[0x14] = 0;
            piVar17[0x15] = 0;
            piVar17[0xe] = 0;
            piVar17[0xf] = 0;
            piVar17[0xc] = 0;
            piVar17[0xd] = 0;
            piVar17[0x12] = 0;
            piVar17[0x13] = 0;
            piVar17[0x10] = 0;
            piVar17[0x11] = 0;
            piVar17[6] = 0;
            piVar17[7] = 0;
            piVar17[4] = 0;
            piVar17[5] = 0;
            piVar17[10] = 0;
            piVar17[0xb] = 0;
            piVar17[8] = 0;
            piVar17[9] = 0;
            piVar17[2] = 0;
            piVar17[3] = 0;
            piVar17[0] = 0;
            piVar17[1] = 0;
            piVar13 = (int *)(pcVar16 + uVar12);
            iVar10 = *piVar13;
            piVar17[2] = 0;
            piVar17[3] = 0;
            uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
            *piVar17 = iVar10;
            piVar17[4] = piVar13[1];
            *(uint64_t *)(piVar17 + 5) = *(uint64_t *)(piVar13 + 2);
            piVar17[7] = piVar13[4];
            piVar17[8] = piVar13[5];
            piVar17[9] = piVar13[6];
            piVar17[10] = piVar13[7];
            piVar17[0xb] = piVar13[8];
            piVar17[0xc] = piVar13[9];
            piVar17[0xd] = piVar13[10];
            piVar17[0xe] = piVar13[0xb];
            piVar17[0xf] = piVar13[0xc];
            piVar17[0x10] = piVar13[0xd];
            piVar17[0x11] = piVar13[0xe];
            piVar17[0x12] = piVar13[0xf];
            piVar17[0x13] = piVar13[0x10];
            piVar17[0x14] = piVar13[0x11];
            goto LAB_0013df54;
          }
        }
      }
      else {
        if (iVar6 < 0x3b9eaa32) {
          if (iVar6 == 0x3b9df299) {
LAB_0013e524:
            iVar6 = *(int *)(pcVar16 + iVar10);
joined_r0x0013e3a8:
            uVar12 = (long)iVar10 + 4;
            if (0 < iVar6) {
              iVar10 = *piVar23;
              if ((iVar10 < 0xffe8) && (*plVar21 != 0)) {
                piVar17 = (int *)(*plVar21 + (long)iVar10);
                *piVar23 = iVar10 + 0x18;
              }
              else {
                piVar17 = malloc(0x18);
                ArrayList_add(param_1 + 0x50,piVar17);
              }
              piVar17[0] = 0;
              piVar17[1] = 0;
              piVar17[2] = 0;
              piVar17[3] = 0;
              piVar17[4] = 0;
              piVar17[5] = 0;
              piVar13 = (int *)(pcVar16 + uVar12);
              uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
              *piVar17 = *piVar13;
              *(uint64_t *)(piVar17 + 4) = *(uint64_t *)(piVar13 + 1);
              goto LAB_0013df54;
            }
            goto LAB_0013df5c;
          }
          if (iVar6 == 0x3b9e38e8) {
LAB_0013e4e8:
            iVar6 = *(int *)(pcVar16 + iVar10);
            uVar12 = (long)iVar10 + 4;
            if (0 < iVar6) {
              iVar10 = *piVar23;
              if ((iVar10 < 0xffe0) && (*plVar21 != 0)) {
                piVar17 = (int *)(*plVar21 + (long)iVar10);
                *piVar23 = iVar10 + 0x20;
              }
              else {
                piVar17 = malloc(0x20);
                ArrayList_add(param_1 + 0x50,piVar17);
              }
              piVar17[2] = 0;
              piVar17[3] = 0;
              piVar17[0] = 0;
              piVar17[1] = 0;
              piVar17[6] = 0;
              piVar17[7] = 0;
              piVar17[4] = 0;
              piVar17[5] = 0;
              piVar13 = (int *)(pcVar16 + uVar12);
              uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
              *piVar17 = *piVar13;
              piVar17[4] = piVar13[1];
              piVar17[5] = piVar13[2];
              piVar17[6] = piVar13[3];
              piVar17[7] = piVar13[4];
              goto LAB_0013df54;
            }
            goto LAB_0013df5c;
          }
        }
        else {
          if (iVar6 == 0x3b9eaa32) goto LAB_0013e430;
          if (iVar6 == 0x3b9ef081) {
            iVar6 = *(int *)(pcVar16 + iVar10);
            goto joined_r0x0013e3a8;
          }
        }
LAB_0013f414:
        uVar12 = (unsigned long)(iVar10 + 4);
      }
    }
    else if (iVar6 < 0x3ba11749) {
      if (iVar6 < 0x3b9f2731) {
        if (iVar6 == 0x3b9f0fc1) {
          iVar6 = *(int *)(pcVar16 + iVar10);
          uVar12 = (long)iVar10 + 4;
          if (0 < iVar6) {
            iVar10 = *piVar23;
            if ((iVar10 < 0xff78) && (*plVar21 != 0)) {
              piVar17 = (int *)(*plVar21 + (long)iVar10);
              *piVar23 = iVar10 + 0x88;
            }
            else {
              piVar17 = malloc(0x88);
              ArrayList_add(param_1 + 0x50,piVar17);
            }
            piVar17[0x20] = 0;
            piVar17[0x21] = 0;
            piVar17[0x1a] = 0;
            piVar17[0x1b] = 0;
            piVar17[0x18] = 0;
            piVar17[0x19] = 0;
            piVar17[0x1e] = 0;
            piVar17[0x1f] = 0;
            piVar17[0x1c] = 0;
            piVar17[0x1d] = 0;
            piVar17[0x12] = 0;
            piVar17[0x13] = 0;
            piVar17[0x10] = 0;
            piVar17[0x11] = 0;
            piVar17[0x16] = 0;
            piVar17[0x17] = 0;
            piVar17[0x14] = 0;
            piVar17[0x15] = 0;
            piVar17[10] = 0;
            piVar17[0xb] = 0;
            piVar17[8] = 0;
            piVar17[9] = 0;
            piVar17[0xe] = 0;
            piVar17[0xf] = 0;
            piVar17[0xc] = 0;
            piVar17[0xd] = 0;
            piVar17[2] = 0;
            piVar17[3] = 0;
            piVar17[0] = 0;
            piVar17[1] = 0;
            piVar17[6] = 0;
            piVar17[7] = 0;
            piVar17[4] = 0;
            piVar17[5] = 0;
            piVar13 = (int *)(pcVar16 + uVar12);
            uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
            *piVar17 = *piVar13;
            piVar17[4] = piVar13[1];
            piVar17[5] = piVar13[2];
            piVar17[6] = piVar13[3];
            piVar17[7] = piVar13[4];
            piVar17[8] = piVar13[5];
            piVar17[9] = piVar13[6];
            piVar17[10] = piVar13[7];
            piVar17[0xb] = piVar13[8];
            piVar17[0xc] = piVar13[9];
            piVar17[0xd] = piVar13[10];
            piVar17[0xe] = piVar13[0xb];
            piVar17[0xf] = piVar13[0xc];
            piVar17[0x10] = piVar13[0xd];
            piVar17[0x11] = piVar13[0xe];
            piVar17[0x12] = piVar13[0xf];
            piVar17[0x13] = piVar13[0x10];
            piVar17[0x14] = piVar13[0x11];
            piVar17[0x15] = piVar13[0x12];
            piVar17[0x16] = piVar13[0x13];
            piVar17[0x17] = piVar13[0x14];
            piVar17[0x18] = piVar13[0x15];
            piVar17[0x19] = piVar13[0x16];
            piVar17[0x1a] = piVar13[0x17];
            piVar17[0x1b] = piVar13[0x18];
            piVar17[0x1c] = piVar13[0x19];
            piVar17[0x1d] = piVar13[0x1a];
            piVar17[0x1e] = piVar13[0x1b];
            piVar17[0x1f] = piVar13[0x1c];
            piVar17[0x20] = piVar13[0x1d];
            piVar17[0x21] = piVar13[0x1e];
            goto LAB_0013df54;
          }
        }
        else {
          if (iVar6 != 0x3b9f13a9) goto LAB_0013f414;
          iVar6 = *(int *)(pcVar16 + iVar10);
          uVar12 = (long)iVar10 + 4;
          if (0 < iVar6) {
            iVar10 = *piVar23;
            if ((iVar10 < 0xffd0) && (*plVar21 != 0)) {
              piVar17 = (int *)(*plVar21 + (long)iVar10);
              *piVar23 = iVar10 + 0x30;
            }
            else {
              piVar17 = malloc(0x30);
              ArrayList_add(param_1 + 0x50,piVar17);
            }
            piVar17[6] = 0;
            piVar17[7] = 0;
            piVar17[4] = 0;
            piVar17[5] = 0;
            piVar17[10] = 0;
            piVar17[0xb] = 0;
            piVar17[8] = 0;
            piVar17[9] = 0;
            piVar17[2] = 0;
            piVar17[3] = 0;
            piVar17[0] = 0;
            piVar17[1] = 0;
            piVar13 = (int *)(pcVar16 + uVar12);
            *piVar17 = *piVar13;
            *(uint64_t *)(piVar17 + 4) = *(uint64_t *)(piVar13 + 1);
            piVar17[6] = piVar13[3];
            *(uint64_t *)(piVar17 + 8) = *(uint64_t *)(piVar13 + 4);
            iVar10 = piVar13[6];
            goto LAB_0013f06c;
          }
        }
      }
      else {
        if (iVar6 != 0x3b9f2731) {
          if (iVar6 == 0x3b9f2b19) goto LAB_0013e300;
          goto LAB_0013f414;
        }
        iVar6 = *(int *)(pcVar16 + iVar10);
        uVar12 = (long)iVar10 + 4;
        if (0 < iVar6) {
          iVar10 = *piVar23;
          if ((iVar10 < 0xffe0) && (*plVar21 != 0)) {
            piVar17 = (int *)(*plVar21 + (long)iVar10);
            *piVar23 = iVar10 + 0x20;
          }
          else {
            piVar17 = malloc(0x20);
            ArrayList_add(param_1 + 0x50,piVar17);
          }
          piVar17[2] = 0;
          piVar17[3] = 0;
          piVar17[0] = 0;
          piVar17[1] = 0;
          piVar17[6] = 0;
          piVar17[7] = 0;
          piVar17[4] = 0;
          piVar17[5] = 0;
          piVar13 = (int *)(pcVar16 + uVar12);
          *piVar17 = *piVar13;
          *(uint64_t *)(piVar17 + 4) = *(uint64_t *)(piVar13 + 1);
          uVar7 = *(uint64_t *)(piVar13 + 3);
LAB_0013f140:
          uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
          *(uint64_t *)(piVar17 + 6) = uVar7;
          goto LAB_0013df54;
        }
      }
    }
    else if (iVar6 < 0x3ba1d6b1) {
      if (iVar6 == 0x3ba11749) goto LAB_0013e524;
      if (iVar6 != 0x3ba1bb59) goto LAB_0013f414;
LAB_0013e300:
      iVar6 = *(int *)(pcVar16 + iVar10);
      uVar12 = (long)iVar10 + 4;
      if (0 < iVar6) {
        iVar10 = *piVar23;
        if ((iVar10 < 0xffe8) && (*plVar21 != 0)) {
          piVar17 = (int *)(*plVar21 + (long)iVar10);
          *piVar23 = iVar10 + 0x18;
        }
        else {
          piVar17 = malloc(0x18);
          ArrayList_add(param_1 + 0x50,piVar17);
        }
        piVar17[0] = 0;
        piVar17[1] = 0;
        piVar17[2] = 0;
        piVar17[3] = 0;
        piVar17[4] = 0;
        piVar17[5] = 0;
        piVar13 = (int *)(pcVar16 + uVar12);
        iVar10 = *piVar13;
LAB_0013e364:
        *piVar17 = iVar10;
        uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
        piVar17[4] = piVar13[1];
        goto LAB_0013df54;
      }
    }
    else {
      if (iVar6 != 0x3ba1d6b1) {
        if (iVar6 == 0x3ba2ccc8) goto LAB_0013e430;
        goto LAB_0013f414;
      }
      iVar6 = *(int *)(pcVar16 + iVar10);
      uVar12 = (long)iVar10 + 4;
      if (0 < iVar6) {
        iVar10 = *piVar23;
        if ((iVar10 < 0xffe0) && (*plVar21 != 0)) {
          piVar17 = (int *)(*plVar21 + (long)iVar10);
          *piVar23 = iVar10 + 0x20;
        }
        else {
          piVar17 = malloc(0x20);
          ArrayList_add(param_1 + 0x50,piVar17);
        }
        piVar17[2] = 0;
        piVar17[3] = 0;
        piVar17[0] = 0;
        piVar17[1] = 0;
        piVar17[6] = 0;
        piVar17[7] = 0;
        piVar17[4] = 0;
        piVar17[5] = 0;
        piVar13 = (int *)(pcVar16 + uVar12);
        iVar10 = *piVar13;
        piVar17[2] = 0;
        piVar17[3] = 0;
        uVar12 = (unsigned long)(uint32_t)(iVar6 + (int)uVar12);
        *piVar17 = iVar10;
        uVar7 = *(uint64_t *)(piVar13 + 1);
        *(uint64_t *)(piVar17 + 6) = *(uint64_t *)(piVar13 + 3);
        *(uint64_t *)(piVar17 + 4) = uVar7;
        goto LAB_0013df54;
      }
    }
LAB_0013df5c:
    piVar17 = (int *)(pcVar16 + (int)uVar12);
    iVar10 = (int)uVar12 + 4;
    goto LAB_0013df64;
  }
LAB_0013f884:
  local_3d0 = (long *)(param_1 + 0x40);
  uVar7 = VkObject_fromId(unaff_x21);
  ((generic_fn_t)DAT_00193f80)(uVar7,local_3c0);
  checkDeviceProperties(param_1,&local_3b0,local_3b8);
  if (local_3b8 == (int *)0x0) {
    iVar10 = 4;
  }
  else {
    iVar10 = 4;
    piVar17 = local_3b8;
    do {
      iVar6 = *piVar17;
      piVar23 = *(int **)(piVar17 + 2);
      piVar17[2] = 0;
      piVar17[3] = 0;
      if (iVar6 < 0x3b9db030) {
        if (iVar6 < 0x3b9c5488) {
          if (0x3b9b9909 < iVar6) {
            if (iVar6 < 0x3b9c0280) {
              if (iVar6 == 0x3b9b990a) goto LAB_0013f95c;
              if (iVar6 == 0x3b9bdf5c) {
                iVar10 = iVar10 + 0x3c;
                goto LAB_0013f960;
              }
            }
            else {
              if (iVar6 == 0x3b9c0280) goto LAB_0013fca8;
              if (iVar6 == 0x3b9c3930) goto LAB_0013fca0;
            }
            goto LAB_0013fd2c;
          }
          if (iVar6 < 0x36) {
            if (iVar6 == 0x32) {
LAB_0013fcfc:
              iVar10 = iVar10 + 0x68;
            }
            else {
              if (iVar6 != 0x34) goto LAB_0013fd2c;
              sVar8 = strlen((char *)(piVar17 + 5));
              sVar9 = strlen((char *)(piVar17 + 0x45));
              iVar10 = (int)sVar9 + (int)((sVar8 << 0x20) + 0x900000000 >> 0x20) + iVar10 + 0xd1;
            }
          }
          else if (iVar6 == 0x36) {
            iVar10 = iVar10 + 0xcc;
          }
          else {
            if (iVar6 != 0x3b9b3761) goto LAB_0013fd2c;
            iVar10 = iVar10 + 0x38;
          }
        }
        else if (iVar6 < 0x3b9cf89b) {
          if (iVar6 < 0x3b9cc5d0) {
            if (iVar6 == 0x3b9c5488) {
              iVar10 = iVar10 + 0x30;
            }
            else {
              if (iVar6 != 0x3b9c9308) goto LAB_0013fd2c;
LAB_0013fca8:
              iVar10 = iVar10 + 0x10;
            }
          }
          else {
            if (iVar6 == 0x3b9cc5d0) goto LAB_0013f95c;
            if (iVar6 != 0x3b9ce511) goto LAB_0013fd2c;
            iVar10 = iVar10 + 0x20;
          }
        }
        else if (iVar6 < 0x3b9d3eea) {
          if (iVar6 != 0x3b9cf89b) {
            if (iVar6 == 0x3b9d006a) goto LAB_0013fca8;
            goto LAB_0013fd2c;
          }
          iVar10 = iVar10 + 0x28;
        }
        else {
          if (iVar6 == 0x3b9d3eea) goto LAB_0013fcfc;
          if (iVar6 != 0x3b9d5a40) goto LAB_0013fd2c;
          iVar10 = iVar10 + 0x18;
        }
      }
      else if (iVar6 < 0x3b9f0fc1) {
        if (iVar6 < 0x3b9df299) {
          if (iVar6 < 0x3b9dcb88) {
            if (iVar6 == 0x3b9db030) goto LAB_0013fca8;
            if (iVar6 != 0x3b9dc7a0) goto LAB_0013fd2c;
            sVar8 = strlen((char *)(piVar17 + 5));
            sVar9 = strlen((char *)(piVar17 + 0x45));
            iVar10 = (int)sVar9 + (int)((sVar8 << 0x20) + 0x900000000 >> 0x20) + iVar10 + 0xd;
          }
          else {
            if (iVar6 != 0x3b9dcb88) {
              if (iVar6 == 0x3b9dd358) goto LAB_0013fca0;
              goto LAB_0013fd2c;
            }
            iVar10 = iVar10 + 0x50;
          }
        }
        else {
          if (iVar6 < 0x3b9eaa32) {
            if (iVar6 == 0x3b9df299) {
LAB_0013f95c:
              iVar10 = iVar10 + 0x14;
              goto LAB_0013f960;
            }
            if (iVar6 == 0x3b9e38e8) goto LAB_0013fca0;
          }
          else if ((iVar6 == 0x3b9eaa32) || (iVar6 == 0x3b9ef081)) goto LAB_0013f95c;
LAB_0013fd2c:
          iVar10 = iVar10 + 8;
        }
      }
      else {
        if (0x3ba11748 < iVar6) {
          if (iVar6 < 0x3ba1d6b1) {
            if (iVar6 == 0x3ba11749) goto LAB_0013f95c;
            if (iVar6 == 0x3ba1bb59) goto LAB_0013fca8;
          }
          else {
            if (iVar6 == 0x3ba1d6b1) goto LAB_0013fca0;
            if (iVar6 == 0x3ba2ccc8) goto LAB_0013f95c;
          }
          goto LAB_0013fd2c;
        }
        if (iVar6 < 0x3b9f2731) {
          if (iVar6 == 0x3b9f0fc1) {
            iVar10 = iVar10 + 0x84;
          }
          else {
            if (iVar6 != 0x3b9f13a9) goto LAB_0013fd2c;
            iVar10 = iVar10 + 0x24;
          }
        }
        else {
          if (iVar6 != 0x3b9f2731) {
            if (iVar6 == 0x3b9f2b19) goto LAB_0013fca8;
            goto LAB_0013fd2c;
          }
LAB_0013fca0:
          iVar10 = iVar10 + 0x1c;
        }
      }
LAB_0013f960:
      *(int **)(piVar17 + 2) = piVar23;
      piVar17 = piVar23;
    } while (piVar23 != (int *)0x0);
  }
  iVar6 = __strlen_chk(auStack_39c,0x324);
  iVar10 = iVar10 + iVar6 + 0x229;
  iVar6 = iVar10 + *(int *)(param_1 + 0x48);
  if ((iVar6 < 0x10000) && (*local_3d0 != 0)) {
    __s = (uint32_t *)(*local_3d0 + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar6;
  }
  else {
    __s = malloc((long)iVar10);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar10);
  *__s = local_3c0[0];
  if (local_3b8 == (int *)0x0) {
    iVar6 = 4;
  }
  else {
    iVar6 = 4;
    piVar17 = local_3b8;
    do {
      iVar18 = *piVar17;
      lVar19 = (long)iVar6;
      lVar3 = lVar19 + 4;
      *(int *)((long)__s + lVar19) = iVar18;
      piVar23 = *(int **)(piVar17 + 2);
      piVar17[2] = 0;
      piVar17[3] = 0;
      if (iVar18 < 0x3b9db030) {
        if (iVar18 < 0x3b9c5488) {
          if (0x3b9b9909 < iVar18) {
            if (iVar18 < 0x3b9c0280) {
              if (iVar18 == 0x3b9b990a) {
                uVar14 = 0x3b9b990a;
                *(uint32_t *)((long)__s + lVar3) = 0xc;
LAB_001409a0:
                *(uint32_t *)((long)__s + lVar19 + 8) = uVar14;
LAB_00140c54:
                iVar18 = piVar17[4];
                goto LAB_00140c98;
              }
              if (iVar18 == 0x3b9bdf5c) {
                *(uint32_t *)((long)__s + lVar3) = 0x34;
                *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9bdf5c;
                uVar7 = *(uint64_t *)(piVar17 + 4);
                *(uint64_t *)((long)__s + lVar19 + 0x14) = *(uint64_t *)(piVar17 + 6);
                *(uint64_t *)((long)__s + lVar19 + 0xc) = uVar7;
                uVar7 = *(uint64_t *)(piVar17 + 8);
                *(uint64_t *)((long)__s + lVar19 + 0x24) = *(uint64_t *)(piVar17 + 10);
                *(uint64_t *)((long)__s + lVar19 + 0x1c) = uVar7;
                *(uint64_t *)((long)__s + lVar19 + 0x2c) = *(uint64_t *)(piVar17 + 0xc);
                *(int *)((long)__s + lVar19 + 0x34) = piVar17[0xe];
                *(int *)((long)__s + lVar19 + 0x38) = piVar17[0xf];
                iVar6 = iVar6 + 0x3c;
                goto LAB_0013fec8;
              }
            }
            else {
              if (iVar18 == 0x3b9c0280) {
                uVar14 = 0x3b9c0280;
                *(uint32_t *)((long)__s + lVar3) = 8;
                goto LAB_00140768;
              }
              if (iVar18 == 0x3b9c3930) {
                uVar14 = 0x3b9c3930;
                *(uint32_t *)((long)__s + lVar3) = 0x14;
                goto LAB_0013fea0;
              }
            }
            goto LAB_00140d98;
          }
          if (iVar18 < 0x36) {
            if (iVar18 != 0x32) {
              if (iVar18 == 0x34) {
                sVar8 = strlen((char *)(piVar17 + 5));
                sVar9 = strlen((char *)(piVar17 + 0x45));
                iVar18 = (int)sVar9 + (int)((sVar8 << 0x20) + 0x900000000 >> 0x20) + 0xc9;
                *(int *)((long)__s + lVar3) = iVar18;
                piVar22 = (int *)((long)__s + lVar19 + 8);
                *piVar22 = *piVar17;
                piVar22[1] = piVar17[4];
                sVar8 = strlen((char *)(piVar17 + 5));
                iVar20 = (int)sVar8;
                piVar22[2] = iVar20 + 1;
                memcpy(piVar22 + 3,piVar17 + 5,(long)(iVar20 + 1));
                sVar8 = strlen((char *)(piVar17 + 0x45));
                iVar15 = (int)sVar8 + 1;
                *(int *)((long)piVar22 + (long)(iVar20 + 0xd)) = iVar15;
                memcpy((void *)((long)piVar22 + (long)(iVar20 + 0x11)),piVar17 + 0x45,(long)iVar15);
                lVar3 = (long)iVar15 + (long)(iVar20 + 0x11);
                puVar1 = (uint8_t *)((long)piVar22 + lVar3);
                *puVar1 = (char)piVar17[0x85];
                puVar1[1] = *(uint8_t *)((long)piVar17 + 0x215);
                puVar1[2] = *(uint8_t *)((long)piVar17 + 0x216);
                puVar1[3] = *(uint8_t *)((long)piVar17 + 0x217);
                iVar15 = (int)lVar3;
                *(int *)((long)piVar22 + (long)iVar15 + 4) = piVar17[0x86];
                *(int *)((long)piVar22 + (long)iVar15 + 8) = piVar17[0x87];
                *(int *)((long)piVar22 + (long)iVar15 + 0xc) = piVar17[0x88];
                *(int *)((long)piVar22 + (long)iVar15 + 0x10) = piVar17[0x89];
                *(int *)((long)piVar22 + (long)iVar15 + 0x14) = piVar17[0x8a];
                *(int *)((long)piVar22 + (long)iVar15 + 0x18) = piVar17[0x8b];
                *(int *)((long)piVar22 + (long)iVar15 + 0x1c) = piVar17[0x8c];
                *(int *)((long)piVar22 + (long)iVar15 + 0x20) = piVar17[0x8d];
                *(int *)((long)piVar22 + (long)iVar15 + 0x24) = piVar17[0x8e];
                *(int *)((long)piVar22 + (long)iVar15 + 0x28) = piVar17[0x8f];
                *(int *)((long)piVar22 + (long)iVar15 + 0x2c) = piVar17[0x90];
                *(int *)((long)piVar22 + (long)iVar15 + 0x30) = piVar17[0x91];
                *(int *)((long)piVar22 + (long)iVar15 + 0x34) = piVar17[0x92];
                *(int *)((long)piVar22 + (long)iVar15 + 0x38) = piVar17[0x93];
                *(int *)((long)piVar22 + (long)iVar15 + 0x3c) = piVar17[0x94];
                *(int *)((long)piVar22 + (long)iVar15 + 0x40) = piVar17[0x95];
                *(int *)((long)piVar22 + (long)iVar15 + 0x44) = piVar17[0x96];
                *(int *)((long)piVar22 + (long)iVar15 + 0x48) = piVar17[0x97];
                *(int *)((long)piVar22 + (long)iVar15 + 0x4c) = piVar17[0x98];
                *(int *)((long)piVar22 + (long)iVar15 + 0x50) = piVar17[0x99];
                *(int *)((long)piVar22 + (long)iVar15 + 0x54) = piVar17[0x9a];
                *(int *)((long)piVar22 + (long)iVar15 + 0x58) = piVar17[0x9b];
                *(int *)((long)piVar22 + (long)iVar15 + 0x5c) = piVar17[0x9c];
                *(int *)((long)piVar22 + (long)iVar15 + 0x60) = piVar17[0x9d];
                *(int *)((long)piVar22 + (long)iVar15 + 100) = piVar17[0x9e];
                *(int *)((long)piVar22 + (long)iVar15 + 0x68) = piVar17[0x9f];
                *(int *)((long)piVar22 + (long)iVar15 + 0x6c) = piVar17[0xa0];
                *(int *)((long)piVar22 + (long)iVar15 + 0x70) = piVar17[0xa1];
                *(int *)((long)piVar22 + (long)iVar15 + 0x74) = piVar17[0xa2];
                *(int *)((long)piVar22 + (long)iVar15 + 0x78) = piVar17[0xa3];
                *(int *)((long)piVar22 + (long)iVar15 + 0x7c) = piVar17[0xa4];
                *(int *)((long)piVar22 + (long)iVar15 + 0x80) = piVar17[0xa5];
                *(int *)((long)piVar22 + (long)iVar15 + 0x84) = piVar17[0xa6];
                *(int *)((long)piVar22 + (long)iVar15 + 0x88) = piVar17[0xa7];
                *(int *)((long)piVar22 + (long)iVar15 + 0x8c) = piVar17[0xa8];
                *(int *)((long)piVar22 + (long)iVar15 + 0x90) = piVar17[0xa9];
                *(int *)((long)piVar22 + (long)iVar15 + 0x94) = piVar17[0xaa];
                *(int *)((long)piVar22 + (long)iVar15 + 0x98) = piVar17[0xab];
                *(int *)((long)piVar22 + (long)iVar15 + 0x9c) = piVar17[0xac];
                *(int *)((long)piVar22 + (long)iVar15 + 0xa0) = piVar17[0xad];
                *(int *)((long)piVar22 + (long)iVar15 + 0xa4) = piVar17[0xae];
                *(int *)((long)piVar22 + (long)iVar15 + 0xa8) = piVar17[0xaf];
                *(int *)((long)piVar22 + (long)iVar15 + 0xac) = piVar17[0xb0];
                *(int *)((long)piVar22 + (long)iVar15 + 0xb0) = piVar17[0xb1];
                *(int *)((long)piVar22 + (long)iVar15 + 0xb4) = piVar17[0xb2];
                *(int *)((long)piVar22 + (long)iVar15 + 0xb8) = piVar17[0xb3];
                *(uint64_t *)((long)piVar22 + (long)iVar15 + 0xbc) =
                     *(uint64_t *)(piVar17 + 0xb4);
                *(int *)((long)piVar22 + (long)iVar15 + 0xc4) = piVar17[0xb6];
                goto LAB_00140384;
              }
              goto LAB_00140d98;
            }
            *(uint32_t *)((long)__s + lVar3) = 0x60;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x32;
            uVar7 = *(uint64_t *)(piVar17 + 4);
            *(uint64_t *)((long)__s + lVar19 + 0x14) = *(uint64_t *)(piVar17 + 6);
            *(uint64_t *)((long)__s + lVar19 + 0xc) = uVar7;
            uVar7 = *(uint64_t *)(piVar17 + 8);
            *(uint64_t *)((long)__s + lVar19 + 0x24) = *(uint64_t *)(piVar17 + 10);
            *(uint64_t *)((long)__s + lVar19 + 0x1c) = uVar7;
            *(uint64_t *)((long)__s + lVar19 + 0x2c) = *(uint64_t *)(piVar17 + 0xc);
            *(int *)((long)__s + lVar19 + 0x34) = piVar17[0xe];
            *(int *)((long)__s + lVar19 + 0x38) = piVar17[0xf];
            *(int *)((long)__s + lVar19 + 0x3c) = piVar17[0x10];
            *(int *)((long)__s + lVar19 + 0x40) = piVar17[0x11];
            *(int *)((long)__s + lVar19 + 0x44) = piVar17[0x12];
            *(uint64_t *)((long)__s + lVar19 + 0x48) = *(uint64_t *)(piVar17 + 0x13);
            *(int *)((long)__s + lVar19 + 0x50) = piVar17[0x15];
            *(int *)((long)__s + lVar19 + 0x54) = piVar17[0x16];
            *(int *)((long)__s + lVar19 + 0x58) = piVar17[0x17];
            *(int *)((long)__s + lVar19 + 0x5c) = piVar17[0x18];
            *(uint64_t *)((long)__s + lVar19 + 0x60) = *(uint64_t *)(piVar17 + 0x1a);
            iVar6 = iVar6 + 0x68;
          }
          else if (iVar18 == 0x36) {
            *(uint32_t *)((long)__s + lVar3) = 0xc4;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x36;
            *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
            *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
            *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
            *(int *)((long)__s + lVar19 + 0x18) = piVar17[7];
            *(int *)((long)__s + lVar19 + 0x1c) = piVar17[8];
            *(int *)((long)__s + lVar19 + 0x20) = piVar17[9];
            *(int *)((long)__s + lVar19 + 0x24) = piVar17[10];
            *(int *)((long)__s + lVar19 + 0x28) = piVar17[0xb];
            *(int *)((long)__s + lVar19 + 0x2c) = piVar17[0xc];
            *(int *)((long)__s + lVar19 + 0x30) = piVar17[0xd];
            *(int *)((long)__s + lVar19 + 0x34) = piVar17[0xe];
            *(int *)((long)__s + lVar19 + 0x38) = piVar17[0xf];
            *(int *)((long)__s + lVar19 + 0x3c) = piVar17[0x10];
            *(int *)((long)__s + lVar19 + 0x40) = piVar17[0x11];
            *(int *)((long)__s + lVar19 + 0x44) = piVar17[0x12];
            *(int *)((long)__s + lVar19 + 0x48) = piVar17[0x13];
            *(int *)((long)__s + lVar19 + 0x4c) = piVar17[0x14];
            *(int *)((long)__s + lVar19 + 0x50) = piVar17[0x15];
            *(int *)((long)__s + lVar19 + 0x54) = piVar17[0x16];
            *(int *)((long)__s + lVar19 + 0x58) = piVar17[0x17];
            *(int *)((long)__s + lVar19 + 0x5c) = piVar17[0x18];
            *(int *)((long)__s + lVar19 + 0x60) = piVar17[0x19];
            *(int *)((long)__s + lVar19 + 100) = piVar17[0x1a];
            *(int *)((long)__s + lVar19 + 0x68) = piVar17[0x1b];
            *(int *)((long)__s + lVar19 + 0x6c) = piVar17[0x1c];
            *(int *)((long)__s + lVar19 + 0x70) = piVar17[0x1d];
            *(int *)((long)__s + lVar19 + 0x74) = piVar17[0x1e];
            *(int *)((long)__s + lVar19 + 0x78) = piVar17[0x1f];
            *(int *)((long)__s + lVar19 + 0x7c) = piVar17[0x20];
            *(int *)((long)__s + lVar19 + 0x80) = piVar17[0x21];
            *(int *)((long)__s + lVar19 + 0x84) = piVar17[0x22];
            *(int *)((long)__s + lVar19 + 0x88) = piVar17[0x23];
            *(int *)((long)__s + lVar19 + 0x8c) = piVar17[0x24];
            *(int *)((long)__s + lVar19 + 0x90) = piVar17[0x25];
            *(int *)((long)__s + lVar19 + 0x94) = piVar17[0x26];
            *(int *)((long)__s + lVar19 + 0x98) = piVar17[0x27];
            *(int *)((long)__s + lVar19 + 0x9c) = piVar17[0x28];
            *(int *)((long)__s + lVar19 + 0xa0) = piVar17[0x29];
            *(int *)((long)__s + lVar19 + 0xa4) = piVar17[0x2a];
            *(int *)((long)__s + lVar19 + 0xa8) = piVar17[0x2b];
            *(uint64_t *)((long)__s + lVar19 + 0xac) = *(uint64_t *)(piVar17 + 0x2c);
            *(int *)((long)__s + lVar19 + 0xb4) = piVar17[0x2e];
            *(uint64_t *)((long)__s + lVar19 + 0xb8) = *(uint64_t *)(piVar17 + 0x30);
            *(int *)((long)__s + lVar19 + 0xc0) = piVar17[0x32];
            *(uint64_t *)((long)__s + lVar19 + 0xc4) = *(uint64_t *)(piVar17 + 0x34);
            iVar6 = iVar6 + 0xcc;
          }
          else {
            if (iVar18 != 0x3b9b3761) goto LAB_00140d98;
            *(uint32_t *)((long)__s + lVar3) = 0x30;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9b3761;
            *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
            *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
            *(uint64_t *)((long)__s + lVar19 + 0x14) = *(uint64_t *)(piVar17 + 6);
            *(int *)((long)__s + lVar19 + 0x1c) = piVar17[8];
            *(int *)((long)__s + lVar19 + 0x20) = piVar17[9];
            *(int *)((long)__s + lVar19 + 0x24) = piVar17[10];
            *(int *)((long)__s + lVar19 + 0x28) = piVar17[0xb];
            *(int *)((long)__s + lVar19 + 0x2c) = piVar17[0xc];
            *(int *)((long)__s + lVar19 + 0x30) = piVar17[0xd];
            *(int *)((long)__s + lVar19 + 0x34) = piVar17[0xe];
            iVar6 = iVar6 + 0x38;
          }
        }
        else if (iVar18 < 0x3b9cf89b) {
          if (iVar18 < 0x3b9cc5d0) {
            if (iVar18 != 0x3b9c5488) {
              if (iVar18 == 0x3b9c9308) {
                *(uint32_t *)((long)__s + lVar3) = 8;
                uVar14 = 0x3b9c9308;
                goto LAB_00140768;
              }
              goto LAB_00140d98;
            }
            *(uint32_t *)((long)__s + lVar3) = 0x28;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9c5488;
            *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
            *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
            *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
            *(int *)((long)__s + lVar19 + 0x18) = piVar17[7];
            *(int *)((long)__s + lVar19 + 0x1c) = piVar17[8];
            *(int *)((long)__s + lVar19 + 0x20) = piVar17[9];
            *(int *)((long)__s + lVar19 + 0x24) = piVar17[10];
            *(int *)((long)__s + lVar19 + 0x28) = piVar17[0xb];
            *(int *)((long)__s + lVar19 + 0x2c) = piVar17[0xc];
            iVar6 = iVar6 + 0x30;
          }
          else {
            if (iVar18 == 0x3b9cc5d0) {
              *(uint32_t *)((long)__s + lVar3) = 0xc;
              *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9cc5d0;
              goto LAB_00140c54;
            }
            if (iVar18 != 0x3b9ce511) goto LAB_00140d98;
            *(uint32_t *)((long)__s + lVar3) = 0x18;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9ce511;
            *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
            *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
            *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
            *(int *)((long)__s + lVar19 + 0x18) = piVar17[7];
            *(int *)((long)__s + lVar19 + 0x1c) = piVar17[8];
            iVar6 = iVar6 + 0x20;
          }
        }
        else if (iVar18 < 0x3b9d3eea) {
          if (iVar18 != 0x3b9cf89b) {
            if (iVar18 == 0x3b9d006a) {
              *(uint32_t *)((long)__s + lVar3) = 8;
              uVar14 = 0x3b9d006a;
              goto LAB_00140768;
            }
            goto LAB_00140d98;
          }
          *(uint32_t *)((long)__s + lVar3) = 0x20;
          *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9cf89b;
          *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
          *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
          *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
          *(uint64_t *)((long)__s + lVar19 + 0x18) = *(uint64_t *)(piVar17 + 7);
          *(int *)((long)__s + lVar19 + 0x20) = piVar17[9];
          *(int *)((long)__s + lVar19 + 0x24) = piVar17[10];
          iVar6 = iVar6 + 0x28;
        }
        else if (iVar18 == 0x3b9d3eea) {
          *(uint32_t *)((long)__s + lVar3) = 0x60;
          *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9d3eea;
          *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
          *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
          *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
          *(int *)((long)__s + lVar19 + 0x18) = piVar17[7];
          *(int *)((long)__s + lVar19 + 0x1c) = piVar17[8];
          *(int *)((long)__s + lVar19 + 0x20) = piVar17[9];
          *(int *)((long)__s + lVar19 + 0x24) = piVar17[10];
          *(int *)((long)__s + lVar19 + 0x28) = piVar17[0xb];
          *(int *)((long)__s + lVar19 + 0x2c) = piVar17[0xc];
          *(int *)((long)__s + lVar19 + 0x30) = piVar17[0xd];
          *(int *)((long)__s + lVar19 + 0x34) = piVar17[0xe];
          *(int *)((long)__s + lVar19 + 0x38) = piVar17[0xf];
          *(int *)((long)__s + lVar19 + 0x3c) = piVar17[0x10];
          *(int *)((long)__s + lVar19 + 0x40) = piVar17[0x11];
          *(int *)((long)__s + lVar19 + 0x44) = piVar17[0x12];
          *(int *)((long)__s + lVar19 + 0x48) = piVar17[0x13];
          *(int *)((long)__s + lVar19 + 0x4c) = piVar17[0x14];
          *(int *)((long)__s + lVar19 + 0x50) = piVar17[0x15];
          *(int *)((long)__s + lVar19 + 0x54) = piVar17[0x16];
          *(int *)((long)__s + lVar19 + 0x58) = piVar17[0x17];
          *(int *)((long)__s + lVar19 + 0x5c) = piVar17[0x18];
          *(int *)((long)__s + lVar19 + 0x60) = piVar17[0x19];
          *(int *)((long)__s + lVar19 + 100) = piVar17[0x1a];
          iVar6 = iVar6 + 0x68;
        }
        else {
          if (iVar18 != 0x3b9d5a40) goto LAB_00140d98;
          *(uint32_t *)((long)__s + lVar3) = 0x10;
          *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9d5a40;
          *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
          *(uint64_t *)((long)__s + lVar19 + 0x10) = *(uint64_t *)(piVar17 + 6);
          iVar6 = iVar6 + 0x18;
        }
      }
      else if (iVar18 < 0x3b9f0fc1) {
        if (iVar18 < 0x3b9df299) {
          if (iVar18 < 0x3b9dcb88) {
            if (iVar18 == 0x3b9db030) {
              *(uint32_t *)((long)__s + lVar3) = 8;
              *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9db030;
              iVar18 = piVar17[4];
LAB_00140770:
              *(int *)((long)__s + lVar19 + 0xc) = iVar18;
              iVar6 = iVar6 + 0x10;
            }
            else {
              if (iVar18 != 0x3b9dc7a0) goto LAB_00140d98;
              sVar8 = strlen((char *)(piVar17 + 5));
              sVar9 = strlen((char *)(piVar17 + 0x45));
              iVar18 = (int)sVar9 + (int)((sVar8 << 0x20) + 0x900000000 >> 0x20) + 5;
              *(int *)((long)__s + lVar3) = iVar18;
              piVar22 = (int *)((long)__s + lVar19 + 8);
              *piVar22 = *piVar17;
              piVar22[1] = piVar17[4];
              sVar8 = strlen((char *)(piVar17 + 5));
              iVar20 = (int)sVar8;
              piVar22[2] = iVar20 + 1;
              memcpy(piVar22 + 3,piVar17 + 5,(long)(iVar20 + 1));
              sVar8 = strlen((char *)(piVar17 + 0x45));
              iVar15 = (int)sVar8 + 1;
              *(int *)((long)piVar22 + (long)(iVar20 + 0xd)) = iVar15;
              memcpy((void *)((long)piVar22 + (long)(iVar20 + 0x11)),piVar17 + 0x45,(long)iVar15);
              puVar1 = (uint8_t *)((long)piVar22 + (long)iVar15 + (long)(iVar20 + 0x11));
              *puVar1 = (char)piVar17[0x85];
              puVar1[1] = *(uint8_t *)((long)piVar17 + 0x215);
              puVar1[2] = *(uint8_t *)((long)piVar17 + 0x216);
              puVar1[3] = *(uint8_t *)((long)piVar17 + 0x217);
LAB_00140384:
              iVar6 = iVar18 + iVar6 + 8;
            }
          }
          else if (iVar18 == 0x3b9dcb88) {
            *(uint32_t *)((long)__s + lVar3) = 0x48;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9dcb88;
            *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
            *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
            *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
            *(int *)((long)__s + lVar19 + 0x18) = piVar17[7];
            *(int *)((long)__s + lVar19 + 0x1c) = piVar17[8];
            *(int *)((long)__s + lVar19 + 0x20) = piVar17[9];
            *(int *)((long)__s + lVar19 + 0x24) = piVar17[10];
            *(int *)((long)__s + lVar19 + 0x28) = piVar17[0xb];
            *(int *)((long)__s + lVar19 + 0x2c) = piVar17[0xc];
            *(int *)((long)__s + lVar19 + 0x30) = piVar17[0xd];
            *(int *)((long)__s + lVar19 + 0x34) = piVar17[0xe];
            *(int *)((long)__s + lVar19 + 0x38) = piVar17[0xf];
            *(int *)((long)__s + lVar19 + 0x3c) = piVar17[0x10];
            *(int *)((long)__s + lVar19 + 0x40) = piVar17[0x11];
            *(int *)((long)__s + lVar19 + 0x44) = piVar17[0x12];
            *(int *)((long)__s + lVar19 + 0x48) = piVar17[0x13];
            *(int *)((long)__s + lVar19 + 0x4c) = piVar17[0x14];
            iVar6 = iVar6 + 0x50;
          }
          else {
            if (iVar18 != 0x3b9dd358) goto LAB_00140d98;
            *(uint32_t *)((long)__s + lVar3) = 0x14;
            uVar14 = 0x3b9dd358;
LAB_0013fea0:
            *(uint32_t *)((long)__s + lVar19 + 8) = uVar14;
            *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
            *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
            *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
            *(int *)((long)__s + lVar19 + 0x18) = piVar17[7];
            iVar6 = iVar6 + 0x1c;
          }
        }
        else if (iVar18 < 0x3b9eaa32) {
          if (iVar18 == 0x3b9df299) {
            *(uint32_t *)((long)__s + lVar3) = 0xc;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9df299;
LAB_001409b4:
            uVar7 = *(uint64_t *)(piVar17 + 4);
LAB_00140a1c:
            *(uint64_t *)((long)__s + lVar19 + 0xc) = uVar7;
            iVar6 = iVar6 + 0x14;
          }
          else {
            if (iVar18 == 0x3b9e38e8) {
              *(uint32_t *)((long)__s + lVar3) = 0x14;
              uVar14 = 0x3b9e38e8;
              goto LAB_0013fea0;
            }
LAB_00140d98:
            iVar6 = iVar6 + 8;
            *(uint32_t *)((long)__s + lVar3) = 0;
          }
        }
        else {
          if (iVar18 != 0x3b9eaa32) {
            if (iVar18 == 0x3b9ef081) {
              *(uint32_t *)((long)__s + lVar3) = 0xc;
              *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9ef081;
              goto LAB_001409b4;
            }
            goto LAB_00140d98;
          }
          *(uint32_t *)((long)__s + lVar3) = 0xc;
          *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9eaa32;
          iVar18 = piVar17[4];
LAB_00140c98:
          *(int *)((long)__s + lVar19 + 0xc) = iVar18;
          *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
          iVar6 = iVar6 + 0x14;
        }
      }
      else {
        if (0x3ba11748 < iVar18) {
          if (iVar18 < 0x3ba1d6b1) {
            if (iVar18 == 0x3ba11749) {
              *(uint32_t *)((long)__s + lVar3) = 0xc;
              *(uint32_t *)((long)__s + lVar19 + 8) = 0x3ba11749;
              uVar7 = *(uint64_t *)(piVar17 + 4);
              goto LAB_00140a1c;
            }
            if (iVar18 == 0x3ba1bb59) {
              *(uint32_t *)((long)__s + lVar3) = 8;
              uVar14 = 0x3ba1bb59;
              goto LAB_00140768;
            }
          }
          else {
            if (iVar18 == 0x3ba1d6b1) {
              *(uint32_t *)((long)__s + lVar3) = 0x14;
              *(uint32_t *)((long)__s + lVar19 + 8) = 0x3ba1d6b1;
              uVar7 = *(uint64_t *)(piVar17 + 4);
              *(uint64_t *)((long)__s + lVar19 + 0x14) = *(uint64_t *)(piVar17 + 6);
              *(uint64_t *)((long)__s + lVar19 + 0xc) = uVar7;
              iVar6 = iVar6 + 0x1c;
              goto LAB_0013fec8;
            }
            if (iVar18 == 0x3ba2ccc8) {
              *(uint32_t *)((long)__s + lVar3) = 0xc;
              uVar14 = 0x3ba2ccc8;
              goto LAB_001409a0;
            }
          }
          goto LAB_00140d98;
        }
        if (iVar18 < 0x3b9f2731) {
          if (iVar18 == 0x3b9f0fc1) {
            *(uint32_t *)((long)__s + lVar3) = 0x7c;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9f0fc1;
            *(int *)((long)__s + lVar19 + 0xc) = piVar17[4];
            *(int *)((long)__s + lVar19 + 0x10) = piVar17[5];
            *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
            *(int *)((long)__s + lVar19 + 0x18) = piVar17[7];
            *(int *)((long)__s + lVar19 + 0x1c) = piVar17[8];
            *(int *)((long)__s + lVar19 + 0x20) = piVar17[9];
            *(int *)((long)__s + lVar19 + 0x24) = piVar17[10];
            *(int *)((long)__s + lVar19 + 0x28) = piVar17[0xb];
            *(int *)((long)__s + lVar19 + 0x2c) = piVar17[0xc];
            *(int *)((long)__s + lVar19 + 0x30) = piVar17[0xd];
            *(int *)((long)__s + lVar19 + 0x34) = piVar17[0xe];
            *(int *)((long)__s + lVar19 + 0x38) = piVar17[0xf];
            *(int *)((long)__s + lVar19 + 0x3c) = piVar17[0x10];
            *(int *)((long)__s + lVar19 + 0x40) = piVar17[0x11];
            *(int *)((long)__s + lVar19 + 0x44) = piVar17[0x12];
            *(int *)((long)__s + lVar19 + 0x48) = piVar17[0x13];
            *(int *)((long)__s + lVar19 + 0x4c) = piVar17[0x14];
            *(int *)((long)__s + lVar19 + 0x50) = piVar17[0x15];
            *(int *)((long)__s + lVar19 + 0x54) = piVar17[0x16];
            *(int *)((long)__s + lVar19 + 0x58) = piVar17[0x17];
            *(int *)((long)__s + lVar19 + 0x5c) = piVar17[0x18];
            *(int *)((long)__s + lVar19 + 0x60) = piVar17[0x19];
            *(int *)((long)__s + lVar19 + 100) = piVar17[0x1a];
            *(int *)((long)__s + lVar19 + 0x68) = piVar17[0x1b];
            *(int *)((long)__s + lVar19 + 0x6c) = piVar17[0x1c];
            *(int *)((long)__s + lVar19 + 0x70) = piVar17[0x1d];
            *(int *)((long)__s + lVar19 + 0x74) = piVar17[0x1e];
            *(int *)((long)__s + lVar19 + 0x78) = piVar17[0x1f];
            *(int *)((long)__s + lVar19 + 0x7c) = piVar17[0x20];
            *(int *)((long)__s + lVar19 + 0x80) = piVar17[0x21];
            iVar6 = iVar6 + 0x84;
          }
          else {
            if (iVar18 != 0x3b9f13a9) goto LAB_00140d98;
            *(uint32_t *)((long)__s + lVar3) = 0x1c;
            *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9f13a9;
            *(uint64_t *)((long)__s + lVar19 + 0xc) = *(uint64_t *)(piVar17 + 4);
            *(int *)((long)__s + lVar19 + 0x14) = piVar17[6];
            *(uint64_t *)((long)__s + lVar19 + 0x18) = *(uint64_t *)(piVar17 + 8);
            *(int *)((long)__s + lVar19 + 0x20) = piVar17[10];
            iVar6 = iVar6 + 0x24;
          }
        }
        else {
          if (iVar18 != 0x3b9f2731) {
            if (iVar18 == 0x3b9f2b19) {
              *(uint32_t *)((long)__s + lVar3) = 8;
              uVar14 = 0x3b9f2b19;
LAB_00140768:
              *(uint32_t *)((long)__s + lVar19 + 8) = uVar14;
              iVar18 = piVar17[4];
              goto LAB_00140770;
            }
            goto LAB_00140d98;
          }
          *(uint32_t *)((long)__s + lVar3) = 0x14;
          *(uint32_t *)((long)__s + lVar19 + 8) = 0x3b9f2731;
          *(uint64_t *)((long)__s + lVar19 + 0xc) = *(uint64_t *)(piVar17 + 4);
          *(uint64_t *)((long)__s + lVar19 + 0x14) = *(uint64_t *)(piVar17 + 6);
          iVar6 = iVar6 + 0x1c;
        }
      }
LAB_0013fec8:
      *(int **)(piVar17 + 2) = piVar23;
      piVar17 = piVar23;
    } while (piVar23 != (int *)0x0);
  }
  *(uint32_t *)((long)__s + (long)iVar6) = 0xffffffff;
  FUN_0012e900(&local_3b0,(uint32_t *)((long)__s + (long)iVar6) + 1);
  __strlen_chk(auStack_39c,0x324);
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  local_78 = 0;
  iStack_74 = iVar10;
  uVar12 = RingBuffer_write(uVar7,&local_78,8);
  if (((uVar12 & 1) != 0) && (0 < iVar10)) {
    RingBuffer_write(uVar7,__s,iVar10);
  }
  if (*(long *)(lVar5 + 0x28) == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0012ed50  size=520 */

/* WARNING: Type propagation algorithm not settling */

void vt_handle_vkGetPhysicalDeviceQueueFamilyProperties(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar4;
  long lVar5;
  long lVar6;
  uint64_t uVar7;
  uint8_t *__s;
  char *pcVar8;
  unsigned long uVar9;
  uint32_t *puVar10;
  uint32_t *puVar11;
  unsigned long unaff_x20;
  void *__ptr;
  uint32_t local_54 [3];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar5 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar9 = 1;
    lVar6 = param_1;
  }
  else {
    uVar9 = 9;
    lVar6 = *(long *)(pcVar8 + 1);
  }
  if (*(int *)(pcVar8 + uVar9) < 1) {
    uVar7 = VkObject_fromId(lVar6);
  }
  else {
    uVar4 = *(uint32_t *)(pcVar8 + (uVar9 | 4));
    unaff_x20 = (unsigned long)uVar4;
    local_54[0] = uVar4;
    uVar7 = VkObject_fromId(lVar6);
    if (uVar4 == 0) {
      __ptr = (void *)0x0;
      goto LAB_0012eddc;
    }
  }
  __ptr = calloc(unaff_x20 & 0xffffffff,0x18);
LAB_0012eddc:
  ((generic_fn_t)DAT_00193b10)(uVar7,local_54,__ptr);
  iVar2 = local_54[0] * 0x1c + 0xd;
  if ((int)local_54[0] < 1 || __ptr == (void *)0x0) {
    iVar2 = 0xd;
  }
  iVar3 = iVar2 + *(int *)(param_1 + 0x48);
  if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar3;
  }
  else {
    __s = malloc((long)iVar2);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar2);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 4;
  uVar9 = (unsigned long)local_54[0];
  *(uint32_t *)(__s + 5) = local_54[0];
  if (__ptr == (void *)0x0) {
    *(uint32_t *)(__s + 9) = 0;
  }
  else {
    *(uint32_t *)(__s + 9) = local_54[0];
    if (0 < (int)local_54[0]) {
      puVar10 = (uint32_t *)(__s + 0x15);
      puVar11 = (uint32_t *)((long)__ptr + 0xc);
      do {
        puVar10[-2] = 0x18;
        uVar9 = uVar9 - 1;
        puVar10[-1] = puVar11[-3];
        *puVar10 = puVar11[-2];
        puVar10[1] = puVar11[-1];
        puVar10[2] = *puVar11;
        puVar10[3] = puVar11[1];
        puVar1 = puVar11 + 2;
        puVar11 = puVar11 + 6;
        puVar10[4] = *puVar1;
        puVar10 = puVar10 + 7;
      } while (uVar9 != 0);
    }
  }
  uVar7 = *(uint64_t *)(param_1 + 0x68);
  local_54[1] = 0;
  local_54[2] = iVar2;
  uVar9 = RingBuffer_write(uVar7,local_54 + 1,8);
  if (((uVar9 & 1) != 0) && (0 < iVar2)) {
    RingBuffer_write(uVar7,__s,iVar2);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (*(long *)(lVar5 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00141968  size=980 */

/* WARNING: Removing unreachable block (ram,0x00141b8c) */
/* WARNING: Removing unreachable block (ram,0x00141b98) */
/* WARNING: Removing unreachable block (ram,0x00141ba4) */
/* WARNING: Removing unreachable block (ram,0x00141bf0) */
/* WARNING: Type propagation algorithm not settling */

void vt_handle_vkGetPhysicalDeviceQueueFamilyProperties2(long param_1)

{
  uint32_t *puVar1;
  char *pcVar2;
  uint32_t uVar3;
  long lVar4;
  long lVar5;
  uint64_t uVar6;
  void *__ptr;
  uint8_t *puVar7;
  char *pcVar8;
  uint32_t uVar9;
  unsigned long uVar10;
  uint32_t *puVar11;
  uint32_t *puVar12;
  int iVar13;
  uint32_t unaff_w20;
  uint32_t local_54 [3];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    uVar10 = 1;
    lVar5 = param_1;
  }
  else {
    uVar10 = 9;
    lVar5 = *(long *)(pcVar8 + 1);
  }
  if (0 < *(int *)(pcVar8 + uVar10)) {
    local_54[0] = *(uint32_t *)(pcVar8 + (uVar10 | 4));
    unaff_w20 = local_54[0];
  }
  uVar6 = VkObject_fromId(lVar5);
  if ((unaff_w20 == 0) || (__ptr = calloc((unsigned long)unaff_w20,0x28), __ptr == (void *)0x0)) {
    ((generic_fn_t)DAT_00193f98)(uVar6,local_54,0);
    iVar13 = *(int *)(param_1 + 0x48) + 0xd;
    if ((iVar13 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar7 = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar13;
    }
    else {
      puVar7 = malloc(0xd);
      ArrayList_add(param_1 + 0x50,puVar7);
    }
    memset(puVar7,0,0xd);
    *puVar7 = 0;
    *(uint32_t *)(puVar7 + 1) = 4;
    *(uint32_t *)(puVar7 + 5) = local_54[0];
    *(uint32_t *)(puVar7 + 9) = 0;
    uVar6 = *(uint64_t *)(param_1 + 0x68);
    local_54[1] = 0;
    local_54[2] = 0xd;
    uVar10 = RingBuffer_write(uVar6,local_54 + 1,8);
    if ((uVar10 & 1) != 0) {
      RingBuffer_write(uVar6,puVar7,0xd);
    }
  }
  else {
    pcVar8 = *(char **)(param_1 + 0x30);
    uVar9 = 9;
    if (*pcVar8 == '\0') {
      uVar9 = 1;
    }
    lVar5 = (unsigned long)(uVar9 | 4) +
            (unsigned long)(*(uint32_t *)(pcVar8 + uVar9) &
                   ((int)*(uint32_t *)(pcVar8 + uVar9) >> 0x1f ^ 0xffffffffU));
    uVar10 = (unsigned long)*(uint32_t *)(pcVar8 + lVar5);
    if (0 < (int)*(uint32_t *)(pcVar8 + lVar5)) {
      iVar13 = (int)lVar5 + 4;
      puVar11 = (uint32_t *)((long)__ptr + 0x14);
      do {
        lVar5 = (long)iVar13 + 4;
        pcVar2 = pcVar8 + lVar5;
        uVar3 = *(uint32_t *)pcVar2;
        iVar13 = *(int *)(pcVar8 + iVar13);
        *(uint64_t *)(puVar11 + -3) = 0;
        uVar10 = uVar10 - 1;
        puVar11[-5] = uVar3;
        iVar13 = iVar13 + (int)lVar5;
        puVar11[-1] = *(uint32_t *)(pcVar2 + 4);
        *puVar11 = *(uint32_t *)(pcVar2 + 8);
        puVar11[1] = *(uint32_t *)(pcVar2 + 0xc);
        puVar11[2] = *(uint32_t *)(pcVar2 + 0x10);
        puVar11[3] = *(uint32_t *)(pcVar2 + 0x14);
        puVar11[4] = *(uint32_t *)(pcVar2 + 0x18);
        puVar11 = puVar11 + 10;
      } while (uVar10 != 0);
    }
    ((generic_fn_t)DAT_00193f98)(uVar6,local_54,__ptr);
    uVar9 = local_54[0] << 5 | 0xd;
    if ((int)local_54[0] < 1) {
      uVar9 = 0xd;
    }
    iVar13 = uVar9 + *(int *)(param_1 + 0x48);
    if ((iVar13 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar7 = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar13;
    }
    else {
      puVar7 = malloc((long)(int)uVar9);
      ArrayList_add(param_1 + 0x50,puVar7);
    }
    memset(puVar7,0,(long)(int)uVar9);
    *puVar7 = 0;
    *(uint32_t *)(puVar7 + 1) = 4;
    uVar10 = (unsigned long)local_54[0];
    *(uint32_t *)(puVar7 + 5) = local_54[0];
    *(uint32_t *)(puVar7 + 9) = local_54[0];
    if (0 < (int)local_54[0]) {
      puVar11 = (uint32_t *)(puVar7 + 0x15);
      puVar12 = (uint32_t *)((long)__ptr + 0x14);
      do {
        puVar11[-2] = 0x1c;
        uVar10 = uVar10 - 1;
        puVar11[-1] = puVar12[-5];
        *puVar11 = puVar12[-1];
        puVar11[1] = *puVar12;
        puVar11[2] = puVar12[1];
        puVar11[3] = puVar12[2];
        puVar11[4] = puVar12[3];
        puVar1 = puVar12 + 4;
        puVar12 = puVar12 + 10;
        puVar11[5] = *puVar1;
        puVar11 = puVar11 + 8;
      } while (uVar10 != 0);
    }
    uVar6 = *(uint64_t *)(param_1 + 0x68);
    local_54[1] = 0;
    local_54[2] = uVar9;
    uVar10 = RingBuffer_write(uVar6,local_54 + 1,8);
    if (((uVar10 & 1) != 0) && (0 < (int)uVar9)) {
      RingBuffer_write(uVar6,puVar7,uVar9);
    }
    free(__ptr);
  }
  if (*(long *)(lVar4 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00131c94  size=604 */

/* WARNING: Type propagation algorithm not settling */

void vt_handle_vkGetPhysicalDeviceSparseImageFormatProperties(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  long lVar11;
  long lVar12;
  uint64_t uVar13;
  uint8_t *__s;
  char *pcVar14;
  unsigned long uVar15;
  uint32_t *puVar16;
  uint32_t *puVar17;
  unsigned long unaff_x20;
  void *__ptr;
  uint32_t local_74 [3];
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar11 + 0x28);
  pcVar14 = *(char **)(param_1 + 0x30);
  if (*pcVar14 == '\0') {
    uVar15 = 1;
    lVar12 = param_1;
  }
  else {
    uVar15 = 9;
    lVar12 = *(long *)(pcVar14 + 1);
  }
  pcVar4 = pcVar14 + uVar15;
  uVar7 = *(uint32_t *)pcVar4;
  uVar10 = *(uint32_t *)(pcVar14 + (uVar15 | 4));
  uVar5 = *(uint32_t *)(pcVar4 + 8);
  uVar6 = *(uint32_t *)(pcVar4 + 0xc);
  uVar8 = *(uint32_t *)(pcVar4 + 0x10);
  if (*(int *)(pcVar14 + (uVar15 | 0x14)) < 1) {
    uVar13 = VkObject_fromId(lVar12);
  }
  else {
    uVar9 = *(uint32_t *)(pcVar14 + uVar15 + 0x18);
    unaff_x20 = (unsigned long)uVar9;
    local_74[0] = uVar9;
    uVar13 = VkObject_fromId(lVar12);
    if (uVar9 == 0) {
      __ptr = (void *)0x0;
      goto LAB_00131d4c;
    }
  }
  __ptr = calloc(unaff_x20 & 0xffffffff,0x14);
LAB_00131d4c:
  ((generic_fn_t)DAT_00193be0)(uVar13,uVar7,uVar10,uVar5,uVar6,uVar8,local_74,__ptr);
  iVar2 = local_74[0] * 0x18 + 0x21;
  if ((int)local_74[0] < 1 || __ptr == (void *)0x0) {
    iVar2 = 0x21;
  }
  iVar3 = iVar2 + *(int *)(param_1 + 0x48);
  if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar3;
  }
  else {
    __s = malloc((long)iVar2);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar2);
  *__s = 0;
  *(uint32_t *)(__s + 1) = uVar7;
  uVar15 = (unsigned long)local_74[0];
  *(uint32_t *)(__s + 5) = uVar10;
  *(uint32_t *)(__s + 9) = uVar5;
  *(uint32_t *)(__s + 0xd) = uVar6;
  *(uint32_t *)(__s + 0x11) = uVar8;
  *(uint32_t *)(__s + 0x15) = 4;
  *(uint32_t *)(__s + 0x19) = local_74[0];
  if (__ptr == (void *)0x0) {
    *(uint32_t *)(__s + 0x1d) = 0;
  }
  else {
    *(uint32_t *)(__s + 0x1d) = local_74[0];
    if (0 < (int)local_74[0]) {
      puVar17 = (uint32_t *)((long)__ptr + 8);
      puVar16 = (uint32_t *)(__s + 0x35);
      do {
        puVar16[-5] = 0x14;
        uVar15 = uVar15 - 1;
        puVar16[-4] = puVar17[-2];
        puVar16[-3] = puVar17[-1];
        puVar16[-2] = *puVar17;
        puVar16[-1] = puVar17[1];
        puVar1 = puVar17 + 2;
        puVar17 = puVar17 + 5;
        *puVar16 = *puVar1;
        puVar16 = puVar16 + 6;
      } while (uVar15 != 0);
    }
  }
  uVar13 = *(uint64_t *)(param_1 + 0x68);
  local_74[1] = 0;
  local_74[2] = iVar2;
  uVar15 = RingBuffer_write(uVar13,local_74 + 1,8);
  if (((uVar15 & 1) != 0) && (0 < iVar2)) {
    RingBuffer_write(uVar13,__s,iVar2);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (*(long *)(lVar11 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00142164  size=1060 */

/* WARNING: Removing unreachable block (ram,0x001423f4) */
/* WARNING: Removing unreachable block (ram,0x00142400) */
/* WARNING: Removing unreachable block (ram,0x0014240c) */
/* WARNING: Removing unreachable block (ram,0x00142448) */

void vt_handle_vkGetPhysicalDeviceSparseImageFormatProperties2(long param_1)

{
  int iVar1;
  uint32_t *puVar2;
  char *pcVar3;
  uint32_t uVar4;
  long lVar5;
  long lVar6;
  uint64_t uVar7;
  void *__ptr;
  uint8_t *puVar8;
  char *pcVar9;
  uint32_t uVar10;
  unsigned long uVar11;
  unsigned long uVar12;
  uint32_t *puVar13;
  uint32_t *puVar14;
  int iVar15;
  uint32_t unaff_w20;
  uint32_t local_84;
  unsigned long local_80 [6];
  uint32_t local_50;
  int iStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar5 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_80[4] = 0;
  local_80[0] = 0;
  local_80[3] = 0;
  local_80[2] = 0;
  if (*pcVar9 == '\0') {
    uVar11 = 1;
    lVar6 = param_1;
  }
  else {
    uVar11 = 9;
    lVar6 = *(long *)(pcVar9 + 1);
  }
  uVar12 = uVar11 | 4;
  if (0 < *(int *)(pcVar9 + uVar11)) {
    puVar2 = (uint32_t *)(pcVar9 + uVar12);
    uVar12 = (unsigned long)(uint32_t)((int)uVar12 + *(int *)(pcVar9 + uVar11));
    local_80[0] = (unsigned long)*puVar2;
    local_80[2] = *(unsigned long *)(puVar2 + 1);
    local_80[3] = *(unsigned long *)(puVar2 + 3);
    local_80[4] = (unsigned long)puVar2[5];
  }
  local_80[1] = 0;
  if (0 < *(int *)(pcVar9 + (int)uVar12)) {
    local_84 = *(uint32_t *)(pcVar9 + (long)(int)uVar12 + 4);
    unaff_w20 = local_84;
  }
  uVar7 = VkObject_fromId(lVar6);
  if ((unaff_w20 == 0) || (__ptr = calloc((unsigned long)unaff_w20,0x28), __ptr == (void *)0x0)) {
    ((generic_fn_t)DAT_00193fa8)(uVar7,local_80,&local_84,0);
    iVar15 = *(int *)(param_1 + 0x48) + 0x11;
    if ((iVar15 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar8 = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar15;
    }
    else {
      puVar8 = malloc(0x11);
      ArrayList_add(param_1 + 0x50,puVar8);
    }
    memset(puVar8,0,0x11);
    *puVar8 = 0;
    *(uint64_t *)(puVar8 + 1) = 0x400000000;
    *(uint32_t *)(puVar8 + 9) = local_84;
    *(uint32_t *)(puVar8 + 0xd) = 0;
    uVar7 = *(uint64_t *)(param_1 + 0x68);
    local_50 = 0;
    iStack_4c = 0x11;
    uVar11 = RingBuffer_write(uVar7,&local_50,8);
    if ((uVar11 & 1) != 0) {
      RingBuffer_write(uVar7,puVar8,0x11);
    }
  }
  else {
    pcVar9 = *(char **)(param_1 + 0x30);
    uVar10 = 9;
    if (*pcVar9 == '\0') {
      uVar10 = 1;
    }
    lVar6 = (unsigned long)(uVar10 | 4) +
            (unsigned long)(*(uint32_t *)(pcVar9 + uVar10) &
                   ((int)*(uint32_t *)(pcVar9 + uVar10) >> 0x1f ^ 0xffffffffU));
    lVar6 = (unsigned long)((int)lVar6 + 4) +
            (unsigned long)(*(uint32_t *)(pcVar9 + lVar6) &
                   ((int)*(uint32_t *)(pcVar9 + lVar6) >> 0x1f ^ 0xffffffffU));
    uVar11 = (unsigned long)*(uint32_t *)(pcVar9 + lVar6);
    if (0 < (int)*(uint32_t *)(pcVar9 + lVar6)) {
      iVar15 = (int)lVar6 + 4;
      puVar13 = (uint32_t *)((long)__ptr + 0x20);
      do {
        lVar6 = (long)iVar15 + 4;
        pcVar3 = pcVar9 + lVar6;
        uVar4 = *(uint32_t *)pcVar3;
        iVar15 = *(int *)(pcVar9 + iVar15);
        *(uint64_t *)(puVar13 + -6) = 0;
        uVar11 = uVar11 - 1;
        puVar13[-8] = uVar4;
        iVar15 = iVar15 + (int)lVar6;
        puVar13[-4] = *(uint32_t *)(pcVar3 + 4);
        puVar13[-3] = *(uint32_t *)(pcVar3 + 8);
        puVar13[-2] = *(uint32_t *)(pcVar3 + 0xc);
        puVar13[-1] = *(uint32_t *)(pcVar3 + 0x10);
        *puVar13 = *(uint32_t *)(pcVar3 + 0x14);
        puVar13 = puVar13 + 10;
      } while (uVar11 != 0);
    }
    ((generic_fn_t)DAT_00193fa8)(uVar7,local_80,&local_84,__ptr);
    iVar15 = local_84 * 0x1c + 0x11;
    if ((int)local_84 < 1) {
      iVar15 = 0x11;
    }
    iVar1 = iVar15 + *(int *)(param_1 + 0x48);
    if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      puVar8 = (uint8_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar1;
    }
    else {
      puVar8 = malloc((long)iVar15);
      ArrayList_add(param_1 + 0x50,puVar8);
    }
    memset(puVar8,0,(long)iVar15);
    *puVar8 = 0;
    uVar11 = (unsigned long)local_84;
    *(uint64_t *)(puVar8 + 1) = 0x400000000;
    *(uint32_t *)(puVar8 + 9) = local_84;
    *(uint32_t *)(puVar8 + 0xd) = local_84;
    if (0 < (int)local_84) {
      puVar13 = (uint32_t *)(puVar8 + 0x29);
      puVar14 = (uint32_t *)((long)__ptr + 0x20);
      do {
        puVar13[-6] = 0x18;
        uVar11 = uVar11 - 1;
        puVar13[-5] = puVar14[-8];
        puVar13[-4] = puVar14[-4];
        puVar13[-3] = puVar14[-3];
        puVar13[-2] = puVar14[-2];
        puVar13[-1] = puVar14[-1];
        *puVar13 = *puVar14;
        puVar13 = puVar13 + 7;
        puVar14 = puVar14 + 10;
      } while (uVar11 != 0);
    }
    uVar7 = *(uint64_t *)(param_1 + 0x68);
    local_50 = 0;
    iStack_4c = iVar15;
    uVar11 = RingBuffer_write(uVar7,&local_50,8);
    if (((uVar11 & 1) != 0) && (0 < iVar15)) {
      RingBuffer_write(uVar7,puVar8,iVar15);
    }
    free(__ptr);
  }
  if (*(long *)(lVar5 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013b70c  size=332 */

void vt_handle_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(long param_1,unsigned long param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  unsigned long uVar5;
  char *pcVar6;
  uint32_t uVar7;
  uint64_t uVar8;
  int local_68;
  int iStack_64;
  uint64_t local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  if (pcVar6[uVar7] != '\0') {
    param_2 = (unsigned long)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 1);
  }
  getWindowExtent(param_1 + 0xd0,param_2,&local_68);
  iVar3 = getSurfaceMinImageCount();
  iVar1 = *(int *)(param_1 + 0x48);
  if ((iVar1 < 0xffcc) && (*(long *)(param_1 + 0x40) != 0)) {
    piVar4 = (int *)(*(long *)(param_1 + 0x40) + (long)iVar1);
    *(int *)(param_1 + 0x48) = iVar1 + 0x34;
  }
  else {
    piVar4 = malloc(0x34);
    ArrayList_add(param_1 + 0x50,piVar4);
  }
  piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[0] = 0;
  piVar4[1] = 0;
  piVar4[6] = 0;
  piVar4[7] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  piVar4[0xc] = 0;
  *piVar4 = iVar3;
  piVar4[1] = (uint32_t)(iVar3 == 1) << 1;
  piVar4[2] = local_68;
  piVar4[3] = iStack_64;
  piVar4[4] = local_68;
  piVar4[5] = iStack_64;
  piVar4[6] = local_68;
  piVar4[7] = iStack_64;
  piVar4[0xc] = 0x9f;
  piVar4[10] = 1;
  piVar4[0xb] = 10;
  piVar4[8] = 1;
  piVar4[9] = 1;
  uVar8 = *(uint64_t *)(param_1 + 0x68);
  local_60 = 0x3400000000;
  uVar5 = RingBuffer_write(uVar8,&local_60,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar8,piVar4,0x34);
  }
  if (*(long *)(lVar2 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013b858  size=612 */

/* WARNING: Type propagation algorithm not settling */

void vt_handle_vkGetPhysicalDeviceSurfaceFormatsKHR(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  uint16_t *__ptr;
  uint16_t *__s;
  char *pcVar6;
  unsigned long uVar7;
  long lVar8;
  uint32_t uVar9;
  unsigned long uVar10;
  uint32_t *puVar11;
  unsigned long uVar12;
  uint32_t *puVar13;
  unsigned long uVar14;
  uint64_t uVar15;
  uint32_t uVar16;
  uint32_t uVar17;
  uint32_t uVar18;
  uint32_t uVar19;
  uint32_t uVar20;
  uint32_t uVar21;
  uint32_t uVar22;
  uint32_t uVar23;
  uint32_t uVar24;
  uint32_t uVar25;
  uint32_t uVar26;
  uint32_t uVar27;
  uint32_t uVar28;
  uint32_t uVar29;
  uint32_t uVar30;
  uint32_t uVar31;
  uint32_t local_54 [3];
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar5 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  uVar2 = uVar9;
  if (*pcVar6 == '\0') {
    uVar2 = 1;
  }
  if (pcVar6[uVar2] == '\0') {
    uVar9 = 1;
  }
  uVar7 = (unsigned long)uVar9 + (unsigned long)uVar2;
  if ((*(int *)(pcVar6 + uVar7) < 1) ||
     (local_54[0] = *(uint32_t *)(pcVar6 + (uVar7 | 4)), local_54[0] != 0)) {
    __ptr = (uint16_t *)getSurfaceFormats(local_54);
    if (local_54[0] == 0) goto LAB_0013b8e0;
  }
  else {
    __ptr = (uint16_t *)0x0;
LAB_0013b8e0:
    getSurfaceFormats(local_54);
  }
  iVar3 = *(int *)(param_1 + 0x48);
  iVar4 = local_54[0] * 0xc + 0xe;
  if ((int)local_54[0] < 1 || __ptr == (uint16_t *)0x0) {
    iVar4 = 0xe;
  }
  iVar1 = iVar4 + iVar3;
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    *(int *)(param_1 + 0x48) = iVar1;
    __s = (uint16_t *)(*(long *)(param_1 + 0x40) + (long)iVar3);
  }
  else {
    __s = malloc((long)iVar4);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar4);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 4;
  uVar7 = (unsigned long)local_54[0];
  *(uint32_t *)(__s + 3) = local_54[0];
  if (__ptr == (uint16_t *)0x0) {
    *(uint32_t *)(__s + 5) = 0;
  }
  else {
    *(uint32_t *)(__s + 5) = local_54[0];
    if (0 < (int)local_54[0]) {
      if ((local_54[0] < 8) || ((__s + 7 < __ptr + uVar7 * 4 && (__ptr < __s + uVar7 * 6 + 7)))) {
        uVar10 = 0;
        uVar12 = 0xe;
      }
      else {
        uVar10 = uVar7 & 0xfffffff8;
        puVar11 = (uint32_t *)(__ptr + 0x10);
        uVar12 = (uVar10 * 3 >> 3) << 5 | 0xe;
        uVar14 = uVar7 & 0xfffffff8;
        puVar13 = (uint32_t *)(__s + 0x1f);
        do {
          uVar16 = *puVar11;
          uVar20 = puVar11[1];
          uVar17 = puVar11[2];
          uVar21 = puVar11[3];
          uVar18 = puVar11[4];
          uVar22 = puVar11[5];
          uVar19 = puVar11[6];
          uVar23 = puVar11[7];
          uVar24 = puVar11[-8];
          uVar28 = puVar11[-7];
          uVar25 = puVar11[-6];
          uVar29 = puVar11[-5];
          uVar26 = puVar11[-4];
          uVar30 = puVar11[-3];
          uVar27 = puVar11[-2];
          uVar31 = puVar11[-1];
          puVar11 = puVar11 + 0x10;
          uVar14 = uVar14 - 8;
          *puVar13 = 8;
          puVar13[1] = uVar16;
          puVar13[2] = uVar20;
          puVar13[3] = 8;
          puVar13[4] = uVar17;
          puVar13[5] = uVar21;
          puVar13[6] = 8;
          puVar13[7] = uVar18;
          puVar13[8] = uVar22;
          puVar13[9] = 8;
          puVar13[10] = uVar19;
          puVar13[0xb] = uVar23;
          puVar13[-0xc] = 8;
          puVar13[-0xb] = uVar24;
          puVar13[-10] = uVar28;
          puVar13[-9] = 8;
          puVar13[-8] = uVar25;
          puVar13[-7] = uVar29;
          puVar13[-6] = 8;
          puVar13[-5] = uVar26;
          puVar13[-4] = uVar30;
          puVar13[-3] = 8;
          puVar13[-2] = uVar27;
          puVar13[-1] = uVar31;
          puVar13 = puVar13 + 0x18;
        } while (uVar14 != 0);
        if (uVar10 == uVar7) goto LAB_0013b9f4;
      }
      lVar8 = uVar7 - uVar10;
      puVar11 = (uint32_t *)((long)__s + uVar12 + 8);
      puVar13 = (uint32_t *)(__ptr + uVar10 * 4 + 2);
      do {
        puVar11[-2] = 8;
        lVar8 = lVar8 + -1;
        puVar11[-1] = puVar13[-1];
        *puVar11 = *puVar13;
        puVar11 = puVar11 + 3;
        puVar13 = puVar13 + 2;
      } while (lVar8 != 0);
    }
  }
LAB_0013b9f4:
  uVar15 = *(uint64_t *)(param_1 + 0x68);
  local_54[1] = 0;
  local_54[2] = iVar4;
  uVar7 = RingBuffer_write(uVar15,local_54 + 1,8);
  if (((uVar7 & 1) != 0) && (0 < iVar4)) {
    RingBuffer_write(uVar15,__s,iVar4);
  }
  if (__ptr != (uint16_t *)0x0) {
    free(__ptr);
  }
  if (*(long *)(lVar5 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013babc  size=404 */

void vt_handle_vkGetPhysicalDeviceSurfacePresentModesKHR(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  long lVar3;
  bool bVar4;
  uint16_t *__s;
  unsigned long uVar5;
  char *pcVar6;
  uint32_t uVar7;
  uint64_t uVar8;
  int iVar9;
  uint8_t *__src;
  int iVar10;
  uint32_t local_60;
  int iStack_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar3 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  uVar2 = uVar7;
  if (*pcVar6 == '\0') {
    uVar2 = 1;
  }
  if (pcVar6[uVar2] == '\0') {
    uVar7 = 1;
  }
  uVar5 = (unsigned long)uVar7 + (unsigned long)uVar2;
  if (*(int *)(pcVar6 + uVar5) < 1) {
    __src = &DAT_0011f420;
  }
  else {
    iVar10 = *(int *)(pcVar6 + (uVar5 | 4));
    if (iVar10 != 0) {
      bVar4 = false;
      iVar9 = iVar10 * 4 + 0xe;
      __src = &DAT_0011f420;
      goto LAB_0013bb60;
    }
    __src = (uint8_t *)0x0;
  }
  iVar9 = 0xe;
  bVar4 = true;
  iVar10 = 4;
LAB_0013bb60:
  iVar1 = *(int *)(param_1 + 0x48) + iVar9;
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint16_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s = malloc((long)iVar9);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar9);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 4;
  *(int *)(__s + 3) = iVar10;
  if (bVar4) {
    *(uint32_t *)(__s + 5) = 0;
  }
  else {
    *(int *)(__s + 5) = iVar10;
    memcpy(__s + 7,__src,(long)(iVar10 << 2));
  }
  uVar8 = *(uint64_t *)(param_1 + 0x68);
  local_60 = 0;
  iStack_5c = iVar9;
  uVar5 = RingBuffer_write(uVar8,&local_60,8);
  if (((uVar5 & 1) != 0) && (0 < iVar9)) {
    RingBuffer_write(uVar8,__s,iVar9);
  }
  if (*(long *)(lVar3 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00134f1c  size=580 */

void vt_handle_vkGetPipelineCacheData(long param_1)

{
  long lVar1;
  bool bVar2;
  uint32_t uVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  void *__s;
  uint16_t *__s_00;
  char *pcVar7;
  long lVar8;
  unsigned long uVar9;
  uint64_t unaff_x20;
  int iVar10;
  int iVar11;
  size_t unaff_x23;
  size_t local_68;
  uint32_t local_60;
  int iStack_5c;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar1 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  if (*pcVar7 == '\0') {
    lVar8 = 1;
    lVar4 = param_1;
  }
  else {
    lVar8 = 9;
    lVar4 = *(long *)(pcVar7 + 1);
  }
  uVar9 = lVar8 + 1;
  if (pcVar7[lVar8] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar7 + uVar9);
    uVar9 = (unsigned long)((int)lVar8 + 9);
  }
  if (0 < *(int *)(pcVar7 + uVar9)) {
    unaff_x23 = *(size_t *)(pcVar7 + uVar9 + 4);
    local_68 = unaff_x23;
  }
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x20);
  if (unaff_x23 == 0) {
    uVar3 = ((generic_fn_t)DAT_00193cd8)(uVar5,uVar6,&local_68,0);
    __s = (void *)0x0;
  }
  else {
    iVar11 = (int)unaff_x23;
    iVar10 = *(int *)(param_1 + 0x48) + iVar11;
    if ((iVar10 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar10;
    }
    else {
      __s = malloc((long)iVar11);
      ArrayList_add(param_1 + 0x50,__s);
    }
    memset(__s,0,(long)iVar11);
    uVar3 = ((generic_fn_t)DAT_00193cd8)(uVar5,uVar6,&local_68,__s);
    if (__s != (void *)0x0) {
      bVar2 = false;
      iVar10 = (int)local_68 + 0x12;
      goto LAB_00135070;
    }
  }
  iVar10 = 0x12;
  bVar2 = true;
LAB_00135070:
  iVar11 = *(int *)(param_1 + 0x48) + iVar10;
  if ((iVar11 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s_00 = (uint16_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar11;
  }
  else {
    __s_00 = malloc((long)iVar10);
    ArrayList_add(param_1 + 0x50,__s_00);
  }
  memset(__s_00,0,(long)iVar10);
  *__s_00 = 0;
  *(uint32_t *)(__s_00 + 1) = 8;
  *(size_t *)(__s_00 + 3) = local_68;
  if (bVar2) {
    *(uint32_t *)(__s_00 + 7) = 0;
  }
  else {
    *(int *)(__s_00 + 7) = (int)local_68;
    memcpy(__s_00 + 9,__s,local_68);
  }
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  local_60 = uVar3;
  iStack_5c = iVar10;
  uVar9 = RingBuffer_write(uVar5,&local_60,8);
  if (((uVar9 & 1) != 0) && (0 < iVar10)) {
    RingBuffer_write(uVar5,__s_00,iVar10);
  }
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00133c7c  size=596 */

void vt_handle_vkGetQueryPoolResults(long param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  long lVar7;
  uint32_t uVar8;
  long lVar9;
  uint64_t uVar10;
  uint64_t uVar11;
  void *__s;
  uint16_t *__s_00;
  char *pcVar12;
  long lVar13;
  unsigned long uVar14;
  int iVar15;
  size_t __n;
  uint64_t unaff_x25;
  uint64_t uVar16;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar7 + 0x28);
  pcVar12 = *(char **)(param_1 + 0x30);
  if (*pcVar12 == '\0') {
    lVar13 = 1;
    lVar9 = param_1;
  }
  else {
    lVar13 = 9;
    lVar9 = *(long *)(pcVar12 + 1);
  }
  uVar14 = lVar13 + 1;
  if (pcVar12[lVar13] != '\0') {
    unaff_x25 = *(uint64_t *)(pcVar12 + uVar14);
    uVar14 = (unsigned long)((int)lVar13 + 9);
  }
  pcVar1 = pcVar12 + uVar14;
  uVar4 = *(uint32_t *)pcVar1;
  uVar5 = *(uint32_t *)(pcVar1 + 4);
  __n = *(size_t *)(pcVar1 + 8);
  uVar14 = (unsigned long)((int)uVar14 + 0x14) +
           (unsigned long)(*(uint32_t *)(pcVar1 + 0x10) & ((int)*(uint32_t *)(pcVar1 + 0x10) >> 0x1f ^ 0xffffffffU))
  ;
  uVar16 = *(uint64_t *)(pcVar12 + uVar14);
  uVar6 = *(uint32_t *)(pcVar12 + (uVar14 & 0xffffffff) + 8);
  uVar10 = VkObject_fromId(lVar9);
  uVar11 = VkObject_fromId(unaff_x25);
  iVar15 = (int)__n;
  iVar2 = *(int *)(param_1 + 0x48) + iVar15;
  if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar2;
  }
  else {
    __s = malloc((long)iVar15);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar15);
  uVar8 = ((generic_fn_t)DAT_00193c60)(uVar10,uVar11,uVar4,uVar5,__n,__s,uVar16,uVar6);
  iVar2 = 0x22;
  if (__s != (void *)0x0) {
    iVar2 = iVar15 + 0x22;
  }
  iVar3 = *(int *)(param_1 + 0x48) + iVar2;
  if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s_00 = (uint16_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar3;
  }
  else {
    __s_00 = malloc((long)iVar2);
    ArrayList_add(param_1 + 0x50,__s_00);
  }
  memset(__s_00,0,(long)iVar2);
  *__s_00 = 0;
  *(uint32_t *)(__s_00 + 1) = uVar4;
  *(uint32_t *)(__s_00 + 3) = uVar5;
  *(size_t *)(__s_00 + 5) = __n;
  if (__s == (void *)0x0) {
    iVar15 = 0x16;
    *(uint32_t *)(__s_00 + 9) = 0;
  }
  else {
    *(int *)(__s_00 + 9) = iVar15;
    memcpy(__s_00 + 0xb,__s,__n);
    iVar15 = iVar15 + 0x16;
  }
  *(uint64_t *)((long)__s_00 + (long)iVar15) = uVar16;
  *(uint32_t *)((uint64_t *)((long)__s_00 + (long)iVar15) + 1) = uVar6;
  uVar10 = *(uint64_t *)(param_1 + 0x68);
  local_70 = uVar8;
  iStack_6c = iVar2;
  uVar14 = RingBuffer_write(uVar10,&local_70,8);
  if (((uVar14 & 1) != 0) && (0 < iVar2)) {
    RingBuffer_write(uVar10,__s_00,iVar2);
  }
  if (*(long *)(lVar7 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00137c54  size=312 */

void vt_handle_vkGetRenderAreaGranularity(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t *puVar7;
  unsigned long uVar8;
  char *pcVar9;
  long lVar10;
  uint64_t unaff_x20;
  uint64_t local_48;
  uint64_t local_40;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar3 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    lVar10 = 1;
    cVar1 = pcVar9[1];
    lVar4 = param_1;
  }
  else {
    lVar4 = *(long *)(pcVar9 + 1);
    lVar10 = 9;
    cVar1 = pcVar9[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar9 + lVar10 + 1);
  }
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x20);
  local_48 = 0;
  ((generic_fn_t)DAT_00193d80)(uVar5,uVar6,&local_48);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 < 0xfff8) && (*(long *)(param_1 + 0x40) != 0)) {
    puVar7 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar2);
    *(int *)(param_1 + 0x48) = iVar2 + 8;
  }
  else {
    puVar7 = malloc(8);
    ArrayList_add(param_1 + 0x50,puVar7);
  }
  *puVar7 = 0;
  *(uint32_t *)puVar7 = (uint32_t)local_48;
  *(uint32_t *)((long)puVar7 + 4) = (*(uint32_t*)((char*)&local_48 + 4));
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  local_40 = 0x800000000;
  uVar8 = RingBuffer_write(uVar5,&local_40,8);
  if ((uVar8 & 1) != 0) {
    RingBuffer_write(uVar5,puVar7,8);
  }
  if (*(long *)(lVar3 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00147c38  size=224 */

void vt_handle_vkGetSemaphoreCounterValue(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  unsigned long uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint64_t local_50;
  uint64_t uStack_48;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
    cVar1 = pcVar6[1];
    lVar3 = param_1;
  }
  else {
    lVar3 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
    cVar1 = pcVar6[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar6 + lVar7 + 1);
  }
  uVar4 = VkObject_fromId(lVar3);
  uStack_48 = VkObject_fromId(unaff_x20);
  local_50 = 0;
  local_40 = ((generic_fn_t)DAT_001940d8)(uVar4,uStack_48,&local_50);
  uVar4 = *(uint64_t *)(param_1 + 0x68);
  uStack_3c = 8;
  uVar5 = RingBuffer_write(uVar4,&local_40,8);
  if ((uVar5 & 1) != 0) {
    RingBuffer_write(uVar4,&uStack_48,8);
  }
  if (*(long *)(lVar2 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00142c04  size=304 */

void vt_handle_vkGetSemaphoreFdKHR(int *param_1)

{
  long lVar1;
  uint64_t uVar2;
  char *pcVar3;
  unsigned long uVar4;
  uint64_t unaff_x20;
  uint32_t local_138;
  int local_134;
  unsigned long local_130 [3];
  uint64_t local_118;
  struct msghdr local_110;
  struct iovec local_d8;
  uint64_t local_c8;
  uint64_t local_c0;
  int local_b8;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar1 + 0x28);
  pcVar3 = *(char **)(param_1 + 0xc);
  local_130[1] = 0;
  local_130[0] = 0;
  local_118 = 0;
  local_130[2] = 0;
  if (*pcVar3 == '\0') {
    uVar4 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar3 + 1);
    uVar4 = 9;
  }
  if (0 < *(int *)(pcVar3 + uVar4)) {
    local_130[1] = 0;
    local_130[0] = (unsigned long)*(uint32_t *)(pcVar3 + (uVar4 | 4));
    local_130[2] = VkObject_fromId(*(uint64_t *)((long)(pcVar3 + (uVar4 | 4)) + 4));
  }
  uVar2 = VkObject_fromId(unaff_x20);
  local_118 = ((uint64_t)((*(uint32_t*)((char*)&local_118 + 4))) << 32 | (uint32_t)(0x10));
  local_138 = ((generic_fn_t)DAT_00193fd8)(uVar2,local_130,&local_134);
  local_d8.iov_base = &local_138;
  local_d8.iov_len = 4;
  local_110.msg_control = &local_c8;
  local_110.msg_controllen = 0x14;
  local_110.msg_iov = &local_d8;
  local_110.msg_name = (void *)0x0;
  local_110.msg_namelen = 0;
  local_110.msg_iovlen = 1;
  local_c8 = 0x14;
  local_110.msg_flags = 0;
  local_c0 = 0x100000001;
  local_b8 = local_134;
  sendmsg(*param_1,&local_110,0);
  if (0 < local_134) {
    local_134 = close(local_134);
  }
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_134);
}


/* @0014b804  size=600 */

void vt_handle_vkGetShaderModuleCreateInfoIdentifierEXT(long param_1)

{
  int iVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  int iVar4;
  long lVar5;
  void *__s;
  uint64_t uVar6;
  uint32_t *__s_00;
  unsigned long uVar7;
  long lVar8;
  uint64_t unaff_x20;
  size_t __size;
  char *pcVar9;
  unsigned long local_e0 [4];
  void *local_c0;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t local_a0;
  uint64_t uStack_98;
  uint64_t uStack_90;
  uint64_t uStack_88;
  uint64_t local_80;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar5 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  local_c0 = (void *)0x0;
  local_e0[1] = 0;
  local_e0[0] = 0;
  local_e0[3] = 0;
  local_e0[2] = 0;
  local_80 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  if (*pcVar9 == '\0') {
    uVar7 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar9 + 1);
    uVar7 = 9;
  }
  iVar4 = *(int *)(pcVar9 + uVar7);
  uVar7 = uVar7 | 4;
  if (0 < iVar4) {
    puVar2 = (uint32_t *)(pcVar9 + uVar7);
    local_e0[1] = 0;
    local_e0[0] = (unsigned long)*puVar2;
    local_e0[2] = (unsigned long)puVar2[1];
    local_e0[3] = *(unsigned long *)(puVar2 + 2);
    __size = (size_t)(int)puVar2[4];
    iVar1 = *(int *)(param_1 + 0x48) + puVar2[4];
    if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      __s = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar1;
    }
    else {
      __s = malloc(__size);
      ArrayList_add(param_1 + 0x50,__s);
    }
    memset(__s,0,__size);
    memcpy(__s,puVar2 + 5,__size);
    uVar7 = (unsigned long)(uint32_t)((int)uVar7 + iVar4);
    local_c0 = __s;
  }
  lVar8 = (long)(int)uVar7;
  if (0 < *(int *)(pcVar9 + lVar8)) {
    uStack_a8 = 0;
    local_b0 = ((uint64_t)((*(uint32_t*)((char*)&local_b0 + 4))) << 32 | (uint32_t)(*(uint32_t *)(pcVar9 + lVar8 + 4)));
    uVar3 = *(uint32_t *)(pcVar9 + lVar8 + 8);
    local_a0 = ((uint64_t)((*(uint32_t*)((char*)&local_a0 + 4))) << 32 | (uint32_t)(uVar3));
    if (uVar3 < 0x21) {
      __memcpy_chk((long)&local_a0 + 4,pcVar9 + lVar8 + 0xc,uVar3,0x24);
    }
  }
  uVar6 = VkObject_fromId(unaff_x20);
  ((generic_fn_t)DAT_001942f8)(uVar6,local_e0,&local_b0);
  iVar4 = (uint32_t)local_a0 + 8;
  iVar1 = *(int *)(param_1 + 0x48) + iVar4;
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s_00 = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s_00 = malloc((long)iVar4);
    ArrayList_add(param_1 + 0x50,__s_00);
  }
  memset(__s_00,0,(long)iVar4);
  *__s_00 = (uint32_t)local_b0;
  __s_00[1] = (uint32_t)local_a0;
  if ((uint32_t)local_a0 < 0x21) {
    memcpy(__s_00 + 2,(void *)((long)&local_a0 + 4),local_a0 & 0xffffffff);
  }
  uVar6 = *(uint64_t *)(param_1 + 0x68);
  local_70 = 0;
  iStack_6c = iVar4;
  uVar7 = RingBuffer_write(uVar6,&local_70,8);
  if (((uVar7 & 1) != 0) && (0 < iVar4)) {
    RingBuffer_write(uVar6,__s_00,iVar4);
  }
  if (*(long *)(lVar5 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0014b638  size=460 */

void vt_handle_vkGetShaderModuleIdentifierEXT(long param_1)

{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  uint32_t *__s;
  char *pcVar7;
  long lVar8;
  unsigned long uVar9;
  uint64_t unaff_x20;
  uint64_t unaff_x21;
  unsigned long local_90 [2];
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t uStack_70;
  uint64_t uStack_68;
  uint64_t local_60;
  uint32_t local_50;
  int iStack_4c;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar4 + 0x28);
  pcVar7 = *(char **)(param_1 + 0x30);
  local_60 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  local_90[1] = 0;
  local_90[0] = 0;
  if (*pcVar7 == '\0') {
    lVar8 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar7 + 1);
    lVar8 = 9;
  }
  uVar9 = lVar8 + 1;
  if (pcVar7[lVar8] != '\0') {
    unaff_x21 = *(uint64_t *)(pcVar7 + uVar9);
    uVar9 = (unsigned long)((int)lVar8 + 9);
  }
  if (0 < *(int *)(pcVar7 + uVar9)) {
    local_90[1] = 0;
    local_90[0] = (unsigned long)*(uint32_t *)(pcVar7 + uVar9 + 4);
    uVar3 = *(uint32_t *)(pcVar7 + uVar9 + 8);
    local_80 = (unsigned long)uVar3;
    if (uVar3 < 0x21) {
      __memcpy_chk((long)&local_80 + 4,pcVar7 + uVar9 + 0xc,uVar3,0x24);
    }
  }
  uVar5 = VkObject_fromId(unaff_x20);
  puVar6 = (uint64_t *)VkObject_fromId(unaff_x21);
  ((generic_fn_t)DAT_001942f0)(uVar5,*puVar6,local_90);
  iVar1 = (uint32_t)local_80 + 8;
  iVar2 = *(int *)(param_1 + 0x48) + iVar1;
  if ((iVar2 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint32_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar2;
  }
  else {
    __s = malloc((long)iVar1);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar1);
  *__s = (uint32_t)local_90[0];
  __s[1] = (uint32_t)local_80;
  if ((uint32_t)local_80 < 0x21) {
    memcpy(__s + 2,(void *)((long)&local_80 + 4),local_80 & 0xffffffff);
  }
  uVar5 = *(uint64_t *)(param_1 + 0x68);
  local_50 = 0;
  iStack_4c = iVar1;
  uVar9 = RingBuffer_write(uVar5,&local_50,8);
  if (((uVar9 & 1) != 0) && (0 < iVar1)) {
    RingBuffer_write(uVar5,__s,iVar1);
  }
  if (*(long *)(lVar4 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013c188  size=632 */

void vt_handle_vkGetSwapchainImagesKHR(long param_1)

{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  long lVar4;
  uint64_t *puVar5;
  bool bVar6;
  long lVar7;
  uint64_t *__ptr;
  uint16_t *__s;
  char *pcVar8;
  long lVar9;
  unsigned long uVar10;
  uint64_t *puVar11;
  unsigned long uVar12;
  unsigned long uVar13;
  uint64_t *puVar14;
  uint64_t *puVar15;
  unsigned long uVar16;
  uint64_t uVar17;
  uint64_t unaff_x20;
  uint32_t uVar18;
  uint64_t uVar19;
  uint64_t uVar20;
  uint32_t local_70;
  int iStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar4 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar9 = 1;
    lVar7 = param_1;
  }
  else {
    lVar9 = 9;
    lVar7 = *(long *)(pcVar8 + 1);
  }
  uVar12 = lVar9 + 1;
  if (pcVar8[lVar9] != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar8 + uVar12);
    uVar12 = (unsigned long)((int)lVar9 + 9);
  }
  if (*(int *)(pcVar8 + uVar12) < 1) {
    uVar18 = 0;
  }
  else {
    uVar18 = *(uint32_t *)(pcVar8 + uVar12 + 4);
  }
  VkObject_fromId(lVar7);
  lVar7 = VkObject_fromId(unaff_x20);
  if (uVar18 == 0) {
    puVar11 = (uint64_t *)0x0;
LAB_0013c27c:
    uVar18 = *(uint32_t *)(lVar7 + 0x10);
    __ptr = (uint64_t *)0x0;
    bVar6 = true;
  }
  else {
    __ptr = calloc((long)*(int *)(lVar7 + 0x10),0x38);
    puVar11 = __ptr;
    if (__ptr == (uint64_t *)0x0) goto LAB_0013c27c;
    uVar3 = *(uint32_t *)(lVar7 + 0x10);
    if (0 < (int)uVar3) {
      lVar9 = 0;
      puVar14 = __ptr;
      do {
        puVar15 = (uint64_t *)(*(long *)(lVar7 + 8) + lVar9);
        lVar9 = lVar9 + 0x10;
        *puVar14 = *puVar15;
        puVar14 = puVar14 + 1;
      } while ((unsigned long)uVar3 * 0x10 - lVar9 != 0);
    }
    bVar6 = false;
  }
  iVar2 = 0xe;
  if (uVar18 != 0 && puVar11 != (uint64_t *)0x0) {
    iVar2 = uVar18 * 8 + 0xe;
  }
  iVar1 = iVar2 + *(int *)(param_1 + 0x48);
  if ((iVar1 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
    __s = (uint16_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    __s = malloc((long)iVar2);
    ArrayList_add(param_1 + 0x50,__s);
  }
  memset(__s,0,(long)iVar2);
  *__s = 0;
  *(uint32_t *)(__s + 1) = 4;
  *(uint32_t *)(__s + 3) = uVar18;
  if (puVar11 == (uint64_t *)0x0) {
    *(uint32_t *)(__s + 5) = 0;
  }
  else {
    *(uint32_t *)(__s + 5) = uVar18;
    if (uVar18 != 0) {
      uVar12 = (unsigned long)uVar18;
      if (uVar18 < 4) {
        uVar10 = 0;
        uVar13 = 0xe;
      }
      else {
        uVar10 = uVar12 & 0xfffffffc;
        puVar14 = puVar11 + 2;
        puVar15 = (uint64_t *)(__s + 0xf);
        uVar13 = (uVar10 >> 2) << 5 | 0xe;
        uVar16 = uVar12 & 0xfffffffc;
        do {
          puVar5 = puVar14 + -1;
          uVar17 = puVar14[-2];
          uVar20 = puVar14[1];
          uVar19 = *puVar14;
          puVar14 = puVar14 + 4;
          uVar16 = uVar16 - 4;
          puVar15[-1] = *puVar5;
          puVar15[-2] = uVar17;
          puVar15[1] = uVar20;
          *puVar15 = uVar19;
          puVar15 = puVar15 + 4;
        } while (uVar16 != 0);
        if (uVar10 == uVar12) goto LAB_0013c38c;
      }
      lVar7 = uVar12 - uVar10;
      puVar11 = puVar11 + uVar10;
      puVar14 = (uint64_t *)((long)__s + uVar13);
      do {
        lVar7 = lVar7 + -1;
        *puVar14 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar14 = puVar14 + 1;
      } while (lVar7 != 0);
    }
  }
LAB_0013c38c:
  uVar17 = *(uint64_t *)(param_1 + 0x68);
  local_70 = 0;
  iStack_6c = iVar2;
  uVar12 = RingBuffer_write(uVar17,&local_70,8);
  if (((uVar12 & 1) != 0) && (0 < iVar2)) {
    RingBuffer_write(uVar17,__s,iVar2);
  }
  if (!bVar6) {
    free(__ptr);
  }
  if (*(long *)(lVar4 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00131344  size=380 */

void vt_handle_vkInvalidateMappedMemoryRanges(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char cVar4;
  long lVar5;
  uint32_t uVar6;
  int iVar7;
  char *pcVar8;
  long lVar9;
  unsigned long uVar10;
  long *plVar11;
  uint64_t auStack_90;
  uint64_t local_88;
  long local_80;
  uint8_t *local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  local_80 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_80 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar9 = 1;
    lVar5 = param_1;
  }
  else {
    lVar9 = 9;
    lVar5 = *(long *)(pcVar8 + 1);
  }
  uVar3 = *(uint32_t *)(pcVar8 + lVar9);
  local_88 = VkObject_fromId(lVar5);
  lVar5 = -((unsigned long)uVar3 * 0x28 + 0xf & 0x7ffffffff0);
  local_78 = auStack_90 + lVar5;
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar6 = 9;
  if (*pcVar8 == '\0') {
    uVar6 = 1;
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar6 + 4);
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)uVar6 + 4)) {
    iVar7 = uVar6 + 8;
    plVar11 = (long *)((long)&local_80 + lVar5);
    do {
      lVar5 = (long)iVar7 + 4;
      pcVar1 = pcVar8 + lVar5;
      uVar2 = *(uint32_t *)pcVar1;
      iVar7 = *(int *)(pcVar8 + iVar7);
      plVar11[-1] = 0;
      cVar4 = vortekSerializerCastVkObject;
      *(uint32_t *)(plVar11 + -2) = uVar2;
      lVar9 = VkObject_fromId(*(uint64_t *)(pcVar1 + 4));
      if (cVar4 != '\0') {
        lVar9 = *(long *)(lVar9 + 0x18);
      }
      *plVar11 = lVar9;
      uVar10 = uVar10 - 1;
      plVar11[1] = *(long *)(pcVar1 + 0xc);
      iVar7 = iVar7 + (int)lVar5;
      plVar11[2] = *(long *)(pcVar1 + 0x14);
      plVar11 = plVar11 + 5;
    } while (uVar10 != 0);
  }
  local_70 = ((generic_fn_t)DAT_00193ba8)(local_88,(unsigned long)uVar3,local_78);
  uStack_6c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_70,8);
  if (*(long *)(local_80 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001310e8  size=192 */

void vt_handle_vkMapMemory(int *param_1)

{
  long lVar1;
  int *piVar2;
  uint32_t local_114;
  struct msghdr local_110;
  struct iovec local_d8;
  uint64_t local_c8;
  uint64_t local_c0;
  int local_b8;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar1 + 0x28);
  piVar2 = (int *)VkObject_fromId(**(uint64_t **)(param_1 + 0xc));
  local_d8.iov_base = &local_114;
  local_110.msg_iov = &local_d8;
  local_d8.iov_len = 4;
  local_110.msg_iovlen = 1;
  local_114 = 0xfffffffb;
  if (*piVar2 != -1) {
    local_114 = 0;
  }
  local_110.msg_control = &local_c8;
  local_110.msg_name = (void *)0x0;
  local_110.msg_namelen = 0;
  local_110.msg_flags = 0;
  local_110.msg_controllen = 0x14;
  local_c0 = 0x100000001;
  local_c8 = 0x14;
  local_b8 = *piVar2;
  sendmsg(*param_1,&local_110,0);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00135160  size=344 */

void vt_handle_vkMergePipelineCaches(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  long lVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t uVar9;
  long lVar10;
  unsigned long uVar11;
  unsigned long uVar12;
  uint64_t unaff_x22;
  uint64_t *puVar13;
  uint64_t *puVar14;
  uint64_t local_70;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar3 + 0x28);
  pcVar8 = *(char **)(param_1 + 0x30);
  if (*pcVar8 == '\0') {
    lVar10 = 1;
    lVar4 = param_1;
  }
  else {
    lVar10 = 9;
    lVar4 = *(long *)(pcVar8 + 1);
  }
  uVar12 = lVar10 + 1;
  if (pcVar8[lVar10] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar8 + uVar12);
    uVar12 = (unsigned long)((int)lVar10 + 9);
  }
  uVar2 = *(uint32_t *)(pcVar8 + uVar12);
  uVar5 = VkObject_fromId(lVar4);
  uVar6 = VkObject_fromId(unaff_x22);
  puVar13 = (uint64_t *)((long)&local_70 - ((unsigned long)uVar2 * 8 + 0xf & 0xffffffff0));
  pcVar8 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  uVar1 = uVar9;
  if (*pcVar8 == '\0') {
    uVar1 = 1;
  }
  if (pcVar8[uVar1] == '\0') {
    uVar9 = 1;
  }
  uVar11 = (unsigned long)(uVar9 + uVar1) | 4;
  uVar12 = (unsigned long)*(uint32_t *)(pcVar8 + uVar11);
  if (0 < (int)*(uint32_t *)(pcVar8 + uVar11)) {
    pcVar8 = pcVar8 + uVar11 + 4;
    puVar14 = puVar13;
    do {
      uVar7 = VkObject_fromId(*(uint64_t *)pcVar8);
      uVar12 = uVar12 - 1;
      *puVar14 = uVar7;
      pcVar8 = pcVar8 + 8;
      puVar14 = puVar14 + 1;
    } while (uVar12 != 0);
  }
  (*(uint32_t*)((char*)&local_70 + 0)) = ((generic_fn_t)DAT_00193ce0)(uVar5,uVar6,(unsigned long)uVar2,puVar13);
  (*(uint32_t*)((char*)&local_70 + 4)) = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_70,8);
  if (*(long *)(lVar3 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00131ef0  size=3404 */

void vt_handle_vkQueueBindSparse(long param_1)

{
  long *plVar1;
  char *pcVar2;
  uint32_t uVar3;
  int iVar4;
  char cVar5;
  long lVar6;
  uint64_t uVar7;
  long lVar8;
  void *pvVar9;
  uint32_t uVar10;
  char *pcVar11;
  unsigned long uVar12;
  int *piVar13;
  uint64_t *puVar14;
  int iVar15;
  unsigned long uVar16;
  uint64_t *puVar17;
  unsigned long uVar18;
  uint64_t unaff_x22;
  int iVar19;
  int iVar20;
  size_t sVar21;
  long *plVar22;
  uint8_t *puVar23;
  uint32_t *puVar24;
  uint64_t *puVar25;
  uint64_t auStack_100;
  uint64_t local_f8;
  uint64_t local_f0;
  long local_e8;
  unsigned long local_e0;
  char *local_d8;
  unsigned long local_d0;
  char *local_c8;
  int local_bc;
  long local_b8;
  void *local_b0;
  unsigned long local_a8;
  long local_a0;
  uint8_t *local_98;
  unsigned long local_90;
  long local_88;
  int *local_80;
  char *local_78;
  uint32_t local_70;
  uint32_t uStack_6c;
  long local_68;
  
  local_e8 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_e8 + 0x28);
  pcVar11 = *(char **)(param_1 + 0x30);
  if (*pcVar11 == '\0') {
    uVar16 = 1;
    lVar6 = param_1;
  }
  else {
    uVar16 = 9;
    lVar6 = *(long *)(pcVar11 + 1);
  }
  uVar12 = (unsigned long)*(uint32_t *)(pcVar11 + (uVar16 | 4));
  local_e0 = (unsigned long)*(uint32_t *)(pcVar11 + uVar16);
  iVar15 = (int)uVar16 + 8;
  if (0 < (int)*(uint32_t *)(pcVar11 + (uVar16 | 4))) {
    do {
      uVar12 = uVar12 - 1;
      iVar15 = iVar15 + *(int *)(pcVar11 + iVar15) + 4;
    } while (uVar12 != 0);
  }
  if (pcVar11[iVar15] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar11 + (long)iVar15 + 1);
  }
  local_88 = param_1;
  local_f0 = VkObject_fromId(lVar6);
  local_f8 = VkObject_fromId(unaff_x22);
  puVar23 = auStack_100 + local_e0 * -0x60;
  local_c8 = *(char **)(local_88 + 0x30);
  uVar10 = 9;
  if (*local_c8 == '\0') {
    uVar10 = 1;
  }
  local_d0 = (unsigned long)*(uint32_t *)(local_c8 + (unsigned long)uVar10 + 4);
  lVar6 = local_88;
  if ((int)*(uint32_t *)(local_c8 + (unsigned long)uVar10 + 4) < 1) {
LAB_00132bd0:
    local_70 = ((generic_fn_t)DAT_00193be8)(local_f0,local_e0,puVar23,local_f8);
    uStack_6c = 0;
    RingBuffer_write(*(uint64_t *)(lVar6 + 0x68),&local_70,8);
    if (*(long *)(local_e8 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  local_80 = (int *)(local_88 + 0x48);
  uVar16 = 0;
  iVar15 = uVar10 + 8;
  local_d8 = local_c8 + 8;
  local_98 = puVar23;
LAB_00132044:
  local_b8 = (long)iVar15 + 4;
  puVar25 = (uint64_t *)0x0;
  local_bc = *(int *)(local_c8 + iVar15);
  piVar13 = (int *)(local_c8 + local_b8 + 4);
  local_78 = local_c8 + local_b8;
  iVar15 = 8;
  *(uint32_t *)(puVar23 + uVar16 * 0x60) = *(uint32_t *)(local_c8 + local_b8);
  local_90 = uVar16;
  do {
    iVar19 = *piVar13;
    if (iVar19 == 0x3b9bb466) {
      uVar12 = (long)iVar15 + 4;
      iVar15 = *(int *)(local_78 + iVar15);
      if (0 < iVar15) {
        iVar19 = *local_80;
        if ((iVar19 < 0xffe8) && (*(long *)(lVar6 + 0x40) != 0)) {
          puVar14 = (uint64_t *)(*(long *)(lVar6 + 0x40) + (long)iVar19);
          *local_80 = iVar19 + 0x18;
        }
        else {
          puVar14 = malloc(0x18);
          ArrayList_add(lVar6 + 0x50,puVar14);
        }
        *puVar14 = 0;
        puVar14[1] = 0;
        puVar14[2] = 0;
        pcVar11 = local_78 + uVar12;
        uVar12 = (unsigned long)(uint32_t)(iVar15 + (int)uVar12);
        *(uint32_t *)puVar14 = *(uint32_t *)pcVar11;
        *(uint32_t *)(puVar14 + 2) = *(uint32_t *)(pcVar11 + 4);
        uVar3 = *(uint32_t *)(pcVar11 + 8);
        puVar14[1] = puVar25;
        *(uint32_t *)((long)puVar14 + 0x14) = uVar3;
        puVar25 = puVar14;
      }
    }
    else if (iVar19 == 0x3b9df29b) {
      uVar12 = (long)iVar15 + 4;
      iVar15 = *(int *)(local_78 + iVar15);
      if (0 < iVar15) {
        iVar19 = *local_80;
        if ((iVar19 < 0xffd0) && (*(long *)(lVar6 + 0x40) != 0)) {
          puVar14 = (uint64_t *)(*(long *)(lVar6 + 0x40) + (long)iVar19);
          *local_80 = iVar19 + 0x30;
        }
        else {
          puVar14 = malloc(0x30);
          ArrayList_add(lVar6 + 0x50,puVar14);
        }
        puVar14[3] = 0;
        puVar14[2] = 0;
        puVar14[5] = 0;
        puVar14[4] = 0;
        puVar14[1] = 0;
        *puVar14 = 0;
        pcVar11 = local_78 + uVar12;
        uVar3 = *(uint32_t *)pcVar11;
        puVar14[1] = 0;
        *(uint32_t *)puVar14 = uVar3;
        *(uint32_t *)(puVar14 + 2) = *(uint32_t *)(pcVar11 + 4);
        if (*(int *)(pcVar11 + 8) < 1) {
          iVar19 = 0xc;
          puVar14[3] = 0;
        }
        else {
          sVar21 = (long)*(int *)(pcVar11 + 8) << 3;
          iVar19 = (int)sVar21;
          iVar4 = *local_80 + iVar19;
          if ((iVar4 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
            pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
            *local_80 = iVar4;
            sVar21 = (size_t)iVar19;
          }
          else {
            pvVar9 = malloc(sVar21);
            ArrayList_add(lVar6 + 0x50,pvVar9);
          }
          memset(pvVar9,0,sVar21);
          if (pvVar9 != (void *)0x0) {
            memcpy(pvVar9,pcVar11 + 0xc,(long)iVar19);
          }
          iVar19 = iVar19 + 0xc;
          puVar14[3] = pvVar9;
        }
        *(uint32_t *)(puVar14 + 4) = *(uint32_t *)(pcVar11 + iVar19);
        iVar4 = *(int *)(pcVar11 + iVar19 + 4);
        if (iVar4 < 1) {
          puVar14[5] = 0;
        }
        else {
          sVar21 = (long)iVar4 << 3;
          iVar20 = (int)sVar21;
          iVar4 = *local_80 + iVar20;
          if ((iVar4 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
            pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
            *local_80 = iVar4;
            sVar21 = (size_t)iVar20;
          }
          else {
            pvVar9 = malloc(sVar21);
            ArrayList_add(lVar6 + 0x50,pvVar9);
          }
          memset(pvVar9,0,sVar21);
          if (pvVar9 != (void *)0x0) {
            memcpy(pvVar9,pcVar11 + (long)iVar19 + 8,(long)iVar20);
          }
          puVar14[5] = pvVar9;
        }
        uVar12 = (unsigned long)(uint32_t)(iVar15 + (int)uVar12);
        puVar14[1] = puVar25;
        puVar25 = puVar14;
        puVar23 = local_98;
        uVar16 = local_90;
      }
    }
    else {
      if (iVar19 == -1) break;
      uVar12 = (unsigned long)(iVar15 + 4);
    }
    piVar13 = (int *)(local_78 + (int)uVar12);
    iVar15 = (int)uVar12 + 4;
  } while( true );
  if (puVar25 == (uint64_t *)0x0) {
    puVar14 = (uint64_t *)0x0;
  }
  else {
    puVar17 = (uint64_t *)0x0;
    do {
      puVar14 = puVar25;
      puVar25 = (uint64_t *)puVar14[1];
      puVar14[1] = puVar17;
      puVar17 = puVar14;
    } while (puVar25 != (uint64_t *)0x0);
  }
  *(uint64_t **)(puVar23 + uVar16 * 0x60 + 8) = puVar14;
  iVar19 = iVar15 + 8;
  pcVar11 = local_78 + iVar15;
  *(uint32_t *)(puVar23 + uVar16 * 0x60 + 0x10) = *(uint32_t *)pcVar11;
  uVar10 = *(uint32_t *)(pcVar11 + 4);
  if ((int)uVar10 < 1) {
    *(uint64_t *)(puVar23 + uVar16 * 0x60 + 0x18) = 0;
  }
  else {
    iVar4 = uVar10 * 8;
    iVar15 = *local_80 + iVar4;
    if ((iVar15 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
      pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
      *local_80 = iVar15;
    }
    else {
      pvVar9 = malloc((long)iVar4);
      ArrayList_add(lVar6 + 0x50,pvVar9);
    }
    memset(pvVar9,0,(long)iVar4);
    pcVar11 = local_c8;
    uVar12 = 0;
    lVar8 = iVar19 + local_b8;
    do {
      if (pvVar9 != (void *)0x0) {
        uVar7 = VkObject_fromId(*(uint64_t *)(pcVar11 + uVar12 * 8 + lVar8));
        *(uint64_t *)((long)pvVar9 + uVar12 * 8) = uVar7;
      }
      lVar6 = local_88;
      uVar12 = uVar12 + 1;
      iVar19 = iVar19 + 8;
    } while (uVar10 != uVar12);
    *(void **)(puVar23 + uVar16 * 0x60 + 0x18) = pvVar9;
  }
  pcVar11 = local_78 + iVar19;
  iVar19 = iVar19 + 8;
  *(uint32_t *)(puVar23 + uVar16 * 0x60 + 0x20) = *(uint32_t *)pcVar11;
  uVar10 = *(uint32_t *)(pcVar11 + 4);
  uVar12 = (unsigned long)uVar10;
  if ((int)uVar10 < 1) {
    *(uint64_t *)(puVar23 + uVar16 * 0x60 + 0x28) = 0;
  }
  else {
    iVar4 = uVar10 * 0x18;
    iVar15 = *local_80 + iVar4;
    if ((iVar15 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
      pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
      *local_80 = iVar15;
    }
    else {
      pvVar9 = malloc((long)iVar4);
      ArrayList_add(lVar6 + 0x50,pvVar9);
    }
    memset(pvVar9,0,(long)iVar4);
    uVar16 = 0;
    local_b0 = pvVar9;
    local_a8 = uVar12;
    do {
      iVar15 = *(int *)(local_78 + iVar19);
      lVar8 = (long)iVar19 + 4;
      if (pvVar9 != (void *)0x0) {
        puVar25 = (uint64_t *)((long)pvVar9 + uVar16 * 0x18);
        pcVar11 = local_78 + lVar8;
        local_a0 = lVar8;
        uVar7 = VkObject_fromId(*(uint64_t *)pcVar11);
        *puVar25 = uVar7;
        *(uint32_t *)(puVar25 + 1) = *(uint32_t *)(pcVar11 + 8);
        uVar10 = *(uint32_t *)(pcVar11 + 0xc);
        uVar18 = (unsigned long)uVar10;
        if ((int)uVar10 < 1) {
          *(uint64_t *)((long)pvVar9 + uVar16 * 0x18 + 0x10) = 0;
          lVar8 = local_a0;
        }
        else {
          iVar4 = uVar10 * 0x28;
          iVar19 = *local_80 + iVar4;
          if ((iVar19 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
            pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
            *local_80 = iVar19;
          }
          else {
            pvVar9 = malloc((long)iVar4);
            ArrayList_add(lVar6 + 0x50,pvVar9);
          }
          memset(pvVar9,0,(long)iVar4);
          plVar22 = (long *)((long)pvVar9 + 0x10);
          iVar19 = 0x10;
          do {
            iVar4 = *(int *)(pcVar11 + iVar19);
            lVar6 = (long)iVar19 + 4;
            if (pvVar9 != (void *)0x0) {
              plVar1 = (long *)(pcVar11 + lVar6);
              plVar22[-2] = *plVar1;
              plVar22[-1] = plVar1[1];
              cVar5 = vortekSerializerCastVkObject;
              lVar8 = VkObject_fromId(plVar1[2]);
              if (cVar5 != '\0') {
                lVar8 = *(long *)(lVar8 + 0x18);
              }
              *plVar22 = lVar8;
              plVar22[1] = plVar1[3];
              *(int *)(plVar22 + 2) = (int)plVar1[4];
            }
            iVar19 = iVar4 + (int)lVar6;
            uVar18 = uVar18 - 1;
            plVar22 = plVar22 + 5;
          } while (uVar18 != 0);
          *(void **)((long)local_b0 + uVar16 * 0x18 + 0x10) = pvVar9;
          lVar8 = local_a0;
          lVar6 = local_88;
          uVar12 = local_a8;
          pvVar9 = local_b0;
        }
      }
      uVar16 = uVar16 + 1;
      iVar19 = iVar15 + (int)lVar8;
    } while (uVar16 != uVar12);
    *(void **)(local_98 + local_90 * 0x60 + 0x28) = pvVar9;
    puVar23 = local_98;
    uVar16 = local_90;
  }
  pcVar11 = local_78 + iVar19;
  iVar19 = iVar19 + 8;
  *(uint32_t *)(puVar23 + uVar16 * 0x60 + 0x30) = *(uint32_t *)pcVar11;
  uVar10 = *(uint32_t *)(pcVar11 + 4);
  uVar12 = (unsigned long)uVar10;
  if ((int)uVar10 < 1) {
    *(uint64_t *)(puVar23 + uVar16 * 0x60 + 0x38) = 0;
  }
  else {
    iVar4 = uVar10 * 0x18;
    iVar15 = *local_80 + iVar4;
    if ((iVar15 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
      pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
      *local_80 = iVar15;
    }
    else {
      pvVar9 = malloc((long)iVar4);
      ArrayList_add(lVar6 + 0x50,pvVar9);
    }
    memset(pvVar9,0,(long)iVar4);
    uVar16 = 0;
    local_b0 = pvVar9;
    local_a8 = uVar12;
    do {
      iVar15 = *(int *)(local_78 + iVar19);
      lVar8 = (long)iVar19 + 4;
      if (pvVar9 != (void *)0x0) {
        puVar25 = (uint64_t *)((long)pvVar9 + uVar16 * 0x18);
        pcVar11 = local_78 + lVar8;
        local_a0 = lVar8;
        uVar7 = VkObject_fromId(*(uint64_t *)pcVar11);
        *puVar25 = uVar7;
        *(uint32_t *)(puVar25 + 1) = *(uint32_t *)(pcVar11 + 8);
        uVar10 = *(uint32_t *)(pcVar11 + 0xc);
        uVar18 = (unsigned long)uVar10;
        if ((int)uVar10 < 1) {
          *(uint64_t *)((long)pvVar9 + uVar16 * 0x18 + 0x10) = 0;
          lVar8 = local_a0;
        }
        else {
          iVar4 = uVar10 * 0x28;
          iVar19 = *local_80 + iVar4;
          if ((iVar19 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
            pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
            *local_80 = iVar19;
          }
          else {
            pvVar9 = malloc((long)iVar4);
            ArrayList_add(lVar6 + 0x50,pvVar9);
          }
          memset(pvVar9,0,(long)iVar4);
          plVar22 = (long *)((long)pvVar9 + 0x10);
          iVar19 = 0x10;
          do {
            iVar4 = *(int *)(pcVar11 + iVar19);
            lVar6 = (long)iVar19 + 4;
            if (pvVar9 != (void *)0x0) {
              plVar1 = (long *)(pcVar11 + lVar6);
              plVar22[-2] = *plVar1;
              plVar22[-1] = plVar1[1];
              cVar5 = vortekSerializerCastVkObject;
              lVar8 = VkObject_fromId(plVar1[2]);
              if (cVar5 != '\0') {
                lVar8 = *(long *)(lVar8 + 0x18);
              }
              *plVar22 = lVar8;
              plVar22[1] = plVar1[3];
              *(int *)(plVar22 + 2) = (int)plVar1[4];
            }
            iVar19 = iVar4 + (int)lVar6;
            uVar18 = uVar18 - 1;
            plVar22 = plVar22 + 5;
          } while (uVar18 != 0);
          *(void **)((long)local_b0 + uVar16 * 0x18 + 0x10) = pvVar9;
          lVar8 = local_a0;
          lVar6 = local_88;
          uVar12 = local_a8;
          pvVar9 = local_b0;
        }
      }
      uVar16 = uVar16 + 1;
      iVar19 = iVar15 + (int)lVar8;
    } while (uVar16 != uVar12);
    *(void **)(local_98 + local_90 * 0x60 + 0x38) = pvVar9;
    puVar23 = local_98;
    uVar16 = local_90;
  }
  pcVar11 = local_78 + iVar19;
  iVar19 = iVar19 + 8;
  *(uint32_t *)(puVar23 + uVar16 * 0x60 + 0x40) = *(uint32_t *)pcVar11;
  uVar10 = *(uint32_t *)(pcVar11 + 4);
  uVar12 = (unsigned long)uVar10;
  if ((int)uVar10 < 1) {
    *(uint64_t *)(puVar23 + uVar16 * 0x60 + 0x48) = 0;
  }
  else {
    iVar4 = uVar10 * 0x18;
    iVar15 = *local_80 + iVar4;
    if ((iVar15 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
      pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
      *local_80 = iVar15;
    }
    else {
      pvVar9 = malloc((long)iVar4);
      ArrayList_add(lVar6 + 0x50,pvVar9);
    }
    memset(pvVar9,0,(long)iVar4);
    uVar18 = 0;
    local_b0 = pvVar9;
    local_a8 = uVar12;
    do {
      iVar15 = *(int *)(local_78 + iVar19);
      lVar8 = (long)iVar19 + 4;
      if (pvVar9 != (void *)0x0) {
        puVar25 = (uint64_t *)((long)pvVar9 + uVar18 * 0x18);
        pcVar11 = local_78 + lVar8;
        local_a0 = lVar8;
        uVar7 = VkObject_fromId(*(uint64_t *)pcVar11);
        lVar6 = local_88;
        *puVar25 = uVar7;
        *(uint32_t *)(puVar25 + 1) = *(uint32_t *)(pcVar11 + 8);
        uVar10 = *(uint32_t *)(pcVar11 + 0xc);
        uVar12 = (unsigned long)uVar10;
        if ((int)uVar10 < 1) {
          *(uint64_t *)((long)pvVar9 + uVar18 * 0x18 + 0x10) = 0;
          lVar8 = local_a0;
          uVar12 = local_a8;
        }
        else {
          iVar4 = uVar10 * 0x40;
          iVar19 = *local_80 + iVar4;
          if ((iVar19 < 0x10000) && (*(long *)(local_88 + 0x40) != 0)) {
            pvVar9 = (void *)(*(long *)(local_88 + 0x40) + (long)*local_80);
            *local_80 = iVar19;
          }
          else {
            pvVar9 = malloc((long)iVar4);
            ArrayList_add(lVar6 + 0x50,pvVar9);
          }
          memset(pvVar9,0,(long)iVar4);
          puVar24 = (uint32_t *)((long)pvVar9 + 0x1c);
          iVar19 = 0x10;
          do {
            iVar4 = *(int *)(pcVar11 + iVar19);
            lVar6 = (long)iVar19 + 4;
            if (pvVar9 != (void *)0x0) {
              pcVar2 = pcVar11 + lVar6;
              puVar24[-7] = *(uint32_t *)pcVar2;
              puVar24[-6] = *(uint32_t *)(pcVar2 + 4);
              puVar24[-5] = *(uint32_t *)(pcVar2 + 8);
              puVar24[-4] = *(uint32_t *)(pcVar2 + 0xc);
              puVar24[-3] = *(uint32_t *)(pcVar2 + 0x10);
              puVar24[-2] = *(uint32_t *)(pcVar2 + 0x14);
              puVar24[-1] = *(uint32_t *)(pcVar2 + 0x18);
              *puVar24 = *(uint32_t *)(pcVar2 + 0x1c);
              puVar24[1] = *(uint32_t *)(pcVar2 + 0x20);
              cVar5 = vortekSerializerCastVkObject;
              lVar8 = VkObject_fromId(*(uint64_t *)(pcVar2 + 0x24));
              if (cVar5 != '\0') {
                lVar8 = *(long *)(lVar8 + 0x18);
              }
              *(long *)(puVar24 + 3) = lVar8;
              *(uint64_t *)(puVar24 + 5) = *(uint64_t *)(pcVar2 + 0x2c);
              puVar24[7] = *(uint32_t *)(pcVar2 + 0x34);
            }
            iVar19 = iVar4 + (int)lVar6;
            uVar12 = uVar12 - 1;
            puVar24 = puVar24 + 0x10;
          } while (uVar12 != 0);
          *(void **)((long)local_b0 + uVar18 * 0x18 + 0x10) = pvVar9;
          lVar8 = local_a0;
          lVar6 = local_88;
          uVar12 = local_a8;
          pvVar9 = local_b0;
          puVar23 = local_98;
          uVar16 = local_90;
        }
      }
      uVar18 = uVar18 + 1;
      iVar19 = iVar15 + (int)lVar8;
    } while (uVar18 != uVar12);
    *(void **)(puVar23 + uVar16 * 0x60 + 0x48) = pvVar9;
  }
  pcVar11 = local_78 + iVar19;
  *(uint32_t *)(puVar23 + uVar16 * 0x60 + 0x50) = *(uint32_t *)pcVar11;
  uVar10 = *(uint32_t *)(pcVar11 + 4);
  if ((int)uVar10 < 1) {
    *(uint64_t *)(puVar23 + uVar16 * 0x60 + 0x58) = 0;
  }
  else {
    iVar4 = uVar10 * 8;
    iVar15 = *local_80 + iVar4;
    if ((iVar15 < 0x10000) && (*(long *)(lVar6 + 0x40) != 0)) {
      pvVar9 = (void *)(*(long *)(lVar6 + 0x40) + (long)*local_80);
      *local_80 = iVar15;
    }
    else {
      pvVar9 = malloc((long)iVar4);
      ArrayList_add(lVar6 + 0x50,pvVar9);
    }
    memset(pvVar9,0,(long)iVar4);
    pcVar11 = local_d8;
    uVar12 = 0;
    lVar8 = iVar19 + local_b8;
    do {
      if (pvVar9 != (void *)0x0) {
        uVar7 = VkObject_fromId(*(uint64_t *)(pcVar11 + uVar12 * 8 + lVar8));
        *(uint64_t *)((long)pvVar9 + uVar12 * 8) = uVar7;
        lVar6 = local_88;
      }
      uVar12 = uVar12 + 1;
    } while (uVar10 != uVar12);
    *(void **)(puVar23 + uVar16 * 0x60 + 0x58) = pvVar9;
  }
  uVar16 = uVar16 + 1;
  iVar15 = local_bc + (int)local_b8;
  if (uVar16 == local_d0) goto LAB_00132bd0;
  goto LAB_00132044;
}


/* @0013c53c  size=1068 */

void vt_handle_vkQueuePresentKHR(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint64_t *puVar6;
  uint64_t uVar7;
  uint64_t *puVar8;
  void *pvVar9;
  long lVar10;
  int *piVar11;
  unsigned long uVar12;
  int iVar13;
  int iVar14;
  size_t sVar15;
  long lVar16;
  uint64_t *puVar17;
  int iVar18;
  unsigned long uVar19;
  
  lVar16 = *(long *)(param_1 + 0x30);
  iVar18 = 8;
  piVar11 = (int *)(lVar16 + 4);
  puVar8 = (uint64_t *)0x0;
  do {
    if (*piVar11 == 0x3b9bb46b) {
      iVar14 = *(int *)(lVar16 + iVar18);
      uVar19 = (long)iVar18 + 4;
      if (iVar14 < 1) goto LAB_0013c584;
      iVar18 = *(int *)(param_1 + 0x48);
      if ((iVar18 < 0xffd8) && (*(long *)(param_1 + 0x40) != 0)) {
        puVar6 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar18);
        *(int *)(param_1 + 0x48) = iVar18 + 0x28;
      }
      else {
        puVar6 = malloc(0x28);
        ArrayList_add(param_1 + 0x50,puVar6);
      }
      puVar6[4] = 0;
      puVar6[1] = 0;
      *puVar6 = 0;
      puVar6[3] = 0;
      puVar6[2] = 0;
      puVar1 = (uint32_t *)(lVar16 + uVar19);
      uVar2 = *puVar1;
      uVar3 = puVar1[1];
      puVar6[1] = 0;
      *(uint32_t *)(puVar6 + 2) = uVar3;
      iVar18 = puVar1[2];
      *(uint32_t *)puVar6 = uVar2;
      if (iVar18 < 1) {
        lVar10 = 0xc;
        puVar6[3] = 0;
      }
      else {
        sVar15 = (long)iVar18 << 2;
        iVar13 = (int)sVar15;
        iVar18 = *(int *)(param_1 + 0x48) + iVar13;
        if ((iVar18 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar9 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          sVar15 = (size_t)iVar13;
          *(int *)(param_1 + 0x48) = iVar18;
        }
        else {
          pvVar9 = malloc(sVar15);
          ArrayList_add(param_1 + 0x50,pvVar9);
        }
        memset(pvVar9,0,sVar15);
        if (pvVar9 != (void *)0x0) {
          memcpy(pvVar9,puVar1 + 3,(long)iVar13);
        }
        puVar6[3] = pvVar9;
        lVar10 = (long)(iVar13 + 0xc);
      }
      uVar2 = *(uint32_t *)((long)puVar1 + lVar10);
      iVar18 = iVar14 + (int)uVar19;
      puVar6[1] = puVar8;
      *(uint32_t *)(puVar6 + 4) = uVar2;
    }
    else {
      if (*piVar11 == -1) {
        if (puVar8 != (uint64_t *)0x0) {
          puVar6 = (uint64_t *)0x0;
          do {
            puVar17 = (uint64_t *)puVar8[1];
            puVar8[1] = puVar6;
            puVar6 = puVar8;
            puVar8 = puVar17;
          } while (puVar17 != (uint64_t *)0x0);
        }
        uVar5 = *(uint32_t *)(lVar16 + iVar18 + 4);
        uVar19 = (unsigned long)uVar5;
        iVar18 = iVar18 + 8;
        if (0 < (int)uVar5) {
          iVar13 = uVar5 * 8;
          iVar14 = *(int *)(param_1 + 0x48) + iVar13;
          if ((iVar14 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar14;
          }
          else {
            puVar8 = malloc((long)iVar13);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          memset(puVar8,0,(long)iVar13);
          puVar6 = (uint64_t *)(lVar16 + iVar18);
          puVar17 = puVar8;
          do {
            if (puVar8 != (uint64_t *)0x0) {
              uVar7 = VkObject_fromId(*puVar6);
              *puVar17 = uVar7;
            }
            uVar19 = uVar19 - 1;
            puVar17 = puVar17 + 1;
            iVar18 = iVar18 + 8;
            puVar6 = puVar6 + 1;
          } while (uVar19 != 0);
        }
        uVar5 = *(uint32_t *)(lVar16 + iVar18);
        uVar19 = (unsigned long)uVar5;
        uVar4 = ((uint32_t *)(lVar16 + iVar18))[1];
        uVar12 = (unsigned long)uVar4;
        iVar18 = iVar18 + 8;
        if ((int)uVar4 < 1) {
          puVar8 = (uint64_t *)0x0;
        }
        else {
          iVar13 = uVar4 * 8;
          iVar14 = *(int *)(param_1 + 0x48) + iVar13;
          if ((iVar14 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar8 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            *(int *)(param_1 + 0x48) = iVar14;
          }
          else {
            puVar8 = malloc((long)iVar13);
            ArrayList_add(param_1 + 0x50,puVar8);
          }
          memset(puVar8,0,(long)iVar13);
          puVar6 = (uint64_t *)(lVar16 + iVar18);
          puVar17 = puVar8;
          do {
            if (puVar8 != (uint64_t *)0x0) {
              uVar7 = VkObject_fromId(*puVar6);
              *puVar17 = uVar7;
            }
            uVar12 = uVar12 - 1;
            puVar17 = puVar17 + 1;
            iVar18 = iVar18 + 8;
            puVar6 = puVar6 + 1;
          } while (uVar12 != 0);
        }
        iVar14 = *(int *)(lVar16 + iVar18);
        uVar12 = (long)iVar18 + 4;
        if (0 < iVar14) {
          sVar15 = (long)iVar14 << 2;
          iVar14 = (int)sVar15;
          iVar18 = *(int *)(param_1 + 0x48) + iVar14;
          if ((iVar18 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar9 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            sVar15 = (size_t)iVar14;
            *(int *)(param_1 + 0x48) = iVar18;
          }
          else {
            pvVar9 = malloc(sVar15);
            ArrayList_add(param_1 + 0x50,pvVar9);
          }
          memset(pvVar9,0,sVar15);
          if (pvVar9 != (void *)0x0) {
            memcpy(pvVar9,(void *)(lVar16 + uVar12),(long)iVar14);
          }
          uVar12 = (unsigned long)(uint32_t)(iVar14 + (int)uVar12);
        }
        iVar18 = *(int *)(lVar16 + (int)uVar12);
        if (0 < iVar18) {
          sVar15 = (long)iVar18 << 2;
          iVar14 = (int)sVar15;
          iVar18 = *(int *)(param_1 + 0x48) + iVar14;
          if ((iVar18 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
            pvVar9 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
            sVar15 = (size_t)iVar14;
            *(int *)(param_1 + 0x48) = iVar18;
          }
          else {
            pvVar9 = malloc(sVar15);
            ArrayList_add(param_1 + 0x50,pvVar9);
          }
          memset(pvVar9,0,sVar15);
          if (pvVar9 != (void *)0x0) {
            memcpy(pvVar9,(void *)(lVar16 + (long)(int)uVar12 + 4),(long)iVar14);
          }
        }
        if (uVar5 != 0) {
          do {
            XWindowSwapchain_presentImage(*puVar8);
            uVar19 = uVar19 - 1;
            puVar8 = puVar8 + 1;
          } while (uVar19 != 0);
        }
        return;
      }
      uVar19 = (unsigned long)(iVar18 + 4);
LAB_0013c584:
      iVar18 = (int)uVar19;
      puVar6 = puVar8;
    }
    piVar11 = (int *)(lVar16 + iVar18);
    iVar18 = iVar18 + 4;
    puVar8 = puVar6;
  } while( true );
}


/* @00130008  size=2740 */

void vt_handle_vkQueueSubmit(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  int iVar3;
  long lVar4;
  uint64_t *puVar5;
  void *pvVar6;
  uint64_t uVar7;
  uint32_t uVar8;
  char *pcVar9;
  unsigned long uVar10;
  int *piVar11;
  unsigned long uVar12;
  uint64_t *puVar13;
  unsigned long uVar14;
  uint64_t *puVar15;
  uint64_t unaff_x22;
  int iVar16;
  int iVar17;
  int iVar18;
  size_t sVar19;
  long lVar20;
  uint64_t auStack_d0;
  uint64_t local_c8;
  uint64_t local_c0;
  unsigned long local_b8;
  long local_b0;
  char *local_a8;
  unsigned long local_a0;
  int local_94;
  char *local_90;
  long local_88;
  unsigned long local_80;
  uint8_t *local_78;
  int local_70 [2];
  long local_68;
  
  local_b0 = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_b0 + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    uVar12 = 1;
    lVar4 = param_1;
  }
  else {
    uVar12 = 9;
    lVar4 = *(long *)(pcVar9 + 1);
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar9 + (uVar12 | 4));
  uVar14 = (unsigned long)*(uint32_t *)(pcVar9 + uVar12);
  iVar3 = (int)uVar12 + 8;
  if (0 < (int)*(uint32_t *)(pcVar9 + (uVar12 | 4))) {
    do {
      uVar10 = uVar10 - 1;
      iVar3 = iVar3 + *(int *)(pcVar9 + iVar3) + 4;
    } while (uVar10 != 0);
  }
  if (pcVar9[iVar3] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar9 + (long)iVar3 + 1);
  }
  local_c0 = VkObject_fromId(lVar4);
  local_c8 = VkObject_fromId(unaff_x22);
  local_78 = auStack_d0 + -(uVar14 * 0x48 + 0xf & 0xfffffffff0);
  local_90 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*local_90 == '\0') {
    uVar8 = 1;
  }
  local_a0 = (unsigned long)*(uint32_t *)(local_90 + (unsigned long)uVar8 + 4);
  local_b8 = uVar14;
  if ((int)*(uint32_t *)(local_90 + (unsigned long)uVar8 + 4) < 1) {
LAB_00130a1c:
    uVar12 = RingBuffer_hasStatus(*(uint64_t *)(param_1 + 0x68),4);
    if (*(long *)(param_1 + 0x80) != 0) {
      TextureDecoder_decodeAll(*(long *)(param_1 + 0x80));
    }
    iVar3 = ((generic_fn_t)DAT_00193b68)(local_c0,local_b8,local_78,local_c8);
    if (iVar3 == -4) {
      *(uint32_t *)(param_1 + 0x78) = 0xfffffffc;
    }
    if ((uVar12 & 1) != 0) {
      local_70[1] = 0;
      local_70[0] = iVar3;
      RingBuffer_write(*(uint64_t *)(param_1 + 0x68),local_70,8);
    }
    if (*(long *)(local_b0 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  uVar12 = 0;
  iVar3 = uVar8 + 8;
  local_a8 = local_90 + 8;
LAB_00130154:
  pcVar9 = local_90;
  lVar4 = (long)iVar3 + 4;
  local_94 = *(int *)(local_90 + iVar3);
  piVar11 = (int *)(local_90 + lVar4 + 4);
  puVar15 = (uint64_t *)0x0;
  *(uint32_t *)(local_78 + uVar12 * 0x48) = *(uint32_t *)(local_90 + lVar4);
  iVar3 = 8;
  local_88 = lVar4;
  local_80 = uVar12;
  do {
    iVar16 = *piVar11;
    if (iVar16 < 0x3b9d0068) {
      if (iVar16 == 0x3b9bb465) {
        iVar16 = *(int *)(pcVar9 + iVar3 + lVar4);
        lVar20 = (long)iVar3 + 4;
        if (iVar16 < 1) {
LAB_00130190:
          iVar16 = (int)lVar20;
        }
        else {
          iVar3 = *(int *)(param_1 + 0x48);
          if ((iVar3 < 0xffc0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar3);
            *(int *)(param_1 + 0x48) = iVar3 + 0x40;
          }
          else {
            puVar5 = malloc(0x40);
            ArrayList_add(param_1 + 0x50,puVar5);
          }
          puVar5[5] = 0;
          puVar5[4] = 0;
          puVar5[7] = 0;
          puVar5[6] = 0;
          puVar5[1] = 0;
          *puVar5 = 0;
          puVar5[3] = 0;
          puVar5[2] = 0;
          pcVar1 = pcVar9 + lVar20 + lVar4;
          uVar2 = *(uint32_t *)pcVar1;
          puVar5[1] = 0;
          *(uint32_t *)puVar5 = uVar2;
          *(uint32_t *)(puVar5 + 2) = *(uint32_t *)(pcVar1 + 4);
          if (*(int *)(pcVar1 + 8) < 1) {
            iVar3 = 0xc;
            puVar5[3] = 0;
          }
          else {
            sVar19 = (long)*(int *)(pcVar1 + 8) << 2;
            iVar3 = (int)sVar19;
            iVar17 = *(int *)(param_1 + 0x48) + iVar3;
            if ((iVar17 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar17;
              sVar19 = (size_t)iVar3;
            }
            else {
              pvVar6 = malloc(sVar19);
              ArrayList_add(param_1 + 0x50,pvVar6);
            }
            memset(pvVar6,0,sVar19);
            if (pvVar6 != (void *)0x0) {
              memcpy(pvVar6,pcVar1 + 0xc,(long)iVar3);
            }
            iVar3 = iVar3 + 0xc;
            puVar5[3] = pvVar6;
          }
          uVar12 = (long)iVar3 + 8;
          *(uint32_t *)(puVar5 + 4) = *(uint32_t *)(pcVar1 + iVar3);
          iVar3 = *(int *)(pcVar1 + iVar3 + 4);
          if (iVar3 < 1) {
            puVar5[5] = 0;
          }
          else {
            sVar19 = (long)iVar3 << 2;
            iVar17 = (int)sVar19;
            iVar3 = *(int *)(param_1 + 0x48) + iVar17;
            if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar3;
              sVar19 = (size_t)iVar17;
            }
            else {
              pvVar6 = malloc(sVar19);
              ArrayList_add(param_1 + 0x50,pvVar6);
            }
            memset(pvVar6,0,sVar19);
            if (pvVar6 != (void *)0x0) {
              memcpy(pvVar6,pcVar1 + uVar12,(long)iVar17);
            }
            uVar12 = (unsigned long)(uint32_t)(iVar17 + (int)uVar12);
            puVar5[5] = pvVar6;
          }
          *(uint32_t *)(puVar5 + 6) = *(uint32_t *)(pcVar1 + (int)uVar12);
          iVar3 = *(int *)(pcVar1 + (int)uVar12 + 4);
          if (iVar3 < 1) {
            puVar5[7] = 0;
          }
          else {
            sVar19 = (long)iVar3 << 2;
            iVar17 = (int)sVar19;
            iVar3 = *(int *)(param_1 + 0x48) + iVar17;
            if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar3;
              sVar19 = (size_t)iVar17;
            }
            else {
              pvVar6 = malloc(sVar19);
              ArrayList_add(param_1 + 0x50,pvVar6);
            }
            memset(pvVar6,0,sVar19);
            if (pvVar6 != (void *)0x0) {
              memcpy(pvVar6,pcVar1 + (long)(int)uVar12 + 8,(long)iVar17);
            }
            puVar5[7] = pvVar6;
          }
          iVar16 = iVar16 + (int)lVar20;
LAB_00130698:
          puVar5[1] = puVar15;
          puVar15 = puVar5;
        }
      }
      else {
        if (iVar16 == -1) break;
LAB_001302b0:
        uVar12 = (unsigned long)(iVar3 + 4);
LAB_001302b4:
        iVar16 = (int)uVar12;
      }
    }
    else {
      if (iVar16 != 0x3b9d0068) {
        if (iVar16 != 0x3b9df29b) goto LAB_001302b0;
        iVar16 = *(int *)(pcVar9 + iVar3 + lVar4);
        uVar12 = (long)iVar3 + 4;
        if (0 < iVar16) {
          iVar3 = *(int *)(param_1 + 0x48);
          if ((iVar3 < 0xffd0) && (*(long *)(param_1 + 0x40) != 0)) {
            puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar3);
            *(int *)(param_1 + 0x48) = iVar3 + 0x30;
          }
          else {
            puVar5 = malloc(0x30);
            ArrayList_add(param_1 + 0x50,puVar5);
          }
          puVar5[3] = 0;
          puVar5[2] = 0;
          puVar5[5] = 0;
          puVar5[4] = 0;
          puVar5[1] = 0;
          *puVar5 = 0;
          pcVar1 = pcVar9 + uVar12 + lVar4;
          uVar2 = *(uint32_t *)pcVar1;
          puVar5[1] = 0;
          *(uint32_t *)puVar5 = uVar2;
          *(uint32_t *)(puVar5 + 2) = *(uint32_t *)(pcVar1 + 4);
          if (*(int *)(pcVar1 + 8) < 1) {
            iVar3 = 0xc;
            puVar5[3] = 0;
          }
          else {
            sVar19 = (long)*(int *)(pcVar1 + 8) << 3;
            iVar3 = (int)sVar19;
            iVar17 = *(int *)(param_1 + 0x48) + iVar3;
            if ((iVar17 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar17;
              sVar19 = (size_t)iVar3;
            }
            else {
              pvVar6 = malloc(sVar19);
              ArrayList_add(param_1 + 0x50,pvVar6);
            }
            memset(pvVar6,0,sVar19);
            if (pvVar6 != (void *)0x0) {
              memcpy(pvVar6,pcVar1 + 0xc,(long)iVar3);
            }
            iVar3 = iVar3 + 0xc;
            puVar5[3] = pvVar6;
          }
          *(uint32_t *)(puVar5 + 4) = *(uint32_t *)(pcVar1 + iVar3);
          iVar17 = *(int *)(pcVar1 + iVar3 + 4);
          if (iVar17 < 1) {
            puVar5[5] = 0;
          }
          else {
            sVar19 = (long)iVar17 << 3;
            iVar18 = (int)sVar19;
            iVar17 = *(int *)(param_1 + 0x48) + iVar18;
            if ((iVar17 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
              pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
              *(int *)(param_1 + 0x48) = iVar17;
              sVar19 = (size_t)iVar18;
            }
            else {
              pvVar6 = malloc(sVar19);
              ArrayList_add(param_1 + 0x50,pvVar6);
            }
            memset(pvVar6,0,sVar19);
            if (pvVar6 != (void *)0x0) {
              memcpy(pvVar6,pcVar1 + (long)iVar3 + 8,(long)iVar18);
            }
            puVar5[5] = pvVar6;
          }
          iVar16 = iVar16 + (int)uVar12;
          goto LAB_00130698;
        }
        goto LAB_001302b4;
      }
      iVar16 = *(int *)(pcVar9 + iVar3 + lVar4);
      lVar20 = (long)iVar3 + 4;
      if (iVar16 < 1) goto LAB_00130190;
      iVar3 = *(int *)(param_1 + 0x48);
      if ((iVar3 < 0xffe8) && (*(long *)(param_1 + 0x40) != 0)) {
        puVar5 = (uint64_t *)(*(long *)(param_1 + 0x40) + (long)iVar3);
        *(int *)(param_1 + 0x48) = iVar3 + 0x18;
      }
      else {
        puVar5 = malloc(0x18);
        ArrayList_add(param_1 + 0x50,puVar5);
      }
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      iVar16 = iVar16 + (int)lVar20;
      *(uint32_t *)puVar5 = *(uint32_t *)(pcVar9 + lVar20 + lVar4);
      uVar2 = *(uint32_t *)(pcVar9 + lVar20 + lVar4 + 4);
      puVar5[1] = puVar15;
      *(uint32_t *)(puVar5 + 2) = uVar2;
      puVar15 = puVar5;
    }
    piVar11 = (int *)(pcVar9 + iVar16 + lVar4);
    iVar3 = iVar16 + 4;
  } while( true );
  if (puVar15 == (uint64_t *)0x0) {
    puVar5 = (uint64_t *)0x0;
  }
  else {
    puVar13 = (uint64_t *)0x0;
    do {
      puVar5 = puVar15;
      puVar15 = (uint64_t *)puVar5[1];
      puVar5[1] = puVar13;
      puVar13 = puVar5;
    } while (puVar15 != (uint64_t *)0x0);
  }
  iVar16 = iVar3 + 8;
  *(uint64_t **)(local_78 + local_80 * 0x48 + 8) = puVar5;
  *(uint32_t *)(local_78 + local_80 * 0x48 + 0x10) = *(uint32_t *)(pcVar9 + iVar3 + lVar4);
  uVar8 = *(uint32_t *)(pcVar9 + iVar3 + lVar4 + 4);
  if ((int)uVar8 < 1) {
    *(uint64_t *)(local_78 + local_80 * 0x48 + 0x18) = 0;
  }
  else {
    iVar17 = uVar8 * 8;
    iVar3 = *(int *)(param_1 + 0x48) + iVar17;
    if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar3;
    }
    else {
      pvVar6 = malloc((long)iVar17);
      ArrayList_add(param_1 + 0x50,pvVar6);
    }
    memset(pvVar6,0,(long)iVar17);
    pcVar1 = local_90;
    uVar12 = 0;
    lVar20 = iVar16 + local_88;
    do {
      if (pvVar6 != (void *)0x0) {
        uVar7 = VkObject_fromId(*(uint64_t *)(pcVar1 + uVar12 * 8 + lVar20));
        *(uint64_t *)((long)pvVar6 + uVar12 * 8) = uVar7;
      }
      uVar12 = uVar12 + 1;
      iVar16 = iVar16 + 8;
    } while (uVar8 != uVar12);
    *(void **)(local_78 + local_80 * 0x48 + 0x18) = pvVar6;
  }
  uVar12 = (long)iVar16 + 4;
  if (*(int *)(pcVar9 + iVar16 + lVar4) < 1) {
    *(uint64_t *)(local_78 + local_80 * 0x48 + 0x20) = 0;
  }
  else {
    sVar19 = (long)*(int *)(pcVar9 + iVar16 + lVar4) << 2;
    iVar16 = (int)sVar19;
    iVar3 = *(int *)(param_1 + 0x48) + iVar16;
    if ((iVar3 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar3;
      sVar19 = (size_t)iVar16;
    }
    else {
      pvVar6 = malloc(sVar19);
      ArrayList_add(param_1 + 0x50,pvVar6);
    }
    memset(pvVar6,0,sVar19);
    if (pvVar6 != (void *)0x0) {
      memcpy(pvVar6,pcVar9 + uVar12 + lVar4,(long)iVar16);
    }
    uVar12 = (unsigned long)(uint32_t)(iVar16 + (int)uVar12);
    *(void **)(local_78 + local_80 * 0x48 + 0x20) = pvVar6;
  }
  iVar3 = (int)uVar12 + 8;
  *(uint32_t *)(local_78 + local_80 * 0x48 + 0x28) = *(uint32_t *)(pcVar9 + (int)uVar12 + lVar4)
  ;
  uVar8 = *(uint32_t *)(pcVar9 + (int)uVar12 + lVar4 + 4);
  if ((int)uVar8 < 1) {
    *(uint64_t *)(local_78 + local_80 * 0x48 + 0x30) = 0;
  }
  else {
    iVar17 = uVar8 * 8;
    iVar16 = *(int *)(param_1 + 0x48) + iVar17;
    if ((iVar16 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar16;
    }
    else {
      pvVar6 = malloc((long)iVar17);
      ArrayList_add(param_1 + 0x50,pvVar6);
    }
    memset(pvVar6,0,(long)iVar17);
    pcVar1 = local_90;
    uVar12 = 0;
    lVar20 = local_88 + iVar3;
    do {
      if (pvVar6 != (void *)0x0) {
        uVar7 = VkObject_fromId(*(uint64_t *)(pcVar1 + uVar12 * 8 + lVar20));
        *(uint64_t *)((long)pvVar6 + uVar12 * 8) = uVar7;
      }
      uVar12 = uVar12 + 1;
      iVar3 = iVar3 + 8;
    } while (uVar8 != uVar12);
    *(void **)(local_78 + local_80 * 0x48 + 0x30) = pvVar6;
  }
  *(uint32_t *)(local_78 + local_80 * 0x48 + 0x38) = *(uint32_t *)(pcVar9 + iVar3 + lVar4);
  uVar8 = *(uint32_t *)(pcVar9 + iVar3 + lVar4 + 4);
  if ((int)uVar8 < 1) {
    *(uint64_t *)(local_78 + local_80 * 0x48 + 0x40) = 0;
  }
  else {
    iVar17 = uVar8 * 8;
    iVar16 = *(int *)(param_1 + 0x48) + iVar17;
    if ((iVar16 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
      pvVar6 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
      *(int *)(param_1 + 0x48) = iVar16;
    }
    else {
      pvVar6 = malloc((long)iVar17);
      ArrayList_add(param_1 + 0x50,pvVar6);
    }
    memset(pvVar6,0,(long)iVar17);
    pcVar9 = local_a8;
    uVar12 = 0;
    lVar4 = iVar3 + local_88;
    do {
      if (pvVar6 != (void *)0x0) {
        uVar7 = VkObject_fromId(*(uint64_t *)(pcVar9 + uVar12 * 8 + lVar4));
        *(uint64_t *)((long)pvVar6 + uVar12 * 8) = uVar7;
      }
      uVar12 = uVar12 + 1;
    } while (uVar8 != uVar12);
    *(void **)(local_78 + local_80 * 0x48 + 0x40) = pvVar6;
  }
  uVar12 = local_80 + 1;
  iVar3 = local_94 + (int)local_88;
  if (uVar12 == local_a0) goto LAB_00130a1c;
  goto LAB_00130154;
}


/* @0014ab5c  size=1176 */

void vt_handle_vkQueueSubmit2(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  uint64_t uVar6;
  void *pvVar7;
  uint32_t uVar8;
  char *pcVar9;
  unsigned long uVar10;
  unsigned long uVar11;
  int iVar12;
  uint64_t *puVar13;
  uint64_t unaff_x22;
  uint64_t *puVar14;
  uint64_t auStack_c0 [2];
  uint32_t local_ac;
  unsigned long local_a8 [4];
  char *local_88;
  int local_7c;
  long local_78;
  int local_70 [2];
  long local_68;
  
  local_a8[2] = 0 /* tpidr_el0 */;
  local_68 = *(long *)(local_a8[2] + 0x28);
  pcVar9 = *(char **)(param_1 + 0x30);
  if (*pcVar9 == '\0') {
    uVar11 = 1;
    lVar5 = param_1;
  }
  else {
    uVar11 = 9;
    lVar5 = *(long *)(pcVar9 + 1);
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar9 + (uVar11 | 4));
  iVar4 = (int)uVar11 + 8;
  if (0 < (int)*(uint32_t *)(pcVar9 + (uVar11 | 4))) {
    do {
      uVar10 = uVar10 - 1;
      iVar4 = iVar4 + *(int *)(pcVar9 + iVar4) + 4;
    } while (uVar10 != 0);
  }
  uVar11 = (unsigned long)*(uint32_t *)(pcVar9 + uVar11);
  if (pcVar9[iVar4] != '\0') {
    unaff_x22 = *(uint64_t *)(pcVar9 + (long)iVar4 + 1);
  }
  local_a8[0] = VkObject_fromId(lVar5);
  auStack_c0[1] = VkObject_fromId(unaff_x22);
  local_ac = RingBuffer_hasStatus(*(uint64_t *)(param_1 + 0x68),4);
  if (*(long *)(param_1 + 0x80) != 0) {
    TextureDecoder_decodeAll(*(long *)(param_1 + 0x80));
  }
  puVar14 = auStack_c0 + uVar11 * -8;
  local_88 = *(char **)(param_1 + 0x30);
  uVar8 = 9;
  if (*local_88 == '\0') {
    uVar8 = 1;
  }
  local_a8[3] = (unsigned long)*(uint32_t *)(local_88 + (unsigned long)uVar8 + 4);
  local_a8[1] = uVar11;
  if (0 < (int)*(uint32_t *)(local_88 + (unsigned long)uVar8 + 4)) {
    uVar11 = 0;
    iVar4 = uVar8 + 8;
    do {
      lVar5 = (long)iVar4 + 4;
      puVar13 = puVar14 + uVar11 * 8;
      pcVar9 = local_88 + lVar5;
      uVar2 = *(uint32_t *)pcVar9;
      iVar4 = *(int *)(local_88 + iVar4);
      puVar13[1] = 0;
      local_78 = lVar5;
      *(uint32_t *)puVar13 = uVar2;
      local_7c = iVar4;
      *(uint32_t *)(puVar13 + 2) = *(uint32_t *)(pcVar9 + 4);
      *(uint32_t *)((long)puVar13 + 0x14) = *(uint32_t *)(pcVar9 + 8);
      uVar8 = *(uint32_t *)(pcVar9 + 0xc);
      uVar10 = (unsigned long)uVar8;
      if ((int)uVar8 < 1) {
        puVar13[3] = 0;
        iVar4 = 0x10;
      }
      else {
        iVar12 = uVar8 * 0x30;
        iVar4 = *(int *)(param_1 + 0x48) + iVar12;
        if ((iVar4 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar7 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar4;
        }
        else {
          pvVar7 = malloc((long)iVar12);
          ArrayList_add(param_1 + 0x50,pvVar7);
        }
        memset(pvVar7,0,(long)iVar12);
        puVar13 = (uint64_t *)((long)pvVar7 + 0x18);
        iVar4 = 0x10;
        do {
          iVar12 = *(int *)(pcVar9 + iVar4);
          lVar5 = (long)iVar4 + 4;
          if (pvVar7 != (void *)0x0) {
            pcVar1 = pcVar9 + lVar5;
            uVar2 = *(uint32_t *)pcVar1;
            puVar13[-2] = 0;
            *(uint32_t *)(puVar13 + -3) = uVar2;
            uVar6 = VkObject_fromId(*(uint64_t *)(pcVar1 + 4));
            puVar13[-1] = uVar6;
            *puVar13 = *(uint64_t *)(pcVar1 + 0xc);
            puVar13[1] = *(uint64_t *)(pcVar1 + 0x14);
            *(uint32_t *)(puVar13 + 2) = *(uint32_t *)(pcVar1 + 0x1c);
          }
          iVar4 = iVar12 + (int)lVar5;
          uVar10 = uVar10 - 1;
          puVar13 = puVar13 + 6;
        } while (uVar10 != 0);
        puVar14[uVar11 * 8 + 3] = pvVar7;
      }
      iVar12 = iVar4 + 8;
      *(uint32_t *)(puVar14 + uVar11 * 8 + 4) = *(uint32_t *)(pcVar9 + iVar4);
      uVar8 = *(uint32_t *)(pcVar9 + iVar4 + 4);
      uVar10 = (unsigned long)uVar8;
      if ((int)uVar8 < 1) {
        puVar14[uVar11 * 8 + 5] = 0;
      }
      else {
        iVar3 = uVar8 * 0x20;
        iVar4 = *(int *)(param_1 + 0x48) + iVar3;
        if ((iVar4 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar7 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar4;
        }
        else {
          pvVar7 = malloc((long)iVar3);
          ArrayList_add(param_1 + 0x50,pvVar7);
        }
        memset(pvVar7,0,(long)iVar3);
        puVar13 = (uint64_t *)((long)pvVar7 + 0x10);
        do {
          iVar4 = *(int *)(pcVar9 + iVar12);
          lVar5 = (long)iVar12 + 4;
          if (pvVar7 != (void *)0x0) {
            pcVar1 = pcVar9 + lVar5;
            uVar2 = *(uint32_t *)pcVar1;
            puVar13[-1] = 0;
            *(uint32_t *)(puVar13 + -2) = uVar2;
            uVar6 = VkObject_fromId(*(uint64_t *)(pcVar1 + 4));
            *puVar13 = uVar6;
            *(uint32_t *)(puVar13 + 1) = *(uint32_t *)(pcVar1 + 0xc);
          }
          iVar12 = iVar4 + (int)lVar5;
          uVar10 = uVar10 - 1;
          puVar13 = puVar13 + 4;
        } while (uVar10 != 0);
        puVar14[uVar11 * 8 + 5] = pvVar7;
      }
      *(uint32_t *)(puVar14 + uVar11 * 8 + 6) = *(uint32_t *)(pcVar9 + iVar12);
      uVar8 = *(uint32_t *)(pcVar9 + iVar12 + 4);
      uVar10 = (unsigned long)uVar8;
      if ((int)uVar8 < 1) {
        puVar14[uVar11 * 8 + 7] = 0;
      }
      else {
        iVar3 = uVar8 * 0x30;
        iVar4 = *(int *)(param_1 + 0x48) + iVar3;
        if ((iVar4 < 0x10000) && (*(long *)(param_1 + 0x40) != 0)) {
          pvVar7 = (void *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x48));
          *(int *)(param_1 + 0x48) = iVar4;
        }
        else {
          pvVar7 = malloc((long)iVar3);
          ArrayList_add(param_1 + 0x50,pvVar7);
        }
        iVar12 = iVar12 + 8;
        memset(pvVar7,0,(long)iVar3);
        puVar13 = (uint64_t *)((long)pvVar7 + 0x18);
        do {
          iVar4 = *(int *)(pcVar9 + iVar12);
          lVar5 = (long)iVar12 + 4;
          if (pvVar7 != (void *)0x0) {
            pcVar1 = pcVar9 + lVar5;
            uVar2 = *(uint32_t *)pcVar1;
            puVar13[-2] = 0;
            *(uint32_t *)(puVar13 + -3) = uVar2;
            uVar6 = VkObject_fromId(*(uint64_t *)(pcVar1 + 4));
            puVar13[-1] = uVar6;
            *puVar13 = *(uint64_t *)(pcVar1 + 0xc);
            puVar13[1] = *(uint64_t *)(pcVar1 + 0x14);
            *(uint32_t *)(puVar13 + 2) = *(uint32_t *)(pcVar1 + 0x1c);
          }
          iVar12 = iVar4 + (int)lVar5;
          uVar10 = uVar10 - 1;
          puVar13 = puVar13 + 6;
        } while (uVar10 != 0);
        puVar14[uVar11 * 8 + 7] = pvVar7;
      }
      uVar11 = uVar11 + 1;
      iVar4 = local_7c + (int)local_78;
    } while (uVar11 != local_a8[3]);
  }
  iVar4 = ((generic_fn_t)DAT_001942d0)(local_a8[0],local_a8[1],puVar14,auStack_c0[1]);
  if (iVar4 == -4) {
    *(uint32_t *)(param_1 + 0x78) = 0xfffffffc;
  }
  if ((local_ac & 1) != 0) {
    local_70[1] = 0;
    local_70[0] = iVar4;
    RingBuffer_write(*(uint64_t *)(param_1 + 0x68),local_70,8);
  }
  if (*(long *)(local_a8[2] + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00130abc  size=120 */

void vt_handle_vkQueueWaitIdle(long param_1)

{
  long lVar1;
  uint32_t local_30;
  uint32_t uStack_2c;
  long local_28;
  
  /* stack canary setup */
  local_28 = *(long *)(lVar1 + 0x28);
  VkObject_fromId(**(uint64_t **)(param_1 + 0x30));
  local_30 = ((generic_fn_t)DAT_00193b70)();
  uStack_2c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_30,8);
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0013890c  size=76 */

void vt_handle_vkResetCommandBuffer(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  char *pcVar3;
  long lVar4;
  
  pcVar3 = *(char **)(param_1 + 0x30);
  if (*pcVar3 == '\0') {
    lVar4 = 1;
  }
  else {
    param_1 = *(long *)(pcVar3 + 1);
    lVar4 = 9;
  }
  uVar1 = *(uint32_t *)(pcVar3 + lVar4);
  uVar2 = VkObject_fromId(param_1);
                    /* WARNING: Could not recover jumptable at 0x00138954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193dc0)(uVar2,uVar1);
  return;
}


/* @00137f44  size=132 */

void vt_handle_vkResetCommandPool(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar6 = lVar5 + 1;
  if (pcVar4[lVar5] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar6);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00137fc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d98)(uVar2,uVar3,uVar1);
  return;
}


/* @00136260  size=132 */

void vt_handle_vkResetDescriptorPool(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar6 = lVar5 + 1;
  if (pcVar4[lVar5] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar6);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x001362e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193d40)(uVar2,uVar3,uVar1);
  return;
}


/* @001339fc  size=192 */

void vt_handle_vkResetEvent(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
    cVar1 = pcVar6[1];
    lVar3 = param_1;
  }
  else {
    lVar3 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
    cVar1 = pcVar6[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar6 + lVar7 + 1);
  }
  uVar4 = VkObject_fromId(lVar3);
  uVar5 = VkObject_fromId(unaff_x20);
  local_40 = ((generic_fn_t)DAT_00193c48)(uVar4,uVar5);
  uStack_3c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_40,8);
  if (*(long *)(lVar2 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00132f0c  size=252 */

void vt_handle_vkResetFences(long param_1)

{
  uint32_t uVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  uint32_t uVar7;
  long lVar8;
  uint64_t *puVar9;
  unsigned long uVar10;
  uint64_t *puVar11;
  long alStack_60 [2];
  
  /* stack canary setup */
  alStack_60[1] = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar8 = 1;
    lVar3 = param_1;
  }
  else {
    lVar8 = 9;
    lVar3 = *(long *)(pcVar6 + 1);
  }
  uVar1 = *(uint32_t *)(pcVar6 + lVar8);
  uVar4 = VkObject_fromId(lVar3);
  puVar9 = (uint64_t *)((long)alStack_60 - ((unsigned long)uVar1 * 8 + 0xf & 0xffffffff0));
  pcVar6 = *(char **)(param_1 + 0x30);
  uVar7 = 9;
  if (*pcVar6 == '\0') {
    uVar7 = 1;
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4);
  if (0 < (int)*(uint32_t *)(pcVar6 + (unsigned long)uVar7 + 4)) {
    pcVar6 = pcVar6 + uVar7;
    puVar11 = puVar9;
    do {
      pcVar6 = pcVar6 + 8;
      uVar5 = VkObject_fromId(*(uint64_t *)pcVar6);
      uVar10 = uVar10 - 1;
      *puVar11 = uVar5;
      puVar11 = puVar11 + 1;
    } while (uVar10 != 0);
  }
  ((generic_fn_t)DAT_00193c00)(uVar4,(unsigned long)uVar1,puVar9);
  if (*(long *)(lVar2 + 0x28) == alStack_60[1]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00133ed0  size=140 */

void vt_handle_vkResetQueryPool(long param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  char *pcVar5;
  long lVar6;
  unsigned long uVar7;
  uint64_t unaff_x19;
  
  pcVar5 = *(char **)(param_1 + 0x30);
  if (*pcVar5 == '\0') {
    lVar6 = 1;
  }
  else {
    param_1 = *(long *)(pcVar5 + 1);
    lVar6 = 9;
  }
  uVar7 = lVar6 + 1;
  if (pcVar5[lVar6] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar5 + uVar7);
    uVar7 = (unsigned long)((int)lVar6 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar5 + uVar7);
  uVar2 = *(uint32_t *)(pcVar5 + uVar7 + 4);
  uVar3 = VkObject_fromId(param_1);
  uVar4 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00133f58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193c68)(uVar3,uVar4,uVar1,uVar2);
  return;
}


/* @0013393c  size=192 */

void vt_handle_vkSetEvent(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint64_t uVar4;
  uint64_t uVar5;
  char *pcVar6;
  long lVar7;
  uint64_t unaff_x20;
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar6 = *(char **)(param_1 + 0x30);
  if (*pcVar6 == '\0') {
    lVar7 = 1;
    cVar1 = pcVar6[1];
    lVar3 = param_1;
  }
  else {
    lVar3 = *(long *)(pcVar6 + 1);
    lVar7 = 9;
    cVar1 = pcVar6[9];
  }
  if (cVar1 != '\0') {
    unaff_x20 = *(uint64_t *)(pcVar6 + lVar7 + 1);
  }
  uVar4 = VkObject_fromId(lVar3);
  uVar5 = VkObject_fromId(unaff_x20);
  local_40 = ((generic_fn_t)DAT_00193c40)(uVar4,uVar5);
  uStack_3c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_40,8);
  if (*(long *)(lVar2 + 0x28) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00147d30  size=220 */

void vt_handle_vkSignalSemaphore(long param_1)

{
  uint32_t *puVar1;
  long lVar2;
  uint64_t uVar3;
  char *pcVar4;
  unsigned long uVar5;
  uint64_t unaff_x20;
  unsigned long local_60 [4];
  uint32_t local_40;
  uint32_t uStack_3c;
  long local_38;
  
  /* stack canary setup */
  local_38 = *(long *)(lVar2 + 0x28);
  pcVar4 = *(char **)(param_1 + 0x30);
  local_60[1] = 0;
  local_60[0] = 0;
  local_60[3] = 0;
  local_60[2] = 0;
  if (*pcVar4 == '\0') {
    uVar5 = 1;
  }
  else {
    unaff_x20 = *(uint64_t *)(pcVar4 + 1);
    uVar5 = 9;
  }
  if (0 < *(int *)(pcVar4 + uVar5)) {
    puVar1 = (uint32_t *)(pcVar4 + (uVar5 | 4));
    local_60[1] = 0;
    local_60[0] = (unsigned long)*puVar1;
    local_60[2] = VkObject_fromId(*(uint64_t *)(puVar1 + 1));
    local_60[3] = *(unsigned long *)(puVar1 + 3);
  }
  uVar3 = VkObject_fromId(unaff_x20);
  local_40 = ((generic_fn_t)DAT_001940e8)(uVar3,local_60);
  uStack_3c = 0;
  RingBuffer_write(*(uint64_t *)(param_1 + 0x68),&local_40,8);
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @00142700  size=132 */

void vt_handle_vkTrimCommandPool(long param_1)

{
  uint32_t uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  char *pcVar4;
  long lVar5;
  unsigned long uVar6;
  uint64_t unaff_x19;
  
  pcVar4 = *(char **)(param_1 + 0x30);
  if (*pcVar4 == '\0') {
    lVar5 = 1;
  }
  else {
    param_1 = *(long *)(pcVar4 + 1);
    lVar5 = 9;
  }
  uVar6 = lVar5 + 1;
  if (pcVar4[lVar5] != '\0') {
    unaff_x19 = *(uint64_t *)(pcVar4 + uVar6);
    uVar6 = (unsigned long)((int)lVar5 + 9);
  }
  uVar1 = *(uint32_t *)(pcVar4 + uVar6);
  uVar2 = VkObject_fromId(param_1);
  uVar3 = VkObject_fromId(unaff_x19);
                    /* WARNING: Could not recover jumptable at 0x00142780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ((generic_fn_t)DAT_00193fb8)(uVar2,uVar3,uVar1);
  return;
}


/* @001311a8  size=32 */

void vt_handle_vkUnmapMemory(void)

{
  __android_log_print(3,"System.out","%s not implemented yet\n","vkUnmapMemory");
  return;
}


/* @00136864  size=500 */

void vt_handle_vkUpdateDescriptorSets(long param_1)

{
  char *pcVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint64_t uVar8;
  uint32_t uVar9;
  char *pcVar10;
  unsigned long uVar11;
  int iVar12;
  unsigned long uVar13;
  uint8_t *puVar14;
  uint8_t *puVar15;
  uint32_t *puVar16;
  uint64_t auStack_80;
  uint64_t local_78;
  long local_70;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar6 + 0x28);
  pcVar10 = *(char **)(param_1 + 0x30);
  if (*pcVar10 == '\0') {
    uVar13 = 1;
    lVar7 = param_1;
  }
  else {
    uVar13 = 9;
    lVar7 = *(long *)(pcVar10 + 1);
  }
  uVar11 = (unsigned long)*(uint32_t *)(pcVar10 + (uVar13 | 4));
  uVar3 = *(uint32_t *)(pcVar10 + uVar13);
  iVar12 = (int)uVar13 + 8;
  if (0 < (int)*(uint32_t *)(pcVar10 + (uVar13 | 4))) {
    do {
      uVar11 = uVar11 - 1;
      iVar12 = iVar12 + *(int *)(pcVar10 + iVar12) + 4;
    } while (uVar11 != 0);
  }
  uVar4 = *(uint32_t *)(pcVar10 + iVar12);
  local_78 = VkObject_fromId(lVar7);
  puVar14 = auStack_80 + (unsigned long)uVar3 * -0x40;
  local_70 = (long)puVar14 - ((unsigned long)uVar4 * 0x38 + 0xf & 0x7ffffffff0);
  pcVar10 = *(char **)(param_1 + 0x30);
  uVar9 = 9;
  if (*pcVar10 == '\0') {
    uVar9 = 1;
  }
  uVar13 = (unsigned long)*(uint32_t *)(pcVar10 + (unsigned long)uVar9 + 4);
  iVar12 = uVar9 + 8;
  if (0 < (int)*(uint32_t *)(pcVar10 + (unsigned long)uVar9 + 4)) {
    puVar15 = puVar14;
    do {
      iVar5 = *(int *)(pcVar10 + iVar12);
      lVar7 = (long)iVar12 + 4;
      FUN_0014eab8(puVar15,pcVar10 + lVar7,param_1 + 0x40);
      iVar12 = iVar5 + (int)lVar7;
      uVar13 = uVar13 - 1;
      puVar15 = puVar15 + 0x40;
    } while (uVar13 != 0);
  }
  uVar13 = (unsigned long)*(uint32_t *)(pcVar10 + (long)iVar12 + 4);
  if (0 < (int)*(uint32_t *)(pcVar10 + (long)iVar12 + 4)) {
    iVar12 = iVar12 + 8;
    puVar16 = (uint32_t *)(local_70 + 0x18);
    do {
      lVar7 = (long)iVar12 + 4;
      pcVar1 = pcVar10 + lVar7;
      uVar2 = *(uint32_t *)pcVar1;
      uVar8 = *(uint64_t *)(pcVar1 + 4);
      iVar12 = *(int *)(pcVar10 + iVar12);
      *(uint64_t *)(puVar16 + -4) = 0;
      puVar16[-6] = uVar2;
      uVar8 = VkObject_fromId(uVar8);
      uVar2 = *(uint32_t *)(pcVar1 + 0xc);
      *(uint64_t *)(puVar16 + -2) = uVar8;
      *puVar16 = uVar2;
      uVar8 = *(uint64_t *)(pcVar1 + 0x14);
      puVar16[1] = *(uint32_t *)(pcVar1 + 0x10);
      uVar8 = VkObject_fromId(uVar8);
      uVar2 = *(uint32_t *)(pcVar1 + 0x1c);
      *(uint64_t *)(puVar16 + 2) = uVar8;
      uVar13 = uVar13 - 1;
      puVar16[4] = uVar2;
      puVar16[5] = *(uint32_t *)(pcVar1 + 0x20);
      iVar12 = iVar12 + (int)lVar7;
      puVar16[6] = *(uint32_t *)(pcVar1 + 0x24);
      puVar16 = puVar16 + 0xe;
    } while (uVar13 != 0);
  }
  ((generic_fn_t)DAT_00193d58)(local_78,(unsigned long)uVar3,puVar14,(unsigned long)uVar4,local_70);
  if (*(long *)(lVar6 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001330c8  size=700 */

void vt_handle_vkWaitForFences(int *param_1)

{
  size_t *psVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  int *piVar5;
  uint64_t uVar6;
  uint64_t uVar7;
  char *pcVar8;
  uint32_t uVar9;
  unsigned long uVar10;
  uint32_t *__src;
  uint64_t *puVar11;
  long lVar12;
  uint32_t *puVar13;
  uint64_t *puVar14;
  unsigned long uVar15;
  long lVar16;
  size_t local_170;
  uint64_t *local_168;
  long local_160;
  long local_158;
  int local_14c;
  struct msghdr local_148;
  struct iovec local_110;
  size_t local_100 [3];
  uint64_t local_e8;
  long local_70;
  
  /* stack canary setup */
  local_70 = *(long *)(lVar16 + 0x28);
  pcVar8 = *(char **)(param_1 + 0xc);
  if (*pcVar8 == '\0') {
    uVar10 = 1;
    piVar5 = param_1;
  }
  else {
    uVar10 = 9;
    piVar5 = *(int **)(pcVar8 + 1);
  }
  uVar4 = *(uint32_t *)(pcVar8 + uVar10);
  uVar15 = (unsigned long)uVar4;
  iVar3 = *(int *)(pcVar8 + (uVar10 | 4)) << 3;
  if (*(int *)(pcVar8 + (uVar10 | 4)) < 1) {
    iVar3 = 0;
  }
  iVar3 = (int)uVar10 + iVar3;
  uVar2 = *(uint32_t *)(pcVar8 + (iVar3 + 8));
  lVar12 = *(long *)(pcVar8 + (iVar3 + 0xc));
  local_158 = (long)(int)uVar4;
  uVar6 = VkObject_fromId(piVar5);
  puVar11 = (uint64_t *)((long)&local_170 - (uVar15 * 8 + 0xf & 0xffffffff0));
  pcVar8 = *(char **)(param_1 + 0xc);
  uVar9 = 9;
  if (*pcVar8 == '\0') {
    uVar9 = 1;
  }
  uVar10 = (unsigned long)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 4);
  if (0 < (int)*(uint32_t *)(pcVar8 + (unsigned long)uVar9 + 4)) {
    pcVar8 = pcVar8 + (uVar9 + 8);
    puVar14 = puVar11;
    do {
      uVar7 = VkObject_fromId(*(uint64_t *)pcVar8);
      uVar10 = uVar10 - 1;
      *puVar14 = uVar7;
      pcVar8 = pcVar8 + 8;
      puVar14 = puVar14 + 1;
    } while (uVar10 != 0);
  }
  if (lVar12 == 0) {
    uVar4 = ((generic_fn_t)DAT_00193c10)(uVar6,local_158,puVar11,uVar2,0);
    local_100[0] = (size_t)uVar4;
    uVar10 = RingBuffer_write(*(uint64_t *)(param_1 + 0x1a),local_100,8);
  }
  else {
    local_168 = puVar11;
    local_170 = uVar15 * 4;
    __src = (uint32_t *)((long)puVar11 - (uVar15 * 4 + 0xf & 0x7fffffff0));
    local_160 = lVar16;
    local_14c = 0;
    if (uVar4 != 0) {
      uVar10 = 0;
      puVar13 = __src;
      do {
        local_100[2] = puVar11[uVar10];
        local_100[1] = 0;
        local_100[0] = 0x3b9c8b39;
        local_e8 = 8;
        local_14c = ((generic_fn_t)DAT_00193fe8)(uVar6,local_100,puVar13);
        if (local_14c != 0) break;
        uVar10 = uVar10 + 1;
        puVar13 = puVar13 + 1;
      } while (uVar10 < uVar15);
    }
    iVar3 = *param_1;
    local_110.iov_base = &local_14c;
    uVar10 = local_158 * 4;
    local_148.msg_iov = &local_110;
    local_148.msg_control = local_100;
    local_110.iov_len = 4;
    local_148.msg_iovlen = 1;
    local_148.msg_controllen = uVar10 + 0x10;
    psVar1 = local_148.msg_control;
    if (0xffffffffffffffef < uVar10) {
      psVar1 = (size_t *)0x0;
    }
    local_148.msg_name = (void *)0x0;
    local_148.msg_namelen = 0;
    local_148.msg_flags = 0;
    *psVar1 = local_148.msg_controllen;
    psVar1[1] = 0x100000001;
    if (0 < (int)local_158) {
      psVar1 = local_100 + 2;
      if (0xffffffffffffffef < uVar10) {
        psVar1 = (size_t *)0x10;
      }
      memcpy(psVar1,__src,local_170);
    }
    uVar10 = sendmsg(iVar3,&local_148,0);
    lVar16 = local_160;
    if (uVar4 != 0) {
      do {
        uVar4 = *__src;
        if (0 < (int)uVar4) {
          uVar4 = close(uVar4);
          *__src = 0xffffffff;
        }
        uVar10 = (unsigned long)uVar4;
        uVar15 = uVar15 - 1;
        __src = __src + 1;
      } while (uVar15 != 0);
    }
  }
  if (*(long *)(lVar16 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}


/* @00147d18  size=24 */

void vt_handle_vkWaitSemaphores(uint32_t *param_1)

{
  TimelineSemaphore_asyncWait
            (*param_1,*(uint64_t *)(param_1 + 0x24),*(uint64_t *)(param_1 + 0xc),param_1[0xe]);
  return;
}


