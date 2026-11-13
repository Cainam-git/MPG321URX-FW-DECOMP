/* sys_ddr_train_read_deskew  (FUN_a00e7eb0)
 *
 * Train the read deskew of one data byte: align its eight data lines.
 * Name basis: derived - 8 x 8 read check against the pattern 0x55, two field sets stepped
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e7eb0 @ 0xa00e7eb0-0xa00e8e6c (4028 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - check_first_read (fw 0xa00e7f90..0xa00e7fe8, error block 0xa00e81c4) is its own static helper with
 *    'return -1' / 'return 0', called first in find_byte_edge;
 *  - the per-beat test beat_mismatch is a static helper inlined in every 8 x 8 check ('mask = ... & (1 << line);
 *    if (read >> line != bit) return 1; return 0;'). With it the result-mask address leaves the beat loops
 *    together with the 'mov 1' of 1 << line and is formed before it (fw 0xa00e80b4, 0xa00e8284, 0xa00e83b0,
 *    0xa00e8540, 0xa00e89d0, 0xa00e8ae0), while the result-register address ('or 0x28') and the constants 7 and
 *    0x55 stay inside the beat loops (fw 0xa00e80c8..0xa00e80e8);
 *  - every field access is its own if (byte == -1)/else statement (the GET_/SET_/READ_ macros), and the loops
 *    of find_byte_edge read both delay fields once and drop the values before the real read.
 */
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_phy_set_bits(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_reset_fifos(unsigned int);
extern void sys_ddr_send_mode_register(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_read_reg1b_word(unsigned int);
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_set_read_dq_bit(unsigned int dev, int byte_idx, int dq_idx, int set);
extern unsigned int sys_ddr_read_deskew_field3_regs[], sys_ddr_read_deskew_field3_masks[], sys_ddr_read_deskew_field3_shifts[];
extern unsigned int sys_ddr_read_deskew_field2_regs[], sys_ddr_read_deskew_field2_masks[], sys_ddr_read_deskew_field2_shifts[];
extern unsigned int sys_ddr_read_deskew_field1_regs[], sys_ddr_read_deskew_field1_masks[], sys_ddr_read_deskew_field1_shifts[];
extern unsigned int sys_ddr_rd_deskew_result_regs[], sys_ddr_rd_deskew_result_masks[];
extern unsigned int sys_ddr_rd_deskew_dq_regs[], sys_ddr_rd_deskew_dq_masks[];

/*
 * The read delay of a whole data byte is two fields: a coarse delay (field2, "cdly" in the messages) and a fine
 * delay of 0..7 (field1, "fdly") that carries into the coarse one. Each of the byte's eight data lines has a
 * further delay word of its own: coarse steps in bits 3 and up (at most 0xF), fine steps in bits 0..2.
 *
 * The field macros take the register, mask and bit position of a field from entry `byte` of its three tables.
 * byte == -1 passes the addresses of the tables themselves in place of an entry.
 */
#define GET_FIELD(x, r, m, s)                                                               \
    do {                                                                                    \
        if (byte == -1)                                                                     \
            x = sys_ddr_phy_read_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s);       \
        else                                                                                \
            x = sys_ddr_phy_read_field(phy, r[byte], m[byte], s[byte]);                               \
    } while (0)
#define READ_FIELD(r, m, s)                                                                 \
    do {                                                                                    \
        if (byte == -1)                                                                     \
            sys_ddr_phy_read_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s);           \
        else                                                                                \
            sys_ddr_phy_read_field(phy, r[byte], m[byte], s[byte]);                                   \
    } while (0)
#define GET_COARSE(x) GET_FIELD(x, sys_ddr_read_deskew_field2_regs, sys_ddr_read_deskew_field2_masks, sys_ddr_read_deskew_field2_shifts)
#define GET_FINE(x) GET_FIELD(x, sys_ddr_read_deskew_field1_regs, sys_ddr_read_deskew_field1_masks, sys_ddr_read_deskew_field1_shifts)
#define READ_COARSE() READ_FIELD(sys_ddr_read_deskew_field2_regs, sys_ddr_read_deskew_field2_masks, sys_ddr_read_deskew_field2_shifts)
#define READ_FINE() READ_FIELD(sys_ddr_read_deskew_field1_regs, sys_ddr_read_deskew_field1_masks, sys_ddr_read_deskew_field1_shifts)
#define SET_FIELD(r, m, s, v)                                                               \
    do {                                                                                    \
        if (byte == -1)                                                                     \
            sys_ddr_phy_write_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s, v);        \
        else                                                                                \
            sys_ddr_phy_write_field(phy, r[byte], m[byte], s[byte], v);                                \
    } while (0)
