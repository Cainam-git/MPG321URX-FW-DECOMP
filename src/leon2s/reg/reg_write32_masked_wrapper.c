/* reg_write32_masked_wrapper  (FUN_a00615cc)
 *
 * Change the masked bits of a 32-bit register (out-of-line wrapper of reg_write32_masked).
 * Name basis: derived - body only forwards to reg_write32_masked; no direct caller (reached through a pointer
 *   or unused)
 *
 * Matching notes
 * --------------
 * FUN_a00615cc (leon2s 0xa00615cc-0xa00615dc, 16 bytes), flags -mcpu=v8 -Os -g.
 * Tail call (the nop after it is the -g line nop). Leaf form of a tail call: 'mov %o7, %g1; call; mov %g1, %o7'
 * leaves the return to the callee.
 */
extern void reg_write32_masked(volatile unsigned int *, unsigned int, unsigned int);

/* Call reg_write32_masked(reg, value, mask). No routine calls this wrapper. */
void reg_write32_masked_wrapper(volatile unsigned int *reg, unsigned int value, unsigned int mask)
{
    reg_write32_masked(reg, value, mask);
}
