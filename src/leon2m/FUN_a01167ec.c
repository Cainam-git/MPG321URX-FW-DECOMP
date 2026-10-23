/* leon2m FUN_a01167ec @ 0xa01167ec-0xa0116914 (296 bytes), no direct callers; the same code appears inline in
 * FUN_a0116ff4.
 * Write counterpart of FUN_a01166d8: sel 0..3 selects register number 0x161..0x164 (else 0), and val is written
 * to that register of the register block selected by port: the page register (port 0: 0xcf022bf8, port 1:
 * 0xcf0233f8, port 2: 0xcf022ff8) gets bits 8..15 of the number, then val is stored to the word at
 * 0xcf000000 | ((base + low byte) << 2), with base 0x8a00, 0x8c00 or 0x8b00 for port 0, 1, 2. Another port
 * writes nothing.
 * Source form: the write is a static copy of FUN_a0114498 (wr) that GCC inlines.
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

void FUN_a01167ec(unsigned char port, unsigned short sel, unsigned char val)
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
