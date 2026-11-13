/* pq_color_matrix_set_param_second  (FUN_a013b684)
 *
 * Store the second matrix parameter and rebuild the colour matrix.
 * Name basis: descriptive - byte at 0xA802A462
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b684 @ 0xa013b684, flags -mcpu=v8 -O2 -g.
 * Source form: pq_color_matrix_rebuild is declared without a prototype, returning int.
 */
extern unsigned char pq_color_matrix_scale;
extern unsigned char pq_color_matrix_param_second;
extern int pq_color_matrix_rebuild();

/*
 * Store the second colour matrix parameter and rebuild the matrix with the stored scale. In the rebuild it
 * scales rows 1 and 2 (second * |first| / 128).
 *
 * Callers: pq_api_set_color_matrix_param (the colour parameter, sys_config byte +0xA) and sys_api_config.
 */
void pq_color_matrix_set_param_second(unsigned char value)
{
  pq_color_matrix_param_second = value;
  pq_color_matrix_rebuild(pq_color_matrix_scale);
}
