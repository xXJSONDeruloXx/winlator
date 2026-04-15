/*
 * async_pipeline.c — Async pipeline compilation
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @00161558  size=8976 */

void AsyncPipelineCreator_create(int *param_1,int param_2)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  uint32_t uVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  uint64_t *__ptr;
  void *pvVar8;
  uint64_t *puVar9;
  void *pvVar10;
  char *pcVar11;
  uint32_t uVar12;
  uint64_t uVar13;
  long lVar14;
  uint32_t *puVar15;
  int *piVar16;
  unsigned long uVar17;
  int *piVar18;
  int iVar19;
  char *pcVar20;
  uint64_t *puVar21;
  uint64_t *puVar22;
  int iVar23;
  uint64_t *puVar24;
  unsigned long uVar25;
  uint32_t uVar26;
  char *pcVar27;
  unsigned long uVar28;
  int iVar29;
  void *pvVar30;
  size_t sVar31;
  int iVar32;
  uint32_t uVar33;
  uint64_t local_1e0;
  uint64_t local_1d8;
  unsigned long local_188;
  char local_154 [4];
  int local_150 [2];
  struct msghdr local_148;
  struct iovec local_110;
  uint64_t local_100;
  uint64_t local_f8;
  int local_f0;
  long local_70;
  
  /* stack canary setup */
  local_70 = *(long *)(lVar6 + 0x28);
  __ptr = calloc(1,0x50);
  uVar13 = *(uint64_t *)(param_1 + 0x22);
  *(int *)(__ptr + 2) = param_2;
  __ptr[4] = uVar13;
  if (param_2 == 1) {
    pcVar20 = *(char **)(param_1 + 0xc);
    if (*pcVar20 == '\0') {
      local_1e0 = 0;
      lVar14 = 1;
    }
    else {
      local_1e0 = *(uint64_t *)(pcVar20 + 1);
      lVar14 = 9;
    }
    uVar17 = lVar14 + 1;
    if (pcVar20[lVar14] == '\0') {
      local_1d8 = 0;
    }
    else {
      local_1d8 = *(uint64_t *)(pcVar20 + uVar17);
      uVar17 = (unsigned long)((int)lVar14 + 9);
    }
    uVar26 = *(uint32_t *)(pcVar20 + uVar17);
    *(uint32_t *)((long)__ptr + 0x14) = uVar26;
    pvVar8 = calloc((unsigned long)uVar26,0x60);
    uVar12 = 9;
    uVar26 = uVar12;
    if (*pcVar20 == '\0') {
      uVar26 = 1;
    }
    if (pcVar20[uVar26] == '\0') {
      uVar12 = 1;
    }
    uVar4 = *(uint32_t *)(pcVar20 + (unsigned long)(uVar12 + uVar26) + 4);
    if (0 < (int)uVar4) {
      uVar17 = 0;
      plVar1 = __ptr + 5;
      iVar7 = uVar12 + uVar26 + 8;
LAB_00163388:
      iVar5 = *(int *)(pcVar20 + iVar7);
      lVar14 = (long)iVar7 + 4;
      if (pvVar8 != (void *)0x0) {
        piVar16 = (int *)(pcVar20 + lVar14 + 4);
        puVar24 = (uint64_t *)0x0;
        iVar7 = 8;
        *(uint32_t *)((long)pvVar8 + uVar17 * 0x60) = *(uint32_t *)(pcVar20 + lVar14);
        do {
          if (*piVar16 == 0x3b9db800) {
            iVar23 = *(int *)(pcVar20 + iVar7 + lVar14);
            uVar28 = (long)iVar7 + 4;
            if (iVar23 < 1) goto LAB_001633cc;
            iVar7 = *(int *)(__ptr + 6);
            if ((iVar7 < 0xffd8) && (*plVar1 != 0)) {
              puVar22 = (uint64_t *)(*plVar1 + (long)iVar7);
              *(int *)(__ptr + 6) = iVar7 + 0x28;
            }
            else {
              puVar22 = malloc(0x28);
              ArrayList_add(__ptr + 7,puVar22);
            }
            puVar22[4] = 0;
            puVar22[1] = 0;
            *puVar22 = 0;
            puVar22[3] = 0;
            puVar22[2] = 0;
            pcVar11 = pcVar20 + uVar28 + lVar14;
            uVar33 = *(uint32_t *)pcVar11;
            puVar22[1] = 0;
            *(uint32_t *)puVar22 = uVar33;
            iVar7 = *(int *)(pcVar11 + 4);
            if (iVar7 < 1) {
              uVar26 = 8;
              puVar22[2] = 0;
            }
            else {
              iVar29 = *(int *)(__ptr + 6);
              if ((iVar29 < 0xfff0) && (*plVar1 != 0)) {
                puVar9 = (uint64_t *)(*plVar1 + (long)iVar29);
                *(int *)(__ptr + 6) = iVar29 + 0x10;
              }
              else {
                puVar9 = malloc(0x10);
                ArrayList_add(__ptr + 7,puVar9);
              }
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar22[2] = puVar9;
              uVar26 = iVar7 + 8;
              *(uint32_t *)puVar9 = *(uint32_t *)(pcVar11 + 8);
              puVar9[1] = *(uint64_t *)(pcVar11 + 0xc);
            }
            *(uint32_t *)(puVar22 + 3) = *(uint32_t *)(pcVar11 + uVar26);
            uVar12 = *(uint32_t *)(pcVar11 + uVar26 + 4);
            uVar25 = (unsigned long)uVar12;
            if ((int)uVar12 < 1) {
              puVar22[4] = 0;
            }
            else {
              iVar29 = uVar12 * 0x10;
              iVar7 = *(int *)(__ptr + 6) + iVar29;
              if ((iVar7 < 0x10000) && (*plVar1 != 0)) {
                pvVar10 = (void *)(*plVar1 + (long)*(int *)(__ptr + 6));
                *(int *)(__ptr + 6) = iVar7;
              }
              else {
                pvVar10 = malloc((long)iVar29);
                ArrayList_add(__ptr + 7,pvVar10);
              }
              iVar7 = uVar26 + 8;
              memset(pvVar10,0,(long)iVar29);
              puVar9 = (uint64_t *)((long)pvVar10 + 8);
              do {
                iVar29 = *(int *)(pcVar11 + iVar7);
                lVar2 = (long)iVar7 + 4;
                if (pvVar10 != (void *)0x0) {
                  *(uint32_t *)(puVar9 + -1) = *(uint32_t *)(pcVar11 + lVar2);
                  *puVar9 = *(uint64_t *)(pcVar11 + lVar2 + 4);
                }
                iVar7 = iVar29 + (int)lVar2;
                uVar25 = uVar25 - 1;
                puVar9 = puVar9 + 2;
              } while (uVar25 != 0);
              puVar22[4] = pvVar10;
            }
            puVar22[1] = puVar24;
            iVar7 = iVar23 + (int)uVar28;
            puVar24 = puVar22;
          }
          else {
            if (*piVar16 == -1) goto LAB_001635cc;
            uVar28 = (unsigned long)(iVar7 + 4);
LAB_001633cc:
            iVar7 = (int)uVar28;
          }
          piVar16 = (int *)(pcVar20 + iVar7 + lVar14);
          iVar7 = iVar7 + 4;
        } while( true );
      }
      goto LAB_00163374;
    }
  }
  else {
    if (param_2 != 0) {
      local_1e0 = 0;
      local_1d8 = 0;
      goto LAB_00163710;
    }
    pcVar20 = *(char **)(param_1 + 0xc);
    if (*pcVar20 == '\0') {
      local_1e0 = 0;
      lVar14 = 1;
    }
    else {
      local_1e0 = *(uint64_t *)(pcVar20 + 1);
      lVar14 = 9;
    }
    uVar17 = lVar14 + 1;
    if (pcVar20[lVar14] == '\0') {
      local_1d8 = 0;
    }
    else {
      local_1d8 = *(uint64_t *)(pcVar20 + uVar17);
      uVar17 = (unsigned long)((int)lVar14 + 9);
    }
    uVar26 = *(uint32_t *)(pcVar20 + uVar17);
    *(uint32_t *)((long)__ptr + 0x14) = uVar26;
    pvVar8 = calloc((unsigned long)uVar26,0x90);
    uVar12 = 9;
    uVar26 = uVar12;
    if (*pcVar20 == '\0') {
      uVar26 = 1;
    }
    if (pcVar20[uVar26] == '\0') {
      uVar12 = 1;
    }
    uVar4 = *(uint32_t *)(pcVar20 + (unsigned long)(uVar12 + uVar26) + 4);
    if (0 < (int)uVar4) {
      plVar1 = __ptr + 5;
      iVar7 = uVar12 + uVar26 + 8;
      piVar16 = (int *)(__ptr + 6);
      local_188 = 0;
LAB_00161760:
      iVar5 = *(int *)(pcVar20 + iVar7);
      lVar14 = (long)iVar7 + 4;
      if (pvVar8 != (void *)0x0) {
        piVar18 = (int *)(pcVar20 + lVar14 + 4);
        puVar24 = (uint64_t *)0x0;
        *(uint32_t *)((long)pvVar8 + local_188 * 0x90) = *(uint32_t *)(pcVar20 + lVar14);
        iVar7 = 8;
        do {
          iVar23 = *piVar18;
          if (iVar23 == 0x3b9b75e2) {
            iVar23 = *(int *)(pcVar20 + iVar7 + lVar14);
            uVar17 = (long)iVar7 + 4;
            if (0 < iVar23) {
              iVar7 = *piVar16;
              if ((iVar7 < 0xffd8) && (*plVar1 != 0)) {
                puVar22 = (uint64_t *)(*plVar1 + (long)iVar7);
                *piVar16 = iVar7 + 0x28;
              }
              else {
                puVar22 = malloc(0x28);
                ArrayList_add(__ptr + 7,puVar22);
              }
              puVar22[4] = 0;
              puVar22[1] = 0;
              *puVar22 = 0;
              puVar22[3] = 0;
              puVar22[2] = 0;
              pcVar11 = pcVar20 + uVar17 + lVar14;
              uVar33 = *(uint32_t *)pcVar11;
              puVar22[1] = 0;
              *(uint32_t *)puVar22 = uVar33;
              *(uint32_t *)(puVar22 + 2) = *(uint32_t *)(pcVar11 + 4);
              *(uint32_t *)((long)puVar22 + 0x14) = *(uint32_t *)(pcVar11 + 8);
              if (*(int *)(pcVar11 + 0xc) < 1) {
                iVar7 = 0x10;
                puVar22[3] = 0;
              }
              else {
                sVar31 = (long)*(int *)(pcVar11 + 0xc) << 2;
                iVar7 = (int)sVar31;
                iVar29 = *piVar16 + iVar7;
                if ((iVar29 < 0x10000) && (*plVar1 != 0)) {
                  pvVar10 = (void *)(*plVar1 + (long)*piVar16);
                  *piVar16 = iVar29;
                  sVar31 = (size_t)iVar7;
                }
                else {
                  pvVar10 = malloc(sVar31);
                  ArrayList_add(__ptr + 7,pvVar10);
                }
                memset(pvVar10,0,sVar31);
                if (pvVar10 != (void *)0x0) {
                  memcpy(pvVar10,pcVar11 + 0x10,(long)iVar7);
                }
                puVar22[3] = pvVar10;
                iVar7 = iVar7 + 0x10;
              }
              uVar17 = (unsigned long)(uint32_t)(iVar23 + (int)uVar17);
              *(uint32_t *)(puVar22 + 4) = *(uint32_t *)(pcVar11 + iVar7);
              uVar33 = *(uint32_t *)(pcVar11 + iVar7 + 4);
              puVar22[1] = puVar24;
              *(uint32_t *)((long)puVar22 + 0x24) = uVar33;
              puVar24 = puVar22;
            }
          }
          else if (iVar23 == 0x3b9db800) {
            iVar23 = *(int *)(pcVar20 + iVar7 + lVar14);
            uVar17 = (long)iVar7 + 4;
            if (0 < iVar23) {
              iVar7 = *piVar16;
              if ((iVar7 < 0xffd8) && (*plVar1 != 0)) {
                puVar22 = (uint64_t *)(*plVar1 + (long)iVar7);
                *piVar16 = iVar7 + 0x28;
              }
              else {
                puVar22 = malloc(0x28);
                ArrayList_add(__ptr + 7,puVar22);
              }
              puVar22[4] = 0;
              puVar22[1] = 0;
              *puVar22 = 0;
              puVar22[3] = 0;
              puVar22[2] = 0;
              pcVar11 = pcVar20 + uVar17 + lVar14;
              uVar33 = *(uint32_t *)pcVar11;
              puVar22[1] = 0;
              *(uint32_t *)puVar22 = uVar33;
              iVar7 = *(int *)(pcVar11 + 4);
              if (iVar7 < 1) {
                uVar26 = 8;
                puVar22[2] = 0;
              }
              else {
                iVar29 = *piVar16;
                if ((iVar29 < 0xfff0) && (*plVar1 != 0)) {
                  puVar9 = (uint64_t *)(*plVar1 + (long)iVar29);
                  *piVar16 = iVar29 + 0x10;
                }
                else {
                  puVar9 = malloc(0x10);
                  ArrayList_add(__ptr + 7,puVar9);
                }
                *puVar9 = 0;
                puVar9[1] = 0;
                puVar22[2] = puVar9;
                uVar26 = iVar7 + 8;
                *(uint32_t *)puVar9 = *(uint32_t *)(pcVar11 + 8);
                puVar9[1] = *(uint64_t *)(pcVar11 + 0xc);
              }
              *(uint32_t *)(puVar22 + 3) = *(uint32_t *)(pcVar11 + uVar26);
              uVar12 = *(uint32_t *)(pcVar11 + uVar26 + 4);
              uVar28 = (unsigned long)uVar12;
              if ((int)uVar12 < 1) {
                puVar22[4] = 0;
              }
              else {
                iVar29 = uVar12 * 0x10;
                iVar7 = *piVar16 + iVar29;
                if ((iVar7 < 0x10000) && (*plVar1 != 0)) {
                  pvVar10 = (void *)(*plVar1 + (long)*piVar16);
                  *piVar16 = iVar7;
                }
                else {
                  pvVar10 = malloc((long)iVar29);
                  ArrayList_add(__ptr + 7,pvVar10);
                }
                iVar7 = uVar26 + 8;
                memset(pvVar10,0,(long)iVar29);
                puVar9 = (uint64_t *)((long)pvVar10 + 8);
                do {
                  iVar29 = *(int *)(pcVar11 + iVar7);
                  lVar2 = (long)iVar7 + 4;
                  if (pvVar10 != (void *)0x0) {
                    *(uint32_t *)(puVar9 + -1) = *(uint32_t *)(pcVar11 + lVar2);
                    *puVar9 = *(uint64_t *)(pcVar11 + lVar2 + 4);
                  }
                  iVar7 = iVar29 + (int)lVar2;
                  uVar28 = uVar28 - 1;
                  puVar9 = puVar9 + 2;
                } while (uVar28 != 0);
                puVar22[4] = pvVar10;
              }
              uVar17 = (unsigned long)(uint32_t)(iVar23 + (int)uVar17);
              puVar22[1] = puVar24;
              puVar24 = puVar22;
            }
          }
          else {
            if (iVar23 == -1) goto LAB_00161b28;
            uVar17 = (unsigned long)(iVar7 + 4);
          }
          piVar18 = (int *)(pcVar20 + (int)uVar17 + lVar14);
          iVar7 = (int)uVar17 + 4;
        } while( true );
      }
      goto LAB_00161748;
    }
  }
