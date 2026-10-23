/* FUN_a00615cc (leon2s 0xa00615cc-0xa00615dc, 16 bytes), flags -mcpu=v8 -Os -g.
 * Wrapper: FUN_a0061540(p, v, m) (tail call; the nop after it is the -g line nop).
 * Nothing in the image calls it. Leaf form of a tail call: 'mov %o7, %g1; call; mov %g1, %o7' leaves the return to
 * the callee.
 */
extern void FUN_a0061540(volatile unsigned int *, unsigned int, unsigned int);

void FUN_a00615cc(volatile unsigned int *p, unsigned int v, unsigned int m)
{
    FUN_a0061540(p, v, m);
}
