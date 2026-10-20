/* leon2m FUN_a01186e0 @ 0xa01186e0-0xa011898c (684 bytes, 171 words), flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a01186e0(arg): output-block (0xCF012Exx/Fxx) set-up from the transformed panel row.
 *   0xCF009BB8 bit 1 cleared; delay 50 (func_0x4008d1a0 = FUN_a002d1a0); 0xCF012E80 = 4; FUN_a00f2e98(0xF4, 0,
 *   0x400, arg);
 *   0xCF012E40 = 0x71; 0xCF012E44 = 0x10; mode = word +4 of record 0xA8027A98:
 *     mode == 1: 0xCF012E44 bit 0 set, else cleared; 0xCF012E40 bits 0-1 = 1 (mode 1/2), 2 (mode 3), 3 (mode 4), 0
 *     (other).
 *   delay 1; h = row(*DAT_a802d6a4) +0x08; n = h/16 (h/8 when 0xCF012E44 bit 5 set) + (h & 15 ? 1 : 0); w = row
 *   +0x0A / 2;
 *   0xCF012E0C/E10 = n low/high byte, 0xCF012E1C/E20 = w low/high byte.
 *   delay 1; record word 0 bit 29 set: 0xCF012F18 = 0xE, F1C = F20 = 1. 0xCF012E60 = 3, E64 = 0xB, bit 5 set in
 *   0xCF011800
 *   and 0xCF011A00; 0xCF012E6C = bit 29 ? 0x12 : 0; F00 = 0x40, F04 = F08 = 0, F0C = F10 = 0xFF, F14 = 0x1F.
 * Callers: no direct call in asm/leon2m.
 * PANEL ROW FIELDS READ: transformed row +0x08 and +0x0A.
 * Source form (all behaviour-neutral):
 *   - registers as 'volatile unsigned long' (alias set differs from the unsigned int record word, so the mode load
 *     is
 *     scheduled between the 0x71 / 0x10 stores like the firmware); mode read after both stores.
 *   - word 0 of 0xA8027A98 read twice: as mask (u0.w & 0x20000000) and as 1-bit field (u0.b.b29 == 1; '== 1' gives
 *     the
 *     firmware's branch layout, '!= 0' does not).
 *   - w read BEFORE the four n/w register stores; '(unsigned char) n' for the low byte (keeps n out of %o3
 *     conflicts).
 *   - case order 4,1,2,3,default (separate case 1 and case 2 bodies).
 */
#define R(a) (*(volatile unsigned long *)(a))
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; unsigned short h0a; };
struct CfgBits { unsigned int b31 : 1, b30 : 1, b29 : 1, rest : 29; };
struct Cfg { union { unsigned int w; struct CfgBits b; } u0; unsigned int w4, w8, wc; };
extern struct PanelParam *DAT_a802d6a4;
extern struct Cfg DAT_a8027a98;
extern void func_0x4008d1a0(int ms);
extern int FUN_a00f2e98();

void FUN_a01186e0(unsigned int arg)
{
    unsigned short h, n, w;
    unsigned char frac;
    unsigned int mode;

    R(0xcf009bb8) &= ~2;
    func_0x4008d1a0(0x32);
    R(0xcf012e80) = 4;
    FUN_a00f2e98(0xf4, 0, 0x400, arg);
    R(0xcf012e40) = 0x71;
    R(0xcf012e44) = 0x10;
    mode = DAT_a8027a98.w4;
    if (mode == 1) R(0xcf012e44) |= 1;
    else R(0xcf012e44) &= ~1;
    switch (mode) {
    case 4: R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 3; break;
    case 1: R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 1; break;
    case 2: R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 1; break;
    case 3: R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 2; break;
    default: R(0xcf012e40) = R(0xcf012e40) & 0xfc; break;
    }
    func_0x4008d1a0(1);
    h = DAT_a802d6a4->h08;
    frac = (h & 0xf) != 0;
    if (!(R(0xcf012e44) & 0x20)) n = (h >> 4) + frac;
    else n = (h >> 3) + frac;
    w = DAT_a802d6a4->h0a >> 1;
    R(0xcf012e0c) = (unsigned char) n;
    R(0xcf012e10) = n >> 8;
    R(0xcf012e1c) = w & 0xff;
    R(0xcf012e20) = w >> 8;
    func_0x4008d1a0(1);
    if (DAT_a8027a98.u0.w & 0x20000000) {
        R(0xcf012f18) = 0xe;
        R(0xcf012f1c) = 1;
        R(0xcf012f20) = 1;
    }
    R(0xcf012e60) = 3;
    R(0xcf012e64) = 0xb;
    R(0xcf011800) |= 0x20;
    R(0xcf011a00) |= 0x20;
    if (DAT_a8027a98.u0.b.b29 == 1) R(0xcf012e6c) = 0x12;
    else R(0xcf012e6c) = 0;
    R(0xcf012f00) = 0x40;
    R(0xcf012f04) = 0;
    R(0xcf012f08) = 0;
    R(0xcf012f0c) = 0xff;
    R(0xcf012f10) = 0xff;
    R(0xcf012f14) = 0x1f;
}
