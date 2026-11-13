/* ipc_set_audio_mute  (FUN_a0138610)
 *
 * Ask the input processor to mute or unmute the audio outputs.
 * Name basis: derived - command 0x91 through the mailbox portal 1 sender; mailbox command 0x91, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138610 @ 0xa0138610, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the one parameter.
 */
#define IPC_CMD_SET_AUDIO_MUTE 0x91             /* mailbox command 0x91 */
#define IPC_SEND_NO_WAIT       0                /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Mute or unmute the audio outputs that the audio configuration selects, in the input processor (mailbox
 * command 0x91).
 *
 *   mute  non-zero mutes, 0 unmutes
 *
 * Called from audio_mute_outputs and audio_unmute_outputs.
 */
void ipc_set_audio_mute(unsigned char mute)
{
    unsigned char msg[4] = {mute};
    ipc_send_command(IPC_CMD_SET_AUDIO_MUTE, 4, msg, IPC_SEND_NO_WAIT);
}
