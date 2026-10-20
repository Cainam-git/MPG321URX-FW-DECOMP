/* leon2m FUN_a0104c34 @ 0xa0104c34-0xa0104cb0 (31 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/31.
 * What it does: returns 1 when bits 0..1 of register 0x54 of block blk (FUN_a00f2254, the 0x19a2ec-table
 * register read) are not both 0, else 0. For blk 8 (= the 'all blocks' code; FUN_a00f2254 reads block 0
 * for 8 and up) it tries up to 4 times and returns 1 at the first nonzero read.
 * Callers: GlobalModeHandler FUN_a0131518 helper chain (FUN_a0129edc, FUN_a012f43c, FUN_a0131518, FUN_a0142418).
 * Not rate-dependent; a ready/lock poll of reg 0x54.
 * Form: a plain 'for (i = 0; i < 4; i++)' loop with an early 'return 1' (u8 i); unsigned char return as the
 * caller src/leon2m/FUN_a0131518.c declares it. volatile: none. Aids: none.
 */
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
unsigned char FUN_a0104c34(unsigned char blk)
{
    unsigned char i;
    if (blk == 8) {
        for (i = 0; i < 4; i++)
            if (FUN_a00f2254(8, 0x54) & 3) return 1;
        return 0;
    }
    if (FUN_a00f2254(blk, 0x54) & 3) return 1;
    return 0;
}
