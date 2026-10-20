/* leon2m FUN_a014459c @ 0xa014459c-0xa01445fc (24 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0.
 * Code facts: reverse lookup in the 4-entry ROM table DAT_001a6db2 of {u8 a, u8 b} pairs: for i = 0..3, when
 * entry i's b equals v the result becomes entry i's a (the LAST match wins, no early exit); no match gives
 * 0xff. u8 parameter and result. Aids: none.
 */
struct Pair { unsigned char a; unsigned char b; };
extern const struct Pair DAT_001a6db2[4];

unsigned char FUN_a014459c(unsigned char v)
{
  unsigned char r = 0xff;
  unsigned char i;

  for (i = 0; i <= 3; i++) {
    if (DAT_001a6db2[i].b == v)
      r = DAT_001a6db2[i].a;
  }
  return r;
}
