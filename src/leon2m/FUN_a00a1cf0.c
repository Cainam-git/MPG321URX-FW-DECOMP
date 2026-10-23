/* leon2m FUN_a00a1cf0 @ 0xa00a1cf0-0xa00a1eec (127 words).
 * Increments byte 0xa8025c55 and limits it to the maximum (value 5 of FUN_a00a14bc for the current word
 * 0xa802afec). With min = value 4 and max = value 5: FUN_a00b7e68(1, 99 * (byte - min) / (max - min) + 1, byte)
 * (tail call). FUN_a00a14bc is defined here as a static copy (as in FUN_a00a20d0) and inlined five times.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802d479;
extern unsigned char DAT_a802d47d;
extern unsigned char DAT_a8025c55;
extern void FUN_a00b7e68(unsigned char, unsigned char, unsigned char);

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

void FUN_a00a1cf0(void)
{
    DAT_a8025c55++;
    if (DAT_a8025c55 > FUN_a00a14bc(5))
        DAT_a8025c55 = FUN_a00a14bc(5);
    FUN_a00b7e68(1, 99 * (DAT_a8025c55 - FUN_a00a14bc(4)) / (FUN_a00a14bc(5) - FUN_a00a14bc(4)) + 1,
                 DAT_a8025c55);
}
