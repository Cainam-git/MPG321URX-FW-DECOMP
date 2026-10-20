/* FUN_a011b034: programs two 10-bit/8-bit register groups in block blk of the second register family (register n
 * at 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk], byte writes that treat blk > 1 as 0).
 * a != 0: base + 0xc8 = low byte of a with bit 7 set, base + 0xd8 = (a >> 7) & 7, base + 0xc9 = low byte of b,
 * base + 0xd9 = (b >> 8) & 3; a == 0: those four registers are written 0. Then the same for c and d with
 * registers 0xca / 0xda ((c >> 7) & 1) / 0xcb / 0xdb. Caller: FUN_a0146648.
 * Exact form: the non-zero arm first in both ifs; bit 7 is ORed as the char constant (char)0x80 (the firmware
 * ORs -128 before the byte truncation); the byte write helper is inlined.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

static void wr8(unsigned char blk, unsigned char reg, unsigned char v)
{
    if (blk > 1) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

void FUN_a011b034(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned char blk)
{
    if (a != 0) {
        wr8(blk, 0xc8, a | (char)0x80);
        wr8(blk, 0xd8, (a >> 7) & 7);
        wr8(blk, 0xc9, b);
        wr8(blk, 0xd9, (b >> 8) & 3);
    } else {
        wr8(blk, 0xc8, 0);
        wr8(blk, 0xd8, 0);
        wr8(blk, 0xc9, 0);
        wr8(blk, 0xd9, 0);
    }
    if (c != 0) {
        wr8(blk, 0xca, c | (char)0x80);
        wr8(blk, 0xda, (c >> 7) & 1);
        wr8(blk, 0xcb, d);
        wr8(blk, 0xdb, (d >> 8) & 3);
    } else {
        wr8(blk, 0xca, 0);
        wr8(blk, 0xda, 0);
        wr8(blk, 0xcb, 0);
        wr8(blk, 0xdb, 0);
    }
}
