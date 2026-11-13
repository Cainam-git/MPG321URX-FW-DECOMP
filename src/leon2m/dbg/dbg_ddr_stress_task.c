/* dbg_ddr_stress_task  (FUN_a014d5f4)
 *
 * Run one step of the memory stress test and print its result table.
 * Note: In the printed table the rows under "PHY1" hold the results of stress unit 2 beside register values
 *   read from unit 1.
 * Name basis: proven - prints 'Stress Stop!' and the per-byte result table; called from the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014d5f4 @ 0xa014d5f4-0xa014dbf4 (384 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the 'dbg_ddr_is_stress_enabled() == 1' case is written first with the stop print in its else arm, and
 *    'dbg_ddr_get_stress_param() > dbg_ddr_stress_count' has the step code first and the finish print in its else
 *    arm (the two else arms 0xa014d60c..0xa014d77c and 0xa014d7a4..0xa014d8f0 are the last blocks at register
 *    renaming);
 *  - the table print is a static inline helper used twice; it and the step code read and write
 *    dbg_ddr_row_index / dbg_ddr_column_index directly (0xa014da08..0xa014dbe8), not through locals;
 *  - the format strings are literals: GCC emits them in the firmware order 0x1a7278..0x1a7308 ("\r\n" is the
 *    shared copy at 0xfefc0), and their label order sets the order of the string addresses loaded before the
 *    finish-path print loop (0xa014d7c4..0xa014d7cc).
 */

/* The four bytes of the test's state record (dbg_ddr_get_test_state_byte / _set_test_state_byte), which are
   also the arguments of dbg_ddr_run_test_step. */
enum {
    STATE_UNIT   = 0,       /* memory interface 0..2 as the stress test numbers them */
    STATE_BYTE   = 1,       /* data byte 0..3 */
    STATE_MODE   = 2,       /* 0: dbg_ddr_test_delay_offset, 1: dbg_ddr_test_second_setting */
    STATE_OFFSET = 3        /* offset, biased by 7 */
};

/* The offset steps of one data byte (dbg_ddr_advance_test_state): 6 down to 0, then 8 up to 14, then the next
   byte with 6 again. Offset 7 would leave the setting as it is and is skipped. */
#define OFFSET_NONE      7
#define OFFSET_DOWN_END  0      /* the step after it starts the upward sweep at 8 */
#define OFFSET_UP_END    0xe    /* the step after it moves on to the next byte */

#define TABLE_ROWS       8      /* rows 0..3: unit 0, bytes 0..3; rows 4..7: unit 2, bytes 0..3 */
#define TABLE_COLUMNS    4      /* 0 / 1: mode 0 down / up; 2 / 3: mode 1 down / up */
#define RESULT_NONE      0xff   /* table entry not written yet */

extern unsigned char dbg_ddr_stress_stopped;      /* 1 (its start value): no run in progress, the next step starts a
                                           new one; 0: a run is in progress */
extern unsigned int dbg_ddr_stress_count;
extern unsigned char dbg_ddr_zero_step_count;      /* steps in a row that returned 0, since the last non-zero step */
extern unsigned char dbg_ddr_row_index;
extern unsigned char dbg_ddr_column_index;
extern unsigned char dbg_ddr_result_table[8][4];
extern int dbg_printf(const char *fmt, ...);
extern unsigned char dbg_ddr_is_stress_enabled(void);
extern unsigned int dbg_ddr_get_stress_param(void);
extern void dbg_ddr_set_stress_enabled(unsigned char);
extern unsigned char dbg_ddr_phy_get_delay_c6_c7(unsigned char port, unsigned short sel);
extern unsigned char dbg_ddr_phy_get_reg_161(unsigned char port, unsigned short sel);
extern unsigned char dbg_ddr_get_test_state_byte(unsigned char i);
extern unsigned char dbg_ddr_run_test_step(unsigned char port, unsigned short sel, unsigned char mode, unsigned char x);
extern void dbg_ddr_set_test_state_byte(unsigned char i, unsigned char v);
extern void dbg_ddr_advance_test_state(void);
extern void dbg_ddr_reset_test_state(void);

/*
 * Print the result table: a "PHY<n> WDQ RDQ" title before rows 0 and 4 (n = row >> 2), then per row its byte
 * number (row & 3), the four entries, after entry 0 the 0xC6 / 0xC7 delay nibble and after entry 2 the setting
 * register 0x161..0x164 of interface row >> 2, byte row & 3.
 * Rows 4..7 hold the results of unit 2, but the register values beside them are read from unit 1 (row >> 2).
 * The test 'row == 8' never holds inside the loop.
 */
