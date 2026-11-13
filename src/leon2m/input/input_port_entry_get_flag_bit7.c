/* input_port_entry_get_flag_bit7  (FUN_a014230c)
 *
 * Return flag bit 7 of the second halfword of port entry 0 or 1.
 * Returns: 0 or 1
 * Name basis: descriptive - 0 for other entries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014230c @ 0xa014230c-0xa0142360, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the range test is a static helper returning an unsigned char 1 or 0 from
 * two return statements (the compiler keeps its result as a flag that is tested afterwards); the entry address is
 * computed before the test; the result variable is returned as "result & 1".
 */

/* A port entry (0x12 bytes), up to the fields used here. */
struct port_entry {
    unsigned short half_0, flags_2;
    unsigned char pad[0xc];
    unsigned char bus_id, byte_0x11;
};
extern struct port_entry port_entries[7];

static unsigned char entry_is_0_or_1(unsigned int entry)
{
    if (entry <= 1)
        return 1;
    return 0;
}

/*
 * Return bit 7 of the halfword at +2 of port entry 0 or 1. For any other entry the answer is 0.
 *
 *   entry  the entry index
 *
 * Called from input_api_is_channel_port_flagged.
 */
int input_port_entry_get_flag_bit7(unsigned int entry)
{
    struct port_entry *e = &port_entries[entry];
    unsigned char result = 0;

    if (entry_is_0_or_1(entry))
        if (e->flags_2 & 0x80)
            result = 1;
    return result & 1;
}
