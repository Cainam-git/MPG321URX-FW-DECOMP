/* leon2m FUN_a00d7de0 @ 0xa00d7de0-0xa00d8034 (149 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Limits byte DAT_a802d290+0xa to 100 and calls FUN_a0145ee8(0, 0). A value v is mapped to (v - 70) * 22 / 30 + 128
 * (v above 70) or v * 100 / 70 + 28 in float and passed as a byte to FUN_a014bcf0. Nothing more happens when byte
 * +0x181 is 4..6 and bit 11 of word +0xa8 is set. When chk() (FUN_a014bd70(0) == 1, or FUN_a01438dc(0) == 1 with
 * FUN_a014ba68() 1..4, as in FUN_a00d9764) is true or byte +0x178 is 1, v is the byte at 0x19852e (stored in +0xa
 * during the call, the old value restored afterwards); otherwise v is byte +0xa.
 * Source form: chk() and the mapping are static helpers (inlined); the v > 70 arm comes first.
 */
struct R290 {
    unsigned char pad0[0xa];
    unsigned char b0a;
    unsigned char pad0b[0xa8 - 0xb];
    unsigned int wa8;
    unsigned char padac[0x178 - 0xac];
    unsigned char b178;
    unsigned char pad179[0x181 - 0x179];
    unsigned char b181;
};
extern struct R290 DAT_a802d290;
extern const unsigned char DAT_0019852e;
extern void FUN_a0145ee8(int, int);
extern unsigned char FUN_a014bd70(unsigned char ch);
extern unsigned char FUN_a01438dc(unsigned char ch);
extern unsigned char FUN_a014ba68(void);
extern void FUN_a014bcf0(unsigned char);

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

static void apply(unsigned char v)
{
    float f;

    if (v > 70)
        f = (v - 70) * 22.0f / 30.0f + 128.0f;
    else
        f = v * 100.0f / 70.0f + 28.0f;
    FUN_a014bcf0((unsigned char)f);
}

void FUN_a00d7de0(void)
{
    unsigned char old = DAT_a802d290.b0a;

    if (old > 100)
        old = 100;
    DAT_a802d290.b0a = old;
    FUN_a0145ee8(0, 0);
    if (chk()) {
        if ((unsigned char)(DAT_a802d290.b181 - 4) <= 2 && (DAT_a802d290.wa8 & 0x800))
            return;
        old = DAT_a802d290.b0a;
        DAT_a802d290.b0a = DAT_0019852e;
        apply(DAT_a802d290.b0a);
        DAT_a802d290.b0a = old;
    } else {
        if ((unsigned char)(DAT_a802d290.b181 - 4) <= 2 && (DAT_a802d290.wa8 & 0x800))
            return;
        if (DAT_a802d290.b178 == 1) {
            old = DAT_a802d290.b0a;
            DAT_a802d290.b0a = DAT_0019852e;
            apply(DAT_a802d290.b0a);
            DAT_a802d290.b0a = old;
        } else
            apply(DAT_a802d290.b0a);
    }
}
