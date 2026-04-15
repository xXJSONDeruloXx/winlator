/*
 * vk_loader.c — Driver loading (adrenotools, linkernsbypass)
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @00164c9c  size=408 */

uint8_t adrenotools_import_user_mem(uint64_t *param_1,uint64_t param_2,uint64_t param_3)

{
  long lVar1;
  int __fd;
  int iVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint8_t local_85;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t local_60;
  uint64_t uStack_58;
  uint64_t local_50;
  uint64_t uStack_48;
  uint64_t *local_40;
  uint64_t local_38;
  uint64_t local_30;
  uint32_t local_28;
  uint32_t local_24;
  uint64_t local_20;
  long local_18;
  
  /* stack canary setup */
  local_18 = *(long *)(lVar1 + 0x28);
  local_40 = &local_20;
  local_30 = 0x8c000000;
  local_28 = 2;
  local_24 = 0;
  uStack_48 = 0;
  local_50 = 0;
  uStack_58 = 0;
  local_60 = 0;
  uStack_68 = 0;
  local_70 = 0;
  local_38 = param_3;
  local_20 = param_2;
  uVar4 = __open_2("/dev/kgsl-3d0",2);
  __fd = (int)uVar4;
  if (__fd < 0) {
    local_85 = 0;
  }
  else {
    iVar2 = ioctl(__fd,0xc0200948,&local_40);
    if (iVar2 == 0) {
      uStack_48 = ((uint64_t)((*(uint32_t*)((char*)&uStack_48 + 4))) << 32 | (uint32_t)(local_24));
      iVar2 = ioctl(__fd,0xc0300947,&local_70);
      if (iVar2 == 0) {
        *param_1 = param_2;
        param_1[1] = local_70;
        param_1[2] = param_3;
        param_1[3] = 0xc2600;
        uVar3 = close(__fd);
        uVar4 = (unsigned long)uVar3;
        local_85 = 1;
        goto LAB_00164dfc;
      }
    }
    uVar3 = close(__fd);
    uVar4 = (unsigned long)uVar3;
    local_85 = 0;
  }
LAB_00164dfc:
  /* stack canary setup */
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar1,uVar4);
  }
  return local_85;
}


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


/* @00164e34  size=424 */

uint8_t adrenotools_mem_gpu_allocate(uint64_t *param_1,uint64_t *param_2)

{
  long lVar1;
  int __fd;
  int iVar2;
  uint32_t uVar3;
  unsigned long uVar4;
  uint8_t local_95;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  uint64_t uStack_68;
  uint64_t local_60;
  uint64_t uStack_58;
  uint64_t local_48;
  uint64_t local_40;
  uint64_t local_38;
  uint64_t local_30;
  uint32_t local_28;
  uint32_t local_24;
  uint64_t local_20;
  long local_18;
  
  /* stack canary setup */
  local_18 = *(long *)(lVar1 + 0x28);
  local_48 = *param_2;
  local_40 = 0x8c000000;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  uStack_58 = 0;
  local_60 = 0;
  uStack_68 = 0;
  local_70 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uVar4 = __open_2("/dev/kgsl-3d0",2);
  __fd = (int)uVar4;
  if (__fd < 0) {
    local_95 = 0;
  }
  else {
    iVar2 = ioctl(__fd,0xc0300945,&local_48);
    if (iVar2 == 0) {
      *param_2 = local_30;
      uStack_58 = ((uint64_t)((*(uint32_t*)((char*)&uStack_58 + 4))) << 32 | (uint32_t)(local_28));
      iVar2 = ioctl(__fd,0xc0300947,&local_80);
      if (iVar2 == 0) {
        *param_1 = 0;
        param_1[1] = local_80;
        param_1[2] = *param_2;
        param_1[3] = 0xc2600;
        uVar3 = close(__fd);
        uVar4 = (unsigned long)uVar3;
        local_95 = 1;
        goto LAB_00164fa4;
      }
    }
    uVar3 = close(__fd);
    uVar4 = (unsigned long)uVar3;
    local_95 = 0;
  }
LAB_00164fa4:
  /* stack canary setup */
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar1,uVar4);
  }
  return local_95;
}


/* @001644a0  size=908 */

uint64_t
adrenotools_open_libvulkan
          (uint32_t param_1,uint32_t param_2,char *param_3,char *param_4,char *param_5,char *param_6,
          char *param_7,long param_8)

