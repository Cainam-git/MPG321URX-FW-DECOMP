/* leon2s FUN_a00a6e8c @ 0xa00a6e8c  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00a6938: same code, constants swapped; byte-exact.
 * See FUN_a00a6938 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned int FUN_a00a6da8(unsigned char, unsigned short);

unsigned short FUN_a00a6e8c(unsigned char port, unsigned short reg)
{
  unsigned int v;
  unsigned char n;

  v = FUN_a00a6da8(port, reg);
  for (n = 0; (unsigned short)v != (unsigned short)FUN_a00a6da8(port, reg) && n <= 4; n++)
    v = FUN_a00a6da8(port, reg);
  return v;
}
