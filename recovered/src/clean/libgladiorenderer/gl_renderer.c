/*
 * gl_renderer.c — GLRenderer state machine and draw calls
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include "gladio_data.h"

/* Forward declarations */
void *GLRenderer_getTexImage(long param_1, int param_2, uint64_t param_3, int param_4, int param_5, int *param_6);
void GLRenderer_readPixels(long param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, uint8_t *param_8);
#include <GLES3/gl32.h>
#include <EGL/egl.h>
#include <android/log.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>

/* @0011fe90  size=344 */

void GLRenderer_addArrayElement(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar4;
  int iVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  uint32_t *puVar8;
  long lVar9;
  uint16_t uVar10;
  
  if (*(long *)(param_1 + 0x898) == 0) {
    return;
  }
  ArrayBuffer_putShort(param_1 + 0x6f0);
  puVar8 = *(uint32_t **)(param_1 + 0x898);
  iVar3 = *(int *)(param_1 + 0x6f4);
  uVar4 = *puVar8;
  iVar5 = puVar8[3];
  *(int *)(param_1 + 0x6f4) = iVar3 + 1;
  uVar1 = iVar5 + 1;
  puVar8[3] = uVar1;
  switch(uVar4) {
  case 5:
  case 8:
    if (iVar5 < 3) {
      return;
    }
    lVar9 = *(long *)(param_1 + 0x700);
    if (uVar1 == 4) {
      uVar10 = *(uint16_t *)(lVar9 + (long)(iVar3 + -2) * 2);
      uVar7 = *(uint16_t *)(lVar9 + (long)(iVar3 + -1) * 2);
    }
    else {
      iVar5 = puVar8[2] + 2;
      iVar2 = iVar5;
      if (iVar5 <= iVar3 + -6) {
        iVar2 = iVar3 + -6;
      }
      if (iVar5 <= iVar3 + -3) {
        iVar5 = iVar3 + -3;
      }
      uVar6 = *(uint16_t *)(lVar9 + (long)iVar2 * 2);
      uVar7 = *(uint16_t *)(lVar9 + (long)iVar5 * 2);
      uVar10 = uVar6;
      if ((uVar1 & 1) != 0) {
        uVar10 = uVar7;
        uVar7 = uVar6;
      }
    }
    break;
  case 6:
  case 9:
    if (iVar5 < 3) {
      return;
    }
    if (uVar1 == 4) {
      iVar5 = iVar3 + -1;
    }
    else {
      iVar5 = puVar8[2] + 2;
      if (iVar5 <= iVar3 + -3) {
        iVar5 = iVar3 + -3;
      }
    }
    uVar10 = *(uint16_t *)(*(long *)(param_1 + 0x700) + (long)iVar5 * 2);
    uVar7 = *(uint16_t *)(*(long *)(param_1 + 0x700) + (long)(int)puVar8[2] * 2);
    break;
  case 7:
    if ((uVar1 & 3) != 0) {
      return;
    }
    lVar9 = *(long *)(param_1 + 0x700);
    ArrayBuffer_putShort(param_1 + 0x6f0,*(uint16_t *)(lVar9 + (long)(iVar3 + -3) * 2));
    uVar10 = *(uint16_t *)(lVar9 + (long)(iVar3 + -1) * 2);
    goto LAB_0011ffc0;
  default:
    goto switchD_0011fef4_default;
  }
  ArrayBuffer_putShort(param_1 + 0x6f0,uVar7);
LAB_0011ffc0:
  ArrayBuffer_putShort(param_1 + 0x6f0,uVar10);
  *(int *)(param_1 + 0x6f4) = *(int *)(param_1 + 0x6f4) + 2;
switchD_0011fef4_default:
  return;
}


/* @0011fd20  size=368 */

void GLRenderer_addVertex(long param_1)

{
  if (*(long *)(param_1 + 0x898) != 0) {
    ArrayBuffer_putFloat4(param_1 + 0x5e8);
    if ((0 < *(int *)(param_1 + 0x604)) || (0 < *(int *)(param_1 + 0x600))) {
      ArrayBuffer_putBytes(param_1 + 0x600,param_1 + 0xac,0x10);
    }
    if (0 < *(int *)(param_1 + 0x61c)) {
      ArrayBuffer_putBytes(param_1 + 0x618,param_1 + 0xbc,0xc);
    }
    if (0 < *(int *)(param_1 + 0x634)) {
      ArrayBuffer_putBytes(param_1 + 0x630,param_1 + 200,0x10);
    }
    if (0 < *(int *)(param_1 + 0x64c)) {
      ArrayBuffer_putBytes(param_1 + 0x648,param_1 + 0xd8,0x10);
    }
    if (0 < *(int *)(param_1 + 0x664)) {
      ArrayBuffer_putBytes(param_1 + 0x660,param_1 + 0xe8,0x10);
    }
    if (0 < *(int *)(param_1 + 0x67c)) {
      ArrayBuffer_putBytes(param_1 + 0x678,param_1 + 0xf8,0x10);
    }
    if (0 < *(int *)(param_1 + 0x694)) {
      ArrayBuffer_putBytes(param_1 + 0x690,param_1 + 0x108,0x10);
    }
    if (0 < *(int *)(param_1 + 0x6ac)) {
      ArrayBuffer_putBytes(param_1 + 0x6a8,param_1 + 0x118,0x10);
    }
    if (0 < *(int *)(param_1 + 0x6c4)) {
      ArrayBuffer_putBytes(param_1 + 0x6c0,param_1 + 0x128,0x10);
    }
    if (0 < *(int *)(param_1 + 0x6dc)) {
      ArrayBuffer_putBytes(param_1 + 0x6d8,param_1 + 0x138,0x10);
    }
    *(int *)(param_1 + 0x5ec) = *(int *)(param_1 + 0x5ec) + 1;
    GLRenderer_addArrayElement(param_1);
    return;
  }
  return;
}


/* @0011fa88  size=180 */

void GLRenderer_beginImmediate(long param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*(long *)(param_1 + 0x898) == 0) {
    piVar2 = (int *)ArrayDeque_getLast(param_1 + 0x880);
    if ((((piVar2 == (int *)0x0) || (*(uint32_t *)(param_1 + 0x48) >> 1 == 0xd80)) || (5 < *piVar2 - 4U)
        ) || (5 < param_2 - 4U)) {
      piVar2 = calloc(1,0x10);
      iVar1 = *(int *)(param_1 + 0x6f4);
      *(int **)(param_1 + 0x898) = piVar2;
      *piVar2 = param_2;
      piVar2[1] = iVar1;
      piVar2[2] = iVar1;
      ArrayDeque_addLast(param_1 + 0x880,piVar2);
      return;
    }
    iVar1 = *(int *)(param_1 + 0x6f4);
    *piVar2 = param_2;
    *(int **)(param_1 + 0x898) = piVar2;
    piVar2[2] = iVar1;
    piVar2[3] = 0;
  }
  return;
}


/* @00120f04  size=364 */

void GLRenderer_destroy(long param_1)

{
  void *__ptr;
  int iVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 != 0) {
    glDeleteBuffers(0xc,param_1 + 0x14);
    GLVertexArrayObject_delete(param_1 + 0x398,0);
    if (*(long *)(param_1 + 0x918) != 0) {
      __ptr = *(void **)(*(long *)(param_1 + 0x918) + 8);
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      *(uint64_t *)(param_1 + 0x918) = 0;
    }
    *(uint32_t *)(param_1 + 0x910) = 0;
    if (*(int *)(param_1 + 0x8fc) != 0) {
      glDeleteTextures(1,param_1 + 0x8fc);
      *(uint32_t *)(param_1 + 0x8fc) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x870);
    if (0 < iVar1) {
      lVar2 = 0;
      lVar3 = 8;
      do {
        if (*(long *)(*(long *)(param_1 + 0x878) + lVar3) != 0) {
          ShaderMaterial_destroy();
          iVar1 = *(int *)(param_1 + 0x870);
        }
        lVar2 = lVar2 + 1;
        lVar3 = lVar3 + 0x10;
      } while (lVar2 < iVar1);
    }
    SparseArray_free(param_1 + 0x870,0);
    if (*(void **)(param_1 + 0x708) != (void *)0x0) {
      free(*(void **)(param_1 + 0x708));
      *(uint64_t *)(param_1 + 0x708) = 0;
    }
    ArrayBuffer_free(param_1 + 0x6f0);
    ArrayBuffer_free(param_1 + 0x5e8);
    ArrayBuffer_free(param_1 + 0x600);
    ArrayBuffer_free(param_1 + 0x618);
    ArrayBuffer_free(param_1 + 0x630);
    ArrayBuffer_free(param_1 + 0x648);
    ArrayBuffer_free(param_1 + 0x660);
    ArrayBuffer_free(param_1 + 0x678);
    ArrayBuffer_free(param_1 + 0x690);
    ArrayBuffer_free(param_1 + 0x6a8);
    ArrayBuffer_free(param_1 + 0x6c0);
    ArrayBuffer_free(param_1 + 0x6d8);
    ArrayDeque_free(param_1 + 0x880,1);
    if (*(long *)(param_1 + 0x8d8) != 0) {
      glDeleteTextures(1,*(long *)(param_1 + 0x8d8) + 0x18);
      free(*(void **)(param_1 + 0x8d8));
      return;
    }
  }
  return;
}


/* @0011f954  size=248 */

void GLRenderer_disableUnusedVertexAttributes(long param_1)

{
  if (*(char *)(param_1 + 0x8f0) != '\0') {
    glDisableVertexAttribArray(0);
    *(uint8_t *)(param_1 + 0x8f0) = 0;
  }
  if (*(char *)(param_1 + 0x8f1) != '\0') {
    glDisableVertexAttribArray(1);
    *(uint8_t *)(param_1 + 0x8f1) = 0;
  }
  if (*(char *)(param_1 + 0x8f2) != '\0') {
    glDisableVertexAttribArray(2);
    *(uint8_t *)(param_1 + 0x8f2) = 0;
  }
  if (*(char *)(param_1 + 0x8f3) != '\0') {
    glDisableVertexAttribArray(3);
    *(uint8_t *)(param_1 + 0x8f3) = 0;
  }
  if (*(char *)(param_1 + 0x8f4) != '\0') {
    glDisableVertexAttribArray(4);
    *(uint8_t *)(param_1 + 0x8f4) = 0;
  }
  if (*(char *)(param_1 + 0x8f5) != '\0') {
    glDisableVertexAttribArray(5);
    *(uint8_t *)(param_1 + 0x8f5) = 0;
  }
  if (*(char *)(param_1 + 0x8f6) != '\0') {
    glDisableVertexAttribArray(6);
    *(uint8_t *)(param_1 + 0x8f6) = 0;
  }
  if (*(char *)(param_1 + 0x8f7) != '\0') {
    glDisableVertexAttribArray(7);
    *(uint8_t *)(param_1 + 0x8f7) = 0;
  }
  if (*(char *)(param_1 + 0x8f8) != '\0') {
    glDisableVertexAttribArray(8);
    *(uint8_t *)(param_1 + 0x8f8) = 0;
  }
  if (*(char *)(param_1 + 0x8f9) != '\0') {
    glDisableVertexAttribArray(9);
    *(uint8_t *)(param_1 + 0x8f9) = 0;
  }
  if (*(char *)(param_1 + 0x8fa) != '\0') {
    glDisableVertexAttribArray(10);
    *(uint8_t *)(param_1 + 0x8fa) = 0;
  }
  return;
}


/* @00121f0c  size=56 */

void GLRenderer_disableVertexAttribute(long param_1,uint32_t param_2)

{
  if ((-1 < (int)param_2) && (*(char *)(param_1 + (unsigned long)param_2 + 0x8f0) != '\0')) {
    glDisableVertexAttribArray(param_2);
    *(uint8_t *)(param_1 + (unsigned long)param_2 + 0x8f0) = 0;
  }
  return;
}


/* @0011f07c  size=1172 */

void GLRenderer_drawImmediate(long param_1)

