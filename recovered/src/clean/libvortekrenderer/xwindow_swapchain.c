/*
 * xwindow_swapchain.c — X11 window swapchain
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015d914  size=288 */

void XWindowSwapchain_acquireNextImage
               (uint32_t *param_1,uint64_t param_2,long param_3,long param_4,uint32_t *param_5
               )

{
  uint32_t uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uint64_t uVar5;
  long lVar6;
  uint64_t local_a0;
  uint64_t uStack_98;
  uint64_t uStack_90;
  uint64_t uStack_88;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t uStack_70;
  unsigned long local_68;
  long *local_60;
  long local_50;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar2 + 0x28);
  local_50 = param_3;
  if ((param_3 != 0) || (param_4 != 0)) {
    local_60 = (long *)0x0;
    uStack_78 = 0;
    local_80 = 0;
    uStack_70 = 0;
    uStack_98 = 0;
    uStack_88 = 0;
    uStack_90 = 0;
    local_a0 = 4;
    if (param_3 != 0) {
      local_60 = &local_50;
    }
    local_68 = (unsigned long)(param_3 != 0);
    uVar5 = ((generic_fn_t)DAT_00193b68)(*(uint64_t *)(param_1 + 10),1,&local_a0);
    if ((int)uVar5 == -4) goto LAB_0015da08;
  }
  lVar6 = *(long *)(param_1 + 0xc);
  uVar1 = *param_1;
/* FIXME: iVar3 = (**(void **)(**(long **)(lVar6 + 8) + 0x188)) */
/* FIXME: (*(long **)(lVar6 + 8),*(uint64_t *)(lVar6 + 0x10), */
/* FIXME: *(uint64_t *)(lVar6 + 0x18),uVar1); */
/* FIXME: iVar4 = (**(void **)(**(long **)(lVar6 + 8) + 0x188)) */
/* FIXME: (*(long **)(lVar6 + 8),*(uint64_t *)(lVar6 + 0x10), */
/* FIXME: *(uint64_t *)(lVar6 + 0x20),uVar1); */
  if ((param_1[6] == iVar3) && (param_1[7] == iVar4)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0xc4653600;
  }
  *param_5 = 0;
