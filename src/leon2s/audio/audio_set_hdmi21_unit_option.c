/* audio_set_hdmi21_unit_option  (FUN_a008a110)
 *
 * Set the HDMI 2.1 option bit of an audio unit.
 *   src: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 *   unit: audio unit
 *   enable: option value
 * Name basis: descriptive - sources 12/14 only: unit register 3 bit 6 and bit unit + 4 of 0xCF014770
 *
 * Matching notes
 * --------------
 * FUN_a008a110 (leon2s 0xa008a110-0xa008a1b4, 164 bytes), flags -mcpu=v8 -Os -g.
 * Source form: a switch on the source (an if/else chain masks the unit separately in each arm).
 */
#define AUDIO_SRC_HDMI21_0 0xc                  /* audio source ids of the HDMI 2.1 receivers */
#define AUDIO_SRC_HDMI21_1 0xe
#define AUDIO_UNIT_REG_3   3                    /* register 3 of an audio unit */
#define AUDIO_REG_4770 (*(volatile unsigned int *)0xcf014770)  /* bit unit + 4: one bit per audio unit */
extern void audio_reg_write_masked(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Set the HDMI 2.1 option of an audio unit. Only the HDMI 2.1 sources do anything.
 *   src:    audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 *   unit:   audio unit
 *   enable: option value
 *
 * For source 0xC or 0xE, bit 6 of the unit's register 3 gets the value of enable. When enable is non-zero,
 * bit unit + 4 of AUDIO_REG_4770 is also changed: cleared for source 0xC, set for source 0xE.
 */
void audio_set_hdmi21_unit_option(unsigned char src, unsigned char unit, unsigned char enable)
{
    switch (src) {
    case AUDIO_SRC_HDMI21_0:
        audio_reg_write_masked(unit, AUDIO_UNIT_REG_3, 0x40, enable << 6);
        if (enable)
            AUDIO_REG_4770 &= ~(1 << (unit + 4));
        break;
    case AUDIO_SRC_HDMI21_1:
        audio_reg_write_masked(unit, AUDIO_UNIT_REG_3, 0x40, enable << 6);
        if (enable)
            AUDIO_REG_4770 |= 1 << (unit + 4);
        break;
    }
}
