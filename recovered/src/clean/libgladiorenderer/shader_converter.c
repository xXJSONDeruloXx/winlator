/*
 * shader_converter.c — ARB assembly to GLSL shader converter
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include "gladio_data.h"
#include <ctype.h>

/* Bionic ctype table — accessed as a raw pointer in the decompile */
static const void *_ctype_table = NULL;
#include <GLES3/gl32.h>
#include <EGL/egl.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>

/* @00132824  size=172 */

int ShaderConverter_attachShader(uint32_t param_1,uint32_t param_2)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  lVar3 = SparseArray_get(*(uint64_t *)(*plVar2 + 0x5c0),param_1);
  lVar4 = SparseArray_get(*(uint64_t *)(*plVar2 + 0x5c8),param_2);
  if ((lVar3 != 0) && (lVar4 != 0)) {
    iVar1 = ArrayList_indexOf(lVar3 + 0x18,lVar4);
    if (iVar1 == -1) {
      *(uint8_t *)(lVar4 + 0x78) = 1;
      ArrayList_add(lVar3 + 0x18,lVar4);
    }
  }
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @0013278c  size=152 */

uint32_t ShaderConverter_createProgram(void)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t *puVar3;
  long *plVar4;
  
  iVar1 = pthread_mutex_lock((&glx_context_mutex));
  uVar2 = glCreateProgram();
  puVar3 = calloc(1,0xa0);
  *puVar3 = uVar2;
  *(uint64_t *)(puVar3 + 0xd) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0xb) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x11) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0xf) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x15) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x13) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x19) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x17) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x1d) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x1b) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x21) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x1f) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x25) = 0xffffffffffffffff;
  *(uint64_t *)(puVar3 + 0x23) = 0xffffffffffffffff;
  plVar4 = (long *)(&currentRenderer);
  SparseArray_put(*(uint64_t *)(*plVar4 + 0x5c0),uVar2,puVar3);
  pthread_mutex_unlock((&glx_context_mutex));
  return uVar2;
}


/* @0013230c  size=128 */

uint32_t ShaderConverter_createShader(uint32_t param_1)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  long *plVar3;
  
  pthread_mutex_lock((&glx_context_mutex));
  uVar1 = glCreateShader(param_1);
  puVar2 = calloc(1,0x80);
  *puVar2 = uVar1;
  puVar2[1] = param_1;
  plVar3 = (long *)(&currentRenderer);
  SparseArray_put(*(uint64_t *)(*plVar3 + 0x5c8),uVar1,puVar2);
  pthread_mutex_unlock((&glx_context_mutex));
  return uVar1;
}


/* @00132678  size=276 */

int ShaderConverter_deleteProgram(uint32_t param_1)

{
  int iVar1;
  long *plVar2;
  void *__ptr;
  uint32_t *puVar3;
  int *piVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  __ptr = (void *)SparseArray_get(*(uint64_t *)(*plVar2 + 0x5c0),param_1);
  if (__ptr != (void *)0x0) {
    piVar4 = (int *)((long)__ptr + 0x18);
    iVar1 = *piVar4;
    while (0 < iVar1) {
      puVar3 = (uint32_t *)ArrayList_removeAt(piVar4,0);
      if (*(char *)((long)puVar3 + 0x79) != '\0') {
        glDeleteShader(*puVar3);
        plVar2 = (long *)(&currentRenderer);
        SparseArray_remove(*(uint64_t *)(*plVar2 + 0x5c8),*puVar3);
        FUN_00132480(*plVar2 + 0x398,puVar3);
      }
      iVar1 = *piVar4;
    }
    plVar2 = (long *)(&currentRenderer);
    SparseArray_remove(*(uint64_t *)(*plVar2 + 0x5c0),param_1);
    SparseArray_free((long)__ptr + 8,1);
    free(__ptr);
  }
  glDeleteProgram(param_1);
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @001323e4  size=156 */

int ShaderConverter_deleteShader(uint32_t param_1)

{
  int iVar1;
  long *plVar2;
  uint32_t *puVar3;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  puVar3 = (uint32_t *)SparseArray_get(*(uint64_t *)(*plVar2 + 0x5c8),param_1);
  if (puVar3 != (uint32_t *)0x0) {
    *(uint8_t *)((long)puVar3 + 0x79) = 1;
    if (*(char *)(puVar3 + 0x1e) == '\0') {
      glDeleteShader(*puVar3);
      plVar2 = (long *)(&currentRenderer);
      SparseArray_remove(*(uint64_t *)(*plVar2 + 0x5c8),*puVar3);
      FUN_00132480(*plVar2 + 0x398,puVar3);
    }
  }
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @001328d0  size=208 */

int ShaderConverter_detachShader(uint32_t param_1,uint32_t param_2)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  uint32_t *puVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  lVar3 = SparseArray_get(*(uint64_t *)(*plVar2 + 0x5c0),param_1);
  puVar4 = (uint32_t *)SparseArray_get(*(uint64_t *)(*plVar2 + 0x5c8),param_2);
  if ((lVar3 != 0) && (puVar4 != (uint32_t *)0x0)) {
    *(uint8_t *)(puVar4 + 0x1e) = 0;
    ArrayList_remove(lVar3 + 0x18,puVar4);
    if (*(char *)((long)puVar4 + 0x79) != '\0') {
      glDeleteShader(*puVar4);
      plVar2 = (long *)(&currentRenderer);
      SparseArray_remove(*(uint64_t *)(*plVar2 + 0x5c8),*puVar4);
      FUN_00132480(*plVar2 + 0x398,puVar4);
    }
  }
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @00132614  size=100 */

uint64_t ShaderConverter_getProgram(int param_1)

{
  long *plVar1;
  uint64_t uVar2;
  
  if (param_1 != 0) {
    pthread_mutex_lock((&glx_context_mutex));
    plVar1 = (long *)(&currentRenderer);
    uVar2 = SparseArray_get(*(uint64_t *)(*plVar1 + 0x5c0),param_1);
    pthread_mutex_unlock((&glx_context_mutex));
    return uVar2;
  }
  return 0;
}


/* @00135050  size=272 */

void ShaderConverter_getProgramiv(uint64_t param_1,int param_2,uint32_t *param_3)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  *param_3 = 0;
  if (param_2 < 0x8b80) {
    uVar1 = param_2 - 0x88a1;
    if (uVar1 < 0x15) {
      uVar2 = 1 << (unsigned long)(uVar1 & 0x1f);
      if ((uVar2 & 0x550) != 0) {
        *param_3 = 0x40;
        return;
      }
      if ((uVar2 & 5) != 0) {
        *param_3 = 0x1000;
        return;
      }
      if ((1 << (unsigned long)(uVar1 & 0x1f) & 0x180000U) != 0) {
        uVar3 = 0x60;
        if ((int)param_1 != 0x8620) {
          uVar3 = 0x18;
        }
        *param_3 = uVar3;
        return;
      }
    }
    if ((1 < param_2 - 0x8a35U) && (param_2 != 0x8257)) goto LAB_00135148;
  }
  else if (((10 < param_2 - 0x8b80U) || ((1 << (unsigned long)(param_2 - 0x8b80U & 0x1f) & 0x6fdU) == 0)) &&
          ((0xd < param_2 - 0x8c76U || ((1 << (unsigned long)(param_2 - 0x8c76U & 0x1f) & 0x2201U) == 0))))
  {
LAB_00135148:
    __android_log_print(3,"System.out","gladio:getProgramiv: unimplemented pname %x");
    return;
  }
  glGetProgramiv(param_1,param_2, 0);
  return;
}


/* @0013238c  size=88 */

uint64_t ShaderConverter_getShader(uint32_t param_1)

{
  long *plVar1;
  uint64_t uVar2;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar1 = (long *)(&currentRenderer);
  uVar2 = SparseArray_get(*(uint64_t *)(*plVar1 + 0x5c8),param_1);
  pthread_mutex_unlock((&glx_context_mutex));
  return uVar2;
}


/* @00132290  size=124 */

void ShaderConverter_getShaderSource(long param_1,uint64_t param_2)

{
  size_t sVar1;
  char *__s;
  long lVar2;
  
  if (0 < *(int *)(param_1 + 8)) {
    lVar2 = 0;
    do {
      __s = *(char **)(*(long *)(param_1 + 0x10) + lVar2 * 8);
      sVar1 = strlen(__s);
      ArrayBuffer_putBytes(param_2,__s,sVar1);
      ArrayBuffer_put(param_2,10);
      lVar2 = lVar2 + 1;
    } while (lVar2 < *(int *)(param_1 + 8));
  }
  ArrayBuffer_put(param_2,0);
  return;
}


/* @00134f5c  size=244 */

int ShaderConverter_getShaderiv(uint32_t param_1,int param_2,uint32_t *param_3)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  uint32_t uVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar2 = (long *)(&currentRenderer);
  lVar3 = SparseArray_get(*(uint64_t *)(*plVar2 + 0x5c8),param_1);
  *param_3 = 0;
  if (lVar3 == 0) goto LAB_00135038;
  if (param_2 < 0x8b81) {
    if (param_2 == 0x8b4f) {
      uVar4 = *(uint32_t *)(lVar3 + 4);
    }
    else {
      if (param_2 != 0x8b80) goto LAB_00135000;
      uVar4 = (uint32_t)*(uint8_t *)(lVar3 + 0x79);
    }
  }
  else {
    if (param_2 != 0x8b81) {
      if (param_2 == 0x8b84) {
        glGetShaderiv(param_1,0x8b84,param_3);
        goto LAB_00135038;
      }
LAB_00135000:
      __android_log_print(3,"System.out","gladio:getShaderiv: unimplemented pname %x",param_2);
      goto LAB_00135038;
    }
    uVar4 = (uint32_t)(*(char *)(lVar3 + 0x7a) != '\0');
  }
  *param_3 = uVar4;
LAB_00135038:
  iVar1 = pthread_mutex_unlock((&glx_context_mutex));
  return iVar1;
}


/* @001329a0  size=2712 */

void ShaderConverter_linkProgram(uint32_t param_1)

