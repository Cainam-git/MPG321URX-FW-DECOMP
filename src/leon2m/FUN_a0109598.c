/* FUN_a0109598 (leon2m 0xa0109598-0xa01095bc, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when bit 'bit' of the word register 0xcf011a00 is set, otherwise 0. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a0109554 and FUN_a01095bc. Source form:
 * the masked value is kept in its own unsigned int local (and/cmp/addx).
 */
#define REG (*(volatile unsigned int *)0xcf011a00)

unsigned int FUN_a0109598(unsigned int bit)
{
    unsigned int m = REG & (1 << bit);
    return m != 0;
}
