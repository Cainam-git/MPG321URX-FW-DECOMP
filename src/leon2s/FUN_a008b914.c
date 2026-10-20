/*
 * FUN_a008b914 (leon2s, 0xa008b914-0xa008b930, 28 bytes, leaf sibcall), flags -mcpu=v8 -Os -g.
 * Code facts: FUN_a00b1e30(4) when param_1 == 0, else FUN_a00b1e30(6), as one crossjumped leaf tail call
 * (mov %o7,%g1 / call / mov %g1,%o7). Written as two calls with the == 0 arm first; a value variable or a
 * ternary becomes branch-free arithmetic (23-33), the != 0 arm first gives 75.00.
 * Aids: none.
 */
extern void FUN_a00b1e30(unsigned int);

void FUN_a008b914(unsigned char param_1)
{
    if (param_1 == 0)
        FUN_a00b1e30(4);
    else
        FUN_a00b1e30(6);
}