{
  bool bVar1;
  uint32_t uVar2;
  long lVar3;
  bool bVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  int iVar8;
  long *plVar9;
  uint32_t *puVar10;
  long lVar11;
  uint64_t uVar12;
  void *__ptr;
  size_t sVar13;
  char cVar14;
  long lVar15;
  unsigned long uVar16;
  unsigned long uVar17;
  long lVar18;
  uint64_t *puVar19;
  unsigned long uVar20;
  uint32_t *puVar21;
  uint32_t *puVar22;
  uint64_t *puVar23;
  char *pcVar24;
  long lVar25;
  long lVar26;
  int local_e4;
  uint64_t local_d0;
  uint64_t uStack_c8;
  uint64_t uStack_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t uStack_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  uint64_t uStack_78;
  long local_70;
  
  /* stack canary setup (elided) */
  local_70 = *(long *)(lVar3 + 0x28);
  pthread_mutex_lock((&glx_context_mutex));
  plVar9 = (long *)(&currentRenderer);
  puVar10 = (uint32_t *)SparseArray_get(*(uint64_t *)(*plVar9 + 0x5c0),param_1);
  if (puVar10 != (uint32_t *)0x0) {
    uVar17 = (unsigned long)(uint32_t)puVar10[6];
    if (0 < (int)puVar10[6]) {
      lVar26 = 0;
      do {
        lVar18 = *(long *)(puVar10 + 8);
        puVar22 = *(uint32_t **)(lVar18 + lVar26 * 8);
        cVar14 = *(char *)((long)puVar22 + 0x7a);
        if (cVar14 == '\x01') {
          uVar20 = (unsigned long)(uint32_t)puVar22[10];
          if (0 < (int)puVar22[10]) {
            iVar8 = 0;
            puVar19 = *(uint64_t **)(puVar22 + 0xc);
            do {
              iVar5 = strcmp(*(char **)*puVar19,"main");
              if (iVar5 == 0) {
                iVar8 = iVar8 + 1;
              }
              uVar20 = uVar20 - 1;
              puVar19 = puVar19 + 1;
            } while (uVar20 != 0);
            if (iVar8 != 0) {
              if (0 < (int)uVar17) {
                lVar15 = 0;
                local_e4 = 0;
                do {
                  puVar21 = *(uint32_t **)(lVar18 + lVar15 * 8);
                  if ((puVar21 != puVar22) && (puVar21[1] == puVar22[1])) {
                    uVar2 = puVar21[10];
                    uVar20 = (unsigned long)uVar2;
                    if (0 < (int)uVar2) {
                      iVar8 = 0;
                      puVar19 = *(uint64_t **)(puVar21 + 0xc);
                      do {
                        iVar5 = strcmp(*(char **)*puVar19,"main");
                        if (iVar5 == 0) {
                          iVar8 = iVar8 + 1;
                        }
                        uVar20 = uVar20 - 1;
                        puVar19 = puVar19 + 1;
                      } while (uVar20 != 0);
                      if (iVar8 != 0) goto LAB_00132e94;
                    }
                    if (0 < (int)puVar21[6]) {
                      lVar18 = 0;
                      do {
                        lVar25 = *(long *)(*(long *)(puVar21 + 8) + lVar18 * 0x10 + 8);
                        lVar11 = ArrayMap_get(puVar22 + 6,*(uint64_t *)(lVar25 + 8));
                        iVar8 = local_e4;
                        if (((lVar11 == 0) && (*(int *)(lVar25 + 0x20) == 0)) &&
                           (*(int *)(lVar25 + 0x24) == 0)) {
                          uVar12 = FUN_001376e0(lVar25);
                          ArrayList_addAt(puVar22 + 2,local_e4,uVar12);
                          uVar17 = (unsigned long)(uint32_t)puVar22[10];
                          if (0 < (int)puVar22[10]) {
                            plVar9 = *(long **)(puVar22 + 0xc);
                            do {
                              lVar11 = *plVar9;
                              if (local_e4 <= *(int *)(lVar11 + 0xc)) {
                                *(int *)(lVar11 + 8) = *(int *)(lVar11 + 8) + 1;
                                *(int *)(lVar11 + 0xc) = *(int *)(lVar11 + 0xc) + 1;
                              }
                              uVar17 = uVar17 - 1;
                              plVar9 = plVar9 + 1;
                            } while (uVar17 != 0);
                          }
                          uVar17 = (unsigned long)(uint32_t)puVar22[6];
                          iVar8 = local_e4 + 1;
                          if (0 < (int)puVar22[6]) {
                            plVar9 = (long *)(*(long *)(puVar22 + 8) + 8);
                            do {
                              iVar5 = *(int *)(*plVar9 + 0x40);
                              if (local_e4 <= iVar5) {
                                *(int *)(*plVar9 + 0x40) = iVar5 + 1;
                              }
                              uVar17 = uVar17 - 1;
                              plVar9 = plVar9 + 2;
                            } while (uVar17 != 0);
                          }
                        }
                        local_e4 = iVar8;
                        lVar18 = lVar18 + 1;
                      } while (lVar18 < (int)puVar21[6]);
                      uVar2 = puVar21[10];
                    }
                    if (0 < (int)uVar2) {
                      uVar17 = (unsigned long)(uint32_t)puVar22[10];
                      lVar18 = 0;
                      do {
                        if (0 < (int)uVar17) {
                          lVar11 = *(long *)(puVar22 + 0xc);
                          uVar20 = 0;
                          puVar19 = *(uint64_t **)(*(long *)(puVar21 + 0xc) + lVar18 * 8);
                          pcVar24 = (char *)*puVar19;
                          do {
                            puVar23 = *(uint64_t **)(lVar11 + uVar20 * 8);
                            iVar8 = strcmp((char *)*puVar23,pcVar24);
                            if (iVar8 == 0) {
                              uVar2 = *(uint32_t *)(puVar23 + 3);
                              if (uVar2 == *(uint32_t *)(puVar19 + 3)) {
                                if (0 < (int)uVar2) {
                                  uVar16 = 0;
                                  do {
                                    iVar8 = *(int *)(puVar23[4] + uVar16 * 4);
                                    iVar5 = *(int *)(puVar19[4] + uVar16 * 4);
                                    uVar16 = uVar16 + 1;
                                    if (uVar2 <= uVar16) break;
                                  } while (iVar8 == iVar5);
                                  if (iVar8 != iVar5) goto LAB_00132c88;
                                  if (puVar23 == (uint64_t *)0x0) break;
                                }
                                if ((*(char *)(puVar23 + 2) == '\0') &&
                                   (*(char *)(puVar19 + 2) != '\0')) {
                                  iVar8 = *(int *)(puVar23 + 1);
                                  __ptr = (void *)ArrayList_removeAt(puVar22 + 2,iVar8);
                                  if (__ptr != (void *)0x0) {
                                    free(__ptr);
                                  }
                                  uVar17 = (unsigned long)(uint32_t)puVar22[10];
                                  if (0 < (int)puVar22[10]) {
                                    plVar9 = *(long **)(puVar22 + 0xc);
                                    uVar20 = uVar17;
                                    do {
                                      lVar11 = *plVar9;
                                      if (iVar8 <= *(int *)(lVar11 + 8)) {
                                        *(int *)(lVar11 + 8) = *(int *)(lVar11 + 8) + -1;
                                        *(int *)(lVar11 + 0xc) = *(int *)(lVar11 + 0xc) + -1;
                                      }
                                      uVar20 = uVar20 - 1;
                                      plVar9 = plVar9 + 1;
                                    } while (uVar20 != 0);
                                  }
                                  uVar20 = (unsigned long)(uint32_t)puVar22[6];
                                  if (0 < (int)puVar22[6]) {
                                    plVar9 = (long *)(*(long *)(puVar22 + 8) + 8);
                                    do {
                                      iVar5 = *(int *)(*plVar9 + 0x40);
                                      if (iVar8 <= iVar5) {
                                        *(int *)(*plVar9 + 0x40) = iVar5 + -1;
                                      }
                                      uVar20 = uVar20 - 1;
                                      plVar9 = plVar9 + 2;
                                    } while (uVar20 != 0);
                                  }
                                  lVar11 = (long)*(int *)(puVar19 + 1);
                                  if (*(int *)(puVar19 + 1) <= *(int *)((long)puVar19 + 0xc)) {
                                    do {
                                      pcVar24 = strdup(*(char **)(*(long *)(puVar21 + 4) +
                                                                 lVar11 * 8));
                                      ArrayList_addAt(puVar22 + 2,iVar8,pcVar24);
                                      uVar17 = (unsigned long)(uint32_t)puVar22[10];
                                      if (0 < (int)puVar22[10]) {
                                        plVar9 = *(long **)(puVar22 + 0xc);
                                        uVar20 = uVar17;
                                        do {
                                          lVar25 = *plVar9;
                                          if (iVar8 <= *(int *)(lVar25 + 0xc)) {
                                            *(int *)(lVar25 + 8) = *(int *)(lVar25 + 8) + 1;
                                            *(int *)(lVar25 + 0xc) = *(int *)(lVar25 + 0xc) + 1;
                                          }
                                          uVar20 = uVar20 - 1;
                                          plVar9 = plVar9 + 1;
                                        } while (uVar20 != 0);
                                      }
                                      uVar20 = (unsigned long)(uint32_t)puVar22[6];
                                      if (0 < (int)puVar22[6]) {
                                        plVar9 = (long *)(*(long *)(puVar22 + 8) + 8);
                                        do {
                                          iVar5 = *(int *)(*plVar9 + 0x40);
                                          if (iVar8 <= iVar5) {
                                            *(int *)(*plVar9 + 0x40) = iVar5 + 1;
                                          }
                                          uVar20 = uVar20 - 1;
                                          plVar9 = plVar9 + 2;
                                        } while (uVar20 != 0);
                                      }
                                      iVar8 = iVar8 + 1;
                                      bVar1 = lVar11 < *(int *)((long)puVar19 + 0xc);
                                      lVar11 = lVar11 + 1;
                                    } while (bVar1);
                                  }
                                }
                                break;
                              }
                            }
LAB_00132c88:
                            uVar20 = uVar20 + 1;
                          } while (uVar20 != uVar17);
                        }
                        lVar18 = lVar18 + 1;
                      } while (lVar18 < (int)puVar21[10]);
                    }
                    puVar22[0x1b] = puVar22[0x1b] | puVar21[0x1b];
                    uVar17 = (unsigned long)(uint32_t)puVar10[6];
                  }
LAB_00132e94:
                  lVar15 = lVar15 + 1;
                  if ((int)uVar17 <= lVar15) break;
                  lVar18 = *(long *)(puVar10 + 8);
                } while( true );
              }
              FUN_00133438(puVar10,puVar22);
              uStack_a8 = 0;
              uStack_a0 = 0;
              local_b0 = 0;
              if (0 < (int)puVar22[2]) {
                lVar18 = 0;
                do {
                  pcVar24 = *(char **)(*(long *)(puVar22 + 4) + lVar18 * 8);
                  sVar13 = strlen(pcVar24);
                  ArrayBuffer_putBytes(&local_b0,pcVar24,sVar13);
                  ArrayBuffer_put(&local_b0,10);
                  lVar18 = lVar18 + 1;
                } while (lVar18 < (int)puVar22[2]);
              }
              ArrayBuffer_put(&local_b0,0);
              glShaderSource(*puVar22,1,&uStack_a0,0);
              glCompileShader(*puVar22);
              ArrayBuffer_free(&local_b0);
              glGetShaderiv(*puVar22,0x8b81,&local_d0);
              cVar14 = ((int)local_d0 != 0) << 1;
              *(char *)((long)puVar22 + 0x7a) = ((int)local_d0 != 0) << 1;
              goto LAB_00132f5c;
            }
          }
        }
        else {
LAB_00132f5c:
          if (cVar14 == '\x02') {
            glAttachShader(param_1,*puVar22);
          }
        }
        uVar17 = (unsigned long)(int)puVar10[6];
        lVar26 = lVar26 + 1;
      } while (lVar26 < (long)uVar17);
    }
    glLinkProgram(*puVar10);
    uVar17 = (unsigned long)(uint32_t)puVar10[6];
    if ((int)puVar10[6] < 1) {
      bVar1 = false;
    }
    else {
      plVar9 = *(long **)(puVar10 + 8);
      bVar4 = false;
      bVar1 = false;
      do {
        uVar2 = *(uint32_t *)(*plVar9 + 0x6c);
        if (((uVar2 & 0x1d) != 0) && (bVar4 = true, (uVar2 & 1) != 0)) {
          *(uint8_t *)((long)puVar10 + 0x29) = 1;
        }
        uVar17 = uVar17 - 1;
        bVar1 = (bool)((uVar2 & 0x403c0) != 0 | bVar1);
        plVar9 = plVar9 + 1;
      } while (uVar17 != 0);
      if (bVar4) {
        uVar6 = glGetAttribLocation(*puVar10,"gd_Vertex");
        puVar10[0xb] = uVar6;
        uVar6 = glGetAttribLocation(*puVar10,"gd_Color");
        puVar10[0xc] = uVar6;
        uVar6 = glGetAttribLocation(*puVar10,"gd_Normal");
        puVar10[0xd] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",0);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0xe] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",1);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0xf] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",2);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0x10] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",3);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0x11] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",4);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0x12] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",5);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0x13] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",6);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0x14] = uVar6;
        FUN_001369dc(&local_b0,0x20,"gd_MultiTexCoord%d",7);
        uVar6 = glGetAttribLocation(*puVar10,&local_b0);
        puVar10[0x15] = uVar6;
      }
    }
    uVar6 = glGetUniformLocation(*puVar10,"gd_AlphaTest");
    puVar10[0x16] = uVar6;
    if (bVar1) {
      uVar6 = glGetUniformLocation(*puVar10,"gd_ModelViewMatrix");
      puVar10[0x18] = uVar6;
      uVar6 = glGetUniformLocation(*puVar10,"gd_ProjectionMatrix");
      puVar10[0x17] = uVar6;
      uVar6 = glGetUniformLocation(*puVar10,"gd_ModelViewProjectionMatrix");
      puVar10[0x19] = uVar6;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",0);
      uVar6 = glGetUniformLocation(*puVar10,&local_d0);
      puVar10[0x1a] = uVar6;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",1);
      uVar6 = glGetUniformLocation(*puVar10,&local_d0);
      puVar10[0x1b] = uVar6;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",2);
      uVar6 = glGetUniformLocation(*puVar10,&local_d0);
      puVar10[0x1c] = uVar6;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",3);
      uVar6 = glGetUniformLocation(*puVar10,&local_d0);
      puVar10[0x1d] = uVar6;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",4);
      uVar6 = glGetUniformLocation(*puVar10,&local_d0);
      puVar10[0x1e] = uVar6;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",5);
      uVar6 = glGetUniformLocation(*puVar10,&local_d0);
      puVar10[0x1f] = uVar6;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",6);
      uVar6 = glGetUniformLocation(*puVar10,&local_d0);
      puVar10[0x20] = uVar6;
      FUN_001369dc(&local_d0,0x20,"gd_TextureMatrix[%d]",7);
      uVar7 = glGetUniformLocation(*puVar10,&local_d0);
      uVar6 = *puVar10;
      puVar10[0x21] = uVar7;
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      local_b0 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      FUN_001369dc(&local_b0,0x40,"gd_Fog.%s","color");
      uVar7 = glGetUniformLocation(uVar6,&local_b0);
      puVar10[0x22] = uVar7;
      FUN_001369dc(&local_b0,0x40,"gd_Fog.%s","density");
      uVar7 = glGetUniformLocation(uVar6,&local_b0);
      puVar10[0x23] = uVar7;
      FUN_001369dc(&local_b0,0x40,"gd_Fog.%s","start");
      uVar7 = glGetUniformLocation(uVar6,&local_b0);
      puVar10[0x24] = uVar7;
      FUN_001369dc(&local_b0,0x40,"gd_Fog.%s",&DAT_001152c2);
      uVar7 = glGetUniformLocation(uVar6,&local_b0);
      puVar10[0x25] = uVar7;
      FUN_001369dc(&local_b0,0x40,"gd_Fog.%s","scale");
      uVar6 = glGetUniformLocation(uVar6,&local_b0);
      puVar10[0x26] = uVar6;
    }
    uVar17 = 0;
    do {
      if (*(int *)((long)puVar10 + uVar17 + 0x2c) != -1) {
        *(uint8_t *)(puVar10 + 10) = 1;
        break;
      }
      uVar17 = (unsigned long)((int)uVar17 + 4);
    } while (uVar17 < 0x70);
  }
  iVar8 = pthread_mutex_unlock((&glx_context_mutex));
  if (*(long *)(lVar3 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar8);
  }
  return;
}


