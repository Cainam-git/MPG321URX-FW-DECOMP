/* dp_unit_write_two_24bit_values  (FUN_a00af8bc)
 *
 * Write two 24-bit values to registers 4..6 and 8..10 of the receiver unit a port is mapped to.
 * Name basis: descriptive - unit registers 4, 5 and 6
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00af8bc @ 0xa00af8bc (-mcpu=v8 -Os -g)
 * Source form: the unused parameters 4 to 6 are handed on to the last unit write, which is declared without a
 * parameter list. The port variable is reused for the unit number.
 */
extern void dp_unit_reg_write8();
extern int dp_map_port_lane_unit();
extern int dp_get_reg9f_field();

/*
 * Write two 24-bit values to the receiver unit that the port is mapped to (dp_map_port_lane_unit with the 2-bit
 * field of register 0x9F of the port), one byte per unit register, low byte first: value_a to unit registers
 * 4, 5, 6 and value_b to unit registers 8, 9, 10.
 *   port: DP receiver (0 or 1)
 *   value_a, value_b: the two values (bits 0 to 23 are used)
 * Called by dp_apply_port_settings, which passes 0x90DFE and 0xC5427. The last three parameters carry no value of
 * their own; they are only handed on to the last write.
 */
void dp_unit_write_two_24bit_values(unsigned char port, unsigned int value_a, unsigned int value_b, unsigned int arg4,
                               unsigned int arg5, unsigned int arg6)
{
    unsigned int field;

    port = port & 0xff;
    field = dp_get_reg9f_field(port);
    port = dp_map_port_lane_unit(port, field & 0xff) & 0xff;       /* from here: the unit number */
    dp_unit_reg_write8(port, 4, value_a & 0xff);
    dp_unit_reg_write8(port, 5, value_a >> 8 & 0xff);
    dp_unit_reg_write8(port, 6, value_a >> 0x10 & 0xff);
    dp_unit_reg_write8(port, 8, value_b & 0xff);
    dp_unit_reg_write8(port, 9, value_b >> 8 & 0xff);
    dp_unit_reg_write8(port, 10, value_b >> 0x10 & 0xff, arg4, arg5, arg6);
    return;
}
