/* input_bring_up_set_pixel_clock  (FUN_a00ef1b0)
 *
 * Compute the pixel clock for the incoming timing and program it.
 * Name basis: proven - clock = horizontal total x vertical total x rate / 10, corrected by measurement
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ef1b0 @ 0xa00ef1b0-0xa00f0380 (1140 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * The float arithmetic is software floating point: the compiler calls the library routines __floatsisf,
 * __addsf3, __mulsf3, __divsf3, __fixunssfsi and __extendsfdf2 (at 0xa0155xxx).
 * Source forms the exact build depends on:
 *  - the lane writes are the inlined static helpers lane_write, lane_set_bits and lane_clear_bits: the firmware
 *    computes the value once, before the 'lane == 8' / 'lane < 4' test;
 *  - the nested 'if (hactive > 0xa00) if (blank_third < 0x1e)', the chained 'blank_third = hblank_part = ...',
 *    hsync_width loaded before hstart, the 480,000,000 dividend as the local 'source_clock', and the copy of
 *    registers 0x77/0x78 as '(.. & 0x7f) << 8 | ..' into an unsigned short with the high part an unsigned char;
 *  - blank_third_x2 is an unsigned short 'blank_third + blank_third' computed right after hblank_rest_half,
 *    before the register writes (with a call between the add and the zero extension, the compiler keeps the add
 *    instead of folding it into the shift, as the firmware does);
 *  - in the reported-timing arm 'htotal_wide = htotal' (unsigned int) right after the rounding, and htotal_wide
 *    is what goes to BLK_HTOTAL;
 *  - the mask of 'register 7 |= 0x80' is passed as (signed char)0x80: the firmware ORs with the sign-extended
 *    immediate -128 (same low byte; the store keeps only the low byte);
 *  - the 'register 0xF = 8' write uses lane_write_copy, whose loop body copies the value into a local before the
 *    address is formed; the firmware loads 8 before the address only in this one lane loop, while the loops for
 *    0x16, 0x98 and 6 form the address first (the lane_write form). Using the copy form in lane_write breaks
 *    those three;
 *  - powers_of_two is filled by the firmware's own memcpy of the ROM table, written as the explicit call.
 */
extern void *memcpy(void *dst, const void *src, int n);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void pq_block_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned int pq_block_read24_stable(unsigned char blk, unsigned char reg);
extern unsigned short input_block_measure_vfreq(unsigned char blk);
extern void timer_wait_frames(unsigned char frames, unsigned short rate);
extern void panel_set_pll_frequency(unsigned char ch, unsigned int freq);
extern void pq_block_show(unsigned char blk);
extern int abs(int);
extern int dbg_printf(const char *fmt, ...);
extern void timer_sleep_ticks(int ms);
extern const unsigned int input_clock_powers_of_two[17];
extern const unsigned short input_bring_up_lane_regs[4];
extern unsigned char input_bring_up_lane, input_bring_up_port;
extern unsigned char input_bring_up_clock_flag;
extern unsigned short input_bring_up_vactive, input_bring_up_hactive;

/* Registers of a picture block (pq_block_*); the port number is used as the block number. */
#define BLK_REG_50         0x50         /* 0x41 before the copy below, then 1 */
#define BLK_REG_51         0x51
#define BLK_REG_52         0x52
#define BLK_REG_53         0x53
#define BLK_REG_55         0x55
#define BLK_VTOTAL         0x5b
#define BLK_HTOTAL         0x5e
#define BLK_REG_61         0x61
#define BLK_ROW_0X30_SUM   0x62         /* same register pair as in the output timing (row +0x30 plus +0x32) */
#define BLK_ROW_0X30_SUM_2 0x6f
#define BLK_LINES          0x64
#define BLK_LINES_2        0x71
#define BLK_HBLANK_SUM     0x66
#define BLK_HBLANK_SUM_2   0x73
#define BLK_WIDTH          0x68
#define BLK_WIDTH_2        0x75
#define BLK_REG_77         0x77
#define BLK_REG_78         0x78
#define BLK_REG_7C         0x7c
#define BLK_COUNT_SELECT   0x88         /* bits 1..2: count for register 0x89; bit 5 cleared at the start */
#define BLK_COUNT          0x89         /* 24-bit reading */
#define BLK_REG_8E         0x8e
#define BLK_HBLANK_PART    0xa0
#define BLK_ROW_0X31       0xbe         /* same register as in the output timing */

#define ALL_LANES          8            /* input_bring_up_lane value: all four register sets */
#define LANE_COUNT         4

/* Register 'reg' of the register set of lane 'lane'. The four sets lie at 0xCF0145C0, 0xCF014640, 0xCF014540 and
   0xCF014400 (input_bring_up_lane_regs). */
