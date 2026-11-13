/* sys_ddr_add_qsen_wrap_delay  (FUN_a00e52e8)
 *
 * Add a step to the strobe-enable wrap delay of a data byte, with range check.
 * Name basis: proven - prints 'Error: qsen_wrap_dly_reg_b%d = %d, add %d will be overflow / underflow'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e52e8 @ 0xa00e52e8, flags -mcpu=v8 -O3 -g.
 * Source form: each register access is written twice (byte_idx == -1 passes the three table addresses
 * themselves, otherwise the table entries), as in src/leon2m/sys/sys_ddr_set_adj_table_fields_first.c; the delta tests are nested (delta > 0,
 * else delta < 0, each with its own range test).
 */
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_qsen_wrap_dly_shifts[];
extern unsigned int sys_ddr_qsen_wrap_dly_masks[];
extern unsigned int sys_ddr_qsen_wrap_dly_regs[];

/*
 * Add `delta` (may be negative) to the strobe-enable wrap delay field of data byte `byte_idx` of memory interface
 * `unit`. The field is held to 0..15: a result outside that range prints an error and changes nothing.
 *
 * The field is entry `byte_idx` of three parallel tables (register, mask, shift). With byte_idx == -1 the three
 * table addresses themselves are handed to the register access routines instead of an entry.
 *
 * Returns 0 on success (also when delta is 0), -1 when the result would overflow or underflow.
 * Called by the gate training (sys_ddr_train_qs_gate_byte) and sys_ddr_add_qs_gate_sel.
 */
int sys_ddr_add_qsen_wrap_delay(unsigned int unit, int byte_idx, int delta)
{
    int delay;

    if (byte_idx == -1)
        delay = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_qsen_wrap_dly_regs, (unsigned int)sys_ddr_qsen_wrap_dly_masks, (unsigned int)sys_ddr_qsen_wrap_dly_shifts);
    else
        delay = sys_ddr_phy_read_field(unit, sys_ddr_qsen_wrap_dly_regs[byte_idx], sys_ddr_qsen_wrap_dly_masks[byte_idx], sys_ddr_qsen_wrap_dly_shifts[byte_idx]);
    if (delta == 0)
        return 0;
    if (delta > 0) {
        if (15 - delay < delta) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: qsen_wrap_dly_reg_b%d = %d, add %d will be overflow.\n", byte_idx, delay, delta);
            return -1;
        }
    } else if (delta < 0) {
        if (delay + delta < 0) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: qsen_wrap_dly_reg_b%d = %d, add %d will be underflow.\n", byte_idx, delay, delta);
            return -1;
        }
    }
    if (byte_idx == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_qsen_wrap_dly_regs, (unsigned int)sys_ddr_qsen_wrap_dly_masks, (unsigned int)sys_ddr_qsen_wrap_dly_shifts, delay + delta);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_qsen_wrap_dly_regs[byte_idx], sys_ddr_qsen_wrap_dly_masks[byte_idx], sys_ddr_qsen_wrap_dly_shifts[byte_idx], delay + delta);
    return 0;
}
