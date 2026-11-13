/* input_port_id_to_entry_index  (FUN_a0142168)
 *
 * Convert a port id to its index in the port entry table.
 * Returns: index
 * Name basis: derived - used wherever a channel's port is looked up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142168 @ 0xa0142168, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: a plain switch on the unsigned char with the cases in ascending order
 * (the compiler builds the signed compare tree around 0x71), the result in an unsigned char local.
 */

#define NO_ENTRY 0xff

/*
 * Convert a port code to the index of its entry in the port entry table.
 *
 *   port_code  0x51, 0x61, 0x71, 0x81 give entries 0 to 3, 0xE8 gives entry 6
 *
 * Any other code gives 0xFF. input_entry_index_to_port_code is the inverse. Used wherever the code of a port
 * (byte +0xA of a port record) has to be turned into an entry.
 */
unsigned char input_port_id_to_entry_index(unsigned char port_code)
{
    unsigned char entry;
    switch (port_code) {
    case 0x51: entry = 0; break;
    case 0x61: entry = 1; break;
    case 0x71: entry = 2; break;
    case 0x81: entry = 3; break;
    case 0xe8: entry = 6; break;
    default: entry = NO_ENTRY; break;
    }
    return entry;
}
