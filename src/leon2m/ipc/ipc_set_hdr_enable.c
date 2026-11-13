/* ipc_set_hdr_enable  (FUN_a0138e8c)
 *
 * Ask the input processor to switch the HDR curve service on or off.
 * Name basis: derived - command 0x7A through the mailbox portal 1 sender; mailbox command 0x7A, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138e8c @ 0xa0138e8c, flags -mcpu=v8 -O2 -g.
 * Source form: as ipc_select_hdr_source; the parameter is the one-byte message and 'return 0;' compiles to
 * nothing.
 */
#define IPC_CMD_SET_HDR_ENABLE 0x7a             /* mailbox command 0x7A */
#define IPC_SEND_NO_WAIT       0                /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Switch the HDR curve service of the input processor on or off (mailbox command 0x7A).
 *
 *   enable  non-zero on, 0 off
 *
 * Called from ipc_api_set_hdr_enable.
 */
void ipc_set_hdr_enable(unsigned char enable)
{
    ipc_send_command(IPC_CMD_SET_HDR_ENABLE, 1, &enable, IPC_SEND_NO_WAIT);
    return 0;
}
