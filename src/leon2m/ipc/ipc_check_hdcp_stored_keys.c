/* ipc_check_hdcp_stored_keys  (FUN_a013851c)
 *
 * Ask the input processor to check the stored copy-protection keys.
 * Returns: reply value
 * Name basis: derived - command 0xFD through the mailbox portal 1 sender; mailbox command 0xFD, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013851c @ 0xa013851c, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with {block, 0, 0, 0}.
 */
#define IPC_CMD_CHECK_HDCP_STORED_KEYS 0xfd     /* mailbox command 0xFD */
#define IPC_SEND_NO_WAIT               0        /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command();
extern int ipc_wait_reply();
extern unsigned char ipc_reply_result_byte;

/*
 * Ask the input processor to check the stored key data against the sum stored with it (mailbox command 0xFD) and
 * return the first reply byte: 1 when the sums are equal, 0 when they differ or the block number is neither
 * 1 nor 2.
 *
 *   block  1 = the first key set, 2 = the HDCP 2 data
 *
 * Called from ddc_tool_build_reply.
 */
int ipc_check_hdcp_stored_keys(unsigned char block)
{
    unsigned char msg[4] = {block, 0, 0, 0};
    
    ipc_send_command(IPC_CMD_CHECK_HDCP_STORED_KEYS, 4, msg, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);
    
    return ipc_reply_result_byte;
}
