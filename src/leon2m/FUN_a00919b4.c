/* leon2m FUN_a00919b4 @ 0xa00919b4-0xa0091a68 (45 words), flags -mcpu=v8 -O3 -g.
 * afec family.
 * Code facts: FUN_a00a8ee8(word 0xa802afec - 0xe); FUN_a00aa0e8(afec - 0xe, 0); if afec > 0x14 (unsigned):
 * FUN_a00b0034(1), else FUN_a00af44c(0xe, 0) and FUN_a00a900c(0, 0). Then afec = 3, FUN_a00b4144(1, 1),
 * FUN_a00a9468(1, 2), tail FUN_a00b34d4(0, 1) (the common tail is duplicated per arm by jump threading).
 * void(void). afec = 3 is a constant store and both arms end in the same tail.
 * Source form: the '> 0x14' arm comes first. Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(int, int);
extern void FUN_a00aa0e8(unsigned char, int);
extern void FUN_a00af44c(unsigned char, unsigned char);
extern void FUN_a00b0034(int);
extern void FUN_a00b34d4(int, int);
extern void FUN_a00b4144(int, int);

void FUN_a00919b4(void)
{
  FUN_a00a8ee8(_DAT_a802afec - 0xe);
  FUN_a00aa0e8(_DAT_a802afec - 0xe, 0);
  if (_DAT_a802afec > 0x14)
    FUN_a00b0034(1);
  else {
    FUN_a00af44c(0xe, 0);
    FUN_a00a900c(0, 0);
  }
  _DAT_a802afec = 3;
  FUN_a00b4144(1, 1);
  FUN_a00a9468(1, 2);
  FUN_a00b34d4(0, 1);
}
