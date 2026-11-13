/* input_get_port_status_bit  (FUN_a0129a10)
 *
 * Return one bit of the first port status word.
 * Returns: 0 or 1
 * Name basis: descriptive - halfword at 0xA802C9FE
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129a10 @ 0xa0129a10, flags -mcpu=v8 -O2 -g.
 * Source form: the shift count has no "& 0x1f" mask, and the (int) cast makes the compiler emit an arithmetic shift.
 */
extern unsigned short port_present_mask;       /* 0xa802c9fe */

/*
 * Return bit `port` of port_present_mask (set by input_report_present_ports).
 */
int input_get_port_status_bit(int port)
{
    return ((int)port_present_mask >> port) & 1;
}
