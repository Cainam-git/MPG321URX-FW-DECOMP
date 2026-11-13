/* pq_color_matrix_set_red_gain  (FUN_a013b42c)
 *
 * Store the first gain value and rebuild the colour matrix.
 * Name basis: derived - halfword 0 of the gain record; channel index 0, the index that the menu's red gain
 *   item uses
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b42c @ 0xa013b42c, flags -mcpu=v8 -O2 -g.
 * Source form: pq_color_matrix_rebuild is declared without a prototype, returning int.
 */
extern unsigned char pq_color_matrix_scale;
extern unsigned short pq_color_gains;               /* pq_color_gains[0], the gain of matrix row 0 */
extern int pq_color_matrix_rebuild();

/*
 * Store the gain of matrix row 0 (pq_color_gains[0]) and rebuild the colour matrix with the stored scale.
 *
 * Callers: pq_api_set_rgb_gain and sys_api_config (setting 0..100 turned into setting * 2 + 0x38),
 * ddc_apply_maker_vcp_set and ddc_tool_set_color_temp_gain.
 */
void pq_color_matrix_set_red_gain(unsigned short gain)
{
  pq_color_gains = gain;
  pq_color_matrix_rebuild(pq_color_matrix_scale);
}
