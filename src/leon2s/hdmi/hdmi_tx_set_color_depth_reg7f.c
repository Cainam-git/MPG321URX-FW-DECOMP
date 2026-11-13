/* hdmi_tx_set_color_depth_reg7f  (FUN_a008d9d4)
 *
 * Set the 10/12-bit colour depth bits of HDMI TX register 0x7F.
 *   port: HDMI TX port
 *   color_depth: bits per colour
 * Name basis: derived - bit 4 for 10, bit 5 for 12; sibling of hdmi_tx_set_color_depth_reg6
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008d9d4 @ 0xa008d9d4-0xa008da34, flags -mcpu=v8 -Os -g.
 * Source form: a switch on the depth value; same form as hdmi_tx_set_color_depth_reg6.
 */
extern unsigned int hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned short, unsigned int);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Read-modify-write HDMI TX register 0x7F: clear bits 4..5, then set bit 4 for the depth value 10 or bit 5 for
 * the depth value 12. Any other depth leaves both bits clear.
 *   port: HDMI TX port.  color_depth: bits per colour.
 * Called by hdmi_tx_setup_clock_path and hdmi_tx_set_video_clock_ranges.
 */
void hdmi_tx_set_color_depth_reg7f(unsigned int port, unsigned char color_depth)
{
    unsigned char value;

    port = port & 0xff;
    value = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x7f);
    value = value & 0xffffffcf;

    switch (color_depth) {
    case 10:
        value = value | 0x10;
        break;
    case 12:
        value = value | 0x20;
        break;
    }

    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x7f, value & 0xff);
}
