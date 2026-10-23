/* FUN_a00617f0 (leon2s 0xa00617f0-0xa006182c, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Unsigned division rounded up: returns a when b is 0, else a / b, plus 1 when a is not a multiple of b.
 * Nothing in the image calls it. Source form: the quotient test is written 'if (a == q * b) return q; return q +
 * 1;' (a q++ form gives a branch-free subx sequence).
 */
unsigned int FUN_a00617f0(unsigned int a, unsigned int b)
{
    unsigned int q;

    if (b == 0)
        return a;
    q = a / b;
    if (a == q * b)
        return q;
    return q + 1;
}
