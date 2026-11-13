/* audio_update_dp_maud_flag  (FUN_a008b694)
 *
 * Set a DP receiver audio flag when the Maud low byte is far from 0x80.
 *   port: DP receiver 0/1
 * Name basis: descriptive - |reg 0x63 - 0x80| > 15 sets bit 5 of reg 0x60 (reg 0x63 = Maud, see
 *   audio_calc_dp_sample_rate)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b694 @ 0xa008b694 (-mcpu=v8 -Os -g).
 * Source form: the distance is stored in an unsigned char before the compare.
 */
extern int abs(int);
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Set or clear bit 5 of DP receiver register 0x60 from the low byte of the audio M value (register 0x63).
 *   port: DP receiver 0 or 1
 * The bit is cleared when the byte is within 15 of 0x80, and set otherwise.
 * Called by audio_enable_unit_dp.
 */
void audio_update_dp_maud_flag(unsigned char port)
{
    int distance;
    unsigned char abs_distance;

    distance = (unsigned char)dp_reg_read8(port, 0x63) - 0x80;
    abs_distance = abs(distance);
    if (abs_distance <= 0xf)
        dp_reg_update_bits(port, 0x60, 0x20, 0);
    else
        dp_reg_update_bits(port, 0x60, 0x20, 1);
}
