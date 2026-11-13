/* sys_ddr_train_write_eye  (FUN_a00ec6b8)
 *
 * Train the write window of a data byte.
 * Name basis: derived - upward search, window search and centring
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ec6b8 @ 0xa00ec6b8-0xa00ed528 (3696 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the upper-edge search is a static helper (find_upper_edge) with early returns, inlined once before the
 *    sys_ddr_find_write_window_lower_edge call;
 *  - each field update (read and write-back of the same field) is one 'if (byte == -1) { .. } else { .. }' block
 *    (fw 0xa00ec89c..0xa00ec8f4: the byte arm of the two whole-step updates); other reads and writes are their own
 *    if (byte == -1)/else statement; reads inside conditions and the three saved words are 'byte == -1 ? R : R'
 *    (fw 0xa00ec784..0xa00ec818: one store to sys_ddr_write_delay_field5_value/670/674 after each join);
 *  - the result is a two-word structure returned by value.
 */
/* Lower and upper edge of the passing window, each as whole steps << 8 | clk_cdly << 3 | field 2. */
struct write_window { int low; int high; };
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_set_write_delay_fields(unsigned int, int, int, unsigned int, unsigned int);
extern int sys_ddr_run_bist_read(unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_find_write_window_lower_edge(unsigned int, unsigned int, unsigned int, int, int, unsigned int, unsigned int,
                        unsigned int);
extern void sys_ddr_set_write_delay_center(unsigned int, int, int, int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *, ...);
/* Field values read before the search; field 5's is the base sys_ddr_set_write_delay_fields starts from, the
   other two are written only. */
extern unsigned int sys_ddr_write_delay_field5_value, sys_ddr_write_delay_field4_value, sys_ddr_write_delay_field3_value;
/* Each field is entry `byte` of three tables (register, mask, shift). clk_cdly is the field the message "DQ clk
   cdly is full" names, wr_eye_lcdly the one of "wr_eye_lcdly_state_error_flag" below; sys_ddr_write_delay_field1_regs is the
   register table of field 1; the dly_per_cnt field gives the number of delay units in one whole step (it is
   used that way below and in sys_ddr_set_write_delay_center). */
extern unsigned int sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[];
extern unsigned int sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[];
extern unsigned int DAT_a8026798_clk_cdly_reg[], DAT_a8026788_clk_cdly_msk[], DAT_a8026778_clk_cdly_sft[];
extern unsigned int sys_ddr_write_delay_field2_regs[], sys_ddr_write_delay_field2_masks[], sys_ddr_write_delay_field2_shifts[];
extern unsigned int DAT_a8026748_eye_lcdly_reg[], DAT_a8026738_eye_lcdly_msk[], DAT_a8026728_eye_lcdly_sft[];
extern unsigned int sys_ddr_write_delay_field1_regs[], sys_ddr_write_delay_field1_masks[], sys_ddr_write_delay_field1_shifts[];
extern unsigned int sys_ddr_write_delay_field5_regs[], sys_ddr_write_delay_field5_masks[], sys_ddr_write_delay_field5_shifts[];
extern unsigned int sys_ddr_write_delay_field6_regs[], sys_ddr_write_delay_field6_masks[], sys_ddr_write_delay_field6_shifts[];
extern unsigned int DAT_a8026308_dly_per_cnt_reg[], DAT_a80262f8_dly_per_cnt_mask[], DAT_a802b638_dly_per_cnt_shift[];

#define DDR_STEP_W_EYE 11           /* training step number, printed as W_EYE by sys_ddr_print_step */
#define DDR3 3                      /* ddr_generation value */

/* Results of the self-test (sys_ddr_run_bist_read); any other value is reported as a timeout. */
#define BIST_PASS 0
#define BIST_FAIL 1

#define UPPER_STEP_LIMIT  12        /* the upward search stops at this many whole steps */
#define FIELD6_STEP_LIMIT 8         /* field 6 is 3 for a step count above this, else 0 */
#define FIELD6_FAR        3
#define CLK_CDLY_FULL     0xf       /* highest clk_cdly value */
#define FINE_MAX          7         /* highest value of the three-bit field 2 before the carry into clk_cdly */

/*
 * Upper edge of the passing write delay window of one data byte: the mirror of sys_ddr_find_write_window_lower_edge, searching
 * upwards from field 5 + step. Arguments as there. Returns the edge as step << 8 | clk_cdly << 3 | field 2, or -1.
 *
 *   0. Put the delay at the start point; the self-test must pass there (else -1, no message).
 *   1. Raise fields 4 and 3 by one whole step per self-test (field 6 follows the step count) until the test fails.
 *      At 12 whole steps with every test passing the search ends with 0xC00 (12 << 8). The limit is checked only
 *      for equality, so a start above 12 has none.
 *   2. Take the whole steps one back (not below 0).
 *   3. Raise clk_cdly and wr_eye_lcdly by one per self-test until it fails; still passing at clk_cdly 0xF prints
 *      "wr_eye_lcdly_state_error_flag" and gives -1. Then take both one step back.
 *   4. Raise field 2 and field 1 by one per self-test until it fails, raising clk_cdly and wr_eye_lcdly too each
 *      time field 2 reads 7 after a pass.
 *   5. Read the fields back and build the result (fields 4 and 3 are read and not used).
 * The self-test used is the read test, sys_ddr_run_bist_read. A result other than pass or fail prints "Bist
 * timeout" and gives -1.
 */

static unsigned int find_upper_edge(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, int step, unsigned int field2_value,
                              unsigned int clk_cdly_value, unsigned int bit_mode)
{
    unsigned int value, coarse, fine;
    int status;

    /* Phase 0: start point. */
    sys_ddr_set_write_delay_fields(unit, byte, step, field2_value, clk_cdly_value);
    status = sys_ddr_run_bist_read(unit, phy_version, ddr_generation, bit_mode);
    if (status != BIST_PASS)
        return -1;
    /* Phase 1: whole steps up until the test fails. */
    for (;;) {
        if (step == UPPER_STEP_LIMIT)
            return UPPER_STEP_LIMIT << 8;
        step++;
        if (byte == -1) {
            value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts);
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts, value + 1);
        } else {
            value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte]);
            sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte], value + 1);
        }
        if (byte == -1) {
            value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts);
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts, value + 1);
        } else {
            value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte]);
            sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte], value + 1);
        }
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
    /* Phase 2: back to the last passing whole step. */
    if (step > 0) {
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
    }
    /* Phase 3: higher bits of the rest up until the test fails. */
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
        if (status == BIST_FAIL)
            break;
        if (status != BIST_PASS) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            return -1;
        }
        if ((byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft) : sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte])) == CLK_CDLY_FULL) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: wr_eye_lcdly_state_error_flag.\n");
            return -1;
        }
    }
    /* Back to the last passing value. */
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
    /* Phase 4: low bits up until the test fails, with the carry at 7. */
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
        if (status == BIST_FAIL)
            break;
        if (status != BIST_PASS) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            return -1;
        }
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
    /* Phase 5: the edge as step count, clk_cdly and field 2. */
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

