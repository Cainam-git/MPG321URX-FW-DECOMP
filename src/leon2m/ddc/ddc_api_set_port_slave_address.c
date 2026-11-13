/* ddc_api_set_port_slave_address  (FUN_a014b01c)
 *
 * Store a DDC/CI slave address for the port of a source and have the 8051 switch that slave on.
 *   port_code: source code whose port is meant
 *   slave_address: the DDC/CI slave address
 * Name basis: derived - port chosen as in input_get_port_bus_id; ddc_set_port_slave_address, then
 *   ipc_8051_enable_ddc_slave(1 << bus id, address); no routine calls it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b01c @ 0xa014b01c-0xa014b0c4 (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: one nested call chain, the record base port_entries + 0x10, u8 prototypes.
 * The explicit 'case 0x51: i = 0' (same value as the default) gives the fw case tree with 0x61 at the root.
 */
struct port_entry {
    unsigned char pad0[0x10];
    unsigned char byte_0x10;   /* +0x10: index into the port table */
    unsigned char byte_0x11;
};
extern struct port_entry port_entries[];
extern int input_port_table_find_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern int input_entry_index_to_port_code(unsigned char);
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void ddc_set_port_slave_address(unsigned char, unsigned char);
extern void ipc_8051_enable_ddc_slave(unsigned char, unsigned char);

/*
 * Store a DDC/CI slave address for the port of a source code and have the 8051 switch that slave on with it
 * (command 7).
 *
 * The code is resolved to a port code as in input_get_port_bus_id; codes 0x61 / 0x71 / 0x81 select port entry
 * 1 / 2 / 3, any other code entry 0. Byte +0x10 of that entry indexes the port table, which gives the bus id.
 * ddc_set_port_slave_address stores the address for that bus id, and ipc_8051_enable_ddc_slave(1 << bus_id,
 * slave_address) sends it to the 8051 (command 7).
 *
 * No direct call to it was found in the image.
 */
void ddc_api_set_port_slave_address(unsigned char port_code, unsigned char slave_address)
{
  unsigned short port_index;
  unsigned char bus_id;

  port_index = 0;
  /* Port codes 0x51/0x61/0x71/0x81 select port indices 0-3; all others use index 0. */
  switch ((unsigned char)input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(port_code)))) {
  case 0x51: port_index = 0; break;
  case 0x61: port_index = 1; break;
  case 0x71: port_index = 2; break;
  case 0x81: port_index = 3; break;
  }
  bus_id = input_port_table_get_bus_id(port_entries[port_index].byte_0x10);
  ddc_set_port_slave_address(bus_id, slave_address);
  ipc_8051_enable_ddc_slave(1 << bus_id, slave_address);
}
