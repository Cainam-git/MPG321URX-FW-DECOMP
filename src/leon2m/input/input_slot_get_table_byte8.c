/* input_slot_get_table_byte8  (FUN_a01254f8)
 *
 * Return byte +8 of the port table entry of a slot.
 * Returns: byte
 * Name basis: descriptive - slot -> row through the table at 0xA802D880
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01254f8 @ 0xa01254f8, flags -mcpu=v8 -O3 -g.
 * Source form: the result is an int set to -1 and narrowed on return (mov -1, then the zero-extension).
 */
/* Bytes +8..+0x0A of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry {
    unsigned char unused_00[4];
    unsigned short edid_size;
    unsigned char unused_06, unused_07;
    unsigned char byte_0x08, byte_0x09, byte_0x0a;
    unsigned char unused_0b[11];
};
extern unsigned char port_table[];
extern unsigned char port_table_index_by_bus_id[];    /* port table index of each bus id, 0xFF if none (startup_init_pins) */

/*
 * Return byte +0x08 of the port table entry of the input with the given bus id, or 0xFF when no entry has that
 * bus id.
 *
 *   bus_id  bus id, 0..6
 */
unsigned char input_slot_get_table_byte8(unsigned char bus_id)
{
    unsigned int index = port_table_index_by_bus_id[bus_id];
    struct port_table_entry *entry = (struct port_table_entry *)port_table + index;
    int value = -1;

    if (index != 0xff)
        value = entry->byte_0x08;
    return value;
}
