/* audio_enable_unit_hdmi  (FUN_a008b5d0)
 *
 * Enable or disable an audio unit fed by an HDMI source.
 *   unit: audio unit
 *   enable: 1 = enable
 * Name basis: descriptive - unit register 7 bit 4 and a register 3 bit 1 pulse; HDMI counterpart of
 *   audio_enable_unit_dp
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b5d0 @ 0xa008b5d0-0xa008b694 (196 bytes), flags -mcpu=v8 -Os -g.
 * The range includes an unreachable ret/restore at 0xa008b68c.
 */
extern unsigned int audio_reg_read8(unsigned int param_1, unsigned int param_2);
extern void audio_reg_write_masked(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Enable or disable an audio unit that takes an HDMI source. Does nothing for a unit above 3.
 *   unit:   audio unit 0..3
 *   enable: 1 = enable, 0 = disable
 *
 * Disable clears bit 4 of unit register 7. Enable sets that bit when it is clear. Then, unless register 1 masked
 * with 0xE equals 2, and when register 0xF reads 0xF0, bit 1 of register 3 is cleared and set again.
 * audio_enable_unit_dp does the same with bit 2 of register 2 and a DP FIFO reset.
 */
void audio_enable_unit_hdmi(unsigned char unit, unsigned char enable)
{
    if (unit > 3)
        return;
    if (enable) {
        if (!(audio_reg_read8(unit, 7) & 0x10))
            audio_reg_write_masked(unit, 7, 0x10, 0x10);
        if ((audio_reg_read8(unit, 1) & 0xe) == 2)
            return;
        if ((unsigned char)audio_reg_read8(unit, 0xf) == 0xf0) {
            audio_reg_write_masked(unit, 3, 2, 0);
            audio_reg_write_masked(unit, 3, 2, 2);
        }
    } else {
        audio_reg_write_masked(unit, 7, 0x10, 0);
    }
}
