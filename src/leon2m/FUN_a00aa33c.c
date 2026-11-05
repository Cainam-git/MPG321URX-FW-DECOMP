/* leon2m FUN_a00aa33c @ 0xa00aa33c-0xa00aa4c0 (97 words), flags -mcpu=v8 -O3 -g.
 * row = (sel % 7) * 2 + 6. For sel 5..8 a flag on = bit 22 (sel 5) or bit 20 (sel 6) of word _DAT_a802d33c, bit 7
 * of word _DAT_a802d47c (sel 7) or bit 30 of word _DAT_a802d484 (sel 8); v = 0x742 (mode 1) or 0x792 (other
 * modes) when on is 1, 0x200 less otherwise; FUN_a00b32e4(1, 1, v, 0x22, row, 3, k) with k = 0x37 for v 0x742
 * and 0x792, else 0x34; then FUN_a00a9468(1, 3) and FUN_a00b34d4(0, 2). Any other sel: FUN_a00a9468(1, 2), then
 * FUN_a00b34d4(0, 1).
 * Callers: FUN_a0092bb4, FUN_a0092c58 (two calls), FUN_a0092d80 (two calls).
 * Source form: the FUN_a00b32e4 call written once per k value in an if/else on the v test (the two calls are
 * merged by cross-jumping into one call after a branch that selects k).
 */
extern unsigned int _DAT_a802d33c;
extern unsigned int _DAT_a802d47c;
extern unsigned int _DAT_a802d484;
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a00aa33c(unsigned char sel, unsigned char mode)
{
    unsigned char row;
    unsigned char on = 0xff;
    unsigned short v;

    row = (sel % 7) * 2 + 6;
    if (sel == 5) {
        on = 1;
        if (!(_DAT_a802d33c & 0x400000))
            on = 0;
    } else if (sel == 6) {
        on = 1;
        if (!(_DAT_a802d33c & 0x100000))
            on = 0;
    } else if (sel == 7) {
        on = 1;
        if (!(_DAT_a802d47c & 0x80))
            on = 0;
    } else if (sel == 8) {
        on = (_DAT_a802d484 >> 30) & 1;
    }
    if (sel >= 5 && sel <= 8) {
        if (mode == 1)
            v = on == 1 ? 0x742 : 0x542;
        else
            v = on == 1 ? 0x792 : 0x592;
        if (v == 0x742 || v == 0x792)
            FUN_a00b32e4(1, 1, v, 0x22, row, 3, 0x37);
        else
            FUN_a00b32e4(1, 1, v, 0x22, row, 3, 0x34);
        FUN_a00a9468(1, 3);
        FUN_a00b34d4(0, 2);
    } else {
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    }
}
