/* FUN_a00a6110 (leon2s 0xa00a6110-0xa00a6190, 128 bytes, leaf), flags -mcpu=v8 -Os -g.
 * r = register block at word 1 (+4) of the 12-byte record port of DAT_a807dc04 (volatile MMIO, read again for
 * each use). Returns 1 when the upper halfword of r[3] is 0; otherwise the quotient (upper halfword of r[2]) /
 * (upper halfword of r[3]) as a byte, or 1 when that byte is 0. One result variable (single exit).
 */
struct rec12 { unsigned int a; volatile unsigned int *regs; unsigned int c; };
extern struct rec12 DAT_a807dc04[];

unsigned char FUN_a00a6110(unsigned char port)
{
    volatile unsigned int *r = DAT_a807dc04[port].regs;
    unsigned char q = 1;

    if (((r[3] >> 16) & 0xffff) != 0) {
        q = ((r[2] >> 16) & 0xffff) / ((r[3] >> 16) & 0xffff);
        if (q == 0)
            q = 1;
    }
    return q;
}
