/* dp_mst_get_reply_timeout_copy  (FUN_a00dac00)
 *
 * Return the reply time-out of 3000 ticks.
 * Returns: 3000
 * Note: Identical copy of dp_mst_get_reply_timeout.
 * Name basis: derived - constant
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dac00 @ 0xa00dac00 (-mcpu=v8 -Os -g)
 */
/*
 * Return 3000: the number of ticks (timer_get_ticks units) after which dp_mst_transmit_task gives up an up
 * request chunk that is not answered. Identical to dp_mst_get_reply_timeout.
 */
unsigned int dp_mst_get_reply_timeout_copy(void)
{
  return 3000;
}
