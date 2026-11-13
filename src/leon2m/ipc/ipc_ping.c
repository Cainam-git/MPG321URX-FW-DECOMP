/* ipc_ping  (FUN_a0137bb0)
 *
 * Ask the input processor to answer with 1.
 * Returns: reply value
 * Name basis: derived - command 0x87 through the mailbox portal 1 sender; used by SYSAPI_PowerSaving; mailbox
 *   command 0x87, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137bb0 @ 0xa0137bb0, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with four zeros.
 */
#define IPC_CMD_PING     0x87           /* mailbox command 0x87 */
#define IPC_SEND_NO_WAIT 0              /* ipc_send_command: do not wait for the input processor */
extern void ipc_send_command();
extern int ipc_wait_reply();
extern unsigned char ipc_reply_result_byte;

/*
 * Check that the input processor answers: send command 0x87 and wait for the reply. The input processor
 * replies 1 to it. Returns bit 0 of the first reply byte.
 *
 * Called from SYSAPI_PowerSaving.
 */
int ipc_ping(void)
{
    unsigned char msg[4] = {0, 0, 0, 0};

    ipc_send_command(IPC_CMD_PING, 4, msg, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);

    return ipc_reply_result_byte & 1;
}
