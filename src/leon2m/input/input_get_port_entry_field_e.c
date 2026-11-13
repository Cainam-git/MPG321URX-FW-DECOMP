/* input_get_port_entry_field_e  (FUN_a0141e0c)
 *
 * Return the 16-bit field at +0x0E of the port entry for a port code.
 * Returns: value, 0 for another code
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141e0c @ 0xa0141e0c-0xa0141e74, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Nothing in the image refers to it (no call, branch or address constant).
 */

/* A port entry (0x12 bytes), up to the field used here. */
struct port_entry {
    unsigned char pad0[0xe];
    unsigned short half_0xe;
    unsigned char pad10[2];
};
extern struct port_entry port_entries[];

/*
 * Return the halfword at +0xE of the port entry that belongs to a port code.
 *
 *   port_code  0x51, 0x61, 0x71 or 0x81 for entries 0 to 3
 *
 * For any other code the answer is 0. Nothing in the image calls this routine.
 */
unsigned short input_get_port_entry_field_e(unsigned char port_code)
{
    switch (port_code) {
    case 0x51:
        return port_entries[0].half_0xe;
    case 0x61:
        return port_entries[1].half_0xe;
    case 0x71:
        return port_entries[2].half_0xe;
    case 0x81:
        return port_entries[3].half_0xe;
    default:
        return 0;
    }
}
