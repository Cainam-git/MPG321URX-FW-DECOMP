/* leon2m FUN_a0129af0 @ 0xa0129af0 (-mcpu=v8 -O2 -g)
 * Twin of FUN_a0129a5c: same code, other constants.
 */
extern unsigned short _DAT_a802ca00;

unsigned char FUN_a0129af0(void)
{
    unsigned char result = 0;
    unsigned short flags = _DAT_a802ca00;

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
