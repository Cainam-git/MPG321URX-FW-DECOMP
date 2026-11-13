/* input_pack_four_flags  (FUN_a012adac)
 *
 * Pack four flags into the low four bits of a byte.
 * Returns: byte
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012adac @ 0xa012adac, flags -mcpu=v8 -O3 -g.
 */
/*
 * Pack four flags into bits 3..0 of a byte: a in bit 3, b in bit 2, c in bit 1, d in bit 0. The flags are
 * not masked to one bit.
 */
unsigned char input_pack_four_flags(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    return (a << 3) | (b << 2) | (c << 1) | d;
}
