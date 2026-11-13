/* reg_write8_offset  (FUN_a002c338)
 *
 * Write byte v to register r + k (word 0xCF000000 + 4(r + k))
 *   base: block base index
 *   offset: register offset
 *   value
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c338 (leon2m 0xa002c338-0xa002c364, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the target is a volatile word, so the store stays out of the retl delay slot.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * Write 'value' (zero-extended to a word) to register 'base' + 'offset'. Nothing in the image refers to it
 * (no call, branch, sethi/or constant or address word).
 */
void reg_write8_offset(unsigned short base, unsigned char offset, unsigned char value)
{
    *(volatile unsigned int *)REG_ADDR(base + offset) = value;
}
