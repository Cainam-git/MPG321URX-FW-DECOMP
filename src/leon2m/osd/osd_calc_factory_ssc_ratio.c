/* osd_calc_factory_ssc_ratio  (FUN_a008b58c)
 *
 * Return the spread-spectrum ratio value in hundredths of a percent from the two SSC bytes.
 * Returns: ratio x 100
 * Note: Unused; osd_draw_factory_ssc_ratio computes the same value inline.
 * Name basis: descriptive - same formula as osd_draw_factory_ssc_ratio; nothing refers to it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008b58c, flags -mcpu=v8 -O3 -g.
 * (84 bytes, leaf). Nothing in the image refers to it. Source form: an unsigned short result variable set in
 * each arm.
 */

extern unsigned char osd_factory_ssc_ratio, osd_factory_ssc_freq;

/*
 * Shift the constant 0x4E by the factory menu's SSC ratio setting (right by 4 - ratio below 4, left by
 * ratio - 4 from 4 up), then right by the SSC frequency setting, and return the result. Nothing calls this
 * routine.
 */
unsigned short osd_calc_factory_ssc_ratio(void)
{
    unsigned short result;

    if (osd_factory_ssc_ratio < 4)
        result = (0x4e >> (4 - osd_factory_ssc_ratio)) >> osd_factory_ssc_freq;
    else
        result = (0x4e << (osd_factory_ssc_ratio - 4)) >> osd_factory_ssc_freq;
    return result;
}
