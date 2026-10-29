/* leon2m FUN_a009f184 @ 0xa009f184-0xa009f42c (-mcpu=v8 -O3 -g).
 * Record bytes at 0xa802d290 (+0x1e2, +0x1e4, +0x1e6, +0x1ee) and halfwords at 0xa802cff4 (+4, +0xe, +0x10, +0x18,
 * byte +0x3f). When +0x1ee is 1 and halfword +0x10 differs from +0x1e2 and is <= 3, it is copied to +0x1e2, bit 1 of
 * 0xa802b08e is set and the function returns. Otherwise, when (+0x1e2 differs from +0x10 or +0x1e6 is 1) and +0x10
 * is nonzero: bit 15 of +4 set -> bit 10 of +4 set and FUN_a00808ac(4, 0); the word 0xa802afec is cleared and
 * FUN_a00b5080() called; FUN_a00daad4() == 1 -> 0xa8025c56 = 0 and FUN_a00da9e4(FUN_a00da870(0)); else bit 15 of
 * +0xe is set, 0xa8025c56 cleared, then either (+0x1e2 equal to +0x10, +0x1e6 == 1, +0x1e2 != 0) +0x1e4 is cleared
 * when nonzero and FUN_a00b1ba4(0xa8025c56, +0x1e2 - 1) called, or +0x3f = 2, bit 15 of +0x18 cleared and
 * FUN_a00b1700(0, 3) when +0x1e2 > 2, else +0x3f = 1, bit 15 of +0x18 = (+0x1ee == 0) and FUN_a00b1700(0, +0x1e2),
 * followed by 0xa8025c55 = 0; 0xa802afec = 0x10a. Bit 1 of 0xa802b08e is set at the end. When neither holds and
 * +0x1e4 is nonzero, the same bit 15 / FUN_a00b5080 / FUN_a00daad4 steps run, with FUN_a00b1ba4(0, 4) and
 * 0xa802afec = 0x10a in the else arm, and bit 1 of 0xa802b08e is set.
 * Source form: one 0x10a store after the inner if/else; in the +0x1e2 > 2 arm +0x3f is written before bit 15 of
 * +0x18.
 */
struct B15 { unsigned short b15 : 1, rest : 15; };
struct Rcff4 {
    unsigned char pad[4];
    unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10;
    unsigned char pad6[0xe - 6];
    struct B15 he;
    unsigned short h10;
    unsigned char pad12[0x18 - 0x12];
    struct B15 h18;
    unsigned char pad1a[0x3f - 0x1a];
    unsigned char b3f;
};
struct R290 {
    unsigned char pad0[0x1e2];
    unsigned char b1e2;
    unsigned char pad1e3;
    unsigned char b1e4;
    unsigned char pad1e5;
    unsigned char b1e6;
    unsigned char pad1e7[0x1ee - 0x1e7];
    unsigned char b1ee;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c55, DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00808ac(unsigned char n, unsigned char f);
extern void FUN_a00b5080(void);
extern unsigned char FUN_a00daad4(void);
extern unsigned char FUN_a00da870(unsigned char p);
extern void FUN_a00da9e4(unsigned char n);
extern void FUN_a00b1700(unsigned char id, unsigned char m);
extern void FUN_a00b1ba4(unsigned char, unsigned char);

void FUN_a009f184(void)
{
    if (DAT_a802d290.b1ee == 1 && DAT_a802d290.b1e2 != DAT_a802cff4.h10 && DAT_a802cff4.h10 <= 3) {
        DAT_a802d290.b1e2 = DAT_a802cff4.h10;
        DAT_a802b08e |= 2;
        return;
    }
    if ((DAT_a802d290.b1e2 != DAT_a802cff4.h10 || DAT_a802d290.b1e6 == 1) && DAT_a802cff4.h10 != 0) {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        if (FUN_a00daad4() == 1) {
            DAT_a8025c56 = 0;
            FUN_a00da9e4(FUN_a00da870(0));
        } else {
            DAT_a802cff4.he.b15 = 1;
            DAT_a8025c56 = 0;
            if (DAT_a802d290.b1e2 == DAT_a802cff4.h10 && DAT_a802d290.b1e6 == 1 && DAT_a802d290.b1e2 != 0) {
                if (DAT_a802d290.b1e4 != 0)
                    DAT_a802d290.b1e4 = 0;
                FUN_a00b1ba4(DAT_a8025c56, DAT_a802d290.b1e2 - 1);
            } else {
                if (DAT_a802d290.b1e2 > 2) {
                    DAT_a802cff4.b3f = 2;
                    DAT_a802cff4.h18.b15 = 0;
                    FUN_a00b1700(0, 3);
                } else {
                    DAT_a802cff4.b3f = 1;
                    if (DAT_a802d290.b1ee == 0)
                        DAT_a802cff4.h18.b15 = 1;
                    else
                        DAT_a802cff4.h18.b15 = 0;
                    FUN_a00b1700(0, DAT_a802d290.b1e2);
                }
                DAT_a8025c55 = 0;
            }
            _DAT_a802afec = 0x10a;
        }
        DAT_a802b08e |= 2;
    } else if (DAT_a802d290.b1e4 != 0) {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        if (FUN_a00daad4() == 1) {
            DAT_a8025c56 = 0;
            FUN_a00da9e4(FUN_a00da870(0));
        } else {
            FUN_a00b1ba4(0, 4);
            _DAT_a802afec = 0x10a;
        }
        DAT_a802b08e |= 2;
    }
}
