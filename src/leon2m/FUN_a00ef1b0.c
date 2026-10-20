/* leon2m FUN_a00ef1b0 @ 0xa00ef1b0-0xa00f0380 (1140 words), flags -mcpu=v8 -O3 -g -msoft-float. BYTE-EXACT
 *: jf 100.00 match=True, rawcmp.py 0 mismatches / 1140 words. Float source: the
 * FUN_a0155xxx callees are libgcc soft-float (c40 __floatsisf, 78c __addsf3, 830 __mulsf3, a18 __divsf3,
 * 1bc __fixunssfsi, d90 __extendsfdf2).
 * What it does: output / pixel-clock set-up of the selected port block (dc6c state 8 step 5 calls
 *   FUN_a00ef1b0(1, 1, &timing copy)). Block a79 = DAT_a8026a79, lane select a78 = DAT_a8026a78 (8 = all 4 lanes of
 *   the u16 table DAT_00199ffc, 0..3 = one lane; register n of lane L = 0xcf000000 | (DAT_00199ffc[L] + n) << 2).
 *   1. tbl = ROM DAT_0019a004 (17 powers of two 2^10..2^26); reg 0x55 = 0; wait 50 ms; div = 2 for ports 6/7, else 8;
 *      lane reg 0 = 0x16; clear bit 5 of reg 0x88.
 *   2. Timing t (8 u16): given != 0 -> htotal w = t[0] rounded up to a multiple of 8, vtotal vt = t[1], the other six
 *      words go to regs 0x64/0x71 (t7), 0xbe (t5), 0x62/0x6f (t3), 0x68/0x75 (t6), 0xa0 (t4), 0x66/0x73 (t2), 0x5e = w,
 *      0x5b = vt (FUN_a00f2488 = 16-bit register write). given == 0 -> scale to the stored target size
 *      ha = DAT_a802b74e, va = DAT_a802b74c: w = t0 * ha / t6, vt = t1 * va / t7, blank d = (w - ha) / 3, e = d
 *      (at least 30 when ha > 2560), f = (w - ha - e) >> 1; regs 0xbe = d, 0x62/0x6f = 2d, 0xa0 = e, 0x66/0x73 = f.
 *   3. clk = w * vt * FUN_a0120b38(a79) / 10 (float; rate in tenths of Hz) -> FUN_a01026e8(a78, clk) (GPLL).
 *      Reg 0x61 bits 0-1 set, reg 0x50 = 0x41, FUN_a0106b08(a79), wait 50 ms, copy regs 0x7c/0x78/0x77 into
 *      0x50 = 1, 0x51 = (r7c >> 4) + 1, 0x52/0x53 = (r78 & 0x7f) << 8 | r77, set reg 0x88 bits 1-2.
 *   4. n = w * vt / div; wait 2 frames (FUN_a0121bcc); m = reg 0x89 (32-bit read); n > 0x380000 and
 *      |n - m| > 0x200000 -> m += 0x400000 (counter wrap); clk = clk * (n / m) (measured correction) ->
 *      FUN_a01026e8(a78, clk) again; clear reg 0x88 bits 1-2. on == 0: return.
 *   5. on != 0: print "p3mpll %lx"; x = clk / 2, / 4 or / 8 above 480/960/1920 MHz; ratio = 480000000 / x; print
 *      "clk_source ... Per_ratio %f"; rate = ratio * 2^24, print "Rate %lx"; lane regs: 7 |= 0x80, 4..7 = rate bytes,
 *      7 &= 0x7f, 1..3 = (n - 1) bytes, 0 = (index of the first table entry > n - 1) + 10 (= bit length of n - 1),
 *      0x10 = 0x98, 0xf = 8, s = w >> 5 (div 8) or w >> 2 (div 2): 0xe = s low byte, 0xf |= (s & 0xf00) >> 4,
 *      0x11 = 6, 0x16 |= 0xc, 0 |= 0x20; DAT_a802b747 = 0 (restarts FUN_a00f0b58's PLL-lock phase 1); reg 0x8e = 3.
 * Rate arithmetic (code only, float32 emulated): with a CTA 4400 x 2250 frame and FUN_a0120b38 = 601
 *   (src/leon2m/FUN_a0120b38.c) the first GPLL value is 9,900,000 * 601 / 10 = 594,989,952 Hz after float rounding
 *   (rate 600: 594,000,000). n = 4400 * 2250 / 8 = 1,237,500 does not depend on the rate; the measured n / m
 *   correction then sets the final clock. Nothing in this function clamps or rejects the rate or the clock: there
 *   is no limit compare on clk, only the 480/960/1920 MHz post-divider choice. FUN_a01070b4 drv_PanelLimitation does
 *   not reject it either (advisory only: its single caller FUN_a014e8d8 discards the bitmask); the 4K cap is the
 *   chosen panel row's max applied in FUN_a013dc6c state 10.
 * Levers (in plain words):
 *   (1) the lane writes are inlined static helpers lane_wr(o, u8 v), lane_or(o, u32 m), lane_and(o, u8 m): the fw
 *       computes the value once before the a78 == 8 / < 4 test;
 *   (2) nested 'if (ha > 0xa00) if (d < 0x1e)', 'd = e = (w - ha) / 3', h4 loaded before h2, the 480000000 dividend
 *       as a local 'src', the 0x77/0x78 copy as '(.. & 0x7f) << 8 | ..' with u16 lo, u8 hi;
 *   (3) 2d is a u16 'd2 = d + d' computed right after f, before the register writes. With a call between the
 *       add and the zero extension, combine cannot fold the add into 'sll 17' (fw keeps add; sll 16; srl 16), and
 *       the 0xbe write then takes d's own extension straight into %o2 like the fw (this fixed 28 of the 35 words);
 *   (4) given arm 'x = w' (unsigned int) right after the rounding, x passed to reg 0x5e. The extension is
 *       computed before a call, sched1 sinks it after that call, and its lower luid puts the fw's srl before the
 *       a79 ldub;
 *   (5) the 7 |= 0x80 mask is passed as (signed char)0x80: the fw ORs with the sign-extended immediate -128
 *       (same low byte, the store keeps only the low byte);
 *   (6) the 0xf = 8 write is lane_wrv(), whose loop body copies the value into a local before the address:
 *       the fw preheader sets 8 before 0xcf000000 (mov 8,%o2; sethi,%o3) only in this one lane loop, while the 0x16,
 *       0x98 and 6 loops set the address first (the lane_wr form). Using the copy form in lane_wr breaks those three.
 * Aids: none (no asm, no barriers, no dummy terms). volatile only on the 0xcf... lane registers. tbl is the fw's own
 *   memcpy (FUN_a013c910) of the ROM table, written as the explicit call like the exact src callers.
 */
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f232c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned int FUN_a00f29d4(unsigned char blk, unsigned char reg);
extern unsigned short FUN_a0120b38(unsigned char blk);
extern void FUN_a0121bcc(unsigned char frames, unsigned short rate);
extern void FUN_a01026e8(unsigned char ch, unsigned int freq);
extern void FUN_a0106b08(unsigned char blk);
extern int abs(int);
extern int FUN_a00df170(const char *fmt, ...);
extern void func_0x4008d1a0(int ms);
extern const unsigned int DAT_0019a004[17];
extern const unsigned short DAT_00199ffc[4];
extern unsigned char DAT_a8026a78, DAT_a8026a79;
extern unsigned char DAT_a802b747;
extern unsigned short DAT_a802b74c, DAT_a802b74e;
extern char s_0019a048[], s_0019a060[], s_0019a088[];

