/* sys_ddr_find_read_eye  (FUN_a00e8e6c)
 *
 * Find both edges of the passing read delay window with self-test steps and set the middle.
 * Returns: left and right edge
 * Name basis: proven - prints 'Error: rd_eye_initial_state_error_flag'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e8e6c @ 0xa00e8e6c-0xa00e9b34 (3272 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - field accesses are GET_FIELD / SET_FIELD statement macros (if (byte == -1) / else); the limits
 *    COARSE_LIMIT / FINE_LIMIT always index the tables with byte;
 *  - the downward fine search is part of the left coarse loop ('if (coarse == 0) { .. break; }'): loop.c then
 *    lifts its fine-table addresses into the coarse loop's preheader with those of the upward search, which keeps
 *    &fine.reg[byte] / &fine.mask[byte] in %l5 / %l6 there (fw 0xa00e9320, 0xa00e9340, copy 'mov %l5,%l3' at
 *    0xa00e97f0) and the shared '-1' exit in %g1 (0xa00e8f04);
 *  - that loop goes on with 'if (bist == BIST_PASS) continue;' (the continue statement's branch prediction puts
 *    its timeout block last, fw 0xa00e9af8, and makes the left coarse value rank before the fine value: coarse
 *    %l0, fine %l2);
 *  - in the upward search the increment arm comes first: its byte == -1 write reuses the limit's address
 *    registers %o4/%o5 of 0xa00e9858..0xa00e9864 (fw 0xa00e9990..0xa00e99a4).
 */
/* The two edges, each as coarse << 3 | fine; both -1 on an error. Same layout as in sys_ddr_measure_read_eye_at. */
struct read_eye_result {
    int first;                          /* right edge (the upper end of the window) */
    int second;                         /* left edge (the lower end) */
};
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_reset_fifos(unsigned int);
extern int sys_ddr_run_bist_read(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *, ...);
extern unsigned int sys_ddr_read_deskew_field3_regs[], sys_ddr_read_deskew_field3_masks[], sys_ddr_read_deskew_field3_shifts[];
extern unsigned int sys_ddr_read_deskew_field2_regs[], sys_ddr_read_deskew_field2_masks[], sys_ddr_read_deskew_field2_shifts[];
extern unsigned int sys_ddr_read_deskew_field1_regs[], sys_ddr_read_deskew_field1_masks[], sys_ddr_read_deskew_field1_shifts[];

/*
 * The read delay of the byte is two fields: a coarse delay (read_deskew field2, "cdly" in the messages) and a
 * fine delay (field1, "fdly") that carries into the coarse one. Field3 is the value the messages call
 * rdqs90_dly / RDQS90.
 *
 * A field of a data byte is entry `byte` of three tables: register, mask and bit position. With byte == -1 the
 * addresses of the tables themselves are passed in place of an entry. The highest value of a field is its mask
 * shifted down by its bit position.
 */
#define GET_FIELD(x, r, m, s)                                                               \
    do {                                                                                    \
        if (byte == -1)                                                                     \
            x = sys_ddr_phy_read_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s);       \
        else                                                                                \
            x = sys_ddr_phy_read_field(phy, r[byte], m[byte], s[byte]);                               \
    } while (0)
#define SET_FIELD(r, m, s, v)                                                               \
    do {                                                                                    \
        if (byte == -1)                                                                     \
            sys_ddr_phy_write_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s, v);        \
        else                                                                                \
            sys_ddr_phy_write_field(phy, r[byte], m[byte], s[byte], v);                                \
    } while (0)
#define GET_RDQS90(x) GET_FIELD(x, sys_ddr_read_deskew_field3_regs, sys_ddr_read_deskew_field3_masks, sys_ddr_read_deskew_field3_shifts)
#define SET_RDQS90(v) SET_FIELD(sys_ddr_read_deskew_field3_regs, sys_ddr_read_deskew_field3_masks, sys_ddr_read_deskew_field3_shifts, v)
#define GET_COARSE(x) GET_FIELD(x, sys_ddr_read_deskew_field2_regs, sys_ddr_read_deskew_field2_masks, sys_ddr_read_deskew_field2_shifts)
#define SET_COARSE(v) SET_FIELD(sys_ddr_read_deskew_field2_regs, sys_ddr_read_deskew_field2_masks, sys_ddr_read_deskew_field2_shifts, v)
#define GET_FINE(x) GET_FIELD(x, sys_ddr_read_deskew_field1_regs, sys_ddr_read_deskew_field1_masks, sys_ddr_read_deskew_field1_shifts)
#define SET_FINE(v) SET_FIELD(sys_ddr_read_deskew_field1_regs, sys_ddr_read_deskew_field1_masks, sys_ddr_read_deskew_field1_shifts, v)
#define COARSE_LIMIT (sys_ddr_read_deskew_field2_masks[byte] >> sys_ddr_read_deskew_field2_shifts[byte])
#define FINE_LIMIT (sys_ddr_read_deskew_field1_masks[byte] >> sys_ddr_read_deskew_field1_shifts[byte])

