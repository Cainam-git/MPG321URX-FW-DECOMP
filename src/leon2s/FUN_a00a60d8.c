/*
 * FUN_a00a60d8 (leon2s, 0xa00a60d8-0xa00a610c, 52 bytes, leaf with sibcall), flags -mcpu=v8 -Os -g.
 * FUN_a00b1508(rec[p].a, rec[p].b, 0x18) on a table of 12-byte records whose base symbol is 0xa807dc04
 * (firmware 'or %g1, 4' base, then [base + p*12] and [+4]). A 0xa807dc00-based array with the fields at
 * +4/+8 gives a different add order, so the array starts at 0xa807dc04. Other src/leon2s files declare
 * DAT_a807dc04 as 'struct Cfg *' (word 0 of record 0 = a pointer), which fits. An int-index form reads the
 * same words. Tail call via the leaf 'mov %o7,%g1' sibcall.
 */
struct rec12 { unsigned int a; unsigned int b; unsigned int c; };
extern struct rec12 DAT_a807dc04[];
extern void FUN_a00b1508(unsigned int, unsigned int, unsigned int);

void FUN_a00a60d8(unsigned char param_1)
{
    FUN_a00b1508(DAT_a807dc04[param_1].a, DAT_a807dc04[param_1].b, 0x18);
}
