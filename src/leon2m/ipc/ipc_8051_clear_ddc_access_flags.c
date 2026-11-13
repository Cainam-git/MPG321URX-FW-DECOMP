/* ipc_8051_clear_ddc_access_flags  (FUN_a013408c)
 *
 * Tell the 8051 to clear the DDC access flags in the mailbox (command 0x20).
 * Name basis: derived - ipc_send_8051_command with command 0x20; unused; 8051 command 0x20; the handler in the
 *   8051 program (ipc_clear_portal_word; the flags are set by MailBox_UpdateDDCFlag) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a013408c, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_CLEAR_DDC_FLAGS  0x20
#define IPC_SEND_WAIT_TAKEN           1 /* return when the 8051 has taken the command */

/* Command 0x20: the 8051 clears portal word 0x0C, where it keeps the ports whose DDC or EDID was accessed.
   Nothing in the firmware calls this routine. */
void ipc_8051_clear_ddc_access_flags(void)
{
    ipc_send_8051_command(IPC_8051_CMD_CLEAR_DDC_FLAGS, 0, 0, 0, IPC_SEND_WAIT_TAKEN);
}