/* @00135668  size=244 */

void ShaderConverter_onDestroy(long param_1)

{
  bool bVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  void *__ptr;
  unsigned long uVar4;
  
  uVar3 = **(uint32_t **)(param_1 + 0x230);
  if (0 < (int)uVar3) {
    FUN_00132480(param_1,*(uint64_t *)
                          (*(long *)(*(uint32_t **)(param_1 + 0x230) + 2) + (unsigned long)(uVar3 - 1) * 0x10 +
                          8));
    SparseArray_removeAt(*(uint64_t *)(param_1 + 0x230),uVar3 - 1);
    uVar4 = (unsigned long)uVar3;
    if (uVar3 != 1) {
      do {
        FUN_00132480(param_1,*(uint64_t *)
                              (*(long *)(*(long *)(param_1 + 0x230) + 8) +
                               (uVar4 - 2 & 0xffffffff) * 0x10 + 8));
        SparseArray_removeAt(*(uint64_t *)(param_1 + 0x230),uVar4 - 2 & 0xffffffff);
        bVar1 = 2 < (long)uVar4;
        uVar4 = uVar4 - 1;
      } while (bVar1);
    }
  }
  puVar2 = *(uint32_t **)(param_1 + 0x228);
  uVar3 = *puVar2;
  uVar4 = (unsigned long)uVar3;
  if (0 < (int)uVar3) {
    while( true ) {
      uVar3 = uVar3 - 1;
      __ptr = *(void **)(*(long *)(puVar2 + 2) + (unsigned long)uVar3 * 0x10 + 8);
      if (__ptr != (void *)0x0) {
        SparseArray_free((long)__ptr + 8,1);
        free(__ptr);
        puVar2 = *(uint32_t **)(param_1 + 0x228);
      }
      SparseArray_removeAt(puVar2,uVar3);
      if ((long)uVar4 < 2) break;
      puVar2 = *(uint32_t **)(param_1 + 0x228);
      uVar4 = uVar4 - 1;
    }
  }
  return;
}


