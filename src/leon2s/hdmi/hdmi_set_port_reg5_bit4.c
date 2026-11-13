/* hdmi_set_port_reg5_bit4  (FUN_a006d548)
 *
 * Set bit 4 of register 5 in a TMDS receiver block.
 *   p2: port
 * Name basis: descriptive - hdmi_reg_update_bits(port, 5, 0x10, 1); caller the TMDS link state machine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d548 @ 0xa006d548, flags -mcpu=v8 -Os -g.
 * Source form: hdmi_reg_update_bits is declared without a parameter list; the first parameter is not
 * used and the second is the port.
 */
extern int hdmi_reg_update_bits();

/* Calls hdmi_reg_update_bits(port, 5, 0x10, 1): sets bit 4 of register 5 of the port.
 *   unused: not used
 *   port:    port (low 8 bits used) */
void hdmi_set_port_reg5_bit4(unsigned int unused,unsigned char port)

{
  hdmi_reg_update_bits(port,5,0x10,1);
  return;
}