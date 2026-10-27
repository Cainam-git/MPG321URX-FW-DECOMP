/* leon2m FUN_a00b65e4 @ 0xa00b65e4-0xa00b6994 (236 words), flags -mcpu=v8 -O3 -g. Called by FUN_a009e1ec.
 * k = byte 0xa802d290+0x1a3 selects entry k of the byte pairs at +0x198 (a) and +0x19c (b), both two-digit decimal
 * values. sel 0 steps the tens digit of a, sel 1 its units digit (modulo 10 each); sel 2 steps the tens digit of b
 * modulo 6, sel 3 its units digit modulo 10; dir != 0 steps up, dir == 0 down. When a and b are then both 0, b
 * becomes 1 (sel 3 stepping down: 9). Other sel values change nothing. Then FUN_a00b6290(0) and bit 1 of byte
 * 0xa802b08e is set.
 * Source form: every statement reads the entry through the record and index again (no local copies).
 */
struct D290 {
    unsigned char p000[0x198];
    unsigned char b198[4];
    unsigned char b19c[4];
    unsigned char p1a0[3];
    unsigned char b1a3;
};
extern struct D290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00b6290(unsigned char);

void FUN_a00b65e4(unsigned char sel, unsigned char dir)
{
    if (sel == 0) {
        if (dir)
            DAT_a802d290.b198[DAT_a802d290.b1a3] =
                (DAT_a802d290.b198[DAT_a802d290.b1a3] / 10 + 1) % 10 * 10 + DAT_a802d290.b198[DAT_a802d290.b1a3] % 10;
        else
            DAT_a802d290.b198[DAT_a802d290.b1a3] =
                (DAT_a802d290.b198[DAT_a802d290.b1a3] / 10 + 9) % 10 * 10 + DAT_a802d290.b198[DAT_a802d290.b1a3] % 10;
        if (DAT_a802d290.b198[DAT_a802d290.b1a3] == 0 && DAT_a802d290.b19c[DAT_a802d290.b1a3] == 0)
            DAT_a802d290.b19c[DAT_a802d290.b1a3] = 1;
    } else if (sel == 1) {
        if (dir)
            DAT_a802d290.b198[DAT_a802d290.b1a3] =
                DAT_a802d290.b198[DAT_a802d290.b1a3] / 10 * 10 + (DAT_a802d290.b198[DAT_a802d290.b1a3] % 10 + 1) % 10;
        else
            DAT_a802d290.b198[DAT_a802d290.b1a3] =
                DAT_a802d290.b198[DAT_a802d290.b1a3] / 10 * 10 + (DAT_a802d290.b198[DAT_a802d290.b1a3] % 10 + 9) % 10;
        if (DAT_a802d290.b198[DAT_a802d290.b1a3] == 0 && DAT_a802d290.b19c[DAT_a802d290.b1a3] == 0)
            DAT_a802d290.b19c[DAT_a802d290.b1a3] = 1;
    } else if (sel == 2) {
        if (dir)
            DAT_a802d290.b19c[DAT_a802d290.b1a3] =
                (DAT_a802d290.b19c[DAT_a802d290.b1a3] / 10 + 1) % 6 * 10 + DAT_a802d290.b19c[DAT_a802d290.b1a3] % 10;
        else
            DAT_a802d290.b19c[DAT_a802d290.b1a3] =
                (DAT_a802d290.b19c[DAT_a802d290.b1a3] / 10 + 5) % 6 * 10 + DAT_a802d290.b19c[DAT_a802d290.b1a3] % 10;
        if (DAT_a802d290.b198[DAT_a802d290.b1a3] == 0 && DAT_a802d290.b19c[DAT_a802d290.b1a3] == 0)
            DAT_a802d290.b19c[DAT_a802d290.b1a3] = 1;
    } else if (sel == 3) {
        if (dir)
            DAT_a802d290.b19c[DAT_a802d290.b1a3] =
                DAT_a802d290.b19c[DAT_a802d290.b1a3] / 10 * 10 + (DAT_a802d290.b19c[DAT_a802d290.b1a3] % 10 + 1) % 10;
        else
            DAT_a802d290.b19c[DAT_a802d290.b1a3] =
                DAT_a802d290.b19c[DAT_a802d290.b1a3] / 10 * 10 + (DAT_a802d290.b19c[DAT_a802d290.b1a3] % 10 + 9) % 10;
        if (DAT_a802d290.b198[DAT_a802d290.b1a3] == 0 && DAT_a802d290.b19c[DAT_a802d290.b1a3] == 0) {
            if (dir)
                DAT_a802d290.b19c[DAT_a802d290.b1a3] = 1;
            else
                DAT_a802d290.b19c[DAT_a802d290.b1a3] = 9;
        }
    }
    FUN_a00b6290(0);
    DAT_a802b08e |= 2;
}
