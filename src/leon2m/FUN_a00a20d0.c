/* leon2m FUN_a00a20d0 @ 0xa00a20d0-0xa00a2264 (101 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * When byte DAT_a8025c56 is not 2: calls FUN_a00a813c(1, v1, 0) with value 1 of FUN_a00a14bc, stores DAT_a8025c56
 * to byte 0x1e8 of DAT_a802d290 and calls FUN_a00a93bc with it, sets word 0xa802afec to value 3 of FUN_a00a14bc
 * plus 0x34, then calls FUN_a00a9650(c56, 0), FUN_a00a813c(1, c56, 1), FUN_a00a900c(afec - 0x34, 1),
 * FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1). When it is 2: copies DAT_a802d479 to DAT_a8025c55 and calls
 * FUN_a00a1a68. Then calls FUN_a00dac00 and sets bit 1 of DAT_a802b08e.
 * FUN_a00a14bc is defined here as a static copy and inlined twice (its two switches with jump tables appear in
 * this function: 0x309c0 and 0x30aa8). The case order of the copy and the arm order of the c56 test (the != 2 arm
 * first) set the register names; the copy with this case order also matches FUN_a00a14bc itself.
 */
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802d290[]; // base 0xa802d290
extern unsigned char DAT_a802d479;   // 0xa802d479
extern unsigned char DAT_a802d47d;   // 0xa802d47d
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a1a68(void);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00dac00(void);

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

void FUN_a00a20d0(void)
{
    if (DAT_a8025c56 != 2) {
        FUN_a00a813c(1, FUN_a00a14bc(1), 0);
        DAT_a802d290[0x1e8] = DAT_a8025c56;
        FUN_a00a93bc(DAT_a8025c56);
        _DAT_a802afec = FUN_a00a14bc(3) + 0x34;
        FUN_a00a9650(DAT_a8025c56, 0);
        FUN_a00a813c(1, DAT_a8025c56, 1);
        FUN_a00a900c(_DAT_a802afec - 0x34, 1);
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    } else {
        DAT_a8025c55 = DAT_a802d479;
        FUN_a00a1a68();
    }
    FUN_a00dac00();
    DAT_a802b08e |= 2;
}
