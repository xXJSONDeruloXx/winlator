/*
 * vk_helpers.c — Named helper functions
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @00173378  size=16 */

uint8_t  [16] FUN_00173378(void)

{
  return ((uint64_t /* was __int128 */)(0));
}


/* @00165b78  size=420 */

void _INIT_0(void)

{
  int iVar1;
  void *__addr;
  long lVar2;
  uint64_t auStack_28;
  void *local_20;
  long local_18;
  
  /* stack canary setup */
  local_18 = *(long *)(lVar2 + 0x28);
  iVar1 = FUN_00165d1c();
  if (iVar1 + -0x1b != 0 && 0x1a < iVar1) {
    local_20 = (void *)FUN_00165dec(iVar1 + -0x1b,auStack_28);
    __addr = (void *)FUN_00165e7c(&local_20);
    iVar1 = getpagesize();
    mprotect(__addr,(long)iVar1,7);
    lVar2 = (*local_20)("ld-android.so",1,dlopen);
    if ((((lVar2 != 0) &&
         (android_link_namespaces_all_libs =
               dlsym(lVar2,"__loader_android_link_namespaces_all_libs"),
         android_link_namespaces_all_libs != 0)) &&
        (android_link_namespaces = dlsym(lVar2,"__loader_android_link_namespaces"),
        android_link_namespaces != 0)) &&
       (((lVar2 = (*local_20)("libdl_android.so",1,dlopen), lVar2 != 0 &&
         (DAT_00194350 = dlsym(lVar2,"__loader_android_create_namespace"), DAT_00194350 != 0)) &&
        (android_get_exported_namespace = dlsym(lVar2,"__loader_android_get_exported_namespace"),
        android_get_exported_namespace != 0)))) {
      DAT_00194348 = 1;
    }
  }
  /* stack canary setup */
  lVar2 = *(long *)(lVar2 + 0x28) - local_18;
  if (lVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}


/* @00187e6c  size=156 */

void _INIT_1(void)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  uint32_t uVar4;
  char acStack_6c [92];
  
  uVar3 = getauxval(0x10);
  if (((uint32_t)uVar3 >> 8 & 1) != 0) {
    iVar2 = __system_property_get("ro.arch",acStack_6c);
    uVar1 = (uint32_t)((unsigned long)uVar3 >> 8);
    if (iVar2 < 1) {
      uVar4 = uVar1 & 1;
    }
    else {
      iVar2 = strncmp(acStack_6c,"exynos9810",10);
      uVar4 = 0;
      if (iVar2 != 0) {
        uVar4 = uVar1 & 1;
      }
    }
    DAT_00195660 = uVar4 != 0;
    return;
  }
  DAT_00195660 = 0;
  return;
}


/* @0016ece8  size=60 */

void __cxa_allocate_dependent_exception(void)

{
  uint64_t *puVar1;
  
  puVar1 = (uint64_t *)FUN_001858b8(0x80);
  if (puVar1 != (uint64_t *)0x0) {
    puVar1[0xd] = 0;
    puVar1[0xc] = 0;
    puVar1[0xf] = 0;
    puVar1[0xe] = 0;
    puVar1[9] = 0;
    puVar1[8] = 0;
    puVar1[0xb] = 0;
    puVar1[10] = 0;
    puVar1[5] = 0;
    puVar1[4] = 0;
    puVar1[7] = 0;
    puVar1[6] = 0;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[2] = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


/* @0016ec70  size=80 */

long __cxa_allocate_exception(long param_1)

{
  void *__s;
  unsigned long __n;
  
  __n = param_1 + 0x8fU & 0xfffffffffffffff0;
                    /* try { // try from 0016ec88 to 0016ec8f has its CatchHandler @ 0016ecc0 */
  __s = (void *)FUN_001858b8(__n);
  if (__s != (void *)0x0) {
    memset(__s,0,__n);
    return (long)__s + 0x80;
  }
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


/* @0016ee60  size=156 */

unsigned long * __cxa_begin_catch(unsigned long *param_1)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  unsigned long *puVar4;
  unsigned long *puVar5;
  unsigned long uVar6;
  
  uVar6 = *param_1;
                    /* try { // try from 0016ee78 to 0016ee7b has its CatchHandler @ 0016eefc */
  plVar3 = (long *)__cxa_get_globals();
  puVar4 = param_1 + -0xc;
  if (uVar6 >> 8 == 0x434c4e47432b2b) {
    iVar2 = (int)param_1[-5];
    puVar5 = (unsigned long *)*plVar3;
    iVar1 = -iVar2;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
    *(int *)(param_1 + -5) = iVar1 + 1;
    if (puVar5 != puVar4) {
      param_1[-6] = (unsigned long)puVar5;
      *plVar3 = (long)puVar4;
    }
    param_1 = (unsigned long *)param_1[-1];
    *(int *)(plVar3 + 1) = (int)plVar3[1] + -1;
  }
  else {
    if (*plVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      std::terminate();
    }
    *plVar3 = (long)puVar4;
    param_1 = param_1 + 4;
  }
  return param_1;
}


/* @00185408  size=112 */

void __cxa_call_unexpected(long param_1)

{
  unsigned long uVar1;
  uint64_t uVar2;
  
  if (param_1 == 0) {
    __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
    std::terminate();
  }
  __cxa_begin_catch();
  uVar1 = FUN_0016ec4c(param_1);
  if ((uVar1 & 1) == 0) {
    std::get_terminate();
    uVar2 = std::get_unexpected();
  }
  else {
    uVar2 = *(uint64_t *)(param_1 + -0x40);
  }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00185474 to 00185477 has its CatchHandler @ 00185478 */
  FUN_0016f854(uVar2);
}


/* @0016f040  size=80 */

uint64_t __cxa_current_exception_type(void)

{
  long *plVar1;
  uint64_t uVar2;
  long lVar3;
  
  plVar1 = (long *)__cxa_get_globals_fast();
  uVar2 = 0;
  if (plVar1 != (long *)0x0) {
    lVar3 = *plVar1;
    if ((lVar3 == 0) || (*(unsigned long *)(lVar3 + 0x60) >> 8 != 0x434c4e47432b2b)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint64_t *)(lVar3 + 0x10);
    }
  }
  return uVar2;
}


/* @0016f1a8  size=124 */

long __cxa_current_primary_exception(void)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
                    /* try { // try from 0016f1b8 to 0016f1bb has its CatchHandler @ 0016f224 */
  plVar1 = (long *)__cxa_get_globals_fast();
  if (((plVar1 == (long *)0x0) || (lVar2 = *plVar1, lVar2 == 0)) ||
     (*(unsigned long *)(lVar2 + 0x60) >> 8 != 0x434c4e47432b2b)) {
    lVar3 = 0;
  }
  else {
    if ((*(unsigned long *)(lVar2 + 0x60) & 0xff) == 1) {
      lVar2 = *(long *)(lVar2 + 8) + -0x80;
    }
    lVar3 = lVar2 + 0x80;
    FUN_00187f40(1,lVar2 + 8);
  }
  return lVar3;
}


/* @0016efe4  size=84 */

void __cxa_decrement_exception_refcount(long param_1)

