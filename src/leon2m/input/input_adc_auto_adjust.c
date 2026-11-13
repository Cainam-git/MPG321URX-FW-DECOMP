/* input_adc_auto_adjust  (FUN_a00f446c)
 *
 * Run the three-stage automatic adjustment of the analogue input stage.
 * Name basis: descriptive - gain search, width stepping and phase search; limited by line rate times sweep
 *   value; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f446c @ 0xa00f446c-0xa00f4e60 (637 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the width sweep and the width probes are plain for loops ('pass < MAX_SWEEP_PASSES', 'probe <= 3');
 *  - the width sweep has one exit test: the three range / line-rate failures set pass = SWEEP_FAILED and break,
 *    and after the loop 'if (pass == SWEEP_FAILED)' restores the width and sets input_adc_adjust_failed (the
 *    firmware's break edges jump straight to that block; the compare stays only on the exhausted-loop path);
 *  - the line-rate test is a static helper with the body of the firmware's own routine at 0xa00f4434:
 *    'input_block_measure_hfreq(block) * width > 2050000';
 *  - in choose_width_by_phase_spread the new phase is an unsigned char and the input_adc_phase_scan_count store is
 *    written inside each arm (the arm tails are merged into the join);
 *  - in find_flattest_phase the pending-change test is the first statement of the poll loop with its own arm
 *    '{ input_adc_adjust_aborted = 1; return 0; }', and the timeout exit has the same arm; the width sweep's wait
 *    helper is the same poll loop with 'break';
 *  - the progress tick before the width probes is 'if (input_adc_progress <= 99 && input_adc_cal_hooks != 0)';
 *  - width probes: phase_at_min loaded before phase_at_max, 'phase_at_min = 0' before 'phase_at_max = 0', both
 *    unsigned int; |best_width - worst_width| through abs();
 *  - phase scan: the order of the first assignments (best_phase, reading_1, reading_2, last_smoothed,
 *    best_change); 'phase = (phase - 1) & 0x3f' before the smoothing; the history shift 'reading_3 = reading_2;
 *    reading_2 = reading_1; reading_1 = reading'; scan_count read before input_adc_get_phase;
 *  - input_adc_get_line_width returns unsigned short, the widths are unsigned short, and
 *    'upper_bound = lower_bound + lower_bound' comes before the 'width <= lower_bound' test.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The caller's adjustment record; only this field is read here (field name as in input_adc_set_capture_offsets). */
struct adc_window_record { unsigned char pad00[0xc]; unsigned short sweep_lower_bound; };
extern unsigned char input_adc_adjust_aborted, input_adc_adjust_failed, input_adc_phase_scan_count, input_adc_phase_first, input_adc_phase_second, input_adc_progress;
/* The first entry of the calibration hook record: the progress hook, called with a number up to 100. */
extern void (*input_adc_cal_hooks)(unsigned char percent);
extern unsigned char input_is_port_code_scalable(unsigned char blk);
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned short input_capture_read16(unsigned char blk, unsigned char reg);
extern void input_capture_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned char input_adc_search_gain(unsigned char blk, struct adc_window_record *record);
extern unsigned short input_adc_get_line_width(void);
extern unsigned char input_adc_get_phase(void);
extern unsigned int input_adc_search_phase(unsigned char blk);
extern void input_adc_step_width_to_target(unsigned char blk, unsigned short v);
extern void input_adc_set_phase(unsigned char v);
extern unsigned int input_block_get_capture_hstart(unsigned char blk);
extern unsigned int input_block_get_capture_vstart(unsigned char blk);
extern unsigned short input_block_measure_hfreq(unsigned char blk);
extern unsigned char input_block_is_change_pending(unsigned char blk);
extern void input_block_reset_window_regs(unsigned char blk);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void timer_sleep_ticks(int ms);
extern int abs(int);

#define ANALOG_REG_114       R(0xcf020114)  /* bits 0..2 = 5: bit 7 of CAP_REG_4A is set */

#define BLK_REG_2A           0x2a   /* picture block register, 0 during the adjustment */

/* Capture block registers used here. */
#define CAP_MEASURE_CTRL     0x36   /* command register (see input_adc_search_gain / input_adc_search_phase) */
#define CAP_READING_40       0x40   /* read in the width sweep, value not used */
#define CAP_PHASE_READING_LO 0x43   /* 32-bit phase reading: pair 0x45 << 16 plus pair 0x43 */
#define CAP_PHASE_READING_HI 0x45
#define CAP_SWEEP_LOWER      0x47   /* gets the lower bound of the width sweep */
#define CAP_WIDTH_ADVICE     0x49   /* bits 6..7 direction, bits 0..5 step size */
#define CAP_REG_4A           0x4a   /* bit 7 set from ANALOG_REG_114 during the adjustment */

