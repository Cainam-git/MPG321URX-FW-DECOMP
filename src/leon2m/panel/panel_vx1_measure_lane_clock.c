/* panel_vx1_measure_lane_clock  (FUN_a0105a94)
 *
 * Measure the clock that sets the V-by-One lane speed.
 * Returns: clock value
 * Name basis: derived - panel_get_pll_frequency_mhz with the source chosen by mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105a94, flags -mcpu=v8 -O3 -g.
 * Source form (the exact build depends on all of it):
 *  - each inner arm shifts the u16 clock up by 16 into the unsigned int t, and r = t >> 16 is written once per
 *    outer arm; t is then live across blocks. The same value as a plain return, but any simpler form gives a
 *    different register assignment;
 *  - r is an unsigned short, and it is the return value.
 */
extern unsigned short panel_get_pll_frequency_mhz(unsigned char source);

/*
 * Return the measured clock that the Vx1 transmitter set-up prints as "Vx1 Lane BW = %ld".
 * The clock comes from panel_get_pll_frequency_mhz with a source number chosen by the two arguments:
 *
 *   use_register_bit  nonzero: source 4 when bit 0 of register 0xcf011a00 is set, else source 0
 *   use_second_source only when use_register_bit is 0: nonzero gives source 2, zero gives source 3
 *
 * Only caller: panel_vx1_setup_lanes, always as (1, 0).
 */
unsigned short panel_vx1_measure_lane_clock(unsigned char use_register_bit, unsigned char use_second_source)
{
    unsigned int shifted;
    unsigned short clock;

    if (use_register_bit) {
        if (*(volatile unsigned int *)0xcf011a00 & 1)
            shifted = (unsigned int)panel_get_pll_frequency_mhz(4) << 16;
        else
            shifted = (unsigned int)panel_get_pll_frequency_mhz(0) << 16;
        clock = shifted >> 16;
    } else {
        if (use_second_source)
            shifted = (unsigned int)panel_get_pll_frequency_mhz(2) << 16;
        else
            shifted = (unsigned int)panel_get_pll_frequency_mhz(3) << 16;
        clock = shifted >> 16;
    }
    return clock;
}
