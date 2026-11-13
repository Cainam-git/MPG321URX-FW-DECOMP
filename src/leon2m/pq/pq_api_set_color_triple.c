/* pq_api_set_color_triple  (FUN_a0145fc0)
 *
 * Store three colour values and rebuild the colour matrix.
 * Name basis: descriptive - forwards to the routine that stores the three values in ascending fields
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145fc0 @ 0xa0145fc0, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the three parameters are unsigned short and passed on unchanged.
 */
extern void pq_color_matrix_set_gains(unsigned short, unsigned short, unsigned short);

/*
 * Store the gains of matrix rows 0, 1 and 2 (pq_color_gains) and rebuild the colour matrix with them.
 *
 *   red, green, blue  the three gains in that order
 *
 * pq_user_apply_color_temperature passes the three colour values of the chosen colour temperature, each plus 1;
 * ShowLogo and ddc_tool_set_fill_or_inspection pass 0x100 for all three.
 */
void pq_api_set_color_triple(unsigned short red, unsigned short green, unsigned short blue)
{
  pq_color_matrix_set_gains(red, green, blue);
  return;
}
