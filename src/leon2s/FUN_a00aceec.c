/* leon2s FUN_a00aceec @ 0xa00aceec-0xa00acff4, -mcpu=v8 -Os -g.
 * (u8 port), returns u16. a = FUN_a00a6f08(port, 0x63); b = 24-bit value from the low bytes of registers
 * 0x68 (high), 0x67, 0x66 (FUN_a00a6bb8). Returns 0 when a or b is 0. Otherwise k = 0xa2, 0x10e, 0x21c or
 * 0x32a for bits 0..1 of register 0x80 = 0..3, and the result is ((a * k / b) * 10000) >> 9 (unsigned),
 * truncated to 16 bits.
 * Source form: FUN_a00a6f08 is declared returning int here (the firmware uses its full register without
 * a zero-extension); one complete formula per case.
 */
extern int FUN_a00a6f08(unsigned char, unsigned short);
extern int FUN_a00a6bb8(unsigned char, unsigned short);

unsigned short FUN_a00aceec(unsigned char port)
{
    unsigned int a, b;
    unsigned int r = 0;

    a = FUN_a00a6f08(port, 0x63);
    b = FUN_a00a6bb8(port, 0x68) & 0xff;
    b <<= 8;
    b |= FUN_a00a6bb8(port, 0x67) & 0xff;
    b <<= 8;
    b |= FUN_a00a6bb8(port, 0x66) & 0xff;
    if (a == 0 || b == 0)
        return 0;
    switch (FUN_a00a6bb8(port, 0x80) & 3) {
    case 0:
        r = (a * 0xa2 / b) * 10000 >> 9;
        break;
    case 1:
        r = (a * 0x10e / b) * 10000 >> 9;
        break;
    case 2:
        r = (a * 0x21c / b) * 10000 >> 9;
        break;
    case 3:
        r = (a * 0x32a / b) * 10000 >> 9;
        break;
    }
    return r;
}
