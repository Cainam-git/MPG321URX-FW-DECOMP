/* ipc_clear_audio_level_steps  (FUN_a013adcc)
 *
 * Ask the input processor to clear the audio level step registers.
 * Name basis: derived - through ipc_send_command_nop_wait; mailbox command 0x95, whose handler in the input
 *   program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013adcc @ 0xa013adcc (-mcpu=v8 -O2 -g).
 */
extern int ipc_send_command_nop_wait();

#define IPC_CMD_CLEAR_AUDIO_LEVEL_STEPS 0x95    /* mailbox command 0x95 */
#define IPC_SEND_NO_WAIT                0       /* do not wait for the reply slot */

/*
 * Send mailbox command 0x95 (clear the audio level step registers) through ipc_send_command_nop_wait. The message
 * is four zero bytes; the command has no arguments.
 */
void ipc_clear_audio_level_steps(void)
{
    unsigned char msg[4] = {0, 0, 0, 0};
    ipc_send_command_nop_wait(IPC_CMD_CLEAR_AUDIO_LEVEL_STEPS, 4, msg, IPC_SEND_NO_WAIT);
}
