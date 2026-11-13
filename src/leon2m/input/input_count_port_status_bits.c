/* input_count_port_status_bits  (FUN_a0129a5c)
 *
 * Return how many of the four bits of the first port status word are set.
 * Returns: 0..4
 * Name basis: descriptive - halfword at 0xA802C9FE
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129a5c @ 0xa0129a5c, flags -mcpu=v8 -O2 -g.
 */
extern unsigned short port_present_mask;

/*
 * Count the bits 0..3 that are set in port_present_mask.
 */
unsigned char input_count_port_status_bits(void)
{
    unsigned char count = 0;
    unsigned short flags = port_present_mask;

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
