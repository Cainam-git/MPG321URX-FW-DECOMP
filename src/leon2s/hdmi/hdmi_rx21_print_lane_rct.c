/* hdmi_rx21_print_lane_rct  (HDMI_SET_DESCRAMBLE_MODE)
 *
 * Print the RCT register value of the four HDMI 2.1 lanes.
 *   port: PHY
 * Note: The old label came from a nearby text ('HDMI_SET_DESCRAMBLE_MODE = 0x05'), not printed here.
 * Name basis: proven - prints '[HDMI21]: ch0 RCT 0x2178 = 0x%02lx' .. ch3
 *
 * Matching notes
 * --------------
 * HDMI_SET_DESCRAMBLE_MODE (leon2s 0xa007f7c8-0xa007f8a4, 220 bytes), flags -mcpu=v8 -Os -g.
 * The range includes the unreachable ret/restore at 0xa007f89c.
 * Source form: four independent if statements; GCC threads a clear bit straight to the exit because the
 * flag word is not written in between.
 */
extern unsigned int dbg_hdmi_message_flags;
extern void H1_H2_VTH(unsigned char port);
extern unsigned int hdmi_phy_read_reg(unsigned int param_1, unsigned short param_2);
extern int dbg_printf(const char *, ...);

#define HDMI_MSG_HDMI21 0x800   /* dbg_hdmi_message_flags bit 11: the "[HDMI21]" lines */
#define PHY_LANE0 0x2000        /* first register of each lane of the PHY */
#define PHY_LANE1 0x2400
#define PHY_LANE2 0x2800
#define PHY_LANE3 0x3000
#define LANE_REG_RCT 0x178      /* RCT register, offset inside a lane */

/*
 * Print the RCT value of the four lanes of an HDMI 2.1 PHY. For each lane the low 4 bits of register
 * lane base + 0x178 are printed when the "[HDMI21]" debug messages are on; H1_H2_VTH is called first and
 * prints its own line. Nothing is written. (The label HDMI_SET_DESCRAMBLE_MODE comes from a nearby text,
 * not from anything this routine prints.)
 *   port: PHY
 */
void hdmi_rx21_print_lane_rct(unsigned char port)
{
    H1_H2_VTH(port);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: ch0 RCT 0x2178 = 0x%02lx\n", hdmi_phy_read_reg(port, PHY_LANE0 + LANE_REG_RCT) & 0xf);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: ch1 RCT 0x2578 = 0x%02lx\n", hdmi_phy_read_reg(port, PHY_LANE1 + LANE_REG_RCT) & 0xf);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: ch2 RCT 0x2978 = 0x%02lx\n", hdmi_phy_read_reg(port, PHY_LANE2 + LANE_REG_RCT) & 0xf);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: ch3 RCT 0x3178 = 0x%02lx\n", hdmi_phy_read_reg(port, PHY_LANE3 + LANE_REG_RCT) & 0xf);
}
