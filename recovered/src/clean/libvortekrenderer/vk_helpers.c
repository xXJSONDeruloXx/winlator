/*
 * vk_helpers.c — Regenerated
 */
#include "vortek_types.h"
#include "vortek_internal.h"
#include "vortek_data.h"


extern void *android_link_namespaces_all_libs;
extern void *android_link_namespaces;

/* STUB: broken signature removed */

/* STUB */

void _INIT_0(void)
{ /* TODO */ }

/* @00187e6c  size=156 */

void _INIT_1(void)

{
  uint32_t uVar1;
  int iVar2;
  uint64_t uVar3;
  uint32_t uVar4;
  char acStack_6c [92];
  
  uVar3 = getauxval(0x10);
  if (((uint32_t)uVar3 >> 8 & 1) != 0) {
    iVar2 = __system_property_get("ro.arch",acStack_6c);
    uVar1 = (uint32_t)((unsigned long)uVar3 >> 8);
    if (iVar2 < 1) {
      uVar4 = uVar1 & 1;
    }
    else {
      iVar2 = strncmp(acStack_6c,"exynos9810",10);
      uVar4 = 0;
      if (iVar2 != 0) {
        uVar4 = uVar1 & 1;
      }
    }
    DAT_00195660 = uVar4 != 0;
    return;
  }
  DAT_00195660 = 0;
  return;
}




/* STUB */

void __cxa_allocate_dependent_exception(void)
{ /* TODO */ }

/* STUB */

long __cxa_allocate_exception(long param_1)
{ /* TODO */ }

/* STUB */

unsigned long * __cxa_begin_catch(unsigned long *param_1)
{ /* TODO */ }

/* STUB */

void __cxa_call_unexpected(long param_1)
{ /* TODO */ }

/* @0016f040  size=80 */

uint64_t __cxa_current_exception_type(void)

{

  /* STUB: conflicting type */
















}





/* @0016f1a8  size=124 */

long __cxa_current_primary_exception(void)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
                    /* try { // try from 0016f1b8 to 0016f1bb has its CatchHandler @ 0016f224 */
  plVar1 = (long *)__cxa_get_globals_fast();
  if (((plVar1 == (long *)0x0) || (lVar2 = *plVar1, lVar2 == 0)) ||
     (*(unsigned long *)(lVar2 + 0x60) >> 8 != 0x434c4e47432b2b)) {
    lVar3 = 0;
  }
  else {
    if ((*(unsigned long *)(lVar2 + 0x60) & 0xff) == 1) {
      lVar2 = *(long *)(lVar2 + 8) + -0x80;
    }
    lVar3 = lVar2 + 0x80;
    FUN_00187f40(1,lVar2 + 8);
  }
  return lVar3;
}




/* STUB */

void __cxa_decrement_exception_refcount(long param_1)
{ /* TODO */ }

/* @001875d4  size=24 */

void __cxa_deleted_virtual(void)

{

  /* STUB: conflicting type */


}





/* STUB */

void * __cxa_demangle(uint8_t *param_1,void *param_2,unsigned long *param_3,uint32_t *param_4)
{ /* TODO */ }

/* STUB */

void __cxa_end_catch(void)
{ /* TODO */ }

/* @0016ed24  size=8 */

void __cxa_free_dependent_exception(void)

{

  /* STUB: conflicting type */


}





/* @0016ecc4  size=32 */

void __cxa_free_exception(long param_1)

{
                    /* try { // try from 0016ecd4 to 0016ecd7 has its CatchHandler @ 0016ece4 */
  FUN_00185a84(param_1 + -0x80);
  return;
}




/* @0016ee54  size=12 */

uint64_t __cxa_get_exception_ptr(long param_1)

{

  /* STUB: conflicting type */

}





/* @0016f414  size=36 */

void __cxa_get_globals(void)

{

  /* STUB: conflicting type */


}





/* @0016f438  size=36 */

/* ERR: void __cxa_get_globals_fast(void) */

/* ERR: { */

  /* STUB: conflicting type */


/* ERR: } */





/* @0016f664  size=160 */

void __cxa_guard_abort(long param_1)

{
  uint8_t bVar1;
  int iVar2;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0016f708("%s failed to acquire mutex","__cxa_guard_abort");
  }
  bVar1 = *(uint8_t *)(param_1 + 1);
  *(uint32_t *)(param_1 + 4) = 0;
  *(uint8_t *)(param_1 + 1) = 0;
                    /* try { // try from 0016f694 to 0016f69f has its CatchHandler @ 0016f704 */
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 == 0) {
    if (((bVar1 >> 2 & 1) != 0) &&
       (iVar2 = pthread_cond_broadcast((pthread_cond_t *)&DAT_001953ac), iVar2 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to broadcast","__cxa_guard_abort");
    }
    return;
  }
                    /* try { // try from 0016f6dc to 0016f6ef has its CatchHandler @ 0016f704 */
                    /* WARNING: Subroutine does not return */
  FUN_0016f708("%s failed to release mutex","__cxa_guard_abort");
}




/* @0016f45c  size=284 */

uint32_t __cxa_guard_acquire(char *param_1)

