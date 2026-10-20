/* FUN_a00aee08 (leon2s 0xa00aee08-0xa00aef04, 252 bytes), flags -mcpu=v8 -Os -g.
 * Loads a 16-bit value and an n-bit mask into port registers: sets bit 3 of reg 0x482, saves the
 * bytes of regs 0x89/0x8a, sets bit 6 of reg 0x9f and bit 2 of reg 0x32, writes the saved bytes back,
 * writes the high and low byte of val to regs 0x8b/0x8c and ((1 << n) - 1) to reg 0x9a (built bit by bit),
 * then clears bit 6 of reg 0x9f. Access through FUN_a00a6bb8 / FUN_a00a6c00 / FUN_a00a6c98.
 * Source forms: the saved bytes are unsigned short locals (the firmware masks them at the read and again
 * at the write); the mask is an unsigned char; the bit counter is initialised at its declaration and
 * again before the loop.
 */
extern unsigned int FUN_a00a6bb8(unsigned int, unsigned short);
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned char);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a00aee08(unsigned int port, unsigned int val, unsigned char n)
{
    unsigned short a;
    unsigned short b;
    unsigned char i = 0;
    unsigned char mask;

    port &= 0xff;
    FUN_a00a6c98(port, 0x482, 8, 1);
    a = FUN_a00a6bb8(port, 0x89) & 0xff;
    b = FUN_a00a6bb8(port, 0x8a) & 0xff;
    FUN_a00a6c98(port, 0x9f, 0x40, 1);
    FUN_a00a6c98(port, 0x32, 4, 1);
    FUN_a00a6c00(port, 0x89, a);
    FUN_a00a6c00(port, 0x8a, b);
    FUN_a00a6c00(port, 0x8b, (unsigned short)val >> 8);
    FUN_a00a6c00(port, 0x8c, val);
    mask = 0;
    i = 0;
    if (n != 0) {
        do {
            mask = (1 << i) | mask;
            i++;
        } while (i < n);
    }
    FUN_a00a6c00(port, 0x9a, mask);
    FUN_a00a6c98(port, 0x9f, 0x40, 0);
}
