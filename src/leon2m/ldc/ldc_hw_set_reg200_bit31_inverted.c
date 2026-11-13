/* ldc_hw_set_reg200_bit31_inverted  (FUN_a00fc15c)
 *
 * Clear bit 31 of register 0xD0040200 when the argument is 1 and set it for every other value.
 *   on: 1 clears the bit, every other value sets it
 * Note: ldc_hw_api_set_enable_mode passes 0 for its modes 0 and 1 (bit set) and 1 for mode 2 (bit cleared).
 * Name basis: descriptive - bit 31 of 0xD0040200: and-mask 0x7FFFFFFF for the argument 1, or-mask 0x80000000
 *   otherwise
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc15c, flags -mcpu=v8 -O3 -g.
 * Source form: the register is a constant hardware address (volatile pointer cast); an extern symbol gives the
 * sethi/%lo simm13 form. Each arm does its own load and store.
 */

/* Register at offset 0x200 of the grid block; the routine changes only its bit 31. */
#define LDC_REG_200  (*(volatile unsigned int *)0xd0040200)

/*
 * Clear bit 31 of LDC_REG_200 when on is 1 and set it for every other value. Called by ldc_hw_api_set_enable_mode,
 * which passes 0 for its modes 0 and 1 and 1 for its mode 2.
 */
void ldc_hw_set_reg200_bit31_inverted(unsigned char on)
{
  if (on == 1)
    LDC_REG_200 &= 0x7fffffff;
  else
    LDC_REG_200 |= 0x80000000;
}
