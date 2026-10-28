/* leon2m FUN_a00a15d0 @ 0xa00a15d0-0xa00a177c (107 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * Calls FUN_a00a93bc(byte DAT_a8025c56), then decrements that byte (values outside 0..3 after the decrement
 * become 2) and calls FUN_a00a9650(byte, 1). Then FUN_a00a813c(1, v, 0) when the byte equals v = value 1 of
 * FUN_a00a14bc (byte 0xa802d478 / 0xa802d47a / 0xa802d47c for word 0xa802afec 0xc0 / 0xc1 / 0xc2, else 0),
 * otherwise FUN_a00a813c(1, v, 1) (tail calls).
 * FUN_a00a14bc is defined here as a static copy (the case order of FUN_a00a20d0) and inlined three times; its
 * first switch appears three times with jump tables over 0xc0..0xf9 (0x2f6b8, 0x2f5d0, 0x2f4e8).
 */
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802d290[]; // base 0xa802d290
extern unsigned char DAT_a802d479;   // 0xa802d479
extern unsigned char DAT_a802d47d;   // 0xa802d47d
extern unsigned char DAT_a8025c56;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

static unsigned char FUN_a00a14bc(unsigned char sel)
{
    unsigned int a = 0, b = 0, c = 0, d = 0, e = 0;

    switch (_DAT_a802afec) {
    case 0xf7:
        b = DAT_a802d479;
        d = 1;
        e = 2;
        break;
    case 0xc0:
        a = DAT_a802d290[0x1e8];
        c = 4;
        break;
    case 0xc1:
        a = DAT_a802d290[0x1ea];
        c = 5;
    case 0xf8:
        b = DAT_a802d290[0x1eb];
        d = 1;
        e = 3;
        break;
    case 0xc2:
        a = DAT_a802d290[0x1ec];
        c = 6;
        break;
    case 0xf9:
        b = DAT_a802d47d;
        d = 1;
        e = 3;
        break;
    default:
        return 0;
    }
    switch (sel) {
    case 1: return a;
    case 2: return b;
    case 3: return c;
    case 4: return d;
    case 5: return e;
    default: return 0;
    }
}

void FUN_a00a15d0(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    DAT_a8025c56 = DAT_a8025c56 - 1;
    if (DAT_a8025c56 > 3)
        DAT_a8025c56 = 2;
    FUN_a00a9650(DAT_a8025c56, 1);
    if (DAT_a8025c56 == FUN_a00a14bc(1))
        FUN_a00a813c(1, FUN_a00a14bc(1), 0);
    else
        FUN_a00a813c(1, FUN_a00a14bc(1), 1);
}
