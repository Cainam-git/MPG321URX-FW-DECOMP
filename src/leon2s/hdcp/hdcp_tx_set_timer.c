/* hdcp_tx_set_timer  (FUN_a00d0530)
 *
 * Update the timers and start one of them with a value.
 * Name basis: derived - word table at 0xA8078B60
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d0530 @ 0xa00d0530 (-mcpu=v8 -Os -g)
 */
extern int hdcp_tx_update_timers();
extern unsigned int hdcp_tx_timers[];

/*
 * Bring the timers up to date (hdcp_tx_update_timers) and start timer number `timer` (0..14, array
 * hdcp_tx_timers) with `ticks`. Callers use the numbers port + 8, port + 0xb and 10.
 */
void hdcp_tx_set_timer(int timer, unsigned int ticks)

{
  hdcp_tx_update_timers();
  hdcp_tx_timers[timer] = ticks;
}