static inline void print_table(void)
{
    for (dbg_ddr_row_index = 0; dbg_ddr_row_index < TABLE_ROWS; dbg_ddr_row_index++) {
        if (dbg_ddr_row_index == 0 || dbg_ddr_row_index == 4 || dbg_ddr_row_index == 8)
            dbg_printf("PHY%d             WDQ                  RDQ\r\n", dbg_ddr_row_index >> 2);
        dbg_printf("          B%d  ", dbg_ddr_row_index & 3);
        for (dbg_ddr_column_index = 0; dbg_ddr_column_index < TABLE_COLUMNS; dbg_ddr_column_index++) {
            dbg_printf("%d     ", dbg_ddr_result_table[dbg_ddr_row_index][dbg_ddr_column_index]);
            if (dbg_ddr_column_index == 0)
                dbg_printf("0x%02X     ", dbg_ddr_phy_get_delay_c6_c7(dbg_ddr_row_index >> 2, dbg_ddr_row_index & 3));
            else if (dbg_ddr_column_index == 2)
                dbg_printf("0x%02X     ", dbg_ddr_phy_get_reg_161(dbg_ddr_row_index >> 2, dbg_ddr_row_index & 3));
        }
        dbg_printf("\r\n");
    }
}

/*
 * One step of the memory stress test, run on every pass of sys_main_loop_periodic_task.
 *
 * The test is switched on and given its parameter (the number of passes to run) through dbg_ddr_configure_stress.
 * One pass walks the state record through unit 0 and unit 2, test modes 0 and 1, data bytes 0..3 and, for each
 * byte, the offsets 6..0 and 8..14 (dbg_ddr_advance_test_state). Each step runs one measurement
 * (dbg_ddr_run_test_step) with the state's unit, byte, mode and offset.
 *
 * Phases while the test is on:
 *  1. Start of a run (dbg_ddr_stress_stopped is 1): print "reset level!", reset the state record, fill the table with
 *     0xFF, start at row 0, column 0.
 *  2. While fewer passes than the parameter are done:
 *     a. run the step; a result of 0 adds one to the count of such steps in a row (dbg_ddr_zero_step_count);
 *     b. a non-zero result ends the sweep: the table entry at the current row and column keeps the smaller of
 *        its value and that count, the table position moves on (see below), the count is cleared, and the
 *        offset is set so that the next step starts the upward sweep (after a downward one) or the next byte
 *        (after an upward one);
 *     c. move the state record on; when it is back at its start (unit 0, byte 0, mode 0, offset 6) one pass is
 *        complete: count it and print "pre_DDRStressCnt = <passes>".
 *  3. All passes done: print "Stress Finish!" and the table, switch the test off, mark the run ended and clear
 *     the pass count.
 * When the test is switched off during a run: print "Stress Stop!" and the table, mark the run ended and clear
 * the pass count.
 *
 * The table position walks in the same order as the state record (rows 0..3 columns 0 / 1, rows 0..3 columns
 * 2 / 3, rows 4..7 columns 0 / 1, rows 4..7 columns 2 / 3), but it moves only after a non-zero result. A sweep
 * whose steps all return 0 moves the state on without moving the table position. The arms for rows 8..11 are
 * never reached: the table has 8 rows.
 */
