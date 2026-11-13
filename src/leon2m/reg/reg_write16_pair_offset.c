/* reg_write16_pair_offset  (FUN_a002c3f4)
 *
 * Write halfword v to byte registers r + k (low) and r + k + 1 (high)
 *   base: block base index
 *   offset: register offset
 *   value: halfword
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c3f4 (leon2m 0xa002c3f4-0xa002c42c, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * reg_write16_pair for register 'base' + 'offset': the low byte of 'value' goes to that register, the high
 * byte to the next one. Nothing in the image refers to it.
 */
void reg_write16_pair_offset(unsigned short base, unsigned char offset, unsigned short value)
{
    volatile unsigned int *regs = (volatile unsigned int *)REG_ADDR(base + offset);

    regs[0] = value & 0xff;
    regs[1] = value >> 8;
}
