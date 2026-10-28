/* FUN_a0089898 (leon2s 0xa0089898-0xa008996c, 212 bytes), flags -mcpu=v8 -Os -g.
 * (u8 port), returns u16. a = FUN_a00a7a5c(port, 0x50); b = 24-bit value from the low bytes of registers 0x53
 * (high), 0x54 and 0x55 (FUN_a00a78b4), 1 when that value is 0. The low byte of register 2 selects
 * k = 0xa2 (6), 0x10e (10), 0x21c (20), 0x32a (30) or 0x21c (any other value); returns a * k / b truncated to
 * 16 bits.
 * Source form: one complete formula per case, as in FUN_a00aceec. FUN_a00a78b4 is declared returning int here;
 * src/leon2s/FUN_a00a78b4.c defines it as returning unsigned int; the firmware compares the switch value signed.
 */
extern int FUN_a00a7a5c(unsigned char port, unsigned short reg);
extern int FUN_a00a78b4(unsigned int, unsigned short);

unsigned short FUN_a0089898(unsigned char port)
{
    unsigned int a, b, m;

    a = FUN_a00a7a5c(port, 0x50);
    b = FUN_a00a78b4(port, 0x53) & 0xff;
    b <<= 8;
    b |= FUN_a00a78b4(port, 0x54) & 0xff;
    b <<= 8;
    b |= FUN_a00a78b4(port, 0x55) & 0xff;
    if (b == 0)
        b = 1;
    switch (FUN_a00a78b4(port, 2) & 0xff) {
    case 6:
        m = a * 0xa2 / b;
        break;
    case 10:
        m = a * 0x10e / b;
        break;
    case 20:
        m = a * 0x21c / b;
        break;
    case 30:
        m = a * 0x32a / b;
        break;
    default:
        m = a * 0x21c / b;
        break;
    }
    return m;
}
