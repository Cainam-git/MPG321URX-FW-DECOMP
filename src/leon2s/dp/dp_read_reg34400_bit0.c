/* dp_read_reg34400_bit0  (FUN_a00aba4c)
 *
 * Return bit 0 of register 0xCF034400.
 * Returns: bit value
 * Name basis: descriptive - caller dp_init_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aba4c @ 0xa00aba4c, flags -mcpu=v8 -Os (no -g). Leaf.
 */
#define DP_REG_34400 (*(volatile unsigned int *)0xcf034400)

/* Return bit 0 of register 0xCF034400 (0 or 1). dp_init_port calls it. */
unsigned int dp_read_reg34400_bit0(void)
{
  return DP_REG_34400 & 1;
}
