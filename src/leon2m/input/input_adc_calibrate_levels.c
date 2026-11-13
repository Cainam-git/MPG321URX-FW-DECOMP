/* input_adc_calibrate_levels  (FUN_a00f4e60)
 *
 * Sample the three level values until ten stable readings and store their averages.
 * Returns: 1 on success
 * Name basis: descriptive - restores the old values on failure
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f4e60 @ 0xa00f4e60-0xa00f51b4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: a K&R definition with an unsigned char parameter; the selector
 * value as 'value = block << 4; value |= block;'; 'stable_left = STABLE_READINGS' right after the
 * ANALOG_REG_10C store; the differences through abs(); the averaging written inside the loop
 * ('if (--stable_left == 0) { ... }' with 'stable_left != 0' in the loop condition), so the compiler moves the
 * 0xcccccccd constant (division by 10) in front of the loop as in the firmware.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char input_adc_levels_done;
extern unsigned char input_adc_get_level2(void);
extern unsigned char input_adc_get_level1(void);
extern unsigned char input_adc_get_level0(void);
extern void input_adc_set_level2(unsigned char);
extern void input_adc_set_level1(unsigned char);
extern void input_adc_set_level0(unsigned char);
extern void input_adc_select_reference(unsigned char);
extern unsigned char input_block_is_change_pending(unsigned char);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern void timer_sleep_ticks(int ms);

extern int abs(int);

/* Analogue input registers. */
#define ANALOG_REG_10C       R(0xcf02010c)  /* block number in both nibbles (blocks 0..7), else 0 */

/* Capture block registers set for the calibration and cleared afterwards. */
#define CAP_REG_5E           0x5e
#define CAP_REG_5F           0x5f
#define CAP_REG_60           0x60
#define CAP_REG_63           0x63
#define CAP_REG_64           0x64
#define CAP_REG_65           0x65
#define CAP_REG_66           0x66
#define CAP_REG_67           0x67

/* input_adc_select_reference selectors used here. */
#define REFERENCE_SELECT_2   2              /* during the calibration */
#define REFERENCE_SELECT_3   3              /* afterwards (the 'any other' case of that routine) */

#define STABLE_READINGS      10             /* readings in a row that must agree; their average is taken */
#define STABLE_TOLERANCE     3              /* largest change between two readings that still counts as stable */
#define SAMPLE_TICKS         2              /* pause before each reading */
#define CALIBRATION_TICKS    0x12b          /* the sampling gives up after this many ticks */
#define LEVEL_START_VALUE    0xff

/*
 * Calibrate the three level values of the analogue input stage: start them at 0xFF, read them back until ten
 * readings in a row agree, and store the averages.
 *
 *   block   input block (0..7 also go to ANALOG_REG_10C)
 *
 * Returns 1 and sets input_adc_levels_done on success. On a pending change of the block, or when no ten stable
 * readings come within CALIBRATION_TICKS, the saved values are written back and 0 is returned.
 * Called by input_adc_auto_color.
 *
 * Phases:
 *  1. set-up: ANALOG_REG_10C, save the three levels, reference selector 2, capture registers 0x5E..0x60 and
 *     0x63..0x67 to their calibration values, the three levels to 0xFF;
 *  2. sampling: every SAMPLE_TICKS read the three levels; a change of more than STABLE_TOLERANCE in any of them
 *     restarts the count and the sums with this reading; after ten readings in a row the averages are taken;
 *  3. clean-up: the capture registers back to 0, reference selector 3, then the averages or the saved values.
 *
 * The arrays hold the levels in the order level 2, level 1, level 0.
 */
unsigned char input_adc_calibrate_levels(block)
unsigned char block;
{
    unsigned short sums[3];
    unsigned char current[3];
    unsigned char saved[3];
    unsigned char stable_left;
    unsigned char value;
    unsigned short start_ticks;

    /* Phase 1: set-up. */
    value = 0;
    if (block <= 7) {
        value = block << 4;
        value |= block;
    }
    ANALOG_REG_10C = value;
    stable_left = STABLE_READINGS;
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
    input_capture_write8(block, CAP_REG_65, 0xf4);
    input_capture_write8(block, CAP_REG_66, 0xf1);
    input_capture_write8(block, CAP_REG_67, 0xec);
    input_capture_write8(block, CAP_REG_63, 0x80);
    input_capture_write8(block, CAP_REG_64, 3);
    sums[0] = 0;
    sums[1] = 0;
    sums[2] = 0;

    /* Phase 2: sampling. */
    start_ticks = timer_get_ticks16();
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

    /* Phase 3: clean-up and result. */
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
        return 0;
    }
    input_adc_set_level2(current[0]);
    input_adc_set_level1(current[1]);
    input_adc_set_level0(current[2]);
    input_adc_levels_done = 1;
    return 1;
}
