/* input_api_get_channel_format_code  (FUN_a01448fc)
 *
 * Return the colour format code 0..0x27 of a channel's port, raised by 2 in twelve cases.
 * Returns: code, 0x28 when out of range
 * Note: The +2 applies to twelve codes when the port's signal code is 0xB1 and the status byte of the active
 *   port's entry is 1. The only caller, pq_auto_level_task, tests bit 0.
 * Name basis: derived - byte 0x28 of the port record, the colour format code that input_csc_setup keeps there
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01448fc @ 0xa01448fc-0xa014505c (472 words), flags -mcpu=v8 -O3 -g (section default).
 */
/* A channel record, up to the port field of the first word (bits 12..15). */
struct channel_record { unsigned int upper_half : 16; unsigned int port : 4; unsigned int lower_bits : 12; unsigned char rest[0x74]; };
/* A port record (0x2a bytes), up to the colour format code. */
struct port_record { unsigned char pad[0x28]; unsigned char format_code; unsigned char tail; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern int dbg_printf();
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char sys_get_active_port_code(void);
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern unsigned char ipc_get_input_status_byte(unsigned char);

/* Channel numbers 0..3 map to themselves; any other number gives -1. */
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

/*
 * 1 when the signal code of the port of channel 'channel' is 0xb1 and the input processor's status byte for the port
 * entry of the active port (sys_get_active_port_code) is 1, else 0.
 */
static unsigned char routed_status_is_one(unsigned char channel)
{
    unsigned char r = 0;

    if (input_block_get_signal_code(channel_records[channel].port) == 0xb1 && ipc_get_input_status_byte(input_port_id_to_entry_index(sys_get_active_port_code())) == 1)
        r = 1;
    return r & 1;
}

/*
 * Return the colour format code of a channel's port, raised by 2 for twelve codes in one case.
 *
 *   channel  channel number 0..3; any other value prints "SYS remapping channel OOR" and uses channel 0
 *
 * The code is byte 0x28 of the port's record in port_records (the colour format code that input_csc_setup works
 * with), the port being the port field (bits 12..15) of the channel record. Codes 0..0x27 are returned as they
 * are, except 2, 3, 8, 9, 0xe, 0xf, 0x14, 0x15, 0x1c, 0x1d, 0x22 and 0x23: for those the result is code + 2 when
 * routed_status_is_one(channel) holds. Any code above 0x27 gives 0x28.
 * Called by pq_auto_level_task, which looks only at bit 0 of the result.
 */
unsigned char input_api_get_channel_format_code(unsigned char channel)
{
    unsigned char i, r;

    i = remap(channel);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    switch (port_records[channel_records[i].port].format_code) {
    case 0x0: r = 0x0; break;
    case 0x1: r = 0x1; break;
    case 0x2: r = routed_status_is_one(i) ? 0x4 : 0x2; break;
    case 0x3: r = routed_status_is_one(i) ? 0x5 : 0x3; break;
    case 0x4: r = 0x4; break;
    case 0x5: r = 0x5; break;
    case 0x6: r = 0x6; break;
    case 0x7: r = 0x7; break;
    case 0x8: r = routed_status_is_one(i) ? 0xa : 0x8; break;
    case 0x9: r = routed_status_is_one(i) ? 0xb : 0x9; break;
    case 0xa: r = 0xa; break;
    case 0xb: r = 0xb; break;
    case 0xc: r = 0xc; break;
    case 0xd: r = 0xd; break;
    case 0xe: r = routed_status_is_one(i) ? 0x10 : 0xe; break;
    case 0xf: r = routed_status_is_one(i) ? 0x11 : 0xf; break;
    case 0x10: r = 0x10; break;
    case 0x11: r = 0x11; break;
    case 0x12: r = 0x12; break;
    case 0x13: r = 0x13; break;
    case 0x14: r = routed_status_is_one(i) ? 0x16 : 0x14; break;
    case 0x15: r = routed_status_is_one(i) ? 0x17 : 0x15; break;
    case 0x16: r = 0x16; break;
    case 0x17: r = 0x17; break;
    case 0x18: r = 0x18; break;
    case 0x19: r = 0x19; break;
    case 0x1a: r = 0x1a; break;
    case 0x1b: r = 0x1b; break;
    case 0x1c: r = routed_status_is_one(i) ? 0x1e : 0x1c; break;
    case 0x1d: r = routed_status_is_one(i) ? 0x1f : 0x1d; break;
    case 0x1e: r = 0x1e; break;
    case 0x1f: r = 0x1f; break;
    case 0x20: r = 0x20; break;
    case 0x21: r = 0x21; break;
    case 0x22: r = routed_status_is_one(i) ? 0x24 : 0x22; break;
    case 0x23: r = routed_status_is_one(i) ? 0x25 : 0x23; break;
    case 0x24: r = 0x24; break;
    case 0x25: r = 0x25; break;
    case 0x26: r = 0x26; break;
    case 0x27: r = 0x27; break;
    default: r = 0x28; break;
    }
    return r;
}
