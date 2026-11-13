/* pq_color_matrix_set_gains  (FUN_a013b4a4)
 *
 * Store the three gain values and rebuild the colour matrix.
 * Name basis: derived - gain record at 0xA802A46C, then pq_color_matrix_rebuild
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b4a4 @ 0xa013b4a4-0xa013b4cc (10 words), flags -mcpu=v8 -O3 -g.
 * Source form: the gains are one struct of three halfwords, stored in ascending source order (the firmware
 * emits +0 through %lo(sym), then +4, then +2); the rebuild is a tail call.
 */

/* The gains of matrix rows 0, 1 and 2. */
struct color_gains { unsigned short red, green, blue; };
extern struct color_gains pq_color_gains;
extern unsigned char pq_color_matrix_scale;
extern void pq_color_matrix_rebuild(unsigned char);

/*
 * Store the gains of matrix rows 0, 1 and 2 and rebuild the colour matrix with the stored scale.
 *
 * Callers: pq_apply_picture_mode (the mode's three colour values, each plus 1) and pq_api_set_color_triple.
 */
void pq_color_matrix_set_gains(unsigned short red, unsigned short green, unsigned short blue)
{
  pq_color_gains.red = red;
  pq_color_gains.green = green;
  pq_color_gains.blue = blue;
  pq_color_matrix_rebuild(pq_color_matrix_scale);
}
