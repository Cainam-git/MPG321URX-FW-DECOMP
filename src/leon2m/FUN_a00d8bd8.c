/* FUN_a00d8bd8 (leon2m, 0xa00d8bd8-0xa00d8c1c, 68 bytes, 17 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: t = FUN_a0145660(0, 1); the low 16 bits of t divided by 10 (umul 0xcccccccd / rd %y reciprocal form)
 * go to FUN_a0087458; the function returns 1 when that call returns non-zero (fw: cmp %g0,%o0 + addx = (r != 0)).
 * The two parameters are not used by the code.
 * Compiler aids: none.
 */
extern int FUN_a0087458();
extern int FUN_a0145660();

unsigned int FUN_a00d8bd8(unsigned int param_1, unsigned int param_2)
{
    unsigned int t;

    t = FUN_a0145660(0, 1);
    return (FUN_a0087458((unsigned short)t / 10) != 0);
}