#define SET_COARSE(v) SET_FIELD(sys_ddr_read_deskew_field2_regs, sys_ddr_read_deskew_field2_masks, sys_ddr_read_deskew_field2_shifts, v)
#define SET_FINE(v) SET_FIELD(sys_ddr_read_deskew_field1_regs, sys_ddr_read_deskew_field1_masks, sys_ddr_read_deskew_field1_shifts, v)

/* The data expected on every line: beat i carries bit 7 - i of 0x55, so the beats read 0, 1, 0, 1, ... */
#define PATTERN_BIT(beat) ((0x55 >> (7 - (beat))) & 1)

#define DDR3 3                          /* DDR generations accepted by sys_ddr_check_arguments */
#define DDR4 4
#define TRAINING_STEP_READ_DESKEW 7     /* step number shown in the error messages */
#define FINE_MAX 7                      /* highest value of the byte's fine delay */
#define LINE_COARSE_MAX 0xf             /* highest coarse value of a line's delay word */

/* 1 when beat `beat` of data line `line` did not read as the pattern. */
static int beat_mismatch(unsigned int phy, int byte, int line, int beat)
{
    unsigned int mask;

    mask = sys_ddr_rd_deskew_result_masks[byte] & (1 << line);
    if ((sys_ddr_phy_read_masked(phy, sys_ddr_rd_deskew_result_regs[byte] + beat, mask) >> line) != PATTERN_BIT(beat))
        return 1;
    return 0;
}

/* 1 when any of the eight beats of data line `line` is wrong. */
static int line_fails(unsigned int phy, int byte, int line)
{
    int beat;

    for (beat = 0; beat < 8; beat++)
        if (beat_mismatch(phy, byte, line, beat))
            return 1;
    return 0;
}

/* 1 when at least one of the byte's eight data lines reads the pattern correctly. */
static int any_line_passes(unsigned int phy, int byte)
{
    int line;

    for (line = 0; line < 8; line++)
        if (!line_fails(phy, byte, line))
            return 1;
    return 0;
}

/* 1 when at least one of the byte's eight data lines reads the pattern wrongly. */
static int any_line_fails(unsigned int phy, int byte)
{
    int line;

    for (line = 0; line < 8; line++)
        if (line_fails(phy, byte, line))
            return 1;
    return 0;
}

/* The read before any delay is changed must show the pattern on all eight lines at once: each beat reads 0xFF
   or 0. Returns 0, or -1 after printing an error. */
static int check_first_read(unsigned int phy, int byte)
{
    unsigned int value, expected;
    int beat;

    for (beat = 0; beat < 8; beat++) {
        value = sys_ddr_phy_read_masked(phy, sys_ddr_rd_deskew_result_regs[byte] + beat, sys_ddr_rd_deskew_result_masks[byte]);
        if (PATTERN_BIT(beat))
            expected = 0xff;
        else
            expected = 0;
        if (value != expected) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: First read fail.\n");
            return -1;
        }
    }
    return 0;
}

/*
 * Lower the byte's read delay until a line fails, then raise it in fine steps until all lines pass again and
 * go back one step, so the byte ends on the highest delay at which a line still fails.
 * When all lines still pass with both delays at 0, the delays stay at 0.
 * Each setting is tested after a FIFO reset and command 5 (value 0x1000); the final step back is not tested.
 * Returns 0, or -1 after printing an error.
 */
