/* input_api_get_channel_status_bit_second  (FUN_a0144144)
 *
 * Return the bit of the second port status word for the port of a channel.
 * Returns: 0 or 1
 * Name basis: descriptive - status halfword at 0xA802CA00; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144144 @ 0xa0144144, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: as in input_api_get_channel_status_bit (static switch helper returning -1, stored in an
 * unsigned char; the whole lookup is one expression in the return statement).
 */

/* The channel record (0x78 bytes), up to the field used here. */
struct channel_record_head {
    unsigned int status_word;       /* +0: port in bits 12-15 */
    unsigned char rest[0x74];
};
extern struct channel_record_head channel_records[4];
/* The port record (0x2A bytes), up to the field used here. */
struct port_record_code {
    unsigned char pad0[0xa];
    unsigned char port_code;        /* +0xA */
    unsigned char rest[0x2a - 0xb];
};
extern struct port_record_code port_records[];
extern int dbg_printf();
extern int input_port_id_to_entry_index(unsigned char port_code);
extern int input_get_port_status_bit_second(int entry);

#define CHANNEL_PORT_SHIFT 12           /* the port is bits 12-15 of the channel's status word */

/* Channel numbers 0 to 3 stay as they are, any other value becomes -1 (read as 0xFF in an unsigned char). */
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
 * Return the bit of the second port status word (port_present_mask_alt, 0xA802CA00) that belongs to the port
 * of a channel. Same lookup as input_api_get_channel_status_bit.
 *
 *   channel  the channel number; a number above 3 prints "SYS remapping channel OOR" and uses channel 0
 */
unsigned char input_api_get_channel_status_bit_second(unsigned char channel)
{
    unsigned char index = remap_channel(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    return input_get_port_status_bit_second(input_port_id_to_entry_index(port_records[(channel_records[index].status_word >> CHANNEL_PORT_SHIFT) & 0xf].port_code) & 0xff);
}
