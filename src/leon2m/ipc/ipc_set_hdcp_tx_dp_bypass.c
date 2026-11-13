/* ipc_set_hdcp_tx_dp_bypass  (FUN_a01380c4)
 *
 * Ask the input processor to clear or set the copy-protection bypass bit of DisplayPort output 0.
 *   output: must be 0, else nothing is sent
 *   off: non-zero = clear the bypass bit, 0 = set it
 * Returns: the reply byte (the input processor answers zeros); 0xFF when nothing was sent
 * Note: A non-zero second argument clears the bypass bit (print 'ENABLE'), zero sets it (print 'DISABLE').
 * Name basis: derived - command 0x5D through the mailbox portal 1 sender; only for a first argument of 0;
 *   unused; its handler prints 'ENABLE: SC_DPTX_HDCP_CTL' after clearing bit 6 and 'DISABLE: SC_DPTX_HDCP_CTL'
 *   after setting it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01380c4 @ 0xa01380c4, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a zero-initialised 4-byte array (the word is cleared before the test); the result
 * is an int local set to -1 and returned as unsigned char.
 */
#define IPC_CMD_SET_HDCP_TX_DP_BYPASS 0x5d      /* mailbox command 0x5D */
#define IPC_SEND_NO_WAIT              0         /* ipc_send_command: do not wait for the input processor */
#define BYPASS_NOT_SENT               -1        /* returned (as 0xff) when nothing was sent */
extern unsigned char ipc_reply_result_byte;
extern void ipc_send_command(int, int, unsigned char *, int);
extern void ipc_wait_reply(int);

/*
 * Ask the input processor to set or clear the bypass bit of the DisplayPort protection control register
 * (mailbox command 0x5D). Only output 0 is sent; for any other output nothing is sent and 0xff is returned.
 * Otherwise it returns the first reply byte; the input processor's reply to this command is all zeros.
 *
 *   output  DP output; only 0 is sent
 *   off     non-zero clears the bypass bit; 0 sets it
 *
 * No routine of the main program calls it directly (it is reached through a table).
 */
unsigned char ipc_set_hdcp_tx_dp_bypass(unsigned char output, unsigned char off)
{
    unsigned char msg[4] = {0};
    int result = BYPASS_NOT_SENT;

    if (output == 0) {
        msg[0] = output;
        msg[1] = off;
        ipc_send_command(IPC_CMD_SET_HDCP_TX_DP_BYPASS, 4, msg, IPC_SEND_NO_WAIT);
        ipc_wait_reply(1);
        result = ipc_reply_result_byte;
    }
    return result;
}
