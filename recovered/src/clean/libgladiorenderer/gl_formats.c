/*
 * gl_formats.c — Internal format query support
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

/* @00137ad4  size=420 */

void GLFormats_queryInternalformat
               (int param_1,int param_2,int param_3,uint64_t param_4,uint32_t *param_5)

{
  uint8_t bVar1;
  char cVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  long lVar5;
  uint32_t *puVar6;
  
  uVar3 = 0;
  if (param_1 < 0x8513) {
    if ((1 < param_1 - 0xde0U) && (param_1 != 0x84f5)) goto switchD_00137bb8_caseD_8297;
  }
  else if (param_1 != 0x8513) {
    if (param_1 != 0x8d41) goto switchD_00137bb8_caseD_8297;
    lVar5 = 0;
    puVar6 = &DAT_00115f44;
    do {
      if (*(int *)((long)&DAT_00115f44 + lVar5) == param_2) goto LAB_00137b8c;
      lVar5 = lVar5 + 0x14;
    } while (lVar5 != 0x2a8);
    goto LAB_00137b78;
  }
  lVar5 = 0;
  puVar6 = &DAT_00115a80;
  do {
    if (*(int *)((long)&DAT_00115a80 + lVar5) == param_2) goto LAB_00137b8c;
    lVar5 = lVar5 + 0x14;
  } while (lVar5 != 0x4c4);
  goto LAB_00137b78;
switchD_00137bb8_caseD_827e:
  __android_log_print(3,"System.out","gladio:queryInternalformat: unimplemented pname %x");
LAB_00137b78:
  uVar3 = 0;
  goto switchD_00137bb8_caseD_8297;
LAB_00137b8c:
  uVar3 = 0x82b7;
  switch(param_3) {
  case 0x8271:
  case 0x8275:
    uVar3 = (uint32_t)*(uint8_t *)((long)puVar6 + lVar5 + 0xc);
    break;
  case 0x8272:
  case 0x8276:
    uVar3 = (uint32_t)*(uint8_t *)((long)puVar6 + lVar5 + 0xd);
    break;
  case 0x8273:
    uVar3 = (uint32_t)*(uint8_t *)((long)puVar6 + lVar5 + 0xe);
    break;
  case 0x8274:
    uVar3 = (uint32_t)*(uint8_t *)((long)puVar6 + lVar5 + 0xf);
    break;
  case 0x8277:
    uVar3 = (uint32_t)*(uint8_t *)((long)puVar6 + lVar5 + 0x10);
    break;
  case 0x8278:
  case 0x827c:
    if (*(char *)((long)puVar6 + lVar5 + 0xc) == '\0') {
      uVar3 = 0;
      break;
    }
    goto LAB_00137c4c;
  case 0x8279:
    if (*(char *)((long)puVar6 + lVar5 + 0xd) == '\0') {
      uVar3 = 0;
      break;
    }
    goto LAB_00137c4c;
  case 0x827a:
    if (*(char *)((long)puVar6 + lVar5 + 0xe) == '\0') {
      uVar3 = 0;
      break;
    }
    goto LAB_00137c4c;
  case 0x827b:
    bVar1 = *(uint8_t *)((long)puVar6 + lVar5 + 0xf);
    uVar3 = (uint32_t)bVar1;
    if (bVar1 == 0) break;
LAB_00137c4c:
    uVar3 = *(uint32_t *)((long)puVar6 + lVar5 + 8);
    break;
  case 0x827d:
    cVar2 = *(char *)((long)puVar6 + lVar5 + 0xd);
    uVar4 = 0x8c17;
    goto LAB_00137c70;
  case 0x827e:
  case 0x827f:
  case 0x8280:
  case 0x8281:
  case 0x8282:
  case 0x8283:
  case 0x8284:
  case 0x8285:
  case 0x8286:
  case 0x8287:
  case 0x8288:
  case 0x828a:
  case 0x828c:
  case 0x828d:
  case 0x828e:
  case 0x828f:
  case 0x8290:
  case 0x8291:
  case 0x8292:
  case 0x8293:
  case 0x8294:
  case 0x8295:
  case 0x8296:
  case 0x8299:
  case 0x829c:
  case 0x829d:
  case 0x829e:
  case 0x82a0:
  case 0x82a1:
  case 0x82a2:
  case 0x82a3:
  case 0x82a4:
    goto switchD_00137bb8_caseD_827e;
  case 0x8289:
  case 0x828b:
    cVar2 = *(char *)((long)puVar6 + lVar5 + 0x11);
    goto LAB_00137c68;
  case 0x8297:
  case 0x8298:
  case 0x829b:
  case 0x829f:
  case 0x82a5:
    break;
  case 0x829a:
    cVar2 = *(char *)((long)puVar6 + lVar5 + 0x12);
LAB_00137c68:
    uVar4 = 0x82b7;
LAB_00137c70:
    uVar3 = 0;
    if (cVar2 != '\0') {
      uVar3 = uVar4;
    }
    break;
  default:
    if ((param_3 == 0x80a9) || (param_3 == 0x9380)) goto LAB_00137b78;
    goto switchD_00137bb8_caseD_827e;
  }
switchD_00137bb8_caseD_8297:
  *param_5 = uVar3;
  return;
}


