/* leon2m FUN_a01086fc @ 0xa01086fc-0xa0108e4c (468 words), flags -mcpu=v8 -O3 -g -msoft-float (float code).
 * Source form, two points:
 *   1. The 0xcf011ddc value is a u8 local set in an if ('d = 0; if (w & 0x1f) d = w / 32 * 32 - w + 0x20;') and
 *      stored after it. With the store written as 'R(0xcf011ddc) = cond ? a : 0' the store ADDRESS is expanded
 *      before the condition, sched2 hoists 'or base,0x1dc' above the branch and every rename choice of the
 *      h3a-bit-15 arms moves. The fw computes 'or %o3,0x1dc,%i2' at the join, after the value.
 *      (The same value through '?:' into a local, or an if/else, does not match: only the 'd = 0' first form does.)
 *   2. The float result is converted with '(unsigned int)ceil(...)': the fw calls 0xa0155160 = __fixunsdfsi
 *      (symbols/leon2m.json, libgcc _fixunsdfsi.o); '(int)' calls __fixdfsi (0xa0156944). FUN_a01547dc is libm
 *      ceil (s_ceil.o, symbols/leon2m.json), declared here with its real name.
 * Float helpers: FUN_a0155c40 = __floatsisf, FUN_a015578c = __addsf3 (the +65536.0f fix-up of an unsigned short,
 *   ROM 0x19a2d0 = 0x47800000), FUN_a0155830 = __mulsf3, FUN_a0155a18 = __divsf3, FUN_a0155d90 = __extendsfdf2,
 *   FUN_a0155160 = __fixunsdfsi, FUN_a01547dc = ceil.
 * What it does: SetFRCCHRW (print "---->SetFRCCHRW(%d) %d", 4, on/off): the FRC channel read/write window set-up
 *   for one input on the 480p / interlace chain (callers FUN_a013c040 / FUN_a013c144 pass (0, &timing copy, w, h,
 *   il, 0, 0)). clk = timing h08 (mode 1: FUN_a00f3528()); when FUN_a0121258(ch) == 1 (a bit-2 status test), h is
 *   rounded up to even and w to a multiple of 8. f (the 6th argument) is cleared when the timing already has this
 *   w / original h (h0c / h0e) or h3a bit 15 is set. v = (h0e * 100 / h) / 200 (min 1); x = ceil((float)clk
 *   * h0a (* 2 for interlace) / v / (h + 0x14)) made even; q = ceil((x - w) / 6) * 2; k = x - 8 - q - w, capped at
 *   8000 (the excess moves into q); reg 0xcf011c00 bit 6 = (clk * h0a / 1000 * h02 / 10000) / v < 40. Then the
 *   16-bit window registers 0xcf011cd0..cf8 / 0xcf011e80..eb8 (FUN_a00f308c = two byte registers), 0xcf011cc0..cc8,
 *   0xcf011ec0 bit 7, the 0xcf0116d0 count (v - 1 or 0), the bit-4 enables of 0xcf011800 / a00 / bf8 / a84 / a88 /
 *   a8c / dc8, 0xcf011ddc = 32 - (w & 31), FUN_a00f232c(ch, 0x90, 0x20, 1) for h3a bit 15 clear, and the
 *   0xcf011d00..
 *   d18 words (h0a / 4, 0, 0, 0). Mode 1 writes only x, q, 8, k, q.
 *   clk * h0a / 1000 * h02 / 10000 is the input rate term that sets 0xcf011c00 bit 6.
 * Code facts:
 *   - f is a plain u8 local that reload SPILLS to [%fp-9] (stb/clrb/ldub = spill code, frame 112). It is NOT an
 *     address-taken byte: an address (ADDRESSOF) or a frame slot at expand time blocks the fw's sibcalls
 *     ('call FUN_a00f308c; restore' at both ends, sibcall.c no_sibcalls/frame_offset). The spill appears once the
 *     register pressure is the fw's (two full float arms).
 *   - one test '(h0c == w && h0e == oh) || h3a bit 15' -> f = 0 (one f = 0 block, two preds: no if-conversion;
 *     reorg copies the clrb into both delay slots).
 *   - oh = h is taken AFTER the clk read, right before the first FUN_a0121258 test (fw keeps it in %o4, not live
 *     across a call); rounding h = h / 2 * 2 + 2, w = w / 8 * 8 + 8 (fw srl/add, srl/sll).
 *   - v = ratio / 100, then v = v / 2 as two statements (fw: u16 mask between, 'sll 11; srl 17').
 *   - hh = h + 0x14 before the second FUN_a0121258 call (fw computes it in that call's delay slot) and both arms
 *     written in full 'x = ceil((float)clk * (h0a * 2) / v / hh)' / '(float)clk * h0a / v / hh': the fw
 *     keeps each arm's clk / h0a / v conversions separate and shares only the '/ hh' conversion (cross-jump).
 *   - 'if (x % 2 == 1) x++;' (EQ with a nonzero constant -> PRED_OPCODE_NONEQUAL: the x+1 block goes out of line
 *     like the fw, at 0xa0108ca0; '(x & 1)' keeps it inline).
 *   - q = (u16)(x - w) / 6 * 2, + 2 on a remainder (two full arms), written as (unsigned short)q.
 *   - the on/off tails written PER ARM (f -> v - 1 + print 1 + ORs; h3a -> 0 + print 1 + ORs; else 0 + print 0 +
 *     ANDs): PRED_CALL then sees a call in every arm and the fw's off-path fall-through comes out; cross-jumping
 *     merges the two 'on' tails into the fw's single print(4, 1) block.
 *   - h3a bit 15 as a BIT-FIELD (b15:1, first field = MSB): the struct alias set keeps the 0xcf011cc0 store before
 *     the h3a re-load (fw order). The test code is the same as '(short)(h3a & 0x8000)'.
 * Register allocation: k and q are u16 (HImode) like the fw ('add %l0,%o4,%l3' = q + raw k); with
 *   q u16 the rounding is written as two arms so combine has no 'q += 2' to fold into the quotient temp.
 * Compiler aids: none. volatile only on the 0xcf... registers.
 */
