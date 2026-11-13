/* sys_ddr_find_write_window_lower_edge  (FUN_a00eba64)
 *
 * Find the lower edge of the passing write delay window of a data byte with read self-tests.
 * Returns: step << 8 | clk_cdly << 3 | field 2, or -1
 * Note: Searches down from a start point; sys_ddr_train_write_eye searches the upper edge itself.
 * Name basis: derived - prints 'Error: Bist timeout.'; searches downwards with sys_ddr_run_bist_read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00eba64 @ 0xa00eba64-0xa00ec340 (2268 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on: as in sys_ddr_train_write_deskew, one 'if (byte == -1) { ... } else
 * { ... }' block per field update and reads inside conditions written 'byte == -1 ? R : R'.
 * Names: the tables 0xa8026798/788/778 and 0xa8026748/738/728 have no identifier in the firmware;
 * sys_ddr_train_write_deskew prints "DQ clk cdly is full" for the first field and sys_ddr_train_write_eye prints
 * "wr_eye_lcdly_state_error_flag" for the pair. GCC orders the high parts of the six addresses by a hash of the
 * symbol name (gcse.c), and the firmware's registers (0xa00ebc30..0xa00ebc44: %l7, %i2, %i5 / %l4, %l5, %l6) need
 * the order reg < shift < mask for the first triple and reg < mask < shift for the second. The spellings
 * DAT_a8026798_clk_cdly_reg / _msk / _sft and DAT_a8026748_eye_lcdly_reg / _msk / _sft give this order with one
 * suffix style for both triples; the six other users build to the same bytes with them.
 */
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_set_write_delay_fields(unsigned int, int, int, unsigned int, unsigned int);
extern int sys_ddr_run_bist_read(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *, ...);
/* Each field is entry `byte` of three tables (register, mask, shift). clk_cdly is the field the message "DQ clk
   cdly is full" names, wr_eye_lcdly the one of "wr_eye_lcdly_state_error_flag"; sys_ddr_write_delay_field1_regs is the register
   table of field 1. */
extern unsigned int sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[], sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[], sys_ddr_write_delay_field6_regs[], sys_ddr_write_delay_field6_masks[], sys_ddr_write_delay_field6_shifts[], DAT_a8026798_clk_cdly_reg[], DAT_a8026788_clk_cdly_msk[], DAT_a8026778_clk_cdly_sft[], DAT_a8026748_eye_lcdly_reg[], DAT_a8026738_eye_lcdly_msk[], DAT_a8026728_eye_lcdly_sft[], sys_ddr_write_delay_field2_regs[], sys_ddr_write_delay_field2_masks[], sys_ddr_write_delay_field2_shifts[], sys_ddr_write_delay_field1_regs[], sys_ddr_write_delay_field1_masks[], sys_ddr_write_delay_field1_shifts[];

/* Results of the self-test (sys_ddr_run_bist_read); any other value is reported as a timeout. */
#define BIST_PASS 0
#define BIST_FAIL 1

#define FIELD6_STEP_LIMIT 8         /* field 6 is 3 for a step count above this, else 0 */
#define FIELD6_FAR        3
#define CLK_CDLY_FULL     0xf       /* highest clk_cdly value */
#define FINE_MAX          7         /* highest value of the three-bit field 2 before the carry into clk_cdly */

/*
 * Find the lower edge of the passing write delay window of one data byte, searching down from a start point.
 *
 *   unit            memory interface number
 *   phy_version     with ddr_generation and bit_mode, passed on to the self-test (sys_ddr_run_bist_read)
 *   ddr_generation
 *   byte            data byte; with -1 the tables' own addresses are passed in place of an entry
 *   step            number of whole steps above field 5 to start from
 *   field2_value    handed on to sys_ddr_set_write_delay_fields, which takes only three arguments and does not
 *   clk_cdly_value  use them (sys_ddr_train_write_eye passes the values of field 2 and clk_cdly it read first)
 *   bit_mode
 *
 * Returns the edge as step << 8 | clk_cdly << 3 | field 2, or -1 when the self-test at the start point does not
 * pass (no message) or a self-test times out ("Bist timeout"). Called by sys_ddr_train_write_eye, which searches
 * the upper edge the same way upwards and converts both edges to delay units ((edge >> 8) * dly_per_cnt +
 * (edge & 0xFF)).
 *
 * The self-test used here is the read test, sys_ddr_run_bist_read, although the fields set are the write delay
 * fields.
 *
 * Phases:
 *   0. Put the delay at field 5 + step with the rest cleared (sys_ddr_set_write_delay_fields); the self-test must
 *      pass there.
 *   1. Lower fields 4 and 3 together by one whole step per self-test (field 6 = 3 while the step count is above
 *      8, else 0) until the test fails. When the step count reaches 0 with every test passing, phases 2 and 3 are
 *      skipped and the edge is 0.
 *   2. From the failing step, raise clk_cdly and wr_eye_lcdly together by one per self-test while it fails; at
 *      the first pass, take both one step back. Raising stops without a step back when clk_cdly reaches 0xF.
 *   3. Raise field 2 and field 1 together by one per self-test while it fails, raising clk_cdly and wr_eye_lcdly
 *      too each time field 2 reads 7. It must end on a pass.
 *   4. Read the fields back and build the result. Fields 4 and 3 are read as well; their values are not used.
 */
