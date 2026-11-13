/* input_port_entry_get_flag_bit6  (FUN_a0142140)
 *
 * Return flag bit 6 of the first halfword of a port entry.
 * Returns: 0 or 1
 * Name basis: descriptive - 18-byte port entries at 0xA802E116; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142140 @ 0xa0142140-0xa0142168, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Nothing in the image refers to it (no call, branch or address constant).
 */

/* A port entry (0x12 bytes), up to the field used here. */
struct port_entry {
    unsigned short head;            /* class in bits 12-15, then the flags */
    unsigned char rest[0x10];
};
extern struct port_entry port_entries[];

/*
 * Return bit 6 of the first halfword of a port entry.
 *
 *   entry  the entry index
 *
 * Nothing in the image calls this routine.
 */
unsigned int input_port_entry_get_flag_bit6(unsigned char entry)
{
    return (port_entries[entry].head >> 6) & 1;
}
