/* edid_api_enable_internal_edid  (FUN_a014b65c)
 *
 * Switch the internal EDID of an input port on or off.
 * Name basis: proven - forwards to the routine that prints 'Enable Internal EDID'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b65c, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the port code is kept in a local and the entry is an unsigned char
 * preset to 0 with a listed case 0x51; the entry index is masked with 3 when used; GCC duplicates the tail call
 * per case.
 */
#define PORT_CODE_ENTRY0 0x51   /* port codes of port entries 0..3 */
#define PORT_CODE_ENTRY1 0x61
#define PORT_CODE_ENTRY2 0x71
#define PORT_CODE_ENTRY3 0x81

struct port_entry { unsigned char byte_0x00[0x10]; unsigned char bus_id; unsigned char byte_0x11; };
extern struct port_entry port_entries[];
extern int input_port_table_find_code(unsigned char);
extern unsigned char input_find_port_entry_by_bus_id(unsigned char v);
extern unsigned char input_entry_index_to_port_code(unsigned char x);
extern unsigned char input_port_table_get_bus_id(unsigned int param_1);
extern void edid_enable_internal_edid(unsigned char, unsigned char);

/*
 * Switch the internal EDID of the input port that belongs to a source on (on != 0) or off.
 * The source is turned into a port entry 0..3 (anything else uses entry 0); the bus id of that entry names
 * the port.
 * Called by input_enable_four_port_items.
 */
void edid_api_enable_internal_edid(unsigned char source, unsigned char on)
{
    unsigned char port_code = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source)));
    unsigned char entry = 0;

    switch (port_code) {
    case PORT_CODE_ENTRY0:
        entry = 0;
        break;
    case PORT_CODE_ENTRY1:
        entry = 1;
        break;
    case PORT_CODE_ENTRY2:
        entry = 2;
        break;
    case PORT_CODE_ENTRY3:
        entry = 3;
        break;
    }
    edid_enable_internal_edid(input_port_table_get_bus_id(port_entries[entry & 3].bus_id), on);
}