LAB_00163708:
  __ptr[3] = pvVar8;
LAB_00163710:
  uVar13 = VkObject_fromId(local_1e0);
  *__ptr = uVar13;
  uVar13 = VkObject_fromId(local_1d8);
  __ptr[1] = uVar13;
  local_150[0] = 0;
  local_150[1] = 0;
  iVar7 = pipe(local_150);
  local_154[0] = iVar7 == 0;
  local_148.msg_iov = &local_110;
  local_110.iov_base = local_154;
  local_110.iov_len = 1;
  local_148.msg_control = &local_100;
  local_148.msg_name = (void *)0x0;
  local_148.msg_namelen = 0;
  local_148.msg_flags = 0;
  local_148.msg_iovlen = 1;
  local_148.msg_controllen = 0x14;
  local_f8 = 0x100000001;
  local_100 = 0x14;
  local_f0 = local_150[0];
  sendmsg(*param_1,&local_148,0);
  if (local_154[0] == '\0') {
    if ((void *)__ptr[3] != (void *)0x0) {
      free((void *)__ptr[3]);
    }
    free(__ptr);
  }
  else {
    *(int *)(__ptr + 9) = local_150[1];
    if (0 < local_150[0]) {
      close(local_150[0]);
      local_150[0] = 0xffffffff;
    }
    lVar14 = *(long *)(param_1 + 0x24);
    puVar24 = malloc(0x18);
    puVar24[1] = __ptr;
    puVar24[2] = 0;
    *puVar24 = FUN_00163868;
    pthread_mutex_lock((pthread_mutex_t *)(lVar14 + 4));
    if (*(long *)(lVar14 + 0xb8) == 0) {
      *(uint64_t **)(lVar14 + 0xb8) = puVar24;
    }
    else {
      *(uint64_t **)(*(long *)(lVar14 + 0xc0) + 0x10) = puVar24;
    }
    *(uint64_t **)(lVar14 + 0xc0) = puVar24;
    pthread_cond_signal((pthread_cond_t *)(lVar14 + 0x2c));
    pthread_mutex_unlock((pthread_mutex_t *)(lVar14 + 4));
  }
  if (*(long *)(lVar6 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_001635cc:
  if (puVar24 == (uint64_t *)0x0) {
    puVar22 = (uint64_t *)0x0;
  }
  else {
    puVar9 = (uint64_t *)0x0;
    do {
      puVar22 = puVar24;
      puVar24 = (uint64_t *)puVar22[1];
      puVar22[1] = puVar9;
      puVar9 = puVar22;
    } while (puVar24 != (uint64_t *)0x0);
  }
  *(uint64_t **)((long)pvVar8 + uVar17 * 0x60 + 8) = puVar22;
  *(uint32_t *)((long)pvVar8 + uVar17 * 0x60 + 0x10) = *(uint32_t *)(pcVar20 + iVar7 + lVar14);
  FUN_00163adc((long)pvVar8 + uVar17 * 0x60 + 0x18,pcVar20 + iVar7 + lVar14 + 4,plVar1);
  piVar16 = *(int **)((long)pvVar8 + uVar17 * 0x60 + 0x20);
  if (piVar16 == (int *)0x0) {
    iVar23 = 4;
  }
  else {
    iVar23 = 4;
    do {
      iVar29 = *piVar16;
      if (iVar29 == 0x3ba1d6b2) {
        if (*(long *)(piVar16 + 6) == 0) {
          iVar29 = 0xc;
        }
        else {
          iVar29 = piVar16[4] + 0xc;
        }
        iVar23 = iVar23 + 8 + iVar29;
      }
      else if (iVar29 == 0x3b9e38e9) {
        iVar23 = iVar23 + 0x10;
      }
      else if (iVar29 == 0x10) {
        iVar23 = iVar23 + piVar16[6] + 0x1c;
      }
      else {
        iVar23 = iVar23 + 8;
      }
      piVar16 = *(int **)(piVar16 + 2);
    } while (piVar16 != (int *)0x0);
  }
  pcVar11 = *(char **)((long)pvVar8 + uVar17 * 0x60 + 0x38);
  if (pcVar11 == (char *)0x0) {
    iVar29 = 0;
  }
  else {
    sVar31 = strlen(pcVar11);
    iVar29 = (int)sVar31 + 1;
  }
  piVar16 = *(int **)((long)pvVar8 + uVar17 * 0x60 + 0x40);
  iVar32 = 0;
  if (piVar16 == (int *)0x0) goto LAB_00163324;
  if ((*(long *)(piVar16 + 2) == 0) || (*piVar16 < 1)) {
    iVar19 = 0x14;
    if (*(long *)(piVar16 + 6) == 0) goto LAB_00163700;
LAB_0016331c:
    iVar32 = piVar16[4];
  }
  else {
    iVar19 = *piVar16 * 0x14 + 0x14;
    if (*(long *)(piVar16 + 6) != 0) goto LAB_0016331c;
LAB_00163700:
    iVar32 = 0;
  }
  iVar32 = iVar32 + iVar19;
LAB_00163324:
  pcVar11 = pcVar20 + (iVar7 + iVar23 + iVar29 + iVar32 + 0x20) + lVar14;
  uVar13 = VkObject_fromId(*(uint64_t *)pcVar11);
  *(uint64_t *)((long)pvVar8 + uVar17 * 0x60 + 0x48) = uVar13;
  uVar13 = VkObject_fromId(*(uint64_t *)(pcVar11 + 8));
  *(uint64_t *)((long)pvVar8 + uVar17 * 0x60 + 0x50) = uVar13;
  *(uint32_t *)((long)pvVar8 + uVar17 * 0x60 + 0x58) = *(uint32_t *)(pcVar11 + 0x10);
LAB_00163374:
  uVar17 = uVar17 + 1;
  iVar7 = iVar5 + (int)lVar14;
  if (uVar17 == uVar4) goto LAB_00163708;
  goto LAB_00163388;
LAB_00161b28:
  if (puVar24 == (uint64_t *)0x0) {
    puVar22 = (uint64_t *)0x0;
  }
  else {
    puVar9 = (uint64_t *)0x0;
    do {
      puVar22 = puVar24;
      puVar24 = (uint64_t *)puVar22[1];
      puVar22[1] = puVar9;
      puVar9 = puVar22;
    } while (puVar24 != (uint64_t *)0x0);
  }
  iVar23 = iVar7 + 0xc;
  *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 8) = puVar22;
  pcVar11 = pcVar20 + iVar7 + lVar14;
  *(uint32_t *)((long)pvVar8 + local_188 * 0x90 + 0x10) = *(uint32_t *)pcVar11;
  *(uint32_t *)((long)pvVar8 + local_188 * 0x90 + 0x14) = *(uint32_t *)(pcVar11 + 4);
  uVar26 = *(uint32_t *)(pcVar11 + 8);
  uVar17 = (unsigned long)uVar26;
  if ((int)uVar26 < 1) {
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x18) = 0;
  }
  else {
    iVar29 = uVar26 * 0x30;
    iVar7 = *piVar16 + iVar29;
    if ((iVar7 < 0x10000) && (*plVar1 != 0)) {
      pvVar10 = (void *)(*plVar1 + (long)*piVar16);
      *piVar16 = iVar7;
    }
    else {
      pvVar10 = malloc((long)iVar29);
      ArrayList_add(__ptr + 7,pvVar10);
    }
    memset(pvVar10,0,(long)iVar29);
    pvVar30 = pvVar10;
    do {
      iVar7 = *(int *)(pcVar20 + iVar23 + lVar14);
      lVar2 = (long)iVar23 + 4;
      if (pvVar10 != (void *)0x0) {
        FUN_00163adc(pvVar30,pcVar20 + lVar2 + lVar14,plVar1);
      }
      iVar23 = iVar7 + (int)lVar2;
      uVar17 = uVar17 - 1;
      pvVar30 = (void *)((long)pvVar30 + 0x30);
    } while (uVar17 != 0);
    *(void **)((long)pvVar8 + local_188 * 0x90 + 0x18) = pvVar10;
  }
  iVar7 = *(int *)(pcVar20 + iVar23 + lVar14);
  uVar17 = (long)iVar23 + 4;
  if (0 < iVar7) {
    iVar23 = *piVar16;
    if ((iVar23 < 0xffd0) && (*plVar1 != 0)) {
      puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
      *piVar16 = iVar23 + 0x30;
    }
    else {
      puVar24 = malloc(0x30);
      ArrayList_add(__ptr + 7,puVar24);
    }
    puVar24[3] = 0;
    puVar24[2] = 0;
    puVar24[5] = 0;
    puVar24[4] = 0;
    puVar24[1] = 0;
    *puVar24 = 0;
    *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x20) = puVar24;
    piVar18 = (int *)(pcVar20 + uVar17 + lVar14 + 4);
    puVar22 = (uint64_t *)0x0;
    lVar2 = uVar17 + lVar14;
    *(uint32_t *)puVar24 = *(uint32_t *)(pcVar20 + uVar17 + lVar14);
    iVar23 = 8;
    do {
      if (*piVar18 == 0x3b9db031) {
        iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
        uVar28 = (long)iVar23 + 4;
        if (iVar29 < 1) goto LAB_00161cec;
        iVar23 = *piVar16;
        if ((iVar23 < 0xffe0) && (*plVar1 != 0)) {
          puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
          *piVar16 = iVar23 + 0x20;
        }
        else {
          puVar9 = malloc(0x20);
          ArrayList_add(__ptr + 7,puVar9);
        }
        puVar9[1] = 0;
        *puVar9 = 0;
        puVar9[3] = 0;
        puVar9[2] = 0;
        pcVar11 = pcVar20 + uVar28 + lVar2;
        uVar33 = *(uint32_t *)pcVar11;
        puVar9[1] = 0;
        *(uint32_t *)puVar9 = uVar33;
        *(uint32_t *)(puVar9 + 2) = *(uint32_t *)(pcVar11 + 4);
        uVar26 = *(uint32_t *)(pcVar11 + 8);
        uVar25 = (unsigned long)uVar26;
        if ((int)uVar26 < 1) {
          puVar9[3] = 0;
        }
        else {
          iVar32 = uVar26 * 8;
          iVar23 = *piVar16 + iVar32;
          if ((iVar23 < 0x10000) && (*plVar1 != 0)) {
            pvVar10 = (void *)(*plVar1 + (long)*piVar16);
            *piVar16 = iVar23;
          }
          else {
            pvVar10 = malloc((long)iVar32);
            ArrayList_add(__ptr + 7,pvVar10);
          }
          memset(pvVar10,0,(long)iVar32);
          puVar15 = (uint32_t *)((long)pvVar10 + 4);
          iVar23 = 0xc;
          do {
            iVar32 = *(int *)(pcVar11 + iVar23);
            lVar3 = (long)iVar23 + 4;
            if (pvVar10 != (void *)0x0) {
              puVar15[-1] = *(uint32_t *)(pcVar11 + lVar3);
              *puVar15 = *(uint32_t *)(pcVar11 + lVar3 + 4);
            }
            iVar23 = iVar32 + (int)lVar3;
            uVar25 = uVar25 - 1;
            puVar15 = puVar15 + 2;
          } while (uVar25 != 0);
          puVar9[3] = pvVar10;
        }
        iVar23 = iVar29 + (int)uVar28;
        puVar9[1] = puVar22;
        puVar22 = puVar9;
      }
      else {
        if (*piVar18 == -1) goto LAB_00161e70;
        uVar28 = (unsigned long)(iVar23 + 4);
LAB_00161cec:
        iVar23 = (int)uVar28;
      }
      piVar18 = (int *)(pcVar20 + iVar23 + lVar2);
      iVar23 = iVar23 + 4;
    } while( true );
  }
  *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x20) = 0;
