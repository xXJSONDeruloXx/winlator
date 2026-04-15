/*
 * shader_material.c — Shader material uniform management
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

/* @0012eb6c  size=2776 */

uint32_t * ShaderMaterial_create(char *param_1)

{
  char cVar1;
  long lVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t *puVar5;
  uint64_t uVar6;
  char *pcVar7;
  uint64_t uVar8;
  unsigned long uVar9;
  unsigned long uVar10;
  unsigned long uVar11;
  unsigned long uVar12;
  uint32_t *puVar13;
  int local_2a4;
  void *local_2a0;
  void *local_298;
  uint64_t local_290;
  uint64_t uStack_288;
  uint64_t uStack_280;
  uint64_t uStack_278;
  uint64_t local_270;
  uint64_t uStack_268;
  uint64_t uStack_260;
  uint64_t uStack_258;
  uint8_t auStack_90 [32];
  long local_70;
  
  /* stack canary setup (elided) */
  local_70 = *(long *)(lVar2 + 0x28);
  puVar5 = calloc(1,0x210);
  uVar6 = FUN_0012f644();
  if (*(long *)(param_1 + 0x10) == 0) {
    pcVar7 = 
    "void main() {\n#if GD_MAX_LIGHTS > 0\nvec4 finalColor = vec4(gd_FrontColor.rgb * gd_TotalDiffuseLight + gd_TotalSpecularLight, gd_FrontColor.a);\n#else\nvec4 finalColor = gd_FrontColor;\n#endif\n#if GD_POINT_SPRITE\nif (gd_Point.size > 0.0) {\nfinalColor *= texture(gd_PointSprite, gl_PointCoord);\nif (finalColor.a <= 0.1) discard;\n}\n#endif\n#if GD_USE_TEXTURE\nfinalColor = applyTexEnv(gd_Texture, gd_TexCoord, gd_TexEnv, finalColor);\n#endif\n#if GD_FOG\nfinalColor.rgb = applyFog(gd_Fog, finalColor.rgb, gd_FogFragCoord);\n#endif\n#if GD_ALPHA_TEST\napplyAlphaTest(finalColor.a);\n#endif\ngd_FragColor = finalColor;\n}\n"
    ;
  }
  else {
    pcVar7 = *(char **)(*(long *)(param_1 + 0x10) + 0x30);
  }
  strdup(pcVar7);
  uVar8 = FUN_0012f644();
  local_298 = (void *)FUN_0012f838(0x8b31,uVar6,param_1);
  local_2a0 = (void *)FUN_0012f838(0x8b30,uVar8,param_1);
  uVar9 = glCreateShader(0x8b31);
  uVar10 = uVar9 & 0xffffffff;
  glShaderSource(uVar9,1,&local_298,0);
  glCompileShader(uVar10);
  glGetShaderiv(uVar10,0x8b81,&local_2a4);
  if (local_2a4 == 0) {
    glGetShaderInfoLog(uVar10,0x200,0,&local_290);
    pcVar7 = "gladio: could not compile vertex shader\n%s\n";
  }
  else {
    uVar9 = glCreateShader(0x8b30);
    uVar11 = uVar9 & 0xffffffff;
    glShaderSource(uVar9,1,&local_2a0,0);
    glCompileShader(uVar11);
    glGetShaderiv(uVar11,0x8b81,&local_2a4);
    if (local_2a4 != 0) {
      uVar9 = glCreateProgram();
      uVar12 = uVar9 & 0xffffffff;
      glAttachShader(uVar9,uVar10);
      glAttachShader(uVar12,uVar11);
      glLinkProgram(uVar12);
      glDeleteShader(uVar10);
      glDeleteShader(uVar11);
      free(local_298);
      free(local_2a0);
      *puVar5 = (int)uVar9;
      *(uint64_t *)(puVar5 + 4) = 0xffffffffffffffff;
      *(uint64_t *)(puVar5 + 2) = 0xffffffffffffffff;
      *(uint64_t *)(puVar5 + 8) = 0xffffffffffffffff;
      *(uint64_t *)(puVar5 + 6) = 0xffffffffffffffff;
      *(uint64_t *)(puVar5 + 0xb) = 0xffffffffffffffff;
      *(uint64_t *)(puVar5 + 9) = 0xffffffffffffffff;
      uVar3 = glGetAttribLocation(uVar12,"gd_Vertex");
      puVar5[2] = uVar3;
      uVar3 = glGetAttribLocation(*puVar5,"gd_Color");
      puVar5[3] = uVar3;
      uVar3 = glGetAttribLocation(*puVar5,"gd_Normal");
      cVar1 = param_1[4];
      puVar5[4] = uVar3;
      if (cVar1 == '\0') {
        uVar3 = 0xffffffff;
        puVar5[0xe] = 0xffffffff;
      }
      else {
        uVar3 = glGetUniformLocation(*puVar5,"gd_ModelViewMatrix");
        puVar5[0xe] = uVar3;
        uVar3 = glGetUniformLocation(*puVar5,"gd_ProjectionMatrix");
      }
      cVar1 = param_1[5];
      puVar5[0xd] = uVar3;
      if (cVar1 != '\0') {
        uVar3 = glGetUniformLocation(*puVar5,"gd_TextureMatrix");
        uVar9 = 0;
        puVar5[0xf] = uVar3;
        *(uint64_t *)(puVar5 + 0x44) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x42) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x14) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x12) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x18) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x16) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x1c) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x1a) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x20) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x1e) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x24) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x22) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x28) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x26) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x2c) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x2a) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x30) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x2e) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x34) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x32) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x38) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x36) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x3c) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x3a) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x40) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x3e) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x48) = 0xffffffffffffffff;
        *(uint64_t *)(puVar5 + 0x46) = 0xffffffffffffffff;
        puVar13 = puVar5 + 0x1f;
        do {
          FUN_001308f8(&local_290,0x20,"gd_Texture%d",uVar9 & 0xffffffff);
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar5[uVar9 + 0x12] = uVar3;
          FUN_001308f8(&local_290,0x20,"gd_TexEnv%d.%s",uVar9 & 0xffffffff,&DAT_001110e2);
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-5] = uVar3;
          FUN_001308f8(&local_290,0x20,"gd_TexEnv%d.%s",uVar9 & 0xffffffff,"color");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-4] = uVar3;
          FUN_001308f8(&local_290,0x20,"gd_TexEnv%d.%s",uVar9 & 0xffffffff,"combineRGBA");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-3] = uVar3;
          FUN_001308f8(&local_290,0x20,"gd_TexEnv%d.%s",uVar9 & 0xffffffff,"rgbaScale");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-2] = uVar3;
          FUN_001308f8(&local_290,0x20,"gd_TexEnv%d.%s",uVar9 & 0xffffffff,"sourceRGBA");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-1] = uVar3;
          FUN_001308f8(&local_290,0x20,"gd_TexEnv%d.%s",uVar9 & 0xffffffff,"operandRGBA");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          uVar9 = uVar9 + 1;
          *puVar13 = uVar3;
          puVar13 = puVar13 + 6;
        } while (uVar9 != 8);
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",0);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[5] = uVar3;
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",1);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[6] = uVar3;
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",2);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[7] = uVar3;
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",3);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[8] = uVar3;
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",4);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[9] = uVar3;
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",5);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[10] = uVar3;
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",6);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[0xb] = uVar3;
        FUN_001308f8(auStack_90,0x20,"gd_MultiTexCoord%d",7);
        uVar3 = glGetAttribLocation(*puVar5,auStack_90);
        puVar5[0xc] = uVar3;
      }
      if (param_1[1] != '\0') {
        uVar3 = glGetUniformLocation(*puVar5,"gd_AlphaTest");
        puVar5[0x10] = uVar3;
      }
      if (param_1[2] != '\0') {
        uVar3 = *puVar5;
        uStack_268 = 0;
        local_270 = 0;
        uStack_258 = 0;
        uStack_260 = 0;
        uStack_288 = 0;
        local_290 = 0;
        uStack_278 = 0;
        uStack_280 = 0;
        FUN_001308f8(&local_290,0x40,"gd_Fog.%s","color");
        uVar4 = glGetUniformLocation(uVar3,&local_290);
        puVar5[0x51] = uVar4;
        FUN_001308f8(&local_290,0x40,"gd_Fog.%s","density");
        uVar4 = glGetUniformLocation(uVar3,&local_290);
        puVar5[0x52] = uVar4;
        FUN_001308f8(&local_290,0x40,"gd_Fog.%s","start");
        uVar4 = glGetUniformLocation(uVar3,&local_290);
        puVar5[0x53] = uVar4;
        FUN_001308f8(&local_290,0x40,"gd_Fog.%s",&DAT_001152c2);
        uVar4 = glGetUniformLocation(uVar3,&local_290);
        puVar5[0x54] = uVar4;
        FUN_001308f8(&local_290,0x40,"gd_Fog.%s","scale");
        uVar3 = glGetUniformLocation(uVar3,&local_290);
        puVar5[0x55] = uVar3;
      }
      uVar3 = *puVar5;
      uStack_268 = 0;
      local_270 = 0;
      uStack_258 = 0;
      uStack_260 = 0;
      uStack_288 = 0;
      local_290 = 0;
      uStack_278 = 0;
      uStack_280 = 0;
      FUN_001308f8(&local_290,0x40,"gd_Point.%s",&DAT_001121dc);
      uVar4 = glGetUniformLocation(uVar3,&local_290);
      puVar5[0x4a] = uVar4;
      FUN_001308f8(&local_290,0x40,"gd_Point.%s","sizeMin");
      uVar4 = glGetUniformLocation(uVar3,&local_290);
      puVar5[0x4b] = uVar4;
      FUN_001308f8(&local_290,0x40,"gd_Point.%s","sizeMax");
      uVar4 = glGetUniformLocation(uVar3,&local_290);
      puVar5[0x4c] = uVar4;
      FUN_001308f8(&local_290,0x40,"gd_Point.%s","fadeThresholdSize");
      uVar4 = glGetUniformLocation(uVar3,&local_290);
      puVar5[0x4d] = uVar4;
      FUN_001308f8(&local_290,0x40,"gd_Point.%s","distanceConstantAttenuation");
      uVar4 = glGetUniformLocation(uVar3,&local_290);
      puVar5[0x4e] = uVar4;
      FUN_001308f8(&local_290,0x40,"gd_Point.%s","distanceLinearAttenuation");
      uVar4 = glGetUniformLocation(uVar3,&local_290);
      puVar5[0x4f] = uVar4;
      FUN_001308f8(&local_290,0x40,"gd_Point.%s","distanceQuadraticAttenuation");
      uVar3 = glGetUniformLocation(uVar3,&local_290);
      cVar1 = *param_1;
      puVar5[0x50] = uVar3;
      if (cVar1 != '\0') {
        uVar9 = 0;
        uStack_288 = 0;
        local_290 = 0;
        uStack_278 = 0;
        uStack_280 = 0;
        puVar13 = puVar5 + 0x5c;
        do {
          FUN_001308f8(&local_290,0x20,"lights[%d].%s",uVar9 & 0xffffffff,"ambient");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-6] = uVar3;
          FUN_001308f8(&local_290,0x20,"lights[%d].%s",uVar9 & 0xffffffff,"diffuse");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-5] = uVar3;
          FUN_001308f8(&local_290,0x20,"lights[%d].%s",uVar9 & 0xffffffff,"specular");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-4] = uVar3;
          FUN_001308f8(&local_290,0x20,"lights[%d].%s",uVar9 & 0xffffffff,"position");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-3] = uVar3;
          FUN_001308f8(&local_290,0x20,"lights[%d].%s",uVar9 & 0xffffffff,"attenuation");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-2] = uVar3;
          FUN_001308f8(&local_290,0x20,"lights[%d].%s",uVar9 & 0xffffffff,"spotCutoffExponent");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          puVar13[-1] = uVar3;
          FUN_001308f8(&local_290,0x20,"lights[%d].%s",uVar9 & 0xffffffff,"spotDirection");
          uVar3 = glGetUniformLocation(*puVar5,&local_290);
          uVar9 = uVar9 + 1;
          *puVar13 = uVar3;
          puVar13 = puVar13 + 7;
        } while (uVar9 != 4);
        uVar3 = glGetUniformLocation(*puVar5,"numLights");
        puVar5[0x72] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",0,"ambient");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x73] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",0,"diffuse");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x74] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",0,"specular");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x75] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",0,"emission");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x76] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",1,"ambient");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x77] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",1,"diffuse");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x78] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",1,"specular");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x79] = uVar3;
        FUN_001308f8(&local_290,0x20,"materials[%d].%s",1,"emission");
        uVar3 = glGetUniformLocation(*puVar5,&local_290);
        puVar5[0x7a] = uVar3;
      }
      if (*(long *)(lVar2 + 0x28) == local_70) {
        return puVar5;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    glGetShaderInfoLog(uVar11,0x200,0,&local_290);
    pcVar7 = "gladio: could not compile fragment shader\n%s\n";
  }
  __android_log_print(3,"System.out",pcVar7,&local_290);
                    /* WARNING: Subroutine does not return */
  exit(1);
}


