/* ipc_8051_notify_power_off  (FUN_a0133e10)
 *
 * Send 8051 command 0x17 and never return (send mode 3 loops forever after the send).
 * Note: Mode 3 writes the command word even when the previous command was not taken within 100 reads.
 * Name basis: derived - ipc_send_8051_command with command 0x17 and mode 3 (send, then loop forever); sent by
 *   SYSAPI_PowerOff
 *
 * Matching notes
 * --------------
 * FUN_a0133e10, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_POWER_OFF      0x17
#define IPC_SEND_NEVER_RETURNS      3   /* send the command, then loop forever */

/*
 * Command 0x17, sent by SYSAPI_PowerOff: the 8051 stops both LEON processors and runs its power-off sequence.
 * The 8051 does not acknowledge this command, so the send mode is IPC_SEND_NEVER_RETURNS and this routine does not
 * return.
 */
void ipc_8051_notify_power_off(void)
{
    ipc_send_8051_command(IPC_8051_CMD_POWER_OFF, 0, 0, 0, IPC_SEND_NEVER_RETURNS);
}
