/* dbg_ddr_set_test_state_byte  (FUN_a0118324)
 *
 * Store one byte of the stress test's state record.
 * Name basis: derived - record at 0xA8027A90
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118324, flags -mcpu=v8 -O3 -g.
 * Source form: both parameters are unsigned char; the selection is a switch.
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
 * Store value in field 'index' of the state record (0 unit, 1 byte, 2 mode, 3 offset); another index stores
 * nothing. Counterpart of dbg_ddr_get_test_state_byte. Called by dbg_ddr_stress_task.
 */
void dbg_ddr_set_test_state_byte(unsigned char index, unsigned char value)
{
    switch (index) {
    case 0:
        dbg_ddr_test_state.unit = value;
        break;
    case 1:
        dbg_ddr_test_state.byte = value;
        break;
    case 2:
        dbg_ddr_test_state.mode = value;
        break;
    case 3:
        dbg_ddr_test_state.offset = value;
        break;
    }
}
