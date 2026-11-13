/* input_api_menu_index_to_port_code  (FUN_a014464c)
 *
 * Translate a menu index to the code of its input port.
 * Returns: port code or 0xFF
 * Name basis: descriptive - table at 0x1A6DB2, then the source -> port chain; unused
 *
 * Matching notes
 * --------------
 * leon2m input_api_menu_index_to_port_code @ 0xa014464c, flags -mcpu=v8 -O3 -g.
 * Source form: the three lookups are separate local variables; each result is masked to a byte before the
 * next call and before the return. INPUT_MENU_SOURCE_PAIR_STRIDE expands to 2.
 */
extern int input_port_table_find_code(int);
extern int input_find_port_entry_by_bus_id(int);
extern int input_entry_index_to_port_code(int);
extern const unsigned char input_menu_source_pairs[];

#define INPUT_MENU_SOURCE_PAIR_STRIDE 2  /* two bytes per {source id, menu index} pair */

/*
 * Translate a menu index to the code of its input port.
 *
 * menu_index is used as the index of a pair in input_menu_source_pairs; the even element of that pair is the
 * source id. The result of each lookup is masked to a byte before it is passed to the next lookup, and the
 * final byte result is returned.
 *
 * No routine calls it by name.
 */
int input_api_menu_index_to_port_code(int menu_index)
{
    /* The even element of the selected pair is the source id. */
    int input_index = input_port_table_find_code(input_menu_source_pairs[(menu_index & 0xff) * INPUT_MENU_SOURCE_PAIR_STRIDE]);
    /* The byte result of the first lookup is used as the bus id for the next lookup. */
    int port_entry_index = input_find_port_entry_by_bus_id(input_index & 0xff);
    int port_code = input_entry_index_to_port_code(port_entry_index & 0xff);
    return port_code & 0xff;
}
