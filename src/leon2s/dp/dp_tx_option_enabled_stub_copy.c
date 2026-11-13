/* dp_tx_option_enabled_stub_copy  (FUN_a008d8d8)
 *
 * Return 1; ipc_dispatch_command sends this value back as a reply byte.
 * Returns: 1
 * Note: Identical copy of dp_tx_option_enabled_stub.
 * Name basis: descriptive - constant 1; called by ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
/*
 * Always returns 1. Identical copy of dp_tx_option_enabled_stub; ipc_dispatch_command calls this one.
 */
unsigned int dp_tx_option_enabled_stub_copy(void)
{
  return 1;
}
