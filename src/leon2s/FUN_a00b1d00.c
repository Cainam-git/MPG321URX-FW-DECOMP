/* FUN_a00b1d00 (leon2s 0xa00b1d00-0xa00b1e2c, 300 bytes), flags -mcpu=v8 -Os -g.
 * Programs a block of 8-bit registers of unit sel through FUN_a00a832c(unit, reg, value): reg 0 = 0 for
 * sel 4 and 6, else 0xd0 (jump table over 0..8); reg 1 = 0xea; for sel 8 also sets bit 7 of register
 * 0xcf0144ac and writes reg 1 of unit 8 = 0xaa; regs 4..6 = bytes 0..2 of a, regs 8..10 = bytes 0..2 of b;
 * then reg 3 = 3, 7, a 1-unit wait (FUN_a00b1794), reg 3 = 3.
 * Source form: every case has its own body; case 8 falls through into the default body (same value),
 * which gives the firmware's block layout after the jump table.
 */
#define R44AC (*(volatile unsigned int *)0xcf0144ac)
extern void FUN_a00a832c(unsigned char, unsigned char, unsigned char);
extern void FUN_a00b1794(int);

void FUN_a00b1d00(unsigned int sel, unsigned int a, unsigned int b)
{
    unsigned char v;
    unsigned char port;

    switch (sel) {
    case 0:
        v = 0xd0;
        break;
    case 1:
        v = 0xd0;
        break;
    case 2:
        v = 0xd0;
        break;
    case 3:
        v = 0xd0;
        break;
    case 4:
        v = 0;
        break;
    case 5:
        v = 0xd0;
        break;
    case 6:
        v = 0;
        break;
    case 7:
        v = 0xd0;
        break;
    case 8:
        v = 0xd0;
    default:
        v = 0xd0;
        break;
    }
    port = sel;
    FUN_a00a832c(port, 0, v);
    FUN_a00a832c(port, 1, 0xea);
    if (sel == 8) {
        R44AC |= 0x80;
        FUN_a00a832c(8, 1, 0xaa);
    }
    FUN_a00a832c(port, 4, a);
    FUN_a00a832c(port, 5, a >> 8);
    FUN_a00a832c(port, 6, a >> 16);
    FUN_a00a832c(port, 8, b);
    FUN_a00a832c(port, 9, b >> 8);
    FUN_a00a832c(port, 10, b >> 16);
    FUN_a00a832c(port, 3, 3);
    FUN_a00a832c(port, 3, 7);
    FUN_a00b1794(1);
    FUN_a00a832c(port, 3, 3);
}
