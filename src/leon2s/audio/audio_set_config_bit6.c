/* audio_set_config_bit6  (FUN_a008a1f8)
 *
 * Write 0x40 to the audio configuration register when the argument is 1.
 *   write: 1 = write
 * Name basis: descriptive - writes 0x40 to 0xCF011024 for argument 1; caller audio_configure
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008a1f8 @ 0xa008a1f8 (-mcpu=v8 -Os -g)
 * The two separate tests on the argument are the form that builds to the firmware code.
 */
#define reg_audio_config (*(volatile unsigned int *)0xcf011024)

/*
 * Write 0x40 (bit 6) to the audio configuration register 0xCF011024 when the argument is 1. Any other value
 * writes nothing. Called by audio_configure.
 */
void audio_set_config_bit6(unsigned char write)
{
    if (write == 0) {
        return;
    }
    if (write != 1) {
        return;
    }
    reg_audio_config = 0x40;
}
