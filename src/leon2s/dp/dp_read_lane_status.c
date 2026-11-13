/* dp_read_lane_status  (FUN_a0085684)
 *
 * Read the lane status register 0x40A of a DP receiver.
 *   p1: port
 * Returns: status byte
 * Name basis: descriptive - register 0x40A read through dp_map_port and dp_paged_reg_read8; the link state
 *   routine tests bit pairs 0x11, 0x22, 0x44, 0x88
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0085684 @ 0xa0085684 (-mcpu=v8 -Os -g)
 * Source form: the port is masked, mapped and masked again through the same variable.
 */
extern int dp_map_port();
extern int dp_paged_reg_read8();

/*
 * Return register 0x40a of the DP receiver of a port. The link state routine tests its bit pairs
 * 0x11, 0x22, 0x44 and 0x88.
 *   port: DP port, mapped to its receiver by dp_map_port
 *   (the second parameter is not used)
 */
unsigned char dp_read_lane_status(unsigned int port, unsigned int unused)

{
  port = port & 0xff;
  port = dp_map_port(port) & 0xff;
  return dp_paged_reg_read8(port,0x40a);
}
