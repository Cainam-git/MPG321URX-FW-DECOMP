/* ipc_select_hdr_source  (FUN_a0138bf8)
 *
 * Ask the input processor to select the source that the HDR service follows.
 * Name basis: derived - command 0x77 through the mailbox portal 1 sender; mailbox command 0x77, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138bf8 @ 0xa0138bf8, flags -mcpu=v8 -O2 -g.
 * Source form: the parameter itself is the one-byte message (its stack slot is passed to the sender, no local
 * array). The 'return 0;' compiles to nothing: the call result is dropped and %i0 is not set, so the routine is
 * void.
 */
#define IPC_CMD_SELECT_HDR_SOURCE 0x77          /* mailbox command 0x77 */
#define IPC_SEND_NO_WAIT          0             /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Tell the input processor which source the HDR handling follows (mailbox command 0x77).
 *
 *   port_code  0x31 + 0x10 * n for n = 0..5; the input processor turns it into the index n (every other code
 *              gives 0)
 *
 * Called from sys_set_channel_port.
 */
void ipc_select_hdr_source(unsigned char port_code)
{
    ipc_send_command(IPC_CMD_SELECT_HDR_SOURCE, 1, &port_code, IPC_SEND_NO_WAIT);
    return 0;
}
