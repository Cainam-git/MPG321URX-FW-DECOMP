/* pq_api_set_color_gain  (FUN_a014bcf0)
 *
 * Store the colour gain and rebuild the colour matrix with it.
 * Name basis: derived - stSysConfig byte +9, then the routine that scales three rows of coefficients by it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bcf0 @ 0xa014bcf0, flags -mcpu=v8 -O2 -g (section default).
 */
extern unsigned char sys_config_color_gain;
extern void pq_color_matrix_rebuild(unsigned char scale);

/*
 * Store the colour gain (sys_config byte +9) and rebuild the colour matrix with it as the overall scale
 * (x / 128; pq_color_matrix_rebuild also keeps it as pq_color_matrix_scale).
 * The only caller, pq_user_apply_color_gain, passes the mapped Contrast setting.
 */
void pq_api_set_color_gain(unsigned char gain)
{
  sys_config_color_gain = gain;
  pq_color_matrix_rebuild(gain);
  return;
}
