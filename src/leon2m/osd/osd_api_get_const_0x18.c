/* osd_api_get_const_0x18  (FUN_a0146e24)
 *
 * Return the constant 0x18.
 * Returns: 0x18
 * Name basis: descriptive - constant 24, the cell code the rounding routines test for
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146e24 @ 0xa0146e24, flags -mcpu=v8 -O2 -g.
 * Source form: the return type is unsigned int.
 */

/* Return 24. osd_draw_text uses it as the width of one cell, in the units of the glyph widths, when it works out
 * the unused width of a text field. */
unsigned int osd_api_get_const_0x18(void)

{
  return 0x18;
}
