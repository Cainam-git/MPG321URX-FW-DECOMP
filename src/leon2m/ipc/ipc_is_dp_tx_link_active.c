/* ipc_is_dp_tx_link_active  (FUN_a013808c)
 *
 * Ask the input processor to report whether a DisplayPort output link is active.
 * Returns: reply value
 * Name basis: derived - command 0x5C through the mailbox portal 1 sender; unused; mailbox command 0x5C, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013808c @ 0xa013808c, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with {output, 0, 0, 0}.
 */
#define IPC_CMD_IS_DP_TX_LINK_ACTIVE 0x5c       /* mailbox command 0x5C */
#define IPC_SEND_NO_WAIT             0          /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command();
extern int ipc_wait_reply();
extern unsigned char ipc_reply_result_byte;

/*
 * Ask the input processor whether the link of one DisplayPort output is active (mailbox command 0x5C) and
 * return the first reply byte.
 *
 *   output  DP output
 *
 * No routine of the main program calls it.
 */
int ipc_is_dp_tx_link_active(unsigned char output)
{
    unsigned char msg[4] = {output, 0, 0, 0};
    
    ipc_send_command(IPC_CMD_IS_DP_TX_LINK_ACTIVE, 4, msg, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);
    
    return ipc_reply_result_byte;
}
