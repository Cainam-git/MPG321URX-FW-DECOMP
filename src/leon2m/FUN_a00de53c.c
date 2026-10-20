/* leon2m FUN_a00de53c @ 0xa00de53c-0xa00de578 (15 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf busy-wait: for i = 0 .. n-1 (unsigned, cmp/bcs), an inner loop of 64 passes
 * (j = 0x3f; addcc -1; bpos) whose body is two real 'nop' instructions. void, n unsigned int.
 * Required forms: the two nops in the inner body. Aid: the nops are inline asm
 * (__asm__ __volatile__("nop")), the same documented aid as FUN_a00de65c: they
 * are real fw instructions, not delay slots. No volatile, no other aids.
 */
void FUN_a00de53c(unsigned int n)
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
