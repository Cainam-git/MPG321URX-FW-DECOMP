/* input_block_restart_statistics  (FUN_a00f62ac)
 *
 * Restart the statistics measurement of an input block.
 * Name basis: descriptive - writes 0x2E or 0x6E to register 0x36; used by the automatic level control
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f62ac @ 0xa00f62ac-0xa00f6340, flags -mcpu=v8 -O3 -g.
 * Source form: nested ifs, the outer one on the low nibble, the inner one on flag_set, with the 0x2e write in both the
 *   inner then-arm and the outer else-arm (cross-jumping merges the calls); the outer else-arm call then has no
 *   jump after it at the first scheduling pass, so its argument moves stay below the nibble compare.
 *   The other matched functions of this file use -msoft-float; this one gives the same bytes without it.
 */
extern unsigned char input_capture_read8(unsigned char block, unsigned char reg);
extern void input_capture_write8(unsigned char block, unsigned char reg, unsigned char val);

#define STATS_CONTROL_REG 0x36
#define STATS_BUSY_BIT 0x02
#define STATS_FLAG_REG 0x9d
#define STATS_MODE_REG 0x04
#define STATS_MODE_MASK 0x0f
#define STATS_RESTART_CMD_0x2E 0x2e
#define STATS_RESTART_CMD_0x6E 0x6e

/*
 * Restart the statistics measurement of an input block.
 *
 * Returns 0 if the block's control register has the busy bit set (bit 1 of register 0x36);
 * in that case no write is performed. Otherwise reads the flag register (0x9d) and the mode
 * register (0x04). Writes a restart command to the control register: 0x6e when the low nibble
 * of the mode register is 0 or 1 and the flag register is zero, else 0x2e. Returns 1.
 */
int input_block_restart_statistics(unsigned char block)
{
    unsigned char flag_set;

    if (input_capture_read8(block, STATS_CONTROL_REG) & STATS_BUSY_BIT)
        return 0;
    flag_set = input_capture_read8(block, STATS_FLAG_REG) != 0;
    /* The low nibble of the mode register selects the restart command. */
    if ((input_capture_read8(block, STATS_MODE_REG) & STATS_MODE_MASK) <= 1) {
        if (flag_set)
            input_capture_write8(block, STATS_CONTROL_REG, STATS_RESTART_CMD_0x2E);
        else
            input_capture_write8(block, STATS_CONTROL_REG, STATS_RESTART_CMD_0x6E);
    } else
        input_capture_write8(block, STATS_CONTROL_REG, STATS_RESTART_CMD_0x2E);
    return 1;
}