LAB_00162090:
  iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
  uVar17 = (long)(int)uVar17 + 4;
  if (iVar7 < 1) {
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x28) = 0;
  }
  else {
    iVar23 = *piVar16;
    if ((iVar23 < 0xffe0) && (*plVar1 != 0)) {
      puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
      *piVar16 = iVar23 + 0x20;
    }
    else {
      puVar24 = malloc(0x20);
      ArrayList_add(__ptr + 7,puVar24);
    }
    puVar24[1] = 0;
    *puVar24 = 0;
    puVar24[3] = 0;
    puVar24[2] = 0;
    pcVar11 = pcVar20 + uVar17 + lVar14;
    *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x28) = puVar24;
    uVar33 = *(uint32_t *)pcVar11;
    puVar24[1] = 0;
    uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
    *(uint32_t *)puVar24 = uVar33;
    *(uint32_t *)(puVar24 + 2) = *(uint32_t *)(pcVar11 + 4);
    *(uint64_t *)((long)puVar24 + 0x14) = *(uint64_t *)(pcVar11 + 8);
  }
  iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
  uVar17 = (long)(int)uVar17 + 4;
  if (0 < iVar7) {
    iVar23 = *piVar16;
    if ((iVar23 < 0xffe8) && (*plVar1 != 0)) {
      puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
      *piVar16 = iVar23 + 0x18;
    }
    else {
      puVar24 = malloc(0x18);
      ArrayList_add(__ptr + 7,puVar24);
    }
    *puVar24 = 0;
    puVar24[1] = 0;
    puVar24[2] = 0;
    *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x30) = puVar24;
    piVar18 = (int *)(pcVar20 + uVar17 + lVar14 + 4);
    lVar2 = uVar17 + lVar14;
    *(uint32_t *)puVar24 = *(uint32_t *)(pcVar20 + uVar17 + lVar14);
    iVar23 = 8;
    puVar22 = (uint64_t *)0x0;
    do {
      puVar9 = puVar22;
      if (*piVar18 == 0x3b9c930b) {
        iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
        uVar28 = (long)iVar23 + 4;
        if (0 < iVar29) {
          iVar23 = *piVar16;
          if ((iVar23 < 0xffe8) && (*plVar1 != 0)) {
            puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
            *piVar16 = iVar23 + 0x18;
          }
          else {
            puVar9 = malloc(0x18);
            ArrayList_add(__ptr + 7,puVar9);
          }
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9[2] = 0;
          lVar3 = uVar28 + lVar2;
          uVar33 = *(uint32_t *)(pcVar20 + lVar3);
          puVar9[1] = 0;
          uVar28 = (unsigned long)(uint32_t)(iVar29 + (int)uVar28);
          *(uint32_t *)puVar9 = uVar33;
          uVar33 = *(uint32_t *)(pcVar20 + lVar3 + 4);
          puVar9[1] = puVar22;
          *(uint32_t *)(puVar9 + 2) = uVar33;
        }
      }
      else {
        if (*piVar18 == -1) goto LAB_0016229c;
        uVar28 = (unsigned long)(iVar23 + 4);
      }
      piVar18 = (int *)(pcVar20 + (int)uVar28 + lVar2);
      iVar23 = (int)uVar28 + 4;
      puVar22 = puVar9;
    } while( true );
  }
  *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x30) = 0;
