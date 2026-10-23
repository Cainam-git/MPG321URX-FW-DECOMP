/* FUN_a00cbb50 (leon2s 0xa00cbb50-0xa00cc1d4, 1668 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port]: st = bits 16..17 of word 0, f23 = bit 23,
 * bytes +3..+8, word +0xc (wc). Sets st = 1, then:
 * - (u8)FUN_a00c0a04(port) != 0 or (u8)FUN_a00c9798(port, &DAT_a807d250) != 0: st = 3, return.
 * - byte +1 (hi) of DAT_a807d250 & 8: st = 0, return; hi & 4 clear: st = 3, return.
 * - n = ((hi & 3) << 8) + lo (u16); n == 0: st = 3 and tail call func_0xa0fc1794(10).
 * - f23 = 0; (u8)FUN_a00c8048(port, 0x74, 0x80, lo) != 0 or (u8)FUN_a00c81f8(port, DAT_a807ce50, lo) != 0:
 *   st = 0, return. For n > 5: wc == 0xffffff with DAT_a807ce50[3..5] all 0, or wc == 0 with any of them
 *   non-zero: st = 0, return.
 * - wc = DAT_a807ce50[3] << 16 | [4] << 8 | [5] (1 if that is 0); FUN_a00c76c0(port, 5, 4, 1 / 0);
 *   FUN_a00c87e8(port, 0xb, 0x8000); writes DAT_a807ce50[1..5] and [0x16 .. lo - 1] with FUN_a00c7654(port, 1, b);
 *   copies DAT_a807ce50[6..0x15] to DAT_a807cd88[0..15]; writes [1..5] again, then 0x80 to reg 1 and 0xe0 to
 *   reg 6, waits while bit 7 of FUN_a00c7770(port, 6) is set; FUN_a00c87e8(port, 0x14, 0x8000) and reads 16
 *   bytes FUN_a00c7770(port, 1) into DAT_a807d088.
 * - with b1 = DAT_a807ce50[1], b2 = DAT_a807ce50[2]: b2 & 0xc sets st = 2; b1 bit 0 set and b2 high nibble 0xf:
 *   b2 |= 8, byte +5 = 1; else high nibble 0xf: b2 &= 0xf, b1 |= 1; else b2 += 0x10. (b1 & 0xe) < 8: b1 += 2,
 *   else b2 |= 4, byte +6 = 1. Then byte +3 = (b1 & 1) << 4 | b2 >> 4, +4 = (b1 & 0xe) >> 1, +5 |= b2 bit 3,
 *   +6 |= b2 bit 2, +7 = b2 bit 0, +8 = b2 bit 1.
 * - st != 2: st = 1, and st = 0 if any of the 16 bytes DAT_a807d088 / DAT_a807cd88 differ.
 * - FUN_a00c87e8(port, 0xb, ((b1 & 1) * 16 + (b2 >> 4)) * 5 | 0x4000), then writes the 5 bytes of row port of
 *   DAT_a807ce38 with FUN_a00c7654(port, 1, b).
 * Source forms: the first b2 test reads b2 into a u8 variable with an unsigned int copy for the tests (the
 * stored b2 | 8 uses the u8); b1 is read into an int before b2 for the record bytes, b2 into a u8 with an int
 * copy for the shifted bits (b2 >> 4 and bit 0 use the u8); the inner else arm clears b2 before setting b1.
 */
struct Rec24 {
    unsigned int top:4;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int mid:5;
    unsigned int st:2;
    unsigned int low:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char pad9[3];
    unsigned int wc;
    unsigned char pad10[8];
};
struct D250 { unsigned char lo; unsigned char hi; };
extern struct Rec24 DAT_a8078bb0[];
extern struct D250 DAT_a807d250;
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807cd88[];
extern unsigned char DAT_a807d088[];
extern unsigned char DAT_a807ce38[][5];
extern unsigned char FUN_a00c0a04(int);
extern unsigned int FUN_a00c9798(unsigned char, struct D250 *);
extern unsigned int FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned short);
extern unsigned int FUN_a00c81f8(unsigned char, unsigned char *, unsigned short);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c76c0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern void func_0xa0fc1794(unsigned int);

