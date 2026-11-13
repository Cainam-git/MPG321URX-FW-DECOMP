/* input_set_main_ports_class_2  (FUN_a0141b10)
 *
 * Set the class field of the four main port entries to 2.
 * Name basis: descriptive - bits 12..15 of the first halfword; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141b10 @ 0xa0141b10, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the class is a four-bit bit-field at the top of the halfword, written by
 * four separate statements. Nothing in the image refers to it (no call, branch or address constant).
 */

/* The first halfword of a port entry; an entry is 0x12 bytes. */
struct port_entry_head {
    unsigned short port_class:4;    /* bits 12-15 */
    unsigned short flag_bit_11:1;
    unsigned short flags_10_6:5;
    unsigned short flag_bit_5:1;
    unsigned short flag_bit_4:1;
    unsigned short flags_3_0:4;
};
struct port_entry { struct port_entry_head head; unsigned char rest[0x12 - 0x02]; };
extern struct port_entry port_entries[];

/*
 * Set the class of the first four port entries (port codes 0x51, 0x61, 0x71, 0x81) to 2.
 */
void input_set_main_ports_class_2(void)
{
    port_entries[0].head.port_class = 2;
    port_entries[1].head.port_class = 2;
    port_entries[2].head.port_class = 2;
    port_entries[3].head.port_class = 2;
}
