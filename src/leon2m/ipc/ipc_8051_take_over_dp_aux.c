/* ipc_8051_take_over_dp_aux  (FUN_a0133d28)
 *
 * Tell the 8051 to answer the DisplayPort AUX requests itself (command 0x2A).
 * Name basis: proven - ipc_send_8051_command with command 0x2A; unused; 8051 command 0x2A; the handler in the
 *   8051 program (Enable_DPMRX, original name) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133d28, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_TAKE_OVER_DP_AUX  0x2a
#define IPC_SEND_WAIT_TAKEN            1    /* return when the 8051 has taken the command */

/* Command 0x2A: the 8051 runs its Enable_DPMRX routine, which switches both DisplayPort receivers to AUX handling by
   the 8051. No arguments. Nothing in the firmware calls this routine. */
void ipc_8051_take_over_dp_aux(void)
{
    ipc_send_8051_command(IPC_8051_CMD_TAKE_OVER_DP_AUX, 0, 0, 0, IPC_SEND_WAIT_TAKEN);
}
