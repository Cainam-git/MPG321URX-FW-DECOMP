/* input_user_get_rounded_refresh_rate  (FUN_a00d8b38)
 *
 * Return the incoming refresh rate rounded, snapped to 120, 144, 180 or 240 when close.
 * Returns: rate
 * Name basis: proven - from the measured rate; used by the on-screen refresh rate display
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8b38 @ 0xa00d8b38, flags -mcpu=v8 -O3 -g.
 */

/* Field of the measured input timing (input_api_get_timing_field). */
enum {
    TIMING_PORT_RATE = 2                        /* halfword +0x20 of the port record of the channel */
};

extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);

/*
 * Return the refresh rate of channel 0 in whole hertz. The value read (timing field 2) is in tenths of a
 * hertz. It is rounded to the nearest hertz, except that 120.3 to 120.7 Hz gives 120 and rates that round
 * to 144 +-1, 180 +-1 or 240 +-1 give exactly 144, 180 or 240.
 */
unsigned short input_user_get_rounded_refresh_rate(void)
{
    unsigned short tenths = input_api_get_timing_field(0, TIMING_PORT_RATE);
    unsigned short hertz;

    if (tenths >= 1203 && tenths <= 1207)
        return 120;
    hertz = (tenths + 5) / 10;
    if (hertz >= 143 && hertz <= 145)
        return 144;
    if (hertz >= 179 && hertz <= 181)
        return 180;
    if (hertz >= 239 && hertz <= 241)
        return 240;
    return hertz;
}
