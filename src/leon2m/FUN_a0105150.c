/* leon2m FUN_a0105150 @ 0xa0105150  output path setup, variant A (hand; BYTE-EXACT at
 * -mcpu=v8 -O3 -g)
 *
 * Called by Disp_Init FUN_a0151db4 and FUN_a015209c with a 36-byte output configuration, stored at 0xA802D680
 * (twin logic of FUN_a0106d64 plus more set-up). In order:
 *   FUN_a00f2298 / FUN_a00f232c on block 8 (all blocks): reg 0x8E = 3, 0x8F = 0, 0x24 = 0, set bit 7 of 0x20;
 *   0xCF00ED58 = config byte +0x0C; 0xCF00ED5C = 0x20 when (row word0 & 0x700000) == 0x200000 and display mode
 *   8..10, else 0x40; 0xCF011658 = 0x40; 0xCF00EDA8 = 0; regs 0x6E = 7, 0x86 = 0, 0x88 = 0x10, 0x8D = 0 (all
 *   blocks), with the same condition block 0 reg 0x8D = 8; reg 0x90 bit 6 cleared, bit 5 set; reg 0x54 = 2;
 *   FUN_a01023f4(8); FUN_a01026e8(0..3, x, x/2, x/2, x/4) with x = row word +0x34 / 10 * row halfword +0x22;
 *   output clock paths 0xCF012890.. / 0xCF012990..:
 *     config byte +0 == 0                    -> bit 0 cleared on both
 *     byte +1 != 0, halfword +0x10 == 0      -> bit 0 cleared
 *     byte +1 != 0, f = +0x10, a = +0x12     -> same registers as FUN_a0106d64 (f 25..500 else 100,
 *                                               a 5..5000 else 150; 1500 / f and a * f * 32768 / 15,000,000),
 *                                               bit 0 = row word0 bit 26
 *     byte +1 == 0, halfword +0x0E == 0      -> bit 0 cleared
 *     byte +1 == 0, m = low byte of +0x0E    -> bits 1-4 of 0xCF012890 from m (result truncated to 8 bits) written
 *                                               to BOTH 0xCF012890 and 0xCF012990, then bits 0-4 of 0xCF012890 kept
 *                                               and bits 5-7 from m, written to both; bit 0 = row word0 bit 26
 *   0xCF00E9E0 = 0xCF00E9E4 = 0; byte 0xA802D700 = 0x10 on chip variants > 0x81 (FUN_a011cf88) else 0;
 *   0xCF00B814 = 0xCF00B854 = (that << 2) | 3, 0xCF00B818 = 0xCF00B848 = 3; 0xCF00B81C.. = row +0x30, +0x26,
 *   +0x26 + +0x28, +0x30 + +0x32 (16-bit pairs via FUN_a00f308c); variants > 0x83: bit 5 of 0xCF00B844;
 *   0xCF00EC04/08/0C = 0, 0xCF00EC10/14 = row +0x08 low 8 / bits 8-12, 0xCF00EC18/1C = 0, 0xCF00EC20/24 = row +0x0A
 *   low 8 / bits 8-12; 0xCF00EFC0 = 0xC0; bits 6 and 0 of 0xCF00F1C0; bit 0 of 0xCF011360.
 * Register addresses (proven by the bytes): the firmware loads %hi(0xCF00EC00) in the delay slots of 'bleu,a' / 'b'
 *   at a01055a8 / a01055c0 (the objdump annotation '! 0xcf00e804' is stale), so the registers are 0xCF00EC04..EC24
 *   and 0xCF00EFC0, not 0xCF00E804..E824 and 0xCF00EBC0.
 * Note: the 0xCF012890 bit merge writes the computed value to BOTH 0xCF012890 and 0xCF012990.
 * Display modes 5 and 11 behave the same here (neither is 8..10).
 * BYTE-EXACT keys:
 *   - the f/a clamp exactly as in FUN_a0106d64: t = h10 (unsigned int) and a0 = h12 read before 'if (t != 0)',
 *     f re-read from the record, 'a = a0' before the f range check (f < 25 || f > 500).
 *   - the clock-path tests written as nested if (x != 0) { work } else { clear } (b0, b1, t, he); gcc cross-jumps
 *     three of the clears into one block.
 *   - m = (unsigned char) of halfword +0x0E held in an unsigned int, the test on the 16-bit value; the first merge
 *     assigned to an unsigned char v8, the second to an unsigned int with 'm & ~0x1f'.
 *   - 'if (FUN_a011cf88() <= 0x81) DAT_a802d700 = 0; else DAT_a802d700 = 0x10;' (the ?: form gives subx) and
 *     DAT_a802d700 re-read for 0xCF00B814; the value kept in v for 0xCF00B854 (no register re-read).
 */
