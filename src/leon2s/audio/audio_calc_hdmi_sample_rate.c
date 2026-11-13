/* audio_calc_hdmi_sample_rate  (FUN_a0091388)
 *
 * Compute the audio sample rate of an HDMI receiver from N and CTS.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: sample rate (units of 100 Hz)
 * Name basis: proven - TMDS clock * N (reg 0x106) / CTS (reg 0x10C) * 10000 / 128 = the HDMI audio clock
 *   formula
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091388 @ 0xa0091388 (-mcpu=v8 -Os -g).
 * Source form: the clock is converted to unsigned int before the multiplication, and the result is narrowed to
 * unsigned short at the end.
 */
extern unsigned int hdmi_reg_read24(unsigned int param_1, unsigned int param_2);
extern unsigned short hdmi_get_tmds_clock(unsigned int param_1);

#define HDMI_AUDIO_N_REG   0x106        /* 20-bit N value */
#define HDMI_AUDIO_CTS_REG 0x10c        /* 20-bit CTS value */

/*
 * Compute the audio sample rate of an HDMI 2.0 receiver from its N and CTS registers.
 *   port: receiver 0 or 1
 * Returns TMDS clock * N / CTS * 10000 >> 7, or 0 when N or CTS is 0. Callers (audio_check_hdmi_rate_valid)
 * compare the result with 301..1929.
 */
unsigned short audio_calc_hdmi_sample_rate(unsigned int port)
{
    unsigned int n_value, cts_value;
    unsigned short result = 0;

    port &= 0xff;
    n_value = hdmi_reg_read24(port, HDMI_AUDIO_N_REG) & 0xfffff;
    cts_value = hdmi_reg_read24(port, HDMI_AUDIO_CTS_REG) & 0xfffff;

    if (n_value != 0 && cts_value != 0) {
        unsigned int t = hdmi_get_tmds_clock(port);
        t = ((unsigned short)t) * n_value / cts_value * 10000 >> 7;
        result = (unsigned short)t;
    }

    return result;
}
