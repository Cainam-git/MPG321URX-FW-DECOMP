/* dp_get_port_pending_bit  (FUN_a00ad5a4)
 *
 * Return the pending bit of port 0 or 1.
 * Returns: 0 or 1
 * Name basis: descriptive - byte at 0xA8079312
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad5a4 @ 0xa00ad5a4, flags -mcpu=v8 -Os -g. Leaf.
 */
extern unsigned char dp_port_pending_bits;      /* bit 0 = port 0, bit 1 = port 1 */

/* Return bit "port" of dp_port_pending_bits for port 0 or 1, and 0 for any other value. */
unsigned int dp_get_port_pending_bit(unsigned char port)

{
  unsigned int bit;

  bit = 0;
  if (port < 2) {
    bit = (int)(unsigned int)dp_port_pending_bits >> port & 1;
  }
  return bit;
}
