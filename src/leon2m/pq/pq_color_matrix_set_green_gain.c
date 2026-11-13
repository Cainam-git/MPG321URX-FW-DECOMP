/* pq_color_matrix_set_green_gain  (FUN_a013b44c)
 *
 * Store the second gain value and rebuild the colour matrix.
 * Name basis: derived - halfword 1 of the gain record; channel index 1, the index that the menu's green gain
 *   item uses
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b44c @ 0xa013b44c, flags -mcpu=v8 -O2 -g.
 * Source form: pq_color_matrix_rebuild is declared without a prototype, returning int.
 */
extern unsigned char pq_color_matrix_scale;
extern unsigned short pq_color_gains_green;         /* pq_color_gains[1], the gain of matrix row 1 */
extern int pq_color_matrix_rebuild();

/*
 * Store the gain of matrix row 1 (pq_color_gains[1]) and rebuild the colour matrix with the stored scale.
 *
 * Callers: pq_api_set_rgb_gain and sys_api_config (setting 0..100 turned into setting * 2 + 0x38),
 * ddc_apply_maker_vcp_set and ddc_tool_set_color_temp_gain.
 */
void pq_color_matrix_set_green_gain(unsigned short gain)
{
  pq_color_gains_green = gain;
  pq_color_matrix_rebuild(pq_color_matrix_scale);
}
