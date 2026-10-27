/* leon2m FUN_a009d234 @ 0xa009d234-0xa009d4e8 (692 bytes), flags -mcpu=v8 -O3 -g. No direct callers found.
 * With a = word 0xa802afec: FUN_a00a93bc((a - 0x92) % 7), then a steps down: k = ((unsigned short)a - 0x76) % 29, a =
 * k + 0x92, until FUN_a00aad30(k) returns 1. Byte DAT_a802d290+8 = a + 0x6e. For a = 0x98, 0x9f, 0xa6, 0xad, 0xae it
 * calls FUN_a00a8c88() and FUN_a00a87cc(0, 1, 2, 3, 4 in that order) and sets a flag; with the flag set and (byte +8)
 * / 7 equal to DAT_a8025c56 / 7 it calls FUN_a00a9650(DAT_a8025c56 % 7, 0). Then FUN_a00a9650((a - 0x92) % 7, 1),
 * FUN_a00ad460(), and when (a - 0x92) / 7 equals (u8)(DAT_a8025c56 / 7): FUN_a00a813c(1, DAT_a8025c56 % 7, 0 if a -
 * 0x92 equals DAT_a8025c56, else 1). Ends with FUN_a00b88b8().
 * Source form: the flag is tested as 'flag == 1' (the plain 'if (flag)' predicts the block differently and changes
 * the block order).
 */
struct D290 { unsigned char p000[8]; unsigned char b008; };
extern struct D290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a8c88(void);
extern void FUN_a00a87cc(unsigned char);
extern void FUN_a00ad460(void);
extern void FUN_a00b88b8(void);

void FUN_a009d234(void)
{
    int k;
    unsigned char flag = 0;

    FUN_a00a93bc((_DAT_a802afec - 0x92) % 7);
    do {
        k = ((unsigned short)_DAT_a802afec - 0x76) % 29;
        _DAT_a802afec = k + 0x92;
    } while (FUN_a00aad30(k) != 1);
    DAT_a802d290.b008 = _DAT_a802afec + 0x6e;
    if (_DAT_a802afec == 0x98) {
        FUN_a00a8c88();
        FUN_a00a87cc(0);
        flag = 1;
    } else if (_DAT_a802afec == 0x9f) {
        FUN_a00a8c88();
        FUN_a00a87cc(1);
        flag = 1;
    } else if (_DAT_a802afec == 0xa6) {
        FUN_a00a8c88();
        FUN_a00a87cc(2);
        flag = 1;
    } else if (_DAT_a802afec == 0xad) {
        FUN_a00a8c88();
        FUN_a00a87cc(3);
        flag = 1;
    } else if (_DAT_a802afec == 0xae) {
        FUN_a00a8c88();
        FUN_a00a87cc(4);
        flag = 1;
    }
    if (flag == 1) {
        if (DAT_a802d290.b008 / 7 == DAT_a8025c56 / 7)
            FUN_a00a9650(DAT_a8025c56 % 7, 0);
    }
    FUN_a00a9650((_DAT_a802afec - 0x92) % 7, 1);
    FUN_a00ad460();
    {
        unsigned char v = DAT_a8025c56;
        if ((_DAT_a802afec - 0x92) / 7 == (unsigned char)(v / 7)) {
            if (_DAT_a802afec - 0x92 == v)
                FUN_a00a813c(1, v % 7, 0);
            else
                FUN_a00a813c(1, v % 7, 1);
        }
    }
    FUN_a00b88b8();
}
