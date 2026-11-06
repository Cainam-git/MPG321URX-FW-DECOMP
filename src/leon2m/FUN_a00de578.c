/* leon2m FUN_a00de578 @ 0xa00de578-0xa00de5c0 (18 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf busy-wait: for n rounds (unsigned, %o0), an inner loop of 64000 passes (j = 0..63999, 'cmp j,
 * 0xf9ff; bleu') whose body is two 'nop' instructions. No calls, no memory access.
 * The nops are inline asm (real instructions in the fw stream, as in src/leon2m/FUN_a00de65c.c).
 * Source form: two nested counted for loops, the inner one with the literal bound 64000.
 */
void FUN_a00de578(unsigned int n)
{
    unsigned int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 64000; j++) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
    }
}
