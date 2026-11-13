/* dp_tx_phy_set_link_rate  (FUN_a00aa5e8)
 *
 * Program the transmitter PHY clock for a DP link rate (RBR, HBR, HBR2, HBR3).
 *   port: output
 *   rate: link rate code
 *   on: value for dp_tx_phy_set_pll_enable: the stored link option byte, or 0
 *   go: non-zero = run the unit start-up list
 * Note: Parameter on is passed to dp_tx_phy_set_pll_enable (the callers give the stored link option byte or
 *   0); go is tested for non-zero.
 * Name basis: derived - rate codes 6 / 0xA / 0x14 / other select the clock register values; caller
 *   dp_tx_set_link_rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aa5e8 @ 0xa00aa5e8-0xa00aa7bc (includes the shared ret/restore tail), -mcpu=v8 -Os -g.
 * Source form: each rate arm holds its own register writes and call; GCC shares the identical ones. The two
 * unit start-up lists are tail calls.
 */
extern void dp_tx_phy_set_pll_enable(unsigned char, unsigned char);
extern void dp_tx_phy_reg_update_bits(unsigned int, short, unsigned int, unsigned int);
extern void dp_tx_phy_init_dptx_unit(void);
extern void dp_tx_phy_init_edp_unit(void);

#define PLL0_REG_C4 (*(volatile unsigned int *)0xcf012ac4) /* output 0 clock registers */
#define PLL0_REG_C8 (*(volatile unsigned int *)0xcf012ac8)
#define PLL0_REG_CC (*(volatile unsigned int *)0xcf012acc)
#define PLL1_REG_84 (*(volatile unsigned int *)0xcf012a84) /* eDP clock registers */
#define PLL1_REG_88 (*(volatile unsigned int *)0xcf012a88)
#define PLL1_REG_8C (*(volatile unsigned int *)0xcf012a8c)
#define PHY_UNIT_EDP 1

/*
 * Set the PLL and clock registers of the transmitter PHY for one link rate.
 *   port: output; 0 = the DPTX unit, anything else = the eDP unit
 *   rate: link rate code, 6, 10 (0xA), 0x14 or 0x1E; any other value takes the same values as 0x1E
 *   on:   passed to dp_tx_phy_set_pll_enable; non-zero = enable the PLL with its set-up values, 0 = disable it
 *   go:   non-zero = also run the unit start-up list (dp_tx_phy_init_dptx_unit for output 0,
 *         dp_tx_phy_init_edp_unit otherwise)
 *
 * Output 0: register 0xCF012AC4 = 0; 0xCF012AC8 = 0x80, but 0 for rate 0x14; 0xCF012ACC = 0xD / 0x16 / 0x2D /
 * 0x43 for rate 6 / 10 / 0x14 / other.
 * Other outputs: registers 0xCF012A84, A88, A8C = 0x5C, 0x77, 0xD (rate 6), 0x99, 0x71, 0x16 (10), 0x33, 0xE3,
 * 0x2C (0x14) or 0xCC, 0x54, 0x43 (other); then bit 1 of eDP PHY register 0xE6 is set for rate 6 and for the
 * other rates, cleared for rates 10 and 0x14.
 * Called by dp_tx_set_link_rate and by the test-request handler with go = 1, and by dp_tx_init_ports with
 * rate 0x1E, on = 0 and go = 0 for outputs 1 and 0.
 */
void dp_tx_phy_set_link_rate(unsigned char port, unsigned char rate, unsigned char on, unsigned char go)
{
    dp_tx_phy_set_pll_enable(port, on);
    if (port == 0) {
        if (rate == 6) {
            PLL0_REG_C4 = 0;
            PLL0_REG_C8 = 0x80;
            PLL0_REG_CC = 0xd;
        } else if (rate == 10) {
            PLL0_REG_C4 = 0;
            PLL0_REG_C8 = 0x80;
            PLL0_REG_CC = 0x16;
        } else if (rate == 0x14) {
            PLL0_REG_C4 = 0;
            PLL0_REG_C8 = 0;
            PLL0_REG_CC = 0x2d;
        } else {
            PLL0_REG_C4 = 0;
            PLL0_REG_C8 = 0x80;
            PLL0_REG_CC = 0x43;
        }
        if (go)
            dp_tx_phy_init_dptx_unit();
    } else {
        if (rate == 6) {
            PLL1_REG_84 = 0x5c;
            PLL1_REG_88 = 0x77;
            PLL1_REG_8C = 0xd;
            dp_tx_phy_reg_update_bits(PHY_UNIT_EDP, 0xe6, 2, 1);
        } else if (rate == 10) {
            PLL1_REG_84 = 0x99;
            PLL1_REG_88 = 0x71;
            PLL1_REG_8C = 0x16;
            dp_tx_phy_reg_update_bits(PHY_UNIT_EDP, 0xe6, 2, 0);
        } else if (rate == 0x14) {
            PLL1_REG_84 = 0x33;
            PLL1_REG_88 = 0xe3;
            PLL1_REG_8C = 0x2c;
            dp_tx_phy_reg_update_bits(PHY_UNIT_EDP, 0xe6, 2, 0);
        } else {
            PLL1_REG_84 = 0xcc;
            PLL1_REG_88 = 0x54;
            PLL1_REG_8C = 0x43;
            dp_tx_phy_reg_update_bits(PHY_UNIT_EDP, 0xe6, 2, 1);
        }
        if (go)
            dp_tx_phy_init_edp_unit();
    }
}
