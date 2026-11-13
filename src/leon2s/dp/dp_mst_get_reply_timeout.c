/* dp_mst_get_reply_timeout  (FUN_a00dabf8)
 *
 * Return the reply time-out of 3000 ticks.
 * Returns: 3000
 * Name basis: derived - constant
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dabf8 @ 0xa00dabf8 (-mcpu=v8 -Os -g)
 */
/*
 * Return 3000: the number of ticks (timer_get_ticks units) after which dp_mst_transmit_task gives up a down
 * reply chunk that is not answered. Identical to dp_mst_get_reply_timeout_copy.
 */
unsigned int dp_mst_get_reply_timeout(void)
{
  return 3000;
}
