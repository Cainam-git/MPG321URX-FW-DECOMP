/* ipc_api_signal_alive  (FUN_a014dd10)
 *
 * Send the alive signal.
 * Name basis: proven - tail call to ipc_signal_alive
 *
 * Matching notes
 * --------------
 * FUN_a014dd10 (leon2m 0xa014dd10-0xa014dd20, 16 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Tail call of ipc_signal_alive ('mov %o7, %g1; call; mov %g1, %o7'); the nop after it is the -g line nop.
 * ipc_signal_alive is the start-up routine ipc_signal_alive: main-program code runs at its name address - 0xa0060000, so
 * the call reaches 0xa002ced8 (0x4008ced8 = 0xa002ced8 + 0xa0060000 mod 2^32).
 */
extern void ipc_signal_alive(void);

/*
 * Forward on to ipc_signal_alive, which tells the 8051 that the main processor is still running. Called by
 * oled_power_task (oled_power_task).
 */
void ipc_api_signal_alive(void)
{
    ipc_signal_alive();
}
