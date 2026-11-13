/* reg_read_masked_at  (FUN_a00df504)
 *
 * Return the masked value of the word at an address.
 * Returns: value
 * Name basis: derived - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df504 @ 0xa00df504, flags -mcpu=v8 -O2 -g (the section default).
 * The mask applies to the value read from the register, not to the address, and the routine returns the
 * result.
 */
extern int reg_read32_copy(unsigned int); /* at 0xa00e021c */

/* Return the bits of the word at 'address' that are set in 'mask'. Nothing calls it. */
unsigned int reg_read_masked_at(unsigned int address, unsigned int mask)
{
    unsigned int value;
    value = reg_read32_copy(address);
    return value & mask;
}
