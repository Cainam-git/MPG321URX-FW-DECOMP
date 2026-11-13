/* ipc_set_audio_level  (FUN_a01386ac)
 *
 * Ask the input processor to set a 16-bit audio level (0x8000 = neutral).
 * Name basis: derived - command 0x94 through the mailbox portal 1 sender; mailbox command 0x94, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01386ac @ 0xa01386ac, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the selector and the two bytes of the level.
 */
#define IPC_CMD_SET_AUDIO_LEVEL 0x94            /* mailbox command 0x94 */
#define IPC_SEND_NO_WAIT        0               /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to set a 16-bit audio level (mailbox command 0x94); 0x8000 is the neutral level.
 *
 *   which  0 = the main output, 1 = all receivers (the input processor ignores other values)
 *   level  the level, sent low byte first
 *
 * Called from audio_api_set_level_percent and audio_api_set_level.
 */
void ipc_set_audio_level(unsigned char which, unsigned short level)
{
    unsigned char msg[4] = {which, (unsigned char)level, (unsigned char)(level >> 8)};
    ipc_send_command(IPC_CMD_SET_AUDIO_LEVEL, 4, msg, IPC_SEND_NO_WAIT);
}
