/* leon2m FUN_a011579c @ 0xa011579c-0xa01158b4 (280 bytes), no direct callers; the same code appears inline in
 * FUN_a0115bd4.
 * Same as FUN_a0115684 with register offsets 0xc8 / 0xc9: off = 0xc8 for sel 0 and 1, 0xc9 for sel 2 and 3,
 * else 0. The page register of the port (port 0: 0xcf022bf8, port 1: 0xcf0233f8, port 2: 0xcf022ff8) is set to 0
 * and the word at 0xcf000000 | ((base + off) << 2) is read, with base 0x8a00, 0x8c00 or 0x8b00 for port 0, 1, 2.
 * Returns the low nibble for sel 0 and 2, the high nibble for sel 1 and 3, else the whole byte; another port
 * reads nothing and returns 0.
 * Source form: as FUN_a0115684 (v an unsigned char cleared before off, port cases in the order 0, 2, 1).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

unsigned char FUN_a011579c(unsigned char port, unsigned short sel)
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