#define MEASURE_START        0x41   /* starts a measurement; bit 0 of CAP_MEASURE_CTRL stays set while it runs */
#define MEASURE_BUSY         1
#define PHASE_MEASURE_START  0x42   /* starts a phase reading; bit 1 stays set while it runs */
#define PHASE_MEASURE_BUSY   2
#define MEASURE_WAIT_TICKS   0x63   /* a wait is abandoned after this many timer ticks */

/* Direction field of CAP_WIDTH_ADVICE. */
#define WIDTH_DONE           0
#define WIDTH_UP             1      /* 2 and 3: down */

#define MAX_SWEEP_PASSES     0x20
#define SWEEP_FAILED         0xff
#define SWEEP_START_MARGIN   0x10   /* a width at or below the lower bound restarts at bound + 0x10 */
#define LINE_RATE_X_WIDTH_MAX 2050000  /* line rate (100 Hz units) x width: at most 205,000,000 per second */
#define PHASE_MASK           0x3f   /* sampling positions have six bits */
#define PROGRESS_LAST        99
#define PROGRESS_DONE        100
#define PROGRESS_TICKS       20     /* pause between two progress steps at the end */

/* Restore the two saved registers, then count the progress up to 100 (a pending change of the block stops the
   count and sets input_adc_adjust_aborted). Returns 0: every failure path ends here. */
static unsigned char finish_failed(unsigned char block, unsigned char saved_reg2a, unsigned char saved_reg4a)
{
  pq_block_write8(block, BLK_REG_2A, saved_reg2a);
  input_capture_write8(block, CAP_REG_4A, saved_reg4a);
  if (input_adc_cal_hooks == 0)
    return 0;
  while (input_adc_progress <= PROGRESS_LAST) {
    input_adc_cal_hooks(input_adc_progress++);
    timer_sleep_ticks(PROGRESS_TICKS);
    if (input_block_is_change_pending(block) == 1) {
      input_adc_adjust_aborted = 1;
      return 0;
    }
  }
  input_adc_cal_hooks(PROGRESS_DONE);
  return 0;
}

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

/* 1 when the measured line rate times the width is above LINE_RATE_X_WIDTH_MAX. */
static int line_rate_too_high(unsigned char block, unsigned short width)
{
    return (unsigned int)(input_block_measure_hfreq(block) * width) > LINE_RATE_X_WIDTH_MAX;
}

/*
 * Width sweep (phase 1): let the capture block advise the line width. Each pass measures (MEASURE_START) and
 * reads CAP_WIDTH_ADVICE: direction 0 ends the sweep, 1 raises the width by the step, 2 and 3 lower it. The width
 * must stay between the record's sweep_lower_bound and twice that, and line rate x width at or below
 * LINE_RATE_X_WIDTH_MAX; otherwise the original width is restored, input_adc_adjust_failed set and 0 returned.
 * After MAX_SWEEP_PASSES passes without direction 0 the sweep ends with 1 as well.
 */
static unsigned char adjust_line_width(unsigned char block, struct adc_window_record *record)
{
  unsigned short lower_bound, width, original_width, upper_bound;
  unsigned char pass, advice, direction, step;

  lower_bound = record->sweep_lower_bound;
  input_capture_write16(block, CAP_SWEEP_LOWER, lower_bound);
  width = original_width = input_adc_get_line_width();
  upper_bound = lower_bound + lower_bound;
  if (width <= lower_bound) {
    width = lower_bound + SWEEP_START_MARGIN;
    input_adc_step_width_to_target(block, width);
  }
  for (pass = 0; pass < MAX_SWEEP_PASSES; pass++) {
    input_block_reset_window_regs(block);
    input_capture_write8(block, CAP_MEASURE_CTRL, MEASURE_START);
    if (!wait_measure_done(block, MEASURE_BUSY)) {
      input_adc_step_width_to_target(block, original_width);
      return 0;
    }
    input_capture_read16(block, CAP_READING_40);
    advice = input_capture_read8(block, CAP_WIDTH_ADVICE);
    direction = (advice & 0xc0) >> 6;
    step = advice & 0x3f;
    if (direction == WIDTH_DONE)
      break;
    if (direction == WIDTH_UP) {
      width = width + step;
      if (width > upper_bound) {
        pass = SWEEP_FAILED;
        break;
      }
    } else if (direction > WIDTH_UP) {
      width = width - step;
      if (width < lower_bound) {
        pass = SWEEP_FAILED;
        break;
      }
    }
    if (line_rate_too_high(block, width)) {
      pass = SWEEP_FAILED;
      break;
    }
    input_adc_step_width_to_target(block, width);
  }
  if (pass == SWEEP_FAILED) {
    input_adc_step_width_to_target(block, original_width);
    input_adc_adjust_failed = 1;
    return 0;
  }
  return 1;
}

