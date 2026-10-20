/* leon2m FUN_a00de578 @ 0xa00de578-0xa00de5c0 (18 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf busy-wait: for n rounds (unsigned, %o0), an inner loop of 64000 passes (j = 0..63999,
 * 'cmp j, 0xf9ff; bleu') whose body is two 'nop' instructions. No calls, no memory access.
 * The nops are inline asm (real instructions in the fw stream, as in src/leon2m/FUN_a00de65c.c).
 * Fix vs the autoc draft (77.78): the bound 63999 is a local set at the top of the outer loop body: the fw
 * builds it (sethi|or 0xf9ff) after the entry test, outside both loops; a literal bound is re-built inside
 * the inner loop (the volatile asm keeps loop.c from moving it), a bound set before the outer loop lands
 * before the entry test (88.89). Aids: none.
 */
void FUN_a00de578(unsigned int n)
{
    unsigned int i, j;

    i = 0;
    while (i < n) {
        unsigned int lim = 63999;
        j = 0;
        do {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
            j++;
        } while (j <= lim);
        i++;
    }
}
