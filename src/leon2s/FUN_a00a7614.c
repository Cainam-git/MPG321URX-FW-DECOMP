/* leon2s FUN_a00a7614 @ 0xa00a7614-0xa00a7718 (-mcpu=v8 -Os -g).
 * void (u8 port, u16 reg, u8 val). Saves the low bytes of the registers 0xcf03d014 / 018 / 01c / 020. For port 0
 * or 1: bit = 1 << (high byte of reg); port 0 writes its low byte to 0xcf03d014 and bit 8 to 0xcf03d018, port 1 to
 * 0xcf03d01c / 0xcf03d020; then val is written to the register word ((DAT_a00b4d84[port] + low byte of reg) << 2) |
 * 0xcf000000 and the four saved bytes are written back. Other ports do nothing after the saves.
 * Same code shape as FUN_a00a74b8. Source form: bit is an unsigned short and its low byte is stored as
 * '(unsigned char)bit'.
 */
extern const unsigned short DAT_a00b4d84[];

#define R14 (*(volatile unsigned int *)0xcf03d014)
#define R18 (*(volatile unsigned int *)0xcf03d018)
#define R1C (*(volatile unsigned int *)0xcf03d01c)
#define R20 (*(volatile unsigned int *)0xcf03d020)

void FUN_a00a7614(unsigned char port, unsigned short reg, unsigned char val)
{
    unsigned char s14 = R14;
    unsigned char s18 = R18;
    unsigned char s1c = R1C;
    unsigned char s20 = R20;
    unsigned short bit;

    if (port < 2) {
        bit = 1 << ((reg & 0xff00) >> 8);
        switch (port) {
        case 0:
            R14 = (unsigned char)bit;
            R18 = (bit >> 8) & 1;
            break;
        case 1:
            R1C = (unsigned char)bit;
            R20 = (bit >> 8) & 1;
            break;
        }
        *(volatile unsigned int *)(((DAT_a00b4d84[port] + (unsigned char)reg) * 4) | 0xcf000000) = val;
        R14 = s14;
        R18 = s18;
        R1C = s1c;
        R20 = s20;
    }
}
