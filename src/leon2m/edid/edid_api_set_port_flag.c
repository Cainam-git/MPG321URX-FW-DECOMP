/* edid_api_set_port_flag  (FUN_a014b750)
 *
 * Set or clear the per-port flag bit that accompanies the internal EDID.
 * Name basis: descriptive - bit per port in the byte at 0xA802C9FA; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b750, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the same form as edid_api_enable_internal_edid (port code kept in a
 * local, entry an unsigned char preset to 0 with a listed case 0x51, entry masked with 3 when used).
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
extern void edid_set_port_flag(unsigned char n, unsigned char on);

/*
 * Set (on != 0) or clear the per-port flag that edid_get_port_flag reads back, for the input port that belongs
 * to a source. The source is turned into a port entry 0..3 (anything else uses entry 0); the bus id of that
 * entry names the port. Nothing calls it.
 */
void edid_api_set_port_flag(unsigned char source, unsigned char on)
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
    edid_set_port_flag(input_port_table_get_bus_id(port_entries[entry & 3].bus_id), on);
}
