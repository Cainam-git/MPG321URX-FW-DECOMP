/* dp_get_link_flag  (FUN_a00856d0)
 *
 * Return bit 1 of register 0xAF of a DP receiver.
 *   port
 * Name basis: descriptive - tested together with dp_read_lane_status by the DP status flag routine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00856d0 (0xa00856d0-0xa00856fc, 11 words), flags -mcpu=v8 -Os -g.
 * dp_map_port returns one bit; dp_paged_reg_read8 returns a byte, so int holds it exactly.
 * Source form: the masked value is an int local tested in its own statement ('(f() & 2) != 0' in one
 * expression folds to srl 1 / and 1).
 */
extern unsigned char dp_map_port(unsigned char);
extern int dp_paged_reg_read8(unsigned char, int);

/*
 * Return 1 when bit 1 of register 0xaf of the DP receiver of a port is set, else 0. The link state routine
 * tests it together with dp_read_lane_status.
 *   port: DP port, mapped to its receiver by dp_map_port
 */
int dp_get_link_flag(unsigned char port)
{
  int bit1 = dp_paged_reg_read8(dp_map_port(port), 0xaf) & 2;

  return bit1 != 0;
}
