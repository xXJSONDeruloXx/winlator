#include "quirks.h"
#include "hook_impl_core.h"

#if defined(__has_include)
#  if __has_include(<sys/auxv.h>)
#    include <sys/auxv.h>
#  else
     static inline unsigned long getauxval(unsigned long type) { (void)type; return 0; }
#    ifndef AT_HWCAP
#      define AT_HWCAP 16
#    endif
#  endif
#else
   static inline unsigned long getauxval(unsigned long type) { (void)type; return 0; }
#  ifndef AT_HWCAP
#    define AT_HWCAP 16
#  endif
#endif

#if defined(__has_include)
#  if __has_include(<android/log.h>)
#    include <android/log.h>
#  else
     extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
     extern int __system_property_get(const char *name, char *value);
#  endif
#else
  extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
  extern int __system_property_get(const char *name, char *value);
#endif

#include <string.h>

// Exact transplant of _INIT_1 from the recovered binary.
// Reads AT_HWCAP (bit 8) and checks ro.arch for the exynos9810 quirk.
void init_cpu_quirk_flags(void) {
    unsigned long hwcap = getauxval(AT_HWCAP);
    bool enabled = false;

    if (((uint32_t)(hwcap >> 8) & 1u) != 0) {
        char arch[92] = {0};
        int rc = __system_property_get("ro.arch", arch);
        uint32_t candidate = (uint32_t)(hwcap >> 8);
        if (rc < 1) {
            enabled = (candidate & 1u) != 0;
        } else {
            if (strncmp(arch, "exynos9810", 10) != 0) {
                enabled = (candidate & 1u) != 0;
            } else {
                enabled = false;
            }
        }
    } else {
        enabled = false;
    }

    g_cpu_quirk_enabled = enabled;
}
