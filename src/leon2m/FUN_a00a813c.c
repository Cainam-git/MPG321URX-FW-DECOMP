/* leon2m FUN_a00a813c @ 0xa00a813c  (-mcpu=v8 -O3 -g)
 * Makes two FUN_a0146b20 calls for columns col and col + 1 at one row. row = sel * 2 + 6 for sel <= 6, else
 * sel * 2 - 8; col = 0x28 for mode 1, 0x14 for other modes, except mode 2, which uses col 0x28 and row sel * 2 + 6.
 * When on != 0 the 5th arguments are ch and ch + 1 with ch = 0x3A (mode 0) or 0x0F (other modes):
 * FUN_a0146b20(0, col, row, 1, ch, 0), FUN_a0146b20(0, col + 1, row, 1, ch + 1, 0); when on == 0 they are 0.
 * Callers: FUN_a00b77b4 (tail call) and others.
 */
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a813c(unsigned char mode, unsigned char sel, unsigned char on)
{
    unsigned char ch = (mode == 0 ? 0x3a : 0x0f);
    unsigned char row;
    unsigned char col = 0x28;

    if (sel <= 6)
        row = sel * 2 + 6;
    else
        row = sel * 2 - 8;
    if (mode != 1) {
        col = 0x14;
        if (mode == 2) {
            row = sel * 2 + 6;
            col = 0x28;
        }
    }
    if (on) {
        FUN_a0146b20(0, col, row, 1, ch, 0);
        FUN_a0146b20(0, col + 1, row, 1, ch + 1, 0);
    } else {
        FUN_a0146b20(0, col, row, 1, 0, 0);
        FUN_a0146b20(0, col + 1, row, 1, 0, 0);
    }
}
