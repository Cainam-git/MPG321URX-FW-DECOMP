/* dp_tx_option_enabled_stub  (FUN_a0089750)
 *
 * Return 1 (an output option that is always on in this build).
 * Returns: 1
 * Name basis: descriptive - constant 1; tested by dp_tx_set_reg70_bit4
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
/*
 * Always returns 1. dp_tx_set_reg70_bit4 tests it against 1 before it changes register 0xCF018E80, so that
 * step is always done in this build. Identical copies: dp_tx_option_enabled_stub_copy, _copy2.
 */
unsigned int dp_tx_option_enabled_stub(void)
{
  return 1;
}
