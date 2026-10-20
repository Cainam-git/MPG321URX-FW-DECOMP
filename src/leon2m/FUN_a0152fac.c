/* leon2m FUN_a0152fac @ 0xa0152fac-0xa0153018 (27 words), flags -mcpu=v8 -O3 -g.
 * Code facts: r = -1 when FUN_a011996c(0) or FUN_a011996c(1) returns non-zero (u8 return, btst 0xff), else 0.
 * When r differs from the word at 0xa802a4bc, FUN_a013a728(r) is called; then the word is set to r. void(void).
 * The callee arguments are the constants 0 and 1 (clr %o0 / mov 1,%o0); the second test uses the second
 * call's result. FUN_a011996c returns u8.
 * Aids: none.
 */
extern int _DAT_a802a4bc;
extern unsigned char FUN_a011996c(int);
extern void FUN_a013a728(int);

void FUN_a0152fac(void)
{
  int r = 0;

  if (FUN_a011996c(0) || FUN_a011996c(1))
    r = -1;
  if (r != _DAT_a802a4bc)
    FUN_a013a728(r);
  _DAT_a802a4bc = r;
}
