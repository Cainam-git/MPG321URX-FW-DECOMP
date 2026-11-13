/* dp_set_reg1143c_bits  (FUN_a00abba8)
 *
 * Set bits 0..2 of register 0xCF01143C.
 * Name basis: descriptive - counterpart of dp_clear_start_bits; caller dp_stop_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00abba8 @ 0xa00abba8, flags -mcpu=v8 -Os -g. Leaf.
 */
#define DP_REG_1143C (*(volatile unsigned int *)0xcf01143c)

/* Set bits 0..2 of register 0xCF01143C. Counterpart of the first step of dp_clear_start_bits; dp_stop_port calls it. */
void dp_set_reg1143c_bits(void)

{
  DP_REG_1143C = DP_REG_1143C | 7;
  return;
}
