/* input_port_set_event_bit  (FUN_a00c5d34)
 *
 * Write an input's event bit in its register.
 * Name basis: descriptive - bit 6 of register 0x2E for inputs 0..3, another register for 4 and 5
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c5d34 @ 0xa00c5d34, flags -mcpu=v8 -Os -g.
 * Source form: Ghidra's six-argument parameter list is kept (arguments 5 and 6 are passed on in registers);
 * the callees are declared without a prototype.
 */

extern int dp_reg_update_bits();
extern int hdmi_port_reg_update_bits();

/*
 * Write the event bit of an input: bit 6 (0x40) of register 0x2E for the inputs 0..3. For the inputs 4 and 5
 * (index port - 4) it sets bit 7 of register 0x30, writes bit 1 of register 0x2A8 from 'value', then clears
 * bit 7 of register 0x30 again. Called from input_port_raise_event.
 *
 * Arguments 3 and 4 are not used; 5 and 6 are passed on to the register routines as they came in.
 */
void input_port_set_event_bit(unsigned char port, unsigned char value, unsigned int unused3, unsigned int unused4,
                 unsigned int arg5, unsigned int arg6)
{
  unsigned char dp_index;

  dp_index = port - 4;
  if (port < 4) {
    hdmi_port_reg_update_bits(port, 0x2e, 0x40, value, arg5, arg6);
    return;
  }
  dp_reg_update_bits(dp_index, 0x30, 0x80, 1);
  dp_reg_update_bits(dp_index, 0x2a8, 2, value);
  dp_reg_update_bits(dp_index, 0x30, 0x80, 0, arg5, arg6);
}
