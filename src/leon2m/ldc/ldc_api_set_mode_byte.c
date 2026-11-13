/* ldc_api_set_mode_byte  (FUN_a01438c8)
 *
 * Send a mode byte to the dimming processor when it has changed.
 * Name basis: descriptive - forwards; the last value is kept at 0xA802A45A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01438c8 @ 0xa01438c8, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype; the parameter is an unsigned char.
 */
extern int ldc_send_peaking();

/*
 * Forward mode to ldc_send_peaking, which sends command 0x82 to the dimming processor only when the byte differs
 * from the one sent last. The callers pass 0 or 1 (pq_fga_handle_command and the two functions APPBlurFree_AfterMute and
 * panel_blurfree_apply_user_mode).
 */
void ldc_api_set_mode_byte(unsigned char mode)

{
  ldc_send_peaking(mode);
  return;
}
