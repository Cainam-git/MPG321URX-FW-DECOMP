/* sys_ddr_train_write_deskew  (FUN_a00ea878)
 *
 * Train the write deskew of one data byte: align its eight data lines.
 * Note: "DQ clk cdly is full" is printed as an error but the routine then returns 0; parameter 5 is not used.
 * Name basis: proven - prints 'WRITE_DESKEW_BYTE should not be here: byte_idx=%d'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ea878 @ 0xa00ea878-0xa00eb708 (3728 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - one 'if (byte == -1) { ... } else { ... }' block per field update (a read and its write-back together) and per
 *    run of same-kind accesses (the three saves, the four clears, the write-backs and clears at the end); reads
 *    inside loop and if conditions are written 'byte == -1 ? R : R';
 *  - step 2 leaves its loop after the step back with 'status = 0; goto step3;' past the messages after the loop
 *    (fw 0xa00eb560 'b 0xa00eac7c; clr %o0' into the step-3 test at 0xa00eac7c);
 *  - in the step-3 loop the self-test result is handled as 'if (status == BIST_PASS) { <carry test> } else
 *    { <result or timeout>; break; }': the result block (fw 0xa00eb588..0xa00eb634, timeout 0xa00eb6bc) lies after
 *    the out-of-line blocks of steps 1 and 2, and the byte == -1 carry arm follows its '== 7' test (fw
 *    0xa00eb368..0xa00eb3f4);
 *  - the table spellings sys_ddr_write_delay_field1_regs and DAT_a802b618_dq_fail_sft are the ones their other users have.
 */
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_set_bits(unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_run_bist_write(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *, ...);
extern int sys_ddr_write_deskew_coarse(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern int sys_ddr_write_deskew_fine(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern unsigned int sys_ddr_write_delay_field5_regs[], sys_ddr_write_delay_field5_masks[], sys_ddr_write_delay_field5_shifts[];
extern unsigned int sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[];
extern unsigned int sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[];
extern unsigned int sys_ddr_write_delay_field2_regs[], sys_ddr_write_delay_field2_masks[], sys_ddr_write_delay_field2_shifts[];
/* clk_cdly: the field the message "DQ clk cdly is full" names (register, mask, shift per data byte). */
extern unsigned int DAT_a8026798_clk_cdly_reg[], DAT_a8026788_clk_cdly_msk[], DAT_a8026778_clk_cdly_sft[];
/* Field 1: register table sys_ddr_write_delay_field1_regs with the field1 masks and shifts. */
extern unsigned int sys_ddr_write_delay_field1_regs[], sys_ddr_write_delay_field1_masks[], sys_ddr_write_delay_field1_shifts[];
/* wr_eye_lcdly: the field the message "wr_eye_lcdly_state_error_flag" of the write window training names. */
extern unsigned int DAT_a8026748_eye_lcdly_reg[], DAT_a8026738_eye_lcdly_msk[], DAT_a8026728_eye_lcdly_sft[];
/* dq_fail: one bit per data line, set when the last self-test failed on that line. */
extern unsigned int DAT_a8026268_dq_fail_reg[], DAT_a8026258_dq_fail_msk[], DAT_a802b618_dq_fail_sft[];

#define DDR_STEP_W_DESKEW 10        /* training step number, printed as W_DESKEW by sys_ddr_print_step */

/* Results of the write self-test (sys_ddr_run_bist_write); any other value is reported as a timeout. */
#define BIST_PASS 0
#define BIST_FAIL 1

#define CLK_CDLY_FULL 0xf           /* highest clk_cdly value ("4'b1111" in the message) */
#define FINE_MAX      7             /* highest value of the three-bit field 2 before the carry into clk_cdly */
#define DQ_ALL_FAIL   0xff          /* dq_fail with all eight line bits set */

/* Registers of the memory interface set before the search; their purpose is not shown here. */
#define REG_1B4 0x1b4
#define REG_165 0x165

/*
 * Write deskew of one data byte of one memory interface (training step W_DESKEW).
 *
 *   unit            memory interface number
 *   phy_version     with ddr_generation, checked by sys_ddr_check_arguments and passed on to the write self-test
 *   ddr_generation
 *   byte            data byte 0..3; with -1 the tables' own addresses are passed in place of an entry
 *   unused          not used (the memory script passes 4)
 *   bit_mode        passed on to the write self-test (sys_ddr_run_bist_write)
 *
 * Returns a negative value when a step fails (after printing the step and an error message), otherwise 0.
 * Called by the memory script (sys_ddr_run_script, command WRITE_DESKEW) for each interface of the command.
 *
 * The common write delay of a data byte is held in several fields; this routine uses seven. Field 4 and field 3 count whole steps on top of
 * field 5 (sys_ddr_set_write_delay_center writes field 5 + steps to field 4 and that minus 4 to field 3);
 * clk_cdly with wr_eye_lcdly and field 2 with field 1 hold the rest of the delay, split into the bits above the
 * low three (clk_cdly, wr_eye_lcdly) and the low three bits (field 2, field 1). This routine raises those
 * common delays until the self-test fails, and then lets sys_ddr_write_deskew_coarse and
 * sys_ddr_write_deskew_fine set the delay of each of the eight data lines on their own. The common fields are
 * put back afterwards (field 5, 4 and 3 to their saved values, the other four to 0); only the per-line delays
 * stay.
 *
 * Phases:
 *   0. Record the step, set up registers 0x1B4 and 0x165, save fields 5, 4 and 3, clear the four other fields.
 *      The write self-test must pass at this point, else "Bist fail or timeout" and -1.
 *   1. Raise fields 4 and 3 together by one per self-test until the test fails, then take them one step back.
 *   2. Raise clk_cdly and wr_eye_lcdly together by one per self-test. When the test fails, take them one step back
 *      and go on with phase 3. When clk_cdly reaches 0xF with every test passing, print "DQ clk cdly is full" and
 *      skip phases 3 and 4 (the routine then returns 0).
 *   3. Raise field 2 and field 1 together by one per self-test while it passes; each time field 2 reads 7 after a
 *      pass, clk_cdly and wr_eye_lcdly are raised by one too. On the first failure dq_fail is read: with all
 *      eight lines failing, phase 4 is skipped; otherwise it runs.
 *   4. sys_ddr_write_deskew_coarse; when it returns 0, one more write self-test (result not used) and
 *      sys_ddr_write_deskew_fine.
 *   5. Put the common fields back. Return a negative result; otherwise print "WRITE_DESKEW_BYTE should not be
 *      here" when byte is not 0..3 (after all the work above) and return 0.
 * Phases 1 to 3 have no step limit of their own; they end on a failing test or, in phase 2, at clk_cdly 0xF.
 * A self-test result other than pass or fail prints "Bist timeout" and gives -1.
 */
int sys_ddr_train_write_deskew(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, unsigned int unused, unsigned int bit_mode)
{
    unsigned int saved_field5, saved_field4, saved_field3, value;
    int result, status;

    /* Phase 0: set-up. */
    sys_ddr_set_step(DDR_STEP_W_DESKEW, unit, byte);
    sys_ddr_check_arguments(unit, phy_version, ddr_generation);
    sys_ddr_phy_set_bits(unit, REG_1B4, 0xf);
    sys_ddr_phy_set_bits(unit, REG_165, 0xf0);
    sys_ddr_phy_set_bits(unit, REG_165, 0xf);
    /* Keep the whole-count fields for the end. */
    if (byte == -1) {
        saved_field5 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts);
        saved_field4 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts);
        saved_field3 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts);
    } else {
        saved_field5 = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte]);
        saved_field4 = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte]);
        saved_field3 = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte]);
    }
    /* Start the rest of the delay from 0. */
    if (byte == -1) {
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts, 0);
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, 0);
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts, 0);
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, 0);
    } else {
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte], 0);
        sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], 0);
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte], 0);
        sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], 0);
    }
    /* The search needs a passing starting point. */
    status = sys_ddr_run_bist_write(unit, phy_version, ddr_generation, bit_mode);
    if (status != BIST_PASS) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: Bist fail or timeout.\n");
        status = -1;
    } else {
        /* Phase 1: fields 4 and 3 up by one per test until the test fails. */
        for (;;) {
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
            status = sys_ddr_run_bist_write(unit, phy_version, ddr_generation, bit_mode);
            if (status == BIST_FAIL)
                break;
            if (status == BIST_PASS)
                continue;
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            status = -1;
            break;
        }
        if (status == BIST_FAIL) {
            /* Back to the last passing count. */
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
            status = 0;
        }
    }
    result = status;
    if (result == 0) {
        /* Phase 2: clk_cdly and wr_eye_lcdly up by one per test until the test fails or clk_cdly is full. */
        do {
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
            status = sys_ddr_run_bist_write(unit, phy_version, ddr_generation, bit_mode);
            if (status == BIST_FAIL) {
                /* Back one step and continue with the low bits. */
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
                status = 0;
                goto step3;
            }
            if (status != BIST_PASS)
                break;
        } while ((byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft) : sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte])) != CLK_CDLY_FULL);
        if (status == BIST_PASS) {
            /* Still passing at the top of clk_cdly: reported, but not as a failure (status 1 skips phases 3
               and 4, and the routine returns 0). */
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("DQ clk cdly is full (4'b1111) at step 4.1\n");
            status = 1;
        } else {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            status = -1;
        }
    }
