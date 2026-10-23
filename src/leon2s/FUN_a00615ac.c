/* FUN_a00615ac (leon2s 0xa00615ac-0xa00615bc, 16 bytes), flags -mcpu=v8 -Os -g.
 * Wrapper: returns FUN_a0061528(p) (tail call; the nop after it is the -g line nop).
 * Nothing in the image calls it. Leaf form of a tail call: 'mov %o7, %g1; call; mov %g1, %o7' leaves the return to
 * the callee.
 */
extern unsigned int FUN_a0061528(volatile unsigned int *);

unsigned int FUN_a00615ac(volatile unsigned int *p)
{
    return FUN_a0061528(p);
}
