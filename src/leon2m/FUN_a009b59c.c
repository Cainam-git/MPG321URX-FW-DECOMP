/* leon2m FUN_a009b59c @ 0xa009b59c-0xa009b864 (178 words), flags -mcpu=v8 -O3 -g. Called by FUN_a009f42c.
 * When bit 15 of halfword 0xa802cff4+4 is set its bit 10 is set and FUN_a00808ac(4, 0) runs; word 0xa802afec = 0,
 * FUN_a00b5080(). byte b = 0xa802cff4+0xa. When byte 0xa802d290+0x1aa is 1: b == 0: b = 9, afec = byte +0x182 +
 * 0x48, bit 11 of word +0xa8 cleared, byte +0x1a9 = 0, FUN_a00dbcf0(), FUN_a00b1004(0, 1), byte 0xa8025c56 = byte
 * +0x182, byte 0xa8025c55 = bit 11 of word +0xa8; b == 2: b = 9, byte +0x1a9 = 0, afec = FUN_a00b6b88(byte +0x181,
 * 0) + 0x5c, FUN_a00b1004(2, 1), bytes 0xa8025c56 / 0xa8025c55 / 0xa8025c54 = byte +0x181 / bit 11 / byte +0x11,
 * bit 11 set with FUN_a00db738() when it was clear, byte 0xa802b08f = 0xc; b == 5: afec = 0xfb, b = 9, bit 11
 * cleared, byte +0x1a9 = 0, FUN_a00dbcf0(), FUN_a00b8e7c(i) for the first i of bytes +0x18a..+0x18d that is 2,
 * then FUN_a00a45a8(). Otherwise b == 0: afec = 0xe, FUN_a00b1004(0, 0); b == 2: afec = 0x15, FUN_a00b1004(2, 0),
 * FUN_a00a900c(0, 1), FUN_a00a9650(FUN_a00b6b88(byte +0x181, 0) % 7, 2). Finally byte +0x1aa = 0 and
 * FUN_a00b88b8() is tail-called.
 * Source form: as FUN_a00a01fc; bit 11 of word +0xa8 is cleared through a 1-bit bit-field of a union view;
 * byte +0x182 is read into a local first in the b == 0 case.
 */
struct D290 {
    unsigned char p000[0x11];
    unsigned char b011;
    unsigned char p012[0xa8 - 0x12];
    union { unsigned int w; struct { unsigned int hi : 20, b11 : 1, lo : 11; } b; } u0a8;
    unsigned char p0ac[0x181 - 0xac];
    unsigned char b181, b182;
    unsigned char p183[0x18a - 0x183];
    unsigned char b18a, b18b, b18c, b18d;
    unsigned char p18e[0x1a9 - 0x18e];
    unsigned char b1a9;
    unsigned char b1aa;
};
struct CFF4 {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned char p6[4];
    unsigned char ba;
};
extern struct D290 DAT_a802d290;
extern struct CFF4 DAT_a802cff4;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a8025c54, DAT_a8025c55, DAT_a8025c56;
extern void FUN_a00808ac(int, int);
extern void FUN_a00b5080(void);
extern void FUN_a00b88b8(void);
extern void FUN_a00b1004(unsigned char a, unsigned char b);
extern void FUN_a00dbcf0(void);
extern void FUN_a00a45a8(void);
extern void FUN_a00b8e7c(unsigned char);
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00db738(void);

void FUN_a009b59c(void)
{
    unsigned char m;

    if ((short)(DAT_a802cff4.h4 & 0x8000)) {
        DAT_a802cff4.h4 |= 0x400;
        FUN_a00808ac(4, 0);
    }
    _DAT_a802afec = 0;
    FUN_a00b5080();
    if (DAT_a802d290.b1aa == 1) {
        switch (DAT_a802cff4.ba) {
        case 0:
            m = DAT_a802d290.b182;
            DAT_a802cff4.ba = 9;
            _DAT_a802afec = m + 0x48;
            DAT_a802d290.u0a8.b.b11 = 0;
            DAT_a802d290.b1a9 = 0;
            FUN_a00dbcf0();
            FUN_a00b1004(0, 1);
            DAT_a8025c56 = DAT_a802d290.b182;
            DAT_a8025c55 = (DAT_a802d290.u0a8.w >> 11) & 1;
            break;
        case 2:
            DAT_a802cff4.ba = 9;
            DAT_a802d290.b1a9 = 0;
            _DAT_a802afec = FUN_a00b6b88(DAT_a802d290.b181, 0) + 0x5c;
            FUN_a00b1004(2, 1);
            DAT_a8025c56 = DAT_a802d290.b181;
            DAT_a8025c55 = (DAT_a802d290.u0a8.w >> 11) & 1;
            DAT_a8025c54 = DAT_a802d290.b011;
            if (!(DAT_a802d290.u0a8.w & 0x800)) {
                DAT_a802d290.u0a8.w |= 0x800;
                FUN_a00db738();
            }
            DAT_a802b08f = 0xc;
            break;
        case 5:
            DAT_a802cff4.ba = 9;
            _DAT_a802afec = 0xfb;
            DAT_a802d290.u0a8.b.b11 = 0;
            DAT_a802d290.b1a9 = 0;
            FUN_a00dbcf0();
            if (DAT_a802d290.b18a == 2)
                FUN_a00b8e7c(0);
            else if (DAT_a802d290.b18b == 2)
                FUN_a00b8e7c(1);
            else if (DAT_a802d290.b18c == 2)
                FUN_a00b8e7c(2);
            else if (DAT_a802d290.b18d == 2)
                FUN_a00b8e7c(3);
            FUN_a00a45a8();
            break;
        }
    } else {
        switch (DAT_a802cff4.ba) {
        case 0:
            _DAT_a802afec = 0xe;
            FUN_a00b1004(0, 0);
            break;
        case 2:
            _DAT_a802afec = 0x15;
            FUN_a00b1004(2, 0);
            FUN_a00a900c(0, 1);
            m = FUN_a00b6b88(DAT_a802d290.b181, 0);
            FUN_a00a9650(m % 7, 2);
            break;
        }
    }
    DAT_a802d290.b1aa = 0;
    FUN_a00b88b8();
}
