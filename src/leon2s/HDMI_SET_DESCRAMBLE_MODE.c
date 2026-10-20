/* HDMI_SET_DESCRAMBLE_MODE (leon2s 0xa007f7c8-0xa007f8a4, 220 bytes), flags -mcpu=v8 -Os -g.
 * Calls H1_H2_VTH(port), then, each time bit 11 (0x800) of _DAT_a8078634 is set, prints the low nibble of
 * FUN_a00a7314(port, reg) with FUN_a0073044 for reg 0x2178, 0x2578, 0x2978 and 0x3178 ("[HDMI21]: ch0..ch3
 * RCT ... = 0x%02lx"). The range includes the unreachable ret/restore at 0xa007f89c.
 * Source form: four independent if statements; GCC threads a clear bit straight to the exit because the
 * flag word is not written in between.
 */
extern unsigned int _DAT_a8078634;
extern char s_a0068520[], s_a0068548[], s_a0068570[], s_a0068598[];
extern void H1_H2_VTH(unsigned char port);
extern unsigned int FUN_a00a7314(unsigned int param_1, unsigned short param_2);
extern int FUN_a0073044(const char *, ...);

void HDMI_SET_DESCRAMBLE_MODE(unsigned char port)
{
    H1_H2_VTH(port);
    if (_DAT_a8078634 & 0x800)
        FUN_a0073044(s_a0068520, FUN_a00a7314(port, 0x2178) & 0xf);
    if (_DAT_a8078634 & 0x800)
        FUN_a0073044(s_a0068548, FUN_a00a7314(port, 0x2578) & 0xf);
    if (_DAT_a8078634 & 0x800)
        FUN_a0073044(s_a0068570, FUN_a00a7314(port, 0x2978) & 0xf);
    if (_DAT_a8078634 & 0x800)
        FUN_a0073044(s_a0068598, FUN_a00a7314(port, 0x3178) & 0xf);
}
