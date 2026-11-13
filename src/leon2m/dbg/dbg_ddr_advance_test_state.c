/* dbg_ddr_advance_test_state  (FUN_a01181d4)
 *
 * Move the stress test on to its next step.
 * Name basis: derived - step byte counts down from 6, then up from 7 to 13, then the next port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01181d4 @ 0xa01181d4, flags -mcpu=v8 -O3 -g.
 * dbg_ddr_reset_test_state (dbg_ddr_reset_test_state) is defined here because GCC inlines it at -O3 (its own store of 6
 * to offset remains in the copy).
 * Source form: the "mode == 1" arm comes before the "mode != 1" arm; "unit == 2" and "unit == 1" are separate
 * ifs, each calling the helper (an || folds into a range test); the helper stores in the order unit,
 * dbg_ddr_result_second, dbg_ddr_result_first, byte, mode, offset.
 */

/* The state record of the stress test (read and written byte by byte through dbg_ddr_get_test_state_byte /
   dbg_ddr_set_test_state_byte, and passed to dbg_ddr_run_test_step in this order). */
struct ddr_test_state {
    unsigned char unit;     /* memory interface; the sweep starts at 0 and moves on to 2 */
    unsigned char byte;     /* data byte 0..3 */
    unsigned char mode;     /* 0 or 1: which of the two measurements runs */
    unsigned char offset;   /* offset step: 6 down to 0, then 8 up to 14; biased by 7 */
};
extern struct ddr_test_state dbg_ddr_test_state;
extern unsigned char dbg_ddr_result_first;
extern unsigned char dbg_ddr_result_second;

#define OFFSET_START     6      /* first offset of every data byte; 7 (no change) is skipped */
#define OFFSET_DOWN_END  0      /* after offset 0 the upward sweep starts at 8 */
#define OFFSET_UP_START  8
#define OFFSET_UP_END    13     /* an offset above this (14, the last one run) ends the data byte */
#define LAST_BYTE        3

/* Back to the start of a sweep: unit 0, byte 0, mode 0, offset 6, and the two result bytes
   (0xA802C98C, 0xA802C98D) cleared. */
void dbg_ddr_reset_test_state(void)
{
    dbg_ddr_test_state.unit = 0;
    dbg_ddr_result_second = 0;
    dbg_ddr_result_first = 0;
    dbg_ddr_test_state.byte = 0;
    dbg_ddr_test_state.mode = 0;
    dbg_ddr_test_state.offset = OFFSET_START;
}

/*
 * Advance the state record by one step. One data byte runs through the offsets 6, 5 ... 0, then 8, 9 ... 14.
 * After offset 14 the next data byte starts at offset 6. After byte 3 the mode changes and the bytes start
 * again at 0: mode 0 first, then mode 1. After mode 1 of unit 0 the sweep goes on with unit 2, mode 0; after
 * mode 1 of unit 2 (or of unit 1) the whole record is reset to its start, which is how the caller sees that
 * one pass is complete. If mode is 1 and the unit is none of 0, 1, 2, only the offset is set to 6.
 */
void dbg_ddr_advance_test_state(void)
{
    unsigned char offset = dbg_ddr_test_state.offset;

    if ((unsigned char)(offset - 1) <= 5) {
        dbg_ddr_test_state.offset = offset - 1;
    } else if (offset == OFFSET_DOWN_END) {
        dbg_ddr_test_state.offset = OFFSET_UP_START;
    } else if (offset <= OFFSET_UP_END) {
        dbg_ddr_test_state.offset = offset + 1;
    } else {
        /* The data byte is finished: next byte, or next mode, or next unit, or the start again. */
        if (dbg_ddr_test_state.byte < LAST_BYTE) {
            dbg_ddr_test_state.byte++;
        } else if (dbg_ddr_test_state.mode == 1) {
            if (dbg_ddr_test_state.unit == 0) {
                dbg_ddr_test_state.mode ^= 1;
                dbg_ddr_test_state.unit = 2;
                dbg_ddr_test_state.byte = 0;
            } else if (dbg_ddr_test_state.unit == 2) {
                dbg_ddr_reset_test_state();
            } else if (dbg_ddr_test_state.unit == 1) {
                dbg_ddr_reset_test_state();
            }
        } else {
            dbg_ddr_test_state.mode ^= 1;
            dbg_ddr_test_state.byte = 0;
        }
        dbg_ddr_test_state.offset = OFFSET_START;
    }
}
