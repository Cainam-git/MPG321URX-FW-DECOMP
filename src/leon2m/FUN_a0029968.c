/* leon2m FUN_a0029968 @ 0xa0029968-0xa0029990 (10 words).
 * FUN_a0029968(n, m): sets the bits of m in the register 0x9f020034 + 4 * n through FUN_a002c268(p, m, m) (tail
 * call). m is an unsigned short.
 */
extern void FUN_a002c268(volatile unsigned int *p, unsigned int v, unsigned int mask);

void FUN_a0029968(int n, unsigned short m)
{
    FUN_a002c268((volatile unsigned int *)(0x9f020034 + n * 4), m, m);
}
