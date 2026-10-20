/* leon2m FUN_a00dbcf0 @ 0xa00dbcf0-0xa00dc2dc (362 words).
 * UserSetGameMode: FUN_a00d8100(n) for n = 0, 1, (2, 4 when byte 0xa802d290+0x1f is 0), 3, 5, 6, 7, 8; prints
 * the mode byte +0x182, calls func_0x4008e2a4() and FUN_a0087a14(mode) for modes 0..5 (one call per case).
 * The rest is the same as FUN_a00db738 (same source shape): FUN_a00d7bc0(),
 * FUN_a00d9764(), FUN_a00d8cd4() when the word +0xb0 is 0 and bit 31 of word +0x11c is clear, FUN_a00d7de0(),
 * FUN_a00d9120(), the FUN_a014e878 / FUN_a00d9120 step of FUN_a00db690, FUN_a0149064(0 and 1, low nibble of
 * halfword +0x34), byte +0x49 limited to 5 and FUN_a01471a0(0, 0xd, 3 * value). When byte +0x1f is 0: the
 * FUN_a00d8c1c step, and when the low byte of word +0xb0 changed and chk() is false, byte +0x4a is cleared (if
 * it and word +0xb0 are nonzero) with FUN_a014d474(1, 0) / FUN_a014dd98(1, 0) when byte +0x1f is still 0.
 * Then the FUN_a00d8ffc step. Finally bit 11 of word +0xa8 is copied to bit 10 (bit 7 of halfword 0xa802cffe
 * set), bit 8 (chk() true) or bit 9 (otherwise), and bytes +0x181 / +0x182 are copied to +0x183 / +0x184,
 * +0x187 / +0x188 or +0x185 / +0x186.
 * chk(): FUN_a014bd70(0) == 1, or FUN_a01438dc(0) == 1 and FUN_a014ba68() is 1..4.
 * Same-file functions inlined here: FUN_a00d8bd8, FUN_a00d8c1c (written in the form that its inlined copy needs;
 * the standalone FUN_a00d8c1c is not matched with this source) and FUN_a00d8ffc.
 * Source forms: the halfword +0x34 nibble is a bit-field (a mask narrows the load to a byte); the limited byte
 * +0x49 is an unsigned short passed as (unsigned char)v * 3; the byte copies
 * are written high byte first. Compiler aid: __builtin_expect(FUN_a00d8bd8(0, 1), 0) emits no instructions; it
 * places the nonzero-result path of that test as in the firmware.
 */
struct W11c {
    unsigned int top : 1;
    unsigned int rest : 31;
};
struct Wa8 {
    unsigned int p0 : 20;
    unsigned int b11 : 1;
    unsigned int b10 : 1;
    unsigned int b9 : 1;
    unsigned int b8 : 1;
    unsigned int p1 : 8;
};
struct R290 {
    unsigned char pad0[0x19];
    unsigned char b19;
    unsigned char pad1a[0x1f - 0x1a];
    unsigned char b1f;
    unsigned char pad20[0x34 - 0x20];
    struct {
        unsigned short p : 12;
        unsigned short lo : 4;
    } h34;
    unsigned char pad36[0x49 - 0x36];
    unsigned char b49;
    unsigned char b4a;
    unsigned char pad4b[0x8f - 0x4b];
    unsigned char b8f;
    unsigned char pad90[0xa8 - 0x90];
    struct Wa8 wa8;
    unsigned int wac;
    unsigned int wb0;
    unsigned char padb4[0x11c - 0xb4];
    struct W11c w11c;
    unsigned char pad120[0x174 - 0x120];
    unsigned int w174;
    unsigned char pad178[0x181 - 0x178];
    unsigned char b181;
    unsigned char b182;
    unsigned char b183;
    unsigned char b184;
    unsigned char b185;
    unsigned char b186;
    unsigned char b187;
    unsigned char b188;
};
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802cffe;
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00d8100(unsigned char);
extern void FUN_a0087a14(int);
extern void FUN_a00d7bc0(void);
extern void func_0x4008e2a4(void);
extern void FUN_a00d9764(void);
extern void FUN_a00d8cd4(void);
extern void FUN_a00d7de0(void);
extern void FUN_a00d9120(void);
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);
extern void FUN_a014e878(unsigned char);
extern void FUN_a0149064(unsigned char, unsigned char);
extern void FUN_a01471a0(unsigned char ch, unsigned char item, unsigned char v);
extern void FUN_a014d474(unsigned char, unsigned char);
extern void FUN_a014dd98(int, int);
extern void FUN_a01492b8(unsigned char);
extern void FUN_a014913c(int);
extern int FUN_a0087458();
extern int FUN_a0145660();

unsigned int FUN_a00d8bd8(unsigned int param_1, unsigned int param_2)
{
    unsigned int t;

    t = FUN_a0145660(0, 1);
    return (FUN_a0087458((unsigned short)t / 10) != 0);
}

