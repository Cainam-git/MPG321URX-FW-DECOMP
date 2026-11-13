/* input_find_port_entry_by_bus_id  (FUN_a0142218)
 *
 * Return the index of the port entry with the given bus id.
 * Returns: index or 0xFF
 * Name basis: derived - compares byte 0x10 of the seven port entries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142218 @ 0xa0142218-0xa014226c, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 */

/* A port entry (0x12 bytes), up to the field used here. */
struct port_entry {
    unsigned short half_0, half_2;
    unsigned char pad[0xc];
    unsigned char bus_id;           /* +0x10 */
    unsigned char byte_0x11;
};
extern struct port_entry port_entries[7];

#define PORT_ENTRY_COUNT 7
#define NO_ENTRY         0xff

/*
 * Return the index of the first port entry whose bus id (byte +0x10) is bus_id, or 0xFF when none has it.
 */
unsigned char input_find_port_entry_by_bus_id(unsigned char bus_id)
{
    unsigned char found = NO_ENTRY;
    unsigned char i;

    for (i = 0; i <= PORT_ENTRY_COUNT - 1; i++) {
        if (port_entries[i].bus_id == bus_id) {
            found = i;
            break;
        }
    }
    return found;
}