int sys_ddr_find_write_window_lower_edge(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, int step, unsigned int field2_value,
                 unsigned int clk_cdly_value, unsigned int bit_mode)
{
    unsigned int value, coarse, fine;
    int status;

    /* Phase 0: start point. */
    sys_ddr_set_write_delay_fields(unit, byte, step, field2_value, clk_cdly_value);
    status = sys_ddr_run_bist_read(unit, phy_version, ddr_generation, bit_mode);
    if (status != BIST_PASS)
        return -1;
    /* Phase 1: whole steps down until the test fails. */
    for (;;) {
        if (step == 0)
            break;
        step--;
        if (byte == -1) {
            value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts);
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts, value - 1);
        } else {
            value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte]);
            sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte], value - 1);
        }
        if (byte == -1) {
            value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts);
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts, value - 1);
        } else {
            value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte]);
            sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte], value - 1);
        }
        /* Field 6 follows the step count, as in sys_ddr_set_write_delay_fields. */
        if (step > FIELD6_STEP_LIMIT) {
            if (byte == -1)
                sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field6_regs, (unsigned int)sys_ddr_write_delay_field6_masks, (unsigned int)sys_ddr_write_delay_field6_shifts, FIELD6_FAR);
            else
                sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field6_regs[byte], sys_ddr_write_delay_field6_masks[byte], sys_ddr_write_delay_field6_shifts[byte], FIELD6_FAR);
        } else {
            if (byte == -1)
                sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field6_regs, (unsigned int)sys_ddr_write_delay_field6_masks, (unsigned int)sys_ddr_write_delay_field6_shifts, 0);
            else
                sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field6_regs[byte], sys_ddr_write_delay_field6_masks[byte], sys_ddr_write_delay_field6_shifts[byte], 0);
        }
        status = sys_ddr_run_bist_read(unit, phy_version, ddr_generation, bit_mode);
        if (status == BIST_FAIL)
            break;
        if (status == BIST_PASS)
            continue;
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: Bist timeout.\n");
        return -1;
    }
    if (status == BIST_FAIL) {
        /* Phase 2: higher bits of the rest up while the test fails. */
        for (;;) {
            if (byte == -1) {
                value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft);
                sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, value + 1);
            } else {
                value = sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte]);
                sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], value + 1);
            }
            if (byte == -1) {
                value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft);
                sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, value + 1);
            } else {
                value = sys_ddr_phy_read_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte]);
                sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], value + 1);
            }
            status = sys_ddr_run_bist_read(unit, phy_version, ddr_generation, bit_mode);
            if (status == BIST_FAIL) {
                if ((byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft) : sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte])) == CLK_CDLY_FULL)
                    break;
                continue;
            }
            if (status == BIST_PASS) {
                /* Passing again: back to the last failing value. */
                if (byte == -1) {
                    value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft);
                    sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, value - 1);
                } else {
                    value = sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte]);
                    sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], value - 1);
                }
                if (byte == -1) {
                    value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft);
                    sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, value - 1);
                } else {
                    value = sys_ddr_phy_read_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte]);
                    sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], value - 1);
                }
                break;
            }
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            return -1;
        }
        /* Phase 3: low bits up while the test fails, with the carry at 7. */
        for (;;) {
            if (byte == -1) {
                value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts);
                sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts, value + 1);
            } else {
                value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte]);
                sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte], value + 1);
            }
            if (byte == -1) {
                value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts);
                sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts, value + 1);
            } else {
                value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte]);
                sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte], value + 1);
            }
            status = sys_ddr_run_bist_read(unit, phy_version, ddr_generation, bit_mode);
            if (status != BIST_FAIL)
                break;
            if ((byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts) : sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte])) == FINE_MAX) {
                if (byte == -1) {
                    value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft);
                    sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, value + 1);
                } else {
                    value = sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte]);
                    sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], value + 1);
                }
                if (byte == -1) {
                    value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft);
                    sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, value + 1);
                } else {
                    value = sys_ddr_phy_read_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte]);
                    sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], value + 1);
                }
            }
        }
        if (status != BIST_PASS) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            return -1;
        }
    }
    /* Phase 4: the edge as step count, clk_cdly and field 2. */
    if (byte == -1)
        sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts);
    else
        sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte]);
    if (byte == -1)
        sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts);
    else
        sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte]);
    if (byte == -1)
        coarse = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft);
    else
        coarse = sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte]);
    if (byte == -1)
        fine = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts);
    else
        fine = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte]);
    return step << 8 | coarse << 3 | fine;
}
