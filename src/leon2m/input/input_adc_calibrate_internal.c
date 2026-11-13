/* input_adc_calibrate_internal  (FUN_a00f557c)
 *
 * Calibrate the analogue input stage against the internal reference.
 * Name basis: descriptive - saves block registers, switches the shared route, averages readings; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f557c @ 0xa00f557c-0xa00f59c4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - an int parameter, passed to the unsigned char parameters of the callees;
 *  - the inlined helper calibrate_levels_three_readings takes the int, starts with the ANALOG_REG_10C write (as
 *    input_adc_calibrate_offsets does) and passes 'unsigned char block = block_arg' to its callees (the firmware
 *    copies the register before the '<= 7' test and zero-extends it after the store);
 *  - the averaging inside the loop ('if (--stable_left == 0) { ... }' with 'stable_left != 0' in the loop
 *    condition), as in input_adc_calibrate_levels;
 *  - the level step as the comma expression '(input_adc_select_reference(2), input_adc_calibrate_levels(...))'
 *    in the condition, and the result returned as 'result & 1'.
 */
extern int abs(int);
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_block_power(unsigned char, int);
extern unsigned char input_block_is_change_pending(unsigned char blk);
extern unsigned char input_adc_get_level2(void);
extern unsigned char input_adc_get_level1(void);
extern unsigned char input_adc_get_level0(void);
extern void input_adc_set_level2(unsigned char);
extern void input_adc_set_level1(unsigned char);
extern void input_adc_set_level0(unsigned char);
extern void input_adc_select_reference(int);
extern unsigned char input_adc_calibrate_offsets(unsigned char);
extern unsigned char input_adc_calibrate_levels(unsigned char);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void timer_sleep_ticks(int ms);

/* Analogue input registers. */
#define ANALOG_REG_10C       R(0xcf02010c)  /* block number in both nibbles (blocks 0..7), else 0 */

#define BLK_REG_2A           0x2a           /* picture block register, 0 during the calibration */

/* Capture block registers. */
#define CAP_REG_4A           0x4a           /* bit 5 cleared during the calibration */
#define CAP_REG_5E           0x5e
#define CAP_REG_5F           0x5f
#define CAP_REG_60           0x60
#define CAP_REG_63           0x63
#define CAP_REG_64           0x64
#define CAP_REG_65           0x65
#define CAP_REG_66           0x66
#define CAP_REG_67           0x67

/* input_adc_select_reference selectors. */
#define REFERENCE_SELECT_0   0              /* for the offset calibration */
#define REFERENCE_SELECT_2   2              /* for the level calibration */
#define REFERENCE_SELECT_3   3              /* afterwards */

#define STABLE_READINGS      3              /* readings in a row that must agree; their average is taken */
#define STABLE_TOLERANCE     2
#define SAMPLE_TICKS         2
#define CALIBRATION_TICKS    0x12b          /* the sampling gives up after this many ticks */
#define LEVEL_START_VALUE    0xff

/*
 * First pass over the three levels, the same steps as input_adc_calibrate_levels with three stable readings
 * (tolerance 2) and other values in capture registers 0x65..0x67. The averages are stored when three readings
 * in a row agree, else the levels found at its start are written back; there is no result.
 */
