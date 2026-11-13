/* input_api_get_channel_port_byte5  (FUN_a01447bc)
 *
 * Return byte 5 of the port entry of the input that a channel shows.
 * Returns: byte
 * Name basis: descriptive - same chain as input_api_get_channel_port_code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01447bc @ 0xa01447bc-0xa014489c, flags -mcpu=v8 -O3 -g.
 * Source form: the channel range check is a static remap() switch, and the final byte read is the static helper
 * entry_byte5() with its clamp, inlined.
 */
/* Four channel records: state, port, picture window and timing. */
struct channel_record {
    unsigned int word0;                 /* +0x0: bits 12-15 select the port record */
    unsigned char pad4[0x74];
};
extern struct channel_record channel_records[4];

/* One record per input port: status bits, state, type, mode and time stamp. */
struct port_record {
    unsigned char bytes[42];            /* +0xA: the port code passed to input_port_id_to_entry_index */
};
extern struct port_record port_records[];

extern int dbg_printf();
extern int input_port_id_to_entry_index(unsigned char);

#define LAST_CHANNEL 3                  /* channel_records has four entries */
#define LAST_PORT_ENTRY 6               /* port_entries has seven entries */

/* Channels 0-3 pass through; anything else is out of range. */
static int remap(int channel)
{
    switch (channel) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Seven port entries; byte +5 is the value returned by this routine. */
struct port_entry {
    unsigned char pad0[5];
    unsigned char byte5;
    unsigned char pad6[10];
    unsigned char bus_id;               /* +0x10; not read here */
    unsigned char byte_0x11;
};
extern struct port_entry port_entries[7];

/* An index above the last port entry is clamped to entry 0. */
static unsigned char entry_byte5(unsigned char entry_index)
{
    if (entry_index > LAST_PORT_ENTRY)
        entry_index = 0;
    return port_entries[entry_index].byte5;
}

/*
 * Return byte 5 of the port entry for the input shown by a channel.
 *
 * channel: 0-3, the picture channel whose channel record selects the input port.
 *
 * Callers: APPActionDispatcher, osd_draw_info_box_values.
 *
 * word0 bits 12-15 of the channel record select a port record. Byte +0xA of that port record is its port code;
 * input_port_id_to_entry_index converts it to an index in the seven port entries. An out-of-range channel
 * prints the debug message and uses channel 0; an out-of-range port entry index uses entry 0.
 */
unsigned char input_api_get_channel_port_byte5(unsigned char channel)
{
    unsigned char channel_index = remap(channel);
    if (channel_index > LAST_CHANNEL) {
        /* Out-of-range channel: report it and fall back to channel 0. */
        dbg_printf("SYS remapping channel OOR\r\n");
        channel_index = 0;
    }
    return entry_byte5(input_port_id_to_entry_index(port_records[(channel_records[channel_index].word0 >> 12) & 0xf].bytes[0xa]) & 0xff);
}
