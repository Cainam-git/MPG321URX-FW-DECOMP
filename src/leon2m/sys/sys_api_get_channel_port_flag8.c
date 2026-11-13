/* sys_api_get_channel_port_flag8  (FUN_a014d3d4)
 *
 * Return flag bit 8 of the port record that a channel is mapped to.
 * Returns: 0 or 1
 * Name basis: descriptive - twin of sys_api_get_channel_port_flag9; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014d3d4 (-mcpu=v8 -O3 -g).
 * Source form: the channel remap is a static helper with a switch; the same code as the flag-9 getter except for the callee.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char pad[0x74]; };
extern struct channel_record channel_records[4];
extern int dbg_printf();
extern unsigned char input_port_get_status_bit8(unsigned char);

/* Return channel for 0..3, else -1. */
static int remap_channel(int channel)
{
    switch (channel) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Return status bit 8 of the port record that a channel is on (input_port_get_status_bit8, given the port number
 * from bits 12..15 of the channel's status word).
 *
 *   channel  0..3; a larger value prints "SYS remapping channel OOR" and is treated as channel 0
 *
 * Nothing in the firmware calls it.
 */
unsigned char sys_api_get_channel_port_flag8(unsigned char channel)
{
    unsigned char i = remap_channel(channel);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return input_port_get_status_bit8((channel_records[i].status_word >> 12) & 0xf);
}
