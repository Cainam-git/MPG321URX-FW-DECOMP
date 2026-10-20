/* leon2m FUN_a01166d8 @ 0xa01166d8-0xa01167ec (276 bytes), called by FUN_a014d5f4.
 * Reads one register of a register block selected by port and returns its low byte. sel 0..3 selects register
 * number 0x161..0x164 (else 0); the page register (port 0: 0xcf022bf8, port 1: 0xcf0233f8, port 2: 0xcf022ff8)
 * gets bits 8..15 of the number, then the word at 0xcf000000 | ((base + low byte) << 2) is read, with base 0x8a00,
 * 0x8c00 or 0x8b00 for port 0, 1, 2. Another port reads nothing and returns 0.
 * Source form: the number is an unsigned short split with unsigned char casts; the result is an unsigned char
 * cleared first; the port cases are written in the order 0, 2, 1 (same form as FUN_a0115684).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

unsigned char FUN_a01166d8(unsigned char port, unsigned short sel)
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
