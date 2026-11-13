/* sys_ddr_train_read_eye  (FUN_a00e9c80)
 *
 * Train the read window of a data byte in two passes and write the midpoints.
 * Name basis: proven - prints 'Error: Bist fail or timeout.' and 'Error: UI_percentage = %d < 20 or > 80.'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e9c80 @ 0xa00e9c80-0xa00ea1f0 (348 words), flags -mcpu=v8 -O3 -g.
 * Source form: each read and write is its own if (byte == -1)/else statement; the two -1 tests combine with '&';
 * the failing upward step and the stop above 0x4b end with continue; the result words are copied into right /
 * left first (operand order of the MIN/MAX selections); 'lower = upper;' comes before the -1 test.
 */
/* The window that sys_ddr_find_read_eye measures, each edge as coarse << 3 | fine; both -1 on an error. */
struct read_eye_result {
    int first;                          /* right edge (the upper end of the window) */
    int second;                         /* left edge (the lower end) */
};
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct read_eye_result sys_ddr_measure_read_eye_at(unsigned int, unsigned int, unsigned int, int, int, int, unsigned int);
extern unsigned int sys_ddr_read_eye_field3_regs[], sys_ddr_read_eye_field3_masks[], sys_ddr_read_eye_field3_shifts[];
extern unsigned int sys_ddr_read_deskew_field3_regs[], sys_ddr_read_deskew_field3_masks[], sys_ddr_read_deskew_field3_shifts[];
extern unsigned int sys_ddr_read_eye_field2_regs[], sys_ddr_read_eye_field2_masks[], sys_ddr_read_eye_field2_shifts[];
extern unsigned int sys_ddr_read_eye_field1_regs[], sys_ddr_read_eye_field1_masks[], sys_ddr_read_eye_field1_shifts[];

#define MIN(x, y) ((x) <= (y) ? (x) : (y))
#define MAX(x, y) ((x) >= (y) ? (x) : (y))

#define DDR_STEP_R_VREF 9               /* training step number, printed as "R_VREF" in the error messages */
#define UI_PERCENTAGE_MIN 20            /* limits of ui_percentage, from the firmware's error message */
#define UI_PERCENTAGE_MAX 80
#define FIRST_PASS_STEP 4               /* step of the first pass; the second pass steps by 1 */
#define UPPER_STOP 0x4b                 /* the upper end stops once it has gone above this value */
#define LOWER_STOP 4                    /* the lower end stops once it is at or below this value */

/*
 * Sweep the value of the read_eye fields of one data byte up and down from its present setting, measuring the
 * read window at each value, and keep the range of values over which the windows overlap by at least a minimum
 * width. Then set the read_eye fields to the middle of that range and rdqs90_dly to the middle of the overlap.
 *
 *   phy, phy_version, generation  checked by sys_ddr_check_arguments (the result is not used) and passed on
 *   byte                          data byte
 *   ui_percentage                 20..80, else an error; the minimum overlap is
 *                                 read_eye field3 * ui_percentage * 2 / 100
 *   bit_mode                      passed on to the self-test
 *
 * Returns 0, or -1 after printing an error. Called by sys_ddr_run_script (script command 54) and by
 * sys_ddr_train_read_eye_all, which nothing calls. The step it records for the error messages is 9 ("R_VREF").
 *
 * One measurement is sys_ddr_measure_read_eye_at: it writes rdqs90_dly (read_deskew field3, the value read at
 * the start) and the swept value into read_eye field2 and field1, then runs sys_ddr_find_read_eye, which gives
 * the window as {right edge, left edge}.
 *
 * Phases:
 *  1. Record the step, check the arguments and ui_percentage.
 *  2. Read read_eye field3 (for the minimum overlap), rdqs90_dly and the present read_eye field2 value, which
 *     is where both ends of the range start. Measure there; both edges -1 is an error ("Bist fail or
 *     timeout"). This window is the first window of both ends.
 *  3. Two passes, with steps of 4 and then 1. A pass moves the upper and the lower end in turn, one step each,
 *     until both have stopped. Upper end: measure at value + step; the end stays there when the edges are not
 *     both -1 and the new window overlaps the lower end's window by at least the minimum, otherwise it goes
 *     back and stops. Once it has gone above 0x4B it stops. Lower end: the same downwards, against the upper
 *     end's window; it stops at 4 or below.
 *  4. Write the middle of the range, (lower + upper) / 2, to read_eye field2 and field1, and the middle of the
 *     overlap of the two end windows, (smaller right edge + larger left edge) / 2, to rdqs90_dly.
 *
 * The overlap (smaller right edge - larger left edge) is compared unsigned: windows that do not overlap give a
 * negative difference, which as an unsigned number passes the test.
 */
