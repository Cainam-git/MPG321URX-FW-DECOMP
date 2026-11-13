/* pq_api_set_picture_mode  (FUN_a014c778)
 *
 * Store the picture mode and apply it.
 * Name basis: derived - stSysConfig byte +0xB, then pq_apply_picture_mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014c778 @ 0xa014c778, flags -mcpu=v8 -O2 -g (section default).
 */
extern unsigned char sys_config_picture_mode;
extern void pq_apply_picture_mode(unsigned char mode);

/*
 * Store the picture mode (sys_config byte +0xB) and apply it with pq_apply_picture_mode.
 * The only caller, pq_user_apply_color_settings, passes the mode it chooses from the Color Temperature
 * setting and the Pro mode.
 */
void pq_api_set_picture_mode(unsigned char mode)
{
  sys_config_picture_mode = mode;
  pq_apply_picture_mode(mode);
  return;
}
