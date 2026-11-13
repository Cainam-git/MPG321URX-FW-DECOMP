/* audio_reset_output_regs  (FUN_a008a7bc)
 *
 * Reset seven audio output registers to 0x88.
 * Name basis: descriptive - writes 0 then 0x88 to 0xCF01125C..0xCF011274
 *
 * Matching notes
 * --------------
 * FUN_a008a7bc (leon2s 0xa008a7bc-0xa008a824, 104 bytes), flags -mcpu=v8 -Os -g.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define AUDIO_OUTPUT_REGS_FIRST 0xcf01125c      /* seven registers, one word apart, up to 0xcf011274 */
#define AUDIO_OUTPUT_REG_RESET  0x88

/*
 * Write 0 and then 0x88 to each of the seven audio output registers 0xCF01125C..0xCF011274 (all seven get 0
 * first, then all seven get 0x88, in ascending order both times). Called by audio_configure.
 */
void audio_reset_output_regs(void)
{
    R(AUDIO_OUTPUT_REGS_FIRST + 0x00) = 0;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x04) = 0;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x08) = 0;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x0c) = 0;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x10) = 0;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x14) = 0;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x18) = 0;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x00) = AUDIO_OUTPUT_REG_RESET;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x04) = AUDIO_OUTPUT_REG_RESET;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x08) = AUDIO_OUTPUT_REG_RESET;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x0c) = AUDIO_OUTPUT_REG_RESET;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x10) = AUDIO_OUTPUT_REG_RESET;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x14) = AUDIO_OUTPUT_REG_RESET;
    R(AUDIO_OUTPUT_REGS_FIRST + 0x18) = AUDIO_OUTPUT_REG_RESET;
}
