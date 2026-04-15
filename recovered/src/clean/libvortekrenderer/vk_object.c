/*
 * vk_object.c — VkObject handle wrapping/tracking
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0012de48  size=336 */

long * VkObject_create(int param_1,long param_2)

{
  long lVar1;
  uint32_t uVar2;
  unsigned long uVar3;
  uint64_t *puVar4;
  long *plVar5;
  
  if (param_1 == 4) {
    uVar3 = (unsigned long)DAT_00194320;
    puVar4 = DAT_00194328;
    if (0 < (int)DAT_00194320) {
      do {
        plVar5 = (long *)*puVar4;
        if (*plVar5 == param_2) {
          lVar1 = *plVar5;
          goto joined_r0x0012df58;
        }
        uVar3 = uVar3 - 1;
        puVar4 = puVar4 + 1;
      } while (uVar3 != 0);
    }
    plVar5 = &vkNullObject;
    lVar1 = vkNullObject;
joined_r0x0012df58:
    if (lVar1 != 0) {
      return plVar5;
    }
    plVar5 = calloc(1,0x20);
    uVar2 = 4;
  }
  else {
    if (param_1 != 2) {
      plVar5 = calloc(1,0x20);
      *(int *)(plVar5 + 1) = param_1;
      *plVar5 = param_2;
      return plVar5;
    }
    uVar3 = (unsigned long)DAT_00194320;
    puVar4 = DAT_00194328;
    if (0 < (int)DAT_00194320) {
      do {
        plVar5 = (long *)*puVar4;
        if (*plVar5 == param_2) {
          lVar1 = *plVar5;
          goto joined_r0x0012df34;
        }
        uVar3 = uVar3 - 1;
        puVar4 = puVar4 + 1;
      } while (uVar3 != 0);
    }
    plVar5 = &vkNullObject;
    lVar1 = vkNullObject;
joined_r0x0012df34:
    if (lVar1 != 0) {
      return plVar5;
    }
    plVar5 = calloc(1,0x20);
    uVar2 = 2;
  }
  *(uint32_t *)(plVar5 + 1) = uVar2;
  *plVar5 = param_2;
  ArrayList_add(&DAT_00194320,plVar5);
  return plVar5;
}


/* @0012dff0  size=68 */

void VkObject_free(long *param_1)

{
  if ((param_1 != (long *)0x0) && (*param_1 != 0)) {
    if ((void *)param_1[3] != (void *)0x0) {
      free((void *)param_1[3]);
    }
    free(param_1);
    return;
  }
  return;
}


/* @0012dfd4  size=28 */

uint64_t * VkObject_fromHandle(long param_1)

{
  if ((param_1 != 0) && (*(uint64_t **)(param_1 + 8) != (uint64_t *)0x0)) {
    return *(uint64_t **)(param_1 + 8);
  }
  return &vkNullObject;
}


/* @0012dfd0  size=4 */

void VkObject_fromId(void)

{
  return;
}


/* @0012df98  size=56 */

void VkObject_toHandle(long param_1)

{
  void *pvVar1;
  
  if (*(long *)(param_1 + 0x18) == 0) {
    pvVar1 = calloc(2,8);
    *(long *)((long)pvVar1 + 8) = param_1;
    *(void **)(param_1 + 0x18) = pvVar1;
  }
  return;
}


