#include "hook_impl_core.h"

// These are named replacements for the anonymous DAT_ globals seen in the raw
// decompilation. They are intentionally first-pass and may need adjustment once
// the full module tree is wired together.
HookConfig *g_hook_config = NULL;
gsl_alloc32_fn g_orig_gsl_alloc32 = NULL;
gsl_alloc64_fn g_orig_gsl_alloc64 = NULL;
gsl_free_fn g_orig_gsl_free = NULL;
int g_kgsl_fd = 0;
bool g_loader_bridge_ready = false;
bool g_cpu_quirk_enabled = false;
android_namespace_handle_t g_default_copy_namespace = 0;
android_link_namespaces_all_libs_fn g_android_link_namespaces_all_libs = NULL;
android_link_namespaces_fn g_android_link_namespaces = NULL;
loader_android_create_namespace_fn g_android_create_namespace_impl = NULL;
android_get_exported_namespace_fn g_android_get_exported_namespace = NULL;

void init_hook_param(uint64_t hook_config_ptr) {
    g_hook_config = (HookConfig *)hook_config_ptr;
}

void init_gsl(uint64_t alloc32, uint64_t alloc64, uint64_t free_fn) {
    g_orig_gsl_alloc32 = (gsl_alloc32_fn)alloc32;
    g_orig_gsl_alloc64 = (gsl_alloc64_fn)alloc64;
    g_orig_gsl_free = (gsl_free_fn)free_fn;
}
