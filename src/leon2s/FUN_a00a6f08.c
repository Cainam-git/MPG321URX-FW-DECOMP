/* leon2s FUN_a00a6f08 @ 0xa00a6f08-0xa00a6f78 (28 words), flags -mcpu=v8 -Os -g.
 * Twin of FUN_a00a7a5c (unsigned short v, int return, as FUN_a00a7a5c).
 * v = (u16)FUN_a00a6e10(port, reg); while a fresh read differs from v and the u8 retry counter n <= 4 (n++ sits
 * in the be delay slot): v = (u16)another read, n++. Returns v. FUN_a00a6e10 returns (hi << 8) | lo as an int
 * (its retl does not truncate). u8 port, u16 reg.
 * Source form: one loop 'for (n = 0; v != rd() && n <= 4; n++) v = rd();', v unsigned short, int return
 * (its callers use the full register without a zero-extension).
 */
extern int FUN_a00a6e10(unsigned char, unsigned short);

int FUN_a00a6f08(unsigned char port, unsigned short reg)
{
  unsigned short v;
  unsigned char n;

  v = FUN_a00a6e10(port, reg);
  for (n = 0; v != FUN_a00a6e10(port, reg) && n <= 4; n++)
    v = FUN_a00a6e10(port, reg);
  return v;
}
