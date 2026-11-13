/* sys_api_get_channel_flag29  (FUN_a0143e70)
 *
 * Return flag bit 29 of a channel's flag word.
 * Returns: 0 or 1
 * Name basis: descriptive - channel record word +0x70; used by the event generator
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143e70, flags -mcpu=v8 -O3 -g.
 */
/* Channel record (0x78 bytes); only the flags word at +0x70 is used here. */
struct channel_record { unsigned int status_word; unsigned char pad[0x6c]; unsigned int flags; unsigned int word_0x74; };
extern struct channel_record channel_records[4];
extern int dbg_printf();                     /* formatted output (vsnprintf) */

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

/* Return bit 29 of the flags word (+0x70) of channel ch. A channel above 3 prints
 * "SYS remapping channel OOR" and is treated as channel 0. */
unsigned char sys_api_get_channel_flag29(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return (channel_records[i].flags >> 29) & 1;
}
