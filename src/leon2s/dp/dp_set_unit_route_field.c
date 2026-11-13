/* dp_set_unit_route_field  (FUN_a00add8c)
 *
 * Write the 2-bit route field of the unit a port is mapped to and note it in a mask.
 * Name basis: descriptive - registers 0xCF014758 / 0xCF01475C; mask at 0xA807DE70
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00add8c @ 0xa00add8c-0xa00adf64, flags -mcpu=v8 -Os -g.
 * dp_get_reg9f_field is a ROM routine outside the image and is called twice. Source form: the four mode arms
 * are written out for each of the two registers; mode 1 ORs 'mode << bit' (the value 1) into the mask.
 */
extern unsigned int dp_get_reg9f_field(unsigned char);
extern unsigned char dp_map_port_lane_unit(unsigned char, unsigned char);
extern unsigned char dp_unit_route_bits;

/* Route fields of the receiver units: two bits per unit, units 0..3 in the first register, 4.. in the second. */
#define UNIT_ROUTE_REG_LOW  (*(volatile unsigned int *)0xcf014758)
#define UNIT_ROUTE_REG_HIGH (*(volatile unsigned int *)0xcf01475c)

/*
 * Write the 2-bit route field of the receiver unit that a port is mapped to, and mark it in dp_unit_route_bits.
 *
 * The unit comes from dp_map_port_lane_unit(port, field of dp_get_reg9f_field). Its field gets 3 for mode 1,
 * 2 for mode 2, 1 for mode 4 and 0 for any other mode. Bit (port * 4 + the same field) of dp_unit_route_bits is
 * set for mode 1 and cleared for every other mode.
 * Called by dp_run_link_state, which passes 1 above the high clock band, 2 in the middle band, and in the low
 * band 4 when the colour space is in format code group 3, else 2.
 *   port: DP receiver
 *   mode: 1, 2 or 4, see above
 */
void dp_set_unit_route_field(unsigned char port, unsigned char mode)
{
    unsigned char unit, bit;

    unit = dp_map_port_lane_unit(port, dp_get_reg9f_field(port));
    bit = port * 4 + dp_get_reg9f_field(port);
    if (unit <= 3) {
        if (mode == 1) {
            UNIT_ROUTE_REG_LOW |= 3 << (unit * 2);
            dp_unit_route_bits |= mode << bit;
        }
        else if (mode == 2) {
            UNIT_ROUTE_REG_LOW = (UNIT_ROUTE_REG_LOW & ~(3 << (unit * 2))) | (mode << (unit * 2));
            dp_unit_route_bits &= ~(1 << bit);
        }
        else if (mode == 4) {
            UNIT_ROUTE_REG_LOW = (UNIT_ROUTE_REG_LOW & ~(3 << (unit * 2))) | (1 << (unit * 2));
            dp_unit_route_bits &= ~(1 << bit);
        }
        else {
            UNIT_ROUTE_REG_LOW &= ~(3 << (unit * 2));
            dp_unit_route_bits &= ~(1 << bit);
        }
    } else {
        unit -= 4;
        if (mode == 1) {
            UNIT_ROUTE_REG_HIGH |= 3 << (unit * 2);
            dp_unit_route_bits |= mode << bit;
        }
        else if (mode == 2) {
            UNIT_ROUTE_REG_HIGH = (UNIT_ROUTE_REG_HIGH & ~(3 << (unit * 2))) | (mode << (unit * 2));
            dp_unit_route_bits &= ~(1 << bit);
        }
        else if (mode == 4) {
            UNIT_ROUTE_REG_HIGH = (UNIT_ROUTE_REG_HIGH & ~(3 << (unit * 2))) | (1 << (unit * 2));
            dp_unit_route_bits &= ~(1 << bit);
        }
        else {
            UNIT_ROUTE_REG_HIGH &= ~(3 << (unit * 2));
            dp_unit_route_bits &= ~(1 << bit);
        }
    }
}
