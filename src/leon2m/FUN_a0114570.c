/* leon2m FUN_a0114570 @ 0xa0114570-0xa0114650 (224 bytes), no direct callers; the same code appears inline in
 * FUN_a0114650, FUN_a0116914 and FUN_a0116ff4.
 * Reads one register of a register block selected by port and returns its low byte: the page register
 * (port 0: 0xcf022bf8, port 1: 0xcf0233f8, port 2: 0xcf022ff8) gets bits 8..15 of reg, then the word at
 * 0xcf000000 | ((base + low byte of reg) << 2) is read, with base 0x8a00, 0x8c00 or 0x8b00 for port 0, 1, 2.
 * Another port reads nothing and returns 0.
 * Source form: the result is an unsigned char cleared first; the port cases are written in the order 0, 2, 1
 * (same form as FUN_a01166d8 and the write routine FUN_a0114498).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

unsigned char FUN_a0114570(unsigned char port, unsigned short reg)
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
