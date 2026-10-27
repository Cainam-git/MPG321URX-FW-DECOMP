/* leon2m FUN_a00e40f4 @ 0xa00e40f4-0xa00e4278 (388 bytes), flags -mcpu=v8 -O2 -g. Callers: FUN_a00e4278,
 * FUN_a00e4538.
 * When FUN_a00e0788(phy, 0x43, 0x40, 0x40) returns 0: v = FUN_a00e0514(phy, 0x3e, 7), FUN_a00e05d8(phy, 0x3e, 7, 1),
 * r = FUN_a00e02ec(phy, 0x395), FUN_a00e05d8(phy, 0x3e, 7, v); returns 1 when FUN_a00e0514(phy, 0x43, 0xe0) is
 * non-zero and a second read of it is not 0x80, else 3 when r is 0 and 1 otherwise.
 * Otherwise by mode: 0 tests FUN_a00e0514(phy, 0x43, 0x80), 1 FUN_a00e0514(phy, 0x41, 0x80), 2 FUN_a00e0514(phy,
 * 0x41, 0x40) (non-zero returns 1); another mode calls FUN_a00df80c(), FUN_a00e0bc0() and prints "Error: unknown
 * bit_mode %d" and returns 1. Then it returns 2 when FUN_a00e0514(phy, 0x43, 0x20) is non-zero, else 0.
 * Source form: the 'return 1' after r != 0 is a goto to the error path's return (one shared exit block).
 */
extern int FUN_a00e0788(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e02ec(int phy, unsigned int addr);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern const char s_001997c8[];

int FUN_a00e40f4(int phy, int mode)
{
    unsigned int v, r;

    if (FUN_a00e0788(phy, 0x43, 0x40, 0x40) == 0) {
        v = FUN_a00e0514(phy, 0x3e, 7);
        FUN_a00e05d8(phy, 0x3e, 7, 1);
        r = FUN_a00e02ec(phy, 0x395);
        FUN_a00e05d8(phy, 0x3e, 7, v);
        if (FUN_a00e0514(phy, 0x43, 0xe0) != 0 && FUN_a00e0514(phy, 0x43, 0xe0) != 0x80)
            return 1;
        if (r == 0)
            return 3;
        goto fail;
    }
    switch (mode) {
    case 0:
        if (FUN_a00e0514(phy, 0x43, 0x80) != 0)
            return 1;
        break;
    case 1:
        if (FUN_a00e0514(phy, 0x41, 0x80) != 0)
            return 1;
        break;
    case 2:
        if (FUN_a00e0514(phy, 0x41, 0x40) != 0)
            return 1;
        break;
    default:
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_001997c8, mode);
    fail:
        return 1;
    }
    return (FUN_a00e0514(phy, 0x43, 0x20) != 0) * 2;
}
