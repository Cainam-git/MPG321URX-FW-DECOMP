/* edid_api_read_port_edid  (FUN_a014b0c4)
 *
 * Read the whole EDID of the input port that belongs to a source.
 * Name basis: derived - reads the port's EDID memory in full; the port memory is the one 'Enable Internal
 *   EDID' switches
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b0c4, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the same switch as edid_api_write_port_edid_bytes (entry preset to 0,
 * an explicit case for port code 0x51, the entry an unsigned short); the callee takes five arguments and is a
 * tail call.
 */
#define PORT_CODE_ENTRY0 0x51   /* port codes of port entries 0..3 */
#define PORT_CODE_ENTRY1 0x61
#define PORT_CODE_ENTRY2 0x71
#define PORT_CODE_ENTRY3 0x81

struct port_entry { unsigned char byte_0x00[0x10]; unsigned char bus_id; unsigned char byte_0x11; };
extern struct port_entry port_entries[];
extern int input_port_table_find_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern int input_entry_index_to_port_code(unsigned char);
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void edid_read_port_edid(unsigned char, unsigned short, int, unsigned short *, unsigned char);

/*
 * Read the whole EDID memory of the input port that belongs to a source.
 *
 *   source  port code of the source; it is turned into a port entry 0..3 (anything else uses entry 0), and the
 *           bus id of that entry names the port whose EDID memory is read
 *   buf     receives the EDID bytes (the buffer address, passed as an int)
 *   size    receives the size of the EDID memory, which is the number of bytes read
 *
 * Called by ddc_answer_maker_vcp_get.
 */
void edid_api_read_port_edid(unsigned char source, int buf, unsigned short *size)
{
  unsigned short entry;

  entry = 0;
  switch ((unsigned char)input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source)))) {
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
  edid_read_port_edid(input_port_table_get_bus_id(port_entries[entry].bus_id), 0, buf, size, 0);
}
