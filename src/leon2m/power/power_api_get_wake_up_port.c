/* power_api_get_wake_up_port  (FUN_a0148974)
 *
 * Return the input port that woke the monitor, or 0xFF.
 * Returns: port code or 0xFF
 * Name basis: derived - maps the start status 8..11 to the port code of an input record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148974, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: plain switch with the result preset to 0xff; both the case 10 and the
 * case 11 arm test 'if (nvram_get_device_option_bit25())' with the true arm first (an '== 0' form in case 11
 * swaps two registers); prototypes with unsigned char returns and void parameters. The four bus-id bytes are
 * separate symbols (one sethi per load).
 */
extern unsigned char port_entry0_bus_id;
extern unsigned char port_entry1_bus_id;
extern unsigned char port_entry2_bus_id;
extern unsigned char port_entry3_bus_id;
extern unsigned char input_port_table_get_code(unsigned char);
extern unsigned char nvram_get_device_option_bit25(void);
extern unsigned char sys_get_status_byte(void);

/*
 * Return the port code of the input that woke the monitor, or 0xFF.
 *
 * The status byte decides which port entry is meant: 8 is entry 0 and 9 is entry 1. For 10 and 11 the
 * entries 2 and 3 are taken in swapped order when device option bit 25 is set. Any other status gives 0xFF.
 * The port code is the one of the port table row that the entry's bus id selects.
 * Called by App_Initialize.
 */
unsigned char power_api_get_wake_up_port(void)
{
  unsigned char wake_port = 0xff;

  switch (sys_get_status_byte()) {
  case 8:
    wake_port = input_port_table_get_code(port_entry0_bus_id);
    break;
  case 9:
    wake_port = input_port_table_get_code(port_entry1_bus_id);
    break;
  case 10:
    if (nvram_get_device_option_bit25())
      wake_port = input_port_table_get_code(port_entry3_bus_id);
    else
      wake_port = input_port_table_get_code(port_entry2_bus_id);
    break;
  case 11:
    if (nvram_get_device_option_bit25())
      wake_port = input_port_table_get_code(port_entry2_bus_id);
    else
      wake_port = input_port_table_get_code(port_entry3_bus_id);
    break;
  }
  return wake_port;
}
