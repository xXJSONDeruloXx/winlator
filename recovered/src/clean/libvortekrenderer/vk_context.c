/*
 * vk_context.c — VkContext lifecycle, dispatch
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015be5c  size=1116 */

int * createVkContext(long *param_1,uint64_t param_2,int param_3,uint64_t param_4)

{
  /* STUB: createVkContext — Ghidra artifacts */
}


/* @0015c4c0  size=420 */

void destroyVkContext(long *param_1,void *param_2)

{
  /* STUB: conflicting types for destroyVkContext */
}


/* @0015bc88  size=468 */

void destroyVkObject(uint32_t param_1,uint64_t param_2,uint64_t *param_3)

{
  /* STUB: destroyVkObject — Ghidra artifacts */
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


