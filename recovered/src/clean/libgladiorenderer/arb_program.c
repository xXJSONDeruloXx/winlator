/*
 * arb_program.c — ARB program object management
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include "gladio_data.h"
#include <GLES3/gl32.h>
#include <EGL/egl.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>

/* @0013b8b0  size=616 */

void ARBProgram_bind(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  lVar3 = SparseArray_get(*(uint64_t *)(*plVar2 + 0x5b8),param_2);
  pthread_mutex_unlock((&glx_context_mutex));
  if (lVar3 == 0) {
LAB_0013b950:
    plVar2 = (long *)(&currentRenderer);
    lVar6 = *plVar2;
    lVar5 = 0;
    if (param_1 < 0x88eb) {
      if (param_1 < 0x8643) {
        if (param_1 < 0x8513) {
          if (param_1 - 0xde0U < 2) goto LAB_0013badc;
          iVar4 = 0x806f;
          goto LAB_0013ba90;
        }
        if (param_1 == 0x8513) goto LAB_0013bad8;
        if (param_1 == 0x8620) goto LAB_0013badc;
      }
      else {
        if (param_1 < 0x8892) {
          if (param_1 == 0x8643) goto LAB_0013badc;
          iVar4 = 0x8804;
        }
        else {
          if (param_1 == 0x8892) goto LAB_0013badc;
          iVar4 = 0x8893;
        }
LAB_0013ba90:
        if (param_1 == iVar4) goto LAB_0013ba98;
      }
LAB_0013bac8:
      if (5 < param_1 - 0x8515U) {
        __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
        lVar5 = 0xff;
        goto LAB_0013badc;
      }
    }
    else {
      if (param_1 < 0x8c1a) {
        if (param_1 < 0x8a11) {
          if (param_1 == 0x88eb) goto LAB_0013bad8;
          iVar4 = 0x88ec;
        }
        else {
          if (param_1 == 0x8a11) {
            lVar5 = 4;
            goto LAB_0013badc;
          }
          iVar4 = 0x8c18;
        }
        if (param_1 != iVar4) goto LAB_0013bac8;
LAB_0013bab8:
        lVar5 = 3;
        goto LAB_0013badc;
      }
      if (param_1 < 0x8ca8) {
        if (param_1 != 0x8c1a) {
          if (param_1 == 0x8c2a) {
            lVar5 = 5;
            goto LAB_0013badc;
          }
          goto LAB_0013bac8;
        }
        goto LAB_0013bab8;
      }
      if (param_1 != 0x8ca8) {
        if (param_1 == 0x8d40) goto LAB_0013badc;
        iVar4 = 0x8ca9;
        goto LAB_0013ba90;
      }
    }
LAB_0013bad8:
    lVar5 = 2;
  }
  else {
    if (param_1 != 0x8804) {
      if (param_1 == 0x8620) {
        if (*(int *)(lVar3 + 8) == 0) {
          uVar1 = ShaderConverter_createShader(0x8b31);
          *(uint32_t *)(lVar3 + 8) = uVar1;
        }
        *(uint32_t *)(lVar3 + 4) = 0x8620;
        plVar2 = (long *)(&currentRenderer);
        lVar6 = *plVar2;
        lVar5 = 0;
        goto LAB_0013badc;
      }
      goto LAB_0013b950;
    }
    if (*(int *)(lVar3 + 8) == 0) {
      uVar1 = ShaderConverter_createShader(0x8b30);
      *(uint32_t *)(lVar3 + 8) = uVar1;
    }
    *(uint32_t *)(lVar3 + 4) = 0x8804;
    plVar2 = (long *)(&currentRenderer);
    lVar6 = *plVar2;
LAB_0013ba98:
    lVar5 = 1;
  }
LAB_0013badc:
  *(long *)(lVar6 + lVar5 * 8 + 0x598) = lVar3;
  return;
}


/* @0013b620  size=136 */

int * ARBProgram_create(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  long *plVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  piVar3 = calloc(1,0x40);
  iVar1 = DAT_00144eec;
  iVar2 = DAT_00144eec + 1;
  *piVar3 = DAT_00144eec;
  DAT_00144eec = iVar2;
  iVar2 = gettid();
  piVar3[3] = iVar2;
  plVar4 = (long *)(&currentRenderer);
  SparseArray_put(*(uint64_t *)(*plVar4 + 0x5b8),iVar1,piVar3);
  pthread_mutex_unlock((&glx_context_mutex));
  return piVar3;
}


