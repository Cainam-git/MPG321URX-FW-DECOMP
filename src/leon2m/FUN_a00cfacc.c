/* leon2m FUN_a00cfacc @ 0xa00cfacc-0xa00d0e48 (1247 words), flags -mcpu=v8 -O3 -g. Called by FUN_a0088724.
 * Handles the byte record p (command byte p[4], arguments p[5..7], data from p[8]) with the reply buffer r.
 * flag = 1 when p[4] is 4, 0x1f, 0x60 or 0xcc, 0x14 with p[7] == 0, 0xe1 with p[5] = 0xa0 / 0xa2 / 0xa5 and
 * p[6] == 0, 8 with p[5] == 1 and p[6] == 0, 0x10 with p[5] == 0x0e, or 0xe1 with p[5] == 0xa4 and p[6] in
 * 0x20..0x23. Then a switch on p[4] (compare tree) with 19 cases, for example:
 *  - 0x16 / 0x18 / 0x1a: FUN_a0145ee8(0, 0), FUN_a0145fac(1), byte 0xa802b0a2 / b0a1 / b0a0 = p[7] and
 *    FUN_a013b42c / FUN_a013b44c / FUN_a013b46c(p[7] + 1); 0x6c / 0x6e / 0x70 the same with bytes 0xa802d2a5..a7
 *    and FUN_a00d4690 / FUN_a00d46c4 / FUN_a00d46f8(), then FUN_a0089f10().
 *  - 0x14: p[7] == 1: k from p[5] (5: 1, 6: 4, 8: 7, 0xb: 0x17, else 0); when byte DAT_a802d290+0x11 differs,
 *    FUN_a0145ee8(0, 0), FUN_a0145fac(1), the byte = k, FUN_a00d9764(). p[7] == 0: switch on p[5] (jump table at
 *    0x0006ec0c, 12 entries): 1 / 5 / 6 / 8 copy bytes 0xa802b0a2, b0a1, b0a0 to 0xa802e1f0 + 0x21 / 6 / 9 / 0x12,
 *    0xb stores (b * 100 + 127) / 255 of the three bytes to DAT_a802d290+0x12..0x14; then FUN_a0145360(0).
 *  - 0xcc: switch on p[7] (jump table at 0x0006eb74, 38 entries) sets byte 0xa802d298 (1 -> 0, 2 -> 1, ...,
 *    37 -> 0x10), then FUN_a0089f10().
 *  - 0xe1: sub-commands on p[5] / p[6] / p[7] (a0 .. a7, ed): FUN_a00cea18 / FUN_a00cea44, an endless loop when
 *    bit 14 of word DAT_a802d290 is set, halfword +0x1f6 = 0x55aa / 0xbb99, bit 12 of word +0, bit 31 of word
 *    +0x11c, bit 6 of word +0x1d4 with halfword +0x1da = 0x36f, FUN_a0145c5c(8 / 9 / 6 / 7, 0), FUN_a014b4b4(0xfe, 1)
 *    and the OR of the halfwords +2 of the three 4-byte entries at 0xa8025c58 in the reply.
 *  - 0xef: record 0xa802d250 (b0 = p[5], b1 = sum of p[8..0x27], h2 = limit 0x80 .. 0x200 from p[7] and p[0x26]),
 *    32 data bytes to 0xa802d148 + p[6] * 0x100 + p[7] (FUN_a014b280(0xff, 1, 0xa802d148, 0x100, 1) when the end
 *    reaches h2) or, for p[5] == 0x13, p[1] + 0x7a bytes to 0xa802d277 and FUN_a014aed0(0x30, 0xa802d274, 0x2e0,
 *    0x1c); reply bytes 0x6e, 0x88 / 0x83.
 *  - 4 / 8 / 0x10 / 0x12 / 0x1e / 0x60 / 0xd6 / 0xe2 / 0xe7: FUN_a00dc3dc, FUN_a014aed0(0x30, 0xa802d290, 0, 0x1fc),
 *    halfword +0x1da = p[7] << 8 | p[8] limited to 0x7e..0x3ff, byte +0xa = p[5] limited to 100, byte 0xa802d2ae,
 *    FUN_a013ce6c tests, bytes 0xa802e1f0..0xa802e1f5 = r[7], FUN_a0145fe8(0, p[5], p[6], p[7], 0).
 * When flag is set the body of FUN_a00cfa68 follows (inlined): CRC of p[4..7] by FUN_a00cea70 into r[0..4]
 * (0x6e, 0x83, 2, crc >> 8, crc) and FUN_a0089f60(0x50).
 * Source form: the case blocks in ascending command order; the flag tests read p[4] directly; case 4 holds its
 * test of halfword +0x1f6 in s (the variable that case 8 uses for byte +0x1d5); case 0x12 stores p[5] first and
 * then limits the stored byte; the 0x14 k switch has no default ('k = 0;' before it) and k is copied to the
 * unsigned int acc for the byte +0x11 compare and store (fw keeps the zero-extended k, 'and %o5, 0xff, %l0' at
 * 0xa00d04a4); the OR of the three halfwords is formed in an unsigned short w copied to acc, with the low reply
 * byte from an unsigned char copy of acc; the 0xe1 arms a2 / 0, a5, a7 / 6 and a7 / 3 call FUN_a0089f24 once
 * after their if/else; for p[5] 0xed with p[6] 5 the case ends without further tests (fw 0xa00cfda0,
 * 0xa00d0a24); the a7 / 0x13 arm tests 'p[7] == 1' first, the other arm clears bit 6 of word +0x1d4, sets
 * v = 0x36f, halfword +0x1da = v and byte +9 = 0x46; in 0xef the bytes 0xa802b0a4 and 0xa802b0a3 are set in that
 * order, the 0x13 arm reads p[7] and p[6] first and copies with its own counter j, the main path stores the h2
 * limit through the pointer hp, the 0x42 / 0x43 arms test 'end >= h2' first (copy loop and FUN_a014b280 call)
 * with the plain copy loop as else, and the end test is 'b + 0x20 < h2' (fw 0xa00d016c). The byte at 0xa802b0a3
 * is declared as PTR_a802b0a3 (the symbol names set the order of the gcse address pseudos and so the register
 * choices: fw %l1 / %l3 / %l4 for the high parts of 0xa802b0a3 / 0xa802d250 / 0xa802b0a4).
 */
