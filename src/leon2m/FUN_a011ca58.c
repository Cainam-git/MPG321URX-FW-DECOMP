/* FUN_a011ca58: writes the low and then the high byte of v to the serial register port of side sel through
 * FUN_a011b3e8 (data register 0xcf01178c for sel 0, 0xcf0117a0 otherwise, each write followed by a 160-nop
 * delay loop). Caller: FUN_a014648c.
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

void FUN_a011ca58(unsigned short v, unsigned char sel)
{
    FUN_a011b3e8(sel, v);
    FUN_a011b3e8(sel, v >> 8);
}