{
  long lVar1;
  
  if ((param_1 != 0) && (lVar1 = FUN_00187f40(0xffffffffffffffff,param_1 + -0x78), lVar1 == 1)) {
    if (*(void **)(param_1 + -0x68) != (void *)0x0) {
                    /* try { // try from 0016f018 to 0016f01f has its CatchHandler @ 0016f038 */
      ((generic_fn_t)(*(void **)(param_1 + -0x68)))(param_1);
    }
                    /* try { // try from 0016f024 to 0016f027 has its CatchHandler @ 0016f03c */
    FUN_00185a84(param_1 + -0x80);
  }
  return;
}


/* @001875d4  size=24 */

void __cxa_deleted_virtual(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_0016f708("Deleted virtual function called!");
}


/* @0016fac4  size=1688 */

void * __cxa_demangle(uint8_t *param_1,void *param_2,unsigned long *param_3,uint32_t *param_4)

{
  uint8_t bVar1;
  long lVar2;
  size_t sVar3;
  long *plVar4;
  long *plVar5;
  uint32_t uVar6;
  long lVar7;
  long *plVar8;
  unsigned long uVar9;
  uint8_t *pbVar10;
  uint8_t *pbVar11;
  uint8_t *pbVar12;
  uint8_t *pbVar13;
  void *pvVar14;
  unsigned long uVar15;
  void *local_13e8;
  unsigned long local_13e0;
  size_t local_13d8;
  uint64_t local_13d0;
  long local_13c8;
  uint8_t *local_13c0;
  uint8_t *local_13b8;
  uint64_t *local_13b0;
  uint64_t *puStack_13a8;
  uint64_t **local_13a0;
  uint64_t local_1398;
  uint64_t uStack_1390;
  uint64_t local_1388;
  uint64_t uStack_1380;
  uint64_t local_1378;
  uint64_t uStack_1370;
  uint64_t local_1368;
  uint64_t uStack_1360;
  uint64_t local_1358;
  uint64_t uStack_1350;
  uint64_t local_1348;
  uint64_t uStack_1340;
  uint64_t local_1338;
  uint64_t uStack_1330;
  uint64_t local_1328;
  uint64_t uStack_1320;
  uint64_t local_1318;
  uint64_t uStack_1310;
  uint64_t local_1308;
  uint64_t uStack_1300;
  uint64_t local_12f8;
  uint64_t uStack_12f0;
  uint64_t local_12e8;
  uint64_t uStack_12e0;
  uint64_t local_12d8;
  uint64_t uStack_12d0;
  uint64_t local_12c8;
  uint64_t uStack_12c0;
  uint64_t local_12b8;
  uint64_t uStack_12b0;
  uint64_t local_12a8;
  uint64_t uStack_12a0;
  uint64_t *local_1298;
  uint64_t *puStack_1290;
  uint64_t **local_1288;
  uint64_t local_1280;
  uint64_t uStack_1278;
  uint64_t uStack_1270;
  uint64_t uStack_1268;
  uint64_t local_1260;
  uint64_t uStack_1258;
  uint64_t uStack_1250;
  uint64_t uStack_1248;
  uint64_t local_1240;
  uint64_t uStack_1238;
  uint64_t uStack_1230;
  uint64_t uStack_1228;
  uint64_t local_1220;
  uint64_t uStack_1218;
  uint64_t uStack_1210;
  uint64_t uStack_1208;
  uint64_t local_1200;
  uint64_t uStack_11f8;
  uint64_t uStack_11f0;
  uint64_t uStack_11e8;
  uint64_t local_11e0;
  uint64_t uStack_11d8;
  uint64_t uStack_11d0;
  uint64_t uStack_11c8;
  uint64_t local_11c0;
  uint64_t uStack_11b8;
  uint64_t uStack_11b0;
  uint64_t uStack_11a8;
  uint64_t local_11a0;
  uint64_t uStack_1198;
  uint64_t uStack_1190;
  uint64_t uStack_1188;
  uint64_t *local_1180;
  uint64_t *local_1178;
  uint64_t **local_1170;
  uint64_t local_1168;
  uint64_t uStack_1160;
  uint64_t local_1158;
  uint64_t uStack_1150;
  uint64_t local_1148;
  uint64_t uStack_1140;
  uint64_t local_1138;
  uint64_t uStack_1130;
  uint64_t *local_1128;
  uint64_t *local_1120;
  uint64_t **local_1118;
  uint64_t local_1110;
  uint64_t uStack_1108;
  uint64_t uStack_1100;
  uint64_t uStack_10f8;
  uint64_t *local_10f0;
  uint64_t *local_10e8;
  uint16_t *local_10e0;
  uint64_t local_10d8;
  uint64_t uStack_10d0;
  uint64_t local_10c8;
  uint64_t uStack_10c0;
  uint16_t local_10b8 [4];
  uint64_t local_10b0;
  uint64_t local_10a8;
  uint32_t local_10a0;
  long local_1090;
  uint64_t uStack_1088;
  long *local_90;
  long local_78;
  
  /* stack canary setup */
  local_78 = *(long *)(lVar2 + 0x28);
  if ((param_1 == (uint8_t *)0x0) || ((param_2 != (void *)0x0 && (param_3 == (unsigned long *)0x0)))) {
    pvVar14 = (void *)0x0;
    if (param_4 != (uint32_t *)0x0) {
      *param_4 = 0xfffffffd;
    }
    goto LAB_001700ec;
  }
  sVar3 = strlen((char *)param_1);
  local_13b8 = param_1 + sVar3;
  uStack_12b0 = 0;
  local_12b8 = 0;
  uStack_1130 = 0;
  local_1138 = 0;
  uStack_1390 = 0;
  local_1398 = 0;
  uStack_1380 = 0;
  local_1388 = 0;
  uStack_1370 = 0;
  local_1378 = 0;
  uStack_1360 = 0;
  local_1368 = 0;
  uStack_1350 = 0;
  local_1358 = 0;
  uStack_1340 = 0;
  local_1348 = 0;
  uStack_1330 = 0;
  local_1338 = 0;
  uStack_1320 = 0;
  local_1328 = 0;
  uStack_1310 = 0;
  local_1318 = 0;
  uStack_1300 = 0;
  local_1308 = 0;
  uStack_12f0 = 0;
  local_12f8 = 0;
  uStack_12e0 = 0;
  local_12e8 = 0;
  uStack_12d0 = 0;
  local_12d8 = 0;
  uStack_12c0 = 0;
  local_12c8 = 0;
  uStack_1278 = 0;
  local_1280 = 0;
  uStack_1268 = 0;
  uStack_1270 = 0;
  uStack_1258 = 0;
  local_1260 = 0;
  uStack_1248 = 0;
  uStack_1250 = 0;
  uStack_1238 = 0;
  local_1240 = 0;
  uStack_1228 = 0;
  uStack_1230 = 0;
  uStack_1218 = 0;
  local_1220 = 0;
  uStack_1208 = 0;
  uStack_1210 = 0;
  uStack_11f8 = 0;
  local_1200 = 0;
  uStack_11e8 = 0;
  uStack_11f0 = 0;
  uStack_11d8 = 0;
  local_11e0 = 0;
  uStack_11c8 = 0;
  uStack_11d0 = 0;
  uStack_11b8 = 0;
  local_11c0 = 0;
  uStack_11a8 = 0;
  uStack_11b0 = 0;
  uStack_1198 = 0;
  local_11a0 = 0;
  uStack_1188 = 0;
  uStack_1190 = 0;
  uStack_1108 = 0;
  local_1110 = 0;
  uStack_10f8 = 0;
  uStack_1100 = 0;
  uStack_1088 = 0;
  local_1090 = 0;
  uStack_1140 = 0;
  local_1148 = 0;
  uStack_12a0 = 0;
  local_12a8 = 0;
  uStack_1150 = 0;
  local_1158 = 0;
  uStack_1160 = 0;
  local_1168 = 0;
  uStack_10c0 = 0;
  local_10c8 = 0;
  uStack_10d0 = 0;
  local_10d8 = 0;
  local_1288 = &local_1180;
  local_1170 = &local_1128;
  local_10b8[0] = 1;
  local_10b0 = 0xffffffffffffffff;
  local_1118 = &local_10f0;
  local_10e0 = local_10b8;
  local_13a0 = &local_1298;
  local_10a0 = 0;
  local_10a8 = 0;
  local_13e8 = (void *)0x0;
  local_13e0 = 0;
  local_13d8 = 0;
  local_13d0 = 0xffffffffffffffff;
  local_13b0 = &local_1398;
  puStack_13a8 = &local_1398;
  local_1298 = &local_1280;
  puStack_1290 = &local_1280;
  local_1180 = &local_1168;
  local_1178 = &local_1168;
  local_1128 = &local_1110;
  local_1120 = &local_1110;
  local_10f0 = &local_10d8;
  local_10e8 = &local_10d8;
  local_90 = &local_1090;
  if ((sVar3 < 2) || (*param_1 != 0x5f)) {
LAB_0016fd64:
    local_13c0 = param_1;
    plVar4 = (long *)FUN_00170b9c(&local_13c0);
    if (local_13b8 == local_13c0) {
LAB_0016ff78:
      if (plVar4 != (long *)0x0) goto LAB_0016ff80;
    }
LAB_0016fd78:
    uVar6 = 0xfffffffe;
    pvVar14 = (void *)0x0;
    uVar15 = local_13e0;
  }
  else {
    if (param_1[1] != 0x5a) {
      if ((sVar3 < 3) || (param_1[1] != 0x5f)) goto LAB_0016fd64;
      if (param_1[2] == 0x5a) {
        lVar7 = 3;
        goto LAB_0016fcb0;
      }
      if (sVar3 < 4) goto LAB_0016fd64;
      if ((param_1[2] == 0x5f) && (param_1[3] == 0x5a)) {
        lVar7 = 4;
      }
      else {
        if ((sVar3 < 5) || (((param_1[2] != 0x5f || (param_1[3] != 0x5f)) || (param_1[4] != 0x5a))))
        goto LAB_0016fd64;
        lVar7 = 5;
      }
      local_13c0 = param_1 + lVar7;
      local_13c8 = FUN_00170240(&local_13c0);
      if (((((local_13c8 == 0) || ((unsigned long)((long)local_13b8 - (long)local_13c0) < 0xd)) ||
           ((*local_13c0 != 0x5f || ((local_13c0[1] != 0x62 || (local_13c0[2] != 0x6c)))))) ||
          (local_13c0[3] != 0x6f)) ||
         ((((((local_13c0[4] != 99 || (local_13c0[5] != 0x6b)) || (local_13c0[6] != 0x5f)) ||
            ((local_13c0[7] != 0x69 || (local_13c0[8] != 0x6e)))) ||
           ((local_13c0[9] != 0x76 || ((local_13c0[10] != 0x6f || (local_13c0[0xb] != 0x6b)))))) ||
          (local_13c0[0xc] != 0x65)))) goto LAB_0016fd78;
      pbVar10 = local_13c0 + 0xd;
      if (pbVar10 != local_13b8) {
        bVar1 = *pbVar10;
        if (bVar1 == 0x5f) {
          pbVar10 = local_13c0 + 0xe;
        }
        local_13c0 = pbVar10;
        if (local_13b8 == pbVar10) {
          pbVar11 = (uint8_t *)0x0;
          pbVar12 = local_13b8;
          pbVar13 = (uint8_t *)0x0;
        }
        else if (*pbVar10 - 0x30 < 10) {
          do {
            local_13c0 = local_13c0 + 1;
            pbVar11 = pbVar10;
            pbVar12 = local_13b8;
            pbVar13 = local_13b8;
            if (local_13c0 == local_13b8) break;
            pbVar12 = local_13c0;
            pbVar13 = local_13c0;
          } while (*local_13c0 - 0x30 < 10);
        }
        else {
          pbVar11 = (uint8_t *)0x0;
          pbVar12 = pbVar10;
          pbVar13 = (uint8_t *)0x0;
        }
        if ((bVar1 == 0x5f) && (pbVar11 == pbVar13)) goto LAB_0016fd78;
        pbVar10 = local_13c0;
        if (local_13b8 != pbVar12) {
          if (*pbVar12 != 0x2e) goto LAB_0016fd78;
          local_13c0 = local_13b8;
          pbVar10 = local_13c0;
        }
      }
      local_13c0 = pbVar10;
      plVar4 = (long *)FUN_00170af4(&local_13c0,"invocation function for block in ",&local_13c8);
      goto LAB_0016ff78;
    }
    lVar7 = 2;
LAB_0016fcb0:
    local_13c0 = param_1 + lVar7;
                    /* try { // try from 0016fcb8 to 0016fffb has its CatchHandler @ 0017015c */
    plVar4 = (long *)FUN_00170240(&local_13c0);
    plVar8 = local_90;
    pbVar11 = local_13b8;
    pbVar10 = local_13c0;
    if (plVar4 == (long *)0x0) goto LAB_0016fd78;
    if (local_13b8 != local_13c0) {
      if (*local_13c0 != 0x2e) goto LAB_0016fd78;
      lVar7 = local_90[1];
      if (0xfef < lVar7 + 0x30U) {
        plVar5 = malloc(0x1000);
        if (plVar5 == (long *)0x0) goto LAB_00170154;
        lVar7 = 0;
        *plVar5 = (long)plVar8;
        plVar5[1] = 0;
        local_90 = plVar5;
      }
      local_90[1] = lVar7 + 0x30;
      plVar8 = (long *)((long)local_90 + lVar7 + 0x10);
      *plVar8 = (long)&PTR_FUN_0018fe40;
      *(uint32_t *)((long)local_90 + lVar7 + 0x18) = 0x1010101;
      *(long **)((long)local_90 + lVar7 + 0x20) = plVar4;
      *(uint8_t **)((long)local_90 + lVar7 + 0x28) = pbVar10;
      *(uint8_t **)((long)local_90 + lVar7 + 0x30) = pbVar11;
      local_13c0 = local_13b8;
      plVar4 = plVar8;
    }
LAB_0016ff80:
    if (param_2 == (void *)0x0) {
      uVar15 = 0x400;
      param_2 = malloc(0x400);
      if (param_2 == (void *)0x0) {
        uVar6 = 0xffffffff;
        pvVar14 = (void *)0x0;
        uVar15 = local_13e0;
        goto joined_r0x00170140;
      }
    }
    else {
      uVar15 = *param_3;
    }
    local_13e0 = 0;
    local_13e8 = param_2;
    local_13d8 = uVar15;
    ((generic_fn_t)(*(void **)(*plVar4 + 0x20)))(plVar4,&local_13e8);
    if (*(char *)((long)plVar4 + 9) != '\x01') {
      ((generic_fn_t)(*(void **)(*plVar4 + 0x28)))(plVar4,&local_13e8);
    }
    uVar15 = local_13e0 + 1;
    if (local_13d8 <= uVar15) {
      uVar9 = local_13d8 << 1;
      local_13d8 = uVar15;
      if (uVar15 <= uVar9) {
        local_13d8 = uVar9;
      }
      local_13e8 = realloc(local_13e8,local_13d8);
      if (local_13e8 == (void *)0x0) {
LAB_00170154:
                    /* WARNING: Subroutine does not return */
        std::terminate();
      }
      uVar15 = local_13e0 + 1;
    }
    *(uint8_t *)((long)local_13e8 + local_13e0) = 0;
    if (param_3 != (unsigned long *)0x0) {
      *param_3 = uVar15;
    }
    uVar6 = 0;
    pvVar14 = local_13e8;
  }
joined_r0x00170140:
  local_13e0 = uVar15;
  plVar4 = local_90;
  if (param_4 != (uint32_t *)0x0) {
    *param_4 = uVar6;
  }
  while (local_90 = plVar4, local_90 != (long *)0x0) {
    while (plVar4 = (long *)*local_90, &local_1090 != local_90) {
      plVar4 = local_90;
      local_90 = (long *)*local_90;
      free(plVar4);
      if (local_90 == (long *)0x0) goto LAB_00170090;
    }
  }
LAB_00170090:
  local_1090 = 0;
  uStack_1088 = 0;
  local_90 = &local_1090;
  if (local_10f0 != &local_10d8) {
    free(local_10f0);
  }
  if (local_1128 != &local_1110) {
    free(local_1128);
  }
  if (local_1180 != &local_1168) {
    free(local_1180);
  }
  if (local_1298 != &local_1280) {
    free(local_1298);
  }
  if (local_13b0 != &local_1398) {
    free(local_13b0);
  }
LAB_001700ec:
  if (*(long *)(lVar2 + 0x28) != local_78) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar14;
}