static int busy(void)
{
    if (DAT_a802d290.wb0 != 0 && FUN_a00d8bd8(0, 1))
        return 1;
    return 0;
}

void FUN_a00d8c1c(void)
{
    unsigned char m = DAT_a802d290.b19;

    if (DAT_a802d290.wb0 != 0 && __builtin_expect(FUN_a00d8bd8(0, 1), 0))
        return;
    if (m > 3)
        m = 3;
    DAT_a802d290.b8f = m;
    if (m != 0)
        DAT_a802d290.b19 = 0;
    else
        DAT_a802d290.b19 = m;
    FUN_a014913c(5);
    DAT_a802d290.b19 = DAT_a802d290.b8f;
}

void FUN_a00d8ffc(void)
{
    unsigned char m = DAT_a802d290.w11c.top;
    unsigned char sel = m;

    DAT_a802d290.w11c.top = sel;
    switch (sel) {
    case 0: m = 0; break;
    case 1: m = 1; break;
    case 2: m = 2; break;
    }
    if (FUN_a014bd70(0) == 1)
        m = 0;
    else if (FUN_a01438dc(0) == 1) {
        switch (FUN_a014ba68()) {
        case 1: m = 0; break;
        case 2: m = 0; break;
        case 3: m = 0; break;
        case 4: m = 0; break;
        }
    }
    FUN_a01492b8(m & 3);
    if (!DAT_a802d290.w11c.top)
        FUN_a00d8cd4();
}

static int chk(void)
{
    if (FUN_a014bd70(0) == 1)
        return 1;
    if (FUN_a01438dc(0) == 1) {
        switch (FUN_a014ba68()) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        }
    }
    return 0;
}

void FUN_a00dbcf0(void)
{
    unsigned char old = DAT_a802d290.wb0;
    unsigned short v;

    FUN_a00d8100(0);
    FUN_a00d8100(1);
    if (DAT_a802d290.b1f == 0) {
        FUN_a00d8100(2);
        FUN_a00d8100(4);
    }
    FUN_a00d8100(3);
    FUN_a00d8100(5);
    FUN_a00d8100(6);
    FUN_a00d8100(7);
    FUN_a00d8100(8);
    FUN_a00df170("\x1b[1;33mUserSetGameMode %x\r\n\x1b[m", DAT_a802d290.b182);
    func_0x4008e2a4();
    switch (DAT_a802d290.b182) {
    case 0: FUN_a0087a14(0); break;
    case 1: FUN_a0087a14(1); break;
    case 2: FUN_a0087a14(2); break;
    case 3: FUN_a0087a14(3); break;
    case 4: FUN_a0087a14(4); break;
    case 5: FUN_a0087a14(5); break;
    }
    FUN_a00d7bc0();
    FUN_a00d9764();
    if (DAT_a802d290.wb0 == 0 && !DAT_a802d290.w11c.top)
        FUN_a00d8cd4();
    FUN_a00d7de0();
    FUN_a00d9120();
    if (chk()) {
        FUN_a014e878(0);
        FUN_a00d9120();
    } else if (DAT_a802d290.w174 & 0x8000) {
        FUN_a014e878(1);
        FUN_a00d9120();
    } else {
        FUN_a014e878(0);
        FUN_a00d9120();
    }
    FUN_a0149064(0, DAT_a802d290.h34.lo);
    FUN_a0149064(1, DAT_a802d290.h34.lo);
    v = DAT_a802d290.b49;
    if (v > 5)
        v = 5;
    DAT_a802d290.b49 = v;
    FUN_a01471a0(0, 0xd, (unsigned char)v * 3);
    if (DAT_a802d290.b1f == 0) {
        FUN_a00d8c1c();
        if (old != DAT_a802d290.wb0 && !chk()) {
            if (DAT_a802d290.b4a != 0 && DAT_a802d290.wb0 != 0) {
                DAT_a802d290.b4a = 0;
                if (DAT_a802d290.b1f == 0) {
                    FUN_a014d474(1, 0);
                    FUN_a014dd98(1, 0);
                }
            }
        }
    }
    FUN_a00d8ffc();
    if (DAT_a802cffe & 0x80) {
        DAT_a802d290.wa8.b10 = DAT_a802d290.wa8.b11;
        DAT_a802d290.b184 = DAT_a802d290.b182;
        DAT_a802d290.b183 = DAT_a802d290.b181;
    } else if (chk()) {
        DAT_a802d290.wa8.b8 = DAT_a802d290.wa8.b11;
        DAT_a802d290.b188 = DAT_a802d290.b182;
        DAT_a802d290.b187 = DAT_a802d290.b181;
    } else {
        DAT_a802d290.wa8.b9 = DAT_a802d290.wa8.b11;
        DAT_a802d290.b186 = DAT_a802d290.b182;
        DAT_a802d290.b185 = DAT_a802d290.b181;
    }
}
