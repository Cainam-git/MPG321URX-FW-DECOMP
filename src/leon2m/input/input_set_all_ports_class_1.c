/* input_set_all_ports_class_1  (FUN_a0141c98)
 *
 * Set the class field of all seven port entries to 1.
 * Name basis: descriptive - bits 12..15 of the first halfword; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141c98 @ 0xa0141c98-0xa0141ce0, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the class is a four-bit bit-field at the top of the halfword (the layout
 * used for port_entries elsewhere), set in a loop. Nothing in the image refers to it (no call, branch or address
 * constant).
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

#define PORT_ENTRY_COUNT 7

/*
 * Set the class of all seven port entries to 1.
 */
void input_set_all_ports_class_1(void)
{
    unsigned char i;

    for (i = 0; i < PORT_ENTRY_COUNT; i++)
        port_entries[i].head.port_class = 1;
}
