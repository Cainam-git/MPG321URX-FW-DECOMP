/* edid_api_read_port_edid_range  (FUN_a014b1c8)
 *
 * Read part of the EDID of the input port that belongs to a source.
 * Name basis: derived - as edid_api_read_port_edid with an address and a length; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b1c8, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the same mapping as edid_api_enable_internal_edid (port code kept in a
 * local, entry preset to 0 with a listed case 0x51); the length is copied into a local halfword, declared first,
 * whose address is passed on; the entry index is masked with 3 when used.
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
extern void edid_read_port_edid(unsigned char, unsigned short, int, unsigned short *, unsigned char);

/*
 * Read part of the EDID memory of the input port that belongs to a source.
 *
 *   source  port code of the source; it is turned into a port entry 0..3 (anything else uses entry 0), and the
 *           bus id of that entry names the port whose EDID memory is read
 *   addr    first byte to read
 *   buf     receives the bytes (the buffer address, passed as an int)
 *   length  number of bytes to read
 *
 * Nothing calls it.
 */
void edid_api_read_port_edid_range(unsigned char source, unsigned short addr, int buf, unsigned short length)
{
    unsigned short length_copy = length;
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
    edid_read_port_edid(input_port_table_get_bus_id(port_entries[entry & 3].bus_id), addr, buf, &length_copy, 1);
}
