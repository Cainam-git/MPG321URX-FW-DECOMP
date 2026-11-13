/* input_port_get_reg2e_bit5  (FUN_a00c4e4c)
 *
 * Return bit 5 of register 0x2E of an input.
 * Returns: 0 or 1
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c4e4c @ 0xa00c4e4c, flags -mcpu=v8 -Os -g. Same code as dp_tx_get_reg70_bit4 with other constants.
 */

extern unsigned int hdmi_port_reg_read8(unsigned int port, unsigned short reg);

/* Return 1 when bit 5 (0x20) of register 0x2E of input 'port' is set, otherwise 0. */
unsigned int input_port_get_reg2e_bit5(unsigned int port)
{
    unsigned int bit5 = hdmi_port_reg_read8(port & 0xff, 0x2e) & 0x20;
    return bit5 != 0;
}
