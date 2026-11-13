/* reg_read_bit_range_at  (FUN_a00e21fc)
 *
 * Return the bits lo..hi of the word at an address.
 * Returns: field
 * Name basis: derived - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e21fc @ 0xa00e21fc, flags -mcpu=v8 -O3 -g.
 */
extern unsigned int reg_read32_copy(unsigned int);

/* Return bits 'low'..'high' (both included) of the word at 'address', shifted down to bit 0. Nothing calls it. */
unsigned int reg_read_bit_range_at(unsigned int address, unsigned int high, unsigned int low)
{
    unsigned int mask = (1 << (high + 1)) - (1 << low);

    return (reg_read32_copy(address) & mask) >> low;
}
