/* leon2m FUN_a014deec @ 0xa014deec-0xa014df68 (31 words), flags -mcpu=v8 -O3 -g.
 * Code facts: r = FUN_a01421c4(FUN_a0142218(FUN_a0125198(p))) (u8 chain); r == 0x71 -> v = 0,
 * FUN_a0151aa4(0x10, 1); r == 0x81 -> v = 1, FUN_a0151aa4(0x20, 1); else v = 0xff. If v != 0xff:
 * tail FUN_a012b884(v). The two FUN_a0151aa4 calls are cross-jumped into one call site in the fw.
 * The 0x71 case gives v = 0 (fw 'clr %i0' on that path). Source form: the selector is a switch (an
 * if/else-if chain or an early-return helper gives other code). Aids: none.
 */
extern unsigned char FUN_a0125198(unsigned char);
extern unsigned char FUN_a0142218(unsigned char);
extern unsigned char FUN_a01421c4(unsigned char);
extern void FUN_a0151aa4(int, int);
extern void FUN_a012b884(unsigned char);

void FUN_a014deec(unsigned char p)
{
    unsigned char v;

    switch (FUN_a01421c4(FUN_a0142218(FUN_a0125198(p)))) {
    case 0x71: v = 0; FUN_a0151aa4(0x10, 1); break;
    case 0x81: v = 1; FUN_a0151aa4(0x20, 1); break;
    default: v = 0xff; break;
    }
    if (v == 0xff)
        return;
    FUN_a012b884(v);
}
