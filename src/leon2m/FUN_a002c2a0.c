/* FUN_a002c2a0 (leon2m 0xa002c2a0-0xa002c2d4, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Replaces byte (a & 3) of the aligned word at a & ~3: clears the bits 0xff << ((a & 3) * 8) and ors in v << ((a &
 * 3) * 8). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a002c284 and FUN_a002c2d4. Source form: p is a volatile word pointer, so the store stays out of the retl
 * delay slot.
 */
void FUN_a002c2a0(unsigned int a, unsigned char v)
{
    unsigned int s = (a & 3) << 3;
    volatile unsigned int *p = (volatile unsigned int *)(a & ~3u);

    *p = (*p & ~(0xff << s)) | (v << s);
}
