/* FUN_a014648c (leon2m 0xa014648c-0xa0146518, 140 bytes), flags -mcpu=v8 -O3 -g.
 * Dispatches on c: FUN_a011b3e8(sel, a) for c = 0 or 3, FUN_a011c998(a, v, sel) for c = 1, FUN_a011ca58(v, sel) for
 * c = 2, as tail calls; other c do nothing. Called by FUN_a008ef48. Source form: a switch with separate identical
 * calls for cases 0 and 3 (GCC merges them).
 */
extern void FUN_a011c998(unsigned char a, unsigned short v, unsigned char sel);
extern void FUN_a011ca58(unsigned short v, unsigned char sel);
extern void FUN_a011b3e8(unsigned char sel, unsigned char v);

void FUN_a014648c(unsigned char c, unsigned char a, unsigned short v, unsigned char sel)
{
    switch (c) {
    case 0:
        FUN_a011b3e8(sel, a);
        break;
    case 1:
        FUN_a011c998(a, v, sel);
        break;
    case 2:
        FUN_a011ca58(v, sel);
        break;
    case 3:
        FUN_a011b3e8(sel, a);
        break;
    }
}
