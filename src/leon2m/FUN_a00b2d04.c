/* leon2m FUN_a00b2d04 @ 0xa00b2d04-0xa00b3070 (-mcpu=v8 -O3 -g). Called by FUN_a009f42c and FUN_a00caf0c.
 * Records: DAT_a802d290 (bytes +0x1e2..+0x1e7, +0x1ee; word +0x1dc with bits 31 and 30) and DAT_a802cff4
 * (halfword +0, bit 15 of halfword +0xe as the 1-bit field b15, halfwords +0x10 / +0x12, byte +0x3f).
 * When byte +0x1e4 or +0x1e5 is 1: clears the bytes that are 1, sets bit 1 of DAT_a802b08e and tail-calls
 * FUN_a0090fd8(). Otherwise calls FUN_a0090fd8(), then by DAT_a8025c55 and byte +0x3f: (c55 == 2, +0x3f == 0)
 * b15 = 0, +0x1ee = 1, word bits 31 and 30 set; (+0x3f != 0 and (c55 == 3 or c55 == 2 with +0x1e2 > 2)) b15 = 1,
 * +0x3f = 0, FUN_a00b1ba4(DAT_a8025c56, min(+0x1e2, 3)) and a tail call FUN_a0090fa0(0x10a); (+0x3f != 0,
 * c55 == 2) as the first case; (+0x3f != 0, other c55) c55 = 1 - c55 and b15 = c55. With both word bits set:
 * c56 == 0 copies halfword +0x10 to +0x1e2 and sets +0x1e6 to b15 (when 1 also clears bit 8 of halfword +0);
 * c56 == 1 copies halfword +0x12 to +0x1e3 and sets +0x1e7 to 0 or c56 (when set also clears bit 8). When b15
 * is set: word bit 31 clear -> clears bit 8 and sets +0x1e4 = 1; word bit 30 clear -> +0x1e5 = 1 and clears
 * bit 8; then FUN_a00dab4c(c56). Ends by setting word bits 31 and 30 and bit 1 of DAT_a802b08e.
 * Source form: set1() (store 1 through a byte pointer, then clear bit 8 of halfword +0) is a static helper
 * inlined for +0x1e5 and +0x1e6; the bit-31 test is written 'w >> 31'; the word is a union of the plain word
 * and bit-fields; 'c55 = 1 - c55; b15 = c55;'.
 */
struct Rcff4 {
    unsigned short h0;
    unsigned short h2, h4, h6, h8, ha, hc;
    unsigned short b15 : 1, r0e : 15;
    unsigned short h10, h12;
    unsigned char p14[0x3f - 0x14];
    unsigned char b3f;
};
struct R290 {
    unsigned char p000[0x1dc];
    union { unsigned int w; struct { unsigned int b31 : 1, b30 : 1, r : 30; } f; } u1dc;
    unsigned char p1e0[2];
    unsigned char b1e2, b1e3, b1e4, b1e5, b1e6, b1e7;
    unsigned char p1e8[6];
    unsigned char b1ee;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55, DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a0090fd8(void);
extern void FUN_a00b1ba4(unsigned char, unsigned char);
extern void FUN_a0090fa0(unsigned short);
extern void FUN_a00dab4c(unsigned char);

static void set1(unsigned char *b)
{
    *b = 1;
    DAT_a802cff4.h0 &= ~0x100;
}

void FUN_a00b2d04(void)
{
    if (DAT_a802d290.b1e4 == 1 || DAT_a802d290.b1e5 == 1) {
        if (DAT_a802d290.b1e4 == 1)
            DAT_a802d290.b1e4 = 0;
        if (DAT_a802d290.b1e5 == 1)
            DAT_a802d290.b1e5 = 0;
        DAT_a802b08e |= 2;
        FUN_a0090fd8();
        return;
    }
    FUN_a0090fd8();
    if (DAT_a8025c55 == 2 && DAT_a802cff4.b3f == 0) {
        DAT_a802cff4.b15 = 0;
        DAT_a802d290.b1ee = 1;
        DAT_a802d290.u1dc.f.b31 = 1;
        DAT_a802d290.u1dc.f.b30 = 1;
    } else if (DAT_a802cff4.b3f != 0) {
        if (DAT_a8025c55 == 3 || (DAT_a802d290.b1e2 > 2 && DAT_a8025c55 == 2)) {
            DAT_a802cff4.b15 = 1;
            DAT_a802cff4.b3f = 0;
            if (DAT_a802d290.b1e2 > 2)
                FUN_a00b1ba4(DAT_a8025c56, 3);
            else
                FUN_a00b1ba4(DAT_a8025c56, DAT_a802d290.b1e2);
            FUN_a0090fa0(0x10a);
            return;
        }
        if (DAT_a8025c55 == 2) {
            DAT_a802cff4.b15 = 0;
            DAT_a802d290.b1ee = 1;
            DAT_a802d290.u1dc.f.b31 = 1;
            DAT_a802d290.u1dc.f.b30 = 1;
        } else {
            DAT_a8025c55 = 1 - DAT_a8025c55;
            DAT_a802cff4.b15 = DAT_a8025c55;
        }
    }
    if (DAT_a8025c56 == 0 && (DAT_a802d290.u1dc.w & 0xc0000000) == 0xc0000000) {
        DAT_a802d290.b1e2 = DAT_a802cff4.h10;
        if (!DAT_a802cff4.b15)
            DAT_a802d290.b1e6 = 0;
        else
            set1(&DAT_a802d290.b1e6);
    }
    if (DAT_a8025c56 == 1 && (DAT_a802d290.u1dc.w & 0xc0000000) == 0xc0000000) {
        DAT_a802d290.b1e3 = DAT_a802cff4.h12;
        if (!DAT_a802cff4.b15)
            DAT_a802d290.b1e7 = 0;
        else {
            DAT_a802d290.b1e7 = DAT_a8025c56;
            DAT_a802cff4.h0 &= ~0x100;
        }
    }
    if (DAT_a802cff4.b15) {
        if (!(DAT_a802d290.u1dc.w >> 31)) {
            DAT_a802cff4.h0 &= ~0x100;
            DAT_a802d290.b1e4 = 1;
        }
        if (!(DAT_a802d290.u1dc.w & 0x40000000))
            set1(&DAT_a802d290.b1e5);
        FUN_a00dab4c(DAT_a8025c56);
    }
    DAT_a802d290.u1dc.f.b31 = 1;
    DAT_a802d290.u1dc.f.b30 = 1;
    DAT_a802b08e |= 2;
}
