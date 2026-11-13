/* dp_get_unit_route_bit  (FUN_a00adf64)
 *
 * Return one of the four route status bits of a port.
 * Returns: 0 or 1
 * Name basis: descriptive - byte at 0xA807DE70, four bits per port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00adf64 @ 0xa00adf64, flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_unit_route_bits;        /* four bits per port; set and cleared by dp_set_unit_route_field */

/*
 * Return bit (field + port * 4) of dp_unit_route_bits. dp_tx_set_lane_routing calls it for ports 0 and 1.
 *   port: DP port
 *   field: bit within the port's four bits
 */
unsigned int dp_get_unit_route_bit(unsigned char port, int field)

{
  return (int)(unsigned int)dp_unit_route_bits >> (field + port * 4) & 1;
}
