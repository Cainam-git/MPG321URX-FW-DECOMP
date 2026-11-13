/* input_set_port_class  (FUN_a0141d50)
 *
 * Store the class field of the port entry for a port code.
 * Name basis: descriptive - bits 12..15 of the first halfword; port codes 0x51..0x81
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141d50 @ 0xa0141d50-0xa0141e0c, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the case labels are in the order 0x71, 0x51, 0x61, 0x81 (the order sets
 * the compare chain and the registers); the class is a four-bit bit-field at the top of the halfword.
 */

/* The first halfword of a port entry: the class in bits 12-15, then the flags. */
struct port_entry_head {
    unsigned short port_class:4;
    unsigned short flags:12;
};
struct port_entry {
    struct port_entry_head head;
    unsigned short rest[8];
};
extern struct port_entry port_entries[4];

/*
 * Store the class of the port entry that belongs to a port code.
 *
 *   port_code   0x51, 0x61, 0x71 or 0x81 for entries 0 to 3; any other code does nothing
 *   port_class  the class to store (4 bits)
 *
 * Called from sys_apply_pip_layout and sys_set_channel_enable.
 */
void input_set_port_class(unsigned char port_code, unsigned char port_class)
{
    switch (port_code) {
    case 0x71: port_entries[2].head.port_class = port_class; break;
    case 0x51: port_entries[0].head.port_class = port_class; break;
    case 0x61: port_entries[1].head.port_class = port_class; break;
    case 0x81: port_entries[3].head.port_class = port_class; break;
    }
}