#define DDR3 3                          /* DDR generations accepted by sys_ddr_check_arguments */
#define DDR_STEP_R_EYE 8                /* training step number, printed as "R_EYE" in the error messages */

/* Results of the self-test (sys_ddr_run_bist_read). */
#define BIST_PASS    0
#define BIST_FAIL    1
#define BIST_TIMEOUT 2                  /* "Error: Bist timeout." */

/*
 * Find the window of read delay settings of one data byte in which the self-test passes, and set the delay to
 * the middle of it.
 *
 *   phy, phy_version, generation  checked by sys_ddr_check_arguments (the result is not used) and passed on to
 *                                 the self-test
 *   byte                          data byte
 *   bit_mode                      passed on to the self-test (sys_ddr_run_bist_read)
 *
 * Returns {first, second} = the right and the left edge, each as coarse << 3 | fine, or {-1, -1} after an error.
 * Called by sys_ddr_run_script (script command 52) and by sys_ddr_measure_read_eye_at, which
 * sys_ddr_train_read_eye uses.
 *
 * Every test resets the FIFOs and runs the self-test. A timeout in a search prints "Error: Bist timeout." and
 * the flag name of that search (rd_rcdly, rd_rfdly, rd_lcdly, rd_lfdly) and returns {-1, -1}.
 *
 * Phases:
 *  1. DDR3: record step R_EYE for the error messages. Check the arguments, save rdqs90_dly, test. A start that
 *     does not pass is an error ("rd_eye_initial_state_error_flag", printed for DDR3 only).
 *  2. Right edge, coarse: raise the coarse delay by one per test until a test fails (then one step back) or
 *     the coarse delay is at its limit.
 *  3. Right edge, fine: raise the fine delay by one per test (at its limit: fine 0 and coarse + 1) until a
 *     test fails or both are at their limits ("rdqs90_dly right boundary is 0xFF"). That is the right edge.
 *  4. Write the saved rdqs90_dly back and test; anything but a pass is an error ("step 9 reset RDQS90",
 *     printed for DDR3 only).
 *  5. Left edge: lower the coarse delay by one per test while the tests pass. On a fail, raise the fine delay
 *     (at its limit: fine 0, coarse + 1) until a test passes; that setting is the left edge, and reaching both
 *     limits first is an error ("rd_fdly_state_error_flag =1 -> step 16"). When the coarse delay is 0 and the
 *     test still passes, lower the fine delay while the tests pass; the left edge is where that stops (the
 *     first failing setting, or fine 0).
 *  6. Middle = ((right coarse + left coarse) * 8 + right fine + left fine) / 2: bits 3 and up go to the coarse
 *     delay, the low 3 bits to the fine delay; reset the FIFOs.
 */
struct read_eye_result sys_ddr_find_read_eye(unsigned int phy, unsigned int phy_version, unsigned int generation, int byte, unsigned int bit_mode)
{
    struct read_eye_result edges;
    unsigned int right_coarse, right_fine, saved_rdqs90, coarse, fine, middle, middle_coarse, middle_fine;
    int bist;

