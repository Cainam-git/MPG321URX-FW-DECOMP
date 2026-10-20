/* leon2s FUN_a008661c @ 0xa008661c-0xa0086678 (23 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 23 words.
 * Code facts: v = 0x80 when bit 3 of byte ARR_a807cd2e[p * 6] is set, else 0 (if-converted: srl 3 / and 1 /
 * cmp %g0 / addx -1 / and -128 / add -128, then the u8 extension narrowed to 'and 0x80'); returns 1 when
 * FUN_a0086360(p, 0x80, 0x107, v) returns 0 (u8), else 0.
 * Fix vs the autoc draft: BEHAVIOUR: the result is the callee's return == 0 (the draft returned p == 0).
 * '(x >> 3) & 1' with an if/else into a u8 keeps the fw sequence; '& 8 ? 0x80 : 0' becomes sll 4 (69.57).
 * Aids: none.
 */
extern unsigned char ARR_a807cd2e[];
extern unsigned char FUN_a0086360(unsigned char, int, int, unsigned char);

unsigned char FUN_a008661c(unsigned char p)
{
  unsigned char v;
  if ((ARR_a807cd2e[p * 6] >> 3) & 1)
    v = 0x80;
  else
    v = 0;
  return FUN_a0086360(p, 0x80, 0x107, v) == 0;
}
