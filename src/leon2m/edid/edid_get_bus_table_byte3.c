/* edid_get_bus_table_byte3  (FUN_a0124fb4)
 *
 * Return byte 3 of an entry of the four-byte EDID bus table.
 * Returns: byte
 * Name basis: descriptive - ROM table at 0x1A4288; used by the EDID read and write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124fb4 @ 0xa0124fb4, flags -mcpu=v8 -O2 -g.
 * Source form: the table is a plain (non-volatile) unsigned char array indexed with the byte offset added.
 */
extern unsigned char edid_bus_table[];

/*
 * Return byte 3 of entry `entry` of edid_bus_table (4-byte entries; only the low byte of `entry` counts).
 * Called by edid_read_port_edid and edid_write_port_edid.
 */
unsigned char edid_get_bus_table_byte3(unsigned int entry)
{
    return edid_bus_table[(entry & 0xff) * 4 + 3];
}
