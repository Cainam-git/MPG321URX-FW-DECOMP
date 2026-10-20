/* leon2m FUN_a01436b4 @ 0xa01436b4-0xa0143700 (19 words).
 * Returns c for c 0..3 and 0xff for any other c: the same check as the remap() switch that the display-channel
 * functions inline, here as a separate routine. A leaf routine without a register window.
 */
unsigned char FUN_a01436b4(unsigned char c)
{
    int r;

    switch (c) {
    case 0: r = 0; break;
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    default: r = -1; break;
    }
    return r;
}
