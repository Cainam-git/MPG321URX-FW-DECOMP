/* DRV_HDMI21_PHY_Freq_Detection  (DRV_HDMI21_PHY_Freq_Detection)
 *
 * Measure and print the clock frequency of each lane of an HDMI 2.1 PHY.
 *   port: HDMI 2.1 receiver 0 or 1 (PHY page 2 or 3); any other value returns at once
 * Name basis: proven - original name printed ('[HDMI21]: %s'); prints 'Lane%d, freq=%ld'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_PHY_Freq_Detection @ 0xa009a580, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the reading is taken twice: once for the table entry and once again for the print;
 *  - the delay comes before the first read; the table index is port * 4 + i.
 */
#define HDMI_MSG_HDMI21 0x800   /* debug message bit: '[HDMI21]' lines (dbg_hdmi_message_flags) */

extern unsigned int dbg_hdmi_message_flags;
extern unsigned short hdmi_rx21_lane_freqs[];
extern void hdmi_phy_update_reg(unsigned char, unsigned short, unsigned int, unsigned int);
extern void timer_delay_units(unsigned int);
extern unsigned int hdmi_phy_read_reg(unsigned char, unsigned short);
extern void hdmi_phy_write_bit(unsigned int, unsigned int, unsigned char, unsigned short);
extern int dbg_printf(const char *, ...);

/* Reads the frequency reading of each of the four lanes of one HDMI 2.1 receiver PHY, stores it in
 * hdmi_rx21_lane_freqs[port * 4 + lane] (checked later by hdmi_rx21_check_sr_detect) and prints it.
 *   port: HDMI 2.1 receiver 0 or 1 (PHY page 2 or 3); any other value returns at once
 * For each lane: select the lane in bits 16..23 of PHY register 0x2f50, set bit 0x18 of that register,
 * wait, then take bits 8..20 of register 0x2f54. */
void DRV_HDMI21_PHY_Freq_Detection(unsigned char port)
{
    unsigned char ch;   /* PHY page */
    unsigned char i;

    if (port == 0)
        ch = 2;
    else if (port == 1)
        ch = 3;
    else
        return;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: \033[34;1m%s\n\033[m", "DRV_HDMI21_PHY_Freq_Detection");
    hdmi_phy_update_reg(ch, 0x2f54, 0xffffff00, 0x5f);   /* low byte of 0x2f54 = 0x5f before the lane loop */
    for (i = 0; i < 4; i++) {
        hdmi_phy_update_reg(ch, 0x2f50, 0xff00ffff, i << 16);
        hdmi_phy_write_bit(1, 0x18, ch, 0x2f50);
        timer_delay_units(0x14);
        hdmi_rx21_lane_freqs[port * 4 + i] = (hdmi_phy_read_reg(ch, 0x2f54) & 0x1fff00) >> 8;
        dbg_printf("\tLane%d, freq=%ld\n", i, (hdmi_phy_read_reg(ch, 0x2f54) & 0x1fff00) >> 8);
    }
}
