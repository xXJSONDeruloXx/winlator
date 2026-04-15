/*
 * texture_decoder.c — Texture format decoding
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015e9a4  size=200 */

void TextureDecoder_addBoundBuffer(long param_1,int *param_2,long param_3,long param_4)

{
  void *__ptr;
  long *plVar1;
  unsigned long uVar2;
  
  if (*param_2 < 1) {
    return;
  }
  if (0 < (int)*(uint32_t *)(param_1 + 0x10)) {
    uVar2 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 0x18) + uVar2 * 8) == param_3) {
        if ((int)uVar2 != -1) {
          __ptr = *(void **)(*(long *)(param_1 + 0x18) + uVar2 * 8);
          if (__ptr != (void *)0x0) {
            free(__ptr);
          }
          ArrayList_removeAt(param_1 + 0x10,uVar2 & 0xffffffff);
        }
        break;
      }
      uVar2 = uVar2 + 1;
    } while (*(uint32_t *)(param_1 + 0x10) != uVar2);
  }
  plVar1 = calloc(1,0x18);
  *plVar1 = param_3;
  plVar1[1] = param_4;
  plVar1[2] = (long)param_2;
  ArrayList_add(param_1 + 0x10);
  return;
}


/* @0015e584  size=68 */

bool TextureDecoder_containsImage(uint32_t *param_1,long param_2)

{
  unsigned long uVar1;
  
  if (0 < (int)*param_1) {
    uVar1 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 2) + uVar1 * 8) == param_2) {
        return (int)uVar1 != -1;
      }
      uVar1 = uVar1 + 1;
    } while (*param_1 != uVar1);
  }
  return false;
}


/* @0015e41c  size=360 */

void TextureDecoder_copyBufferToImage
               (uint32_t *param_1,uint64_t param_2,long param_3,long param_4,uint32_t param_5,
               uint64_t param_6)

{
  long lVar1;
  uint64_t *puVar2;
  unsigned long uVar3;
  uint64_t uVar4;
  long lVar5;
  uint64_t local_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  long lStack_78;
  int local_70;
  uint32_t uStack_6c;
  long local_68;
  
  /* stack canary setup */
  local_68 = *(long *)(lVar1 + 0x28);
  if (0 < (int)param_1[4]) {
    uVar3 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 6) + uVar3 * 8) == param_3) {
        if (((int)uVar3 != -1) && (0 < (int)*param_1)) {
          uVar4 = *(uint64_t *)(*(long *)(param_1 + 6) + uVar3 * 8);
          uVar3 = 0;
          goto LAB_0015e4b0;
        }
        break;
      }
      uVar3 = uVar3 + 1;
    } while (param_1[4] != uVar3);
  }
  goto LAB_0015e550;
  while (uVar3 = uVar3 + 1, *param_1 != uVar3) {
LAB_0015e4b0:
    if (**(long **)(*(long *)(param_1 + 2) + uVar3 * 8) == param_4) {
      if ((int)uVar3 != -1) {
        lVar5 = *(long *)(*(long *)(param_1 + 2) + uVar3 * 8);
        puVar2 = calloc(1,0x18);
        *puVar2 = uVar4;
        puVar2[1] = lVar5;
        puVar2[2] = param_6;
        ArrayDeque_addLast(param_1 + 8,puVar2);
        uStack_80 = 0;
        uStack_98 = 0;
        local_a0 = 0;
        lStack_78 = (unsigned long)(uint32_t)(int)*(short *)(lVar5 + 0xc) << 0x20;
        local_90 = 1;
        uStack_88 = 0x100000000;
        local_70 = ((uint64_t)(1) << 32 | (uint32_t)((int)*(short *)(lVar5 + 0xe)));
        ((generic_fn_t)DAT_00193e78)(param_2,*(uint64_t *)(lVar5 + 0x10),param_4,param_5,1,&local_a0);
      }
      break;
    }
  }
