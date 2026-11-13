/* dp_tx_hpd_option_stub  (FUN_a0089420)
 *
 * Return 0 (an HPD option that is switched off in this build).
 * Returns: 0
 * Name basis: descriptive - constant 0; tested by dp_tx_run_hpd_actions
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
/*
 * Always returns 0. dp_tx_run_hpd_actions tests it against 1 before an MST reset, so that branch is never
 * taken in this build. Identical copies: dp_tx_hpd_option_stub_copy, _copy2, _copy3.
 */
unsigned int dp_tx_hpd_option_stub(void)
{
  return 0;
}
