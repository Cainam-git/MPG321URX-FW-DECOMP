/* hdmi_phy_switch_channel_bit21  (FUN_a0079778)
 *
 * Set or clear bit 21 of the channel registers in power-up or power-down order.
 *   port: PHY
 *   on: 1 = HDMI 2.1 lanes
 *   mode: 1 = set
 * Name basis: descriptive - mode 1: four HDMI 2.1 lanes 0x2100..0x3100, else three TMDS channels
 *   0x1100..0x1900
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0079778 @ 0xa0079778, flags -mcpu=v8 -Os -g.
 * Source form: the mode 1 calls pass 'on == 1' directly; the other calls go through a macro that tests on
 * and passes the literal 1 or 0, so each call repeats the test with its own constants.
 */
extern void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned char reg, unsigned short val);

#define WR(port, on, reg) \
    if ((on) == 1) \
        hdmi_phy_write_bit(1, 0x15, port, reg); \
    else \
        hdmi_phy_write_bit(0, 0x15, port, reg)

/* Sets (on == 1) or clears bit 21 of one register per lane or channel. In mode 1 the registers are
 * the four HDMI 2.1 lanes 0x2100, 0x2500, 0x2900, 0x3100; in any other mode the three channels 0x1100,
 * 0x1500, 0x1900. Setting goes through the list in that order, clearing in the reverse order.
 *   port: PHY page
 *   on:   1 = set, otherwise clear
 *   mode: 1 = the HDMI 2.1 lanes */
void hdmi_phy_switch_channel_bit21(unsigned char port, unsigned char on, unsigned char mode)
{
    if (mode == 1) {
        if (on == 1) {
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x2100);
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x2500);
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x2900);
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x3100);
        } else {
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x3100);
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x2900);
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x2500);
            hdmi_phy_write_bit(on == 1, 0x15, port, 0x2100);
        }
    } else {
        if (on == 1) {
            WR(port, on, 0x1100);
            WR(port, on, 0x1500);
            WR(port, on, 0x1900);
        } else {
            WR(port, on, 0x1900);
            WR(port, on, 0x1500);
            WR(port, on, 0x1100);
        }
    }
}
