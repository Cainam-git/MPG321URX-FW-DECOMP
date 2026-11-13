/* dp_get_reg480_bit0  (FUN_a00ae238)
 *
 * Return bit 0 of register 0x480 of a port.
 * Returns: 0 or 1
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae238 @ 0xa00ae238, flags -mcpu=v8 -Os -g.
 * Source form: the routine is declared with a second parameter that is not used; the read routine is declared
 * without a prototype.
 */
extern int dp_reg_read8();

/* Return bit 0 of receiver register 0x480 (0 or 1). dp_set_reg44_high_bits calls it.
 *   port: DP receiver
 */
unsigned char dp_get_reg480_bit0(unsigned int port, unsigned int unused)

{
  port = port & 0xff;
  return dp_reg_read8(port,0x480) & 1;
}
