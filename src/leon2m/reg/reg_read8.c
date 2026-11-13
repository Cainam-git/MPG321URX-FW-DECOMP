/* reg_read8  (FUN_a002c2d4)
 *
 * Return byte register r (word 0xCF000000 + 4r)
 *   reg: register index
 * Returns: byte value
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c2d4 (leon2m 0xa002c2d4-0xa002c2f0, 28 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: an unsigned short register number shifted into a volatile word address.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * Return the low byte of register 'reg'. Nothing in the image refers to it (no call, branch, sethi/or
 * constant or address word).
 */
unsigned char reg_read8(unsigned short reg)
{
    return *(volatile unsigned int *)REG_ADDR(reg);
}
