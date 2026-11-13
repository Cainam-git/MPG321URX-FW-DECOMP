/* sys_ddr_add_qs_gate_sel  (FUN_a00e5428)
 *
 * Add one step to the strobe gate selection of a data byte.
 * Name basis: proven - prints 'Error: add_qs_gate_sel(phy_id, ) impossible val_qs_gate_sel ...'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e5428 @ 0xa00e5428-0xa00e55ec (452 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - both arms test step == 1 first and write the field in each branch; cross-jumping merges the writes and
 *    keeps the gate_sel == 1 arm's wrap-delay call out of line (0xa00e554c, entered by the bne,a at 0xa00e5500);
 *  - every table access is its own if (byte == -1)/else statement, as in src/leon2m/sys/sys_ddr_add_qsen_wrap_delay.c.
 */
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_add_qsen_wrap_delay(unsigned int phy, int byte, int step);
extern unsigned int sys_ddr_qs_gate_sel_shifts[];
extern unsigned int sys_ddr_qs_gate_sel_masks[];
extern unsigned int sys_ddr_qs_gate_sel_regs[];

/* The two values the qs_gate_sel field takes. */
#define QS_GATE_SEL_FIRST  1
#define QS_GATE_SEL_SECOND 3

/*
 * Move the strobe gate of one data byte of a memory interface by one step, earlier or later.
 *
 *   phy   the memory interface (phy_id in the messages)
 *   byte  the data byte: the entry of the three qs_gate_sel tables (register, mask, shift); -1 passes the
 *         addresses of the three tables themselves in place of an entry
 *   step  -1, 0 or +1; 0 does nothing
 *
 * Returns 0, or -1 for a step of more than one or a field value other than 1 and 3 (after printing an error),
 * or the error of sys_ddr_add_qsen_wrap_delay.
 *
 * qs_gate_sel holds 1 or 3, and the strobe-enable wrap delay counts above it: stepping up from 1 gives 3,
 * stepping up from 3 adds 1 to the wrap delay and gives 1; stepping down mirrors that. The wrap delay is changed
 * first, so its range check can refuse the step before qs_gate_sel is written.
 *
 * Called by sys_ddr_move_qs_gate with one step up or down when the move it makes would leave the range of the
 * finer field it moves itself.
 */
int sys_ddr_add_qs_gate_sel(unsigned int phy, int byte, int step)
{
    int gate_sel, error;

    if (step < -1 || step > 1) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("TODO: add_qs_gate_sel(phy_id, ) not implement more than 1 or -1 steps.\n");
        return -1;
    }
    if (step == 0)
        return 0;

    if (byte == -1)
        gate_sel = sys_ddr_phy_read_field(phy, (unsigned int)sys_ddr_qs_gate_sel_regs, (unsigned int)sys_ddr_qs_gate_sel_masks, (unsigned int)sys_ddr_qs_gate_sel_shifts);
    else
        gate_sel = sys_ddr_phy_read_field(phy, sys_ddr_qs_gate_sel_regs[byte], sys_ddr_qs_gate_sel_masks[byte], sys_ddr_qs_gate_sel_shifts[byte]);
    if (gate_sel == QS_GATE_SEL_FIRST) {
        if (step == 1) {
            if (byte == -1)
                sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qs_gate_sel_regs, (unsigned int)sys_ddr_qs_gate_sel_masks, (unsigned int)sys_ddr_qs_gate_sel_shifts, QS_GATE_SEL_SECOND);
            else
                sys_ddr_phy_write_field(phy, sys_ddr_qs_gate_sel_regs[byte], sys_ddr_qs_gate_sel_masks[byte], sys_ddr_qs_gate_sel_shifts[byte], QS_GATE_SEL_SECOND);
        } else {
            /* Down from the first value: borrow one from the wrap delay. */
            error = sys_ddr_add_qsen_wrap_delay(phy, byte, -1);
            if (error != 0)
                return error;
            if (byte == -1)
                sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qs_gate_sel_regs, (unsigned int)sys_ddr_qs_gate_sel_masks, (unsigned int)sys_ddr_qs_gate_sel_shifts, QS_GATE_SEL_SECOND);
            else
                sys_ddr_phy_write_field(phy, sys_ddr_qs_gate_sel_regs[byte], sys_ddr_qs_gate_sel_masks[byte], sys_ddr_qs_gate_sel_shifts[byte], QS_GATE_SEL_SECOND);
        }
    } else if (gate_sel == QS_GATE_SEL_SECOND) {
        if (step == 1) {
            error = sys_ddr_add_qsen_wrap_delay(phy, byte, 1);
            if (error != 0)
                return error;
            if (byte == -1)
                sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qs_gate_sel_regs, (unsigned int)sys_ddr_qs_gate_sel_masks, (unsigned int)sys_ddr_qs_gate_sel_shifts, QS_GATE_SEL_FIRST);
            else
                sys_ddr_phy_write_field(phy, sys_ddr_qs_gate_sel_regs[byte], sys_ddr_qs_gate_sel_masks[byte], sys_ddr_qs_gate_sel_shifts[byte], QS_GATE_SEL_FIRST);
        } else {
            if (byte == -1)
                sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qs_gate_sel_regs, (unsigned int)sys_ddr_qs_gate_sel_masks, (unsigned int)sys_ddr_qs_gate_sel_shifts, QS_GATE_SEL_FIRST);
            else
                sys_ddr_phy_write_field(phy, sys_ddr_qs_gate_sel_regs[byte], sys_ddr_qs_gate_sel_masks[byte], sys_ddr_qs_gate_sel_shifts[byte], QS_GATE_SEL_FIRST);
        }
    } else {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: add_qs_gate_sel(phy_id, ) impossible val_qs_gate_sel = %d\n", gate_sel);
        return -1;
    }
    return 0;
}
