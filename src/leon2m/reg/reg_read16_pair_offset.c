/* reg_read16_pair_offset  (FUN_a002c390)
 *
 * Return byte registers r + k (high) and r + k + 1 (low) as a halfword.
 *   base: block base index
 *   offset: register offset
 * Returns: halfword
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c390 (leon2m 0xa002c390-0xa002c3c8, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * reg_read16_pair for register 'base' + 'offset': the low byte of that register is the high byte of the
 * result, the low byte of the next register the low byte. Nothing in the image refers to it.
 */
unsigned short reg_read16_pair_offset(unsigned short base, unsigned char offset)
{
    volatile unsigned int *regs = (volatile unsigned int *)REG_ADDR(base + offset);

    return ((regs[0] & 0xff) << 8) | (regs[1] & 0xff);
}