#define R(a) (*(volatile unsigned int *)(a))
struct OutCfg { unsigned char b0, b1, b2, b3; unsigned int w4, w8; unsigned char bc, bd; unsigned short he;
                unsigned short h10, h12; unsigned char b14, b15, b16, b17; unsigned int w18, w1c, w20; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; unsigned char b0c[0x16];
                    unsigned short h22; unsigned char b24[2]; unsigned short h26, h28; unsigned char b2a[6];
                    unsigned short h30, h32; unsigned int w34; };
extern struct OutCfg DAT_a802d680;
extern struct PanelParam *DAT_a802d6a4;
extern void FUN_a00f2298(int, int, int);
extern void FUN_a01023f4(int);
extern void FUN_a01026e8(int, unsigned int);
extern void FUN_a00f308c(unsigned int, unsigned int);
extern void FUN_a00f232c(int, int, int, int);
extern unsigned char FUN_a011cf88(void);
extern unsigned char DAT_a802d700;
void FUN_a0105150(struct OutCfg *cfg)
{
    unsigned int v;
    unsigned int x;
    unsigned short f, a;
    unsigned char v8;
    unsigned int mi;
    unsigned int t;
    unsigned short a0;
    DAT_a802d680 = *cfg;
    FUN_a00f2298(8, 0x8e, 3);
    FUN_a00f2298(8, 0x8f, 0);
    FUN_a00f2298(8, 0x24, 0);
    FUN_a00f232c(8, 0x20, 0x80, 1);
    R(0xcf00ed58) = DAT_a802d680.bc;
    if ((DAT_a802d6a4->w0 & 0x700000) == 0x200000 && (unsigned char)(DAT_a802d6a4->b6 - 8) <= 2) R(0xcf00ed5c) = 0x20;
    else R(0xcf00ed5c) = 0x40;
    R(0xcf011658) = 0x40;
    R(0xcf00eda8) = 0;
    FUN_a00f2298(8, 0x6e, 7);
    FUN_a00f2298(8, 0x86, 0);
    FUN_a00f2298(8, 0x88, 0x10);
    FUN_a00f2298(8, 0x8d, 0);
    if ((DAT_a802d6a4->w0 & 0x700000) == 0x200000 && (unsigned char)(DAT_a802d6a4->b6 - 8) <= 2) FUN_a00f2298(0, 0x8d, 8);
    FUN_a00f232c(8, 0x90, 0x40, 0);
    FUN_a00f232c(8, 0x90, 0x20, 1);
    FUN_a00f2298(8, 0x54, 2);
    FUN_a01023f4(8);
    x = DAT_a802d6a4->w34 / 10 * DAT_a802d6a4->h22;
    FUN_a01026e8(0, x);
    FUN_a01026e8(1, x >> 1);
    FUN_a01026e8(2, x >> 1);
    FUN_a01026e8(3, x >> 2);
    if (DAT_a802d680.b0 != 0) {
        if (DAT_a802d680.b1 != 0) {
            t = DAT_a802d680.h10;
            a0 = DAT_a802d680.h12;
            if (t != 0) {
                f = DAT_a802d680.h10;
                a = a0;
                if ((f < 25) || (f > 500)) f = 100;
                if ((a < 5) || (a > 5000)) a = 150;
                R(0xcf012898) = (unsigned char)(1500 / f);
                R(0xcf01289c) = (unsigned char)((((unsigned int)a * f) << 15) / 15000000);
                R(0xcf012898) = R(0xcf012898) | 0x80;
                R(0xcf012998) = (unsigned char)(1500 / f);
                R(0xcf01299c) = (unsigned char)((((unsigned int)a * f) << 15) / 15000000);
                R(0xcf012998) = R(0xcf012998) | 0x80;
                if (DAT_a802d6a4->w0 & 0x4000000) { R(0xcf012890) = R(0xcf012890) | 1; R(0xcf012990) = R(0xcf012990) | 1; }
                else { R(0xcf012890) = R(0xcf012890) & ~1; R(0xcf012990) = R(0xcf012990) & ~1; }
            } else {
                R(0xcf012890) = R(0xcf012890) & ~1;
                R(0xcf012990) = R(0xcf012990) & ~1;
            }
        } else {
            if (DAT_a802d680.he != 0) {
                mi = (unsigned char)DAT_a802d680.he;
                v8 = (R(0xcf012890) & ~0x1e) | (mi & 0x1e);
                R(0xcf012890) = v8;
                R(0xcf012990) = v8;
                v = (R(0xcf012890) & 0x1f) | (mi & ~0x1f);
                R(0xcf012890) = v;
                R(0xcf012990) = v;
                if (DAT_a802d6a4->w0 & 0x4000000) { R(0xcf012890) = R(0xcf012890) | 1; R(0xcf012990) = R(0xcf012990) | 1; }
                else { R(0xcf012890) = R(0xcf012890) & ~1; R(0xcf012990) = R(0xcf012990) & ~1; }
            } else {
                R(0xcf012890) = R(0xcf012890) & ~1;
                R(0xcf012990) = R(0xcf012990) & ~1;
            }
        }
    } else {
        R(0xcf012890) = R(0xcf012890) & ~1;
        R(0xcf012990) = R(0xcf012990) & ~1;
    }
    R(0xcf00e9e0) = 0;
    R(0xcf00e9e4) = 0;
    if (FUN_a011cf88() <= 0x81) DAT_a802d700 = 0;
    else DAT_a802d700 = 0x10;
    v = DAT_a802d700 << 2 | 3;
    R(0xcf00b814) = v;
    R(0xcf00b818) = 3;
    R(0xcf00b848) = 3;
    R(0xcf00b854) = v;
    FUN_a00f308c(0xcf00b81c, DAT_a802d6a4->h30);
    FUN_a00f308c(0xcf00b824, DAT_a802d6a4->h26);
    FUN_a00f308c(0xcf00b82c, DAT_a802d6a4->h26 + DAT_a802d6a4->h28);
    FUN_a00f308c(0xcf00b834, DAT_a802d6a4->h30 + DAT_a802d6a4->h32);
    if (FUN_a011cf88() > 0x83) R(0xcf00b844) = R(0xcf00b844) | 0x20;
    R(0xcf00ec04) = 0;
    R(0xcf00ec08) = 0;
    R(0xcf00ec0c) = 0;
    R(0xcf00ec10) = DAT_a802d6a4->h08 & 0xff;
    R(0xcf00ec14) = (DAT_a802d6a4->h08 >> 8) & 0x1f;
    R(0xcf00ec18) = 0;
    R(0xcf00ec1c) = 0;
    R(0xcf00ec20) = DAT_a802d6a4->h0a & 0xff;
    R(0xcf00ec24) = (DAT_a802d6a4->h0a >> 8) & 0x1f;
    R(0xcf00efc0) = 0xc0;
    R(0xcf00f1c0) = R(0xcf00f1c0) | 0x40;
    R(0xcf00f1c0) = R(0xcf00f1c0) | 1;
    R(0xcf011360) = R(0xcf011360) | 1;
}
