/* FUN_a011c998: writes three data bytes to the serial register port of side sel through FUN_a011b3e8: the byte a,
 * then the low and the high byte of v (data register 0xcf01178c for sel 0, 0xcf0117a0 otherwise, each write
 * followed by a 160-nop delay loop). Caller: FUN_a014648c.
 * FUN_a011b3e8 is defined here because GCC inlines it at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011b3e8(unsigned char sel, unsigned char v)
{
    int i;

    if (sel == 0)
        R(0xcf01178c) = v;
    else
        R(0xcf0117a0) = v;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

void FUN_a011c998(unsigned char a, unsigned short v, unsigned char sel)
{
    FUN_a011b3e8(sel, a);
    FUN_a011b3e8(sel, v);
    FUN_a011b3e8(sel, v >> 8);
}
