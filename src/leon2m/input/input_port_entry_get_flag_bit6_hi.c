/* input_port_entry_get_flag_bit6_hi  (FUN_a01420e4)
 *
 * Return flag bit 6 of the second halfword of a port entry.
 * Returns: 0 or 1
 * Name basis: descriptive - 18-byte port entries at 0xA802E116; used by the keep-or-restart check
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01420e4 @ 0xa01420e4-0xa0142110, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 */

/* A port entry (0x12 bytes), up to the fields used here. */
struct port_entry {
    unsigned short half_0;
    unsigned short flags_2;         /* +2 */
    unsigned char rest[0x12 - 4];
};
extern struct port_entry port_entries[];

/*
 * Return bit 6 of the halfword at +2 of a port entry.
 *
 *   entry  the entry index
 *
 * The only caller is input_port_is_av_muted, which asks it for entry 0 and 1.
 */
unsigned int input_port_entry_get_flag_bit6_hi(unsigned char entry)
{
    return (port_entries[entry].flags_2 >> 6) & 1;
}
