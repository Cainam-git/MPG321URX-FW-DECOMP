/* leon2m FUN_a0121714 @ 0xa0121714  switch one input port's receiver block on or off
 * Flags: -mcpu=v8 -O3 -g -msoft-float.
 *
 * on != 0: func_0x40089968(5, 0xF); clear bit ch of 0xA802C9E4; FUN_a00f1d48(ch, 0x57, 0xB0), (ch, 0x59, 0x464);
 *   FUN_a00f36b8(ch, transformed row halfword +0x22); FUN_a00f1ad4(ch, 0x55, 0xB2), (ch, 0x54, 1);
 *   tail FUN_a00f1b5c(ch, 0x94, 0x20, 1).
 * on == 0: FUN_a00f1ad4(ch, 0x55, 0xC0); reg 0x54 by port type FUN_a00fd820(ch): 0x11/0x71/0x81 -> 0x20,
 *   0x12/0x13/0x21 -> 0x21, 0x31/0x41/0x51/0x61 -> 0x20 when word 0 of entry ch (12-byte entries at 0xA8027AAC)
 *   is 1, else 0x90; any other type -> 0x90; then FUN_a00f1b5c(ch, 0x94, 0x20, 0) and set bit ch of 0xA802C9E4.
 * Only the 'on' path reads row +0x22.
 * key: one FUN_a00f1ad4 call per case group (gcc cross-jumps them), not a value variable.
 */
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; unsigned char b0c[0x14];
                    unsigned short h20, h22; };
struct PortCfg { unsigned int w0, w4, w8; };
extern struct PanelParam *DAT_a802d6a4;
extern unsigned int DAT_a802c9e4;
extern struct PortCfg DAT_a8027aac[];
extern void func_0x40089968(int, int);
extern void FUN_a00f1d48(unsigned char, int, int);
extern void FUN_a00f36b8(unsigned char, unsigned short);
extern void FUN_a00f1ad4(unsigned char, int, int);
extern void FUN_a00f1b5c(unsigned char, int, int, int);
extern unsigned char FUN_a00fd820(unsigned char);

void FUN_a0121714(unsigned char ch, unsigned char on)
{
    int x;

    if (on) {
        func_0x40089968(5, 0xf);
        DAT_a802c9e4 &= ~(1 << ch);
        FUN_a00f1d48(ch, 0x57, 0xb0);
        FUN_a00f1d48(ch, 0x59, 0x464);
        FUN_a00f36b8(ch, DAT_a802d6a4->h22);
        FUN_a00f1ad4(ch, 0x55, 0xb2);
        FUN_a00f1ad4(ch, 0x54, 1);
        FUN_a00f1b5c(ch, 0x94, 0x20, 1);
        return;
    }
    FUN_a00f1ad4(ch, 0x55, 0xc0);
    switch (FUN_a00fd820(ch)) {
    case 0x11: case 0x71: case 0x81:
        FUN_a00f1ad4(ch, 0x54, 0x20); break;
    case 0x12: case 0x13: case 0x21:
        FUN_a00f1ad4(ch, 0x54, 0x21); break;
    case 0x31: case 0x41: case 0x51: case 0x61:
        if (DAT_a8027aac[ch].w0 == 1) FUN_a00f1ad4(ch, 0x54, 0x20); else FUN_a00f1ad4(ch, 0x54, 0x90);
        break;
    default:
        FUN_a00f1ad4(ch, 0x54, 0x90); break;
    }
    FUN_a00f1b5c(ch, 0x94, 0x20, 0);
    DAT_a802c9e4 |= 1 << ch;
}
