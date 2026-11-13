/* sys_ddr_write_deskew_coarse  (FUN_a00ea308)
 *
 * Run the coarse passes of the write deskew of one data byte.
 * Name basis: proven - prints 'Error: wr_deskew_cdly_state_error_flag = %d.' and the self-test result
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ea308 @ 0xa00ea308-0xa00ea638, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form the exact build depends on: the loop over the lines with ((coarse - 1) << 3) follows the outer
 * for (;;), left by 'break'; in both loops the low bits stay in delay ('delay &= 7;' before the coarse test) and
 * new_delay is formed after the test.
 * Names: the match depends on the names DAT_a8026268_dq_fail_reg, DAT_a8026258_dq_fail_msk and
 *   DAT_a802b618_dq_fail_sft (gcse orders the hoisted %hi parts of the three tables by a hash of the names).
 */
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_run_bist_write(unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_set_write_dq_bit(unsigned int, int, int, int);
extern unsigned int DAT_a8026268_dq_fail_reg[], DAT_a8026258_dq_fail_msk[], DAT_a802b618_dq_fail_sft[];
extern unsigned int sys_ddr_wr_deskew_dq_regs[], sys_ddr_wr_deskew_dq_masks[];

/*
 * Coarse part of the write deskew of one data byte: bring all eight data lines to the point where they just fail.
 *
 *   unit            memory interface number
 *   phy_version     with ddr_generation and bit_mode, passed on to the write self-test (sys_ddr_run_bist_write)
 *   ddr_generation
 *   byte            data byte; with -1 the tables' own addresses are passed in place of an entry
 *   bit_mode
 *
 * Returns 0, or -1 (after printing the step and an error message), or the failure of sys_ddr_set_write_dq_bit.
 * Called by sys_ddr_train_write_deskew.
 *
 * Every line has its own delay register (wr_deskew_dq_regs[byte] + line); the delay value is the coarse part
 * (value >> 3) and the low 3 bits. The field dq_fail has one bit per line, set when the self-test failed on it.
 * Each pass raises the coarse part by one on every line that does not fail yet, then runs the write self-test and
 * reads dq_fail again. The passes end when the test returns 1 and all eight bits are set; a result of 0 or 1
 * with bits still clear starts another pass; any other result stops with the "Bist result" error. When a line is already at coarse part
 * 0xF the "wr_deskew_cdly_state_error_flag" error is printed. Afterwards every line with a coarse part above 0 is
 * set one coarse step back. After each new delay the control bit of the line is written 0, 1, 0. The delay
 * registers are indexed by byte even when byte is -1.
 */
int sys_ddr_write_deskew_coarse(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, unsigned int bit_mode)
{
    unsigned int dq_fail, delay, coarse, new_delay;
    unsigned int bist_result;
    int line, status;

    if (byte == -1)
        dq_fail = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026268_dq_fail_reg, (unsigned int)DAT_a8026258_dq_fail_msk, (unsigned int)DAT_a802b618_dq_fail_sft);
    else
        dq_fail = sys_ddr_phy_read_field(unit, DAT_a8026268_dq_fail_reg[byte], DAT_a8026258_dq_fail_msk[byte], DAT_a802b618_dq_fail_sft[byte]);
    for (;;) {
        for (line = 0; line < 8; line++) {
            /* A line that already fails is left alone. */
            if ((1 << line) & dq_fail)
                continue;
            delay = sys_ddr_phy_read_masked(unit, sys_ddr_wr_deskew_dq_regs[byte] + line, sys_ddr_wr_deskew_dq_masks[byte]);
            coarse = delay >> 3;
            delay &= 7;
            if (coarse == 0xf) {
                sys_ddr_print_step();
                sys_ddr_print_error_prefix();
                dbg_printf("Error: wr_deskew_cdly_state_error_flag = %d.\n", 1);
                return -1;
            }
            new_delay = ((coarse + 1) << 3) + delay;
            sys_ddr_phy_update_bits(unit, sys_ddr_wr_deskew_dq_regs[byte] + line, sys_ddr_wr_deskew_dq_masks[byte], new_delay);
            status = sys_ddr_set_write_dq_bit(unit, byte, line, 0);
            if (status)
                return status;
            status = sys_ddr_set_write_dq_bit(unit, byte, line, 1);
            if (status)
                return status;
            status = sys_ddr_set_write_dq_bit(unit, byte, line, 0);
            if (status)
                return status;
        }
        bist_result = sys_ddr_run_bist_write(unit, phy_version, ddr_generation, bit_mode);
        if (byte == -1)
            dq_fail = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026268_dq_fail_reg, (unsigned int)DAT_a8026258_dq_fail_msk, (unsigned int)DAT_a802b618_dq_fail_sft);
        else
            dq_fail = sys_ddr_phy_read_field(unit, DAT_a8026268_dq_fail_reg[byte], DAT_a8026258_dq_fail_msk[byte], DAT_a802b618_dq_fail_sft[byte]);
        if ((bist_result == 1) & (dq_fail == 0xff))
            break;
        if ((bist_result < 2) & (dq_fail != 0xff))
            continue;
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: Bist result = %d, dq_fail = %d.\n", bist_result, dq_fail);
        return -1;
    }
    /* All lines fail now: take the coarse part of each one step back. */
    for (line = 0; line < 8; line++) {
        delay =sys_ddr_phy_read_masked(unit, sys_ddr_wr_deskew_dq_regs[byte] + line, sys_ddr_wr_deskew_dq_masks[byte]);
        coarse = delay >> 3;
        delay &= 7;
        if (coarse == 0)
            continue;
        new_delay = ((coarse - 1) << 3) + delay;
        sys_ddr_phy_update_bits(unit, sys_ddr_wr_deskew_dq_regs[byte] + line, sys_ddr_wr_deskew_dq_masks[byte], new_delay);
        status = sys_ddr_set_write_dq_bit(unit, byte, line, 0);
        if (status)
            return status;
        status = sys_ddr_set_write_dq_bit(unit, byte, line, 1);
        if (status)
            return status;
        status = sys_ddr_set_write_dq_bit(unit, byte, line, 0);
        if (status)
            return status;
    }
    return 0;
}
