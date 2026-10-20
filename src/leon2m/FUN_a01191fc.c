/* leon2m FUN_a01191fc @ 0xa01191fc  set (set == 1) or clear the bits 'mask' of one register in block 0/1 of the
 * second register family (hand; byte-exact at -mcpu=v8 -O3 -g).
 * Register = halfword base from the RAM table 0xA8027AA8[blk] + reg (no range check on blk, unlike FUN_a011919c);
 * the new value is written back as a byte. Caller: FRCConfigPostFRC FUN_a0107e44, FUN_a01191fc(0/1, 0xA5, 8, 1):
 * sets bit 3 of register 0xA5 in both blocks.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}
