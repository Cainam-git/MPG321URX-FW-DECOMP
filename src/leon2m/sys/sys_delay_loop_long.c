/* sys_delay_loop_long  (FUN_a00de578)
 *
 * Wait in a loop of n times 64,000 passes.
 * Name basis: derived - nop loop
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de578 @ 0xa00de578-0xa00de5c0 (18 words), flags -mcpu=v8 -O2 -g.
 * Source form: two nested counted for loops, the inner one with the literal bound 64000. The nops are inline
 * asm (real instructions in the firmware, as in power_core_sleep_sequence).
 */
/* Busy-wait: n rounds of 64000 passes, each pass two nop instructions. Called from sys_ddr_delay_short. */
void sys_delay_loop_long(unsigned int n)
{
    unsigned int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 64000; j++) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
    }
}
