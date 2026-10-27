/* leon2m FUN_a00f793c @ 0xa00f793c (-mcpu=v8 -O3 -g). Called by FUN_a0150da4.
 * For the selector values 3, 2, 1, 0 in turn: selects it (body of FUN_a00f63bc), calls FUN_a00f6fe4(1, 2, 0, 0xff),
 * configures the ACE block from the local 3-byte record {0, 0, 16} (body of FUN_a00f7894 with the record passed by
 * value, prints "Config ACE (%d) : (%d)"), streams the default coefficient table DAT_0019a378 (body of
 * FUN_a00f7434(0)), clears the selector bit of 0xcf00ee80 (FUN_a00f6408), loads the default 24-entry tables with
 * 0xcf00ef34 = 1 and 2 (FUN_a00f643c(0), FUN_a00f6508(0)) and the 17-entry table with 0xcf00ef34 = 0 (fill 0x80,
 * the form of FUN_a00f65d8(0)), and clears all enable bits (FUN_a00f66a4(0xff)). Then: 0xcf00ee40 &= 0x3f, |= 0x10;
 * 0xcf00ee68 |= 0x40; 0xcf00ee50 = 0; bits 2..3 of 0xcf00ec80 and 0xcf00eca8 become 2 and bits 4..5 become 2;
 * finally the bodies of FUN_a00f67d0(0..3) clear bits 0 and 1 of 0xcf00ec80 and 0xcf00eca8.
 * Source form: the neighbouring routines are copied here as static functions (GCC inlines every call); the four
 * selector blocks are written out; the record is a local struct filled field by field in the order c, b, a.
 */
#define R(a) (*(volatile unsigned int *)(a))

struct coef {
    unsigned char n;
    unsigned short v[1];
};
struct tab {
    unsigned int mask;
    unsigned char v[24];
};
struct tab17 {
    unsigned int mask;
    unsigned char v[17];
};
struct ace {
    unsigned char a, b, c;
};

extern unsigned char DAT_a802b7b4;
extern struct coef DAT_0019a378;
extern void FUN_a00f2e74(void);
extern void func_0x4008e2a4(void);
extern void FUN_a00f6fe4(unsigned char, unsigned char, void *, unsigned char);
extern int FUN_a00df170(const char *fmt, ...);

static void sel_set(unsigned int p)
{
    if (DAT_a802b7b4 != p) {
        R(0xcf00ec84) = (R(0xcf00ec84) & 0xfc) | p;
        R(0xcf00e980) = (R(0xcf00e980) & 0xfc) | p;
        DAT_a802b7b4 = p;
    }
}

static void cfg_ace(struct ace r)
{
    unsigned char m = 0;

    switch (r.c) {
    case 0:
        m = 0;
        break;
    case 8:
        m = 1;
        break;
    case 16:
        m = 2;
        break;
    }
    R(0xcf00ee80) = (R(0xcf00ee80) & 0xf9) | (DAT_a802b7b4 << 1);
    R(0xcf00eec0) = (R(0xcf00eec0) & 0x3a) | (r.a << 7) | (r.b << 6) | (m << 2);
    FUN_a00df170("Config ACE (%d) : (%d)\r\n", DAT_a802b7b4, r.c);
}

static void coef_load(struct coef *p)
{
    unsigned char i;
    unsigned char v;
    struct coef *t;

    R(0xcf00ee80) = (R(0xcf00ee80) & 0xf9) | (DAT_a802b7b4 << 1);
    R(0xcf00eec0) &= ~0x20;
    v = (R(0xcf00eec4) & 0xf) | 0x50;
    R(0xcf00eec4) = v;
    if (p == 0)
        t = &DAT_0019a378;
    else
        t = p;
    i = 0;
    do {
        R(0xcf00eec8) = t->v[i] & 0xff;
        FUN_a00f2e74();
        R(0xcf00eec8) = t->v[i] >> 8;
        i++;
        FUN_a00f2e74();
    } while (i <= t->n);
    R(0xcf00eec4) = v | 0x90;
    func_0x4008e2a4();
    R(0xcf00ee80) = (R(0xcf00ee80) | (1 << (DAT_a802b7b4 + 4))) & 0xff;
    R(0xcf00eec4) &= ~0x80;
}

static void sel_bit_clear(void)
{
    R(0xcf00ee80) = (unsigned char)(R(0xcf00ee80) & ~(1 << (DAT_a802b7b4 + 4)));
}

