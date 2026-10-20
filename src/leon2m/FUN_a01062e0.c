/* leon2m FUN_a01062e0 @ 0xa01062e0  output block 4 set-up, flags -mcpu=v8 -O3 -g.
 * Source form: h08 is loaded into a temporary early, h26 last; FUN_a00f25f8 returns unsigned short, FUN_a010a8f0 /
 * FUN_a010a494 return int, a and b are int; the FRC-on test is written positive first.
 *
 * Programs register block 4 of the 0x19A2EC family (0xCF00A800, via FUN_a00f2488 / FUN_a00f2298 /
 * FUN_a00f232c) from the active panel row (DAT_a802d6a4) and two measured values, in one of two recipes:
 *   full != 0: a = b = block 0 reg 0x64 (FRC on: FUN_a010a8f0() twice); regs 0x18 = b, 0x1A = a, 0x61 = 0x12,
 *     0x54 = 0, 0x5B = row +0x2C, 0xBE = row +0x30, 0x5E = row +0x22, 0xA0 = row +0x26, 0x62 = 0x6F = row +0x30 +
 *     +0x32, 0x64 = 0x71 = row +0x0A, 0x66 = 0x73 = row +0x26 + +0x28, 0x68 = 0x75 = row +0x08, 0x79 = row +0x22,
 *     0xBE = row +0x30 again, 0x6E = 1, 0x88 = 0x11, 0x86 = 0x18; then 0xCF00EC04..EC24 (row +0x08 / +0x0A split
 *     into low 8 / high 5 bits), 0xCF00EC00 = 9, 0xCF00ED80 = 0x10.
 *   full == 0: a = block 0 reg 0x68, b = block 0 reg 0x64 (FRC on: FUN_a010a494(), FUN_a010a8f0()); same pattern
 *     with 0x5B = row +0x2A, 0xBE = 1, 0x5E = 0x79 = row +0x20, 0x62 = 0x6F = 2, bit 5 of reg 0x50 cleared; then
 *     the same 0xCF00EC.. writes, and 0xCF00ED80 = 0x10 plus block 4 reg 0x8D = 8 only when (row word0 &
 *     0x700000) == 0x200000 and display mode 8..10, else 0xCF00ED80 = 0.
 * The first parameter is not used. Caller: FUN_a013dc6c.
 * Display modes 5 and 11 behave the same here (neither is 8..10).
 */
#define R(a) (*(volatile unsigned int *)(a))
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; unsigned char b0c[0x14];
                    unsigned short h20, h22; unsigned char b24[2]; unsigned short h26, h28, h2a, h2c, h2e, h30, h32; };
