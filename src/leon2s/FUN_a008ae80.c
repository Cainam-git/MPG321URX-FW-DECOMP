/* leon2s FUN_a008ae80 @ 0xa008ae80 (-mcpu=v8 -Os -g)
 * Switch on mode (jump table, 1..0x13) with an on/off byte: 3 / 0x13 clear / set bit 0 of register 0xcf0111d4,
 * then pulse bit 0 of 0xcf011118 and bit 3 of 0xcf0111dc (set, then clear) and set bit 7 of 0xcf011148; 1 / 0x11
 * write 0xf4 / 0xf2 to 0xcf0110c0; 2 writes 0 then 0x87 to 0xcf011148 (these only when on is non-zero).
 * 8 / 10 write fields 0x127 (0x20, 0x10) and 0x129 (4, 1, 2) of unit 0 / 1 to on through FUN_a00a67b8 and field
 * 0x137 bit 1 to !on; 0xc / 0xe call FUN_a00a1bb0(0 / 1, on); 4 / 6 write bit 7 of fields 0x55, 0x58, 0x5a of unit
 * 0 / 1 to on through FUN_a00a6c98; for 4 with on set, field 0x7d bit 4 and FUN_a00a6c00(0, 0x7e, 0xff / 0) follow
 * the result of func_0x9f1c6694(0). Other modes do nothing.
 * Source form: the case bodies are listed in the order 3, 0x13, 1, 0x11, 2, 8, 10, 0xc, 0xe, 4, 6; each case
 * writes its full sequence (GCC shares the common tails).
 */
#define R10C0 (*(volatile unsigned int *)0xcf0110c0)
#define R1118 (*(volatile unsigned int *)0xcf011118)
#define R1148 (*(volatile unsigned int *)0xcf011148)
#define R11D4 (*(volatile unsigned int *)0xcf0111d4)
#define R11DC (*(volatile unsigned int *)0xcf0111dc)

extern void FUN_a00a67b8(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a1bb0(unsigned char, unsigned char);
extern unsigned char func_0x9f1c6694(unsigned char);

void FUN_a008ae80(unsigned char mode, unsigned char on)
{
    switch (mode) {
    case 3:
        if (on) {
            R11D4 &= ~1;
            R1118 |= 1;
            R1118 &= ~1;
            R11DC |= 8;
            R11DC &= ~8;
            R1148 |= 0x80;
        }
        break;
    case 0x13:
        if (on) {
            R11D4 |= 1;
            R1118 |= 1;
            R1118 &= ~1;
            R11DC |= 8;
            R11DC &= ~8;
            R1148 |= 0x80;
        }
        break;
    case 1:
        if (on)
            R10C0 = 0xf4;
        break;
    case 0x11:
        if (on)
            R10C0 = 0xf2;
        break;
    case 2:
        if (on) {
            R1148 = 0;
            R1148 = 0x87;
        }
        break;
    case 8:
        if (on) {
            FUN_a00a67b8(0, 0x127, 0x20, 1);
            FUN_a00a67b8(0, 0x127, 0x10, 1);
            FUN_a00a67b8(0, 0x129, 4, 1);
            FUN_a00a67b8(0, 0x129, 1, 1);
            FUN_a00a67b8(0, 0x129, 2, 1);
            FUN_a00a67b8(0, 0x137, 2, 0);
        } else {
            FUN_a00a67b8(0, 0x127, 0x20, 0);
            FUN_a00a67b8(0, 0x127, 0x10, 0);
            FUN_a00a67b8(0, 0x129, 4, 0);
            FUN_a00a67b8(0, 0x129, 1, 0);
            FUN_a00a67b8(0, 0x129, 2, 0);
            FUN_a00a67b8(0, 0x137, 2, 1);
        }
        break;
    case 10:
        if (on) {
            FUN_a00a67b8(1, 0x127, 0x20, 1);
            FUN_a00a67b8(1, 0x127, 0x10, 1);
            FUN_a00a67b8(1, 0x129, 4, 1);
            FUN_a00a67b8(1, 0x129, 1, 1);
            FUN_a00a67b8(1, 0x129, 2, 1);
            FUN_a00a67b8(1, 0x137, 2, 0);
        } else {
            FUN_a00a67b8(1, 0x127, 0x20, 0);
            FUN_a00a67b8(1, 0x127, 0x10, 0);
            FUN_a00a67b8(1, 0x129, 4, 0);
            FUN_a00a67b8(1, 0x129, 1, 0);
            FUN_a00a67b8(1, 0x129, 2, 0);
            FUN_a00a67b8(1, 0x137, 2, 1);
        }
        break;
    case 0xc:
        FUN_a00a1bb0(0, on);
        break;
    case 0xe:
        FUN_a00a1bb0(1, on);
        break;
    case 4:
        if (on) {
            FUN_a00a6c98(0, 0x55, 0x80, 1);
            FUN_a00a6c98(0, 0x58, 0x80, 1);
            FUN_a00a6c98(0, 0x5a, 0x80, 1);
            if (func_0x9f1c6694(0)) {
                FUN_a00a6c98(0, 0x7d, 0x10, 1);
                FUN_a00a6c00(0, 0x7e, 0xff);
            } else {
                FUN_a00a6c98(0, 0x7d, 0x10, 0);
                FUN_a00a6c00(0, 0x7e, 0);
            }
        } else {
            FUN_a00a6c98(0, 0x55, 0x80, 0);
            FUN_a00a6c98(0, 0x58, 0x80, 0);
            FUN_a00a6c98(0, 0x5a, 0x80, 0);
        }
        break;
    case 6:
        if (on) {
            FUN_a00a6c98(1, 0x55, 0x80, 1);
            FUN_a00a6c98(1, 0x58, 0x80, 1);
            FUN_a00a6c98(1, 0x5a, 0x80, 1);
        } else {
            FUN_a00a6c98(1, 0x55, 0x80, 0);
            FUN_a00a6c98(1, 0x58, 0x80, 0);
            FUN_a00a6c98(1, 0x5a, 0x80, 0);
        }
        break;
    }
}