LAB_001622f4:
  iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
  uVar17 = (long)(int)uVar17 + 4;
  if (0 < iVar7) {
    iVar23 = *piVar16;
    if ((iVar23 < 0xffd0) && (*plVar1 != 0)) {
      puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
      *piVar16 = iVar23 + 0x30;
    }
    else {
      puVar24 = malloc(0x30);
      ArrayList_add(__ptr + 7,puVar24);
    }
    puVar24[3] = 0;
    puVar24[2] = 0;
    puVar24[5] = 0;
    puVar24[4] = 0;
    puVar24[1] = 0;
    *puVar24 = 0;
    *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x38) = puVar24;
    piVar18 = (int *)(pcVar20 + uVar17 + lVar14 + 4);
    lVar2 = uVar17 + lVar14;
    *(uint32_t *)puVar24 = *(uint32_t *)(pcVar20 + uVar17 + lVar14);
    iVar23 = 8;
    puVar22 = (uint64_t *)0x0;
    do {
      puVar9 = puVar22;
      if (*piVar18 == 0x3ba034b9) {
        iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
        uVar28 = (long)iVar23 + 4;
        if (0 < iVar29) {
          iVar23 = *piVar16;
          if ((iVar23 < 0xffe8) && (*plVar1 != 0)) {
            puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
            *piVar16 = iVar23 + 0x18;
          }
          else {
            puVar9 = malloc(0x18);
            ArrayList_add(__ptr + 7,puVar9);
          }
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9[2] = 0;
          lVar3 = uVar28 + lVar2;
          uVar28 = (unsigned long)(uint32_t)(iVar29 + (int)uVar28);
          *(uint32_t *)puVar9 = *(uint32_t *)(pcVar20 + lVar3);
          uVar33 = *(uint32_t *)(pcVar20 + lVar3 + 4);
          puVar9[1] = puVar22;
          *(uint32_t *)(puVar9 + 2) = uVar33;
        }
      }
      else {
        if (*piVar18 == -1) goto LAB_00162448;
        uVar28 = (unsigned long)(iVar23 + 4);
      }
      piVar18 = (int *)(pcVar20 + (int)uVar28 + lVar2);
      iVar23 = (int)uVar28 + 4;
      puVar22 = puVar9;
    } while( true );
  }
  *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x38) = 0;
