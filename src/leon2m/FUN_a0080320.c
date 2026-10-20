/* leon2m FUN_a0080320 @ 0xa0080320-0xa00803a4 (33 words).
 * Tests byte 0xa802d2af against condition c: c 0 is always true, c 1 tests for nonzero, c 2 for 4..7 and c 3 for 7;
 * other c are false. Returns 1 when the condition holds, else 0.
 */
extern unsigned char DAT_a802d2af;

unsigned char FUN_a0080320(unsigned char c)
{
    unsigned char r = 0;

    if (c == 0)
        r = 1;
    else if (c == 1) {
        if (DAT_a802d2af != 0)
            r = 1;
    } else if (c == 2) {
        if ((unsigned char)(DAT_a802d2af - 4) <= 3)
            r = 1;
    } else if (c == 3) {
        if (DAT_a802d2af == 7)
            r = 1;
    }
    return r & 1;
}
