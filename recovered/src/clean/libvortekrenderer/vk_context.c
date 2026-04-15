/*
 * vk_context.c — VkContext lifecycle, dispatch
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015be5c  size=1116 */

int * createVkContext(long *param_1,uint64_t param_2,int param_3,uint64_t param_4)

{
  long lVar1;
  char cVar2;
  uint16_t uVar3;
  int iVar4;
  uint32_t uVar5;
  int iVar6;
  uint32_t uVar7;
  long lVar8;
  int *__arg;
  void *pvVar9;
  uint64_t uVar10;
  char *__s;
  char *pcVar11;
  uint8_t *__arg_00;
  ssize_t sVar12;
  unsigned long uVar13;
  struct msghdr local_150;
  struct iovec local_118;
  uint8_t local_104 [4];
  pthread_t local_100 [18];
  long local_70;
  
  /* stack canary setup */
  local_70 = *(long *)(lVar1 + 0x28);
  lVar8 = FUN_0015c2b8(param_1,param_4,"exposedDeviceExtensions","[Ljava/lang/String;");
  __arg = calloc(1,0x110);
  *__arg = param_3;
  iVar4 = FUN_0015c2b8(param_1,param_4,"vkMaxVersion",&DAT_0011d7ba);
  __arg[1] = iVar4;
  uVar3 = FUN_0015c2b8(param_1,param_4,"maxDeviceMemory",&DAT_0011bed2);
  *(uint16_t *)(__arg + 2) = uVar3;
  uVar3 = FUN_0015c2b8(param_1,param_4,"imageCacheSize",&DAT_0011bed2);
  *(uint16_t *)((long)__arg + 10) = uVar3;
  cVar2 = FUN_0015c2b8(param_1,param_4,"resourceMemoryType",&DAT_0011bcd7);
  __arg[3] = (int)cVar2;
  if (lVar8 == 0) {
    pvVar9 = (void *)0x0;
  }
  else {
    iVar4 = ((generic_fn_t)(*(void **)(*param_1 + 0x558)))(param_1,lVar8);
    pvVar9 = calloc(1,0x10);
    if (0 < iVar4) {
      iVar6 = 0;
      do {
        uVar10 = ((generic_fn_t)(*(void **)(*param_1 + 0x568)))(param_1,lVar8,iVar6);
        __s = (char *)((generic_fn_t)(*(void **)(*param_1 + 0x548)))(param_1,uVar10,0);
        pcVar11 = strdup(__s);
        ArrayList_add(pvVar9,pcVar11);
        ((generic_fn_t)(*(void **)(*param_1 + 0x550)))(param_1,uVar10,__s);
        iVar6 = iVar6 + 1;
      } while (iVar4 != iVar6);
    }
  }
  *(void **)(__arg + 4) = pvVar9;
  pthread_mutex_init((pthread_mutex_t *)(__arg + 0x2a),(pthread_mutexattr_t *)0x0);
  pvVar9 = calloc(0x10000,1);
  *(void **)(__arg + 0x10) = pvVar9;
  __arg_00 = calloc(1,200);
  *__arg_00 = 8;
  __arg_00[2] = 1;
  pthread_mutex_init((pthread_mutex_t *)(__arg_00 + 4),(pthread_mutexattr_t *)0x0);
  pthread_mutex_init((pthread_mutex_t *)(__arg_00 + 0x5c),(pthread_mutexattr_t *)0x0);
  pthread_cond_init((pthread_cond_t *)(__arg_00 + 0x2c),(pthread_condattr_t *)0x0);
  pthread_cond_init((pthread_cond_t *)(__arg_00 + 0x84),(pthread_condattr_t *)0x0);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  pthread_create(local_100,(pthread_attr_t *)0x0,FUN_0015c754,__arg_00);
  pthread_detach(local_100[0]);
  lVar8 = *param_1;
  *(uint8_t **)(__arg + 0x24) = __arg_00;
  ((generic_fn_t)(*(void **)(lVar8 + 0x6d8)))(param_1,__arg + 0x34);
  uVar10 = ((generic_fn_t)(*(void **)(*param_1 + 0xa8)))(param_1,param_2);
  *(uint64_t *)(__arg + 0x38) = uVar10;
  uVar5 = RingBuffer_getSHMemSize(0x400000);
  iVar4 = ashmemCreateRegion("vt-server-ring",uVar5);
  uVar5 = RingBuffer_getSHMemSize(0x40000);
  iVar6 = ashmemCreateRegion("vt-client-ring",uVar5);
  lVar8 = RingBuffer_create(iVar4,0x400000);
  *(long *)(__arg + 0x1c) = lVar8;
  if (lVar8 != 0) {
    lVar8 = RingBuffer_create(iVar6,0x40000);
    *(long *)(__arg + 0x1a) = lVar8;
    if (lVar8 != 0) {
      local_118.iov_base = local_104;
      local_150.msg_control = local_100;
      local_118.iov_len = 1;
      local_150.msg_controllen = 0x18;
      local_100[0] = 0x18;
      local_150.msg_iov = &local_118;
      local_100[2] = ((uint64_t)(iVar6) << 32 | (uint32_t)(iVar4));
      local_104[0] = 0;
      local_150.msg_name = (void *)0x0;
      local_150.msg_namelen = 0;
      local_150.msg_iovlen = 1;
      local_150.msg_flags = 0;
      local_100[1] = 0x100000001;
      sVar12 = sendmsg(*__arg,&local_150,0);
      close(iVar4);
      close(iVar6);
      if (-1 < (int)sVar12) {
        uVar7 = pthread_create((pthread_t *)(__arg + 0x18),(pthread_attr_t *)0x0,FUN_0015c88c,__arg)
        ;
        uVar13 = (unsigned long)uVar7;
        goto LAB_0015c280;
      }
    }
  }
  uVar13 = destroyVkContext(param_1,__arg);
  __arg = (int *)0x0;
LAB_0015c280:
  if (*(long *)(lVar1 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return __arg;
}


/* @0015c4c0  size=420 */

void destroyVkContext(long *param_1,void *param_2)

{
  void *__ptr;
  char *__ptr_00;
  long *plVar1;
  void *pvVar2;
  
  *(uint32_t *)((long)param_2 + 0x78) = 0xfffffffc;
  if (*(long *)((long)param_2 + 0x60) != 0) {
    RingBuffer_setStatus(*(uint64_t *)((long)param_2 + 0x70),2);
    RingBuffer_setStatus(*(uint64_t *)((long)param_2 + 0x68),2);
    pthread_join(*(pthread_t *)((long)param_2 + 0x60),(void **)0x0);
    __ptr_00 = *(char **)((long)param_2 + 0x90);
    if (__ptr_00 != (char *)0x0) {
      pthread_mutex_lock((pthread_mutex_t *)(__ptr_00 + 4));
      plVar1 = (long *)(__ptr_00 + 0xb8);
      __ptr = (void *)*plVar1;
      while (__ptr != (void *)0x0) {
        pvVar2 = *(void **)((long)__ptr + 0x10);
        free(__ptr);
        __ptr = pvVar2;
      }
      __ptr_00[2] = '\0';
      *plVar1 = 0;
      __ptr_00[0xc0] = '\0';
      __ptr_00[0xc1] = '\0';
      __ptr_00[0xc2] = '\0';
      __ptr_00[0xc3] = '\0';
      __ptr_00[0xc4] = '\0';
      __ptr_00[0xc5] = '\0';
      __ptr_00[0xc6] = '\0';
      __ptr_00[199] = '\0';
      pthread_cond_broadcast((pthread_cond_t *)(__ptr_00 + 0x2c));
      pthread_mutex_unlock((pthread_mutex_t *)(__ptr_00 + 4));
      pthread_mutex_lock((pthread_mutex_t *)(__ptr_00 + 0x5c));
      while ((((__ptr_00[2] == '\0' && (*__ptr_00 != '\0')) || (*plVar1 != 0)) ||
             (__ptr_00[1] != '\0'))) {
        pthread_cond_wait((pthread_cond_t *)(__ptr_00 + 0x84),(pthread_mutex_t *)(__ptr_00 + 0x5c));
      }
      pthread_mutex_unlock((pthread_mutex_t *)(__ptr_00 + 0x5c));
      pthread_mutex_destroy((pthread_mutex_t *)(__ptr_00 + 4));
      pthread_cond_destroy((pthread_cond_t *)(__ptr_00 + 0x2c));
      pthread_cond_destroy((pthread_cond_t *)(__ptr_00 + 0x84));
      free(__ptr_00);
    }
    *(uint64_t *)((long)param_2 + 0x90) = 0;
    *(uint64_t *)((long)param_2 + 0x60) = 0;
    RingBuffer_free(*(uint64_t *)((long)param_2 + 0x70));
    RingBuffer_free(*(uint64_t *)((long)param_2 + 0x68));
  }
  if (*(long *)((long)param_2 + 0xe0) != 0) {
    ((generic_fn_t)(*(void **)(*param_1 + 0xb0)))(param_1);
    *(uint64_t *)((long)param_2 + 0xe0) = 0;
  }
  *(uint32_t *)((long)param_2 + 0x7c) = 0;
  if (*(long *)((long)param_2 + 0x80) != 0) {
    TextureDecoder_destroy();
    *(uint64_t *)((long)param_2 + 0x80) = 0;
  }
  ArrayList_free(*(uint64_t *)((long)param_2 + 0x10),1);
  *(uint64_t *)((long)param_2 + 0x10) = 0;
  ArrayList_free(*(uint64_t *)((long)param_2 + 0x18),1);
  *(uint64_t *)((long)param_2 + 0x18) = 0;
  ArrayList_free((long)param_2 + 0x98,1);
  pthread_mutex_destroy((pthread_mutex_t *)((long)param_2 + 0xa8));
  if (*(void **)((long)param_2 + 0x40) != (void *)0x0) {
    free(*(void **)((long)param_2 + 0x40));
    *(uint64_t *)((long)param_2 + 0x40) = 0;
  }
  if (*(void **)((long)param_2 + 0x108) != (void *)0x0) {
    free(*(void **)((long)param_2 + 0x108));
  }
  free(param_2);
  return;
}


/* @0015bc88  size=468 */

void destroyVkObject(uint32_t param_1,uint64_t param_2,uint64_t *param_3)

{
  void *UNRECOVERED_JUMPTABLE_00;
  
  if (param_3 == (uint64_t *)0x0) {
switchD_0015bcbc_caseD_2:
    return;
  }
  switch(param_1) {
  case 1:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193af8;
    goto LAB_0015bce8;
  default:
    goto switchD_0015bcbc_caseD_2;
  case 3:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193b40;
LAB_0015bce8:
                    /* WARNING: Could not recover jumptable at 0x0015bcf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_3,0);
    return;
  case 5:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193c20;
    break;
  case 7:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193bf8;
    break;
  case 9:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193c78;
    break;
  case 10:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193c98;
    break;
  case 0xb:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193c30;
    break;
  case 0xc:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193c58;
    break;
  case 0xd:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193c88;
    break;
  case 0xe:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193cb0;
    break;
  case 0xf:
    ((generic_fn_t)DAT_00193cc0)(param_2,*param_3,0);
    if ((void *)param_3[1] != (void *)0x0) {
      free((void *)param_3[1]);
    }
    free(param_3);
    return;
  case 0x10:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193cd0;
    break;
  case 0x11:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193d08;
    break;
  case 0x12:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193d78;
    break;
  case 0x13:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193cf8;
    break;
  case 0x14:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193d28;
    break;
  case 0x15:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193d18;
    break;
  case 0x16:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193d38;
    break;
  case 0x18:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193d68;
    break;
  case 0x19:
    UNRECOVERED_JUMPTABLE_00 = DAT_00193d90;
  }
                    /* WARNING: Could not recover jumptable at 0x0015be58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_2,param_3,0);
  return;
}


/* @001388dc  size=48 */

uint64_t getHandleRequestFunc(uint16_t param_1)

{
  if ((uint16_t)(param_1 - 100) < 0xfe) {
    return *(uint64_t *)((unsigned long)param_1 * 8 + 0x192d88);
  }
  return 0;
}


/* @0015c664  size=240 */

uint64_t handleExtraDataRequest(uint32_t *param_1,uint16_t param_2,uint32_t param_3)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  void *pvVar4;
  uint16_t *puVar5;
  void *pvVar6;
  
  if ((int)param_3 < 1) {
    pvVar4 = (void *)0x0;
  }
  else {
    pvVar4 = calloc((unsigned long)param_3,1);
    uVar1 = *param_1;
    pvVar6 = pvVar4;
    uVar2 = param_3;
    do {
      iVar3 = __read_chk(uVar1,pvVar6,(long)(int)uVar2,0xffffffffffffffff);
      if (iVar3 < 1) {
        if (-(uint32_t)(iVar3 == -1) != param_3) {
          return 0;
        }
        break;
      }
      uVar2 = uVar2 - iVar3;
      pvVar6 = (void *)((long)pvVar6 + (long)iVar3);
    } while (uVar2 != 0);
  }
  puVar5 = calloc(1,0x18);
  *puVar5 = param_2;
  *(uint32_t *)(puVar5 + 8) = param_3;
  *(void **)(puVar5 + 4) = pvVar4;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x2a));
  ArrayList_add(param_1 + 0x26,puVar5);
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x2a));
  return 1;
}


