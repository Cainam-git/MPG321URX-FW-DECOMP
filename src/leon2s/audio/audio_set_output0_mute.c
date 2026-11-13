/* audio_set_output0_mute  (FUN_a008a824)
 *
 * Mute or unmute audio output 0.
 *   mute: 1 = mute
 * Name basis: derived - bits 2..3 of 0xCF011018, the bits audio_set_output_source sets when output 0 is
 *   disabled
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008a824 @ 0xa008a824 (-mcpu=v8 -Os -g)
 * The two stores to the output control register are separate and sit where the tests put them.
 */
#define AUDIO_OUTPUT_CTRL_REG    (*(volatile unsigned int *)0xcf011018)  /* bits 2..3: mute of output 0 */
#define AUDIO_OUTPUT0_SELECT_REG (*(volatile unsigned int *)0xcf011200)  /* low nibble: source of output 0 */
#define AUDIO_OUTPUT0_MUTE_BITS  0xc
#define AUDIO_SOURCE_NIBBLE      0xf

/*
 * Mute or unmute audio output 0.
 *   mute: non-zero = set the mute bits 2..3 of 0xCF011018; zero = clear them, but only while a source is
 *         selected in the low nibble of 0xCF011200 (the select register of output 0)
 */
void audio_set_output0_mute(unsigned char mute)
{
    if (mute != 0) {
        AUDIO_OUTPUT_CTRL_REG = AUDIO_OUTPUT_CTRL_REG | AUDIO_OUTPUT0_MUTE_BITS;
    } else if ((AUDIO_OUTPUT0_SELECT_REG & AUDIO_SOURCE_NIBBLE) != 0) {
        AUDIO_OUTPUT_CTRL_REG = AUDIO_OUTPUT_CTRL_REG & 0xfffffff3;
    }
}