#define LANE_REG(lane, reg) (*(volatile unsigned int *)(0xcf000000 | ((input_bring_up_lane_regs[lane] + (reg)) << 2)))

#define SETTLE_TICKS       0x32
#define SOURCE_CLOCK_HZ    480000000    /* printed as clk_source */
#define RATE_ONE           16777216.0f  /* 2^24: the rate registers hold the ratio as a 8.24 fixed-point value */
#define COUNT_WRAP         0x400000     /* 2^22, added to a reading taken as wrapped */

/* Write one register of the selected lane, or of all four lanes. */
static void lane_write(unsigned char reg, unsigned char value)
{
    unsigned char i;

    if (input_bring_up_lane == ALL_LANES) {
        for (i = 0; i < LANE_COUNT; i++)
            LANE_REG(i, reg) = value;
    } else if (input_bring_up_lane < LANE_COUNT)
        LANE_REG(input_bring_up_lane, reg) = value;
}

/* The same write; the value is copied into a local first (see the matching notes). */
static void lane_write_copy(unsigned char reg, unsigned char value)
{
    unsigned char i;

    if (input_bring_up_lane == ALL_LANES) {
        for (i = 0; i < LANE_COUNT; i++) {
            unsigned int copy = value;
            LANE_REG(i, reg) = copy;
        }
    } else if (input_bring_up_lane < LANE_COUNT)
        LANE_REG(input_bring_up_lane, reg) = value;
}

/* Set bits in one register of the selected lane(s); the register keeps only the low byte. */
static void lane_set_bits(unsigned char reg, unsigned int mask)
{
    unsigned char i;

    if (input_bring_up_lane == ALL_LANES) {
        for (i = 0; i < LANE_COUNT; i++)
            LANE_REG(i, reg) = (unsigned char)(LANE_REG(i, reg) | mask);
    } else if (input_bring_up_lane < LANE_COUNT)
        LANE_REG(input_bring_up_lane, reg) = (unsigned char)(LANE_REG(input_bring_up_lane, reg) | mask);
}

/* Keep only the bits of 'mask' in one register of the selected lane(s). */
static void lane_clear_bits(unsigned char reg, unsigned char mask)
{
    unsigned char i;

    if (input_bring_up_lane == ALL_LANES) {
        for (i = 0; i < LANE_COUNT; i++)
            LANE_REG(i, reg) = LANE_REG(i, reg) & mask;
    } else if (input_bring_up_lane < LANE_COUNT)
        LANE_REG(input_bring_up_lane, reg) = LANE_REG(input_bring_up_lane, reg) & mask;
}

/*
 * Program the pixel clock for the port being brought up (input_bring_up_port, lane input_bring_up_lane, both
 * set by input_set_bring_up_port) from the timing of its signal, correct it by a measurement, and, when asked,
 * set the lane's rate registers.
 *
 *   set_lane_rate        not 0: also do phase 5 below; 0: return after the corrected clock is programmed
 *   use_reported_timing  not 0: take the totals and sizes from the timing as they are;
 *                        0: scale the totals to the size in input_bring_up_hactive / input_bring_up_vactive
 *   timing               eight 16-bit values, as input_query_port_timing returns them from the input processor
 *                        (input_read_port_timing there): [0] horizontal total, [1] vertical total,
 *                        [2] horizontal sync width plus back porch, [3] the same vertically, [4] horizontal sync
 *                        width, [5] vertical sync width, [6] active width, [7] active lines
 *
 * Called from the channel bring-up state machine (input_channel_bring_up_task) with (1, 1, measured timing).
 *
 * Phases:
 *  1. preparation: block register 0x55 = 0, wait 50 ticks; the count divider is 2 for ports 6 and 7, else 8;
 *     lane register 0 = 0x16; bit 5 of BLK_COUNT_SELECT cleared;
 *  2. timing registers of the picture block: either the reported values (horizontal total rounded up to a
 *     multiple of 8), or the scaled totals with the horizontal blanking split into parts;
 *  3. first clock = horizontal total x vertical total x measured frame rate (tenths of a hertz) / 10, given to
 *     panel_set_pll_frequency with input_bring_up_lane as the generator number; block registers 0x61/0x50 set,
 *     the block's output switched on, and registers 0x7C/0x78/0x77 copied into 0x51..0x53;
 *  4. correction: the block counts for two frames; the expected count (total pixels / divider) over the
 *     measured count scales the clock, which is programmed again;
 *  5. lane rate registers (only with set_lane_rate): 480 MHz over the clock (brought below 480 MHz by halving)
 *     as a 2^24 fixed-point value into lane registers 4..7, the expected count - 1 into 1..3, its bit length into
 *     register 0, then fixed values and a width-derived value into 0x0E..0x16; input_bring_up_clock_flag is
 *     cleared and block register 0x8E set to 3.
 *
 * Nothing here limits or rejects the clock or the frame rate: the only comparisons on the clock are the 480 /
 * 960 / 1920 MHz steps of phase 5.
 */
