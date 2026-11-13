/* input_api_set_port_field_third  (FUN_a014a588)
 *
 * Store a per-port link setting (third field) and save the settings record.
 * Note: Writes the EEPROM.
 * Name basis: descriptive - port row byte 0 and a 2-bit field of the device record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a588 @ 0xa014a588-0xa014a654 (204 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the setting mapping is a static helper with a switch (inlined; cases written 3, 2, 1, the 0 return
 * after the switch); the row selection is a switch on port_code_result as in input_api_set_port_flag_row7.
 */

#define PORT_CODE_ENTRY2     0x71               /* port code of port entry 2 (DisplayPort class) */
#define PORT_CODE_ENTRY3     0x81               /* port code of port entry 3 (DisplayPort class) */
#define PORT_MASK_ENTRY2     0x10               /* bit of input_power_on_ports_by_mask for port entry 2 */
#define PORT_MASK_ENTRY3     0x20               /* bit of input_power_on_ports_by_mask for port entry 3 */
#define NO_ROW               0xff

extern unsigned char device_settings[];
extern int input_port_table_find_code(unsigned char);
extern void input_set_port_link_field_third(unsigned char, unsigned char);
extern int input_entry_index_to_port_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern void input_power_on_ports_by_mask(unsigned int, unsigned int);
extern void nvram_write_settings_record(void *, unsigned int);

/* The value to store for a setting: 1, 2 and 3 as they are, everything else 0. */
static int link_value_of(unsigned char setting)
{
    switch (setting) {
    case 3: return 3;
    case 2: return 2;
    case 1: return 1;
    }
    return 0;
}

/*
 * Store the third link setting of a DisplayPort-class input and save the device settings record.
 *
 * port_code: the input port code to set. It is turned into the port code of its port entry; only 0x71
 *            (link row 0) and 0x81 (link row 1) are handled. Any other input does nothing.
 * setting:   the value to store; 1, 2 or 3 is stored as it is; any other value is stored as 0.
 *
 * For a handled input the port is first switched on with input_power_on_ports_by_mask (mask bit for its
 * entry, on = 1), then the value is handed to input_set_port_link_field_third for the link row, then
 * the device settings record is written to the EEPROM.
 */
void input_api_set_port_field_third(unsigned char port_code, unsigned char setting)
{
    unsigned char port_code_result;
    unsigned char row_index;
    unsigned char link_value;

    port_code_result = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(port_code)));
    switch (port_code_result) {
    case PORT_CODE_ENTRY2:
        row_index = 0;
        input_power_on_ports_by_mask(PORT_MASK_ENTRY2, 1);
        break;
    case PORT_CODE_ENTRY3:
        row_index = 1;
        input_power_on_ports_by_mask(PORT_MASK_ENTRY3, 1);
        break;
    default:
        row_index = NO_ROW;
        break;
    }
    link_value = link_value_of(setting);
    if (row_index != NO_ROW) {
        input_set_port_link_field_third(row_index, link_value & 3);
        nvram_write_settings_record(device_settings, 0);
    }
}
