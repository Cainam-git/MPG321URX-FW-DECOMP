/* FUN_a00f3164 (leon2m 0xa00f3164-0xa00f3194, 48 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24) for the words p[0..3] (the counterpart of
 * FUN_a00f3134, which stores one byte per word). Nothing in the image refers to it. It lies between FUN_a00f3134 and
 * FUN_a00f3194. Source form: p points to volatile words, read in the order p[0], p[1], p[2], p[3] (p[0] into a local
 * first).
 */
unsigned int FUN_a00f3164(volatile unsigned int *p)
{
    unsigned int lo = p[0];

    return (p[1] << 8) | lo | (p[2] << 16) | (p[3] << 24);
}
