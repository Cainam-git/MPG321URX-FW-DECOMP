/* dp_set_port_control_bit  (FUN_a00af858)
 *
 * Set or clear the port's bit in control register 0xCF012448.
 * Name basis: descriptive - bit number from the lane mapping
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00af858 @ 0xa00af858 (-mcpu=v8 -Os -g)
 * Source form: the set arm shifts the masked 'on' value (which is 1 there) instead of a constant 1; the clear arm
 * shifts a constant 1. The bit number is the masked result of dp_map_port_lane_unit.
 */
extern int dp_get_reg9f_field(int);
extern int dp_map_port_lane_unit(int, int);
#define reg_input_port_control (*(volatile unsigned int *)0xcf012448)

/*
 * Set (on is 1) or clear (any other value) one bit of the control register 0xCF012448. The bit number is the
 * receiver unit that the port is mapped to (dp_map_port_lane_unit with the 2-bit field of register 0x9F of the
 * port, as in dp_unit_set_field).
 *   port: DP receiver (0 or 1)
 *   on: 1 = set the bit, anything else = clear it
 * Called from dp_run_link_state.
 */
void dp_set_port_control_bit(unsigned char port, unsigned char on) {
    unsigned int bit_number;
    port &= 0xff;
    bit_number = dp_map_port_lane_unit(port, dp_get_reg9f_field(port) & 0xff) & 0xff;
    on &= 0xff;
    if (on == 1) {
        reg_input_port_control |= (on << bit_number);
    } else {
        reg_input_port_control &= ~(1 << bit_number);
    }
}
