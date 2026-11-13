/* ipc_set_dp_mst_logical_number  (FUN_a0137d40)
 *
 * Ask the input processor to set the DisplayPort multi-stream logical number.
 * Name basis: derived - command 0x2F through the mailbox portal 1 sender; waits until the command slot reads
 *   empty (command taken); mailbox command 0x2F, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137d40 @ 0xa0137d40, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array with an initialiser (a single unsigned char local gives no word
 * clear); the callee is declared void (int, int, void *, int).
 */
#define IPC_CMD_SET_DP_MST_LOGICAL_NUMBER 0x2f  /* mailbox command 0x2F */
#define IPC_SEND_WAIT_TAKEN               1     /* ipc_send_command: wait until the input processor has taken the message */
extern void ipc_send_command(int, int, void *, int);

/*
 * Send the multi-stream (MST) logical number to the input processor (mailbox command 0x2F). The input processor
 * prints it ('MSTLogicalNum') and stores it as its MST option value.
 *
 * Called from startup_init_input_ports.
 */
void ipc_set_dp_mst_logical_number(unsigned char logical_number)
{
  unsigned char msg[4] = { logical_number };

  ipc_send_command(IPC_CMD_SET_DP_MST_LOGICAL_NUMBER, 4, msg, IPC_SEND_WAIT_TAKEN);
}
