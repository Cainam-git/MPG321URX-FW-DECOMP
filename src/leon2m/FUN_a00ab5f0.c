/* leon2m FUN_a00ab5f0 @ 0xa00ab5f0-0xa00ab96c (892 bytes), flags -mcpu=v8 -O3 -g.
 * v = val >> 1, full = v / 10, part = v % 10; full is decremented when part == 0 and full != 0. rest = 4 - full
 * when full < 4, else 0. Two halfword values: c1 = 0x864a and c2 = 0x834a when hl is nonzero, else 0x809a and
 * 0x839a. For each of the first full positions FUN_a0146a80(x + i, y, 1, c1, 0) and FUN_a0146b20(0, x + i, y, 1, 1,
 * 0). Then at x + full: when v == 0, FUN_a0146a80 with c1 and FUN_a0146b20 with 2, followed at x + full + 1 by
 * 0x839a and 1; otherwise FUN_a0146b20 with part * 2 + 1 and, when full <= 5, a second position x + full + 1 with
 * c1 and part * 2 + 2. Then rest positions from x + full + 2 with c2 and 1.
 * Finally, for sel == 6: when hl == 1, FUN_a00a9468(2, 6), (0, 1), (1, 3) and FUN_a00b34d4(3, 5); otherwise, when
 * FUN_a0090fcc() != 5, FUN_a00ab4bc(), FUN_a00a9468(2, 5), (0, 0), (1, 2), FUN_a00b34d4(0, 1), FUN_a00b344c(7).
 * Source form: the count 6 is held in the local 'cells', so the test 'full < cells - 2' compiles to a signed
 * 'cmp full, 4' and 'rest = cells - full; rest -= 2;' to 'mov 6; sub; add -2' on the unmasked quotient; the two
 * values are set in an if/else with the hl arm first; c2 lives in a stack halfword (register allocator spill).
 */
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a00ab4bc(void);
extern void FUN_a00b344c(unsigned int);

void FUN_a00ab5f0(unsigned char x, unsigned char y, unsigned char val, unsigned char sel, unsigned char hl)
{
    unsigned char v, full, part, rest, i;
    unsigned char cells;
    unsigned short c1;
    unsigned short c2;

    v = val >> 1;
    full = v / 10;
    part = v % 10;
    rest = 0;
    if (part == 0 && full != 0)
        full--;
    cells = 6;
    if (full < cells - 2) {
        rest = cells - full;
        rest -= 2;
    }
    if (hl) {
        c1 = 0x864a;
        c2 = 0x834a;
    } else {
        c1 = 0x809a;
        c2 = 0x839a;
    }
    if (full != 0)
        for (i = 0; i < full; i++) {
            FUN_a0146a80(x + i, y, 1, c1, 0);
            FUN_a0146b20(0, x + i, y, 1, 1, 0);
        }
    if (v == 0) {
        FUN_a0146a80(x + full, y, 1, c1, 0);
        FUN_a0146b20(0, x + full, y, 1, 2, 0);
        FUN_a0146a80(x + full + 1, y, 1, 0x839a, 0);
        FUN_a0146b20(0, x + full + 1, y, 1, 1, 0);
    } else {
        FUN_a0146a80(x + full, y, 1, c1, 0);
        FUN_a0146b20(0, x + full, y, 1, part * 2 + 1, 0);
        if (full <= 5) {
            FUN_a0146a80(x + full + 1, y, 1, c1, 0);
            FUN_a0146b20(0, x + full + 1, y, 1, part * 2 + 2, 0);
        }
    }
    for (i = 0; i < rest; i++) {
        FUN_a0146a80(x + full + i + 2, y, 1, c2, 0);
        FUN_a0146b20(0, x + full + i + 2, y, 1, 1, 0);
    }
    if (hl == 1) {
        if (sel == 6) {
            FUN_a00a9468(2, 6);
            FUN_a00a9468(0, 1);
            FUN_a00a9468(1, 3);
            FUN_a00b34d4(3, 5);
        }
    } else if (sel == 6) {
        if (FUN_a0090fcc() != 5) {
            FUN_a00ab4bc();
            FUN_a00a9468(2, 5);
            FUN_a00a9468(0, 0);
            FUN_a00a9468(1, 2);
            FUN_a00b34d4(0, 1);
            FUN_a00b344c(7);
        }
    }
}
