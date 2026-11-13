/* input_get_port_class  (FUN_a0141ce0)
 *
 * Return the class field of the port entry for a port code.
 * Returns: class, 8 for another code
 * Name basis: descriptive - bits 12..15 of the first halfword; port codes 0x51..0x81
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141ce0 @ 0xa0141ce0-0xa0141d50, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: each of the four entries is a separate extern label (its own address
 * constant) read as a halfword; port_entry1..3 are entries 1..3 of port_entries.
 */

extern unsigned short port_entries, port_entry1, port_entry2, port_entry3;     /* first halfword of entries 0..3 */

#define PORT_CODE_ENTRY0 0x51
#define PORT_CODE_ENTRY1 0x61
#define PORT_CODE_ENTRY2 0x71
#define PORT_CODE_ENTRY3 0x81
#define PORT_CLASS_SHIFT 12             /* the class is bits 12-15 of the entry's first halfword */
#define PORT_CLASS_NONE  8              /* returned for any other port code */

/*
 * Return the class of the port entry that belongs to a port code.
 *
 *   port_code  0x51, 0x61, 0x71 or 0x81 for entries 0 to 3
 *
 * For any other code the answer is 8. Called from sys_apply_pip_layout and sys_set_channel_enable.
 */
int input_get_port_class(unsigned char port_code)
{
    int port_class;

    switch (port_code) {
    case PORT_CODE_ENTRY0: port_class = port_entries >> PORT_CLASS_SHIFT; break;
    case PORT_CODE_ENTRY1: port_class = port_entry1 >> PORT_CLASS_SHIFT; break;
    case PORT_CODE_ENTRY2: port_class = port_entry2 >> PORT_CLASS_SHIFT; break;
    case PORT_CODE_ENTRY3: port_class = port_entry3 >> PORT_CLASS_SHIFT; break;
    default: port_class = PORT_CLASS_NONE; break;
    }
    return port_class;
}
