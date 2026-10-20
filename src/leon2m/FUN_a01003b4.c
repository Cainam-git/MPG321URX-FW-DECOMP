/* leon2m FUN_a01003b4 @ 0xa01003b4-0xa0100434 (32 words).
 * Reads register 4 of block blk with FUN_a00f1a90. When its bits 0-1 are both set, writes it back through
 * FUN_a00f1ad4 with bits 2-3 replaced by sel (value (v & ~0xc) | sel << 2, truncated to a byte), then calls
 * FUN_a00f1b5c(blk, 0x16, 0x50, 1) when sel is non-zero and FUN_a00f1b5c(blk, 0x16, 0x50, 0) when it is zero.
 * Called from FUN_a0142fcc.
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

void FUN_a01003b4(unsigned char blk, unsigned char sel)
{
    unsigned char v = FUN_a00f1a90(blk, 4);

    if ((v & 3) == 3) {
        FUN_a00f1ad4(blk, 4, (v & ~0xc) | (sel << 2));
        if (sel != 0)
            FUN_a00f1b5c(blk, 0x16, 0x50, 1);
        else
            FUN_a00f1b5c(blk, 0x16, 0x50, 0);
    }
}
