/* leon2m FUN_a00f63bc @ 0xa00f63bc-0xa00f6408 (19 words), flags -mcpu=v8 -O3 -g.
 * Leaf.
 * Code facts: when the cached byte DAT_a802b7b4 differs from p (cmp without any extension of %o0, so p is a full
 * unsigned int), the two hardware registers 0xcf00ec84 and 0xcf00e980 each get (reg & 0xfc) | p (ld / and / or / st,
 * in that order), then the cache byte is set to p (stb).
 * Written from the assembly. volatile only on the two 0xcf00xxxx hardware registers. Compiler aids: none.
 */
extern unsigned char DAT_a802b7b4;

void FUN_a00f63bc(unsigned int p)
{
    if (DAT_a802b7b4 != p) {
        *(volatile unsigned int *)0xcf00ec84 = (*(volatile unsigned int *)0xcf00ec84 & 0xfc) | p;
        *(volatile unsigned int *)0xcf00e980 = (*(volatile unsigned int *)0xcf00e980 & 0xfc) | p;
        DAT_a802b7b4 = p;
    }
}
