/*
 * vortek_globals.c — Global state for libvortekrenderer
 */
#include "vortek_types.h"

/* Command dispatch table — populated at link/init time */
VortekHandler vortek_dispatch_table[VORTEK_OPCODE_COUNT] = { 0 };
