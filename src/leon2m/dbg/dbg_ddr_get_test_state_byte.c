/* dbg_ddr_get_test_state_byte  (FUN_a01182cc)
 *
 * Return one byte of the stress test's state record.
 * Returns: byte
 * Name basis: derived - record at 0xA8027A90
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01182cc, flags -mcpu=v8 -O2 -g.
 * Source form: the index is an unsigned char; the selection is a switch (signed compare chain after promotion).
 */

/* The state record of the stress test: the four values passed to dbg_ddr_run_test_step, in this order. */
struct ddr_test_state {
    unsigned char unit;     /* memory interface */
    unsigned char byte;     /* data byte 0..3 */
    unsigned char mode;     /* 0 or 1: which of the two measurements runs */
    unsigned char offset;   /* offset step, biased by 7 */
};
extern struct ddr_test_state dbg_ddr_test_state;

/*
 * Return field 'index' of the state record: 1 byte, 2 mode, 3 offset; unit for 0 and for every other index.
 * Called by dbg_ddr_stress_task.
 */
unsigned char dbg_ddr_get_test_state_byte(unsigned char index)
{
    unsigned char value;

    switch (index) {
    case 1:
        value = dbg_ddr_test_state.byte;
        break;
    case 2:
        value = dbg_ddr_test_state.mode;
        break;
    case 3:
        value = dbg_ddr_test_state.offset;
        break;
    default:
        value = dbg_ddr_test_state.unit;
        break;
    }
    return value;
}
