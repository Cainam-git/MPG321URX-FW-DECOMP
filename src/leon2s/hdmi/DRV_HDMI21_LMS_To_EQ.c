/* DRV_HDMI21_LMS_To_EQ  (DRV_HDMI21_LMS_To_EQ)
 *
 * Write fixed values to the channel and lane EQ registers of an HDMI 2.1 PHY, then reset the lane EQ.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_LMS_To_EQ'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_LMS_To_EQ @ 0xa0079f80, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - `i = 0` comes before the debug test, and a goto skips the print;
 *  - the port is copied to a second local (port_copy) that is masked to 8 bits for the calls;
 *  - the `if (i <= 3)` inside the second loop is always true and stays.
 */
#define HDMI_MSG_HDMI21 0x800   /* debug message bit: '[HDMI21]' lines (dbg_hdmi_message_flags) */

extern unsigned int dbg_hdmi_message_flags;
extern unsigned short hdmi_phy_channel_regs_0x17c[4];
extern unsigned short hdmi_rx21_lane_regs_0x17c[4];
extern unsigned short hdmi_rx21_lane_eq_regs[4];
extern char s_a0067868[];
extern void dbg_printf(unsigned int, const char *);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void hdmi_rx21_reset_lane_eq_regs(unsigned char);

/* Writes a fixed set of values into the PHY registers named by three halfword tables:
 * one register per entry of hdmi_phy_channel_regs_0x17c (entries 0..2) and, for each of the four
 * lanes, one register of hdmi_rx21_lane_eq_regs and one of hdmi_rx21_lane_regs_0x17c. Then it calls
 * hdmi_rx21_reset_lane_eq_regs for the same PHY.
 *   port:   PHY page (the low 8 bits are used)
 *   unused: not read
 * Prints its name first when the '[HDMI21]' debug bit is set. */
void DRV_HDMI21_LMS_To_EQ(unsigned int port, unsigned int unused)
{
    int i;
    unsigned int phy;
    unsigned int port_copy = port;

    i = 0;
    if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) == 0) {
        goto skip;
    }
    dbg_printf((unsigned int)s_a0067868, "DRV_HDMI21_LMS_To_EQ");
skip:
    do {
        phy = port_copy & 0xff;
        hdmi_phy_update_reg(phy, hdmi_phy_channel_regs_0x17c[i], 0xffffff, 0x18000000);
        i++;
    } while (i <= 2);

    i = 0;
    do {
        hdmi_phy_update_reg(phy, hdmi_rx21_lane_eq_regs[i], 0xfffffff0, 0xf);
        if (i <= 3) {
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_regs_0x17c[i], 0xffffff, 0x18000000);
        }
        i++;
    } while (i <= 3);

    hdmi_rx21_reset_lane_eq_regs(phy);
}
