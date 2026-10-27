/* FUN_a00f3134 (leon2m 0xa00f3134-0xa00f3164, 48 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores the four bytes of v to the words p[0], p[1], p[2], p[3] (low byte first). Called 16 times by FUN_a01129e4.
 * It lies between FUN_a00f30f0 and FUN_a00f3164. Source form: p points to volatile words (the form of FUN_a00f30c8);
 * with a plain pointer GCC reorders the stores and moves the last into the retl delay slot.
 */
void FUN_a00f3134(volatile unsigned int *p, unsigned int v)
{
    p[0] = v & 0xff;
    p[1] = (v >> 8) & 0xff;
    p[2] = (v >> 16) & 0xff;
    p[3] = v >> 24;
}
