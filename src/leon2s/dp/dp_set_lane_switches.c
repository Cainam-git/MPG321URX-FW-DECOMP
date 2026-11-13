/* dp_set_lane_switches  (FUN_a0084c94)
 *
 * Set the four per-lane on/off switches of a DP receiver from a mask.
 *   port
 *   mask
 * Name basis: descriptive - bits 0..3 of the mask to registers 0x140/0x1C0/0x240/0x2C0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0084c94 @ 0xa0084c94 (-mcpu=v8 -Os -g)
 * Source form: the port is mapped through itself (the parameter is reused) and the mask byte is copied into
 * an unsigned int that the three shifted tests use.
 */
extern int dp_map_port();
extern void dp_paged_reg_update_bits();

/*
 * Write bit 0 of each of the registers 0x140, 0x1c0, 0x240 and 0x2c0 of a DP receiver from the four low bits
 * of a mask (mask bit 0 to the first register, bit 3 to the last).
 *   port: DP port, mapped to its receiver by dp_map_port
 *   mask: bits 0..3 are the values
 */
void dp_set_lane_switches(int port, unsigned char mask)

{
  unsigned int bits;
  
  port = dp_map_port(port & 0xff) & 0xff;
  bits = mask & 0xff;
  dp_paged_reg_update_bits(port,0x140,1,mask & 1);
  dp_paged_reg_update_bits(port,0x1c0,1,bits >> 1 & 1);
  dp_paged_reg_update_bits(port,0x240,1,bits >> 2 & 1);
  dp_paged_reg_update_bits(port,0x2c0,1,bits >> 3 & 1);
  return;
}
