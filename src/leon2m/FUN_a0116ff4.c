/* leon2m FUN_a0116ff4 @ 0xa0116ff4-0xa0117f48 (3924 bytes), called by FUN_a0117f48.
 * Port register blocks as in FUN_a0114498 / FUN_a01166d8 (page register 0xcf022bf8 / 0xcf0233f8 / 0xcf022ff8,
 * data 0xcf000000 | ((0x8a00 / 0x8c00 / 0x8b00 + low byte) << 2) for port 0 / 1 / 2); sel 0..3 selects register
 * 0x161..0x164.
 * Steps: orig = the byte of register sel (rdsel, the body of FUN_a01166d8); the byte of 0xcf012e00 is saved;
 * 0xcf013800 = 0. When x != 7: nv = orig - (7 - x) * 16 for x < 7 (0 when bits 4..7 of the result are all set),
 * orig + x * 16 - 0x70 for x > 7, written by setsel: 0x008 = (0x008 & 0xdf) | 0x20, 0x251 = (0x251 & 0xbf) | 0x40,
 * register sel = nv, 0x008 &= 0xdf, 0x251 &= 0xbf, each followed by func_0x4008d1a0(1).
 * Then FUN_a0116914(port) twice, 0xcf012e40 = 0x71, FUN_a01185d4(), FUN_a0118a28(0, 0). meas writes 0x11, 1, 0x81
 * to 0xcf012e00 and 2, 5 to 0xcf012f2c with delays 0x28, 0x28, 0x14, 0x14, 0x14, reads the bytes a, b, c, d of
 * 0xcf012f30..0xcf012f3c, sets c = 0 when bit 7 of 0xcf012f2c is clear and a == 0, b == 0, c == 0x10, d == 0,
 * and returns acc | (a + b + c + d). r = meas(0); 0xcf013800 = 0x30; r = meas(r); 0xcf012e00 = saved byte;
 * FUN_a011855c(); setsel writes orig back; FUN_a0116914(port) twice; returns r.
 * Source form: wr/rd as in FUN_a0116914 (read nested in the write argument); the OR of the two meas results is
 * inside the helper's return expression (with r |= meas() GCC keeps a zero-extension of the second sum);
 * setsel is declared inline (without it GCC calls it instead of inlining both copies).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

static void wr(unsigned char port, unsigned short reg, unsigned char val)
{
    switch (port) {
    case 0:
        REG(0xcf022bf8) = (unsigned char)(reg >> 8);
        PREG(0x8a00 + (unsigned char)reg) = val;
        break;
    case 2:
        REG(0xcf022ff8) = (unsigned char)(reg >> 8);
        PREG(0x8b00 + (unsigned char)reg) = val;
        break;
    case 1:
        REG(0xcf0233f8) = (unsigned char)(reg >> 8);
        PREG(0x8c00 + (unsigned char)reg) = val;
        break;
    }
}

static unsigned char rd(unsigned char port, unsigned short reg)
{
    unsigned char v;

    v = 0;
    switch (port) {
    case 0:
        REG(0xcf022bf8) = (unsigned char)(reg >> 8);
        v = PREG(0x8a00 + (unsigned char)reg);
        break;
    case 2:
        REG(0xcf022ff8) = (unsigned char)(reg >> 8);
        v = PREG(0x8b00 + (unsigned char)reg);
        break;
    case 1:
        REG(0xcf0233f8) = (unsigned char)(reg >> 8);
        v = PREG(0x8c00 + (unsigned char)reg);
        break;
    }
    return v;
}

extern void func_0x4008d1a0(int ms);
extern void FUN_a0116914(unsigned char port);
extern void FUN_a01185d4(void);
extern void FUN_a0118a28(unsigned char, unsigned char);
extern void FUN_a011855c(void);

static unsigned char rdsel(unsigned char port, unsigned short sel)
{
    unsigned short reg;
    unsigned char v;

    v = 0;
    reg = 0;
    switch (sel) {
    case 0:
        reg = 0x161;
        break;
    case 1:
        reg = 0x162;
        break;
    case 2:
        reg = 0x163;
        break;
    case 3:
        reg = 0x164;
        break;
    }
    switch (port) {
    case 0:
        REG(0xcf022bf8) = (unsigned char)(reg >> 8);
        v = PREG(0x8a00 + (unsigned char)reg);
        break;
    case 2:
        REG(0xcf022ff8) = (unsigned char)(reg >> 8);
        v = PREG(0x8b00 + (unsigned char)reg);
        break;
    case 1:
        REG(0xcf0233f8) = (unsigned char)(reg >> 8);
        v = PREG(0x8c00 + (unsigned char)reg);
        break;
    }
    return v;
}

static void wrsel(unsigned char port, unsigned short sel, unsigned char val)
{
    unsigned short reg;

    reg = 0;
    switch (sel) {
    case 0:
        reg = 0x161;
        break;
    case 1:
        reg = 0x162;
        break;
    case 2:
        reg = 0x163;
        break;
    case 3:
        reg = 0x164;
        break;
    }
    wr(port, reg, val);
}

static inline void setsel(unsigned char port, unsigned short sel, unsigned char val)
{
    wr(port, 0x008, (rd(port, 0x008) & 0xdf) | 0x20);
    func_0x4008d1a0(1);
    wr(port, 0x251, (rd(port, 0x251) & 0xbf) | 0x40);
    func_0x4008d1a0(1);
    wrsel(port, sel, val);
    func_0x4008d1a0(1);
    wr(port, 0x008, rd(port, 0x008) & 0xdf);
    func_0x4008d1a0(1);
    wr(port, 0x251, rd(port, 0x251) & 0xbf);
    func_0x4008d1a0(1);
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

unsigned char FUN_a0116ff4(unsigned char port, unsigned short sel, unsigned char x)
{
    unsigned char orig, nv, saved, r;

    nv = 0;
    orig = rdsel(port, sel);
    saved = REG(0xcf012e00);
    REG(0xcf013800) = 0;
    if (x != 7) {
        if (x < 7) {
            nv = orig - (7 - x) * 16;
            if ((nv & 0xf0) == 0xf0)
                nv = 0;
        } else if (x > 7) {
            nv = orig + x * 16 - 0x70;
        }
        setsel(port, sel, nv);
    }
    FUN_a0116914(port);
    FUN_a0116914(port);
    REG(0xcf012e40) = 0x71;
    FUN_a01185d4();
    FUN_a0118a28(0, 0);
    r = meas(0);
    REG(0xcf013800) = 0x30;
    r = meas(r);
    REG(0xcf012e00) = saved;
    FUN_a011855c();
    setsel(port, sel, orig);
    FUN_a0116914(port);
    FUN_a0116914(port);
    return r;
}
