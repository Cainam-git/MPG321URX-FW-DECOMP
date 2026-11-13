/* osd_api_set_reg_c8_ranges  (FUN_a0146648)
 *
 * Program two pairs of limits in registers 0xC8..0xDB of a menu layer.
 * Name basis: descriptive - forwards to osd_set_reg_c8_ranges
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146648 @ 0xa0146648, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the parameters keep the decompiler's
 * widths (halfwords for the four limits, a byte for the layer).
 */
extern int osd_set_reg_c8_ranges();

/* Pass the four limits and the menu layer (0 or 1) on to osd_set_reg_c8_ranges, which writes registers 0xC8..0xCB
 * and 0xD8..0xDB; the limits are the first and second value of each of the two pairs. Called by the routines that
 * set up the menu layers. */
void osd_api_set_reg_c8_ranges(unsigned short limit0_a, unsigned short limit0_b, unsigned short limit1_a,
                 unsigned short limit1_b, unsigned char layer)

{
  osd_set_reg_c8_ranges(limit0_a,limit0_b,limit1_a,limit1_b,layer);
  return;
}
