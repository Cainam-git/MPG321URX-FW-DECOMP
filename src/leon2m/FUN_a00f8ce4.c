/* leon2m FUN_a00f8ce4 @ 0xa00f8ce4  MATCH (-mcpu=v8 -O3 -g)
 * Writes two 16-bit values a and b as byte pairs into registers +0x60..+0x6C of the register block of blk:
 * +0x60/+0x64 = b (low, high byte), +0x68/+0x6C = a. Block bases: 0 -> 0xCF009800, 1 -> 0xCF009C00,
 * 2 -> 0xCF00A000, 3 -> 0xCF00A400, 6 -> 0xCF009000, 7 -> 0xCF009400 (the 0x19A2EC table of FUN_a00f2254);
 * blocks 4, 5 and above 7 write nothing. Before that, a > 0x780 is halved when FUN_a0114360(blk) returns blk and
 * FUN_a011440c() returns non-zero, and a and b are exchanged when swap is non-zero. Caller:
 * FUN_a013c144.
 * Source form: the switch only selects the base; the addresses are written as base | offset (base + offset or a
 * per-case write gives sethi/%lo addressing instead of the firmware's or).
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char FUN_a0114360(unsigned char blk);
extern unsigned char FUN_a011440c(void);

void FUN_a00f8ce4(unsigned char blk, unsigned short a, unsigned short b, unsigned char swap)
{
    unsigned short t;
    unsigned int r;

    if (a > 0x780 && FUN_a0114360(blk) == blk && FUN_a011440c())
        a >>= 1;
    if (swap) {
        t = a;
        a = b;
        b = t;
    }
    switch (blk) {
    case 0: r = 0xcf009800; break;
    case 1: r = 0xcf009c00; break;
    case 2: r = 0xcf00a000; break;
    case 3: r = 0xcf00a400; break;
    case 6: r = 0xcf009000; break;
    case 7: r = 0xcf009400; break;
    default: return;
    }
    R(r | 0x60) = (unsigned char)b;
    R(r | 0x64) = (unsigned char)(b >> 8);
    R(r | 0x68) = (unsigned char)a;
    R(r | 0x6c) = (unsigned char)(a >> 8);
}
