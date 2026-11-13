/* pq_block_read16_stable  (FUN_a00f2708)
 *
 * Read a 16-bit register pair of a picture block until two reads agree.
 * Returns: value
 * Name basis: proven - block base addresses from the ROM table at 0x19A2EC; at most five retries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2708 @ 0xa00f2708, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - pq_block_read16 (pq_block_read16) is defined again in this file, so that it is inlined here three times;
 *  - the retry counter is set to 0 in its declaration, before the first read, and the loop is
 *      for (; value != pq_block_read16(...) && retries < 5; retries++) value = pq_block_read16(...);
 *    (the compare read comes first, then the counter test). Setting the counter after the first read changes
 *    the register choice; a separate temporary or two if-breaks give different code.
 */

/* Register n of a picture block is the word at 0xCF000000 + 4 * (block base + n); only its low 8 bits are used. */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))
extern unsigned short pq_block_reg_bases[8];     /* register bases of the eight picture blocks */

#define LAST_BLOCK          7           /* a higher block number reads block 0 */
#define LAST_PAIR_BLOCK     5           /* blocks 0..5 hold every value as a register pair */
#define PAIR_REG_A0         0xa0        /* in blocks 6 and 7: single register 0x60 */
#define SINGLE_REG_60       0x60
#define PAIR_REG_BE         0xbe        /* in blocks 6 and 7: single register 0x5D */
#define SINGLE_REG_5D       0x5d
#define MAX_RETRIES         5

/* Read registers reg (low byte) and reg + 1 (high byte) of a picture block; see pq_block_read16. */
unsigned short pq_block_read16(unsigned char block, unsigned char reg)
{
    unsigned short value; unsigned int index, low, high;
    if (block > LAST_BLOCK) block = 0;
    if (block <= LAST_PAIR_BLOCK) { index = pq_block_reg_bases[block] + reg; low = BLOCK_REG(index); high = BLOCK_REG(index + 1); value = (high << 8) | (low & 0xff); }
    else if (reg == PAIR_REG_A0) value = BLOCK_REG(pq_block_reg_bases[block] + SINGLE_REG_60);
    else if (reg == PAIR_REG_BE) value = BLOCK_REG(pq_block_reg_bases[block] + SINGLE_REG_5D);
    else { index = pq_block_reg_bases[block] + reg; low = BLOCK_REG(index); high = BLOCK_REG(index + 1); value = (high << 8) | (low & 0xff); }
    return value;
}

/*
 * Read a 16-bit register pair of a picture block (pq_block_read16) until two reads in a row give the same
 * value. After 5 retries the last value read is returned even when it still differs from the compare read.
 *   block  picture block 0..7 (a higher number reads block 0)
 *   reg    register number of the low byte
 *
 * Callers: panel_output_setup_channel_timing, panel_correct_clock_first_step / _second_step and
 * pq_block5_copy_htotal_readback.
 */
unsigned short pq_block_read16_stable(unsigned char block, unsigned char reg)
{
    unsigned short value;
    unsigned char retries = 0;
    value = pq_block_read16(block, reg);
    for (; value != pq_block_read16(block, reg) && retries < MAX_RETRIES; retries++)
        value = pq_block_read16(block, reg);
    return value;
}
