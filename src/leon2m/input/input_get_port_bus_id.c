/* input_get_port_bus_id  (FUN_a014af84)
 *
 * Return the bus id of the input port that belongs to a source code.
 * Returns: bus id
 * Name basis: descriptive - maps the source to port entry 0..3 (codes 0x51/0x61/0x71/0x81) and returns byte +2
 *   (the bus id) of that entry's row in the port table; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014af84 @ 0xa014af84-0xa014b01c (152 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: k = 0 before a switch that lists case 0x51 with the default value (keeps the compare-tree root at 0x61).
 */
/* The seven port entries: the inputs as the control logic sees them (0x12 bytes each). */
struct port_entry {
    unsigned char pad0[0x10];
    unsigned char byte_0x10;   /* +0x10: index into the port table */
    unsigned char byte_0x11;   /* +0x11 */
};
extern struct port_entry port_entries[];
extern int input_port_table_find_code(unsigned char source_code);
extern unsigned char input_find_port_entry_by_bus_id(unsigned char bus_id);
extern unsigned char input_entry_index_to_port_code(unsigned char port_entry_index);
extern unsigned char input_port_table_get_bus_id(unsigned int port_code);

/*
 * Return the bus id of the input port that belongs to a source code.
 *
 * The source code is resolved to a port code (port table index, the entry with that bus id, its code).
 * Port codes 0x61, 0x71, 0x81 select port entries 1, 2, 3; 0x51 and any other code select entry 0.
 * Byte +0x10 of that entry is an index into the port table, and input_port_table_get_bus_id returns
 * byte +2 of that table entry.
 *
 * No direct call to it was found in the image.
 */
unsigned char input_get_port_bus_id(unsigned char source_code)
{
    unsigned char port_code = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source_code)));
    unsigned char port_entry_index = 0;

    switch (port_code) {
    case 0x51:
        port_entry_index = 0;
        break;
    case 0x61:
        port_entry_index = 1;
        break;
    case 0x71:
        port_entry_index = 2;
        break;
    case 0x81:
        port_entry_index = 3;
        break;
    }
    return input_port_table_get_bus_id(port_entries[port_entry_index & 3].byte_0x10);
}
