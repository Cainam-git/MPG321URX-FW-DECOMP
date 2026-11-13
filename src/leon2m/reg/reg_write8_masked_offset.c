/* reg_write8_masked_offset  (FUN_a002c464)
 *
 * Clear mask and OR in v in byte register r + k.
 *   base: block base index
 *   offset: register offset
 *   set_bits: bits to set
 *   clear_bits: bits to clear
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c464 (leon2m 0xa002c464-0xa002c4a8, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the result is cast to unsigned short before the store.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * reg_write8_masked for register 'base' + 'offset': clear 'clear_bits', set 'set_bits', write back the low
 * 16 bits of the result. Nothing in the image refers to it.
 */
void reg_write8_masked_offset(unsigned short base, unsigned char offset, unsigned char set_bits, unsigned char clear_bits)
{
    volatile unsigned int *regs = (volatile unsigned int *)REG_ADDR(base + offset);

    *regs = (unsigned short)((*regs & ~clear_bits) | set_bits);
}