/*
 * Write window training of one data byte of one memory interface (training step W_EYE): find the passing
 * window of the common write delay and set the delay to its middle.
 *
 *   unit            memory interface number
 *   phy_version     with ddr_generation, checked by sys_ddr_check_arguments and passed on to the self-test
 *   ddr_generation  3 or 4; only with 3 is the step recorded as W_EYE (otherwise the step recorded before stays)
 *   byte            data byte; with -1 the tables' own addresses are passed in place of an entry
 *   delay_step      whole steps above field 5 that both edge searches start from
 *   bit_mode        passed on to the self-test (sys_ddr_run_bist_read)
 *
 * Returns the two edges {low, high}, each as whole steps << 8 | clk_cdly << 3 | field 2, or {-1, -1} when either
 * search fails. Called by the memory script (sys_ddr_run_script, command WRITE_EYE, which passes its arguments
 * 4 and 5 as bit_mode and delay_step) and, once per reference voltage step, by sys_ddr_measure_write_eye, which
 * puts the delay fields back afterwards.
 *
 * Phases:
 *   1. Record the step (DDR3 only) and check the arguments. Read field 2 and clk_cdly (handed on to the searches,
 *      which do not use them) and keep fields 5, 4 and 3 in sys_ddr_write_delay_field5/4/3_value; field 5's is
 *      the base the searches start from.
 *   2. Upper edge (find_upper_edge, upwards from the start), then lower edge (sys_ddr_find_write_window_lower_edge, downwards
 *      from the same start).
 *   3. Convert both edges to delay units with dly_per_cnt ((edge >> 8) * dly_per_cnt + (edge & 0xFF)) and set the
 *      delay to their middle (sys_ddr_set_write_delay_center).
 */
struct write_window sys_ddr_train_write_eye(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, unsigned int delay_step, unsigned int bit_mode)
{
    struct write_window window;
    unsigned int field2_value, clk_cdly_value, delay_per_count, value;
    unsigned int low_edge, high_edge;

    /* Phase 1: step, arguments and the starting values. */
    if (ddr_generation == DDR3)
        sys_ddr_set_step(DDR_STEP_W_EYE, unit, byte);
    sys_ddr_check_arguments(unit, phy_version, ddr_generation);
    if (byte == -1)
        field2_value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts);
    else
        field2_value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte]);
    if (byte == -1)
        clk_cdly_value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft);
    else
        clk_cdly_value = sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte]);
    sys_ddr_write_delay_field5_value = (byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts) : sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte]));
    sys_ddr_write_delay_field4_value = (byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts) : sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte]));
    sys_ddr_write_delay_field3_value = (byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts) : sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte]));
    /* Phase 2: both edges from the same start step. */
    high_edge = find_upper_edge(unit, phy_version, ddr_generation, byte, delay_step, field2_value, clk_cdly_value, bit_mode);
    low_edge = sys_ddr_find_write_window_lower_edge(unit, phy_version, ddr_generation, byte, delay_step, field2_value, clk_cdly_value, bit_mode);
    if (high_edge == -1 || low_edge == -1) {
        window.low = -1;
        window.high = -1;
        return window;
    }
    /* Phase 3: to delay units, and the delay to the middle. */
    if (byte == -1)
        delay_per_count = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026308_dly_per_cnt_reg, (unsigned int)DAT_a80262f8_dly_per_cnt_mask, (unsigned int)DAT_a802b638_dly_per_cnt_shift);
    else
        delay_per_count = sys_ddr_phy_read_field(unit, DAT_a8026308_dly_per_cnt_reg[byte], DAT_a80262f8_dly_per_cnt_mask[byte], DAT_a802b638_dly_per_cnt_shift[byte]);
    sys_ddr_set_write_delay_center(unit, byte, (low_edge >> 8) * delay_per_count + (low_edge & 0xff), (high_edge >> 8) * delay_per_count + (high_edge & 0xff), delay_per_count);
    window.low = low_edge;
    window.high = high_edge;
    return window;
}
