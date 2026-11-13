/* input_api_set_port0_option_bit24  (FUN_a014a0d8)
 *
 * Store configuration bit 24, switch on input port entry 2 and send the bit as link byte 3 of port 0.
 * Name basis: descriptive - stSysConfig bit 24; input_power_on_ports_by_mask(0x10, 1) = port entry 2 without
 *   the cable test; input_set_port_link_byte3(0, bit)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a0d8 @ 0xa014a0d8-0xa014a11c (17 words), flags -mcpu=v8 -O3 -g.
 * Source form: bit 24 of sys_config word 0 is a one-bit bit-field; it is written, and the value passed to
 * input_set_port_link_byte3 is read back from the record (a byte load of +0 and & 1), not taken from the parameter.
 */

/* Word 0 of the system configuration record; only bit 24 is used here. */
struct sys_config_record { unsigned int bits_31_25 : 7, bit24 : 1, bits_23_0 : 24; };
extern struct sys_config_record sys_config;
extern void input_power_on_ports_by_mask(unsigned int, unsigned int);
extern void input_set_port_link_byte3(unsigned char port, unsigned char value);

#define PORT_MASK_ENTRY2 0x10           /* input_power_on_ports_by_mask: port entry 2 */
#define POWER_ON_ALWAYS  1              /* input_power_on_ports_by_mask: switch on without the cable test */
#define LINK_PORT_0      0

/*
 * Keep `on` (bit 0) as bit 24 of the system configuration, switch on input port entry 2, then store the bit in
 * byte 3 of the link row of port 0 and send it to the input processor (input_set_port_link_byte3, which sends
 * mailbox command 0x24: DisplayPort multi-stream on or off for one port).
 *
 * The same steps as command SYS_CFG_BIT24 of sys_api_config. The only caller is input_user_apply_port0_option,
 * which passes bit 29 of the settings option word; nothing calls that routine.
 */
void input_api_set_port0_option_bit24(unsigned int on)
{
    sys_config.bit24 = on;
    input_power_on_ports_by_mask(PORT_MASK_ENTRY2, POWER_ON_ALWAYS);
    input_set_port_link_byte3(LINK_PORT_0, sys_config.bit24);
}
