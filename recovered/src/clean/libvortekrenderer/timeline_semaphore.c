/*
 * timeline_semaphore.c — Timeline semaphore support
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @00164090  size=348 */

void TimelineSemaphore_asyncWait(int param_1,long param_2,void *param_3,int param_4)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  void *__dest;
  uint64_t *puVar4;
  struct msghdr local_138;
  struct iovec local_100;
  uint8_t local_ec [4];
  uint64_t local_e8;
  uint64_t local_e0;
  int local_d8;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar1 + 0x28);
  piVar3 = calloc(1,0x10);
  __dest = malloc((long)param_4);
  if (__dest != (void *)0x0) {
    memcpy(__dest,param_3,(long)param_4);
  }
  *(void **)(piVar3 + 2) = __dest;
  local_d8 = eventfd(0,0);
  local_100.iov_base = local_ec;
  *piVar3 = local_d8;
  local_138.msg_iov = &local_100;
  local_138.msg_control = &local_e8;
  local_100.iov_len = 1;
  local_ec[0] = 0;
  local_138.msg_name = (void *)0x0;
  local_138.msg_namelen = 0;
  local_138.msg_iovlen = 1;
  local_138.msg_flags = 0;
  local_138.msg_controllen = 0x14;
  local_e0 = 0x100000001;
  local_e8 = 0x14;
  sendmsg(param_1,&local_138,0);
  puVar4 = malloc(0x18);
  puVar4[1] = piVar3;
  puVar4[2] = 0;
  *puVar4 = FUN_001641ec;
  pthread_mutex_lock((pthread_mutex_t *)(param_2 + 4));
  if (*(long *)(param_2 + 0xb8) == 0) {
    *(uint64_t **)(param_2 + 0xb8) = puVar4;
  }
  else {
    *(uint64_t **)(*(long *)(param_2 + 0xc0) + 0x10) = puVar4;
  }
  *(uint64_t **)(param_2 + 0xc0) = puVar4;
  pthread_cond_signal((pthread_cond_t *)(param_2 + 0x2c));
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_2 + 4));
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}


