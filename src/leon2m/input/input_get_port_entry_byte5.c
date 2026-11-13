/* input_get_port_entry_byte5  (FUN_a0141e74)
 *
 * Return byte 5 of the port entry for a port code.
 * Returns: byte, 8 for another code
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141e74 @ 0xa0141e74-0xa0141edc, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Nothing in the image refers to it (no call, branch or address constant).
 */

/* A port entry (0x12 bytes), up to the field used here. */
struct port_entry {
    unsigned char pad0[5];
    unsigned char byte_5;
    unsigned char pad6[0xc];
};
extern struct port_entry port_entries[];

/*
 * Return byte +5 of the port entry that belongs to a port code.
 *
 *   port_code  0x51, 0x61, 0x71 or 0x81 for entries 0 to 3
 *
 * For any other code the answer is 8. Nothing in the image calls this routine.
 */
unsigned char input_get_port_entry_byte5(unsigned char port_code)
{
    switch (port_code) {
    case 0x51:
        return port_entries[0].byte_5;
    case 0x61:
        return port_entries[1].byte_5;
    case 0x71:
        return port_entries[2].byte_5;
    case 0x81:
        return port_entries[3].byte_5;
    default:
        return 8;
    }
}