LAB_0015da08:
  if (*(long *)(lVar2 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}


/* @0015d550  size=792 */

uint32_t *
XWindowSwapchain_create
          (uint64_t param_1,uint32_t param_2,long param_3,long param_4,uint32_t param_5)

{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t *__ptr;
  void *__ptr_00;
  uint64_t uVar7;
  uint64_t uVar8;
  uint64_t extraout_x8;
  long lVar9;
  uint64_t *puVar10;
  uint64_t local_1d8;
  uint64_t local_1d0;
  uint64_t *puStack_1c8;
  uint64_t local_1c0;
  int local_1b8;
  uint32_t local_1b4;
  uint32_t uStack_1b0;
  uint32_t uStack_1ac;
  uint32_t uStack_1a8;
  uint32_t uStack_1a4;
  uint32_t local_1a0;
  uint32_t uStack_19c;
  unsigned long uStack_198;
  uint64_t uStack_190;
  uint64_t uStack_188;
  uint64_t local_180;
  uint64_t local_170;
  uint64_t *local_168;
  uint64_t local_160;
  uint64_t local_158;
  uint64_t uStack_150;
  uint64_t local_148;
  uint64_t local_140;
  uint64_t uStack_138;
  uint64_t uStack_130;
  uint64_t uStack_128;
  uint64_t local_120;
  uint64_t local_118;
  uint64_t local_110;
  uint64_t *puStack_108;
  uint64_t uStack_100;
  uint64_t local_f8;
  uint64_t local_e8;
  uint64_t *local_e0;
  uint64_t uStack_d8;
  uint64_t local_d0;
  uint64_t local_c8;
  uint64_t uStack_c0;
  uint64_t local_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t local_a0;
  unsigned long local_98;
  long local_88;
  
  /* stack canary setup */
  local_88 = *(long *)(lVar4 + 0x28);
  __ptr = calloc(1,0x38);
  iVar3 = *(int *)(param_3 + 0x20);
  *__ptr = param_5;
  __ptr[4] = iVar3;
  __ptr_00 = calloc((long)iVar3,0x10);
  iVar1 = *(int *)(param_3 + 0x24);
  uVar2 = *(uint32_t *)(param_3 + 0x38);
  uVar8 = *(uint64_t *)(param_3 + 0x2c);
  *(void **)(__ptr + 2) = __ptr_00;
  *(long *)(__ptr + 0xc) = param_4;
  __ptr[5] = iVar1;
  __ptr[8] = uVar2;
  *(uint64_t *)(__ptr + 6) = uVar8;
  if (0 < iVar3) {
    puVar10 = (uint64_t *)((long)__ptr_00 + 8);
    lVar9 = 0;
    do {
/* FIXME: uVar7 = (**(void **)(**(long **)(param_4 + 8) + 0x1a0)) */
/* FIXME: (*(long **)(param_4 + 8),*(uint64_t *)(param_4 + 0x10), */
/* FIXME: *(uint64_t *)(param_4 + 0x28),param_5,iVar1 == 0x2c || iVar1 == 0x32); */
      local_120 = 0;
      uStack_138 = 0;
      local_140 = 0;
      uStack_128 = 0;
      uStack_130 = 0;
      AHardwareBuffer_describe(uVar7,&local_140);
      uStack_150 = 0;
      local_170 = 0x3b9be341;
      local_168 = &local_158;
      uStack_188 = 0;
      uStack_190 = 0;
      local_158 = 0x3b9cc1ed;
      local_160 = 0x400;
      local_1d0 = 0xe;
      puStack_1c8 = &local_170;
      local_148 = 0;
      local_1c0 = 0x100000400;
      uStack_1a4 = 1;
      local_1a0 = 1;
      uStack_1ac = 1;
      uStack_1a8 = 1;
      uStack_19c = 0;
      uStack_198 = (unsigned long)uVar2;
      local_1b4 = (uint32_t)local_140;
      uStack_1b0 = (uint32_t)((unsigned long)local_140 >> 0x20);
      local_180 = 0;
      local_1b8 = iVar1;
      iVar5 = ((generic_fn_t)DAT_00193c90)(param_1,&local_1d0,0,&local_1d8);
      uVar8 = local_1d8;
      if (iVar5 == 0) {
        uStack_a8 = 0;
        local_98 = 0;
        local_a0 = 0;
        local_b0 = 0x3b9cc1e9;
        ((generic_fn_t)DAT_001940f0)(param_1,uVar7,&local_b0);
        local_e8 = 0x3b9cba19;
        local_e0 = &local_c8;
        uStack_d8 = uVar8;
        uStack_c0 = 0;
        local_c8 = 0x3b9cc1eb;
        local_f8 = 0;
        local_110 = 5;
        puStack_108 = &local_e8;
        local_d0 = 0;
        uStack_100 = local_a0;
        local_b8 = uVar7;
        uVar6 = getMemoryTypeIndex(local_98 & 0xffffffff,1);
        local_f8 = ((uint64_t)((*(uint32_t*)((char*)&local_f8 + 4))) << 32 | (uint32_t)(uVar6));
        iVar5 = ((generic_fn_t)DAT_00193b80)(param_1,&local_110,0,&local_118);
        uVar7 = extraout_x8;
        if (iVar5 == 0) {
          iVar5 = ((generic_fn_t)DAT_00193bd0)(param_1,uVar8,local_118,0);
          uVar7 = local_118;
        }
        if (iVar5 == 0) {
          puVar10[-1] = local_1d8;
          *puVar10 = uVar7;
        }
      }
      if (iVar5 != 0) {
        if (__ptr_00 != (void *)0x0) {
          free(__ptr_00);
        }
        free(__ptr);
        __ptr = (uint32_t *)0x0;
        goto LAB_0015d828;
      }
      lVar9 = lVar9 + 1;
      puVar10 = puVar10 + 2;
    } while (lVar9 < iVar3);
  }
  ((generic_fn_t)DAT_00193b60)(param_1,param_2,0,__ptr + 10);
LAB_0015d828:
  if (*(long *)(lVar4 + 0x28) == local_88) {
    return __ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0015d868  size=172 */

void XWindowSwapchain_destroy(uint64_t param_1,void *param_2)

{
  long lVar1;
  long lVar2;
  
  if (param_2 != (void *)0x0) {
    if (0 < *(int *)((long)param_2 + 0x10)) {
      lVar1 = 0;
      lVar2 = 0;
      do {
        ((generic_fn_t)DAT_00193c98)(param_1,*(uint64_t *)(*(long *)((long)param_2 + 8) + lVar1),0);
        ((generic_fn_t)DAT_00193b88)(param_1,*(uint64_t *)(*(long *)((long)param_2 + 8) + lVar1 + 8),0);
        lVar2 = lVar2 + 1;
        lVar1 = lVar1 + 0x10;
      } while (lVar2 < *(int *)((long)param_2 + 0x10));
    }
    if (*(void **)((long)param_2 + 8) != (void *)0x0) {
      free(*(void **)((long)param_2 + 8));
    }
    free(param_2);
    return;
  }
  return;
}


/* @0015da34  size=32 */

void XWindowSwapchain_presentImage(uint32_t *param_1)

{
  /* STUB: XWindowSwapchain_presentImage — Ghidra artifacts */
}