int sys_ddr_train_read_eye(unsigned int phy, unsigned int phy_version, unsigned int generation, int byte, int ui_percentage, unsigned int bit_mode)
{
    unsigned int field3_value, min_overlap;
    int rdqs90, upper, lower, step, pass, upper_done, lower_done;
    int lower_right, lower_left, upper_right, upper_left;
    struct read_eye_result edges;
    int right, left;

    /* Phase 1: step, arguments. */
    sys_ddr_set_step(DDR_STEP_R_VREF, phy, byte);
    sys_ddr_check_arguments(phy, phy_version, generation);
    if (ui_percentage < UI_PERCENTAGE_MIN || ui_percentage > UI_PERCENTAGE_MAX) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: UI_percentage = %d < 20 or > 80.\n", ui_percentage);
        return -1;
    }
    /* Phase 2: minimum overlap, start value, first window. */
    if (byte == -1)
        field3_value = sys_ddr_phy_read_field(phy, (unsigned int)sys_ddr_read_eye_field3_regs, (unsigned int)sys_ddr_read_eye_field3_masks, (unsigned int)sys_ddr_read_eye_field3_shifts);
    else
        field3_value = sys_ddr_phy_read_field(phy, sys_ddr_read_eye_field3_regs[byte], sys_ddr_read_eye_field3_masks[byte], sys_ddr_read_eye_field3_shifts[byte]);
    min_overlap = field3_value * ui_percentage * 2 / 100;
    if (byte == -1)
        rdqs90 = sys_ddr_phy_read_field(phy, (unsigned int)sys_ddr_read_deskew_field3_regs, (unsigned int)sys_ddr_read_deskew_field3_masks, (unsigned int)sys_ddr_read_deskew_field3_shifts);
    else
        rdqs90 = sys_ddr_phy_read_field(phy, sys_ddr_read_deskew_field3_regs[byte], sys_ddr_read_deskew_field3_masks[byte], sys_ddr_read_deskew_field3_shifts[byte]);
    if (byte == -1)
        upper = sys_ddr_phy_read_field(phy, (unsigned int)sys_ddr_read_eye_field2_regs, (unsigned int)sys_ddr_read_eye_field2_masks, (unsigned int)sys_ddr_read_eye_field2_shifts);
    else
        upper = sys_ddr_phy_read_field(phy, sys_ddr_read_eye_field2_regs[byte], sys_ddr_read_eye_field2_masks[byte], sys_ddr_read_eye_field2_shifts[byte]);
    step = FIRST_PASS_STEP;
    edges = sys_ddr_measure_read_eye_at(phy, phy_version, generation, upper, byte, rdqs90, bit_mode);
    right = edges.first;
    left = edges.second;
    lower = upper;
    if ((left == -1) & (right == -1)) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: Bist fail or timeout.\n");
        return -1;
    }
    upper_left = left;
    upper_right = right;
    lower_left = left;
    lower_right = right;
    /* Phase 3: two passes, the ends moved in turn. */
    for (pass = 0; pass <= 1; pass++) {
        if (pass > 0)
            step = 1;
        lower_done = 0;
        upper_done = 0;
        while (!upper_done || !lower_done) {
            if (!upper_done) {
                upper += step;
                edges = sys_ddr_measure_read_eye_at(phy, phy_version, generation, upper, byte, rdqs90, bit_mode);
                right = edges.first;
                left = edges.second;
                if ((left == -1) & (right == -1)) {
                    upper -= step;
                    upper_done = 1;
                    continue;
                }
                /* Overlap with the lower end's window. */
                if ((unsigned int)(MIN(lower_right, right) - MAX(lower_left, left)) >= min_overlap) {
                    upper_left = left;
                    upper_right = right;
                    if (upper > UPPER_STOP) {
                        upper_done = 1;
                        continue;
                    }
                } else {
                    upper -= step;
                    upper_done = 1;
                }
            }
            if (!lower_done) {
                lower -= step;
                edges = sys_ddr_measure_read_eye_at(phy, phy_version, generation, lower, byte, rdqs90, bit_mode);
                right = edges.first;
                left = edges.second;
                if ((left == -1) & (right == -1)) {
                    lower += step;
                    lower_done = 1;
                    continue;
                }
                /* Overlap with the upper end's window. */
                if ((unsigned int)(MIN(right, upper_right) - MAX(left, upper_left)) >= min_overlap) {
                    lower_left = left;
                    lower_right = right;
                    if (lower <= LOWER_STOP)
                        lower_done = 1;
                } else {
                    lower += step;
                    lower_done = 1;
                }
            }
        }
    }
    /* Phase 4: the middles. */
    if (byte == -1)
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_read_eye_field2_regs, (unsigned int)sys_ddr_read_eye_field2_masks, (unsigned int)sys_ddr_read_eye_field2_shifts, (lower + upper) >> 1);
    else
        sys_ddr_phy_write_field(phy, sys_ddr_read_eye_field2_regs[byte], sys_ddr_read_eye_field2_masks[byte], sys_ddr_read_eye_field2_shifts[byte], (lower + upper) >> 1);
    if (byte == -1)
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_read_eye_field1_regs, (unsigned int)sys_ddr_read_eye_field1_masks, (unsigned int)sys_ddr_read_eye_field1_shifts, (lower + upper) >> 1);
    else
        sys_ddr_phy_write_field(phy, sys_ddr_read_eye_field1_regs[byte], sys_ddr_read_eye_field1_masks[byte], sys_ddr_read_eye_field1_shifts[byte], (lower + upper) >> 1);
    if (byte == -1)
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_read_deskew_field3_regs, (unsigned int)sys_ddr_read_deskew_field3_masks, (unsigned int)sys_ddr_read_deskew_field3_shifts,
                     (MIN(lower_right, upper_right) + MAX(lower_left, upper_left)) / 2);
    else
        sys_ddr_phy_write_field(phy, sys_ddr_read_deskew_field3_regs[byte], sys_ddr_read_deskew_field3_masks[byte], sys_ddr_read_deskew_field3_shifts[byte], (MIN(lower_right, upper_right) + MAX(lower_left, upper_left)) / 2);
    return 0;
}
