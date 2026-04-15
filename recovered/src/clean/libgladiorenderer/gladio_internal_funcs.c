/*
 * gladio_internal_funcs.c — Internal helper functions
 *
 * Some functions are stubbed due to Ghidra NEON/SIMD artifacts
 * that require manual AARCH64 intrinsic reconstruction.
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include "gladio_data.h"
#include <ctype.h>
#include <math.h>

static const void *_ctype_table = NULL;

/* @0011c864  size=8 */

void FUN_0011c864(void)

{
  return;
}


/* @0011c874  size=20 */

void FUN_0011c874(void *UNRECOVERED_JUMPTABLE)

{
  if (UNRECOVERED_JUMPTABLE != (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011c880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ((generic_fn_t)0)();
    return;
  }
  return;
}


/* @0011c888  size=32 */

void FUN_0011c888(uint64_t param_1)

{
  __cxa_atexit(FUN_0011c874,param_1,&PTR_LOOP_00141df0);
  return;
}


/* @0011c8a8  size=16 */

void FUN_0011c8a8(void)

{
  __register_atfork();
  return;
}


/* STUBBED — needs manual NEON/SIMD reconstruction */

uint64_t FUN_0011cb78(long *param_1)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0011db60(long param_1,int param_2,int param_3,long param_4,long param_5)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

uint64_t FUN_0011e56c(char *param_1)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0011e6a4(long param_1,int param_2)
{
  /* TODO */
}

/* @0011f510  size=404 */

uint32_t * FUN_0011f510(long param_1,uint8_t *param_2)

{
  int iVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  uVar3 = 0;
  if (*(uint32_t **)(param_2 + 8) != (uint32_t *)0x0) {
    uVar3 = **(uint32_t **)(param_2 + 8);
  }
  uVar4 = 0;
  if (*(uint32_t **)(param_2 + 0x10) != (uint32_t *)0x0) {
    uVar4 = **(uint32_t **)(param_2 + 0x10);
  }
  iVar1 = ((((((((((((((((uVar4 & 0xff ^
                         (((((uVar3 & 0xff ^ 0x811c9dc5) * 0x1000193 ^ uVar3 >> 8 & 0xff) *
                            0x1000193 ^ uVar3 >> 0x10 & 0xff) * 0x1000193 ^ uVar3 >> 0x18) *
                          0x1000193 ^ 0x2d) * 0x1000193) * 0x1000193 ^ uVar4 >> 8 & 0xff) *
                        0x1000193 ^ uVar4 >> 0x10 & 0xff) * 0x1000193 ^ uVar4 >> 0x18) * 0x1000193 ^
                     0x2d) * 0x1000193 ^ (*param_2 | 0x30)) * 0x1000193 ^ 0x2d) * 0x1000193 ^
                  (param_2[1] | 0x30)) * 0x1000193 ^ 0x2d) * 0x1000193 ^ (param_2[2] | 0x30)) *
                0x1000193 ^ 0x2d) * 0x1000193 ^ (param_2[3] | 0x30)) * 0x1000193 ^ 0x2d) * 0x1000193
            ^ (param_2[4] | 0x30)) * 0x1000193 ^ 0x2d) * 0x1000193 ^ param_2[5] + 0x30 & 0xff) *
          0x1000193;
  puVar2 = (uint32_t *)SparseArray_get(param_1 + 0x870,iVar1);
  if (puVar2 == (uint32_t *)0x0) {
    puVar2 = (uint32_t *)ShaderMaterial_create(param_2);
    SparseArray_put(param_1 + 0x870,iVar1,puVar2);
  }
  glUseProgram(*puVar2);
  ShaderMaterial_updateUniforms(puVar2,param_1,param_2);
  return puVar2;
}


/* @0011f6a4  size=688 */

void FUN_0011f6a4(long param_1,uint32_t *param_2)

{
  uint32_t uVar1;
  int iVar2;
  unsigned long uVar3;
  uint64_t uVar4;
  long lVar5;
  int *piVar6;
  
  glBindBuffer(0x8893,*(uint32_t *)(param_1 + 0x14));
  glBufferData(0x8893,(long)*(int *)(param_1 + 0x6f0),*(uint64_t *)(param_1 + 0x700),0x88e8);
  uVar1 = *param_2;
  if (uVar1 != 0xffffffff) {
    iVar2 = *(int *)(param_1 + 0x5e8);
    uVar4 = *(uint64_t *)(param_1 + 0x5f8);
    glBindBuffer(0x8892,*(uint32_t *)(param_1 + 0x18));
    glBufferData(0x8892,(long)iVar2,uVar4,0x88e8);
    if ((-1 < (int)uVar1) && (*(char *)(param_1 + (unsigned long)uVar1 + 0x8f0) == '\0')) {
      glEnableVertexAttribArray(uVar1);
      *(uint8_t *)(param_1 + (unsigned long)uVar1 + 0x8f0) = 1;
    }
    glVertexAttribPointer(uVar1,4,0x1406,0,0,0);
  }
  uVar1 = param_2[1];
  uVar3 = (unsigned long)uVar1;
  if (uVar1 != 0xffffffff) {
    iVar2 = *(int *)(param_1 + 0x600);
    if (iVar2 < 1) {
      if ((-1 < (int)uVar1) && (lVar5 = param_1 + uVar3, *(char *)(lVar5 + 0x8f0) != '\0')) {
        glDisableVertexAttribArray(uVar1);
        uVar3 = (unsigned long)param_2[1];
        *(uint8_t *)(lVar5 + 0x8f0) = 0;
      }
      glVertexAttrib4fv(uVar3,param_1 + 0xac);
    }
    else {
      uVar4 = *(uint64_t *)(param_1 + 0x610);
      glBindBuffer(0x8892,*(uint32_t *)(param_1 + 0x1c));
      glBufferData(0x8892,iVar2,uVar4,0x88e8);
      if ((-1 < (int)uVar1) && (*(char *)(param_1 + uVar3 + 0x8f0) == '\0')) {
        glEnableVertexAttribArray(uVar1);
        *(uint8_t *)(param_1 + uVar3 + 0x8f0) = 1;
      }
      glVertexAttribPointer(uVar1,4,0x1406,0,0,0);
    }
  }
  uVar1 = param_2[2];
  if ((uVar1 != 0xffffffff) && (iVar2 = *(int *)(param_1 + 0x618), 0 < iVar2)) {
    uVar4 = *(uint64_t *)(param_1 + 0x628);
    glBindBuffer(0x8892,*(uint32_t *)(param_1 + 0x20));
    glBufferData(0x8892,iVar2,uVar4,0x88e8);
    if ((-1 < (int)uVar1) && (*(char *)(param_1 + (unsigned long)uVar1 + 0x8f0) == '\0')) {
      glEnableVertexAttribArray(uVar1);
      *(uint8_t *)(param_1 + (unsigned long)uVar1 + 0x8f0) = 1;
    }
    glVertexAttribPointer(uVar1,3,0x1406,0,0,0);
  }
  lVar5 = 0;
  piVar6 = (int *)(param_1 + 0x630);
  do {
    uVar1 = *(uint32_t *)((long)param_2 + lVar5 + 0xc);
    uVar3 = (unsigned long)uVar1;
    if ((uVar1 != 0xffffffff) && (iVar2 = *piVar6, 0 < iVar2)) {
      uVar4 = *(uint64_t *)(piVar6 + 4);
      glBindBuffer(0x8892,*(uint32_t *)(param_1 + lVar5 + 0x24));
      glBufferData(0x8892,iVar2,uVar4,0x88e8);
      if ((-1 < (int)uVar1) && (*(char *)(param_1 + uVar3 + 0x8f0) == '\0')) {
        glEnableVertexAttribArray(uVar3);
        *(uint8_t *)(param_1 + uVar3 + 0x8f0) = 1;
      }
      glVertexAttribPointer(uVar3,4,0x1406,0,0,0);
    }
    lVar5 = lVar5 + 4;
    *piVar6 = 0;
    piVar6 = piVar6 + 6;
  } while (lVar5 != 0x20);
  *(uint32_t *)(param_1 + 0x6f0) = 0;
  *(uint32_t *)(param_1 + 0x5e8) = 0;
  *(uint32_t *)(param_1 + 0x600) = 0;
  *(uint32_t *)(param_1 + 0x618) = 0;
  return;
}


/* @0012088c  size=1380 */

void FUN_0012088c(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  
  fVar19 = param_2[8];
  fVar17 = param_2[9];
  fVar23 = param_2[0xc];
  fVar21 = param_2[0xd];
  fVar2 = param_2[0xe];
  fVar5 = param_2[0xf];
  fVar1 = param_2[10];
  fVar4 = param_2[0xb];
  fVar15 = param_2[6];
  fVar3 = param_2[7];
  fVar8 = param_2[4];
  fVar6 = param_2[5];
  fVar32 = fVar19 * fVar21;
  fVar33 = fVar17 * fVar23;
  fVar29 = fVar6 * fVar23;
  fVar11 = fVar8 * fVar21;
  fVar27 = fVar6 * fVar19;
  fVar30 = fVar6 * fVar1 * fVar5 +
           (((fVar4 * fVar15 * fVar21 + (fVar3 * fVar17 * fVar2 - fVar3 * fVar1 * fVar21)) -
            fVar4 * fVar6 * fVar2) - fVar15 * fVar17 * fVar5);
  fVar13 = fVar8 * fVar17;
  fVar28 = (fVar15 * fVar19 * fVar5 +
           fVar4 * fVar8 * fVar2 +
           ((fVar3 * fVar1 * fVar23 - fVar3 * fVar19 * fVar2) - fVar4 * fVar15 * fVar23)) -
           fVar8 * fVar1 * fVar5;
  fVar14 = fVar13 * fVar5 +
           (((fVar4 * fVar29 + (fVar3 * fVar32 - fVar3 * fVar33)) - fVar4 * fVar11) - fVar27 * fVar5
           );
  fVar31 = (fVar27 * fVar2 + fVar1 * fVar11 + ((fVar15 * fVar33 - fVar15 * fVar32) - fVar1 * fVar29)
           ) - fVar13 * fVar2;
  fVar25 = *param_2;
  fVar10 = param_2[1];
  fVar12 = param_2[2];
  fVar16 = param_2[3];
  fVar26 = fVar16 * fVar31 + fVar12 * fVar14 + fVar25 * fVar30 + fVar10 * fVar28;
  if (fVar26 == 0.0) {
    param_1[3] = 0.0;
    param_1[4] = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    param_1[6] = 0.0;
    param_1[7] = 0.0;
    param_1[8] = 0.0;
    param_1[9] = 0.0;
    param_1[0xd] = 0.0;
    param_1[0xe] = 0.0;
    param_1[0xb] = 0.0;
    param_1[0xc] = 0.0;
    *param_1 = 1.0;
    param_1[5] = 1.0;
    param_1[10] = 1.0;
    fVar26 = 1.0;
  }
  else {
    fVar26 = 1.0 / fVar26;
    fVar24 = fVar10 * fVar23;
    fVar20 = fVar10 * fVar19;
    fVar9 = fVar10 * fVar8;
    fVar22 = fVar25 * fVar21;
    fVar18 = fVar25 * fVar17;
    fVar7 = fVar25 * fVar6;
    *param_1 = fVar30 * fVar26;
    param_1[1] = ((fVar12 * fVar17 * fVar5 +
                  fVar4 * fVar10 * fVar2 +
                  ((fVar16 * fVar1 * fVar21 - fVar16 * fVar17 * fVar2) - fVar4 * fVar12 * fVar21)) -
                 fVar10 * fVar1 * fVar5) * fVar26;
    param_1[2] = (fVar10 * fVar15 * fVar5 +
                 (((fVar3 * fVar12 * fVar21 + (fVar16 * fVar6 * fVar2 - fVar16 * fVar15 * fVar21)) -
                  fVar3 * fVar10 * fVar2) - fVar12 * fVar6 * fVar5)) * fVar26;
    param_1[3] = ((fVar12 * fVar6 * fVar4 +
                  fVar3 * fVar10 * fVar1 +
                  ((fVar16 * fVar15 * fVar17 - fVar16 * fVar6 * fVar1) - fVar3 * fVar12 * fVar17)) -
                 fVar10 * fVar15 * fVar4) * fVar26;
    param_1[4] = fVar28 * fVar26;
    param_1[5] = (fVar25 * fVar1 * fVar5 +
                 (((fVar4 * fVar12 * fVar23 + (fVar16 * fVar19 * fVar2 - fVar16 * fVar1 * fVar23)) -
                  fVar4 * fVar25 * fVar2) - fVar12 * fVar19 * fVar5)) * fVar26;
    param_1[6] = ((fVar12 * fVar8 * fVar5 +
                  fVar3 * fVar25 * fVar2 +
                  ((fVar16 * fVar15 * fVar23 - fVar16 * fVar8 * fVar2) - fVar3 * fVar12 * fVar23)) -
                 fVar25 * fVar15 * fVar5) * fVar26;
    param_1[7] = (fVar25 * fVar15 * fVar4 +
                 (((fVar3 * fVar12 * fVar19 + (fVar16 * fVar8 * fVar1 - fVar16 * fVar15 * fVar19)) -
                  fVar3 * fVar25 * fVar1) - fVar12 * fVar8 * fVar4)) * fVar26;
    param_1[8] = fVar14 * fVar26;
    param_1[9] = ((fVar20 * fVar5 +
                  fVar4 * fVar22 + ((fVar16 * fVar33 - fVar16 * fVar32) - fVar4 * fVar24)) -
                 fVar18 * fVar5) * fVar26;
    param_1[10] = (fVar7 * fVar5 +
                  (((fVar3 * fVar24 + (fVar16 * fVar11 - fVar16 * fVar29)) - fVar3 * fVar22) -
                  fVar9 * fVar5)) * fVar26;
    param_1[0xb] = ((fVar9 * fVar4 +
                    fVar3 * fVar18 + ((fVar16 * fVar27 - fVar16 * fVar13) - fVar3 * fVar20)) -
                   fVar7 * fVar4) * fVar26;
    param_1[0xc] = fVar31 * fVar26;
    param_1[0xd] = (fVar18 * fVar2 +
                   (((fVar1 * fVar24 + (fVar12 * fVar32 - fVar12 * fVar33)) - fVar1 * fVar22) -
                   fVar20 * fVar2)) * fVar26;
    param_1[0xe] = ((fVar9 * fVar2 +
                    fVar15 * fVar22 + ((fVar12 * fVar29 - fVar12 * fVar11) - fVar15 * fVar24)) -
                   fVar7 * fVar2) * fVar26;
    fVar26 = (fVar7 * fVar1 +
             (((fVar15 * fVar20 + (fVar12 * fVar13 - fVar12 * fVar27)) - fVar15 * fVar18) -
             fVar9 * fVar1)) * fVar26;
  }
  param_1[0xf] = fVar26;
  return;
}


/* @001215fc  size=200 */

void FUN_001215fc(long param_1)

{
  uint64_t *puVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint64_t uVar4;
  
  if (*(long *)(param_1 + 0x8d8) == 0) {
    puVar1 = calloc(1,0x50);
    uVar4 = NEON_fmov(0x3f800000,4);
    puVar1[2] = uVar4;
    puVar1[1] = 0x3f80000000000000;
    *puVar1 = 0;
    glGenTextures(1,puVar1 + 3);
    glBindTexture(0xde1,*(uint32_t *)(puVar1 + 3));
    glTexParameteri(0xde1,0x2801,0x2600);
    glTexParameteri(0xde1,0x2800,0x2600);
    glTexParameteri(0xde1,0x2802,0x812f);
    glTexParameteri(0xde1,0x2803,0x812f);
    puVar2 = (uint32_t *)GLTexture_getBound(0xde1);
    if (puVar2 == (uint32_t *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *puVar2;
    }
    glBindTexture(0xde1,uVar3);
    *(uint64_t **)(param_1 + 0x8d8) = puVar1;
  }
  return;
}


/* @00123074  size=476 */

uint64_t FUN_00123074(int param_1)

{
  uint64_t uVar1;
  int iVar2;
  unsigned long uVar3;
  
  uVar1 = 1;
  if (param_1 < 0x8814) {
    if (param_1 < 0x80e0) {
      if (0x804e < param_1) {
        if (param_1 - 0x8055U < 7) {
          return 4;
        }
        if (param_1 - 0x804fU < 5) {
          return 3;
        }
        return 0;
      }
      switch(param_1) {
      case 0x1903:
      case 0x1904:
      case 0x1905:
      case 0x1906:
      case 0x1909:
        goto switchD_001231a8_caseD_1903;
      case 0x1907:
        return 3;
      case 0x1908:
        goto switchD_001231a8_caseD_1908;
      case 0x190a:
        goto switchD_001231a8_caseD_190a;
      default:
        if (param_1 == 0x2a10) {
          return 3;
        }
        if (param_1 == 0x803c) {
          return uVar1;
        }
        return 0;
      }
    }
    if (param_1 - 0x8227U < 0x16) {
      if ((1 << (unsigned long)(param_1 - 0x8227U & 0x1f) & 0x3f0333U) != 0) {
        return 2;
      }
      return uVar1;
    }
    if (param_1 == 0x80e0) {
      return 3;
    }
    iVar2 = 0x80e1;
  }
  else {
    if (param_1 < 0x8d62) {
      switch(param_1) {
      case 0x8814:
      case 0x881a:
        goto switchD_001231a8_caseD_1908;
      case 0x8815:
      case 0x881b:
switchD_001231a8_caseD_1907:
        return 3;
      case 0x8816:
      case 0x8817:
      case 0x8818:
      case 0x8819:
        goto switchD_001231e0_caseD_8c3b;
      default:
        switch(param_1) {
        case 0x8c3a:
        case 0x8c3d:
        case 0x8c41:
          goto switchD_001231a8_caseD_1907;
        default:
          goto switchD_001231e0_caseD_8c3b;
        case 0x8c43:
          goto switchD_001231a8_caseD_1908;
        }
      }
    }
    uVar3 = (unsigned long)(param_1 - 0x8d62U);
    if (param_1 - 0x8d62U < 0x3a) {
      if ((1L << (uVar3 & 0x3f) & 0x140208208208001U) != 0) {
        return 3;
      }
      if ((1L << (uVar3 & 0x3f) & 0x280104104104000U) != 0) {
        return 4;
      }
      if (uVar3 == 0x32) {
        return uVar1;
      }
    }
    switch(param_1) {
    case 0x8f94:
    case 0x8f98:
      goto switchD_001231a8_caseD_1903;
    case 0x8f95:
    case 0x8f99:
switchD_001231a8_caseD_190a:
      return 2;
    case 0x8f96:
    case 0x8f9a:
      goto switchD_001231a8_caseD_1907;
    case 0x8f97:
      goto switchD_001231a8_caseD_1908;
    default:
      iVar2 = 0x906f;
    }
  }
  if (param_1 == iVar2) {
switchD_001231a8_caseD_1908:
    return 4;
  }
switchD_001231e0_caseD_8c3b:
  return 0;
switchD_001231a8_caseD_1903:
  return uVar1;
}


/* @001268f4  size=172 */

void FUN_001268f4(uint64_t *param_1,uint64_t *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  
  fVar18 = param_3[4];
  fVar21 = param_3[5];
  fVar19 = param_3[8];
  fVar23 = param_3[9];
  fVar20 = param_3[0xc];
  fVar25 = param_3[0xd];
  fVar1 = *param_3;
  fVar22 = param_3[6];
  fVar29 = param_3[7];
  fVar24 = param_3[10];
  fVar30 = param_3[0xb];
  fVar26 = param_3[0xe];
  fVar31 = param_3[0xf];
  fVar32 = param_3[1];
  fVar27 = param_3[2];
  fVar28 = param_3[3];
  fVar6 = (float)*param_2;
  fVar7 = (float)((unsigned long)*param_2 >> 0x20);
  fVar8 = (float)param_2[1];
  fVar9 = (float)((unsigned long)param_2[1] >> 0x20);
  fVar2 = (float)param_2[2];
  fVar3 = (float)((unsigned long)param_2[2] >> 0x20);
  fVar4 = (float)param_2[3];
  fVar5 = (float)((unsigned long)param_2[3] >> 0x20);
  fVar10 = (float)param_2[4];
  fVar11 = (float)((unsigned long)param_2[4] >> 0x20);
  fVar12 = (float)param_2[5];
  fVar13 = (float)((unsigned long)param_2[5] >> 0x20);
  fVar14 = (float)param_2[6];
  fVar15 = (float)((unsigned long)param_2[6] >> 0x20);
  fVar16 = (float)param_2[7];
  fVar17 = (float)((unsigned long)param_2[7] >> 0x20);
  param_1[1] = ((uint64_t)(fVar9 * fVar1 + fVar5 * fVar32 + fVar13 * fVar27 + fVar17 * fVar28) << 32 | (uint32_t)(
                        fVar8 * fVar1 + fVar4 * fVar32 + fVar12 * fVar27 + fVar16 * fVar28));
  *param_1 = ((uint64_t)(fVar7 * fVar1 + fVar3 * fVar32 + fVar11 * fVar27 + fVar15 * fVar28) << 32 | (uint32_t)(
                      fVar6 * fVar1 + fVar2 * fVar32 + fVar10 * fVar27 + fVar14 * fVar28));
  param_1[3] = ((uint64_t)(fVar9 * fVar18 + fVar5 * fVar21 + fVar13 * fVar22 + fVar17 * fVar29) << 32 | (uint32_t)(
                        fVar8 * fVar18 + fVar4 * fVar21 + fVar12 * fVar22 + fVar16 * fVar29));
  param_1[2] = ((uint64_t)(fVar7 * fVar18 + fVar3 * fVar21 + fVar11 * fVar22 + fVar15 * fVar29) << 32 | (uint32_t)(
                        fVar6 * fVar18 + fVar2 * fVar21 + fVar10 * fVar22 + fVar14 * fVar29));
  param_1[5] = ((uint64_t)(fVar9 * fVar19 + fVar5 * fVar23 + fVar13 * fVar24 + fVar17 * fVar30) << 32 | (uint32_t)(
                        fVar8 * fVar19 + fVar4 * fVar23 + fVar12 * fVar24 + fVar16 * fVar30));
  param_1[4] = ((uint64_t)(fVar7 * fVar19 + fVar3 * fVar23 + fVar11 * fVar24 + fVar15 * fVar30) << 32 | (uint32_t)(
                        fVar6 * fVar19 + fVar2 * fVar23 + fVar10 * fVar24 + fVar14 * fVar30));
  param_1[7] = ((uint64_t)(fVar9 * fVar20 + fVar5 * fVar25 + fVar13 * fVar26 + fVar17 * fVar31) << 32 | (uint32_t)(
                        fVar8 * fVar20 + fVar4 * fVar25 + fVar12 * fVar26 + fVar16 * fVar31));
  param_1[6] = ((uint64_t)(fVar7 * fVar20 + fVar3 * fVar25 + fVar11 * fVar26 + fVar15 * fVar31) << 32 | (uint32_t)(
                        fVar6 * fVar20 + fVar2 * fVar25 + fVar10 * fVar26 + fVar14 * fVar31));
  return;
}


/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0012bf98(uint32_t param_1,uint32_t *param_2,int *param_3,int *param_4,long *param_5,
                 uint32_t param_6)
{
  /* TODO */
}

/* @0012e990  size=476 */

uint64_t FUN_0012e990(int param_1)

{
  uint64_t uVar1;
  int iVar2;
  unsigned long uVar3;
  
  uVar1 = 1;
  if (param_1 < 0x8814) {
    if (param_1 < 0x80e0) {
      if (0x804e < param_1) {
        if (param_1 - 0x8055U < 7) {
          return 4;
        }
        if (param_1 - 0x804fU < 5) {
          return 3;
        }
        return 0;
      }
      switch(param_1) {
      case 0x1903:
      case 0x1904:
      case 0x1905:
      case 0x1906:
      case 0x1909:
        goto switchD_0012eac4_caseD_1903;
      case 0x1907:
        return 3;
      case 0x1908:
        goto switchD_0012eac4_caseD_1908;
      case 0x190a:
        goto switchD_0012eac4_caseD_190a;
      default:
        if (param_1 == 0x2a10) {
          return 3;
        }
        if (param_1 == 0x803c) {
          return uVar1;
        }
        return 0;
      }
    }
    if (param_1 - 0x8227U < 0x16) {
      if ((1 << (unsigned long)(param_1 - 0x8227U & 0x1f) & 0x3f0333U) != 0) {
        return 2;
      }
      return uVar1;
    }
    if (param_1 == 0x80e0) {
      return 3;
    }
    iVar2 = 0x80e1;
  }
  else {
    if (param_1 < 0x8d62) {
      switch(param_1) {
      case 0x8814:
      case 0x881a:
        goto switchD_0012eac4_caseD_1908;
      case 0x8815:
      case 0x881b:
switchD_0012eac4_caseD_1907:
        return 3;
      case 0x8816:
      case 0x8817:
      case 0x8818:
      case 0x8819:
        goto switchD_0012eafc_caseD_8c3b;
      default:
        switch(param_1) {
        case 0x8c3a:
        case 0x8c3d:
        case 0x8c41:
          goto switchD_0012eac4_caseD_1907;
        default:
          goto switchD_0012eafc_caseD_8c3b;
        case 0x8c43:
          goto switchD_0012eac4_caseD_1908;
        }
      }
    }
    uVar3 = (unsigned long)(param_1 - 0x8d62U);
    if (param_1 - 0x8d62U < 0x3a) {
      if ((1L << (uVar3 & 0x3f) & 0x140208208208001U) != 0) {
        return 3;
      }
      if ((1L << (uVar3 & 0x3f) & 0x280104104104000U) != 0) {
        return 4;
      }
      if (uVar3 == 0x32) {
        return uVar1;
      }
    }
    switch(param_1) {
    case 0x8f94:
    case 0x8f98:
      goto switchD_0012eac4_caseD_1903;
    case 0x8f95:
    case 0x8f99:
switchD_0012eac4_caseD_190a:
      return 2;
    case 0x8f96:
    case 0x8f9a:
      goto switchD_0012eac4_caseD_1907;
    case 0x8f97:
      goto switchD_0012eac4_caseD_1908;
    default:
      iVar2 = 0x906f;
    }
  }
  if (param_1 == iVar2) {
switchD_0012eac4_caseD_1908:
    return 4;
  }
switchD_0012eafc_caseD_8c3b:
  return 0;
switchD_0012eac4_caseD_1903:
  return uVar1;
}


/* @0012f644  size=500 */

/* WARNING: Removing unreachable block (ram,0x0012f6cc) */
/* WARNING: Removing unreachable block (ram,0x0012f708) */
/* WARNING: Removing unreachable block (ram,0x0012f77c) */
/* WARNING: Removing unreachable block (ram,0x0012f7cc) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff68 : 0x0012f788 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void * FUN_0012f644(uint64_t param_1,uint64_t param_2,char *param_3,char *param_4)

{
  int iVar1;
  long lVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  void *__dest;
  long lVar6;
  
  /* stack canary */
  lVar6 = *(long *)(lVar2 + 0x28);
  sVar4 = strlen(param_3);
  sVar5 = strlen(param_4);
  iVar1 = (int)sVar5 + (int)sVar4;
  __dest = malloc((long)(iVar1 + 2));
  sVar4 = strlen(param_3);
  iVar3 = (int)sVar4;
  memcpy(__dest,param_3,(long)iVar3);
  *(uint8_t *)((long)__dest + (long)iVar3) = 10;
  sVar4 = strlen(param_4);
  memcpy((void *)((long)__dest + (long)(iVar3 + 1)),param_4,(long)(int)sVar4);
  *(uint8_t *)((long)__dest + (long)(iVar1 + 1)) = 0;
  if (*(long *)(lVar2 + 0x28) != lVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __dest;
}


/* @0012f838  size=2632 */

char * FUN_0012f838(int param_1,char *param_2,char *param_3)

{
  char *__src;
  char cVar1;
  long lVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  size_t sVar6;
  uint8_t bVar7;
  char *pcVar8;
  char cVar9;
  uint8_t bVar10;
  size_t __n;
  char *__dest;
  uint32_t uVar11;
  int iVar12;
  unsigned long uVar13;
  uint8_t bVar14;
  unsigned long uVar15;
  uint64_t local_d0;
  uint64_t uStack_c8;
  uint64_t local_c0;
  uint64_t uStack_b8;
  uint64_t local_b0;
  uint64_t uStack_a8;
  uint64_t uStack_a0;
  uint64_t uStack_98;
  uint64_t local_90;
  uint64_t uStack_88;
  uint64_t uStack_80;
  uint64_t local_78;
  long local_68;
  
  /* stack canary */
  local_68 = *(long *)(lVar2 + 0x28);
  cVar1 = *param_3;
  if (param_3[5] == '\0') {
    bVar7 = 0x30;
  }
  else if (param_1 == 0x8b31) {
    uVar11 = 0;
    local_90 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_b8 = 0;
    local_c0 = 0;
    do {
      ArrayBuffer_putString(&local_d0,"in vec4 gd_MultiTexCoord%d;\n",uVar11);
      ArrayBuffer_putString(&uStack_b8,"out vec4 gd_TexCoord%d;\n",uVar11);
      ArrayBuffer_putString
                (&uStack_a0,"gd_TexCoord%d = gd_TextureMatrix * gd_MultiTexCoord%d;\n",uVar11,uVar11
                );
      uVar11 = uVar11 + 1;
    } while (uVar11 < (uint8_t)param_3[5]);
    ArrayBuffer_put(&local_d0,0);
    pvVar4 = (void *)FUN_001307e4("in vec4 gd_MultiTexCoord;",local_c0,param_2);
    free(param_2);
    ArrayBuffer_free(&local_d0);
    ArrayBuffer_put(&uStack_b8,0);
    pvVar5 = (void *)FUN_001307e4("out vec4 gd_TexCoord;",uStack_a8,pvVar4);
    free(pvVar4);
    ArrayBuffer_free(&uStack_b8);
    ArrayBuffer_put(&uStack_a0,0);
    param_2 = (char *)FUN_001307e4("gd_TexCoord = gd_TextureMatrix * gd_MultiTexCoord;",local_90,
                                   pvVar5);
    free(pvVar5);
    ArrayBuffer_free(&uStack_a0);
    bVar7 = 0x31;
  }
  else {
    uVar11 = 0;
    uStack_88 = 0;
    local_90 = 0;
    local_78 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_b8 = 0;
    local_c0 = 0;
    do {
      ArrayBuffer_putString(&local_d0,"uniform sampler2D gd_Texture%d;\n",uVar11);
      ArrayBuffer_putString(&uStack_b8,"uniform gd_TexEnvParameters gd_TexEnv%d;\n",uVar11);
      ArrayBuffer_putString(&uStack_a0,"in vec4 gd_TexCoord%d;\n",uVar11);
      ArrayBuffer_putString
                (&uStack_88,
                 "finalColor = applyTexEnv(gd_Texture%d, gd_TexCoord%d, gd_TexEnv%d, finalColor);\n"
                 ,uVar11,uVar11,uVar11);
      uVar11 = uVar11 + 1;
    } while (uVar11 < (uint8_t)param_3[5]);
    ArrayBuffer_put(&local_d0,0);
    pvVar4 = (void *)FUN_001307e4("uniform sampler2D gd_Texture;",local_c0,param_2);
    free(param_2);
    ArrayBuffer_free(&local_d0);
    ArrayBuffer_put(&uStack_b8,0);
    pvVar5 = (void *)FUN_001307e4("uniform gd_TexEnvParameters gd_TexEnv;",uStack_a8,pvVar4);
    free(pvVar4);
    ArrayBuffer_free(&uStack_b8);
    ArrayBuffer_put(&uStack_a0,0);
    pvVar4 = (void *)FUN_001307e4("in vec4 gd_TexCoord;",local_90,pvVar5);
    free(pvVar5);
    ArrayBuffer_free(&uStack_a0);
    ArrayBuffer_put(&uStack_88,0);
    param_2 = (char *)FUN_001307e4("finalColor = applyTexEnv(gd_Texture, gd_TexCoord, gd_TexEnv, finalColor);"
                                   ,local_78,pvVar4);
    free(pvVar4);
    ArrayBuffer_free(&uStack_88);
    bVar7 = 0x31;
  }
  sVar6 = strlen(param_2);
  bVar14 = 0x30;
  if (cVar1 != '\0') {
    bVar14 = 0x34;
  }
  if ((uint32_t)sVar6 < 0x7fffffff) {
    uVar13 = 0;
    __dest = (char *)0x0;
    iVar12 = 0;
    uVar15 = (unsigned long)((uint32_t)sVar6 + 1);
    do {
      while ((cVar1 = param_2[uVar13], cVar1 == '\n' || (uVar13 == (sVar6 & 0xffffffff)))) {
        cVar9 = cVar1;
        if (cVar1 == '\n') {
          cVar9 = '\0';
          param_2[uVar13] = '\0';
        }
        __n = (size_t)((int)uVar13 - iVar12);
        if (cVar9 != '\0') {
          __n = __n + 1;
        }
        __src = param_2 + iVar12;
        iVar12 = (int)__n;
        pcVar8 = __src;
        if (uVar13 == (sVar6 & 0xffffffff)) {
          if (iVar12 == 0) goto LAB_00130244;
          if (cVar9 != '\0') {
            __dest = malloc((long)(iVar12 + 1));
            memcpy(__dest,__src,__n);
            __dest[__n] = '\0';
            pcVar8 = __dest;
          }
        }
        if ((*pcVar8 == '#') && (pcVar8[1] == 'd')) {
          if ((((((pcVar8[2] != 'e') ||
                 (((pcVar8[3] != 'f' || (pcVar8[4] != 'i')) || (pcVar8[5] != 'n')))) ||
                (((pcVar8[6] != 'e' || (pcVar8[7] != ' ')) || (pcVar8[8] != 'G')))) ||
               ((pcVar8[9] != 'D' || (pcVar8[10] != '_')))) ||
              ((pcVar8[0xb] != 'M' ||
               ((((pcVar8[0xc] != 'A' || (pcVar8[0xd] != 'X')) || (pcVar8[0xe] != '_')) ||
                ((pcVar8[0xf] != 'L' || (pcVar8[0x10] != 'I')))))))) ||
             (((pcVar8[0x11] != 'G' || ((pcVar8[0x12] != 'H' || (pcVar8[0x13] != 'T')))) ||
              (bVar10 = bVar14, pcVar8[0x14] != 'S')))) {
            if (pcVar8[1] != 'd') goto LAB_001301f4;
            if ((((((pcVar8[2] != 'e') || (pcVar8[3] != 'f')) || (pcVar8[4] != 'i')) ||
                 (((pcVar8[5] != 'n' || (pcVar8[6] != 'e')) ||
                  ((pcVar8[7] != ' ' || ((pcVar8[8] != 'G' || (pcVar8[9] != 'D')))))))) ||
                (pcVar8[10] != '_')) ||
               (((((pcVar8[0xb] != 'U' || (pcVar8[0xc] != 'S')) || (pcVar8[0xd] != 'E')) ||
                 (((pcVar8[0xe] != '_' || (pcVar8[0xf] != 'T')) ||
                  (((pcVar8[0x10] != 'E' || ((pcVar8[0x11] != 'X' || (pcVar8[0x12] != 'T')))) ||
                   (pcVar8[0x13] != 'U')))))) ||
                ((pcVar8[0x14] != 'R' || (bVar10 = bVar7, pcVar8[0x15] != 'E')))))) {
              if (pcVar8[1] != 'd') goto LAB_001301f4;
              if ((((((((pcVar8[2] == 'e') && (pcVar8[3] == 'f')) && (pcVar8[4] == 'i')) &&
                     ((pcVar8[5] == 'n' && (pcVar8[6] == 'e')))) && (pcVar8[7] == ' ')) &&
                   ((pcVar8[8] == 'G' && (pcVar8[9] == 'D')))) &&
                  (((pcVar8[10] == '_' &&
                    (((pcVar8[0xb] == 'A' && (pcVar8[0xc] == 'L')) && (pcVar8[0xd] == 'P')))) &&
                   (((pcVar8[0xe] == 'H' && (pcVar8[0xf] == 'A')) && (pcVar8[0x10] == '_')))))) &&
                 (((pcVar8[0x11] == 'T' && (pcVar8[0x12] == 'E')) &&
                  ((pcVar8[0x13] == 'S' && (pcVar8[0x14] == 'T')))))) {
                bVar10 = param_3[1];
              }
              else {
                if (pcVar8[1] != 'd') goto LAB_001301f4;
                if (((((pcVar8[2] == 'e') && (pcVar8[3] == 'f')) && (pcVar8[4] == 'i')) &&
                    ((pcVar8[5] == 'n' && (pcVar8[6] == 'e')))) &&
                   ((((pcVar8[7] == ' ' && ((pcVar8[8] == 'G' && (pcVar8[9] == 'D')))) &&
                     (pcVar8[10] == '_')) &&
                    (((pcVar8[0xb] == 'F' && (pcVar8[0xc] == 'O')) && (pcVar8[0xd] == 'G')))))) {
                  bVar10 = param_3[2];
                }
                else {
                  if (pcVar8[1] != 'd') goto LAB_001301f4;
                  if ((((((((pcVar8[2] == 'e') && (pcVar8[3] == 'f')) &&
                          ((pcVar8[4] == 'i' && ((pcVar8[5] == 'n' && (pcVar8[6] == 'e')))))) &&
                         (pcVar8[7] == ' ')) &&
                        (((((pcVar8[8] == 'G' && (pcVar8[9] == 'D')) && (pcVar8[10] == '_')) &&
                          ((pcVar8[0xb] == 'P' && (pcVar8[0xc] == 'O')))) &&
                         ((pcVar8[0xd] == 'I' && ((pcVar8[0xe] == 'N' && (pcVar8[0xf] == 'T'))))))))
                       && (pcVar8[0x10] == '_')) &&
                      ((((pcVar8[0x11] == 'S' && (pcVar8[0x12] == 'P')) && (pcVar8[0x13] == 'R')) &&
                       ((pcVar8[0x14] == 'I' && (pcVar8[0x15] == 'T')))))) && (pcVar8[0x16] == 'E'))
                  {
                    bVar10 = param_3[3];
                  }
                  else {
                    if ((((((pcVar8[1] != 'd') || (pcVar8[2] != 'e')) ||
                          ((pcVar8[3] != 'f' ||
                           (((pcVar8[4] != 'i' || (pcVar8[5] != 'n')) || (pcVar8[6] != 'e')))))) ||
                         (((pcVar8[7] != ' ' || (pcVar8[8] != 'G')) ||
                          ((pcVar8[9] != 'D' ||
                           (((pcVar8[10] != '_' || (pcVar8[0xb] != 'T')) ||
                            ((pcVar8[0xc] != 'R' ||
                             ((((pcVar8[0xd] != 'A' || (pcVar8[0xe] != 'N')) || (pcVar8[0xf] != 'S')
                               ) || ((pcVar8[0x10] != 'F' || (pcVar8[0x11] != 'O')))))))))))))) ||
                        ((pcVar8[0x12] != 'R' || ((pcVar8[0x13] != 'M' || (pcVar8[0x14] != '_'))))))
                       || (((pcVar8[0x15] != 'V' ||
                            (((pcVar8[0x16] != 'E' || (pcVar8[0x17] != 'R')) ||
                             (pcVar8[0x18] != 'T')))) ||
                           ((pcVar8[0x19] != 'E' || (pcVar8[0x1a] != 'X')))))) goto LAB_001301f4;
                    bVar10 = param_3[4];
                  }
                }
              }
              bVar10 = bVar10 | 0x30;
            }
          }
          pcVar8[__n - 1] = bVar10;
        }
LAB_001301f4:
        if (cVar1 == '\n') {
          param_2[uVar13] = '\n';
        }
        if (__dest != (char *)0x0) {
          iVar3 = memcmp(__src,__dest,(long)iVar12);
          if (iVar3 != 0) {
            memcpy(__src,__dest,(long)iVar12);
          }
          free(__dest);
        }
        uVar13 = uVar13 + 1;
        iVar12 = (int)uVar13;
        if (uVar13 == uVar15) goto LAB_00130244;
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 != uVar15);
  }
LAB_00130244:
  if (*(long *)(lVar2 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}


/* @00130654  size=400 */

void FUN_00130654(uint32_t *param_1,long param_2)

{
  long lVar1;
  int iVar2;
  unsigned long uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  uint8_t auStack_78 [32];
  long local_58;
  
  /* stack canary */
  local_58 = *(long *)(lVar1 + 0x28);
  if (0 < *(int *)(param_2 + 0x10)) {
    lVar4 = 0;
    lVar5 = 0;
    do {
      lVar6 = *(long *)(param_2 + 0x18);
      uVar3 = SparseArray_get(param_1 + 0x7c,*(uint32_t *)(lVar6 + lVar4));
      if (uVar3 == 0) {
        FUN_001308f8(auStack_78,0x20,"gd_ProgramEnv[%d]",*(uint32_t *)(lVar6 + lVar4));
        iVar2 = glGetUniformLocation(*param_1,auStack_78);
        uVar3 = (unsigned long)iVar2;
        SparseArray_put(param_1 + 0x7c,*(uint32_t *)(lVar6 + lVar4),uVar3);
      }
      glUniform4fv(uVar3 & 0xffffffff,1,*(uint64_t *)(lVar6 + lVar4 + 8));
      lVar5 = lVar5 + 1;
      lVar4 = lVar4 + 0x10;
    } while (lVar5 < *(int *)(param_2 + 0x10));
  }
  if (0 < *(int *)(param_2 + 0x20)) {
    lVar4 = 0;
    lVar5 = 0;
    do {
      lVar6 = *(long *)(param_2 + 0x28);
      uVar3 = SparseArray_get(param_1 + 0x80,*(uint32_t *)(lVar6 + lVar4));
      if (uVar3 == 0) {
        FUN_001308f8(auStack_78,0x20,"gd_ProgramLocal[%d]",*(uint32_t *)(lVar6 + lVar4));
        iVar2 = glGetUniformLocation(*param_1,auStack_78);
        uVar3 = (unsigned long)iVar2;
        SparseArray_put(param_1 + 0x80,*(uint32_t *)(lVar6 + lVar4),uVar3);
      }
      glUniform4fv(uVar3 & 0xffffffff,1,*(uint64_t *)(lVar6 + lVar4 + 8));
      lVar5 = lVar5 + 1;
      lVar4 = lVar4 + 0x10;
    } while (lVar5 < *(int *)(param_2 + 0x20));
  }
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}




/* @00132480  size=404 */

void FUN_00132480(long param_1,void *param_2)

{
  void *__ptr;
  int *piVar1;
  long lVar2;
  int *piVar3;
  long lVar4;
  uint64_t *puVar5;
  void *__ptr_00;
  void *pvVar6;
  
  if (param_2 == (void *)0x0) {
    return;
  }
  piVar1 = *(int **)(param_1 + 0x228);
  if (0 < *piVar1) {
    lVar2 = 0;
    lVar4 = 8;
    do {
      ArrayList_remove(*(long *)(*(long *)(piVar1 + 2) + lVar4) + 0x18,param_2);
      piVar1 = *(int **)(param_1 + 0x228);
      lVar2 = lVar2 + 1;
      lVar4 = lVar4 + 0x10;
    } while (lVar2 < *piVar1);
  }
  piVar1 = (int *)((long)param_2 + 0x28);
  if (0 < *piVar1) {
    lVar2 = 0;
    do {
      puVar5 = *(uint64_t **)(*(long *)((long)param_2 + 0x30) + lVar2 * 8);
      IntArray_clear(puVar5 + 3);
      if ((void *)*puVar5 != (void *)0x0) {
        free((void *)*puVar5);
        *puVar5 = 0;
      }
      lVar2 = lVar2 + 1;
    } while (lVar2 < *piVar1);
  }
  piVar3 = (int *)((long)param_2 + 0x18);
  if (0 < *piVar3) {
    lVar2 = 0;
    do {
      __ptr_00 = *(void **)(*(long *)((long)param_2 + 0x20) + lVar2 * 0x10 + 8);
      __ptr = *(void **)((long)__ptr_00 + 0x38);
      while (__ptr != (void *)0x0) {
        pvVar6 = *(void **)((long)__ptr + 0x38);
        if (*(void **)((long)__ptr + 8) != (void *)0x0) {
          free(*(void **)((long)__ptr + 8));
        }
        free(__ptr);
        __ptr = pvVar6;
      }
      if (*(void **)((long)__ptr_00 + 8) != (void *)0x0) {
        free(*(void **)((long)__ptr_00 + 8));
        *(uint64_t *)((long)__ptr_00 + 8) = 0;
      }
      if (*(void **)((long)__ptr_00 + 0x10) != (void *)0x0) {
        free(*(void **)((long)__ptr_00 + 0x10));
      }
      free(__ptr_00);
      lVar2 = lVar2 + 1;
    } while (lVar2 < *piVar3);
  }
  ArrayList_free(piVar1,1);
  ArrayMap_free(piVar3,0,0);
  ArrayMap_free((long)param_2 + 0x38,1,1);
  ArrayList_free((long)param_2 + 8,1);
  free(param_2);
  return;
}


/* @00133438  size=6948 */

/* WARNING: Type propagation algorithm not settling */

void FUN_00133438(long param_1,long param_2)

{
  char *pcVar1;
  int iVar2;
  uint8_t bVar3;
  char cVar4;
  uint8_t *puVar5;
  int iVar6;
  int iVar7;
  uint32_t uVar8;
  char *pcVar9;
  uint64_t uVar10;
  char *pcVar11;
  long lVar12;
  unsigned long uVar13;
  char cVar14;
  long *plVar15;
  long lVar16;
  long lVar17;
  unsigned long uVar18;
  int *piVar19;
  uint64_t *puVar20;
  uint64_t *puVar21;
  int *piVar22;
  char *pcVar23;
  int *piVar24;
  uint32_t uVar25;
  uint8_t auStack_140 [8];
  long local_138;
  long local_130;
  int *local_128;
  int *local_120;
  int *local_118;
  uint8_t *local_110;
  uint32_t *local_108;
  uint32_t *local_100;
  uint8_t auStack_f8 [8];
  char acStack_f0 [128];
  long local_70;
  
  local_130 = 0;
  local_70 = *(long *)(local_130 + 0x28);
  local_100 = (uint32_t *)(param_2 + 0x28);
  uVar8 = *local_100;
  uVar18 = (unsigned long)uVar8;
  local_138 = param_1;
  if ((int)uVar8 < 1) {
    piVar24 = (int *)0x0;
    uVar25 = 0;
    local_110 = auStack_f8;
  }
  else {
    uVar25 = 0;
    puVar20 = *(uint64_t **)(param_2 + 0x30);
    uVar13 = uVar18;
    do {
      iVar6 = strcmp(*(char **)*puVar20,"main");
      if (iVar6 == 0) {
        uVar25 = uVar25 + 1;
      }
      uVar13 = uVar13 - 1;
      puVar20 = puVar20 + 1;
    } while (uVar13 != 0);
    piVar24 = (int *)(unsigned long)uVar25;
    local_110 = auStack_140 + -((long)piVar24 * 8 + 0xfU & 0xffffffff0);
    if (0 < (int)uVar8) {
      puVar20 = *(uint64_t **)(param_2 + 0x30);
      iVar6 = 0;
      do {
        puVar21 = (uint64_t *)*puVar20;
        iVar7 = strcmp((char *)*puVar21,"main");
        if (iVar7 == 0) {
          *(uint64_t **)(local_110 + (long)iVar6 * 8) = puVar21;
          iVar6 = iVar6 + 1;
        }
        uVar18 = uVar18 - 1;
        puVar20 = puVar20 + 1;
      } while (uVar18 != 0);
    }
  }
  pcVar9 = strdup("#version 320 es");
  ArrayList_addAt(param_2 + 8,0,pcVar9);
  uVar18 = (unsigned long)*(uint32_t *)(param_2 + 0x28);
  if (0 < (int)*(uint32_t *)(param_2 + 0x28)) {
    plVar15 = *(long **)(param_2 + 0x30);
    do {
      lVar16 = *plVar15;
      if (-1 < *(int *)(lVar16 + 0xc)) {
        *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
        *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
      }
      uVar18 = uVar18 - 1;
      plVar15 = plVar15 + 1;
    } while (uVar18 != 0);
  }
  local_108 = (uint32_t *)(param_2 + 0x18);
  uVar18 = (unsigned long)*local_108;
  if (0 < (int)*local_108) {
    plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
    do {
      iVar6 = *(int *)(*plVar15 + 0x40);
      if (-1 < iVar6) {
        *(int *)(*plVar15 + 0x40) = iVar6 + 1;
      }
      uVar18 = uVar18 - 1;
      plVar15 = plVar15 + 2;
    } while (uVar18 != 0);
  }
  iVar6 = *(int *)(param_2 + 4);
  if (iVar6 == 0x8b30) {
    pcVar9 = strdup("precision highp float;");
    ArrayList_addAt(param_2 + 8,1,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (0 < *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar6 = *(int *)(*plVar15 + 0x40);
        if (0 < iVar6) {
          *(int *)(*plVar15 + 0x40) = iVar6 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    pcVar9 = strdup("precision highp int;");
    ArrayList_addAt(param_2 + 8,2,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (1 < *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar6 = *(int *)(*plVar15 + 0x40);
        if (1 < iVar6) {
          *(int *)(*plVar15 + 0x40) = iVar6 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    pcVar9 = strdup("precision highp sampler2DShadow;");
    ArrayList_addAt(param_2 + 8,3,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (2 < *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar6 = *(int *)(*plVar15 + 0x40);
        if (2 < iVar6) {
          *(int *)(*plVar15 + 0x40) = iVar6 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    iVar6 = *(int *)(param_2 + 4);
    iVar7 = 4;
  }
  else {
    iVar7 = 1;
  }
  puVar5 = &DAT_001149fb;
  if (iVar6 != 0x8b31) goto LAB_00133cb0;
  if ((*(uint8_t *)(param_2 + 0x6c) & 1) == 0) {
    iVar6 = iVar7;
    if ((*(uint8_t *)(param_2 + 0x6c) >> 1 & 1) != 0) goto LAB_001338f8;
LAB_00133820:
    iVar7 = iVar6;
    if ((*(uint8_t *)(param_2 + 0x6c) >> 2 & 1) != 0) goto LAB_001339b0;
LAB_00133828:
    iVar6 = iVar7;
    if ((*(uint8_t *)(param_2 + 0x6c) >> 3 & 1) != 0) goto LAB_00133a68;
LAB_00133830:
    uVar8 = *(uint32_t *)(param_2 + 0x6c);
  }
  else {
    iVar6 = iVar7 + 1;
    pcVar9 = strdup("in vec4 gd_Color;");
    ArrayList_addAt(param_2 + 8,iVar7,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar7 <= iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    if ((*(uint8_t *)(param_2 + 0x6c) >> 1 & 1) == 0) goto LAB_00133820;
LAB_001338f8:
    iVar7 = iVar6 + 1;
    pcVar9 = strdup("in vec4 gd_SecondaryColor;");
    ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    if ((*(uint8_t *)(param_2 + 0x6c) >> 2 & 1) == 0) goto LAB_00133828;
LAB_001339b0:
    iVar6 = iVar7 + 1;
    pcVar9 = strdup("in vec4 gd_Vertex;");
    ArrayList_addAt(param_2 + 8,iVar7,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar7 <= iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    if ((*(uint8_t *)(param_2 + 0x6c) >> 3 & 1) == 0) goto LAB_00133830;
LAB_00133a68:
    pcVar9 = strdup("in vec3 gd_Normal;");
    ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar7 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar7) {
          *(int *)(*plVar15 + 0x40) = iVar7 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    uVar8 = *(uint32_t *)(param_2 + 0x6c);
    iVar6 = iVar6 + 1;
  }
  if ((uVar8 >> 4 & 1) != 0) {
    iVar7 = 0;
    do {
      FUN_001369dc(acStack_f0,0x40,"in vec4 gd_MultiTexCoord%d;",iVar7);
      pcVar9 = strdup(acStack_f0);
      ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
      uVar18 = (unsigned long)*local_100;
      if (0 < (int)*local_100) {
        plVar15 = *(long **)(param_2 + 0x30);
        do {
          lVar16 = *plVar15;
          if (iVar6 <= *(int *)(lVar16 + 0xc)) {
            *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
            *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
          }
          uVar18 = uVar18 - 1;
          plVar15 = plVar15 + 1;
        } while (uVar18 != 0);
      }
      uVar18 = (unsigned long)*local_108;
      if (0 < (int)*local_108) {
        plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
        do {
          iVar2 = *(int *)(*plVar15 + 0x40);
          if (iVar6 <= iVar2) {
            *(int *)(*plVar15 + 0x40) = iVar2 + 1;
          }
          uVar18 = uVar18 - 1;
          plVar15 = plVar15 + 2;
        } while (uVar18 != 0);
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar7 != 8);
    uVar8 = *(uint32_t *)(param_2 + 0x6c);
  }
  iVar7 = iVar6;
  puVar5 = &DAT_00111039;
  if ((uVar8 >> 5 & 1) != 0) {
    iVar7 = iVar6 + 1;
    pcVar9 = strdup("in float gd_FogCoord;");
    ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
  }
LAB_00133cb0:
  iVar6 = iVar7;
  if ((*(uint8_t *)(param_2 + 0x6d) & 0xc) != 0) {
    uVar10 = FUN_00137168(0x20,2,puVar5,"vec4 gd_FrontColor;");
    ArrayList_addAt(param_2 + 8,iVar7,uVar10);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar6 = *(int *)(*plVar15 + 0x40);
        if (iVar7 <= iVar6) {
          *(int *)(*plVar15 + 0x40) = iVar6 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    uVar10 = FUN_00137168(0x20,2,puVar5,"vec4 gd_BackColor;");
    ArrayList_addAt(param_2 + 8,iVar7 + 1,uVar10);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 < *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    iVar6 = iVar7 + 2;
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar7 < iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    if (((*(int *)(param_2 + 4) == 0x8b31) && ((*(uint8_t *)(param_2 + 0x6d) >> 3 & 1) == 0)) &&
       (0 < (int)uVar25)) {
      piVar19 = (int *)0x0;
      do {
        iVar7 = *(int *)(*(long *)(local_110 + (long)piVar19 * 8) + 0xc);
        pcVar9 = strdup("gd_BackColor = gd_FrontColor;");
        ArrayList_addAt(param_2 + 8,iVar7,pcVar9);
        uVar18 = (unsigned long)*local_100;
        if (0 < (int)*local_100) {
          plVar15 = *(long **)(param_2 + 0x30);
          do {
            lVar16 = *plVar15;
            if (iVar7 <= *(int *)(lVar16 + 0xc)) {
              *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
              *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 1;
          } while (uVar18 != 0);
        }
        uVar18 = (unsigned long)*local_108;
        if (0 < (int)*local_108) {
          plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
          do {
            iVar2 = *(int *)(*plVar15 + 0x40);
            if (iVar7 <= iVar2) {
              *(int *)(*plVar15 + 0x40) = iVar2 + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 2;
          } while (uVar18 != 0);
        }
        piVar19 = (int *)((long)piVar19 + 1);
      } while (piVar19 != piVar24);
    }
  }
  iVar7 = iVar6;
  if ((*(uint8_t *)(param_2 + 0x6d) & 0x30) != 0) {
    uVar10 = FUN_00137168(0x20,2,puVar5,"vec4 gd_FrontSecondaryColor;");
    ArrayList_addAt(param_2 + 8,iVar6,uVar10);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar7 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar7) {
          *(int *)(*plVar15 + 0x40) = iVar7 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    uVar10 = FUN_00137168(0x20,2,puVar5,"vec4 gd_BackSecondaryColor;");
    ArrayList_addAt(param_2 + 8,iVar6 + 1,uVar10);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 < *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    iVar7 = iVar6 + 2;
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar6 < iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    if (((*(int *)(param_2 + 4) == 0x8b31) && ((*(uint8_t *)(param_2 + 0x6d) >> 5 & 1) == 0)) &&
       (0 < (int)uVar25)) {
      piVar19 = (int *)0x0;
      do {
        iVar6 = *(int *)(*(long *)(local_110 + (long)piVar19 * 8) + 0xc);
        pcVar9 = strdup("gd_BackSecondaryColor = gd_FrontSecondaryColor;");
        ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
        uVar18 = (unsigned long)*local_100;
        if (0 < (int)*local_100) {
          plVar15 = *(long **)(param_2 + 0x30);
          do {
            lVar16 = *plVar15;
            if (iVar6 <= *(int *)(lVar16 + 0xc)) {
              *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
              *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 1;
          } while (uVar18 != 0);
        }
        uVar18 = (unsigned long)*local_108;
        if (0 < (int)*local_108) {
          plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
          do {
            iVar2 = *(int *)(*plVar15 + 0x40);
            if (iVar6 <= iVar2) {
              *(int *)(*plVar15 + 0x40) = iVar2 + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 2;
          } while (uVar18 != 0);
        }
        piVar19 = (int *)((long)piVar19 + 1);
      } while (piVar19 != piVar24);
    }
  }
  uVar8 = *(uint32_t *)(param_2 + 0x6c);
  if ((uVar8 >> 0xe & 1) != 0) {
    FUN_001369dc(acStack_f0,0x40,"%s vec4 gd_TexCoord[%d];",puVar5,8);
    pcVar9 = strdup(acStack_f0);
    ArrayList_addAt(param_2 + 8,iVar7,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar6 = *(int *)(*plVar15 + 0x40);
        if (iVar7 <= iVar6) {
          *(int *)(*plVar15 + 0x40) = iVar6 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    uVar8 = *(uint32_t *)(param_2 + 0x6c);
    iVar7 = iVar7 + 1;
  }
  if ((uVar8 >> 0xf & 1) == 0) {
    bVar3 = *(uint8_t *)(param_2 + 0x6e);
    iVar6 = iVar7;
  }
  else {
    iVar6 = iVar7 + 1;
    uVar10 = FUN_00137168(0x20,2,puVar5,"float gd_FogFragCoord;");
    ArrayList_addAt(param_2 + 8,iVar7,uVar10);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar7 <= iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    bVar3 = *(uint8_t *)(param_2 + 0x6e);
  }
  if ((bVar3 & 1) == 0) {
    bVar3 = *(uint8_t *)(param_2 + 0x6c);
  }
  else {
    pcVar9 = strdup("out vec4 gd_FragColor;");
    ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar7 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar7) {
          *(int *)(*plVar15 + 0x40) = iVar7 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    bVar3 = *(uint8_t *)(param_2 + 0x6c);
    iVar6 = iVar6 + 1;
  }
  if ((bVar3 >> 6 & 1) == 0) {
    cVar4 = *(char *)(param_2 + 0x6c);
    iVar7 = iVar6;
  }
  else {
    iVar7 = iVar6 + 1;
    pcVar9 = strdup("uniform mat4 gd_ModelViewMatrix;");
    ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    cVar4 = *(char *)(param_2 + 0x6c);
  }
  if (cVar4 < '\0') {
    pcVar9 = strdup("uniform mat4 gd_ProjectionMatrix;");
    ArrayList_addAt(param_2 + 8,iVar7,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar6 = *(int *)(*plVar15 + 0x40);
        if (iVar7 <= iVar6) {
          *(int *)(*plVar15 + 0x40) = iVar6 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    bVar3 = *(uint8_t *)(param_2 + 0x6d);
    iVar7 = iVar7 + 1;
  }
  else {
    bVar3 = *(uint8_t *)(param_2 + 0x6d);
  }
  if ((bVar3 & 1) == 0) {
    uVar8 = *(uint32_t *)(param_2 + 0x6c);
    iVar6 = iVar7;
  }
  else {
    iVar6 = iVar7 + 1;
    pcVar9 = strdup("uniform mat4 gd_ModelViewProjectionMatrix;");
    ArrayList_addAt(param_2 + 8,iVar7,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar7 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar2 = *(int *)(*plVar15 + 0x40);
        if (iVar7 <= iVar2) {
          *(int *)(*plVar15 + 0x40) = iVar2 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    uVar8 = *(uint32_t *)(param_2 + 0x6c);
  }
  if ((uVar8 >> 9 & 1) != 0) {
    FUN_001369dc(acStack_f0,0x40,"uniform mat4 gd_TextureMatrix[%d];",8);
    pcVar9 = strdup(acStack_f0);
    ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar7 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar7) {
          *(int *)(*plVar15 + 0x40) = iVar7 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    uVar8 = *(uint32_t *)(param_2 + 0x6c);
    iVar6 = iVar6 + 1;
  }
  if ((uVar8 >> 0x12 & 1) != 0) {
    local_120 = piVar24;
    pcVar9 = strdup(
                   "struct gd_FogParameters {\nvec4 color;\nfloat density;\nfloat start;\nfloat end;\nfloat scale;\n};\nuniform gd_FogParameters gd_Fog;\n"
                   );
    uVar8 = __strlen_chk(pcVar9,0x7f);
    if (uVar8 < 0x7fffffff) {
      piVar24 = (int *)0x0;
      iVar7 = 0;
      pcVar23 = (char *)0x0;
      piVar22 = (int *)(unsigned long)(uVar8 + 1);
      local_118 = (int *)(unsigned long)uVar8;
      piVar19 = local_118;
      local_128 = piVar22;
      do {
        while ((cVar4 = pcVar9[(long)piVar24], cVar4 != '\n' && (piVar24 != piVar19))) {
          piVar24 = (int *)((long)piVar24 + 1);
          if (piVar24 == piVar22) goto LAB_001348d4;
        }
        cVar14 = cVar4;
        if (cVar4 == '\n') {
          cVar14 = '\0';
          pcVar9[(long)piVar24] = '\0';
        }
        iVar2 = (int)piVar24 - iVar7;
        if (cVar14 != '\0') {
          iVar2 = iVar2 + 1;
        }
        pcVar1 = pcVar9 + iVar7;
        pcVar11 = pcVar1;
        if (piVar24 == piVar19) {
          if (iVar2 == 0) break;
          if (cVar14 != '\0') {
            pcVar23 = malloc((long)(iVar2 + 1));
            memcpy(pcVar23,pcVar1,(long)iVar2);
            pcVar23[iVar2] = '\0';
            pcVar11 = pcVar23;
            piVar22 = local_128;
          }
        }
        pcVar11 = strdup(pcVar11);
        ArrayList_addAt(param_2 + 8,iVar6,pcVar11);
        uVar18 = (unsigned long)*local_100;
        if (0 < (int)*local_100) {
          plVar15 = *(long **)(param_2 + 0x30);
          do {
            lVar16 = *plVar15;
            if (iVar6 <= *(int *)(lVar16 + 0xc)) {
              *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
              *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 1;
          } while (uVar18 != 0);
        }
        uVar18 = (unsigned long)*local_108;
        if (0 < (int)*local_108) {
          plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
          do {
            iVar7 = *(int *)(*plVar15 + 0x40);
            if (iVar6 <= iVar7) {
              *(int *)(*plVar15 + 0x40) = iVar7 + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 2;
          } while (uVar18 != 0);
        }
        if (cVar4 == '\n') {
          pcVar9[(long)piVar24] = '\n';
        }
        if (pcVar23 != (char *)0x0) {
          iVar7 = memcmp(pcVar1,pcVar23,(long)iVar2);
          if (iVar7 != 0) {
            memcpy(pcVar1,pcVar23,(long)iVar2);
          }
          free(pcVar23);
          piVar22 = local_128;
        }
        piVar24 = (int *)((long)piVar24 + 1);
        iVar6 = iVar6 + 1;
        iVar7 = (int)piVar24;
        piVar19 = local_118;
      } while (piVar24 != piVar22);
    }
LAB_001348d4:
    free(pcVar9);
    piVar24 = local_120;
  }
  if ((*(short *)(param_2 + 0x70) < 0x8c) && (*(int *)(param_2 + 4) == 0x8b30)) {
    pcVar9 = strdup("#define GD_ALPHA_TEST 1");
    ArrayList_addAt(param_2 + 8,iVar6,pcVar9);
    uVar18 = (unsigned long)*local_100;
    if (0 < (int)*local_100) {
      plVar15 = *(long **)(param_2 + 0x30);
      do {
        lVar16 = *plVar15;
        if (iVar6 <= *(int *)(lVar16 + 0xc)) {
          *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
          *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 1;
      } while (uVar18 != 0);
    }
    uVar18 = (unsigned long)*local_108;
    if (0 < (int)*local_108) {
      plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
      do {
        iVar7 = *(int *)(*plVar15 + 0x40);
        if (iVar6 <= iVar7) {
          *(int *)(*plVar15 + 0x40) = iVar7 + 1;
        }
        uVar18 = uVar18 - 1;
        plVar15 = plVar15 + 2;
      } while (uVar18 != 0);
    }
    pcVar9 = strdup(
                   "#if GD_ALPHA_TEST\nuniform vec2 gd_AlphaTest;\nvoid applyAlphaTest(float alpha) {\nint alphaTestFunc = int(gd_AlphaTest.x);\nfloat alphaTestRef = gd_AlphaTest.y;\nif (alphaTestFunc == 519 ||\n(alphaTestFunc == 513 && alpha < alphaTestRef) ||\n(alphaTestFunc == 514 && alpha == alphaTestRef) ||\n(alphaTestFunc == 515 && alpha <= alphaTestRef) ||\n(alphaTestFunc == 516 && alpha > alphaTestRef) ||\n(alphaTestFunc == 517 && alpha != alphaTestRef) ||\n(alphaTestFunc == 518 && alpha >= alphaTestRef)) return;\ndiscard;\n}\n#endif\n"
                   );
    if (0 < (int)uVar25) {
      local_118 = (int *)0x0;
      local_128 = (int *)(local_138 + 8);
      local_120 = piVar24;
      do {
        uVar8 = __strlen_chk(pcVar9,0x203);
        if (uVar8 < 0x7fffffff) {
          uVar18 = 0;
          pcVar23 = (char *)0x0;
          iVar6 = 0;
          do {
            while ((cVar4 = pcVar9[uVar18], cVar4 != '\n' && (uVar18 != uVar8))) {
              uVar18 = uVar18 + 1;
              if (uVar18 == uVar8 + 1) goto LAB_00134ba0;
            }
            cVar14 = cVar4;
            if (cVar4 == '\n') {
              cVar14 = '\0';
              pcVar9[uVar18] = '\0';
            }
            iVar7 = (int)uVar18 - iVar6;
            if (cVar14 != '\0') {
              iVar7 = iVar7 + 1;
            }
            pcVar1 = pcVar9 + iVar6;
            pcVar11 = pcVar1;
            if (uVar18 == uVar8) {
              if (iVar7 == 0) break;
              if (cVar14 != '\0') {
                pcVar23 = malloc((long)(iVar7 + 1));
                memcpy(pcVar23,pcVar1,(long)iVar7);
                pcVar23[iVar7] = '\0';
                pcVar11 = pcVar23;
              }
            }
            iVar6 = *(int *)(*(long *)(local_110 + (long)local_118 * 8) + 8);
            pcVar11 = strdup(pcVar11);
            ArrayList_addAt(param_2 + 8,iVar6,pcVar11);
            uVar13 = (unsigned long)*local_100;
            if (0 < (int)*local_100) {
              plVar15 = *(long **)(param_2 + 0x30);
              do {
                lVar16 = *plVar15;
                if (iVar6 <= *(int *)(lVar16 + 0xc)) {
                  *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
                  *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
                }
                uVar13 = uVar13 - 1;
                plVar15 = plVar15 + 1;
              } while (uVar13 != 0);
            }
            uVar13 = (unsigned long)*local_108;
            if (0 < (int)*local_108) {
              plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
              do {
                iVar2 = *(int *)(*plVar15 + 0x40);
                if (iVar6 <= iVar2) {
                  *(int *)(*plVar15 + 0x40) = iVar2 + 1;
                }
                uVar13 = uVar13 - 1;
                plVar15 = plVar15 + 2;
              } while (uVar13 != 0);
            }
            if (cVar4 == '\n') {
              pcVar9[uVar18] = '\n';
            }
            if (pcVar23 != (char *)0x0) {
              iVar6 = memcmp(pcVar1,pcVar23,(long)iVar7);
              if (iVar6 != 0) {
                memcpy(pcVar1,pcVar23,(long)iVar7);
              }
              free(pcVar23);
            }
            uVar18 = uVar18 + 1;
            iVar6 = (int)uVar18;
          } while (uVar18 != uVar8 + 1);
        }
LAB_00134ba0:
        lVar16 = *(long *)(local_110 + (long)local_118 * 8);
        iVar6 = *(int *)(lVar16 + 0xc);
        pcVar23 = strdup("#if GD_ALPHA_TEST");
        ArrayList_addAt(param_2 + 8,iVar6,pcVar23);
        uVar18 = (unsigned long)*local_100;
        if (0 < (int)*local_100) {
          plVar15 = *(long **)(param_2 + 0x30);
          do {
            lVar17 = *plVar15;
            if (iVar6 <= *(int *)(lVar17 + 0xc)) {
              *(int *)(lVar17 + 8) = *(int *)(lVar17 + 8) + 1;
              *(int *)(lVar17 + 0xc) = *(int *)(lVar17 + 0xc) + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 1;
          } while (uVar18 != 0);
        }
        uVar8 = *local_108;
        uVar18 = (unsigned long)uVar8;
        if (0 < (int)uVar8) {
          plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
          uVar13 = uVar18;
          do {
            iVar7 = *(int *)(*plVar15 + 0x40);
            if (iVar6 <= iVar7) {
              *(int *)(*plVar15 + 0x40) = iVar7 + 1;
            }
            uVar13 = uVar13 - 1;
            plVar15 = plVar15 + 2;
          } while (uVar13 != 0);
        }
        if (*local_128 < 1) {
          if ((*(uint8_t *)(param_2 + 0x6e) & 1) == 0) {
            if (0 < (int)uVar8) {
              lVar17 = 0;
              plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
              do {
                lVar12 = *plVar15;
                if ((*(char *)(lVar12 + 0x18) == '\x03') &&
                   ((lVar17 == 0 || (*(int *)(lVar12 + 0x1c) == 0)))) {
                  lVar17 = lVar12;
                }
                uVar18 = uVar18 - 1;
                plVar15 = plVar15 + 2;
              } while (uVar18 != 0);
              goto LAB_00134c88;
            }
          }
          else {
            iVar6 = *(int *)(lVar16 + 0xc);
            pcVar23 = strdup("applyAlphaTest(gd_FragColor.a);");
            ArrayList_addAt(param_2 + 8,iVar6,pcVar23);
            uVar18 = (unsigned long)*local_100;
            if (0 < (int)*local_100) {
              plVar15 = *(long **)(param_2 + 0x30);
              do {
                lVar17 = *plVar15;
                if (iVar6 <= *(int *)(lVar17 + 0xc)) {
                  *(int *)(lVar17 + 8) = *(int *)(lVar17 + 8) + 1;
                  *(int *)(lVar17 + 0xc) = *(int *)(lVar17 + 0xc) + 1;
                }
                uVar18 = uVar18 - 1;
                plVar15 = plVar15 + 1;
              } while (uVar18 != 0);
            }
            uVar18 = (unsigned long)*local_108;
            if (0 < (int)*local_108) {
              plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
              do {
                iVar7 = *(int *)(*plVar15 + 0x40);
                if (iVar6 <= iVar7) {
                  *(int *)(*plVar15 + 0x40) = iVar7 + 1;
                }
                uVar18 = uVar18 - 1;
                plVar15 = plVar15 + 2;
              } while (uVar18 != 0);
            }
          }
        }
        else {
          lVar17 = SparseArray_get(local_128,0);
          if (lVar17 != 0) {
            lVar17 = ArrayMap_get(param_2 + 0x18,lVar17);
LAB_00134c88:
            if (lVar17 != 0) {
              lVar12 = ArrayMap_get(param_2 + 0x18,*(uint64_t *)(lVar17 + 8));
              if ((lVar12 == 0) ||
                 (pcVar23 = "applyAlphaTest(%s[0].a);", *(int *)(lVar12 + 0x28) < 1)) {
                pcVar23 = "applyAlphaTest(%s.a);";
              }
              FUN_001369dc(acStack_f0,0x80,pcVar23,*(uint64_t *)(lVar17 + 8));
              iVar6 = *(int *)(lVar16 + 0xc);
              pcVar23 = strdup(acStack_f0);
              ArrayList_addAt(param_2 + 8,iVar6,pcVar23);
              uVar18 = (unsigned long)*local_100;
              if (0 < (int)*local_100) {
                plVar15 = *(long **)(param_2 + 0x30);
                do {
                  lVar17 = *plVar15;
                  if (iVar6 <= *(int *)(lVar17 + 0xc)) {
                    *(int *)(lVar17 + 8) = *(int *)(lVar17 + 8) + 1;
                    *(int *)(lVar17 + 0xc) = *(int *)(lVar17 + 0xc) + 1;
                  }
                  uVar18 = uVar18 - 1;
                  plVar15 = plVar15 + 1;
                } while (uVar18 != 0);
              }
              uVar18 = (unsigned long)*local_108;
              if (0 < (int)*local_108) {
                plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
                do {
                  iVar7 = *(int *)(*plVar15 + 0x40);
                  if (iVar6 <= iVar7) {
                    *(int *)(*plVar15 + 0x40) = iVar7 + 1;
                  }
                  uVar18 = uVar18 - 1;
                  plVar15 = plVar15 + 2;
                } while (uVar18 != 0);
              }
            }
          }
        }
        iVar6 = *(int *)(lVar16 + 0xc);
        pcVar23 = strdup("#endif");
        ArrayList_addAt(param_2 + 8,iVar6,pcVar23);
        uVar18 = (unsigned long)*local_100;
        if (0 < (int)*local_100) {
          plVar15 = *(long **)(param_2 + 0x30);
          do {
            lVar16 = *plVar15;
            if (iVar6 <= *(int *)(lVar16 + 0xc)) {
              *(int *)(lVar16 + 8) = *(int *)(lVar16 + 8) + 1;
              *(int *)(lVar16 + 0xc) = *(int *)(lVar16 + 0xc) + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 1;
          } while (uVar18 != 0);
        }
        uVar18 = (unsigned long)*local_108;
        if (0 < (int)*local_108) {
          plVar15 = (long *)(*(long *)(param_2 + 0x20) + 8);
          do {
            iVar7 = *(int *)(*plVar15 + 0x40);
            if (iVar6 <= iVar7) {
              *(int *)(*plVar15 + 0x40) = iVar7 + 1;
            }
            uVar18 = uVar18 - 1;
            plVar15 = plVar15 + 2;
          } while (uVar18 != 0);
        }
        local_118 = (int *)((long)local_118 + 1);
      } while (local_118 != local_120);
    }
    free(pcVar9);
  }
  if (*(long *)(local_130 + 0x28) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* @0013575c  size=2296 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_0013575c(int *param_1,void *param_2)

{
  bool bVar1;
  uint8_t *puVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  uint8_t bVar7;
  uint8_t uVar8;
  long lVar9;
  uint32_t uVar10;
  uint8_t bVar11;
  int iVar12;
  int iVar13;
  uint64_t uVar14;
  unsigned long uVar15;
  char *pcVar16;
  uint64_t *puVar17;
  char *pcVar18;
  void *pvVar19;
  long lVar20;
  uint8_t *pbVar21;
  uint32_t uVar22;
  uint8_t *pbVar23;
  long lVar24;
  uint64_t *puVar25;
  size_t __n;
  uint32_t local_ac;
  uint64_t local_a8;
  long local_a0;
  uint64_t local_98;
  long local_90;
  uint64_t local_88;
  uint64_t uStack_80;
  long local_68;
  
  /* stack canary */
  local_68 = *(long *)(lVar9 + 0x28);
  local_ac = 0;
  iVar12 = 0;
  iVar13 = -1;
  uVar22 = 0xffffffff;
  local_a8 = 0;
  local_a0 = 0;
  while( true ) {
    lVar24 = (long)(int)local_ac;
    bVar7 = *(uint8_t *)((long)param_2 + lVar24);
    if (bVar7 == 0x29) {
      iVar12 = iVar12 + -1;
      if ((iVar12 == 0) && (iVar13 != -1)) {
        puVar25 = calloc(1,0x18);
        __n = lVar24 - iVar13;
        pvVar19 = malloc((long)((int)__n + 1));
        memcpy(pvVar19,(void *)((long)param_2 + (long)iVar13),__n);
        *(uint8_t *)((long)pvVar19 + __n) = 0;
        *puVar25 = pvVar19;
        *(int *)(puVar25 + 1) = iVar13;
        *(uint32_t *)((long)puVar25 + 0xc) = local_ac;
        ArrayList_add(&local_a8,puVar25);
        iVar12 = 0;
        iVar13 = -1;
      }
    }
    else if (bVar7 == 0x28) {
      iVar12 = iVar12 + 1;
    }
    if (((*(uint8_t *)((unsigned long)bVar7 + _ctype_table + 1) & 7) == 0) && (bVar7 != 0x5f)) {
      uVar10 = uVar22;
      if (uVar22 != 0xffffffff) {
        bVar11 = FUN_00137344(param_2,uVar22,local_ac);
        if ((bVar11 & iVar13 == -1) != 0) {
          iVar13 = local_ac + 1;
        }
        uVar10 = 0xffffffff;
      }
    }
    else {
      uVar10 = local_ac;
      if (uVar22 != 0xffffffff) {
        uVar10 = uVar22;
      }
    }
    uVar22 = uVar10;
    if (bVar7 == 0) break;
    local_ac = local_ac + 1;
  }
  local_ac = (uint32_t)local_a8 - 1;
  if (0 < (int)(uint32_t)local_a8) {
    do {
      puVar25 = *(uint64_t **)(local_a0 + (unsigned long)local_ac * 8);
      uVar14 = FUN_0013575c(param_1,*puVar25);
      *puVar25 = uVar14;
      param_2 = (void *)FUN_001370c4(uVar14,*(uint32_t *)(puVar25 + 1),
                                     *(uint32_t *)((long)puVar25 + 0xc),param_2);
      free((void *)*puVar25);
      uVar22 = local_ac - 1;
      bVar1 = 0 < (int)local_ac;
      local_ac = uVar22;
    } while (bVar1);
    ArrayList_free(&local_a8,1);
  }
  local_ac = 0;
  uVar22 = 0xffffffff;
  do {
    bVar7 = *(uint8_t *)((long)param_2 + (long)(int)local_ac);
    if (((*(uint8_t *)((unsigned long)bVar7 + _ctype_table + 1) & 7) == 0) && (bVar7 != 0x5f)) {
      uVar10 = uVar22;
      if (uVar22 != 0xffffffff) {
        uVar15 = FUN_00137344(param_2,uVar22);
        if ((uVar15 & 1) == 0) {
LAB_00135fa8:
          uVar10 = 0xffffffff;
        }
        else {
          pcVar16 = (char *)((long)param_2 + (long)(int)uVar22);
          uVar8 = *(uint8_t *)((long)param_2 + (long)(int)local_ac);
          *(uint8_t *)((long)param_2 + (long)(int)local_ac) = 0;
          iVar12 = strcmp(pcVar16,"min");
          if (((((iVar12 == 0) || (iVar12 = strcmp(pcVar16,"max"), iVar12 == 0)) ||
               (iVar12 = strcmp(pcVar16,"pow"), iVar12 == 0)) ||
              ((iVar12 = strcmp(pcVar16,"mod"), iVar12 == 0 ||
               (iVar12 = strcmp(pcVar16,"clamp"), iVar12 == 0)))) ||
             (iVar12 = strcmp(pcVar16,"smoothstep"), iVar12 == 0)) {
            *(uint8_t *)((long)param_2 + (long)(int)local_ac) = uVar8;
            lVar24 = (long)(int)local_ac;
            local_98 = 0;
            local_90 = 0;
            FUN_00136bbc((long)param_2 + lVar24,0,&local_98);
            iVar12 = (int)local_98;
            if ((int)local_98 < 0) {
              iVar12 = (int)local_98 + 1;
            }
            if (1 < (int)local_98) {
              lVar20 = 0;
              do {
                piVar3 = (int *)(local_90 + lVar20 * 8);
                lVar4 = piVar3[1] + lVar24;
                pbVar21 = (uint8_t *)((long)param_2 + *piVar3 + lVar24);
                uVar8 = *(uint8_t *)((long)param_2 + lVar4);
                *(uint8_t *)((long)param_2 + lVar4) = 0;
                bVar11 = *pbVar21;
                if ((bVar11 == 0x2d) || (pbVar23 = pbVar21, uVar22 = (uint32_t)bVar11, bVar11 == 0x2b))
                {
                  pbVar23 = pbVar21 + 1;
                  uVar22 = (uint32_t)*pbVar23;
                }
                if (uVar22 == 0) {
LAB_00135b20:
                  if ((((bVar11 == 0x69) && (pbVar21[1] == 0x6e)) && (pbVar21[2] == 0x74)) &&
                     (pbVar21[3] == 0x28)) goto LAB_00135aac;
                  uVar15 = 0;
                  *(uint8_t *)((long)param_2 + lVar4) = uVar8;
                  do {
                    piVar3 = (int *)(local_90 + uVar15 * 8);
                    lVar20 = *piVar3 + lVar24;
                    lVar4 = piVar3[1] + lVar24;
                    uVar8 = *(uint8_t *)((long)param_2 + lVar4);
                    *(uint8_t *)((long)param_2 + lVar4) = 0;
                    bVar11 = *(uint8_t *)((long)param_2 + lVar20);
                    if ((bVar11 == 0x2d) ||
                       (pbVar21 = (uint8_t *)((long)param_2 + lVar20), bVar11 == 0x2b)) {
                      pbVar21 = (uint8_t *)((long)param_2 + lVar20 + 1);
                      bVar11 = *pbVar21;
                    }
                    if (bVar11 != 0) {
                      do {
                        pbVar21 = pbVar21 + 1;
                        if (9 < bVar11 - 0x30) goto LAB_00135c08;
                        bVar11 = *pbVar21;
                      } while (bVar11 != 0);
                      FUN_001369dc(&local_88,0x20,&DAT_001153a1,(long)param_2 + lVar20);
                      puVar25 = calloc(1,0x18);
                      pcVar16 = strdup((char *)&local_88);
                      *puVar25 = pcVar16;
                      uVar22 = (uint32_t)lVar4;
                      *(int *)(puVar25 + 1) = (int)lVar20;
                      *(uint32_t *)((long)puVar25 + 0xc) = uVar22;
                      ArrayList_add(&local_a8,puVar25);
                      if ((int)local_ac <= (int)uVar22) {
                        local_ac = uVar22;
                      }
                    }
LAB_00135c08:
                    uVar15 = uVar15 + 1;
                    *(uint8_t *)((long)param_2 + lVar4) = uVar8;
                  } while (uVar15 != (uint32_t)(iVar12 >> 1));
                  break;
                }
                do {
                  pbVar23 = pbVar23 + 1;
                  if (9 < uVar22 - 0x30) goto LAB_00135b20;
                  uVar22 = (uint32_t)*pbVar23;
                } while (*pbVar23 != 0);
LAB_00135aac:
                lVar20 = lVar20 + 1;
                *(uint8_t *)((long)param_2 + lVar4) = uVar8;
              } while (lVar20 < iVar12 >> 1);
            }
            puVar25 = &local_98;
          }
          else {
            iVar12 = strcmp(pcVar16,"texture");
            if ((iVar12 == 0) || (iVar12 = strcmp(pcVar16,"textureLod"), iVar12 == 0)) {
              *(uint8_t *)((long)param_2 + (long)(int)local_ac) = uVar8;
            }
            else {
              iVar12 = strcmp(pcVar16,"textureProj");
              *(uint8_t *)((long)param_2 + (long)(int)local_ac) = uVar8;
              if (iVar12 != 0) {
                if (0 < param_1[8]) {
                  lVar20 = (long)(int)local_ac;
                  iVar12 = *param_1;
                  lVar24 = 0;
                  puVar2 = (uint8_t *)((long)param_2 + lVar20);
                  do {
                    puVar25 = *(uint64_t **)(*(long *)(param_1 + 10) + lVar24 * 8);
                    if ((*(int *)(puVar25 + 1) < iVar12) && (*(int *)((long)puVar25 + 0xc) < iVar12)
                       ) {
                      uVar8 = *puVar2;
                      *puVar2 = 0;
                      iVar13 = strcmp((char *)*puVar25,pcVar16);
                      *puVar2 = uVar8;
                      if (iVar13 == 0) {
                        local_98 = 0;
                        local_90 = 0;
                        FUN_00136bbc((long)param_2 + lVar20,0,&local_98);
                        iVar13 = (int)local_98;
                        if ((int)local_98 < 0) {
                          iVar13 = (int)local_98 + 1;
                        }
                        if ((1 < (int)local_98) && (iVar13 >> 1 == *(uint32_t *)(puVar25 + 3))) {
                          uVar15 = 0;
                          do {
                            piVar3 = (int *)(local_90 + uVar15 * 8);
                            iVar6 = *piVar3;
                            lVar4 = piVar3[1] + lVar20;
                            uVar8 = *(uint8_t *)((long)param_2 + lVar4);
                            *(uint8_t *)((long)param_2 + lVar4) = 0;
                            if (*(int *)(puVar25[4] + uVar15 * 4) == 0x1406) {
                              lVar5 = iVar6 + lVar20;
                              bVar11 = *(uint8_t *)((long)param_2 + lVar5);
                              if ((bVar11 == 0x2d) ||
                                 (pbVar21 = (uint8_t *)((long)param_2 + lVar5), bVar11 == 0x2b)) {
                                pbVar21 = (uint8_t *)((long)param_2 + lVar5 + 1);
                                bVar11 = *pbVar21;
                              }
                              if (bVar11 != 0) {
                                do {
                                  pbVar21 = pbVar21 + 1;
                                  if (9 < bVar11 - 0x30) goto LAB_00135d94;
                                  bVar11 = *pbVar21;
                                } while (bVar11 != 0);
                                FUN_001369dc(&local_88,0x20,&DAT_001153a1,(long)param_2 + lVar5);
                                puVar17 = calloc(1,0x18);
                                pcVar18 = strdup((char *)&local_88);
                                *puVar17 = pcVar18;
                                uVar22 = (uint32_t)lVar4;
                                *(int *)(puVar17 + 1) = (int)lVar5;
                                *(uint32_t *)((long)puVar17 + 0xc) = uVar22;
                                ArrayList_add(&local_a8,puVar17);
                                if ((int)local_ac <= (int)uVar22) {
                                  local_ac = uVar22;
                                }
                              }
                            }
LAB_00135d94:
                            uVar15 = uVar15 + 1;
                            *(uint8_t *)((long)param_2 + lVar4) = uVar8;
                          } while (uVar15 != (uint32_t)(iVar13 >> 1));
                        }
                        IntArray_clear(&local_98);
                      }
                    }
                    lVar24 = lVar24 + 1;
                    uVar10 = 0xffffffff;
                  } while (lVar24 < param_1[8]);
                  goto LAB_00135a54;
                }
                goto LAB_00135fa8;
              }
            }
            pcVar18 = pcVar16 + 1;
            if ((*pcVar16 != 't') || (*pcVar18 != 'e')) goto LAB_00135fa8;
            if (((pcVar16[2] == 'x') &&
                (((pcVar16[3] == 't' && (pcVar16[4] == 'u')) && (pcVar16[5] == 'r')))) &&
               ((pcVar16[6] == 'e' && (pcVar16[7] == '(')))) {
LAB_00135c98:
              local_88 = 0;
              uStack_80 = 0;
              FUN_00136bbc((long)param_2 + (long)(int)local_ac,0,&local_88);
              uVar14 = 2;
            }
            else {
              if (*pcVar18 != 'e') goto LAB_00135fa8;
              if (((pcVar16[2] == 'x') && (pcVar16[3] == 't')) &&
                 ((pcVar16[4] == 'u' &&
                  (((((pcVar16[5] == 'r' && (pcVar16[6] == 'e')) && (pcVar16[7] == 'L')) &&
                    ((pcVar16[8] == 'o' && (pcVar16[9] == 'd')))) && (pcVar16[10] == '('))))))
              goto LAB_00135c98;
              if (((*pcVar18 != 'e') || (pcVar16[2] != 'x')) ||
                 ((pcVar16[3] != 't' ||
                  ((((pcVar16[4] != 'u' || (pcVar16[5] != 'r')) || (pcVar16[6] != 'e')) ||
                   (((pcVar16[7] != 'P' || (pcVar16[8] != 'r')) ||
                    ((pcVar16[9] != 'o' || ((pcVar16[10] != 'j' || (pcVar16[0xb] != '('))))))))))))
              goto LAB_00135fa8;
              local_88 = 0;
              uStack_80 = 0;
              FUN_00136bbc((long)param_2 + (long)(int)local_ac,0,&local_88);
              uVar14 = 3;
            }
            FUN_001373ec(param_1,param_2,&local_ac,uVar14,&local_88,&local_a8);
            puVar25 = &local_88;
          }
          IntArray_clear(puVar25);
          uVar10 = 0xffffffff;
        }
      }
    }
    else {
      uVar10 = local_ac;
      if (uVar22 != 0xffffffff) {
        uVar10 = uVar22;
      }
    }
LAB_00135a54:
    uVar22 = uVar10;
    if (bVar7 == 0) {
      uVar22 = (uint32_t)local_a8;
      while (local_ac = uVar22 - 1, 0 < (int)uVar22) {
        puVar25 = *(uint64_t **)(local_a0 + (unsigned long)local_ac * 8);
        pvVar19 = (void *)FUN_001370c4(*puVar25,*(uint32_t *)(puVar25 + 1),
                                       *(uint32_t *)((long)puVar25 + 0xc),param_2);
        free(param_2);
        free((void *)*puVar25);
        param_2 = pvVar19;
        uVar22 = local_ac;
      }
      ArrayList_free(&local_a8,1);
      if (*(long *)(lVar9 + 0x28) == local_68) {
        return param_2;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    local_ac = local_ac + 1;
  } while( true );
}


/* @00136054  size=2440 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * FUN_00136054(long param_1,uint8_t *param_2)

{
  bool bVar1;
  uint8_t bVar2;
  uint8_t bVar3;
  uint8_t bVar4;
  long lVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  uint64_t uVar10;
  void *pvVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  int *piVar15;
  size_t sVar16;
  uint8_t *pbVar17;
  uint8_t *pbVar18;
  int iVar19;
  long lVar20;
  uint8_t *pbVar21;
  uint32_t uVar22;
  uint32_t uVar23;
  unsigned long uVar24;
  uint64_t *puVar25;
  int iVar26;
  unsigned long uVar27;
  unsigned long uVar28;
  char *pcVar29;
  unsigned long uVar30;
  uint8_t *pbVar31;
  unsigned long local_b8;
  long local_b0;
  uint8_t auStack_a8 [64];
  long local_68;
  
  /* stack canary */
  local_68 = *(long *)(lVar5 + 0x28);
  lVar20 = 0;
  bVar4 = 0;
  iVar26 = 0;
  iVar9 = -1;
  local_b8 = 0;
  local_b0 = 0;
  do {
    bVar3 = param_2[lVar20];
    iVar19 = (int)lVar20;
    if (bVar3 == 0x5d) {
      iVar26 = iVar26 + -1;
      if ((iVar26 == 0) && (!(bool)(bVar4 ^ 1))) {
        puVar25 = calloc(1,0x18);
        iVar26 = iVar19 - iVar9;
        pvVar11 = malloc((long)(iVar26 + 1));
        memcpy(pvVar11,param_2 + iVar9,(long)iVar26);
        *(uint8_t *)((long)pvVar11 + (long)iVar26) = 0;
        *puVar25 = pvVar11;
        *(int *)(puVar25 + 1) = iVar9;
        *(int *)((long)puVar25 + 0xc) = iVar19;
        ArrayList_add(&local_b8,puVar25);
        iVar26 = 0;
        iVar9 = -1;
      }
    }
    else if (bVar3 == 0x5b) {
      if (iVar26 == 0) {
        iVar9 = iVar19 + 1;
      }
      bVar4 = iVar26 != 0 & bVar4;
      iVar26 = iVar26 + 1;
    }
    else if (((0 < iVar26) && (bVar3 < 0x40)) &&
            ((1L << ((unsigned long)(uint32_t)bVar3 & 0x3f) & 0xf400ac0000000000U) != 0)) {
      bVar4 = 1;
    }
    lVar20 = lVar20 + 1;
  } while (bVar3 != 0);
  if (0 < (int)(uint32_t)local_b8) {
    lVar20 = (local_b8 & 0xffffffff) + 1;
    uVar22 = (uint32_t)local_b8;
    do {
      uVar22 = uVar22 - 1;
      puVar25 = *(uint64_t **)(local_b0 + (unsigned long)uVar22 * 8);
      uVar10 = FUN_00136054(param_1,*puVar25);
      *puVar25 = uVar10;
      param_2 = (uint8_t *)FUN_001370c4(uVar10,*(uint32_t *)(puVar25 + 1),
                                     *(uint32_t *)((long)puVar25 + 0xc),param_2);
      free((void *)*puVar25);
      lVar20 = lVar20 + -1;
    } while (1 < lVar20);
    ArrayList_free(&local_b8,1);
  }
  uVar28 = 0xffffffff;
  uVar24 = 0;
  iVar26 = 0;
  bVar1 = false;
  bVar8 = false;
  pbVar31 = param_2 + -1;
  uVar27 = 0xffffffff;
  pbVar21 = param_2;
  do {
    pbVar21 = pbVar21 + 1;
    bVar4 = param_2[uVar24];
    uVar30 = (unsigned long)bVar4;
    if (bVar4 == 0x28) {
      bVar1 = true;
joined_r0x00136460:
      if (0 < iVar26) goto LAB_0013625c;
LAB_00136264:
      uVar22 = (uint32_t)uVar27;
      if (((uVar22 == 0xffffffff) || ((bVar4 != 0x2d && (bVar4 != 0x2b)))) ||
         ((param_2[uVar24 - 1] | 0x20) != 0x65)) {
        bVar7 = false;
      }
      else {
        bVar7 = param_2[(int)uVar22] - 0x30 < 10;
      }
      uVar23 = (uint32_t)uVar24;
      if ((((*(uint8_t *)(uVar30 + _ctype_table + 1) & 7) != 0) || (bVar4 == 0x5f)) ||
         ((bool)((bVar4 == 0x2e || 0 < iVar26) | bVar7))) {
        if (uVar22 != 0xffffffff) {
          uVar23 = uVar22;
        }
        uVar27 = (unsigned long)uVar23;
LAB_001362f4:
        iVar9 = (int)uVar27;
        bVar6 = false;
        if ((iVar9 != -1) && ((int)uVar28 != -1)) {
          if (((bVar4 < 0x3c) && ((1L << (uVar30 & 0x3f) & 0x800130000000000U) != 0)) ||
             (iVar9 = strncmp((char *)(param_2 + iVar9),"return",(long)((int)uVar28 - iVar9)),
             iVar9 == 0)) {
LAB_00136334:
            bVar6 = false;
            bVar8 = false;
            uVar28 = 0xffffffff;
            uVar27 = 0xffffffff;
          }
          else {
            bVar6 = true;
          }
        }
      }
      else {
        if ((uVar22 == 0xffffffff) || ((int)uVar28 != -1)) goto LAB_001362f4;
        uVar28 = FUN_00137344(param_2,uVar27,uVar24 & 0xffffffff);
        if ((bVar8 || bVar1) && ((uVar28 & 1) == 0)) {
          lVar20 = (long)(int)uVar22;
          if (((*(uint8_t *)((unsigned long)param_2[lVar20] + _ctype_table + 1) & 7) == 0) &&
             (param_2[lVar20] != 0x5f)) goto LAB_001364d0;
          puVar25 = calloc(1,0x18);
          sVar16 = (int)uVar23 - lVar20;
          pvVar11 = malloc((long)((int)sVar16 + 1));
          memcpy(pvVar11,param_2 + lVar20,sVar16);
          *(uint8_t *)((long)pvVar11 + sVar16) = 0;
          *puVar25 = pvVar11;
          *(uint32_t *)(puVar25 + 1) = uVar22;
          *(uint32_t *)((long)puVar25 + 0xc) = uVar23;
          ArrayList_add(&local_b8);
          if (bVar1) {
            uVar23 = 0xffffffff;
          }
          uVar28 = (unsigned long)uVar23;
          if (bVar1) {
            uVar22 = 0xffffffff;
          }
          uVar27 = (unsigned long)uVar22;
        }
        else {
LAB_001364d0:
          uVar28 = uVar24 & 0xffffffff;
        }
        pbVar18 = param_2 + (int)uVar27;
        if (*pbVar18 == 0x66) {
          if ((pbVar18[1] == 0x6c) &&
             (((pbVar18[2] == 0x6f && (pbVar18[3] == 0x61)) && (pbVar18[4] == 0x74))))
          goto LAB_00136648;
LAB_00136660:
          bVar1 = false;
          if (!bVar8) goto LAB_001362f4;
          goto LAB_00136334;
        }
        if ((((*pbVar18 != 0x76) || (pbVar18[1] != 0x65)) || (pbVar18[2] != 99)) ||
           ((pbVar18[3] != 0x32 &&
            ((pbVar18[1] != 0x65 ||
             (((pbVar18[2] != 99 || (pbVar18[3] != 0x33)) &&
              ((pbVar18[1] != 0x65 || ((pbVar18[2] != 99 || (pbVar18[3] != 0x34))))))))))))
        goto LAB_00136660;
LAB_00136648:
        uVar28 = 0xffffffff;
        bVar1 = false;
        bVar6 = false;
        bVar8 = false;
        uVar27 = 0xffffffff;
      }
      iVar26 = iVar26 - (uint32_t)(bVar4 == 0x5d);
      if ((bVar4 < 0x40) && ((1L << (uVar30 & 0x3f) & 0xf400ac0000000000U) != 0)) {
        iVar9 = (int)uVar27;
        if (((bVar4 == 0x2b) || (bVar4 == 0x2d)) && (pbVar18 = pbVar31, iVar9 != -1)) {
          do {
            do {
              pbVar17 = pbVar18 + -1;
              bVar3 = *pbVar18;
              pbVar18 = pbVar17;
            } while (bVar3 == 0x20);
            pbVar17 = pbVar21;
          } while (bVar3 - 9 < 5);
          do {
            do {
              pbVar18 = pbVar17 + 1;
              bVar2 = *pbVar17;
              pbVar17 = pbVar18;
            } while (bVar2 == 0x20);
          } while (bVar2 - 9 < 5);
          if ((((bVar3 == 0x2b) || (bVar3 == 0x2d)) || (bVar2 == 0x2b)) || (bVar2 == 0x2d))
          goto LAB_00136214;
        }
        if (!(bool)((bVar6 ^ 1U) & bVar1) && !bVar7) {
          if (bVar6) {
            puVar25 = calloc(1,0x18);
            sVar16 = (long)(int)uVar28 - (long)iVar9;
            pvVar11 = malloc((long)((int)sVar16 + 1));
            memcpy(pvVar11,param_2 + iVar9,sVar16);
            *puVar25 = pvVar11;
            *(int *)(puVar25 + 1) = iVar9;
            *(int *)((long)puVar25 + 0xc) = (int)uVar28;
            *(uint8_t *)((long)pvVar11 + sVar16) = 0;
            ArrayList_add(&local_b8,puVar25);
          }
          bVar8 = uVar24 != uVar27;
          uVar28 = 0xffffffff;
          uVar27 = 0xffffffff;
        }
      }
    }
    else {
      if (bVar4 == 0x29) {
        bVar1 = false;
      }
      else if (bVar4 == 0x5b) {
        iVar26 = iVar26 + 1;
        goto joined_r0x00136460;
      }
      if (iVar26 < 1) goto LAB_00136264;
LAB_0013625c:
      if (bVar4 == 0x5d) goto LAB_00136264;
    }
LAB_00136214:
    uVar24 = uVar24 + 1;
    pbVar31 = pbVar31 + 1;
  } while (bVar4 != 0);
  uVar24 = local_b8 & 0xffffffff;
  if (0 < (int)(uint32_t)local_b8) {
    bVar8 = false;
    uVar27 = uVar24;
    do {
      uVar24 = (unsigned long)((int)uVar24 - 1);
      puVar25 = *(uint64_t **)(local_b0 + uVar24 * 8);
      pbVar31 = (uint8_t *)*puVar25;
      pbVar21 = (uint8_t *)ArrayMap_get(param_1 + 0x30,pbVar31);
      if (pbVar21 != (uint8_t *)0x0) {
        pbVar31 = pbVar21;
      }
      pcVar12 = strchr((char *)pbVar31,0x5b);
      if (pcVar12 == (char *)0x0) {
        if (((*(uint8_t *)((unsigned long)*pbVar31 + _ctype_table + 1) & 7) == 0) && (*pbVar31 != 0x5f)) {
          pcVar29 = (char *)0x0;
        }
        else {
          pcVar29 = strchr((char *)pbVar31,0x2e);
          pcVar13 = pcVar29;
          if (pcVar29 != (char *)0x0) goto LAB_001366e8;
        }
      }
      else {
        pcVar29 = pcVar12;
        pcVar13 = (char *)0x0;
LAB_001366e8:
        *pcVar29 = '\0';
        pcVar29 = pcVar13;
      }
      for (; (*pbVar31 == 0x2d || (*pbVar31 == 0x2b)); pbVar31 = pbVar31 + 1) {
      }
      pcVar13 = strchr((char *)pbVar31,0x2b);
      if (pcVar13 != (char *)0x0) {
        *pcVar13 = '\0';
      }
      pcVar14 = strchr((char *)pbVar31,0x2d);
      if (pcVar14 != (char *)0x0) {
        *pcVar14 = '\0';
      }
      piVar15 = (int *)ArrayMap_get(param_1 + 0x10,pbVar31);
      if ((piVar15 != (int *)0x0) && ((*piVar15 - 0x8b50U < 3 || (*piVar15 == 0x1406)))) {
        bVar8 = true;
      }
      puVar25[2] = piVar15;
      if (pcVar12 != (char *)0x0) {
        *pcVar12 = '[';
      }
      if (pcVar29 != (char *)0x0) {
        *pcVar29 = '.';
      }
      if (pcVar13 != (char *)0x0) {
        *pcVar13 = '+';
      }
      if (pcVar14 != (char *)0x0) {
        *pcVar14 = '-';
      }
      uVar28 = uVar27 - 1;
      bVar1 = 0 < (long)uVar27;
      uVar27 = uVar28;
    } while (uVar28 != 0 && bVar1);
    if (0 < (int)(uint32_t)local_b8) {
      uVar24 = local_b8 & 0xffffffff;
      do {
        puVar25 = *(uint64_t **)(local_b0 + (uVar24 - 1 & 0xffffffff) * 8);
        if (bVar8) {
          pbVar31 = (uint8_t *)ArrayMap_get(param_1 + 0x30,*puVar25);
          if ((pbVar31 == (uint8_t *)0x0) && (pbVar31 = (uint8_t *)*puVar25, pbVar31 == (uint8_t *)0x0)) {
LAB_001368dc:
            if ((int *)puVar25[2] == (int *)0x0) goto LAB_0013684c;
            iVar26 = *(int *)puVar25[2];
            if (iVar26 < 0x8b54) {
              if (iVar26 == 0x1404) {
                uVar22 = 1;
              }
              else {
                if (iVar26 != 0x8b53) goto LAB_0013684c;
                uVar22 = 2;
              }
            }
            else if (iVar26 == 0x8b55) {
              uVar22 = 4;
            }
            else {
              if (iVar26 != 0x8b54) goto LAB_0013684c;
              uVar22 = 3;
            }
            pcVar29 = (char *)*puVar25;
            pcVar12 = strrchr(pcVar29,0x5d);
            lVar20 = 0;
            if (pcVar12 != (char *)0x0) {
              lVar20 = (long)pcVar12 - (long)pcVar29;
            }
            pcVar12 = strchr(pcVar29 + lVar20,0x2e);
            if (pcVar12 != (char *)0x0) {
              sVar16 = strlen(pcVar12 + 1);
              uVar22 = (uint32_t)sVar16;
            }
            if ((uVar22 & 0xff) < 2) {
              pbVar31 = (uint8_t *)*puVar25;
              uVar10 = 0x40;
              pcVar12 = "float(%s)";
              goto LAB_00136828;
            }
            FUN_001369dc(auStack_a8,0x40,"vec%d(%s)",uVar22 & 0xff,*puVar25);
          }
          else {
            bVar4 = *pbVar31;
            if ((bVar4 == 0x2d) || (pbVar21 = pbVar31, bVar4 == 0x2b)) {
              pbVar21 = pbVar31 + 1;
              bVar4 = *pbVar21;
            }
            if (bVar4 == 0) goto LAB_001368dc;
            do {
              pbVar21 = pbVar21 + 1;
              if (9 < bVar4 - 0x30) goto LAB_001368dc;
              bVar4 = *pbVar21;
            } while (bVar4 != 0);
            uVar10 = 8;
            pcVar12 = "%s.0";
LAB_00136828:
            FUN_001369dc(auStack_a8,uVar10,pcVar12,pbVar31);
          }
          pbVar31 = (uint8_t *)FUN_001370c4(auStack_a8,*(uint32_t *)(puVar25 + 1),
                                         *(uint32_t *)((long)puVar25 + 0xc),param_2);
          free(param_2);
          param_2 = pbVar31;
        }
LAB_0013684c:
        free((void *)*puVar25);
        bVar1 = 1 < (long)uVar24;
        uVar24 = uVar24 - 1;
      } while (bVar1);
    }
  }
  ArrayList_free(&local_b8,1);
  if (*(long *)(lVar5 + 0x28) == local_68) {
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* @00136a80  size=316 */

void FUN_00136a80(char *param_1)

{
  uint8_t bVar1;
  long lVar2;
  unsigned long uVar3;
  long lVar4;
  uint32_t uVar5;
  uint8_t *pbVar6;
  uint8_t *pbVar7;
  uint8_t *pbVar8;
  uint8_t local_a8 [128];
  long local_28;
  
  /* stack canary */
  local_28 = *(long *)(lVar2 + 0x28);
  if ((*param_1 == '[') || (param_1 = strchr(param_1,0x5b), param_1 != (char *)0x0)) {
    bVar1 = param_1[1];
    uVar3 = 0;
    while ((bVar1 != 0 && (bVar1 != 0x5d))) {
      local_a8[uVar3] = bVar1;
      bVar1 = (param_1 + 1)[uVar3 + 1];
      uVar3 = uVar3 + 1;
    }
    local_a8[uVar3 & 0xffffffff] = 0;
    lVar4 = __strlen_chk(local_a8,0x80);
    pbVar6 = local_a8 + lVar4 + 1;
    do {
      do {
        pbVar7 = pbVar6 + -2;
        pbVar6 = pbVar6 + -1;
      } while (*pbVar7 == 0x20);
    } while (*pbVar7 - 9 < 5);
    *pbVar6 = 0;
    pbVar6 = local_a8;
    do {
      do {
        pbVar7 = pbVar6;
        pbVar6 = pbVar7 + 1;
        bVar1 = *pbVar7;
      } while (bVar1 == 0x20);
    } while (bVar1 - 9 < 5);
    if ((bVar1 == 0x2b) || (pbVar8 = pbVar7, bVar1 == 0x2d)) {
      bVar1 = *pbVar6;
      pbVar8 = pbVar6;
    }
    uVar5 = (uint32_t)bVar1;
    if (uVar5 == 0) {
LAB_00136b8c:
      lVar4 = 0x7fffffff;
    }
    else {
      do {
        pbVar8 = pbVar8 + 1;
        if (9 < uVar5 - 0x30) goto LAB_00136b8c;
        uVar5 = (uint32_t)*pbVar8;
      } while (uVar5 != 0);
      lVar4 = strtol((char *)pbVar7,(char **)0x0,10);
    }
  }
  else {
    lVar4 = 0xffffffff;
  }
  if (*(long *)(lVar2 + 0x28) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(lVar4);
}



/* STUBBED — needs manual NEON/SIMD reconstruction */

uint32_t FUN_00136e4c(char *param_1)
{
  /* TODO */
}





/* @001375cc  size=276 */

void * FUN_001375cc(char *param_1,char *param_2,char *param_3)

{
  uint32_t uVar1;
  size_t sVar2;
  void *__ptr;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  unsigned long uVar6;
  long lVar7;
  
  sVar2 = strlen(param_3);
  uVar1 = (int)sVar2 + 1;
  uVar6 = (unsigned long)uVar1;
  __ptr = malloc((long)(int)uVar1);
  pcVar3 = strstr(param_3,param_1);
  if (pcVar3 == (char *)0x0) {
    lVar7 = 0;
  }
  else {
    lVar7 = 0;
    do {
      memcpy((void *)((long)__ptr + lVar7),param_3,(long)pcVar3 - (long)param_3);
      iVar5 = (int)((long)pcVar3 - (long)param_3) + (int)lVar7;
      sVar2 = strlen(param_1);
      param_3 = pcVar3 + sVar2;
      sVar2 = strlen(param_1);
      sVar4 = strlen(param_2);
      uVar6 = ((uVar6 & 0xffffffff) - sVar2) + sVar4;
      __ptr = realloc(__ptr,(long)(int)uVar6);
      sVar2 = strlen(param_2);
      memcpy((void *)((long)__ptr + (long)iVar5),param_2,sVar2);
      sVar2 = strlen(param_2);
      lVar7 = (long)((int)sVar2 + iVar5);
      pcVar3 = strstr(param_3,param_1);
    } while (pcVar3 != (char *)0x0);
  }
  strcpy((char *)((long)__ptr + lVar7),param_3);
  return __ptr;
}


/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_001376e0(int *param_1)
{
  /* TODO */
}

/* @00138d7c  size=172 */

uint32_t * FUN_00138d7c(uint32_t param_1)

{
  long *plVar1;
  uint32_t *puVar2;
  uint64_t *puVar3;
  uint64_t uVar4;
  
  pthread_mutex_lock((&glx_context_mutex));
  plVar1 = (long *)(&currentRenderer);
  puVar2 = (uint32_t *)SparseArray_get(*(uint64_t *)(*plVar1 + 0x5d8),param_1);
  if (puVar2 == (uint32_t *)&DAT_00144f24) {
    puVar2 = calloc(1,0x14);
    glGenQueries(1,puVar2 + 1);
    puVar3 = (uint64_t *)(&currentRenderer);
    uVar4 = *(uint64_t *)((uint32_t *)*puVar3 + 0x176);
    *puVar2 = *(uint32_t *)*puVar3;
    SparseArray_put(uVar4,param_1,puVar2);
  }
  pthread_mutex_unlock((&glx_context_mutex));
  return puVar2;
}


/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013a2dc(uint8_t *param_1,uint8_t *param_2,unsigned long param_3)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013a974(long param_1,uint8_t *param_2)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013aaa0(long *param_1)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013b00c(uint16_t *param_1,long param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,unsigned long param_8,uint8_t param_9)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013b260(unsigned long param_1,long param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,uint8_t param_9)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013c1d4(long param_1,uint64_t param_2,uint64_t param_3,uint64_t param_4)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013cd54(uint32_t param_1,uint8_t *param_2,long param_3,uint64_t param_4)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013d0d0(uint8_t *param_1,uint64_t param_2)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013d240(uint8_t *param_1,long param_2,uint64_t param_3)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013d8f4(uint8_t *param_1,uint64_t param_2)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

unsigned long FUN_0013f308(unsigned long param_1)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013f340(void)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

unsigned long FUN_0013f37c(long *param_1)
{
  /* TODO */
}

/* STUBBED — needs manual NEON/SIMD reconstruction */

void FUN_0013f410(void)
{
  /* TODO */
}

