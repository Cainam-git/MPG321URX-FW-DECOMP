/* leon2m FUN_a0146dfc @ 0xa0146dfc-0xa0146e24 (10 words), flags -mcpu=v8 -O3 -g.
 * Code facts: returns 1 when FUN_a011996c(p) (u8, btst 0xff) is non-zero, else 0; the fw sets 0/1
 * per path and masks with 'and 1' at the join (a u8 flag 'return r & 1', same form as
 * FUN_a00d8034). p is a u8 param. The result is a 0/1 flag, not the callee's value.
 * Source form: _Bool gives other code. Aids: none.
 */
extern unsigned char FUN_a011996c(unsigned char);

unsigned char FUN_a0146dfc(unsigned char p)
{
    unsigned char r = 0;

    if (FUN_a011996c(p) != 0)
        r = 1;
    return r & 1;
}
