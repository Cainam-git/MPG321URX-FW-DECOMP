/* dbg_ddr_reset_test_state  (FUN_a01181a4)
 *
 * Reset the state record of the stress test.
 * Name basis: derived - record at 0xA8027A90: step 6, the rest cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01181a4, flags -mcpu=v8 -O2 -g.
 * The record is one object (its address is kept in a register and the bytes are stored by offset); the stores
 * run in the order offset, unit, result second, result first, mode, byte, which gives the firmware order.
 */

/* First offset step of every data byte. */
#define OFFSET_START 6

/* The state record of the stress test: the four values passed to dbg_ddr_run_test_step, in this order. */
struct ddr_test_state {
    unsigned char unit;     /* memory interface */
    unsigned char byte;     /* data byte 0..3 */
    unsigned char mode;     /* 0 or 1: which of the two measurements runs */
    unsigned char offset;   /* offset step, biased by 7 */
};
extern struct ddr_test_state dbg_ddr_test_state;
extern unsigned char dbg_ddr_result_first;
extern unsigned char dbg_ddr_result_second;

/*
 * Back to the start of a sweep: unit 0, byte 0, mode 0, offset OFFSET_START, and the two result bytes
 * (0xA802C98C, 0xA802C98D) cleared. Called by dbg_ddr_stress_task.
 */
void dbg_ddr_reset_test_state(void)
{
    dbg_ddr_test_state.offset = OFFSET_START;
    dbg_ddr_test_state.unit = 0;
    dbg_ddr_result_second = 0;
    dbg_ddr_result_first = 0;
    dbg_ddr_test_state.mode = 0;
    dbg_ddr_test_state.byte = 0;
}
