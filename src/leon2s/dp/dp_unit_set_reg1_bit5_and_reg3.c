/* dp_unit_set_reg1_bit5_and_reg3  (FUN_a00afdb0)
 *
 * Set bit 5 of register 1 and write 2 to register 3 of the receiver unit a port is mapped to.
 * Name basis: descriptive - mapped unit, then dp_unit_reg_update_bits(unit, 1, 0x20, 1) and
 *   dp_unit_reg_write8(unit, 3, 2)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00afdb0 @ 0xa00afdb0 (-mcpu=v8 -Os -g)
 * Source form: the unit number is the masked result of dp_map_port_lane_unit and replaces the port variable for
 * the two unit accesses. The unused parameters 2 to 6 are declared; parameters 4 to 6 are handed on to the final
 * call, which is a tail call and is declared without a parameter list.
 */
extern int dp_get_reg9f_field();
extern int dp_map_port_lane_unit();
extern int dp_unit_reg_update_bits();
extern int dp_unit_reg_write8();

/*
 * Set bit 5 (mask 0x20) of unit register 1 and write 2 to unit register 3 of the receiver unit that the port is
 * mapped to (dp_map_port_lane_unit with the 2-bit field of register 0x9F of the port).
 *   port: DP receiver (0 or 1)
 * Called by dp_unit_restart in mode 1, and by the power-off routines input_power_off_receivers_mode0 and
 * input_power_off_receivers_mode1 (both with the value 2). The other parameters carry no value of their own; they are only handed on to
 * dp_unit_reg_write8.
 */
void dp_unit_set_reg1_bit5_and_reg3(unsigned char port, unsigned int arg2, unsigned int arg3,
                  unsigned int arg4, unsigned int arg5, unsigned int arg6)
{
    unsigned int unit;

    port = port & 0xff;
    unit = dp_get_reg9f_field(port);
    unit = dp_map_port_lane_unit(port, unit & 0xff) & 0xff;       /* from here: the unit number */
    dp_unit_reg_update_bits(unit, 1, 0x20, 1);
    dp_unit_reg_write8(unit, 3, 2, arg4, arg5, arg6);
}
