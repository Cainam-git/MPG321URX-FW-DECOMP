/* leon2m FUN_a00fd820 @ 0xa00fd820  MATCH (-mcpu=v8 -O3 -g)
 * Returns the class code of block blk that FUN_a00fd594 / FUN_a00fd9a0 take as input:
 *   FUN_a00f92d4(blk) non-zero -> 0xE8;
 *   reg 3 bit 5 set -> by reg 0x40 bits 0-1 (FUN_a00f1e0c): 0 -> 0x91, 2 -> 0xA1, else 0xB1;
 *   reg 3 bit 4 set -> 0xC1;
 *   else by reg 4 bits 0-3: 0/1 -> (FUN_a00f1f9c(blk, 0) bit 3 set: 0x21 when (0xCF020114 & 7) == 5, else 0x13;
 *   clear: 0x12 when reg 0x54 bit 0 is set, else 0x11), 2 -> 0x31, 6 -> 0x41, 10 -> 0x51, 14 -> 0x61,
 *   3/7/11/15 -> 0x81 when reg 3 bit 0 is set else 0x71, others -> 1.
 * "reg n" is FUN_a00f1a90(blk, n). Callers: FUN_a00f896c, FUN_a00f8a98, FUN_a01012a8, FUN_a012127c and others.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char FUN_a00f92d4(unsigned char port);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a00f1e0c(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a00f1f9c(unsigned char blk, unsigned char reg);

unsigned char FUN_a00fd820(unsigned char blk)
{
    unsigned char c;
    unsigned char r;

    if (FUN_a00f92d4(blk))
        return 0xe8;
    if (FUN_a00f1a90(blk, 3) & 0x20) {
        r = FUN_a00f1e0c(blk, 0x40) & 3;
        if (r == 0)
            c = 0x91;
        else if (r == 2)
            c = 0xa1;
        else
            c = 0xb1;
        return c;
    }
    if (FUN_a00f1a90(blk, 3) & 0x10)
        return 0xc1;
    switch (FUN_a00f1a90(blk, 4) & 0xf) {
    case 0:
    case 1:
        if (FUN_a00f1f9c(blk, 0) & 8) {
            if ((R(0xcf020114) & 7) == 5)
                c = 0x21;
            else
                c = 0x13;
        } else if (FUN_a00f1a90(blk, 0x54) & 1)
            c = 0x12;
        else
            c = 0x11;
        break;
    case 2:
        c = 0x31;
        break;
    case 6:
        c = 0x41;
        break;
    case 10:
        c = 0x51;
        break;
    case 14:
        c = 0x61;
        break;
    case 3:
    case 7:
    case 11:
    case 15:
        if (FUN_a00f1a90(blk, 3) & 1)
            c = 0x81;
        else
            c = 0x71;
        break;
    default:
        c = 1;
        break;
    }
    return c;
}
