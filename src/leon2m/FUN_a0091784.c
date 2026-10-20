/* leon2m FUN_a0091784 @ 0xa0091784  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a0091de8: same code, constants swapped; byte-exact.
 * See FUN_a0091de8 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00aa4c0(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00af44c(unsigned char, unsigned char);

void FUN_a0091784(void)
{
  int t;

  FUN_a00a8ee8(_DAT_a802afec - 0xb);
  FUN_a00aa4c0(_DAT_a802afec - 0xb, 0);
  do {
    t = (unsigned short)_DAT_a802afec - 0x9;
    t = t % 3;
    _DAT_a802afec = t + 0xb;
  } while (FUN_a00aa520(t) != 1);
  FUN_a00a900c(_DAT_a802afec - 0xb, 1);
  FUN_a00aa4c0(_DAT_a802afec - 0xb, 1);
  FUN_a00af44c(0xb, _DAT_a802afec - 0xb);
}
