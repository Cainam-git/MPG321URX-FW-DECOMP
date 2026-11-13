/* reg_write32_masked  (FUN_a0061540)
 *
 * Change only the masked bits of a 32-bit hardware register.
 *   reg: register address
 *   value
 *   mask: bits to change
 * Name basis: proven - *p = (*p & ~m) | (v & m) on a volatile word
 *
 * Matching notes
 * --------------
 * FUN_a0061540 (leon2s 0xa0061540-0xa006155c, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The store stays before retl. Called by the wrapper reg_write32_masked_wrapper.
 * Source form: 'value &= mask;' as its own statement gives the firmware's and/andn order.
 */
/*
 * Change only the bits of the 32-bit word at address reg that are set in mask; the other bits keep their value.
 *   reg:   register address
 *   value: new bits (cut to mask)
 *   mask:  the bits to change
 */
void reg_write32_masked(volatile unsigned int *reg, unsigned int value, unsigned int mask)
{
    value &= mask;
    *reg = (*reg & ~mask) | value;
}
