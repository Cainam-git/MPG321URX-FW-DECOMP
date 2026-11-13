/* dp_tx_phy_write_output_field  (FUN_a00aa88c)
 *
 * Write the PHY nibble field that belongs to one DP / eDP output.
 *   output: output 0..4
 *   set: 1 = set
 * Name basis: descriptive - output 0 -> unit 0 reg 0x49, 1/2 -> unit 1 reg 0x67, 3/4 -> unit 1 reg 0x8A
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. A leaf wrapper; the final call is a tail call.
 * Source form: 'set &= 0xff;' sits between the range test and the switch (at the top of the function or in
 * the call it gives other code). The switch is a jump table (switchdataD_a00aa878); case 0 is the last arm
 * (its block is last in the firmware, table entry 0) and passes the output number itself as the unit.
 */

extern int dp_tx_phy_reg_update_bits();

/*
 * Set or clear one nibble of a PHY register that belongs to a DP output, through dp_tx_phy_reg_update_bits.
 *
 *   output: 0..4; larger values do nothing
 *   set:    1 = set the nibble's bits, any other value = clear them
 *
 * Output  PHY unit  register  mask
 *   0        0        0x49     0xF0
 *   1        1        0x67     0x0F
 *   2        1        0x67     0xF0
 *   3        1        0x8A     0x0F
 *   4        1        0x8A     0xF0
 *
 * Called by dp_tx_init_ports (cleared for every output at start-up), dp_tx_edp_run_hpd_actions and
 * dp_tx_set_link_pattern.
 */
void dp_tx_phy_write_output_field(unsigned int output, unsigned int set) {
  unsigned int reg, mask;
  
  output &= 0xff;
  if (output > 4) return;
  set &= 0xff;
  
  switch (output) {
    case 1:
      output = 1;
      reg = 0x67;
      mask = 0xf;
      break;
    case 2:
      output = 1;
      reg = 0x67;
      mask = 0xf0;
      break;
    case 3:
      output = 1;
      reg = 0x8a;
      mask = 0xf;
      break;
    case 4:
      output = 1;
      reg = 0x8a;
      mask = 0xf0;
      break;
    case 0:
      reg = 0x49;
      mask = 0xf0;
      break;
  }
  dp_tx_phy_reg_update_bits(output, reg, mask, set);
}
