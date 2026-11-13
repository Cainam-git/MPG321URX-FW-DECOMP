/* input_api_get_channel_port_code  (FUN_a014448c)
 *
 * Return the port code of the input that a channel shows.
 * Returns: port code
 * Name basis: derived - channel record -> port record -> port entry -> code of the ROM port table; many
 *   callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014448c @ 0xa014448c-0xa0144574, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the same lookup as input_api_get_channel_status_bit_second with its
 * last call replaced by a static getter (inlined) that reads the bus id of a port entry and the call of
 * input_port_table_get_code.
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
extern unsigned char input_port_table_get_code(unsigned char bus_id);

#define CHANNEL_PORT_SHIFT 12           /* the port is bits 12-15 of the channel's status word */
#define PORT_ENTRY_COUNT   7

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

/* A port entry (0x12 bytes), up to the fields used here. */
struct port_entry { unsigned char pad[5]; unsigned char byte_5; unsigned char pad6[10]; unsigned char bus_id; unsigned char byte_0x11; };
extern struct port_entry port_entries[PORT_ENTRY_COUNT];

/* The bus id of a port entry; an entry number above 6 reads entry 0. */
static unsigned char get_bus_id(unsigned char entry)
{
    if (entry > PORT_ENTRY_COUNT - 1)
        entry = 0;
    return port_entries[entry].bus_id;
}

/*
 * Return the port code (as the port table lists it) of the input that a channel shows.
 *
 *   channel  the channel number; a number above 3 prints "SYS remapping channel OOR" and uses channel 0
 *
 * Chain: the channel's port record gives a port code (byte +0xA), that gives a port entry, the entry gives a
 * bus id (byte +0x10), and input_port_table_get_code turns the bus id into the code.
 */
unsigned char input_api_get_channel_port_code(unsigned char channel)
{
    unsigned char index = remap_channel(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    return input_port_table_get_code(get_bus_id(input_port_id_to_entry_index(port_records[(channel_records[index].status_word >> CHANNEL_PORT_SHIFT) & 0xf].port_code) & 0xff));
}
