/* input_adc_search_gain  (FUN_a00f3c18)
 *
 * Search the gain setting with up to five probes per step and check the result.
 * Returns: 1 on success
 * Name basis: descriptive - set-up step of the calibration; calls the two check hooks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3c18 @ 0xa00f3c18-0xa00f3f64 (211 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the two searches are written with labels (next_gain / next_probe): with loop statements the compiler lifts
 *    an address part out of the loop, which the firmware does not have;
 *  - the three flags have one shape, 'set 1, branch, clear' (0xa00f3d18, 0xa00f3d28, 0xa00f3d38). For the first
 *    two that is the compiler's form for '> 0x100'. For the third the limit 0 must not be a literal at the
 *    comparison (a literal 0 turns '> 0' into '!= 0' and the flag is then formed without a branch): the limit is
 *    the parameter of the predicate is_above, with the flag set first and cleared when the value is not above
 *    the limit;
 *  - wait_measure_done and fail_and_reset_offsets are the same helpers as in input_adc_auto_adjust.
 */
/* The caller's record (see input_adc_set_capture_offsets); only passed on here. */
struct adc_window_record { unsigned char pad00[0xc]; unsigned short sweep_lower_bound; };

/* The first three entries of the calibration hook record (0xA802B79C). */
struct adc_cal_hooks {
    void (*progress)(unsigned char percent);       /* called with a progress number by input_adc_auto_adjust */
    unsigned char (*check_height)(unsigned char block, unsigned short value, unsigned short reading);  /* not 0 = reject */
    unsigned char (*check_width)(unsigned char block, unsigned short value, unsigned short reading);   /* 0 = take the width */
};
extern struct adc_cal_hooks input_adc_cal_hooks;
extern unsigned char input_adc_adjust_aborted, input_adc_adjust_failed;
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short input_capture_read16(unsigned char blk, unsigned char reg);
extern unsigned int input_block_get_capture_hstart(unsigned char blk);
extern unsigned int input_block_get_capture_vstart(unsigned char blk);
extern unsigned char input_block_is_change_pending(unsigned char blk);
extern void input_block_reset_window_regs(unsigned char blk);
extern void input_block_set_capture_reg12(unsigned char, unsigned short);
extern void input_block_set_capture_reg0e(unsigned char, unsigned short);
extern void input_adc_set_capture_offsets(unsigned char blk, struct adc_window_record *record);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern int abs(int);

/* Capture block registers used here. */
#define CAP_MEASURE_CTRL     0x36   /* command register: 0x41 starts a measurement, bit 0 stays set while it runs */
#define CAP_GAIN             0x37
#define CAP_RESULT_WIDTH     0x38   /* 11 bits; given to input_block_set_capture_reg0e */
#define CAP_READING_3C       0x3c   /* 11 bits */
#define CAP_RESULT_HEIGHT    0x3e   /* 12 bits; given to input_block_set_capture_reg12 */
#define CAP_READING_40       0x40   /* 12 bits */
#define MEASURE_START        0x41
#define MEASURE_BUSY         1

#define MEASURE_WAIT_TICKS   0x63   /* a wait is abandoned after this many timer ticks */
#define GAIN_FIRST           0x30
#define GAIN_STEP            0x10
#define GAIN_END             0xa0   /* the last gain tried is 0x90 */
#define READING_MIN          0x100  /* a probe counts when both readings are above this */
#define PROBES_NEEDED        5      /* counted probes in a row that end the search */
#define RECHECK_TOLERANCE    5

/* Wait until the measurement bits 'mask' of CAP_MEASURE_CTRL clear. Gives up when the block has a pending change
   or after MEASURE_WAIT_TICKS; then input_adc_adjust_aborted is set and 0 returned. */
static unsigned char wait_measure_done(unsigned char block, unsigned char mask)
{
    unsigned short start_ticks;
    unsigned char finished;

    start_ticks = timer_get_ticks16();
    finished = 0;
    for (;;) {
        if (input_block_is_change_pending(block) == 1)
            break;
        if (!(input_capture_read8(block, CAP_MEASURE_CTRL) & mask)) {
            finished = 1;
            break;
        }
        if (timer_ticks_since(start_ticks) > MEASURE_WAIT_TICKS)
            break;
    }
    if (finished == 0)
        input_adc_adjust_aborted = 1;
    return finished;
}

static unsigned char is_above(unsigned int value, unsigned int limit)
{
    unsigned char result = 1;
    if (value <= limit)
        result = 0;
    return result;
}

