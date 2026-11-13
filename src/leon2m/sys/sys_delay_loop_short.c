/* sys_delay_loop_short  (FUN_a00de53c)
 *
 * Wait in a loop of n times 64 passes.
 * Name basis: derived - nop loop; the delay unit of the memory training
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de53c @ 0xa00de53c-0xa00de578 (15 words), flags -mcpu=v8 -O2 -g.
 * Source form: the two nops in the inner body are inline asm (__asm__ __volatile__("nop")): they are real
 * firmware instructions, not delay slots. The inner counter runs from 0x3f down to 0 (64 passes). No volatile
 * and no other aids.
 */
/* Busy-wait: n rounds of 64 passes, each pass two nop instructions. Called from sys_ddr_delay and sys_ddr_delay_tens. */
void sys_delay_loop_short(unsigned int n)
{
    unsigned int i;
    int j;

    for (i = 0; i < n; i++) {
        j = 0x3f;
        do {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        } while (--j >= 0);
    }
}
