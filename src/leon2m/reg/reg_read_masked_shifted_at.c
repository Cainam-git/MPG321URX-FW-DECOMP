/* reg_read_masked_shifted_at  (FUN_a00e21e0)
 *
 * Return the masked and shifted value of the word at an address.
 * Returns: field
 * Name basis: derived - (word & mask) >> shift; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e21e0 @ 0xa00e21e0, flags -mcpu=v8 -O2 -g (the section default).
 */
extern int reg_read32_copy(unsigned int); /* at 0xa00e021c */

/* Return the bits of the word at 'address' that are set in 'mask', shifted down by 'shift'. Nothing calls it. */
unsigned int reg_read_masked_shifted_at(unsigned int address, unsigned int mask, unsigned int shift)
{
    return (reg_read32_copy(address) & mask) >> shift;
}
