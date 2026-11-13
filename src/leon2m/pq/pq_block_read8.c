/* pq_block_read8  (FUN_a00f2254)
 *
 * Read an 8-bit register of a picture block.
 * Returns: byte
 * Name basis: proven - block base addresses from the ROM table at 0x19A2EC; blocks 0..7; other numbers read
 *   block 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2254 @ 0xa00f2254  (-mcpu=v8 -O3 -g)
 * Source form: the block number is clamped to 0..7 by the if statement; the register address is computed as
 * base + (block_base + reg) << 2. The expression is kept exactly as in the original.
 */
extern unsigned short pq_block_reg_bases[8];     /* block bases, see above */

#define PICTURE_BLOCK_REG_BASE 0xcf000000       /* memory-mapped register base for picture blocks */
#define NUM_PICTURE_BLOCKS 8                    /* number of picture blocks */

/*
 * Read an 8-bit register of a picture block.
 *
 * The block number is clamped to 0..7 (block 8 and up read block 0). The register address is
 * PICTURE_BLOCK_REG_BASE + 4 * (pq_block_reg_bases[block] + reg_num). Each register is a 32-bit word;
 * only the low 8 bits are used.
 *
 * Parameters:
 *   block  - picture block number (0..7, 8+ treated as 0)
 *   reg_num - register number within the block
 *
 * Returns the low byte of the register.
 */
unsigned char pq_block_read8(unsigned char block, unsigned char reg_num)
{
    if (block >= NUM_PICTURE_BLOCKS) block = 0;
    return *(volatile unsigned int *)(PICTURE_BLOCK_REG_BASE | ((pq_block_reg_bases[block] + reg_num) << 2));
}