/* @0016ef00  size=220 */

void __cxa_end_catch(void)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  plVar2 = (long *)__cxa_get_globals_fast();
  lVar3 = *plVar2;
  if (lVar3 == 0) {
    return;
  }
  if (*(unsigned long *)(lVar3 + 0x60) >> 8 == 0x434c4e47432b2b) {
    iVar1 = *(int *)(lVar3 + 0x38);
    if (-1 < iVar1) {
      *(int *)(lVar3 + 0x38) = iVar1 + -1;
      if (iVar1 + -1 != 0) {
        return;
      }
      *plVar2 = *(long *)(lVar3 + 0x30);
      lVar4 = lVar3;
      if (*(char *)(lVar3 + 0x60) == '\x01') {
        lVar4 = *(long *)(lVar3 + 8) + -0x80;
        FUN_00185a84(lVar3);
      }
      lVar3 = FUN_00187f40(0xffffffffffffffff,lVar4 + 8);
      if (lVar3 != 1) {
        return;
      }
      if (*(void **)(lVar4 + 0x18) != (void *)0x0) {
                    /* try { // try from 0016ef98 to 0016ef9f has its CatchHandler @ 0016efdc */
        ((generic_fn_t)(*(void **)(lVar4 + 0x18)))(lVar4 + 0x80);
      }
                    /* try { // try from 0016efa0 to 0016efa7 has its CatchHandler @ 0016efe0 */
      FUN_00185a84(lVar4);
      return;
    }
    *(int *)(lVar3 + 0x38) = iVar1 + 1;
    if (iVar1 != -1) {
      return;
    }
    lVar3 = *(long *)(lVar3 + 0x30);
  }
  else {
    FUN_001883e8();
    lVar3 = 0;
  }
  *plVar2 = lVar3;
  return;
}


