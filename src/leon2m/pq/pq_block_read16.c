/* pq_block_read16  (FUN_a00f25f8)
 *
 * Read a 16-bit register pair of a picture block.
 * Returns: value
 * Name basis: proven - block base addresses from the ROM table at 0x19A2EC; blocks 6 and 7 use 8-bit registers
 *   for two of the pairs
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f25f8 @ 0xa00f25f8 (-mcpu=v8 -O3 -g).
 * Source form: the normal register-pair read appears twice: once for blocks 0..5 and once for blocks 6/7
 * with non-special registers. Block numbers >7 are clamped to 0 before the branch.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))   /* register at 0xCF000000 + 4 * a */
extern unsigned short pq_block_reg_bases[8];     /* register bases of the eight picture blocks */

#define MAX_BLOCK_NUMBER 7      /* valid block numbers are 0..7 */
#define FALLBACK_BLOCK 0        /* block used for out-of-range block numbers */
#define LAST_NORMAL_BLOCK 5     /* blocks 0..5 use the normal register-pair layout */
#define REG_A0 0xa0             /* register number remapped for blocks 6 and 7 */
#define REG_BE 0xbe             /* register number remapped for blocks 6 and 7 */
#define REG_60 0x60             /* single register replacing REG_A0 in blocks 6 and 7 */
#define REG_5D 0x5d             /* single register replacing REG_BE in blocks 6 and 7 */
#define LOW_BYTE_MASK 0xff      /* low byte of the register value */

/*
 * Read a 16-bit register pair of a picture block.
 * Block numbers >7 read block 0. Blocks 6 and 7 remap registers 0xA0 and 0xBE to single 8-bit registers
 * 0x60 and 0x5D; all other blocks read two consecutive registers (low byte first).
 */
unsigned short pq_block_read16(unsigned char block, unsigned char reg)
{
    unsigned short value; unsigned int reg_addr, low_reg, high_reg;
    if (block > MAX_BLOCK_NUMBER) block = FALLBACK_BLOCK;
    if (block <= LAST_NORMAL_BLOCK) { reg_addr = pq_block_reg_bases[block] + reg; low_reg = R(reg_addr); high_reg = R(reg_addr + 1); value = (high_reg << 8) | (low_reg & LOW_BYTE_MASK); }
    else if (reg == REG_A0) value = R(pq_block_reg_bases[block] + REG_60);
    else if (reg == REG_BE) value = R(pq_block_reg_bases[block] + REG_5D);
    else { reg_addr = pq_block_reg_bases[block] + reg; low_reg = R(reg_addr); high_reg = R(reg_addr + 1); value = (high_reg << 8) | (low_reg & LOW_BYTE_MASK); }
    return value;
}