/* @00130280  size=64 */

void ShaderMaterial_destroy(uint32_t *param_1)

{
  if (param_1 != (uint32_t *)0x0) {
    SparseArray_free(param_1 + 0x7c,0);
    SparseArray_free(param_1 + 0x80,0);
    glDeleteProgram(*param_1);
    return;
  }
  return;
}


/* @001302c0  size=100 */

void ShaderMaterial_updatePointUniforms(long param_1,long param_2)

{
  glUniform1f(*(uint32_t *)(param_2 + 0x88),*(uint32_t *)(param_1 + 0x128));
  glUniform1f(*(uint32_t *)(param_2 + 0x8c),*(uint32_t *)(param_1 + 300));
  glUniform1f(*(uint32_t *)(param_2 + 0x90),*(uint32_t *)(param_1 + 0x130));
  glUniform1f(*(uint32_t *)(param_2 + 0x98),*(uint32_t *)(param_1 + 0x138));
  glUniform1f(*(uint32_t *)(param_2 + 0x9c),*(uint32_t *)(param_1 + 0x13c));
  glUniform1f(*(uint32_t *)(param_2 + 0xa0),*(uint32_t *)(param_1 + 0x140));
  return;
}


/* @00130324  size=816 */

void ShaderMaterial_updateUniforms(long param_1,long param_2,char *param_3)

