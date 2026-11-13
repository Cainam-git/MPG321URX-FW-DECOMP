/* hdmi_tx_set_color_depth_reg6  (FUN_a008d920)
 *
 * Set the 10/12-bit colour depth bits of HDMI TX register 6.
 *   port: HDMI TX port
 *   color_depth: bits per colour
 * Name basis: derived - bit 2 for 10, bit 3 for 12; callers pass bits per colour (8/0xC), as in the video_clk
 *   formula
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008d920 @ 0xa008d920-0xa008d980, flags -mcpu=v8 -Os -g.
 * Source form: a switch on the depth value; same form as hdmi_tx_set_clock_mode_reg5.
 */
extern unsigned int hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned short, unsigned int);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Read-modify-write HDMI TX register 6: clear bits 2..3, then set bit 2 for the depth value 10 or bit 3 for
 * the depth value 12. Any other depth leaves both bits clear.
 *   port: HDMI TX port.  color_depth: bits per colour.
 * Called by hdmi_tx_setup_clock_path and hdmi_tx_set_video_clock_ranges.
 */
void hdmi_tx_set_color_depth_reg6(unsigned int port, unsigned char color_depth)
{
    unsigned char value;

    port = port & 0xff;
    value = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 6);
    value = value & 0xfffffff3;

    switch (color_depth) {
    case 10:
        value = value | 4;
        break;
    case 12:
        value = value | 8;
        break;
    }

    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 6, value & 0xff);
}
