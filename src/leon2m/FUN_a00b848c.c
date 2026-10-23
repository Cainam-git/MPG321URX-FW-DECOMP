/* leon2m FUN_a00b848c @ 0xa00b848c-0xa00b8668 (119 words).
 * Re-maps byte DAT_a802d290+0x1e with FUN_a014459c(FUN_a01445fc(b)); when that changes it, stores it and sets
 * bit 1 of DAT_a802b08e. When FUN_a0142e8c(0) is not 5, FUN_a0145660(0, 0x16) is 0 and byte +0x1d5 is 0:
 * FUN_a00b7f9c(0x15), FUN_a014771c(0), FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0), byte 0xa802b08f = 0x24,
 * FUN_a0146dc0(0, 1), clears bit 15 of halfword 0xa802cff4+0x3e, and sets bit 0 of DAT_a802b08e when
 * FUN_a0145660(0, 0x16) is then non-zero. Then by bit 10 of halfword 0xa802cff4: set -> FUN_a00b7f9c(0x1e) unless
 * halfword +0x1f6 is 0x55aa, bit 10 cleared, bit 9 set when FUN_a00d7d48() is non-zero and +0x1f6 is not 0x55aa,
 * else cleared; clear -> bit 9 cleared and FUN_a00b7f9c(0x11) when FUN_a00d7d48() is non-zero and +0x1f6 is not
 * 0x55aa.
 * Source form: the halfword at 0xa802cff4 is a union of the plain halfword (updates) and a bit-field view (the
 * bit 10 test); a mask test lets GCC reuse the loaded value where the firmware reloads it.
 */
struct R290 {
    unsigned char pad0[0x1e];
    unsigned char b1e;
    unsigned char pad1f[0x1d5 - 0x1f];
    unsigned char b1d5;
    unsigned char pad1d6[0x1f6 - 0x1d6];
    unsigned short h1f6;
};
struct Rcff4 {
    union {
        unsigned short h;
        struct {
            unsigned short b15 : 5, b10 : 1, b9 : 1, rest : 9;
        } f;
    } h0;
    unsigned char pad2[0x3e - 2];
    unsigned short h3e;
};
extern struct R290 DAT_a802d290;
extern struct Rcff4 DAT_a802cff4;
extern unsigned char DAT_a802b08e, DAT_a802b08f;
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern unsigned char FUN_a0142e8c(unsigned int);
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern void FUN_a00b7f9c(int);
extern void FUN_a014771c(int);
extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern int FUN_a00d7d48(void);

void FUN_a00b848c(void)
{
    if (DAT_a802d290.b1e != FUN_a014459c(FUN_a01445fc(DAT_a802d290.b1e))) {
        DAT_a802d290.b1e = FUN_a014459c(FUN_a01445fc(DAT_a802d290.b1e));
        DAT_a802b08e |= 2;
    }
    if (FUN_a0142e8c(0) != 5 && FUN_a0145660(0, 0x16) == 0 && DAT_a802d290.b1d5 == 0) {
        FUN_a00b7f9c(0x15);
        FUN_a014771c(0);
        FUN_a0146dc0(0, 0);
        FUN_a0146c40(8, 0, 0);
        DAT_a802b08f = 0x24;
        FUN_a0146dc0(0, 1);
        DAT_a802cff4.h3e &= ~0x8000;
        if (FUN_a0145660(0, 0x16) != 0)
            DAT_a802b08e |= 1;
    }
    if (DAT_a802cff4.h0.f.b10) {
        if (DAT_a802d290.h1f6 != 0x55aa)
            FUN_a00b7f9c(0x1e);
        DAT_a802cff4.h0.h &= ~0x400;
        if (FUN_a00d7d48() != 0 && DAT_a802d290.h1f6 != 0x55aa)
            DAT_a802cff4.h0.h |= 0x200;
        else
            DAT_a802cff4.h0.h &= ~0x200;
    } else {
        DAT_a802cff4.h0.h &= ~0x200;
        if (FUN_a00d7d48() != 0 && DAT_a802d290.h1f6 != 0x55aa)
            FUN_a00b7f9c(0x11);
    }
}
