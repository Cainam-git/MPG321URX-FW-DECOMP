/* sys_ddr_train_vref  (FUN_a00ee1e8)
 *
 * Narrow the reference voltage index range and write the centre of the shared write delay window.
 * Note: It does not set the reference voltage itself; sys_ddr_set_vref uses the narrowed range later.
 * Name basis: derived - prints 'vref2index: can not valid index of vref: 0x%02x' and the MR6 error
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ee1e8 @ 0xa00ee1e8-0xa00ee964 (1916 bytes), flags -mcpu=v8 -O3 (no -g).
 * Source forms the exact build depends on:
 *  - each read and write is its own 'if (byte == -1) ... else ...' statement and the final writes nest their read
 *    ('sys_ddr_phy_write_field(.., sys_ddr_phy_read_field(..) + ..)');
 *  - the speed chain is written in place with delay_per_count as the temporary ('tccd_index = delay_per_count;',
 *    delay_per_count is then set by the second read), which keeps the copy into tccd_index;
 *  - the second final write adds '(whole_steps -= 4)' so the subtraction stays a separate step before the
 *    addition; 'step = 4;' precedes the both-edges test;
 *  - vref2index is a static helper (inlined).
 * Names: the match depends on the names DAT_a8026308_dly_per_cnt_reg, DAT_a80262f8_dly_per_cnt_mask,
 *   DAT_a802b638_dly_per_cnt_shift and sys_ddr_write_delay_field1_regs (the spelling all users of 0xa8026718 share): gcse orders the
 *   hoisted %hi parts of the tables by a hash of the names, which sets their registers.
 */
