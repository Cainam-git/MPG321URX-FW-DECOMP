/* dp_tx_hpd_option_stub_copy  (FUN_a00aa7bc)
 *
 * Return 0; dp_tx_init_ports skips the set-up of DP output 0 when this is non-zero.
 * Returns: 0
 * Note: Identical copy of dp_tx_hpd_option_stub.
 * Name basis: descriptive - constant 0; tested by dp_tx_init_ports for output 0
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
/*
 * Always returns 0. Identical copy of dp_tx_hpd_option_stub; dp_tx_init_ports tests it for output 0 and skips
 * the set-up of that output when it returns non-zero.
 */
unsigned int dp_tx_hpd_option_stub_copy(void)
{
  return 0;
}
