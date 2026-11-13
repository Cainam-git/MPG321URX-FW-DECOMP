/* input_api_set_port_flag_row7  (FUN_a014a654)
 *
 * Store a per-port on/off setting (row byte 7) and save the settings record.
 * Note: Writes the EEPROM.
 * Name basis: descriptive - ports with codes 0x71/0x81; called from the EDID and PIP menu code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a654 @ 0xa014a654-0xa014a6e0 (35 words), flags -mcpu=v8 -O3 -g.
 * Source form: the arm selection is a switch on v (an if/else-if chain makes gcc crossjump
 * 'mov 1,%o1; call' together; the switch keeps only the call shared, so the 0x81 arm sets o0 and o1
 * itself as in the fw).
 */
extern unsigned char device_settings[];
extern int input_port_table_find_code(unsigned char);
extern void input_set_port_link_flag_row7(unsigned char, unsigned char);
extern int input_entry_index_to_port_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern void input_power_on_ports_by_mask(unsigned int, unsigned int);
extern void nvram_write_settings_record(void *, unsigned int);

#define NO_ROW 0xff
#define PORT_CODE_ENTRY2 0x71
#define PORT_CODE_ENTRY3 0x81
#define PORT_MASK_ENTRY2 0x10           /* input_power_on_ports_by_mask: the port of code 0x71 */
#define PORT_MASK_ENTRY3 0x20           /* the port of code 0x81 */

/*
 * Store a per-port on/off setting (row byte 7) and save the settings record.
 *
 *   port_code       the input port code; it is looked up in the port table, the entry found by its bus id
 *                   and that entry's code taken
 *   on_off_setting  the value handed to input_set_port_link_flag_row7
 *
 * Only the codes 0x71 (row 0) and 0x81 (row 1) do anything: the port is switched on with
 * input_power_on_ports_by_mask (mask 0x10 or 0x20, second argument 1), the value is stored for the row, and the
 * 0x50-byte record device_settings is written to the EEPROM. Any other code does nothing.
 *
 * Callers: sys_user_apply_input_link_settings, UserSetPIPMode.
 */
void input_api_set_port_flag_row7(unsigned char port_code, unsigned char on_off_setting)
{
    unsigned char entry_code;
    unsigned char row_index;

    entry_code = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(port_code)));
    switch (entry_code) {
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
    if (row_index != NO_ROW) {
        input_set_port_link_flag_row7(row_index, on_off_setting);
        nvram_write_settings_record(device_settings, 0);
    }
}
