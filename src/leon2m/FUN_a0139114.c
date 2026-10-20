/* leon2m FUN_a0139114 @ 0xa0139114 (-mcpu=v8 -O2 -g)
 * Twin of FUN_a013923c: same code, other constants.
 * See FUN_a013923c for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802cba3;
extern void FUN_a01370dc(int, int, unsigned char *, int);
extern void FUN_a0137344(int);

unsigned char FUN_a0139114(unsigned char mode)
{
  unsigned char buf[4] = {0};

  switch (mode) {
  case 1: buf[0] = 3; break;
  case 2: buf[0] = 4; break;
  case 3: buf[0] = 5; break;
  case 0: buf[0] = 2; break;
  }
  FUN_a01370dc(0xa0, 4, buf, 0);
  FUN_a0137344(1);
  return DAT_a802cba3;
}