struct D290 {
    unsigned int w0;
    unsigned char p004[5];
    unsigned char b9;
    unsigned char b0a;
    unsigned char p00b[5];
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char p015[0x107];
    unsigned int w11c;
    unsigned char p120[0xb4];
    union {
        unsigned int w;
        unsigned char b[4];
    } u1d4;
    unsigned char b1d8;
    unsigned char p1d9;
    unsigned short h1da;
    unsigned char p1dc[0x1a];
    unsigned short h1f6;
};
struct D250 {
    unsigned char b0;
    unsigned char b1;
    unsigned short h2;
};
struct S274 {
    unsigned char pad[2];
    unsigned char n;
    unsigned char data[0x19];
};
struct H4 {
    unsigned short h0;
    unsigned short h2;
};
extern struct D290 DAT_a802d290;
extern struct D250 DAT_a802d250;
extern struct S274 DAT_a802d274;
extern struct H4 DAT_a8025c58[];
extern unsigned char DAT_a802d148[];
extern unsigned char DAT_a802e1f0[];
extern unsigned char DAT_a802d298, DAT_a802d2a5, DAT_a802d2a6, DAT_a802d2a7, DAT_a802d2ae;
extern unsigned char DAT_a802b09d, DAT_a802b0a0, DAT_a802b0a1, DAT_a802b0a2, PTR_a802b0a3, DAT_a802b0a4;
extern unsigned char DAT_a802df6a;

extern void FUN_a0089f10(void);
extern void FUN_a0089f24(void);
extern void FUN_a0089f38(void);
extern void FUN_a0089f4c(void);
extern void FUN_a0089f60(unsigned char);
extern unsigned short FUN_a00cea70(unsigned char, unsigned short);
extern void FUN_a00cea18(void);
extern void FUN_a00cea44(void);
extern void FUN_a0145ee8(unsigned char ch, unsigned char off);
extern void FUN_a0145fac(int);
extern void FUN_a013b42c(unsigned short v);
extern void FUN_a013b44c(unsigned short v);
extern void FUN_a013b46c(unsigned short v);
extern void FUN_a00d4690(void);
extern void FUN_a00d46c4(void);
extern void FUN_a00d46f8(void);
extern void FUN_a00dc3dc(void);
extern void FUN_a0124ab0(void);
extern void FUN_a0124af8(void);
extern unsigned int FUN_a013ce6c(unsigned int);
extern void FUN_a01437f4(void);
extern void FUN_a01437fc(void);
extern void func_0x4008f8d8(void);
extern unsigned char FUN_a0142e8c(unsigned int);
extern void FUN_a014771c(int);
extern void FUN_a00d7de0(void);
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern int FUN_a0087458(unsigned short x);
extern void FUN_a00d8cd4(void);
extern int FUN_a014aed0(int, void *, int, int);
extern void FUN_a00d9764(void);
extern void FUN_a0145360(unsigned char);
extern void FUN_a0145fe8(int, int, int, int, int);
extern void FUN_a0106ba8(unsigned char);
extern void FUN_a0145c5c(int, int);
extern void FUN_a014b4b4(unsigned char p, unsigned char on);
extern void FUN_a00d8ffc(void);
extern void FUN_a00d4998(void);
extern void FUN_a014b280(unsigned char port, unsigned char b, unsigned int addr, unsigned short len,
                         unsigned char clear);

