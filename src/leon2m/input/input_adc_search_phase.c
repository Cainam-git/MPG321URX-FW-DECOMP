/* input_adc_search_phase  (FUN_a00f3f64)
 *
 * Step a sampling position through its range and find where the readings are smallest and largest.
 * Name basis: descriptive - positions 4..0x40
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3f64 @ 0xa00f3f64-0xa00f40e4, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - a do-while loop over `phase` (the loop pass keeps the high parts of input_adc_progress and
 *    input_adc_adjust_aborted in registers as in the firmware);
 *  - the wait is a 'for (;;)' with the input-changed return in place;
 *  - the file needs -msoft-float: it changes which loop invariants are moved. The other matched functions of the
 *    file (input_block_measure_active_area, input_adc_auto_adjust, input_adc_calibrate_levels, input_adc_calibrate_offsets) give the same bytes with -msoft-float.
 */
extern unsigned char input_adc_adjust_aborted, input_adc_phase_first, input_adc_phase_second, input_adc_progress;
extern void (*input_adc_cal_hooks)(unsigned char pct);
extern void input_adc_set_phase(unsigned char v);
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short input_capture_read16(unsigned char blk, unsigned char reg);
extern unsigned char input_block_is_change_pending(unsigned char blk);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);

#define PHASE_STEP          4       /* distance between two tested positions */
#define PHASE_LOOP_LAST     0x41    /* the loop runs while the next position is at most this: the last start is position 0x40 */
#define PHASE_MASK          0x3f    /* positions are stored with six bits */
#define MEASURE_WAIT_TICKS  0x63    /* longest wait for one reading, in ticks */

/*
 * Run a series of readings of input block `block`, one for each sampling position 0, 4, 8, ... 0x3C (16 in
 * all), and return the spread between the largest and the smallest reading. Position of the smallest reading
 * goes to input_adc_phase_first, position of the largest to input_adc_phase_second.
 *
 * The block register 0x36 takes the command 0x42, which starts a reading; bit 1 of register 0x36 stays set until
 * the reading is finished. Each pass of the loop waits for the reading that is running, then sets the next
 * position (input_adc_set_phase) and starts the next reading, and only then collects the finished one:
 * the 32-bit reading is (register pair 0x45 << 16) + register pair 0x43. The position stored for a reading is
 * phase - 4, and the reading started at the last position (0x40) is never collected.
 *
 * While input_adc_progress is 99 or less and the hook input_adc_cal_hooks is set, each pass reports
 * input_adc_progress to the hook and counts it up.
 *
 * Returns the spread, or 0 with input_adc_adjust_aborted set to 1 when the wait is abandoned: the block has a
 * pending change (input_block_is_change_pending), or the reading is not finished after 0x63 ticks. Caller:
 * input_adc_auto_adjust.
 */
unsigned int input_adc_search_phase(unsigned char block)
{
    unsigned char phase, finished;
    unsigned int reading, min_reading, max_reading;
    unsigned short start_ticks;

    input_adc_set_phase(0);
    input_capture_write8(block, 0x36, 0x42);
    max_reading = 0;
    min_reading = 0xffffffff;
    phase = PHASE_STEP;
    do {
        if (input_adc_progress <= 99 && input_adc_cal_hooks != 0)
            input_adc_cal_hooks(input_adc_progress++);
        start_ticks = timer_get_ticks16();
        finished = 0;
        for (;;) {
            if (input_block_is_change_pending(block) == 1) {
                input_adc_adjust_aborted = 1;
                return 0;
            }
            if (!(input_capture_read8(block, 0x36) & 2)) {
                finished = 1;
                break;
            }
            if (timer_ticks_since(start_ticks) > MEASURE_WAIT_TICKS)
                break;
        }
        if (finished == 0) {
            input_adc_adjust_aborted = 1;
            return 0;
        }
        input_adc_set_phase(phase);
        input_capture_write8(block, 0x36, 0x42);
        reading = (input_capture_read16(block, 0x45) << 16) + input_capture_read16(block, 0x43);
        if (reading < min_reading) {
            input_adc_phase_first = (phase - PHASE_STEP) & PHASE_MASK;
            min_reading = reading;
        }
        if (reading > max_reading) {
            input_adc_phase_second = (phase - PHASE_STEP) & PHASE_MASK;
            max_reading = reading;
        }
        phase += PHASE_STEP;
    } while (phase <= PHASE_LOOP_LAST);
    return max_reading - min_reading;
}
