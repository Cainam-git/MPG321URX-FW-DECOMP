/* leon2m FUN_a0115bd4 @ 0xa0115bd4-0xa01166d8 (2820 bytes), called by FUN_a0117f48.
 * Port register blocks as in FUN_a0115684 (page register 0xcf022bf8 / 0xcf0233f8 / 0xcf022ff8, data
 * 0xcf000000 | ((0x8a00 / 0x8c00 / 0x8b00 + offset) << 2) for port 0 / 1 / 2). sel 0 and 2 select the low nibble,
 * sel 1 and 3 the high nibble of register offset 0xc6 (sel 0, 1) or 0xc7 (sel 2, 3), and in the same way of
 * offset 0xc8 / 0xc9.
 * Steps: n1 = nibble at 0xc6/0xc7 (rdnib1, the body of FUN_a0115684), n2 = nibble at 0xc8/0xc9 (rdnib2, the body
 * of FUN_a011579c); the byte of 0xcf012e00 is saved; 0xcf013800 = 0. When x != 7, n1 and n2 are both moved by
 * x - 7 (modulo 16) and written by wrnib1 / wrnib2 (the bodies of FUN_a01158b4 / FUN_a0115a44), each followed by
 * func_0x4008d1a0(1). Then 0xcf012e40 = 0x71, FUN_a01185d4(), FUN_a0118a28(0, 0); r = meas(0); 0xcf013800 = 0x30;
 * r = meas(r) (meas as in FUN_a0116ff4: writes 0x11, 1, 0x81 to 0xcf012e00 and 2, 5 to 0xcf012f2c with delays
 * 0x28, 0x28, 0x14, 0x14, 0x14, reads the bytes a, b, c, d of 0xcf012f30..0xcf012f3c, sets c = 0 when bit 7 of
 * 0xcf012f2c is clear and a == 0, b == 0, c == 0x10, d == 0, and returns acc | (a + b + c + d)).
 * Finally 0xcf012e00 = saved byte, FUN_a011855c(), n1 and n2 are written back with wrnib1 / wrnib2 (each followed by
 * func_0x4008d1a0(1)), and r is returned.
 * Source form: the four nibble helpers are static copies of FUN_a0115684, FUN_a011579c, FUN_a01158b4 and
 * FUN_a0115a44; the two writers are declared inline (without it GCC calls them instead of inlining both copies) and
 * write the page register as (unsigned char)(off >> 8) like the standalone writers. The x > 7 arm is written as
 * 'else if (x > 7)' (a plain else gives a different block layout).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

extern void func_0x4008d1a0(int ms);
extern void FUN_a01185d4(void);
extern void FUN_a0118a28(unsigned char, unsigned char);
extern void FUN_a011855c(void);

static unsigned char rdnib1(unsigned char port, unsigned short sel)
{
    unsigned short off;
    unsigned char v;

    v = 0;
    off = 0;
    switch (sel) {
    case 0:
    case 1:
        off = 0xc6;
        break;
    case 2:
    case 3:
        off = 0xc7;
        break;
    }
    switch (port) {
    case 0:
        REG(0xcf022bf8) = 0;
        v = PREG(0x8a00 + (unsigned char)off);
        break;
    case 2:
        REG(0xcf022ff8) = 0;
        v = PREG(0x8b00 + (unsigned char)off);
        break;
    case 1:
        REG(0xcf0233f8) = 0;
        v = PREG(0x8c00 + (unsigned char)off);
        break;
    }
    switch (sel) {
    case 0:
    case 2:
        v = v & 0xf;
        break;
    case 1:
    case 3:
        v = v >> 4;
        break;
    }
    return v;
}

static unsigned char rdnib2(unsigned char port, unsigned short sel)
{
    unsigned short off;
    unsigned char v;

    v = 0;
    off = 0;
    switch (sel) {
    case 0:
    case 1:
        off = 0xc8;
        break;
    case 2:
    case 3:
        off = 0xc9;
        break;
    }
    switch (port) {
    case 0:
        REG(0xcf022bf8) = 0;
        v = PREG(0x8a00 + (unsigned char)off);
        break;
    case 2:
        REG(0xcf022ff8) = 0;
        v = PREG(0x8b00 + (unsigned char)off);
        break;
    case 1:
        REG(0xcf0233f8) = 0;
        v = PREG(0x8c00 + (unsigned char)off);
        break;
    }
    switch (sel) {
    case 0:
    case 2:
        v = v & 0xf;
        break;
    case 1:
    case 3:
        v = v >> 4;
        break;
    }
    return v;
}

static inline void wrnib1(unsigned char port, unsigned short sel, unsigned char val)
{
    unsigned short off;

    off = 0;
    switch (sel) {
    case 0:
    case 1:
        off = 0xc6;
        break;
    case 2:
    case 3:
        off = 0xc7;
        break;
    }
    switch (port) {
    case 0:
        REG(0xcf022bf8) = (unsigned char)(off >> 8);
        if (sel == 0 || sel == 2)
            PREG(0x8a00 + (unsigned char)off) = (PREG(0x8a00 + (unsigned char)off) & 0xf0) | (val & 0xf);
        else
            PREG(0x8a00 + (unsigned char)off) = (PREG(0x8a00 + (unsigned char)off) & 0xf) | (val << 4);
        break;
    case 2:
        REG(0xcf022ff8) = (unsigned char)(off >> 8);
        if (sel == 0 || sel == 2)
            PREG(0x8b00 + (unsigned char)off) = (PREG(0x8b00 + (unsigned char)off) & 0xf0) | (val & 0xf);
        else
            PREG(0x8b00 + (unsigned char)off) = (PREG(0x8b00 + (unsigned char)off) & 0xf) | (val << 4);
        break;
    case 1:
        REG(0xcf0233f8) = (unsigned char)(off >> 8);
        if (sel == 0 || sel == 2)
            PREG(0x8c00 + (unsigned char)off) = (PREG(0x8c00 + (unsigned char)off) & 0xf0) | (val & 0xf);
        else
            PREG(0x8c00 + (unsigned char)off) = (PREG(0x8c00 + (unsigned char)off) & 0xf) | (val << 4);
        break;
    }
}

static inline void wrnib2(unsigned char port, unsigned short sel, unsigned char val)
{
    unsigned short off;

    off = 0;
    switch (sel) {
    case 0:
    case 1:
        off = 0xc8;
        break;
    case 2:
    case 3:
        off = 0xc9;
        break;
    }
    switch (port) {
    case 0:
        REG(0xcf022bf8) = (unsigned char)(off >> 8);
        if (sel == 0 || sel == 2)
            PREG(0x8a00 + (unsigned char)off) = (PREG(0x8a00 + (unsigned char)off) & 0xf0) | (val & 0xf);
        else
            PREG(0x8a00 + (unsigned char)off) = (PREG(0x8a00 + (unsigned char)off) & 0xf) | (val << 4);
        break;
    case 2:
        REG(0xcf022ff8) = (unsigned char)(off >> 8);
        if (sel == 0 || sel == 2)
            PREG(0x8b00 + (unsigned char)off) = (PREG(0x8b00 + (unsigned char)off) & 0xf0) | (val & 0xf);
        else
            PREG(0x8b00 + (unsigned char)off) = (PREG(0x8b00 + (unsigned char)off) & 0xf) | (val << 4);
        break;
    case 1:
        REG(0xcf0233f8) = (unsigned char)(off >> 8);
        if (sel == 0 || sel == 2)
            PREG(0x8c00 + (unsigned char)off) = (PREG(0x8c00 + (unsigned char)off) & 0xf0) | (val & 0xf);
        else
            PREG(0x8c00 + (unsigned char)off) = (PREG(0x8c00 + (unsigned char)off) & 0xf) | (val << 4);
        break;
    }
}

static unsigned char meas(unsigned char acc)
{
    unsigned char a, b, c, d;

    REG(0xcf012e00) = 0x11;
    func_0x4008d1a0(0x28);
    REG(0xcf012e00) = 1;
    func_0x4008d1a0(0x28);
    REG(0xcf012e00) = 0x81;
    func_0x4008d1a0(0x14);
    REG(0xcf012f2c) = 2;
    func_0x4008d1a0(0x14);
    REG(0xcf012f2c) = 5;
    func_0x4008d1a0(0x14);
    a = REG(0xcf012f30);
    b = REG(0xcf012f34);
    c = REG(0xcf012f38);
    d = REG(0xcf012f3c);
    if (!(REG(0xcf012f2c) & 0x80) && a == 0 && b == 0 && c == 0x10 && d == 0)
        c = 0;
    return acc | (a + b + c + d);
}

unsigned char FUN_a0115bd4(unsigned char port, unsigned short sel, unsigned char x)
{
    unsigned char n1, n2, a, b, saved, r;

    a = 0;
    b = 0;
    n1 = rdnib1(port, sel);
    n2 = rdnib2(port, sel);
    saved = REG(0xcf012e00);
    REG(0xcf013800) = 0;
    if (x != 7) {
        if (x < 7) {
            a = (n1 - (7 - x)) & 0xf;
            b = (n2 - (7 - x)) & 0xf;
        } else if (x > 7) {
            a = (n1 + (x - 7)) & 0xf;
            b = (n2 + (x - 7)) & 0xf;
        }
        wrnib1(port, sel, a);
        func_0x4008d1a0(1);
        wrnib2(port, sel, b);
        func_0x4008d1a0(1);
    }
    REG(0xcf012e40) = 0x71;
    FUN_a01185d4();
    FUN_a0118a28(0, 0);
    r = meas(0);
    REG(0xcf013800) = 0x30;
    r = meas(r);
    REG(0xcf012e00) = saved;
    FUN_a011855c();
    wrnib1(port, sel, n1);
    func_0x4008d1a0(1);
    wrnib2(port, sel, n2);
    func_0x4008d1a0(1);
    return r;
}