/* @0013beb0  size=236 */

int ARBProgram_delete(uint32_t param_1)

{
  int iVar1;
  long *plVar2;
  void *__ptr;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  __ptr = (void *)SparseArray_get(*(uint64_t *)(*plVar2 + 0x5b8),param_1);
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  if (__ptr != (void *)0x0) {
    if (*(int *)((long)__ptr + 8) != 0) {
      ShaderConverter_deleteShader();
    }
    SparseArray_free((long)__ptr + 0x10,1);
    SparseArray_free((long)__ptr + 0x20,1);
    if (*(void **)((long)__ptr + 0x30) != (void *)0x0) {
      free(*(void **)((long)__ptr + 0x30));
      *(uint64_t *)((long)__ptr + 0x30) = 0;
    }
    if (*(void **)((long)__ptr + 0x38) != (void *)0x0) {
      free(*(void **)((long)__ptr + 0x38));
      *(uint64_t *)((long)__ptr + 0x38) = 0;
    }
    free(__ptr);
    pthread_mutex_lock((&glx_context_mutex));
    plVar2 = (long *)(&currentRenderer);
    SparseArray_remove(*(uint64_t *)(*plVar2 + 0x5b8),param_1);
    iVar1 = pthread_mutex_unlock((&glx_context_mutex));
    return iVar1;
  }
  return iVar1;
}


/* @0013b6a8  size=100 */

uint64_t ARBProgram_get(int param_1)

{
  long *plVar1;
  uint64_t uVar2;
  
  if (param_1 != 0) {
    pthread_mutex_lock((&glx_context_mutex));
    plVar1 = (long *)(&currentRenderer);
    uVar2 = SparseArray_get(*(uint64_t *)(*plVar1 + 0x5b8),param_1);
    pthread_mutex_unlock((&glx_context_mutex));
    return uVar2;
  }
  return 0;
}


/* @0013b70c  size=420 */

uint64_t ARBProgram_getBound(int param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  plVar1 = (long *)(&currentRenderer);
  lVar4 = *plVar1;
  lVar3 = 0;
  if (param_1 < 0x88eb) {
    if (param_1 < 0x8643) {
      if (param_1 < 0x8513) {
        if (param_1 - 0xde0U < 2) goto LAB_0013b878;
        iVar2 = 0x806f;
        goto LAB_0013b82c;
      }
      if (param_1 == 0x8513) goto LAB_0013b874;
      if (param_1 == 0x8620) goto LAB_0013b878;
    }
    else {
      if (param_1 < 0x8892) {
        if (param_1 == 0x8643) goto LAB_0013b878;
        iVar2 = 0x8804;
      }
      else {
        if (param_1 == 0x8892) goto LAB_0013b878;
        iVar2 = 0x8893;
      }
LAB_0013b82c:
      if (param_1 == iVar2) {
        lVar3 = 1;
        goto LAB_0013b878;
      }
    }
LAB_0013b864:
    if (5 < param_1 - 0x8515U) {
      __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_1);
      lVar3 = 0xff;
      goto LAB_0013b878;
    }
  }
  else {
    if (param_1 < 0x8c1a) {
      if (param_1 < 0x8a11) {
        if (param_1 == 0x88eb) goto LAB_0013b874;
        iVar2 = 0x88ec;
      }
      else {
        if (param_1 == 0x8a11) {
          lVar3 = 4;
          goto LAB_0013b878;
        }
        iVar2 = 0x8c18;
      }
      if (param_1 != iVar2) goto LAB_0013b864;
LAB_0013b854:
      lVar3 = 3;
      goto LAB_0013b878;
    }
    if (param_1 < 0x8ca8) {
      if (param_1 != 0x8c1a) {
        if (param_1 == 0x8c2a) {
          lVar3 = 5;
          goto LAB_0013b878;
        }
        goto LAB_0013b864;
      }
      goto LAB_0013b854;
    }
    if (param_1 != 0x8ca8) {
      if (param_1 == 0x8d40) goto LAB_0013b878;
      iVar2 = 0x8ca9;
      goto LAB_0013b82c;
    }
  }
LAB_0013b874:
  lVar3 = 2;
LAB_0013b878:
  return *(uint64_t *)(lVar4 + lVar3 * 8 + 0x598);
}


/* @0013c130  size=164 */