LAB_00162674:
  iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
  uVar17 = (long)(int)uVar17 + 4;
  if (iVar7 < 1) {
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x40) = 0;
LAB_001629cc:
    iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
    uVar17 = (long)(int)uVar17 + 4;
    if (0 < iVar7) {
      iVar23 = *piVar16;
      if ((iVar23 < 0xffd0) && (*plVar1 != 0)) {
        puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
        *piVar16 = iVar23 + 0x30;
      }
      else {
        puVar24 = malloc(0x30);
        ArrayList_add(__ptr + 7,puVar24);
      }
      puVar24[3] = 0;
      puVar24[2] = 0;
      puVar24[5] = 0;
      puVar24[4] = 0;
      puVar24[1] = 0;
      *puVar24 = 0;
      *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x48) = puVar24;
      piVar18 = (int *)(pcVar20 + uVar17 + lVar14 + 4);
      puVar22 = (uint64_t *)0x0;
      *(uint32_t *)puVar24 = *(uint32_t *)(pcVar20 + uVar17 + lVar14);
      lVar2 = uVar17 + lVar14;
      iVar23 = 8;
      do {
        if (*piVar18 == 0x3b9cf89a) {
          iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
          uVar28 = (long)iVar23 + 4;
          if (iVar29 < 1) goto LAB_00162a80;
          iVar23 = *piVar16;
          if ((iVar23 < 0xffc0) && (*plVar1 != 0)) {
            puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
            *piVar16 = iVar23 + 0x40;
          }
          else {
            puVar9 = malloc(0x40);
            ArrayList_add(__ptr + 7,puVar9);
          }
          puVar9[5] = 0;
          puVar9[4] = 0;
          puVar9[7] = 0;
          puVar9[6] = 0;
          puVar9[1] = 0;
          *puVar9 = 0;
          puVar9[3] = 0;
          puVar9[2] = 0;
          pcVar11 = pcVar20 + uVar28 + lVar2;
          uVar33 = *(uint32_t *)pcVar11;
          puVar9[1] = 0;
          *(uint32_t *)puVar9 = uVar33;
          *(uint32_t *)(puVar9 + 2) = *(uint32_t *)(pcVar11 + 4);
          pcVar27 = pcVar11 + 8;
          uVar33 = *(uint32_t *)pcVar27;
          puVar9[4] = 0;
          *(uint32_t *)(puVar9 + 3) = uVar33;
          puVar9[5] = *(uint64_t *)(pcVar11 + 0xc);
          *(uint32_t *)(puVar9 + 6) = *(uint32_t *)(pcVar11 + 0x14);
          *(uint32_t *)((long)puVar9 + 0x34) = *(uint32_t *)(pcVar11 + 0x18);
          uVar26 = *(uint32_t *)(pcVar11 + 0x1c);
          uVar25 = (unsigned long)uVar26;
          if ((int)uVar26 < 1) {
            puVar9[7] = 0;
          }
          else {
            iVar32 = uVar26 * 8;
            iVar23 = *piVar16 + iVar32;
            if ((iVar23 < 0x10000) && (*plVar1 != 0)) {
              pvVar10 = (void *)(*plVar1 + (long)*piVar16);
              *piVar16 = iVar23;
            }
            else {
              pvVar10 = malloc((long)iVar32);
              ArrayList_add(__ptr + 7,pvVar10);
            }
            memset(pvVar10,0,(long)iVar32);
            puVar15 = (uint32_t *)((long)pvVar10 + 4);
            iVar23 = 0x18;
            do {
              iVar32 = *(int *)(pcVar27 + iVar23);
              lVar3 = (long)iVar23 + 4;
              if (pvVar10 != (void *)0x0) {
                puVar15[-1] = *(uint32_t *)(pcVar27 + lVar3);
                *puVar15 = *(uint32_t *)(pcVar27 + lVar3 + 4);
              }
              iVar23 = iVar32 + (int)lVar3;
              uVar25 = uVar25 - 1;
              puVar15 = puVar15 + 2;
            } while (uVar25 != 0);
            puVar9[7] = pvVar10;
          }
          iVar23 = iVar29 + (int)uVar28;
          puVar9[1] = puVar22;
          puVar22 = puVar9;
        }
        else {
          if (*piVar18 == -1) goto LAB_00162c34;
          uVar28 = (unsigned long)(iVar23 + 4);
LAB_00162a80:
          iVar23 = (int)uVar28;
        }
        piVar18 = (int *)(pcVar20 + iVar23 + lVar2);
        iVar23 = iVar23 + 4;
      } while( true );
    }
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x48) = 0;
LAB_00162cb4:
    iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
    uVar17 = (long)(int)uVar17 + 4;
    if (iVar7 < 1) {
      *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x50) = 0;
    }
    else {
      iVar23 = *piVar16;
      if ((iVar23 < 0xff98) && (*plVar1 != 0)) {
        puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
        *piVar16 = iVar23 + 0x68;
      }
      else {
        puVar24 = malloc(0x68);
        ArrayList_add(__ptr + 7,puVar24);
      }
      puVar24[0xc] = 0;
      puVar24[9] = 0;
      puVar24[8] = 0;
      puVar24[0xb] = 0;
      puVar24[10] = 0;
      puVar24[5] = 0;
      puVar24[4] = 0;
      puVar24[7] = 0;
      puVar24[6] = 0;
      puVar24[1] = 0;
      *puVar24 = 0;
      puVar24[3] = 0;
      puVar24[2] = 0;
      pcVar11 = pcVar20 + uVar17 + lVar14;
      *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x50) = puVar24;
      uVar33 = *(uint32_t *)pcVar11;
      puVar24[1] = 0;
      uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
      *(uint32_t *)puVar24 = uVar33;
      *(uint32_t *)(puVar24 + 2) = *(uint32_t *)(pcVar11 + 4);
      *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar11 + 8);
      *(uint32_t *)(puVar24 + 3) = *(uint32_t *)(pcVar11 + 0xc);
      *(uint64_t *)((long)puVar24 + 0x1c) = *(uint64_t *)(pcVar11 + 0x10);
      *(uint32_t *)((long)puVar24 + 0x24) = *(uint32_t *)(pcVar11 + 0x18);
      *(uint32_t *)(puVar24 + 5) = *(uint32_t *)(pcVar11 + 0x1c);
      *(uint32_t *)((long)puVar24 + 0x2c) = *(uint32_t *)(pcVar11 + 0x20);
      *(uint32_t *)(puVar24 + 6) = *(uint32_t *)(pcVar11 + 0x24);
      *(uint64_t *)((long)puVar24 + 0x34) = *(uint64_t *)(pcVar11 + 0x28);
      *(uint32_t *)((long)puVar24 + 0x3c) = *(uint32_t *)(pcVar11 + 0x30);
      *(uint32_t *)(puVar24 + 8) = *(uint32_t *)(pcVar11 + 0x34);
      *(uint32_t *)((long)puVar24 + 0x44) = *(uint32_t *)(pcVar11 + 0x38);
      *(uint32_t *)(puVar24 + 9) = *(uint32_t *)(pcVar11 + 0x3c);
      *(uint32_t *)((long)puVar24 + 0x4c) = *(uint32_t *)(pcVar11 + 0x40);
      puVar24[10] = *(uint64_t *)(pcVar11 + 0x44);
      *(uint32_t *)(puVar24 + 0xb) = *(uint32_t *)(pcVar11 + 0x4c);
      *(uint32_t *)((long)puVar24 + 0x5c) = *(uint32_t *)(pcVar11 + 0x50);
      *(uint32_t *)(puVar24 + 0xc) = *(uint32_t *)(pcVar11 + 0x54);
      *(uint32_t *)((long)puVar24 + 100) = *(uint32_t *)(pcVar11 + 0x58);
    }
    iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
    uVar17 = (long)(int)uVar17 + 4;
    if (0 < iVar7) {
      iVar23 = *piVar16;
      if ((iVar23 < 0xffc8) && (*plVar1 != 0)) {
        puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
        *piVar16 = iVar23 + 0x38;
      }
      else {
        puVar24 = malloc(0x38);
        ArrayList_add(__ptr + 7,puVar24);
      }
      puVar24[6] = 0;
      puVar24[3] = 0;
      puVar24[2] = 0;
      puVar24[5] = 0;
      puVar24[4] = 0;
      puVar24[1] = 0;
      *puVar24 = 0;
      *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x58) = puVar24;
      piVar18 = (int *)(pcVar20 + uVar17 + lVar14 + 4);
      puVar22 = (uint64_t *)0x0;
      lVar2 = uVar17 + lVar14;
      *(uint32_t *)puVar24 = *(uint32_t *)(pcVar20 + uVar17 + lVar14);
      iVar23 = 8;
      do {
        if (*piVar18 == 0x3ba09a49) {
          iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
          uVar28 = (long)iVar23 + 4;
          if (iVar29 < 1) goto LAB_00162eac;
          iVar23 = *piVar16;
          if ((iVar23 < 0xffe0) && (*plVar1 != 0)) {
            puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
            *piVar16 = iVar23 + 0x20;
          }
          else {
            puVar9 = malloc(0x20);
            ArrayList_add(__ptr + 7,puVar9);
          }
          puVar9[1] = 0;
          *puVar9 = 0;
          puVar9[3] = 0;
          puVar9[2] = 0;
          pcVar11 = pcVar20 + uVar28 + lVar2;
          uVar33 = *(uint32_t *)pcVar11;
          puVar9[1] = 0;
          *(uint32_t *)puVar9 = uVar33;
          *(uint32_t *)(puVar9 + 2) = *(uint32_t *)(pcVar11 + 4);
          if (*(int *)(pcVar11 + 8) < 1) {
            puVar9[3] = 0;
          }
          else {
            sVar31 = (long)*(int *)(pcVar11 + 8) << 2;
            iVar32 = (int)sVar31;
            iVar23 = *piVar16 + iVar32;
            if ((iVar23 < 0x10000) && (*plVar1 != 0)) {
              pvVar10 = (void *)(*plVar1 + (long)*piVar16);
              *piVar16 = iVar23;
              sVar31 = (size_t)iVar32;
            }
            else {
              pvVar10 = malloc(sVar31);
              ArrayList_add(__ptr + 7,pvVar10);
            }
            memset(pvVar10,0,sVar31);
            if (pvVar10 != (void *)0x0) {
              memcpy(pvVar10,pcVar11 + 0xc,(long)iVar32);
            }
            puVar9[3] = pvVar10;
          }
          iVar23 = iVar29 + (int)uVar28;
          puVar9[1] = puVar22;
          puVar22 = puVar9;
        }
        else {
          if (*piVar18 == -1) goto LAB_00163000;
          uVar28 = (unsigned long)(iVar23 + 4);
LAB_00162eac:
          iVar23 = (int)uVar28;
        }
        piVar18 = (int *)(pcVar20 + iVar23 + lVar2);
        iVar23 = iVar23 + 4;
      } while( true );
    }
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x58) = 0;
LAB_00163164:
    iVar7 = *(int *)(pcVar20 + (int)uVar17 + lVar14);
    uVar17 = (long)(int)uVar17 + 4;
    if (iVar7 < 1) {
      *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x60) = 0;
    }
    else {
      iVar23 = *piVar16;
      if ((iVar23 < 0xffe0) && (*plVar1 != 0)) {
        puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
        *piVar16 = iVar23 + 0x20;
      }
      else {
        puVar24 = malloc(0x20);
        ArrayList_add(__ptr + 7,puVar24);
      }
      puVar24[1] = 0;
      *puVar24 = 0;
      puVar24[3] = 0;
      puVar24[2] = 0;
      pcVar11 = pcVar20 + uVar17 + lVar14;
      *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x60) = puVar24;
      uVar33 = *(uint32_t *)pcVar11;
      puVar24[1] = 0;
      *(uint32_t *)puVar24 = uVar33;
      *(uint32_t *)(puVar24 + 2) = *(uint32_t *)(pcVar11 + 4);
      *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar11 + 8);
      if (*(int *)(pcVar11 + 0xc) < 1) {
        puVar24[3] = 0;
      }
      else {
        sVar31 = (long)*(int *)(pcVar11 + 0xc) << 2;
        iVar29 = (int)sVar31;
        iVar23 = *piVar16 + iVar29;
        if ((iVar23 < 0x10000) && (*plVar1 != 0)) {
          pvVar10 = (void *)(*plVar1 + (long)*piVar16);
          *piVar16 = iVar23;
          sVar31 = (size_t)iVar29;
        }
        else {
          pvVar10 = malloc(sVar31);
          ArrayList_add(__ptr + 7,pvVar10);
        }
        memset(pvVar10,0,sVar31);
        if (pvVar10 != (void *)0x0) {
          memcpy(pvVar10,pcVar11 + 0x10,(long)iVar29);
        }
        puVar24[3] = pvVar10;
      }
      uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
    }
    pcVar11 = pcVar20 + (int)uVar17 + lVar14;
    uVar13 = VkObject_fromId(*(uint64_t *)pcVar11);
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x68) = uVar13;
    uVar13 = VkObject_fromId(*(uint64_t *)(pcVar11 + 8));
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x70) = uVar13;
    *(uint32_t *)((long)pvVar8 + local_188 * 0x90 + 0x78) = *(uint32_t *)(pcVar11 + 0x10);
    uVar13 = VkObject_fromId(*(uint64_t *)(pcVar11 + 0x14));
    *(uint64_t *)((long)pvVar8 + local_188 * 0x90 + 0x80) = uVar13;
    *(uint32_t *)((long)pvVar8 + local_188 * 0x90 + 0x88) = *(uint32_t *)(pcVar11 + 0x1c);