/* @0016ed24  size=8 */

void __cxa_free_dependent_exception(void)

{
  FUN_00185a84();
  return;
}


/* @0016ecc4  size=32 */

void __cxa_free_exception(long param_1)

{
                    /* try { // try from 0016ecd4 to 0016ecd7 has its CatchHandler @ 0016ece4 */
  FUN_00185a84(param_1 + -0x80);
  return;
}


/* @0016ee54  size=12 */

uint64_t __cxa_get_exception_ptr(long param_1)

{
  return *(uint64_t *)(param_1 + -8);
}


/* @0016f414  size=36 */

void __cxa_get_globals(void)

{
  __emutls_get_address(&DAT_00193a88);
  return;
}


/* @0016f438  size=36 */

void __cxa_get_globals_fast(void)

{
  __emutls_get_address(&DAT_00193a88);
  return;
}


/* @0016f664  size=160 */

void __cxa_guard_abort(long param_1)

{
  uint8_t bVar1;
  int iVar2;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0016f708("%s failed to acquire mutex","__cxa_guard_abort");
  }
  bVar1 = *(uint8_t *)(param_1 + 1);
  *(uint32_t *)(param_1 + 4) = 0;
  *(uint8_t *)(param_1 + 1) = 0;
                    /* try { // try from 0016f694 to 0016f69f has its CatchHandler @ 0016f704 */
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 == 0) {
    if (((bVar1 >> 2 & 1) != 0) &&
       (iVar2 = pthread_cond_broadcast((pthread_cond_t *)&DAT_001953ac), iVar2 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to broadcast","__cxa_guard_abort");
    }
    return;
  }
                    /* try { // try from 0016f6dc to 0016f6ef has its CatchHandler @ 0016f704 */
                    /* WARNING: Subroutine does not return */
  FUN_0016f708("%s failed to release mutex","__cxa_guard_abort");
}


/* @0016f45c  size=284 */

uint32_t __cxa_guard_acquire(char *param_1)

