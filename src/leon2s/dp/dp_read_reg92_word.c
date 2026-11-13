/* dp_read_reg92_word  (FUN_a00acb60)
 *
 * Return the 16-bit value of register 0x92 of a port.
 * Returns: value
 * Name basis: descriptive - forwards to the 16-bit read
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00acb60 @ 0xa00acb60, flags -mcpu=v8 -Os -g.
 * Source form: the routine is declared with a second parameter that is not used; the read routine is declared
 * without a prototype.
 */
extern int dp_reg_read16_stable();

/*
 * Read the 16-bit receiver register 0x92 through dp_reg_read16_stable. The callers store the result as the
 * vtotal field of the port's timing.
 *   port: DP receiver
 */
unsigned short dp_read_reg92_word(unsigned int port, unsigned int unused)

{
  port = port & 0xff;
  return dp_reg_read16_stable(port,0x92);
}
