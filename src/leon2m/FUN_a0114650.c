/* leon2m FUN_a0114650 @ 0xa0114650-0xa011552c (3804 bytes), called by FUN_a011552c.
 * For port 0, 1 and 2 in turn: writes 0xf0 to registers 0x149, 0x14b, 0x14a, 0x14c and 0 to 0x129, 0x12a, 0x12b;
 * reads 0x125 and writes 0 to it; then clears single bits by read-modify-write: 0xe1 bit 1 then bit 0, 0xe3 bit 1
 * then bit 0, 0xe5 bit 6 then bit 5, 0xd8 bit 1 then bit 0, 0xd7 bits 7, 6, 5, 0xbe bit 7, 0xd7 bit 1.
 * Register access (inlined static helpers wr/rd, same form as FUN_a0114498 and FUN_a01166d8): the page register
 * (port 0: 0xcf022bf8, port 1: 0xcf0233f8, port 2: 0xcf022ff8) gets bits 8..15 of the register number, then the
 * word at 0xcf000000 | ((base + low byte) << 2) is accessed, base 0x8a00, 0x8c00 or 0x8b00 for port 0, 1, 2.
 * Source form: one unsigned char v holds every value read (also the unused read of 0x125); each mask is applied
 * as a separate statement v &= m. The port cases are written in the order 0, 2, 1.
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

void FUN_a0114650(void)
{
    unsigned char port;
    unsigned char v;

    for (port = 0; port < 3; port++) {
        wr(port, 0x149, 0xf0);
        wr(port, 0x14b, 0xf0);
        wr(port, 0x14a, 0xf0);
        wr(port, 0x14c, 0xf0);
        wr(port, 0x129, 0);
        wr(port, 0x12a, 0);
        wr(port, 0x12b, 0);
        v = rd(port, 0x125);
        wr(port, 0x125, 0);
        v = rd(port, 0x0e1);
        v &= 0xfd;
        wr(port, 0x0e1, v);
        v = rd(port, 0x0e1);
        v &= 0xfe;
        wr(port, 0x0e1, v);
        v = rd(port, 0x0e3);
        v &= 0xfd;
        wr(port, 0x0e3, v);
        v = rd(port, 0x0e3);
        v &= 0xfe;
        wr(port, 0x0e3, v);
        v = rd(port, 0x0e5);
        v &= 0xbf;
        wr(port, 0x0e5, v);
        v = rd(port, 0x0e5);
        v &= 0xdf;
        wr(port, 0x0e5, v);
        v = rd(port, 0x0d8);
        v &= 0xfd;
        wr(port, 0x0d8, v);
        v = rd(port, 0x0d8);
        v &= 0xfe;
        wr(port, 0x0d8, v);
        v = rd(port, 0x0d7);
        v &= 0x7f;
        wr(port, 0x0d7, v);
        v = rd(port, 0x0d7);
        v &= 0xbf;
        wr(port, 0x0d7, v);
        v = rd(port, 0x0d7);
        v &= 0xdf;
        wr(port, 0x0d7, v);
        v = rd(port, 0x0be);
        v &= 0x7f;
        wr(port, 0x0be, v);
        v = rd(port, 0x0d7);
        v &= 0xfd;
        wr(port, 0x0d7, v);
    }
}