void FUN_a00cbb50(unsigned char port)
{
    unsigned short n;
    unsigned char lo;
    unsigned char i;
    unsigned char v;
    unsigned int w;
    unsigned char c;
    int x;
    int d;

    DAT_a8078bb0[port].st = 1;
    if ((unsigned char)FUN_a00c0a04(port) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if ((unsigned char)FUN_a00c9798(port, &DAT_a807d250) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (DAT_a807d250.hi & 8) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if ((DAT_a807d250.hi & 4) == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    lo = DAT_a807d250.lo;
    n = ((DAT_a807d250.hi & 3) << 8) + lo;
    if (n == 0) {
        DAT_a8078bb0[port].st = 3;
        func_0xa0fc1794(10);
        return;
    }
    DAT_a8078bb0[port].f23 = 0;
    if ((unsigned char)FUN_a00c8048(port, 0x74, 0x80, lo) != 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if ((unsigned char)FUN_a00c81f8(port, DAT_a807ce50, DAT_a807d250.lo) != 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if (n > 5) {
        if (DAT_a8078bb0[port].wc == 0xffffff && DAT_a807ce50[3] == 0 && DAT_a807ce50[4] == 0
            && DAT_a807ce50[5] == 0) {
            DAT_a8078bb0[port].st = 0;
            return;
        }
        if (DAT_a8078bb0[port].wc == 0
            && (DAT_a807ce50[3] != 0 || DAT_a807ce50[4] != 0 || DAT_a807ce50[5] != 0)) {
            DAT_a8078bb0[port].st = 0;
            return;
        }
    }
    DAT_a8078bb0[port].wc = (DAT_a807ce50[3] << 16) | (DAT_a807ce50[4] << 8) | DAT_a807ce50[5];
    if (DAT_a8078bb0[port].wc == 0)
        DAT_a8078bb0[port].wc = 1;
    FUN_a00c76c0(port, 5, 4, 1);
    FUN_a00c76c0(port, 5, 4, 0);
    FUN_a00c87e8(port, 0xb, 0x8000);
    for (i = 0; i < 5; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[i + 1]);
    for (i = 0x15; i < DAT_a807d250.lo - 1; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[i + 1]);
    for (i = 0; i < 16; i++)
        DAT_a807cd88[i] = DAT_a807ce50[i + 6];
    for (i = 0; i < 5; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[i + 1]);
    FUN_a00c7654(port, 1, 0x80);
    FUN_a00c7654(port, 6, 0xe0);
    while (FUN_a00c7770(port, 6) & 0x80)
        ;
    FUN_a00c87e8(port, 0x14, 0x8000);
    for (i = 0; i < 16; i++)
        DAT_a807d088[i] = FUN_a00c7770(port, 1);
    v = DAT_a807ce50[2];
    w = v;
    if (w & 0xc)
        DAT_a8078bb0[port].st = 2;
    if ((DAT_a807ce50[1] & 1) && (w & 0xf0) == 0xf0) {
        DAT_a807ce50[2] = v | 8;
        DAT_a8078bb0[port].b5 = 1;
    } else if ((DAT_a807ce50[2] & 0xf0) == 0xf0) {
        DAT_a807ce50[2] &= 0xf;
        DAT_a807ce50[1] |= 1;
    } else {
        DAT_a807ce50[2] += 0x10;
    }
    if ((DAT_a807ce50[1] & 0xe) < 8) {
        DAT_a807ce50[1] += 2;
    } else {
        DAT_a807ce50[2] |= 4;
        DAT_a8078bb0[port].b6 = 1;
    }
    d = DAT_a807ce50[1];
    c = DAT_a807ce50[2];
    x = c;
    DAT_a8078bb0[port].b3 = ((d & 1) << 4) | (c >> 4);
    DAT_a8078bb0[port].b4 = (d & 0xe) >> 1;
    DAT_a8078bb0[port].b5 |= (x & 8) >> 3;
    DAT_a8078bb0[port].b6 |= (x & 4) >> 2;
    DAT_a8078bb0[port].b7 = c & 1;
    DAT_a8078bb0[port].b8 = (x & 2) >> 1;
    if (DAT_a8078bb0[port].st != 2) {
        DAT_a8078bb0[port].st = 1;
        for (i = 0; i < 16; i++)
            if (DAT_a807d088[i] != DAT_a807cd88[i])
                DAT_a8078bb0[port].st = 0;
    }
    FUN_a00c87e8(port, 0xb, ((((DAT_a807ce50[1] & 1) << 4) + (DAT_a807ce50[2] >> 4)) * 5) | 0x4000);
    for (i = 0; i < 5; i++)
        FUN_a00c7654(port, 1, DAT_a807ce38[port][i]);
}
