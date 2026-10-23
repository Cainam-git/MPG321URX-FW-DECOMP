/* leon2m FUN_a01391a8 @ 0xa01391a8 (-mcpu=v8 -O2 -g)
 * b = 2, 3, 4 or 5 for p1 = 0, 1, 2 or 3 (0 for any other p1). Calls FUN_a01370dc(0xa4, 4, buf, 0) with the local
 * bytes buf = {b, 0, 0, 0} and FUN_a0137344(1); returns byte 0xA802CBA3. Same code as FUN_a013923c with other
 * constants.
 * See FUN_a013923c for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802cba3;
extern void FUN_a01370dc(int, int, unsigned char *, int);
extern void FUN_a0137344(int);

unsigned char FUN_a01391a8(unsigned char mode)
{
  unsigned char buf[4] = {0};

  switch (mode) {
  case 1: buf[0] = 3; break;
  case 2: buf[0] = 4; break;
  case 3: buf[0] = 5; break;
  case 0: buf[0] = 2; break;
  }
  FUN_a01370dc(0xa4, 4, buf, 0);
  FUN_a0137344(1);
  return DAT_a802cba3;
}
