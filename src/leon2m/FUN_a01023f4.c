/* leon2m FUN_a01023f4 @ 0xa01023f4  output timing apply, flags -mcpu=v8 -O3 -g.
 * Source form: the register macro is written "volatile unsigned long" instead of "unsigned int" (same 32-bit width
 * on SPARC v8, different alias type, so gcc places the cfg +8 reload later); the working value is an unsigned char
 * that starts at 0x61 and is overwritten with 0xE1, and the display-mode test is written "!= 0" first, which gives
 * the firmware's branches.
 *
 * Programs output timing block 'blk' (0x19A2EC register family, FUN_a00f2488 16-bit writes) from the active
 * transformed panel row (DAT_a802d6a4) and the output configuration at 0xA802D680:
 *   0xCF00ED40 = low byte of: 0xE1 (row word0 bit 23 set) or 0x61, OR (cfg +4) << 3, OR 0x10 when row word0 bits
 *   20..22 == 1, bit 2 set when the display mode (cfg +8) is 0 else cleared, bit 1 set when row word0 bit 25 and
 *   cfg byte +2 are both set, else cleared;
 *   0xCF00EDE4 = cfg byte +0x0D when the display mode is above 2; FUN_a0101e9c(display mode);
 *   block registers: 0x5B = row +0x2C, 0xBE = low byte of row +0x30, 0x62 = 0x6F = row +0x30 + +0x32,
 *   0x64 = 0x71 = row +0x0A (active lines), 0x5E = 0x79 = row +0x22, 0xA0 = row +0x26, 0x66 = 0x73 = row +0x26 +
 *   +0x28, 0x68 = 0x75 = row +0x08 (active width);
 *   func_0x4008e69c(0/1, 0x5D, low byte of row +0x30) and FUN_a011919c(0/1, 0x62, row +0x30 + +0x32).
 * Callers: FUN_a01483f4 (apply != 0, blk 0), FUN_a0105150 (blk 8 = all), FUN_a0106d64, FUN_a0106bfc,
 * FUN_a01295e4 (OLED FRC handler on FRC power-up).
 * Display modes 5 and 11 behave the same here (both > 2, both non-zero).
 */
#define R(a) (*(volatile unsigned long *)(a))
struct OutCfg { unsigned char b0, b1, b2, b3; unsigned int w4, w8; unsigned char bc, bd, be, bf; unsigned int rest[5]; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; unsigned char b0c[0x14];
                    unsigned short h20, h22, h24, h26, h28, h2a, h2c, h2e, h30, h32; };
extern struct OutCfg DAT_a802d680;
extern struct PanelParam *DAT_a802d6a4;
extern void FUN_a0101e9c(unsigned char);
extern void FUN_a00f2488(unsigned char, unsigned char, unsigned short);
extern void func_0x4008e69c(int, int, int);
extern void FUN_a011919c(int, int, unsigned short);
void FUN_a01023f4(unsigned char blk)
{
    unsigned char v;
    v = 0x61;
    if (DAT_a802d6a4->w0 & 0x800000) v = 0xe1;
    v = DAT_a802d680.w4 << 3 | v;
    if ((DAT_a802d6a4->w0 & 0x700000) == 0x100000) v |= 0x10;
    if (DAT_a802d680.w8 != 0) v &= 0xfb; else v |= 4;
    if ((DAT_a802d6a4->w0 & 0x2000000) && DAT_a802d680.b2 != 0) v |= 2; else v &= 0xfd;
    R(0xcf00ed40) = v & 0xff;
    if (DAT_a802d680.w8 > 2) R(0xcf00ede4) = DAT_a802d680.bd;
    FUN_a0101e9c(DAT_a802d680.w8);
    FUN_a00f2488(blk, 0x5b, DAT_a802d6a4->h2c);
    FUN_a00f2488(blk, 0xbe, ((unsigned char *)&DAT_a802d6a4->h30)[1]);
    FUN_a00f2488(blk, 0x62, DAT_a802d6a4->h30 + DAT_a802d6a4->h32);
    FUN_a00f2488(blk, 0x64, DAT_a802d6a4->h0a);
    FUN_a00f2488(blk, 0x6f, DAT_a802d6a4->h30 + DAT_a802d6a4->h32);
    FUN_a00f2488(blk, 0x71, DAT_a802d6a4->h0a);
    FUN_a00f2488(blk, 0x5e, DAT_a802d6a4->h22);
    FUN_a00f2488(blk, 0xa0, DAT_a802d6a4->h26);
    FUN_a00f2488(blk, 0x66, DAT_a802d6a4->h26 + DAT_a802d6a4->h28);
    FUN_a00f2488(blk, 0x68, DAT_a802d6a4->h08);
    FUN_a00f2488(blk, 0x73, DAT_a802d6a4->h26 + DAT_a802d6a4->h28);
    FUN_a00f2488(blk, 0x75, DAT_a802d6a4->h08);
    FUN_a00f2488(blk, 0x79, DAT_a802d6a4->h22);
    func_0x4008e69c(0, 0x5d, ((unsigned char *)&DAT_a802d6a4->h30)[1]);
    FUN_a011919c(0, 0x62, DAT_a802d6a4->h30 + DAT_a802d6a4->h32);
    func_0x4008e69c(1, 0x5d, ((unsigned char *)&DAT_a802d6a4->h30)[1]);
    FUN_a011919c(1, 0x62, DAT_a802d6a4->h30 + DAT_a802d6a4->h32);
}
