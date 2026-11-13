/* ipc_reload_hdr_tone_curve  (FUN_a0138f04)
 *
 * Ask the input processor to reload the HDR tone curve table.
 * Name basis: derived - command 0xA2 through the mailbox portal 1 sender; unused; mailbox command 0xA2, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138f04 @ 0xa0138f04 (-mcpu=v8 -O2 -g).
 */
extern int ipc_send_command();

#define IPC_CMD_RELOAD_HDR_TONE_CURVE 0xa2      /* mailbox command 0xA2 */
#define IPC_SEND_NO_WAIT              0         /* do not wait for the reply slot */

/*
 * Send mailbox command 0xA2 (reload the HDR tone curve table) to the input processor.
 * The message is four zero bytes; the command has no arguments.
 */
void ipc_reload_hdr_tone_curve(void)
{
    unsigned char msg[4] = {0, 0, 0, 0};
    ipc_send_command(IPC_CMD_RELOAD_HDR_TONE_CURVE, 4, msg, IPC_SEND_NO_WAIT);
}
