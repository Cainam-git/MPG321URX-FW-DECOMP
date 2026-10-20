/* leon2m FUN_a009bedc @ 0xa009bedc  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a009bf48: same code, constants swapped; byte-exact.
 * See FUN_a009bf48 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009bedc(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec - 0x3f);
  do {
    t = (unsigned short)_DAT_a802afec - 0x3c;
    t = t % 4;
    _DAT_a802afec = t + 0x3f;
  } while (FUN_a00aad30(t) != 1);
  FUN_a00a9650(_DAT_a802afec - 0x3f, 1);
}
