/* leon2m FUN_a014b4b4 @ 0xa014b4b4-0xa014b65c (106 words), flags -mcpu=v8 -O3 -g -msoft-float (with -O3 -g the
 * 'mov 1' of '1 << i' is hoisted out of the loop; the firmware sets it in every pass).
 * p == 0xfe: i runs over 0..6. Any other p: first = last = FUN_a014af84(p) (k = 1, 2, 3 for
 * FUN_a01421c4(FUN_a0142218(FUN_a0125198(p))) = 0x61, 0x71, 0x81, else 0; FUN_a0125124 of byte +0x10 of
 * DAT_a802e116[k]), so the loop does not run. Per i: FUN_a01340b0(1 << i, on) when FUN_a0125350(i) is nonzero,
 * otherwise func_0x4008c86c(FUN_a01254f8(i), FUN_a0125530(i), FUN_a0125568(i)), the last value inverted when on
 * is 0.
 * Source form: FUN_a014af84 is the matched neighbour, defined here as a static copy and inlined (GCC copies its
 * table lookup into the k = 1 path); first/last are set in both arms of 'if (p == 0xfe) ... else ...' (presetting
 * them before an 'if (p != 0xfe)' gives another block layout).
 */
struct E12 { unsigned char p0[0x10]; unsigned char b10; unsigned char p11; };
extern struct E12 DAT_a802e116[];
extern int FUN_a0125198(unsigned char);
extern unsigned char FUN_a0142218(unsigned char v);
extern unsigned char FUN_a01421c4(unsigned char x);
extern unsigned char FUN_a0125124(unsigned int param_1);

extern unsigned char FUN_a0125350(unsigned char);
extern void FUN_a01340b0(unsigned char, unsigned char);
extern unsigned char FUN_a01254f8(unsigned char);
extern unsigned char FUN_a0125530(unsigned char);
extern unsigned char FUN_a0125568(unsigned char);
extern void func_0x4008c86c(unsigned char, unsigned char, unsigned char);

static unsigned char FUN_a014af84(unsigned char c)
{
    unsigned char x = FUN_a01421c4(FUN_a0142218(FUN_a0125198(c)));
    unsigned char k = 0;

    switch (x) {
    case 0x51:
        k = 0;
        break;
    case 0x61:
        k = 1;
        break;
    case 0x71:
        k = 2;
        break;
    case 0x81:
        k = 3;
        break;
    }
    return FUN_a0125124(DAT_a802e116[k & 3].b10);
}

void FUN_a014b4b4(unsigned char p, unsigned char on)
{
    unsigned char i, first, last;

    if (p == 0xfe) {
        first = 0;
        last = 7;
    } else {
        last = FUN_a014af84(p);
        first = last;
    }
    for (i = first; i < last; i++) {
        if (FUN_a0125350(i))
            FUN_a01340b0(1 << i, on);
        else if (on)
            func_0x4008c86c(FUN_a01254f8(i), FUN_a0125530(i), FUN_a0125568(i));
        else
            func_0x4008c86c(FUN_a01254f8(i), FUN_a0125530(i), ~FUN_a0125568(i));
    }
}
