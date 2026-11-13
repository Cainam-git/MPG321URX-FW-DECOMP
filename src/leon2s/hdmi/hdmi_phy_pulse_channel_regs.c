/* hdmi_phy_pulse_channel_regs  (FUN_a00787f4)
 *
 * Pulse the two control registers of each of the three channels.
 *   p: PHY
 * Name basis: descriptive - per-channel register tables, set/clear around a short delay; callers
 *   Search_Process and the error monitor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00787f4 @ 0xa00787f4, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: unsigned int parameter, unsigned short loop counter, an
 * 'i < 3' test inside each loop, and the port masked in different spellings ((char)p & 0xff,
 * (unsigned char)p, p & 0xff, (unsigned short)p & 0xff); equal spellings are merged into one register
 * by GCC.
 */
extern unsigned short hdmi_phy_channel_regs_0x170[3];
extern unsigned short hdmi_phy_channel_regs_0x17c[3];
extern void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned int reg, unsigned short val);
extern void hdmi_phy_update_reg(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern void timer_delay_long_units(unsigned int);

/* For each of the three channels, in two passes with a short wait (delay value 1) between them.
 * First pass: sets bit 4 of register a (table hdmi_phy_channel_regs_0x17c), clears bit 0 of register b
 * (table hdmi_phy_channel_regs_0x170), then sets bits 16..23 of b to 0x2c and of a to 0xff.
 * Second pass: sets bit 0 of b and clears bit 4 of a.
 *   p: PHY page (low 8 bits used) */
void hdmi_phy_pulse_channel_regs(unsigned int p)
{
    unsigned short i;
    unsigned short a, b;     /* the channel's register of the _0x17c and the _0x170 table */

    for (i = 0; i < 3; i++) {
        if (i < 3) {
            a = hdmi_phy_channel_regs_0x17c[i];
            hdmi_phy_write_bit(1, 4, (char)p & 0xff, a);
            b = hdmi_phy_channel_regs_0x170[i];
            hdmi_phy_write_bit(0, 0, (unsigned char)p, b);
            hdmi_phy_update_reg(p & 0xff, b, 0xff00ffff, 0x2c0000);
            hdmi_phy_update_reg((unsigned short)p & 0xff, a, 0xff00ffff, 0xff0000);
        }
    }
    timer_delay_long_units(1);
    for (i = 0; i < 3; i++) {
        if (i < 3) {
            hdmi_phy_write_bit(1, 0, p & 0xff, hdmi_phy_channel_regs_0x170[i]);
            hdmi_phy_write_bit(0, 4, (unsigned short)p & 0xff, hdmi_phy_channel_regs_0x17c[i]);
        }
    }
}
