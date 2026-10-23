/* leon2m FUN_a0091784 @ 0xa0091784 (-mcpu=v8 -O3 -g)
 * With w = word 0xA802AFEC: calls FUN_a00a8ee8(w - 0xB) and FUN_a00aa4c0(w - 0xB, 0), repeats t = ((low 16 bits of
 * w) - 9) % 3 (signed), w = t + 0xB until FUN_a00aa520(t) returns 1, then calls FUN_a00a900c(w - 0xB, 1),
 * FUN_a00aa4c0(w - 0xB, 1) and FUN_a00af44c(0xb, w - 0xB). Same code as FUN_a0091de8 with other constants.
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
