/* leon2m FUN_a0129ab8 @ 0xa0129ab8-0xa0129af0 (14 words), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a0129a24.
 * Code facts: leaf; one lduh of the halfword DAT_a802ca00; returns 1 if bit 0, 1 or 3 is set (btst/bne chain), else
 * (h & 4) != 0 (and 4; cmp %g0; addx). int result.
 * Source form: the flag word is an unsigned short (lduh); early 'return 1' for bits 0, 1, 3 and then for bit 2,
 * else 'return 0' (gcc turns the last test into the and/cmp/addx store-flag).
 */
extern unsigned short DAT_a802ca00;

int FUN_a0129ab8(void)
{
    if ((DAT_a802ca00 & 1) || (DAT_a802ca00 & 2) || (DAT_a802ca00 & 8))
        return 1;
    if (DAT_a802ca00 & 4)
        return 1;
    return 0;
}
