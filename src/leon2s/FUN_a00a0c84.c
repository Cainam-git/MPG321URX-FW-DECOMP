/*
 * FUN_a00a0c84 (leon2s, 0xa00a0c84-0xa00a1098, 1044 bytes), flags -mcpu=v8 -Os -g.
 * int (u8 port), returns 0. Handles the pending events of FUN_a00a0588(port, id) in the order 8, 0x1c, 0xe,
 * 0x16, 0xb, 0xc. Uses the 400-byte record DAT_a807d7e0[port] (bytes +1, +7, +8, +0x18, +0x18a, words
 * +0xc, +0x10, +0x18c) and the context pointer at +4 of the 0x34-byte record DAT_a807db00[port] (words
 * +0x40, +0x44, block +0x34).
 * - 8 and 0xb: sets bit (port + 2) of register 0xcf03c890, FUN_a00b1948(); (u8)FUN_a008d800() <= 0x82
 *   acknowledges with FUN_a00a07b8(port, id); FUN_a00a0b10(port, 0); FUN_a009e9a4(port).
 * - 0x1c: with byte +0x18 set the same sequence without the FUN_a008d800 test; FUN_a00a07b8(port, 0x1c).
 * - 0xe: v = 3 for port 1, else 2. Byte +1 == 1: when FUN_a0096428(port): word +0xc != ctx->w40 copies
 *   it (after FUN_a0096300(port) and word +0x10 = ctx->w44 when bits 5..7 of the two differ); byte +8 = 1;
 *   FUN_a00a07b8(port, 0x10); FUN_a00a0b98(port, 0x10, 0); word +0x18c = FUN_a00b2064(). Otherwise byte
 *   +0x18a = 1 when FUN_a007517c(v & 3), FUN_a008f990(word +0x18c), FUN_a00a7408(0, ctx + 0x34) and
 *   FUN_a00a7408(1, ctx + 0x34) are all non-zero. Then DAT_a8079184[port] equal to the byte
 *   DAT_a8079180[port]: when non-zero, DAT_a8079178[port] is incremented and above 0x14 all three are
 *   cleared; different: DAT_a8079180[port] takes the value and DAT_a8079178[port] = 0.
 *   FUN_a00a07b8(port, 0xe).
 * - 0x16: done = 1, FUN_a00a0930(port, 0x16, 0), FUN_a00a07b8(port, 0x16).
 * - 0xc only when (u8)FUN_a008d800() > 0x82: the 0x1c sequence.
 * Byte +7 = done at the end.
 * Source forms: v is set by 'v = 2; if (port != 0) { if (port == 1) v = 3; }' (branches, not flag
 * arithmetic); done = 1 is written before the FUN_a00a0930 call.
 */
struct Ctx {
    unsigned char pad0[0x34];
    unsigned char b34[0xc];
    unsigned int w40;
    unsigned int w44;
};
struct Rec34 {
    unsigned int w0;
    struct Ctx *ctx;
    unsigned char pad8[0x2c];
};
struct Rec400 {
    unsigned char b0;
    unsigned char b1;
    unsigned char pad2[5];
    unsigned char b7;
    unsigned char b8;
    unsigned char pad9[3];
    unsigned int w0c;
    unsigned int w10;
    unsigned char pad14[4];
    unsigned char b18;
    unsigned char pad19[0x18a - 0x19];
    unsigned char b18a;
    unsigned char pad18b;
    unsigned int w18c;
};
extern struct Rec400 DAT_a807d7e0[];
extern struct Rec34 DAT_a807db00[];
extern unsigned int DAT_a8079184[];
extern unsigned char DAT_a8079180[];
extern unsigned char DAT_a8079178[];
extern unsigned char FUN_a00a0588(unsigned char, unsigned char);
extern void FUN_a00a07b8(unsigned int, unsigned int);
extern void FUN_a00a0b10(unsigned char, unsigned char);
extern void FUN_a009e9a4(unsigned int);
extern void FUN_a00b1948(void);
extern unsigned char FUN_a008d800(void);
extern unsigned char FUN_a0096428(unsigned char);
extern void FUN_a0096300(unsigned char);
extern void FUN_a00a0b98(unsigned char, unsigned int, unsigned char);
extern unsigned int FUN_a00b2064(void);
extern unsigned char FUN_a007517c(unsigned int);
extern unsigned char FUN_a008f990(unsigned int);
extern unsigned int FUN_a00a7408(unsigned int, void *);
extern void FUN_a00a0930(unsigned char, unsigned char, unsigned char);

