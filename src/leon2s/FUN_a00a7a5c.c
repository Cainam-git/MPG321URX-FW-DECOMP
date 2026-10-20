/* leon2s FUN_a00a7a5c @ 0xa00a7a5c-0xa00a7acc (28 words), flags -mcpu=v8 -Os -g.
 * Twin of FUN_a00a6f08 (int result here).
 * Code facts: v = FUN_a00a79c4(port, reg) (int, (hi << 8) | lo); while a fresh read differs from v and the u8
 * retry counter n <= 4: v = another read, n++. Returns v in %i0 (int, no extension).
 * Fix vs the autoc draft: BEHAVIOUR: the result is the last read value (the draft returned the port byte and
 * compared the port with the read). Aids: none.
 */
extern int FUN_a00a79c4(unsigned char, unsigned short);

int FUN_a00a7a5c(unsigned char port, unsigned short reg)
{
  int v;
  unsigned char n;

  v = FUN_a00a79c4(port, reg);
  for (n = 0; v != FUN_a00a79c4(port, reg) && n <= 4; n++)
    v = FUN_a00a79c4(port, reg);
  return v;
}
