/* hdr_request_curve_table_reload  (FUN_a0063950)
 *
 * Request a reload of the tone-curve row table before the next static curve build.
 * Name basis: derived - sets the flag hdr_build_static_tone_curve tests before copying the row table
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0063950 @ 0xa0063950 (-mcpu=v8 -Os -g)
 */
extern unsigned char hdr_curve_rows_reload_flag;

/*
 * Ask for the static tone-curve rows to be reloaded: sets hdr_curve_rows_reload_flag, which
 * hdr_build_static_tone_curve tests before it copies the row table. Called for the mailbox command
 * IPC_CMD_RELOAD_HDR_TONE_CURVE.
 */
void hdr_request_curve_table_reload(void)
{
  hdr_curve_rows_reload_flag = 1;
  return;
}
