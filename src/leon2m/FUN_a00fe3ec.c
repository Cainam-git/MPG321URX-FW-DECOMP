/* leon2m FUN_a00fe3ec @ 0xa00fe3ec  MATCH (-mcpu=v8 -O3 -g)
 * Reads back the field written by FUN_a00fe1dc (internal path 2): the path register is 0xCF0116E0 when the chip
 * variant FUN_a011cf88() is above 0x81, else 0xCF0116D4; of its low byte, bits 3 and 5 (0x28) are kept.
 * Returns 3 when the field is 0x20, 2 when it is 0x08, otherwise 1. No direct callers found.
 * Source form (as in the writer): the register read as an if/else of two loads into an unsigned char, then masked.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char FUN_a011cf88(void);

unsigned char FUN_a00fe3ec(void)
{
    unsigned char v;
    unsigned int res;

    if (FUN_a011cf88() > 0x81)
        v = R(0xcf0116e0);
    else
        v = R(0xcf0116d4);
    v &= 0x28;
    if (v == 0x20)
        res = 3;
    else if (v == 0x08)
        res = 2;
    else
        res = 1;
    return res;
}