static void lut1_load(struct tab *p)
{
    unsigned char i;

    R(0xcf00ef30) &= ~2;
    R(0xcf00ef34) = 1;
    for (i = 0; i <= 0x17; i++) {
        if (p) {
            if ((p->mask >> i) & 1) {
                R(0xcf00ef38) = i;
                R(0xcf00ef3c) = p->v[i];
            }
        } else {
            R(0xcf00ef38) = i;
            R(0xcf00ef3c) = 0;
        }
    }
    R(0xcf00ef30) |= 2;
}

static void lut2_load(struct tab *p)
{
    unsigned char i;

    R(0xcf00ef30) &= ~2;
    R(0xcf00ef34) = 2;
    for (i = 0; i <= 0x17; i++) {
        if (p) {
            if ((p->mask >> i) & 1) {
                R(0xcf00ef38) = i;
                R(0xcf00ef3c) = p->v[i];
            }
        } else {
            R(0xcf00ef38) = i;
            R(0xcf00ef3c) = 0x80;
        }
    }
    R(0xcf00ef30) |= 2;
}

static void lut0_load(struct tab17 *p)
{
    unsigned char i;

    R(0xcf00ef30) &= ~2;
    R(0xcf00ef34) = 0;
    for (i = 0; i <= 0x10; i++) {
        if (p) {
            if ((p->mask >> i) & 1) {
                R(0xcf00ef38) = i;
                R(0xcf00ef3c) = p->v[i];
            }
        } else {
            R(0xcf00ef38) = i;
            R(0xcf00ef3c) = 0x80;
        }
    }
    R(0xcf00ef30) |= 2;
}

static void en_clear(unsigned int m)
{
    if (m & 1)
        R(0xcf00ef00) &= ~0x40u;
    if (m & 2)
        R(0xcf00ef00) &= ~0x20u;
    if (m & 4)
        R(0xcf00ef00) &= ~0x10u;
    if (m & 8)
        R(0xcf00ef00) &= ~8u;
    if (m & 0x10)
        R(0xcf00ef00) &= ~4u;
    if (m & 0x20)
        R(0xcf00ef30) &= ~0x80u;
    if (m & 0x40)
        R(0xcf00ef30) &= ~0x40u;
    if (m & 0x80)
        R(0xcf00ef30) &= ~0x10u;
    if ((R(0xcf00ef30) & 0xe0) == 0)
        R(0xcf00ef30) &= ~1u;
}

static void out_off(int p)
{
    if (p == 0)
        R(0xcf00ec80) &= 0xfe;
    else if (p == 1)
        R(0xcf00ec80) &= 0xfd;
    else if (p == 2)
        R(0xcf00eca8) &= 0xfe;
    else if (p == 3)
        R(0xcf00eca8) &= 0xfd;
}

void FUN_a00f793c(void)
{
    struct ace r;

    r.c = 16;
    r.b = 0;
    r.a = 0;

    sel_set(3);
    FUN_a00f6fe4(1, 2, 0, 0xff);
    cfg_ace(r);
    coef_load(0);
    sel_bit_clear();
    lut1_load(0);
    lut2_load(0);
    lut0_load(0);
    en_clear(0xff);
    sel_set(2);
    FUN_a00f6fe4(1, 2, 0, 0xff);
    cfg_ace(r);
    coef_load(0);
    sel_bit_clear();
    lut1_load(0);
    lut2_load(0);
    lut0_load(0);
    en_clear(0xff);
    sel_set(1);
    FUN_a00f6fe4(1, 2, 0, 0xff);
    cfg_ace(r);
    coef_load(0);
    sel_bit_clear();
    lut1_load(0);
    lut2_load(0);
    lut0_load(0);
    en_clear(0xff);
    sel_set(0);
    FUN_a00f6fe4(1, 2, 0, 0xff);
    cfg_ace(r);
    coef_load(0);
    sel_bit_clear();
    lut1_load(0);
    lut2_load(0);
    lut0_load(0);
    en_clear(0xff);
    R(0xcf00ee40) &= 0x3f;
    R(0xcf00ee40) |= 0x10;
    R(0xcf00ee68) = (R(0xcf00ee68) | 0x40) & 0xff;
    R(0xcf00ee50) = 0;
    R(0xcf00ec80) = (R(0xcf00ec80) & 0xf3) | 8;
    R(0xcf00ec80) = (R(0xcf00ec80) & 0xcf) | 0x20;
    R(0xcf00eca8) = (R(0xcf00eca8) & 0xf3) | 8;
    R(0xcf00eca8) = (R(0xcf00eca8) & 0xcf) | 0x20;
    out_off(0);
    out_off(1);
    out_off(2);
    out_off(3);
}
