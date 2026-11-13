/* ipc_set_audio_unit_frequency  (FUN_a0138674)
 *
 * Ask the input processor to program the frequency word of one audio unit.
 * Name basis: derived - command 0x93 through the mailbox portal 1 sender; mailbox command 0x93, whose handler
 *   in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138674 @ 0xa0138674, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the unit and the two bytes of the frequency word.
 */
#define IPC_CMD_SET_AUDIO_UNIT_FREQUENCY 0x93   /* mailbox command 0x93 */
#define IPC_SEND_NO_WAIT                 0      /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Ask the input processor to program the frequency word of one audio unit (mailbox command 0x93).
 *
 *   unit       the audio unit
 *   frequency  the frequency word, sent low byte first
 *
 * Called from audio_unit_send_unit_value.
 */
void ipc_set_audio_unit_frequency(unsigned char unit, unsigned short frequency)
{
    unsigned char msg[4] = {unit, (unsigned char)frequency, (unsigned char)(frequency >> 8)};
    ipc_send_command(IPC_CMD_SET_AUDIO_UNIT_FREQUENCY, 4, msg, IPC_SEND_NO_WAIT);
}