step3:
    result = status;
    if (result == 0) {
        /* Phase 3: field 2 and field 1 up by one per test while it passes, carrying into clk_cdly and
           wr_eye_lcdly when field 2 reads 7. */
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
            status = sys_ddr_run_bist_write(unit, phy_version, ddr_generation, bit_mode);
            if (status == BIST_PASS) {
                if ((byte == -1 ? sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts) : sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte])) == FINE_MAX) {
                    /* Carry into the higher bits. */
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
            } else {
                if (status == BIST_FAIL) {
                    /* Status 1 when every line fails (phase 4 skipped), 0 when some still pass. */
                    if (byte == -1)
                        value = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026268_dq_fail_reg, (unsigned int)DAT_a8026258_dq_fail_msk, (unsigned int)DAT_a802b618_dq_fail_sft);
                    else
                        value = sys_ddr_phy_read_field(unit, DAT_a8026268_dq_fail_reg[byte], DAT_a8026258_dq_fail_msk[byte], DAT_a802b618_dq_fail_sft[byte]);
                    status = 1;
                    if (value != DQ_ALL_FAIL)
                        status = 0;
                } else {
                    sys_ddr_print_step();
                    sys_ddr_print_error_prefix();
                    dbg_printf("Error: Bist timeout.\n");
                    status = -1;
                }
                break;
            }
        }
        result = status;
        if (result == 0) {
            /* Phase 4: the delays of the single lines. */
            result = sys_ddr_write_deskew_coarse(unit, phy_version, ddr_generation, byte, bit_mode);
            if (result == 0) {
                sys_ddr_run_bist_write(unit, phy_version, ddr_generation, bit_mode);
                result = sys_ddr_write_deskew_fine(unit, phy_version, ddr_generation, byte, bit_mode);
            }
        }
    }
    /* Phase 5: put the common fields back. */
    if (byte == -1) {
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts, saved_field5);
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts, saved_field4);
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts, saved_field3);
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts, 0);
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, 0);
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts, 0);
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, 0);
    } else {
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte], saved_field5);
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte], saved_field4);
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte], saved_field3);
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte], 0);
        sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], 0);
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte], 0);
        sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], 0);
    }
    if (result < 0)
        return result;
    if ((unsigned int)byte > 3) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("WRITE_DESKEW_BYTE should not be here: byte_idx=%d\n", byte);
    }
    return 0;
}
