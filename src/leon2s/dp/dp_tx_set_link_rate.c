/* dp_tx_set_link_rate  (FUN_a0087734)
 *
 * Program the link rate of a DP output and its PHY clock.
 *   port: output
 *   rate_code
 *   second_port: second output
 * Name basis: derived - writes the rate to register 2 (default 0x1E) and the rate-dependent PHY values
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0087734 @ 0xa0087734 (-mcpu=v8 -Os -g)
 * Source form: dp_tx_link_option_port0 is volatile (see dp_tx_set_link_option). All three parameters are
 * masked to bytes in place.
 */
extern volatile unsigned char dp_tx_link_option_port0;
extern unsigned char dp_tx_link_option_others;
extern void dp_tx_reg_write8(unsigned int port, unsigned short reg, unsigned int value);
extern void dp_tx_phy_set_link_rate();

/*
 * Set the link rate of an output. For output 0, dp_tx_phy_set_link_rate is called with the rate code and
 * dp_tx_link_option_port0; for any other output only when it equals second_port, with
 * dp_tx_link_option_others. Then the rate code is written to register 2 of the output.
 *   port:        link output
 *   rate_code:   link rate code
 *   second_port: the other output whose PHY is set up
 */
void dp_tx_set_link_rate(unsigned int port, unsigned char rate_code, unsigned int second_port)
{
    port &= 0xff;
    rate_code &= 0xff;
    second_port &= 0xff;
    
    if (port == 0) {
        dp_tx_phy_set_link_rate(port, rate_code, dp_tx_link_option_port0, 1);
    } else if (port == second_port) {
        dp_tx_phy_set_link_rate(port, rate_code, dp_tx_link_option_others, 1);
    }
    dp_tx_reg_write8(port, 2, rate_code);
}
