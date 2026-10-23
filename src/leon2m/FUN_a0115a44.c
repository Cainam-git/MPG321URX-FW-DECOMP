/* leon2m FUN_a0115a44 @ 0xa0115a44-0xa0115bd4 (400 bytes), no direct callers; the same code appears inline in
 * FUN_a0115bd4.
 * Read-modify-write of one register of the register block selected by port (write counterpart of FUN_a011579c):
 * off = 0xc8 for sel 0 and 1, 0xc9 for sel 2 and 3, else 0. The page register (port 0: 0xcf022bf8, port 1:
 * 0xcf0233f8, port 2: 0xcf022ff8) gets bits 8..15 of off, which are 0 for every value off can take; then the word
 * at 0xcf000000 | ((base + low byte of off) << 2), base 0x8a00, 0x8c00 or 0x8b00 for port 0, 1, 2, is read and
 * written back as (word & 0xf0) | (val & 0xf) for sel 0 and 2, else as (word & 0xf) | (val << 4).
 * Another port writes nothing.
 * Source form: the page register value is written as (unsigned char)(off >> 8), as in FUN_a0114498; GCC folds it
 * to a stored 0, and the written-out form places the store ahead of the sel test (a literal 0 does not).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

void FUN_a0115a44(unsigned char port, unsigned short sel, unsigned char val)
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
