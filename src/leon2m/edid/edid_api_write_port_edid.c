/* edid_api_write_port_edid  (FUN_a014b280)
 *
 * Write an EDID, or the built-in default, to the input port that belongs to a source.
 * Note: Changes what the connected device sees.
 * Name basis: derived - records the chosen EDID variant per port, then writes the port's EDID memory; called
 *   from the EDID switching code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b280, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the same switch as edid_api_write_port_edid_bytes (entry preset to 0,
 * an explicit case for port code 0x51, the entry an unsigned short); the variant byte is stored in both arms of
 * 'if (clear == 0) ... else ...', and the call after it is a tail call.
 */
#define PORT_CODE_ENTRY0 0x51   /* port codes of port entries 0..3 */
#define PORT_CODE_ENTRY1 0x61
#define PORT_CODE_ENTRY2 0x71
#define PORT_CODE_ENTRY3 0x81

#define EDID_VARIANT          0x1b      /* device settings: one variant byte per port starts here */
#define EDID_VARIANT_NONE     0xff      /* no variant chosen for the port */

struct port_entry { unsigned char byte_0x00[0x10]; unsigned char bus_id; unsigned char byte_0x11; };
extern struct port_entry port_entries[];
extern unsigned char device_settings[];
extern int input_port_table_find_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern int input_entry_index_to_port_code(unsigned char);
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void edid_write_port_edid(unsigned char, unsigned short, int, unsigned short, unsigned char);

/*
 * Choose the EDID variant of the input port that belongs to a source and write the EDID to the port.
 *
 *   source   port code of the source; it is turned into a port entry 0..3 (anything else uses entry 0), and the
 *            bus id of that entry names the port
 *   variant  EDID variant number stored for the port
 *   data     bytes to write, passed on as they are (the buffer address, passed as an int)
 *   length   number of bytes in data
 *   clear    non-zero stores EDID_VARIANT_NONE instead of the variant
 *
 * The variant byte is kept in the device settings (EDID_VARIANT + bus id), then the whole EDID is written;
 * edid_write_port_edid uses the stored variant to pick the built-in EDID unless the variant is
 * EDID_VARIANT_NONE.
 * Called by LoadCustomerEDIDData and ddc_apply_maker_vcp_set.
 *
 * Note: Changes what the connected device sees.
 */
void edid_api_write_port_edid(unsigned char source, unsigned char variant, int data, unsigned short length, unsigned char clear)
{
  unsigned short entry;
  unsigned char bus_id;

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
  bus_id = input_port_table_get_bus_id(port_entries[entry].bus_id);
  if (clear == 0) {
    device_settings[EDID_VARIANT + bus_id] = variant;
  } else {
    device_settings[EDID_VARIANT + bus_id] = EDID_VARIANT_NONE;
  }
  edid_write_port_edid(bus_id, 0, data, length, 0);
}
