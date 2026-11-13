/* dp_tx_calc_pixel_clock  (FUN_a0089898)
 *
 * Compute the pixel clock of a DP output from its M/N values and link rate.
 *   port: DP output 0..4
 * Returns: clock value (16 bits)
 * Name basis: derived - reg 0x50 * link rate (0xA2/0x10E/0x21C/0x32A = 1.62..8.1 Gbit/s) / 24-bit regs
 *   0x53..0x55; feeds clk print
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: one complete formula per case (as in dp_calc_rate_value); the switch value (unsigned char result of
 * dp_tx_reg_read8, & 0xff) is compared as int.
 */
extern int dp_tx_reg_read24_stable(unsigned char port, unsigned short reg);
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);

#define TX_REG_LINK_RATE 2      /* link rate code: 6, 10, 20 or 30 */

/*
 * Compute a clock value of a DP output from its registers: register 0x50 (24 bits) times a factor chosen by
 * the link rate code in register 2, divided by the 24-bit value of registers 0x53..0x55 (high byte first).
 *
 *   port: DP output 0..4
 *
 * Returns the result truncated to 16 bits. DPTX_SetBrilliantMode uses it as the clock ('clk') of the output.
 * The divisor is taken as 1 when registers 0x53..0x55 read 0; a link rate code other than 6, 10, 20 or 30
 * uses the factor of code 20.
 */
unsigned short dp_tx_calc_pixel_clock(unsigned char port)
{
    unsigned int reg_0x50, reg_0x53_to_55, clock;

    reg_0x50 = dp_tx_reg_read24_stable(port, 0x50);
    reg_0x53_to_55 = dp_tx_reg_read8(port, 0x53) & 0xff;
    reg_0x53_to_55 <<= 8;
    reg_0x53_to_55 |= dp_tx_reg_read8(port, 0x54) & 0xff;
    reg_0x53_to_55 <<= 8;
    reg_0x53_to_55 |= dp_tx_reg_read8(port, 0x55) & 0xff;
    if (reg_0x53_to_55 == 0)
        reg_0x53_to_55 = 1;
    switch (dp_tx_reg_read8(port, TX_REG_LINK_RATE) & 0xff) {
    case 6:
        clock = reg_0x50 * 0xa2 / reg_0x53_to_55;
        break;
    case 10:
        clock = reg_0x50 * 0x10e / reg_0x53_to_55;
        break;
    case 20:
        clock = reg_0x50 * 0x21c / reg_0x53_to_55;
        break;
    case 30:
        clock = reg_0x50 * 0x32a / reg_0x53_to_55;
        break;
    default:
        clock = reg_0x50 * 0x21c / reg_0x53_to_55;
        break;
    }
    return clock;
}
