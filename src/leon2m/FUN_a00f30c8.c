/* FUN_a00f30c8 (leon2m 0xa00f30c8-0xa00f30f0, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores the low three bytes of v to p[0], p[1] and p[2] (one byte per word, low byte first). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00f30a8 and FUN_a00f30f0.
 * Source form: p points to volatile words; with a plain pointer GCC reorders the stores and moves the last into the
 * retl delay slot.
 */
void FUN_a00f30c8(volatile unsigned int *p, unsigned int v)
{
    p[0] = v & 0xff;
    p[1] = (v >> 8) & 0xff;
    p[2] = (v >> 16) & 0xff;
}
