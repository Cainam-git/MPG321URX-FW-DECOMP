/* ldc_hw_api_set_enable_mode  (FUN_a014e878)
 *
 * Set the grid block's enable and bit 31 of its register 0x200 for mode 0, 1 or 2.
 * Note: Mode 0: bit 31 set, then enable off; mode 1: enable on, bit 31 set; mode 2: enable on, bit 31 cleared;
 *   other modes do nothing.
 * Name basis: descriptive - ldc_hw_enable_with_irq(0 / 1 / 1) and ldc_hw_set_reg200_bit31_inverted(0 / 0 / 1)
 *   for the modes 0 / 1 / 2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e878, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: an if/else chain that tests the mode 0, 1, 2 in that order; the two
 * calls are in a different order in mode 0 than in modes 1 and 2.
 */
extern void ldc_hw_set_reg200_bit31_inverted(unsigned char on);
extern void ldc_hw_enable_with_irq(unsigned char on);

/*
 * Set the two enable switches of the grid block.
 *
 *   mode  0: both off (second enable first, then the main enable);
 *         1: main enable on, second enable off;
 *         2: both on (main enable first, then the second enable);
 *         anything else does nothing.
 *
 * Called by ldc_user_apply_grid_enable, UserSetProMode, UserSetGameMode and sys_user_factory_reset.
 */
void ldc_hw_api_set_enable_mode(unsigned char mode)
{
    if (mode == 0) {
        ldc_hw_set_reg200_bit31_inverted(0);
        ldc_hw_enable_with_irq(0);
    } else if (mode == 1) {
        ldc_hw_enable_with_irq(1);
        ldc_hw_set_reg200_bit31_inverted(0);
    } else if (mode == 2) {
        ldc_hw_enable_with_irq(1);
        ldc_hw_set_reg200_bit31_inverted(1);
    }
}
