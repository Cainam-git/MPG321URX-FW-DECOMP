/* reg_write8_masked  (FUN_a002c42c)
 *
 * Clear mask and OR in v in byte register r.
 *   reg: register index
 *   set_bits: bits to set
 *   clear_bits: bits to clear
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c42c (leon2m 0xa002c42c-0xa002c464, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the result is cast to unsigned short before the store.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * Read-modify-write of register 'reg': the bits of 'clear_bits' are cleared, the bits of 'set_bits' set, and
 * the low 16 bits of the result are written back (bits 16..31 become 0). Nothing in the image refers to it
 * (no call, branch, sethi/or constant or address word).
 */
void reg_write8_masked(unsigned short reg, unsigned char set_bits, unsigned char clear_bits)
{
    volatile unsigned int *regs = (volatile unsigned int *)REG_ADDR(reg);

    *regs = (unsigned short)((*regs & ~clear_bits) | set_bits);
}
