/* sys_ddr_set_pll  (FUN_a00dffd8)
 *
 * Check the interface number and write its clock value.
 * Name basis: derived - one script command
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dffd8 @ 0xa00dffd8-0xa00e0040 (26 words), flags -mcpu=v8 -O2 -g.
 * Source form: the third argument of sys_ddr_set_pll_value is set before each tail call (that routine reads two
 * arguments, the compiler still loads the constant).
 */
extern int sys_ddr_check_phy_id(unsigned int id);
extern void sys_ddr_set_pll_value(int, int, int);

/*
 * Write a clock value (value_a, value_b) for memory interface id. The result of the interface check is not used:
 * an interface number above 2 is reported by the check, and then nothing is written. Interfaces 0 and 2 pass 1
 * as the last argument to sys_ddr_set_pll_value, interface 1 passes 2.
 */
void sys_ddr_set_pll(unsigned int id, int value_a, int value_b)
{
    sys_ddr_check_phy_id(id);
    if (id == 0 || id == 2)
        sys_ddr_set_pll_value(value_a, value_b, 1);
    else if (id == 1)
        sys_ddr_set_pll_value(value_a, value_b, 2);
}
