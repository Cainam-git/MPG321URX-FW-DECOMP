/* leon2m FUN_a00f8e44 @ 0xa00f8e44 (-mcpu=v8 -O3 -g)
 * For blocks 6 and 7 the value v is incremented when FUN_a00f1a90(blk, 3) & 0x30 is 0, FUN_a00f1a90(blk, 4) & 0xf is
 * below 2 and bit 0 of FUN_a00f1a90(blk, 0x5c) is clear (tested in that order). Then FUN_a00f1d48(blk, 0xe,
 * DAT_a802b7d8[blk] + v) and FUN_a00f1d48(blk, 0xc, v) (tail call).
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1d48(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short DAT_a802b7d8[];

void FUN_a00f8e44(unsigned char blk, unsigned short v)
{
    if ((unsigned char)(blk - 6) <= 1) {
        if ((FUN_a00f1a90(blk, 3) & 0x30) == 0) {
            if ((FUN_a00f1a90(blk, 4) & 0xf) < 2) {
                if ((FUN_a00f1a90(blk, 0x5c) & 1) == 0)
                    v = v + 1;
            }
        }
    }
    FUN_a00f1d48(blk, 0xe, DAT_a802b7d8[blk] + v);
    FUN_a00f1d48(blk, 0xc, v);
}