static int find_byte_edge(unsigned int phy, int byte)
{
    unsigned int coarse, fine;
    int pass;

    if (check_first_read(phy, byte) != 0)
        return -1;
    pass = 1;
    /* Coarse steps down first. */
    for (;;) {
        READ_COARSE();
        READ_FINE();
        GET_COARSE(coarse);
        if (coarse == 0)
            break;
        coarse--;
        SET_COARSE(coarse);
        sys_ddr_reset_fifos(phy);
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
        if (any_line_fails(phy, byte)) {
            pass = 0;
            break;
        }
    }
    /* Then fine steps down. */
    if (pass) {
        for (;;) {
            READ_COARSE();
            READ_FINE();
            GET_FINE(fine);
            if (fine == 0)
                break;
            fine--;
            SET_FINE(fine);
            sys_ddr_reset_fifos(phy);
            sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
            if (any_line_fails(phy, byte)) {
                pass = 0;
                break;
            }
        }
    }
    if (pass) {
        GET_COARSE(coarse);
        GET_FINE(fine);
        if (coarse != 0 || fine != 0) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: Still pass but cdly=%d fdly=%d, should be both 0.\n", coarse, fine);
            return -1;
        }
        return 0;
    }
    /* A line failed: one fine step up at a time (carrying into the coarse delay) until all lines pass. */
    while (!pass) {
        READ_COARSE();
        READ_FINE();
        GET_FINE(fine);
        if (fine == FINE_MAX) {
            GET_COARSE(coarse);
            coarse++;
            SET_COARSE(coarse);
            SET_FINE(0);
        } else {
            fine++;
            SET_FINE(fine);
        }
        sys_ddr_reset_fifos(phy);
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
        pass = !any_line_fails(phy, byte);
    }
    /* And one fine step back down (borrowing from the coarse delay). */
    GET_FINE(fine);
    if (fine == 0) {
        GET_COARSE(coarse);
        coarse--;
        SET_COARSE(coarse);
        SET_FINE(FINE_MAX);
    } else {
        fine--;
        SET_FINE(fine);
    }
    sys_ddr_reset_fifos(phy);
    return 0;
}

/*
 * Coarse pass over the lines: raise the coarse part of the delay word of every line that passes by one, again
 * and again, until no line passes; then lower the coarse part of every line that is above 0 by one.
 * After each change the line's control bit is pulsed (written 0, 1, 0).
 * Returns 0, -1 when a line's coarse part is already at its maximum (after printing an error), or the error of
 * sys_ddr_set_read_dq_bit.
 */
static int step_lines_coarse(unsigned int phy, int byte)
{
    unsigned int word, coarse, fine;
    int line, error;

    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    do {
        for (line = 0; line < 8; line++) {
            if (line_fails(phy, byte, line))
                continue;
            word = sys_ddr_phy_read_masked(phy, sys_ddr_rd_deskew_dq_regs[byte] + line, sys_ddr_rd_deskew_dq_masks[byte]);
            coarse = word >> 3;
            fine = word & 7;
            if (coarse == LINE_COARSE_MAX) {
                sys_ddr_print_step();
                sys_ddr_print_error_prefix();
                dbg_printf("Error: 1\n");
                return -1;
            }
            coarse++;
            sys_ddr_phy_update_bits(phy, sys_ddr_rd_deskew_dq_regs[byte] + line, sys_ddr_rd_deskew_dq_masks[byte], coarse * 8 + fine);
            if ((error = sys_ddr_set_read_dq_bit(phy, byte, line, 0)) != 0)
                return error;
            if ((error = sys_ddr_set_read_dq_bit(phy, byte, line, 1)) != 0)
                return error;
            if ((error = sys_ddr_set_read_dq_bit(phy, byte, line, 0)) != 0)
                return error;
        }
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    } while (any_line_passes(phy, byte));
    for (line = 0; line < 8; line++) {
        word = sys_ddr_phy_read_masked(phy, sys_ddr_rd_deskew_dq_regs[byte] + line, sys_ddr_rd_deskew_dq_masks[byte]);
        coarse = word >> 3;
        fine = word & 7;
        if (coarse != 0) {
            coarse--;
            sys_ddr_phy_update_bits(phy, sys_ddr_rd_deskew_dq_regs[byte] + line, sys_ddr_rd_deskew_dq_masks[byte], coarse * 8 + fine);
            if ((error = sys_ddr_set_read_dq_bit(phy, byte, line, 0)) != 0)
                return error;
            if ((error = sys_ddr_set_read_dq_bit(phy, byte, line, 1)) != 0)
                return error;
            if ((error = sys_ddr_set_read_dq_bit(phy, byte, line, 0)) != 0)
                return error;
        }
    }
    return 0;
}

/*
 * Fine pass over the lines: raise the delay word of every line that passes by one, again and again; a line that
 * fails once is left alone from then on. Ends when all eight lines have failed, or at once (without a result)
 * when pulsing a control bit fails.
 */
