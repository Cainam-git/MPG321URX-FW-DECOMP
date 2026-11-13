/* ipc_request_hdr_reload  (FUN_a0138eb4)
 *
 * Ask the input processor to mark the HDR settings as changed.
 * Name basis: derived - command 0x7B through the mailbox portal 1 sender; unused; mailbox command 0x7B, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138eb4 @ 0xa0138eb4, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with four zeros.
 */
#define IPC_CMD_REQUEST_HDR_RELOAD 0x7b         /* mailbox command 0x7B */
#define IPC_SEND_NO_WAIT           0            /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to mark its HDR settings as changed and to reload the curve table (mailbox command
 * 0x7B).
 *
 * No routine of the main program calls it.
 */
void ipc_request_hdr_reload(void)
{
    unsigned char msg[4] = {0, 0, 0, 0};
    ipc_send_command(IPC_CMD_REQUEST_HDR_RELOAD, 4, msg, IPC_SEND_NO_WAIT);
}
