/* hdmi_tx_set_low_clock_bits  (FUN_a008f450)
 *
 * Set HDMI TX register 5 bits 6..7 when the clock is below a depth-based limit.
 *   port: HDMI TX port
 *   color_depth: bits per colour
 *   pixel_clock
 * Name basis: descriptive - limits 0x50 / 0x40 / 0x36 for 8 / 10 / 12 bits
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f450 @ 0xa008f450-0xa008f4d0, flags -mcpu=v8 -Os -g.
 * Source form: both arms are tail calls; val is a signed int, so the comparison with the limit is signed.
 */
extern void hdmi_tx_reg_write_field(unsigned char, unsigned char, unsigned short, unsigned int, unsigned int);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set bits 6..7 of HDMI TX register 5 to 3 when pixel_clock is below a limit that depends on the colour depth
 * (0x50 for depth 8, 0x40 for 10, 0x36 for 12, 0x50 for any other depth); otherwise set them to 0.
 *   port: HDMI TX port.  color_depth: bits per colour.  pixel_clock: the channel record's pixel clock.
 * Called by hdmi_tx_run_step.
 */
void hdmi_tx_set_low_clock_bits(unsigned char port, unsigned char color_depth, int pixel_clock)
{
    unsigned char limit;

    if (color_depth == 8)
        limit = 0x50;
    else if (color_depth == 0xa)
        limit = 0x40;
    else if (color_depth == 0xc)
        limit = 0x36;
    else
        limit = 0x50;
    if (pixel_clock < limit)
        hdmi_tx_reg_write_field(port, HDMI_TX_BANK_PHY, 5, 0xc0, 0xc0);
    else
        hdmi_tx_reg_write_field(port, HDMI_TX_BANK_PHY, 5, 0xc0, 0);
}
