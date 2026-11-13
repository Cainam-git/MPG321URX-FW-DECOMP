/* dp_unit_set_bits_10_80  (FUN_a00b0004)
 *
 * Write two control bits of a port's receiver unit with opposite values.
 * Name basis: descriptive - unit bits 0x10 and 0x80
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0004 @ 0xa00b0004-0xa00b0078 (29 words), flags -mcpu=v8 -Os -g.
 * Source form: the unit is an unsigned char; the two writes of each arm are separate calls (the second is a tail
 * call and the 0x80 write takes the inverse constant per arm, so the two tails share one call).
 */
extern void dp_unit_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned char);
extern unsigned char dp_map_port_lane_unit(unsigned char, unsigned char);
extern unsigned char dp_get_reg9f_field(unsigned char);

/*
 * On the receiver unit that the port is mapped to (dp_map_port_lane_unit with the 2-bit field of register 0x9F
 * of the port): with on set, set bit 4 (0x10) and clear bit 7 (0x80) of unit register 0; with on clear, clear
 * bit 4 and set bit 7.
 *   port: DP receiver (0 or 1)
 *   on: non-zero or 0
 * Called from dp_run_link_state.
 */
void dp_unit_set_bits_10_80(unsigned char port, unsigned char on)
{
  unsigned char unit = dp_map_port_lane_unit(port, dp_get_reg9f_field(port));

  if (on) {
    dp_unit_reg_update_bits(unit, 0, 0x10, 1);
    dp_unit_reg_update_bits(unit, 0, 0x80, 0);
  } else {
    dp_unit_reg_update_bits(unit, 0, 0x10, 0);
    dp_unit_reg_update_bits(unit, 0, 0x80, 1);
  }
}
