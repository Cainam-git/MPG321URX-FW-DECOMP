/* dp_tx_phy_power_up_output  (FUN_a00ab4a8)
 *
 * Power up the PHY lanes of one DP / eDP output.
 *   output
 * Name basis: derived - bit n of 0xCF013280, clears bits 0/3 of 0xCF013290, then sets 0xCF013284 bit 0; caller
 *   dp_tx_init_port_phy
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab4a8 @ 0xa00ab4a8, flags -mcpu=v8 -Os -g.
 * Source form: the shift count is used unmasked and the routine returns nothing.
 */
#define DP_TX_PHY_REG_3280 (*(volatile unsigned int *)0xcf013280)
#define DP_TX_PHY_REG_3284 (*(volatile unsigned int *)0xcf013284)
#define DP_TX_PHY_REG_3290 (*(volatile unsigned int *)0xcf013290)
extern void timer_delay_long_units(int);

/*
 * Power up the PHY of one output. Twin of dp_tx_phy_power_down_output.
 *
 * Sets bit "output" of register 0xCF013280, clears bits 0 and 3 of 0xCF013290, waits one unit
 * (timer_delay_long_units) and sets bit 0 of 0xCF013284. Caller: dp_tx_init_port_phy.
 *   output: output number, used as the bit number
 */
void dp_tx_phy_power_up_output(unsigned int output)
{
  DP_TX_PHY_REG_3280 = DP_TX_PHY_REG_3280 | 1 << output;
  DP_TX_PHY_REG_3290 = DP_TX_PHY_REG_3290 & 0xfffffff6;
  timer_delay_long_units(1);
  DP_TX_PHY_REG_3284 = DP_TX_PHY_REG_3284 | 1;
}