/*
 * Width probes (phase 2): try the widths base - 2 .. base + 1 around the current width and run the phase search
 * (input_adc_search_phase: spread between the largest and the smallest reading over 16 sampling positions) at
 * each. The width with the largest spread wins, rounded down to an even width unless the widths with the largest
 * and the smallest spread are neighbours; after rounding the phase search runs again there. Then the starting
 * phase for the phase scan: when the spread is below (horizontal start x vertical start) << 6, 0x18 after the position
 * of the smallest reading, with 0x20 positions to scan; otherwise 8 before the position of the largest reading,
 * with 0x10 positions (input_adc_phase_scan_count). Returns 0 when a phase search was abandoned.
 */
static unsigned char choose_width_by_phase_spread(unsigned char block)
{
  unsigned short base_width, width, best_width, worst_width, chosen_width;
  unsigned int spread, best_spread, worst_spread, spread_limit;
  unsigned char probe;
  unsigned int phase_at_min, phase_at_max;
  unsigned char phase;

  base_width = input_adc_get_line_width();
  phase_at_min = 0;
  best_width = base_width;
  phase_at_max = 0;
  worst_width = base_width;
  best_spread = 0;
  worst_spread = 0xffffffff;
  width = base_width - 2;
  for (probe = 0; probe <= 3; probe++) {
      input_adc_step_width_to_target(block, width);
      spread = input_adc_search_phase(block);
      if (input_adc_adjust_aborted == 1)
        return 0;
      if (best_spread < spread) {
        phase_at_min = input_adc_phase_first;
        phase_at_max = input_adc_phase_second;
        best_spread = spread;
        best_width = width;
      }
      if (worst_spread > spread) {
        worst_spread = spread;
        worst_width = width;
      }
    width++;
  }
  chosen_width = best_width;
  {
    int distance = abs(best_width - worst_width);
    if (distance != 1)
      chosen_width = best_width & ~1;
  }
  input_adc_step_width_to_target(block, chosen_width);
  if (best_width != chosen_width) {
    best_spread = input_adc_search_phase(block);
    phase_at_min = input_adc_phase_first;
    phase_at_max = input_adc_phase_second;
  }
  {
    unsigned short hstart = input_block_get_capture_hstart(block), vstart = input_block_get_capture_vstart(block);
    spread_limit = (hstart * vstart) << 6;
  }
  if (best_spread < spread_limit) {
    phase = (phase_at_min + 0x18) & PHASE_MASK;
    input_adc_phase_scan_count = 0x20;
  } else {
    phase = (phase_at_max - 8) & PHASE_MASK;
    input_adc_phase_scan_count = 0x10;
  }
  input_adc_set_phase(phase);
  return 1;
}

/*
 * Phase scan (phase 3): step the sampling position from the start phase through input_adc_phase_scan_count - 1
 * positions. Each pass waits for the running reading (PHASE_MEASURE_BUSY), sets the next position, starts the
 * next reading and collects the finished one, which belongs to the position before. The readings are smoothed
 * (1/4, 1/2, 1/4 over the last three); from the fourth pass on, the position where the smoothed value changes
 * least from the pass before is kept. The phase is then set one below that position. Returns 0 (with
 * input_adc_adjust_aborted set) when a wait is abandoned.
 */
