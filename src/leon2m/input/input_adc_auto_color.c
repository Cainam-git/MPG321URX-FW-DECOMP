/* input_adc_auto_color  (FUN_a00f59c4)
 *
 * Run the automatic level and offset calibration in one of two sequences chosen by mode.
 * Note: Mode 0: a level balance, input_adc_calibrate_offsets, then a level trim. Any other mode:
 *   input_adc_calibrate_offsets, then input_adc_calibrate_levels. Nothing calls it.
 * Name basis: descriptive - mode 0: level balance, offsets, level trim; other modes: offsets, then levels; no
 *   caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f59c4 @ 0xa00f59c4-0xa00f62ac (2280 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the first two steps are the static helper first_steps(port, mode), inlined once: 'unsigned char block =
 *    port; if (mode == 0 && balance_levels(port) != 1) return 0; return input_adc_calibrate_offsets(block);'.
 *    Its block is the firmware's copy 'mov %l0,%l6' (0xa00f5a6c, used only by the call at 0xa00f6184);
 *    balance_levels' own 'unsigned char block = port' is 'mov %l0,%l2' / 'and %l2,0xff,%i0' (0xa00f5a74,
 *    0xa00f5a94). mode != 0 enters the call block directly (0xa00f5a68), the call block lies out of line
 *    (0xa00f6180, 'b 0xa00f5dc0'), and the helper's result is tested at its end label ('clr %o0' /
 *    'and %o0,0xff' at 0xa00f5dbc / 0xa00f618c, then 'and %o0,0xff,%l0; cmp %l0,1' at 0xa00f5dc0);
 *  - balance_levels and trim_levels return unsigned char 0/1; their results stay as unfolded tests at the joins
 *    (0xa00f5db0 'clr %g1; cmp %g1,0', 0xa00f6168 'mov 1,%g1; cmp %g1,0');
 *  - limit_x10 is an unsigned int (32-bit compare with the reloaded value at 0xa00f610c);
 *  - trim_levels' failure exits each restore the levels and return 0 in place, as balance_levels does; the
 *    compiler merges them into the firmware's one restore block (0xa00f621c / 0xa00f6224, reached from
 *    0xa00f5f78, 0xa00f6000 and 0xa00f60d0);
 *  - trim_levels keeps one byte scratch for the level index ('scratch = 2 - i; ADC_LEVEL_REG(scratch) = ..')
 *    and for the register 0x30 value ('scratch = (2 - i) * 8 + 0x80; input_capture_write8(block, 0x30,
 *    scratch);'): the firmware recomputes 2 - i at every level access, also inside the coarse and fine loops
 *    (0xa00f5e8c, 0xa00f5ed8, 0xa00f6030, 0xa00f6134), computes the register value in each loop's preheader
 *    (0xa00f5eb4, 0xa00f6004) and masks it at the use ('and %i5,0xf8,%o2' at 0xa00f5ef4 and in the delay slot
 *    of the 0xa00f6054 call);
 *  - one variable (value) holds both the route byte and the readings in balance_levels.
 */

/* The shared route register: (block << 4) | block for a block from 0 to 7, else 0 (as input_set_shared_route). */
#define SHARED_ROUTE_REG (*(volatile unsigned int *)0xcf02010c)

/* Level register n of the analogue input stage: 0xCF020000 + 4 * n, the registers of input_adc_get_level0..2. */
#define HW(n) (*(volatile unsigned int *)(0xcf000000 | ((n) << 2)))
#define ADC_LEVEL_REG(n) HW(0x8000 + n)

#define MEASURE_WAIT_TICKS 0x63         /* a wait is abandoned after this many timer ticks */

extern unsigned char input_adc_adjust_aborted;
extern unsigned char input_is_port_code_scalable(unsigned char block);
extern unsigned char pq_block_read8(unsigned char block, unsigned char reg);
extern unsigned char input_capture_read8(unsigned char block, unsigned char reg);
extern void pq_block_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void input_capture_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void input_capture_update_bits(unsigned char block, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned short input_capture_read16(unsigned char block, unsigned char reg);
extern unsigned int input_block_get_capture_vstart(unsigned char block);
extern unsigned char input_block_is_change_pending(unsigned char block);
extern unsigned char input_adc_get_offset2(void);
extern unsigned char input_adc_get_offset1(void);
extern unsigned char input_adc_get_offset0(void);
extern unsigned char input_adc_get_level2(void);
extern unsigned char input_adc_get_level1(void);
extern unsigned char input_adc_get_level0(void);
extern void input_adc_set_offset2(unsigned char value);
extern void input_adc_set_offset1(unsigned char value);
extern void input_adc_set_offset0(unsigned char value);
extern void input_adc_set_level2(unsigned char value);
extern void input_adc_set_level1(unsigned char value);
extern void input_adc_set_level0(unsigned char value);
extern unsigned char input_adc_calibrate_offsets(unsigned char block);
extern unsigned char input_adc_calibrate_levels(unsigned char block);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);

