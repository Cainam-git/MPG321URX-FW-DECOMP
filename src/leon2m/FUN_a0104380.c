/* leon2m FUN_a0104380 @ 0xa0104380-0xa01045a0 (544 bytes)  correct a clock value from measured register-block counts
 * (hand; -mcpu=v8 -O3 -g, also -O3 -g -msoft-float and -O3; jf.py 100 %, ).
 *
 * void FUN_a0104380(ch, clk): ch = block number of the 0x19A2EC register-block family (FUN_a00f2254 read8,
 *   FUN_a00f2298 write8, FUN_a00f25f8 read16, FUN_a00f2488 write16, FUN_a00f2708 stable read16); clk = pointer to
 *   a 64-bit clock value (Hz, it is handed to FUN_a01026e8 channel 0 = GPLL_DISPM).
 *   1. Saves regs 0x50, 0x86, 0x88 of block ch into DAT_a802c982, DAT_a802c984, DAT_a802c983 (bytes).
 *   2. 0xCF00EAC8: saved, bit 4 cleared, 0xCF00E9C4 bit 7 set, then 0xCF00EAC8 = saved low byte (bits 8-31 cleared).
 *   3. FUN_a0118a28(ch, 0) (clears bit 0 of reg 0x10); reg 0x54 = 0; n = read16(0x71); write16(0x64, n);
 *      reg 0x50 = saved 0x50 | 0x20.
 *   4. m = stable read16(0x84); d = (10m > 9n) ? (10m - 9n) / 10 : (10m + n) / 10 (signed int maths, kept as short).
 *   5. h = stable read16(0x82); only if row +0x20 <= h <= row +0x24 (transformed row *DAT_a802d6a4, u16 fields):
 *      *clk -= (int)(*clk * d * 100 / n / h / 100)   (64-bit, unsigned divisions = __udivdi3 FUN_a0155208),
 *      then FUN_a01026e8(0, low 32 bits of *clk).
 *   6. Always: reg 0x86 = 1, reg 0x88 = 6.
 * Callers: FUN_a013dc6c (one call).
 * PANEL ROW FIELDS READ: transformed row +0x20 and +0x24 (bounds for reg 0x82).
 * keys: n and m are int (callee returns unsigned short, zero-extended right after the call; an
 *   unsigned short variable gives other registers); d is short (gives the srl in the else division).
 */
#define R(a) (*(volatile unsigned int *)(a))
struct PanelParam
{
  unsigned int w0;
  unsigned short h4;
  unsigned char b6;
  unsigned char b7;
  unsigned short h08;
  unsigned short h0a;
  unsigned char b0c[4];
  unsigned long long clk_min;
  unsigned long long clk_max;
  unsigned short h20;
  unsigned short h22;
  unsigned short h24;
};
extern struct PanelParam *DAT_a802d6a4;
extern unsigned char DAT_a802c982, DAT_a802c983, DAT_a802c984;
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short FUN_a00f25f8(unsigned char blk, unsigned char reg);
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short FUN_a00f2708(unsigned char blk, unsigned char reg);
extern void FUN_a0118a28();
extern void FUN_a01026e8(unsigned char ch, unsigned int freq);

void FUN_a0104380(unsigned char ch, unsigned long long *clk)
{
    unsigned int save;
    int n71, h84;
    unsigned short h82;
    int a, b;
    short d;

    DAT_a802c982 = FUN_a00f2254(ch, 0x50);
    DAT_a802c984 = FUN_a00f2254(ch, 0x86);
    DAT_a802c983 = FUN_a00f2254(ch, 0x88);
    save = R(0xcf00eac8);
    R(0xcf00eac8) &= ~0x10;
    R(0xcf00e9c4) |= 0x80;
    R(0xcf00eac8) = save & 0xff;
    FUN_a0118a28(ch, 0);
    FUN_a00f2298(ch, 0x54, 0);
    n71 = FUN_a00f25f8(ch, 0x71);
    FUN_a00f2488(ch, 0x64, n71);
    FUN_a00f2298(ch, 0x50, DAT_a802c982 | 0x20);
    h84 = FUN_a00f2708(ch, 0x84);
    a = h84 * 10;
    b = n71 * 9;
    if (a > b) d = (a - b) / 10;
    else d = (a + n71) / 10;
    h82 = FUN_a00f2708(ch, 0x82);
    if (DAT_a802d6a4->h20 <= h82 && h82 <= DAT_a802d6a4->h24) {
        *clk -= (int)(*clk * d * 100 / n71 / h82 / 100);
        FUN_a01026e8(0, *clk);
    }
    FUN_a00f2298(ch, 0x86, 1);
    FUN_a00f2298(ch, 0x88, 6);
}