/* @0013099c  size=6388 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ShaderConverter_setShaderSource(uint32_t param_1,int param_2,uint64_t param_3)

{
  void *__src;
  uint32_t uVar1;
  uint8_t bVar2;
  char cVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  long *plVar14;
  long lVar15;
  long lVar16;
  uint8_t *pbVar17;
  void *__dest;
  uint32_t *puVar18;
  uint8_t *pbVar19;
  long lVar20;
  char *pcVar21;
  char *pcVar22;
  uint64_t uVar23;
  uint32_t uVar24;
  uint8_t *pbVar25;
  unsigned long uVar26;
  long lVar27;
  uint8_t *pbVar28;
  unsigned long uVar29;
  uint8_t *pbVar30;
  long lVar31;
  unsigned long uVar32;
  unsigned long uVar33;
  void *pvVar34;
  char cVar35;
  char cVar36;
  int iVar37;
  uint64_t *puVar38;
  void *pvVar39;
  char *pcVar40;
  int *piVar41;
  size_t sVar42;
  uint64_t uVar43;
  uint64_t uVar44;
  uint64_t uVar45;
  uint64_t uVar46;
  uint64_t uVar47;
  void *local_c0;
  long local_b8;
  unsigned long local_b0;
  long local_a8;
  long local_70;
  
  /* stack canary setup (elided) */
  local_70 = *(long *)(lVar27 + 0x28);
  pthread_mutex_lock((&glx_context_mutex));
  plVar14 = (long *)(&currentRenderer);
  lVar15 = SparseArray_get(*(uint64_t *)(*plVar14 + 0x5c8),param_1);
  if (lVar15 == 0) {
    iVar13 = pthread_mutex_unlock((&glx_context_mutex));
    lVar27 = *(long *)(lVar27 + 0x28);
  }
  else {
    if (0 < param_2) {
      iVar13 = 0;
      do {
        uVar8 = ArrayBuffer_getInt(param_3);
        uVar33 = (unsigned long)uVar8;
        lVar16 = ArrayBuffer_getBytes(param_3,uVar33);
        if (0 < (int)uVar8) {
          uVar32 = 0;
          iVar12 = 0;
          pvVar39 = (void *)0x0;
          do {
            while ((cVar3 = *(char *)(lVar16 + uVar32), cVar3 != '\n' && (uVar32 != uVar8 - 1))) {
              uVar32 = uVar32 + 1;
              if (uVar32 == uVar33) goto LAB_00130a28;
            }
            cVar35 = cVar3;
            if (cVar3 == '\n') {
              cVar35 = '\0';
              *(uint8_t *)(lVar16 + uVar32) = 0;
            }
            iVar4 = (int)uVar32 - iVar12;
            if (cVar35 != '\0') {
              iVar4 = iVar4 + 1;
            }
            __src = (void *)(lVar16 + iVar12);
            pvVar34 = __src;
            if (uVar32 == uVar8 - 1) {
              if (iVar4 == 0) break;
              if (cVar35 != '\0') {
                pvVar39 = malloc((long)(iVar4 + 1));
                memcpy(pvVar39,__src,(long)iVar4);
                *(uint8_t *)((long)pvVar39 + (long)iVar4) = 0;
                pvVar34 = pvVar39;
              }
            }
            pbVar17 = (uint8_t *)((long)pvVar34 + -1);
            do {
              do {
                pbVar17 = pbVar17 + 1;
              } while (*pbVar17 == 0x20);
            } while (*pbVar17 - 9 < 5);
            pbVar17 = (uint8_t *)strdup((char *)pbVar17);
            bVar2 = *pbVar17;
            iVar12 = (int)pbVar17;
            if (bVar2 == 0x2f) {
              bVar7 = pbVar17[1] == 0x2f;
LAB_00130dc0:
              bVar2 = *pbVar17;
              lVar20 = _ctype_table;
            }
            else {
              if (bVar2 == 0x23) {
                pbVar28 = pbVar17 + 3;
                pbVar19 = pbVar17 + 3;
                do {
                  do {
                    pbVar30 = pbVar19;
                    bVar2 = pbVar30[-2];
                    pbVar19 = pbVar30 + 1;
                  } while (bVar2 == 0x20);
                } while (bVar2 - 9 < 5);
                if (((((bVar2 == 0x76) && (pbVar30[-1] == 0x65)) && (*pbVar30 == 0x72)) &&
                    ((*pbVar19 == 0x73 && (pbVar30[2] == 0x69)))) &&
                   ((pbVar30[3] == 0x6f && ((pbVar30[4] == 0x6e && (pbVar30[5] == 0x20)))))) {
                  local_b0 = local_b0 & 0xffffffffffffff00;
                  if (pbVar17 != (uint8_t *)0x0) {
                    iVar10 = 0;
                    pbVar28 = pbVar17;
                    do {
                      pbVar28 = pbVar28 + 1;
                      bVar2 = *pbVar28;
                      if (bVar2 - 0x30 < 10) {
                        *(uint8_t *)((long)&local_b0 + (long)iVar10) = bVar2;
                        iVar10 = iVar10 + 1;
                      }
                    } while (bVar2 != 0);
                    *(uint8_t *)((long)&local_b0 + (long)iVar10) = 0;
                    if (0 < iVar10) {
                      lVar20 = strtol((char *)&local_b0,(char **)0x0,10);
                      *(short *)(lVar15 + 0x70) = (short)lVar20;
                      goto LAB_00130db4;
                    }
                  }
                  *(uint16_t *)(lVar15 + 0x70) = 0;
                }
                else {
                  pbVar19 = pbVar17 + 4;
                  do {
                    do {
                      pbVar30 = pbVar19;
                      bVar2 = pbVar30[-3];
                      pbVar19 = pbVar30 + 1;
                    } while (bVar2 == 0x20);
                  } while (bVar2 - 9 < 5);
                  if (((((bVar2 == 0x65) && (pbVar30[-2] == 0x78)) && (pbVar30[-1] == 0x74)) &&
                      (((*pbVar30 == 0x65 && (*pbVar19 == 0x6e)) &&
                       ((pbVar30[2] == 0x73 && ((pbVar30[3] == 0x69 && (pbVar30[4] == 0x6f))))))))
                     && ((pbVar30[5] == 0x6e && (pbVar30[6] == 0x20)))) {
                    pcVar21 = strstr((char *)pbVar17,"GL_ARB_shader_texture_lod");
                    if (pcVar21 != (char *)0x0) {
                      FUN_001369dc(&local_b0,0x40,"#define GD_%s 1","ARB_shader_texture_lod");
                      pcVar21 = strdup((char *)&local_b0);
                      ArrayList_add(lVar15 + 8,pcVar21);
                      *(uint32_t *)(lVar15 + 0x6c) = *(uint32_t *)(lVar15 + 0x6c) | 0x80000;
                    }
                  }
                  else {
                    do {
                      do {
                        pbVar19 = pbVar28;
                        bVar2 = pbVar19[-2];
                        pbVar28 = pbVar19 + 1;
                      } while (bVar2 == 0x20);
                    } while (bVar2 - 9 < 5);
                    if ((((bVar2 != 0x70) || (pbVar19[-1] != 0x72)) || (*pbVar19 != 0x61)) ||
                       (((*pbVar28 != 0x67 || (pbVar19[2] != 0x6d)) ||
                        ((pbVar19[3] != 0x61 || (pbVar19[4] != 0x20)))))) {
                      pbVar28 = pbVar17 + 2;
                      do {
                        do {
                          pbVar19 = pbVar28;
                          bVar2 = pbVar19[-1];
                          pbVar28 = pbVar19 + 1;
                        } while (bVar2 == 0x20);
                      } while (bVar2 - 9 < 5);
                      if (((bVar2 != 0x6c) || (*pbVar19 != 0x69)) ||
                         ((*pbVar28 != 0x6e || ((pbVar19[2] != 0x65 || (pbVar19[3] != 0x20)))))) {
                        bVar7 = false;
                        goto LAB_00130dc0;
                      }
                    }
                  }
                }
LAB_00130db4:
                bVar7 = true;
                goto LAB_00130dc0;
              }
              bVar7 = false;
              lVar20 = _ctype_table;
            }
            _ctype_table = lVar20;
            if (bVar2 == 0x23) {
              pbVar28 = pbVar17 + 2;
              do {
                do {
                  pbVar19 = pbVar28;
                  bVar2 = pbVar19[-1];
                  pbVar28 = pbVar19 + 1;
                } while (bVar2 == 0x20);
              } while (bVar2 - 9 < 5);
              if (((((bVar2 == 100) && (*pbVar19 == 0x65)) && (*pbVar28 == 0x66)) &&
                  ((pbVar19[2] == 0x69 && (pbVar19[3] == 0x6e)))) && (pbVar19[4] == 0x65)) {
                pvVar34 = (void *)0x0;
                pbVar28 = pbVar17 + 7;
                iVar10 = -1;
LAB_00130e44:
                do {
                  lVar31 = (long)pbVar28 << 0x20;
                  iVar11 = (int)pbVar28 - iVar12;
                  iVar37 = iVar10;
                  pbVar19 = pbVar28;
                  while( true ) {
                    pbVar28 = pbVar19 + 1;
                    bVar2 = *pbVar19;
                    uVar29 = (unsigned long)bVar2;
                    if ((((*(uint8_t *)(uVar29 + lVar20 + 1) & 7) != 0) || (bVar2 == 0x5f)) ||
                       (bVar2 == 0x2e)) break;
                    if (iVar37 == -1) {
LAB_00130f08:
                      iVar10 = -1;
                      if ((int)uVar29 != 0) goto LAB_00130e44;
                      goto LAB_00130f10;
                    }
                    if (pvVar34 != (void *)0x0) {
                      lVar31 = lVar31 - ((unsigned long)(uint32_t)(iVar37 + iVar12) << 0x20);
                      __dest = malloc(lVar31 + 0x100000000 >> 0x20);
                      sVar42 = lVar31 >> 0x20;
                      memcpy(__dest,pbVar17 + iVar37,sVar42);
                      *(uint8_t *)((long)__dest + sVar42) = 0;
                      ArrayMap_put(lVar15 + 0x38,pvVar34,__dest);
                      goto joined_r0x00130fa8;
                    }
                    if (bVar2 == 0x28) goto joined_r0x00130fa8;
                    if (bVar2 == 0x20) {
                      lVar31 = lVar31 - ((unsigned long)(uint32_t)(iVar37 + iVar12) << 0x20);
                      pvVar34 = malloc(lVar31 + 0x100000000 >> 0x20);
                      sVar42 = lVar31 >> 0x20;
                      memcpy(pvVar34,pbVar17 + iVar37,sVar42);
                      *(uint8_t *)((long)pvVar34 + sVar42) = 0;
                      uVar29 = (unsigned long)*pbVar19;
                      goto LAB_00130f08;
                    }
                    pvVar34 = (void *)0x0;
                    lVar31 = lVar31 + 0x100000000;
                    iVar11 = iVar11 + 1;
                    iVar37 = -1;
                    pbVar19 = pbVar28;
                    if (bVar2 == 0) goto joined_r0x00130fa8;
                  }
                  iVar10 = iVar11;
                  if (iVar37 != -1) {
                    iVar10 = iVar37;
                  }
                } while (bVar2 != 0);
LAB_00130f10:
                if (pvVar34 != (void *)0x0) {
                  free(pvVar34);
                }
              }
            }
joined_r0x00130fa8:
            if (bVar7) {
              free(pbVar17);
            }
            else {
              bVar7 = false;
              cVar35 = '\0';
              iVar10 = -1;
              iVar11 = 0;
              local_b8 = 0xffffffff;
              pbVar28 = pbVar17;
LAB_00130fcc:
              do {
                if (*pbVar28 == 0x7d) {
                  iVar37 = *(int *)(lVar15 + 0x48);
                  if (iVar37 < 1) goto LAB_00131098;
                  lVar20 = *(long *)(lVar15 + 0x60);
                  if ((lVar20 == 0) || (*(char *)(lVar20 + 0x2d) != '\0')) {
                    uVar29 = (unsigned long)*(uint32_t *)(lVar15 + 0x18);
                    if (0 < (int)*(uint32_t *)(lVar15 + 0x18)) {
                      plVar14 = (long *)(*(long *)(lVar15 + 0x20) + 8);
                      do {
                        if (*(int *)(*plVar14 + 0x20) == iVar37) {
                          *(uint8_t *)(*plVar14 + 0x2d) = 1;
                        }
                        uVar29 = uVar29 - 1;
                        plVar14 = plVar14 + 2;
                      } while (uVar29 != 0);
                    }
                  }
                  else {
                    *(long *)(lVar15 + 0x58) = lVar20;
                    *(uint64_t *)(lVar15 + 0x60) = 0;
                  }
                  lVar20 = *(long *)(lVar15 + 0x50);
                  *(int *)(lVar15 + 0x48) = iVar37 + -1;
                  if ((lVar20 == 0) || (iVar37 + -1 != 0)) goto LAB_0013109c;
                  if (*(char *)(lVar20 + 0x10) == '\0') goto LAB_00131098;
LAB_00131100:
                  *(uint32_t *)(lVar20 + 0xc) = *(uint32_t *)(lVar15 + 8);
                  ArrayList_add(lVar15 + 0x28);
                  *(uint64_t *)(lVar15 + 0x50) = 0;
LAB_00131118:
                  uVar24 = (uint32_t)*pbVar28;
                }
                else {
                  if (*pbVar28 == 0x7b) {
                    if (*(long *)(lVar15 + 0x60) != 0) {
                      cVar35 = '\0';
                      *(uint8_t *)(*(long *)(lVar15 + 0x60) + 0x2d) = 0;
                      local_b8 = 0xffffffff;
                    }
                    iVar37 = *(int *)(lVar15 + 0x48);
                    lVar20 = *(long *)(lVar15 + 0x50);
                    *(int *)(lVar15 + 0x48) = iVar37 + 1;
                    if (lVar20 != 0) {
                      if ((*(char *)(lVar20 + 0x10) == '\0') && (iVar37 == 0)) {
                        *(uint8_t *)(lVar20 + 0x10) = 1;
                      }
                      goto LAB_00131098;
                    }
                    goto LAB_00131118;
                  }
LAB_00131098:
                  lVar20 = *(long *)(lVar15 + 0x50);
LAB_0013109c:
                  if (lVar20 == 0) goto LAB_00131118;
                  bVar2 = *pbVar28;
                  uVar24 = (uint32_t)bVar2;
                  if (bVar2 == 0x3b) {
                    if (*(int *)(lVar15 + 0x68) != 0) {
                      uVar24 = 0x3b;
                      goto LAB_0013111c;
                    }
                    if (*(char *)(lVar20 + 0x10) == '\0') goto LAB_00131100;
                    goto LAB_00131118;
                  }
                  if (bVar2 == 0x29) {
                    if (0 < *(int *)(lVar15 + 0x68)) {
                      *(int *)(lVar15 + 0x68) = *(int *)(lVar15 + 0x68) + -1;
                      goto LAB_00131118;
                    }
                    uVar24 = 0x29;
                  }
                  else if (bVar2 == 0x28) {
                    *(int *)(lVar15 + 0x68) = *(int *)(lVar15 + 0x68) + 1;
                    goto LAB_00131118;
                  }
                }
LAB_0013111c:
                piVar41 = *(int **)(lVar15 + 0x58);
                iVar37 = (int)pbVar28;
                if (piVar41 != (int *)0x0) {
                  if (uVar24 == 0x2c) {
                    if (bVar7) {
                      bVar7 = true;
joined_r0x001311b0:
                      if (iVar10 == -1) {
                        iVar10 = -1;
                      }
                      else {
                        puVar38 = malloc(0x48);
                        if (puVar38 != (uint64_t *)0x0) {
                          uVar23 = *(uint64_t *)piVar41;
                          puVar38[1] = *(uint64_t *)(piVar41 + 2);
                          *puVar38 = uVar23;
                          uVar45 = *(uint64_t *)(piVar41 + 10);
                          uVar44 = *(uint64_t *)(piVar41 + 8);
                          uVar43 = *(uint64_t *)(piVar41 + 0xe);
                          uVar23 = *(uint64_t *)(piVar41 + 0xc);
                          uVar47 = *(uint64_t *)(piVar41 + 6);
                          uVar46 = *(uint64_t *)(piVar41 + 4);
                          puVar38[8] = *(uint64_t *)(piVar41 + 0x10);
                          puVar38[5] = uVar45;
                          puVar38[4] = uVar44;
                          puVar38[7] = uVar43;
                          puVar38[6] = uVar23;
                          puVar38[3] = uVar47;
                          puVar38[2] = uVar46;
                        }
                        sVar42 = (long)(iVar37 - iVar12) - (long)iVar10;
                        pvVar34 = malloc((long)((int)sVar42 + 1));
                        memcpy(pvVar34,pbVar17 + iVar10,sVar42);
                        *(uint8_t *)((long)pvVar34 + sVar42) = 0;
                        puVar38[1] = pvVar34;
                        puVar38[6] = 0;
                        *(uint64_t **)(*(long *)(lVar15 + 0x58) + 0x30) = puVar38;
                        *(uint64_t **)(lVar15 + 0x58) = puVar38;
                        ArrayMap_put(lVar15 + 0x18,pvVar34,puVar38);
                        iVar10 = -1;
                      }
                      goto LAB_00131310;
                    }
                    bVar7 = false;
                    uVar24 = 0x2c;
                  }
                  else if (uVar24 == 0x3d) {
                    bVar7 = false;
                  }
                  else {
                    if (uVar24 == 0x3b) {
                      if (*piVar41 == 0xff02) {
                        pcVar21 = *(char **)(piVar41 + 2);
                        if ((pcVar21 == (char *)0x0) && (iVar10 != -1)) {
                          sVar42 = (long)(iVar37 - iVar12) - (long)iVar10;
                          pcVar21 = malloc((long)((int)sVar42 + 1));
                          memcpy(pcVar21,pbVar17 + iVar10,sVar42);
                          pcVar21[sVar42] = '\0';
                          piVar41 = *(int **)(lVar15 + 0x58);
                          *(char **)(piVar41 + 2) = pcVar21;
                        }
                        else if (pcVar21 == (char *)0x0) {
                          pcVar21 = strdup(*(char **)(piVar41 + 4));
                          *(char **)(piVar41 + 2) = pcVar21;
                        }
                        ArrayMap_put(lVar15 + 0x18,pcVar21,piVar41);
                        *(uint64_t *)(lVar15 + 0x58) = 0;
                      }
                      else {
                        if (bVar7) {
                          bVar7 = false;
                          goto joined_r0x001311b0;
                        }
                        bVar7 = false;
                        *(uint64_t *)(lVar15 + 0x58) = 0;
                      }
                    }
                    else if ((*piVar41 == 0xff02) && (uVar24 == 0x5b)) {
                      if ((*(long *)(piVar41 + 2) == 0) && (iVar10 != -1)) {
                        sVar42 = (long)(iVar37 - iVar12) - (long)iVar10;
                        pvVar34 = malloc((long)((int)sVar42 + 1));
                        memcpy(pvVar34,pbVar17 + iVar10,sVar42);
                        *(uint8_t *)((long)pvVar34 + sVar42) = 0;
                        *(void **)(*(long *)(lVar15 + 0x58) + 8) = pvVar34;
                      }
                      iVar9 = FUN_00136a80(pbVar28);
                      if (0 < iVar9) {
                        *(int *)(*(long *)(lVar15 + 0x58) + 0x28) = iVar9;
                      }
                    }
LAB_00131310:
                    uVar24 = (uint32_t)*pbVar28;
                    if (uVar24 != 0x3b) goto LAB_00131320;
                  }
                  *(uint64_t *)(lVar15 + 0x58) = 0;
                }
LAB_00131320:
                if ((((*(uint8_t *)(_ctype_table + (unsigned long)uVar24 + 1) & 7) == 0) && (uVar24 != 0x5f)) &&
                   (uVar24 != 0x23)) {
                  if (iVar10 == -1) {
                    iVar10 = -1;
                  }
                  else {
                    lVar20 = (long)iVar10;
                    pbVar19 = pbVar17 + lVar20;
                    if (*pbVar19 == 0x23) {
                      pbVar30 = pbVar17 + lVar20 + 2;
                      do {
                        do {
                          pbVar25 = pbVar30;
                          bVar2 = pbVar25[-1];
                          pbVar30 = pbVar25 + 1;
                        } while (bVar2 == 0x20);
                      } while (bVar2 - 9 < 5);
                      if ((((bVar2 == 100) && (*pbVar25 == 0x65)) &&
                          ((*pbVar30 == 0x66 && ((pbVar25[2] == 0x69 && (pbVar25[3] == 0x6e)))))) &&
                         (pbVar25[4] == 0x65)) break;
                    }
                    pvVar34 = *(void **)(lVar15 + 0x60);
                    if ((pvVar34 != (void *)0x0) && (*(char *)((long)pvVar34 + 0x2d) != '\0')) {
                      if (*(void **)((long)pvVar34 + 0x10) != (void *)0x0) {
                        free(*(void **)((long)pvVar34 + 0x10));
                        pvVar34 = *(void **)(lVar15 + 0x60);
                        *(uint64_t *)((long)pvVar34 + 0x10) = 0;
                      }
                      free(pvVar34);
                      *(uint64_t *)(lVar15 + 0x60) = 0;
                    }
                    iVar37 = iVar37 - iVar12;
                    if (iVar11 == 0) {
                      if ((((*pbVar19 == 0x6c) && (pbVar19[1] == 0x61)) && (pbVar19[2] == 0x79)) &&
                         (((pbVar19[3] == 0x6f && (pbVar19[4] == 0x75)) &&
                          (pbVar30 = pbVar28, pbVar19[5] == 0x74)))) {
                        do {
                          do {
                            pbVar25 = pbVar30 + 1;
                            bVar2 = *pbVar30;
                            pbVar30 = pbVar25;
                          } while (bVar2 == 0x20);
                        } while (bVar2 - 9 < 5);
                        if (bVar2 == 0x28) {
                          local_b0 = 0;
                          local_a8 = 0;
                          bVar2 = *pbVar28;
                          if (bVar2 != 0) {
                            iVar10 = -1;
                            uVar29 = 0;
                            bVar5 = false;
                            uVar26 = 0xffffffff;
                            local_c0 = (void *)0x0;
                            do {
                              bVar6 = (bool)(bVar2 == 0x28 | bVar5);
                              if ((bVar2 == 0x28) || (!bVar5)) {
joined_r0x001316bc:
                                bVar5 = bVar6;
                                if (bVar2 != 0x2c) goto LAB_001316d4;
LAB_001316dc:
                                if ((int)uVar26 == -1) {
                                  uVar26 = 0xffffffff;
                                  if (bVar5) goto LAB_00131714;
                                }
                                else {
LAB_00131704:
                                  if (iVar10 == -1) {
                                    iVar10 = -1;
                                    goto LAB_00131710;
                                  }
                                  iVar11 = (int)uVar26;
                                  if ((bVar2 == 0x29) || (bVar2 == 0x2c)) {
                                    sVar42 = (long)iVar10 - (long)iVar11;
                                    pvVar34 = malloc((long)((int)sVar42 + 1));
                                    memcpy(pvVar34,pbVar28 + iVar11,sVar42);
                                    *(uint8_t *)((long)pvVar34 + sVar42) = 0;
                                    if ((local_c0 == (void *)0x0) || (pvVar34 == (void *)0x0)) {
                                      ArrayMap_put(&local_b0,pvVar34,0);
                                    }
                                    else {
                                      ArrayMap_put(&local_b0,local_c0,pvVar34);
                                      local_c0 = (void *)0x0;
                                    }
                                  }
                                  else if (bVar2 == 0x3d) {
                                    sVar42 = (long)iVar10 - (long)iVar11;
                                    local_c0 = malloc((long)((int)sVar42 + 1));
                                    memcpy(local_c0,pbVar28 + iVar11,sVar42);
                                    *(uint8_t *)((long)local_c0 + sVar42) = 0;
                                  }
                                  uVar26 = 0xffffffff;
                                  iVar10 = -1;
                                  if (bVar5) goto LAB_00131714;
                                }
                              }
                              else {
                                bVar6 = bVar5;
                                if (((*(uint8_t *)(_ctype_table + (unsigned long)bVar2 + 1) & 7) == 0) &&
                                   (bVar2 != 0x5f)) {
                                  if (((int)uVar26 == -1) || (iVar11 = (int)uVar29, iVar10 != -1))
                                  goto joined_r0x001316bc;
                                }
                                else {
                                  if ((int)uVar26 != -1) goto joined_r0x001316bc;
                                  uVar26 = uVar29 & 0xffffffff;
                                  iVar11 = iVar10;
                                }
                                iVar10 = iVar11;
                                if (bVar2 == 0x2c) goto LAB_001316dc;
LAB_001316d4:
                                if (bVar2 == 0x3d) goto LAB_001316dc;
                                if ((bVar2 == 0x29) && ((int)uVar26 != -1)) goto LAB_00131704;
LAB_00131710:
                                if (bVar5) {
LAB_00131714:
                                  if (pbVar28[uVar29] == 0x29) break;
                                }
                              }
                              bVar2 = pbVar28[uVar29 + 1];
                              uVar29 = uVar29 + 1;
                            } while (bVar2 != 0);
                            if (local_c0 != (void *)0x0) {
                              free(local_c0);
                            }
                          }
                          pbVar19 = (uint8_t *)ArrayMap_get(&local_b0,"location");
                          if (pbVar19 != (uint8_t *)0x0) {
                            bVar2 = *pbVar19;
                            if ((bVar2 == 0x2d) || (pbVar30 = pbVar19, bVar2 == 0x2b)) {
                              pbVar30 = pbVar19 + 1;
                              bVar2 = *pbVar30;
                            }
                            uVar24 = (uint32_t)bVar2;
                            if (uVar24 != 0) {
                              do {
                                pbVar30 = pbVar30 + 1;
                                if (9 < uVar24 - 0x30) goto LAB_00131a7c;
                                uVar24 = (uint32_t)*pbVar30;
                              } while (uVar24 != 0);
                              local_b8 = strtol((char *)pbVar19,(char **)0x0,10);
                            }
                          }
LAB_00131a7c:
                          ArrayMap_free(&local_b0,1,1);
                          iVar11 = 0;
                          iVar10 = -1;
                          goto LAB_00131340;
                        }
                      }
                      bVar2 = *pbVar28;
                      if (bVar2 != 0x20) {
                        iVar11 = 0;
                        iVar10 = -1;
                        pbVar28 = pbVar28 + 1;
                        if (bVar2 == 0) break;
                        goto LAB_00130fcc;
                      }
                      bVar2 = pbVar17[iVar37];
                      pbVar17[iVar37] = 0;
                      iVar11 = FUN_00136e4c(pbVar19);
                      cVar36 = cVar35;
                      if (iVar11 == 0) {
                        if ((uint8_t)(cVar35 - 2U) < 3) {
                          puVar18 = calloc(1,0x48);
                          pcVar21 = strdup((char *)pbVar19);
                          *puVar18 = 0xff02;
                          *(char **)(puVar18 + 4) = pcVar21;
                          *(char *)(puVar18 + 6) = cVar35;
                          puVar18[7] = (int)local_b8;
                          uVar1 = *(uint32_t *)(lVar15 + 8);
                          *(uint8_t *)((long)puVar18 + 0x2d) = 1;
                          puVar18[0x10] = uVar1;
                          *(uint32_t **)(lVar15 + 0x60) = puVar18;
                        }
                        else {
                          iVar10 = strcmp((char *)pbVar19,"const");
                          if (iVar10 == 0) {
                            cVar36 = '\x01';
                          }
                          else {
                            iVar10 = strcmp((char *)pbVar19,"in");
                            if (iVar10 == 0) {
                              cVar36 = '\x02';
                            }
                            else {
                              iVar10 = strcmp((char *)pbVar19,"out");
                              if (iVar10 == 0) {
                                cVar36 = '\x03';
                              }
                              else {
                                iVar10 = strcmp((char *)pbVar19,"uniform");
                                if (iVar10 == 0) {
                                  cVar36 = '\x04';
                                }
                                else {
                                  iVar10 = strcmp((char *)pbVar19,"attribute");
                                  if (iVar10 == 0) {
                                    cVar36 = '\x05';
                                  }
                                  else {
                                    iVar10 = strcmp((char *)pbVar19,"varying");
                                    cVar36 = '\x06';
                                    if (iVar10 != 0) {
                                      cVar36 = cVar35;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      pbVar17[iVar37] = bVar2;
                      cVar35 = cVar36;
                    }
                    else {
                      pbVar30 = pbVar28;
                      if (9 < *pbVar19 - 0x30) {
                        do {
                          do {
                            pbVar25 = pbVar30 + 1;
                            bVar2 = *pbVar30;
                            pbVar30 = pbVar25;
                          } while (bVar2 == 0x20);
                        } while (bVar2 - 9 < 5);
                        if (bVar2 == 0x28) {
                          if (*(long *)(lVar15 + 0x50) == 0) {
                            puVar38 = calloc(1,0x28);
                            sVar42 = iVar37 - lVar20;
                            pvVar34 = malloc((long)((int)sVar42 + 1));
                            memcpy(pvVar34,pbVar19,sVar42);
                            *(uint8_t *)((long)pvVar34 + sVar42) = 0;
                            *puVar38 = pvVar34;
                            *(uint32_t *)(puVar38 + 1) = *(uint32_t *)(lVar15 + 8);
                            *(uint64_t **)(lVar15 + 0x50) = puVar38;
                            *(int *)(lVar15 + 0x68) = *(int *)(lVar15 + 0x68) + 1;
                            FUN_00136bbc(pbVar19,puVar38 + 3,0);
                          }
                        }
                        else if (*(long *)(lVar15 + 0x58) == 0) {
                          iVar10 = *(int *)(lVar15 + 0x48);
                          if ((iVar10 == 0) && (*(long *)(lVar15 + 0x50) != 0)) {
                            iVar10 = 1;
                          }
                          piVar41 = calloc(1,0x48);
                          sVar42 = iVar37 - lVar20;
                          pvVar34 = malloc((long)((int)sVar42 + 1));
                          memcpy(pvVar34,pbVar19,sVar42);
                          *(uint8_t *)((long)pvVar34 + sVar42) = 0;
                          *(void **)(piVar41 + 2) = pvVar34;
                          piVar41[8] = iVar10;
                          *piVar41 = iVar11;
                          iVar10 = *(int *)(lVar15 + 0x68);
                          *(char *)(piVar41 + 6) = cVar35;
                          piVar41[9] = iVar10;
                          piVar41[7] = (int)local_b8;
                          piVar41[0x10] = *(int *)(lVar15 + 8);
                          lVar20 = *(long *)(lVar15 + 0x60);
                          if ((lVar20 != 0) && (*(char *)(lVar20 + 0x2d) == '\0')) {
                            for (lVar31 = *(long *)(lVar20 + 0x38); lVar31 != 0;
                                lVar31 = *(long *)(lVar31 + 0x38)) {
                              lVar20 = lVar31;
                            }
                            *(int **)(lVar20 + 0x38) = piVar41;
                            *(uint8_t *)(piVar41 + 0xb) = 1;
                          }
                          bVar2 = *pbVar28;
                          if (bVar2 == 0x5b) {
                            iVar10 = FUN_00136a80(pbVar28);
                            if (0 < iVar10) {
                              piVar41[10] = iVar10;
                            }
                            cVar35 = (char)piVar41[0xb];
                          }
                          else {
                            if (iVar10 == 0) {
                              if ((bVar2 == 0x20) || (bVar2 - 9 < 5)) {
                                lVar20 = 1;
                                do {
                                  do {
                                    bVar2 = pbVar28[lVar20];
                                    lVar20 = lVar20 + 1;
                                  } while (bVar2 == 0x20);
                                } while (bVar2 - 9 < 5);
                              }
                              if (bVar2 == 0x2c) {
                                bVar7 = true;
                                *(int **)(lVar15 + 0x58) = piVar41;
                              }
                            }
                            cVar35 = (char)piVar41[0xb];
                          }
                          if (cVar35 == '\0') {
                            ArrayMap_put(lVar15 + 0x18,*(uint64_t *)(piVar41 + 2),piVar41);
                          }
                          cVar35 = '\0';
                          iVar11 = 0;
                          local_b8 = 0xffffffff;
                          iVar10 = -1;
                          goto LAB_00131340;
                        }
                      }
                      cVar35 = '\0';
                      iVar11 = 0;
                      local_b8 = 0xffffffff;
                    }
                    iVar10 = -1;
                  }
                }
                else if (iVar10 == -1) {
                  iVar10 = iVar37 - iVar12;
                }
LAB_00131340:
                bVar2 = *pbVar28;
                pbVar28 = pbVar28 + 1;
              } while (bVar2 != 0);
              iVar12 = 0;
              local_b0 = 0;
              local_a8 = 0;
              *(uint32_t *)(lVar15 + 0x6c) = *(uint32_t *)(lVar15 + 0x6c) & 0xfffdffff;
              iVar10 = -1;
              do {
                bVar2 = pbVar17[iVar12];
                if ((bVar2 < 0x40) && ((1L << ((unsigned long)bVar2 & 0x3f) & 0xf400ac0000000000U) != 0)) {
                  *(uint32_t *)(lVar15 + 0x6c) = *(uint32_t *)(lVar15 + 0x6c) | 0x20000;
                }
                if (((*(uint8_t *)((unsigned long)bVar2 + _ctype_table + 1) & 7) == 0) && (bVar2 != 0x5f)) {
                  if (iVar10 == -1) {
                    iVar11 = -1;
                  }
                  else {
                    pbVar28 = pbVar17 + iVar10;
                    if ((((iVar12 - iVar10 < 4) || (*pbVar28 != 0x67)) || (pbVar28[1] != 0x6c)) ||
                       (pbVar28[2] != 0x5f)) {
                      pbVar17[iVar12] = 0;
                      if (*(int *)(lVar15 + 4) == 0x8b30) {
                        iVar11 = strcmp("varying",(char *)pbVar28);
                        if (iVar11 == 0) {
                          lVar20 = 2;
                        }
                        else {
                          iVar11 = strcmp("sampler1D",(char *)pbVar28);
                          if (iVar11 == 0) {
                            lVar20 = 3;
                          }
                          else {
                            iVar11 = strcmp("texture2D",(char *)pbVar28);
                            if (iVar11 == 0) {
                              lVar20 = 4;
                            }
                            else {
                              iVar11 = strcmp("texture2DLod",(char *)pbVar28);
                              if (iVar11 == 0) {
                                lVar20 = 5;
                              }
                              else {
                                iVar11 = strcmp("texture2DGradARB",(char *)pbVar28);
                                if (iVar11 == 0) {
                                  lVar20 = 6;
                                }
                                else {
                                  iVar11 = strcmp("texture2DLodOffset",(char *)pbVar28);
                                  if (iVar11 == 0) {
                                    lVar20 = 7;
                                  }
                                  else {
                                    iVar11 = strcmp("texture3D",(char *)pbVar28);
                                    if (iVar11 == 0) {
                                      lVar20 = 8;
                                    }
                                    else {
                                      iVar11 = strcmp("filter",(char *)pbVar28);
                                      if (iVar11 != 0) goto LAB_00131c24;
                                      lVar20 = 9;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        goto LAB_00131dd8;
                      }
                      if (*(int *)(lVar15 + 4) == 0x8b31) {
                        iVar11 = strcmp("attribute",(char *)pbVar28);
                        if (iVar11 == 0) {
                          lVar20 = 0;
LAB_00131dd8:
                          pcVar21 = strdup((&PTR_DAT_00141ff8)[lVar20 * 3]);
                        }
                        else {
                          iVar11 = strcmp("varying",(char *)pbVar28);
                          if (iVar11 == 0) {
                            lVar20 = 1;
                            goto LAB_00131dd8;
                          }
LAB_00131c24:
                          pcVar21 = (char *)0x0;
                        }
                        pbVar17[iVar12] = bVar2;
joined_r0x00131e04:
                        if (pcVar21 != (char *)0x0) {
                          plVar14 = calloc(1,0x18);
                          *plVar14 = (long)pcVar21;
                          *(int *)(plVar14 + 1) = iVar10;
                          *(int *)((long)plVar14 + 0xc) = iVar12;
                          ArrayList_add(&local_b0,plVar14);
                        }
                      }
                      else {
                        pbVar17[iVar12] = bVar2;
                      }
                      iVar11 = -1;
                    }
                    else {
                      uVar29 = 0;
                      do {
                        if (((0x184000U >> (uVar29 & 0x3f) & 1) != 0) ||
                           ((&DAT_00141e0c)[uVar29 * 6] == *(int *)(lVar15 + 4))) {
                          pcVar21 = (&PTR_s_gl_Color_00141df8)[uVar29 * 3];
                          lVar20 = 0;
                          do {
                            pbVar19 = (uint8_t *)(pcVar21 + lVar20);
                            if (*pbVar19 == 0) {
                              sVar42 = strlen(pcVar21);
                              if ((unsigned long)(long)(iVar12 - iVar10) < sVar42) {
                                sVar42 = strlen(pcVar21);
                                iVar12 = iVar10 + (int)sVar42;
                              }
                              if ((0x1a7fffU >> (uVar29 & 0x3f) & 1) == 0) {
                                pcVar21 = strdup(*(char **)(&UNK_00141e00 +
                                                           (uVar29 & 0xffffffff) * 0x18));
                              }
                              else {
                                pcVar21 = (char *)0x0;
                                pbVar28[1] = 100;
                              }
                              *(uint32_t *)(lVar15 + 0x6c) =
                                   *(uint32_t *)(lVar15 + 0x6c) |
                                   *(uint32_t *)(&UNK_00141e08 + (uVar29 & 0xffffffff) * 0x18);
                              goto joined_r0x00131e04;
                            }
                            pbVar30 = pbVar28 + lVar20;
                            lVar20 = lVar20 + 1;
                          } while (*pbVar19 == *pbVar30);
                        }
                        uVar29 = uVar29 + 1;
                        iVar11 = -1;
                      } while (uVar29 != 0x15);
                    }
                  }
                }
                else {
                  iVar11 = iVar12;
                  if (iVar10 != -1) {
                    iVar11 = iVar10;
                  }
                }
                iVar12 = iVar12 + 1;
                iVar10 = iVar11;
              } while (bVar2 != 0);
              if (0 < (int)(uint32_t)local_b0) {
                lVar20 = (local_b0 & 0xffffffff) + 1;
                pbVar28 = pbVar17;
                uVar24 = (uint32_t)local_b0;
                do {
                  uVar24 = uVar24 - 1;
                  puVar38 = *(uint64_t **)(local_a8 + (unsigned long)uVar24 * 8);
                  pbVar17 = (uint8_t *)FUN_001370c4(*puVar38,*(uint32_t *)(puVar38 + 1),
                                                 *(uint32_t *)((long)puVar38 + 0xc),pbVar28);
                  free(pbVar28);
                  free((void *)*puVar38);
                  lVar20 = lVar20 + -1;
                  pbVar28 = pbVar17;
                } while (1 < lVar20);
              }
              ArrayList_free(&local_b0,1);
              pcVar21 = (char *)FUN_0013575c(lVar15 + 8,pbVar17);
              uVar24 = *(uint32_t *)(lVar15 + 0x6c);
              if ((uVar24 >> 0x11 & 1) != 0) {
                pcVar21 = (char *)FUN_00136054(lVar15 + 8,pcVar21);
                uVar24 = *(uint32_t *)(lVar15 + 0x6c);
              }
              pcVar40 = pcVar21;
              if (((uVar24 >> 0x13 & 1) != 0) &&
                 (pcVar22 = strstr(pcVar21,"GL_ARB_shader_texture_lod"), pcVar22 != (char *)0x0)) {
                FUN_001369dc(&local_b0,0x40,"GD_%s","ARB_shader_texture_lod");
                pcVar40 = (char *)FUN_001375cc("GL_ARB_shader_texture_lod",&local_b0,pcVar21);
                free(pcVar21);
              }
              uVar24 = *(uint32_t *)(lVar15 + 0x18);
              if (0 < (int)uVar24) {
                lVar20 = (unsigned long)uVar24 + 1;
                do {
                  uVar24 = uVar24 - 1;
                  pvVar34 = *(void **)(*(long *)(lVar15 + 0x20) + (unsigned long)uVar24 * 0x10 + 8);
                  if ((*(char *)((long)pvVar34 + 0x2d) != '\0') &&
                     (ArrayMap_removeAt((uint32_t *)(lVar15 + 0x18),uVar24),
                     *(char *)((long)pvVar34 + 0x2c) == '\0')) {
                    if (*(void **)((long)pvVar34 + 8) != (void *)0x0) {
                      free(*(void **)((long)pvVar34 + 8));
                    }
                    free(pvVar34);
                  }
                  lVar20 = lVar20 + -1;
                } while (1 < lVar20);
              }
              ArrayList_add(lVar15 + 8,pcVar40);
            }
            if (cVar3 == '\n') {
              *(uint8_t *)(lVar16 + uVar32) = 10;
            }
            if (pvVar39 != (void *)0x0) {
              iVar12 = memcmp(__src,pvVar39,(long)iVar4);
              if (iVar12 != 0) {
                memcpy(__src,pvVar39,(long)iVar4);
              }
              free(pvVar39);
            }
            uVar32 = uVar32 + 1;
            iVar12 = (int)uVar32;
          } while (uVar32 != uVar33);
        }
LAB_00130a28:
        iVar13 = iVar13 + 1;
      } while (iVar13 != param_2);
    }
    lVar16 = 0;
    do {
      lVar20 = ArrayMap_get((uint32_t *)(lVar15 + 0x18),
                            (long)&DAT_00115a20 + (long)(int)(&DAT_00115a20)[lVar16]);
      if (lVar20 != 0) {
        iVar13 = *(int *)(lVar20 + 0x40);
        pvVar39 = (void *)ArrayList_removeAt(lVar15 + 8,iVar13);
        if (pvVar39 != (void *)0x0) {
          free(pvVar39);
        }
        uVar33 = (unsigned long)*(uint32_t *)(lVar15 + 0x28);
        if (0 < (int)*(uint32_t *)(lVar15 + 0x28)) {
          plVar14 = *(long **)(lVar15 + 0x30);
          do {
            lVar20 = *plVar14;
            if (iVar13 <= *(int *)(lVar20 + 8)) {
              *(int *)(lVar20 + 8) = *(int *)(lVar20 + 8) + -1;
              *(int *)(lVar20 + 0xc) = *(int *)(lVar20 + 0xc) + -1;
            }
            uVar33 = uVar33 - 1;
            plVar14 = plVar14 + 1;
          } while (uVar33 != 0);
        }
        uVar8 = *(uint32_t *)(lVar15 + 0x18);
        uVar33 = (unsigned long)uVar8;
        if (0 < (int)uVar8) {
          plVar14 = (long *)(*(long *)(lVar15 + 0x20) + 8);
          do {
            iVar12 = *(int *)(*plVar14 + 0x40);
            if (iVar13 <= iVar12) {
              *(int *)(*plVar14 + 0x40) = iVar12 + -1;
            }
            uVar33 = uVar33 - 1;
            plVar14 = plVar14 + 2;
          } while (uVar33 != 0);
        }
      }
      lVar16 = lVar16 + 1;
    } while (lVar16 != 4);
    if (0 < *(int *)(lVar15 + 0x18)) {
      lVar16 = 0;
      lVar20 = 8;
      do {
        lVar31 = *(long *)(*(long *)(lVar15 + 0x20) + lVar20);
        if ((*(int *)(lVar31 + 0x20) < 1) &&
           ((*(char *)(lVar31 + 0x18) == '\0' ||
            ((*(char *)(lVar31 + 0x18) == '\x04' && (*(short *)(lVar15 + 0x70) < 0x79)))))) {
          pcVar40 = *(char **)(*(long *)(lVar15 + 0x10) + (long)*(int *)(lVar31 + 0x40) * 8);
          pcVar21 = strstr(pcVar40,"//");
          if ((pcVar21 == (char *)0x0) && (pcVar21 = strstr(pcVar40,"/*"), pcVar21 == (char *)0x0))
          {
            bVar7 = true;
          }
          else {
            bVar7 = false;
            *pcVar21 = '\0';
          }
          pcVar22 = strchr(pcVar40,0x3d);
          if (!bVar7) {
            *pcVar21 = '/';
          }
          if (pcVar22 != (char *)0x0) {
            if (*(char *)(lVar31 + 0x18) == '\0') {
              uVar23 = FUN_00137168(0,2,"const ",pcVar40);
            }
            else {
              uVar23 = FUN_001375cc("uniform ","const ",pcVar40);
            }
            *(uint64_t *)(*(long *)(lVar15 + 0x10) + (long)*(int *)(lVar31 + 0x40) * 8) = uVar23;
            free(pcVar40);
            *(uint8_t *)(lVar31 + 0x18) = 1;
          }
        }
        lVar16 = lVar16 + 1;
        lVar20 = lVar20 + 0x10;
      } while (lVar16 < *(int *)(lVar15 + 0x18));
    }
    iVar13 = pthread_mutex_unlock((&glx_context_mutex));
    lVar27 = *(long *)(lVar27 + 0x28);
  }
  if (lVar27 != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar13);
  }
  return;
}


/* @00135160  size=1288 */

void ShaderConverter_updateBoundProgram(void)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  uint64_t *puVar4;
  uint64_t uVar5;
  uint64_t *puVar6;
  unsigned long *puVar7;
  long lVar8;
  uint32_t uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  simd128_t auVar14;
  simd128_t auVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  uint32_t uVar24;
  simd128_t auVar25;
  simd128_t auVar26;
  float fVar27;
  float fVar29;
  float fVar30;
  simd128_t auVar28;
  float fVar31;
  uint32_t uVar34;
  simd128_t auVar32;
  simd128_t auVar33;
  simd128_t auVar35;
  simd128_t auVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  simd128_t auVar45;
  simd128_t auVar46;
  simd128_t auVar47;
  simd128_t auVar48;
  simd128_t auVar49;
  uint64_t local_80;
  uint64_t uStack_78;
  uint64_t uStack_70;
  uint64_t uStack_68;
  uint64_t local_60;
  uint64_t uStack_58;
  uint64_t uStack_50;
  uint64_t uStack_48;
  long local_38;
  
  /* stack canary setup (elided) */
  local_38 = *(long *)(lVar2 + 0x28);
  plVar3 = (long *)(&currentRenderer);
  lVar8 = *(long *)(*plVar3 + 0x560);
  if (lVar8 != 0) {
    if (((*(char *)(lVar8 + 0x29) != '\0') && (*(char *)(*(long *)(*plVar3 + 0x540) + 0x42) == '\0')
        ) && (*(int *)(lVar8 + 0x30) != -1)) {
      GLRenderer_disableVertexAttribute();
      uVar9 = *(uint32_t *)(lVar8 + 0x30);
      plVar3 = (long *)(&currentRenderer);
      glVertexAttrib4fv(uVar9,*plVar3 + 0xac);
    }
    if (*(char *)(lVar8 + 0x28) != '\0') {
      iVar1 = *(int *)(lVar8 + 0x58);
      if (iVar1 != -1) {
        plVar3 = (long *)(&currentRenderer);
        if (*(char *)(*plVar3 + 0x58) == '\0') {
          uVar9 = 0x4401c000;
        }
        else {
          uVar9 = NEON_ucvtf(*(uint32_t *)(*plVar3 + 0x5c));
        }
        glUniform2f(uVar9, iVar1, 0);
      }
      iVar1 = *(int *)(lVar8 + 0x60);
      if (iVar1 != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,0);
        glUniformMatrix4fv(iVar1,1,0,uVar5);
      }
      iVar1 = *(int *)(lVar8 + 0x5c);
      if (iVar1 != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,1);
        glUniformMatrix4fv(iVar1,1,0,uVar5);
      }
      if (*(int *)(lVar8 + 100) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        puVar6 = (uint64_t *)GLRenderer_getMatrixFromStack(*puVar4,0);
        puVar7 = (unsigned long *)GLRenderer_getMatrixFromStack(*puVar4,1);
        (*(uint64_t*)((char*)&auVar28 + 0)) = *puVar7;
        (*(uint64_t*)((char*)&auVar28 + 8)) = 0;
        fVar12 = *(float *)(puVar6 + 1);
        (*(uint64_t*)((char*)&auVar25 + 0)) = puVar7[2];
        (*(uint64_t*)((char*)&auVar25 + 8)) = 0;
        (*(uint64_t*)((char*)&auVar32 + 0)) = puVar7[4];
        (*(uint64_t*)((char*)&auVar32 + 8)) = 0;
        (*(uint64_t*)((char*)&auVar35 + 0)) = puVar7[6];
        (*(uint64_t*)((char*)&auVar35 + 8)) = 0;
        fVar37 = *(float *)(puVar7 + 1);
        fVar38 = *(float *)((long)puVar7 + 0xc);
        fVar39 = *(float *)(puVar7 + 3);
        fVar40 = *(float *)((long)puVar7 + 0x1c);
        fVar41 = *(float *)(puVar7 + 5);
        fVar42 = *(float *)((long)puVar7 + 0x2c);
        fVar43 = *(float *)(puVar7 + 7);
        fVar44 = *(float *)((long)puVar7 + 0x3c);
        fVar13 = *(float *)((long)puVar6 + 0x1c);
        uVar9 = (uint32_t)(*(uint64_t*)((char*)&auVar28 + 0));
        (*(uint32_t*)((char*)&auVar46 + 4)) = uVar9;
        (*(uint32_t*)((char*)&auVar46 + 0)) = uVar9;
        (*(uint32_t*)((char*)&auVar46 + 8)) = uVar9;
        (*(uint32_t*)((char*)&auVar46 + 12)) = uVar9;
        uVar9 = (uint32_t)((*(uint64_t*)((char*)&auVar28 + 0)) >> 0x20);
        uVar24 = (uint32_t)(*(uint64_t*)((char*)&auVar25 + 0));
        (*(uint32_t*)((char*)&auVar47 + 4)) = uVar24;
        (*(uint32_t*)((char*)&auVar47 + 0)) = uVar24;
        (*(uint32_t*)((char*)&auVar47 + 8)) = uVar24;
        (*(uint32_t*)((char*)&auVar47 + 12)) = uVar24;
        uVar24 = (uint32_t)(*(uint64_t*)((char*)&auVar32 + 0));
        (*(uint32_t*)((char*)&auVar49 + 4)) = uVar24;
        (*(uint32_t*)((char*)&auVar49 + 0)) = uVar24;
        (*(uint32_t*)((char*)&auVar49 + 8)) = uVar24;
        (*(uint32_t*)((char*)&auVar49 + 12)) = uVar24;
        uVar24 = (uint32_t)(*(uint64_t*)((char*)&auVar35 + 0));
        (*(uint32_t*)((char*)&auVar48 + 4)) = uVar24;
        (*(uint32_t*)((char*)&auVar48 + 0)) = uVar24;
        (*(uint32_t*)((char*)&auVar48 + 8)) = uVar24;
        (*(uint32_t*)((char*)&auVar48 + 12)) = uVar24;
        fVar20 = (float)puVar6[4];
        fVar21 = (float)((unsigned long)puVar6[4] >> 0x20);
        fVar22 = (float)puVar6[5];
        fVar23 = (float)((unsigned long)puVar6[5] >> 0x20);
        fVar16 = (float)puVar6[6];
        fVar17 = (float)((unsigned long)puVar6[6] >> 0x20);
        fVar18 = (float)puVar6[7];
        fVar19 = (float)((unsigned long)puVar6[7] >> 0x20);
        uVar24 = (uint32_t)((*(uint64_t*)((char*)&auVar25 + 0)) >> 0x20);
        uVar34 = (uint32_t)((*(uint64_t*)((char*)&auVar32 + 0)) >> 0x20);
        auVar45 = (simd128_t){0};
        (*(uint32_t*)((char*)&auVar14 + 4)) = uVar9;
        (*(uint32_t*)((char*)&auVar14 + 0)) = uVar9;
        (*(uint32_t*)((char*)&auVar14 + 8)) = uVar9;
        (*(uint32_t*)((char*)&auVar14 + 12)) = uVar9;
        auVar14 = (simd128_t){0};
        uVar9 = (uint32_t)((*(uint64_t*)((char*)&auVar35 + 0)) >> 0x20);
        /* NEON intrinsic elided */
        auVar46 = (simd128_t){0};
        auVar47 = (simd128_t){0};
        auVar49 = (simd128_t){0};
        (*(uint32_t*)((char*)&auVar26 + 4)) = uVar24;
        (*(uint32_t*)((char*)&auVar26 + 0)) = uVar24;
        (*(uint32_t*)((char*)&auVar26 + 8)) = uVar24;
        (*(uint32_t*)((char*)&auVar26 + 12)) = uVar24;
        auVar26 = (simd128_t){0};
        (*(uint32_t*)((char*)&auVar33 + 4)) = uVar34;
        (*(uint32_t*)((char*)&auVar33 + 0)) = uVar34;
        (*(uint32_t*)((char*)&auVar33 + 8)) = uVar34;
        (*(uint32_t*)((char*)&auVar33 + 12)) = uVar34;
        auVar33 = (simd128_t){0};
        (*(uint32_t*)((char*)&auVar36 + 4)) = uVar9;
        (*(uint32_t*)((char*)&auVar36 + 0)) = uVar9;
        (*(uint32_t*)((char*)&auVar36 + 8)) = uVar9;
        (*(uint32_t*)((char*)&auVar36 + 12)) = uVar9;
        auVar36 = (simd128_t){0};
        fVar27 = (*(uint32_t*)((char*)&auVar28 + 0));
        fVar29 = (*(uint32_t*)((char*)&auVar28 + 4));
        fVar30 = (*(uint32_t*)((char*)&auVar28 + 8));
        fVar31 = (*(uint32_t*)((char*)&auVar28 + 12));
        fVar10 = (float)*puVar6;
        fVar11 = (float)((unsigned long)*puVar6 >> 0x20);
        (*(uint64_t*)((char*)&auVar15 + 0)) =
             ((uint64_t)(fVar11 * (*(uint32_t*)((char*)&auVar45 + 4)) + fVar29 * (*(uint32_t*)((char*)&auVar14 + 4)) + fVar21 * fVar37 +
                      fVar17 * fVar38) << 32 | (uint32_t)(
                      fVar10 * (*(uint32_t*)((char*)&auVar45 + 0)) + fVar27 * (*(uint32_t*)((char*)&auVar14 + 0)) + fVar20 * fVar37 +
                      fVar16 * fVar38));
        (*(uint32_t*)((char*)&auVar15 + 8)) =
             fVar12 * (*(uint32_t*)((char*)&auVar45 + 8)) + fVar30 * (*(uint32_t*)((char*)&auVar14 + 8)) + fVar22 * fVar37 + fVar18 * fVar38;
        (*(uint32_t*)((char*)&auVar15 + 12)) =
             fVar13 * (*(uint32_t*)((char*)&auVar45 + 12)) + fVar31 * (*(uint32_t*)((char*)&auVar14 + 12)) + fVar23 * fVar37 + fVar19 * fVar38;
        uStack_70 = ((uint64_t)(fVar11 * (*(uint32_t*)((char*)&auVar46 + 4)) + fVar29 * (*(uint32_t*)((char*)&auVar26 + 4)) + fVar21 * fVar39 +
                             fVar17 * fVar40) << 32 | (uint32_t)(
                             fVar10 * (*(uint32_t*)((char*)&auVar46 + 0)) + fVar27 * (*(uint32_t*)((char*)&auVar26 + 0)) + fVar20 * fVar39 +
                             fVar16 * fVar40));
        uStack_68 = ((uint64_t)(fVar13 * (*(uint32_t*)((char*)&auVar46 + 12)) + fVar31 * (*(uint32_t*)((char*)&auVar26 + 12)) + fVar23 * fVar39 +
                             fVar19 * fVar40) << 32 | (uint32_t)(
                             fVar12 * (*(uint32_t*)((char*)&auVar46 + 8)) + fVar30 * (*(uint32_t*)((char*)&auVar26 + 8)) + fVar22 * fVar39 +
                             fVar18 * fVar40));
        (*(uint64_t*)((char*)&auVar45 + 0)) =
             ((uint64_t)(fVar11 * (*(uint32_t*)((char*)&auVar47 + 4)) + fVar29 * (*(uint32_t*)((char*)&auVar33 + 4)) + fVar21 * fVar41 +
                      fVar17 * fVar42) << 32 | (uint32_t)(
                      fVar10 * (*(uint32_t*)((char*)&auVar47 + 0)) + fVar27 * (*(uint32_t*)((char*)&auVar33 + 0)) + fVar20 * fVar41 +
                      fVar16 * fVar42));
        (*(uint32_t*)((char*)&auVar45 + 8)) =
             fVar12 * (*(uint32_t*)((char*)&auVar47 + 8)) + fVar30 * (*(uint32_t*)((char*)&auVar33 + 8)) + fVar22 * fVar41 + fVar18 * fVar42;
        (*(uint32_t*)((char*)&auVar45 + 12)) =
             fVar13 * (*(uint32_t*)((char*)&auVar47 + 12)) + fVar31 * (*(uint32_t*)((char*)&auVar33 + 12)) + fVar23 * fVar41 + fVar19 * fVar42;
        uStack_50 = ((uint64_t)(fVar11 * (*(uint32_t*)((char*)&auVar49 + 4)) + fVar29 * (*(uint32_t*)((char*)&auVar36 + 4)) + fVar21 * fVar43 +
                             fVar17 * fVar44) << 32 | (uint32_t)(
                             fVar10 * (*(uint32_t*)((char*)&auVar49 + 0)) + fVar27 * (*(uint32_t*)((char*)&auVar36 + 0)) + fVar20 * fVar43 +
                             fVar16 * fVar44));
        uStack_48 = ((uint64_t)(fVar13 * (*(uint32_t*)((char*)&auVar49 + 12)) + fVar31 * (*(uint32_t*)((char*)&auVar36 + 12)) + fVar23 * fVar43 +
                             fVar19 * fVar44) << 32 | (uint32_t)(
                             fVar12 * (*(uint32_t*)((char*)&auVar49 + 8)) + fVar30 * (*(uint32_t*)((char*)&auVar36 + 8)) + fVar22 * fVar43 +
                             fVar18 * fVar44));
        uStack_78 = (*(uint64_t*)((char*)&auVar15 + 8));
        uStack_58 = (*(uint64_t*)((char*)&auVar45 + 8));
        local_80 = (*(uint64_t*)((char*)&auVar15 + 0));
        local_60 = (*(uint64_t*)((char*)&auVar45 + 0));
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 100),1,0,&local_80);
      }
      if (*(int *)(lVar8 + 0x68) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x68),1,0,uVar5);
      }
      if (*(int *)(lVar8 + 0x6c) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x6c),1,0,uVar5);
      }
      if (*(int *)(lVar8 + 0x70) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x70),1,0,uVar5);
      }
      if (*(int *)(lVar8 + 0x74) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x74),1,0,uVar5);
      }
      if (*(int *)(lVar8 + 0x78) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x78),1,0,uVar5);
      }
      if (*(int *)(lVar8 + 0x7c) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x7c),1,0,uVar5);
      }
      if (*(int *)(lVar8 + 0x80) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x80),1,0,uVar5);
      }
      if (*(int *)(lVar8 + 0x84) != -1) {
        puVar4 = (uint64_t *)(&currentRenderer);
        uVar5 = GLRenderer_getMatrixFromStack(*puVar4,2);
        glUniformMatrix4fv(*(uint32_t *)(lVar8 + 0x84),1,0,uVar5);
      }
      iVar1 = *(int *)(lVar8 + 0x88);
      if (iVar1 != -1) {
        plVar3 = (long *)(&currentRenderer);
        glUniform4fv(iVar1,1,*plVar3 + 100);
        glUniform1f(*(uint32_t *)(*plVar3 + 0x74),*(uint32_t *)(lVar8 + 0x8c));
        glUniform1f(*(uint32_t *)(*plVar3 + 0x78),*(uint32_t *)(lVar8 + 0x90));
        glUniform1f(*(uint32_t *)(*plVar3 + 0x7c),*(uint32_t *)(lVar8 + 0x94));
        glUniform1f(1.0 / (*(float *)(*plVar3 + 0x7c) - *(float *)(*plVar3 + 0x78)),
                    *(uint32_t *)(lVar8 + 0x98));
      }
    }
  }
  if (*(long *)(lVar2 + 0x28) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


