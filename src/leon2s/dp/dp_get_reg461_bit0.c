/* dp_get_reg461_bit0  (FUN_a00ad668)
 *
 * Return bit 0 of register 0x461 of a port.
 * Returns: 0 or 1
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad668 @ 0xa00ad668, flags -mcpu=v8 -Os -g.
 * Source form: the routine is declared with a second parameter that is not used; the read routine is declared
 * without a prototype.
 */
extern int dp_reg_read8();

/* Return bit 0 of receiver register 0x461 (0 or 1).
 *   port: DP receiver
 */
unsigned char dp_get_reg461_bit0(unsigned int port, unsigned int unused)

{
  port = port & 0xff;
  return dp_reg_read8(port,0x461) & 1;
}
