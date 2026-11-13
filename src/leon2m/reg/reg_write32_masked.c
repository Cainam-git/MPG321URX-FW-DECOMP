/* reg_write32_masked  (FUN_a002c268)
 *
 * Replace the bits of mask in the word at p with those of v.
 *   reg: register address
 *   value: new bit values
 *   mask: bits to change
 * Name basis: proven - code: read-modify-write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002c268 @ 0xa002c268-0xa002c284 (7 words), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the pointer is volatile, so the store stays out of the delay slot of retl, which holds a nop.
 */

/*
 * Read-modify-write of one 32-bit register: the bits set in 'mask' take their value from 'value', all other
 * bits keep theirs. reg_write32_masked(reg, bits, bits) sets bits, reg_write32_masked(reg, 0, bits) clears
 * them; the interrupt level handlers use it both ways.
 */
void reg_write32_masked(volatile unsigned int *reg, unsigned int value, unsigned int mask)
{
    value &= mask;
    *reg = (*reg & ~mask) | value;
}
