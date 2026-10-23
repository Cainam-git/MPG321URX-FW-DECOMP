/* leon2s FUN_a00a88b8 @ 0xa00a88b8-0xa00a89c0, -mcpu=v8 -Os -g.
 * (u8 port, u8 sel, u8 mode), returns 1 or 0. sel 0x31, 0x41, 0x51, 0x71, 0x81, 0x61 gives the value
 * v = 0, 1, 2, 3, 4, 5; any other sel gives v = 0 and result 0. mode 0: FUN_a00a6428(DAT_a807874c[port],
 * 7, v & 7); mode 1: the same with DAT_a8078758[port]; mode 2: FUN_a00a6428(DAT_a8078758[port], 0x70,
 * (v << 4) & 0x70); other modes: no write, result 0. The two tables hold register pointers.
 * Source form: result r = 1 cleared per failing case, returned as r & 1; the shifted value is truncated
 * to a byte before the and.
 */
extern volatile unsigned int *DAT_a807874c[];
extern volatile unsigned int *DAT_a8078758[];
extern void FUN_a00a6428(volatile unsigned int *, unsigned int, unsigned int);

unsigned char FUN_a00a88b8(unsigned char port, unsigned char sel, unsigned char mode)
{
    unsigned char r = 1;
    unsigned char v;

    switch (sel) {
    case 0x31: v = 0; break;
    case 0x41: v = 1; break;
    case 0x51: v = 2; break;
    case 0x71: v = 3; break;
    case 0x81: v = 4; break;
    case 0x61: v = 5; break;
    default: v = 0; r = 0; break;
    }
    switch (mode) {
    case 0:
        FUN_a00a6428(DAT_a807874c[port], 7, v & 7);
        break;
    case 1:
        FUN_a00a6428(DAT_a8078758[port], 7, v & 7);
        break;
    case 2:
        FUN_a00a6428(DAT_a8078758[port], 0x70, (unsigned char)(v << 4) & 0x70);
        break;
    default:
        r = 0;
        break;
    }
    return r & 1;
}