{
  uint8_t bVar1;
  uint8_t bVar2;
  int iVar3;
  long lVar4;
  uint32_t uVar5;
  int unaff_w20;
  
  if (*param_1 == '\0') {
    iVar3 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00195384);
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to acquire mutex","__cxa_guard_acquire");
    }
    bVar1 = param_1[1];
    if ((bVar1 >> 1 & 1) != 0) {
      iVar3 = *(int *)(param_1 + 4);
                    /* try { // try from 0016f4a4 to 0016f4ab has its CatchHandler @ 0016f578 */
      lVar4 = syscall(0xb2);
      unaff_w20 = (int)lVar4;
      if (iVar3 == unaff_w20) {
                    /* try { // try from 0016f56c to 0016f577 has its CatchHandler @ 0016f578 */
                    /* WARNING: Subroutine does not return */
        FUN_0016f708("__cxa_guard_acquire detected recursive initialization");
      }
    }
    while (bVar2 = param_1[1], (bVar2 >> 1 & 1) != 0) {
      param_1[1] = bVar2 | 4;
                    /* try { // try from 0016f4d8 to 0016f4e3 has its CatchHandler @ 0016f580 */
      pthread_cond_wait((pthread_cond_t *)&DAT_001953ac,(pthread_mutex_t *)&DAT_00195384);
    }
    if (bVar2 == 1) {
      uVar5 = 0;
    }
    else {
      if ((bVar1 >> 1 & 1) == 0) {
                    /* try { // try from 0016f4fc to 0016f503 has its CatchHandler @ 0016f578 */
        lVar4 = syscall(0xb2);
        unaff_w20 = (int)lVar4;
      }
      *(int *)(param_1 + 4) = unaff_w20;
      param_1[1] = '\x02';
      uVar5 = 1;
    }
                    /* try { // try from 0016f518 to 0016f523 has its CatchHandler @ 0016f57c */
    iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00195384);
    if (iVar3 != 0) {
                    /* try { // try from 0016f558 to 0016f56b has its CatchHandler @ 0016f57c */
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to release mutex","__cxa_guard_acquire");
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}




/* @0016f5b4  size=172 */

void __cxa_guard_release(uint32_t *param_1)

{
  uint8_t bVar1;
  int iVar2;
  
  *param_1 = 1;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0016f708("%s failed to acquire mutex","__cxa_guard_release");
  }
  bVar1 = *(uint8_t *)((long)param_1 + 1);
  *(uint8_t *)((long)param_1 + 1) = 1;
                    /* try { // try from 0016f5ec to 0016f5f7 has its CatchHandler @ 0016f660 */
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00195384);
  if (iVar2 == 0) {
    if (((bVar1 >> 2 & 1) != 0) &&
       (iVar2 = pthread_cond_broadcast((pthread_cond_t *)&DAT_001953ac), iVar2 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_0016f708("%s failed to broadcast","__cxa_guard_release");
    }
    return;
  }
                    /* try { // try from 0016f638 to 0016f64b has its CatchHandler @ 0016f660 */
                    /* WARNING: Subroutine does not return */
  FUN_0016f708("%s failed to release mutex","__cxa_guard_release");
}




/* @0016f17c  size=44 */

void __cxa_increment_exception_refcount(long param_1)

{

  /* STUB: conflicting type */




}





/* @001875bc  size=24 */

void __cxa_pure_virtual(void)

{

  /* STUB: conflicting type */


}





/* STUB */

void __cxa_rethrow(void)
{ /* TODO */ }

/* STUB */

void __cxa_rethrow_primary_exception(long param_1)
{ /* TODO */ }

/* STUB */

void __cxa_throw(long param_1,uint64_t param_2,uint64_t param_3)
{ /* TODO */ }

/* @0016f3bc  size=44 */

bool __cxa_uncaught_exception(void)

{
  bool bVar1;
  long lVar2;
  
                    /* try { // try from 0016f3c8 to 0016f3cb has its CatchHandler @ 0016f3e8 */
  lVar2 = __cxa_get_globals_fast();
  bVar1 = false;
  if (lVar2 != 0) {
    bVar1 = *(int *)(lVar2 + 8) != 0;
  }
  return bVar1;
}




/* @0016f3ec  size=36 */

uint32_t __cxa_uncaught_exceptions(void)

{
  uint32_t uVar1;
  long lVar2;
  
                    /* try { // try from 0016f3f8 to 0016f3fb has its CatchHandler @ 0016f410 */
  lVar2 = __cxa_get_globals_fast();
  uVar1 = 0;
  if (lVar2 != 0) {
    uVar1 = *(uint32_t *)(lVar2 + 8);
  }
  return uVar1;
}




/* STUB */

void __dynamic_cast(long *param_1,uint64_t param_2,long param_3,uint64_t param_4)
{ /* TODO */ }

/* STUB */

void __gxx_personality_v0(int param_1,unsigned long param_2,unsigned long param_3,long param_4,long param_5)
{ /* TODO */ }

/* STUB: broken signature removed */

/* STUB: broken signature removed */

/* STUB: broken signature removed */

/* STUB: broken signature removed */

/* STUB: broken signature removed */

/* STUB: broken signature removed */

/* @00166388  size=8 */

/* operator delete(void*) */

void operator_delete(void *param_1)

{
  free(param_1);
  return;
}




/* @001663a0  size=8 */

/* operator delete[](void*) */

void operator_delete__(void *param_1)

{
  operator_delete(param_1);
  return;
}




/* STUB */

void * operator_new(unsigned long param_1)
{ /* TODO */ }

/* @00166350  size=8 */

/* operator new[](unsigned long) */

void * operator_new__(unsigned long param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}




/* STUB: broken signature removed */

/* STUB: broken signature removed */

/* STUB: broken signature removed */

/* STUB: broken signature removed */

