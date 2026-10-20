/* leon2m FUN_a01327e0 @ 0xa01327e0-0xa0132850 (28 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a014b844.
 * Leaf with tail calls: FUN_a00fe1dc(1) for v 0, FUN_a00fe1dc(2) for v 1, FUN_a00fe1dc(3) for v 2 and 4; other
 * values do nothing. FUN_a0132770 is the same with FUN_a00fdf74.
 * Exact form: the callee is declared without a prototype (the argument is passed as int). With an unsigned char
 * prototype GCC keeps v in %g1 instead of %o0 and fills the first delay slot with the argument.
 */
extern void FUN_a00fe1dc();

void FUN_a01327e0(unsigned char v)
{
    switch (v) {
    case 0:
        FUN_a00fe1dc(1);
        break;
    case 1:
        FUN_a00fe1dc(2);
        break;
    case 2:
    case 4:
        FUN_a00fe1dc(3);
        break;
    }
}
