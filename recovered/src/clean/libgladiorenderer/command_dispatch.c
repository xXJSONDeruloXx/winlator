/*
 * command_dispatch.c — Command dispatch table
 *
 * Maps opcodes 100..529 to gd_handle_* function pointers.
 * The table is populated at link time from the handlers in gd_handlers.c.
 *
 * In the original binary this was a static .rodata table at address 0x143e58.
 * Here we reconstruct it as an initialized array.
 */
#include "gladio_types.h"
#include "gladio_internal.h"

/*
 * The dispatch table is indexed by (opcode - GLADIO_OPCODE_BASE).
 * Entries that are NULL correspond to unimplemented/reserved opcodes.
 *
 * TODO: Fill in the actual opcode→handler mapping once all handlers compile.
 * For now this is a zero-initialized table; getHandleRequestFunc() returns NULL
 * for unmapped opcodes which is the same behavior as the original.
 */
GladioHandler gladio_dispatch_table[GLADIO_OPCODE_COUNT] = { 0 };
