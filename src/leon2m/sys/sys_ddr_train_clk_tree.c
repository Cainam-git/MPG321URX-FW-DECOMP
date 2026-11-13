/* sys_ddr_train_clk_tree  (FUN_a00e2340)
 *
 * Run training step 1 (CLK_TREE): step register 0xD5 until status bits 0x80 and 0x40 are right.
 * Returns: 0 or -1
 * Note: Every failure prints CASE_D_ERROR; the tests for CASE_A, B and C can never be true (the counters stop
 *   at 64).
 * Name basis: proven - sets training step 1, which the firmware prints as "CLK_TREE"; prints
 *   'Error:CASE_D_ERROR!!!'
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the counters are set after the two entry calls. When a flag is set, 'step = 0; if (only_80)
 * step = -1; else if (only_40) step = 1;' is followed by 'if (step == -1) { loop } else if (step == 1) { loop }
 * else { both-set arm }', with step as the third argument of sys_ddr_adjust_reg_d5. The test of bit 0x40 follows
 * the test of bit 0x80 and both branch to their loops. Each inner loop leaves with 'break' when its bit clears
 * and the 'return 0' follows the loop. The failure tree tests i > 64 first.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern void sys_ddr_delay(unsigned int);
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_adjust_reg_d5(unsigned int phy, unsigned int generation, unsigned int delta);

/* Status register 0x3e: the two bits that steer the search. */
#define STATUS_REG          0x3e
#define STATUS_BIT_80       0x80
#define STATUS_BIT_40       0x40

/* Bound on every counter of the search. */
#define SEARCH_LIMIT        64

/*
 * Training step 1 (CLK_TREE): move register 0xD5 of memory interface phy until status bits 0x80 and 0x40 of
 * register 0x3e no longer say "move on". Returns 0 when it settled, -1 when it gave up. The script runner calls
 * it for every interface of a unit.
 *
 * version and generation are the values sys_ddr_check_arguments checks (generation 3 or 4); generation also
 * picks the coarse step size.
 *
 * Each round waits one delay unit and reads both bits:
 *   - neither set: add a coarse step to register 0xD5 (8 for generation 3, 16 otherwise);
 *   - only 0x80 set: add -1 step by step, re-reading the bit after each, up to 64 times; if the bit clears the
 *     routine returns 0;
 *   - only 0x40 set: the same with +1 and bit 0x40;
 *   - both set: count the round and wait one more delay unit.
 * The search stops when the coarse steps, the both-set rounds or the fine steps reach 64. It then prints
 * "Error:CASE_x_ERROR!!!" with the step line and returns -1. The fine-step and coarse-step counters stop at 64,
 * so the tests for more than 64 in the error tree are never true and the text that is printed is always
 * CASE_D_ERROR.
 */
int sys_ddr_train_clk_tree(unsigned int phy, unsigned int version, unsigned int generation)
{
    int fine_steps, coarse_steps, both_rounds;
    int bit_80, bit_40;
    int step;

    sys_ddr_set_step(1, phy, -1);
    sys_ddr_check_arguments(phy, version, generation);
    fine_steps = 0;
    coarse_steps = 0;
    both_rounds = 0;
    bit_80 = 0;
    bit_40 = 0;
    while (coarse_steps < SEARCH_LIMIT && both_rounds < SEARCH_LIMIT && fine_steps < SEARCH_LIMIT) {
        sys_ddr_delay(1);
        bit_80 = sys_ddr_phy_read_masked(phy, STATUS_REG, STATUS_BIT_80) == STATUS_BIT_80;
        bit_40 = sys_ddr_phy_read_masked(phy, STATUS_REG, STATUS_BIT_40) == STATUS_BIT_40;
        if (!bit_80 && !bit_40) {
            /* Neither bit: far from the target, take a coarse step. */
            sys_ddr_adjust_reg_d5(phy, generation, generation == 3 ? 8 : 16);
            coarse_steps++;
        } else {
            step = 0;
            if (bit_80 && !bit_40)
                step = -1;
            else if (bit_40 && !bit_80)
                step = 1;
            if (step == -1) {
                for (fine_steps = 0; fine_steps < SEARCH_LIMIT; ) {
                    sys_ddr_adjust_reg_d5(phy, generation, step);
                    bit_80 = sys_ddr_phy_read_masked(phy, STATUS_REG, STATUS_BIT_80) == STATUS_BIT_80;
                    fine_steps++;
                    if (!bit_80)
                        break;
                }
                if (!bit_80)
                    return 0;
            } else if (step == 1) {
                for (fine_steps = 0; fine_steps < SEARCH_LIMIT; ) {
                    sys_ddr_adjust_reg_d5(phy, generation, step);
                    bit_40 = sys_ddr_phy_read_masked(phy, STATUS_REG, STATUS_BIT_40) == STATUS_BIT_40;
                    fine_steps++;
                    if (!bit_40)
                        break;
                }
                if (!bit_40)
                    return 0;
            } else {
                both_rounds++;
                sys_ddr_delay(1);
            }
        }
    }
    if (fine_steps > SEARCH_LIMIT) {
        if (bit_80 && !bit_40) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error:CASE_A_ERROR!!!\n");
        } else {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error:CASE_B_ERROR!!!\n");
        }
    } else {
        if (coarse_steps > SEARCH_LIMIT) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error:CASE_C_ERROR!!!\n");
        } else {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error:CASE_D_ERROR!!!\n");
        }
    }
    return -1;
}
