/* sys_ddr_write_deskew_fine  (FUN_a00ea638)
 *
 * Run the fail-mask passes of the write deskew of one data byte.
 * Name basis: proven - prints 'Error: Bist result = %d, dq_fail = %d, dq_fail_fw = %d.'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ea638 @ 0xa00ea638-0xa00ea878, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form the exact build depends on: the second read of dq_fail and both tests after it are written in each
 * arm of if (byte == -1) inside for (;;); the addresses of the tables sys_ddr_wr_deskew_dq_regs and
 * sys_ddr_wr_deskew_dq_masks are held in the pointer locals dq_regs / dq_masks before the loop (dq_masks declared
 * first, dq_regs assigned first: the declaration order sets the order of the address pseudos and so the register
 * choices).
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
 * Fine part of the write deskew of one data byte: delay every line by single steps until each has been seen to fail.
 *
 *   unit            memory interface number
 *   phy_version     with ddr_generation and bit_mode, passed on to the write self-test (sys_ddr_run_bist_write)
 *   ddr_generation
 *   byte            data byte; with -1 the tables' own addresses are passed in place of an entry
 *   bit_mode
 *
 * Returns 0, or -1 (after printing the step and an error message), or the failure of sys_ddr_set_write_dq_bit.
 * Called by sys_ddr_train_write_deskew, after sys_ddr_write_deskew_coarse.
 *
 * Every line has its own delay register (wr_deskew_dq_regs[byte] + line); dq_fail has one bit per line, set when
 * the write self-test failed on it. Each pass adds 1 to the delay of every line that neither fails nor is settled
 * yet and writes its control bit 0, 1, 0; a line that fails is marked settled instead and not touched again.
 * Then the write self-test runs. With a result of 0 or 1 the routine returns 0 once all eight lines are settled
 * and otherwise starts the next pass; any other result prints "Bist result = %d, dq_fail = %d, dq_fail_fw = %d"
 * (with the settled mask as the last value) and returns -1. The delay registers are indexed by byte even when
 * byte is -1.
 */
int sys_ddr_write_deskew_fine(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, unsigned int bit_mode)
{
    unsigned int dq_fail, settled, delay;
    unsigned int bist_result;
    int line, status;
    unsigned int *dq_masks, *dq_regs;

    settled = 0;
    if (byte == -1)
        dq_fail = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026268_dq_fail_reg, (unsigned int)DAT_a8026258_dq_fail_msk, (unsigned int)DAT_a802b618_dq_fail_sft);
    else
        dq_fail = sys_ddr_phy_read_field(unit, DAT_a8026268_dq_fail_reg[byte], DAT_a8026258_dq_fail_msk[byte], DAT_a802b618_dq_fail_sft[byte]);
    dq_regs = sys_ddr_wr_deskew_dq_regs;
    dq_masks = sys_ddr_wr_deskew_dq_masks;
    for (;;) {
        for (line = 0; line < 8; line++) {
            /* Still passing and not settled: one more delay step. Otherwise it is settled. */
            if (!((1 << line) & dq_fail) && !((1 << line) & settled)) {
                delay = sys_ddr_phy_read_masked(unit, dq_regs[byte] + line, dq_masks[byte]);
                sys_ddr_phy_update_bits(unit, dq_regs[byte] + line, dq_masks[byte], delay + 1);
                status = sys_ddr_set_write_dq_bit(unit, byte, line, 0);
                if (status)
                    return status;
                status = sys_ddr_set_write_dq_bit(unit, byte, line, 1);
                if (status)
                    return status;
                status = sys_ddr_set_write_dq_bit(unit, byte, line, 0);
                if (status)
                    return status;
            } else
                settled |= 1 << line;
        }
        bist_result = sys_ddr_run_bist_write(unit, phy_version, ddr_generation, bit_mode);
        if (byte == -1) {
            dq_fail = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026268_dq_fail_reg, (unsigned int)DAT_a8026258_dq_fail_msk, (unsigned int)DAT_a802b618_dq_fail_sft);
            if ((bist_result < 2) & (settled == 0xff))
                return 0;
            if (((bist_result < 2) & (settled != 0xff)) == 0)
                break;
        } else {
            dq_fail = sys_ddr_phy_read_field(unit, DAT_a8026268_dq_fail_reg[byte], DAT_a8026258_dq_fail_msk[byte], DAT_a802b618_dq_fail_sft[byte]);
            if ((bist_result < 2) & (settled == 0xff))
                return 0;
            if (((bist_result < 2) & (settled != 0xff)) == 0)
                break;
        }
    }
    sys_ddr_print_step();
    sys_ddr_print_error_prefix();
    dbg_printf("Error: Bist result = %d, dq_fail = %d, dq_fail_fw = %d.\n", bist_result, dq_fail, settled);
    return -1;
}