    /* Phase 1: start. */
    if (generation == DDR3)
        sys_ddr_set_step(DDR_STEP_R_EYE, phy, byte);
    sys_ddr_check_arguments(phy, phy_version, generation);
    GET_RDQS90(saved_rdqs90);
    sys_ddr_reset_fifos(phy);
    if (sys_ddr_run_bist_read(phy, phy_version, generation, bit_mode) != BIST_PASS) {
        if (generation == DDR3) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: rd_eye_initial_state_error_flag\n");
        }
        edges.first = -1;
        edges.second = -1;
        return edges;
    }
    /* Phase 2: right edge, coarse steps up. */
    do {
        GET_COARSE(coarse);
        if (coarse != COARSE_LIMIT) {
            coarse++;
            SET_COARSE(coarse);
        }
        sys_ddr_reset_fifos(phy);
        bist = sys_ddr_run_bist_read(phy, phy_version, generation, bit_mode);
        if (bist == BIST_TIMEOUT) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("rd_rcdly_state_error_flag\n");
            edges.first = -1;
            edges.second = -1;
            return edges;
        }
        if (bist == BIST_FAIL) {
            GET_COARSE(coarse);
            coarse--;
            SET_COARSE(coarse);
            sys_ddr_reset_fifos(phy);
            break;
        }
    } while (coarse != COARSE_LIMIT);
    /* Phase 3: right edge, fine steps up (carrying into the coarse delay). */
    for (;;) {
        GET_FINE(fine);
        if (fine == FINE_LIMIT) {
            GET_COARSE(coarse);
            if (coarse == COARSE_LIMIT)
                break;
            coarse++;
            SET_COARSE(coarse);
            fine = 0;
        } else {
            fine++;
        }
        SET_FINE(fine);
        sys_ddr_reset_fifos(phy);
        bist = sys_ddr_run_bist_read(phy, phy_version, generation, bit_mode);
        if (bist == BIST_TIMEOUT) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: rd_rfdly_state_error_flag\n");
            edges.first = -1;
            edges.second = -1;
            return edges;
        }
        if (bist == BIST_FAIL)
            break;
    }
    if (coarse == COARSE_LIMIT && fine == FINE_LIMIT)
        dbg_printf("rdqs90_dly right boundary is 0xFF\n");
    right_coarse = coarse;
    right_fine = fine;
    /* Phase 4: rdqs90_dly back to its saved value; the test must pass there. */
    SET_RDQS90(saved_rdqs90);
    sys_ddr_reset_fifos(phy);
    bist = sys_ddr_run_bist_read(phy, phy_version, generation, bit_mode);
    if (bist != BIST_PASS) {
        if (generation == DDR3) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: step 9 reset RDQS90, but BIST(%d) != pass !!!\n", bist);
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("val_rdqs_90_dly_m = 0x%02x reg = 0x%02x\n", saved_rdqs90, (byte == -1 ? sys_ddr_phy_read_field(phy, (unsigned int)sys_ddr_read_deskew_field3_regs, (unsigned int)sys_ddr_read_deskew_field3_masks, (unsigned int)sys_ddr_read_deskew_field3_shifts) : sys_ddr_phy_read_field(phy, sys_ddr_read_deskew_field3_regs[byte], sys_ddr_read_deskew_field3_masks[byte], sys_ddr_read_deskew_field3_shifts[byte])));
        }
        edges.first = -1;
        edges.second = -1;
        return edges;
    }
    /* Phase 5: left edge, coarse steps down while the test passes. */
    for (;;) {
        GET_COARSE(coarse);
        if (coarse != 0) {
            coarse--;
            SET_COARSE(coarse);
        }
        sys_ddr_reset_fifos(phy);
        bist = sys_ddr_run_bist_read(phy, phy_version, generation, bit_mode);
        if (bist == BIST_TIMEOUT) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Bist timeout.\n");
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: rd_lcdly_state_error_flag\n");
            edges.first = -1;
            edges.second = -1;
            return edges;
        }
        if (bist == BIST_FAIL) {
            /* Past the edge: fine steps up (carrying into the coarse delay) until the test passes again. */
            for (;;) {
                GET_FINE(fine);
                if (fine != FINE_LIMIT) {
                    fine++;
                    SET_FINE(fine);
                } else {
                    fine = 0;
                    SET_FINE(fine);
                    GET_COARSE(coarse);
                    coarse++;
                    SET_COARSE(coarse);
                }
                sys_ddr_reset_fifos(phy);
                bist = sys_ddr_run_bist_read(phy, phy_version, generation, bit_mode);
                if (bist == BIST_TIMEOUT) {
                    sys_ddr_print_step();
                    sys_ddr_print_error_prefix();
                    dbg_printf("Error: Bist timeout.\n");
                    sys_ddr_print_step();
                    sys_ddr_print_error_prefix();
                    dbg_printf("Error: rd_lfdly_state_error_flag\n");
                    edges.first = -1;
                    edges.second = -1;
                    return edges;
                }
                if (bist == BIST_PASS)
                    goto end;
                if (fine == FINE_LIMIT) {
                    GET_COARSE(coarse);
                    if (coarse == COARSE_LIMIT)
                        break;
                }
            }
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("rd_fdly_state_error_flag =1 -> step 16\n");
            edges.first = -1;
            edges.second = -1;
            return edges;
        }
        if (coarse == 0) {
            /* Coarse delay at 0 and still passing: fine steps down while the test passes. */
            GET_FINE(fine);
            for (;;) {
                if (fine == 0)
                    break;
                fine--;
                SET_FINE(fine);
                sys_ddr_reset_fifos(phy);
                bist = sys_ddr_run_bist_read(phy, phy_version, generation, bit_mode);
                if (bist == BIST_TIMEOUT) {
                    sys_ddr_print_step();
                    sys_ddr_print_error_prefix();
                    dbg_printf("Error: Bist timeout.\n");
                    sys_ddr_print_step();
                    sys_ddr_print_error_prefix();
                    dbg_printf("Error: rd_lfdly_state_error_flag\n");
                    edges.first = -1;
                    edges.second = -1;
                    return edges;
                }
                if (bist == BIST_PASS)
                    continue;
                break;
            }
            break;
        }
    }
end:
    /* Phase 6: the middle of the two edges. */
    middle = ((right_coarse + coarse) * 8 + (right_fine + fine)) / 2;
    middle_coarse = middle >> 3;
    middle_fine = middle & 7;
    SET_COARSE(middle_coarse);
    SET_FINE(middle_fine);
    sys_ddr_reset_fifos(phy);
    edges.first = right_coarse << 3 | right_fine;
    edges.second = coarse << 3 | fine;
    return edges;
}
