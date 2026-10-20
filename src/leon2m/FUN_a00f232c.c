/* leon2m FUN_a00f232c @ 0xa00f232c  read-modify-write of one register in one or all eight register blocks, bases DAT_0019a2ec
 * (hand; BYTE-EXACT at -mcpu=v8 -O3 -g, rawcmp 0 mismatches). blk == 8 = all blocks 0..7, blk > 8 = nothing;
 * set == 1 ORs mask in, else clears it; the low byte is written back. All parameters and the value are unsigned char. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_0019a2ec[8];
void FUN_a00f232c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i; unsigned char v;
    if (blk == 8) {
        for (i = 0; i <= 7; i++) {
            v = R(DAT_0019a2ec[i] + reg);
            if (set == 1) v |= mask; else v &= ~mask;
            R(DAT_0019a2ec[i] + reg) = (unsigned char)v;
        }
    } else if (blk <= 7) {
        v = R(DAT_0019a2ec[blk] + reg);
        if (set == 1) v |= mask; else v &= ~mask;
        R(DAT_0019a2ec[blk] + reg) = (unsigned char)v;
    }
}
