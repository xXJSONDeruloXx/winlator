/*
 * gl_context.c — GL context lifecycle, command buffer dispatch
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include "gladio_data.h"

/* Forward declaration */
void readVertexArrayElement(uint64_t param_1, int param_2, uint32_t param_3);

/* Forward declarations for internal functions */
static void *FUN_0011e56c(void *arg);
static void *FUN_0011cb78(void *arg);
#include <GLES3/gl32.h>
#include <EGL/egl.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>

/* @0011c8d8  size=672 */

void * createGLContext(long *param_1,uint64_t param_2,int param_3)

{
  long lVar1;
  uint32_t uVar2;
  int __fd;
  int __fd_00;
  void *__ptr;
  long lVar3;
  ssize_t sVar4;
  uint64_t uVar5;
  uint8_t *__arg;
  struct msghdr local_148;
  struct iovec local_110;
  uint8_t local_fc [4];
  pthread_t local_f8 [18];
  long local_68;
  
  /* stack canary setup (elided) */
  local_68 = *(long *)(lVar1 + 0x28);
  __ptr = calloc(1,0xb8);
  *(int *)((long)__ptr + 8) = param_3;
  uVar2 = RingBuffer_getSHMemSize(0x4000000);
  __fd = ashmemCreateRegion("gl-server-ring",uVar2);
  uVar2 = RingBuffer_getSHMemSize(0x2000000);
  __fd_00 = ashmemCreateRegion("gl-client-ring",uVar2);
  lVar3 = RingBuffer_create(__fd,0x4000000);
  *(long *)((long)__ptr + 0x18) = lVar3;
  if (lVar3 != 0) {
    lVar3 = RingBuffer_create(__fd_00,0x2000000);
    *(long *)((long)__ptr + 0x10) = lVar3;
    if (lVar3 != 0) {
      local_148.msg_control = local_f8;
      local_148.msg_controllen = 0x18;
      local_110.iov_base = local_fc;
      local_148.msg_iov = &local_110;
      local_f8[2] = ((uint64_t)(__fd_00) << 32 | (uint32_t)(__fd));
      local_fc[0] = 0;
      local_148.msg_name = (void *)0x0;
      local_148.msg_namelen = 0;
      local_148.msg_flags = 0;
      local_f8[0] = 0x18;
      local_110.iov_len = 1;
      local_148.msg_iovlen = 1;
      local_f8[1] = 0x100000001;
      sVar4 = sendmsg(param_3,&local_148,0);
      if (-1 < (int)sVar4) {
        ((generic_fn_t)(*(void **)(*param_1 + 0x6d8)))(param_1,(long)__ptr + 0x20);
        uVar5 = ((generic_fn_t)(*(void **)(*param_1 + 0xa8)))(param_1,param_2);
        *(uint64_t *)((long)__ptr + 0x30) = uVar5;
        __arg = calloc(1,200);
        *__arg = 4;
        __arg[2] = 1;
        pthread_mutex_init((pthread_mutex_t *)(__arg + 4),(pthread_mutexattr_t *)0x0);
        pthread_mutex_init((pthread_mutex_t *)(__arg + 0x5c),(pthread_mutexattr_t *)0x0);
        pthread_cond_init((pthread_cond_t *)(__arg + 0x2c),(pthread_condattr_t *)0x0);
        pthread_cond_init((pthread_cond_t *)(__arg + 0x84),(pthread_condattr_t *)0x0);
        pthread_create(local_f8,(pthread_attr_t *)0x0,FUN_0011e56c,__arg);
        pthread_detach(local_f8[0]);
        pthread_create(local_f8,(pthread_attr_t *)0x0,FUN_0011e56c,__arg);
        pthread_detach(local_f8[0]);
        pthread_create(local_f8,(pthread_attr_t *)0x0,FUN_0011e56c,__arg);
        pthread_detach(local_f8[0]);
        pthread_create(local_f8,(pthread_attr_t *)0x0,FUN_0011e56c,__arg);
        pthread_detach(local_f8[0]);
        *(uint8_t **)((long)__ptr + 0x98) = __arg;
        *(uint8_t *)((long)__ptr + 0x60) = 1;
        pthread_create((pthread_t *)((long)__ptr + 0x58),(pthread_attr_t *)0x0,FUN_0011cb78,__ptr);
        if (0 < __fd) {
          close(__fd);
        }
        if (0 < __fd_00) {
          close(__fd_00);
        }
        goto LAB_0011cb40;
      }
    }
  }
  if (0 < __fd) {
    close(__fd);
  }
  if (0 < __fd_00) {
    close(__fd_00);
  }
  free(__ptr);
  __ptr = (void *)0x0;
LAB_0011cb40:
  if (*(long *)(lVar1 + 0x28) == local_68) {
    return __ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* @0011d3a4  size=332 */

void destroyGLContext(long *param_1,void *param_2)

{
  void *__ptr;
  char *__ptr_00;
  long *plVar1;
  void *pvVar2;
  
  *(uint8_t *)((long)param_2 + 0x60) = 0;
  if (*(long *)((long)param_2 + 0x58) != 0) {
    RingBuffer_setStatus(*(uint64_t *)((long)param_2 + 0x18),2);
    RingBuffer_setStatus(*(uint64_t *)((long)param_2 + 0x10),2);
    pthread_join(*(pthread_t *)((long)param_2 + 0x58),(void **)0x0);
    __ptr_00 = *(char **)((long)param_2 + 0x98);
    if (__ptr_00 != (char *)0x0) {
      pthread_mutex_lock((pthread_mutex_t *)(__ptr_00 + 4));
      plVar1 = (long *)(__ptr_00 + 0xb8);
      __ptr = (void *)*plVar1;
      while (__ptr != (void *)0x0) {
        pvVar2 = *(void **)((long)__ptr + 0x10);
        free(__ptr);
        __ptr = pvVar2;
      }
      __ptr_00[2] = '\0';
      *plVar1 = 0;
      __ptr_00[0xc0] = '\0';
      __ptr_00[0xc1] = '\0';
      __ptr_00[0xc2] = '\0';
      __ptr_00[0xc3] = '\0';
      __ptr_00[0xc4] = '\0';
      __ptr_00[0xc5] = '\0';
      __ptr_00[0xc6] = '\0';
      __ptr_00[199] = '\0';
      pthread_cond_broadcast((pthread_cond_t *)(__ptr_00 + 0x2c));
      pthread_mutex_unlock((pthread_mutex_t *)(__ptr_00 + 4));
      pthread_mutex_lock((pthread_mutex_t *)(__ptr_00 + 0x5c));
      while ((((__ptr_00[2] == '\0' && (*__ptr_00 != '\0')) || (*plVar1 != 0)) ||
             (__ptr_00[1] != '\0'))) {
        pthread_cond_wait((pthread_cond_t *)(__ptr_00 + 0x84),(pthread_mutex_t *)(__ptr_00 + 0x5c));
      }
      pthread_mutex_unlock((pthread_mutex_t *)(__ptr_00 + 0x5c));
      pthread_mutex_destroy((pthread_mutex_t *)(__ptr_00 + 4));
      pthread_cond_destroy((pthread_cond_t *)(__ptr_00 + 0x2c));
      pthread_cond_destroy((pthread_cond_t *)(__ptr_00 + 0x84));
      free(__ptr_00);
    }
    *(uint64_t *)((long)param_2 + 0x98) = 0;
    *(uint64_t *)((long)param_2 + 0x58) = 0;
    RingBuffer_free(*(uint64_t *)((long)param_2 + 0x18));
    RingBuffer_free(*(uint64_t *)((long)param_2 + 0x10));
  }
  if (*(long *)((long)param_2 + 0x30) != 0) {
    ((generic_fn_t)(*(void **)(*param_1 + 0xb0)))(param_1);
    *(uint64_t *)((long)param_2 + 0x30) = 0;
  }
  ArrayBuffer_free((long)param_2 + 0x68);
  ArrayBuffer_free((long)param_2 + 0x80);
  free(param_2);
  return;
}


/* @0011e4fc  size=112 */

char * getGLExtensions(int *param_1)

{
  char *pcVar1;
  
  if (DAT_00144f20 == 0) {
    pcVar1 = 
    "GL_EXT_abgr GL_ARB_shadow GL_ARB_window_pos GL_EXT_packed_pixels GL_ARB_vertex_buffer_object GL_ARB_vertex_array_object GL_ARB_texture_border_clamp GL_ARB_texture_env_add GL_EXT_texture_env_add GL_EXT_draw_range_elements GL_EXT_bgra GL_ARB_texture_compression GL_EXT_texture_compression_s3tc GL_EXT_texture_compression_dxt1 GL_EXT_texture_compression_dxt3 GL_EXT_texture_compression_dxt5 GL_ARB_point_parameters GL_EXT_point_parameters GL_EXT_texture_edge_clamp GL_EXT_multi_draw_arrays GL_ARB_multisample GL_EXT_polygon_offset GL_ARB_draw_elements_base_vertex GL_ARB_texture_rectangle GL_EXT_vertex_array GL_ARB_vertex_array_bgra GL_ARB_texture_non_power_of_two GL_EXT_blend_color GL_EXT_blend_minmax GL_EXT_blend_equation_separate GL_EXT_blend_func_separate GL_EXT_blend_subtract GL_EXT_texture_filter_anisotropic GL_ARB_texture_mirrored_repeat GL_ARB_point_sprite GL_ARB_texture_cube_map GL_EXT_texture_cube_map GL_EXT_texture_rg GL_ARB_texture_rg GL_EXT_texture_float GL_ARB_texture_float GL_EXT_texture_half_float GL_EXT_color_buffer_float GL_EXT_color_buffer_half_float GL_EXT_depth_texture GL_ARB_depth_texture GL_ARB_depth_clamp GL_ARB_ES2_compatibility GL_ARB_fragment_shader GL_ARB_vertex_shader GL_ARB_shading_language_100 GL_ARB_draw_instanced GL_EXT_draw_instanced GL_ARB_instanced_arrays GL_EXT_instanced_arrays GL_ARB_framebuffer_object GL_EXT_framebuffer_object GL_EXT_packed_depth_stencil GL_EXT_framebuffer_blit GL_ARB_draw_buffers GL_ARB_internalformat_query GL_ARB_internalformat_query2 GL_ARB_map_buffer_range GL_ARB_draw_buffers_blend GL_ARB_multitexture GL_ARB_texture_env_combine GL_EXT_texture_env_combine GL_ARB_texture_env_dot3 GL_EXT_texture_env_dot3 GL_ARB_shader_objects GL_ARB_vertex_program GL_ARB_fragment_program GL_ARB_buffer_storage GL_EXT_buffer_storage GL_ARB_sync GL_ARB_sampler_objects GL_ARB_texture_multisample GL_ARB_color_buffer_float GL_ARB_occlusion_query GL_ARB_occlusion_query2 GL_EXT_direct_state_access GL_ARB_uniform_buffer_object GL_ARB_timer_query GL_EXT_timer_query GL_ARB_texture_swizzle GL_AR..." /* TRUNCATED STRING LITERAL */
    ;
    while (pcVar1 = strchr(pcVar1,0x20), pcVar1 != (char *)0x0) {
      pcVar1 = pcVar1 + -1;
      do {
        pcVar1 = pcVar1 + 1;
      } while (*pcVar1 == ' ');
      DAT_00144f20 = DAT_00144f20 + 1;
    }
  }
  if (param_1 != (int *)0x0) {
    *param_1 = DAT_00144f20;
  }
  return 
  "GL_EXT_abgr GL_ARB_shadow GL_ARB_window_pos GL_EXT_packed_pixels GL_ARB_vertex_buffer_object GL_ARB_vertex_array_object GL_ARB_texture_border_clamp GL_ARB_texture_env_add GL_EXT_texture_env_add GL_EXT_draw_range_elements GL_EXT_bgra GL_ARB_texture_compression GL_EXT_texture_compression_s3tc GL_EXT_texture_compression_dxt1 GL_EXT_texture_compression_dxt3 GL_EXT_texture_compression_dxt5 GL_ARB_point_parameters GL_EXT_point_parameters GL_EXT_texture_edge_clamp GL_EXT_multi_draw_arrays GL_ARB_multisample GL_EXT_polygon_offset GL_ARB_draw_elements_base_vertex GL_ARB_texture_rectangle GL_EXT_vertex_array GL_ARB_vertex_array_bgra GL_ARB_texture_non_power_of_two GL_EXT_blend_color GL_EXT_blend_minmax GL_EXT_blend_equation_separate GL_EXT_blend_func_separate GL_EXT_blend_subtract GL_EXT_texture_filter_anisotropic GL_ARB_texture_mirrored_repeat GL_ARB_point_sprite GL_ARB_texture_cube_map GL_EXT_texture_cube_map GL_EXT_texture_rg GL_ARB_texture_rg GL_EXT_texture_float GL_ARB_texture_float GL_EXT_texture_half_float GL_EXT_color_buffer_float GL_EXT_color_buffer_half_float GL_EXT_depth_texture GL_ARB_depth_texture GL_ARB_depth_clamp GL_ARB_ES2_compatibility GL_ARB_fragment_shader GL_ARB_vertex_shader GL_ARB_shading_language_100 GL_ARB_draw_instanced GL_EXT_draw_instanced GL_ARB_instanced_arrays GL_EXT_instanced_arrays GL_ARB_framebuffer_object GL_EXT_framebuffer_object GL_EXT_packed_depth_stencil GL_EXT_framebuffer_blit GL_ARB_draw_buffers GL_ARB_internalformat_query GL_ARB_internalformat_query2 GL_ARB_map_buffer_range GL_ARB_draw_buffers_blend GL_ARB_multitexture GL_ARB_texture_env_combine GL_EXT_texture_env_combine GL_ARB_texture_env_dot3 GL_EXT_texture_env_dot3 GL_ARB_shader_objects GL_ARB_vertex_program GL_ARB_fragment_program GL_ARB_buffer_storage GL_EXT_buffer_storage GL_ARB_sync GL_ARB_sampler_objects GL_ARB_texture_multisample GL_ARB_color_buffer_float GL_ARB_occlusion_query GL_ARB_occlusion_query2 GL_EXT_direct_state_access GL_ARB_uniform_buffer_object GL_ARB_timer_query GL_EXT_timer_query GL_ARB_texture_swizzle GL_AR..." /* TRUNCATED STRING LITERAL */
  ;
}


/* @0012e960  size=48 */

uint64_t getHandleRequestFunc(uint16_t param_1)

{
  if ((uint16_t)(param_1 - 100) < 0x1ae) {
    return *(uint64_t *)((unsigned long)param_1 * 8 + 0x143e58);
  }
  return 0;
}


/* @0011d868  size=516 */

void readCommandBuffer(long param_1)

{
  uint32_t uVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  long *plVar7;
  void *pvVar8;
  uint64_t *puVar9;
  void *pcVar10;
  unsigned long uVar11;
  uint8_t *pbVar12;
  long lVar13;
  
  iVar3 = ArrayBuffer_available(param_1 + 0x68);
  if (iVar3 == 0) {
    puVar9 = (uint64_t *)(&currentRenderer);
    GLRenderer_endImmediate(*puVar9);
    return;
  }
  uVar4 = ArrayBuffer_getInt(param_1 + 0x68);
  uVar5 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar3 = ArrayBuffer_getInt(param_1 + 0x68);
  iVar6 = ArrayBuffer_getInt(param_1 + 0x68);
  if (iVar6 != 0) {
    plVar7 = (long *)(&currentRenderer);
    lVar13 = *plVar7;
    *(uint32_t *)(lVar13 + 0x39c) = uVar5;
    if (iVar3 < 1) {
      ArrayBuffer_rewind(param_1 + 0x68);
    }
    else {
      uVar11 = (unsigned long)**(uint8_t **)(lVar13 + 0x540);
      if (uVar11 != 0) {
        pbVar12 = *(uint8_t **)(lVar13 + 0x540) + 0x22;
        do {
          if (*pbVar12 != 0) {
            iVar2 = *(int *)(param_1 + 0x6c);
            *(long *)(pbVar12 + -10) = *(long *)(param_1 + 0x78) + (long)iVar2;
            *(int *)(param_1 + 0x6c) = iVar2 + iVar3 * *(short *)(pbVar12 + -2);
          }
          uVar11 = uVar11 - 1;
          pbVar12 = pbVar12 + 0x20;
        } while (uVar11 != 0);
      }
    }
    uVar1 = *(int *)(param_1 + 0x68) + iVar6;
    if (*(int *)(param_1 + 0x70) < (int)uVar1) {
      uVar1 = uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU);
      pvVar8 = realloc(*(void **)(param_1 + 0x78),(unsigned long)uVar1);
      *(void **)(param_1 + 0x78) = pvVar8;
      memset((void *)((long)pvVar8 + (long)*(int *)(param_1 + 0x70)),0,
             (long)(int)uVar1 - (long)*(int *)(param_1 + 0x70));
      *(uint32_t *)(param_1 + 0x70) = uVar1;
    }
    RingBuffer_read(*(uint64_t *)(param_1 + 0x18),
                    *(long *)(param_1 + 0x78) + (long)*(int *)(param_1 + 0x6c),iVar6);
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + iVar6;
    puVar9 = (uint64_t *)(&currentRenderer);
    GLRenderer_beginImmediate(*puVar9,uVar4);
    iVar3 = ArrayBuffer_available(param_1 + 0x68);
    while (0 < iVar3) {
      ArrayBuffer_getShort(param_1 + 0x68);
      pcVar10 = (void *)getHandleRequestFunc(ArrayBuffer_getShort(param_1 + 0x68));
      if (pcVar10 == (void *)0x0) break;
      ((void (*)(long))pcVar10)(param_1);
      iVar3 = ArrayBuffer_available(param_1 + 0x68);
    }
    puVar9 = (uint64_t *)(&currentRenderer);
    GLRenderer_endImmediate(*puVar9);
    uVar11 = (unsigned long)**(uint8_t **)(lVar13 + 0x540);
    if (uVar11 != 0) {
      pbVar12 = *(uint8_t **)(lVar13 + 0x540) + 0x22;
      do {
        if (*pbVar12 != 0) {
          pbVar12[-10] = 0;
          pbVar12[-9] = 0;
          pbVar12[-8] = 0;
          pbVar12[-7] = 0;
          pbVar12[-6] = 0;
          pbVar12[-5] = 0;
          pbVar12[-4] = 0;
          pbVar12[-3] = 0;
        }
        uVar11 = uVar11 - 1;
        pbVar12 = pbVar12 + 0x20;
      } while (uVar11 != 0);
    }
    *(uint32_t *)(lVar13 + 0x39c) = 0;
  }
  return;
}


/* @0011e1f8  size=772 */

uint64_t
readUnboundVertexArrays(long param_1,uint32_t param_2,int param_3,long *param_4,int param_5)

{
  uint8_t *puVar1;
  short sVar2;
  int iVar3;
  uint8_t uVar4;
  uint32_t uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  uint64_t uVar11;
  long *plVar12;
  long lVar13;
  uint64_t *puVar14;
  long lVar15;
  long lVar16;
  uint8_t *pbVar17;
  unsigned long uVar18;
  unsigned long uVar19;
  uint32_t *puVar20;
  
  if (param_5 != 0) {
    lVar10 = GLBuffer_getBound(0x8893);
    if (lVar10 == 0) {
      if (param_5 - 0x1400U < 0xb) {
        iVar8 = *(int *)(&DAT_001156c0 + (long)(int)(param_5 - 0x1400U) * 4);
      }
      else {
        iVar8 = 0;
      }
      lVar10 = ArrayBuffer_getBytes(param_1 + 0x68,iVar8 * param_3);
    }
    else {
      iVar8 = ArrayBuffer_getInt(param_1 + 0x68);
      lVar10 = (long)iVar8;
    }
    *param_4 = lVar10;
  }
  uVar11 = ArrayBuffer_available(param_1 + 0x68);
  if ((int)uVar11 != 0) {
    plVar12 = (long *)(&currentRenderer);
    lVar10 = *plVar12;
    pbVar17 = *(uint8_t **)(lVar10 + 0x540);
    if (*pbVar17 != 0) {
      uVar18 = 0;
      bVar7 = false;
      do {
        if (pbVar17[uVar18 * 0x20 + 0x22] == 2) {
          bVar6 = false;
LAB_0011e300:
          iVar8 = *(int *)(pbVar17 + uVar18 * 0x20 + 0x14);
          if (3 < iVar8) {
            iVar8 = 4;
          }
          iVar9 = ArrayBuffer_getInt(param_1 + 0x68);
          lVar13 = ArrayBuffer_getBytes(param_1 + 0x68,iVar9);
          if (*(int *)(pbVar17 + uVar18 * 0x20 + 0x14) == 0x80e1) {
            lVar16 = *(long *)(pbVar17 + uVar18 * 0x20 + 0x18);
            uVar5 = iVar9 - (int)lVar16;
            if (0 < (int)uVar5) {
              lVar15 = 0;
              sVar2 = 4;
              if (*(short *)(pbVar17 + uVar18 * 0x20 + 0x20) != 0) {
                sVar2 = *(short *)(pbVar17 + uVar18 * 0x20 + 0x20);
              }
              do {
                puVar1 = (uint8_t *)(lVar13 + lVar16 + lVar15);
                uVar4 = *puVar1;
                lVar15 = lVar15 + sVar2;
                *puVar1 = puVar1[2];
                puVar1[2] = uVar4;
              } while (lVar15 < (long)(unsigned long)uVar5);
            }
            lVar16 = *(long *)(lVar10 + 0x540);
            iVar3 = *(int *)(lVar16 + 0x198);
            puVar20 = *(uint32_t **)(lVar16 + 0x168);
            if (iVar3 == 0) {
              glGenBuffers(1,lVar16 + 0x198);
              iVar3 = *(int *)(*(long *)(lVar10 + 0x540) + 0x198);
            }
            glBindBuffer(0x8892,iVar3);
            glBufferData(0x8892,(long)iVar9,lVar13,0x88e8);
            lVar13 = *(long *)(pbVar17 + uVar18 * 0x20 + 0x18);
          }
          else {
            puVar20 = (uint32_t *)0x0;
          }
          uVar19 = uVar18 & 0xffffffff;
          if (bVar6) {
            plVar12 = (long *)(&currentRenderer);
            uVar19 = (unsigned long)*(uint32_t *)(*(long *)(*plVar12 + 0x560) + uVar18 * 4 + 0x2c);
            GLRenderer_enableVertexAttribute(*plVar12,uVar19);
          }
          glVertexAttribPointer
                    (uVar19,iVar8,*(uint32_t *)(pbVar17 + uVar18 * 0x20 + 0xc),
                     pbVar17[uVar18 * 0x20 + 8],(long)*(short *)(pbVar17 + uVar18 * 0x20 + 0x20),
                     lVar13);
          if (puVar20 != (uint32_t *)0x0) {
            glBindBuffer(0x8892,*puVar20);
          }
        }
        else if (pbVar17[uVar18 * 0x20 + 0x22] == 1) {
          if (*(long *)(lVar10 + 0x560) != 0) {
            bVar6 = true;
            goto LAB_0011e300;
          }
          if (!bVar7) {
            puVar14 = (uint64_t *)(&currentRenderer);
            GLRenderer_beginImmediate(*puVar14,param_2);
          }
          iVar8 = param_3;
          if (0 < param_3) {
            do {
              readVertexArrayElement(param_1,uVar18 & 0xffffffff,0xffffffff);
              if (uVar18 == 0) {
                plVar12 = (long *)(&currentRenderer);
                GLRenderer_addArrayElement(*plVar12,*(int *)(*plVar12 + 0x5ec) + -1);
              }
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          bVar7 = true;
        }
        pbVar17 = *(uint8_t **)(lVar10 + 0x540);
        uVar18 = uVar18 + 1;
      } while (uVar18 < *pbVar17);
      if (bVar7) {
        puVar14 = (uint64_t *)(&currentRenderer);
        GLRenderer_endImmediate(*puVar14);
        return 1;
      }
    }
    uVar11 = 0;
  }
  return uVar11;
}


/* @0011da6c  size=244 */

void readVertexArrayElement(uint64_t param_1,int param_2,uint32_t param_3)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
  if (param_2 == 2) {
    plVar1 = (long *)(&currentRenderer);
    param_2 = 2;
    lVar2 = *plVar1 + 0x618;
    lVar3 = *plVar1 + 0xbc;
  }
  else if (param_2 == 1) {
    plVar1 = (long *)(&currentRenderer);
    param_2 = 1;
    lVar2 = *plVar1 + 0x600;
    lVar3 = *plVar1 + 0xac;
  }
  else if (param_2 == 0) {
    plVar1 = (long *)(&currentRenderer);
    param_2 = 0;
    lVar2 = *plVar1 + 0x5e8;
    lVar3 = 0;
  }
  else {
    if (param_2 < 3) {
      return;
    }
    plVar1 = (long *)(&currentRenderer);
    lVar2 = *plVar1 + (unsigned long)(param_2 - 3U) * 0x18 + 0x630;
    lVar3 = *plVar1 + (unsigned long)(param_2 - 3U) * 0x10 + 200;
  }
  FUN_0011db60(param_1,param_2,param_3,lVar2,lVar3);
  return;
}


