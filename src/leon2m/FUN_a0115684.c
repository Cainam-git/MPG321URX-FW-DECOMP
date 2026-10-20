/* leon2m FUN_a0115684 @ 0xa0115684-0xa011579c (280 bytes), called by FUN_a014d5f4.
 * Reads one byte of a register block selected by port: port 0 uses the page register 0xcf022bf8 and the data
 * registers 0xcf000000 | ((0x8a00 + off) << 2), port 1 0xcf0233f8 and index base 0x8c00, port 2 0xcf022ff8 and
 * index base 0x8b00; another port reads nothing (value 0). The page register is set to 0 before the read.
 * off = 0xc6 for sel 0 and 1, 0xc7 for sel 2 and 3, else 0. Returns the low nibble for sel 0 and 2, the high
 * nibble for sel 1 and 3, else the whole byte.
 * Source form: v is an unsigned char (the word read is copied into it at the join), off an unsigned short passed
 * through an unsigned char cast; the port cases are written in the order 0, 2, 1 and v is cleared before off.
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

unsigned char FUN_a0115684(unsigned char port, unsigned short sel)
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
