/* pq_api_set_color_matrix_option  (FUN_a0145fac)
 *
 * Switch the second option of the colour matrix on or off.
 * Name basis: descriptive - option bit 1 of the matrix flags with its hardware call
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145fac @ 0xa0145fac, flags -mcpu=v8 -O2 -g (section default).
 */
extern void pq_color_matrix_set_option(unsigned char on);

/*
 * Pass the second option flag of the colour matrix on to pq_color_matrix_set_option (bit 1 of
 * pq_color_matrix_flags and bit 7 of the colour matrix option register).
 * Callers: App_Initialize and ddc_apply_maker_vcp_set, both with on = 1 right after pq_api_enable_color_matrix(0, 0).
 */
void pq_api_set_color_matrix_option(unsigned char on)
{
  pq_color_matrix_set_option(on);
  return;
}
