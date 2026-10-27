/* leon2m FUN_a00b0710 @ 0xa00b0710-0xa00b0a90 (896 bytes), flags -mcpu=v8 -O3 -g. Twelve call sites in
 * FUN_a00b0a90 .. FUN_a00b2c18. sel selects up to four first arguments a, b, c, d and a column col:
 * sel 0: 9, 0x15, col 7; sel 1: 0x10, 0x1c, 0x25, col 0x16; sel 2: 10, 0x16, 0x23, col 0x16; sel 3: 10, 0x17,
 * 0x24 when the byte DAT_a802d033 is 2, else 4, 0x10, 0x1c, 0x28, col 7. FUN_a00ad5a4(3, x, col, flag) for each:
 * sel other than 2 and 3: a, b with flag 1 on a when st != 0, else on b; sel 2: a, b, c with flag 1 on a (st 1),
 * b (st 0) or c (other st); sel 3: a (flag st == 0), b only when the byte DAT_a802d472 < 3 or FUN_a0090fcc() !=
 * 0x10a (flag st == 1), c (flag st == 2), and when DAT_a802d033 == 1 also d (flag st == 3).
 * Source form: every state arm written out with constant flags (GCC cross-jumps the shared calls); in sel 3 the
 * column is set after the DAT_a802d033 if/else.
 */
extern unsigned char DAT_a802d033;
extern unsigned char DAT_a802d472;
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a00ad5a4(unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a00b0710(unsigned char sel, unsigned char st)
{
    unsigned char a = 0, b = 0, c = 0, d = 0, col = 0;

    switch (sel) {
    case 0:
        a = 9; b = 0x15; col = 7;
        break;
    case 1:
        a = 0x10; b = 0x1c; c = 0x25; col = 0x16;
        break;
    case 2:
        a = 10; b = 0x16; c = 0x23; col = 0x16;
        break;
    case 3:
        if (DAT_a802d033 == 2) {
            a = 10; b = 0x17; c = 0x24;
        } else {
            a = 4; b = 0x10; c = 0x1c; d = 0x28;
        }
        col = 7;
        break;
    }
    if (sel != 2 && sel != 3) {
        if (st) {
            FUN_a00ad5a4(3, a, col, 1);
            FUN_a00ad5a4(3, b, col, 0);
        } else {
            FUN_a00ad5a4(3, a, col, 0);
            FUN_a00ad5a4(3, b, col, 1);
        }
    } else if (sel != 3) {
        if (st == 1) {
            FUN_a00ad5a4(3, a, col, 1);
            FUN_a00ad5a4(3, b, col, 0);
            FUN_a00ad5a4(3, c, col, 0);
        } else if (st == 0) {
            FUN_a00ad5a4(3, a, col, 0);
            FUN_a00ad5a4(3, b, col, 1);
            FUN_a00ad5a4(3, c, col, 0);
        } else {
            FUN_a00ad5a4(3, a, col, 0);
            FUN_a00ad5a4(3, b, col, 0);
            FUN_a00ad5a4(3, c, col, 1);
        }
    } else {
        if (st == 0) {
            FUN_a00ad5a4(3, a, col, 1);
            if (DAT_a802d472 < 3 || FUN_a0090fcc() != 0x10a)
                FUN_a00ad5a4(3, b, col, 0);
            FUN_a00ad5a4(3, c, col, 0);
        } else if (st == 1) {
            FUN_a00ad5a4(3, a, col, 0);
            if (DAT_a802d472 < 3 || FUN_a0090fcc() != 0x10a)
                FUN_a00ad5a4(3, b, col, 1);
            FUN_a00ad5a4(3, c, col, 0);
        } else if (st == 2) {
            FUN_a00ad5a4(3, a, col, 0);
            if (DAT_a802d472 < 3 || FUN_a0090fcc() != 0x10a)
                FUN_a00ad5a4(3, b, col, 0);
            FUN_a00ad5a4(3, c, col, 1);
        } else {
            FUN_a00ad5a4(3, a, col, 0);
            if (DAT_a802d472 < 3 || FUN_a0090fcc() != 0x10a)
                FUN_a00ad5a4(3, b, col, 0);
            FUN_a00ad5a4(3, c, col, 0);
        }
        if (DAT_a802d033 == 1) {
            if (st == 3)
                FUN_a00ad5a4(3, d, col, 1);
            else
                FUN_a00ad5a4(3, d, col, 0);
        }
    }
}
