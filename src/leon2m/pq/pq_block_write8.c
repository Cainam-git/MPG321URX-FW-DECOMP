/* pq_block_write8  (FUN_a00f2298)
 *
 * Write an 8-bit register of one picture block, or of all eight.
 * Name basis: proven - block base addresses from the ROM table at 0x19A2EC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2298 @ 0xa00f2298  (-mcpu=v8 -O3 -g)
 * Source form: the if/else if with the loop for block 8 is kept as in the original.
 */
/* Register address: 0xCF000000 + 4 * offset. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define NUM_PQ_BLOCKS 8
#define LAST_PQ_BLOCK (NUM_PQ_BLOCKS - 1)

extern unsigned short pq_block_reg_bases[8];     /* block bases */

/*
 * Write an 8-bit value to a register of a picture block.
 * block 0..7 select one of the eight picture blocks; block 8 writes the same register of all eight blocks.
 * reg is the register offset within the block's register space.
 */
void pq_block_write8(unsigned char block, unsigned char reg, unsigned char value)
{
    unsigned char i;
    if (block == NUM_PQ_BLOCKS) {
        /* Write to all eight blocks. */
        for (i = 0; i <= LAST_PQ_BLOCK; i++) R(pq_block_reg_bases[i] + reg) = value;
    }
    else if (block <= LAST_PQ_BLOCK) {
        R(pq_block_reg_bases[block] + reg) = value;
    }
}
