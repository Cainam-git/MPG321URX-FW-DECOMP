/* dp_map_port_lane_unit  (FUN_a00add48)
 *
 * Return the receiver unit that a port and lane pair is mapped to.
 * Returns: unit number
 * Name basis: derived - row of the mapping table at 0xA8078768; 9 for port 2
 *
 * Matching notes
 * --------------
 * FUN_a00add48 (leon2s), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: the range test a * 4 + b > 4 is made on signed ints.
 */
extern unsigned char dp_port_lane_units[][4];   /* four bytes per port */

/*
 * Look up the receiver unit of a port: 9 for port 2; otherwise byte "lane" of the port's row in
 * dp_port_lane_units, or byte 0 of the row when port * 4 + lane is above 4.
 * Callers: dp_set_unit_format_field, dp_set_unit_route_field, dp_select_lane_mask, dp_set_port_control_bit, dp_unit_write_two_24bit_values, dp_unit_set_field.
 *   port: DP port
 *   lane: the value read from the receiver by dp_get_reg9f_field
 */
unsigned char dp_map_port_lane_unit(unsigned char port, unsigned char lane)
{
    if (port == 2)
        return 9;
    if (port * 4 + lane > 4)
        return dp_port_lane_units[port][0];
    return dp_port_lane_units[port][lane];
}
