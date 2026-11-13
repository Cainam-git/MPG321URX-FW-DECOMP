/* input_get_port_entry_word_e  (FUN_a012b370)
 *
 * Return the 16-bit field at +0x0E of a port entry.
 * Returns: value
 * Name basis: descriptive - 18-byte port entries at 0xA802E116; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b370 @ 0xa012b370, flags -mcpu=v8 -O3 -g.
 */
/* One port entry (0x12 bytes at port_entries); only the halfword +0x0E is named here. */
struct port_entry { unsigned char unused_00[0xe]; unsigned short halfword_0x0e; unsigned char unused_10[2]; };
extern struct port_entry port_entries[];

/*
 * Return the halfword at +0x0E of port entry `entry`.
 */
unsigned short input_get_port_entry_word_e(unsigned char entry)
{
    return port_entries[entry].halfword_0x0e;
}
