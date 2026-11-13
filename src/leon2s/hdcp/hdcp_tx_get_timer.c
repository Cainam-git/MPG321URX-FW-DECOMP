/* hdcp_tx_get_timer  (FUN_a00cfb20)
 *
 * Update the timers and return one of them.
 * Returns: remaining ticks
 * Name basis: derived - word table at 0xA8078B60
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cfb20 @ 0xa00cfb20 (-mcpu=v8 -Os -g)
 */
extern int hdcp_tx_update_timers();
extern unsigned int hdcp_tx_timers[];

/*
 * Bring the timers up to date (hdcp_tx_update_timers) and return the remaining ticks of timer number `timer`
 * (0..14). Callers use the numbers port + 8, port + 0xb, 10 and 0xd.
 */
int hdcp_tx_get_timer(int timer)

{
  hdcp_tx_update_timers();
  return hdcp_tx_timers[timer];
}