#define MREG(i, o) (*(volatile unsigned int *)(0xcf000000 | ((DAT_00199ffc[i] + (o)) << 2)))
static void lane_wr(unsigned char o, unsigned char v)
{
    unsigned char i;

    if (DAT_a8026a78 == 8) {
        for (i = 0; i < 4; i++)
            MREG(i, o) = v;
    } else if (DAT_a8026a78 < 4)
        MREG(DAT_a8026a78, o) = v;
}

static void lane_wrv(unsigned char o, unsigned char v)
{
    unsigned char i;

    if (DAT_a8026a78 == 8) {
        for (i = 0; i < 4; i++) {
            unsigned int x = v;
            MREG(i, o) = x;
        }
    } else if (DAT_a8026a78 < 4)
        MREG(DAT_a8026a78, o) = v;
}

static void lane_or(unsigned char o, unsigned int m)
{
    unsigned char i;

    if (DAT_a8026a78 == 8) {
        for (i = 0; i < 4; i++)
            MREG(i, o) = (unsigned char)(MREG(i, o) | m);
    } else if (DAT_a8026a78 < 4)
        MREG(DAT_a8026a78, o) = (unsigned char)(MREG(DAT_a8026a78, o) | m);
}

static void lane_and(unsigned char o, unsigned char m)
{
    unsigned char i;

    if (DAT_a8026a78 == 8) {
        for (i = 0; i < 4; i++)
            MREG(i, o) = MREG(i, o) & m;
    } else if (DAT_a8026a78 < 4)
        MREG(DAT_a8026a78, o) = MREG(DAT_a8026a78, o) & m;
}

