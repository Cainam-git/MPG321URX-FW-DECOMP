/* leon2s FUN_a00a74b8 @ 0xa00a74b8-0xa00a7614 (-mcpu=v8 -Os -g).
 * unsigned int (u8 port, u16 reg). Saves the low bytes of the registers 0xcf03d014 / 018 / 01c / 020 and
 * 0xcf01142c / 030. For port 0 or 1: bit = 1 << (high byte of reg); port 0 writes its low byte to 0xcf03d014 and
 * bit 8 to 0xcf03d018, port 1 to 0xcf03d01c / 0xcf03d020; 0xcf01142c = 0x85 (port 0) or 0x86; 0xcf011430 = low byte
 * of reg; 0xcf011434 is read twice and the second value kept; then the six saved bytes are written back in the order
 * 030, 02c, 014, 018, 01c, 020, 0xcf011434 is read once more, and the kept value's low byte is returned. Other
 * ports return 0 without any access after the saves.
 * Source form: bit is an unsigned short and its low byte is stored as '(unsigned char)bit'.
 */
#define R14 (*(volatile unsigned int *)0xcf03d014)
#define R18 (*(volatile unsigned int *)0xcf03d018)
#define R1C (*(volatile unsigned int *)0xcf03d01c)
#define R20 (*(volatile unsigned int *)0xcf03d020)
#define R2C (*(volatile unsigned int *)0xcf01142c)
#define R30 (*(volatile unsigned int *)0xcf011430)
#define R34 (*(volatile unsigned int *)0xcf011434)

unsigned int FUN_a00a74b8(unsigned char port, unsigned short reg)
{
    unsigned char s14 = R14;
    unsigned char s18 = R18;
    unsigned char s1c = R1C;
    unsigned char s20 = R20;
    unsigned char s2c = R2C;
    unsigned char s30 = R30;
    unsigned int r = 0;
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
        if (port == 0)
            R2C = 0x85;
        else
            R2C = 0x86;
        R30 = (unsigned char)reg;
        R34;
        r = R34;
        R30 = s30;
        R2C = s2c;
        R14 = s14;
        R18 = s18;
        R1C = s1c;
        R20 = s20;
        R34;
        r &= 0xff;
    }
    return r;
}
