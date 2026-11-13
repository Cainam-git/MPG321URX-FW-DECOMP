/* audio_set_dp_unit_option  (FUN_a008a1b4)
 *
 * Set the DP option bit of an audio unit.
 *   src: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 *   unit: audio unit
 *   value: bit value
 * Name basis: descriptive - sources 4/6 only: unit register 3 bit 5
 *
 * Matching notes
 * --------------
 * FUN_a008a1b4 (leon2s 0xa008a1b4-0xa008a1f8, 17 words), flags -mcpu=v8 -Os -g.
 * Leaf sibling call. The fourth argument is masked 0xe0 by the unsigned char conversion.
 * Source form: 'switch (src) { case 4: case 6: ... }' gives the firmware's two compare-and-branch tests (the
 * '||' form becomes branch-free subx flags).
 */
#define AUDIO_SRC_DP0    4                      /* audio source ids of the DP receivers */
#define AUDIO_SRC_DP1    6
#define AUDIO_UNIT_REG_3 3                      /* register 3 of an audio unit */
extern void audio_reg_write_masked(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Set the DP option of an audio unit. Only the DP sources do anything.
 *   src:   audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 *   unit:  audio unit
 *   value: bit value
 *
 * For source 4 or 6, bit 5 of the unit's register 3 gets the low bit of value.
 */
void audio_set_dp_unit_option(unsigned char src, unsigned char unit, unsigned int value)
{
    switch (src) {
    case AUDIO_SRC_DP0:
    case AUDIO_SRC_DP1:
        audio_reg_write_masked(unit, AUDIO_UNIT_REG_3, 0x20, value << 5);
        break;
    }
}
