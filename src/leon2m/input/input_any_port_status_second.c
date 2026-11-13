/* input_any_port_status_second  (FUN_a0129ab8)
 *
 * Return whether any of the four bits of the second port status word is set.
 * Returns: 0 or 1
 * Name basis: descriptive - halfword at 0xA802CA00
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129ab8 @ 0xa0129ab8, flags -mcpu=v8 -O2 -g. Twin of input_any_port_status.
 */
extern unsigned short port_present_mask_alt;

/*
 * Return 1 when any of the bits 0..3 of port_present_mask_alt is set, else 0.
 */
int input_any_port_status_second(void)
{
    if ((port_present_mask_alt & 1) || (port_present_mask_alt & 2) || (port_present_mask_alt & 8))
        return 1;
    if (port_present_mask_alt & 4)
        return 1;
    return 0;
}