{
  uint8_t bVar1;
  uint8_t bVar2;
  int iVar3;
  long lVar4;
  uint32_t uVar5;
  int unaff_w20;
  
  if (*param_1 == '\0') {
    iVar3 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00195384);
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to acquire mutex","__cxa_guard_acquire");
    }
    bVar1 = param_1[1];
    if ((bVar1 >> 1 & 1) != 0) {
      iVar3 = *(int *)(param_1 + 4);
                    /* try { // try from 0016f4a4 to 0016f4ab has its CatchHandler @ 0016f578 */
      lVar4 = syscall(0xb2);
      unaff_w20 = (int)lVar4;
      if (iVar3 == unaff_w20) {
                    /* try { // try from 0016f56c to 0016f577 has its CatchHandler @ 0016f578 */
                    /* WARNING: Subroutine does not return */
        FUN_0016f708("__cxa_guard_acquire detected recursive initialization");
      }
    }
    while (bVar2 = param_1[1], (bVar2 >> 1 & 1) != 0) {
      param_1[1] = bVar2 | 4;
                    /* try { // try from 0016f4d8 to 0016f4e3 has its CatchHandler @ 0016f580 */
      pthread_cond_wait((pthread_cond_t *)&DAT_001953ac,(pthread_mutex_t *)&DAT_00195384);
    }
    if (bVar2 == 1) {
      uVar5 = 0;
    }
    else {
      if ((bVar1 >> 1 & 1) == 0) {
                    /* try { // try from 0016f4fc to 0016f503 has its CatchHandler @ 0016f578 */
        lVar4 = syscall(0xb2);
        unaff_w20 = (int)lVar4;
      }
      *(int *)(param_1 + 4) = unaff_w20;
      param_1[1] = '\x02';
      uVar5 = 1;
    }
                    /* try { // try from 0016f518 to 0016f523 has its CatchHandler @ 0016f57c */
    iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00195384);
    if (iVar3 != 0) {
                    /* try { // try from 0016f558 to 0016f56b has its CatchHandler @ 0016f57c */
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to release mutex","__cxa_guard_acquire");
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* @0016f5b4  size=172 */

void __cxa_guard_release(uint32_t *param_1)

{
  uint8_t bVar1;
  int iVar2;
  
  *param_1 = 1;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0016f708("%s failed to acquire mutex","__cxa_guard_release");
  }
  bVar1 = *(uint8_t *)((long)param_1 + 1);
  *(uint8_t *)((long)param_1 + 1) = 1;
                    /* try { // try from 0016f5ec to 0016f5f7 has its CatchHandler @ 0016f660 */
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 == 0) {
    if (((bVar1 >> 2 & 1) != 0) &&
       (iVar2 = pthread_cond_broadcast((pthread_cond_t *)&DAT_001953ac), iVar2 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to broadcast","__cxa_guard_release");
    }
    return;
  }
                    /* try { // try from 0016f638 to 0016f64b has its CatchHandler @ 0016f660 */
                    /* WARNING: Subroutine does not return */
  FUN_0016f708("%s failed to release mutex","__cxa_guard_release");
}


/* @0016f17c  size=44 */

void __cxa_increment_exception_refcount(long param_1)

{
  if (param_1 != 0) {
    FUN_00187f40(1,param_1 + -0x78);
  }
  return;
}


/* @001875bc  size=24 */

void __cxa_pure_virtual(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_0016f708("Pure virtual function called!");
}


/* @0016f090  size=232 */

void __cxa_rethrow(void)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  unsigned long uVar4;
  long lVar5;
  unsigned long *puVar6;
  long lVar7;
  unsigned long uVar8;
  
  plVar3 = (long *)__cxa_get_globals();
  lVar7 = *plVar3;
  if (lVar7 != 0) {
    puVar6 = (unsigned long *)(lVar7 + 0x60);
    uVar4 = *puVar6;
    if ((uVar4 & 0xffffffffffffff00) == 0x434c4e47432b2b00) {
      lVar5 = plVar3[1];
      *(int *)(lVar7 + 0x38) = -*(int *)(lVar7 + 0x38);
      *(int *)(plVar3 + 1) = (int)lVar5 + 1;
    }
    else {
      *plVar3 = 0;
    }
    FUN_00187f70(puVar6);
    uVar8 = *puVar6;
                    /* try { // try from 0016f108 to 0016f10b has its CatchHandler @ 0016f178 */
    plVar3 = (long *)__cxa_get_globals();
    if ((uVar8 & 0xffffffffffffff00) == 0x434c4e47432b2b00) {
      iVar2 = *(int *)(lVar7 + 0x38);
      lVar5 = *plVar3;
      iVar1 = -iVar2;
      if (-1 < iVar2) {
        iVar1 = iVar2;
      }
      *(int *)(lVar7 + 0x38) = iVar1 + 1;
      if (lVar5 != lVar7) {
        *(long *)(lVar7 + 0x30) = lVar5;
        *plVar3 = lVar7;
      }
      *(int *)(plVar3 + 1) = (int)plVar3[1] + -1;
    }
    else {
      if (*plVar3 != 0) goto LAB_0016f0b4;
      *plVar3 = lVar7;
    }
    if ((uVar4 & 0xffffffffffffff00) == 0x434c4e47432b2b00) {
                    /* WARNING: Subroutine does not return */
      FUN_0016f8a0(*(uint64_t *)(lVar7 + 0x28));
    }
  }
LAB_0016f0b4:
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


/* @0016f228  size=284 */

void __cxa_rethrow_primary_exception(long param_1)

{
  int iVar1;
  int iVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  long lVar5;
  long *plVar6;
  uint64_t *puVar7;
  unsigned long uVar8;
  unsigned long *puVar9;
  
  if (param_1 != 0) {
    puVar3 = (uint64_t *)FUN_001858b8(0x80);
    if (puVar3 == (uint64_t *)0x0) {
LAB_0016f340:
                    /* WARNING: Subroutine does not return */
      std::terminate();
    }
    puVar3[0xf] = 0;
    puVar3[0xe] = 0;
    puVar3[9] = 0;
    puVar3[8] = 0;
    puVar3[0xb] = 0;
    puVar3[10] = 0;
    puVar3[5] = 0;
    puVar3[4] = 0;
    puVar3[7] = 0;
    puVar3[6] = 0;
    puVar3[1] = 0;
    *puVar3 = 0;
    puVar3[3] = 0;
    puVar3[2] = 0;
    puVar9 = puVar3 + 0xc;
    puVar3[0xd] = 0;
    *puVar9 = 0;
    puVar3[1] = param_1;
    FUN_00187f40(1,param_1 + -0x78);
    puVar3[2] = *(uint64_t *)(param_1 + -0x70);
    uVar4 = std::get_unexpected();
    puVar3[4] = uVar4;
    uVar4 = std::get_terminate();
    puVar3[5] = uVar4;
    *puVar9 = 0x434c4e47432b2b01;
    lVar5 = __cxa_get_globals();
    iVar1 = *(int *)(lVar5 + 8);
    puVar3[0xd] = FUN_0016f348;
    *(int *)(lVar5 + 8) = iVar1 + 1;
    FUN_00187f70(puVar9);
    uVar8 = *puVar9;
                    /* try { // try from 0016f2d8 to 0016f2db has its CatchHandler @ 0016f344 */
    plVar6 = (long *)__cxa_get_globals();
    if ((uVar8 & 0xffffffffffffff00) == 0x434c4e47432b2b00) {
      iVar2 = *(int *)(puVar3 + 7);
      puVar7 = (uint64_t *)*plVar6;
      iVar1 = -iVar2;
      if (-1 < iVar2) {
        iVar1 = iVar2;
      }
      *(int *)(puVar3 + 7) = iVar1 + 1;
      if (puVar7 != puVar3) {
        puVar3[6] = puVar7;
        *plVar6 = (long)puVar3;
      }
      *(int *)(plVar6 + 1) = (int)plVar6[1] + -1;
    }
    else {
      if (*plVar6 != 0) goto LAB_0016f340;
      *plVar6 = (long)puVar3;
    }
  }
  return;
}


/* @0016ed2c  size=128 */

void __cxa_throw(long param_1,uint64_t param_2,uint64_t param_3)

