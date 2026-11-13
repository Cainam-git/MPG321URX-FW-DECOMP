/* lib_extract_bits  (FUN_a00f99e8)
 *
 * Return the bits from position lo to hi of a value.
 * Returns: field
 * Name basis: derived - bit field extraction; unused
 *
 * Matching notes
 * --------------
 * FUN_a00f99e8 (leon2m 0xa00f99e8-0xa00f9a00, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two shifts with counts 31 - hi and 31 - hi + lo. GCC writes the left shift count 31 - hi as ~hi
 * (only the low 5 bits count).
 */
/*
 * Return the bit field lo..hi of a word, moved down to bit 0.
 *   value: the word
 *   hi:    number of the highest bit of the field (0..31)
 *   lo:    number of the lowest bit of the field (lo <= hi)
 * Nothing calls this routine.
 */
unsigned int lib_extract_bits(unsigned int value, unsigned int hi, unsigned int lo)
{
    return (value << (31 - hi)) >> (31 - hi + lo);
}
