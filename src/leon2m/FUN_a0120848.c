/* leon2m FUN_a0120848 @ 0xa0120848-0xa0120998 (336 bytes). Called by FUN_a00fd9a0.
 * Uses the table of 12-byte records at 0xa8027aac. When word 4 of record 0 is 1, b becomes (b & 0xff) << 3.
 * If blk is 8, for each i = 0..7: FUN_a00f1fe0(i, 0x29, (b & 0xe0) | 4) when word 4 of record i is 1, else
 * FUN_a00f1fe0(i, 0x29, b & 0xe0); then FUN_a00f1fe0(i, 0x1b, (a << 5) | (b & 0x1e)). Otherwise the same two
 * calls are made once for block blk. FUN_a01218c8 contains the same code with blk 8, a 1 and b 4.
 * Source form: an old-style definition (blk and a unsigned char, b int): the parameters are extended at each
 * use, and the shifted b keeps its bits above bit 7 until each byte argument is formed.
 */
struct Rec12 { unsigned int w0, w4, w8; };
extern struct Rec12 DAT_a8027aac[];
extern void FUN_a00f1fe0(unsigned char blk, unsigned char reg, unsigned char val);

void FUN_a0120848(blk, a, b)
unsigned char blk, a;
int b;
{
    unsigned char i = 0;

    if (DAT_a8027aac[0].w4 == 1)
        b = (unsigned char)b << 3;
    if (blk == 8) {
        for (; i <= 7; i++) {
            if (DAT_a8027aac[i].w4 == 1)
                FUN_a00f1fe0(i, 0x29, (b & 0xe0) | 4);
            else
                FUN_a00f1fe0(i, 0x29, b & 0xe0);
            FUN_a00f1fe0(i, 0x1b, (a << 5) | (b & 0x1e));
        }
    } else {
        if (DAT_a8027aac[blk].w4 == 1)
            FUN_a00f1fe0(blk, 0x29, (b & 0xe0) | 4);
        else
            FUN_a00f1fe0(blk, 0x29, b & 0xe0);
        FUN_a00f1fe0(blk, 0x1b, (a << 5) | (b & 0x1e));
    }
}