#define REG_C890 (*(volatile unsigned int *)0xcf03c890)

int FUN_a00a0c84(unsigned char port)
{
    unsigned char done = 0;
    unsigned char v;

    if (FUN_a00a0588(port, 8)) {
        REG_C890 |= 4 << port;
        FUN_a00b1948();
        if (FUN_a008d800() <= 0x82)
            FUN_a00a07b8(port, 8);
        FUN_a00a0b10(port, 0);
        FUN_a009e9a4(port);
    }
    if (FUN_a00a0588(port, 0x1c)) {
        if (DAT_a807d7e0[port].b18) {
            REG_C890 |= 4 << port;
            FUN_a00b1948();
            FUN_a00a0b10(port, 0);
            FUN_a009e9a4(port);
        }
        FUN_a00a07b8(port, 0x1c);
    }
    if (FUN_a00a0588(port, 0xe)) {
        v = 2;
        if (port != 0) {
            if (port == 1)
                v = 3;
        }
        if (DAT_a807d7e0[port].b1 == 1) {
            if (FUN_a0096428(port)) {
                if (DAT_a807d7e0[port].w0c != DAT_a807db00[port].ctx->w40) {
                    if ((DAT_a807d7e0[port].w10 & 0xe0) != (DAT_a807db00[port].ctx->w44 & 0xe0)) {
                        FUN_a0096300(port);
                        DAT_a807d7e0[port].w10 = DAT_a807db00[port].ctx->w44;
                    }
                    DAT_a807d7e0[port].w0c = DAT_a807db00[port].ctx->w40;
                }
                DAT_a807d7e0[port].b8 = 1;
                FUN_a00a07b8(port, 0x10);
                FUN_a00a0b98(port, 0x10, 0);
                DAT_a807d7e0[port].w18c = FUN_a00b2064();
            }
        } else if (FUN_a007517c(v & 3) && FUN_a008f990(DAT_a807d7e0[port].w18c)
                   && FUN_a00a7408(0, DAT_a807db00[port].ctx->b34)
                   && FUN_a00a7408(1, DAT_a807db00[port].ctx->b34)) {
            DAT_a807d7e0[port].b18a = 1;
        }
        if (DAT_a8079184[port] == DAT_a8079180[port]) {
            if (DAT_a8079184[port] != 0 && ++DAT_a8079178[port] > 0x14) {
                DAT_a8079184[port] = 0;
                DAT_a8079178[port] = 0;
                DAT_a8079180[port] = 0;
            }
        } else {
            DAT_a8079180[port] = DAT_a8079184[port];
            DAT_a8079178[port] = 0;
        }
        FUN_a00a07b8(port, 0xe);
    }
    if (FUN_a00a0588(port, 0x16)) {
        done = 1;
        FUN_a00a0930(port, 0x16, 0);
        FUN_a00a07b8(port, 0x16);
    }
    if (FUN_a00a0588(port, 0xb)) {
        REG_C890 |= 4 << port;
        FUN_a00b1948();
        if (FUN_a008d800() <= 0x82)
            FUN_a00a07b8(port, 0xb);
        FUN_a00a0b10(port, 0);
        FUN_a009e9a4(port);
    }
    if (FUN_a008d800() > 0x82 && FUN_a00a0588(port, 0xc)) {
        REG_C890 |= 4 << port;
        FUN_a00b1948();
        FUN_a00a0b10(port, 0);
        FUN_a009e9a4(port);
    }
    DAT_a807d7e0[port].b7 = done;
    return 0;
}
