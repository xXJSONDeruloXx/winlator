/*
 * resource_memory.c — GPU memory management
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0015cc28  size=1968 */

int * ResourceMemory_allocate(long param_1,uint64_t param_2,long param_3)

{
  long lVar1;
  bool bVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *__ptr;
  unsigned long uVar8;
  int *piVar9;
  long lVar10;
  long lVar11;
  uint64_t uVar12;
  int local_144;
  unsigned long local_140;
  uint64_t uStack_138;
  uint64_t local_130;
  uint64_t local_128;
  uint64_t local_120;
  uint64_t *puStack_118;
  uint64_t local_110;
  uint64_t uStack_108;
  uint64_t local_100;
  uint64_t local_f8;
  uint64_t local_f0;
  uint64_t local_e8;
  uint64_t uStack_e0;
  uint64_t local_d8;
  uint32_t local_d0;
  uint32_t uStack_cc;
  uint64_t uStack_c8;
  uint64_t local_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t local_a0;
  uint64_t local_90;
  uint64_t local_88;
  uint64_t local_80;
  long local_78;
  
  /* stack canary setup */
  local_78 = *(long *)(lVar1 + 0x28);
  uVar8 = DAT_00194340;
  if (*(short *)(param_1 + 8) != 0) {
    uVar8 = (long)*(short *)(param_1 + 8) << 0x14;
  }
  if ((unsigned long)(*(long *)(param_3 + 0x10) + *(long *)(param_1 + 0x20)) < uVar8) {
    __ptr = calloc(1,0x28);
    uVar4 = *(uint32_t *)(param_3 + 0x18);
    *__ptr = -1;
    uVar8 = isHostVisibleMemory(uVar4);
    if ((uVar8 & 1) == 0) {
      iVar5 = ((generic_fn_t)DAT_00193b80)(param_2,param_3,0,__ptr + 6);
      if (iVar5 != 0) goto LAB_0015d2e8;
LAB_0015d2cc:
      lVar10 = *(long *)(param_3 + 0x10);
      lVar11 = *(long *)(param_1 + 0x20);
      *(long *)(__ptr + 8) = lVar10;
      *(long *)(param_1 + 0x20) = lVar11 + lVar10;
      goto LAB_0015d374;
    }
    iVar5 = *(int *)(param_1 + 0xc);
    bVar2 = true;
    if (iVar5 == 1) {
LAB_0015cd1c:
      local_88 = 0;
      local_a0 = 0;
      local_90 = 0x3b9be340;
      local_80 = 1;
      uStack_cc = 0;
      local_c0 = 0;
      uStack_a8 = 0;
      local_d0 = 0xc;
      uStack_b8 = *(uint64_t *)(param_3 + 0x10);
      uStack_c8 = &local_90;
      local_b0 = 0x1ff;
      iVar5 = ((generic_fn_t)DAT_00193c70)(param_2,&local_d0,0,__ptr + 4);
      if (iVar5 == 0) {
        local_e8 = 0;
        uStack_e0 = 0;
        local_d8 = 0;
        ((generic_fn_t)DAT_00193bb8)(param_2,*(uint64_t *)(__ptr + 4),&local_e8);
        local_100 = 0x3b9be342;
        puStack_118 = &local_100;
        *(uint64_t **)(param_3 + 8) = &local_120;
        *(uint64_t *)(param_3 + 0x10) = local_e8;
        local_120 = 0x3b9cba19;
        uStack_108 = *(uint64_t *)(__ptr + 4);
        local_f8 = 0;
        local_f0 = 1;
        local_110 = 0;
        iVar5 = ((generic_fn_t)DAT_00193b80)(param_2,param_3,0,__ptr + 6);
        if (iVar5 == 0) {
          local_130 = *(uint64_t *)(__ptr + 6);
          uStack_138 = 0;
          local_144 = -1;
          local_140 = 0x3b9beb12;
          local_128 = 1;
          iVar5 = ((generic_fn_t)DAT_00193fc8)(param_2,&local_140,&local_144);
          iVar6 = 3;
          if ((iVar5 == 0) && (0 < local_144)) {
            iVar6 = 0;
            *__ptr = local_144;
          }
          if (iVar6 == 0) {
            if (iVar5 != 0) {
              *(uint64_t *)(__ptr + 8) = *(uint64_t *)(param_3 + 0x10);
              goto LAB_0015d374;
            }
            goto LAB_0015d2cc;
          }
          if (iVar6 != 3) goto LAB_0015d374;
        }
      }
    }
    else {
      if (iVar5 != 2) {
        if (iVar5 == 3) {
          bVar2 = false;
        }
        else {
          bVar2 = *(char *)(param_1 + 0x29) != '\0';
          if (*(char *)(param_1 + 0x28) != '\0') goto LAB_0015cd1c;
        }
      }
      uVar3 = getMemoryPropertyFlags(*(uint32_t *)(param_3 + 0x18));
      if ((uVar3 >> 3 & 1) != 0) {
        uVar4 = getMemoryTypeIndex(0x7fffffff,6);
        *(uint32_t *)(param_3 + 0x18) = uVar4;
      }
      if (bVar2) {
        uVar12 = *(uint64_t *)(param_3 + 0x10);
        iVar5 = __open_2("/dev/dma_heap/system-uncached",0);
        local_d0 = (uint32_t)uVar12;
        uStack_cc = (uint32_t)((unsigned long)uVar12 >> 0x20);
        if ((iVar5 < 0) && (iVar5 = __open_2("/dev/dma_heap/system",0), iVar5 < 0)) {
          iVar5 = __open_2("/dev/ion",0);
          if (-1 < iVar5) {
            local_140 = local_140 & 0xffffffff00000000;
            iVar6 = ioctl(iVar5,0xc0044901,&local_140);
            if (iVar6 == -1) {
              piVar9 = (int *)__errno();
              do {
                iVar6 = *piVar9;
                if ((iVar6 != 0xb) && (iVar6 != 4)) goto LAB_0015d05c;
                iVar6 = ioctl(iVar5,0xc0044901,&local_140);
              } while (iVar6 == -1);
            }
            if (iVar6 < 0) {
              piVar9 = (int *)__errno();
              iVar6 = *piVar9;
LAB_0015d05c:
              if (iVar6 == 0x19) {
                local_c0 = 0xffffffff;
                (*(uint32_t*)((char*)&uStack_c8 + 0)) = 0x2000000;
                (*(uint32_t*)((char*)&uStack_c8 + 4)) = 0;
                iVar6 = ioctl(iVar5,0xc0184900,&local_d0);
                while (iVar6 == -1) {
                  if ((*piVar9 != 4) && (*piVar9 != 0xb)) goto LAB_0015d21c;
                  iVar6 = ioctl(iVar5,0xc0184900,&local_d0);
                }
                close(iVar5);
                iVar5 = (int)local_c0;
                goto LAB_0015cf48;
              }
            }
            (*(uint32_t*)((char*)&uStack_c8 + 0)) = 0x1000;
            (*(uint32_t*)((char*)&uStack_c8 + 4)) = 0;
            local_c0 = 0x2000000;
            uStack_b8 = ((uint64_t)((*(uint32_t*)((char*)&uStack_b8 + 4))) << 32 | (uint32_t)(0xffffffff));
            iVar6 = ioctl(iVar5,0xc0204900,&local_d0);
            if (iVar6 == -1) {
              piVar9 = (int *)__errno();
              do {
                if ((*piVar9 != 0xb) && (*piVar9 != 4)) goto LAB_0015d21c;
                iVar6 = ioctl(iVar5,0xc0204900,&local_d0);
              } while (iVar6 == -1);
            }
            if (iVar6 == 0) {
              local_120 = ((uint64_t)(0xffffffff) << 32 | (uint32_t)((int)uStack_b8);
              iVar6 = ioctl(iVar5,0xc0084904,&local_120);
              if (iVar6 == -1) {
                piVar9 = (int *)__errno();
                do {
                  if ((*piVar9 != 0xb) && (*piVar9 != 4)) goto LAB_0015d21c;
                  iVar6 = ioctl(iVar5,0xc0084904,&local_120);
                } while (iVar6 == -1);
              }
              if (iVar6 == 0) {
                local_140 = ((uint64_t)((*(uint32_t*)((char*)&local_140 + 4))) << 32 | (uint32_t)((uint32_t)uStack_b8);
                iVar6 = ioctl(iVar5,0xc0044901,&local_140);
                if (iVar6 == -1) {
                  piVar9 = (int *)__errno();
                  do {
                    if ((*piVar9 != 4) && (*piVar9 != 0xb)) goto LAB_0015d21c;
                    iVar6 = ioctl(iVar5,0xc0044901,&local_140);
                  } while (iVar6 == -1);
                }
                close(iVar5);
                iVar5 = (*(uint32_t*)((char*)&local_120 + 4));
                goto LAB_0015cf48;
              }
            }
LAB_0015d21c:
            close(iVar5);
          }
          goto LAB_0015d230;
        }
        (*(uint32_t*)((char*)&uStack_c8 + 0)) = 0;
        (*(uint32_t*)((char*)&uStack_c8 + 4)) = 0x80002;
        local_c0 = 0;
        iVar6 = ioctl(iVar5,0xc0184800,&local_d0);
        if (iVar6 == -1) {
          piVar9 = (int *)__errno();
          do {
            if ((*piVar9 != 4) && (*piVar9 != 0xb)) goto LAB_0015d21c;
            iVar6 = ioctl(iVar5,0xc0184800,&local_d0);
          } while (iVar6 == -1);
        }
        close(iVar5);
        iVar5 = (int)uStack_c8;
LAB_0015cf48:
        if (iVar6 != 0) {
          iVar5 = -1;
        }
        if (iVar5 < 1) goto LAB_0015d230;
        iVar6 = dup(iVar5);
        uStack_cc = 0;
        (*(uint32_t*)((char*)&uStack_c8 + 0)) = 0;
        (*(uint32_t*)((char*)&uStack_c8 + 4)) = 0;
        *(uint32_t **)(param_3 + 8) = &local_d0;
        local_d0 = 0x3b9beb10;
        local_c0 = ((uint64_t)(iVar6) << 32 | (uint32_t)(0x200));
        iVar7 = ((generic_fn_t)DAT_00193b80)(param_2,param_3,0,__ptr + 6);
        if (iVar7 != 0) {
          close(iVar5);
          if (0 < iVar6) {
            close(iVar6);
          }
          goto LAB_0015d230;
        }
LAB_0015d2c8:
        *__ptr = iVar5;
        goto LAB_0015d2cc;
      }
LAB_0015d230:
      uStack_b8 = 0;
      local_b0 = 0;
      uStack_cc = 1;
      (*(uint32_t*)((char*)&uStack_c8 + 0)) = 1;
      local_c0 = 0x33;
      (*(uint32_t*)((char*)&uStack_c8 + 4)) = 0x21;
      local_d0 = (uint32_t)*(uint64_t *)(param_3 + 0x10);
      local_120 = 0;
      AHardwareBuffer_allocate(&local_d0,&local_120);
      lVar10 = local_120;
      if (local_120 == 0) {
        if (__ptr == (int *)0x0) goto LAB_0015d374;
      }
      else {
        *(long *)(__ptr + 2) = local_120;
        iVar5 = AHardwareBuffer_getFd(local_120);
        if (0 < iVar5) {
          uStack_cc = 0;
          (*(uint32_t*)((char*)&uStack_c8 + 0)) = 0;
          (*(uint32_t*)((char*)&uStack_c8 + 4)) = 0;
          *(uint32_t **)(param_3 + 8) = &local_d0;
          local_d0 = 0x3b9cc1eb;
          local_c0 = lVar10;
          iVar6 = ((generic_fn_t)DAT_00193b80)(param_2,param_3,0,__ptr + 6);
          if (iVar6 == 0) goto LAB_0015d2c8;
        }
      }
    }
LAB_0015d2e8:
    if (*(long *)(__ptr + 4) != 0) {
      ((generic_fn_t)DAT_00193c78)(param_2,*(long *)(__ptr + 4),0);
      __ptr[4] = 0;
      __ptr[5] = 0;
    }
    if (0 < *__ptr) {
      close(*__ptr);
      *__ptr = -1;
    }
    if (*(long *)(__ptr + 6) != 0) {
      ((generic_fn_t)DAT_00193b88)(param_2,*(long *)(__ptr + 6),0);
      uVar8 = *(unsigned long *)(param_1 + 0x20);
      __ptr[6] = 0;
      __ptr[7] = 0;
      lVar10 = 0;
      if (*(unsigned long *)(__ptr + 8) <= uVar8) {
        lVar10 = uVar8 - *(unsigned long *)(__ptr + 8);
      }
      *(long *)(param_1 + 0x20) = lVar10;
    }
    if (*(long *)(__ptr + 2) != 0) {
      AHardwareBuffer_release();
    }
    free(__ptr);
  }
  __ptr = (int *)0x0;
LAB_0015d374:
  if (*(long *)(lVar1 + 0x28) != local_78) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __ptr;
}


/* @0015d3d8  size=176 */

void ResourceMemory_free(long param_1,uint64_t param_2,int *param_3)

{
  long lVar1;
  unsigned long uVar2;
  
  if (param_3 != (int *)0x0) {
    if (*(long *)(param_3 + 4) != 0) {
      ((generic_fn_t)DAT_00193c78)(param_2,*(long *)(param_3 + 4),0);
      param_3[4] = 0;
      param_3[5] = 0;
    }
    if (0 < *param_3) {
      close(*param_3);
      *param_3 = -1;
    }
    if (*(long *)(param_3 + 6) != 0) {
      ((generic_fn_t)DAT_00193b88)(param_2,*(long *)(param_3 + 6),0);
      uVar2 = *(unsigned long *)(param_1 + 0x20);
      param_3[6] = 0;
      param_3[7] = 0;
      lVar1 = 0;
      if (*(unsigned long *)(param_3 + 8) <= uVar2) {
        lVar1 = uVar2 - *(unsigned long *)(param_3 + 8);
      }
      *(long *)(param_1 + 0x20) = lVar1;
    }
    if (*(long *)(param_3 + 2) != 0) {
      AHardwareBuffer_release();
    }
    free(param_3);
    return;
  }
  return;
}


