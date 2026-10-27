/* FUN_a014883c (leon2m 0xa014883c-0xa0148854, 24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns byte c * 2 of the table at 0x1a6db2 (the first byte of the two-byte entry c). Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0148834 and FUN_a0148854. Source
 * form: an unsigned char parameter indexing an extern byte array with c * 2 (add %o0, %o0).
 */
extern unsigned char DAT_001a6db2[];

unsigned char FUN_a014883c(unsigned char c)
{
    return DAT_001a6db2[c * 2];
}
