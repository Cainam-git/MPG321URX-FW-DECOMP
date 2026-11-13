/* dp_unit_set_reg0b_field  (FUN_a00b00e0)
 *
 * Write the 2-bit field of register 0x0B of a port's receiver unit.
 * Name basis: descriptive - on / off value
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b00e0 @ 0xa00b00e0 (-mcpu=v8 -Os -g)
 * Source form: the unit holds the dp_map_port_lane_unit result and is masked at each use; the two arms of the
 * test are separate calls.
 */
extern int dp_get_reg9f_field(unsigned int port);
extern unsigned int dp_map_port_lane_unit(unsigned int port, unsigned int field);
extern void dp_unit_reg_update_bits(unsigned int unit, unsigned int reg, unsigned int mask, unsigned int mode);

/*
 * On the receiver unit that the port is mapped to (dp_map_port_lane_unit with the 2-bit field of register 0x9F
 * of the port): set bits 0 and 1 of unit register 0x0B when value is non-zero, clear them when it is 0.
 *   port: DP receiver (0 or 1)
 *   value: non-zero or 0
 * Called from dp_run_link_state.
 */
void dp_unit_set_reg0b_field(unsigned int port, unsigned char value)
{
    unsigned int unit;

    port = port & 0xff;
    unit = dp_get_reg9f_field(port);
    unit = dp_map_port_lane_unit(port, unit & 0xff);
    if (value != 0) {
        dp_unit_reg_update_bits(unit & 0xff, 0xb, 3, 1);
    } else {
        dp_unit_reg_update_bits(unit & 0xff, 0xb, 3, 0);
    }
    return;
}
