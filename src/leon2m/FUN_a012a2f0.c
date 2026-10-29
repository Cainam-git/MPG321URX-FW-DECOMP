/* leon2m FUN_a012a2f0 @ 0xa012a2f0-0xa012a700 (1040 bytes), flags -mcpu=v8 -O3 -g. No direct callers found.
 * When m != 0 the halfword tables DAT_a802ca3a[16] and DAT_a802ca1a[16] are set to i * 0x40 + 0x40. When the
 * halfword DAT_a802ca12 is 0, the bytes DAT_a802cae0[16] are set to 0x3a and DAT_a802ca12 to their sum.
 * When the inlined copy of FUN_a012a228 returns nonzero: the inlined copy of FUN_a012a164 copies DAT_a802ca5c to
 * DAT_a802ca9c, then for i = 0..15 DAT_a802ca1a[i] = (0x400 - DAT_a802ca12) * DAT_a802ca5c[i] / DAT_a802ca0c; when
 * DAT_a802ca5c[i] * 10 / DAT_a802ca0c > 7 the loop stops and DAT_a802ca1a is reset to i * 0x40 + 0x40, otherwise
 * DAT_a802cae0[i] and the previous entry are added. When that happened, or m != 0, or the byte DAT_a802ca10 is
 * nonzero: with DAT_a802ca08 == 0 each DAT_a802ca3a[i] moves towards DAT_a802ca1a[i] by at most 4 and DAT_a802ca10
 * = 1 if any entry changed (else 0); otherwise DAT_a802ca3a is copied from DAT_a802ca1a and DAT_a802ca10 = 0.
 * Finally a local record { n = 0x10, v[0] = 0, v[1..15] = DAT_a802ca3a[0..14], v[16] = 0x400 } is passed to
 * FUN_a00f7434.
 * Source form: FUN_a012a228 and FUN_a012a164 are static copies (inlined); loop.c hoists the table addresses in the
 * order the loop bodies use them, so the first loop stores DAT_a802ca3a before DAT_a802ca1a and the scaling loop
 * stores its quotient into DAT_a802ca1a[i] first; chg is an int set in both arms; nested ifs for the three tests.
 * Compiler aid: the first 'f = 0;' (before the chg test) is overwritten before any use and emits no instructions;
 * it keeps the chg test block from holding only the compare and jump, so GCSE jump bypassing does not thread chg
 * (the firmware keeps 'mov 1' and the compare).
 */
struct coef {
    unsigned char n;
    unsigned short v[35];
};
extern unsigned short DAT_a802ca1a[16];
extern unsigned short DAT_a802ca3a[16];
extern unsigned char DAT_a802cae0[16];
extern unsigned short DAT_a802ca12;
extern int DAT_a802ca5c[16];
extern int DAT_a802ca9c[16];
extern unsigned int DAT_a802ca0c;
extern int DAT_a802ca08;
extern unsigned char DAT_a802ca10;
extern int abs(int);
extern void FUN_a00f7434(struct coef *);

static void FUN_a012a164(void)
{
    unsigned char i;

    for (i = 0; i < 16; i++)
        DAT_a802ca9c[i] = DAT_a802ca5c[i];
}

static unsigned char FUN_a012a228(void)
{
    unsigned char i, n, run;
    unsigned short d;
    int a;
    int hit, few;

    if (DAT_a802ca0c == 0)
        return 0;
    n = 0;
    run = 0;
    for (i = 0; i < 16; i++) {
        a = DAT_a802ca9c[i] - DAT_a802ca5c[i];
        d = abs(a);
        if (d > 0x40) {
            n++;
            run++;
            if (run > 1)
                run |= 0x80;
        } else
            run &= 0x80;
    }
    hit = (run & 0x80) != 0;
    few = n < 3;
    if (few & hit)
        return 0;
    if (n != 0)
        return 1;
    return 0;
}

void FUN_a012a2f0(unsigned char m)
{
    unsigned char i, big, f;
    int chg;
    unsigned short v;
    struct coef c;

    if (m != 0) {
        for (i = 0; i < 16; i++) {
            DAT_a802ca3a[i] = i * 0x40 + 0x40;
            DAT_a802ca1a[i] = i * 0x40 + 0x40;
        }
    }
    if (DAT_a802ca12 == 0) {
        DAT_a802ca12 = 0;
        for (i = 0; i < 16; i++) {
            DAT_a802cae0[i] = 0x3a;
            DAT_a802ca12 += 0x3a;
        }
    }
    if (FUN_a012a228()) {
        FUN_a012a164();
        big = 0;
        for (i = 0; i < 16; i++) {
            DAT_a802ca1a[i] = (0x400 - DAT_a802ca12) * DAT_a802ca5c[i] / DAT_a802ca0c;
            if (DAT_a802ca5c[i] * 10 / DAT_a802ca0c > 7) {
                big = 1;
                break;
            }
            DAT_a802ca1a[i] += DAT_a802cae0[i];
            if (i != 0)
                DAT_a802ca1a[i] += DAT_a802ca1a[i - 1];
        }
        if (big) {
            for (i = 0; i < 16; i++)
                DAT_a802ca1a[i] = i * 0x40 + 0x40;
        }
        chg = 1;
    } else
        chg = 0;
    f = 0;
    if (chg == 0)
        if (m == 0)
            if (DAT_a802ca10 == 0)
                return;
    {
        f = 0;
        if (DAT_a802ca08 == 0) {
            for (i = 0; i < 16; i++) {
                if (DAT_a802ca3a[i] > DAT_a802ca1a[i]) {
                    if (DAT_a802ca3a[i] - DAT_a802ca1a[i] < 5)
                        DAT_a802ca3a[i] = DAT_a802ca1a[i];
                    else
                        DAT_a802ca3a[i] -= 4;
                    f = 1;
                } else if (DAT_a802ca3a[i] < DAT_a802ca1a[i]) {
                    if (DAT_a802ca1a[i] - DAT_a802ca3a[i] > 4)
                        DAT_a802ca3a[i] += 4;
                    else
                        DAT_a802ca3a[i] = DAT_a802ca1a[i];
                    f = 1;
                }
            }
            DAT_a802ca10 = f;
        } else {
            DAT_a802ca10 = 0;
            for (i = 0; i < 16; i++)
                DAT_a802ca3a[i] = DAT_a802ca1a[i];
        }
        c.n = 0x10;
        c.v[0] = 0;
        for (i = 1; i < 16; i++)
            c.v[i] = DAT_a802ca3a[i - 1];
        c.v[16] = 0x400;
        FUN_a00f7434(&c);
    }
}