void input_bring_up_set_pixel_clock(unsigned char set_lane_rate, unsigned char use_reported_timing, unsigned short *timing)
{
    unsigned int powers_of_two[17];
    unsigned char count_divider, i;
    unsigned short htotal, vtotal;
    unsigned int pixel_clock, expected_count, measured_count, rate_word;

    /* Phase 1: preparation. powers_of_two[i] = 2^(10 + i). */
    memcpy(powers_of_two, input_clock_powers_of_two, 0x44);
    pq_block_write8(input_bring_up_port, BLK_REG_55, 0);
    timer_sleep_ticks(SETTLE_TICKS);
    count_divider = 2;
    if ((unsigned char)(input_bring_up_port - 6) > 1)
        count_divider = 8;
    lane_write(0, 0x16);
    pq_block_update_bits(input_bring_up_port, BLK_COUNT_SELECT, 0x20, 0);

    /* Phase 2: timing registers of the picture block. */
    if (use_reported_timing) {
        unsigned short hstart, vstart, hsync_width, vsync_width, hactive, vactive;
        unsigned int htotal_wide;
        htotal = timing[0];
        if (htotal & 7)
            htotal = htotal / 8 * 8 + 8;
        htotal_wide = htotal;
        vtotal = timing[1];
        vactive = timing[7];
        vstart = timing[3];
        vsync_width = timing[5];
        hactive = timing[6];
        hsync_width = timing[4];
        hstart = timing[2];
        pq_block_write16(input_bring_up_port, BLK_VTOTAL, vtotal);
        pq_block_write16(input_bring_up_port, BLK_LINES, vactive);
        pq_block_write16(input_bring_up_port, BLK_LINES_2, vactive);
        pq_block_write16(input_bring_up_port, BLK_ROW_0X31, vsync_width);
        pq_block_write16(input_bring_up_port, BLK_ROW_0X30_SUM, vstart);
        pq_block_write16(input_bring_up_port, BLK_ROW_0X30_SUM_2, vstart);
        pq_block_write16(input_bring_up_port, BLK_HTOTAL, htotal_wide);
        pq_block_write16(input_bring_up_port, BLK_WIDTH, hactive);
        pq_block_write16(input_bring_up_port, BLK_WIDTH_2, hactive);
        pq_block_write16(input_bring_up_port, BLK_HBLANK_PART, hsync_width);
        pq_block_write16(input_bring_up_port, BLK_HBLANK_SUM, hstart);
        pq_block_write16(input_bring_up_port, BLK_HBLANK_SUM_2, hstart);
    } else {
        unsigned short hactive, vactive, blank_third, hblank_part, hblank_rest_half, blank_third_x2;

        /* Keep the reported total-to-active ratios at the stored size. The horizontal blanking is split into
           hblank_part (a third, at least 30 above 2560 pixels) and two halves of the rest; a third of it and
           twice that also go to BLK_ROW_0X31 and BLK_ROW_0X30_SUM. */
        hactive = input_bring_up_hactive;
        htotal = (timing[0] * hactive) / timing[6];
        vactive = input_bring_up_vactive;
        blank_third = hblank_part = (htotal - hactive) / 3;
        vtotal = (timing[1] * vactive) / timing[7];
        if (hactive > 0xa00)
            if (blank_third < 0x1e)
                hblank_part = 0x1e;
        hblank_rest_half = (htotal - hactive - hblank_part) >> 1;
        blank_third_x2 = blank_third + blank_third;
        pq_block_write16(input_bring_up_port, BLK_VTOTAL, vtotal);
        pq_block_write16(input_bring_up_port, BLK_LINES, vactive);
        pq_block_write16(input_bring_up_port, BLK_LINES_2, vactive);
        pq_block_write16(input_bring_up_port, BLK_ROW_0X31, blank_third);
        pq_block_write16(input_bring_up_port, BLK_ROW_0X30_SUM, blank_third_x2);
        pq_block_write16(input_bring_up_port, BLK_ROW_0X30_SUM_2, blank_third_x2);
        pq_block_write16(input_bring_up_port, BLK_HTOTAL, htotal);
        pq_block_write16(input_bring_up_port, BLK_WIDTH, hactive);
        pq_block_write16(input_bring_up_port, BLK_WIDTH_2, hactive);
        pq_block_write16(input_bring_up_port, BLK_HBLANK_PART, hblank_part);
        pq_block_write16(input_bring_up_port, BLK_HBLANK_SUM, hblank_rest_half);
        pq_block_write16(input_bring_up_port, BLK_HBLANK_SUM_2, hblank_rest_half);
    }

    /* Phase 3: first clock from the totals and the measured frame rate (tenths of a hertz). */
    pixel_clock = (float)htotal * (int)vtotal * (int)input_block_measure_vfreq(input_bring_up_port) / 10.0f;
    panel_set_pll_frequency(input_bring_up_lane, pixel_clock);
    pq_block_update_bits(input_bring_up_port, BLK_REG_61, 3, 1);
    pq_block_write8(input_bring_up_port, BLK_REG_50, 0x41);
    pq_block_show(input_bring_up_port);
    timer_sleep_ticks(SETTLE_TICKS);
    {
        /* Bits 4..7 of 0x7C plus 1 into 0x51; 0x78 bits 0..6 and 0x77 as a 15-bit value into 0x53 / 0x52. */
        unsigned char high_nibble;
        unsigned short value_15bit;
        high_nibble = pq_block_read8(input_bring_up_port, BLK_REG_7C) >> 4;
        value_15bit = (pq_block_read8(input_bring_up_port, BLK_REG_78) & 0x7f) << 8 | pq_block_read8(input_bring_up_port, BLK_REG_77);
        pq_block_write8(input_bring_up_port, BLK_REG_50, 1);
        pq_block_write8(input_bring_up_port, BLK_REG_51, high_nibble + 1);
        pq_block_write8(input_bring_up_port, BLK_REG_52, value_15bit);
        pq_block_write8(input_bring_up_port, BLK_REG_53, value_15bit >> 8);
    }

    /* Phase 4: count over two frames and correct the clock by expected / measured. */
    pq_block_update_bits(input_bring_up_port, BLK_COUNT_SELECT, 6, 1);
    expected_count = (unsigned int)(htotal * vtotal) / count_divider;
    timer_wait_frames(2, input_block_measure_vfreq(input_bring_up_port));
    measured_count = pq_block_read24_stable(input_bring_up_port, BLK_COUNT);
    /* A large expected count with a reading far below it: the counter has passed 2^22, add it back. */
    if (expected_count > 0x380000 && abs((int)(expected_count - measured_count)) > 0x200000)
        measured_count += COUNT_WRAP;
    pixel_clock = pixel_clock * ((float)expected_count / (float)measured_count);
    panel_set_pll_frequency(input_bring_up_lane, pixel_clock);
    pq_block_update_bits(input_bring_up_port, BLK_COUNT_SELECT, 6, 0);
    if (!set_lane_rate)
        return;

    /* Phase 5: the lane's rate registers. */
    dbg_printf("\033[1;31mp3mpll %lx\n\033[m", pixel_clock);
    if (pixel_clock > 479999999) {
        if (pixel_clock <= 959999999)
            pixel_clock >>= 1;
        else if (pixel_clock <= 1919999999)
            pixel_clock >>= 2;
        else
            pixel_clock >>= 3;
    }
    {
        unsigned int source_clock = SOURCE_CLOCK_HZ;
        float ratio = (float)source_clock / pixel_clock;
        dbg_printf("clk_source %lx p3mpll %lx Per_ratio %f\n", source_clock, pixel_clock, (double)ratio);
        rate_word = ratio * RATE_ONE;
    }
    dbg_printf("Rate %lx\n", rate_word);
    /* Bit 7 of register 7 is held set while the four bytes are written, then cleared. */
    lane_set_bits(7, (signed char)0x80);
    lane_write(4, rate_word & 0xff);
    lane_write(5, (rate_word >> 8) & 0xff);
    lane_write(6, (rate_word >> 16) & 0xff);
    lane_write(7, rate_word >> 24);
    lane_clear_bits(7, 0x7f);
    expected_count = (unsigned int)(htotal * vtotal) / count_divider - 1;
    lane_write(1, expected_count & 0xff);
    lane_write(2, (expected_count >> 8) & 0xff);
    lane_write(3, (expected_count >> 16) & 0xff);
    /* Register 0 = the number of bits of the count (10 at least, 27 above 2^26). */
    for (i = 0; i < 17; i++)
        if (powers_of_two[i] > expected_count)
            break;
    {
        unsigned char bit_length = i + 10;
        lane_write(0, bit_length);
    }
    lane_write(0x10, 0x98);
    lane_write_copy(0xf, 8);
    {
        /* The horizontal total / 32 (divider 8) or / 4 (divider 2): low byte into 0x0E, bits 8..11 into the
           top half of 0x0F. */
        unsigned int width_value = count_divider == 8 ? htotal >> 5 : htotal >> 2;
        lane_write(0xe, width_value & 0xff);
        lane_set_bits(0xf, (width_value & 0xf00) >> 4);
    }
    lane_write(0x11, 6);
    lane_set_bits(0x16, 0xc);
    lane_set_bits(0, 0x20);
    input_bring_up_clock_flag = 0;
    pq_block_write8(input_bring_up_port, BLK_REG_8E, 3);
}
