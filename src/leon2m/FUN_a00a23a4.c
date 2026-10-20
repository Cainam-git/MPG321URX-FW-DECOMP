/* leon2m FUN_a00a23a4 @ 0xa00a23a4-0xa00a2548 (105 words). No direct callers (reached through a table).
 * Switch on byte 0xa8025c56. Values 0 and 1: FUN_a00a813c(1, sel1, 0); copies the byte to 0xa802d290+0x1ea and
 * calls FUN_a00a93bc with it; stores sel3 + 0x34 to word 0xa802afec; FUN_a00a9650(b, 0), FUN_a00a813c(1, b, 1)
 * (b = byte 0xa8025c56), FUN_a00a900c(word 0xa802afec - 0x34, 1), FUN_a00a9468(1, 2), FUN_a00b34d4(0, 1).
 * Value 2: copies byte 0xa802d290+0x1eb to 0xa8025c55 and calls FUN_a00a1a68. Both then call FUN_a00dabc8 and
 * set bit 1 of byte 0xa802b08e; other values return at once.
 * sel1 and sel3 are the values 1 and 3 of FUN_a00a14bc (selection by word 0xa802afec, 0xc0..0xc2 and 0xf7..0xf9),
 * which GCC inlines here as two jump-table switches (tables 0x30b90 and 0x30c78). The inlined copy is written with
 * its cases in ascending record-offset order (0x1e8 ... 0x1ed); that order gives the firmware's block layout.
 * The switch on the byte gives the signed compare chain (ble / bne).
 */
extern unsigned char DAT_a802d290[];
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00a1a68(void);
extern void FUN_a00dabc8(void);

static unsigned char FUN_a00a14bc(unsigned char sel)
{
    unsigned int a = 0, b = 0, c = 0, d = 0, e = 0;

    switch (_DAT_a802afec) {
    case 0xc0:
        a = DAT_a802d290[0x1e8];
        c = 4;
        break;
    case 0xf7:
        b = DAT_a802d290[0x1e9];
        d = 1;
        e = 2;
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
        b = DAT_a802d290[0x1ed];
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

void FUN_a00a23a4(void)
{
    switch (DAT_a8025c56) {
    case 0:
    case 1:
        FUN_a00a813c(1, FUN_a00a14bc(1), 0);
        DAT_a802d290[0x1ea] = DAT_a8025c56;
        FUN_a00a93bc(DAT_a802d290[0x1ea]);
        _DAT_a802afec = FUN_a00a14bc(3) + 0x34;
        FUN_a00a9650(DAT_a8025c56, 0);
        FUN_a00a813c(1, DAT_a8025c56, 1);
        FUN_a00a900c(_DAT_a802afec - 0x34, 1);
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
        break;
    case 2:
        DAT_a8025c55 = DAT_a802d290[0x1eb];
        FUN_a00a1a68();
        break;
    default:
        return;
    }
    FUN_a00dabc8();
    DAT_a802b08e |= 2;
}
