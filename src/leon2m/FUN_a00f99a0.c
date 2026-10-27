/* FUN_a00f99a0 (leon2m 0xa00f99a0-0xa00f99e8, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes (v != 0) to bit 31 of the word register 0xd0040000 and v & 0xf to bits 0..3 of the word register
 * 0xd00400d8; returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It
 * lies between FUN_a00f9994 and FUN_a00f99e8. Source form: a static field-write helper wr(reg, mask, shift, val)
 * ('*r = (*r & ~mask) | ((val << shift) & mask)') inlined; it keeps the 'and' with the sethi'd mask after the
 * shift.
 */
#define REG0 (*(volatile unsigned int *)0xd0040000)
#define REG1 (*(volatile unsigned int *)0xd00400d8)
static void wr(volatile unsigned int *r, unsigned int mask, unsigned int shift, unsigned int val)
{
    *r = (*r & ~mask) | ((val << shift) & mask);
}
int FUN_a00f99a0(unsigned int v)
{
    wr(&REG0, 0x80000000, 31, v != 0);
    wr(&REG1, 0xf, 0, v);
    return 0;
}
