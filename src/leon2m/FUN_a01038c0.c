/* leon2m FUN_a01038c0 @ 0xa01038c0..0xa01042c8  display output timing set-up for one channel
 * Flags: -mcpu=v8 -O3 -g -msoft-float, also at -mcpu=v8 -O3 -g.
 *
 * Called by the port state machine FUN_a013dc6c in MODE_DISPLAY sub-step 2 (ch = output block, in = input timing
 * record (0x3C bytes, copied to a local), out = output timing record, flag, p7 = 7th argument (stack byte)).
 * 1. htot = out->h00. If FUN_a0121258(ch) is set, or for ch 1 with in = 3840 x 2160, h10 0x108, h12 0x10e and
 *    in->h02 > 1600: clear bit 0x20 of register 0x50 of block ch. Otherwise read the measured htotal
 *    FUN_a00f2708(ch, 0x82) and take it when it is within +-4 of htot (unsigned range check).
 * 2. vt = (pclk * 100 / htot / in->h02 + 5) / 10, 64-bit (__udivdi3).
 *    flag set: vt is raised to at least panel h30 + h32 + h0a + 1 (panel = *DAT_a802d6a4); otherwise (or when vt is
 *    already above that) to at least reg62 + reg64 + 0x10 (FUN_a00f25f8). When panel h0a == reg64 and vt < panel h2a:
 *    prints s_0019a858 ("\x1b[1;33mwarning: (%d)display vtotal (%d) < (%d)\r\n",
 *    leon2m_data +0x22858) and uses panel h2a.
 * 3. Writes vt to reg 0x5b; if out->w20 bit 20: reg 0x62 = h30 + h32, reg 0x6f = h30 + h32 + (h0a - out->h0a) / 2;
 *    reg 0x5e = htot; copies *in; clears 0xf0 of reg 0x53; for ch <= 3 stores reg 0x7c >> 4 and reg 0x77 & 0x7fff in
 *    the 0xA802D680 block (lvl[ch] at +0x15, rate[ch] at +0x1a).
 * 4. Sets bit 0x40 of reg 0x50 and writes reg 0x55 = (reg55 & 0xf0) | ((reg7c >> 4) + 3), with bit 0x80 set when
 *    FUN_a0121258(ch), cleared by FUN_a00f232c otherwise.
 * 5. Unless (R(0xCF01166C) & 3) == ch and p7 != 0: copies *in again and, when FUN_a0121258(ch), runs the frame-lock
 *    re-check (saves regs 0x54/0x50/0x88 and R(0xCF012890), with flag: toggles bit 0x80 of R(0xCF00E9C4) around it;
 *    retry sequences on |reg 0xdc - reg 0xde| via FUN_a00f8e2c/FUN_a00f8e44 offsets 0, 0xffff, 1 and 10-frame waits
 *    FUN_a0121bcc(10, buf.h02), or the 0x0c/0x0e swap path), then restores them.
 * 6. Sets bit 0x20 of reg 0x90 unless in->h10 == out->h04 and in->h12 == out->h0c.
 * Field names hNN = byte offset.
 *
 * keys: (a) the first test is the BOOL idiom 'tc = FUN_a0121258(ch) ? 1 : 0; if (tc == 1)':
 *   the code is the same btst/bne as 'if (tc)', but at branch-prediction time it is an '== 1' test (opcode heuristic,
 *   not taken), which lowers that block's estimated frequency and moves it behind the frame-lock block in the layout
 *   (95.95 -> 100 %); (b) the htotal candidate held in an unsigned short (rs); (c) the false-path reg 0x7c value held
 *   in an unsigned int, the true-path ((v >> 4) + 3) computed before the reg 0x55 read; (d) unsigned char t/t2 for
 *   the saved register words (the write-back stores the low byte, as the firmware's 'and 0xff'); (e) FUN_a00f8e44
 *   declared void here; (f) builtin abs(); (g) s = buf.h16 read before FUN_a00f8e2c(ch, 0); (h) 'ch != (R & 3)'.
 *   htot, vt and x live in one 16-byte local struct (stack slots fp-20/-18/-14), buf at fp-88.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct InT  { unsigned short h00, h02; unsigned char p04[8]; unsigned short h0c, h0e, h10, h12, h14, h16; unsigned char rest[0x24]; };
struct OutT { unsigned short h00, h02, h04, h06, h08, h0a, h0c, h0e; unsigned char p10[8]; unsigned long long pclk; unsigned int w20; };
struct Panel { unsigned char p00[0xa]; unsigned short h0a; unsigned char p0c[0x1e]; unsigned short h2a; unsigned char p2c[4]; unsigned short h30, h32; };
extern struct Panel *DAT_a802d6a4;
struct OutCfg { unsigned char p00[0x15]; unsigned char lvl[4]; unsigned char p19; unsigned short rate[4]; };
extern struct OutCfg DAT_a802d680;
extern unsigned char FUN_a0121258(unsigned char);
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short FUN_a00f2708(unsigned char blk, unsigned char reg);
extern unsigned short FUN_a00f25f8(unsigned char blk, unsigned char reg);
extern void FUN_a00f232c(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern unsigned short FUN_a00f1ce4(unsigned char blk, unsigned char reg);
extern void FUN_a00f1d48(unsigned char blk, unsigned char reg, unsigned short val);
extern void FUN_a00f8e2c(unsigned char blk, unsigned short v);
extern void FUN_a00f8e44(unsigned char blk, unsigned short v);
extern void FUN_a0121bcc(unsigned char frames, unsigned short rate);
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern int FUN_a00df170();
extern char s_0019a858[];

extern int abs(int);

void FUN_a01038c0(unsigned char ch, int unused1, unsigned char flag, struct InT *in, struct OutT *out, int unused5,
                  unsigned char p7)
{
    struct { unsigned short pad0[2]; unsigned short htot, vt, pad, x; unsigned short pad1[2]; } L;
    struct InT buf;
    unsigned short a, b, s;
    unsigned char t;
    unsigned char t2;
    unsigned char tc;
    unsigned char v, w;
    unsigned int vi;
    unsigned short rs;
    unsigned char v4, v5, v6;

    tc = FUN_a0121258(ch) ? 1 : 0;
    L.htot = out->h00;
    L.x = out->h0a;
    if (tc == 1) {
        FUN_a00f2298(ch, 0x50, FUN_a00f2254(ch, 0x50) & 0xdf);
    } else if (ch == 1 && in->h0c == 0xf00 && in->h0e == 0x870 && in->h10 == 0x108 && in->h12 == 0x10e
               && in->h02 > 0x640) {
        FUN_a00f2298(ch, 0x50, FUN_a00f2254(ch, 0x50) & 0xdf);
    } else {
        rs = FUN_a00f2708(ch, 0x82);
        if ((unsigned int)(rs - L.htot + 4) <= 8) L.htot = rs;
    }
    L.vt = ((out->pclk * 100 / L.htot) / in->h02 + 5) / 10;
    a = FUN_a00f25f8(ch, 0x62);
    b = FUN_a00f25f8(ch, 0x64);
    if (flag && L.vt <= DAT_a802d6a4->h30 + DAT_a802d6a4->h32 + DAT_a802d6a4->h0a)
        L.vt = DAT_a802d6a4->h30 + DAT_a802d6a4->h32 + DAT_a802d6a4->h0a + 1;
    else if (L.vt <= a + b)
        L.vt = a + b + 0x10;
    if (DAT_a802d6a4->h0a == b && L.vt < DAT_a802d6a4->h2a) {
        FUN_a00df170(s_0019a858, ch, L.vt, DAT_a802d6a4->h2a);
        L.vt = DAT_a802d6a4->h2a;
    }
    FUN_a00f2488(ch, 0x5b, L.vt);
    if (out->w20 & 0x100000) {
        FUN_a00f2488(ch, 0x62, DAT_a802d6a4->h30 + DAT_a802d6a4->h32);
        FUN_a00f2488(ch, 0x6f, DAT_a802d6a4->h30 + DAT_a802d6a4->h32 + (DAT_a802d6a4->h0a - L.x) / 2);
    }
    FUN_a00f2488(ch, 0x5e, L.htot);
    FUN_a013c910(&buf, in, 0x3c);
    FUN_a00f232c(ch, 0x53, 0xf0, 0);
    if (ch <= 3) {
        DAT_a802d680.lvl[ch] = FUN_a00f2254(ch, 0x7c) >> 4;
        DAT_a802d680.rate[ch] = FUN_a00f2708(ch, 0x77) & 0x7fff;
    }
    if (FUN_a0121258(ch)) {
        FUN_a00f232c(ch, 0x50, 0x40, 1);
        v = (FUN_a00f2254(ch, 0x7c) >> 4) + 3;
        w = FUN_a00f2254(ch, 0x55);
        FUN_a00f2298(ch, 0x55, v | (w & 0xf0) | 0x80);
    } else {
        FUN_a00f232c(ch, 0x50, 0x40, 1);
        vi = FUN_a00f2254(ch, 0x7c);
        w = FUN_a00f2254(ch, 0x55);
        FUN_a00f2298(ch, 0x55, (w & 0xf0) | ((vi >> 4) + 3));
        FUN_a00f232c(ch, 0x55, 0x80, 0);
    }
    if (ch != (R(0xcf01166c) & 3) || p7 == 0) {
        FUN_a013c910(&buf, in, 0x3c);
        if (FUN_a0121258(ch)) {
            v5 = FUN_a00f2254(ch, 0x54);
            v4 = FUN_a00f2254(ch, 0x50);
            v6 = FUN_a00f2254(ch, 0x88);
            if (flag) {
                t = R(0xcf00eac8); R(0xcf00eac8) = R(0xcf00eac8) & ~0x10;
                R(0xcf00e9c4) = R(0xcf00e9c4) | 0x80;
                R(0xcf00eac8) = t;
            }
            FUN_a00f2298(ch, 0x54, 0);
            t2 = R(0xcf012890);
            R(0xcf012890) = R(0xcf012890) & ~1;
            R(0xcf012990) = R(0xcf012990) & ~1;
            if ((FUN_a00f1a90(ch, 4) & 0xf) <= 1) {
                FUN_a00f2298(ch, 0x6e, 7);
                s = buf.h16;
                FUN_a00f8e2c(ch, 0);
                FUN_a00f8e44(ch, 5);
                FUN_a0121bcc(10, buf.h02);
                if (abs(FUN_a00f2708(ch, 0xdc) - FUN_a00f2708(ch, 0xde)) > 1) {
                    FUN_a00f8e2c(ch, 0xffff);
                    FUN_a00f8e44(ch, 5);
                    FUN_a0121bcc(10, buf.h02);
                    if (abs(FUN_a00f2708(ch, 0xdc) - FUN_a00f2708(ch, 0xde)) > 1) {
                        FUN_a00f8e2c(ch, 1);
                        FUN_a00f8e44(ch, 5);
                        FUN_a0121bcc(10, buf.h02);
                    }
                }
                FUN_a00f8e44(ch, s);
                FUN_a0121bcc(10, buf.h02);
                if (abs(FUN_a00f2708(ch, 0xdc) - FUN_a00f2708(ch, 0xde)) > 1)
                    FUN_a00f2298(ch, 0x6e, 0x47);
            } else {
                unsigned short r1, r2;
                if ((FUN_a00f1a90(ch, 4) & 3) == 3) {
                    FUN_a00f2298(ch, 0x6e, 7);
                } else {
                    FUN_a00f2298(ch, 0x6e, 7);
                    if (abs(FUN_a00f1ce4(ch, 0xc) - FUN_a00f1ce4(ch, 0xe)) <= 0) {
                        FUN_a00f1b5c(ch, 0x56, 1, 0);
                    } else if ((FUN_a00f1a90(ch, 0x56) & 1) == 0) {
                        unsigned short e, c;
                        FUN_a00f1b5c(ch, 0x56, 1, 1);
                        e = FUN_a00f1ce4(ch, 0xe); c = FUN_a00f1ce4(ch, 0xc);
                        FUN_a00f1d48(ch, 0xe, c); FUN_a00f1d48(ch, 0xc, e);
                    }
                    FUN_a0121bcc(10, buf.h02);
                    r1 = FUN_a00f2708(ch, 0xdc);
                    r2 = FUN_a00f2708(ch, 0xde);
                    if (abs(FUN_a00f2708(ch, 0xdc) - FUN_a00f2708(ch, 0xde)) > 1) {
                        FUN_a00f232c(ch, 0x6e, 0x40, 1);
                        FUN_a0121bcc(10, buf.h02);
                        if (abs(r1 - FUN_a00f2708(ch, 0xdc)) > 5 || abs(r2 - FUN_a00f2708(ch, 0xde)) > 5) {
                            unsigned short e, c;
                            e = FUN_a00f1ce4(ch, 0xe); c = FUN_a00f1ce4(ch, 0xc);
                            FUN_a00f1d48(ch, 0xe, c); FUN_a00f1d48(ch, 0xc, e);
                        }
                    }
                }
            }
            R(0xcf012890) = t2;
            FUN_a00f2298(ch, 0x54, v5);
            FUN_a00f2298(ch, 0x50, v4);
            FUN_a00f2298(ch, 0x88, v6);
            if (flag) {
                t = R(0xcf00eac8); R(0xcf00eac8) = R(0xcf00eac8) & ~0x10;
                R(0xcf00e9c4) = R(0xcf00e9c4) & ~0x80;
                R(0xcf00eac8) = t;
            }
        }
    }
    if (in->h10 == out->h04 && in->h12 == out->h0c)
        FUN_a00f232c(ch, 0x90, 0x20, 0);
    else
        FUN_a00f232c(ch, 0x90, 0x20, 1);
}
