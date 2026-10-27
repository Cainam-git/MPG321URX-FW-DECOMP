/* leon2m FUN_a009cfd4 @ 0xa009cfd4-0xa009d234 (608 bytes), flags -mcpu=v8 -O3 -g. No direct callers found.
 * With a = word 0xa802afec: FUN_a00a93bc((a - 0x86) % 7), then a steps down: k = ((unsigned short)a - 0x85) % 12,
 * a = k + 0x86, until FUN_a00aad30(k) returns 1. The byte DAT_a802d290+0x18a[DAT_a802d290+0x1a3] = a + 0x7a. For
 * a = 0x8d it calls FUN_a00a8c88() and FUN_a00b7b8c(1), for a = 0x86 FUN_a00a8c88() and FUN_a00b7b8c(0), and sets a
 * flag; with the flag set and that byte / 7 equal to DAT_a8025c56 / 7 it calls FUN_a00a9650(DAT_a8025c56 % 7, 0).
 * Then FUN_a00a9650((a - 0x86) % 7, 1), and when (u8)(DAT_a8025c56 / 7) equals (a - 0x86) / 7:
 * FUN_a00a813c(1, DAT_a8025c56 % 7, 0 if a - 0x86 equals DAT_a8025c56, else 1). Ends with FUN_a00b88b8().
 * Source form: as FUN_a009d234 (flag tested as 'flag == 1'); the last comparison has the DAT_a8025c56 side first.
 */
struct D290 { unsigned char p000[0x18a]; unsigned char a18a[0x1a3 - 0x18a]; unsigned char b1a3; };
extern struct D290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a8c88(void);
extern void FUN_a00b7b8c(unsigned char);
extern void FUN_a00b88b8(void);

void FUN_a009cfd4(void)
{
    int k;
    unsigned char flag = 0;

    FUN_a00a93bc((_DAT_a802afec - 0x86) % 7);
    do {
        k = ((unsigned short)_DAT_a802afec - 0x85) % 12;
        _DAT_a802afec = k + 0x86;
    } while (FUN_a00aad30(k) != 1);
    DAT_a802d290.a18a[DAT_a802d290.b1a3] = _DAT_a802afec + 0x7a;
    if (_DAT_a802afec == 0x8d) {
        FUN_a00a8c88();
        FUN_a00b7b8c(1);
        flag = 1;
    } else if (_DAT_a802afec == 0x86) {
        FUN_a00a8c88();
        FUN_a00b7b8c(0);
        flag = 1;
    }
    if (flag == 1) {
        if (DAT_a802d290.a18a[DAT_a802d290.b1a3] / 7 == DAT_a8025c56 / 7)
            FUN_a00a9650(DAT_a8025c56 % 7, 0);
    }
    FUN_a00a9650((_DAT_a802afec - 0x86) % 7, 1);
    {
        unsigned char v = DAT_a8025c56;
        if ((unsigned char)(v / 7) == (_DAT_a802afec - 0x86) / 7) {
            if (_DAT_a802afec - 0x86 == v)
                FUN_a00a813c(1, v % 7, 0);
            else
                FUN_a00a813c(1, v % 7, 1);
        }
    }
    FUN_a00b88b8();
}