static void step_lines_fine(unsigned int phy, int byte)
{
    unsigned int word, done;
    int line;

    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    done = 0;
    do {
        for (line = 0; line < 8; line++) {
            if (!(done & (1 << line)) && !line_fails(phy, byte, line)) {
                word = sys_ddr_phy_read_masked(phy, sys_ddr_rd_deskew_dq_regs[byte] + line, sys_ddr_rd_deskew_dq_masks[byte]);
                sys_ddr_phy_update_bits(phy, sys_ddr_rd_deskew_dq_regs[byte] + line, sys_ddr_rd_deskew_dq_masks[byte], word + 1);
                if (sys_ddr_set_read_dq_bit(phy, byte, line, 0) != 0 || sys_ddr_set_read_dq_bit(phy, byte, line, 1) != 0 ||
                    sys_ddr_set_read_dq_bit(phy, byte, line, 0) != 0)
                    return;
            } else
                done |= 1 << line;
        }
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    } while (done != 0xff);
}

/*
 * Read deskew training of one data byte: line up the read timing of its eight data lines against the pattern
 * 0x55 (beats 0, 1, 0, 1, ...).
 *
 *   phy          memory interface
 *   phy_version  version of the interface, checked together with phy and generation
 *   generation   DDR3 or DDR4
 *   byte         data byte 0..3
 *
 * Returns 0, or a negative error after printing it. One of the memory training steps that sys_ddr_run_script
 * runs; the result of the argument check is not used.
 *
 * Order: find_byte_edge, then step_lines_coarse, then step_lines_fine; each runs only when the one before
 * returned 0. Before them: bits are set in interface registers 0x1B4 (0xF0), 0x15D (0xF0) and 0x165 (0x0F), the
 * byte's field3 is saved, and commands 2 (0x400), 6 (with bit 2 set in the value of registers 0x1B/0x1C; for
 * DDR3 the value is also masked with 0xF00FC), for DDR4 command 0xB with the pattern value 0x55, and command 5
 * (0x1000) are sent. Afterwards command 6 is sent with bit 2 cleared, field3 is restored and the FIFOs are reset.
 *
 * A byte above 3 (which includes -1) ends a run that returned 0 with "never here" and -1.
 */
int sys_ddr_train_read_deskew(unsigned int phy, unsigned int phy_version, int generation, int byte)
{
    unsigned int saved, word;
    int result;

    sys_ddr_set_step(TRAINING_STEP_READ_DESKEW, phy, byte);
    sys_ddr_check_arguments(phy, phy_version, generation);
    sys_ddr_phy_set_bits(phy, 0x1b4, 0xf0);
    sys_ddr_phy_set_bits(phy, 0x15d, 0xf0);
    sys_ddr_phy_set_bits(phy, 0x165, 0xf);
    if (byte == -1)
        saved = sys_ddr_phy_read_field(phy, (unsigned int)sys_ddr_read_deskew_field3_regs, (unsigned int)sys_ddr_read_deskew_field3_masks, (unsigned int)sys_ddr_read_deskew_field3_shifts);
    else
        saved = sys_ddr_phy_read_field(phy, sys_ddr_read_deskew_field3_regs[byte], sys_ddr_read_deskew_field3_masks[byte], sys_ddr_read_deskew_field3_shifts[byte]);
    sys_ddr_reset_fifos(phy);
    sys_ddr_send_mode_register(phy, 2, 0, 0x400);
    if (generation == DDR4) {
        word = sys_ddr_read_reg1b_word(phy);
        sys_ddr_send_mode_register(phy, 6, 3, word | 4);
    } else if (generation == DDR3) {
        word = sys_ddr_read_reg1b_word(phy);
        sys_ddr_send_mode_register(phy, 6, 3, (word | 4) & 0xf00fc);
    }
    if (generation == DDR4)
        sys_ddr_send_mode_register(phy, 0xb, 0, 0x55);
    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    result = find_byte_edge(phy, byte);
    if (result == 0) {
        result = step_lines_coarse(phy, byte);
        if (result == 0)
            step_lines_fine(phy, byte);
    }
    word = sys_ddr_read_reg1b_word(phy);
    sys_ddr_send_mode_register(phy, 6, 3, word & 0xffffb);
    if (byte == -1)
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_read_deskew_field3_regs, (unsigned int)sys_ddr_read_deskew_field3_masks, (unsigned int)sys_ddr_read_deskew_field3_shifts, saved);
    else
        sys_ddr_phy_write_field(phy, sys_ddr_read_deskew_field3_regs[byte], sys_ddr_read_deskew_field3_masks[byte], sys_ddr_read_deskew_field3_shifts[byte], saved);
    sys_ddr_reset_fifos(phy);
    if (result != 0)
        return result;
    if ((unsigned int)byte > 3) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: never here. byte_idx = %d\n", byte);
        return -1;
    }
    return 0;
}
