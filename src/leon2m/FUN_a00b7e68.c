/* leon2m FUN_a00b7e68 @ 0xa00b7e68-0xa00b7f9c (77 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a00ab5f0(0x2c, 6, p2 & 0xff, 6, p1 & 0xff);
 * p1 != 0 -> v = 0x742, FUN_a00a9468(1, 3); else v = 0x792, FUN_a00a9468(1, 2) (u16 v; the
 * zero-extension shows as 'and %l0, 0x7d2' = nonzero bits of both constants). Then
 * FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1, v, 0) with FUN_a0146b20(0, 0x2b/0x32, 6, 1, 0x3f/0x40, 0)
 * after the 2nd and 3rd; FUN_a0146b50(0xe6, 0); FUN_a01577f4(buf[8] at %fp-16, 0x1981d0, p3 & 0xff);
 * buf[0] = 3; FUN_a0146b6c(2, 0); FUN_a00a31a4(0, 0x28, 6, 2, buf, 0).
 * Fix vs the autoc draft (97.40, schedule of 'mov 0x742'): v is assigned in BOTH arms
 * ('v = 0x742' in the != 0 arm) instead of a default before the if. Aids: none.
 */
// FUN_a00b7e68 at 0xa00b7e68
extern void FUN_a0146b50(unsigned int, unsigned char);
extern void FUN_a00ab5f0(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned char);
extern void FUN_a0146b6c(unsigned int, unsigned int);
extern void FUN_a00a31a4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

void FUN_a00b7e68(unsigned int param_1, unsigned char param_2, unsigned char param_3)
{
    unsigned short uVar1;
    unsigned char local_10[8];

    FUN_a0146b50(0x111, 0);
    FUN_a00ab5f0(0x2c, 6, param_2, 6, param_1 & 0xff);

    if ((param_1 & 0xff) != 0) {
        uVar1 = 0x742;
        FUN_a00a9468(1, 3);
    } else {
        uVar1 = 0x792;
        FUN_a00a9468(1, 2);
    }

    FUN_a0146a80(0x28, 6, 3, uVar1, 0);
    FUN_a0146a80(0x2b, 6, 1, uVar1, 0);
    FUN_a0146b20(0, 0x2b, 6, 1, 0x3f, 0);
    FUN_a0146a80(0x32, 6, 1, uVar1, 0);
    FUN_a0146b20(0, 0x32, 6, 1, 0x40, 0);
    FUN_a0146b50(0xe6, 0);

    FUN_a01577f4(local_10, 0x1981d0, param_3);
    local_10[0] = 3;
    FUN_a0146b6c(2, 0);
    FUN_a00a31a4(0, 0x28, 6, 2, local_10, 0);
}
