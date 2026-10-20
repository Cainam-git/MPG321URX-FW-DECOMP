/* leon2s FUN_a00a73d4 @ 0xa00a73d4-0xa00a7408 (13 words).
 * Clears bit (bit & 31) of word (bit >> 5) of the word array at p; the clear twin of FUN_a00a73ac.
 * The mask goes through a stack slot (st/ld in a 112-byte leaf frame): the mask local is volatile.
 */
void FUN_a00a73d4(unsigned int bit, volatile unsigned int *p)
{
    volatile unsigned int m = 1 << (bit & 0x1f);

    p[bit >> 5] &= ~m;
}
