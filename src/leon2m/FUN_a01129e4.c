/* leon2m FUN_a01129e4 @ 0xa01129e4-0xa0112b2c (82 words, including the unreachable ret/restore tail).
 * Passes up to three values to FUN_a00f3134(register address, value) for a register group chosen by sel:
 * 0..4: three registers each (0xcf011880 + sel * 0x30, + 0x10, + 0x20) get a, b, c; 5: 0xcf011970 gets a;
 * 0xa: 0xcf00f510 / f520 get a / b; 0xb: 0xcf00f590 / f5a0 get a / b; 0x13: 0xcf015b40 gets a; other sel: nothing.
 * Called by FUN_a0112b2c (and others).
 */
extern void FUN_a00f3134(unsigned int reg, unsigned int v);

void FUN_a01129e4(unsigned char sel, unsigned int a, unsigned int b, unsigned int c)
{
    switch (sel) {
    case 0x0:
        FUN_a00f3134(0xcf011880, a);
        FUN_a00f3134(0xcf011890, b);
        FUN_a00f3134(0xcf0118a0, c);
        break;
    case 0x1:
        FUN_a00f3134(0xcf0118b0, a);
        FUN_a00f3134(0xcf0118c0, b);
        FUN_a00f3134(0xcf0118d0, c);
        break;
    case 0x2:
        FUN_a00f3134(0xcf0118e0, a);
        FUN_a00f3134(0xcf0118f0, b);
        FUN_a00f3134(0xcf011900, c);
        break;
    case 0x3:
        FUN_a00f3134(0xcf011910, a);
        FUN_a00f3134(0xcf011920, b);
        FUN_a00f3134(0xcf011930, c);
        break;
    case 0x4:
        FUN_a00f3134(0xcf011940, a);
        FUN_a00f3134(0xcf011950, b);
        FUN_a00f3134(0xcf011960, c);
        break;
    case 0x5:
        FUN_a00f3134(0xcf011970, a);
        break;
    case 0xa:
        FUN_a00f3134(0xcf00f510, a);
        FUN_a00f3134(0xcf00f520, b);
        break;
    case 0xb:
        FUN_a00f3134(0xcf00f590, a);
        FUN_a00f3134(0xcf00f5a0, b);
        break;
    case 0x13:
        FUN_a00f3134(0xcf015b40, a);
        break;
    }
}
