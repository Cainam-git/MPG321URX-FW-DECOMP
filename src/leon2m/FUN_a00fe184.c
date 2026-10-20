/* leon2m FUN_a00fe184 @ 0xa00fe184  MATCH (-mcpu=v8 -O3 -g)
 * Reads back the field written by FUN_a00fdf74 (internal path 1): the path register is 0xCF0116E0 when the chip
 * variant FUN_a011cf88() is above 0x81, else 0xCF0116D4; of its low byte, bits 4 and 6 (0x50) are kept.
 * Returns 3 when the field is 0x40, 2 when it is 0x10, otherwise 1. No direct callers found.
 * Source form (as in the writer): the register read as an if/else of two loads into an unsigned char, then masked.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char FUN_a011cf88(void);

unsigned char FUN_a00fe184(void)
{
    unsigned char v;
    unsigned int res;

    if (FUN_a011cf88() > 0x81)
        v = R(0xcf0116e0);
    else
        v = R(0xcf0116d4);
    v &= 0x50;
    if (v == 0x40)
        res = 3;
    else if (v == 0x10)
        res = 2;
    else
        res = 1;
    return res;
}
