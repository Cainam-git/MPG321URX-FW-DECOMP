/* input_entry_index_to_port_code  (FUN_a01421c4)
 *
 * Convert a port entry index to its port code.
 * Returns: port code or 0xFF
 * Name basis: derived - 0..3 and 6 -> 0x51, 0x61, 0x71, 0x81, 0xE8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01421c4 @ 0xa01421c4-0xa0142218, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the result is a local that starts at 0xff and is set in the cases of
 * a switch (the firmware uses a jump table).
 */

/*
 * Convert the index of a port entry to its port code: entries 0 to 3 give 0x51, 0x61, 0x71, 0x81, entry 6
 * gives 0xE8. Any other index gives 0xFF. input_port_id_to_entry_index is the inverse.
 */
unsigned char input_entry_index_to_port_code(unsigned char entry)
{
    unsigned char port_code = 0xff;

    switch (entry) {
    case 0:
        port_code = 0x51;
        break;
    case 1:
        port_code = 0x61;
        break;
    case 2:
        port_code = 0x71;
        break;
    case 3:
        port_code = 0x81;
        break;
    case 6:
        port_code = 0xe8;
        break;
    }
    return port_code;
}