/* Lower and upper edge of a passing write window, in delay units (sys_ddr_measure_write_eye). */
struct write_window { int low; int high; };
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read(unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct write_window sys_ddr_measure_write_eye(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int,
                               int, unsigned int, unsigned int);
/* 0x4A rows {mode register 6 value, percent, hundredths of a percent}. */
extern unsigned char sys_ddr_vref_table[][3];
/* Per memory interface: the table index range that passed, used by sys_ddr_set_vref. */
extern unsigned int sys_ddr_vref_high_indexes[], sys_ddr_vref_low_indexes[];
/* Each field is entry `byte` of three tables (register, mask, shift). dly_per_cnt gives the number of delay units
   in one whole step; clk_cdly is the field the message "DQ clk cdly is full" names, wr_eye_lcdly the one of
   "wr_eye_lcdly_state_error_flag"; sys_ddr_write_delay_field1_regs is the register table of field 1. */
extern unsigned int DAT_a8026308_dly_per_cnt_reg[], DAT_a80262f8_dly_per_cnt_mask[], DAT_a802b638_dly_per_cnt_shift[];
extern unsigned int sys_ddr_write_delay_field5_regs[], sys_ddr_write_delay_field5_masks[], sys_ddr_write_delay_field5_shifts[];
extern unsigned int sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[];
extern unsigned int sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[];
extern unsigned int DAT_a8026798_clk_cdly_reg[], DAT_a8026788_clk_cdly_msk[], DAT_a8026778_clk_cdly_sft[];
extern unsigned int sys_ddr_write_delay_field2_regs[], sys_ddr_write_delay_field2_masks[], sys_ddr_write_delay_field2_shifts[];
extern unsigned int DAT_a8026748_eye_lcdly_reg[], DAT_a8026738_eye_lcdly_msk[], DAT_a8026728_eye_lcdly_sft[];
extern unsigned int sys_ddr_write_delay_field1_regs[], sys_ddr_write_delay_field1_masks[], sys_ddr_write_delay_field1_shifts[];

#define MIN(x, y) ((x) <= (y) ? (x) : (y))
#define MAX(x, y) ((x) >= (y) ? (x) : (y))

#define DDR_STEP_W_VREF 12          /* training step number, printed as W_VREF by sys_ddr_print_step */

/* Highest DDR speed of each tCCD_L index (as sys_ddr_speed_to_tccd_index and sys_ddr_set_vref). */
#define SPEED_TCCD_0_MAX 1333
#define SPEED_TCCD_1_MAX 1866
#define SPEED_TCCD_2_MAX 2400
#define SPEED_TCCD_3_MAX 2667

#define VREF_ROWS       0x4a        /* rows of sys_ddr_vref_table */
#define VREF_LAST_INDEX 0x49
#define REG_28E         0x28e       /* sys_ddr_set_vref writes the mode register 6 value it accepts here */
#define COARSE_STEP     4           /* index step of the first pass; the second pass steps by 1 */
#define FIELD3_OFFSET   4           /* field 3 = field 4 - 4 */

/* Row of sys_ddr_vref_table whose mode register 6 value equals mr6_value, or -1 with the firmware's message. */

static int vref2index(unsigned char mr6_value)
{
    int i;

    for (i = 0; i < VREF_ROWS; i++)
        if (sys_ddr_vref_table[i][0] == mr6_value)
            return i;
    sys_ddr_print_step();
    sys_ddr_print_error_prefix();
    dbg_printf("vref2index: can not valid index of vref: 0x%02x\n", mr6_value);
    return -1;
}

/*
 * Reference voltage training of one data byte of one memory interface (training step W_VREF): find the range of
 * reference voltage steps over which the write window stays wide enough, and set the write delay to the middle
 * of the window that the whole range shares.
 *
 *   unit            memory interface number
 *   phy_version     with ddr_generation, checked by sys_ddr_check_arguments and passed on to the training
 *   ddr_generation
 *   byte            data byte; with -1 the tables' own addresses are passed in place of an entry
 *   bit_mode        passed on to the write window training (through sys_ddr_measure_write_eye)
 *   delay_step      start step of the write window training
 *   speed           DDR speed; gives the tCCD_L index sent with every mode register 6 value
 *   window_percent  the smallest accepted overlap, in percent of 8 whole steps
 *
 * Returns 0, or -1 after printing the step and an error message. Called by the memory script
 * (sys_ddr_run_script, command TRAIN_VREF, arguments 4 to 7 as bit_mode, delay_step, speed, window_percent) and
 * by sys_ddr_train_and_set_vref, which nothing calls.
 *
 * Phases:
 *   1. Record the step, check the arguments, compute the smallest overlap min_window = dly_per_cnt *
 *      window_percent * 8 / 100 delay units, and the tCCD_L index of the speed (above 2667: "Undefined MR6
 *      tCCD_L" and -1).
 *   2. Start at the table row of the value in register 0x28E (no such row: the "vref2index" message and -1) and
 *      measure the write window there (sys_ddr_measure_write_eye, which sends mode register 6 and puts the delay
 *      fields back). No window at all: "Bist fail or timeout" and -1.
 *   3. Two passes, the first stepping the index by 4, the second by 1. In each pass the top index moves up and
 *      the bottom index down, alternately, until both directions have stopped. A direction stops when the new
 *      step has no window or its window overlaps the window at the other end by less than min_window (the step is
 *      undone), or when the top passes 0x49 / the bottom reaches 0 (the step is kept).
 *   4. Narrow the range kept for this interface (sys_ddr_vref_low_indexes / _high_indexes) to the one found.
 *   5. The centre of the overlap of the two end windows, in delay units, becomes the write delay: whole steps
 *      added to field 5 give field 4 and (minus 4) field 3; the rest goes to clk_cdly and wr_eye_lcdly (bits
 *      above the low three) and to field 2 and field 1 (low three bits). Field 6 is not written here.
 * The reference voltage itself is not set here: mode register 6 keeps the value of the last measurement, and
 * sys_ddr_set_vref uses the stored index range.
 */
int sys_ddr_train_vref(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, unsigned int bit_mode, unsigned int delay_step,
                 int speed, int window_percent)
{
    int vref_index, step_units, min_window, tccd_index, delay_per_count, high_index, low_index, step, pass, up_done, down_done, centre;
    int bottom_low, bottom_high, top_low, top_high, new_low, new_high;
    unsigned int whole_steps;
    struct write_window window;

    /* Phase 1: step, arguments, smallest overlap, tCCD_L index. */
    sys_ddr_set_step(DDR_STEP_W_VREF, unit, byte);
    sys_ddr_check_arguments(unit, phy_version, ddr_generation);
    if (byte == -1)
        step_units = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026308_dly_per_cnt_reg, (unsigned int)DAT_a80262f8_dly_per_cnt_mask, (unsigned int)DAT_a802b638_dly_per_cnt_shift);
    else
        step_units = sys_ddr_phy_read_field(unit, DAT_a8026308_dly_per_cnt_reg[byte], DAT_a80262f8_dly_per_cnt_mask[byte], DAT_a802b638_dly_per_cnt_shift[byte]);
    /* dly_per_cnt is read here for the limit and again below for the conversion. */
    min_window = step_units * window_percent * 8 / 100;
    /* delay_per_count holds the tCCD_L index until it is read below. */
    if (speed <= SPEED_TCCD_0_MAX)
        delay_per_count = 0;
    else if (speed <= SPEED_TCCD_1_MAX)
        delay_per_count = 1;
    else if (speed <= SPEED_TCCD_2_MAX)
        delay_per_count = 2;
    else if (speed <= SPEED_TCCD_3_MAX)
        delay_per_count = 3;
    else {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: Undefined MR6 tCCD_L for DDR speed = %d.\n", speed);
        return -1;
    }
    tccd_index = delay_per_count;
    if (byte == -1)
        delay_per_count = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026308_dly_per_cnt_reg, (unsigned int)DAT_a80262f8_dly_per_cnt_mask, (unsigned int)DAT_a802b638_dly_per_cnt_shift);
    else
        delay_per_count = sys_ddr_phy_read_field(unit, DAT_a8026308_dly_per_cnt_reg[byte], DAT_a80262f8_dly_per_cnt_mask[byte], DAT_a802b638_dly_per_cnt_shift[byte]);
    /* Phase 2: the starting row and its window. */
    vref_index = vref2index(sys_ddr_phy_read(unit, REG_28E));
    if (vref_index < 0)
        return -1;
    low_index = vref_index;
    window = sys_ddr_measure_write_eye(unit, phy_version, ddr_generation, tccd_index, vref_index, byte, delay_per_count, bit_mode, delay_step);
    new_low = window.low;
    new_high = window.high;
    high_index = low_index;
    step = COARSE_STEP;
    if ((new_high == -1) & (new_low == -1)) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: Bist fail or timeout.\n");
        return -1;
    }
    top_high = new_high;
    top_low = new_low;
    bottom_high = new_high;
    bottom_low = new_low;
    /* Phase 3: widen the range, first by 4 rows, then by 1. */
    for (pass = 0; pass <= 1; pass++) {
        if (pass > 0)
            step = 1;
        down_done = 0;
        up_done = 0;
        while (!up_done || !down_done) {
            if (!up_done) {
                /* One step up; its window must overlap the window at the bottom. */
                high_index += step;
                window = sys_ddr_measure_write_eye(unit, phy_version, ddr_generation, tccd_index, high_index, byte, delay_per_count, bit_mode, delay_step);
                new_low = window.low;
                new_high = window.high;
                if (new_high == -1) {
                    high_index -= step;
                    up_done = 1;
                } else if (MIN(bottom_high, new_high) - MAX(bottom_low, new_low) >= min_window) {
                    top_high = new_high;
                    top_low = new_low;
                    if (high_index > VREF_LAST_INDEX)
                        up_done = 1;
                } else {
                    high_index -= step;
                    up_done = 1;
                }
            }
            if (!down_done) {
                /* One step down; its window must overlap the window at the top. */
                low_index -= step;
                window = sys_ddr_measure_write_eye(unit, phy_version, ddr_generation, tccd_index, low_index, byte, delay_per_count, bit_mode, delay_step);
                new_low = window.low;
                new_high = window.high;
                if (new_high == -1) {
                    low_index += step;
                    down_done = 1;
                } else if (MIN(new_high, top_high) - MAX(new_low, top_low) >= min_window) {
                    bottom_high = new_high;
                    bottom_low = new_low;
                    if (low_index <= 0)
                        down_done = 1;
                } else {
                    low_index += step;
                    down_done = 1;
                }
            }
        }
    }
    /* Phase 4: narrow the stored range. */
    if (sys_ddr_vref_high_indexes[unit] > (unsigned int)high_index)
        sys_ddr_vref_high_indexes[unit] = high_index;
    if (sys_ddr_vref_low_indexes[unit] < (unsigned int)low_index)
        sys_ddr_vref_low_indexes[unit] = low_index;
    /* Phase 5: the middle of the shared window becomes the write delay. */
    centre = (MAX(bottom_low, top_low) + MIN(bottom_high, top_high)) >> 1;
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts,
                     sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts) + (whole_steps = (unsigned int)centre / delay_per_count));
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte],
                     sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte]) + (whole_steps = (unsigned int)centre / delay_per_count));
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts,
                     sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts) + (whole_steps -= FIELD3_OFFSET));
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte],
                     sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte]) + (whole_steps -= FIELD3_OFFSET));
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, (unsigned int)centre % delay_per_count >> 3);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], (unsigned int)centre % delay_per_count >> 3);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts, (unsigned int)centre % delay_per_count & 7);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte], (unsigned int)centre % delay_per_count & 7);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, (unsigned int)centre % delay_per_count >> 3);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], (unsigned int)centre % delay_per_count >> 3);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts, (unsigned int)centre % delay_per_count & 7);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte], (unsigned int)centre % delay_per_count & 7);
    return 0;
}