void dbg_ddr_stress_task(void)
{
    if (dbg_ddr_is_stress_enabled() == 1) {
        /* 1. A new run: start from a clean state and an empty table. */
        if (dbg_ddr_stress_stopped == 1) {
            dbg_printf("reset level!\r\n");
            dbg_ddr_reset_test_state();
            dbg_ddr_stress_stopped = 0;
            for (dbg_ddr_row_index = 0; dbg_ddr_row_index < TABLE_ROWS; dbg_ddr_row_index++)
                for (dbg_ddr_column_index = 0; dbg_ddr_column_index < TABLE_COLUMNS; dbg_ddr_column_index++)
                    dbg_ddr_result_table[dbg_ddr_row_index][dbg_ddr_column_index] = RESULT_NONE;
            dbg_ddr_row_index = 0;
            dbg_ddr_column_index = 0;
        }
        if (dbg_ddr_get_stress_param() > dbg_ddr_stress_count) {
            /* 2a. One measurement with the present state. */
            if (dbg_ddr_run_test_step(dbg_ddr_get_test_state_byte(STATE_UNIT), dbg_ddr_get_test_state_byte(STATE_BYTE), dbg_ddr_get_test_state_byte(STATE_MODE), dbg_ddr_get_test_state_byte(STATE_OFFSET)) == 0) {
                dbg_ddr_zero_step_count++;
            } else {
                /* 2b. The sweep ends here: keep the shortest run of zero results seen at this position. */
                if (dbg_ddr_result_table[dbg_ddr_row_index][dbg_ddr_column_index] > dbg_ddr_zero_step_count)
                    dbg_ddr_result_table[dbg_ddr_row_index][dbg_ddr_column_index] = dbg_ddr_zero_step_count;
                /* Next table position. */
                if (dbg_ddr_column_index == 0) {
                    dbg_ddr_column_index++;
                } else if (dbg_ddr_column_index == 1) {
                    /* Mode 0 of a byte done: next byte, or mode 1 of the unit's first byte. */
                    if (dbg_ddr_row_index < 3) {
                        dbg_ddr_row_index++;
                        dbg_ddr_column_index = 0;
                    } else if (dbg_ddr_row_index == 3) {
                        dbg_ddr_row_index -= 3;
                        dbg_ddr_column_index = 2;
                    } else if (dbg_ddr_row_index < 7) {
                        dbg_ddr_row_index++;
                        dbg_ddr_column_index = 0;
                    } else if (dbg_ddr_row_index == 7) {
                        dbg_ddr_row_index -= 3;
                        dbg_ddr_column_index = 2;
                    } else if (dbg_ddr_row_index < 11) {
                        dbg_ddr_row_index++;
                        dbg_ddr_column_index = 0;
                    } else if (dbg_ddr_row_index == 11) {
                        dbg_ddr_row_index -= 3;
                        dbg_ddr_column_index = 2;
                    }
                } else if (dbg_ddr_column_index < 3) {
                    dbg_ddr_column_index++;
                } else if (dbg_ddr_column_index == 3) {
                    /* Mode 1 of a byte done: next byte, the next unit's rows, or back to the start. */
                    if (dbg_ddr_row_index < 3) {
                        dbg_ddr_row_index++;
                        dbg_ddr_column_index = 2;
                    } else if (dbg_ddr_row_index == 3) {
                        dbg_ddr_row_index++;
                        dbg_ddr_column_index = 0;
                    } else if (dbg_ddr_row_index < 7) {
                        dbg_ddr_row_index++;
                        dbg_ddr_column_index = 2;
                    } else if (dbg_ddr_row_index == 7) {
                        dbg_ddr_row_index = 0;
                        dbg_ddr_column_index = 0;
                    } else if (dbg_ddr_row_index < 11) {
                        dbg_ddr_row_index++;
                        dbg_ddr_column_index = 2;
                    } else if (dbg_ddr_row_index == 11) {
                        dbg_ddr_row_index = 0;
                        dbg_ddr_column_index = 0;
                    }
                }
                dbg_ddr_zero_step_count = 0;
                /* Cut the sweep short: after a downward sweep go up next, after an upward one go to the next byte. */
                if (dbg_ddr_get_test_state_byte(STATE_OFFSET) < OFFSET_NONE)
                    dbg_ddr_set_test_state_byte(STATE_OFFSET, OFFSET_DOWN_END);
                else
                    dbg_ddr_set_test_state_byte(STATE_OFFSET, OFFSET_UP_END);
            }
            /* 2c. Next step; back at the start means one more pass is complete. */
            dbg_ddr_advance_test_state();
            if (dbg_ddr_get_test_state_byte(STATE_UNIT) == 0 && dbg_ddr_get_test_state_byte(STATE_BYTE) == 0 && dbg_ddr_get_test_state_byte(STATE_MODE) == 0 && dbg_ddr_get_test_state_byte(STATE_OFFSET) == 6) {
                dbg_ddr_stress_count++;
                dbg_printf("pre_DDRStressCnt = %ld\r\n", dbg_ddr_stress_count);
            }
        } else {
            /* 3. All passes done. */
            dbg_printf("Stress Finish!\r\n");
            print_table();
            dbg_ddr_set_stress_enabled(0);
            dbg_ddr_stress_stopped = 1;
            dbg_ddr_stress_count = 0;
        }
    } else if (dbg_ddr_stress_stopped == 0) {
        /* Switched off during a run. */
        dbg_printf("Stress Stop!\r\n");
        print_table();
        dbg_ddr_stress_stopped = 1;
        dbg_ddr_stress_count = 0;
    }
}
