/* input_is_sample_rate_too_high  (FUN_a00f4434)
 *
 * Return whether the line rate times a value exceeds 2,050,000.
 * Returns: 0 or 1
 * Name basis: descriptive - input_block_measure_hfreq times n; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f4434 @ 0xa00f4434, flags -mcpu=v8 -O3 -g.
 * No direct caller exists.
 */
extern unsigned short input_block_measure_hfreq(unsigned char port);

/* Return 1 when the measured line rate of the port, multiplied by n, is above 2,050,000, else 0. */
int input_is_sample_rate_too_high(unsigned char port, unsigned short n)
{
    return (unsigned int)(input_block_measure_hfreq(port) * n) > 2050000;
}