static void calibrate_levels_three_readings(int block_arg)
{
    unsigned char block = block_arg;
    unsigned short sums[3];
    unsigned char current[3], saved[3];
    unsigned char stable_left, value;
    unsigned char selector;
    unsigned short start_ticks;

    selector = 0;
    if ((unsigned char)block_arg <= 7) {
        selector = block_arg << 4;
        selector |= block_arg;
    }
    ANALOG_REG_10C = selector;

    saved[0] = input_adc_get_level2();
    saved[1] = input_adc_get_level1();
    saved[2] = input_adc_get_level0();
    input_adc_select_reference(REFERENCE_SELECT_2);
    input_capture_write8(block, CAP_REG_5E, 0x71);
    input_capture_write8(block, CAP_REG_5F, 0xff);
    input_capture_write8(block, CAP_REG_60, 0);
    current[0] = 0;
    current[1] = 0;
    current[2] = 0;
    input_adc_set_level2(LEVEL_START_VALUE);
    input_adc_set_level1(LEVEL_START_VALUE);
    input_adc_set_level0(LEVEL_START_VALUE);
    input_capture_write8(block, CAP_REG_65, 0xf5);
    input_capture_write8(block, CAP_REG_66, 0xf4);
    input_capture_write8(block, CAP_REG_67, 0xf0);
    input_capture_write8(block, CAP_REG_63, 0x80);
    input_capture_write8(block, CAP_REG_64, 3);
    sums[0] = 0;
    sums[1] = 0;
    sums[2] = 0;
    start_ticks = timer_get_ticks16();
    stable_left = STABLE_READINGS;
    do {
        timer_sleep_ticks(SAMPLE_TICKS);
        if (input_block_is_change_pending(block) == 1) {
            stable_left = STABLE_READINGS;
            break;
        }
        value = input_adc_get_level2();
        if (abs(current[0] - value) > STABLE_TOLERANCE)
            stable_left = STABLE_READINGS;
        current[0] = value;
        value = input_adc_get_level1();
        if (abs(current[1] - value) > STABLE_TOLERANCE)
            stable_left = STABLE_READINGS;
        current[1] = value;
        value = input_adc_get_level0();
        if (abs(current[2] - value) > STABLE_TOLERANCE)
            stable_left = STABLE_READINGS;
        current[2] = value;
        /* A (re)started count begins its sums with this reading. */
        if (stable_left == STABLE_READINGS) {
            sums[0] = current[0];
            sums[1] = current[1];
            sums[2] = current[2];
        } else {
            sums[0] += current[0];
            sums[1] += current[1];
            sums[2] += current[2];
        }
        if (--stable_left == 0) {
            current[0] = sums[0] / STABLE_READINGS;
            current[1] = sums[1] / STABLE_READINGS;
            current[2] = sums[2] / STABLE_READINGS;
        }
    } while (stable_left != 0 && timer_ticks_since(start_ticks) <= CALIBRATION_TICKS);
    input_capture_write8(block, CAP_REG_63, 0);
    input_capture_write8(block, CAP_REG_64, 0);
    input_capture_write8(block, CAP_REG_65, 0);
    input_capture_write8(block, CAP_REG_66, 0);
    input_capture_write8(block, CAP_REG_67, 0);
    input_capture_write8(block, CAP_REG_5E, 0);
    input_adc_select_reference(REFERENCE_SELECT_3);
    if (stable_left != 0) {
        input_adc_set_level2(saved[0]);
        input_adc_set_level1(saved[1]);
        input_adc_set_level0(saved[2]);
    } else {
        input_adc_set_level2(current[0]);
        input_adc_set_level1(current[1]);
        input_adc_set_level0(current[2]);
    }
}

/*
 * Calibrate the analogue input stage of one input block: a first pass over the levels, then the offsets, then
 * the levels again.
 *
 *   block   input block
 *
 * Returns 1 when both input_adc_calibrate_offsets and input_adc_calibrate_levels succeed; else the three levels
 * read at the start are written back and 0 is returned. No routine of this firmware calls it directly and its
 * address is not stored as data.
 *
 * Phases:
 *  1. set-up: save picture block register 0x2A and CAP_REG_4A; register 0x2A = 0, bit 5 of CAP_REG_4A cleared;
 *     the block's receiver switched on (input_block_power); the three levels saved;
 *  2. first level pass (calibrate_levels_three_readings);
 *  3. reference selector 0 and input_adc_calibrate_offsets; when that succeeds, selector 2 and
 *     input_adc_calibrate_levels;
 *  4. clean-up: selector 3, receiver off, the two saved registers restored.
 */
int input_adc_calibrate_internal(int block)
{
    unsigned char levels_before[3];
    unsigned char saved_reg2a, saved_reg4a;
    unsigned char result;

    /* Phase 1: set-up. */
    saved_reg2a = pq_block_read8(block, BLK_REG_2A);
    saved_reg4a = input_capture_read8(block, CAP_REG_4A);
    pq_block_write8(block, BLK_REG_2A, 0);
    input_capture_update_bits(block, CAP_REG_4A, 0x20, 0);
    input_block_power(block, 1);
    result = 0;
    levels_before[0] = input_adc_get_level2();
    levels_before[1] = input_adc_get_level1();
    levels_before[2] = input_adc_get_level0();

    /* Phase 2: first level pass. */
    calibrate_levels_three_readings(block);

    /* Phase 3: offsets, then levels. */
    input_adc_select_reference(REFERENCE_SELECT_0);
    if (input_adc_calibrate_offsets(block) && (input_adc_select_reference(REFERENCE_SELECT_2), input_adc_calibrate_levels(block))) {
        result = 1;
    } else {
        input_adc_set_level2(levels_before[0]);
        input_adc_set_level1(levels_before[1]);
        input_adc_set_level0(levels_before[2]);
    }

    /* Phase 4: clean-up. */
    input_adc_select_reference(REFERENCE_SELECT_3);
    input_block_power(block, 0);
    pq_block_write8(block, BLK_REG_2A, saved_reg2a);
    input_capture_write8(block, CAP_REG_4A, saved_reg4a);
    return result & 1;
}
