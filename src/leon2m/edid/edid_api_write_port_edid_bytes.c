/* edid_api_write_port_edid_bytes  (FUN_a014b360)
 *
 * Write given bytes at an address into the EDID memory of the input port that belongs to a source.
 * Name basis: derived - same port lookup, then edid_write_port_edid with its own address, data and length and
 *   partial = 1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b360, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: a switch with the entry preset to 0 and an explicit 'case 0x51: entry = 0'
 * (same behaviour as the default; it makes 0x61 the root of the case tree, and its block merges with the
 * default); the entry is an unsigned short (the firmware's 'and 3' is the reduced zero-extension; an unsigned
 * char gives 'and 0xff'); the base is port_entries. The tail call takes five arguments; the data pointer is
 * passed through unchanged (no code for it).
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
extern void edid_write_port_edid(unsigned char, unsigned short, int, unsigned short, unsigned char);

/*
 * Write part of an EDID to the input port that belongs to a source: length bytes of data at address addr of
 * the port's EDID memory (edid_write_port_edid with its "partial" argument set to 1).
 *
 *   source  port code of the source; it is turned into a port entry 0..3 (anything else uses entry 0), and the
 *           bus id of that entry names the port
 *   addr    first byte of the EDID memory to write
 *   data    bytes to write (the buffer address, passed as an int)
 *   length  number of bytes in data
 *
 * Nothing calls it. It does not select the built-in default EDID: that is done by edid_write_port_edid for a
 * whole write (partial 0) when the port has a variant stored.
 */
void edid_api_write_port_edid_bytes(unsigned char source, unsigned short addr, int data, unsigned short length)
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
  edid_write_port_edid(input_port_table_get_bus_id(port_entries[entry].bus_id), addr, data, length, 1);
}