static void FUN_a00cfa68(unsigned char *param_1, unsigned char *param_2)
{
  unsigned short crc = 0;
  unsigned char i;

  for (i = 4; i < 8; i++)
    crc = FUN_a00cea70(param_1[i], crc);
  param_2[0] = 0x6e;
  param_2[1] = 0x83;
  param_2[2] = 2;
  param_2[3] = crc >> 8;
  param_2[4] = crc;
  FUN_a0089f60(0x50);
}

void FUN_a00cfacc(unsigned char *p, unsigned char *r)
{
    unsigned char flag;
    unsigned char k;
    unsigned char was;
    unsigned char s;
    unsigned char a;
    unsigned char b;
    unsigned char n;
    unsigned char c;
    unsigned char i;
    unsigned char j;
    unsigned short old;
    unsigned int acc;
    unsigned char lo;
    unsigned short v;
    unsigned short w;
    unsigned short *hp;

    flag = 0;
    if (p[4] == 4 || (p[4] == 0x14 && p[7] == 0) || p[4] == 0x1f || p[4] == 0x60 || p[4] == 0xcc
        || (p[4] == 0xe1 && p[5] == 0xa0 && p[6] == 0) || (p[4] == 0xe1 && p[5] == 0xa2 && p[6] == 0)
        || (p[4] == 0xe1 && p[5] == 0xa5 && p[6] == 0))
        flag = 1;
    else if (p[4] == 8 && p[5] == 1 && p[6] == 0)
        flag = 1;
    else if (p[4] == 0x10) {
        if (p[5] == 0xe)
            flag = 1;
    } else if (p[4] == 0xe1 && p[5] == 0xa4) {
        if (p[6] == 0x22 || p[6] == 0x23 || p[6] == 0x20 || p[6] == 0x21)
            flag = 1;
    }

    switch (p[4]) {
    case 4:
        s = DAT_a802d290.h1f6 == 0x55aa;
        FUN_a00dc3dc();
        FUN_a0089f10();
        if (s && DAT_a802d290.h1f6 != 0x55aa) {
            FUN_a0124ab0();
            FUN_a0124af8();
            break;
        }
        FUN_a0089f10();
        break;
    case 8:
        if (p[5] == 1 && p[6] == 0 && p[7] == 0) {
            was = DAT_a802d290.h1f6 == 0x55aa;
            s = DAT_a802d290.u1d4.b[1];
            FUN_a00dc3dc();
            if (was == 1)
                DAT_a802d290.h1f6 = 0x55aa;
            else
                DAT_a802d290.h1f6 = 0xbb99;
            DAT_a802d290.u1d4.b[1] = s;
        }
        FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
        break;
    case 16:
        if (p[5] != 0xe)
            break;
        old = DAT_a802d290.h1da;
        DAT_a802d290.h1da = p[7] << 8 | p[8];
        FUN_a0087458((unsigned short)FUN_a0145660(0, 1) / 10);
        if (DAT_a802d290.h1da > 0x3ff)
            DAT_a802d290.h1da = 0x3ff;
        else if (DAT_a802d290.h1da < 0x7e)
            DAT_a802d290.h1da = 0x7e;
        FUN_a00d8cd4();
        if (p[6] == 1)
            FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
        else
            DAT_a802d290.h1da = old;
        FUN_a00cfa68(p, r);
        break;
    case 18:
        FUN_a0145ee8(0, 0);
        FUN_a0145fac(1);
        DAT_a802d290.b0a = p[5];
        if (DAT_a802d290.b0a > 100)
            DAT_a802d290.b0a = 100;
        FUN_a00d7de0();
        FUN_a0089f10();
        break;
    case 20:
        if (p[7] == 1) {
            k = 0;
            switch (p[5]) {
            case 5: k = 1; break;
            case 6: k = 4; break;
            case 8: k = 7; break;
            case 11: k = 0x17; break;
            }
            acc = k;
            if (DAT_a802d290.b11 != acc) {
                FUN_a0145ee8(0, 0);
                FUN_a0145fac(1);
                DAT_a802d290.b11 = acc;
                FUN_a00d9764();
            }
        } else if (p[7] == 0) {
            switch (p[5]) {
            case 1:
                DAT_a802e1f0[0x21] = DAT_a802b0a2;
                DAT_a802e1f0[0x22] = DAT_a802b0a1;
                DAT_a802e1f0[0x23] = DAT_a802b0a0;
                FUN_a0145360(0);
                break;
            case 5:
                DAT_a802e1f0[6] = DAT_a802b0a2;
                DAT_a802e1f0[7] = DAT_a802b0a1;
                DAT_a802e1f0[8] = DAT_a802b0a0;
                FUN_a0145360(0);
                break;
            case 6:
                DAT_a802e1f0[9] = DAT_a802b0a2;
                DAT_a802e1f0[0xa] = DAT_a802b0a1;
                DAT_a802e1f0[0xb] = DAT_a802b0a0;
                FUN_a0145360(0);
                break;
            case 8:
                DAT_a802e1f0[0x12] = DAT_a802b0a2;
                DAT_a802e1f0[0x13] = DAT_a802b0a1;
                DAT_a802e1f0[0x14] = DAT_a802b0a0;
                FUN_a0145360(0);
                break;
            case 11:
                DAT_a802d290.b12 = (DAT_a802b0a2 * 100 + 0x7f) / 0xffu;
                DAT_a802d290.b13 = (DAT_a802b0a1 * 100 + 0x7f) / 0xffu;
                DAT_a802d290.b14 = (DAT_a802b0a0 * 100 + 0x7f) / 0xffu;
                FUN_a0145360(0);
                break;
            }
        }
        break;
    case 22:
        FUN_a0145ee8(0, 0);
        FUN_a0145fac(1);
        DAT_a802b0a2 = p[7];
        FUN_a013b42c(DAT_a802b0a2 + 1);
        break;
    case 24:
        FUN_a0145ee8(0, 0);
        FUN_a0145fac(1);
        DAT_a802b0a1 = p[7];
        FUN_a013b44c(DAT_a802b0a1 + 1);
        break;
    case 26:
        FUN_a0145ee8(0, 0);
        FUN_a0145fac(1);
        DAT_a802b0a0 = p[7];
        FUN_a013b46c(DAT_a802b0a0 + 1);
        break;
    case 30:
        if (FUN_a0142e8c(0) != 5) {
            FUN_a014771c(0);
            if (DAT_a802df6a != 0)
                FUN_a0089f4c();
        }
        break;
    case 96:
        if (p[5] == 3)
            DAT_a802d2ae = 2;
        else if (p[5] == 0x11)
            DAT_a802d2ae = 4;
        else if (p[5] == 0x12)
            DAT_a802d2ae = 6;
        else if (p[5] == 0xf)
            DAT_a802d2ae = 0xb;
        else if (p[5] == 0x10)
            DAT_a802d2ae = 0xd;
        else if (p[5] == 1)
            DAT_a802d2ae = 0;
        FUN_a0089f10();
        break;
    case 108:
        FUN_a0145ee8(0, 0);
        FUN_a0145fac(1);
        DAT_a802d2a5 = p[7];
        FUN_a00d4690();
        FUN_a0089f10();
        break;
    case 110:
        FUN_a0145ee8(0, 0);
        FUN_a0145fac(1);
        DAT_a802d2a6 = p[7];
        FUN_a00d46c4();
        FUN_a0089f10();
        break;
    case 112:
        FUN_a0145ee8(0, 0);
        FUN_a0145fac(1);
        DAT_a802d2a7 = p[7];
        FUN_a00d46f8();
        FUN_a0089f10();
        break;
    case 204:
        switch (p[7]) {
        case 1: DAT_a802d298 = 0; break;
        case 2: DAT_a802d298 = 1; break;
        case 3: DAT_a802d298 = 2; break;
        case 4: DAT_a802d298 = 3; break;
        case 5: DAT_a802d298 = 4; break;
        case 6: DAT_a802d298 = 7; break;
        case 7: DAT_a802d298 = 6; break;
        case 8: DAT_a802d298 = 9; break;
        case 9: DAT_a802d298 = 8; break;
        case 10: DAT_a802d298 = 5; break;
        case 12: DAT_a802d298 = 0xe; break;
        case 13: DAT_a802d298 = 0xa; break;
        case 15: DAT_a802d298 = 0x13; break;
        case 18: DAT_a802d298 = 0x1a; break;
        case 20: DAT_a802d298 = 0x15; break;
        case 24: DAT_a802d298 = 0x11; break;
        case 25: DAT_a802d298 = 0xd; break;
        case 35: DAT_a802d298 = 0xb; break;
        case 37: DAT_a802d298 = 0x10; break;
        }
        FUN_a0089f10();
        break;
    case 214:
        if (p[5] == 1) {
            if ((unsigned char)FUN_a013ce6c(0) != 4)
                FUN_a01437f4();
        } else if (p[5] == 0) {
            if ((unsigned char)FUN_a013ce6c(0) != 1 && (unsigned char)FUN_a013ce6c(1) != 1)
                FUN_a01437fc();
        } else if (p[5] == 5) {
            if ((unsigned char)FUN_a013ce6c(0) != 0)
                func_0x4008f8d8();
        }
        FUN_a0089f10();
        break;
    case 225:
        if (p[5] == 0xa0 && p[6] == 0) {
            if (p[7] == 1)
                FUN_a00cea18();
            else if (p[7] == 0)
                FUN_a00cea44();
        } else if (p[5] == 0xa1 && p[6] == 0) {
            if (DAT_a802d290.w0 & 0x4000)
                for (;;)
                    ;
        } else if (p[5] == 0xa2 && p[6] == 0) {
            if (p[7] != 0)
                DAT_a802d290.u1d4.b[1] = p[7];
            else
                DAT_a802d290.u1d4.b[1] = 0;
            FUN_a0089f24();
            FUN_a0089f10();
        } else if (p[5] == 0xa2 && p[6] == 1) {
            w = 0;
            for (i = 0; i < 3; i++)
                w |= DAT_a8025c58[i].h2;
            acc = w;
            lo = acc;
            if (p[7] == 1)
                DAT_a802b09d = 1;
            else if (p[7] == 0) {
                FUN_a014b4b4(0xfe, 1);
                DAT_a802b09d = 0;
            } else
                break;
            FUN_a014b4b4(0xfe, 1);
            r[0] = 0x6e;
            r[1] = 0x84;
            r[2] = 2;
            r[3] = acc >> 8;
            r[4] = DAT_a802b09d * 2;
            r[5] = lo;
            FUN_a0089f60(0x50);
        } else if (p[5] == 0xa3 && p[6] == 0 && p[7] == 0) {
            FUN_a0145c5c(8, 0);
            FUN_a0145c5c(9, 0);
            FUN_a0145c5c(6, 0);
            FUN_a0145c5c(7, 0);
            FUN_a0089f24();
        } else if (p[5] == 0xa5 && p[6] == 0) {
            if (p[7] == 1) {
                DAT_a802d290.h1f6 = 0x55aa;
                DAT_a802d290.b10 = 100;
            } else
                DAT_a802d290.h1f6 = 0xbb99;
            FUN_a0089f24();
            FUN_a0089f10();
        } else if (p[5] == 0xed && p[6] == 5) {
            break;
        } else if (p[5] == 0xa7 && p[6] == 6) {
            if (p[7] == 1)
                DAT_a802d290.w0 |= 0x1000;
            else
                DAT_a802d290.w0 &= ~0x1000;
            FUN_a0089f24();
            FUN_a0089f10();
        } else if (p[5] == 0xa7 && p[6] == 3) {
            if (p[7] == 0)
                DAT_a802d290.w11c &= ~0x80000000;
            else if (p[7] == 1)
                DAT_a802d290.w11c |= 0x80000000;
            if ((unsigned char)FUN_a013ce6c(0) == 0xc)
                FUN_a00d8ffc();
            FUN_a0089f24();
            FUN_a0089f10();
        } else if (p[5] == 0xa7 && p[6] == 0x13) {
            if (p[7] == 1) {
                DAT_a802d290.u1d4.w |= 0x40;
                DAT_a802d290.b9 = DAT_a802d290.b1d8;
                FUN_a00d8cd4();
                FUN_a00d4998();
                FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
                v = 0x36f;
                r[0] = 0x6e;
                r[1] = 0x87;
                r[2] = 2;
                r[3] = v >> 8;
                r[4] = v;
                r[5] = 3;
                r[6] = 0xff;
                r[7] = 0x96;
                r[8] = 0xff;
                FUN_a0089f60(0x50);
            } else {
                DAT_a802d290.u1d4.w &= ~0x40;
                v = 0x36f;
                DAT_a802d290.h1da = v;
                DAT_a802d290.b9 = 0x46;
                FUN_a00d8cd4();
                FUN_a00d4998();
                FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
            }
        }
        break;
    case 226:
        if (p[5] == 1) {
            DAT_a802e1f0[0] = r[7];
            FUN_a0089f38();
        } else if (p[5] == 2) {
            DAT_a802e1f0[1] = r[7];
            FUN_a0089f38();
        } else if (p[5] == 3) {
            DAT_a802e1f0[2] = r[7];
            FUN_a0089f38();
        } else if (p[5] == 4) {
            DAT_a802e1f0[3] = r[7];
            FUN_a0089f38();
        } else if (p[5] == 5) {
            DAT_a802e1f0[4] = r[7];
            FUN_a0089f38();
        } else if (p[5] == 6) {
            DAT_a802e1f0[5] = r[7];
            FUN_a0089f38();
        }
        break;
    case 231:
        FUN_a0145fe8(0, p[5], p[6], p[7], 0);
        FUN_a0106ba8(0);
        break;
    case 239:
        DAT_a802b0a4 = 2;
        PTR_a802b0a3 = 2;
        DAT_a802d250.b0 = p[5];
        if (DAT_a802d250.b0 == 0x13) {
            b = p[7];
            a = p[6];
            DAT_a802d274.n = p[1] + 0x7a;
            DAT_a802d250.b1 = 0;
            r[0] = 0x6e;
            r[1] = 0x88;
            r[2] = a;
            r[3] = b;
            r[4] = DAT_a802d274.n;
            FUN_a0089f60(0x50);
            for (j = 0; j < DAT_a802d274.n; j++)
                DAT_a802d274.data[j] = p[8 + j];
            FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
            break;
        }
        a = p[6];
        b = p[7];
        if (b == 0)
            DAT_a802d250.b1 = 0;
        n = 0x20;
        for (i = 0; i < n; i++)
            DAT_a802d250.b1 += p[8 + i];
        r[0] = 0x6e;
        r[1] = 0x88;
        r[2] = a;
        r[3] = b;
        r[4] = 0x20;
        FUN_a0089f60(0x50);
        c = p[0x26];
        hp = &DAT_a802d250.h2;
        if (b < 0x60)
            *hp = 0x80;
        else if (b == 0x60) {
            if (c == 0)
                *hp = 0x80;
            else if (c == 1)
                *hp = 0x100;
            else if (c == 2)
                *hp = 0x180;
            else
                *hp = 0x200;
        }
        if (DAT_a802d250.b0 == 0x42) {
            if ((unsigned short)(a * 0x100 + b + 0x20) >= DAT_a802d250.h2) {
                for (i = 0; i < 0x20; i++)
                    DAT_a802d148[a * 0x100 + b + i] = p[8 + i];
                FUN_a014b280(0xff, 1, (unsigned int)DAT_a802d148, 0x100, 1);
            } else {
                for (i = 0; i < 0x20; i++)
                    DAT_a802d148[a * 0x100 + b + i] = p[8 + i];
            }
        }
        if (DAT_a802d250.b0 == 0x43) {
            if ((unsigned short)(a * 0x100 + b + 0x20) >= DAT_a802d250.h2) {
                for (i = 0; i < 0x20; i++)
                    DAT_a802d148[a * 0x100 + b + i] = p[8 + i];
                FUN_a014b280(0xff, 1, (unsigned int)DAT_a802d148, 0x100, 1);
            } else {
                for (i = 0; i < 0x20; i++)
                    DAT_a802d148[a * 0x100 + b + i] = p[8 + i];
            }
        }
        if (b + 0x20 < DAT_a802d250.h2)
            break;
        if (DAT_a802d250.b1 == 0) {
            if (--PTR_a802b0a3 == 0)
                PTR_a802b0a3 = DAT_a802b0a4;
            break;
        }
        r[0] = 0x6e;
        r[1] = 0x83;
        r[2] = p[6];
        r[3] = p[7];
        r[4] = p[1] + 0x7a;
        FUN_a0089f60(0x50);
        break;
    }
    if (flag)
        FUN_a00cfa68(p, r);
}