LAB_0015e550:
  if (*(long *)(lVar1 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0015da54  size=72 */

void * TextureDecoder_create(long param_1,long param_2)

{
  void *pvVar1;
  uint64_t uVar2;
  
  if (*(int *)(param_2 + 0x58) == 0) {
    pvVar1 = calloc(1,0x48);
    uVar2 = *(uint64_t *)(param_1 + 0x90);
    *(uint16_t *)((long)pvVar1 + 0x38) = *(uint16_t *)(param_1 + 10);
    *(uint64_t *)((long)pvVar1 + 0x40) = uVar2;
  }
  else {
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}


/* @0015e5c8  size=736 */

/* WARNING: Type propagation algorithm not settling */

int TextureDecoder_createImage(uint64_t param_1,uint64_t param_2,long param_3,long *param_4)

{
  uint32_t uVar1;
  long lVar2;
  int iVar3;
  uint32_t uVar4;
  long *__ptr;
  int *piVar5;
  size_t __n;
  long local_e8 [4];
  uint64_t local_c8;
  uint64_t local_c0;
  uint64_t uStack_b8;
  unsigned long local_b0;
  long local_a8 [5];
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t local_70;
  long local_60;
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar2 + 0x28);
  *param_4 = 0;
  iVar3 = *(int *)(param_3 + 0x18);
  if (iVar3 - 0x83U < 0xc) {
    __ptr = calloc(1,0x28);
    uVar4 = *(uint32_t *)(param_3 + 0x20);
    uVar1 = *(uint32_t *)(param_3 + 0x10);
    piVar5 = *(int **)(param_3 + 8);
    *(short *)((long)__ptr + 0xc) = (short)*(uint32_t *)(param_3 + 0x1c);
    *(int *)(__ptr + 1) = iVar3;
    *(uint32_t *)(param_3 + 0x18) = 0x2c;
    *(short *)((long)__ptr + 0xe) = (short)uVar4;
    *(uint32_t *)(param_3 + 0x10) = uVar1 & 0xffffff7f;
    *(uint32_t *)(param_3 + 0x28) = 1;
    for (; piVar5 != (int *)0x0; piVar5 = *(int **)(piVar5 + 2)) {
      if (*piVar5 == 0x3b9d0838) {
        if (*(uint32_t **)(piVar5 + 6) != (uint32_t *)0x0) {
          piVar5[4] = 1;
          **(uint32_t **)(piVar5 + 6) = 0x2c;
        }
        break;
      }
    }
    iVar3 = ((generic_fn_t)DAT_00193c90)(param_2,param_3,0,&local_60);
    if (iVar3 == 0) {
      local_a8[2] = 0;
      local_a8[3] = 0;
      local_a8[1] = 0xc;
      local_a8[4] = (long)(uint32_t)(*(int *)(param_3 + 0x1c) * *(int *)(param_3 + 0x20) * 4);
      local_70 = 0;
      uStack_78 = 0;
      local_80 = 1;
      iVar3 = ((generic_fn_t)DAT_00193c70)(param_2,local_a8 + 1,0,local_a8);
      if (iVar3 == 0) {
        local_c0 = 0;
        uStack_b8 = 0;
        local_b0 = 0;
        ((generic_fn_t)DAT_00193bb8)(param_2,local_a8[0],&local_c0);
        local_e8[2] = 0;
        local_c8 = 0;
        local_e8[1] = 5;
        local_e8[3] = local_c0;
        uVar4 = getMemoryTypeIndex(local_b0 & 0xffffffff,2);
        local_c8 = ((uint64_t)((*(uint32_t*)((char*)&local_c8 + 4))) << 32 | (uint32_t)(uVar4));
        iVar3 = ((generic_fn_t)DAT_00193b80)(param_2,local_e8 + 1,0,local_e8);
        if ((iVar3 == 0) && (iVar3 = ((generic_fn_t)DAT_00193bc0)(param_2,local_a8[0],local_e8[0],0), iVar3 == 0)
           ) {
          __n = (size_t)((int)*(short *)((long)__ptr + 0xc) * (int)*(short *)((long)__ptr + 0xe) * 4
                        );
          iVar3 = ((generic_fn_t)DAT_00193b90)(param_2,local_e8[0],0,__n,0,__ptr + 4);
          if (iVar3 == 0) {
            memset((void *)__ptr[4],0,__n);
            *__ptr = local_60;
            __ptr[2] = local_a8[0];
            __ptr[3] = local_e8[0];
            ArrayList_add(param_1,__ptr);
            *param_4 = local_60;
            goto LAB_0015e838;
          }
        }
      }
    }
    if (__ptr[4] != 0) {
      ((generic_fn_t)DAT_00193b98)(param_2,__ptr[3]);
    }
    if (*__ptr != 0) {
      ((generic_fn_t)DAT_00193c98)(param_2,*__ptr,0);
    }
    if (__ptr[2] != 0) {
      ((generic_fn_t)DAT_00193c78)(param_2,__ptr[2],0);
    }
    if (__ptr[3] != 0) {
      ((generic_fn_t)DAT_00193b88)(param_2,__ptr[3],0);
    }
    free(__ptr);
  }
  else {
    iVar3 = -0xb;
  }
LAB_0015e838:
  if (*(long *)(lVar2 + 0x28) == local_58) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0015dae8  size=2356 */

void TextureDecoder_decodeAll(long param_1)

{
  /* STUB: TextureDecoder_decodeAll — Ghidra artifacts */
}


/* @0015da9c  size=76 */

void TextureDecoder_destroy(void *param_1)

{
  if (*(void **)((long)param_1 + 8) != (void *)0x0) {
    free(*(void **)((long)param_1 + 8));
    *(uint64_t *)((long)param_1 + 8) = 0;
  }
  if (*(void **)((long)param_1 + 0x18) != (void *)0x0) {
    free(*(void **)((long)param_1 + 0x18));
    *(uint64_t *)((long)param_1 + 0x18) = 0;
  }
  if (*(void **)((long)param_1 + 0x30) != (void *)0x0) {
    free(*(void **)((long)param_1 + 0x30));
  }
  free(param_1);
  return;
}


/* @0015e8a8  size=252 */

void TextureDecoder_destroyImage(uint32_t *param_1,uint64_t param_2,long param_3)

{
  unsigned long uVar1;
  long *__ptr;
  
  if (0 < (int)*param_1) {
    uVar1 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 2) + uVar1 * 8) == param_3) {
        if ((int)uVar1 == -1) {
          return;
        }
        __ptr = *(long **)(*(long *)(param_1 + 2) + uVar1 * 8);
        if (__ptr[4] != 0) {
          ((generic_fn_t)DAT_00193b98)(param_2,__ptr[3]);
        }
        if (*__ptr != 0) {
          ((generic_fn_t)DAT_00193c98)(param_2,*__ptr,0);
        }
        if (__ptr[2] != 0) {
          ((generic_fn_t)DAT_00193c78)(param_2,__ptr[2],0);
        }
        if (__ptr[3] != 0) {
          ((generic_fn_t)DAT_00193b88)(param_2,__ptr[3],0);
        }
        free(__ptr);
        ArrayList_removeAt(param_1,uVar1 & 0xffffffff);
        return;
      }
      uVar1 = uVar1 + 1;
    } while (*param_1 != uVar1);
  }
  return;
}


/* @0015ea6c  size=124 */

void TextureDecoder_removeBoundBuffer(long param_1,long param_2)

{
  void *__ptr;
  unsigned long uVar1;
  
  if (0 < (int)*(uint32_t *)(param_1 + 0x10)) {
    uVar1 = 0;
    do {
      if (**(long **)(*(long *)(param_1 + 0x18) + uVar1 * 8) == param_2) {
        if ((int)uVar1 == -1) {
          return;
        }
        __ptr = *(void **)(*(long *)(param_1 + 0x18) + uVar1 * 8);
        if (__ptr != (void *)0x0) {
          free(__ptr);
        }
        ArrayList_removeAt(param_1 + 0x10,uVar1 & 0xffffffff);
        return;
      }
      uVar1 = uVar1 + 1;
    } while (*(uint32_t *)(param_1 + 0x10) != uVar1);
  }
  return;
}


