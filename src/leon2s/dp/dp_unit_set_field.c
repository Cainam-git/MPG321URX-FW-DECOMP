/* dp_unit_set_field  (FUN_a00af94c)
 *
 * Write 0 and 0x6A to unit registers 0 and 1 of the receiver unit a port is mapped to.
 * Name basis: descriptive - unit register write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00af94c @ 0xa00af94c (-mcpu=v8 -Os -g)
 * Source form: the port variable is reused for the unit number that dp_map_port_lane_unit returns.
 */
extern int dp_unit_reg_write8();
extern int dp_map_port_lane_unit();
extern int dp_get_reg9f_field();

/*
 * Write 0 to unit register 0 and 0x6A to unit register 1 of the receiver unit that the port is mapped to
 * (dp_map_port_lane_unit with the 2-bit field of register 0x9F of the port).
 *   port: DP receiver (0 or 1)
 * Called by dp_apply_port_settings after dp_unit_write_two_24bit_values.
 */
void dp_unit_set_field(unsigned char port)

{
  unsigned int field;

  port = port & 0xff;
  field = dp_get_reg9f_field(port);
  port = dp_map_port_lane_unit(port, field & 0xff);       /* from here: the unit number */
  dp_unit_reg_write8(port & 0xff, 0, 0);
  dp_unit_reg_write8(port & 0xff, 1, 0x6a);
  return;
}
