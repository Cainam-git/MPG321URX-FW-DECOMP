/* audio_enable_unit_dp  (FUN_a008b75c)
 *
 * Enable or disable an audio unit fed by a DP source.
 *   unit: audio unit
 *   enable: 1 = enable
 * Name basis: descriptive - unit register 2 bit 2 with a DP FIFO reset; DP counterpart of
 *   audio_enable_unit_hdmi
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b75c @ 0xa008b75c-0xa008b838 (220 bytes, with the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Same source form as audio_enable_unit_hdmi.
 */
extern unsigned int audio_reg_read8(unsigned int param_1, unsigned int param_2);
extern void audio_reg_write_masked(unsigned char, unsigned short, unsigned char, unsigned char);
extern void audio_update_dp_maud_flag(unsigned char);
extern void audio_reset_dp_fifo(unsigned char);

/*
 * Enable or disable an audio unit that takes a DP source. Does nothing for a unit above 3.
 *   unit:   audio unit 0..3
 *   enable: 1 = enable, 0 = disable
 *
 * Disable clears bit 2 of unit register 2. Enable, when that bit is clear, updates the Maud flag of the DP
 * receiver, sets the bit and resets that receiver's audio FIFO; the receiver number is 0 for unit 0 and 1 for
 * units 1..3. Then, unless register 1 masked with 0xE equals 2, and when register 0xF reads 0xF0, bit 1 of
 * register 3 is cleared and set again.
 */
void audio_enable_unit_dp(unsigned char unit, unsigned char enable)
{
    if (unit > 3)
        return;
    if (enable) {
        if (!(audio_reg_read8(unit, 2) & 4)) {
            audio_update_dp_maud_flag(unit != 0);
            audio_reg_write_masked(unit, 2, 4, 4);
            audio_reset_dp_fifo(unit != 0);
        }
        if ((audio_reg_read8(unit, 1) & 0xe) == 2)
            return;
        if ((unsigned char)audio_reg_read8(unit, 0xf) == 0xf0) {
            audio_reg_write_masked(unit, 3, 2, 0);
            audio_reg_write_masked(unit, 3, 2, 2);
        }
    } else {
        audio_reg_write_masked(unit, 2, 4, 0);
    }
}
