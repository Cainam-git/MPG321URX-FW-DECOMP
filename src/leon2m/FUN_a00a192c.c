/* leon2m FUN_a00a192c @ 0xa00a192c-0xa00a1a68 (79 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Calls FUN_a00a93bc(byte DAT_a8025c56) and FUN_a00a813c(1, sel1, 1), sets word 0xa802afec to sel3 + 0x34, then
 * calls FUN_a00a900c(afec - 0x34, 1), FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1). sel1 and sel3 are the values 1
 * and 3 of FUN_a00a14bc (chosen by word 0xa802afec, 0xc0..0xc2 and 0xf7..0xf9), inlined here as two jump-table
 * switches (tables 0x2fb40 and 0x2fa58).
 * Source form: the static copy of FUN_a00a14bc is FUN_a00a23a4's (cases in ascending record-offset order
 * 0x1e8 ... 0x1ed, all values read as bytes of DAT_a802d290); with it the copy-1 0xc2 block comes before the
 * copy-2 0xc2 block and tail (0xa00a19e4, 0xa00a19f4) as in the firmware. The FUN_a00a20d0 copy (0xf7 first,
 * DAT_a802d479 / DAT_a802d47d) puts the copy-2 block first.
 */
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802d290[]; // base 0xa802d290
extern unsigned char DAT_a8025c56;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

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

void FUN_a00a192c(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    FUN_a00a813c(1, FUN_a00a14bc(1), 1);
    _DAT_a802afec = FUN_a00a14bc(3) + 0x34;
    FUN_a00a900c(_DAT_a802afec - 0x34, 1);
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
}
