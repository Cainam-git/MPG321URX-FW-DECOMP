/* reg_write16_pair  (FUN_a002c3c8)
 *
 * Write halfword v to byte registers r (low byte) and r + 1 (high byte)
 *   reg: register index
 *   value: halfword
 * Note: Low byte first, unlike reg_read16_pair; nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c3c8 (leon2m 0xa002c3c8-0xa002c3f4, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * Write a 16-bit value to two neighbouring registers: the low byte to register 'reg', the high byte to
 * register 'reg' + 1 (the opposite order to reg_read16_pair). Nothing in the image refers to it (no call,
 * branch, sethi/or constant or address word).
 */
void reg_write16_pair(unsigned short reg, unsigned short value)
{
    volatile unsigned int *regs = (volatile unsigned int *)REG_ADDR(reg);

    regs[0] = value & 0xff;
    regs[1] = value >> 8;
}
