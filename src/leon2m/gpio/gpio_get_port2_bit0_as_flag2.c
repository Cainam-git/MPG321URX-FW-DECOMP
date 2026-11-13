/* gpio_get_port2_bit0_as_flag2  (FUN_a0124220)
 *
 * Return 2 when pin 0 of GPIO port 2 reads high, else 0.
 * Returns: 2 or 0
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124220, flags -mcpu=v8 -O2 -g.
 * Source form: result and return type are unsigned char; gpio_is_port2_bit0_high returns unsigned char (its code:
 * cmp %g0,%o0; subx -> 0 or 1). The firmware's 'and %i0, 2, %i0' is the unsigned char return extension.
 */
extern unsigned char gpio_is_port2_bit0_high(void);

/* Return 2 when gpio_is_port2_bit0_high() is true, else 0. No routine calls it. */
unsigned char gpio_get_port2_bit0_as_flag2(void)
{
  unsigned char flag = 0;

  if (gpio_is_port2_bit0_high())
    flag = 2;
  return flag;
}