/*
 * Write 0x6E to capture register 0x36 and wait until its bit 1 reads 0. The wait is abandoned, with
 * input_adc_adjust_aborted set to 1, when the block's change flag is set or after MEASURE_WAIT_TICKS ticks.
 */
static void wait_reg36(unsigned char block)
{
    unsigned short start;
    unsigned char done;

    start = timer_get_ticks16();
    input_capture_write8(block, 0x36, 0x6e);
    done = 0;
    for (;;) {
        if (input_block_is_change_pending(block) == 1) {
            input_adc_adjust_aborted = 1;
            break;
        }
        if (!(input_capture_read8(block, 0x36) & 2)) {
            done = 1;
            break;
        }
        if (timer_ticks_since(start) > MEASURE_WAIT_TICKS)
            break;
    }
    if (done == 0)
        input_adc_adjust_aborted = 1;
}

/* Wait until bit 7 of capture register 0x30 reads 0; abandoned like wait_reg36. */
static void wait_reg30(unsigned char block)
{
    unsigned short start;
    unsigned char done;

    start = timer_get_ticks16();
    done = 0;
    for (;;) {
        if (input_block_is_change_pending(block) == 1) {
            input_adc_adjust_aborted = 1;
            break;
        }
        if (!(input_capture_read8(block, 0x30) & 0x80)) {
            done = 1;
            break;
        }
        if (timer_ticks_since(start) > MEASURE_WAIT_TICKS)
            break;
    }
    if (done == 0)
        input_adc_adjust_aborted = 1;
}

/*
 * Move the three level values until each reading of capture registers 0x43, 0x44 and 0x45 lies between 0xF0
 * and 0xF8. level[0] is level 2 and goes with register 0x43, level[1] is level 1 with 0x44, level[2] is
 * level 0 with 0x45. At most 0x80 rounds.
 *
 * Returns 1 when a round changes nothing and every level is between 8 and 0xF8. Every other end (a wait
 * abandoned, a reading below its lower bound, a level out of that range, 0x80 rounds used up) puts the
 * levels back as they were and returns 0 with input_adc_adjust_aborted set to 1.
 */
