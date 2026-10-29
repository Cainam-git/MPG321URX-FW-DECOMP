/* leon2s FUN_a00a7718 @ 0xa00a7718-0xa00a78b4 (-mcpu=v8 -Os -g).
 * void (u8 port, u16 reg, u8 mask, u8 mode). Saves the low bytes of the registers 0xcf03d014 / 018 / 01c / 020 and
 * 0xcf01142c / 030. For port 0 or 1: bit = 1 << (high byte of reg); port 0 writes its low byte to 0xcf03d014 and
 * bit 8 to 0xcf03d018, port 1 to 0xcf03d01c / 0xcf03d020; 0xcf01142c = 0x85 (port 0) or 0x86; 0xcf011430 = low byte
 * of reg; 0xcf011434 is read twice and the second value v kept; mode == 1 writes (v | mask), any other mode
 * (v & ~mask), to the register word ((DAT_a00b4d84[port] + low byte of reg) << 2) | 0xcf000000; then the six saved
 * bytes are written back and 0xcf011434 is read once more. Other ports do nothing after the saves.
 * Same code shape as FUN_a00a74b8. Source form: mask and the written value w are unsigned char (the mask parameter
 * then has no stack-slot equivalence, which decides its register).
 */
extern const unsigned short DAT_a00b4d84[];

#define R14 (*(volatile unsigned int *)0xcf03d014)
#define R18 (*(volatile unsigned int *)0xcf03d018)
#define R1C (*(volatile unsigned int *)0xcf03d01c)
#define R20 (*(volatile unsigned int *)0xcf03d020)
#define R2C (*(volatile unsigned int *)0xcf01142c)
#define R30 (*(volatile unsigned int *)0xcf011430)
#define R34 (*(volatile unsigned int *)0xcf011434)

void FUN_a00a7718(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char s14 = R14;
    unsigned char s18 = R18;
    unsigned char s1c = R1C;
    unsigned char s20 = R20;
    unsigned char s2c = R2C;
    unsigned char s30 = R30;
    unsigned int v;
    unsigned char w;
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
        reg &= 0xff;
        R30 = (unsigned char)reg;
        R34;
        v = R34;
        if (mode == 1)
            w = v | mask;
        else
            w = v & ~mask;
        *(volatile unsigned int *)(((DAT_a00b4d84[port] + (unsigned short)reg) * 4) | 0xcf000000) = w;
        R14 = s14;
        R18 = s18;
        R1C = s1c;
        R20 = s20;
        R2C = s2c;
        R30 = s30;
        R34;
    }
}