{
  uint32_t *puVar1;
  long lVar2;
  uint64_t uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  uint32_t uVar8;
  
  if (param_3[4] != '\0') {
    uVar8 = *(uint32_t *)(param_1 + 0x38);
    uVar3 = GLRenderer_getMatrixFromStack(param_2,0);
    glUniformMatrix4fv(uVar8,1,0,uVar3);
    uVar8 = *(uint32_t *)(param_1 + 0x34);
    uVar3 = GLRenderer_getMatrixFromStack(param_2,1);
    glUniformMatrix4fv(uVar8,1,0,uVar3);
  }
  if (param_3[5] != '\0') {
    uVar8 = *(uint32_t *)(param_1 + 0x3c);
    uVar3 = GLRenderer_getMatrixFromStack(param_2,2);
    glUniformMatrix4fv(uVar8,1,0,uVar3);
    lVar5 = 0;
    lVar6 = 0x12;
    lVar7 = 0x7c;
    do {
      iVar4 = *(int *)(param_1 + lVar6 * 4);
      if (iVar4 != -1) {
        glUniform1i(iVar4,(int)lVar6 + -0x12);
        puVar1 = (uint32_t *)(param_1 + lVar7);
        lVar2 = param_2 + lVar5;
        glUniform1i(puVar1[-5],*(uint32_t *)(lVar2 + 0x148));
        glUniform4fv(puVar1[-4],1,lVar2 + 0x14c);
        glUniform2iv(puVar1[-3],1,lVar2 + 0x15c);
        glUniform2fv(puVar1[-2],1,lVar2 + 0x164);
        glUniform4iv(puVar1[-1],1,lVar2 + 0x16c);
        glUniform4iv(*puVar1,1,lVar2 + 0x17c);
      }
      lVar5 = lVar5 + 0x44;
      lVar6 = lVar6 + 1;
      lVar7 = lVar7 + 0x18;
    } while (lVar5 != 0x220);
  }
  if (param_3[1] != '\0') {
    uVar8 = NEON_ucvtf(*(uint32_t *)(param_2 + 0x5c));
    glUniform2f(uVar8,*(uint32_t *)(param_2 + 0x60),*(uint32_t *)(param_1 + 0x40));
  }
  if (param_3[2] != '\0') {
    glUniform4fv(*(uint32_t *)(param_1 + 0x144),1,param_2 + 100);
    glUniform1f(*(uint32_t *)(param_2 + 0x74),*(uint32_t *)(param_1 + 0x148));
    glUniform1f(*(uint32_t *)(param_2 + 0x78),*(uint32_t *)(param_1 + 0x14c));
    glUniform1f(*(uint32_t *)(param_2 + 0x7c),*(uint32_t *)(param_1 + 0x150));
    uVar8 = NEON_ucvtf(*(uint32_t *)(param_2 + 0x80));
    glUniform1f(uVar8,*(uint32_t *)(param_1 + 0x154));
  }
  if (*param_3 != '\0') {
    lVar5 = 0;
    iVar4 = 0;
    do {
      lVar6 = param_2 + lVar5;
      if (*(char *)(lVar6 + 0x710) != '\0') {
        lVar7 = param_1 + (long)iVar4 * 0x1c;
        glUniform3fv(*(uint32_t *)(lVar7 + 0x158),1,lVar6 + 0x714);
        glUniform3fv(*(uint32_t *)(lVar7 + 0x15c),1,lVar6 + 0x720);
        glUniform3fv(*(uint32_t *)(lVar7 + 0x160),1,lVar6 + 0x72c);
        glUniform4fv(*(uint32_t *)(lVar7 + 0x164),1,lVar6 + 0x738);
        glUniform3fv(*(uint32_t *)(lVar7 + 0x168),1,lVar6 + 0x748);
        glUniform2fv(*(uint32_t *)(lVar7 + 0x16c),1,lVar6 + 0x754);
        glUniform3fv(*(uint32_t *)(lVar7 + 0x170),1,lVar6 + 0x75c);
        iVar4 = iVar4 + 1;
      }
      lVar5 = lVar5 + 0x58;
    } while (lVar5 != 0x160);
    glUniform1i(*(uint32_t *)(param_1 + 0x1c8),iVar4);
    lVar5 = *(long *)(param_2 + 0x708);
    if (lVar5 != 0) {
      glUniform3fv(*(uint32_t *)(param_1 + 0x1cc),1,lVar5);
      glUniform3fv(*(uint32_t *)(param_1 + 0x1d0),1,lVar5 + 0xc);
      glUniform4fv(*(uint32_t *)(param_1 + 0x1d4),1,lVar5 + 0x18);
      glUniform3fv(*(uint32_t *)(param_1 + 0x1d8),1,lVar5 + 0x28);
      glUniform3fv(*(uint32_t *)(param_1 + 0x1dc),1,lVar5 + 0x34);
      glUniform3fv(*(uint32_t *)(param_1 + 0x1e0),1,lVar5 + 0x40);
      glUniform4fv(*(uint32_t *)(param_1 + 0x1e4),1,lVar5 + 0x4c);
      glUniform3fv(*(uint32_t *)(param_1 + 0x1e8),1,lVar5 + 0x5c);
    }
  }
  if (*(long *)(param_3 + 8) != 0) {
    FUN_00130654(param_1);
  }
  if (*(long *)(param_3 + 0x10) != 0) {
    FUN_00130654(param_1);
    return;
  }
  return;
}


