/* leon2m FUN_a013923c @ 0xa013923c-0xa01392d0 (37 words), flags -mcpu=v8 -O3 -g.
 * Same shape as FUN_a0137c4c.
 * Code facts: stack u8 buf[4] = {0} (word clear at %fp-16); buf[0] = 3 / 4 / 5 / 2 for mode 1 / 2 / 3 / 0
 * (case tree rooted at 1), other modes leave 0; FUN_a01370dc(0xa1, 4, buf, 0); FUN_a0137344(1); returns byte
 * 0xa802cba3 (u8). Source form: a switch, not an if-chain. Aids: none.
 */
extern unsigned char DAT_a802cba3;
extern void FUN_a01370dc(int, int, unsigned char *, int);
extern void FUN_a0137344(int);

unsigned char FUN_a013923c(unsigned char mode)
{
  unsigned char buf[4] = {0};

  switch (mode) {
  case 1: buf[0] = 3; break;
  case 2: buf[0] = 4; break;
  case 3: buf[0] = 5; break;
  case 0: buf[0] = 2; break;
  }
  FUN_a01370dc(0xa1, 4, buf, 0);
  FUN_a0137344(1);
  return DAT_a802cba3;
}
