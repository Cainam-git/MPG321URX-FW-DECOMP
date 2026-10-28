/* FUN_a006182c (leon2s 0xa006182c-0xa0061864, 56 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Rounds a up to a multiple of b: returns a when b is 0 or a is a multiple of b, else (a / b) * b + b.
 * Nothing in the image calls it; it follows FUN_a00617f0 (division rounded up) in the image.
 * Source form: the quotient is computed first, the test is 'a % b == 0' (GCC reuses the quotient for it).
 */
unsigned int FUN_a006182c(unsigned int a, unsigned int b)
{
    unsigned int q;

    if (b == 0)
        return a;
    q = a / b;
    if (a % b == 0)
        return a;
    return q * b + b;
}