static unsigned char balance_levels(unsigned int port)
{
    unsigned char block = port;
    unsigned char level[3];
    unsigned char saved_level[3];
    unsigned char value, changed, round;

    if (block > 7)
        value = 0;
    else {
        value = port << 4;
        value |= port;
    }
    SHARED_ROUTE_REG = value;
    saved_level[0] = input_adc_get_level2();
    saved_level[1] = input_adc_get_level1();
    saved_level[2] = input_adc_get_level0();
    level[0] = input_adc_get_level2();
    level[1] = input_adc_get_level1();
    level[2] = input_adc_get_level0();
    for (round = 0; round < 0x80; round++) {
        wait_reg36(block);
        if (input_adc_adjust_aborted == 1) {
            input_adc_set_level2(saved_level[0]);
            input_adc_set_level1(saved_level[1]);
            input_adc_set_level0(saved_level[2]);
            return 0;
        }
        /* For each level: a reading below 0x60 + (0xFF - level) * 0x90 / 0xFF ends the search. In byte
           arithmetic level + reading + 0x10 is level - (0xF0 - reading), and level + reading + 8 is
           level + (reading - 0xF8): the level moves by the distance of the reading from 0xF0..0xF8. */
        changed = 0;
        value = input_capture_read8(block, 0x43);
        if (value < (unsigned short)((unsigned short)(0xff - level[0]) * 0x90 / 0xff + 0x60))
            break;
        if (value < 0xf0 && level[0] > 8) {
            level[0] = level[0] + value + 0x10;
            changed = 0xff;
        }
        if (value > 0xf8 && level[0] < 0xf8) {
            level[0] = level[0] + value + 8;
            changed = 0xff;
        }
        value = input_capture_read8(block, 0x44);
        if (value < (unsigned short)((unsigned short)(0xff - level[1]) * 0x90 / 0xff + 0x60))
            break;
        if (value < 0xf0 && level[1] > 8) {
            level[1] = level[1] + value + 0x10;
            changed = 0xff;
        }
        if (value > 0xf8 && level[1] < 0xf8) {
            level[1] = level[1] + value + 8;
            changed = 0xff;
        }
        value = input_capture_read8(block, 0x45);
        if (value < (unsigned short)((unsigned short)(0xff - level[2]) * 0x90 / 0xff + 0x60))
            break;
        if (value < 0xf0 && level[2] > 8) {
            level[2] = level[2] + value + 0x10;
            changed = 0xff;
        }
        if (value > 0xf8 && level[2] < 0xf8) {
            level[2] = level[2] + value + 8;
            changed = 0xff;
        }
        if (changed == 0) {
            /* Nothing moved: done when every level lies in 8..0xF8. */
            if ((unsigned char)(level[0] - 8) <= 0xf0 && (unsigned char)(level[1] - 8) <= 0xf0 &&
                (unsigned char)(level[2] - 8) <= 0xf0)
                return 1;
            break;
        }
        input_adc_set_level2(level[0]);
        input_adc_set_level1(level[1]);
        input_adc_set_level0(level[2]);
    }
    input_adc_set_level2(saved_level[0]);
    input_adc_set_level1(saved_level[1]);
    input_adc_set_level0(saved_level[2]);
    input_adc_adjust_aborted = 1;
    return 0;
}

/*
 * Lower each level (level 2, then 1, then 0) until a reading passes a bound taken from the block's vertical
 * start (input_block_get_capture_vstart). Capture register 0x32 is set to 0xF8 first.
 *
 * A reading: capture register 0x30 = 0, the level register written, register 0x30 = 0x80 + 8 * level number,
 * a wait for bit 7 of register 0x30 to clear, then register 0x31 = an index 0..7 and the 24-bit value of
 * registers 0x33 (low byte) to 0x35.
 *
 * Coarse phase: while the level is above 7, indexes 0..7 are read; a value above 3 * vertical start ends the
 * phase, else the level goes down by 8. A level of 0 at the end is a failure.
 * Fine phase: up to 16 more steps of 1, reading index 7, until its value is above 10 * vertical start.
 * The level is left at the last value tried.
 *
 * Returns 1, or 0 with the levels put back as they were (input_adc_adjust_aborted is 1 then).
 */
static unsigned char trim_levels(unsigned char block)
{
    unsigned char saved_level[3];
    unsigned int vstart;
    unsigned int limit_x10;
    unsigned char i, index, step, level, found, scratch;
    unsigned int reading;

    saved_level[0] = input_adc_get_level2();
    saved_level[1] = input_adc_get_level1();
    saved_level[2] = input_adc_get_level0();
    input_capture_write8(block, 0x32, 0xf8);
    vstart = (unsigned short)input_block_get_capture_vstart(block);
    limit_x10 = vstart * 10;
    for (i = 0; i < 3; i++) {
        scratch = 2 - i;
        level = ADC_LEVEL_REG(scratch);

        /* Coarse phase: steps of 8. */
        while (level > 7) {
            input_capture_write8(block, 0x30, 0);
            scratch = 2 - i;
            ADC_LEVEL_REG(scratch) = level;
            scratch = (2 - i) * 8 + 0x80;
            input_capture_write8(block, 0x30, scratch);
            wait_reg30(block);
            if (input_adc_adjust_aborted == 1) {
                input_adc_set_level2(saved_level[0]);
                input_adc_set_level1(saved_level[1]);
                input_adc_set_level0(saved_level[2]);
                return 0;
            }
            found = 0;
            for (index = 0; index < 8; index++) {
                input_capture_write8(block, 0x31, index);
                reading = (input_capture_read16(block, 0x34) << 8) + input_capture_read8(block, 0x33);
                if (vstart * 3 < reading) {
                    found = 0xff;
                    break;
                }
            }
            if (found)
                break;
            level -= 8;
        }
        if (level == 0) {
            input_adc_adjust_aborted = 1;
            input_adc_set_level2(saved_level[0]);
            input_adc_set_level1(saved_level[1]);
            input_adc_set_level0(saved_level[2]);
            return 0;
        }

        /* Fine phase: steps of 1 below the coarse result. */
        for (step = 0; step < 0x10; step++) {
            input_capture_write8(block, 0x30, 0);
            scratch = 2 - i;
            ADC_LEVEL_REG(scratch) = level - step;
            scratch = (2 - i) * 8 + 0x80;
            input_capture_write8(block, 0x30, scratch);
            wait_reg30(block);
            if (input_adc_adjust_aborted == 1) {
                input_adc_set_level2(saved_level[0]);
                input_adc_set_level1(saved_level[1]);
                input_adc_set_level0(saved_level[2]);
                return 0;
            }
            input_capture_write8(block, 0x31, 7);
            reading = (input_capture_read16(block, 0x34) << 8) + input_capture_read8(block, 0x33);
            if (limit_x10 < reading)
                break;
        }
        scratch = 2 - i;
        ADC_LEVEL_REG(scratch) = (unsigned char)(level - step);
    }
    return 1;
}

