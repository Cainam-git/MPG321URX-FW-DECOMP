/* MailBoxSub_SetDPTXBrilliantMode  (FUN_a0138148)
 *
 * Ask the input processor to start the pacing update of one DP output.
 *   output: DP output 0..4 (others are ignored by the input processor)
 * Name basis: proven - prints 'MailBoxSub_SetDPTXBrilliantMode' (original name); command 0x60 through the
 *   mailbox portal 1 sender; its handler calls dp_tx_request_pacing_update for outputs 0..4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138148 @ 0xa0138148, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with {output}; the print comes before the send.
 */
#define IPC_CMD_REQUEST_DP_TX_PACING_UPDATE 0x60        /* mailbox command 0x60 */
#define IPC_SEND_NO_WAIT                    0           /* ipc_send_command: do not wait for the input processor */
extern int dbg_printf();
extern int ipc_send_command();

/*
 * Print 'MailBoxSub_SetDPTXBrilliantMode' and ask the input processor to mark the pacing update of one DisplayPort
 * output as requested (mailbox command 0x60). The input processor ignores an output number of 5 or more.
 *
 *   output  DP output (0..4)
 *
 * No routine of the main program calls it.
 */
void MailBoxSub_SetDPTXBrilliantMode(unsigned char output)
{
    unsigned char msg[4] = {output};
    dbg_printf("MailBoxSub_SetDPTXBrilliantMode \r\n");
    ipc_send_command(IPC_CMD_REQUEST_DP_TX_PACING_UPDATE, 4, msg, IPC_SEND_NO_WAIT);
}
