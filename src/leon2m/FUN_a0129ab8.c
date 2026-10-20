/* leon2m FUN_a0129ab8 @ 0xa0129ab8-0xa0129af0 (14 words), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a0129a24.
 * Code facts: leaf; one lduh of the halfword DAT_a802ca00; returns 1 if bit 0, 1 or 3 is set (btst/bne
 * chain), else (h & 4) != 0 (and 4; cmp %g0; addx). int result.
 * Fixes vs the autoc draft (50.00): the flag word is an unsigned short (lduh), and the last bit is
 * masked into an int local before the != 0 test (the 'int r = x & 2; r != 0' form); a u16 local
 * or a direct '(h & 4) != 0' gives sll/srl + a bit extract. Aids: none.
 */
extern unsigned short DAT_a802ca00;

int FUN_a0129ab8(void)
{
    int r = 1;

    if ((DAT_a802ca00 & 1) == 0 && (DAT_a802ca00 & 2) == 0 && (DAT_a802ca00 & 8) == 0) {
        int m = DAT_a802ca00 & 4;
        r = m != 0;
    }
    return r;
}
