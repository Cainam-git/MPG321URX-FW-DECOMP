/* leon2m FUN_a01045a0 @ 0xa01045a0-0xa0104a34 (1172 bytes)  measure and correct the output clock (second half of
 * FUN_a0104380, same block registers and saved bytes)
 * Flags: -mcpu=v8 -O3 -g -msoft-float.
 *
 * void FUN_a01045a0(ch, clk, rate): ch = register block (0x19A2EC family), clk = 64-bit clock in Hz, rate = refresh
 *   in 0.1 Hz for the frame waits FUN_a0121bcc(1, rate).
 *   n = read16(0x71); lim = (row +0x0A * row +0x08) >> 3 (transformed row *DAT_a802d6a4); delay 100.
 *   4 passes: reg 0x88 = 6; wait 1 frame; sum82 += stable read16(0x82);
 *     FUN_a0121258(ch) != 0: a = read24(0x89) (FUN_a00f29d4), wait 1 frame, b = read24(0x89); up to 3 more
 *       re-reads while -15 <= a - b <= 15; v = (a + b) / 2;   else v = read24(0x89);
 *     if lim > 0x3FFFFF and v < lim: v += 0x400000 (24-bit counter wrap);  s1 += v;
 *     reg 0x88 = 2; s2 += read24(0x89).
 *   avg = (sum82 + 2) / 4 (16 bit); avg == 0 or s1 == 0: endless loop of delay(1) (divide-by-zero guard).
 *   r1 = 2*s2 % n; q1 = (9n - 10*r1) / 10 (unsigned); q2 = 2*s1 / avg; r2 = 2*s1 % avg;
 *   x = (short)(r2 + q1 * q2 / n);
 *   t = first of 9avg/6, 7avg/6, 5avg/6, avg/2, avg/6, -(avg/6), -(avg/2) that is < x, else avg/6 (sic);
 *   d = (short)(t - r2); *clk += (int)(*clk * d / q2 / avg) (64-bit, __udivdi3 = FUN_a0155208);
 *   avg odd: *clk = *clk / avg * (avg - 1) and avg -= 1.
 *   reg16 0x5E = avg; FUN_a01026e8(0, low word of *clk) (GPLL_DISPM); reg 0x54 = 2; regs 0x86/0x50 = the bytes
 *   FUN_a0104380 saved (DAT_a802c984/c982); reg16 0x64 = row +0x0A; reg 0x88 = DAT_a802c983.
 * Callers: FUN_a013dc6c (one call, after FUN_a0104380).
 * Row fields read: transformed row +0x08 and +0x0A (lim at entry), +0x0A again at the end.
 * Code facts used: the wrap fix is written in both arms of the FUN_a0121258 test (the firmware computes
 *   'lim > 0x3FFFFF' in both predecessors and cross-jumps the rest); -msoft-float keeps 0x400000 inside the loop;
 *   x is a short variable (gives 'cmp x, K; bg'); the declaration order gives the firmware's loop registers.
 * Source shapes that reproduce the firmware (all behaviour-neutral):
 *   - one 16-bit variable (sum82) holds the loop sum AND the average: sum82 = (sum82 + 2) >> 2 (gives the
 *     firmware's avg register in cc1's global-alloc order);
 *   - avg (16 bit) holds a copy of r2 for d = t - avg: d is short, so only the low 16 bits of r2 matter;
 *   - x = r2; x += q1 * q2 / n: x is short, same low 16 bits as x = r2 + ...; gives the firmware's add operand
 *     order;
 *   - the four counters are cleared in the for header, cnt first (firmware clear order);
 *   - the declaration order is significant: global-alloc ties are broken by pseudo number = declaration order.
 */
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; unsigned short h0a; };
extern struct PanelParam *DAT_a802d6a4;
extern unsigned char DAT_a802c982, DAT_a802c983, DAT_a802c984;
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short FUN_a00f25f8(unsigned char blk, unsigned char reg);
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short FUN_a00f2708(unsigned char blk, unsigned char reg);
extern unsigned int FUN_a00f29d4(unsigned char blk, unsigned char reg);
extern void FUN_a0121bcc(unsigned char frames, unsigned short rate);
extern unsigned char FUN_a0121258(unsigned char);
extern void FUN_a01026e8(unsigned char ch, unsigned int freq);
extern void func_0x4008d1a0(int ms);

