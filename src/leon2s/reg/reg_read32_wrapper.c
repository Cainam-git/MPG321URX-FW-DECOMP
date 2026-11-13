/* reg_read32_wrapper  (FUN_a00615ac)
 *
 * Read a 32-bit hardware register (out-of-line wrapper of reg_read32).
 * Name basis: derived - body only forwards to reg_read32; no direct caller (reached through a pointer or
 *   unused)
 *
 * Matching notes
 * --------------
 * FUN_a00615ac (leon2s 0xa00615ac-0xa00615bc, 16 bytes), flags -mcpu=v8 -Os -g.
 * Tail call (the nop after it is the -g line nop). Leaf form of a tail call: 'mov %o7, %g1; call; mov %g1, %o7'
 * leaves the return to the callee.
 */
extern unsigned int reg_read32(volatile unsigned int *);

/* Return reg_read32(reg). No routine calls this wrapper. */
unsigned int reg_read32_wrapper(volatile unsigned int *reg)
{
    return reg_read32(reg);
}
