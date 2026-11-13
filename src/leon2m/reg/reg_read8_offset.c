/* reg_read8_offset  (FUN_a002c2f0)
 *
 * Return byte register r + k (word 0xCF000000 + 4(r + k))
 *   base: block base index
 *   offset: register offset
 * Returns: byte value
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c2f0 (leon2m 0xa002c2f0-0xa002c318, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: an unsigned short base and an unsigned char offset, added before the shift.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * Return the low byte of register 'base' + 'offset'. Nothing in the image refers to it (no call, branch,
 * sethi/or constant or address word).
 */
unsigned char reg_read8_offset(unsigned short base, unsigned char offset)
{
    return *(volatile unsigned int *)REG_ADDR(base + offset);
}
