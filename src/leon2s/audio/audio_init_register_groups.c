/* audio_init_register_groups  (FUN_a008a590)
 *
 * Load seven fixed register groups of the audio interface block.
 * Name basis: descriptive - fixed groups at 0xCF00F680..0xCF00F6B0; caller audio_configure
 *
 * Matching notes
 * --------------
 * FUN_a008a590 (leon2s 0xa008a590-0xa008a6f4, 356 bytes), flags -mcpu=v8 -Os -g.
 * The registers are volatile (the R macro); the group writer is a static inline function.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define AUDIO_GROUP_BASE 0xcf00f680             /* the nine registers of one group: +0x00 .. +0x1c and +0x30 */

/* Write one group: three of the nine registers take the arguments, the others fixed values. */
static inline void write_group(unsigned int word_00, unsigned int word_10, unsigned int word_14)
{
    R(AUDIO_GROUP_BASE + 0x00) = word_00;
    R(AUDIO_GROUP_BASE + 0x04) = 0x20;
    R(AUDIO_GROUP_BASE + 0x08) = 0x18;
    R(AUDIO_GROUP_BASE + 0x0c) = 0xfe;
    R(AUDIO_GROUP_BASE + 0x10) = word_10;
    R(AUDIO_GROUP_BASE + 0x14) = word_14;
    R(AUDIO_GROUP_BASE + 0x18) = 0;
    R(AUDIO_GROUP_BASE + 0x1c) = 0;
    R(AUDIO_GROUP_BASE + 0x30) = 0x80;
}

/*
 * Load seven fixed groups into the audio interface registers 0xCF00F680..0xCF00F6B0. Every group writes the
 * same nine registers one after the other; the values of the registers at +0x00, +0x10 and +0x14 differ from
 * group to group, the others are the same in every group. Called by audio_configure.
 */
void audio_init_register_groups(void)
{
    write_group(8, 3, 0);
    write_group(4, 0x1f, 0x29);
    write_group(8, 0, 0);
    write_group(4, 4, 8);
    write_group(0x30, 0x13, 0);
    write_group(0x70, 0, 3);
    write_group(0, 1, 0);
}
