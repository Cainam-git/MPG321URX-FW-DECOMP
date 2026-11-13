/* panel_correct_clock_second_step  (FUN_a01045a0)
 *
 * Measure the output and correct the clock (second step).
 * Name basis: derived - frame waits and repeated measurements; used by the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01045a0 @ 0xa01045a0-0xa0104a34 (1172 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the wrap fix is written in both arms of the status test (the firmware computes 'wrap_limit > 0x3FFFFF' in
 *    both arms and cross-jumps the rest); -msoft-float keeps 0x400000 inside the loop;
 *  - position is a short (gives 'cmp position, K; bg'), written 'position = remainder; position += ...'
 *    (the firmware's add operand order);
 *  - one 16-bit variable (htotal_avg) holds the loop sum and then the average, '(htotal_avg + 2) >> 2';
 *  - remainder16 holds a copy of remainder for 'correction = target - remainder16' (correction is a short, so
 *    only the low 16 bits count);
 *  - the four counters are cleared in the for header, pass first (the firmware's clear order);
 *  - the declaration order of the locals is significant (register allocation ties go by declaration order).
 */

#define GPLL_DISPM         0               /* clock generator of the main display output */

/* Registers of a picture block. */
#define BLK_REG_50         0x50
#define BLK_BLANK_MODE     0x54         /* blanking mode (see pq_block_blank) */
#define BLK_HTOTAL         0x5e
#define BLK_LINES          0x64
#define BLK_LINES_2        0x71
#define BLK_HTOTAL_READBACK 0x82        /* a horizontal total read back from the block */
#define BLK_REG_86         0x86
#define BLK_COUNT_SELECT   0x88         /* selects what register 0x89 reads: 6 or 2 */
#define BLK_COUNT          0x89         /* 24-bit reading */

#define COUNT_WRAP         0x400000     /* the reading wraps past 22 bits */
#define MEASURE_PASSES     4

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row { unsigned int flags; unsigned short half_0x04; unsigned char display_mode, bpc; unsigned short active_size0; unsigned short active_size1; };
extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned char panel_clock_saved_reg50, panel_clock_saved_reg88, panel_clock_saved_reg86;
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short pq_block_read16(unsigned char blk, unsigned char reg);
extern void pq_block_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short pq_block_read16_stable(unsigned char blk, unsigned char reg);
extern unsigned int pq_block_read24_stable(unsigned char blk, unsigned char reg);
extern void timer_wait_frames(unsigned char frames, unsigned short rate);
extern unsigned char input_block_get_status_bit2(unsigned char);
extern void panel_set_pll_frequency(unsigned char ch, unsigned int freq);
extern void timer_sleep_ticks(int ms);

/*
 * Second clock correction after a channel's output is set up: measure four times, correct the pixel clock and
 * the horizontal total, and put back the block registers that panel_correct_clock_first_step saved.
 *
 *   port          the channel's port: the picture block
 *   pixel_clock   the channel's output pixel clock in Hz (output timing +0x18); corrected in place
 *   refresh_rate  the input's refresh rate in tenths of a hertz, for the frame waits
 *
 * Called from input_channel_bring_up_task (state 8, step 4), one step after panel_correct_clock_first_step.
 *
 * Each of the four passes adds up the horizontal total read back (register 0x82) and two readings of register
 * 0x89, one with 0x88 = 6 and one with 0x88 = 2. With status bit 2 of the input block set, the first reading is
 * the mean of two readings one frame apart, read again up to three more times while the two lie within 15 of
 * each other. A reading below the panel's active width * lines / 8, when that is above 0x3FFFFF, has wrapped
 * and gets 0x400000 added.
 *
 * The mean horizontal total becomes the block's new horizontal total; when it is odd it is lowered by one and
 * the clock scaled down with it. The clock goes to the main display clock generator (GPLL_DISPM).
 * A mean of 0, or a first sum of 0, stops here for good (endless wait instead of a division by zero).
 */