/* The failure path: mark it and recompute the capture offsets. */
static void fail_and_reset_offsets(unsigned char block, struct adc_window_record *record)
{
    input_adc_adjust_failed = 1;
    input_adc_set_capture_offsets(block, record);
}

/*
 * Find a gain at which the capture block's two readings are both above 0x100, then measure once more and take
 * the width and height results.
 *
 *   block   input block
 *   record  the adjustment record of the caller; passed to input_adc_set_capture_offsets on failure
 *
 * Returns 1 on success, 0 on failure. Called by input_adc_auto_adjust.
 *
 * Phases:
 *  1. read the block's vertical and horizontal start (results not used), reset the window registers, clear
 *     CAP_MEASURE_CTRL;
 *  2. gain search: for gains 0x30, 0x40, ... 0x90 in CAP_GAIN, start measurements; five counted probes in a row
 *     end the search, a probe that does not count moves on to the next gain;
 *  3. check: one more measurement; when either reading differs from the last probe by more than 5, or the
 *     check_height hook rejects the height result, the failure path runs (input_adc_adjust_failed = 1, then
 *     input_adc_set_capture_offsets);
 *  4. CAP_RESULT_HEIGHT becomes the capture height; CAP_RESULT_WIDTH becomes the capture width only when the
 *     check_width hook is set and returns 0.
 * A wait that is abandoned returns 0 at once (with input_adc_adjust_aborted set).
 *
 * The test 'gain > GAIN_END' never holds (the search stops at GAIN_END), so when no gain passes, the check
 * runs with the last gain, 0x90, still in CAP_GAIN.
 */
unsigned char input_adc_search_gain(unsigned char block, struct adc_window_record *record)
{
    unsigned short reading_3c, reading_40, recheck_3c, recheck_40;
    unsigned char gain, good_probes, both_above;
    int first_above, second_above;

    /* Phase 1. */
    input_block_get_capture_vstart(block);
    input_block_get_capture_hstart(block);
    input_block_reset_window_regs(block);
    input_capture_write8(block, CAP_MEASURE_CTRL, 0);

    /* Phase 2: gain search. */
    gain = GAIN_FIRST;
next_gain:
    input_capture_write8(block, CAP_GAIN, gain);
    good_probes = 0;
next_probe:
    input_capture_write8(block, CAP_MEASURE_CTRL, MEASURE_START);
    if (!wait_measure_done(block, MEASURE_BUSY))
        return 0;
    reading_3c = input_capture_read16(block, CAP_READING_3C) & 0x7ff;
    reading_40 = input_capture_read16(block, CAP_READING_40) & 0xfff;
    first_above = reading_3c > READING_MIN;
    second_above = reading_40 > READING_MIN;
    both_above = is_above(first_above & second_above, 0);
    if (both_above) {
        good_probes++;
        if (good_probes < PROBES_NEEDED)
            goto next_probe;
    }
    if (good_probes != PROBES_NEEDED) {
        gain += GAIN_STEP;
        if (gain < GAIN_END)
            goto next_gain;
    }
    if (gain > GAIN_END)
        return 0;

    /* Phase 3: check that a new measurement agrees with the last probe. */
    input_capture_write8(block, CAP_MEASURE_CTRL, MEASURE_START);
    if (wait_measure_done(block, MEASURE_BUSY) == 1) {
        recheck_3c = input_capture_read16(block, CAP_READING_3C) & 0x7ff;
        recheck_40 = input_capture_read16(block, CAP_READING_40) & 0xfff;
        if (abs(recheck_40 - reading_40) > RECHECK_TOLERANCE || abs(recheck_3c - reading_3c) > RECHECK_TOLERANCE) {
            fail_and_reset_offsets(block, record);
            return 0;
        }

        /* Phase 4: the results (the two variables now hold the height and width results). */
        reading_40 = input_capture_read16(block, CAP_RESULT_HEIGHT) & 0xfff;
        reading_3c = input_capture_read16(block, CAP_RESULT_WIDTH) & 0x7ff;
        if (input_adc_cal_hooks.check_height != 0 && input_adc_cal_hooks.check_height(block, reading_40, recheck_40) != 0) {
            fail_and_reset_offsets(block, record);
            return 0;
        }
        input_block_set_capture_reg12(block, reading_40);
        if (input_adc_cal_hooks.check_width != 0 && input_adc_cal_hooks.check_width(block, reading_3c, recheck_3c) == 0)
            input_block_set_capture_reg0e(block, reading_3c);
        return 1;
    }
    return 0;
}
