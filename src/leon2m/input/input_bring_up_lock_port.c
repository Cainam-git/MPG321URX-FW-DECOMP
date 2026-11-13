/* input_bring_up_lock_port  (FUN_a00f0b58)
 *
 * Bring a port's clock up with retries, then start the free-run check.
 * Name basis: proven - PLL auto-on retries with prints
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f0b58 @ 0xa00f0b58-0xa00f1100 (362 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the port test as four arms 2, 3, 6, 7 with the same bodies (the firmware's compare chain; '||' gives a
 *    different compare);
 *  - the lane clamp as the inlined helper lane_or_zero (the first use becomes a mask, the later ones branches,
 *    as in the firmware);
 *  - the 0x77/0x78 copy as a static helper used twice (the firmware has both copies inline), with the old
 *    0x52/0x53 value written straight into the print call (held in a variable, the 'or' operands swap).
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void pq_block_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char input_bring_up_step_reg51(unsigned char p, unsigned short cnt, unsigned char v);
extern void input_block_wait_measure_cycle(unsigned char);
extern int timer_sleep_ticks(int ms);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern const unsigned short input_bring_up_lane_regs[4];
extern unsigned char input_bring_up_clock_flag;
extern unsigned char input_bring_up_done_ports_3_7, input_bring_up_done_ports_2_6;
extern unsigned short input_bring_up_retry_count_ports_3_7, input_bring_up_retry_count_ports_2_6, input_bring_up_start_tick_ports_3_7, input_bring_up_start_tick_ports_2_6;

/* Register set of a lane (see input_bring_up_set_pixel_clock): register 'reg' of lane 'lane'. */
#define LANE_REG(lane, reg) (*(volatile unsigned int *)(0xcf000000 | ((input_bring_up_lane_regs[lane] + (reg)) << 2)))
#define LANE_OR_ZERO(x) lane_or_zero(x)
#define LANE_PLL_AUTO_ON   0xa0         /* lane register 0: bits 5 and 7 both set before 'PLL auto on' */

/* Registers of a picture block (pq_block_*); the port number is used as the block number. */
#define BLK_REG_52         0x52
#define BLK_REG_53         0x53
#define BLK_BLANK_MODE     0x54         /* bit 7 tested here */
#define BLK_REG_77         0x77
#define BLK_REG_78         0x78
#define BLK_COUNT_SELECT   0x88
#define BLK_FREE_RUN_BIT   0x20         /* bit 5 of BLK_COUNT_SELECT: set when "FreeRun" is printed */
#define BLK_REG_8E         0x8e         /* bit 0 step up / bit 1 step down of register 0x51 (input_bring_up_step_reg51) */
#define STEP_FLAGS         3

#define RETRY_LIMIT        300          /* passes; a count of 300 also ends the stepping series */
#define FIRST_PHASE_PASSES 0x95         /* phase 1 ends after this many passes once no step is asked for */
#define LOCK_SETTLE_TICKS  0x32         /* time the lock must hold before the free run starts */

/* Lanes 0..3 as they are; anything else reads lane 0. */
static int lane_or_zero(unsigned char lane)
{
    if (lane >= 4)
        lane = 0;
    return lane;
}

/* Print the old and the new value, and copy registers 0x78 (bits 0..6) / 0x77 into 0x53 / 0x52. */
static void copy_reg77_78_to_52_53(unsigned char port, char *fmt)
{
    unsigned short value_15bit;

    value_15bit = (pq_block_read8(port, BLK_REG_78) & 0x7f) << 8 | pq_block_read8(port, BLK_REG_77);
    dbg_printf(fmt, port, (pq_block_read8(port, BLK_REG_53) & 0x7f) << 8 | pq_block_read8(port, BLK_REG_52), value_15bit);
    pq_block_write8(port, BLK_REG_52, value_15bit);
    pq_block_write8(port, BLK_REG_53, value_15bit >> 8);
}

/*
 * One pass of the clock lock of a port during channel bring-up; the caller runs it again until the port's
 * done flag is set.
 *
 *   port  2, 3, 6 or 7; other ports return at once. Ports 2 and 6 share one set of variables and lane 2
 *         (input_bring_up_*_pair3, input_bring_up_start_tick_ports_2_6), ports 3 and 7 the other set and lane 3 (input_bring_up_*_pair2,
 *         input_bring_up_start_tick_ports_3_7).
 *
 * The step flags (bits 0..1 of BLK_REG_8E) ask for register 0x51 to be stepped up or down; each retry does that
 * step with input_bring_up_step_reg51, writes 3 to BLK_REG_8E and waits for one measure cycle.
 *
 * Phase 1 (while input_bring_up_clock_flag is 0; input_bring_up_set_pixel_clock clears it): retries print
 *   "1retry"; the phase ends (flag = 1, count = 0) after more than 0x95 passes without a step request, or after
 *   300 passes.
 * Phase 2: the port is done when no step is asked for and the free run is on, or after 300 passes. While the
 *   free run is on and a step is asked for, the free run is switched off and a retry made ("2retry"), and the
 *   start time is taken. While the free run is off: print lane registers 0 and 0x0B..0x0F; once lane register 0
 *   has bits 5 and 7 set ("PLL auto on") and more than 50 ticks have passed since the start time, wait one
 *   measure cycle and 5 ticks, switch the free run on ("FreeRun") and write 3 to BLK_REG_8E.
 * In both phases, ports 2 and 3 with bit 7 of BLK_BLANK_MODE clear also get the 0x77/0x78 copy ("Fail ?").
 *
 * Nothing here reads the input's frame rate.
 */
