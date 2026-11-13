/* audio_check_hdmi_rate_valid  (FUN_a0091420)
 *
 * Report every 40 ticks whether an HDMI receiver's audio rate is in range.
 *   reset: non-zero = clear
 *   raw_port: HDMI 2.0 receiver
 * Returns: 1 when valid
 * Name basis: derived - audio_calc_hdmi_sample_rate within 301..1929 (about 30..193 kHz); result goes to the
 *   port status flags
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091420 @ 0xa0091420-0xa00914c4 (164 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the port is an unsigned char local. The final read goes through the static helper
 * read_flag(), called with the raw parameter, so the "and 0xff" is done again there as in the firmware.
 */
extern unsigned char audio_hdmi_rate_valid_flags[];
extern unsigned int audio_hdmi_rate_check_ticks[];
extern unsigned int timer_get_ticks(void);
extern unsigned short audio_calc_hdmi_sample_rate(unsigned int);

#define RATE_CHECK_INTERVAL 0x28        /* ticks between two checks of one receiver */
#define RATE_MIN            301         /* lowest rate counted as valid */
#define RATE_SPAN           0x65c       /* highest valid rate is RATE_MIN + RATE_SPAN = 1929 */

static unsigned char read_flag(unsigned char port)
{
    return audio_hdmi_rate_valid_flags[port];
}

/*
 * Check at most every 40 ticks whether the audio rate of an HDMI 2.0 receiver is in range, and return the
 * result of the last check.
 *   reset: non-zero = clear the result and restart the interval
 *   raw_port: receiver (only the low byte is used)
 *
 * A check sets the result to 1 when audio_calc_hdmi_sample_rate is in 301..1929, else to 0.
 * Returns 1 when the last check found the rate valid.
 */
unsigned int audio_check_hdmi_rate_valid(unsigned char reset, unsigned int raw_port)
{
    unsigned char port = raw_port;

    if (reset) {
        audio_hdmi_rate_valid_flags[port] = 0;
        audio_hdmi_rate_check_ticks[port] = timer_get_ticks();
    } else if (timer_get_ticks() - audio_hdmi_rate_check_ticks[port] > RATE_CHECK_INTERVAL) {
        audio_hdmi_rate_check_ticks[port] = timer_get_ticks();
        if ((unsigned short)(audio_calc_hdmi_sample_rate(port) - RATE_MIN) <= RATE_SPAN)
            audio_hdmi_rate_valid_flags[port] = 1;
        else
            audio_hdmi_rate_valid_flags[port] = 0;
    }
    return read_flag(raw_port);
}