void panel_correct_clock_second_step(unsigned char port, unsigned long long *pixel_clock, unsigned short refresh_rate)
{
    unsigned short block_lines;
    unsigned short htotal_avg;
    short correction;
    unsigned short quotient;
    unsigned int remainder;
    unsigned short remainder16;
    unsigned long long clock_step;
    unsigned int sum_first;
    short target;
    short position;
    unsigned int reading_b;
    int diff;
    unsigned char i;
    unsigned short remainder_second;
    unsigned int reading_a;
    unsigned char pass;
    unsigned int reading;
    unsigned int sum_second;
    short fraction;
    unsigned int wrap_limit;

    block_lines = pq_block_read16(port, BLK_LINES_2);
    wrap_limit = (unsigned int)(panel_working_row_ptr->active_size1 * panel_working_row_ptr->active_size0) >> 3;
    timer_sleep_ticks(100);
    for (pass = 0, htotal_avg = 0, sum_first = 0, sum_second = 0; pass < MEASURE_PASSES; pass++) {
        pq_block_write8(port, BLK_COUNT_SELECT, 6);
        timer_wait_frames(1, refresh_rate);
        htotal_avg += pq_block_read16_stable(port, BLK_HTOTAL_READBACK);
        if (input_block_get_status_bit2(port)) {
            reading_a = pq_block_read24_stable(port, BLK_COUNT);
            timer_wait_frames(1, refresh_rate);
            reading_b = pq_block_read24_stable(port, BLK_COUNT);
            for (i = 0; (diff = reading_a - reading_b) >= -15 && diff <= 15 && i < 3; i++) {
                reading_a = pq_block_read24_stable(port, BLK_COUNT);
                timer_wait_frames(1, refresh_rate);
                reading_b = pq_block_read24_stable(port, BLK_COUNT);
            }
            reading = (reading_a + reading_b) >> 1;
            if (wrap_limit > 0x3fffff && reading < wrap_limit) reading += COUNT_WRAP;
        } else {
            reading = pq_block_read24_stable(port, BLK_COUNT);
            if (wrap_limit > 0x3fffff && reading < wrap_limit) reading += COUNT_WRAP;
        }
        sum_first += reading;
        pq_block_write8(port, BLK_COUNT_SELECT, 2);
        sum_second += pq_block_read24_stable(port, BLK_COUNT);
    }
    htotal_avg = (htotal_avg + 2) >> 2;         /* rounded mean of the four */
    if (htotal_avg == 0) for (;;) timer_sleep_ticks(1);
    if (sum_first == 0) for (;;) timer_sleep_ticks(1);
    remainder_second = (sum_second * 2) % block_lines;
    fraction = (unsigned int)(block_lines * 9 - remainder_second * 10) / 10;
    quotient = (sum_first * 2) / htotal_avg;
    remainder = (sum_first * 2) % htotal_avg;
    position = remainder; position += fraction * quotient / block_lines;
    remainder16 = remainder;
    /* The target: the first of 9/6, 7/6, 5/6, 3/6, 1/6, -1/6, -3/6 of the mean horizontal total that position
       exceeds; when it exceeds none, 1/6. */
    if (position > htotal_avg * 9 / 6) target = htotal_avg * 9 / 6;
    else if (position > htotal_avg * 7 / 6) target = htotal_avg * 7 / 6;
    else if (position > htotal_avg * 5 / 6) target = htotal_avg * 5 / 6;
    else if (position > htotal_avg * 3 / 6) target = htotal_avg * 3 / 6;
    else if (position > htotal_avg / 6) target = htotal_avg / 6;
    else if (position > -(htotal_avg / 6)) target = -(htotal_avg / 6);
    else if (position > -(htotal_avg * 3 / 6)) target = -(htotal_avg * 3 / 6);
    else target = htotal_avg / 6;
    correction = target - remainder16;
    clock_step = *pixel_clock * correction / quotient / htotal_avg;
    *pixel_clock += (int)clock_step;
    /* The horizontal total is kept even. */
    if (htotal_avg & 1) {
        *pixel_clock = *pixel_clock / htotal_avg * (htotal_avg - 1);
        htotal_avg--;
        pq_block_write16(port, BLK_HTOTAL, htotal_avg);
    } else
        pq_block_write16(port, BLK_HTOTAL, htotal_avg);
    panel_set_pll_frequency(GPLL_DISPM, *pixel_clock);
    /* Blanking mode 2; the registers the first step saved go back, the line register gets the row's lines. */
    pq_block_write8(port, BLK_BLANK_MODE, 2);
    pq_block_write8(port, BLK_REG_86, panel_clock_saved_reg86);
    pq_block_write8(port, BLK_REG_50, panel_clock_saved_reg50);
    pq_block_write16(port, BLK_LINES, panel_working_row_ptr->active_size1);
    pq_block_write8(port, BLK_COUNT_SELECT, panel_clock_saved_reg88);
}
