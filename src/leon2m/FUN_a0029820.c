/* leon2m FUN_a0029820 @ 0xa0029820-0xa0029858 (14 words).
 * FUN_a0029820(n, m): clears the bits of m in the register 0x9f020034 + 4 * n through FUN_a002c268(p, 0, m), then
 * writes m to the register 0x9f02006c + 4 * n with FUN_a002c25c (tail call). m is an unsigned short.
 * The next function, FUN_a0029858, contains two inlined copies of this body.
 */
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern void FUN_a002c268(volatile unsigned int *p, unsigned int v, unsigned int mask);

void FUN_a0029820(int n, unsigned short m)
{
    FUN_a002c268((volatile unsigned int *)(0x9f020034 + n * 4), 0, m);
    FUN_a002c25c(0x9f02006c + n * 4, m);
}
