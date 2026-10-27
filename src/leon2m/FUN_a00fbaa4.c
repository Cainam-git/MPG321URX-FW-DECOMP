/* FUN_a00fbaa4 (leon2m 0xa00fbaa4-0xa00fbaf8, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When c is non-zero, saves bit 31 of the word register 0xd0040000 to the byte DAT_a802b7e8 and clears it;
 * otherwise writes DAT_a802b7e8 back to bit 31. Returns 1. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a00fb9ec and FUN_a00fbaf8. Source form: a static
 * field-write helper wr(reg, mask, shift, val) ('*r = (*r & ~mask) | ((val << shift) & mask)') inlined; it keeps
 * the 'and' with the sethi'd mask after the shift.
 */
#define REG0 (*(volatile unsigned int *)0xd0040000)
extern unsigned char DAT_a802b7e8;
static void wr(volatile unsigned int *r, unsigned int mask, unsigned int shift, unsigned int val)
{
    *r = (*r & ~mask) | ((val << shift) & mask);
}
int FUN_a00fbaa4(unsigned char c)
{
    if (c) {
        unsigned int v = REG0;
        DAT_a802b7e8 = v >> 31;
        REG0 = v & ~0x80000000u;
    } else
        wr(&REG0, 0x80000000, 31, DAT_a802b7e8);
    return 1;
}
