/* reg_blockset5_read16_stable  (FUN_a00f154c)
 *
 * Read a 16-bit register pair of the fifth block set until two reads agree.
 * Returns: value
 * Name basis: descriptive - at most five retries; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f154c @ 0xa00f154c, flags -mcpu=v8 -O3 -g.
 * Source form: the read is a static helper (read_pair) used four times; the retry loop is
 * 'for (; first != read_pair() && n < 5; n++) first = read_pair();'.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of 16-bit block bases reg_blockset5_bases; each word holds one byte of the register. A 16-bit value
 * lies in registers n (low byte) and n + 1 (high byte).
 */

extern unsigned short reg_blockset5_bases[4];

/* Read the register pair 'reg' / 'reg' + 1 of block 'block' as a 16-bit value (block numbers above 3 read block 0). */
static unsigned short read_pair(unsigned char block, unsigned short reg)
{
    unsigned int low_word, high_word, index;

    if (block >= 4) block = 0;
    index = reg_blockset5_bases[block] + reg;
    low_word = *(volatile unsigned int *)(0xcf000000 | (index << 2));
    high_word = *(volatile unsigned int *)(0xcf000000 | ((index + 1) << 2));
    return (high_word << 8) | (low_word & 0xff);
}

/*
 * Return the 16-bit value of the register pair 'reg' / 'reg' + 1 of block 'block', read again until a read
 * equals the one before it. After five unequal comparisons the last value is returned anyway. Nothing calls it.
 */
unsigned short reg_blockset5_read16_stable(unsigned char block, unsigned short reg)
{
    unsigned short first;
    unsigned char retries = 0;

    first = read_pair(block, reg);
    for (; first != read_pair(block, reg) && retries < 5; retries++)
        first = read_pair(block, reg);
    return first;
}
