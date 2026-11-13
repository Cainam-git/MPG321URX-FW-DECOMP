/* ipc_clear_hdmi_tx_request_bit14  (FUN_a0137fa0)
 *
 * Ask the input processor to clear flag bit 14 of an HDMI output's request and mark it pending.
 *   port: HDMI TX port
 * Name basis: descriptive - command 0x43 through the mailbox portal 1 sender with only the HDMI TX port; its
 *   handler in the input program clears bit 14 of that port's request record and calls
 *   hdmi_tx_mark_request_pending; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137fa0 @ 0xa0137fa0, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the one parameter.
 */
#define IPC_CMD_CLEAR_HDMI_TX_REQUEST_BIT14 0x43        /* mailbox command 0x43 */
#define IPC_SEND_NO_WAIT                    0           /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to clear flag bit 14 of the request record of one HDMI transmitter port and to mark
 * the request pending (mailbox command 0x43). Only the port number is sent.
 *
 *   port  HDMI transmitter port
 *
 * No routine of the main program calls it.
 */
void ipc_clear_hdmi_tx_request_bit14(unsigned char port)
{
    unsigned char msg[4] = {port};

    ipc_send_command(IPC_CMD_CLEAR_HDMI_TX_REQUEST_BIT14, 4, msg, IPC_SEND_NO_WAIT);
}
