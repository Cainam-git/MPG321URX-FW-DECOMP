/* dp_tx_hpd_option_stub_copy2  (FUN_a00aa7c4)
 *
 * Return 0; dp_tx_init_ports skips the set-up of a DP output 1..4 when this is non-zero.
 * Returns: 0
 * Note: Identical copy of dp_tx_hpd_option_stub.
 * Name basis: descriptive - constant 0; tested by dp_tx_init_ports for outputs 1..4
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
/*
 * Always returns 0. Identical copy of dp_tx_hpd_option_stub; dp_tx_init_ports tests it for outputs 1..4 and
 * skips the set-up of an output when it returns non-zero.
 */
unsigned int dp_tx_hpd_option_stub_copy2(void)
{
  return 0;
}
