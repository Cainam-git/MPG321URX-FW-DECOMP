/* audio_set_mute  (FUN_a008a868)
 *
 * Mute or unmute the audio outputs selected in the audio configuration.
 *   mute: 1 = mute
 * Name basis: derived - mailbox command 0x91; output 0 mute and bit 7 of the output 6/7 source registers
 *
 * Matching notes
 * --------------
 * FUN_a008a868 (leon2s 0xa008a868-0xa008a924, 188 bytes), flags -mcpu=v8 -Os -g.
 * audio_config is a byte array indexed directly and the flag byte is read again for each test. Each arm of the
 * 'mute' test has its own pair of flag tests, and the zero arm passes the constant 0.
 */
#define AUDIO_OUTPUT6_SELECT_REG (*(volatile unsigned int *)0xcf01120c)  /* select register of audio output 6 */
#define AUDIO_OUTPUT7_SELECT_REG (*(volatile unsigned int *)0xcf011218)  /* select register of audio output 7 */
#define AUDIO_CONFIG_FLAGS       2              /* audio_config[2]: output flags */
#define CFG2_OUTPUT0             1              /* bit 0: mute output 0 */
#define CFG2_OUTPUTS_6_7         2              /* bit 1: mute outputs 6 and 7 (bit 7 of their select registers) */
#define OUTPUT_SELECT_MUTE       0x80
extern unsigned char audio_config[];
extern void audio_set_output0_mute(unsigned char mute);

/*
 * Mute or unmute the audio outputs that the audio configuration names.
 *   mute: 1 = mute, 0 = unmute
 *
 * audio_config[2] (the third byte given to audio_configure) selects the outputs: bit 0 goes through
 * audio_set_output0_mute; bit 1 sets (mute) or clears (unmute) bit 7 in the select registers of outputs 6 and 7.
 * Called for mailbox command 0x91.
 */
void audio_set_mute(unsigned char mute)
{
    if (mute) {
        if (audio_config[AUDIO_CONFIG_FLAGS] & CFG2_OUTPUT0)
            audio_set_output0_mute(mute);
        if (audio_config[AUDIO_CONFIG_FLAGS] & CFG2_OUTPUTS_6_7) {
            AUDIO_OUTPUT6_SELECT_REG |= OUTPUT_SELECT_MUTE;
            AUDIO_OUTPUT7_SELECT_REG |= OUTPUT_SELECT_MUTE;
        }
    } else {
        if (audio_config[AUDIO_CONFIG_FLAGS] & CFG2_OUTPUT0)
            audio_set_output0_mute(0);
        if (audio_config[AUDIO_CONFIG_FLAGS] & CFG2_OUTPUTS_6_7) {
            AUDIO_OUTPUT6_SELECT_REG &= ~OUTPUT_SELECT_MUTE;
            AUDIO_OUTPUT7_SELECT_REG &= ~OUTPUT_SELECT_MUTE;
        }
    }
}