void FUN_a00ef1b0(unsigned char on, unsigned char given, unsigned short *t)
{
    unsigned int tbl[17];
    unsigned char div, i;
    unsigned short w, vt;
    unsigned int clk, n, m, rate;

    FUN_a013c910(tbl, DAT_0019a004, 0x44);
    FUN_a00f2298(DAT_a8026a79, 0x55, 0);
    func_0x4008d1a0(0x32);
    div = 2;
    if ((unsigned char)(DAT_a8026a79 - 6) > 1)
        div = 8;
    lane_wr(0, 0x16);
    FUN_a00f232c(DAT_a8026a79, 0x88, 0x20, 0);
    if (given) {
        unsigned short h2, h3, h4, h5, h6, h7;
        unsigned int x;
        w = t[0];
        if (w & 7)
            w = w / 8 * 8 + 8;
        x = w;
        vt = t[1];
        h7 = t[7];
        h3 = t[3];
        h5 = t[5];
        h6 = t[6];
        h4 = t[4];
        h2 = t[2];
        FUN_a00f2488(DAT_a8026a79, 0x5b, vt);
        FUN_a00f2488(DAT_a8026a79, 0x64, h7);
        FUN_a00f2488(DAT_a8026a79, 0x71, h7);
        FUN_a00f2488(DAT_a8026a79, 0xbe, h5);
        FUN_a00f2488(DAT_a8026a79, 0x62, h3);
        FUN_a00f2488(DAT_a8026a79, 0x6f, h3);
        FUN_a00f2488(DAT_a8026a79, 0x5e, x);
        FUN_a00f2488(DAT_a8026a79, 0x68, h6);
        FUN_a00f2488(DAT_a8026a79, 0x75, h6);
        FUN_a00f2488(DAT_a8026a79, 0xa0, h4);
        FUN_a00f2488(DAT_a8026a79, 0x66, h2);
        FUN_a00f2488(DAT_a8026a79, 0x73, h2);
    } else {
        unsigned short ha, va, d, e, f, d2;

        ha = DAT_a802b74e;
        w = (t[0] * ha) / t[6];
        va = DAT_a802b74c;
        d = e = (w - ha) / 3;
        vt = (t[1] * va) / t[7];
        if (ha > 0xa00)
            if (d < 0x1e)
                e = 0x1e;
        f = (w - ha - e) >> 1;
        d2 = d + d;
        FUN_a00f2488(DAT_a8026a79, 0x5b, vt);
        FUN_a00f2488(DAT_a8026a79, 0x64, va);
        FUN_a00f2488(DAT_a8026a79, 0x71, va);
        FUN_a00f2488(DAT_a8026a79, 0xbe, d);
        FUN_a00f2488(DAT_a8026a79, 0x62, d2);
        FUN_a00f2488(DAT_a8026a79, 0x6f, d2);
        FUN_a00f2488(DAT_a8026a79, 0x5e, w);
        FUN_a00f2488(DAT_a8026a79, 0x68, ha);
        FUN_a00f2488(DAT_a8026a79, 0x75, ha);
        FUN_a00f2488(DAT_a8026a79, 0xa0, e);
        FUN_a00f2488(DAT_a8026a79, 0x66, f);
        FUN_a00f2488(DAT_a8026a79, 0x73, f);
    }
    clk = (float)w * (int)vt * (int)FUN_a0120b38(DAT_a8026a79) / 10.0f;
    FUN_a01026e8(DAT_a8026a78, clk);
    FUN_a00f232c(DAT_a8026a79, 0x61, 3, 1);
    FUN_a00f2298(DAT_a8026a79, 0x50, 0x41);
    FUN_a0106b08(DAT_a8026a79);
    func_0x4008d1a0(0x32);
    {
        unsigned char hi;
        unsigned short lo;
        hi = FUN_a00f2254(DAT_a8026a79, 0x7c) >> 4;
        lo = (FUN_a00f2254(DAT_a8026a79, 0x78) & 0x7f) << 8 | FUN_a00f2254(DAT_a8026a79, 0x77);
        FUN_a00f2298(DAT_a8026a79, 0x50, 1);
        FUN_a00f2298(DAT_a8026a79, 0x51, hi + 1);
        FUN_a00f2298(DAT_a8026a79, 0x52, lo);
        FUN_a00f2298(DAT_a8026a79, 0x53, lo >> 8);
    }
    FUN_a00f232c(DAT_a8026a79, 0x88, 6, 1);
    n = (unsigned int)(w * vt) / div;
    FUN_a0121bcc(2, FUN_a0120b38(DAT_a8026a79));
    m = FUN_a00f29d4(DAT_a8026a79, 0x89);
    if (n > 0x380000 && abs((int)(n - m)) > 0x200000)
        m += 0x400000;
    clk = clk * ((float)n / (float)m);
    FUN_a01026e8(DAT_a8026a78, clk);
    FUN_a00f232c(DAT_a8026a79, 0x88, 6, 0);
    if (!on)
        return;
    FUN_a00df170(s_0019a048, clk);
    if (clk > 479999999) {
        if (clk <= 959999999)
            clk >>= 1;
        else if (clk <= 1919999999)
            clk >>= 2;
        else
            clk >>= 3;
    }
    {
        unsigned int src = 480000000;
        float r = (float)src / clk;
        FUN_a00df170(s_0019a060, src, clk, (double)r);
        rate = r * 16777216.0f;
    }
    FUN_a00df170(s_0019a088, rate);
    lane_or(7, (signed char)0x80);
    lane_wr(4, rate & 0xff);
    lane_wr(5, (rate >> 8) & 0xff);
    lane_wr(6, (rate >> 16) & 0xff);
    lane_wr(7, rate >> 24);
    lane_and(7, 0x7f);
    n = (unsigned int)(w * vt) / div - 1;
    lane_wr(1, n & 0xff);
    lane_wr(2, (n >> 8) & 0xff);
    lane_wr(3, (n >> 16) & 0xff);
    for (i = 0; i < 17; i++)
        if (tbl[i] > n)
            break;
    {
        unsigned char k = i + 10;
        lane_wr(0, k);
    }
    lane_wr(0x10, 0x98);
    lane_wrv(0xf, 8);
    {
        unsigned int s = div == 8 ? w >> 5 : w >> 2;
        lane_wr(0xe, s & 0xff);
        lane_or(0xf, (s & 0xf00) >> 4);
    }
    lane_wr(0x11, 6);
    lane_or(0x16, 0xc);
    lane_or(0, 0x20);
    DAT_a802b747 = 0;
    FUN_a00f2298(DAT_a8026a79, 0x8e, 3);
}