/* Mode 0 balances the levels before the offsets; any other mode starts with the offsets. */
static unsigned char first_steps(unsigned int port, unsigned char mode)
{
    unsigned char block = port;

    if (mode == 0 && balance_levels(port) != 1)
        return 0;
    return input_adc_calibrate_offsets(block);
}

/*
 * Calibrate the three offset and three level values of the analogue input stage for input block port.
 *
 *   port  the input block (0..7; also written to the shared route register)
 *   mode  0: balance the levels, calibrate the offsets, then trim the levels (the helpers above);
 *         other: calibrate the offsets, then the levels (input_adc_calibrate_offsets, input_adc_calibrate_levels)
 *
 * Returns 1 on success, 0 on failure or when input_is_port_code_scalable returns 0 for the block. Nothing in the
 * firmware calls this routine.
 *
 * Phases:
 *   1. picture block register 0x2A and capture register 0x4A are saved; 0x2A is set to 0, bit 5 of 0x4A cleared;
 *   2. input_adc_adjust_aborted is cleared and the six present values are saved;
 *   3. the calibration steps of the mode run; a step that fails sets input_adc_adjust_aborted to 1;
 *   4. on failure the six saved values are written back;
 *   5. registers 0x2A and 0x4A get their saved values back.
 */
unsigned char input_adc_auto_color(port, mode)
unsigned int port;
unsigned char mode;
{
    unsigned char block = port;
    unsigned char saved[6];
    unsigned char saved_pq_2a, saved_capture_4a;

    if (!input_is_port_code_scalable(block))
        return 0;

    /* 1. Save and set the two block registers. */
    saved_pq_2a = pq_block_read8(block, 0x2a);
    saved_capture_4a = input_capture_read8(block, 0x4a);
    pq_block_write8(block, 0x2a, 0);
    input_capture_update_bits(block, 0x4a, 0x20, 0);

    /* 2. Clear the failure flag and save offsets 2..0 and levels 2..0. */
    input_adc_adjust_aborted = 0;
    saved[0] = input_adc_get_offset2();
    saved[1] = input_adc_get_offset1();
    saved[2] = input_adc_get_offset0();
    saved[3] = input_adc_get_level2();
    saved[4] = input_adc_get_level1();
    saved[5] = input_adc_get_level0();

    /* 3. The calibration steps. */
    if (first_steps(port, mode) == 1) {
        if (mode == 0) {
            if (!trim_levels(block))
                input_adc_adjust_aborted = 1;
        } else if (!input_adc_calibrate_levels(block))
            input_adc_adjust_aborted = 1;
    } else
        input_adc_adjust_aborted = 1;

    /* 4. Failure: put all six values back. */
    if (input_adc_adjust_aborted == 1) {
        input_adc_set_offset2(saved[0]);
        input_adc_set_offset1(saved[1]);
        input_adc_set_offset0(saved[2]);
        input_adc_set_level2(saved[3]);
        input_adc_set_level1(saved[4]);
        input_adc_set_level0(saved[5]);
    }

    /* 5. Restore the two block registers. */
    pq_block_write8(block, 0x2a, saved_pq_2a);
    input_capture_write8(block, 0x4a, saved_capture_4a);
    return input_adc_adjust_aborted == 0;
}
