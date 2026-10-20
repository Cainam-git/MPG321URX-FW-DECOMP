/* leon2m FUN_a0090f30 @ 0xa0090f30-0xa0090f94 (25 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Checks the ports 0..3: returns 0 as soon as one port p has FUN_a0080320(p) != 0 and FUN_a0143c14(p) != 4,
 * otherwise 1. The result is returned as (flag & 1) (and 1 before the return).
 */
extern unsigned char FUN_a0080320(unsigned char port);
extern unsigned char FUN_a0143c14(unsigned char ch);

unsigned char FUN_a0090f30(void)
{
    unsigned char ok = 1;
    unsigned char i;

    for (i = 0; i <= 3; i++)
        if (FUN_a0080320(i) && FUN_a0143c14(i) != 4) {
            ok = 0;
            break;
        }
    return ok & 1;
}
