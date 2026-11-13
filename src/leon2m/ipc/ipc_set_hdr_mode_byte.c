/* ipc_set_hdr_mode_byte  (FUN_a0138edc)
 *
 * Ask the input processor to store an HDR mode byte.
 * Returns: 0
 * Name basis: derived - command 0x88 through the mailbox portal 1 sender; mailbox command 0x88, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138edc @ 0xa0138edc, flags -mcpu=v8 -O2 -g.
 * Source form: as ipc_select_hdr_source; the parameter is the one-byte message and 'return 0;' compiles to
 * nothing.
 */
#define IPC_CMD_SET_HDR_MODE_BYTE 0x88          /* mailbox command 0x88 */
#define IPC_SEND_NO_WAIT          0             /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Send an HDR mode byte to the input processor (mailbox command 0x88). The input processor stores it and marks
 * its HDR settings as changed.
 *
 *   mode  the mode byte
 *
 * Called from ldc_api_set_zone_grid.
 */
void ipc_set_hdr_mode_byte(unsigned char mode)
{
    ipc_send_command(IPC_CMD_SET_HDR_MODE_BYTE, 1, &mode, IPC_SEND_NO_WAIT);
    return 0;
}