{
  int iVar1;
  long lVar2;
  uint64_t uVar3;
  
  lVar2 = __cxa_get_globals();
  uVar3 = std::get_unexpected();
  *(uint64_t *)(param_1 + -0x60) = uVar3;
  uVar3 = std::get_terminate();
  *(uint64_t *)(param_1 + -0x58) = uVar3;
  *(uint64_t *)(param_1 + -0x70) = param_2;
  *(uint64_t *)(param_1 + -0x68) = param_3;
  FUN_0016edac(param_1 + -0x20);
  iVar1 = *(int *)(lVar2 + 8);
  *(uint64_t *)(param_1 + -0x78) = 1;
  *(int *)(lVar2 + 8) = iVar1 + 1;
  *(void **)(param_1 + -0x18) = FUN_0016edc8;
  FUN_00187f70(param_1 + -0x20);
                    /* WARNING: Subroutine does not return */
  FUN_0016ee30(param_1 + -0x80);
}


/* @0016f3bc  size=44 */

bool __cxa_uncaught_exception(void)

{
  bool bVar1;
  long lVar2;
  
                    /* try { // try from 0016f3c8 to 0016f3cb has its CatchHandler @ 0016f3e8 */
  lVar2 = __cxa_get_globals_fast();
  bVar1 = false;
  if (lVar2 != 0) {
    bVar1 = *(int *)(lVar2 + 8) != 0;
  }
  return bVar1;
}


/* @0016f3ec  size=36 */

uint32_t __cxa_uncaught_exceptions(void)

{
  uint32_t uVar1;
  long lVar2;
  
                    /* try { // try from 0016f3f8 to 0016f3fb has its CatchHandler @ 0016f410 */
  lVar2 = __cxa_get_globals_fast();
  uVar1 = 0;
  if (lVar2 != 0) {
    uVar1 = *(uint32_t *)(lVar2 + 8);
  }
  return uVar1;
}


/* @0018682c  size=324 */

void __dynamic_cast(long *param_1,uint64_t param_2,long param_3,uint64_t param_4)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long local_78;
  long *local_70;
  uint64_t uStack_68;
  uint64_t local_60;
  long local_58;
  long lStack_50;
  uint64_t local_48;
  int iStack_40;
  int iStack_3c;
  int local_38;
  uint32_t uStack_34;
  uint64_t uStack_31;
  long local_28;
  
  /* stack canary setup */
  local_28 = *(long *)(lVar2 + 0x28);
  plVar1 = *(long **)(*param_1 + -8);
  lStack_50 = 0;
  local_58 = 0;
  iStack_40 = 0;
  local_48 = 0;
  uStack_31 = 0;
  iStack_3c = 0;
  local_38 = 0;
  uStack_34 = 0;
  lVar3 = (long)param_1 + *(long *)(*param_1 + -0x10);
  local_78 = param_3;
  local_70 = param_1;
  uStack_68 = param_2;
  local_60 = param_4;
  if (plVar1[1] == *(long *)(param_3 + 8)) {
    uStack_31 = 0x100;
    ((generic_fn_t)(*(void **)(*plVar1 + 0x28)))(plVar1,&local_78,lVar3,lVar3,1,0);
    if ((int)local_48 != 1) {
      lVar3 = 0;
    }
  }
  else {
    ((generic_fn_t)(*(void **)(*plVar1 + 0x30)))(plVar1,&local_78,lVar3,1,0);
    if (iStack_3c == 1) {
      if (((int)local_48 == 1) ||
         (((lVar3 = 0, local_38 == 0 && ((*(uint32_t*)((char*)&local_48 + 4)) == 1)) && (iStack_40 == 1)))) {
        lVar3 = local_58;
      }
    }
    else if (iStack_3c == 0) {
      lVar3 = lStack_50;
      if ((iStack_40 != 1 || (*(uint32_t*)((char*)&local_48 + 4)) != 1) || local_38 != 1) {
        lVar3 = 0;
      }
    }
    else {
      lVar3 = 0;
    }
  }
  if (*(long *)(lVar2 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(lVar3);
}


/* @00184cf8  size=464 */

void __gxx_personality_v0(int param_1,unsigned long param_2,unsigned long param_3,long param_4,long param_5)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint64_t uVar4;
  long local_78;
  uint64_t uStack_70;
  uint64_t local_68;
  uint64_t uStack_60;
  uint64_t local_58;
  int local_50;
  long local_48;
  
  /* stack canary setup */
  local_48 = *(long *)(lVar1 + 0x28);
  iVar3 = 3;
  if (((param_1 == 1) && (param_4 != 0)) && (param_5 != 0)) {
    param_3 = param_3 & 0xffffffffffffff00;
    if ((param_2 & 1) == 0) {
      if (((uint32_t)param_2 >> 1 & 1) == 0) {
        iVar3 = 3;
      }
      else {
        if (((uint32_t)param_2 >> 2 & 1) == 0) {
          FUN_00184ec8(&local_78,param_2,param_3 == 0x434c4e47432b2b00,param_4,param_5);
          iVar3 = local_50;
          if (local_50 != 6) goto LAB_00184e8c;
          thunk_FUN_0018859c(param_5,0,param_4);
          thunk_FUN_0018859c(param_5,1,local_78);
          uVar4 = uStack_60;
        }
        else {
          if (param_3 == 0x434c4e47432b2b00) {
            local_78 = (long)*(int *)(param_4 + -0x24);
            uStack_70 = *(uint64_t *)(param_4 + -0x20);
            local_68 = *(uint64_t *)(param_4 + -0x18);
            uStack_60 = *(uint64_t *)(param_4 + -0x10);
            local_58 = *(uint64_t *)(param_4 + -8);
          }
          else {
            FUN_00184ec8(&local_78,param_2,0,param_4,param_5);
            if (local_50 != 6) {
              __cxa_begin_catch(param_4);
                    /* WARNING: Subroutine does not return */
              std::terminate();
            }
          }
          uVar4 = uStack_60;
          lVar2 = local_78;
          thunk_FUN_0018859c(param_5,0,param_4);
          thunk_FUN_0018859c(param_5,1,lVar2);
        }
        FUN_00188468(param_5,uVar4);
        iVar3 = 7;
      }
    }
    else {
      FUN_00184ec8(&local_78,param_2,param_3 == 0x434c4e47432b2b00,param_4,param_5);
      iVar3 = local_50;
      if ((local_50 == 6) && (param_3 == 0x434c4e47432b2b00)) {
        iVar3 = 6;
        *(int *)(param_4 + -0x24) = (int)local_78;
        *(uint64_t *)(param_4 + -0x20) = uStack_70;
        *(uint64_t *)(param_4 + -0x10) = uStack_60;
        *(uint64_t *)(param_4 + -0x18) = local_68;
        *(uint64_t *)(param_4 + -8) = local_58;
      }
    }
  }
LAB_00184e8c:
  if (*(long *)(lVar1 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar3);
  }
  return;
}


/* @00164998  size=124 */

/* std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>
   >::basic_string<decltype(nullptr)>(char const*) */

void __thiscall
std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
basic_string<decltype(nullptr)>
          (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *this,
          char *param_1)

