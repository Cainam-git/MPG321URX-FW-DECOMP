/* leon2m FUN_a00958c4 @ 0xa00958c4-0xa0095930 (108 bytes, 27 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a93bc((u8)(_DAT_a802afec - 0x3f)); if the word _DAT_a802afec (re-read) is 0x42:
 * FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1); then on both paths _DAT_a802afec = 0xc and a tail call
 * FUN_a00a900c(1, 1) (fw: restore in the delay slot, %i0/%i1 = 1).
 * FUN_a00a900c takes TWO arguments (its entry overwrites %i2 before any read), so this function has no
 * parameters. Source form: the store + tail call is ONE shared tail after the if (two written copies give %o3
 * for 0xc in the first copy); the compiler duplicates it into both paths. Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c();
extern void FUN_a00a93bc();
extern void FUN_a00a9468();
extern void FUN_a00b34d4();

void FUN_a00958c4(void)
{
  FUN_a00a93bc(_DAT_a802afec - 0x3fU & 0xff);
  if (_DAT_a802afec == 0x42) {
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
  }
  _DAT_a802afec = 0xc;
  FUN_a00a900c(1, 1);
}
