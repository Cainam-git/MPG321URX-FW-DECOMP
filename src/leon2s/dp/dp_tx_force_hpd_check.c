/* dp_tx_force_hpd_check  (FUN_a0088fd4)
 *
 * Make the next HPD pass treat one DP output as freshly plugged.
 *   port: DP output 0..4
 * Name basis: derived - flag read and cleared by the HPD action routines ('GOGO' print); set at power-off and
 *   by command 0x75
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_tx_forced_hpd_flags[];

/*
 * Make the next HPD pass treat a DP output as freshly plugged (sets its byte in dp_tx_forced_hpd_flags).
 * dp_tx_run_hpd_actions reads the flag.
 *
 *   port: DP output 0..4
 *
 * Called from the mailbox command dispatcher (ipc_dispatch_command) and from the two receiver power-off
 * routines (input_power_off_receivers_mode0 / mode1).
 */
void dp_tx_force_hpd_check(unsigned int port)
{
  dp_tx_forced_hpd_flags[(port & 0xff)] = 1;
}
