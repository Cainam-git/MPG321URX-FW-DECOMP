/* leon2m FUN_a0116914 @ 0xa0116914-0xa0116ff4 (1760 bytes), called by FUN_a0116ff4.
 * Read-modify-writes three registers of the register block selected by port, each write followed by
 * func_0x4008d1a0(1): register 0x2ce = (value & 0x70) | 0x80, then 0x2ce |= 0x8f; the same for 0x2cd; then
 * register 0x5a &= 0x7f, then 0x5a |= 0x80.
 * Register access (inlined static helpers wr/rd, same form as FUN_a0114498 and FUN_a01166d8): the page register
 * (port 0: 0xcf022bf8, port 1: 0xcf0233f8, port 2: 0xcf022ff8) gets bits 8..15 of the register number, then the
 * word at 0xcf000000 | ((base + low byte) << 2) is accessed, base 0x8a00, 0x8c00 or 0x8b00 for port 0, 1, 2;
 * another port accesses nothing and reads 0.
 * Source form: each read is nested in the argument of the write, wr(port, r, rd(port, r) & m); with the value in a
 * separate variable GCC shares one zero-extension of port across the first read and write.
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

void FUN_a0116914(unsigned char port)
{
    wr(port, 0x2ce, (rd(port, 0x2ce) & 0x70) | 0x80);
    func_0x4008d1a0(1);
    wr(port, 0x2ce, rd(port, 0x2ce) | 0x8f);
    func_0x4008d1a0(1);
    wr(port, 0x2cd, (rd(port, 0x2cd) & 0x70) | 0x80);
    func_0x4008d1a0(1);
    wr(port, 0x2cd, rd(port, 0x2cd) | 0x8f);
    func_0x4008d1a0(1);
    wr(port, 0x05a, rd(port, 0x05a) & 0x7f);
    func_0x4008d1a0(1);
    wr(port, 0x05a, rd(port, 0x05a) | 0x80);
    func_0x4008d1a0(1);
}
