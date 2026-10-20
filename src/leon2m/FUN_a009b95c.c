/* leon2m FUN_a009b95c @ 0xa009b95c (-mcpu=v8 -O3 -g)
 * Twin of FUN_a009ba34: same code, other constants.
 * See FUN_a009ba34 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d2db;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d5eac(int);
extern void FUN_a014a8d4(int, int, int);

void FUN_a009b95c(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec + 0x19);
  do {
    t = (unsigned short)_DAT_a802afec - 0xe5;
    t = t % 3;
    _DAT_a802afec = t + 0xe7;
  } while (FUN_a00aad30(t) != 1);
  DAT_a802d2db = _DAT_a802afec + 0x19;
  FUN_a00a9650(_DAT_a802afec + 0x19, 1);
  FUN_a00d5eac(1);
  {
    unsigned char v = DAT_a8025c55;
    if (_DAT_a802afec - 0xe7 == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
  DAT_a802b08e |= 2;
  FUN_a014a8d4(1, 0, 0);
}
