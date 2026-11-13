/* input_user_has_rate_mode  (FUN_a00d8bd8)
 *
 * Return 1 when pq_select_rate_mode gives a mode other than 0 for channel 0's refresh rate.
 * Returns: 0 or 1
 * Note: Reads timing field 1 (refresh rate in tenths of Hz) and passes it divided by 10. Its two parameters
 *   are not used.
 * Name basis: derived - input_api_get_timing_field(0, 1) / 10 handed to pq_select_rate_mode; result != 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8bd8 @ 0xa00d8bd8, flags -mcpu=v8 -O3 -g.
 * Source form: the two parameters and the K&R style declarations are kept; the result is the comparison itself.
 */

#define TIMING_REFRESH_RATE 1                   /* measured refresh rate in tenths of a hertz */

extern int pq_select_rate_mode();
extern int input_api_get_timing_field();

/*
 * Return 1 when pq_select_rate_mode gives a result other than 0 for the refresh rate of channel 0 in
 * whole hertz (tenths / 10), else 0. The parameters are not used.
 */
unsigned int input_user_has_rate_mode(unsigned int param_1, unsigned int param_2)
{
    unsigned int refresh_rate;

    refresh_rate = input_api_get_timing_field(0, TIMING_REFRESH_RATE);
    return (pq_select_rate_mode((unsigned short)refresh_rate / 10) != 0);
}