{
  long lVar1;
  unsigned long uVar2;
  __default_init_tag a_Stack_28 [8];
  __default_init_tag a_Stack_20 [8];
  long local_18;
  
  /* stack canary setup */
  local_18 = *(long *)(lVar1 + 0x28);
  __compressed_pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::__rep,std::__ndk1::allocator<char>>
  ::__compressed_pair<std::__ndk1::__default_init_tag,std::__ndk1::__default_init_tag>
            ((__compressed_pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::__rep,std::__ndk1::allocator<char>>
              *)this,a_Stack_20,a_Stack_28);
  uVar2 = char_traits<char>::length(param_1);
  __init(this,param_1,uVar2);
  lVar1 = *(long *)(lVar1 + 0x28) - local_18;
  if (lVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(lVar1);
}


/* @0016a450  size=60 */

/* std::__ndk1::basic_string<wchar_t, std::__ndk1::char_traits<wchar_t>,
   std::__ndk1::allocator<wchar_t> >::append(wchar_t const*) */

void __thiscall
std::__ndk1::basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
::append(basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
         *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  append(this,param_1,sVar1);
  return;
}


/* @0016a160  size=60 */

/* std::__ndk1::basic_string<wchar_t, std::__ndk1::char_traits<wchar_t>,
   std::__ndk1::allocator<wchar_t> >::assign(wchar_t const*) */

void __thiscall
std::__ndk1::basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
::assign(basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
         *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  assign(this,param_1,sVar1);
  return;
}


/* @00166b2c  size=160 */

/* std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>
   >::basic_string(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > const&, std::__ndk1::allocator<char> const&) */

void std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
     basic_string(basic_string *param_1,allocator *param_2)

{
  unsigned long uVar1;
  void *__src;
  basic_string *__dest;
  unsigned long uVar2;
  uint64_t uVar3;
  uint64_t uVar4;
  
  if (((uint8_t)*param_2 & 1) == 0) {
    uVar4 = *(uint64_t *)(param_2 + 8);
    uVar3 = *(uint64_t *)param_2;
    *(uint64_t *)(param_1 + 0x10) = *(uint64_t *)(param_2 + 0x10);
    *(uint64_t *)(param_1 + 8) = uVar4;
    *(uint64_t *)param_1 = uVar3;
  }
  else {
    uVar1 = *(unsigned long *)(param_2 + 8);
    __src = *(void **)(param_2 + 0x10);
    if (uVar1 < 0x17) {
      __dest = param_1 + 1;
      *param_1 = SUB41((int)uVar1 << 1,0);
    }
    else {
      if (0xffffffffffffffef < uVar1) {
                    /* WARNING: Subroutine does not return */
        __basic_string_common<true>::__throw_length_error();
      }
      uVar2 = uVar1 + 0x10 & 0xfffffffffffffff0;
      __dest = operator_new(uVar2);
      *(unsigned long *)(param_1 + 8) = uVar1;
      *(basic_string **)(param_1 + 0x10) = __dest;
      *(unsigned long *)param_1 = uVar2 | 1;
    }
    memcpy(__dest,__src,uVar1 + 1);
  }
  return;
}


/* @00164ab0  size=372 */

/* HookImplParams::HookImplParams(int, char const*, char const*, char const*, char const*, char
   const*, adrenotools_gpu_mapping*) */

void __thiscall
HookImplParams::HookImplParams
          (HookImplParams *this,int param_1,char *param_2,char *param_3,char *param_4,char *param_5,
          char *param_6,adrenotools_gpu_mapping *param_7)

{
  char *local_b0;
  char *local_a0;
  char *local_90;
  char *local_78;
  
  *(int *)this = param_1;
  local_78 = param_2;
  if (param_2 == (char *)0x0) {
    local_78 = "";
  }
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  basic_string<decltype(nullptr)>
            ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
             (this + 8),local_78);
                    /* try { // try from 00164b38 to 00164b3b has its CatchHandler @ 00164c24 */
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  basic_string<decltype(nullptr)>
            ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
             (this + 0x20),param_3);
  local_90 = param_4;
  if (param_4 == (char *)0x0) {
    local_90 = "";
  }
                    /* try { // try from 00164b74 to 00164b7f has its CatchHandler @ 00164c34 */
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  basic_string<decltype(nullptr)>
            ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
             (this + 0x38),local_90);
  local_a0 = param_5;
  if (param_5 == (char *)0x0) {
    local_a0 = "";
  }
                    /* try { // try from 00164bb8 to 00164bc3 has its CatchHandler @ 00164c44 */
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  basic_string<decltype(nullptr)>
            ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
             (this + 0x50),local_a0);
  local_b0 = param_6;
  if (param_6 == (char *)0x0) {
    local_b0 = "";
  }
                    /* try { // try from 00164bfc to 00164c07 has its CatchHandler @ 00164c54 */
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  basic_string<decltype(nullptr)>
            ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
             (this + 0x68),local_b0);
  *(adrenotools_gpu_mapping **)(this + 0x80) = param_7;
  return;
}


/* @001678f0  size=76 */

/* std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>
   >::insert(unsigned long, char const*) */

void __thiscall
std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::insert
          (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *this,
          unsigned long param_1,char *param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_2);
  insert(this,param_1,param_2,sVar1);
  return;
}


/* @0016e464  size=120 */

/* std::logic_error::logic_error(char const*) */

void __thiscall std::logic_error::logic_error(logic_error *this,char *param_1)

{
  long lVar1;
  long *plVar2;
  
  *(uint8_t ***)this = &PTR__length_error_00191150;
                    /* try { // try from 0016e490 to 0016e4a7 has its CatchHandler @ 0016e4dc */
  lVar1 = __strlen_chk(param_1,0xffffffffffffffff);
  plVar2 = operator_new(lVar1 + 0x19);
  *plVar2 = lVar1;
  plVar2[1] = lVar1;
  *(uint32_t *)(plVar2 + 2) = 0;
  memcpy(plVar2 + 3,param_1,lVar1 + 1);
  *(long **)(this + 8) = plVar2 + 3;
  return;
}


/* @00166388  size=8 */

/* operator delete(void*) */

void operator_delete(void *param_1)

{
  free(param_1);
  return;
}


/* @001663a0  size=8 */

/* operator delete[](void*) */

void operator_delete__(void *param_1)

{
  operator_delete(param_1);
  return;
}


/* @001662a4  size=108 */

/* operator new(unsigned long) */

void * operator_new(unsigned long param_1)

{
  void *pvVar1;
  void *pcVar2;
  bad_alloc *this;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    pvVar1 = malloc(param_1);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    pcVar2 = (void *)std::get_new_handler();
    if (pcVar2 == (void *)0x0) break;
    ((generic_fn_t)pcVar2)();
  }
  this = (bad_alloc *)__cxa_allocate_exception(8);
  std::bad_alloc::bad_alloc(this);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this,&std::bad_alloc::typeinfo,std::bad_exception::~bad_exception);
}


/* @00166350  size=8 */

/* operator new[](unsigned long) */

void * operator_new__(unsigned long param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}


/* @00166ad8  size=84 */

/* std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>
   >::replace(unsigned long, unsigned long, char const*) */

void __thiscall
std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::replace
          (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *this,
          unsigned long param_1,unsigned long param_2,char *param_3)

{
  size_t sVar1;
  
  sVar1 = strlen(param_3);
  replace(this,param_1,param_2,param_3,sVar1);
  return;
}


/* @00165200  size=36 */

/* std::__ndk1::char_traits<char>::length(char const*) */

void std::__ndk1::char_traits<char>::length(char *param_1)