void ARBProgram_onDestroy(long param_1)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  void *__ptr;
  long lVar3;
  
  puVar1 = *(uint32_t **)(param_1 + 0x220);
  uVar2 = *puVar1;
  if (0 < (int)uVar2) {
    lVar3 = (unsigned long)uVar2 + 1;
    do {
      uVar2 = uVar2 - 1;
      __ptr = *(void **)(*(long *)(puVar1 + 2) + (unsigned long)uVar2 * 0x10 + 8);
      SparseArray_free((long)__ptr + 0x10,1);
      SparseArray_free((long)__ptr + 0x20,1);
      if (*(void **)((long)__ptr + 0x30) != (void *)0x0) {
        free(*(void **)((long)__ptr + 0x30));
        *(uint64_t *)((long)__ptr + 0x30) = 0;
      }
      if (*(void **)((long)__ptr + 0x38) != (void *)0x0) {
        free(*(void **)((long)__ptr + 0x38));
      }
      free(__ptr);
      SparseArray_removeAt(puVar1,uVar2);
      lVar3 = lVar3 + -1;
    } while (1 < lVar3);
  }
  return;
}


/* @0013bf9c  size=276 */

int ARBProgram_setEnvParameter
              (uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,
              int param_5,uint32_t param_6)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  uint32_t *puVar4;
  long lVar5;
  int *piVar6;
  long lVar7;
  long lVar8;
  
  iVar1 = pthread_mutex_lock((&glx_context_mutex));
  iVar2 = gettid();
  plVar3 = (long *)(&currentRenderer);
  piVar6 = *(int **)(*plVar3 + 0x5b8);
  iVar1 = *piVar6;
  if (0 < iVar1) {
    lVar7 = 0;
    lVar8 = 8;
    do {
      lVar5 = *(long *)(*(long *)(piVar6 + 2) + lVar8);
      if ((*(int *)(lVar5 + 0xc) == iVar2) && (*(int *)(lVar5 + 4) == param_5)) {
        puVar4 = (uint32_t *)SparseArray_get(lVar5 + 0x10,param_6);
        if (puVar4 == (uint32_t *)0x0) {
          puVar4 = malloc(0x10);
          SparseArray_put(lVar5 + 0x10,param_6,puVar4);
        }
        iVar1 = *piVar6;
        *puVar4 = param_1;
        puVar4[1] = param_2;
        puVar4[2] = param_3;
        puVar4[3] = param_4;
      }
      lVar7 = lVar7 + 1;
      lVar8 = lVar8 + 0x10;
    } while (lVar7 < iVar1);
  }
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @0013c0b0  size=128 */

void ARBProgram_setLocalParameter
               (uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,
               long param_5,uint32_t param_6)

{
  uint32_t *puVar1;
  
  if (param_5 != 0) {
    puVar1 = (uint32_t *)SparseArray_get(param_5 + 0x20);
    if (puVar1 == (uint32_t *)0x0) {
      puVar1 = malloc(0x10);
      SparseArray_put(param_5 + 0x20,param_6,puVar1);
    }
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = param_4;
  }
  return;
}


/* @0013bb18  size=920 */

void ARBProgram_setSource(long param_1,int param_2,char *param_3,uint32_t param_4)

