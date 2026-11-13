/* input_adc_calibrate_offsets  (FUN_a00f51b4)
 *
 * Sample the three offset values until ten stable readings and store their averages.
 * Returns: 1 on success
 * Name basis: descriptive - averages plus an offset; restores the old values on failure
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f51b4 @ 0xa00f51b4-0xa00f557c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: a K&R definition with an unsigned char parameter; the selector
 * value as 'selector = block << 4; selector |= block;'; the averaging written inside the loop
 * ('if (--stable_left == 0) { ... }' with 'stable_left != 0' in the loop condition), so the compiler moves the
 * 0xcccccccd constant (division by 10) in front of the loop as in the firmware.
 */
#define ANALOG_REG_10C (*(volatile unsigned int *)0xcf02010c)  /* block number in both nibbles (blocks 0..7), else 0 */
#define ANALOG_REG_114 (*(volatile unsigned int *)0xcf020114)  /* bits 0..2 = 5: the mode handled separately here */
#define ANALOG_MODE_5  5

extern unsigned char input_adc_get_offset2(void);
extern unsigned char input_adc_get_offset1(void);
extern unsigned char input_adc_get_offset0(void);
extern void input_adc_set_offset2(unsigned char);
extern void input_adc_set_offset1(unsigned char);
extern void input_adc_set_offset0(unsigned char);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char input_block_is_change_pending(unsigned int);
extern void timer_sleep_ticks(int);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern int abs(int);

/* Capture block registers set for the calibration. */
#define CAP_REG_63           0x63           /* 0x80, then 0xE0 after the settle time, 0 at the end */
#define CAP_REG_64           0x64           /* 3, 0 at the end */
#define CAP_REG_65           0x65
#define CAP_REG_66           0x66
#define CAP_REG_67           0x67

#define STABLE_READINGS      10             /* readings in a row that must agree; their average is taken */
#define STABLE_TOLERANCE     3              /* largest change between two readings that still counts as stable */
#define OFFSET_READING_MAX   0xe0           /* a reading above this restarts the count */
#define SETTLE_TICKS         300            /* wait before the sampling starts */
#define SAMPLE_TICKS         0x14           /* pause before each reading */
#define CALIBRATION_TICKS    0x12b          /* the sampling gives up after this many ticks */
#define OFFSET_START_VALUE   0x80
#define OFFSET_ADD           4              /* added to the averages that are stored */

/*
 * Calibrate the three offset values of the analogue input stage: start them at 0x80, read them back until ten
 * readings in a row agree (and none is above 0xE0), and store the averages plus 4.
 *
 *   block   input block (0..7 also go to ANALOG_REG_10C)
 *
 * Returns 1 on success. On a pending change of the block, or when no ten stable readings come within
 * CALIBRATION_TICKS, the saved values are written back and 0 is returned. Called by input_adc_auto_color.
 *
 * Phases:
 *  1. set-up: ANALOG_REG_10C, save the three offsets and set them to 0x80; capture registers 0x63..0x67 to their
 *     calibration values (0x65 / 0x67 = 0x80 only in mode 5 of ANALOG_REG_114); wait SETTLE_TICKS; register
 *     0x63 = 0xE0;
 *  2. sampling: every SAMPLE_TICKS read the three offsets; a change of more than STABLE_TOLERANCE or a reading
 *     above OFFSET_READING_MAX restarts the count and the sums with this reading; after ten readings in a row the
 *     averages are taken;
 *  3. clean-up: registers 0x63 / 0x64 back to 0, then the averages + 4 (in mode 5 only offset 1 gets the + 4)
 *     or the saved values. Registers 0x65..0x67 keep their calibration values.
 *
 * The arrays hold the offsets in the order offset 2, offset 1, offset 0.
 */
unsigned char input_adc_calibrate_offsets(block)
    unsigned char block;
{
    unsigned short sums[3];
    unsigned char current[3];
    unsigned char saved[3];
    unsigned char selector;
    unsigned char stable_left;
    unsigned short start_ticks;
    unsigned char value;

    /* Phase 1: set-up. */
    selector = 0;
    if (block <= 7) {
        selector = block << 4;
        selector |= block;
    }
    ANALOG_REG_10C = selector;
    saved[0] = input_adc_get_offset2();
    saved[1] = input_adc_get_offset1();
    saved[2] = input_adc_get_offset0();
    current[0] = 0;
    current[1] = 0;
    current[2] = 0;
    input_adc_set_offset2(OFFSET_START_VALUE);
    input_adc_set_offset1(OFFSET_START_VALUE);
    input_adc_set_offset0(OFFSET_START_VALUE);
    input_capture_write8(block, CAP_REG_66, 0);
    if ((ANALOG_REG_114 & 7) == ANALOG_MODE_5) {
        input_capture_write8(block, CAP_REG_65, 0x80);
        input_capture_write8(block, CAP_REG_67, 0x80);
    } else {
        input_capture_write8(block, CAP_REG_65, 0);
        input_capture_write8(block, CAP_REG_67, 0);
    }
    stable_left = STABLE_READINGS;
    input_capture_write8(block, CAP_REG_63, 0x80);
    input_capture_write8(block, CAP_REG_64, 3);
    sums[0] = 0;
    sums[1] = 0;
    sums[2] = 0;
    timer_sleep_ticks(SETTLE_TICKS);
    input_capture_write8(block, CAP_REG_63, 0xe0);

    /* Phase 2: sampling. */
    start_ticks = timer_get_ticks16();
    do {
        timer_sleep_ticks(SAMPLE_TICKS);
        if (input_block_is_change_pending(block) == 1) {
            stable_left = STABLE_READINGS;
            break;
        }
        value = input_adc_get_offset2();
        if (abs(current[0] - value) > STABLE_TOLERANCE || value > OFFSET_READING_MAX)
            stable_left = STABLE_READINGS;
        current[0] = value;
        value = input_adc_get_offset1();
        if (abs(current[1] - value) > STABLE_TOLERANCE || value > OFFSET_READING_MAX)
            stable_left = STABLE_READINGS;
        current[1] = value;
        value = input_adc_get_offset0();
        if (abs(current[2] - value) > STABLE_TOLERANCE || value > OFFSET_READING_MAX)
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
    if (stable_left == 0) {
        if ((ANALOG_REG_114 & 7) == ANALOG_MODE_5) {
            input_adc_set_offset2(current[0]);
            input_adc_set_offset1(current[1] + OFFSET_ADD);
            input_adc_set_offset0(current[2]);
        } else {
            input_adc_set_offset2(current[0] + OFFSET_ADD);
            input_adc_set_offset1(current[1] + OFFSET_ADD);
            input_adc_set_offset0(current[2] + OFFSET_ADD);
        }
        return 1;
    }
    input_adc_set_offset2(saved[0]);
    input_adc_set_offset1(saved[1]);
    input_adc_set_offset0(saved[2]);
    return 0;
}