LAB_00161748:
    local_188 = local_188 + 1;
    iVar7 = iVar5 + (int)lVar14;
    if (local_188 == uVar4) goto LAB_00163708;
    goto LAB_00161760;
  }
  iVar23 = *piVar16;
  if ((iVar23 < 0xffc0) && (*plVar1 != 0)) {
    puVar24 = (uint64_t *)(*plVar1 + (long)iVar23);
    *piVar16 = iVar23 + 0x40;
  }
  else {
    puVar24 = malloc(0x40);
    ArrayList_add(__ptr + 7,puVar24);
  }
  puVar24[5] = 0;
  puVar24[4] = 0;
  puVar24[7] = 0;
  puVar24[6] = 0;
  puVar24[1] = 0;
  *puVar24 = 0;
  puVar24[3] = 0;
  puVar24[2] = 0;
  *(uint64_t **)((long)pvVar8 + local_188 * 0x90 + 0x40) = puVar24;
  piVar18 = (int *)(pcVar20 + uVar17 + lVar14 + 4);
  puVar22 = (uint64_t *)0x0;
  lVar2 = uVar17 + lVar14;
  *(uint32_t *)puVar24 = *(uint32_t *)(pcVar20 + uVar17 + lVar14);
  iVar23 = 8;
LAB_00162760:
  iVar29 = *piVar18;
  if (0x3b9c5870 < iVar29) {
    if (iVar29 == 0x3b9c5871) goto LAB_0016283c;
    if (iVar29 != 0x3b9eaa31) goto LAB_0016288c;
    iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
    uVar28 = (long)iVar23 + 4;
    if (0 < iVar29) {
      iVar23 = *piVar16;
      if ((iVar23 < 0xffe8) && (*plVar1 != 0)) {
        puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
        *piVar16 = iVar23 + 0x18;
      }
      else {
        puVar9 = malloc(0x18);
        ArrayList_add(__ptr + 7,puVar9);
      }
      *puVar9 = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      lVar3 = uVar28 + lVar2;
      uVar33 = *(uint32_t *)(pcVar20 + lVar3);
      puVar9[1] = 0;
      uVar28 = (unsigned long)(uint32_t)(iVar29 + (int)uVar28);
      *(uint32_t *)puVar9 = uVar33;
      *(uint32_t *)(puVar9 + 2) = *(uint32_t *)(pcVar20 + lVar3 + 4);
      goto LAB_00162750;
    }
    goto LAB_00162758;
  }
  if (iVar29 == 0x3b9b3762) {
LAB_0016283c:
    iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
    uVar28 = (long)iVar23 + 4;
    if (iVar29 < 1) goto LAB_00162758;
    iVar23 = *piVar16;
    if ((iVar23 < 0xffe8) && (*plVar1 != 0)) {
      puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
      *piVar16 = iVar23 + 0x18;
    }
    else {
      puVar9 = malloc(0x18);
      ArrayList_add(__ptr + 7,puVar9);
    }
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    pcVar11 = pcVar20 + uVar28 + lVar2;
    uVar28 = (unsigned long)(uint32_t)(iVar29 + (int)uVar28);
    *(uint32_t *)puVar9 = *(uint32_t *)pcVar11;
    *(uint32_t *)(puVar9 + 2) = *(uint32_t *)(pcVar11 + 4);
    *(uint32_t *)((long)puVar9 + 0x14) = *(uint32_t *)(pcVar11 + 8);
  }
  else {
    if (iVar29 != 0x3b9c5489) {
      if (iVar29 != -1) {
LAB_0016288c:
        uVar28 = (unsigned long)(iVar23 + 4);
        goto LAB_00162758;
      }
      if (puVar22 == (uint64_t *)0x0) {
        puVar9 = (uint64_t *)0x0;
      }
      else {
        puVar21 = (uint64_t *)0x0;
        do {
          puVar9 = puVar22;
          puVar22 = (uint64_t *)puVar9[1];
          puVar9[1] = puVar21;
          puVar21 = puVar9;
        } while (puVar22 != (uint64_t *)0x0);
      }
      puVar24[1] = puVar9;
      pcVar11 = pcVar20 + iVar23 + lVar2;
      uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
      *(uint32_t *)(puVar24 + 2) = *(uint32_t *)pcVar11;
      *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar11 + 4);
      *(uint32_t *)(puVar24 + 3) = *(uint32_t *)(pcVar11 + 8);
      *(uint32_t *)((long)puVar24 + 0x1c) = *(uint32_t *)(pcVar11 + 0xc);
      *(uint32_t *)(puVar24 + 4) = *(uint32_t *)(pcVar11 + 0x10);
      *(uint32_t *)((long)puVar24 + 0x24) = *(uint32_t *)(pcVar11 + 0x14);
      *(uint32_t *)(puVar24 + 5) = *(uint32_t *)(pcVar11 + 0x18);
      *(uint32_t *)((long)puVar24 + 0x2c) = *(uint32_t *)(pcVar11 + 0x1c);
      *(uint32_t *)(puVar24 + 6) = *(uint32_t *)(pcVar11 + 0x20);
      *(uint32_t *)((long)puVar24 + 0x34) = *(uint32_t *)(pcVar11 + 0x24);
      *(uint32_t *)(puVar24 + 7) = *(uint32_t *)(pcVar11 + 0x28);
      goto LAB_001629cc;
    }
    iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
    uVar28 = (long)iVar23 + 4;
    if (iVar29 < 1) goto LAB_00162758;
    iVar23 = *piVar16;
    if ((iVar23 < 0xffe0) && (*plVar1 != 0)) {
      puVar9 = (uint64_t *)(*plVar1 + (long)iVar23);
      *piVar16 = iVar23 + 0x20;
    }
    else {
      puVar9 = malloc(0x20);
      ArrayList_add(__ptr + 7,puVar9);
    }
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9[3] = 0;
    puVar9[2] = 0;
    pcVar11 = pcVar20 + uVar28 + lVar2;
    uVar33 = *(uint32_t *)pcVar11;
    puVar9[1] = 0;
    uVar28 = (unsigned long)(uint32_t)(iVar29 + (int)uVar28);
    *(uint32_t *)puVar9 = uVar33;
    *(uint32_t *)(puVar9 + 2) = *(uint32_t *)(pcVar11 + 4);
    *(uint32_t *)((long)puVar9 + 0x14) = *(uint32_t *)(pcVar11 + 8);
    *(uint32_t *)(puVar9 + 3) = *(uint32_t *)(pcVar11 + 0xc);
  }
