/* leon2m FUN_a00e0774 @ 0xa00e0774-0xa00e0784 (4 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/4 mismatches.
 * Code facts: leaf sibling-call wrapper: FUN_a00e05d8(unit, reg, mask, val << shift) with
 * 5 params (sll %o4, %o3, %o3; mov %o7,%g1; call; mov %g1,%o7). void. Callers pass 5 args
 * (e.g. FUN_a00e2690: (unit, 0x215, 0xf0, 4, a)).
 * The shift count is the 4th parameter and the value the 5th. The built object has a trailing
 * alignment nop after the range (outside the function's 16 bytes). Aids: none.
 */
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00e0774(unsigned int unit, unsigned int reg, unsigned int mask, unsigned int shift,
                  unsigned int val)
{
    FUN_a00e05d8(unit, reg, mask, val << shift);
}
