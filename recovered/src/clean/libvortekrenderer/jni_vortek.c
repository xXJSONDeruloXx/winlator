/*
 * jni_vortek.c — JNI entry points
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"

/* @0012dbf4  size=4 */

void Java_com_winlator_xenvironment_components_VortekRendererComponent_createVkContext(void)

{
  createVkContext();
  return;
}


/* @0012dbf8  size=8 */

void Java_com_winlator_xenvironment_components_VortekRendererComponent_destroyVkContext
               (uint64_t param_1,uint64_t param_2,uint64_t param_3)

{
  destroyVkContext(param_1,param_3);
  return;
}


/* @0012de24  size=36 */

uint32_t Java_com_winlator_xenvironment_components_VortekRendererComponent_handleExtraDataRequest
               (uint64_t param_1,uint64_t param_2,uint64_t param_3,uint32_t param_4,
               uint32_t param_5)

{
  uint32_t uVar1;
  
  uVar1 = handleExtraDataRequest(param_3,param_4,param_5);
  return uVar1 & 1;
}


/* @0012dc00  size=548 */

void Java_com_winlator_xenvironment_components_VortekRendererComponent_initVulkanWrapper
               (long *param_1,uint64_t param_2,uint64_t param_3,long param_4)

{
  long lVar1;
  uint64_t uVar2;
  char *__filename;
  char *pcVar3;
  char *pcVar4;
  long lVar5;
  char *local_1060;
  uint8_t auStack_1058 [4096];
  long local_58;
  
  /* stack canary setup */
  local_58 = *(long *)(lVar1 + 0x28);
  if (param_4 == 0) {
    lVar5 = dlopen("/system/lib64/libvulkan.so",2);
  }
  else {
    uVar2 = ((generic_fn_t)(*(void **)(*param_1 + 0x548)))(param_1,param_3,0);
    __filename = (char *)((generic_fn_t)(*(void **)(*param_1 + 0x548)))(param_1,param_4,0);
    pcVar3 = basename(__filename);
    memset(auStack_1058,0,0x1000);
    pcVar4 = dirname(__filename);
    __strcpy_chk(auStack_1058,pcVar4,0x1000);
    __strcat_chk(auStack_1058,&DAT_0011bdb1,0x1000);
    asprintf(&local_1060,"%s%s",auStack_1058,&DAT_0011dd6c);
    mkdir(local_1060,0x1f8);
    lVar5 = adrenotools_open_libvulkan(2,1,local_1060,uVar2,auStack_1058,pcVar3,0,0);
    ((generic_fn_t)(*(void **)(*param_1 + 0x550)))(param_1,param_3,uVar2);
    ((generic_fn_t)(*(void **)(*param_1 + 0x550)))(param_1,param_4,__filename);
  }
  if (lVar5 == 0) {
    uVar2 = dlerror();
    __android_log_print(3,"System.out","vortek: unable to open libvulkan: %s",uVar2);
  }
  memset(&vulkanWrapper,0,0x820);
  DAT_00193af0 = dlsym(lVar5,"vkCreateInstance");
  DAT_00193b48 = dlsym(lVar5,"vkEnumerateInstanceVersion");
  DAT_00193b50 = dlsym(lVar5,"vkEnumerateInstanceExtensionProperties");
  DAT_00193ae8 = dlsym(lVar5,"vkGetInstanceProcAddr");
  *(void **)(vulkanWrapper + 0x10) = dlsym(lVar5,"vkGetDeviceProcAddr") /* was vulkanWrapper assignment */;
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


