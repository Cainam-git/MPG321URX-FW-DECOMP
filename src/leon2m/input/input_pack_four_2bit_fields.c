/* input_pack_four_2bit_fields  (FUN_a012ad80)
 *
 * Pack four 2-bit values into one byte.
 * Returns: byte
 * Name basis: descriptive - first value in the top bits; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012ad80 @ 0xa012ad80, flags -mcpu=v8 -O3 -g.
 */
/*
 * Pack four 2-bit values into one byte: a in bits 7..6, b in bits 5..4, c in bits 3..2, d in bits 1..0.
 */
unsigned int input_pack_four_2bit_fields(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    return ((a & 3) << 6) | ((b & 3) << 4) | ((c & 3) << 2) | (d & 3);
}
