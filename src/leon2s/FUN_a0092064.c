/* leon2s FUN_a0092064 @ 0xa0092064-0xa00920ec (34 words), flags -mcpu=v8 -Os -g.
 * Code facts: (u8 port, mode). v = FUN_a00a7fd8(port, 0, 0x82) (u8 register read); by mode & 0xf:
 * 1 -> write (v | 0x40) & 0xdf, then sibcall FUN_a008d980(port, 1); 3 -> write v | 0x60, d980(port, 2);
 * else -> write (v | 0x20) & 0xbf, d980(port, 0). The write is FUN_a00a8054(port, 0, 0x82, value).
 * gcc crossjumps the 1 and 3 arms into one a8054 call (the k argument lands in %i1 in the delay slots).
 * Fixes vs the autoc draft (78.38): a SWITCH on mode & 0xf (the if/else-if chain gives another layout and
 * keeps the masked mode in %l0), real prototypes (a7fd8 returns u8; a8054 takes a u8 value: the 3-case
 * 'and 0xff' is that conversion), sibcall tails. Aids: none.
 */
extern unsigned char FUN_a00a7fd8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a008d980(unsigned char, unsigned char);

void FUN_a0092064(unsigned char port, unsigned int mode)
{
    unsigned char v;

    v = FUN_a00a7fd8(port, 0, 0x82);
    switch (mode & 0xf) {
    case 1:
        FUN_a00a8054(port, 0, 0x82, (v | 0x40) & 0xdf);
        FUN_a008d980(port, 1);
        break;
    case 3:
        FUN_a00a8054(port, 0, 0x82, v | 0x60);
        FUN_a008d980(port, 2);
        break;
    default:
        FUN_a00a8054(port, 0, 0x82, (v | 0x20) & 0xbf);
        FUN_a008d980(port, 0);
        break;
    }
}
