/* input_bring_up_check_free_run  (FUN_a00f04f8)
 *
 * Run the free-run calibration check of a port.
 * Name basis: proven - prints the FreeRun RST / ON fail / PASS / ON / OFF steps
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f04f8 @ 0xa00f04f8-0xa00f0b58 (408 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the reg 0x16 test is '(block_reg_read(block, 0x16) & 0xc) != 0 || value > 0x200' with the "ON Fail" arm
 *    first (the firmware keeps the 0x199ffc address in %i0 and 0xcf000000 in %i1 from 0xa00f0554 / 0xa00f0564
 *    into that arm at 0xa00f0720 / 0xa00f072c);
 *  - the OFF path clears input_free_run_on_counts, then input_free_run_start_ticks, then sets
 *    input_free_run_wait_ticks (stored as wait, on count, start at 0xa00f0910..0xa00f091c);
 *  - block_reg_update_bits has the form of pq_block_update_bits (pq_block_update_bits).
 */
extern int dbg_printf(const char *fmt, ...);
extern void input_block_wait_measure_cycle(unsigned char);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern const unsigned short input_bring_up_lane_regs[4];
extern unsigned char input_bring_up_lane, input_bring_up_port;
extern unsigned char input_free_run_fail_counts[2], input_free_run_on_counts[2];
extern unsigned short input_free_run_start_ticks[2], input_free_run_pass_ticks[2], input_free_run_wait_ticks[2];

/* Register reg of input block i: the block's base is input_bring_up_lane_regs[i]; the address is
   0xCF000000 | ((base + reg) * 4). */
#define MREG(i, o) (*(volatile unsigned int *)(0xcf000000 | ((input_bring_up_lane_regs[i] + (o)) << 2)))

#define FREE_RUN_RESET_WAIT_TICKS   0x32    /* wait after a restart before the first OFF step */
#define FREE_RUN_ON_DELAY_TICKS     0x32    /* time after the OFF step before the ON check is made */
#define FREE_RUN_RETRY_WAIT_TICKS   2       /* wait before the next OFF step after an ON check failed */
#define FREE_RUN_MAX_COUNT          5       /* more than this many failed OFF steps: give up; more than this many ON checks: pass */
#define FREE_RUN_VALUE_LIMIT        0x200   /* limit of the 24-bit value in registers 0xB..0xD */
#define FREE_RUN_REG0_BITS          0xa0    /* bits of register 0 that the OFF step sets and a failed ON check clears */
#define FREE_RUN_REG16_BITS         0xc     /* bits of register 0x16 that are tested and set */

/* Read register reg of input block `block` (a block number of 4 or more reads block 0). */
static unsigned char block_reg_read(unsigned char block, unsigned char reg)
{
    if (block >= 4)
        block = 0;
    return MREG(block, reg);
}

/* Set (set == 1) or clear the bits of `mask` in register reg of input block `block`; block 8 means all four
   blocks. Any other block of 4 or more changes nothing. */
static void block_reg_update_bits(unsigned char block, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;
    unsigned char value;

    if (block == 8) {
        for (i = 0; i < 4; i++) {
            value = MREG(i, reg);
            if (set == 1) value |= mask; else value &= ~mask;
            MREG(i, reg) = value;
        }
    } else if (block < 4) {
        value = MREG(block, reg);
        if (set == 1) value |= mask; else value &= ~mask;
        MREG(block, reg) = value;
    }
}

/*
 * Check, step by step, the free-run state of the input blocks of a port. The caller (input_channel_bring_up_task,
 * steps 6 and 7) calls it once with restart = 1 and then again with restart = 0 on each pass until it returns 1.
 *
 *   port      the port that is brought up. Ports 2 and 6 use input block 2 and counter slot 0; ports 3 and 7
 *             use block 3 and slot 1; every other port uses block 0 and slot 0. The slot selects the counters
 *             and time stamps below (input_free_run_*). The values read below come from the block of
 *             input_bring_up_port, the bit changes go to the block of this port.
 *   restart   1: print 'drv_FreeRun_CalibrationCheckRoutine RST', clear the failure count and the second time
 *             stamp, start the first wait (0x32 ticks) and return 0.
 *
 * Return value: 1 when the check is over (the ON check passed, or more than 5 OFF steps were made), 0 while it
 * is running.
 *
 * With restart = 0 the routine does one of these, in this order of testing:
 *  1. More than 5 OFF steps: print 'FreeRun Calibration Fail' three times, return 1.
 *  2. ON check, when more than 0x32 ticks have passed since input_free_run_pass_ticks and
 *     input_free_run_start_ticks is 0 (that is, after an OFF step):
 *       - register 0x16 & 0xC is not 0, or the 24-bit value of registers 0xD, 0xC, 0xB is above 0x200:
 *         print 'ON Fail', clear bits 0xA0 of register 0 and set bits 0xC of register 0x16 in the block, start
 *         input_free_run_start_ticks, clear input_free_run_pass_ticks, return 0;
 *       - otherwise, after more than 5 ON checks: print 'PASS', return 1;
 *       - otherwise print 'ON', count the check, return 0.
 *  3. OFF step, when more than input_free_run_wait_ticks ticks have passed since input_free_run_start_ticks
 *     and input_free_run_pass_ticks is 0: two measure cycles of the port, set bits 0xA0 of register 0 and bits 0xC
 *     of register 0x16 in the block, print 'OFF', clear the ON count and input_free_run_start_ticks, set the wait
 *     to 2 ticks, start input_free_run_pass_ticks, count the OFF step, return 0.
 *  4. Otherwise return 0 and wait.
 * The texts print the registers as _MISC_5116 (register 0x16) and _MISC_510D (the 24-bit value).
 */
