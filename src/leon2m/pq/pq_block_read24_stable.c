/* pq_block_read24_stable  (FUN_a00f29d4)
 *
 * Read a 24-bit register triple of a picture block until two reads agree.
 * Returns: value
 * Name basis: proven - block base addresses from the ROM table at 0x19A2EC; at most five retries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f29d4 @ 0xa00f29d4-0xa00f2b48, flags -mcpu=v8 -O3 -g.
 * Source form: rd24 is static and inlined three times; the loop reads a fresh rd24 each iteration and compares.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define MAX_BLOCK_INDEX 7
#define MAX_RETRIES 5
#define REG_LOW_OFFSET 0
#define REG_MID_OFFSET 1
#define REG_HIGH_OFFSET 2
#define BYTE_MASK 0xff

extern unsigned short pq_block_reg_bases[8];

static unsigned int rd24(unsigned char block, unsigned char reg)
{
    unsigned int reg_addr;

    if (block > MAX_BLOCK_INDEX)
        block = 0;
    reg_addr = pq_block_reg_bases[block] + reg;
    return (((R(reg_addr + REG_HIGH_OFFSET) << 8) | (R(reg_addr + REG_MID_OFFSET) & BYTE_MASK)) << 8) | (R(reg_addr + REG_LOW_OFFSET) & BYTE_MASK);
}

/*
 * Read a 24-bit register triple of a picture block until two reads agree.
 * The triple is read as (high << 16) | (mid byte << 8) | low byte, from registers reg + 2, reg + 1 and reg
 * (the high register is not masked to 8 bits). If the block index is out of range ( > 7 ), block 0 is used.
 * After the first read, each pass reads the triple again and stops when that read equals the kept value;
 * otherwise the triple is read once more into the kept value. After 5 such retries one more compare read is
 * done and the kept value is returned as it is.
 *
 * Callers: input_bring_up_set_pixel_clock, pq_block_read_reg89_pair_average, panel_correct_clock_second_step.
 */
unsigned int pq_block_read24_stable(unsigned char block, unsigned char reg)
{
    unsigned int value;
    unsigned char retry = 0;

    value = rd24(block, reg);
    /* Retry until a fresh read matches the previous one. */
    for (; value != rd24(block, reg) && retry < MAX_RETRIES; retry++)
        value = rd24(block, reg);
    return value;
}
