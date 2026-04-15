/*
 * vk_loader.c — Regenerated
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* STUB */

uint8_t adrenotools_import_user_mem(uint64_t *param_1,uint64_t param_2,uint64_t param_3)
{ /* TODO */ }

/* @00164fdc  size=212 */

bool adrenotools_mem_cpu_map(long *param_1,void *param_2,size_t param_3)

{
  int __fd;
  void *pvVar1;
  bool local_25;
  
  __fd = __open_2("/dev/kgsl-3d0",2);
  if (__fd < 0) {
    local_25 = false;
  }
  else {
    pvVar1 = mmap(param_2,param_3,3,0x11,__fd,param_1[1]);
    *param_1 = (long)pvVar1;
    close(__fd);
    local_25 = *param_1 != 0;
  }
  return local_25;
}




/* STUB */

uint8_t adrenotools_mem_gpu_allocate(uint64_t *param_1,uint64_t *param_2)
{ /* TODO */ }

/* STUB */

uint64_t
adrenotools_open_libvulkan
          (uint32_t param_1,uint32_t param_2,char *param_3,char *param_4,char *param_5,char *param_6,
          char *param_7,long param_8)
{ /* TODO */ }

/* @001650e4  size=200 */

void adrenotools_set_turbo(uint8_t param_1)

{
  long lVar1;
  int __fd;
  uint32_t uVar2;
  unsigned long uVar3;
  uint32_t local_38 [2];
  uint32_t *local_30;
  uint64_t local_28;
  uint32_t local_1c;
  long local_18;
  
  /* stack canary */
  local_18 = *(long *)(lVar1 + 0x28);
  local_1c = ~(uint32_t)(param_1 & 1) & 1;
  local_38[0] = 0xe;
  local_30 = &local_1c;
  local_28 = 4;
  uVar3 = __open_2("/dev/kgsl-3d0",2);
  __fd = (int)uVar3;
  if (-1 < __fd) {
    ioctl(__fd,0x40180932,local_38);
    uVar2 = close(__fd);
    uVar3 = (unsigned long)uVar2;
  }
  /* stack canary */
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar1,uVar3);
  }
  return;
}




/* @001650b0  size=52 */

bool adrenotools_validate_gpu_mapping(long param_1)

{
  return *(long *)(param_1 + 8) == 0xdeadbeef;
}




/* @00165530  size=96 */

void android_create_namespace
               (uint64_t param_1,uint64_t param_2,uint64_t param_3,uint64_t param_4,
               uint64_t param_5,uint64_t param_6)

{
  uint64_t unaff_x30;
  
  ((generic_fn_t)DAT_00194350)(param_1,param_2,param_3,param_4,param_5,param_6,unaff_x30);
  return;
}




/* @00165590  size=100 */

void android_create_namespace_escape
               (uint64_t param_1,uint64_t param_2,uint64_t param_3,uint64_t param_4,
               uint64_t param_5,uint64_t param_6)

{
  ((generic_fn_t)DAT_00194350)(param_1,param_2,param_3,param_4,param_5,param_6,dlopen);
  return;
}




/* STUB */

uint32_t linkernsbypass_link_namespace_to_default_all_libs(uint64_t param_1)
{ /* TODO */ }

/* @00165520  size=16 */

uint8_t linkernsbypass_load_status(void)

{
  return DAT_00194348 & 1;
}




/* @001656c8  size=148 */

uint64_t linkernsbypass_namespace_dlopen(uint64_t param_1,uint32_t param_2,uint64_t param_3)

{
  long lVar1;
  uint64_t uVar2;
  uint64_t local_48;
  uint64_t local_40;
  uint64_t local_38;
  uint32_t local_30;
  uint32_t local_2c;
  uint64_t local_28;
  uint64_t local_20;
  long local_18;
  
  /* stack canary */
  local_18 = *(long *)(lVar1 + 0x28);
  local_48 = 0x200;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_20 = param_3;
  uVar2 = android_dlopen_ext(param_1,param_2,&local_48);
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 == 0) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(lVar1);
}




/* @0016575c  size=424 */

uint64_t
linkernsbypass_namespace_dlopen_unique
          (uint64_t param_1,uint64_t param_2,uint32_t param_3,uint64_t param_4)

{
  long lVar1;
  int iVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  unsigned long uVar5;
  uint64_t local_78;
  uint64_t local_70;
  uint64_t local_68;
  uint64_t local_60;
  uint32_t local_58;
  int local_54;
  uint64_t local_50;
  uint64_t local_48;
  uint64_t *local_40;
  uint64_t *local_38;
  uint64_t local_30;
  uint64_t local_28;
  uint16_t local_20;
  uint8_t local_1e;
  long local_18;
  
  /* stack canary */
  local_18 = *(long *)(lVar1 + 0x28);
  local_40 = &local_30;
  local_38 = &local_28;
  local_30 = param_2;
  local_28 = param_1;
  iVar2 = FUN_00165904(&local_40);
  if (iVar2 == -1) {
    local_78 = 0;
  }
  else {
    local_1e = 0;
    local_20 = 0;
    uVar3 = FUN_00165b28();
    uVar4 = FUN_00165b3c(&local_20);
    DAT_00195380 = DAT_00195380 + 1;
    FUN_00165a2c(uVar3,0xffffffffffffffff,uVar4,&DAT_0011dcf5);
    uVar3 = local_28;
    uVar4 = FUN_00165b28(&local_20);
    uVar5 = elf_soname_patch(uVar3,iVar2,uVar4);
    if ((uVar5 & 1) == 0) {
      local_78 = 0;
    }
    else {
      local_70 = 0x210;
      local_68 = 0;
      local_60 = 0;
      local_58 = 0;
      local_50 = 0;
      local_54 = iVar2;
      local_48 = param_4;
      uVar3 = FUN_00165b50();
      uVar4 = FUN_00165b64(&DAT_00194380);
      FUN_00165a2c(uVar3,0xffffffffffffffff,uVar4,"/proc/self/fd/%d",iVar2);
      uVar3 = FUN_00165b50(&DAT_00194380);
      local_78 = android_dlopen_ext(uVar3,param_3,&local_70);
    }
  }
  /* stack canary */
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 == 0) {
    return local_78;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(lVar1);
}




