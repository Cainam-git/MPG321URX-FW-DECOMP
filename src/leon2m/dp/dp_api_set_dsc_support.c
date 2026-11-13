/* dp_api_set_dsc_support  (FUN_a014a768)
 *
 * Store whether DSC is enabled for the DisplayPort input of a source and save the setting.
 * Note: Writes the EEPROM.
 * Name basis: derived - calls dp_set_port_dsc_support (bit in device settings byte +0x33, link row byte 6);
 *   saved with nvram_write_settings_record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a768 @ 0xa014a768, flags -mcpu=v8 -O3 -g. Same code as input_api_set_port_flag_row7.
 * Source form: the port selection is a switch.
 */
extern unsigned char device_settings[];
extern int input_port_table_find_code(unsigned char);
extern void dp_set_port_dsc_support(unsigned char, unsigned char);
extern int input_entry_index_to_port_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern void input_power_on_ports_by_mask(unsigned int, unsigned int);
extern void nvram_write_settings_record(void *, unsigned int);

#define PORT_CODE_DP0 0x71      /* port code mapped to DisplayPort number 0 */
#define PORT_CODE_DP1 0x81      /* port code mapped to DisplayPort number 1 */
#define NO_DP_PORT    0xff

/*
 * Store the DSC flag of the DisplayPort input behind a source and save the settings record.
 *
 *   source  source (input) number
 *   value   new flag value
 *
 * The source is turned into a port code. Port code 0x71 is DisplayPort number 0 and 0x81 is number 1; for any
 * other code nothing happens. For a DisplayPort, input_power_on_ports_by_mask is called first (mask 0x10 for
 * number 0, 0x20 for number 1, with 1), then the flag is stored with dp_set_port_dsc_support and the settings
 * record is written to the EEPROM. Called by sys_user_apply_adaptive_sync_setting.
 */
void dp_api_set_dsc_support(unsigned char source, unsigned char value)
{
    unsigned char port_code;
    unsigned char dp_port;

    port_code = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source)));
    switch (port_code) {
    case PORT_CODE_DP0:
        dp_port = 0;
        input_power_on_ports_by_mask(0x10, 1);
        break;
    case PORT_CODE_DP1:
        dp_port = 1;
        input_power_on_ports_by_mask(0x20, 1);
        break;
    default:
        dp_port = NO_DP_PORT;
        break;
    }
    if (dp_port != NO_DP_PORT) {
        dp_set_port_dsc_support(dp_port, value);
        nvram_write_settings_record(device_settings, 0);
    }
}
