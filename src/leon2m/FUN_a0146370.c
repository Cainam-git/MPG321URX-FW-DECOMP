/* leon2m FUN_a0146370 @ 0xa0146370-0xa01463f8 (34 words).
 * Tail-calls FUN_a011932c(code, v, blk) with code 0xa0, 0xb0, 0xc0 or 0xc1 for sel 0, 1, 2 or 3; other sel values
 * do nothing. Called from FUN_a008a4a8, FUN_a008ce90, FUN_a008d2f8, FUN_a008ef48, FUN_a00b50d8 and others.
 */
extern void FUN_a011932c(unsigned int sel, unsigned int v, unsigned char blk);

void FUN_a0146370(unsigned char sel, unsigned int v, unsigned char blk)
{
    switch (sel) {
    case 0:
        FUN_a011932c(0xa0, v, blk);
        break;
    case 1:
        FUN_a011932c(0xb0, v, blk);
        break;
    case 2:
        FUN_a011932c(0xc0, v, blk);
        break;
    case 3:
        FUN_a011932c(0xc1, v, blk);
        break;
    }
}
