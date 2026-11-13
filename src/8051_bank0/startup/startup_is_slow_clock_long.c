/* startup_is_slow_clock_long  (FUN_CODE_18ab)
 *
 * Test the clock variant and return 0 as a 32-bit value.
 * Returns: 0
 * Name basis: descriptive - calls startup_is_slow_clock and returns 0 for both answers; no routine calls it
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: 'result = 0' in both arms.  The first arm's store is dropped after the jumps are laid out (R7 is
 * already 0), which leaves the firmware's 'JNC / SJMP' pair; the second arm keeps 'CLR A / MOV R7,A'.
 */
extern bit startup_is_slow_clock(void);

/* startup_is_slow_clock_long
 *
 * Calls startup_is_slow_clock and returns 0 as an unsigned long whatever it answers.  No code of the boot loader
 * calls or jumps to this routine.
 */
unsigned long startup_is_slow_clock_long(void)
{
    unsigned char result = 0;

    if (startup_is_slow_clock()) {
        result = 0;
    } else {
        result = 0;
    }
    return result;
}