static unsigned char find_flattest_phase(unsigned char block)
{
  unsigned char start_phase, scan_count, j, phase, finished, best_phase;
  unsigned int reading, reading_1, reading_2, smoothed, last_smoothed, change, best_change, reading_3;
  unsigned short start_ticks;

  scan_count = input_adc_phase_scan_count;
  start_phase = input_adc_get_phase();
  input_capture_write8(block, CAP_MEASURE_CTRL, PHASE_MEASURE_START);
  best_phase = 0;
  reading_1 = 0;
  reading_2 = 0;
  last_smoothed = 0;
  best_change = 0xffffffff;
  for (j = 1; j < scan_count; j++) {
    if (input_adc_progress <= PROGRESS_LAST && input_adc_cal_hooks != 0)
      input_adc_cal_hooks(input_adc_progress++);
    start_ticks = timer_get_ticks16();
    finished = 0;
    for (;;) {
      if (input_block_is_change_pending(block) == 1) {
        input_adc_adjust_aborted = 1;
        return 0;
      }
      if (!(input_capture_read8(block, CAP_MEASURE_CTRL) & PHASE_MEASURE_BUSY)) {
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
    phase = (start_phase + j) & PHASE_MASK;
    input_adc_set_phase(phase);
    input_capture_write8(block, CAP_MEASURE_CTRL, PHASE_MEASURE_START);
    reading = (input_capture_read16(block, CAP_PHASE_READING_HI) << 16) + input_capture_read16(block, CAP_PHASE_READING_LO);
    reading_3 = reading_2;
    reading_2 = reading_1;
    reading_1 = reading;
    /* The reading just collected was taken at the position before. */
    phase = (phase - 1) & PHASE_MASK;
    smoothed = (reading_1 >> 2) + (reading_2 >> 1) + (reading_3 >> 2);
    if (j > 3) {
      if (smoothed > last_smoothed)
        change = smoothed - last_smoothed;
      else
        change = last_smoothed - smoothed;
      if (change < best_change) {
        best_phase = phase;
        best_change = change;
      }
    }
    last_smoothed = smoothed;
  }
  input_adc_set_phase((best_phase - 1) & PHASE_MASK);
  return 1;
}

/*
 * Automatic adjustment of the analogue input on an input block: gain, line width and sampling phase.
 *
 *   block   input block
 *   record  adjustment record; +0x0C (sweep_lower_bound) bounds the width sweep, and the record is passed to
 *           input_adc_search_gain
 *
 * Returns 1 when all stages succeed, else 0. No routine of this firmware calls it directly and its address is
 * not stored as data. Progress goes to the progress hook (input_adc_cal_hooks) as numbers from 4 up to 100.
 *
 * Phases:
 *  0. preparation: return 0 at once when input_is_port_code_scalable says 0. Save picture block register 0x2A
 *     and CAP_REG_4A; register 0x2A = 0; bit 7 of CAP_REG_4A = (bits 0..2 of ANALOG_REG_114 are 5); clear
 *     input_adc_adjust_failed and input_adc_adjust_aborted;
 *  1. gain search (input_adc_search_gain), then the width sweep (adjust_line_width) when neither flag is set;
 *  2. width probes (choose_width_by_phase_spread);
 *  3. phase scan (find_flattest_phase);
 *  4. gain search again, progress counted up to 100, the two saved registers restored, return 1.
 * Any failure goes to finish_failed: the saved registers are restored, the progress counted up to 100, and 0
 * returned.
 *
 * The only rate this routine reads is the line rate in the width sweep's limit.
 */
unsigned char input_adc_auto_adjust(unsigned char block, struct adc_window_record *record)
{
  unsigned char saved_reg4a, saved_reg2a;

  /* Phase 0: preparation. */
  if (!input_is_port_code_scalable(block))
    return 0;
  input_adc_progress = 4;
  saved_reg2a = pq_block_read8(block, BLK_REG_2A);
  saved_reg4a = input_capture_read8(block, CAP_REG_4A);
  pq_block_write8(block, BLK_REG_2A, 0);
  if ((ANALOG_REG_114 & 7) == 5)
    input_capture_update_bits(block, CAP_REG_4A, 0x80, 1);
  else
    input_capture_update_bits(block, CAP_REG_4A, 0x80, 0);
  input_adc_adjust_failed = 0;
  input_adc_adjust_aborted = 0;

  /* Phase 1: gain, then line width. */
  if (!input_adc_search_gain(block, record))
    return finish_failed(block, saved_reg2a, saved_reg4a);
  if (input_adc_adjust_aborted == 0 && input_adc_adjust_failed == 0) {
    if (!adjust_line_width(block, record))
      return finish_failed(block, saved_reg2a, saved_reg4a);
  }
  if (input_adc_progress <= PROGRESS_LAST && input_adc_cal_hooks != 0)
    input_adc_cal_hooks(input_adc_progress++);

  /* Phases 2 and 3: width probes and phase scan. */
  if (!choose_width_by_phase_spread(block))
    return finish_failed(block, saved_reg2a, saved_reg4a);
  if (!find_flattest_phase(block))
    return finish_failed(block, saved_reg2a, saved_reg4a);

  /* Phase 4: gain again, then finish. */
  if (!input_adc_search_gain(block, record))
    return finish_failed(block, saved_reg2a, saved_reg4a);
  if (input_adc_cal_hooks != 0) {
    while (input_adc_progress <= PROGRESS_LAST) {
      input_adc_cal_hooks(input_adc_progress++);
      timer_sleep_ticks(PROGRESS_TICKS);
      if (input_block_is_change_pending(block) == 1) {
        input_adc_adjust_aborted = 1;
        goto restore;
      }
    }
    input_adc_cal_hooks(PROGRESS_DONE);
  }
restore:
  pq_block_write8(block, BLK_REG_2A, saved_reg2a);
  input_capture_write8(block, CAP_REG_4A, saved_reg4a);
  return 1;
}
