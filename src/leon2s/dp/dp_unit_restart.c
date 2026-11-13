/* dp_unit_restart  (FUN_a00afdf4)
 *
 * Restart the receiver unit of a port, in one of two ways by mode.
 * Name basis: descriptive - dp_unit_set_reg1_bit5_and_reg3 for mode 1, else a pulse sequence
 *
 * Matching notes
 * --------------
 * FUN_a00afdf4 (leon2s 0xa00afdf4-0xa00afeb8, 196 bytes), flags -mcpu=v8 -Os -g.
 * Source form: dp_unit_set_reg1_bit5_and_reg3 takes one parameter here; the arguments 3, 4, 0 of the last tail call are set
 * once before the mode test. The unit number is computed before the mode test.
 */
extern unsigned char dp_port_flag_bits;         /* one bit per port */
extern unsigned int dp_get_reg9f_field(unsigned char);
extern unsigned char dp_map_port_lane_unit(unsigned char, unsigned char);
extern void dp_unit_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_unit_set_reg1_bit5_and_reg3(unsigned char);
extern void timer_delay_long_units(int);

/*
 * Mode 1: run dp_unit_set_reg1_bit5_and_reg3 for the port. Any other mode: on the receiver unit that the port is mapped to
 * (dp_map_port_lane_unit with the 2-bit field of register 0x9F of the port), first clear bit 5 of unit register 1
 * and bit 1 of unit register 3, but only when the port's bit in dp_port_flag_bits is clear; then set bits 0 and 1
 * of unit register 3, set bit 2 of it, wait one delay unit and clear bit 2 again.
 *   port: DP receiver (0 or 1)
 *   mode: 1 = reset only, any other value = the pulse sequence
 * Called from dp_run_link_state (mode 1), by mailbox command 0xFF (mode 0) and by dp_start_stream (mode 0), among
 * others.
 */
void dp_unit_restart(unsigned char port, unsigned char mode)
{
    unsigned char unit;

    unit = dp_map_port_lane_unit(port, dp_get_reg9f_field(port));
    if (mode == 1) {
        dp_unit_set_reg1_bit5_and_reg3(port);
        return;
    }
    if (((dp_port_flag_bits >> port) & 1) == 0) {
        dp_unit_reg_update_bits(unit, 1, 0x20, 0);
        dp_unit_reg_update_bits(unit, 3, 2, 0);
    }
    dp_unit_reg_update_bits(unit, 3, 3, 1);
    dp_unit_reg_update_bits(unit, 3, 4, 1);
    timer_delay_long_units(1);
    dp_unit_reg_update_bits(unit, 3, 4, 0);
}
