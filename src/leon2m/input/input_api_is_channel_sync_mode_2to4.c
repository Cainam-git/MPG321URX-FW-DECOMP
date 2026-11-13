/* input_api_is_channel_sync_mode_2to4  (FUN_a0144350)
 *
 * Return whether the port of a channel has sync mode 2, 3 or 4.
 * Returns: 0 or 1
 * Name basis: descriptive - byte 9 (sync mode) of the port record; used by the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144350 @ 0xa0144350-0xa0144414, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the channel check is a static switch helper (case 1 first, so the
 * compare tree is rooted at 1) returning -1 for any other value, stored in an unsigned char; the sync mode test is on
 * an unsigned char holding (sync mode - 2), written as an early "return 1; return 0;" (a "<= 2" expression gives
 * a subtract-with-carry).
 */

/* The channel record (0x78 bytes), up to the field used here. */
struct channel_record_head {
    unsigned int status_word;       /* +0: port in bits 12-15 */
    unsigned char rest[0x74];
};
extern struct channel_record_head channel_records[4];
/* The port record (0x2A bytes), up to the field used here. */
struct port_record_sync {
    unsigned char pad0[9];
    unsigned char sync_mode;        /* +9: 1 = none recognised, 2..5 */
    unsigned char rest[0x2a - 0xa];
};
extern struct port_record_sync port_records[];
extern int dbg_printf();

#define CHANNEL_PORT_SHIFT 12           /* the port is bits 12-15 of the channel's status word */

/* Channel numbers 0 to 3 stay as they are, any other value becomes -1 (read as 0xFF in an unsigned char). */
static int remap_channel(int channel)
{
    switch (channel) {
    case 1: return 1;
    case 0: return 0;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Return 1 when the port record of the port of a channel holds sync mode 2, 3 or 4, else 0.
 *
 *   channel  the channel number; a number above 3 prints "SYS remapping channel OOR" and uses channel 0
 */
unsigned char input_api_is_channel_sync_mode_2to4(unsigned char channel)
{
    unsigned char index = remap_channel(channel);
    unsigned char sync_mode_minus_2;
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    sync_mode_minus_2 = port_records[(channel_records[index].status_word >> CHANNEL_PORT_SHIFT) & 0xf].sync_mode - 2;
    if (sync_mode_minus_2 <= 2)
        return 1;
    return 0;
}
