/* leon2m FUN_a00d94fc @ 0xa00d94fc-0xa00d972c (75 words).
 * Returns at once when FUN_a014bd70(0) returns 1, when FUN_a01438dc(0) returns 1 and FUN_a014ba68() returns
 * 1..4, or when bit 4 of the word at 0xa802d290+0x11c is clear. Otherwise byte +0x11 (0..7, others as 1) selects
 * three bytes a, b, c: FUN_a0145920 of three consecutive indices (0x12, 9, 6, -, 9, 0xc, 0xf, 0x15), or for
 * selector 3 the bytes +0x12, +0x13, +0x14 scaled as (x * 200 + 50) / 100 + 55.
 * c is scaled to (unsigned char)(c * 0.81) in double arithmetic (soft-float calls __floatsidf, __muldf3,
 * __fixunsdfsi; flags -mcpu=v8 -O3 -g -msoft-float), then tail call FUN_a0145fc0(a + 1, b + 1, c + 1).
 * The first test is a static helper chk() with one return per case (inlined); the scaling uses unsigned
 * arithmetic (200U) as the firmware divides with umul.
 */
struct R290 {
    unsigned char pad0[0x11];
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15[0x11c - 0x15];
    unsigned int w11c;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);
extern unsigned char FUN_a0145920(unsigned char);
extern void FUN_a0145fc0(unsigned short a, unsigned short b, unsigned short c);

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

void FUN_a00d94fc(void)
{
    unsigned char a, b, c;

    if (chk())
        return;
    if (!(DAT_a802d290.w11c & 0x10))
        return;
    switch (DAT_a802d290.b11) {
    case 0:
        a = FUN_a0145920(0x12); b = FUN_a0145920(0x13); c = FUN_a0145920(0x14);
        break;
    case 2:
        a = FUN_a0145920(6); b = FUN_a0145920(7); c = FUN_a0145920(8);
        break;
    case 3:
        a = (DAT_a802d290.b12 * 200U + 50) / 100 + 55;
        b = (DAT_a802d290.b13 * 200U + 50) / 100 + 55;
        c = (DAT_a802d290.b14 * 200U + 50) / 100 + 55;
        break;
    case 5:
        a = FUN_a0145920(0xc); b = FUN_a0145920(0xd); c = FUN_a0145920(0xe);
        break;
    case 6:
        a = FUN_a0145920(0xf); b = FUN_a0145920(0x10); c = FUN_a0145920(0x11);
        break;
    case 7:
        a = FUN_a0145920(0x15); b = FUN_a0145920(0x16); c = FUN_a0145920(0x17);
        break;
    case 1:
    case 4:
    default:
        a = FUN_a0145920(9); b = FUN_a0145920(10); c = FUN_a0145920(11);
        break;
    }
    c = c * 0.81;
    FUN_a0145fc0(a + 1, b + 1, c + 1);
}
