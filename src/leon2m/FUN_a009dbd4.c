/* leon2m FUN_a009dbd4 @ 0xa009dbd4 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a009dc84: same code, other constants.
 * See FUN_a009dc84 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009dbd4(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec - 0x44);
  do {
    t = (unsigned short)_DAT_a802afec - 0x41;
    t = t % 4;
    _DAT_a802afec = t + 0x44;
  } while (FUN_a00aad30(t) != 1);
  FUN_a00a9650(_DAT_a802afec - 0x44, 1);
  {
    unsigned char v = DAT_a8025c56;
    if (_DAT_a802afec - 0x46 == v)
      FUN_a00a813c(1, v + 2, 0);
    else
      FUN_a00a813c(1, v + 2, 1);
  }
}
