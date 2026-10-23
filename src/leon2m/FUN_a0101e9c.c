/* leon2m FUN_a0101e9c @ 0xa0101e9c  output register set-up per display mode (-mcpu=v8 -O3 -g;
 * jump table at runtime 0xa1cc8, cases in number order)
 *
 * Called by FUN_a01023f4 (output path set-up B) with the display mode DAT_a802d680.w8 (0..17, from
 * DispModeTransform).
 * Writes three output-format fields; each is a read-modify-write on a 32-bit hardware register:
 *   0xCF00ED58 bits 0..3 (value 0, 1, 4 or 5), 0xCF00EDE0 bits 0..2 and 4..7 (mask 0xF7),
 *   and for display modes 5, 9, 13, 14, 15, 17 only when the active 0x58-byte row's link type
 *   (DAT_a802d6a4->w0 bits 20..22) is 1: 0xCF0116D4 bits 4, 6, 7 (mask 0xD0; value 0x00, 0x40 or 0x80).
 *   Mode 16 instead sets bit 3 of 0xCF00ED54. Modes above 17: nothing.
 * Mode -> ED58 / EDE0 / 116D4:  0,1: 0/0  2: 0/01  3: 0/10  4: 4/20  5: 1/30/00  6: 5/40  7: 5/54  8: 1/62
 *   9: 5/72/40  10: 5/86  11: 1/92  12: 5/A2  13: 5/B6/80  14: 1/D2/00  15: 5/C2/40  16: 0/00 + ED54 bit 3  17:
 *   5/E2/40
 */
#define R(a) (*(volatile unsigned long *)(a))
struct PanelParam { volatile unsigned int w0; };   /* volatile: the firmware re-reads w0 after each register write */
extern struct PanelParam *DAT_a802d6a4;
void FUN_a0101e9c(unsigned char mode)
{
    switch (mode)
    {
    case 0:
    case 1:
        R(0xcf00ed58) &= ~0x0f;
        R(0xcf00ede0) &= ~0xf7;
        break;
    case 2:
        R(0xcf00ed58) &= ~0x0f;
        R(0xcf00ede0) &= ~0xf6; R(0xcf00ede0) |= 0x01;
        break;
    case 3:
        R(0xcf00ed58) &= ~0x0f;
        R(0xcf00ede0) &= ~0xe7; R(0xcf00ede0) |= 0x10;
        break;
    case 4:
        R(0xcf00ed58) &= ~0x0b; R(0xcf00ed58) |= 0x04;
        R(0xcf00ede0) &= ~0xd7; R(0xcf00ede0) |= 0x20;
        break;
    case 5:
        R(0xcf00ed58) &= ~0x0e; R(0xcf00ed58) |= 0x01;
        R(0xcf00ede0) &= ~0xc7; R(0xcf00ede0) |= 0x30;
        if ((DAT_a802d6a4->w0 & 0x700000) == 0x100000) R(0xcf0116d4) &= ~0xd0;
        break;
    case 6:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0xb7; R(0xcf00ede0) |= 0x40;
        break;
    case 7:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0xa3; R(0xcf00ede0) |= 0x54;
        break;
    case 8:
        R(0xcf00ed58) &= ~0x0e; R(0xcf00ed58) |= 0x01;
        R(0xcf00ede0) &= ~0x95; R(0xcf00ede0) |= 0x62;
        break;
    case 9:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0x87; R(0xcf00ede0) |= 0x72;
        if ((DAT_a802d6a4->w0 & 0x700000) == 0x100000) { R(0xcf0116d4) &= ~0x90; R(0xcf0116d4) |= 0x40; }
        break;
    case 10:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0x71; R(0xcf00ede0) |= 0x86;
        break;
    case 11:
        R(0xcf00ed58) &= ~0x0e; R(0xcf00ed58) |= 0x01;
        R(0xcf00ede0) &= ~0x65; R(0xcf00ede0) |= 0x92;
        break;
    case 12:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0x55; R(0xcf00ede0) |= 0xa2;
        break;
    case 13:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0x41; R(0xcf00ede0) |= 0xb6;
        if ((DAT_a802d6a4->w0 & 0x700000) == 0x100000) { R(0xcf0116d4) &= ~0x50; R(0xcf0116d4) |= 0x80; }
        break;
    case 14:
        R(0xcf00ed58) &= ~0x0e; R(0xcf00ed58) |= 0x01;
        R(0xcf00ede0) &= ~0x35; R(0xcf00ede0) |= 0xd2;
        if ((DAT_a802d6a4->w0 & 0x700000) == 0x100000) R(0xcf0116d4) &= ~0xd0;
        break;
    case 15:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0x35; R(0xcf00ede0) |= 0xc2;
        if ((DAT_a802d6a4->w0 & 0x700000) == 0x100000) { R(0xcf0116d4) &= ~0x90; R(0xcf0116d4) |= 0x40; }
        break;
    case 16:
        R(0xcf00ed58) &= ~0x0f;
        R(0xcf00ede0) &= ~0xf7;
        R(0xcf00ed54) |= 0x08;
        break;
    case 17:
        R(0xcf00ed58) &= ~0x0a; R(0xcf00ed58) |= 0x05;
        R(0xcf00ede0) &= ~0x17; R(0xcf00ede0) |= 0xe2;
        if ((DAT_a802d6a4->w0 & 0x700000) == 0x100000) { R(0xcf0116d4) &= ~0x90; R(0xcf0116d4) |= 0x40; }
        break;
    }
}
