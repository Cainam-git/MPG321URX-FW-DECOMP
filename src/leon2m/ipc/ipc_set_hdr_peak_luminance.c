/* ipc_set_hdr_peak_luminance  (FUN_a0138e28)
 *
 * Ask the input processor to store the panel's peak luminance for the HDR handling.
 * Name basis: derived - command 0x76 through the mailbox portal 1 sender; mailbox command 0x76, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138e28 @ 0xa0138e28, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the low and high byte of the parameter (the whole
 * word is cleared first).
 */
#define IPC_CMD_SET_HDR_PEAK_LUMINANCE 0x76     /* mailbox command 0x76 */
#define IPC_SEND_NO_WAIT               0        /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Send the panel's peak luminance for the HDR handling to the input processor (mailbox command 0x76). The input
 * processor limits it to 10000 (1000 when 0 is given).
 *
 *   peak_luminance  sent low byte first
 *
 * Called from ipc_api_set_hdr_peak_luminance and System_Initialize.
 */
void ipc_set_hdr_peak_luminance(unsigned short peak_luminance)
{
    unsigned char msg[4] = {(unsigned char)peak_luminance, (unsigned char)(peak_luminance >> 8)};
    ipc_send_command(IPC_CMD_SET_HDR_PEAK_LUMINANCE, 4, msg, IPC_SEND_NO_WAIT);
}
