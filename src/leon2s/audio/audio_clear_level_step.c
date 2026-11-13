/* audio_clear_level_step  (FUN_a008a9b0)
 *
 * Clear the audio level step registers when a step is pending.
 * Name basis: descriptive - mailbox command 0x95; same registers as audio_start_level_step
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008a9b0 @ 0xa008a9b0-0xa008a9ec (60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The register accesses are volatile word accesses to fixed addresses, as the macros below.
 */
/* Registers of the audio level step. audio_start_level_step writes 0xFF to the first one, sets bits 5 and 6 of
   the second and writes its argument to the last two. */
#define AUDIO_STEP_PENDING_REG (*(volatile unsigned int *)0xcf011014)
#define AUDIO_STEP_CTRL_REG    (*(volatile unsigned int *)0xcf011048)
#define AUDIO_STEP_VALUE_REG_A (*(volatile unsigned int *)0xcf011058)
#define AUDIO_STEP_VALUE_REG_B (*(volatile unsigned int *)0xcf01105c)

/*
 * Clear the audio level step registers, but only when the first one is non-zero.
 *
 * The first two registers get 0; the two value registers get 0xC6 (what the value means is not shown).
 * Called for mailbox command 0x95.
 */
void audio_clear_level_step(void)
{
    if (AUDIO_STEP_PENDING_REG != 0) {
        AUDIO_STEP_PENDING_REG = 0;
        AUDIO_STEP_CTRL_REG = 0;
        AUDIO_STEP_VALUE_REG_A = 0xc6;
        AUDIO_STEP_VALUE_REG_B = 0xc6;
    }
}