{
  strlen(param_1);
  return;
}


/* @0016d668  size=444 */

/* WARNING: Removing unreachable block (ram,0x0016d6bc) */
/* WARNING: Removing unreachable block (ram,0x0016d6e0) */
/* std::__ndk1::to_string(float) */

void __thiscall std::__ndk1::to_string(__ndk1 *this,float param_1)

{
  char *__s;
  long lVar1;
  uint32_t uVar2;
  unsigned long *in_x8;
  unsigned long uVar3;
  unsigned long uVar4;
  unsigned long uVar5;
  uint64_t local_70;
  unsigned long uStack_68;
  char *local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar1 + 0x28);
  uStack_68 = 0;
  local_70 = 0x2c;
  uVar3 = 0;
  local_60 = (char *)0x0;
  uVar5 = 0x16;
  do {
    while( true ) {
      __s = (char *)((unsigned long)&local_70 | 1);
      if ((uVar3 & 1) != 0) {
        __s = local_60;
      }
      uVar2 = snprintf(__s,uVar5 + 1,"%f",(double)param_1);
      if ((int)uVar2 < 0) {
        uVar4 = uVar5 << 1 | 1;
      }
      else {
        uVar4 = (unsigned long)uVar2;
        if (uVar4 <= uVar5) {
          uVar3 = (unsigned long)((uint8_t)(*(uint8_t*)((char*)&local_70 + 0)) >> 1);
          if ((local_70 & 1) != 0) {
            uVar3 = uStack_68;
          }
          if (uVar3 < uVar4) {
                    /* try { // try from 0016d7a8 to 0016d7b3 has its CatchHandler @ 0016d824 */
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::append
                      ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                        *)&local_70,uVar4 - uVar3,'\0');
          }
          else if ((local_70 & 1) == 0) {
            *(uint8_t *)((long)&local_70 + uVar4 + 1) = 0;
            local_70 = CONCAT71((*(uint64_t*)((char*)&local_70 + 1)),(char)(uVar2 << 1));
          }
          else {
            local_60[uVar4] = '\0';
            uStack_68 = uVar4;
          }
          in_x8[1] = uStack_68;
          *in_x8 = local_70;
          in_x8[2] = (unsigned long)local_60;
          if (*(long *)(lVar1 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return;
        }
      }
      uVar3 = (unsigned long)((uint8_t)(*(uint8_t*)((char*)&local_70 + 0)) >> 1);
      if ((local_70 & 1) != 0) {
        uVar3 = uStack_68;
      }
      uVar5 = uVar4;
      if (uVar4 < uVar3 || uVar4 - uVar3 == 0) break;
                    /* try { // try from 0016d6f0 to 0016d6fb has its CatchHandler @ 0016d828 */
      basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::append
                ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                 &local_70,uVar4 - uVar3,'\0');
LAB_0016d6fc:
      uVar3 = local_70 & 0xff;
    }
    if ((local_70 & 1) == 0) {
      *(uint8_t *)((long)&local_70 + uVar4 + 1) = 0;
      local_70 = CONCAT71((*(uint64_t*)((char*)&local_70 + 1)),(char)((int)uVar4 << 1));
      goto LAB_0016d6fc;
    }
    local_60[uVar4] = '\0';
    uVar3 = local_70 & 0xff;
    uStack_68 = uVar4;
  } while( true );
}


/* @0016dbf4  size=464 */

/* std::__ndk1::to_wstring(float) */

void __thiscall std::__ndk1::to_wstring(__ndk1 *this,float param_1)

{
  long lVar1;
  uint32_t uVar2;
  wchar_t *pwVar3;
  unsigned long *in_x8;
  unsigned long uVar4;
  unsigned long uVar5;
  unsigned long uVar6;
  uint64_t local_70;
  unsigned long uStack_68;
  wchar_t *local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar1 + 0x28);
  pwVar3 = operator_new(0x60);
  uStack_68 = 0x14;
  local_70 = 0x19;
  local_60 = pwVar3;
                    /* try { // try from 0016dc44 to 0016dc4f has its CatchHandler @ 0016ddcc */
  wmemset(pwVar3,L'\0',0x14);
  pwVar3[0x14] = L'\0';
                    /* try { // try from 0016dc54 to 0016dc67 has its CatchHandler @ 0016ddc8 */
  basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>::append
            ((basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
              *)&local_70,3,L'\0');
  uVar4 = local_70 & 0xff;
  uVar6 = local_70 >> 1 & 0x7f;
  if ((local_70 & 1) != 0) {
    uVar6 = uStack_68;
  }
  do {
    while( true ) {
      pwVar3 = (wchar_t *)((unsigned long)&local_70 | 4);
      if ((uVar4 & 1) != 0) {
        pwVar3 = local_60;
      }
      uVar2 = swprintf(pwVar3,uVar6 + 1,L"%f",(double)param_1);
      if ((int)uVar2 < 0) {
        uVar5 = uVar6 << 1 | 1;
      }
      else {
        uVar5 = (unsigned long)uVar2;
        if (uVar5 <= uVar6) {
          uVar6 = (unsigned long)((uint8_t)(*(uint8_t*)((char*)&local_70 + 0)) >> 1);
          if ((local_70 & 1) != 0) {
            uVar6 = uStack_68;
          }
          if (uVar6 < uVar5) {
                    /* try { // try from 0016dd48 to 0016dd53 has its CatchHandler @ 0016ddc4 */
            basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
            ::append((basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
                      *)&local_70,uVar5 - uVar6,L'\0');
          }
          else if ((local_70 & 1) == 0) {
            *(uint32_t *)((long)&local_70 + uVar5 * 4 + 4) = 0;
            local_70 = CONCAT71((*(uint64_t*)((char*)&local_70 + 1)),(char)(uVar2 << 1));
          }
          else {
            local_60[uVar5] = L'\0';
            uStack_68 = uVar5;
          }
          in_x8[1] = uStack_68;
          *in_x8 = local_70;
          in_x8[2] = (unsigned long)local_60;
          if (*(long *)(lVar1 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return;
        }
      }
      uVar4 = (unsigned long)((uint8_t)(*(uint8_t*)((char*)&local_70 + 0)) >> 1);
      if ((local_70 & 1) != 0) {
        uVar4 = uStack_68;
      }
      uVar6 = uVar5;
      if (uVar5 < uVar4 || uVar5 - uVar4 == 0) break;
                    /* try { // try from 0016dc90 to 0016dcbb has its CatchHandler @ 0016ddd0 */
      basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>::
      append((basic_string<wchar_t,std::__ndk1::char_traits<wchar_t>,std::__ndk1::allocator<wchar_t>>
              *)&local_70,uVar5 - uVar4,L'\0');
LAB_0016dc9c:
      uVar4 = local_70 & 0xff;
    }
    if ((local_70 & 1) == 0) {
      *(uint32_t *)((long)&local_70 + uVar5 * 4 + 4) = 0;
      local_70 = CONCAT71((*(uint64_t*)((char*)&local_70 + 1)),(char)((int)uVar5 << 1));
      goto LAB_0016dc9c;
    }
    local_60[uVar5] = L'\0';
    uVar4 = local_70 & 0xff;
    uStack_68 = uVar5;
  } while( true );
}


