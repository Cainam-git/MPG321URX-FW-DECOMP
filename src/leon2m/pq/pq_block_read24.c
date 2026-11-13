/* pq_block_read24  (FUN_a00f295c)
 *
 * Read a 24-bit register triple of a picture block.
 * Returns: value
 * Name basis: derived - block base addresses from the ROM table at 0x19A2EC; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f295c @ 0xa00f295c-0xa00f29d4 (120 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */

/* Register n of a picture block is the word at 0xCF000000 + 4 * (block base + n); only its low 8 bits are used. */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))
extern const unsigned short pq_block_reg_bases[];

#define LAST_BLOCK 7                    /* a higher block number reads block 0 */

/*
 * Read a 24-bit value from registers reg (bits 0..7), reg + 1 (bits 8..15) and reg + 2 (bits 16..23) of a
 * picture block. The two lower registers are masked to their low byte; the word of reg + 2 is taken whole.
 *   block  picture block 0..7 (a higher number reads block 0)
 *   reg    register number of the low byte
 *
 * Nothing in the firmware refers to this routine: no call, branch, constant or address word.
 */
unsigned int pq_block_read24(unsigned char block, unsigned char reg)
{
    unsigned int index, value;

    if (block > LAST_BLOCK)
        block = 0;
    index = pq_block_reg_bases[block] + reg;
    value = BLOCK_REG(index + 2);
    value = (value << 8) | (BLOCK_REG(index + 1) & 0xff);
    value = (value << 8) | (BLOCK_REG(index) & 0xff);
    return value;
}