{
  int *piVar1;
  uint32_t uVar2;
  uint8_t bVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  bool bVar7;
  int iVar8;
  bool bVar9;
  int iVar10;
  uint8_t *pbVar11;
  char cVar13;
  char *pcVar14;
  long lVar15;
  char *pcVar16;
  unsigned long uVar17;
  unsigned long uVar18;
  unsigned long uVar19;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t local_a8;
  char *local_a0;
  unsigned long local_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t local_80;
  uint64_t local_78;
  uint64_t uStack_70;
  long local_68;
  uint8_t *pbVar12;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar6 + 0x28);
  if ((param_1 != 0) && (param_2 == 0x8875)) {
    uVar2 = *(uint32_t *)(param_1 + 4);
    lVar15 = 0;
    uStack_b8 = 0;
    local_90 = 0;
    uStack_88 = 0;
    local_98 = (unsigned long)param_4;
    local_b0 = 0;
    local_a8 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_a0 = param_3;
    do {
      piVar1 = &DAT_001167ac + lVar15;
      lVar15 = lVar15 + 1;
      ArrayMap_put(&local_78,(long)&DAT_001167ac + (long)*piVar1,lVar15);
    } while (lVar15 != 0x24);
    local_80 = 0;
    ShaderConverter_getProgramiv(uVar2,0x88b4,(long)&local_80 + 4);
    ShaderConverter_getProgramiv(uVar2,0x88b5,&local_80);
    ArrayBuffer_putString(&uStack_b8,"uniform vec4 gd_ProgramEnv[%d];\n",local_80 & 0xffffffff);
    ArrayBuffer_putString(&uStack_b8,"uniform vec4 gd_ProgramLocal[%d];\n",(*(uint32_t*)((char*)&local_80 + 4)));
    ArrayBuffer_putString(&uStack_b8,"void main() {\n");
    iVar8 = (int)local_98;
    uVar18 = local_98 & 0xffffffff;
    if (0 < (int)local_98) {
      uVar19 = 0;
      bVar7 = false;
      iVar10 = 0;
      pcVar14 = (char *)0x0;
      uVar17 = (unsigned long)((int)local_98 - 1);
      do {
        while (cVar4 = local_a0[uVar19], cVar4 != '\n' && uVar19 != uVar17) {
          uVar19 = uVar19 + 1;
          if (uVar19 == uVar18) goto LAB_0013be34;
        }
        cVar13 = cVar4;
        if (cVar4 == '\n') {
          local_a0[uVar19] = '\0';
          cVar13 = local_a0[uVar19];
        }
        iVar5 = (int)uVar19 - iVar10;
        if (cVar13 != '\0') {
          iVar5 = iVar5 + 1;
        }
        pcVar16 = local_a0 + iVar10;
        if (uVar19 == uVar17) {
          if (iVar5 == 0) break;
          if (cVar13 != '\0') {
            pcVar14 = malloc((long)(iVar5 + 1));
            memcpy(pcVar14,pcVar16,(long)iVar5);
            pcVar14[iVar5] = '\0';
            uVar17 = (unsigned long)(iVar8 - 1);
            pcVar16 = pcVar14;
          }
        }
        pbVar11 = (uint8_t *)(pcVar16 + -1);
        do {
          do {
            pbVar12 = pbVar11;
            pbVar11 = pbVar12 + 1;
            bVar3 = *pbVar11;
          } while (bVar3 == 0x20);
        } while (bVar3 - 9 < 5);
        if ((((bVar3 == 0x21) && (pbVar12[2] == 0x21)) && (pbVar12[3] == 0x41)) &&
           (pbVar12[4] == 0x52)) {
          if ((((pbVar12[5] == 0x42) && (pbVar12[6] == 0x76)) &&
              ((pbVar12[7] == 0x70 && ((pbVar12[8] == 0x31 && (pbVar12[9] == 0x2e)))))) &&
             (pbVar12[10] == 0x30)) goto LAB_0013bdb4;
          if ((((pbVar12[5] != 0x42) || (pbVar12[6] != 0x66)) || (pbVar12[7] != 0x70)) ||
             ((pbVar12[8] != 0x31 || (pbVar12[9] != 0x2e)))) goto LAB_0013bd98;
          bVar9 = pbVar12[10] == 0x30;
          if ((!bVar9) && (bVar7)) goto LAB_0013bda4;
        }
        else {
LAB_0013bd98:
          if (bVar7) {
            if (bVar3 != 0x23) {
LAB_0013bda4:
              FUN_0013c1d4(pbVar11,&local_78,&local_a0,&uStack_b8);
            }
LAB_0013bdb4:
            bVar9 = true;
          }
          else {
            bVar9 = false;
          }
        }
        bVar7 = bVar9;
        if (cVar4 == '\n') {
          local_a0[uVar19] = '\n';
        }
        if (pcVar14 != (char *)0x0) {
          pcVar16 = local_a0 + iVar10;
          iVar10 = memcmp(pcVar16,pcVar14,(long)iVar5);
          if (iVar10 != 0) {
            memcpy(pcVar16,pcVar14,(long)iVar5);
          }
          free(pcVar14);
          uVar17 = (unsigned long)(iVar8 - 1);
        }
        uVar19 = uVar19 + 1;
        iVar10 = (int)uVar19;
      } while (uVar19 != uVar18);
    }
LAB_0013be34:
    ArrayBuffer_putString(&uStack_b8,&DAT_001122d0);
    ArrayBuffer_put(&uStack_b8,0);
    *(uint64_t *)(param_1 + 0x30) = local_a8;
    pcVar14 = strdup(param_3);
    *(char **)(param_1 + 0x38) = pcVar14;
    ArrayMap_free(&local_90,1,0);
  }
  if (*(long *)(lVar6 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


