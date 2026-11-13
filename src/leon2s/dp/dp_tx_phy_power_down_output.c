/* dp_tx_phy_power_down_output  (FUN_a00ab4f8)
 *
 * Power down the PHY lanes of one DP / eDP output.
 *   output
 * Name basis: derived - twin of dp_tx_phy_power_up_output in the opposite direction; callers
 *   input_power_off_receivers_mode0/1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab4f8 @ 0xa00ab4f8, flags -mcpu=v8 -Os -g.
 * Source form: the shift count is used unmasked.
 */
#define DP_TX_PHY_REG_3280 (*(volatile unsigned int *)0xcf013280)
#define DP_TX_PHY_REG_3284 (*(volatile unsigned int *)0xcf013284)
#define DP_TX_PHY_REG_3290 (*(volatile unsigned int *)0xcf013290)
extern void timer_delay_long_units(int);

/*
 * Power down the PHY of one output. Twin of dp_tx_phy_power_up_output.
 *
 * Sets bit "output" of register 0xCF013280, sets bits 0 and 3 of 0xCF013290, waits one unit
 * (timer_delay_long_units) and clears bit 0 of 0xCF013284.
 *   output: output number, used as the bit number
 */
void dp_tx_phy_power_down_output(unsigned int output)
{
  DP_TX_PHY_REG_3280 = DP_TX_PHY_REG_3280 | 1 << output;
  DP_TX_PHY_REG_3290 = DP_TX_PHY_REG_3290 | 9;
  timer_delay_long_units(1);
  DP_TX_PHY_REG_3284 = DP_TX_PHY_REG_3284 & 0xfffffffe;
}
