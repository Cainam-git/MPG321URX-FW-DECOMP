/* input_port_entry_is_class5  (FUN_a0142110)
 *
 * Return whether the class field of a port entry is 5.
 * Returns: 0 or 1
 * Name basis: descriptive - top nibble of the first halfword of the port entry; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142110 @ 0xa0142110-0xa0142140, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Nothing in the image refers to it (no call, branch or address constant).
 */

/* A port entry (0x12 bytes), up to the field used here. */
struct port_entry {
    unsigned short head;            /* class in bits 12-15 */
    unsigned char rest[0x10];
};
extern struct port_entry port_entries[];

#define PORT_CLASS_SHIFT 12

/*
 * Return 1 when the class of a port entry is 5, else 0.
 *
 *   entry  the entry index
 *
 * Nothing in the image calls this routine.
 */
unsigned int input_port_entry_is_class5(unsigned char entry)
{
    return (port_entries[entry].head >> PORT_CLASS_SHIFT) == 5;
}
