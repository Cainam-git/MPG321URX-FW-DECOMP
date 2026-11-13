/* sys_api_get_channel_flags_14_15  (FUN_a0143d14)
 *
 * Return the 2-bit field at bits 14-15 of a channel's flag word.
 * Returns: 0..3
 * Name basis: descriptive - channel record word +0x70; used by the event generator
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143d14, flags -mcpu=v8 -O3 -g.
 * Same shape as sys_api_get_channel_block_flag2.
 */
extern int dbg_printf();                     /* formatted output (vsnprintf) */
extern unsigned char sys_get_channel_flags_14_15(unsigned char);

/* Return ch for 0..3, else -1. */
static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Channel-checked wrapper of sys_get_channel_flags_14_15. A channel above 3 prints
 * "SYS remapping channel OOR" and is treated as channel 0. */
unsigned char sys_api_get_channel_flags_14_15(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return sys_get_channel_flags_14_15(i);
}
