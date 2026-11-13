/* reg_write32_wrapper  (FUN_a00615bc)
 *
 * Write a 32-bit hardware register (out-of-line wrapper of reg_write32).
 * Name basis: derived - body only forwards to reg_write32; no direct caller (reached through a pointer or
 *   unused)
 *
 * Matching notes
 * --------------
 * FUN_a00615bc (leon2s 0xa00615bc-0xa00615cc, 16 bytes), flags -mcpu=v8 -Os -g.
 * Tail call (the nop after it is the -g line nop). Leaf form of a tail call: 'mov %o7, %g1; call; mov %g1, %o7'
 * leaves the return to the callee.
 */
extern void reg_write32(volatile unsigned int *, unsigned int);

/* Call reg_write32(reg, value). No routine calls this wrapper. */
void reg_write32_wrapper(volatile unsigned int *reg, unsigned int value)
{
    reg_write32(reg, value);
}
