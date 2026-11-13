/* ipc_set_hdr_source_enable  (FUN_a0138c20)
 *
 * Ask the input processor to switch the HDR handling of a source on or off.
 * Name basis: derived - command 0x78 through the mailbox portal 1 sender; mailbox command 0x78, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138c20 @ 0xa0138c20, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters.
 */
#define IPC_CMD_SET_HDR_SOURCE_ENABLE 0x78      /* mailbox command 0x78 */
#define IPC_SEND_NO_WAIT              0         /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Switch the HDR handling of one source on or off in the input processor (mailbox command 0x78).
 *
 *   port_code  the source, coded as for ipc_select_hdr_source
 *   enable     non-zero sets the source's bit in the HDR enable bits, 0 clears it
 *
 * Called from hdr_api_set_port_enable.
 */
void ipc_set_hdr_source_enable(unsigned char port_code, unsigned char enable)
{
    unsigned char msg[4] = {port_code, enable};
    ipc_send_command(IPC_CMD_SET_HDR_SOURCE_ENABLE, 4, msg, IPC_SEND_NO_WAIT);
}
