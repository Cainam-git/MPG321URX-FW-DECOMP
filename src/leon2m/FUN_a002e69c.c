/* leon2m FUN_a002e69c @ 0xa002e69c-0xa002e6e4 (RAM copy, called as func_0x4008e69c)  write one byte register in register
 * block 0 or 1 (hand; BYTE-EXACT at -mcpu=v8 -O3 -g). blk >= 2 falls back to block 0; register address = 0xCF000000 + 4 * (base + reg)
 * with the block bases in RAM at DAT_a8027aa8. Called by the output path set-up FUN_a01023f4 (register 0x5D).
 * Ghidra's import did not mark this function; it was added to the function table by hand.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
void FUN_a002e69c(unsigned char blk, unsigned char reg, unsigned char val)
{
    if (blk >= 2) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = val;
}
