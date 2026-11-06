/* leon2m FUN_a00d8cd4 @ 0xa00d8cd4-0xa00d8ffc (202 words), flags -mcpu=v8 -O3 -g.
 * Limits the byte DAT_a802d290 + 0x09 to 100 and stores it back as v. r = 100 when FUN_a00d7d48() is not 0, or
 * when the word at +0xb0 is not 0 and FUN_a00d8bd8(0, 1) is 1. Otherwise, when bit 6 of the word at +0x1d4 and
 * bit 11 of the word at +0xa8 are set and the byte at +0x181 is 7, r = the FUN_a00d3e28 conversion of v (knee =
 * halfword +0x1da); else r = the FUN_a00d3f80 conversion (knee 272 under the +0xa8 bit 11 / +0x181 == 7 test,
 * else 879). Then FUN_a012653c(2) when FUN_a00d7d48() is 0, otherwise FUN_a012653c(0) when bits 18..19 of the
 * word at +0xac are set and FUN_a012653c(1) when not; ends with FUN_a014bf64(r).
 * Callers: FUN_a00a4244, FUN_a00a429c, FUN_a00d27ac, FUN_a00d8ffc and others.
 * Source form: FUN_a00d7d48, FUN_a00d8bd8 and FUN_a00d3e28 are static copies of the matched routines (the knee
 * read as the record member +0x1da, fw 'lduh [%o3 + 0x1da]' at 0xa00d8fa8), inlined; the FUN_a00d3f80
 * conversion is a static helper with both knee formulas in one if/else and one shared return expression (fw:
 * one scaling tail at 0xa00d8db8 for all three formulas); the FUN_a00d8bd8 result is compared '== 1' as the
 * FUN_a014bd70 / FUN_a01438dc results are; v and r are unsigned short (fw 'mov %l0, %o5' copy of the helper
 * parameter at 0xa00d8d74, one 'and 0xff' per formula tail at 0xa00d8df0).
 */
struct R290 {
    unsigned char pad0[0x09];
    unsigned char b09;
    unsigned char pad0a[0xa8 - 0x0a];
    unsigned int wa8;
    unsigned int wac;
    unsigned int wb0;
    unsigned char padb4[0x181 - 0xb4];
    unsigned char b181;
    unsigned char pad182[0x1d4 - 0x182];
    unsigned int w1d4;
    unsigned char pad1d8[2];
    unsigned short h1da;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);
extern int FUN_a0087458();
extern int FUN_a0145660();
extern void FUN_a012653c(unsigned char);
extern void FUN_a014bf64(unsigned char);

static unsigned int FUN_a00d8bd8(unsigned int param_1, unsigned int param_2)
{
    unsigned int t;

    t = FUN_a0145660(0, 1);
    return (FUN_a0087458((unsigned short)t / 10) != 0);
}

static unsigned char FUN_a00d3e28(unsigned char c)
{
    unsigned short v;

    if (c > 0x45)
        v = (unsigned int)((c - 70) * (0x3ff - DAT_a802d290.h1da) + 15) / 30 + DAT_a802d290.h1da;
    else
        v = (unsigned int)(c * (DAT_a802d290.h1da - 126) + 35) / 70 + 126;
    return (v - 126) * 100 / 897;
}

static unsigned char FUN_a00d3f80(unsigned char c)
{
    unsigned short v;

    if ((DAT_a802d290.wa8 & 0x800) && DAT_a802d290.b181 == 7) {
        if (c > 0x45)
            v = (unsigned int)((c - 70) * (0x3ff - 272) + 15) / 30 + 272;
        else
            v = (unsigned int)(c * (272 - 126) + 35) / 70 + 126;
    } else {
        if (c > 0x45)
            v = (unsigned int)((c - 70) * (0x3ff - 879) + 15) / 30 + 879;
        else
            v = (unsigned int)(c * (879 - 126) + 35) / 70 + 126;
    }
    return (v - 126) * 100 / 897;
}

static int FUN_a00d7d48(void)
{
    int r = 5;

    if (FUN_a014bd70(0) == 1)
        r = 4;
    else if (FUN_a01438dc(0) == 1) {
        switch (FUN_a014ba68()) {
        case 1: r = 1; break;
        case 2: r = 2; break;
        case 3: r = 3; break;
        case 4: r = 5; break;
        default: r = 0; break;
        }
    } else
        r = 0;
    return r;
}

void FUN_a00d8cd4(void)
{
    unsigned short v = DAT_a802d290.b09;
    unsigned short r;

    if (v > 100)
        v = 100;
    DAT_a802d290.b09 = v;
    if (FUN_a00d7d48())
        r = 100;
    else if (DAT_a802d290.wb0 != 0 && FUN_a00d8bd8(0, 1) == 1)
        r = 100;
    else if ((DAT_a802d290.w1d4 & 0x40) && (DAT_a802d290.wa8 & 0x800) && DAT_a802d290.b181 == 7)
        r = FUN_a00d3e28(v);
    else
        r = FUN_a00d3f80(v);
    if (FUN_a00d7d48()) {
        if (DAT_a802d290.wac & 0xc0000)
            FUN_a012653c(0);
        else
            FUN_a012653c(1);
    } else
        FUN_a012653c(2);
    FUN_a014bf64(r);
}
