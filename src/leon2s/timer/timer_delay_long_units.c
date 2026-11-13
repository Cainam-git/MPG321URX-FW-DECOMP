/* timer_delay_long_units  (FUN_a00b1794)
 *
 * Wait in an idle loop of n times 50,000 passes.
 * Name basis: proven - nop loop; used all over the input program
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1794 @ 0xa00b1794-0xa00b17e8 (84 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Both counters are halfwords. The inner limit is an unsigned int variable (gives the firmware's
 * 'cmp 50000; bcs').
 */
#define DELAY_PASSES_PER_UNIT 50000

/*
 * Busy wait: "units" outer passes of 50000 inner passes, each inner pass one nop.
 *   units: number of outer passes
 */
void timer_delay_long_units(unsigned short units)
{
    unsigned short i, j;
    unsigned int passes = DELAY_PASSES_PER_UNIT;

    for (i = 0; i < units; i++)
        for (j = 0; j < passes; j++)
            __asm__("nop");
}
