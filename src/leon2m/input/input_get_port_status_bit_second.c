/* input_get_port_status_bit_second  (FUN_a0129aa4)
 *
 * Return one bit of the second port status word.
 * Returns: 0 or 1
 * Name basis: descriptive - halfword at 0xA802CA00
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129aa4 @ 0xa0129aa4, flags -mcpu=v8 -O2 -g.
 */
extern unsigned short port_present_mask_alt;       /* 0xa802ca00 */

/*
 * Return bit `port` of port_present_mask_alt (set by input_update_present_ports_alt).
 */
int input_get_port_status_bit_second(int port)
{
    return (int)port_present_mask_alt >> port & 1;
}
