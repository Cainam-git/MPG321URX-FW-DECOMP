/* reg_write_bit_range  (FUN_a00d21e0)
 *
 * Write a value into the bits lo..hi of a register.
 * Name basis: proven - bit-range read-modify-write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d21e0 @ 0xa00d21e0-0xa00d2210 (12 words), flags -mcpu=v8 -Os -g.
 * Source form: one temporary (top_bit) for 1 << hi inside the mask expression, and the read-modify-write as a
 * local (word = *reg; word &= ~mask; word |= ...; *reg = word), which gives the firmware order (load before the
 * shift of the value, andn/or into the loaded register).
 */
/*
 * Store value in bits lo..hi (both included) of the word at reg and leave the other bits as they are. The
 * value is shifted left by lo and cut to the field. Same operation as reg_write_bit_field with the register
 * given by pointer.
 */
void reg_write_bit_range(unsigned int *reg, unsigned char hi, int lo, int value)
{
    unsigned int top_bit = 1 << hi;
    unsigned int mask = (top_bit - (1 << lo)) | top_bit;   /* bits lo..hi */
    unsigned int word = *reg;
    word &= ~mask;
    word |= (value << lo) & mask;
    *reg = word;
}
