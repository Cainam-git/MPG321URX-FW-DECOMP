/* dp_set_lane_option_bit  (FUN_a00857d0)
 *
 * Set or clear bit 2 of the four lane registers of a DP receiver.
 *   p1: port
 *   p2: 1 = set
 * Name basis: descriptive - registers 0x551/0x651/0x751/0x851; caller ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00857d0 @ 0xa00857d0 (-mcpu=v8 -Os -g)
 * Source form: the last call also passes the unused parameters 5 and 6 on.
 */
extern int dp_map_port();
extern void dp_paged_reg_update_bits();

/*
 * Set or clear bit 2 of the registers 0x551, 0x651, 0x751 and 0x851 of the DP receiver of a port.
 *   port:  DP port, mapped to its receiver by dp_map_port
 *   value: 1 = set, 0 = clear
 * Called by ipc_dispatch_command.
 */
void dp_set_lane_option_bit(unsigned char port,unsigned char value,unsigned int unused_3,unsigned int unused_4,
                 unsigned int unused_5,unsigned int unused_6)

{
  port = port & 0xff;
  port = dp_map_port(port) & 0xff;
  dp_paged_reg_update_bits(port,0x551,4,value);
  dp_paged_reg_update_bits(port,0x651,4,value);
  dp_paged_reg_update_bits(port,0x751,4,value);
  dp_paged_reg_update_bits(port,0x851,4,value,unused_5,unused_6);
  return;
}
