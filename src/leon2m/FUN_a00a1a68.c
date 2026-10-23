/* leon2m FUN_a00a1a68 @ 0xa00a1a68-0xa00a1cf0 (162 words).
 * FUN_a00a93bc(byte 0xa8025c56), FUN_a00a8c88(). Word 0xa802afec 0xc0, 0xc1, 0xc2: prints s_001081d0, s_001081e0,
 * s_001081c0 and sets the word to 0xf7, 0xf8, 0xf9. Then with b = value 2, min = value 4 and max = value 5 of
 * FUN_a00a14bc: FUN_a00b7e68(1, 99 * (b - min) / (max - min) + 1, b), FUN_a00a9650(0, 1) and
 * FUN_a00aee44(low byte of the word, 0) (tail call). FUN_a00a14bc is a static copy (as in FUN_a00a20d0).
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802d479;
extern unsigned char DAT_a802d47d;
extern unsigned char DAT_a8025c56;
extern char s_001081c0[], s_001081d0[], s_001081e0[];
extern int FUN_a00df170();
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a8c88(void);
extern void FUN_a00b7e68(unsigned char, unsigned char, unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00aee44(unsigned char, int);

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

void FUN_a00a1a68(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    FUN_a00a8c88();
    switch (_DAT_a802afec) {
    case 0xc0:
        FUN_a00df170(s_001081d0);
        _DAT_a802afec = 0xf7;
        break;
    case 0xc1:
        FUN_a00df170(s_001081e0);
        _DAT_a802afec = 0xf8;
        break;
    case 0xc2:
        FUN_a00df170(s_001081c0);
        _DAT_a802afec = 0xf9;
        break;
    }
    FUN_a00b7e68(1, 99 * (FUN_a00a14bc(2) - FUN_a00a14bc(4)) / (FUN_a00a14bc(5) - FUN_a00a14bc(4)) + 1,
                 FUN_a00a14bc(2));
    FUN_a00a9650(0, 1);
    FUN_a00aee44(_DAT_a802afec, 0);
}