struct Tim {
    unsigned short h00, h02, h04, h06, h08, h0a, h0c, h0e;
    unsigned char p10[0x3a - 0x10];
    struct { unsigned short b15 : 1, rest : 15; } h3a;
};
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned short FUN_a00f3528(void);
extern unsigned char FUN_a0121258(unsigned char ch);
extern void FUN_a00f308c(volatile unsigned int *r, unsigned int v);
extern void FUN_a00f232c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern int func_0x4008d1a0(int ms);
extern double ceil(double);
extern char s_0019abe8[];

#define R(a) (*(volatile unsigned int *)(a))
#define RP(a) ((volatile unsigned int *)(a))

void FUN_a01086fc(unsigned char ch, struct Tim *t, unsigned short w, unsigned short h, unsigned char il,
                  unsigned char f6, unsigned char mode)
{
    unsigned char f = f6;
    unsigned char d;
    unsigned short hh, clk, oh, v, x, k, rate, q;

    if (mode == 1)
        clk = FUN_a00f3528();
    else
        clk = t->h08;
    oh = h;
    if (FUN_a0121258(ch) == 1) {
        if (h & 1)
            h = h / 2 * 2 + 2;
        if (w & 7)
            w = w / 8 * 8 + 8;
    }
    if ((t->h0c == w && t->h0e == oh) || t->h3a.b15)
        f = 0;
    rate = (unsigned int)clk * t->h0a / 1000 * t->h02 / 10000;
    if (mode == 0)
        R(0xcf011800) &= ~0x10;
    v = (unsigned short)((unsigned int)(t->h0e * 100) / oh) / 100;
    v = v / 2;
    if (v == 0)
        v = 1;
    hh = h + 0x14;
    if (FUN_a0121258(ch) && il)
        x = (unsigned int)ceil((double)((float)clk * (t->h0a * 2) / v / hh));
    else
        x = (unsigned int)ceil((double)((float)clk * t->h0a / v / hh));
    if (x % 2 == 1)
        x++;
    if ((unsigned short)(x - w) % 6 == 0)
        q = (unsigned short)(x - w) / 6 * 2;
    else
        q = (unsigned short)(x - w) / 6 * 2 + 2;
    k = x - 8; k = k - q - w;
    if (rate / v < 40)
        R(0xcf011c00) |= 0x40;
    else
        R(0xcf011c00) &= ~0x40;
    if (k > 8000) {
        q = q + k - 8000;
        k = 8000;
    }
    if (mode == 1) {
        FUN_a00f308c(RP(0xcf011ce0), x);
        FUN_a00f308c(RP(0xcf011cd0), (unsigned short)q);
        FUN_a00f308c(RP(0xcf011e80), 8);
        FUN_a00f308c(RP(0xcf011e88), k);
        FUN_a00f308c(RP(0xcf011e90), (unsigned short)q);
        return;
    }
    FUN_a00f308c(RP(0xcf011ce0), x);
    FUN_a00f308c(RP(0xcf011cf8), hh);
    FUN_a00f308c(RP(0xcf011cd8), w);
    FUN_a00f308c(RP(0xcf011cf0), h);
    FUN_a00f308c(RP(0xcf011cd0), (unsigned short)q);
    FUN_a00f308c(RP(0xcf011ce8), 8);
    FUN_a00f308c(RP(0xcf011e80), 8);
    FUN_a00f308c(RP(0xcf011e88), k);
    FUN_a00f308c(RP(0xcf011e90), (unsigned short)q);
    FUN_a00f308c(RP(0xcf011e98), w);
    FUN_a00f308c(RP(0xcf011ea0), 8);
    FUN_a00f308c(RP(0xcf011ea8), 4);
    FUN_a00f308c(RP(0xcf011eb0), 8);
    FUN_a00f308c(RP(0xcf011eb8), h);
    R(0xcf011cc0) = 0;
    if (t->h3a.b15) {
        R(0xcf011cc4) = 0x20;
        R(0xcf011ec0) &= ~0x80;
    } else {
        R(0xcf011cc4) = 0xa0;
        R(0xcf011ec0) |= 0x80;
    }
    R(0xcf011cc8) = 0;
    func_0x4008d1a0(100);
    if (f) {
        R(0xcf0116d0) = v - 1;
        FUN_a00df170(s_0019abe8, 4, 1);
        R(0xcf011800) |= 0x10;
        R(0xcf011a00) |= 0x10;
        R(0xcf011bf8) |= 0x10;
    } else if (t->h3a.b15) {
        R(0xcf0116d0) = 0;
        FUN_a00df170(s_0019abe8, 4, 1);
        R(0xcf011800) |= 0x10;
        R(0xcf011a00) |= 0x10;
        R(0xcf011bf8) |= 0x10;
    } else {
        R(0xcf0116d0) = 0;
        FUN_a00df170(s_0019abe8, 4, 0);
        R(0xcf011bf8) &= ~0x10;
        R(0xcf011a00) &= ~0x10;
        R(0xcf011800) &= ~0x10;
    }

    if (t->h3a.b15) {
        R(0xcf011a84) |= 0x10;
        R(0xcf011a88) |= 0x10;
        R(0xcf011a8c) &= ~0x10;
        R(0xcf011dc8) &= ~0x10;
        d = 0;
        if (w & 0x1f)
            d = w / 32 * 32 - w + 0x20;
        R(0xcf011ddc) = d;
    } else {
        R(0xcf011dc8) &= ~0x10;
        R(0xcf011a84) |= 0x10;
        R(0xcf011a88) &= ~0x10;
        R(0xcf011a8c) &= ~0x10;
        FUN_a00f232c(ch, 0x90, 0x20, 1);
    }
    FUN_a00f308c(RP(0xcf011d08), t->h0a >> 2);
    FUN_a00f308c(RP(0xcf011d00), 0);
    FUN_a00f308c(RP(0xcf011d18), 0);
    FUN_a00f308c(RP(0xcf011d10), 0);
}
