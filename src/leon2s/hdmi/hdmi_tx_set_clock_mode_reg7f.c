/* hdmi_tx_set_clock_mode_reg7f  (FUN_a008da34)
 *
 * Set the clock mode field (bits 2..3) of HDMI TX register 0x7F.
 *   port: HDMI TX port
 *   clock_mode
 * Name basis: descriptive - 1 -> 2, 2 -> 3, other -> 1; sibling of the reg 5 setter
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008da34 @ 0xa008da34, flags -mcpu=v8 -Os -g.
 * Source form: a switch on the clock mode, same form as hdmi_tx_set_clock_mode_reg5.
 */
extern unsigned int hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned short, unsigned int);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Read-modify-write HDMI TX register 0x7F: bits 2..3 become 2 for clock_mode 1, 3 for clock_mode 2 and 1 for
 * any other value.
 *   port: HDMI TX port.  clock_mode: 1, 2 or other.
 * Called by hdmi_tx_setup_clock_path and hdmi_tx_set_video_clock_ranges.
 */
void hdmi_tx_set_clock_mode_reg7f(unsigned int port, unsigned char clock_mode)
{
    unsigned char value;

    port = port & 0xff;
    value = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x7f);
    value = value & 0xfffffff3;

    switch (clock_mode) {
    case 1:
        value = value | 8;
        break;
    case 2:
        value = value | 0xc;
        break;
    default:
        value = value | 4;
        break;
    }

    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x7f, value & 0xff);
}
