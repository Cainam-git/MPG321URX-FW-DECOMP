/* ipc_set_dp_rx_setting_11f  (FUN_a0138b98)
 *
 * Ask the input processor to store a DisplayPort receiver setting byte and set the port up again.
 * Name basis: derived - command 0x80 through the mailbox portal 1 sender; mailbox command 0x80, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138b98 @ 0xa0138b98, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_DP_RX_SETTING_11F 0x80      /* mailbox command 0x80 */
#define IPC_SEND_NO_WAIT              0         /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Store a byte in the record of one DisplayPort receiver (byte +0x11F) in the input processor and have it set the
 * receiver up again (mailbox command 0x80).
 *
 *   port   DP receiver
 *   value  the byte to store
 *
 * Called from ipc_api_set_dp_rx_setting_11f.
 */
void ipc_set_dp_rx_setting_11f(unsigned char port, unsigned char value)
{
    unsigned char msg[4] = {port, value};
    ipc_send_command(IPC_CMD_SET_DP_RX_SETTING_11F, 4, msg, IPC_SEND_NO_WAIT);
}
