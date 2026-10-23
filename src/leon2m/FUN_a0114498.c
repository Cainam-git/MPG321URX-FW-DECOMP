/* leon2m FUN_a0114498 @ 0xa0114498-0xa0114570 (216 bytes), no direct callers found.
 * Writes val to one register of a register block selected by port: the page register (port 0: 0xcf022bf8,
 * port 1: 0xcf0233f8, port 2: 0xcf022ff8) gets bits 8..15 of reg, then val is stored to the word at
 * 0xcf000000 | ((base + low byte of reg) << 2), with base 0x8a00, 0x8c00 or 0x8b00 for port 0, 1, 2.
 * Another port writes nothing.
 * Source form: reg is an unsigned short split with unsigned char casts; the port cases are written in the order
 * 0, 2, 1 (same form as FUN_a0115684 and FUN_a01166d8).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

void FUN_a0114498(unsigned char port, unsigned short reg, unsigned char val)
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
