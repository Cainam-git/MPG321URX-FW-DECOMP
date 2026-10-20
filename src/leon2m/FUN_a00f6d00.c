/* leon2m FUN_a00f6d00 @ 0xa00f6d00 (-mcpu=v8 -O3 -g)
 * Writes four 16-bit values as byte pairs (low byte first) to the hardware registers 0xCF00EC88..0xCF00ECA4:
 * a -> 0xCF00EC88/8C, c -> 0xCF00EC90/94, b -> 0xCF00EC98/9C, d -> 0xCF00ECA0/A4.
 * Callers: FUN_a012d554 (several), FUN_a013d918.
 * Source form: each byte converted with an (unsigned char) cast; the firmware keeps a register window (save) although
 * the function makes no call, which this form reproduces (masking with & 0xff gives a leaf function instead).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00f6d00(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    R(0xcf00ec88) = (unsigned char)a;
    R(0xcf00ec8c) = (unsigned char)(a >> 8);
    R(0xcf00ec90) = (unsigned char)c;
    R(0xcf00ec94) = (unsigned char)(c >> 8);
    R(0xcf00ec98) = (unsigned char)b;
    R(0xcf00ec9c) = (unsigned char)(b >> 8);
    R(0xcf00eca0) = (unsigned char)d;
    R(0xcf00eca4) = (unsigned char)(d >> 8);
}
