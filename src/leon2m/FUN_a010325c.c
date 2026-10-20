/* FUN_a010325c (0xa010325c-0xa0103808): output pixel clock calculation.
 * Toolchain sparc-elf-3.4.4, flags: -mcpu=v8 -O3 -g -msoft-float.
 * Facts behind the non-obvious parts (all behaviour-neutral, no inline asm, no no-code hints):
 * - -msoft-float: fixes the 32 FP regs, so loop.c's threshold (1 + n_non_fixed_regs) drops to ~25 and the loads of
 *   t.act / t.vt / 0xcf011a00 stay in the htot loop ('not desirable'), as in the fw. The fw has no FPU insns at all.
 * - struct Tm: leading u32 field puts ht/act/x/vt at fp-36/-30/-18/-14 with frame -136 (no spill once loop.c stops
 *   hoisting).
 * - struct Row: DAT_a802d6a4 is used directly (no cached 'row' local); w0 is a signed 3-bit bitfield 'mode' at bits
 *   22..20 (big-endian MSB-first layout): 'mode == 2' gives the and 0x700000 / cmp 0x200000 form and its struct
 *   alias set makes the w0 load reload every iteration (r->clk store conflicts), as in the fw.
 * - struct In: h3a bit 14 as a 1-bit unsigned short bitfield f14 (gives the fw's andcc operand order).
 * - FUN_a00df170 is declared 'int (...)' (printf-like); 'void' changes the arg-setup order around both calls.
 * - Format strings are DAT_0019a7d8 / DAT_0019a7f0 / DAT_0019a828.
 */
struct In { unsigned short h0, h2, h4, h6, h8, ha, hc, he, h10, h12; unsigned char pad14[0x26]; unsigned short h3a_hi : 1, f14 : 1, h3a_lo : 14; };
struct Rec { unsigned short h0, h2, h4, h6, h8, ha, hc, he; unsigned char pad10[8]; unsigned long long clk; unsigned char b20; };
struct Tm { unsigned int w0; unsigned short ht, h2, h4, act; unsigned int w8; unsigned short hc, he, h10, x, h14, vt; };
struct Row { int w0a : 9, mode : 3, w0b : 20; unsigned short h4; unsigned char b6, b7; unsigned short h8; unsigned char pada[6];
             unsigned long long win; unsigned char pad18[8]; unsigned short h20, h22, h24; };
extern struct Row *DAT_a802d6a4;
extern unsigned char FUN_a00f2254(unsigned char port, unsigned char reg);
extern void FUN_a00f2298(unsigned char port, unsigned char reg, unsigned char val);
extern void FUN_a00f232c(unsigned char port, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char FUN_a0121258(unsigned char port);
extern unsigned short FUN_a0120c90(unsigned char port);
extern int FUN_a00df170(const char *fmt, ...);
extern const char DAT_0019a7d8[], DAT_0019a7f0[], DAT_0019a828[];
extern void FUN_a00f2488(unsigned char port, unsigned char reg, unsigned short val);
extern void FUN_a01026e8(unsigned char ch, unsigned int hz);
#define R(a) (*(volatile unsigned int *)(a))

unsigned int FUN_a010325c(unsigned char port, int unused, unsigned char dbl, struct In *in, struct Rec *r)
{
    struct Tm t;
    unsigned short s, start;
    unsigned char il;
    unsigned int q, lim;

    FUN_a00f2298(port, 0x55, FUN_a00f2254(port, 0x55) & 0xf0);
    FUN_a00f232c(port, 0x50, 4, 1);
    FUN_a00f232c(port, 0x50, 0x20, 1);
    FUN_a00f2298(port, 0x6e, 7);
    t.vt = in->h12;
    if (FUN_a0121258(port) && (!dbl || !in->f14))
        il = 1;
    else
        il = 0;
    t.act = r->hc + r->b20;
    t.ht = r->h0;
    t.x = FUN_a0120c90(port);
    start = DAT_a802d6a4->h8;
    s = DAT_a802d6a4->h20;
    if (s < start + 0xe0)
        s = ((start + 0xe4) >> 3) << 3;
    if (port == 0 && r->h2 == start) {
        for (t.ht = s; t.ht < DAT_a802d6a4->h24; t.ht += 8) {
            if (DAT_a802d6a4->mode == 2 && (unsigned char)(DAT_a802d6a4->b6 - 8) <= 2 && (t.ht & 0xf) != 0)
                continue;
            q = ((unsigned long long)t.ht * 100 - 10) * t.act / t.vt / 100;
            r->clk = (unsigned int)(in->h0 * q * 100);
            if (il == 1)
                r->clk <<= 1;
            if ((R(0xcf011a00) & 0x10) && dbl)
                r->clk = r->clk * in->h8 / (R(0xcf011ce0) | R(0xcf011ce4) << 8);
            if (r->clk > DAT_a802d6a4->win)
                break;
        }
        if (t.ht > DAT_a802d6a4->h24 && t.ht > s)
            t.ht -= 8;
    }
    FUN_a00df170(DAT_0019a7d8, t.ht);
    r->h0 = t.ht;
    FUN_a00f2488(port, 0x64, r->ha);
    FUN_a00f2488(port, 0x71, t.act);
    q = ((unsigned long long)t.ht * 100 - 10) * t.act / t.vt / 100;
    if (q == 0)
        q = 1;
    r->clk = (unsigned int)(in->h0 * q * 100);
    FUN_a00df170(DAT_0019a7f0, port, (unsigned int)r->clk);
    if (il == 1)
        r->clk <<= 1;
    if (port == 0 && (R(0xcf011a00) & 0x10) && dbl) {
        r->clk = r->clk * in->h8 / (R(0xcf011ce0) | R(0xcf011ce4) << 8);
    } else {
        lim = (unsigned int)in->h8 * in->ha / 10 * in->h2 / 10;
        if (lim < 50000000)
            lim = 50000000;
        if (r->clk < lim) {
            r->h0 = (unsigned long long)r->h0 * lim / r->clk;
            r->clk = lim;
        }
    }
    FUN_a00df170(DAT_0019a828, port, (unsigned int)r->clk);
    FUN_a01026e8(port, (unsigned int)r->clk);
    return 1;
}