LAB_00162750:
  puVar9[1] = puVar22;
  puVar22 = puVar9;
LAB_00162758:
  piVar18 = (int *)(pcVar20 + (int)uVar28 + lVar2);
  iVar23 = (int)uVar28 + 4;
  goto LAB_00162760;
LAB_00161e70:
  if (puVar22 == (uint64_t *)0x0) {
    puVar9 = (uint64_t *)0x0;
  }
  else {
    puVar21 = (uint64_t *)0x0;
    do {
      puVar9 = puVar22;
      puVar22 = (uint64_t *)puVar9[1];
      puVar9[1] = puVar21;
      puVar21 = puVar9;
    } while (puVar22 != (uint64_t *)0x0);
  }
  puVar24[1] = puVar9;
  pcVar11 = pcVar20 + iVar23 + lVar2;
  iVar23 = iVar23 + 0xc;
  *(uint32_t *)(puVar24 + 2) = *(uint32_t *)pcVar11;
  *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar11 + 4);
  uVar26 = *(uint32_t *)(pcVar11 + 8);
  uVar28 = (unsigned long)uVar26;
  if ((int)uVar26 < 1) {
    puVar24[3] = 0;
  }
  else {
    iVar32 = uVar26 * 0xc;
    iVar29 = *piVar16 + iVar32;
    if ((iVar29 < 0x10000) && (*plVar1 != 0)) {
      pvVar10 = (void *)(*plVar1 + (long)*piVar16);
      *piVar16 = iVar29;
    }
    else {
      pvVar10 = malloc((long)iVar32);
      ArrayList_add(__ptr + 7,pvVar10);
    }
    memset(pvVar10,0,(long)iVar32);
    puVar15 = (uint32_t *)((long)pvVar10 + 8);
    do {
      iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
      lVar3 = (long)iVar23 + 4;
      if (pvVar10 != (void *)0x0) {
        pcVar11 = pcVar20 + lVar3 + lVar2;
        puVar15[-2] = *(uint32_t *)pcVar11;
        puVar15[-1] = *(uint32_t *)(pcVar11 + 4);
        *puVar15 = *(uint32_t *)(pcVar11 + 8);
      }
      iVar23 = iVar29 + (int)lVar3;
      uVar28 = uVar28 - 1;
      puVar15 = puVar15 + 3;
    } while (uVar28 != 0);
    puVar24[3] = pvVar10;
  }
  *(uint32_t *)(puVar24 + 4) = *(uint32_t *)(pcVar20 + iVar23 + lVar2);
  uVar26 = *(uint32_t *)(pcVar20 + iVar23 + lVar2 + 4);
  uVar28 = (unsigned long)uVar26;
  if ((int)uVar26 < 1) {
    puVar24[5] = 0;
  }
  else {
    iVar32 = uVar26 * 0x10;
    iVar29 = *piVar16 + iVar32;
    if ((iVar29 < 0x10000) && (*plVar1 != 0)) {
      pvVar10 = (void *)(*plVar1 + (long)*piVar16);
      *piVar16 = iVar29;
    }
    else {
      pvVar10 = malloc((long)iVar32);
      ArrayList_add(__ptr + 7,pvVar10);
    }
    iVar23 = iVar23 + 8;
    memset(pvVar10,0,(long)iVar32);
    puVar22 = (uint64_t *)((long)pvVar10 + 8);
    do {
      iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
      lVar3 = (long)iVar23 + 4;
      if (pvVar10 != (void *)0x0) {
        pcVar11 = pcVar20 + lVar3 + lVar2;
        *(uint32_t *)(puVar22 + -1) = *(uint32_t *)pcVar11;
        *(uint32_t *)((long)puVar22 + -4) = *(uint32_t *)(pcVar11 + 4);
        *puVar22 = *(uint64_t *)(pcVar11 + 8);
      }
      iVar23 = iVar29 + (int)lVar3;
      uVar28 = uVar28 - 1;
      puVar22 = puVar22 + 2;
    } while (uVar28 != 0);
    puVar24[5] = pvVar10;
  }
  uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
  goto LAB_00162090;
LAB_0016229c:
  if (puVar22 == (uint64_t *)0x0) {
    puVar9 = (uint64_t *)0x0;
  }
  else {
    puVar21 = (uint64_t *)0x0;
    do {
      puVar9 = puVar22;
      puVar22 = (uint64_t *)puVar9[1];
      puVar9[1] = puVar21;
      puVar21 = puVar9;
    } while (puVar22 != (uint64_t *)0x0);
  }
  puVar24[1] = puVar9;
  uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
  *(uint32_t *)(puVar24 + 2) = *(uint32_t *)(pcVar20 + iVar23 + lVar2);
  *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar20 + iVar23 + lVar2 + 4);
  goto LAB_001622f4;
