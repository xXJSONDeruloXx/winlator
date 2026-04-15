#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int get_android_sdk_int(void);
uint64_t page_align_down(uint64_t addr);
bool is_unconditional_branch_insn(uint32_t *insn);
void *find_loader_entry_via_dlopen_branch_scan(void);

void init_loader_bridge_symbols(void);

uint64_t android_create_namespace(uint64_t name, uint64_t ld_library_path,
                                  uint64_t default_library_path, uint64_t type,
                                  uint64_t permitted_when_isolated_path,
                                  uint64_t parent_namespace);

uint64_t android_create_namespace_escape(uint64_t name, uint64_t ld_library_path,
                                         uint64_t default_library_path, uint64_t type,
                                         uint64_t permitted_when_isolated_path,
                                         uint64_t parent_namespace);

uint8_t elf_soname_patch(const char *path, int dest_fd, const char *new_soname);

uint32_t linkernsbypass_link_namespace_to_default_all_libs(uint64_t namespace_handle);
uint8_t linkernsbypass_load_status(void);
uint64_t linkernsbypass_namespace_dlopen(uint64_t path, uint32_t flags, uint64_t namespace_handle);
uint64_t linkernsbypass_namespace_dlopen_unique(uint64_t path, uint64_t soname,
                                                uint32_t flags, uint64_t namespace_handle);

#ifdef __cplusplus
}
#endif
