/* dp_clear_port_pending_bit  (FUN_a00ad060)
 *
 * Clear the pending bit of port 0 or 1, or of both.
 * Name basis: descriptive - byte at 0xA8079312
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad060 @ 0xa00ad060, flags -mcpu=v8 -Os -g. Leaf.
 */
extern unsigned char dp_port_pending_bits;      /* bit 0 = port 0, bit 1 = port 1 */

/*
 * Clear the pending bit of port 0 or port 1 in dp_port_pending_bits, or all bits when port is 2. A value above 2
 * does nothing. Callers: dp_setup_service_block, dp_port_task.
 *   port: 0, 1, or 2 for both
 */
void dp_clear_port_pending_bit(unsigned char port)

{
  if (port < 3) {
    if (port == 2) {
      dp_port_pending_bits = 0;
    }
    else {
      dp_port_pending_bits = dp_port_pending_bits & ~(unsigned char)(1 << port);
    }
  }
  return;
}