LAB_00162448:
  if (puVar22 == (uint64_t *)0x0) {
    puVar9 = (uint64_t *)0x0;
  }
  else {
    puVar21 = (uint64_t *)0x0;
    do {
      puVar9 = puVar22;
      puVar22 = (uint64_t *)puVar9[1];
      puVar9[1] = puVar21;
      puVar21 = puVar9;
    } while (puVar22 != (uint64_t *)0x0);
  }
  puVar24[1] = puVar9;
  pcVar11 = pcVar20 + iVar23 + lVar2;
  iVar23 = iVar23 + 0xc;
  *(uint32_t *)(puVar24 + 2) = *(uint32_t *)pcVar11;
  *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar11 + 4);
  uVar26 = *(uint32_t *)(pcVar11 + 8);
  uVar28 = (unsigned long)uVar26;
  if ((int)uVar26 < 1) {
    puVar24[3] = 0;
  }
  else {
    iVar32 = uVar26 * 0x18;
    iVar29 = *piVar16 + iVar32;
    if ((iVar29 < 0x10000) && (*plVar1 != 0)) {
      pvVar10 = (void *)(*plVar1 + (long)*piVar16);
      *piVar16 = iVar29;
    }
    else {
      pvVar10 = malloc((long)iVar32);
      ArrayList_add(__ptr + 7,pvVar10);
    }
    memset(pvVar10,0,(long)iVar32);
    puVar15 = (uint32_t *)((long)pvVar10 + 0xc);
    do {
      iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
      lVar3 = (long)iVar23 + 4;
      if (pvVar10 != (void *)0x0) {
        pcVar11 = pcVar20 + lVar3 + lVar2;
        puVar15[-3] = *(uint32_t *)pcVar11;
        puVar15[-2] = *(uint32_t *)(pcVar11 + 4);
        puVar15[-1] = *(uint32_t *)(pcVar11 + 8);
        *puVar15 = *(uint32_t *)(pcVar11 + 0xc);
        puVar15[1] = *(uint32_t *)(pcVar11 + 0x10);
        puVar15[2] = *(uint32_t *)(pcVar11 + 0x14);
      }
      iVar23 = iVar29 + (int)lVar3;
      uVar28 = uVar28 - 1;
      puVar15 = puVar15 + 6;
    } while (uVar28 != 0);
    puVar24[3] = pvVar10;
  }
  *(uint32_t *)(puVar24 + 4) = *(uint32_t *)(pcVar20 + iVar23 + lVar2);
  uVar26 = *(uint32_t *)(pcVar20 + iVar23 + lVar2 + 4);
  uVar28 = (unsigned long)uVar26;
  if ((int)uVar26 < 1) {
    puVar24[5] = 0;
  }
  else {
    iVar32 = uVar26 * 0x10;
    iVar29 = *piVar16 + iVar32;
    if ((iVar29 < 0x10000) && (*plVar1 != 0)) {
      pvVar10 = (void *)(*plVar1 + (long)*piVar16);
      *piVar16 = iVar29;
    }
    else {
      pvVar10 = malloc((long)iVar32);
      ArrayList_add(__ptr + 7,pvVar10);
    }
    iVar23 = iVar23 + 8;
    memset(pvVar10,0,(long)iVar32);
    puVar15 = (uint32_t *)((long)pvVar10 + 8);
    do {
      iVar29 = *(int *)(pcVar20 + iVar23 + lVar2);
      lVar3 = (long)iVar23 + 4;
      if (pvVar10 != (void *)0x0) {
        pcVar11 = pcVar20 + lVar3 + lVar2;
        puVar15[-2] = *(uint32_t *)pcVar11;
        puVar15[-1] = *(uint32_t *)(pcVar11 + 4);
        *puVar15 = *(uint32_t *)(pcVar11 + 8);
        puVar15[1] = *(uint32_t *)(pcVar11 + 0xc);
      }
      iVar23 = iVar29 + (int)lVar3;
      uVar28 = uVar28 - 1;
      puVar15 = puVar15 + 4;
    } while (uVar28 != 0);
    puVar24[5] = pvVar10;
  }
  uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
  goto LAB_00162674;
LAB_00162c34:
  if (puVar22 == (uint64_t *)0x0) {
    puVar9 = (uint64_t *)0x0;
  }
  else {
    puVar21 = (uint64_t *)0x0;
    do {
      puVar9 = puVar22;
      puVar22 = (uint64_t *)puVar9[1];
      puVar9[1] = puVar21;
      puVar21 = puVar9;
    } while (puVar22 != (uint64_t *)0x0);
  }
  pcVar11 = pcVar20 + iVar23 + lVar2;
  puVar24[1] = puVar9;
  *(uint32_t *)(puVar24 + 2) = *(uint32_t *)pcVar11;
  *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar11 + 4);
  *(uint32_t *)(puVar24 + 3) = *(uint32_t *)(pcVar11 + 8);
  uVar33 = *(uint32_t *)(pcVar11 + 0xc);
  puVar24[4] = 0;
  *(uint32_t *)((long)puVar24 + 0x1c) = uVar33;
  *(uint32_t *)(puVar24 + 5) = *(uint32_t *)(pcVar11 + 0x10);
  *(uint32_t *)((long)puVar24 + 0x2c) = *(uint32_t *)(pcVar11 + 0x14);
  uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
  goto LAB_00162cb4;
LAB_00163000:
  if (puVar22 == (uint64_t *)0x0) {
    puVar9 = (uint64_t *)0x0;
  }
  else {
    puVar21 = (uint64_t *)0x0;
    do {
      puVar9 = puVar22;
      puVar22 = (uint64_t *)puVar9[1];
      puVar9[1] = puVar21;
      puVar21 = puVar9;
    } while (puVar22 != (uint64_t *)0x0);
  }
  iVar29 = iVar23 + 0x14;
  puVar24[1] = puVar9;
  pcVar11 = pcVar20 + iVar23 + lVar2;
  *(uint32_t *)(puVar24 + 2) = *(uint32_t *)pcVar11;
  *(uint32_t *)((long)puVar24 + 0x14) = *(uint32_t *)(pcVar11 + 4);
  *(uint32_t *)(puVar24 + 3) = *(uint32_t *)(pcVar11 + 8);
  *(uint32_t *)((long)puVar24 + 0x1c) = *(uint32_t *)(pcVar11 + 0xc);
  uVar26 = *(uint32_t *)(pcVar11 + 0x10);
  uVar28 = (unsigned long)uVar26;
  if ((int)uVar26 < 1) {
    puVar24[4] = 0;
  }
  else {
    iVar32 = uVar26 * 0x20;
    iVar23 = *piVar16 + iVar32;
    if ((iVar23 < 0x10000) && (*plVar1 != 0)) {
      pvVar10 = (void *)(*plVar1 + (long)*piVar16);
      *piVar16 = iVar23;
    }
    else {
      pvVar10 = malloc((long)iVar32);
      ArrayList_add(__ptr + 7,pvVar10);
    }
    memset(pvVar10,0,(long)iVar32);
    puVar15 = (uint32_t *)((long)pvVar10 + 0xc);
    do {
      iVar23 = *(int *)(pcVar20 + iVar29 + lVar2);
      lVar3 = (long)iVar29 + 4;
      if (pvVar10 != (void *)0x0) {
        pcVar11 = pcVar20 + lVar3 + lVar2;
        puVar15[-3] = *(uint32_t *)pcVar11;
        puVar15[-2] = *(uint32_t *)(pcVar11 + 4);
        puVar15[-1] = *(uint32_t *)(pcVar11 + 8);
        *puVar15 = *(uint32_t *)(pcVar11 + 0xc);
        puVar15[1] = *(uint32_t *)(pcVar11 + 0x10);
        puVar15[2] = *(uint32_t *)(pcVar11 + 0x14);
        *(uint64_t *)(puVar15 + 3) = *(uint64_t *)(pcVar11 + 0x18);
      }
      iVar29 = iVar23 + (int)lVar3;
      uVar28 = uVar28 - 1;
      puVar15 = puVar15 + 8;
    } while (uVar28 != 0);
    puVar24[4] = pvVar10;
  }
  uVar13 = *(uint64_t *)(pcVar20 + iVar29 + lVar2);
  puVar24[6] = *(uint64_t *)(pcVar20 + iVar29 + lVar2 + 8);
  puVar24[5] = uVar13;
  uVar17 = (unsigned long)(uint32_t)((int)uVar17 + iVar7);
  goto LAB_00163164;
}


