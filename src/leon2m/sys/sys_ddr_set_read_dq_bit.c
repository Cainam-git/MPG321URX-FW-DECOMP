/* sys_ddr_set_read_dq_bit  (FUN_a00e7dc8)
 *
 * Write the read deskew control bit of one data line.
 * Name basis: derived - checks byte_idx 0..3 and dq_idx 0..7 with error messages
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e7dc8 @ 0xa00e7dc8, flags -mcpu=v8 -O3 -g.
 * Source form: byte_idx and dq_idx are signed ints; each range test (x < 0 || x > n) folds into one unsigned
 * compare. The second error message prints byte_idx, as the firmware does.
 */
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern int sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Set (set == 1) or clear the read deskew control bit of data line `dq_idx` of data byte `byte_idx` of memory
 * interface `unit`.
 *
 * The bit lies in one of the registers 0x1b6 + 3 * byte_idx (dq_idx 0..3, bits 4..7), 0x1b7 + 3 * byte_idx
 * (dq_idx 4..7, bits 0..3). Data byte 3 differs: its bits are in register 0x1bf (bit dq_idx + 1), except dq_idx 7,
 * which is bit 6 of register 0x1bd.
 *
 * Returns 0, or -1 after an error message when byte_idx is not 0..3 or dq_idx is not 0..7. (The dq_idx message
 * prints byte_idx.)
 * Called by sys_ddr_train_read_deskew, nine times.
 */
int sys_ddr_set_read_dq_bit(unsigned int unit, int byte_idx, int dq_idx, int set)
{
    unsigned int reg, mask;

    if (byte_idx < 0 || byte_idx > 3) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: byte_idx=%d, sould never here.\n", byte_idx);
        return -1;
    }
    if (dq_idx < 0 || dq_idx > 7) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: dq_idx=%d, sould never here.\n", byte_idx);
        return -1;
    }
    if (byte_idx == 3) {
        if (dq_idx > 6) {
            reg = 0x1bd;
            mask = 0x40;
        } else {
            reg = 0x1bf;
            mask = 1 << (dq_idx + 1);
        }
    } else if (dq_idx < 4) {
        reg = byte_idx * 3 + 0x1b6;
        mask = 1 << (dq_idx + 4);
    } else {
        reg = byte_idx * 3 + 0x1b7;
        mask = 1 << (dq_idx - 4);
    }
    sys_ddr_phy_update_bits(unit, reg, mask, set == 1 ? mask : 0);
    return 0;
}
