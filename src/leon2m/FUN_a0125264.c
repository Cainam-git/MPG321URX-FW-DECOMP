/* leon2m FUN_a0125264 @ 0xa0125264-0xa0125294 (12 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 12 words. Leaf.
 * Code facts: r = ROM record DAT_001a42a8[n] (0x16-byte rows, smul 0x16; same table as FUN_a0124da4 /
 * FUN_a0125380); returns r->b12 when r->b01 == 1, else 0xf.
 * Fix vs the autoc draft (66.67): real base DAT_001a42a8 as a struct array (draft used 0x1a42a9 / 0x1a42ba
 * constants); the result is held in an unsigned int local (a u8 local adds 'and 0xff' before the retl; both
 * values are already zero-extended bytes). Aids: none.
 */
struct rec { unsigned char b00, b01; unsigned char b02[0x10]; unsigned char b12; unsigned char b13[3]; };
extern const struct rec DAT_001a42a8[];

unsigned char FUN_a0125264(unsigned char n)
{
  const struct rec *r = &DAT_001a42a8[n];
  unsigned int v = 0xf;

  if (r->b01 == 1)
    v = r->b12;
  return v;
}
