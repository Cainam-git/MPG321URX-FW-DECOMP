/* reg_read16_pair  (FUN_a002c364)
 *
 * Return byte registers r (high) and r + 1 (low) as a halfword.
 *   reg: register index
 * Returns: halfword
 * Note: Opposite byte order to reg_write16_pair; nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c364 (leon2m 0xa002c364-0xa002c390, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * Return a 16-bit value from two neighbouring registers: the low byte of register 'reg' is the high byte, the
 * low byte of register 'reg' + 1 the low byte. reg_write16_pair writes the bytes the other way round. Nothing
 * in the image refers to it (no call, branch, sethi/or constant or address word).
 */
unsigned short reg_read16_pair(unsigned short reg)
{
    volatile unsigned int *regs = (volatile unsigned int *)REG_ADDR(reg);

    return ((regs[0] & 0xff) << 8) | (regs[1] & 0xff);
}
