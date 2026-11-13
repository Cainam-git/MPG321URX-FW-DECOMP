/* input_init_phy_registers_wrapper  (FUN_a006d30c)
 *
 * Run the fixed receiver PHY register set-up.
 * Name basis: descriptive - forwards to the 0xCF0146xx/0xCF0147xx register set-up; called from
 *   input_init_receivers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d30c @ 0xa006d30c, flags -mcpu=v8 -Os -g.
 */

extern int input_init_phy_registers();

/* Run input_init_phy_registers, the fixed receiver PHY register set-up; called from input_init_receivers. */
void input_init_phy_registers_wrapper(void)
{
  input_init_phy_registers();
}
