/* lib_make_bit_range_mask  (FUN_a0089058)
 *
 * Return a byte with bits first..last set.
 *   first: lowest bit
 *   last: highest bit
 * Returns: bit mask
 * Name basis: proven - loop over the bit range; 0 when first > last
 *
 * Matching notes
 * --------------
 * FUN_a0089058 (leon2s 0xa0089058), flags -mcpu=v8 -Os -g.
 * Ghidra's type names (uint, byte) are kept.
 */
typedef unsigned char byte;
typedef unsigned int uint;
#define true 1
#define false 0

/*
 * Return a mask with bits first..last set (both included). Bits above bit 7 are dropped; the result is 0 when
 * first is larger than last.
 */
uint lib_make_bit_range_mask(byte first,byte last)

{
  unsigned char mask;
  
  mask = 0;
  for (; first <= last; first = first + 1) {
    mask = 1 << first | mask;
  }
  return mask & 0xff;
}
