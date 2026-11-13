/* input_api_set_port_option_bit20  (FUN_a014df68)
 *
 * Store option bit 20 and send it for the port of a source (codes 0x71/0x81).
 * Name basis: descriptive - bit 20 of stSysConfig; input_power_on_ports_by_mask, then a mailbox command
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014df68 @ 0xa014df68, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: bit 20 of sys_config is a one-bit bit-field; the port code is a switch
 * on an unsigned char; the stored bit is read back for the final call.
 */

/* The first word of the system configuration record; bit 20 is the one stored here. */
struct sys_config_bits { unsigned int bits_31_21 : 11, option_bit_20 : 1, bits_19_0 : 20; };
extern struct sys_config_bits sys_config;
extern int input_port_table_find_code(unsigned char);
extern void ipc_api_set_dp_rx_reg252_bits(unsigned char receiver, unsigned char bit);
extern int input_entry_index_to_port_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern void input_power_on_ports_by_mask(unsigned int mask, unsigned int on);

#define NO_RECEIVER 0xff

/*
 * Store bit 20 of the system configuration record and, for the source whose port code is 0x71 or 0x81, send it
 * to the input processor.
 *
 *   source  the source, as input_port_table_find_code takes it
 *   on      the value of bit 20
 *
 * Bit 20 is stored in every case. The source is turned into a port code (index, port entry, code). For 0x71 the
 * ports of mask 0x10 are switched on and receiver 0 is used; for 0x81 the ports of mask 0x20 are switched on and
 * receiver 1 is used. Then ipc_api_set_dp_rx_reg252_bits is called with the receiver and bit 20. For any other
 * code that call is not made. Called from osd_factory_decrease_value and
 * osd_factory_increase_value.
 */
void input_api_set_port_option_bit20(unsigned char source, unsigned int on)
{
    unsigned char port_code;
    unsigned char receiver;

    port_code = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source)));
    sys_config.option_bit_20 = on;
    switch (port_code) {
    case 0x71:
        receiver = 0;
        input_power_on_ports_by_mask(0x10, 1);
        break;
    case 0x81:
        receiver = 1;
        input_power_on_ports_by_mask(0x20, 1);
        break;
    default:
        receiver = NO_RECEIVER;
        break;
    }
    if (receiver != NO_RECEIVER)
        ipc_api_set_dp_rx_reg252_bits(receiver, sys_config.option_bit_20);

}
