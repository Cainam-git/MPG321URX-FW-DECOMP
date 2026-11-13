/* audio_start_level_step  (FUN_a008a974)
 *
 * Arm the audio level step registers with a start value.
 *   value: step value
 * Name basis: descriptive - 0xCF011014 = 0xFF, 0xCF011048 bits 5..6, value to 0xCF011058/5C; cleared again by
 *   audio_clear_level_step
 *
 * Matching notes
 * --------------
 * FUN_a008a974 (leon2s 0xa008a974-0xa008a9b0, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
#define AUDIO_STEP_PENDING_REG (*(volatile unsigned int *)0xcf011014)
#define AUDIO_STEP_CTRL_REG    (*(volatile unsigned int *)0xcf011048)
#define AUDIO_STEP_VALUE_REG_A (*(volatile unsigned int *)0xcf011058)
#define AUDIO_STEP_VALUE_REG_B (*(volatile unsigned int *)0xcf01105c)

/*
 * Start a step of the audio level: write 0xFF to AUDIO_STEP_PENDING_REG, set bits 5 and 6 of
 * AUDIO_STEP_CTRL_REG and write the byte to both value registers. audio_clear_level_step (mailbox command
 * 0x95) writes the same four registers again, with 0, 0, 0xC6 and 0xC6. Called by audio_set_output_level.
 *   value: byte for AUDIO_STEP_VALUE_REG_A and _B
 */
void audio_start_level_step(unsigned char value)
{
    AUDIO_STEP_PENDING_REG = 0xff;
    AUDIO_STEP_CTRL_REG |= 0x60;
    AUDIO_STEP_VALUE_REG_A = value;
    AUDIO_STEP_VALUE_REG_B = value;
}
