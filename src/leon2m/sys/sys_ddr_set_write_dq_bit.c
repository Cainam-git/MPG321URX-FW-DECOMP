/* sys_ddr_set_write_dq_bit  (FUN_a00ea25c)
 *
 * Write the write deskew control bit of one data line.
 * Name basis: derived - checks byte_idx 0..3 and dq_idx 0..7 with error messages
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ea25c @ 0xa00ea25c, flags -mcpu=v8 -O3 -g.
 * Source form: both range checks come before the computation of the register number and the mask; byte_idx and
 * dq_idx are unsigned, so one compare covers each range.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Set (on == 1) or clear the write deskew control bit of data line `dq_idx` of data byte `byte_idx` of memory
 * interface `unit`: bit dq_idx of register 0x1b5 + 3 * byte_idx.
 *
 * Returns 0, or -1 after an error message when byte_idx is above 3 or dq_idx is above 7.
 * Called by sys_ddr_write_deskew_coarse and sys_ddr_write_deskew_fine.
 */
int sys_ddr_set_write_dq_bit(unsigned int unit, unsigned int byte_idx, unsigned int dq_idx, unsigned int on)
{
    unsigned int reg, mask;

    if (byte_idx > 3) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: byte_idx=%d, sould never here.\n", byte_idx);
        return -1;
    }
    if (dq_idx > 7) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: dq_idx=%d, sould never here.\n", dq_idx);
        return -1;
    }
    reg = byte_idx * 3 + 0x1b5;
    mask = 1 << dq_idx;
    if (on == 1)
        sys_ddr_phy_update_bits(unit, reg, mask, mask);
    else
        sys_ddr_phy_update_bits(unit, reg, mask, 0);
    return 0;
}