{
  int iVar1;
  unsigned long uVar2;
  char *__file;
  uint64_t uVar3;
  long lVar4;
  void *pcVar5;
  adrenotools_gpu_mapping *paVar6;
  HookImplParams *this;
  char *local_118;
  uint64_t local_108;
  uint32_t *local_100;
  long *local_f8;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_f0 [24];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_d8 [24];
  stat local_c0;
  uint32_t local_2c;
  long local_28;
  
  /* stack canary setup */
  local_28 = *(long *)(lVar4 + 0x28);
  local_c0.__unused[2] = param_8;
  local_2c = param_2;
  uVar2 = linkernsbypass_load_status();
  if ((uVar2 & 1) == 0) {
    local_108 = 0;
  }
  else {
    iVar1 = FUN_00164884();
    local_118 = param_3;
    if (0x1c < iVar1) {
      local_118 = (char *)0x0;
    }
    if ((((uint8_t)local_2c >> 1 & 1) == 0) && (param_7 != (char *)0x0)) {
      local_108 = 0;
    }
    else if (((local_2c & 1) == 0) && ((param_5 != (char *)0x0 || (param_6 != (char *)0x0)))) {
      local_108 = 0;
    }
    else if ((((uint8_t)local_2c >> 2 & 1) == 0) && (local_c0.__unused[2] != 0)) {
      local_108 = 0;
    }
    else {
      local_c0.__unused[0] = 0;
      local_c0.st_ctim.tv_nsec = 0;
      local_c0.st_ctim.tv_sec = 0;
      local_c0.st_mtim.tv_nsec = 0;
      local_c0.st_mtim.tv_sec = 0;
      local_c0.st_atim.tv_nsec = 0;
      local_c0.st_atim.tv_sec = 0;
      local_c0.st_blocks = 0;
      local_c0.st_blksize = 0;
      local_c0.st_size = 0;
      local_c0.st_rdev = 0;
      local_c0.st_gid = 0;
      local_c0.__pad0 = 0;
      local_c0.st_mode = 0;
      local_c0.st_uid = 0;
      local_c0.st_nlink = 0;
      local_c0.st_ino = 0;
      local_c0.st_dev = 0;
      if ((local_2c & 1) != 0) {
        if ((param_6 == (char *)0x0) || (param_5 == (char *)0x0)) {
          local_108 = 0;
          goto LAB_00164844;
        }
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::basic_string<decltype(nullptr)>(abStack_f0,param_5);
                    /* try { // try from 00164604 to 0016460b has its CatchHandler @ 00164650 */
        FUN_00164954(abStack_d8,abStack_f0,param_6);
        __file = (char *)FUN_00164a14(abStack_d8);
                    /* try { // try from 00164618 to 0016461f has its CatchHandler @ 00164660 */
        iVar1 = stat(__file,&local_c0);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string(abStack_d8);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string(abStack_f0);
        if (iVar1 != 0) {
          local_108 = 0;
          goto LAB_00164844;
        }
      }
      if (((uint8_t)local_2c >> 1 & 1) != 0) {
        if (param_7 == (char *)0x0) {
          local_108 = 0;
          goto LAB_00164844;
        }
        iVar1 = stat(param_7,&local_c0);
        if (iVar1 != 0) {
          local_108 = 0;
          goto LAB_00164844;
        }
      }
      uVar3 = android_create_namespace("adrenotools-libvulkan",param_4,0,2,0);
      uVar2 = linkernsbypass_link_namespace_to_default_all_libs(uVar3);
      if ((uVar2 & 1) == 0) {
        local_108 = 0;
      }
      else {
        lVar4 = linkernsbypass_namespace_dlopen("libhook_impl.so",2,uVar3);
        if (lVar4 == 0) {
          local_108 = 0;
        }
        else {
          pcVar5 = (void *)dlsym(lVar4,"init_hook_param");
          if (pcVar5 == (void *)0x0) {
            local_108 = 0;
          }
          else {
            local_100 = &local_2c;
            local_f8 = local_c0.__unused + 2;
            paVar6 = (adrenotools_gpu_mapping *)FUN_00164a38(&local_100);
            this = operator_new(0x88);
                    /* try { // try from 001647cc to 001647cf has its CatchHandler @ 00164808 */
            HookImplParams::HookImplParams
                      (this,local_2c,local_118,param_4,param_5,param_6,param_7,paVar6);
            ((generic_fn_t)pcVar5)(this);
            lVar4 = linkernsbypass_namespace_dlopen("libmain_hook.so",0x100,uVar3);
            if (lVar4 == 0) {
              local_108 = 0;
            }
            else {
              local_108 = linkernsbypass_namespace_dlopen_unique
                                    ("/system/lib64/libvulkan.so",local_118,param_1,uVar3);
            }
          }
        }
      }
    }
  }
LAB_00164844:
  /* stack canary setup */
  lVar4 = *(long *)(lVar4 + 0x28) - local_28;
  if (lVar4 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return local_108;
}


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
  
  /* stack canary setup */
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
  /* stack canary setup */
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


/* @001655f4  size=176 */

uint32_t linkernsbypass_link_namespace_to_default_all_libs(uint64_t param_1)

{
  int iVar1;
  uint32_t uVar2;
  
  if (((DAT_00194378 & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_00194378), iVar1 != 0)) {
                    /* try { // try from 00165634 to 00165657 has its CatchHandler @ 001656a4 */
    DAT_00194370 = android_create_namespace_escape("default_copy",0,0,2,0);
    __cxa_guard_release(&DAT_00194378);
  }
  uVar2 = (*android_link_namespaces_all_libs)(param_1,DAT_00194370);
  return uVar2 & 1;
}


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
  
  /* stack canary setup */
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
  
  /* stack canary setup */
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
  /* stack canary setup */
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 == 0) {
    return local_78;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(lVar1);
}