unsigned char input_bring_up_check_free_run(unsigned char port, unsigned char restart)
{
    unsigned char block = 0;
    unsigned char slot = 0;
    unsigned int value_0d_0b;       /* registers 0xD, 0xC, 0xB of the block, 0xD the high byte */
    unsigned int value_0f_0e;       /* register 0xE with the high nibble of register 0xF above it */

    if (port == 2)
        block = 2;
    else if (port == 3) {
        block = 3;
        slot = 1;
    } else if (port == 6)
        block = 2;
    else if (port == 7) {
        block = 3;
        slot = 1;
    }
    if (restart) {
        dbg_printf("drv_FreeRun_CalibrationCheckRoutine RST\r\n");
        input_free_run_fail_counts[slot] = 0;
        input_free_run_pass_ticks[slot] = 0;
        input_free_run_start_ticks[slot] = timer_get_ticks16();
        input_free_run_wait_ticks[slot] = FREE_RUN_RESET_WAIT_TICKS;
        return 0;
    }
    value_0d_0b = (unsigned int)block_reg_read(input_bring_up_port, 0xd) << 16 | (unsigned int)block_reg_read(input_bring_up_port, 0xc) << 8 |
          block_reg_read(input_bring_up_port, 0xb);
    value_0f_0e = (block_reg_read(input_bring_up_port, 0xf) & 0xf0) << 8 | block_reg_read(input_bring_up_port, 0xe);
    if (input_free_run_fail_counts[slot] > FREE_RUN_MAX_COUNT) {
        dbg_printf("\033[1;31m!!!!!!!FreeRun Calibration Fail!!!!!!!\r\n\033[m");
        dbg_printf("\033[1;31m!!!!!!!FreeRun Calibration Fail!!!!!!!\r\n\033[m");
        dbg_printf("\033[1;31m!!!!!!!FreeRun Calibration Fail!!!!!!!\r\n\033[m");
        return 1;
    }
    if (timer_ticks_since(input_free_run_pass_ticks[slot]) > FREE_RUN_ON_DELAY_TICKS && input_free_run_start_ticks[slot] == 0) {
        /* ON check */
        if ((block_reg_read(block, 0x16) & FREE_RUN_REG16_BITS) != 0 || value_0d_0b > FREE_RUN_VALUE_LIMIT) {
            dbg_printf("(%d) ON Fail_MISC_5116 %x _MISC_510D %lx %d\r\n\033[m", block, block_reg_read(input_bring_up_lane, 0x16) & 0xc, value_0d_0b, input_free_run_fail_counts[slot]);
            block_reg_update_bits(block, 0, FREE_RUN_REG0_BITS, 0);
            block_reg_update_bits(block, 0x16, FREE_RUN_REG16_BITS, 1);
            input_free_run_start_ticks[slot] = timer_get_ticks16();
            input_free_run_pass_ticks[slot] = 0;
            return 0;
        }
        if (input_free_run_on_counts[slot] > FREE_RUN_MAX_COUNT) {
            dbg_printf("(%d) %d PASS_MISC_5116 %x _MISC_510D %lx %d\r\n\033[m", block, timer_ticks_since(input_free_run_pass_ticks[slot]), block_reg_read(input_bring_up_lane, 0x16) & 0xc,
                         value_0d_0b, input_free_run_fail_counts[slot]);
            return 1;
        }
        dbg_printf("(%d) %d ON_MISC_5116 %x _MISC_510D %lx %lx %d\r\n\033[m", block, input_free_run_on_counts[slot], block_reg_read(input_bring_up_lane, 0x16) & 0xc, value_0d_0b, value_0f_0e,
                     input_free_run_fail_counts[slot]);
        input_free_run_on_counts[slot]++;
        return 0;
    }
    if (timer_ticks_since(input_free_run_start_ticks[slot]) <= input_free_run_wait_ticks[slot] || input_free_run_pass_ticks[slot] != 0)
        return 0;
    /* OFF step */
    input_block_wait_measure_cycle(input_bring_up_port);
    input_block_wait_measure_cycle(input_bring_up_port);
    block_reg_update_bits(block, 0, FREE_RUN_REG0_BITS, 1);
    block_reg_update_bits(block, 0x16, FREE_RUN_REG16_BITS, 1);
    dbg_printf("\033[1;33m(%d) OFF_MISC_5116 %x _MISC_510D %lx %d %x\r\n\033[m", block, block_reg_read(block, 0x16) & 0xc, value_0d_0b, input_free_run_fail_counts[slot], value_0f_0e);
    input_free_run_on_counts[slot] = 0;
    input_free_run_start_ticks[slot] = 0;
    input_free_run_wait_ticks[slot] = FREE_RUN_RETRY_WAIT_TICKS;
    input_free_run_pass_ticks[slot] = timer_get_ticks16();
    input_free_run_fail_counts[slot]++;
    return 0;
}
