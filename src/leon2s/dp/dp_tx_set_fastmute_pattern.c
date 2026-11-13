/* dp_tx_set_fastmute_pattern  (FUN_a0089e54)
 *
 * Switch the fast-mute pattern of a DP output on or off.
 *   port: DP output
 *   on: 1 = on
 * Name basis: derived - register 0x7D bit 4, the bit dp_tx_update_edp_fastmute switches with
 *   'EnableEDPFastmutePattern'; command 0x63
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: dp_tx_reg_update_bits is declared without a prototype.
 */
extern int dp_tx_reg_update_bits();

/*
 * Set (on = 1) or clear bit 4 of register 0x7D of a DP output. dp_tx_update_edp_fastmute switches the same bit
 * for eDP outputs 1..4 ('EnableEDPFastmutePattern').
 *
 *   port: DP output 0..4
 *   on:   1 = set, any other value = clear
 *
 * Called from the mailbox command dispatcher (ipc_dispatch_command).
 */
void dp_tx_set_fastmute_pattern(unsigned char port, unsigned char on)
{
  dp_tx_reg_update_bits(port,0x7d,0x10,on);
}
