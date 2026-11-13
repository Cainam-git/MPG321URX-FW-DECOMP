/* input_slot_get_port_code  (FUN_a0125230)
 *
 * Return the port code of the input in a given slot.
 * Returns: port code or 0xFF
 * Name basis: descriptive - slot -> row through the table at 0xA802D880
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125230 @ 0xa0125230, flags -mcpu=v8 -O3 -g.
 * Same shape as input_slot_get_table_byte8 and its two neighbours.
 */
/* Byte +0 of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry { unsigned char code; unsigned char unused_01[0x15]; };
extern const struct port_table_entry port_table[];
extern unsigned char port_table_index_by_bus_id[];    /* port table index of each bus id, 0xFF if none (startup_init_pins) */

/*
 * Return the port code of the input with the given bus id (a bus id is the field +2 of a port table entry),
 * or 0xFF when no entry has that bus id.
 *
 *   bus_id  bus id, 0..6
 */
unsigned char input_slot_get_port_code(unsigned char bus_id)
{
    unsigned int index = port_table_index_by_bus_id[bus_id];
    unsigned short code = 0xff;

    if (index != 0xff)
        code = port_table[index].code;
    return code;
}
