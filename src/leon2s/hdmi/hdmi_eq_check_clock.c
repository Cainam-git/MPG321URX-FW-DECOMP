/* hdmi_eq_check_clock  (EQ_handler)
 *
 * Restart the equaliser of a port when its clock became unstable.
 *   port: PHY
 * Note: The old label EQ_handler is not printed by the firmware.
 * Name basis: proven - prints '[EQ]: # Port%c Clock Unstable, Restart EQ' and 'EQ Clock Unstable. Set Mute'
 *
 * Matching notes
 * --------------
 * leon2s EQ_handler @ 0xa007501c, flags -mcpu=v8 -Os -g.
 * The old label EQ_handler is not printed by the firmware; the routine is named hdmi_eq_check_clock.
 */
#define HDMI_MSG_EQ_FLOW 2      /* debug message bit: '[EQ]' lines (dbg_hdmi_message_flags) */

/* Entry of hdmi_phy_records: one per HDMI PHY (24 bytes). */
struct hdmi_phy_record {
    unsigned char power;                /* +0 */
    unsigned char eq_done;              /* +1: 1 = equaliser finished; cleared here to make it run again */
    unsigned char bytes_0x2_to_0x17[0x18 - 2];
};
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern int hdmi_phy_clock_changed(unsigned char);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern int hdmi_rx21_is_port_ready(int);
extern unsigned int hdmi_rx21_read_frl_rate(unsigned char);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);

/* Called for a PHY. When hdmi_phy_clock_changed reports a change, the equaliser has to run again: it
 * prints "Clock Unstable, Restart EQ" (and, for an HDMI 2.1 PHY that is ready, "EQ Clock Unstable. Set
 * Mute") and clears the PHY's eq_done byte. For a PHY whose lane field (hdmi_rx21_read_frl_rate)
 * is 0 it also clears eq_done when bits 16..19 of PHY registers 0x1148, 0x1548 or 0x1948 are not all 1.
 *   port: PHY index (the letter in the prints is 'A' + port) */
void hdmi_eq_check_clock(unsigned char port)
{
    if ((unsigned char)hdmi_phy_clock_changed(port) == 1) {
        if (hdmi_is_hdmi21_phy(port) && (unsigned char)hdmi_rx21_is_port_ready(port) == 1) {
            if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
                dbg_printf("[EQ]: # Port%c EQ Clock Unstable. Set Mute\n", (char)(port + 'A'));
        }
        if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
            dbg_printf("[EQ]: # Port%c Clock Unstable, Restart EQ (%d)\n", (char)(port + 'A'), 0x2ed);
        hdmi_phy_records[port].eq_done = 0;
    }
    if ((unsigned char)hdmi_rx21_read_frl_rate(port))
        return;
    if ((hdmi_phy_read_reg(port, 0x1148) >> 16 & 0xf) != 0xf || (hdmi_phy_read_reg(port, 0x1548) >> 16 & 0xf) != 0xf
        || (hdmi_phy_read_reg(port, 0x1948) >> 16 & 0xf) != 0xf)
        hdmi_phy_records[port].eq_done = 0;
}
