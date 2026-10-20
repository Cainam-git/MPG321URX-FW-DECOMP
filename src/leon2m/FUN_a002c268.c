/* leon2m FUN_a002c268 @ 0xa002c268-0xa002c284 (7 words).
 * Read-modify-write of the word at p: the bits set in mask take their value from v, the other bits are kept
 * (*p = (*p & ~mask) | (v & mask)). A leaf routine without a register window. The pointer is volatile: the store
 * stays out of the delay slot of retl, which holds a nop.
 */
void FUN_a002c268(volatile unsigned int *p, unsigned int v, unsigned int mask)
{
    v &= mask;
    *p = (*p & ~mask) | v;
}
