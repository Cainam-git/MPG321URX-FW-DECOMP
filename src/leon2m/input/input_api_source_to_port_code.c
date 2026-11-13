/* input_api_source_to_port_code  (FUN_a0144574)
 *
 * Convert a source id to the code of its input port.
 * Returns: port code or 0xFF
 * Name basis: derived - the three-step source -> port chain; returns 0x51/0x61/0x71/0x81; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144574 @ 0xa0144574, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: one int parameter and an int return; the three callees are declared
 * with int parameters and results, each argument masked to a byte.
 */

extern int input_port_table_find_code(int);
extern int input_find_port_entry_by_bus_id(int);
extern int input_entry_index_to_port_code(int);

/*
 * Convert a source to the code of its input port (0x51, 0x61, 0x71, 0x81, or 0xFF).
 *
 *   source  the source, as input_port_table_find_code takes it
 *
 * The source is turned into an index (input_port_table_find_code), that into a port entry
 * (input_find_port_entry_by_bus_id), and the entry number into its port code (input_entry_index_to_port_code).
 */
int input_api_source_to_port_code(int source)
{
    int index = input_port_table_find_code(source & 0xff);
    int entry = input_find_port_entry_by_bus_id(index & 0xff);
    int port_code = input_entry_index_to_port_code(entry & 0xff);
    return port_code & 0xff;
}
