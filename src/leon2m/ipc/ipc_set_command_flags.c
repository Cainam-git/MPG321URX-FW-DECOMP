/* ipc_set_command_flags  (FUN_a0138284)
 *
 * Ask the input processor to set the command flags.
 * Name basis: derived - command 0x7D through the mailbox portal 1 sender; called from start-up; mailbox
 *   command 0x7D, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138284 @ 0xa0138284, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a zero-initialised 4-byte array; panel_get_active_row is called after it and its
 * result is dropped.
 */
#define IPC_CMD_SET_COMMAND_FLAGS 0x7d          /* mailbox command 0x7D */
#define IPC_SEND_NO_WAIT          0             /* ipc_send_command: do not wait for the input processor */
extern int panel_get_active_row(void);
extern int ipc_send_command();

/*
 * Send the command flags 0 to the input processor (mailbox command 0x7D). The input processor keeps the byte as
 * its port action flags; bits 0 and 1 are the enables of HDMI transmitter ports 0 and 1. The routine also
 * calls panel_get_active_row and drops the result.
 *
 * Called from startup_bring_up_system.
 */
void ipc_set_command_flags(void)
{
    unsigned char msg[4] = {0, 0, 0, 0};
    panel_get_active_row();
    ipc_send_command(IPC_CMD_SET_COMMAND_FLAGS, 4, msg, IPC_SEND_NO_WAIT);
}