{
  short *psVar1;
  long lVar2;
  int iVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint8_t uVar6;
  long lVar7;
  unsigned long uVar8;
  int *__ptr;
  uint32_t *puVar9;
  void *__ptr_00;
  uint32_t uVar10;
  int iVar11;
  uint8_t *puVar12;
  uint8_t *puVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint8_t local_90;
  uint8_t local_8f;
  uint8_t local_8e;
  uint8_t local_8d;
  uint8_t local_8c;
  char local_8b;
  uint64_t local_88;
  uint64_t uStack_80;
  long local_78;
  
  /* stack canary setup (elided) */
  local_78 = *(long *)(lVar7 + 0x28);
  if ((param_1 != 0) && (uVar8 = ArrayDeque_isEmpty(param_1 + 0x880), (uVar8 & 1) == 0)) {
    if (*(long *)(param_1 + 0x560) == 0) {
      if ((*(char *)(param_1 + 0x388) == '\0') && (*(char *)(param_1 + 0x389) == '\0')) {
        uStack_80 = 0;
        local_88 = 0;
      }
      else {
        local_88 = *(uint64_t *)(param_1 + 0x598);
        uStack_80 = *(uint64_t *)(param_1 + 0x5a0);
      }
      local_8b = *(char *)(param_1 + 900) +
                 *(char *)(param_1 + 0x380) +
                 *(char *)(param_1 + 0x37c) +
                 *(char *)(param_1 + 0x378) +
                 *(char *)(param_1 + 0x374) +
                 *(char *)(param_1 + 0x370) +
                 *(char *)(param_1 + 0x36c) + *(char *)(param_1 + 0x368);
      local_8d = true;
      if (*(char *)(param_1 + 0xa8) == '\0') {
        local_8d = *(char *)(param_1 + 0xa9) != '\0';
      }
      local_90 = *(uint8_t *)(param_1 + 0x44);
      local_8f = *(uint8_t *)(param_1 + 0x58);
      local_8e = *(uint8_t *)(param_1 + 0x84);
      local_8c = 1;
      lVar14 = FUN_0011f510(param_1,&local_90);
      FUN_0011f6a4(param_1,lVar14 + 8);
    }
    else {
      ShaderConverter_updateBoundProgram();
      FUN_0011f6a4(param_1,*(long *)(param_1 + 0x560) + 0x2c);
      lVar14 = 0;
    }
    uVar8 = ArrayDeque_isEmpty(param_1 + 0x880);
    while ((uVar8 & 1) == 0) {
      __ptr = (int *)ArrayDeque_removeFirst(param_1 + 0x880);
      if (*(int *)(param_1 + 0x48) == 0x1b00) {
        iVar11 = 0;
      }
      else if (*(int *)(param_1 + 0x48) == 0x1b01) {
        iVar11 = 1;
      }
      else {
        iVar11 = *__ptr;
      }
      iVar3 = 4;
      if ((iVar11 != 9 && 1 < iVar11 - 7U) && 1 < iVar11 - 5U) {
        iVar3 = iVar11;
      }
      if (lVar14 != 0) {
        if (iVar3 == 0) {
          ShaderMaterial_updatePointUniforms(lVar14,param_1);
          if ((*(char *)(param_1 + 0xa9) != '\0') && (*(char *)(param_1 + 0xa8) == '\0')) {
            iVar11 = *(int *)(param_1 + 0x8fc);
            if (iVar11 == 0) {
              glGenTextures(1,param_1 + 0x8fc);
              glBindTexture(0xde1,*(uint32_t *)(param_1 + 0x8fc));
              glTexParameteri(0xde1,0x2801,0x2600);
              glTexParameteri(0xde1,0x2800,0x2600);
              glTexParameteri(0xde1,0x2802,0x812f);
              glTexParameteri(0xde1,0x2803,0x812f);
              __ptr_00 = malloc(0x4000);
              lVar15 = 0;
              puVar12 = (uint8_t *)((long)__ptr_00 + 3);
              do {
                fVar17 = 32.0 - (float)(int)lVar15;
                lVar16 = 0;
                puVar13 = puVar12;
                do {
                  fVar18 = 32.0 - (float)(int)lVar16;
                  fVar19 = 32.0 - SQRT(fVar17 * fVar17 + fVar18 * fVar18);
                  fVar18 = fVar19;
                  if (fVar19 <= 0.0) {
                    fVar18 = 0.0;
                  }
                  fVar20 = 255.0;
                  if (fVar19 <= 1.0) {
                    fVar20 = fVar18 * 255.0;
                  }
                  lVar16 = lVar16 + 1;
                  uVar6 = (uint8_t)(int)fVar20;
                  puVar13[-3] = uVar6;
                  puVar13[-2] = uVar6;
                  puVar13[-1] = uVar6;
                  *puVar13 = uVar6;
                  puVar13 = puVar13 + 0x100;
                } while (lVar16 != 0x40);
                lVar15 = lVar15 + 1;
                puVar12 = puVar12 + 4;
              } while (lVar15 != 0x40);
              glTexImage2D(0xde1,0,0x8058,0x40,0x40,0,0x1908,0x1401,__ptr_00);
              free(__ptr_00);
              glBindTexture(0xde1,0);
              iVar11 = *(int *)(param_1 + 0x8fc);
            }
            glBindTexture(0xde1,iVar11);
          }
        }
        else {
          glUniform1f(0,*(uint32_t *)(lVar14 + 0x128));
        }
      }
      glDrawElements(iVar3,__ptr[2] - __ptr[1],0x1403,(long)__ptr[1] << 1);
      free(__ptr);
      if (((iVar3 == 0) && (*(char *)(param_1 + 0xa9) != '\0')) &&
         (*(char *)(param_1 + 0xa8) == '\0')) {
        puVar9 = (uint32_t *)GLTexture_getBound(0xde1);
        if (puVar9 == (uint32_t *)0x0) {
          uVar10 = 0;
        }
        else {
          uVar10 = *puVar9;
        }
        glBindTexture(0xde1,uVar10);
      }
      uVar8 = ArrayDeque_isEmpty(param_1 + 0x880);
    }
    glFlush();
    *(uint32_t *)(param_1 + 0x6f4) = 0;
    *(uint32_t *)(param_1 + 0x5ec) = 0;
    GLRenderer_disableUnusedVertexAttributes(param_1);
    if (*(long *)(param_1 + 0x560) != 0) {
      lVar14 = 0x20;
      lVar15 = 0x2c;
      do {
        lVar16 = *(long *)(param_1 + 0x540);
        if (*(int *)(lVar16 + lVar14 + -0x10) != 0) {
          glBindBuffer(0x8892, 0);
          uVar5 = *(uint32_t *)(*(long *)(param_1 + 0x560) + lVar15);
          if ((-1 < (int)uVar5) &&
             (lVar2 = param_1 + (unsigned long)uVar5, *(char *)(lVar2 + 0x8f0) == '\0')) {
            glEnableVertexAttribArray(uVar5);
            *(uint8_t *)(lVar2 + 0x8f0) = 1;
          }
          psVar1 = (short *)(lVar16 + lVar14);
          glVertexAttribPointer
                    ((unsigned long)uVar5,*(uint32_t *)(psVar1 + -6),*(uint32_t *)(psVar1 + -10),
                     (char)psVar1[-0xc],(long)*psVar1,*(uint64_t *)(psVar1 + -4));
        }
        lVar14 = lVar14 + 0x20;
        lVar15 = lVar15 + 4;
      } while (lVar14 != 0x180);
    }
    puVar9 = *(uint32_t **)(*(long *)(param_1 + 0x540) + 0x168);
    puVar4 = *(uint32_t **)(*(long *)(param_1 + 0x540) + 0x170);
    if (puVar9 == (uint32_t *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = *puVar9;
    }
    glBindBuffer(0x8892,uVar10);
    if (puVar4 == (uint32_t *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = *puVar4;
    }
    glBindBuffer(0x8893,uVar10);
  }
  if (*(long *)(lVar7 + 0x28) == local_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @001218b4  size=1624 */

void GLRenderer_drawPixels
               (long param_1,int param_2,int param_3,int param_4,int param_5,uint64_t param_6)

{
  long lVar1;
  uint32_t uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  unsigned long uVar7;
  uint32_t *puVar8;
  uint32_t uVar9;
  int iVar10;
  uint64_t uVar11;
  long lVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint64_t local_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  long local_88;
  
  /* stack canary setup (elided) */
  local_88 = *(long *)(lVar3 + 0x28);
  if (((param_5 == 0x1400) || (param_5 == 0x8367)) || (param_5 == 0x8035)) {
    param_5 = 0x1401;
  }
  iVar10 = 0;
  if (0x8048 < param_4) {
    if (param_4 == 0x8049) {
      glTexParameteri(0xde1,0x8e42,0x1903);
      glTexParameteri(0xde1,0x8e43,0x1903);
      glTexParameteri(0xde1,0x8e44,0x1903);
      uVar11 = 0x1903;
      goto LAB_00121ab0;
    }
    if (param_4 == 0x80e0) {
      iVar10 = 0x8051;
      param_4 = 0x1907;
    }
    else if (param_4 == 0x80e1) {
      if (param_5 == 0x8365) {
        iVar10 = 0x8056;
        param_5 = 0x8033;
        param_4 = 0x1908;
      }
      else if (param_5 == 0x8366) {
        iVar10 = 0x8057;
        param_5 = 0x8034;
        param_4 = 0x1908;
      }
      else {
        iVar10 = 0;
        param_4 = 0x80e1;
      }
    }
    goto switchD_0012195c_caseD_1902;
  }
  switch(param_4) {
  case 0x1906:
    glTexParameteri(0xde1,0x8e42,0);
    glTexParameteri(0xde1,0x8e43,0);
    glTexParameteri(0xde1,0x8e44,0);
    uVar11 = 0x1903;
    goto LAB_00121ab0;
  case 0x1907:
    param_4 = 0x1907;
    if (param_5 == 0x8363) {
      iVar10 = 0x8d62;
      param_5 = 0x8363;
    }
    else {
      iVar10 = 0;
    }
    break;
  case 0x1908:
    param_4 = 0x8d99;
    if (param_5 != 0x1403) {
      param_4 = 0x1908;
    }
    iVar10 = 0x8d76;
    if (param_5 != 0x1403) {
      iVar10 = 0;
    }
    break;
  case 0x1909:
    glTexParameteri(0xde1,0x8e42,0x1903);
    glTexParameteri(0xde1,0x8e43,0x1903);
    glTexParameteri(0xde1,0x8e44,0x1903);
    uVar11 = 1;
LAB_00121ab0:
    param_4 = 0x1903;
    glTexParameteri(0xde1,0x8e45,uVar11);
    iVar10 = 0x8229;
  }
switchD_0012195c_caseD_1902:
  iVar4 = FUN_00123074(iVar10);
  iVar5 = FUN_00123074(param_4);
  if ((iVar4 != iVar5) || (iVar10 == 0)) {
    switch(param_4) {
    case 0x1903:
    case 0x1904:
    case 0x1905:
    case 0x1906:
    case 0x1909:
switchD_00121b2c_caseD_1903:
      iVar10 = 0x8229;
      param_4 = 0x1903;
      break;
    case 0x1907:
      iVar10 = 0x8051;
      param_4 = 0x1907;
      break;
    case 0x1908:
switchD_00121b2c_caseD_1908:
      iVar10 = 0x8058;
      break;
    case 0x190a:
      iVar10 = 0x822b;
      param_4 = 0x8227;
      break;
    default:
      if (param_4 == 0x80e1) goto switchD_00121b2c_caseD_1908;
      if (param_4 == 0x8049) goto switchD_00121b2c_caseD_1903;
      iVar10 = 0;
    }
    if ((iVar4 == 3) && (iVar5 == 4)) {
      glTexParameteri(0xde1,0x8e45,1);
    }
    else if ((iVar4 == 1) && (1 < iVar5)) {
      param_4 = 0x1903;
      iVar4 = 0x8229;
      goto LAB_00121bc4;
    }
  }
  iVar4 = param_4;
  if (param_4 != 0x80e1) {
    iVar4 = iVar10;
  }
LAB_00121bc4:
  FUN_001215fc(param_1);
  lVar12 = *(long *)(param_1 + 0x8d8);
  glBindTexture(0xde1,*(uint32_t *)(lVar12 + 0x18));
  glTexImage2D(0xde1,0,iVar4,param_2,param_3,0,param_4,param_5,param_6);
  ArrayBuffer_rewind(lVar12 + 0x20);
  ArrayBuffer_rewind(lVar12 + 0x38);
  fVar15 = **(float **)(param_1 + 0x8d8);
  fVar16 = (*(float **)(param_1 + 0x8d8))[1];
  fVar13 = fVar15 / (float)(int)*(short *)(param_1 + 4);
  fVar14 = fVar16 / (float)(int)*(short *)(param_1 + 6);
  fVar15 = (fVar15 + *(float *)(lVar12 + 0x10) * (float)param_2) /
           (float)(int)*(short *)(param_1 + 4);
  fVar16 = (fVar16 + *(float *)(lVar12 + 0x14) * (float)param_3) /
           (float)(int)*(short *)(param_1 + 6);
  fVar13 = fVar13 + fVar13 + -1.0;
  fVar14 = fVar14 + fVar14 + -1.0;
  fVar15 = fVar15 + fVar15 + -1.0;
  fVar16 = fVar16 + fVar16 + -1.0;
  ArrayBuffer_putFloat4(fVar13,fVar14,0,0x3f800000,lVar12 + 0x20);
  ArrayBuffer_putFloat4(0,0,0,0x3f800000,lVar12 + 0x38);
  ArrayBuffer_putFloat4(fVar13,fVar16,0,0x3f800000,lVar12 + 0x20);
  ArrayBuffer_putFloat4(0,0x3f800000,0,0x3f800000,lVar12 + 0x38);
  ArrayBuffer_putFloat4(fVar15,fVar14,0,0x3f800000,lVar12 + 0x20);
  ArrayBuffer_putFloat4(0x3f800000,0,0,0x3f800000,lVar12 + 0x38);
  ArrayBuffer_putFloat4(fVar15,fVar16,0,0x3f800000,lVar12 + 0x20);
  ArrayBuffer_putFloat4(0x3f800000,0x3f800000,0,0x3f800000,lVar12 + 0x38);
  uStack_98 = 0;
  local_90 = 0;
  local_a0 = (unsigned long)CONCAT15(1,(uint32_t)*(uint8_t *)(param_1 + 0x44));
  lVar6 = FUN_0011f510(param_1,&local_a0);
  uVar2 = *(uint32_t *)(lVar6 + 8);
  iVar10 = *(int *)(lVar12 + 0x20);
  uVar11 = *(uint64_t *)(lVar12 + 0x30);
  glBindBuffer(0x8892,*(uint32_t *)(param_1 + 0x1c));
  glBufferData(0x8892,(long)iVar10,uVar11,0x88e8);
  if ((-1 < (int)uVar2) && (lVar1 = param_1 + (unsigned long)uVar2, *(char *)(lVar1 + 0x8f0) == '\0')) {
    glEnableVertexAttribArray(uVar2);
    *(uint8_t *)(lVar1 + 0x8f0) = 1;
  }
  glVertexAttribPointer((unsigned long)uVar2,4,0x1406,0,0,0);
  uVar2 = *(uint32_t *)(lVar6 + 0x14);
  iVar10 = *(int *)(lVar12 + 0x38);
  uVar11 = *(uint64_t *)(lVar12 + 0x48);
  glBindBuffer(0x8892,*(uint32_t *)(param_1 + 0x24));
  glBufferData(0x8892,(long)iVar10,uVar11,0x88e8);
  if ((-1 < (int)uVar2) && (lVar12 = param_1 + (unsigned long)uVar2, *(char *)(lVar12 + 0x8f0) == '\0')) {
    glEnableVertexAttribArray(uVar2);
    *(uint8_t *)(lVar12 + 0x8f0) = 1;
  }
  glVertexAttribPointer((unsigned long)uVar2,4,0x1406,0,0,0);
  glBindBuffer(0x8892,*(uint32_t *)(param_1 + 0x20));
  uVar7 = (unsigned long)*(uint32_t *)(lVar6 + 0xc);
  if ((-1 < (int)*(uint32_t *)(lVar6 + 0xc)) && (*(char *)(param_1 + uVar7 + 0x8f0) != '\0')) {
    glDisableVertexAttribArray(0);
    *(uint8_t *)(param_1 + uVar7 + 0x8f0) = 0;
    uVar7 = (unsigned long)*(uint32_t *)(lVar6 + 0xc);
  }
  glVertexAttrib4fv(uVar7,param_1 + 0xac);
  glDrawArrays(5,0,4);
  GLRenderer_disableUnusedVertexAttributes(param_1);
  puVar8 = (uint32_t *)GLTexture_getBound(0xde1);
  if (puVar8 == (uint32_t *)0x0) {
    uVar9 = 0;
  }
  else {
    uVar9 = *puVar8;
  }
  glBindTexture(0xde1,uVar9);
  if (*(long *)(lVar3 + 0x28) != local_88) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0011fa4c  size=60 */

void GLRenderer_enableVertexAttribute(long param_1,uint32_t param_2)

{
  if ((-1 < (int)param_2) && (*(char *)(param_1 + (unsigned long)param_2 + 0x8f0) == '\0')) {
    glEnableVertexAttribArray(param_2);
    *(uint8_t *)(param_1 + (unsigned long)param_2 + 0x8f0) = 1;
  }
  return;
}


/* @0011fb3c  size=64 */

void GLRenderer_endImmediate(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x898);
  if (lVar1 != 0) {
    *(uint64_t *)(param_1 + 0x898) = 0;
    *(uint32_t *)(param_1 + 0x604) = 0;
    *(uint32_t *)(param_1 + 0x61c) = 0;
    *(uint32_t *)(param_1 + 0x634) = 0;
    *(uint32_t *)(param_1 + 0x64c) = 0;
    *(uint32_t *)(param_1 + 0x664) = 0;
    *(uint32_t *)(param_1 + 0x67c) = 0;
    *(uint32_t *)(param_1 + 0x694) = 0;
    *(uint32_t *)(param_1 + 0x6ac) = 0;
    *(uint32_t *)(param_1 + 0x6c4) = 0;
    *(uint32_t *)(lVar1 + 8) = *(uint32_t *)(param_1 + 0x6f4);
    *(uint32_t *)(param_1 + 0x6dc) = 0;
  }
  return;
}


/* @00122e74  size=324 */

void * GLRenderer_getCompressedTexImage(uint64_t param_1,int param_2,uint32_t param_3,uint32_t *param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  void *__ptr;
  void *pvVar5;
  long lVar6;
  int iVar7;
  
  /* stack canary setup (elided) */
  lVar6 = *(long *)(lVar3 + 0x28);
  iVar7 = 0xde1;
  if (((param_2 != 0xde0) && (param_2 != 0x84f5)) && (iVar7 = param_2, param_2 == 0x8c18)) {
    iVar7 = 0x8c1a;
  }
  lVar4 = GLTexture_getBound(iVar7);
  if (lVar4 == 0) {
    pvVar5 = (void *)0x0;
    *param_4 = 0;
  }
  else {
    iVar1 = ((int)*(short *)(lVar4 + 0xc) >> (param_3 & 0x1f)) >> 2;
    iVar2 = ((int)*(short *)(lVar4 + 0xe) >> (param_3 & 0x1f)) >> 2;
    if (iVar1 < 2) {
      iVar1 = 1;
    }
    if (iVar2 < 2) {
      iVar2 = 1;
    }
    *param_4 = (uint32_t)(iVar1 * iVar2 * 0x10) >> (*(uint32_t *)(lVar4 + 8) >> 1 == 0x41f8);
    __ptr = (void *)GLRenderer_getTexImage(param_1, iVar7, 0, 0, 0, 0);
    pvVar5 = malloc((long)(int)*param_4);
    compressTexImage2D(*(uint32_t *)(lVar4 + 8),(long)*(short *)(lVar4 + 0xc),
                       (long)*(short *)(lVar4 + 0xe),__ptr,pvVar5);
    free(__ptr);
  }
  if (*(long *)(lVar3 + 0x28) != lVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar5;
}


/* @0011fbac  size=120 */

uint64_t GLRenderer_getCurrentMatrix(long param_1)

{
  uint32_t *puVar1;
  int iVar2;
  
  param_1 = param_1 + (unsigned long)*(uint32_t *)(param_1 + 0x8d0) * 0x10;
  iVar2 = *(int *)(param_1 + 0x8a0);
  if (iVar2 == 0) {
    puVar1 = malloc(0x40);
    *(uint64_t *)(puVar1 + 3) = 0;
    *(uint64_t *)(puVar1 + 1) = 0;
    *(uint64_t *)(puVar1 + 6) = 0;
    *(uint64_t *)(puVar1 + 8) = 0;
    *(uint64_t *)(puVar1 + 0xd) = 0;
    *(uint64_t *)(puVar1 + 0xb) = 0;
    *puVar1 = 0x3f800000;
    puVar1[5] = 0x3f800000;
    puVar1[10] = 0x3f800000;
    puVar1[0xf] = 0x3f800000;
    ArrayList_add(param_1 + 0x8a0,puVar1);
    iVar2 = *(int *)(param_1 + 0x8a0);
  }
  return *(uint64_t *)(*(long *)(param_1 + 0x8a8) + (long)(iVar2 + -1) * 8);
}


/* @0011fb7c  size=48 */

uint32_t * GLRenderer_getMatrixFromStack(long param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + (long)param_2 * 0x10 + 0x8a0);
  if (0 < iVar1) {
    return *(uint32_t **)
            (*(long *)(param_1 + (long)param_2 * 0x10 + 0x8a8) + (unsigned long)(iVar1 - 1) * 8);
  }
  return &DAT_00144118;
}


/* @001210a8  size=1308 */

uint32_t GLRenderer_getParamsv(unsigned long param_1,uint32_t param_2,int param_3,uint32_t *param_4)

{
  long lVar1;
  uint32_t uVar2;
  unsigned long uVar3;
  uint8_t uVar4;
  uint32_t uVar5;
  uint64_t *puVar6;
  long lVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  uint64_t uVar10;
  uint64_t uVar11;
  uint64_t uVar12;
  uint64_t uVar13;
  uint64_t uVar14;
  uint32_t uStack_50;
  uint8_t auStack_4c [4];
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar1 + 0x28);
  uVar5 = 4;
  if (param_3 == 0x8b56) {
    uVar5 = 1;
  }
  uVar3 = param_1;
  if (0xd30 < (int)param_2) {
    if (0x821c < (int)param_2) {
      if ((int)param_2 < 0x8861) {
        if (0x84f7 < (int)param_2) {
          if (param_2 != 0x84f8) {
            uVar2 = 0x8642;
            goto LAB_0012129c;
          }
          goto switchD_00121150_caseD_d33;
        }
        if (param_2 == 0x821d) {
          if (param_4 != (uint32_t *)0x0) {
            uVar3 = getGLExtensions(param_4);
          }
          goto LAB_0012157c;
        }
        uVar2 = 0x84e2;
      }
      else {
        if (0x891b < (int)param_2) {
          if (param_2 == 0x891c) {
            if (param_4 != (uint32_t *)0x0) {
              *param_4 = (uint32_t)*(uint8_t *)(param_1 + 0x390);
            }
            goto LAB_0012157c;
          }
          if (param_2 == 0x9126) {
            if (param_4 != (uint32_t *)0x0) {
              *param_4 = 3;
            }
            goto LAB_0012157c;
          }
          goto switchD_00121114_caseD_b01;
        }
        if (param_2 == 0x8861) goto switchD_00121114_caseD_b10;
        uVar2 = 0x8871;
      }
      if (param_2 == uVar2) {
        if (param_4 != (uint32_t *)0x0) {
          *param_4 = 8;
        }
        goto LAB_0012157c;
      }
      goto switchD_00121114_caseD_b01;
    }
    switch(param_2) {
    case 0xd31:
      if (param_4 != (uint32_t *)0x0) {
        *param_4 = 4;
      }
      break;
    case 0xd32:
      if (param_4 != (uint32_t *)0x0) {
        *param_4 = 6;
      }
      break;
    case 0xd33:
switchD_00121150_caseD_d33:
      if (param_4 != (uint32_t *)0x0) {
        *param_4 = 0x1000;
      }
      break;
    case 0xd34:
    case 0xd35:
    case 0xd37:
      goto switchD_00121114_caseD_b01;
    case 0xd36:
      if (param_4 != (uint32_t *)0x0) {
        *param_4 = 0x20;
      }
      break;
    case 0xd38:
    case 0xd39:
      if (param_4 != (uint32_t *)0x0) {
        *param_4 = 2;
      }
      break;
    default:
      if (param_2 - 0x821b < 2) {
        if (param_4 != (uint32_t *)0x0) {
          uVar2 = sscanf("3.3","%d.%d",&uStack_50,auStack_4c);
          *param_4 = (&uStack_50)[param_2 - 0x821b];
          uVar3 = (unsigned long)uVar2;
        }
        break;
      }
      uVar2 = 0x2a02;
LAB_0012129c:
      if (param_2 == uVar2) goto switchD_00121114_caseD_b10;
switchD_00121114_caseD_b01:
      if ((param_2 & 0xfffffff8) == 0x4000) {
        if (param_4 != (uint32_t *)0x0) {
          if ((int)param_2 < 0x4004) {
            uVar4 = *(uint8_t *)(param_1 + (unsigned long)(param_2 - 0x4000) * 0x58 + 0x710);
          }
          else {
            uVar4 = 0;
          }
LAB_00121574:
          *(uint8_t *)param_4 = uVar4;
        }
        goto LAB_00121578;
      }
      uVar2 = param_2;
      if ((int)param_2 < 0xc23) {
        if ((int)param_2 < 0xc10) {
          if (param_2 == 0xb70) goto switchD_00121114_caseD_b12;
          if (param_2 == 0xba2) goto LAB_001215b8;
        }
        else if ((param_2 == 0xc10) || (param_2 == 0xc22)) {
LAB_001215b8:
          uVar5 = 0x10;
        }
      }
      else if (param_2 - 0x846d < 2) {
switchD_00121114_caseD_b12:
        param_2 = uVar2;
        uVar5 = 8;
      }
      else {
        if (param_2 == 0x8005) goto LAB_001215b8;
        if (param_2 == 0xc23) {
          uVar5 = 4;
        }
      }
      if (param_3 == 0x1404) {
        if (param_4 == (uint32_t *)0x0) break;
        glGetIntegerv(param_2,param_4); uVar3 = 0;
      }
      else if (param_3 == 0x8b56) {
        if (param_4 == (uint32_t *)0x0) break;
        glGetBooleanv(param_2,param_4); uVar3 = 0;
      }
      else if (param_3 == 0x1406) {
        if (param_4 == (uint32_t *)0x0) break;
        glGetFloatv(param_2,param_4); uVar3 = 0;
      }
      else if (param_4 == (uint32_t *)0x0) break;
      if (((param_2 == 0x8caa) || (param_2 == 0x8ca6)) &&
         ((*param_4 == *(uint32_t *)(param_1 + 8) || (*param_4 == *(uint32_t *)(param_1 + 0xc))))) {
LAB_00121568:
        *param_4 = 0;
      }
    }
    goto LAB_0012157c;
  }
  uVar2 = 0x846d;
  switch(param_2) {
  case 0xb00:
    if (param_4 == (uint32_t *)0x0) {
LAB_00121408:
      uVar5 = 0x10;
      break;
    }
    uVar9 = *(uint64_t *)(param_1 + 0xb4);
    uVar8 = *(uint64_t *)(param_1 + 0xac);
    goto LAB_001213fc;
  case 0xb01:
  case 0xb04:
  case 0xb05:
  case 0xb06:
  case 0xb07:
  case 0xb08:
  case 0xb09:
  case 0xb0a:
  case 0xb0b:
  case 0xb0c:
  case 0xb0d:
  case 0xb0e:
  case 0xb0f:
  case 0xb11:
  case 0xb13:
  case 0xb14:
  case 0xb15:
  case 0xb16:
  case 0xb17:
  case 0xb18:
  case 0xb19:
  case 0xb1a:
  case 0xb1b:
  case 0xb1c:
  case 0xb1d:
  case 0xb1e:
  case 0xb1f:
  case 0xb21:
  case 0xb22:
  case 0xb23:
  case 0xb25:
  case 0xb26:
  case 0xb27:
  case 0xb28:
  case 0xb29:
  case 0xb2a:
  case 0xb2b:
  case 0xb2c:
  case 0xb2d:
  case 0xb2e:
  case 0xb2f:
  case 0xb30:
  case 0xb31:
  case 0xb32:
  case 0xb33:
  case 0xb34:
  case 0xb35:
  case 0xb36:
  case 0xb37:
  case 0xb38:
  case 0xb39:
  case 0xb3a:
  case 0xb3b:
  case 0xb3c:
  case 0xb3d:
  case 0xb3e:
  case 0xb3f:
  case 0xb40:
  case 0xb41:
  case 0xb43:
  case 0xb44:
  case 0xb45:
  case 0xb46:
  case 0xb47:
  case 0xb48:
  case 0xb49:
  case 0xb4a:
  case 0xb4b:
  case 0xb4c:
  case 0xb4d:
  case 0xb4e:
  case 0xb4f:
  case 0xb51:
  case 0xb52:
  case 0xb53:
  case 0xb55:
  case 0xb56:
  case 0xb58:
  case 0xb59:
  case 0xb5a:
  case 0xb5b:
  case 0xb5c:
  case 0xb5d:
  case 0xb5e:
  case 0xb5f:
  case 0xb61:
  case 0xb67:
  case 0xb68:
  case 0xb69:
  case 0xb6a:
  case 0xb6b:
  case 0xb6c:
  case 0xb6d:
  case 0xb6e:
  case 0xb6f:
  case 0xb70:
  case 0xb71:
  case 0xb72:
  case 0xb73:
  case 0xb74:
  case 0xb75:
  case 0xb76:
  case 0xb77:
  case 0xb78:
  case 0xb79:
  case 0xb7a:
  case 0xb7b:
  case 0xb7c:
  case 0xb7d:
  case 0xb7e:
  case 0xb7f:
  case 0xb80:
  case 0xb81:
  case 0xb82:
  case 0xb83:
  case 0xb84:
  case 0xb85:
  case 0xb86:
  case 0xb87:
  case 0xb88:
  case 0xb89:
  case 0xb8a:
  case 0xb8b:
  case 0xb8c:
  case 0xb8d:
  case 0xb8e:
  case 0xb8f:
  case 0xb90:
  case 0xb91:
  case 0xb92:
  case 0xb93:
  case 0xb94:
  case 0xb95:
  case 0xb96:
  case 0xb97:
  case 0xb98:
  case 0xb99:
  case 0xb9a:
  case 0xb9b:
  case 0xb9c:
  case 0xb9d:
  case 0xb9e:
  case 0xb9f:
  case 0xba0:
  case 0xba2:
  case 0xba3:
  case 0xba4:
  case 0xba5:
  case 0xba9:
  case 0xbaa:
  case 0xbab:
  case 0xbac:
  case 0xbad:
  case 0xbae:
  case 0xbaf:
  case 0xbb0:
  case 0xbb1:
  case 0xbb2:
  case 0xbb3:
  case 0xbb4:
  case 0xbb5:
  case 0xbb6:
  case 2999:
  case 3000:
  case 0xbb9:
  case 0xbba:
  case 0xbbb:
  case 0xbbc:
  case 0xbbd:
  case 0xbbe:
  case 0xbbf:
    goto switchD_00121114_caseD_b01;
  case 0xb02:
    if (param_4 == (uint32_t *)0x0) {
      uVar5 = 0xc;
    }
    else {
      uVar8 = *(uint64_t *)(param_1 + 0xbc);
      uVar5 = 0xc;
      param_4[2] = *(uint32_t *)(param_1 + 0xc4);
      *(uint64_t *)param_4 = uVar8;
    }
    break;
  case 0xb03:
    if (param_4 == (uint32_t *)0x0) goto LAB_00121408;
    lVar7 = param_1 + (unsigned long)*(uint8_t *)(param_1 + 0x399) * 0x10;
    uVar9 = *(uint64_t *)(lVar7 + 0xd0);
    uVar8 = *(uint64_t *)(lVar7 + 200);
    goto LAB_001213fc;
  case 0xb10:
  case 0xb20:
  case 0xb24:
  case 0xb42:
  case 0xba1:
switchD_00121114_caseD_b10:
    if (param_4 != (uint32_t *)0x0) {
      *(uint8_t *)param_4 = 0;
    }
    goto LAB_00121578;
  case 0xb12:
    goto switchD_00121114_caseD_b12;
  case 0xb50:
    if (param_4 == (uint32_t *)0x0) goto LAB_00121578;
    uVar4 = *(uint8_t *)(param_1 + 0x44);
    goto LAB_00121574;
  case 0xb54:
    if (param_4 != (uint32_t *)0x0) {
      *param_4 = *(uint32_t *)(param_1 + 0x38c);
    }
    break;
  case 0xb57:
    if (param_4 != (uint32_t *)0x0) {
      uVar4 = *(uint8_t *)(param_1 + 0x4c);
      goto LAB_00121574;
    }
    goto LAB_00121578;
  case 0xb60:
    if (param_4 != (uint32_t *)0x0) {
      uVar4 = *(uint8_t *)(param_1 + 0x84);
      goto LAB_00121574;
    }
    goto LAB_00121578;
  case 0xb62:
    if (param_4 != (uint32_t *)0x0) {
      *param_4 = *(uint32_t *)(param_1 + 0x74);
    }
    break;
  case 0xb63:
    if (param_4 != (uint32_t *)0x0) {
      *param_4 = *(uint32_t *)(param_1 + 0x78);
    }
    break;
  case 0xb64:
    if (param_4 != (uint32_t *)0x0) {
      *param_4 = *(uint32_t *)(param_1 + 0x7c);
    }
    break;
  case 0xb65:
    if (param_4 != (uint32_t *)0x0) {
      uVar2 = NEON_ucvtf(*(uint32_t *)(param_1 + 0x80));
      *param_4 = uVar2;
    }
    break;
  case 0xb66:
    if (param_4 == (uint32_t *)0x0) goto LAB_00121408;
    uVar9 = *(uint64_t *)(param_1 + 0x6c);
    uVar8 = *(uint64_t *)(param_1 + 100);
LAB_001213fc:
    *(uint64_t *)(param_4 + 2) = uVar9;
    *(uint64_t *)param_4 = uVar8;
    uVar5 = 0x10;
    break;
  case 0xba6:
    if (param_4 == (uint32_t *)0x0) {
LAB_0012142c:
      uVar5 = 0x40;
      break;
    }
    uVar2 = *(int *)(param_1 + 0x8a0) - 1;
    if (*(int *)(param_1 + 0x8a0) < 1) goto LAB_0012144c;
    lVar7 = *(long *)(param_1 + 0x8a8);
LAB_00121424:
    puVar6 = *(uint64_t **)(lVar7 + (unsigned long)uVar2 * 8);
    goto LAB_00121454;
  case 0xba7:
    if (param_4 == (uint32_t *)0x0) goto LAB_0012142c;
    uVar2 = *(int *)(param_1 + 0x8b0) - 1;
    if (0 < *(int *)(param_1 + 0x8b0)) {
      lVar7 = *(long *)(param_1 + 0x8b8);
      goto LAB_00121424;
    }
    goto LAB_0012144c;
  case 0xba8:
    if (param_4 == (uint32_t *)0x0) goto LAB_0012142c;
    uVar2 = *(int *)(param_1 + 0x8c0) - 1;
    if (0 < *(int *)(param_1 + 0x8c0)) {
      lVar7 = *(long *)(param_1 + 0x8c8);
      goto LAB_00121424;
    }
LAB_0012144c:
    puVar6 = (uint64_t *)&DAT_00144118;
LAB_00121454:
    uVar10 = puVar6[4];
    uVar9 = puVar6[7];
    uVar8 = puVar6[6];
    uVar14 = puVar6[1];
    uVar13 = *puVar6;
    uVar12 = puVar6[3];
    uVar11 = puVar6[2];
    uVar5 = 0x40;
    *(uint64_t *)(param_4 + 10) = puVar6[5];
    *(uint64_t *)(param_4 + 8) = uVar10;
    *(uint64_t *)(param_4 + 0xe) = uVar9;
    *(uint64_t *)(param_4 + 0xc) = uVar8;
    *(uint64_t *)(param_4 + 2) = uVar14;
    *(uint64_t *)param_4 = uVar13;
    *(uint64_t *)(param_4 + 6) = uVar12;
    *(uint64_t *)(param_4 + 4) = uVar11;
    break;
  case 0xbc0:
    if (param_4 != (uint32_t *)0x0) {
      uVar4 = *(uint8_t *)(param_1 + 0x58);
      goto LAB_00121574;
    }
LAB_00121578:
    uVar5 = 1;
    break;
  case 0xbc1:
    if (param_4 != (uint32_t *)0x0) {
      *param_4 = *(uint32_t *)(param_1 + 0x5c);
    }
    break;
  case 0xbc2:
    if (param_4 != (uint32_t *)0x0) {
      *param_4 = *(uint32_t *)(param_1 + 0x60);
    }
    break;
  default:
    if (param_2 != 0xc00) {
      if (param_2 == 0xc33) goto switchD_00121114_caseD_b10;
      goto switchD_00121114_caseD_b01;
    }
    if (param_4 == (uint32_t *)0x0) break;
    goto LAB_00121568;
  }
LAB_0012157c:
  if (*(long *)(lVar1 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return uVar5;
}


/* @00121ff0  size=248 */

void GLRenderer_getSamplerParameter
               (uint64_t param_1,uint32_t param_2,int param_3,float *param_4)

{
  long lVar1;
  int local_2c;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  if (param_3 < 0x813a) {
    if (3 < param_3 - 0x2800U) {
      if (param_3 == 0x1004) goto LAB_00122098;
      if (param_3 != 0x8072) {
LAB_001220c8:
        __android_log_print(3,"System.out","gladio:getSamplerParameter: unimplemented pname %x");
        goto LAB_001220a8;
      }
    }
LAB_0012206c:
    glGetSamplerParameteriv(param_2,param_3,&local_2c);
    *param_4 = (float)local_2c;
  }
  else {
    if (1 < param_3 - 0x813aU) {
      if (param_3 - 0x884cU < 2) goto LAB_0012206c;
      if (param_3 != 0x84fe) goto LAB_001220c8;
    }
LAB_00122098:
    glGetSamplerParameterfv(param_2,param_3,param_4);
  }
LAB_001220a8:
  if (*(long *)(lVar1 + 0x28) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @001226b4  size=724 */

void * GLRenderer_getTexImage
                 (long param_1,int param_2,uint64_t param_3,int param_4,int param_5,int *param_6)

{
  uint32_t uVar1;
  uint32_t uVar2;
  long lVar3;
  uint32_t *puVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint32_t local_5c;
  long local_58;
  
  /* stack canary setup (elided) */
  local_58 = *(long *)(lVar3 + 0x28);
  iVar9 = 0xde1;
  if (((param_2 != 0xde0) && (param_2 != 0x84f5)) && (iVar9 = param_2, param_2 == 0x8c18)) {
    iVar9 = 0x8c1a;
  }
  puVar4 = (uint32_t *)GLTexture_getBound(iVar9);
  if (puVar4 == (uint32_t *)0x0) {
    pvVar5 = (void *)0x0;
    *param_6 = 0;
    goto LAB_00122954;
  }
  iVar6 = 0;
  if (param_4 < 0x80e1) {
    switch(param_4) {
    case 0x1903:
    case 0x1904:
    case 0x1905:
    case 0x1906:
    case 0x1909:
      goto switchD_00122768_caseD_8d94;
    case 0x1907:
switchD_00122768_caseD_8d98:
      iVar6 = 3;
      break;
    case 0x1908:
      goto switchD_00122768_caseD_8d99;
    case 0x190a:
switchD_0012279c_caseD_190a:
      iVar6 = 2;
      break;
    default:
      if (param_4 == 0x80e0) goto switchD_00122768_caseD_8d98;
    }
  }
  else {
    switch(param_4) {
    case 0x8d94:
switchD_00122768_caseD_8d94:
      iVar6 = 1;
      break;
    case 0x8d95:
    case 0x8d96:
    case 0x8d97:
      break;
    case 0x8d98:
    case 0x8d9a:
      goto switchD_00122768_caseD_8d98;
    case 0x8d99:
    case 0x8d9b:
switchD_00122768_caseD_8d99:
      iVar6 = 4;
      break;
    default:
      if (param_4 - 0x8227U < 2) goto switchD_0012279c_caseD_190a;
      if (param_4 == 0x80e1) goto switchD_00122768_caseD_8d99;
    }
  }
  iVar7 = 0;
  if (param_5 < 0x8035) {
    uVar1 = param_5 - 0x1400;
    if (uVar1 < 0xc) {
      uVar2 = 1 << (unsigned long)(uVar1 & 0x1f);
      if ((uVar2 & 0x70) == 0) {
        if ((uVar2 & 0x80c) == 0) {
          if ((1 << (unsigned long)(uVar1 & 0x1f) & 3U) == 0) goto LAB_00122888;
          goto LAB_001228bc;
        }
        iVar7 = 2;
      }
      else {
        iVar7 = 4;
      }
    }
    else {
LAB_00122888:
      if (1 < param_5 - 0x8033U) {
        iVar8 = 0x8032;
        goto LAB_001228b0;
      }
LAB_00122898:
      iVar7 = 2;
      iVar6 = 1;
    }
  }
  else {
    if (param_5 < 0x8363) {
      if (1 < param_5 - 0x8035U) {
        iVar8 = 0x8362;
LAB_001228b0:
        if (param_5 == iVar8) {
          iVar6 = 1;
LAB_001228bc:
          iVar7 = 1;
        }
        goto LAB_001228c0;
      }
    }
    else {
      if (param_5 - 0x8363U < 4) goto LAB_00122898;
      if (param_5 != 0x8367) goto LAB_001228c0;
    }
    iVar7 = 4;
    iVar6 = 1;
  }
LAB_001228c0:
  iVar7 = (int)*(short *)((long)puVar4 + 0xe) * (int)*(short *)(puVar4 + 3) * iVar6 * iVar7;
  *param_6 = iVar7;
  if (iVar7 == 0) {
    pvVar5 = (void *)0x0;
  }
  else {
    glGenFramebuffers(1,&local_5c);
    glBindFramebuffer(0x8d40,local_5c);
    glFramebufferTexture2D(0x8d40,0x8ce0,iVar9,*puVar4,0);
    pvVar5 = malloc((long)*param_6);
    GLRenderer_readPixels
              (param_1,0,0,(long)*(short *)(puVar4 + 3),(long)*(short *)((long)puVar4 + 0xe),param_4
               ,param_5,pvVar5);
    glBindFramebuffer(0x8d40,*(uint32_t *)(param_1 + 0x588));
    glDeleteFramebuffers(1,&local_5c);
  }
LAB_00122954:
  if (*(long *)(lVar3 + 0x28) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar5;
}


/* @0012239c  size=792 */

void GLRenderer_getTexParameter
               (uint64_t param_1,uint32_t param_2,uint32_t param_3,int param_4,float *param_5)

{
  int iVar1;
  int iVar2;
  short sVar3;
  long lVar4;
  long lVar5;
  uint32_t uVar6;
  float fVar7;
  int local_4c;
  long local_48;
  
  /* stack canary setup (elided) */
  local_48 = *(long *)(lVar4 + 0x28);
  lVar5 = GLTexture_getBound(param_2);
  *param_5 = 0.0;
  if (lVar5 == 0) goto LAB_00122614;
  if (0x82de < param_4) {
    if (0x8c0f < param_4) {
      if (param_4 < 0x8e42) {
        if ((param_4 - 0x8c10U < 7) && ((1 << (unsigned long)(param_4 - 0x8c10U & 0x1f) & 0x4fU) != 0)) {
          *param_5 = 5126.0;
          goto LAB_00122614;
        }
      }
      else if (param_4 < 0x90c7) {
        if (param_4 - 0x8e42U < 4) goto LAB_001225f8;
      }
      else if (((param_4 == 0x90c7) || (param_4 == 0x90ea)) || (param_4 == 0x912f))
      goto LAB_001225f8;
      goto switchD_0012241c_caseD_8060;
    }
    if (0x86a0 < param_4) {
      if (param_4 - 0x884cU < 2) {
LAB_001225f8:
        glGetTexParameteriv(param_2,param_4,&local_4c);
        goto LAB_0012260c;
      }
      if (param_4 != 0x86a1) {
        if (param_4 == 0x884a) goto switchD_0012241c_caseD_8071;
        goto switchD_0012241c_caseD_8060;
      }
      fVar7 = 1.0;
      if (*(uint32_t *)(lVar5 + 8) >> 2 != 0x20fc) {
        fVar7 = 0.0;
      }
      goto LAB_00122610;
    }
    if (param_4 == 0x82df) goto LAB_001225f8;
    if (param_4 == 0x84fe) goto switchD_0012241c_caseD_8072;
    if (param_4 != 0x86a0) goto switchD_0012241c_caseD_8060;
    if (*(uint32_t *)(lVar5 + 8) >> 2 == 0x20fc) {
      iVar1 = ((int)*(short *)(lVar5 + 0xc) >> (param_3 & 0x1f)) >> 2;
      iVar2 = ((int)*(short *)(lVar5 + 0xe) >> (param_3 & 0x1f)) >> 2;
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      if (iVar2 < 2) {
        iVar2 = 1;
      }
      uVar6 = (uint32_t)(iVar1 * iVar2 * 0x10) >> (*(uint32_t *)(lVar5 + 8) >> 1 == 0x41f8);
    }
    else {
      uVar6 = (int)*(short *)(lVar5 + 0xc) * (int)*(short *)(lVar5 + 0xe) * 4;
    }
    goto LAB_001226a8;
  }
  if (0x805b < param_4) {
    switch(param_4) {
    case 0x805c:
    case 0x805d:
    case 0x805e:
    case 0x805f:
      *param_5 = 8.0;
      break;
    case 0x8067:
      *param_5 = 1.0;
      break;
    case 0x8071:
switchD_0012241c_caseD_8071:
      *param_5 = 0.0;
      break;
    case 0x8072:
switchD_0012241c_caseD_8072:
      glGetTexParameterfv(param_2,param_4,param_5);
      break;
    default:
      if (param_4 - 0x813aU < 2) goto switchD_0012241c_caseD_8072;
      if (param_4 - 0x813cU < 2) goto LAB_001225f8;
    case 0x8060:
    case 0x8061:
    case 0x8062:
    case 0x8063:
    case 0x8064:
    case 0x8065:
    case 0x8066:
    case 0x8068:
    case 0x8069:
    case 0x806a:
    case 0x806b:
    case 0x806c:
    case 0x806d:
    case 0x806e:
    case 0x806f:
    case 0x8070:
switchD_0012241c_caseD_8060:
      __android_log_print(3,"System.out","gladio:getTexParameter: unimplemented pname %x",param_4);
    }
LAB_00122614:
    if (*(long *)(lVar4 + 0x28) != local_48) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  switch(param_4) {
  case 0x1000:
    sVar3 = *(short *)(lVar5 + 0xc);
    goto LAB_00122660;
  case 0x1001:
    sVar3 = *(short *)(lVar5 + 0xe);
LAB_00122660:
    uVar6 = (int)sVar3 >> (param_3 & 0x1f);
    if ((int)uVar6 < 2) {
      uVar6 = 1;
    }
LAB_001226a8:
    fVar7 = (float)(int)uVar6;
LAB_00122610:
    *param_5 = fVar7;
    goto LAB_00122614;
  case 0x1002:
    break;
  case 0x1003:
    local_4c = *(int *)(lVar5 + 8);
LAB_0012260c:
    fVar7 = (float)local_4c;
    goto LAB_00122610;
  case 0x1004:
    goto switchD_0012241c_caseD_8072;
  default:
    if (param_4 - 0x2800U < 2) goto LAB_001225f8;
    if (param_4 - 0x2802U < 2) goto switchD_0012241c_caseD_8072;
  }
  goto switchD_0012241c_caseD_8060;
}


/* @0011eb30  size=820 */

void GLRenderer_initOnEGLContext(long param_1)

{
  long lVar1;
  int iVar2;
  uint64_t uVar3;
  struct timespec local_38;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  *(uint64_t *)(param_1 + 0xb4) = 0x3f8000003f800000;
  *(uint64_t *)(param_1 + 0xac) = 0x3f8000003f800000;
  *(uint64_t *)(param_1 + 0x714) = 0x3e4ccccd3e4ccccd;
  *(uint64_t *)(param_1 + 0x76c) = 0x3e4ccccd3e4ccccd;
  *(uint64_t *)(param_1 + 0x7c4) = 0x3e4ccccd3e4ccccd;
  uVar3 = neon_fmov_helper(0x3f800000);
  *(uint64_t *)(param_1 + 0x81c) = 0x3e4ccccd3e4ccccd;
  *(uint64_t *)(param_1 + 0x110) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 0x108) = 0;
  *(uint64_t *)(param_1 + 0x120) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 0x118) = 0;
  *(uint64_t *)(param_1 + 0x130) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 0x128) = 0;
  *(uint64_t *)(param_1 + 0x164) = uVar3;
  *(uint64_t *)(param_1 + 0x1ec) = uVar3;
  *(uint64_t *)(param_1 + 0x274) = uVar3;
  *(uint64_t *)(param_1 + 0x2fc) = uVar3;
  *(uint64_t *)(param_1 + 0x140) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 0x138) = 0;
  *(uint8_t *)(param_1 + 0x398) = 2;
  *(uint8_t *)(param_1 + 0x398) = 3;
  *(uint8_t *)(param_1 + 0x398) = 4;
  *(uint8_t *)(param_1 + 0x398) = 5;
  *(uint8_t *)(param_1 + 0x398) = 6;
  *(uint64_t *)(param_1 + 0xd0) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 200) = 0;
  *(uint64_t *)(param_1 + 0xe0) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 0xd8) = 0;
  *(uint64_t *)(param_1 + 0xf0) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 0xe8) = 0;
  *(uint64_t *)(param_1 + 0x100) = 0x3f80000000000000;
  *(uint64_t *)(param_1 + 0xf8) = 0;
  *(uint32_t *)(param_1 + 0x7c) = 0x3f800000;
  *(uint32_t *)(param_1 + 0x80) = 0x800;
  *(uint32_t *)(param_1 + 0xc4) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x1a8) = uVar3;
  *(uint64_t *)(param_1 + 0x230) = uVar3;
  *(uint64_t *)(param_1 + 0x2b8) = uVar3;
  *(uint64_t *)(param_1 + 0x340) = uVar3;
  *(uint64_t *)(param_1 + 0x5c) = 0x207;
  *(uint32_t *)(param_1 + 0x148) = 0x2100;
  *(uint32_t *)(param_1 + 0x15c) = 0x2100;
  *(uint32_t *)(param_1 + 0x18c) = 0x2100;
  *(uint32_t *)(param_1 + 0x1a0) = 0x2100;
  *(uint32_t *)(param_1 + 0x1d0) = 0x2100;
  *(uint32_t *)(param_1 + 0x1e4) = 0x2100;
  *(uint32_t *)(param_1 + 0x214) = 0x2100;
  *(uint32_t *)(param_1 + 0x228) = 0x2100;
  *(uint32_t *)(param_1 + 600) = 0x2100;
  *(uint32_t *)(param_1 + 0x26c) = 0x2100;
  *(uint32_t *)(param_1 + 0x29c) = 0x2100;
  *(uint32_t *)(param_1 + 0x2b0) = 0x2100;
  *(uint32_t *)(param_1 + 0x2e0) = 0x2100;
  *(uint32_t *)(param_1 + 0x2f4) = 0x2100;
  *(uint32_t *)(param_1 + 0x324) = 0x2100;
  *(uint32_t *)(param_1 + 0x338) = 0x2100;
  *(uint32_t *)(param_1 + 0x48) = 0x1b02;
  *(uint64_t *)(param_1 + 0x90) = 0x3f8000003f800000;
  *(uint64_t *)(param_1 + 0x88) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x72c) = 0x3f8000003f800000;
  *(uint64_t *)(param_1 + 0xbc) = 0;
  *(uint32_t *)(param_1 + 0xa0) = 0;
  *(uint32_t *)(param_1 + 0xa4) = 0x8ca2;
  *(uint64_t *)(param_1 + 0x98) = 0x3f800000;
  *(uint32_t *)(param_1 + 0x74) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x750) = 0;
  *(uint64_t *)(param_1 + 0x748) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x75c) = 0;
  *(uint64_t *)(param_1 + 0x740) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x738) = 0;
  *(uint64_t *)(param_1 + 0x784) = 0x3f8000003f800000;
  *(uint64_t *)(param_1 + 0x7b4) = 0;
  *(uint64_t *)(param_1 + 0x7dc) = 0x3f8000003f800000;
  *(uint64_t *)(param_1 + 0x7f0) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x7e8) = 0;
  *(uint32_t *)(param_1 + 0x38c) = 0x1d01;
  *(uint64_t *)(param_1 + 0x800) = 0;
  *(uint64_t *)(param_1 + 0x7f8) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x80c) = 0;
  *(uint8_t *)(param_1 + 0x398) = 0;
  *(uint8_t *)(param_1 + 0x390) = 0;
  *(uint32_t *)(param_1 + 0x71c) = 0x3e4ccccd;
  *(uint32_t *)(param_1 + 0x728) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x720) = 0x3f8000003f800000;
  *(uint32_t *)(param_1 + 0x734) = 0x3f800000;
  *(uint32_t *)(param_1 + 0x764) = 0xbf800000;
  *(uint32_t *)(param_1 + 0x754) = 0x40490fdb;
  *(uint32_t *)(param_1 + 0x774) = 0x3e4ccccd;
  *(uint32_t *)(param_1 + 0x780) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x778) = 0x3f8000003f800000;
  *(uint32_t *)(param_1 + 0x78c) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x798) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x790) = 0;
  *(uint64_t *)(param_1 + 0x7a8) = 0;
  *(uint64_t *)(param_1 + 0x7a0) = 0x3f800000;
  *(uint32_t *)(param_1 + 0x7bc) = 0xbf800000;
  *(uint32_t *)(param_1 + 0x7ac) = 0x40490fdb;
  *(uint32_t *)(param_1 + 0x7cc) = 0x3e4ccccd;
  *(uint32_t *)(param_1 + 0x7d8) = 0x3f800000;
  *(uint64_t *)(param_1 + 2000) = 0x3f8000003f800000;
  *(uint32_t *)(param_1 + 0x7e4) = 0x3f800000;
  *(uint32_t *)(param_1 + 0x814) = 0xbf800000;
  *(uint32_t *)(param_1 + 0x804) = 0x40490fdb;
  *(uint32_t *)(param_1 + 0x824) = 0x3e4ccccd;
  *(uint32_t *)(param_1 + 0x830) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x828) = 0x3f8000003f800000;
  *(uint32_t *)(param_1 + 0x83c) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x848) = 0x3f800000;
  *(uint64_t *)(param_1 + 0x840) = 0;
  *(uint64_t *)(param_1 + 0x858) = 0;
  *(uint64_t *)(param_1 + 0x850) = 0x3f800000;
  *(uint32_t *)(param_1 + 0x86c) = 0xbf800000;
  *(uint32_t *)(param_1 + 0x85c) = 0x40490fdb;
  *(uint64_t *)(param_1 + 0x834) = 0x3f8000003f800000;
  *(uint64_t *)(param_1 + 0x864) = 0;
  glGenBuffers(0xc,param_1 + 0x14);
  glPixelStorei(0xd05,1);
  glPixelStorei(0xcf5,1);
  glPixelStorei(0xcf2,0);
  glPixelStorei(0xcf4,0);
  glPixelStorei(0xcf3,0);
  iVar2 = clock_gettime(0,&local_38);
  *(long *)(param_1 + 0x908) = local_38.tv_nsec + local_38.tv_sec * 1000000000;
  if (*(long *)(lVar1 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}


/* @0011fce4  size=60 */

void GLRenderer_popMatrix(long param_1)

{
  int iVar1;
  void *__ptr;
  
  param_1 = param_1 + (unsigned long)*(uint32_t *)(param_1 + 0x8d0) * 0x10;
  iVar1 = *(int *)(param_1 + 0x8a0);
  if ((1 < iVar1) &&
     (__ptr = (void *)ArrayList_removeAt(param_1 + 0x8a0,iVar1 + -1), __ptr != (void *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


/* @0011fc24  size=192 */

void GLRenderer_pushMatrix(long param_1)

{
  int *piVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t *puVar4;
  uint64_t *puVar5;
  int iVar6;
  uint64_t *puVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  uint64_t uVar10;
  uint64_t uVar11;
  uint64_t uVar12;
  uint64_t uVar13;
  uint64_t uVar14;
  
  uVar3 = *(uint32_t *)(param_1 + 0x8d0);
  lVar2 = param_1 + (unsigned long)uVar3 * 0x10;
  iVar6 = *(int *)(lVar2 + 0x8a0);
  if (iVar6 < 0x20) {
    piVar1 = (int *)(lVar2 + 0x8a0);
    if (iVar6 == 0) {
      puVar4 = malloc(0x40);
      *(uint64_t *)(puVar4 + 3) = 0;
      *(uint64_t *)(puVar4 + 1) = 0;
      *(uint64_t *)(puVar4 + 6) = 0;
      *(uint64_t *)(puVar4 + 8) = 0;
      *(uint64_t *)(puVar4 + 0xd) = 0;
      *(uint64_t *)(puVar4 + 0xb) = 0;
      *puVar4 = 0x3f800000;
      puVar4[5] = 0x3f800000;
      puVar4[10] = 0x3f800000;
      puVar4[0xf] = 0x3f800000;
      ArrayList_add(piVar1,puVar4);
      iVar6 = *piVar1;
    }
    puVar7 = *(uint64_t **)
              (*(long *)(param_1 + (unsigned long)uVar3 * 0x10 + 0x8a8) + (long)(iVar6 + -1) * 8);
    puVar5 = malloc(0x40);
    uVar10 = puVar7[4];
    uVar9 = puVar7[7];
    uVar8 = puVar7[6];
    uVar12 = puVar7[1];
    uVar11 = *puVar7;
    uVar14 = puVar7[3];
    uVar13 = puVar7[2];
    puVar5[5] = puVar7[5];
    puVar5[4] = uVar10;
    puVar5[7] = uVar9;
    puVar5[6] = uVar8;
    puVar5[1] = uVar12;
    *puVar5 = uVar11;
    puVar5[3] = uVar14;
    puVar5[2] = uVar13;
    ArrayList_add(piVar1,puVar5);
    return;
  }
  return;
}


/* @00122988  size=1260 */

void GLRenderer_readPixels
               (long param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
               ,uint8_t *param_8)

{
  uint8_t *puVar1;
  uint8_t *pbVar2;
  int iVar3;
  uint8_t bVar4;
  uint8_t bVar5;
  uint32_t uVar6;
  uint32_t *puVar7;
  uint8_t *puVar8;
  void *pvVar9;
  char *pcVar10;
  uint8_t *puVar11;
  unsigned long uVar12;
  long lVar13;
  unsigned long uVar14;
  uint8_t *pbVar15;
  int *piVar16;
  
  piVar16 = *(int **)(param_1 + 0x918);
  iVar3 = *(int *)(param_1 + 0x590);
  uVar6 = param_4 * param_5 * 4;
  uVar14 = (unsigned long)uVar6;
  if (((((piVar16 != (int *)0x0) && (param_2 == 0)) && (param_3 == 0)) &&
      ((piVar16[1] == uVar6 && (*piVar16 == iVar3)))) &&
     ((uint32_t)(*(int *)(param_1 + 0x910) - piVar16[4]) < 4)) {
    memcpy(param_8,*(void **)(piVar16 + 2),(long)(int)uVar6);
    return;
  }
  puVar7 = (uint32_t *)GLBuffer_getBound(0x88eb);
  puVar8 = param_8;
  if (puVar7 == (uint32_t *)0x0) {
LAB_00122a6c:
    if ((param_6 != 0x1908) && (param_6 != 0x80e1)) {
      puVar8 = malloc((long)(int)uVar6);
    }
  }
  else if ((param_6 != 0x1908) && (param_6 != 0x80e1)) {
    glBindBuffer(0x88eb,0);
    goto LAB_00122a6c;
  }
  glReadPixels(param_2,param_3,param_4,param_5,0x1908,0x1401,puVar8);
  if ((((param_2 == 0) && (param_3 == 0)) && (param_4 < 0x101)) &&
     ((param_5 < 0x101 && ((param_6 == 0x80e1 || (param_6 == 0x1908)))))) {
    if (piVar16 == (int *)0x0) {
      piVar16 = calloc(1,0x18);
      *(int **)(param_1 + 0x918) = piVar16;
    }
    pvVar9 = *(void **)(piVar16 + 2);
    if (uVar6 != piVar16[1]) {
      if (pvVar9 != (void *)0x0) {
        free(pvVar9);
        piVar16[2] = 0;
        piVar16[3] = 0;
      }
      pvVar9 = malloc((long)(int)uVar6);
      *(void **)(piVar16 + 2) = pvVar9;
      piVar16[1] = uVar6;
    }
    piVar16[4] = *(int *)(param_1 + 0x910);
    *piVar16 = iVar3;
    memcpy(pvVar9,puVar8,(long)(int)uVar6);
  }
  else if (*(long *)(param_1 + 0x918) != 0) {
    pvVar9 = *(void **)(*(long *)(param_1 + 0x918) + 8);
    if (pvVar9 != (void *)0x0) {
      free(pvVar9);
    }
    *(uint64_t *)(param_1 + 0x918) = 0;
  }
  if (puVar7 != (uint32_t *)0x0) {
    if ((param_6 == 0x80e1) || (param_6 == 0x1908)) {
      puVar8 = (uint8_t *)glMapBufferRange(0x88eb,0,(long)(int)puVar7[1],1);
      memcpy(*(void **)(puVar7 + 2),puVar8,(long)(int)puVar7[1]);
      glUnmapBuffer(0x88eb);
    }
    else {
      glBindBuffer(0x88eb,*puVar7);
    }
  }
  if (param_7 < 0x8363) {
    if ((1 < param_7 - 0x1400U) && (param_7 != 0x8035)) goto LAB_00122cfc;
LAB_00122c30:
    if (puVar7 != (uint32_t *)0x0) {
      param_8 = *(uint8_t **)(puVar7 + 2);
    }
    switch(param_6) {
    case 0x1903:
    case 0x1904:
    case 0x1905:
    case 0x1909:
      if (0 < (int)uVar6) {
        lVar13 = (unsigned long)((uVar6 - 1 >> 2) + 1) << 2;
        puVar11 = puVar8 + (param_6 - 0x1903);
        do {
          lVar13 = lVar13 + -4;
          *param_8 = *puVar11;
          puVar11 = puVar11 + 4;
          param_8 = param_8 + 1;
        } while (lVar13 != 0);
      }
      break;
    case 0x1906:
switchD_00122c60_caseD_1906:
      pcVar10 = "gladio:readPixels: unimplemented format %x";
      param_7 = param_6;
      goto LAB_00122d2c;
    case 0x1907:
      if (param_7 == 0x8363) {
        if ((int)uVar6 < 1) goto LAB_00122e50;
        uVar12 = 0;
        pbVar15 = param_8 + 1;
        do {
          pbVar2 = puVar8 + uVar12;
          bVar4 = pbVar2[1];
          bVar5 = *pbVar2;
          uVar12 = uVar12 + 4;
          pbVar15[-1] = pbVar2[2] >> 3 | (bVar4 >> 2) << 5;
          *pbVar15 = bVar5 & 0xf8 | bVar4 >> 5;
          pbVar15 = pbVar15 + 2;
        } while (uVar12 < uVar14);
      }
      else {
        if ((int)uVar6 < 1) goto LAB_00122e50;
        uVar12 = 0;
        param_8 = param_8 + 1;
        do {
          puVar11 = puVar8 + uVar12;
          uVar12 = uVar12 + 4;
          param_8[-1] = *puVar11;
          *param_8 = puVar11[1];
          param_8[1] = puVar11[2];
          param_8 = param_8 + 3;
        } while (uVar12 < uVar14);
      }
      break;
    case 0x1908:
      goto switchD_00122c60_caseD_1908;
    default:
      if (param_6 == 0x80e0) {
        if ((int)uVar6 < 1) goto LAB_00122e50;
        uVar12 = 0;
        param_8 = param_8 + 1;
        do {
          puVar11 = puVar8 + uVar12;
          uVar12 = uVar12 + 4;
          param_8[-1] = puVar11[2];
          *param_8 = puVar11[1];
          param_8[1] = *puVar11;
          param_8 = param_8 + 3;
        } while (uVar12 < uVar14);
      }
      else {
        if (param_6 != 0x80e1) goto switchD_00122c60_caseD_1906;
        if ((int)uVar6 < 1) {
          return;
        }
        uVar12 = 0;
        do {
          puVar11 = puVar8 + uVar12;
          puVar1 = param_8 + uVar12;
          uVar12 = uVar12 + 4;
          *puVar1 = puVar11[2];
          puVar1[1] = puVar11[1];
          puVar1[2] = *puVar11;
          puVar1[3] = puVar11[3];
        } while (uVar12 < uVar14);
      }
    }
  }
  else {
    if ((param_7 == 0x8367) || (param_7 == 0x8363)) goto LAB_00122c30;
LAB_00122cfc:
    pcVar10 = "gladio:readPixels: unimplemented type %x";
LAB_00122d2c:
    __android_log_print(3,"System.out",pcVar10,param_7);
  }
  if ((param_6 != 0x1908) && (param_6 != 0x80e1)) {
LAB_00122e50:
    free(puVar8);
    return;
  }
switchD_00122c60_caseD_1908:
  return;
}


/* @00121070  size=56 */

void GLRenderer_resetFrameCount(long param_1)

{
  void *__ptr;
  
  if (*(long *)(param_1 + 0x918) != 0) {
    __ptr = *(void **)(*(long *)(param_1 + 0x918) + 8);
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    *(uint64_t *)(param_1 + 0x918) = 0;
  }
  *(uint32_t *)(param_1 + 0x910) = 0;
  return;
}


/* @0011ffe8  size=736 */

void GLRenderer_setCapabilityState(long param_1,uint32_t param_2,uint8_t param_3,int param_4)

{
  uint8_t bVar1;
  long lVar2;
  unsigned long uVar3;
  
  bVar1 = param_3 & 1;
  if ((int)param_2 < 0x2a02) {
    if ((int)param_2 < 0xba1) {
      if ((int)param_2 < 0xb42) {
        if (param_2 == 0xb10) {
          *(uint8_t *)(param_1 + 0xa9) = bVar1;
          return;
        }
        if (param_2 == 0xb20) {
          return;
        }
        if (param_2 == 0xb24) {
          return;
        }
      }
      else {
        switch(param_2) {
        case 0xb42:
          return;
        case 0xb50:
          *(uint8_t *)(param_1 + 0x44) = bVar1;
          return;
        case 0xb57:
          *(uint8_t *)(param_1 + 0x4c) = bVar1;
          return;
        case 0xb60:
          *(uint8_t *)(param_1 + 0x84) = bVar1;
          return;
        }
      }
    }
    else if ((int)param_2 < 0xde0) {
      if (param_2 == 0xba1) {
        return;
      }
      if (param_2 == 0xbc0) {
        *(uint8_t *)(param_1 + 0x58) = bVar1;
        return;
      }
    }
    else {
      if (param_2 == 0xde0) {
        uVar3 = (unsigned long)*(uint8_t *)(param_1 + 0x398);
LAB_0012021c:
        lVar2 = 0;
LAB_0012024c:
        *(uint8_t *)(param_1 + uVar3 * 4 + lVar2 + 0x368) = bVar1;
        return;
      }
      if (param_2 == 0xde1) goto LAB_00120154;
    }
  }
  else {
    lVar2 = 0;
    if ((int)param_2 < 0x8643) {
      if ((int)param_2 < 0x8513) {
        if (param_2 == 0x2a02) {
          return;
        }
        if (param_2 == 0x806f) goto LAB_00120154;
      }
      else {
        if (param_2 == 0x8513) {
LAB_00120154:
          uVar3 = (unsigned long)*(uint8_t *)(param_1 + 0x398);
          if (param_2 != 0xde1) {
            if (param_2 == 0x8513) {
              lVar2 = 2;
            }
            else if (param_2 == 0x806f) {
              lVar2 = 1;
            }
            else {
              __android_log_print(3,"System.out","gladio: unimplemented gl target %x",param_2);
              lVar2 = 0xff;
            }
            goto LAB_0012024c;
          }
          goto LAB_0012021c;
        }
        if (param_2 == 0x8620) goto LAB_00120130;
        if (param_2 == 0x8642) {
          return;
        }
      }
    }
    else if ((int)param_2 < 0x884f) {
      if (param_2 == 0x8643) {
LAB_00120130:
        *(uint8_t *)(param_1 + lVar2 + 0x388) = bVar1;
        return;
      }
      if (param_2 == 0x864f) {
        return;
      }
      if (param_2 == 0x8804) {
        lVar2 = 1;
        goto LAB_00120130;
      }
    }
    else {
      if (param_2 == 0x884f) {
        return;
      }
      if (param_2 == 0x8861) {
        *(uint8_t *)(param_1 + 0xa8) = bVar1;
        return;
      }
      if (param_2 == 0x8f9d) {
        param_2 = 0x8d69;
        goto LAB_001201bc;
      }
    }
  }
  if ((param_2 & 0xfffffff8) == 0x4000) {
    if (0x4003 < (int)param_2) {
      return;
    }
    *(uint8_t *)(param_1 + (unsigned long)(param_2 - 0x4000) * 0x58 + 0x710) = bVar1;
    return;
  }
LAB_001201bc:
  if (((param_2 & 0xfffffffc) == 0xc60) || (param_2 - 0x3000 < 6)) {
    if ((param_3 & 1) == 0) {
      return;
    }
    __android_log_print(3,"System.out","gladio:setCapabilityState: unimplemented cap %x",param_2);
    return;
  }
  if (param_4 == -1) {
    if ((param_3 & 1) == 0) {
      glDisable(param_2);
      return;
    }
    glEnable(0);
    return;
  }
  if ((param_3 & 1) == 0) {
    glDisablei(param_2,param_4);
    return;
  }
  glEnablei(0, 0);
  return;
}


/* @00122fb8  size=188 */

void GLRenderer_setDrawBuffer(long param_1,uint32_t param_2)

{
  int iVar1;
  long lVar2;
  uint32_t local_2c;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar2 + 0x28);
  if ((param_2 & 0xfffffffe) == 0x402) {
    local_2c = 0x405;
LAB_00123008:
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    if ((param_2 & 0xfffffffe) == 0x400) {
      local_2c = 0x404;
    }
    else {
      local_2c = param_2;
      if ((param_2 == 0) || ((param_2 & 0xffffffe0) == 0x8ce0)) {
        GLFramebuffer_setDrawBuffers(1,&local_2c);
        goto LAB_00123050;
      }
      if (param_2 != 0x404) goto LAB_00123008;
    }
    iVar1 = *(int *)(param_1 + 8);
    *(uint8_t *)(param_1 + 0x10) = 0;
  }
  if (iVar1 != *(int *)(param_1 + 0x588)) {
    GLFramebuffer_bind(0x8d40);
  }
LAB_00123050:
  if (*(long *)(lVar2 + 0x28) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00120df0  size=128 */

void GLRenderer_setFogParams(long param_1,uint32_t param_2,float *param_3)

{
  uint64_t uVar1;
  
  switch(param_2) {
  case 0xb62:
    *(float *)(param_1 + 0x74) = *param_3;
    return;
  case 0xb63:
    *(float *)(param_1 + 0x78) = *param_3;
    return;
  case 0xb64:
    *(float *)(param_1 + 0x7c) = *param_3;
    return;
  case 0xb65:
    *(int *)(param_1 + 0x80) = (int)*param_3;
    return;
  case 0xb66:
    uVar1 = *(uint64_t *)param_3;
    *(uint64_t *)(param_1 + 0x6c) = *(uint64_t *)(param_3 + 2);
    *(uint64_t *)(param_1 + 100) = uVar1;
    return;
  default:
    __android_log_print(3,"System.out","gladio:setFogParams: unimplemented pname %x",param_2);
    return;
  }
}


/* @001202c8  size=872 */

void GLRenderer_setLightParams(long param_1,int param_2,int param_3,float *param_4)

{
  long lVar1;
  float *pfVar2;
  uint32_t *puVar3;
  long lVar4;
  uint64_t uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint64_t local_68;
  float local_60;
  uint64_t local_58;
  float local_50;
  uint64_t local_48;
  float local_40;
  long local_28;
  
  /* stack canary setup (elided) */
  local_28 = *(long *)(lVar1 + 0x28);
  lVar4 = param_1 + (long)(param_2 + -0x4000) * 0x58;
  if (param_2 + -0x4000 < 4) {
    switch(param_3) {
    case 0x1200:
      uVar5 = *(uint64_t *)param_4;
      *(float *)(lVar4 + 0x71c) = param_4[2];
      *(uint64_t *)(lVar4 + 0x714) = uVar5;
      break;
    case 0x1201:
      uVar5 = *(uint64_t *)param_4;
      *(float *)(lVar4 + 0x728) = param_4[2];
      *(uint64_t *)(lVar4 + 0x720) = uVar5;
      break;
    case 0x1202:
      uVar5 = *(uint64_t *)param_4;
      *(float *)(lVar4 + 0x734) = param_4[2];
      *(uint64_t *)(lVar4 + 0x72c) = uVar5;
      break;
    case 0x1203:
      uVar5 = *(uint64_t *)param_4;
      *(uint64_t *)(lVar4 + 0x740) = *(uint64_t *)(param_4 + 2);
      *(uint64_t *)(lVar4 + 0x738) = uVar5;
      if (*(int *)(param_1 + 0x8a0) < 1) {
        pfVar2 = (float *)&DAT_00144118;
      }
      else {
        pfVar2 = *(float **)
                  (*(long *)(param_1 + 0x8a8) + (unsigned long)(*(int *)(param_1 + 0x8a0) - 1) * 8);
      }
      if (*(float *)(lVar4 + 0x744) <= 0.0) {
        FUN_0012088c(local_68);
        fVar6 = *(float *)(lVar4 + 0x738);
        fVar7 = *(float *)(lVar4 + 0x73c);
        fVar10 = *(float *)(lVar4 + 0x740);
        fVar8 = (*(uint32_t*)((char*)&local_68 + 0)) * fVar6 + (float)local_58 * fVar7 + (float)local_48 * fVar10;
        fVar9 = (*(uint32_t*)((char*)&local_68 + 4)) * fVar6 + (float)((unsigned long)local_58 >> 0x20) * fVar7 +
                (float)((unsigned long)local_48 >> 0x20) * fVar10;
        fVar6 = fVar6 * local_60 + fVar7 * local_50 + fVar10 * local_40;
        fVar7 = 1.0 / SQRT(fVar8 * fVar8 + fVar9 * fVar9 + fVar6 * fVar6);
        *(unsigned long *)(lVar4 + 0x738) = ((uint64_t)(fVar9) << 32 | (uint32_t)(fVar8));
        if ((INFINITY <= ABS(fVar7)) && (ABS(fVar7) == INFINITY)) {
          *(uint32_t *)(lVar4 + 0x740) = 0;
          *(uint64_t *)(lVar4 + 0x738) = 0;
          break;
        }
        fVar6 = fVar6 * fVar7;
        *(unsigned long *)(lVar4 + 0x738) = ((uint64_t)(fVar9 * fVar7) << 32 | (uint32_t)(fVar8 * fVar7));
      }
      else {
        fVar6 = *(float *)(lVar4 + 0x738);
        fVar7 = *(float *)(lVar4 + 0x73c);
        fVar8 = *(float *)(lVar4 + 0x740);
        *(float *)(lVar4 + 0x738) =
             pfVar2[0xc] + fVar6 * *pfVar2 + fVar7 * pfVar2[4] + fVar8 * pfVar2[8];
        *(float *)(lVar4 + 0x73c) =
             pfVar2[0xd] + fVar6 * pfVar2[1] + fVar7 * pfVar2[5] + fVar8 * pfVar2[9];
        fVar6 = pfVar2[0xe] + fVar6 * pfVar2[2] + fVar7 * pfVar2[6] + fVar8 * pfVar2[10];
      }
      *(float *)(lVar4 + 0x740) = fVar6;
      break;
    case 0x1204:
      uVar5 = *(uint64_t *)param_4;
      *(float *)(lVar4 + 0x764) = param_4[2];
      *(uint64_t *)(lVar4 + 0x75c) = uVar5;
      if (*(int *)(param_1 + 0x8a0) < 1) {
        puVar3 = &DAT_00144118;
      }
      else {
        puVar3 = *(uint32_t **)
                  (*(long *)(param_1 + 0x8a8) + (unsigned long)(*(int *)(param_1 + 0x8a0) - 1) * 8);
      }
      FUN_0012088c(local_68,puVar3);
      fVar6 = *(float *)(lVar4 + 0x75c);
      fVar7 = *(float *)(lVar4 + 0x760);
      fVar10 = *(float *)(lVar4 + 0x764);
      fVar8 = (*(uint32_t*)((char*)&local_68 + 0)) * fVar6 + (float)local_58 * fVar7 + (float)local_48 * fVar10;
      fVar9 = (*(uint32_t*)((char*)&local_68 + 4)) * fVar6 + (float)((unsigned long)local_58 >> 0x20) * fVar7 +
              (float)((unsigned long)local_48 >> 0x20) * fVar10;
      fVar6 = fVar6 * local_60 + fVar7 * local_50 + fVar10 * local_40;
      fVar7 = 1.0 / SQRT(fVar8 * fVar8 + fVar9 * fVar9 + fVar6 * fVar6);
      *(unsigned long *)(lVar4 + 0x75c) = ((uint64_t)(fVar9) << 32 | (uint32_t)(fVar8));
      if ((ABS(fVar7) < INFINITY) || (ABS(fVar7) != INFINITY)) {
        *(unsigned long *)(lVar4 + 0x75c) = ((uint64_t)(fVar9 * fVar7) << 32 | (uint32_t)(fVar8 * fVar7));
        *(float *)(lVar4 + 0x764) = fVar6 * fVar7;
      }
      else {
        *(uint64_t *)(lVar4 + 0x760) = 0;
        *(uint32_t *)(lVar4 + 0x75c) = 0;
      }
      break;
    case 0x1205:
      *(float *)(lVar4 + 0x758) = *param_4;
      break;
    case 0x1206:
      *(float *)(lVar4 + 0x754) = *param_4 * 0.017453292;
      break;
    case 0x1207:
      *(float *)(lVar4 + 0x748) = *param_4;
      break;
    case 0x1208:
      *(float *)(lVar4 + 0x74c) = *param_4;
      break;
    case 0x1209:
      *(float *)(lVar4 + 0x750) = *param_4;
      break;
    default:
      if (param_3 == 0xb50) {
        *(uint8_t *)(lVar4 + 0x710) = *(uint8_t *)param_4;
      }
    }
  }
  if (*(long *)(lVar1 + 0x28) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @00120630  size=604 */

void GLRenderer_setMaterialParams(long param_1,int param_2,int param_3,uint64_t *param_4)

{
  uint64_t *puVar1;
  long lVar2;
  uint64_t uVar3;
  
  puVar1 = *(uint64_t **)(param_1 + 0x708);
  if (puVar1 == (uint64_t *)0x0) {
    puVar1 = calloc(2,0x34);
    *puVar1 = 0x3e4ccccd3e4ccccd;
    *(uint32_t *)(puVar1 + 1) = 0x3e4ccccd;
    *(uint64_t *)((long)puVar1 + 0xc) = 0x3f4ccccd3f4ccccd;
    *(uint32_t *)((long)puVar1 + 0x14) = 0x3f4ccccd;
    *(uint64_t *)((long)puVar1 + 0x34) = 0x3e4ccccd3e4ccccd;
    *(uint32_t *)((long)puVar1 + 0x3c) = 0x3e4ccccd;
    *(uint32_t *)(puVar1 + 9) = 0x3f4ccccd;
    puVar1[8] = 0x3f4ccccd3f4ccccd;
    *(uint64_t **)(param_1 + 0x708) = puVar1;
  }
  if (param_2 != 0x408) {
    if (param_2 == 0x405) goto LAB_001207a4;
    if (param_2 != 0x404) {
      return;
    }
  }
  if (param_3 < 0x1600) {
    if (param_3 == 0x1200) {
      uVar3 = *param_4;
      *(uint32_t *)(puVar1 + 1) = *(uint32_t *)(param_4 + 1);
      *puVar1 = uVar3;
    }
    else if (param_3 == 0x1201) {
LAB_0012074c:
      uVar3 = *param_4;
      *(uint32_t *)((long)puVar1 + 0x14) = *(uint32_t *)(param_4 + 1);
      *(uint64_t *)((long)puVar1 + 0xc) = uVar3;
    }
    else if (param_3 == 0x1202) {
      uVar3 = *param_4;
      *(uint32_t *)(puVar1 + 4) = *(uint32_t *)(param_4 + 1);
      puVar1[3] = uVar3;
    }
  }
  else if (param_3 == 0x1600) {
    uVar3 = *param_4;
    *(uint32_t *)(puVar1 + 6) = *(uint32_t *)(param_4 + 1);
    puVar1[5] = uVar3;
  }
  else if (param_3 == 0x1601) {
    *(uint32_t *)((long)puVar1 + 0x24) = *(uint32_t *)param_4;
  }
  else if (param_3 == 0x1602) {
    uVar3 = *param_4;
    *(uint32_t *)(puVar1 + 1) = *(uint32_t *)(param_4 + 1);
    *puVar1 = uVar3;
    goto LAB_0012074c;
  }
  if ((param_2 != 0x408) && (param_2 != 0x405)) {
    return;
  }
LAB_001207a4:
  lVar2 = *(long *)(param_1 + 0x708);
  if (param_3 < 0x1600) {
    if (param_3 == 0x1200) {
      uVar3 = *param_4;
      *(uint32_t *)(lVar2 + 0x3c) = *(uint32_t *)(param_4 + 1);
      *(uint64_t *)(lVar2 + 0x34) = uVar3;
      return;
    }
    if (param_3 != 0x1201) {
      if (param_3 != 0x1202) {
        return;
      }
      uVar3 = *param_4;
      *(uint32_t *)(lVar2 + 0x54) = *(uint32_t *)(param_4 + 1);
      *(uint64_t *)(lVar2 + 0x4c) = uVar3;
      return;
    }
  }
  else {
    if (param_3 == 0x1600) {
      uVar3 = *param_4;
      *(uint32_t *)(lVar2 + 100) = *(uint32_t *)(param_4 + 1);
      *(uint64_t *)(lVar2 + 0x5c) = uVar3;
      return;
    }
    if (param_3 == 0x1601) {
      *(uint32_t *)(lVar2 + 0x58) = *(uint32_t *)param_4;
      return;
    }
    if (param_3 != 0x1602) {
      return;
    }
    uVar3 = *param_4;
    *(uint32_t *)(lVar2 + 0x3c) = *(uint32_t *)(param_4 + 1);
    *(uint64_t *)(lVar2 + 0x34) = uVar3;
  }
  uVar3 = *param_4;
  *(uint32_t *)(lVar2 + 0x48) = *(uint32_t *)(param_4 + 1);
  *(uint64_t *)(lVar2 + 0x40) = uVar3;
  return;
}


/* @001215c4  size=56 */

void GLRenderer_setPixelZoom(uint32_t param_1,uint32_t param_2,long param_3)

{
  long lVar1;
  
  FUN_001215fc();
  lVar1 = *(long *)(param_3 + 0x8d8);
  *(uint32_t *)(lVar1 + 0x10) = param_1;
  *(uint32_t *)(lVar1 + 0x14) = param_2;
  return;
}


/* @00120e70  size=148 */

void GLRenderer_setPointParams(long param_1,int param_2,uint64_t *param_3)

{
  uint64_t uVar1;
  
  switch(param_2) {
  case 0x8126:
    *(uint32_t *)(param_1 + 0x8c) = *(uint32_t *)param_3;
    return;
  case 0x8127:
    *(uint32_t *)(param_1 + 0x90) = *(uint32_t *)param_3;
    return;
  case 0x8128:
    *(uint32_t *)(param_1 + 0x94) = *(uint32_t *)param_3;
    return;
  case 0x8129:
    uVar1 = *param_3;
    *(uint32_t *)(param_1 + 0xa0) = *(uint32_t *)(param_3 + 1);
    *(uint64_t *)(param_1 + 0x98) = uVar1;
    return;
  }
  if (param_2 != 36000) {
    __android_log_print(3,"System.out","gladio:setPointParams: unimplemented pname %x",param_2);
    return;
  }
  *(uint32_t *)(param_1 + 0xa4) = *(uint32_t *)param_3;
  return;
}


/* @001216c4  size=496 */

void GLRenderer_setRasterPos
               (float param_1,float param_2,float param_3,float param_4,long param_5,uint32_t param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  short sVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  short sVar16;
  float fVar17;
  
  FUN_001215fc();
  if (*(int *)(param_5 + 0x8b0) < 1) {
    pfVar4 = (float *)&DAT_00144118;
  }
  else {
    pfVar4 = *(float **)(*(long *)(param_5 + 0x8b8) + (unsigned long)(*(int *)(param_5 + 0x8b0) - 1) * 8);
  }
  if (*(int *)(param_5 + 0x8a0) < 1) {
    pfVar6 = (float *)&DAT_00144118;
  }
  else {
    pfVar6 = *(float **)(*(long *)(param_5 + 0x8a8) + (unsigned long)(*(int *)(param_5 + 0x8a0) - 1) * 8);
  }
  pfVar5 = *(float **)(param_5 + 0x8d8);
  *pfVar5 = param_1;
  pfVar5[1] = param_2;
  pfVar5[2] = param_3;
  pfVar5[3] = param_4;
  if ((param_6 & 1) != 0) {
    sVar12 = *(short *)(param_5 + 4);
    fVar11 = 1.0;
    if (param_4 != 0.0) {
      fVar11 = 1.0 / param_4;
    }
    sVar16 = *(short *)(param_5 + 6);
    fVar7 = pfVar6[0xc] + *pfVar6 * param_1 + pfVar6[4] * param_2 + pfVar6[8] * param_3;
    *pfVar5 = fVar7;
    fVar9 = pfVar6[0xd] + pfVar6[1] * param_1 + pfVar6[5] * param_2 + pfVar6[9] * param_3;
    pfVar5[1] = fVar9;
    fVar8 = (float)(int)sVar12 * 0.5;
    fVar1 = (float)(int)sVar16 * 0.5;
    fVar10 = pfVar6[0xe] + pfVar6[2] * param_1 + pfVar6[6] * param_2 + pfVar6[10] * param_3;
    pfVar5[2] = fVar10;
    fVar13 = pfVar4[0xc] + fVar7 * *pfVar4 + fVar9 * pfVar4[4] + fVar10 * pfVar4[8];
    *pfVar5 = fVar13;
    fVar14 = pfVar4[0xd] + fVar7 * pfVar4[1] + fVar9 * pfVar4[5] + fVar10 * pfVar4[9];
    pfVar5[1] = fVar14;
    fVar2 = pfVar4[2];
    fVar17 = pfVar4[6];
    fVar15 = pfVar4[10];
    fVar3 = pfVar4[0xe];
    pfVar5[1] = fVar1 + fVar11 * fVar14 * fVar1;
    pfVar5[2] = fVar11 * (fVar3 + fVar7 * fVar2 + fVar9 * fVar17 + fVar10 * fVar15);
    *pfVar5 = fVar8 + fVar11 * fVar13 * fVar8;
  }
  return;
}


/* @00121f44  size=172 */

void GLRenderer_setSamplerParameter
               (uint64_t param_1,uint32_t param_2,int param_3,float *param_4)

{
  float fVar1;
  
  if (param_3 < 0x813a) {
    if (3 < param_3 - 0x2800U) {
      if (param_3 == 0x1004) {
        glSamplerParameterfv(param_2,0x1004,param_4);
        return;
      }
      if (param_3 != 0x8072) {
        return;
      }
    }
  }
  else {
    if (param_3 - 0x813aU < 2) {
      glSamplerParameterf(*param_4,param_2,param_3);
      return;
    }
    if (1 < param_3 - 0x884cU) {
      if (param_3 != 0x84fe) {
        return;
      }
      fVar1 = *param_4;
      if (fVar1 <= 1.0) {
        fVar1 = 1.0;
      }
      glSamplerParameterf(fVar1,param_2,0x84fe);
      return;
    }
  }
  glSamplerParameteri(param_2,param_3,(int)*param_4);
  return;
}


/* @0011ee64  size=536 */

void GLRenderer_setTexEnvParams(long param_1,uint64_t param_2,int param_3,float *param_4)

{
  int iVar1;
  unsigned long uVar2;
  int iVar3;
  uint64_t uVar4;
  
  uVar2 = (unsigned long)*(uint8_t *)(param_1 + 0x398);
  if (param_3 < 0x8571) {
    if (param_3 == 0xd1c) {
      *(float *)(param_1 + uVar2 * 0x44 + 0x168) = *param_4;
      return;
    }
    if (param_3 != 0x2200) {
      if (param_3 == 0x2201) {
        uVar4 = *(uint64_t *)param_4;
        param_1 = param_1 + uVar2 * 0x44;
        *(uint64_t *)(param_1 + 0x154) = *(uint64_t *)(param_4 + 2);
        *(uint64_t *)(param_1 + 0x14c) = uVar4;
        return;
      }
      goto switchD_0011ee9c_caseD_8574;
    }
    iVar1 = (int)*param_4;
    if (iVar1 < 0x2100) {
      if ((iVar1 == 0x104) || (iVar1 == 0xbe2)) goto LAB_0011f060;
      iVar3 = 0x1e01;
    }
    else {
      if ((iVar1 - 0x2100U < 2) || (iVar1 == 0x8575)) goto LAB_0011f060;
      iVar3 = 0x8570;
    }
    if (iVar1 == iVar3) {
LAB_0011f060:
      iVar3 = 0x8575;
      if (iVar1 != 0xbe2) {
        iVar3 = iVar1;
      }
      *(int *)(param_1 + uVar2 * 0x44 + 0x148) = iVar3;
      return;
    }
  }
  else {
    switch(param_3) {
    case 0x8571:
      *(int *)(param_1 + uVar2 * 0x44 + 0x15c) = (int)*param_4;
      return;
    case 0x8572:
      *(int *)(param_1 + uVar2 * 0x44 + 0x160) = (int)*param_4;
      return;
    case 0x8573:
      *(float *)(param_1 + uVar2 * 0x44 + 0x164) = *param_4;
      break;
    default:
switchD_0011ee9c_caseD_8574:
      __android_log_print(3,"System.out","gladio:setTexEnvParams: unimplemented pname %x",param_3);
      return;
    case 0x8580:
      *(int *)(param_1 + uVar2 * 0x44 + 0x16c) = (int)*param_4;
      return;
    case 0x8581:
      *(int *)(param_1 + uVar2 * 0x44 + 0x170) = (int)*param_4;
      return;
    case 0x8588:
      *(int *)(param_1 + uVar2 * 0x44 + 0x174) = (int)*param_4;
      return;
    case 0x8589:
      *(int *)(param_1 + uVar2 * 0x44 + 0x178) = (int)*param_4;
      return;
    case 0x8590:
      *(int *)(param_1 + uVar2 * 0x44 + 0x17c) = (int)*param_4;
      return;
    case 0x8591:
      *(int *)(param_1 + uVar2 * 0x44 + 0x180) = (int)*param_4;
      return;
    case 0x8598:
      *(int *)(param_1 + uVar2 * 0x44 + 0x184) = (int)*param_4;
      return;
    case 0x8599:
      *(int *)(param_1 + uVar2 * 0x44 + 0x188) = (int)*param_4;
      return;
    }
  }
  return;
}


/* @001220e8  size=692 */

void GLRenderer_setTexParameter(uint64_t param_1,int param_2,int param_3,float *param_4)

{
  long lVar1;
  uint64_t uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  iVar4 = 0xde1;
  if (((param_2 != 0xde0) && (param_2 != 0x84f5)) && (iVar4 = param_2, param_2 == 0x8c18)) {
    iVar4 = 0x8c1a;
  }
  if (param_3 < 0x8191) {
    if (param_3 < 0x8072) {
      if (1 < param_3 - 0x2800U) {
        if (1 < param_3 - 0x2802U) {
          if (param_3 != 0x1004) {
            return;
          }
          glTexParameterfv(iVar4,0x1004,param_4);
          return;
        }
LAB_00122258:
        iVar3 = 0x812f;
        if ((int)*param_4 != 0x2900) {
          iVar3 = (int)*param_4;
        }
        goto LAB_001222b8;
      }
    }
    else {
      if (param_3 - 0x813aU < 2) {
        fVar5 = *param_4;
LAB_0012231c:
        glTexParameterf(fVar5,iVar4,param_3);
        return;
      }
      if (1 < param_3 - 0x813cU) {
        if (param_3 != 0x8072) {
          return;
        }
        goto LAB_00122258;
      }
    }
  }
  else if (param_3 < 0x8e42) {
    if (param_3 < 0x884c) {
      if (param_3 == 0x8191) {
        fVar5 = *param_4;
        lVar1 = GLTexture_getBound(iVar4);
        if (lVar1 == 0) {
          return;
        }
        *(bool *)(lVar1 + 0x10) = (int)fVar5 != 0;
        return;
      }
      if (param_3 == 0x84fe) {
        fVar5 = *param_4;
        param_3 = 0x84fe;
        if (fVar5 <= 1.0) {
          fVar5 = 1.0;
        }
        goto LAB_0012231c;
      }
      if (param_3 != 0x884b) {
        return;
      }
      iVar3 = (int)*param_4;
      if (iVar3 == 0x1906) {
        glTexParameteri(iVar4,0x8e42,0);
        glTexParameteri(iVar4,0x8e43,0);
        uVar2 = 0;
LAB_00122388:
        glTexParameteri(iVar4,0x8e44,uVar2);
        iVar3 = 0x1906;
      }
      else {
        if (iVar3 == 0x8049) {
          glTexParameteri(iVar4,0x8e42,0x1903);
          glTexParameteri(iVar4,0x8e43,0x1904);
          uVar2 = 0x1905;
          goto LAB_00122388;
        }
        if (iVar3 != 0x1909) {
          return;
        }
        glTexParameteri(iVar4,0x8e42,0x1903);
        glTexParameteri(iVar4,0x8e43,0x1904);
        glTexParameteri(iVar4,0x8e44,0x1905);
        iVar3 = 1;
      }
      param_3 = 0x8e45;
      goto LAB_001222b8;
    }
    if (1 < param_3 - 0x884cU) {
      return;
    }
  }
  else if ((3 < param_3 - 0x8e42U) && (param_3 != 0x90ea)) {
    return;
  }
  iVar3 = (int)*param_4;
LAB_001222b8:
  glTexParameteri(iVar4,param_3,iVar3);
  return;
}


