/* FUN_a011cc44: 16-bit write into block blk of the second register family (register n at 0xcf000000 + 4 * n,
 * block base = halfword table 0xa8027aa8[blk], blk > 1 treated as 0): low byte of v to register base + 0xcc,
 * high byte to base + 0xcd. Caller: FUN_a0146ab0.
 * Same form as FUN_a011919c with the register number fixed (inlined 16-bit write helper).
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }

void FUN_a011cc44(unsigned char blk, unsigned short v)
{
    if (blk > 1) blk = 0;
    wr16(DAT_a8027aa8[blk] + 0xcc, v);
}
