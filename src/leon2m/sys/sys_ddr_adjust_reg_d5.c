/* sys_ddr_adjust_reg_d5  (FUN_a00e2288)
 *
 * Add a step to register 0xD5 of a memory interface and update register 0xD6.
 * Name basis: descriptive - mode-dependent mask
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2288 @ 0xa00e2288-0xa00e2340 (46 words), flags: section default (-mcpu=v8 -O2 -g).
 * Source form: the two masks are locals set before the generation test; the third write is a nested call of the
 * masked read.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Add `delta` to register 0xd5 of memory interface phy and bring register 0xd6 along. Called by
 * sys_ddr_train_clk_tree with delta -1, 1 or 0.
 *
 * The bits of register 0xd5 that count are 0x3f, or 0x1f for generation 3. Bit 4 (mask 0x10) of register 0 is
 * read first. If it is 0, register 0xd6 gets (register 0xd5 & 0x1f) + 0x10, under the mask 0x1f for generation 4
 * and no mask (nothing changes) otherwise. If it is 0x10, register 0xd6 is left alone. The read is masked
 * with 0x10, so no other value can come up; the code for it prints the current step, the "ddr_err: " prefix
 * and a message that names the setting add_DPHY_CTRL_QDR_PH_SEL.
 */
void sys_ddr_adjust_reg_d5(unsigned int phy, unsigned int generation, unsigned int delta)
{
    unsigned int reg0_bit4 = sys_ddr_phy_read_masked(phy, 0, 0x10);
    unsigned int d5_mask = 0x3f;
    unsigned int d6_mask = 0;

    if (generation == 4)
        d6_mask = 0x1f;
    else if (generation == 3)
        d5_mask = 0x1f;
    sys_ddr_phy_update_bits(phy, 0xd5, d5_mask, sys_ddr_phy_read_masked(phy, 0xd5, d5_mask) + delta);
    if (reg0_bit4 == 0)
        sys_ddr_phy_update_bits(phy, 0xd6, d6_mask, sys_ddr_phy_read_masked(phy, 0xd5, 0x1f) + 0x10);
    else if (reg0_bit4 != 0x10) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: NOT possible in this case !!! Please check add_DPHY_CTRL_QDR_PH_SEL !!!\n");
    }
}
