/* reg_write8  (FUN_a002c318)
 *
 * Write byte v to register r (word 0xCF000000 + 4r)
 *   reg: register index
 *   value
 * Note: Nothing calls it.
 * Name basis: descriptive - code only; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c318 (leon2m 0xa002c318-0xa002c338, 32 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: an unsigned short register number and an unsigned char value; the target is a volatile word,
 * so the store stays out of the retl delay slot.
 */

/* Register number n of the 0xCF000000 block is the word at 0xCF000000 | (n << 2). */
#define REG_ADDR(index) (0xcf000000 | ((index) << 2))

/*
 * Write 'value' (zero-extended to a word) to register 'reg'. Nothing in the image refers to it (no call,
 * branch, sethi/or constant or address word).
 */
void reg_write8(unsigned short reg, unsigned char value)
{
    *(volatile unsigned int *)REG_ADDR(reg) = value;
}