extern struct PanelParam *DAT_a802d6a4;
extern unsigned char FUN_a010a864(void);
extern unsigned short FUN_a00f25f8(int, int);
extern int FUN_a010a8f0(void);
extern int FUN_a010a494(void);
extern void FUN_a00f2488(unsigned char, unsigned char, unsigned short);
extern void FUN_a00f2298(unsigned char, unsigned char, unsigned char);
extern void FUN_a00f232c(unsigned char, unsigned char, unsigned int, unsigned char);
void FUN_a01062e0(int unused, unsigned char full)
{
    int a, b;
    unsigned short h26, h30, h32, h22, t08, h2c, h28, h0a, h08, h20, h2a;
    if (full) {
        if (FUN_a010a864()) { a = FUN_a010a8f0(); b = FUN_a010a8f0(); }
        else { a = FUN_a00f25f8(0, 0x64); b = FUN_a00f25f8(0, 0x64); }
        /* load order as the original schedules it (h08 is read early into a temporary, h26 last) */
        h30 = DAT_a802d6a4->h30; h32 = DAT_a802d6a4->h32; t08 = DAT_a802d6a4->h08; h22 = DAT_a802d6a4->h22;
        h2c = DAT_a802d6a4->h2c; h28 = DAT_a802d6a4->h28; h0a = DAT_a802d6a4->h0a; h26 = DAT_a802d6a4->h26;
        h08 = t08;
        FUN_a00f2488(4, 0x18, b);
        FUN_a00f2488(4, 0x1a, a);
        FUN_a00f2298(4, 0x61, 0x12);
        FUN_a00f2298(4, 0x54, 0);
        FUN_a00f2488(4, 0x5b, h2c);
        FUN_a00f2488(4, 0xbe, h30);
        FUN_a00f2488(4, 0x5e, h22);
        FUN_a00f2488(4, 0xa0, h26);
        FUN_a00f2488(4, 0x62, (unsigned short)(h30 + h32));
        FUN_a00f2488(4, 0x64, h0a);
        FUN_a00f2488(4, 0x66, (unsigned short)(h26 + h28));
        FUN_a00f2488(4, 0x68, h08);
        FUN_a00f2488(4, 0x6f, (unsigned short)(h30 + h32));
        FUN_a00f2488(4, 0x71, h0a);
        FUN_a00f2488(4, 0x73, (unsigned short)(h26 + h28));
        FUN_a00f2488(4, 0x75, h08);
        FUN_a00f2488(4, 0x79, h22);
        FUN_a00f2488(4, 0xbe, h30);
        FUN_a00f2298(4, 0x6e, 1);
        FUN_a00f2298(4, 0x88, 0x11);
        FUN_a00f2298(4, 0x86, 0x18);
        R(0xcf00ec04) = 0; R(0xcf00ec08) = 0; R(0xcf00ec0c) = 0;
        R(0xcf00ec10) = h08 & 0xff; R(0xcf00ec14) = (h08 >> 8) & 0x1f;
        R(0xcf00ec18) = 0; R(0xcf00ec1c) = 0;
        R(0xcf00ec20) = h0a & 0xff; R(0xcf00ec24) = (h0a >> 8) & 0x1f;
        R(0xcf00ec00) = 9;
        R(0xcf00ed80) = 0x10;
    } else {
        if (FUN_a010a864()) { a = FUN_a010a494(); b = FUN_a010a8f0(); }
        else { a = FUN_a00f25f8(0, 0x68); b = FUN_a00f25f8(0, 0x64); }
        h26 = DAT_a802d6a4->h26; h20 = DAT_a802d6a4->h20; h2a = DAT_a802d6a4->h2a; h08 = DAT_a802d6a4->h08;
        h28 = DAT_a802d6a4->h28; h0a = DAT_a802d6a4->h0a;
        FUN_a00f2488(4, 0x18, b);
        FUN_a00f2488(4, 0x1a, a);
        FUN_a00f2298(4, 0x61, 0x12);
        FUN_a00f2298(4, 0x54, 0);
        FUN_a00f2488(4, 0x5b, h2a);
        FUN_a00f2488(4, 0xbe, 1);
        FUN_a00f2488(4, 0x5e, h20);
        FUN_a00f2488(4, 0xa0, h26);
        FUN_a00f2488(4, 0x62, 2);
        FUN_a00f2488(4, 0x64, h0a);
        FUN_a00f2488(4, 0x66, (unsigned short)(h26 + h28));
        FUN_a00f2488(4, 0x68, h08);
        FUN_a00f2488(4, 0x6f, 2);
        FUN_a00f2488(4, 0x71, h0a);
        FUN_a00f2488(4, 0x73, (unsigned short)(h26 + h28));
        FUN_a00f2488(4, 0x75, h08);
        FUN_a00f2488(4, 0x79, h20);
        FUN_a00f2488(4, 0xbe, 1);
        FUN_a00f232c(4, 0x50, 0x20, 0);
        FUN_a00f2298(4, 0x6e, 1);
        FUN_a00f2298(4, 0x88, 0x11);
        FUN_a00f2298(4, 0x86, 0x18);
        R(0xcf00ec04) = 0; R(0xcf00ec08) = 0; R(0xcf00ec0c) = 0;
        R(0xcf00ec10) = h08 & 0xff; R(0xcf00ec14) = (h08 >> 8) & 0x1f;
        R(0xcf00ec18) = 0; R(0xcf00ec1c) = 0;
        R(0xcf00ec20) = h0a & 0xff; R(0xcf00ec24) = (h0a >> 8) & 0x1f;
        R(0xcf00ec00) = 9;
        if ((DAT_a802d6a4->w0 & 0x700000) == 0x200000 && (unsigned char)(DAT_a802d6a4->b6 - 8) <= 2) {
            FUN_a00f2298(4, 0x8d, 8);
            R(0xcf00ed80) = 0x10;
        } else R(0xcf00ed80) = 0;
    }
}
