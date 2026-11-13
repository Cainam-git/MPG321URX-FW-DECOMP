/* startup_init_input_ports  (FUN_a012b7b8)
 *
 * Send the link settings of the input ports and set up their pins.
 * Name basis: derived - start-up step 7: input_init_port_link_row, pin set-up, mailbox command 0x2F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b7b8 @ 0xa012b7b8..0xa012b86c (45 words), flags -mcpu=v8 -O3 -g (section default).
 * Exact form: bit 25 as a bitfield, re-read before each use; each call is written in both arms of an if/else
 * (cross-jumping merges them into one call with the argument in the branch delay slot, as in the firmware; a ?:
 * argument becomes branch-free code).
 */

#define PIN_GROUP_0 0                           /* first argument of gpio_setup_pin */
#define PIN_GROUP_1 1
#define PIN_OUTPUT 1                            /* output_enable argument of gpio_setup_pin */
#define PIN_LEVEL_LOW 0                         /* level argument of gpio_setup_pin */
#define MST_LOGICAL_NUMBER 1                    /* value sent by ipc_set_dp_mst_logical_number */

/* One port entry (0x12 bytes, docs/DATA.md); only the halfword at +0 and the bus id are used here. */
struct port_entry {
    unsigned short word_0;
    unsigned char other[14];
    unsigned char bus_id;                       /* +0x10 */
    unsigned char byte_0x11;
};
/* The first word of the device settings record with the option bit 25 as a bitfield. */
struct device_settings_first_word {
    unsigned int bits_31_26 : 6;
    unsigned int option_bit_25 : 1;             /* also returned by nvram_get_device_option_bit25 */
    unsigned int bits_24_0 : 25;
};
extern struct device_settings_first_word device_settings;
extern struct port_entry port_entries[];
extern void input_init_port_link_row(unsigned char);
extern void input_set_pin_config_byte0(unsigned char);
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void gpio_setup_pin(unsigned char group, unsigned char pin, unsigned char output_enable, unsigned char level);
extern void ipc_set_dp_mst_logical_number(unsigned char);

/*
 * Start-up step 7 (called by the system start-up, startup_bring_up_system, after the display start-up). Option bit 25 of
 * the device settings picks the order:
 *   1. input_init_port_link_row for row 1 then row 0 when the bit is set, row 0 then row 1 when it is clear;
 *   2. input_set_pin_config_byte0 with the value of the bit;
 *   3. gpio_setup_pin as an output, level 0, for pin group 0 with the bus id of port entry 2 and for pin group 1
 *      with the bus id of port entry 3 (the ids come from input_port_table_get_bus_id);
 *   4. the multi-stream logical number 1 goes to the input processor (mailbox command 0x2F).
 * The record is read again before each use because every call may change it.
 */
void startup_init_input_ports(void)
{
    if (device_settings.option_bit_25)
        input_init_port_link_row(1);
    else
        input_init_port_link_row(0);
    if (device_settings.option_bit_25)
        input_init_port_link_row(0);
    else
        input_init_port_link_row(1);
    if (device_settings.option_bit_25)
        input_set_pin_config_byte0(1);
    else
        input_set_pin_config_byte0(0);
    gpio_setup_pin(PIN_GROUP_0, input_port_table_get_bus_id(port_entries[2].bus_id), PIN_OUTPUT, PIN_LEVEL_LOW);
    gpio_setup_pin(PIN_GROUP_1, input_port_table_get_bus_id(port_entries[3].bus_id), PIN_OUTPUT, PIN_LEVEL_LOW);
    ipc_set_dp_mst_logical_number(MST_LOGICAL_NUMBER);
}
