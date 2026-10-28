/* leon2m FUN_a0146c40 @ 0xa0146c40-0xa0146dc0 (96 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * switch (ch) over 0..7 (jump table at 0x000e3360): on != 0 -> FUN_a011a1b0(ch, blk), otherwise
 * FUN_a011a378(ch, blk) (tail calls). Other ch: on != 0 -> FUN_a011a1b0(0..7, blk) in turn, otherwise
 * FUN_a011a378(8, blk). Parameter names follow the callees' definitions (bit, blk).
 * Both callees take two arguments; blk is masked once in each case block before the on test.
 */
extern void FUN_a011a1b0(unsigned int, unsigned char);
extern void FUN_a011a378(unsigned int, unsigned char);

void FUN_a0146c40(unsigned char ch, unsigned char on, unsigned char blk)
{
    switch (ch) {
    case 0:
        if (on)
            FUN_a011a1b0(0, blk);
        else
            FUN_a011a378(0, blk);
        break;
    case 1:
        if (on)
            FUN_a011a1b0(1, blk);
        else
            FUN_a011a378(1, blk);
        break;
    case 2:
        if (on)
            FUN_a011a1b0(2, blk);
        else
            FUN_a011a378(2, blk);
        break;
    case 3:
        if (on)
            FUN_a011a1b0(3, blk);
        else
            FUN_a011a378(3, blk);
        break;
    case 4:
        if (on)
            FUN_a011a1b0(4, blk);
        else
            FUN_a011a378(4, blk);
        break;
    case 5:
        if (on)
            FUN_a011a1b0(5, blk);
        else
            FUN_a011a378(5, blk);
        break;
    case 6:
        if (on)
            FUN_a011a1b0(6, blk);
        else
            FUN_a011a378(6, blk);
        break;
    case 7:
        if (on)
            FUN_a011a1b0(7, blk);
        else
            FUN_a011a378(7, blk);
        break;
    default:
        if (on) {
            FUN_a011a1b0(0, blk);
            FUN_a011a1b0(1, blk);
            FUN_a011a1b0(2, blk);
            FUN_a011a1b0(3, blk);
            FUN_a011a1b0(4, blk);
            FUN_a011a1b0(5, blk);
            FUN_a011a1b0(6, blk);
            FUN_a011a1b0(7, blk);
        } else
            FUN_a011a378(8, blk);
        break;
    }
}
