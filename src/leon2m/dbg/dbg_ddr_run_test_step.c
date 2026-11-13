/* dbg_ddr_run_test_step  (FUN_a0117f48)
 *
 * Run one measurement of the memory stress test on a memory interface.
 * Name basis: proven - saves registers, selects the port, runs one of the two tests, restores; called from the
 *   stress test task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0117f48 @ 0xa0117f48-0xa0118174 (139 words), flags -mcpu=v8 -O3 -g.
 * Source form: switch with case order 0, 2, 1 (decides the register names in the case blocks). The saved
 * registers are unsigned char locals, so only the low byte of each register is saved and written back.
 */
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char dbg_ddr_test_delay_offset(unsigned char unit, unsigned short byte, unsigned char offset);
extern unsigned char dbg_ddr_test_second_setting(unsigned char unit, unsigned short byte, unsigned char offset);
extern void pq_block8_start(void);
extern void pq_block8_stop(void);
extern void timer_sleep_ticks(int ticks);

#define R(a) (*(volatile unsigned int *)(a))

/* Registers saved, changed for the measurement and written back. */
#define CTRL_12E00      0xcf012e00      /* bit 0 set: picture block 8 is restarted at the end (pq_block8_start) */
#define REG_11BF8       0xcf011bf8      /* cleared during the measurement */
#define FRC_CTRL        0xcf011a00      /* cleared during the measurement */
#define REG_11800       0xcf011800      /* cleared during the measurement */
#define UNIT_SELECT_REG 0xcf013454      /* bits 4..7 pick the unit under test, bits 0..3 are kept */
#define REG_9BB8        0xcf009bb8      /* 0x59 during the measurement */
#define REG_12E60       0xcf012e60      /* 1 during the measurement */
#define REG_12E64       0xcf012e64      /* 0 during the measurement */
#define BLOCK0          0               /* block of pq_block_read8 / pq_block_write8 */
#define BLOCK0_REG_54   0x54            /* 0x31 during the measurement */

/* Values of UNIT_SELECT_REG bits 4..7 for unit 0, 1, 2 (the units are numbered as in the stress test). */
#define UNIT0_SELECT    0x10
#define UNIT1_SELECT    0x40
#define UNIT2_SELECT    0x20

#define MODE_DELAY_OFFSET   0   /* run dbg_ddr_test_delay_offset */
#define MODE_SECOND_SETTING 1   /* run dbg_ddr_test_second_setting */

/*
 * Run one measurement step of the memory stress test and give back its result byte.
 *   unit   memory interface 0, 1, 2 (as the stress test numbers them)
 *   byte   data byte 0..3
 *   mode   MODE_DELAY_OFFSET or MODE_SECOND_SETTING: which of the two measurements runs
 *   offset the offset of the step, biased by 7 (7 = unchanged)
 * unit, byte, mode and offset are the four bytes of the stress test's state record, in that order.
 * Order of work:
 *   1. save the low bytes of 0xCF012E00, 0xCF011BF8, FRC_CTRL and 0xCF011800, stop picture block 8, clear the
 *      last three registers and wait timer_sleep_ticks(0x14);
 *   2. save 0xCF013454 and put the unit's code into its bits 4..7 (a unit other than 0, 1, 2 leaves it alone);
 *   3. save 0xCF009BB8, register 0x54 of block 0, 0xCF012E60 and 0xCF012E64, then write 0x59, 0x31 (followed
 *      by timer_sleep_ticks(2)), 1 and 0 to them;
 *   4. run the measurement chosen by mode; any other mode runs none and the result is 0;
 *   5. stop picture block 8 again, wait timer_sleep_ticks(0x14), write every saved register back except
 *      0xCF012E00, and restart picture block 8 only when bit 0 of the saved 0xCF012E00 was set.
 */
unsigned char dbg_ddr_run_test_step(unsigned char unit, unsigned short byte, unsigned char mode, unsigned char offset)
{
    unsigned char saved_12e00, saved_11bf8, saved_frc_ctrl, saved_11800, saved_unit_select, saved_9bb8, saved_reg_54, saved_12e60, saved_12e64, result;

    saved_12e00 = R(CTRL_12E00);
    saved_11bf8 = R(REG_11BF8);
    saved_frc_ctrl = R(FRC_CTRL);
    saved_11800 = R(REG_11800);
    pq_block8_stop();
    R(REG_11BF8) = 0;
    R(FRC_CTRL) = 0;
    R(REG_11800) = 0;
    timer_sleep_ticks(0x14);
    saved_unit_select = R(UNIT_SELECT_REG);
    switch (unit) {
    case 0:
        R(UNIT_SELECT_REG) = (R(UNIT_SELECT_REG) & 0xf) | UNIT0_SELECT;
        break;
    case 2:
        R(UNIT_SELECT_REG) = (R(UNIT_SELECT_REG) & 0xf) | UNIT2_SELECT;
        break;
    case 1:
        R(UNIT_SELECT_REG) = (R(UNIT_SELECT_REG) & 0xf) | UNIT1_SELECT;
        break;
    }
    saved_9bb8 = R(REG_9BB8);
    saved_reg_54 = pq_block_read8(BLOCK0, BLOCK0_REG_54);
    saved_12e60 = R(REG_12E60);
    saved_12e64 = R(REG_12E64);
    R(REG_9BB8) = 0x59;
    pq_block_write8(BLOCK0, BLOCK0_REG_54, 0x31);
    timer_sleep_ticks(2);
    R(REG_12E60) = 1;
    R(REG_12E64) = 0;
    result = 0;
    if (mode == MODE_DELAY_OFFSET)
        result = dbg_ddr_test_delay_offset(unit, byte, offset);
    else if (mode == MODE_SECOND_SETTING)
        result = dbg_ddr_test_second_setting(unit, byte, offset);
    pq_block8_stop();
    timer_sleep_ticks(0x14);
    R(UNIT_SELECT_REG) = saved_unit_select;
    R(REG_9BB8) = saved_9bb8;
    pq_block_write8(BLOCK0, BLOCK0_REG_54, saved_reg_54);
    R(REG_12E60) = saved_12e60;
    R(REG_12E64) = saved_12e64;
    R(REG_11800) = saved_11800;
    R(FRC_CTRL) = saved_frc_ctrl;
    R(REG_11BF8) = saved_11bf8;
    if (saved_12e00 & 1)
        pq_block8_start();
    return result;
}