void FUN_a01045a0(unsigned char ch, unsigned long long *clk, unsigned short rate)
{
    unsigned short n71;
    unsigned short sum82;
    short d;
    unsigned short q2;
    unsigned int r2;
    unsigned short avg;
    unsigned long long q;
    unsigned int s89a;
    short t;
    short x;
    unsigned int b;
    int diff;
    unsigned char i;
    unsigned short r1;
    unsigned int a;
    unsigned char cnt;
    unsigned int v;
    unsigned int s89b;
    short q1;
    unsigned int lim;

    n71 = FUN_a00f25f8(ch, 0x71);
    lim = (unsigned int)(DAT_a802d6a4->h0a * DAT_a802d6a4->h08) >> 3;
    func_0x4008d1a0(100);
    for (cnt = 0, sum82 = 0, s89a = 0, s89b = 0; cnt < 4; cnt++) {
        FUN_a00f2298(ch, 0x88, 6);
        FUN_a0121bcc(1, rate);
        sum82 += FUN_a00f2708(ch, 0x82);
        if (FUN_a0121258(ch)) {
            a = FUN_a00f29d4(ch, 0x89);
            FUN_a0121bcc(1, rate);
            b = FUN_a00f29d4(ch, 0x89);
            for (i = 0; (diff = a - b) >= -15 && diff <= 15 && i < 3; i++) {
                a = FUN_a00f29d4(ch, 0x89);
                FUN_a0121bcc(1, rate);
                b = FUN_a00f29d4(ch, 0x89);
            }
            v = (a + b) >> 1;
            if (lim > 0x3fffff && v < lim) v += 0x400000;
        } else {
            v = FUN_a00f29d4(ch, 0x89);
            if (lim > 0x3fffff && v < lim) v += 0x400000;
        }
        s89a += v;
        FUN_a00f2298(ch, 0x88, 2);
        s89b += FUN_a00f29d4(ch, 0x89);
    }
    sum82 = (sum82 + 2) >> 2;
    if (sum82 == 0) for (;;) func_0x4008d1a0(1);
    if (s89a == 0) for (;;) func_0x4008d1a0(1);
    r1 = (s89b * 2) % n71;
    q1 = (unsigned int)(n71 * 9 - r1 * 10) / 10;
    q2 = (s89a * 2) / sum82;
    r2 = (s89a * 2) % sum82;
    x = r2; x += q1 * q2 / n71;
    avg = r2;
    if (x > sum82 * 9 / 6) t = sum82 * 9 / 6;
    else if (x > sum82 * 7 / 6) t = sum82 * 7 / 6;
    else if (x > sum82 * 5 / 6) t = sum82 * 5 / 6;
    else if (x > sum82 * 3 / 6) t = sum82 * 3 / 6;
    else if (x > sum82 / 6) t = sum82 / 6;
    else if (x > -(sum82 / 6)) t = -(sum82 / 6);
    else if (x > -(sum82 * 3 / 6)) t = -(sum82 * 3 / 6);
    else t = sum82 / 6;
    d = t - avg;
    q = *clk * d / q2 / sum82;
    *clk += (int)q;
    if (sum82 & 1) {
        *clk = *clk / sum82 * (sum82 - 1);
        sum82--;
        FUN_a00f2488(ch, 0x5e, sum82);
    } else
        FUN_a00f2488(ch, 0x5e, sum82);
    FUN_a01026e8(0, *clk);
    FUN_a00f2298(ch, 0x54, 2);
    FUN_a00f2298(ch, 0x86, DAT_a802c984);
    FUN_a00f2298(ch, 0x50, DAT_a802c982);
    FUN_a00f2488(ch, 0x64, DAT_a802d6a4->h0a);
    FUN_a00f2298(ch, 0x88, DAT_a802c983);
}
