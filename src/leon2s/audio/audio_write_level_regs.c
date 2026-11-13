/* audio_write_level_regs  (FUN_a008a924)
 *
 * Write a 16-bit level value to the two audio level register pairs.
 *   level: 16-bit level
 * Name basis: descriptive - 0xCF011060/64 and 0xCF011068/6C; 0x8000 is the neutral value
 *
 * Matching notes
 * --------------
 * FUN_a008a924 (leon2s, 0xa008a924-0xa008a95c, 14 words, leaf). Flags -mcpu=v8 -Os -g.
 * The argument is a full word: high is bits 8..15 (sll 16, srl 24 = (unsigned short)level >> 8).
 */
#define AUDIO_LEVEL_LOW_A  (*(volatile unsigned int *)0xcf011060)
#define AUDIO_LEVEL_HIGH_A (*(volatile unsigned int *)0xcf011064)
#define AUDIO_LEVEL_LOW_B  (*(volatile unsigned int *)0xcf011068)
#define AUDIO_LEVEL_HIGH_B (*(volatile unsigned int *)0xcf01106c)

/*
 * Write a 16-bit level to the two pairs of audio level registers: the low byte of the level to the first
 * register of each pair, bits 8..15 to the second. audio_set_output_level calls it with 0x8000, the level that
 * leaves the audio unchanged, or with the level itself.
 *   level: 16-bit level
 */
void audio_write_level_regs(unsigned int level)
{
    unsigned int low = level & 0xff;
    unsigned int high = (unsigned short)level >> 8;
    AUDIO_LEVEL_LOW_A = low;
    AUDIO_LEVEL_HIGH_A = high;
    AUDIO_LEVEL_LOW_B = low;
    AUDIO_LEVEL_HIGH_B = high;
}
