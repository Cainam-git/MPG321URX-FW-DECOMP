/* leon2m FUN_a010fda4 @ 0xa010fda4-0xa010fe50 (43 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 c). For register block 0xD0032000 and then 0xD003A000: c == 1 clears bit 2 of the base register and
 * sets bit 1 of base | 0x270; any other c clears bit 1 of the base register and sets bit 0 of base | 0x270.
 * Source form: one static helper blk_off(side, c) on the block chosen by a side index (B(side) = 0xD003A000 for
 * side 1, else 0xD0032000), inlined for side 0 and side 1; FUN_a010fe50 makes the same writes.
 */
#define B(s) ((s) ? 0xd003a000 : 0xd0032000)
#define R(a) (*(volatile unsigned int *)(a))

static void blk_off(int side, unsigned char ch)
{
    if (ch == 1) {
        R(B(side)) &= ~4;
        R(B(side) | 0x270) |= 2;
    } else {
        R(B(side)) &= ~2;
        R(B(side) | 0x270) |= 1;
    }
}

void FUN_a010fda4(unsigned char c)
{
    blk_off(0, c);
    blk_off(1, c);
}
