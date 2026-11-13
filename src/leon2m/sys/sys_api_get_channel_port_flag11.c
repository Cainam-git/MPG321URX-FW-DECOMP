/* sys_api_get_channel_port_flag11  (FUN_a014d544)
 *
 * Return bit 11 of the status halfword of the port record that a channel is mapped to.
 * Returns: 0 or 1
 * Name basis: descriptive - reads (status halfword of the channel's port record >> 11) & 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014d544 @ 0xa014d544-0xa014d5f4 (44 words), flags -mcpu=v8 -O3 -g.
 * Source form: the same code as sys_api_get_channel_port_flag6 (sys_api_get_channel_port_flag6) with another bit number.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char pad[0x74]; };
/* Port record (0x2a bytes); only the status halfword at +0 is used here. */
struct port_record { unsigned short status; unsigned char rest[0x28]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern int dbg_printf();

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
 * Return bit 11 of the status halfword of the port record that a channel is on.
 *
 *   channel  0..3; a larger value prints "SYS remapping channel OOR" and is treated as channel 0
 */
unsigned char sys_api_get_channel_port_flag11(unsigned char channel)
{
    unsigned char i = remap_channel(channel);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return (port_records[(channel_records[i].status_word >> 12) & 0xf].status >> 11) & 1;
}
