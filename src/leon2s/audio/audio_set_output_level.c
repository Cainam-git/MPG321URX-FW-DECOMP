/* audio_set_output_level  (FUN_a008aa18)
 *
 * Apply a 16-bit level to the main audio output for its current source.
 *   level: 16-bit level
 * Name basis: descriptive - mailbox command 0x94 sub 0; DP sources get the value at the receiver, others at
 *   the output registers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008aa18 @ 0xa008aa18-0xa008aab0 (152 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the source test for 4..7 is a static helper with one early return per value. GCC inlines it and
 * keeps the four compares (an || chain or a switch is folded into one range test).
 */
extern void audio_start_level_step(unsigned char v);
extern unsigned char audio_get_output_source(unsigned char p);
extern void audio_write_level_regs(unsigned int v);
extern void audio_write_level_high_byte(unsigned char v);
extern void audio_set_dp_rx_level(unsigned char port, unsigned short level);

#define MAIN_AUDIO_OUTPUT   0           /* audio output whose source is looked up */
#define AUDIO_STEP_START    0x44        /* value given to audio_start_level_step */
#define AUDIO_LEVEL_NEUTRAL 0x8000      /* the level that leaves the audio unchanged */
#define AUDIO_SRC_1         1
#define AUDIO_SRC_DP0       4
#define AUDIO_SRC_5         5
#define AUDIO_SRC_DP1       6
#define AUDIO_SRC_7         7

/* Sources 4 to 7: the DP source ids and the ids between them. */
static int is_dp_group_source(unsigned char source)
{
    if (source == AUDIO_SRC_DP0)
        return 1;
    if (source == AUDIO_SRC_5)
        return 1;
    if (source == AUDIO_SRC_DP1)
        return 1;
    if (source == AUDIO_SRC_7)
        return 1;
    return 0;
}

/*
 * Set the level of the main audio output (mailbox command 0x94, sub 0).
 *   level: 16-bit level
 *
 * Starts the level step, then looks at the source routed to output 0. For a source in 4..7 the level registers
 * get the neutral value and the level goes to both DP receivers. For source 1 the registers get the neutral
 * value and the high byte of the level goes to audio_write_level_high_byte. Any other source gets the level in
 * the level registers.
 */
void audio_set_output_level(unsigned short level)
{
    unsigned char source;

    audio_start_level_step(AUDIO_STEP_START);
    source = audio_get_output_source(MAIN_AUDIO_OUTPUT);
    if (is_dp_group_source(source)) {
        audio_write_level_regs(AUDIO_LEVEL_NEUTRAL);
        audio_set_dp_rx_level(0, level);
        audio_set_dp_rx_level(1, level);
    } else if (source == AUDIO_SRC_1) {
        audio_write_level_regs(AUDIO_LEVEL_NEUTRAL);
        audio_write_level_high_byte(level >> 8);
    } else {
        audio_write_level_regs(level);
    }
}
