/* leon2m FUN_a012f134 @ 0xa012f134
 * Returns 1 when bit 4 (0x10) of the argument is set, else 0. Called by FUN_a014c118 and FUN_a014e320.
 * Source form: an unsigned char result set to 0, then to 1 by an if, and returned as r & 1 (the firmware keeps
 * the and 1 in the return delay slot).
 */
unsigned char FUN_a012f134(unsigned int v)
{
    unsigned char r;

    r = 0;
    if (v & 0x10)
        r = 1;
    return r & 1;
}
