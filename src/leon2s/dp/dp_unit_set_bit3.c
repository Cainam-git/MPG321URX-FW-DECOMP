/* dp_unit_set_bit3  (FUN_a00b0078)
 *
 * Set or clear bit 3 of register 0 of a port's receiver unit, clearing bit 7 when setting.
 * Name basis: descriptive - unit register 0 of the mapped unit; called from dp_run_link_state
 *
 * Matching notes
 * --------------
 * FUN_a00b0078 (leon2s 0xa00b0078-0xa00b00e0, 104 bytes), flags -mcpu=v8 -Os -g.
 * Same register access routines as dp_unit_restart. Source form: the port is masked into the parameter variable
 * itself; the unit is an unsigned char.
 */
extern unsigned int dp_get_reg9f_field(unsigned char);
extern unsigned int dp_map_port_lane_unit(unsigned char, unsigned char);
extern void dp_unit_reg_update_bits(unsigned char, unsigned int, unsigned int, unsigned char);

/*
 * On the receiver unit that the port is mapped to (dp_map_port_lane_unit with the 2-bit field of register 0x9F
 * of the port): with enable set, clear bit 7 and set bit 3 of unit register 0; with enable clear, clear bit 3.
 *   port: DP receiver (0 or 1)
 *   enable: non-zero or 0
 * Called from dp_run_link_state.
 */
void dp_unit_set_bit3(unsigned int port, unsigned char enable)
{
    unsigned char unit;

    port &= 0xff;
    unit = dp_map_port_lane_unit(port, dp_get_reg9f_field(port));
    if (enable != 0) {
        dp_unit_reg_update_bits(unit, 0, 0x80, 0);
        dp_unit_reg_update_bits(unit, 0, 8, 1);
    } else {
        dp_unit_reg_update_bits(unit, 0, 8, 0);
    }
}
