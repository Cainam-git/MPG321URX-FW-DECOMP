/* leon2m FUN_a00a10c8 @ 0xa00a10c8-0xa00a13d8 (196 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a00c9980,
 * FUN_a00db1ac.
 * When byte 0xa802cff4+0x34 is 2: bit 6 set in word 0xa802d290+0x1ec, halfwords +0x1f0 / +0x1f2 = halfwords
 * 0xa802cff4+0x36 / +0x38, and both are printed with the string at 0x1081b0. Then as in FUN_a00c7e3c: byte +0x4a
 * == 1: cleared, FUN_a00d5eac(0); bit 7 of word +0xa8 set: cleared, FUN_a0124f44(), FUN_a00d91fc(0),
 * FUN_a00da184(); bit 0x100000 of word +0xac set, byte +0x1f differs from byte 0xa8025c56 and FUN_a01445fc(byte
 * +0x1e) returns 0: FUN_a00d91fc(0), FUN_a01439d8(0x10, 1), FUN_a0148268(0, 1), FUN_a0148268(1, 1);
 * FUN_a00837e4() == 1: byte +0x1a4 cleared. Byte +0x1f = 2, word +0xb0 = 0, byte +0x19 = 0. Both values of byte
 * 0xa8025c56 then set bit 10 of halfword 0xa802cff4+4 and call FUN_a00808ac(4, 0) when its bit 15 is set, clear
 * word 0xa802afec and call FUN_a00b5080(), FUN_a00d91fc(0), FUN_a0148268(0, 1), FUN_a0148268(1, 1),
 * FUN_a00da254(); for a value other than 2 also FUN_a00830f4(0), FUN_a00d8c1c(), FUN_a00acef4(), FUN_a00d4998(),
 * FUN_a00d5cd8() when bit 14 of word +0xa8 is set, FUN_a00808ac(0, 0), FUN_a00808ac(1, 0) and byte 0xa8025c56 =
 * byte +0x1f; for 2, byte 0xa8025c54 = byte +0x2f. When word 0xa802afec - 0x7f differs from byte 0xa8025c54,
 * FUN_a00a93bc(that byte) and FUN_a00a813c(1, that byte, 0) run. Finally bit 1 of byte 0xa802b08e is set.
 * Source form: the bit-field layout of 0xa802cff4+4 as in FUN_a00972cc; the 'byte 0xa8025c56 != 2' arm is written
 * first (register names).
 */
struct Rcff4 {
    unsigned char pad[4];
    unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10;
    unsigned char pad6[0x34 - 6];
    unsigned char b34;
    unsigned char pad35;
    unsigned short h36, h38;
};
struct R290 {
    unsigned char pad0[0x19];
    unsigned char b19;
    unsigned char pad1a[0x1e - 0x1a];
    unsigned char b1e, b1f;
    unsigned char pad20[0x2f - 0x20];
    unsigned char b2f;
    unsigned char pad30[0x4a - 0x30];
    unsigned char b4a;
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int wa8, wac, wb0;
    unsigned char padb4[0x1a4 - 0xb4];
    unsigned char b1a4;
    unsigned char pad1a5[0x1ec - 0x1a5];
    unsigned int w1ec;
    unsigned short h1f0, h1f2;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c54, DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern char s_001081b0[];
extern int FUN_a00df170();
extern void FUN_a00808ac(unsigned char, unsigned char);
extern void FUN_a00b5080(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);
extern void FUN_a0124f44(void);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a01439d8(int, int);
extern void FUN_a0148268(int, int);
extern void FUN_a00830f4(int);
extern void FUN_a00d8c1c(void);
extern void FUN_a00acef4(void);
extern void FUN_a00d4998(void);
extern void FUN_a00d5cd8(void);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00a10c8(void)
{
    if (DAT_a802cff4.b34 == 2) {
        DAT_a802d290.w1ec |= 0x40;
        DAT_a802d290.h1f0 = DAT_a802cff4.h36;
        DAT_a802d290.h1f2 = DAT_a802cff4.h38;
        FUN_a00df170(s_001081b0, DAT_a802cff4.h36, DAT_a802cff4.h38);
    }
    if (DAT_a802d290.b4a == 1) {
        DAT_a802d290.b4a = 0;
        FUN_a00d5eac(0);
    }
    if (DAT_a802d290.wa8 & 0x80) {
        DAT_a802d290.wa8 &= ~0x80;
        FUN_a0124f44();
        FUN_a00d91fc(0);
        FUN_a00da184();
    }
    if ((DAT_a802d290.wac & 0x100000) && DAT_a802d290.b1f != DAT_a8025c56 && FUN_a01445fc(DAT_a802d290.b1e) == 0) {
        FUN_a00d91fc(0);
        FUN_a01439d8(0x10, 1);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
    }
    if (FUN_a00837e4() == 1)
        DAT_a802d290.b1a4 = 0;
    DAT_a802d290.b1f = 2;
    DAT_a802d290.wb0 = 0;
    DAT_a802d290.b19 = 0;
    if (DAT_a8025c56 != 2) {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        FUN_a00d91fc(0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a00da254();
        FUN_a00830f4(0);
        FUN_a00d8c1c();
        FUN_a00acef4();
        FUN_a00d4998();
        if (DAT_a802d290.wa8 & 0x4000)
            FUN_a00d5cd8();
        FUN_a00808ac(0, 0);
        FUN_a00808ac(1, 0);
        DAT_a8025c56 = DAT_a802d290.b1f;
    } else {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        FUN_a00d91fc(0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a00da254();
        DAT_a8025c54 = DAT_a802d290.b2f;
    }
    if (_DAT_a802afec - 0x7f != DAT_a8025c54) {
        FUN_a00a93bc(DAT_a8025c54);
        FUN_a00a813c(1, DAT_a8025c54, 0);
    }
    DAT_a802b08e |= 2;
}
