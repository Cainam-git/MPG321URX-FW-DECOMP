/* reg_write_bit_field  (FUN_a00614b8)
 *
 * Replace bits lo..hi of a word with a value.
 *   p: word to change
 *   hi: highest bit
 *   lo: lowest bit
 *   v: new field value
 * Returns: 1 when hi is below lo or above 31, else 0
 * Note: Byte-identical copy of the routine at 0xA0061A6C.
 * Name basis: proven - mask from hi/lo, read-modify-write; callers write HDR registers 0xD0013Fxx
 *
 * Matching notes
 * --------------
 * FUN_a00614b8 (leon2s 0xa00614b8-0xa0061528, 112 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Byte-identical to reg_write_bit_field_copy (reg_write_bit_field_copy).
 * Source form: the mask and the shifted value are computed inside the write arm 'if (!(hi_bad | lo_bad))'; the
 * scheduler then moves them into the 'hi <= 31' test block (the firmware place) instead of above the 'hi >= lo'
 * test.
 */
/*
 * Replace bits lo..hi of the word at p with the low bits of v (v is shifted left by lo and cut to the field).
 *
 *   p:  the word to change
 *   hi: highest bit of the field (0..31)
 *   lo: lowest bit of the field (0..31, not above hi)
 *
 * Returns 1 when hi is below lo or above 31, else 0. When lo is above 31 nothing is written and 0 is returned.
 * The word is read and written back; it is not declared volatile here.
 */
unsigned int reg_write_bit_field(unsigned int *p, unsigned int hi, unsigned int lo, unsigned int v)
{
    unsigned int hi_bad = 1;
    unsigned int lo_bad = 1;
    unsigned int mask;

    if (hi >= lo) {
        if (hi <= 31)
            hi_bad = 0;
        if (lo <= 31)
            lo_bad = 0;
        if (!(hi_bad | lo_bad)) {
            /* Bits lo..hi set. */
            mask = ((1u << hi) - (1u << lo)) | (1u << hi);
            *p = (*p & ~mask) | ((v << lo) & mask);
        }
    }
    return hi_bad;
}
