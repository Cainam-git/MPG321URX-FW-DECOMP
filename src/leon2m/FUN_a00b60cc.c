/* leon2m FUN_a00b60cc @ 0xa00b60cc-0xa00b617c (44 words), flags -mcpu=v8 -O3 -g.
 * Code facts: (p1 & 0xff) != 0 -> v = 0x742, FUN_a00a9468(1, 3); else v = 0x792, FUN_a00a9468(1, 2) (u16 v,
 * 'and 0x7d2' = its zero-extension); FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1, v, 0) with
 * FUN_a0146b20(0, 0x2b/0x32, 6, 1, 0x3f/0x40, 0) after the 2nd and 3rd (the last one a tail call).
 * Same block as the middle of FUN_a00b7e68 / FUN_a00b7188.
 * Fix vs the autoc draft (77.27): v set in BOTH arms (the a00b7e68 lever), the param is tested as (p1 & 0xff) (fw btst
 * 0xff, %i0 with no entry mask), u8/void prototypes. Aids: none.
 */
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);

void FUN_a00b60cc(unsigned int param_1)
{
    unsigned short v;

    if ((param_1 & 0xff) != 0) {
        v = 0x742;
        FUN_a00a9468(1, 3);
    } else {
        v = 0x792;
        FUN_a00a9468(1, 2);
    }
    FUN_a0146a80(0x28, 6, 3, v, 0);
    FUN_a0146a80(0x2b, 6, 1, v, 0);
    FUN_a0146b20(0, 0x2b, 6, 1, 0x3f, 0);
    FUN_a0146a80(0x32, 6, 1, v, 0);
    FUN_a0146b20(0, 0x32, 6, 1, 0x40, 0);
}
