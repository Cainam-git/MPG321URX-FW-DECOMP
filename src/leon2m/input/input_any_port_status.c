/* input_any_port_status  (FUN_a0129a24)
 *
 * Return whether any of the four bits of the first port status word is set.
 * Returns: 0 or 1
 * Name basis: descriptive - halfword at 0xA802C9FE
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129a24 @ 0xa0129a24-0xa0129a5c (14 words), flags -mcpu=v8 -O2 -g. Twin of input_any_port_status_second.
 * Source forms the build depends on: the flag word is an unsigned short, and the last bit is masked into an int
 * local before the != 0 test ('int r = x & 4; r != 0'); an unsigned short local or a direct '(h & 4) != 0' gives
 * shift and extract code.
 */
extern unsigned short port_present_mask;

/*
 * Return 1 when any of the bits 0..3 of port_present_mask is set, else 0.
 */
int input_any_port_status(void)
{
    int any = 1;

    if ((port_present_mask & 1) == 0 && (port_present_mask & 2) == 0 && (port_present_mask & 8) == 0) {
        int bit2 = port_present_mask & 4;
        any = bit2 != 0;
    }
    return any;
}