void input_bring_up_lock_port(unsigned char port)
{
    unsigned char *done_flag;
    unsigned short *retry_count, *start_tick;
    unsigned char lane, step_flags;

    if (port == 2) {
        done_flag = &input_bring_up_done_ports_2_6;
        retry_count = &input_bring_up_retry_count_ports_2_6;
        start_tick = &input_bring_up_start_tick_ports_2_6;
        lane = 2;
    } else if (port == 3) {
        done_flag = &input_bring_up_done_ports_3_7;
        retry_count = &input_bring_up_retry_count_ports_3_7;
        start_tick = &input_bring_up_start_tick_ports_3_7;
        lane = 3;
    } else if (port == 6) {
        done_flag = &input_bring_up_done_ports_2_6;
        retry_count = &input_bring_up_retry_count_ports_2_6;
        start_tick = &input_bring_up_start_tick_ports_2_6;
        lane = 2;
    } else if (port == 7) {
        done_flag = &input_bring_up_done_ports_3_7;
        retry_count = &input_bring_up_retry_count_ports_3_7;
        start_tick = &input_bring_up_start_tick_ports_3_7;
        lane = 3;
    } else
        return;
    step_flags = pq_block_read8(port, BLK_REG_8E);

    /* Phase 1. */
    if (input_bring_up_clock_flag == 0) {
        if (((step_flags & STEP_FLAGS) == 0 && *retry_count > FIRST_PHASE_PASSES) || *retry_count > RETRY_LIMIT - 1) {
            input_bring_up_clock_flag = 1;
            *retry_count = 0;
        }
        if ((step_flags & STEP_FLAGS) != 0 && *retry_count < RETRY_LIMIT) {
            dbg_printf("\033[1;31m1retry_%d %02X\r\n\033[m", *retry_count, step_flags);
            input_bring_up_step_reg51(port, *retry_count, step_flags);
            pq_block_write8(port, BLK_REG_8E, 3);
            input_block_wait_measure_cycle(port);
        }
        if (port != 6 && port != 7 && (pq_block_read8(port, BLK_BLANK_MODE) & 0x80) == 0)
            copy_reg77_78_to_52_53(port, "\033[1;32m[%02x]1Fail ? %d %d\r\n\033[m");
        (*retry_count)++;
        return;
    }

    /* Phase 2: done check, then a retry while the free run is on. */
    if (((step_flags & STEP_FLAGS) == 0 && (pq_block_read8(port, BLK_COUNT_SELECT) & BLK_FREE_RUN_BIT)) || *retry_count > RETRY_LIMIT - 1)
        *done_flag = 1;
    if ((step_flags & STEP_FLAGS) != 0 && (pq_block_read8(port, BLK_COUNT_SELECT) & BLK_FREE_RUN_BIT) && *retry_count < RETRY_LIMIT) {
        pq_block_update_bits(port, BLK_COUNT_SELECT, BLK_FREE_RUN_BIT, 0);
        dbg_printf("\033[1;31m2retry_%d %02X\r\n\033[m", *retry_count, step_flags);
        /* The step routine returns 1 when it made one of its counted steps: end the retries. */
        if (input_bring_up_step_reg51(port, *retry_count, step_flags))
            *retry_count = RETRY_LIMIT;
        if (port != 6 && port != 7 && (pq_block_read8(port, BLK_BLANK_MODE) & 0x80) == 0)
            copy_reg77_78_to_52_53(port, "\033[1;32m[%02x]2Fail ? %d %d\r\n\033[m");
        pq_block_write8(port, BLK_REG_8E, 3);
        input_block_wait_measure_cycle(port);
        *start_tick = timer_get_ticks16();
        (*retry_count)++;
    }
    if (pq_block_read8(port, BLK_COUNT_SELECT) & BLK_FREE_RUN_BIT)
        return;

    /* Free run off: wait for the lane's lock, then switch the free run on. The first print has four %02x
       but only two arguments. */
    dbg_printf("[%02x] 5100:%02x %02x %02x\r\n", lane, LANE_REG(LANE_OR_ZERO(lane), 0) & 0xff);
    dbg_printf("510B:%02x %02x %02x%02x %02x\r\n", LANE_REG(LANE_OR_ZERO(lane), 0xb) & 0xff, LANE_REG(LANE_OR_ZERO(lane), 0xc) & 0xff, LANE_REG(LANE_OR_ZERO(lane), 0xd) & 0xff,
                 LANE_REG(LANE_OR_ZERO(lane), 0xe) & 0xff, LANE_REG(LANE_OR_ZERO(lane), 0xf) & 0xff);
    if ((LANE_REG(LANE_OR_ZERO(lane), 0) & LANE_PLL_AUTO_ON) != LANE_PLL_AUTO_ON)
        return;
    dbg_printf("[%02x]PLL auto on : %d\r\n", port, timer_ticks_since(*start_tick));
    if (timer_ticks_since(*start_tick) <= LOCK_SETTLE_TICKS)
        return;
    input_block_wait_measure_cycle(port);
    timer_sleep_ticks(5);
    pq_block_update_bits(port, BLK_COUNT_SELECT, BLK_FREE_RUN_BIT, 1);
    dbg_printf("FreeRun\r\n");
    pq_block_write8(port, BLK_REG_8E, 3);
}
