/* leon2m FUN_a014a4d8 @ 0xa014a4d8-0xa014a588 (176 bytes), flags -mcpu=v8 -O3 -g.
 * Same start as FUN_a014a654: v = (u8)FUN_a01421c4((u8)FUN_a0142218((u8)FUN_a0125198(p))); v == 0x71: k = 0,
 * FUN_a0151aa4(0x10, 1); v == 0x81: k = 1, FUN_a0151aa4(0x20, 1); else k = 0xff. m = q for q = 1 or 2, else 0.
 * If k != 0xff: FUN_a012b078(k, m & 3) and the tail call FUN_a0153970(&DAT_a802e1a0, 0).
 * Source form: the q mapping is a switch written case 2, case 1, default (GCC turns the q == 2 arm into a
 * store-flag sequence); the arm selection is a switch on v as in FUN_a014a654.
 */
extern unsigned char DAT_a802e1a0[];
extern int FUN_a0125198(unsigned char);
extern void FUN_a012b078(unsigned char, unsigned char);
extern int FUN_a01421c4(unsigned char);
extern int FUN_a0142218(unsigned char);
extern void FUN_a0151aa4(unsigned int, unsigned int);
extern void FUN_a0153970(void *, unsigned int);

void FUN_a014a4d8(unsigned char p, unsigned char q)
{
    unsigned char v;
    unsigned char k;
    unsigned char m;

    v = FUN_a01421c4(FUN_a0142218(FUN_a0125198(p)));
    switch (v) {
    case 0x71:
        k = 0;
        FUN_a0151aa4(0x10, 1);
        break;
    case 0x81:
        k = 1;
        FUN_a0151aa4(0x20, 1);
        break;
    default:
        k = 0xff;
        break;
    }
    switch (q) {
    case 2:
        m = 2;
        break;
    case 1:
        m = 1;
        break;
    default:
        m = 0;
        break;
    }
    if (k != 0xff) {
        FUN_a012b078(k, m & 3);
        FUN_a0153970(DAT_a802e1a0, 0);
    }
}
