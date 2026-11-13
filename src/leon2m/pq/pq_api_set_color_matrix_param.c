/* pq_api_set_color_matrix_param  (FUN_a014929c)
 *
 * Store a colour parameter and rebuild the colour matrix.
 * Name basis: descriptive - stSysConfig byte +0xA, then the matrix routine; the caller limits the value to 100
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014929c @ 0xa014929c, flags -mcpu=v8 -O2 -g (section default).
 */
extern unsigned char sys_config_color_matrix_param;
extern void pq_color_matrix_set_param_second(unsigned char);

/*
 * Store the colour parameter (sys_config byte +0xA) and make it the second colour matrix parameter, which
 * rebuilds the matrix. In the rebuild the second parameter scales rows 1 and 2 of the matrix.
 * The only caller, pq_user_apply_color_matrix_param, limits the value to 100 first.
 */
void pq_api_set_color_matrix_param(unsigned char value)
{
  sys_config_color_matrix_param = value;
  pq_color_matrix_set_param_second(value);
  return;
}
