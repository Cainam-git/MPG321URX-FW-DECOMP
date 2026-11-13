/* edid_get_port_memory_size  (FUN_a01255a0)
 *
 * Return the size of an input's EDID memory.
 * Returns: size
 * Name basis: derived - halfword +4 of the port table entry of the slot
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01255a0 @ 0xa01255a0, flags -mcpu=v8 -O3 -g.
 * Source form: the row is addressed as `(struct port_table_entry *)port_table + row` before the 0xff test, and
 * the size is an int set to -1 and narrowed on return (mov -1, then the zero-extension).
 */
/* One 0x16-byte record of the port table (docs/DATA.md); only the EDID size is read here. */
struct port_table_entry {
    unsigned char code, type, bus_id, byte_0x03;    /* +0..+3 */
    unsigned short edid_size;                       /* +4: size of the EDID memory */
    unsigned char rest[16];                         /* +6..+0x15 */
};
extern unsigned char port_table[];
extern unsigned char port_table_index_by_bus_id[];                /* row in port_table by bus id; 0xff = no row */

#define NO_ROW   0xff

/*
 * Return the size of the EDID memory of the input with this bus id (+4 of its port table row), or 0xffff when
 * no row has that bus id.
 * Called by edid_read_port_edid, edid_write_port_edid and startup_load_port_edids.
 */
unsigned short edid_get_port_memory_size(unsigned char bus_id)
{
    unsigned int row = port_table_index_by_bus_id[bus_id];
    struct port_table_entry *entry = (struct port_table_entry *)port_table + row;
    int size = -1;

    if (row != NO_ROW)
        size = entry->edid_size;
    return size;
}
