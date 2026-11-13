/* input_count_port_status_bits_second  (FUN_a0129af0)
 *
 * Return how many of the four bits of the second port status word are set.
 * Returns: 0..4
 * Name basis: descriptive - bits 0..3 of the halfword at 0xA802CA00
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129af0 @ 0xa0129af0, flags -mcpu=v8 -O2 -g.
 */
extern unsigned short port_present_mask_alt;

/*
 * Count the bits 0..3 that are set in port_present_mask_alt.
 */
unsigned char input_count_port_status_bits_second(void)
{
    unsigned char count = 0;
    unsigned short flags = port_present_mask_alt;

    if (flags & 1)
        count = 1;
    if (flags & 2)
        count++;
    if (flags & 8)
        count++;
    if (flags & 4)
        count++;
    return count;
}
