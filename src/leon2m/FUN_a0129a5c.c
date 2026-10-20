/* leon2m FUN_a0129a5c @ 0xa0129a5c (-mcpu=v8 -O2 -g)
 * Returns the number of bits set among bits 0..3 of the halfword at 0xa802c9fe. The tests run in the target's
 * order (1, 2, 8, 4); the first test assigns 1 instead of incrementing, which gives the target's be with clr %o0
 * in the delay slot followed by mov 1, %o0.
 */
extern unsigned short _DAT_a802c9fe;

unsigned char FUN_a0129a5c(void)
{
    unsigned char result = 0;
    unsigned short flags = _DAT_a802c9fe;

    if (flags & 1)
        result = 1;
    if (flags & 2)
        result++;
    if (flags & 8)
        result++;
    if (flags & 4)
        result++;
    return result;
}
