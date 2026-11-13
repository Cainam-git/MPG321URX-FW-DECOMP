/* sys_set_timed_ramp_step  (FUN_CODE_ba6d)
 *
 * Store the high/low levels of a ramp channel and compute its step.
 *   ch: channel
 *   hi: high level
 *   lo: low level
 * Name basis: derived - command 0x31; record 0xA735 used by sys_run_timed_ramp
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ba6d, OPTIMIZE(7,SPEED).
 * Source form: the pairs are a two-dimensional array [2][2]: Keil scales the row index with 'ADD A,ACC' and recomputes it
 * for each access (a struct of two bytes gives MUL AB, a flat array with 'ch * 2' a 16-bit index).
 */
extern unsigned char xdata sys_timed_limits[2][2];
extern unsigned char xdata sys_timed_steps[];
extern unsigned char xdata DAT_EXTMEM_a73b;

/*
 * sys_set_timed_ramp_step - store the two ends of the ramp of channel ch (ch above 1 is taken as 1) and compute its
 * step. sys_timed_limits[ch] = {hi, lo}. The step in sys_timed_steps[ch] is (hi - lo) / (rate * 5), at least 1,
 * where rate = bits 0..4 of XDATA 0xA73B (the rate of channel 1; 0 counts as 1).
 * Only caller: the command switch ipc_run_command, command 0x31. sys_run_timed_ramp uses the result.
 */
void sys_set_timed_ramp_step(unsigned char ch, unsigned char hi, unsigned char lo)
{
    unsigned char rate;

    if (ch > 1) ch = 1;
    sys_timed_limits[ch][1] = lo;
    sys_timed_limits[ch][0] = hi;
    rate = DAT_EXTMEM_a73b & 0x1f;
    if (rate == 0) rate = 1;
    sys_timed_steps[ch] = (unsigned int)(hi - lo) / (rate * 5);
    if (sys_timed_steps[ch] == 0) sys_timed_steps[ch] = 1;
}
