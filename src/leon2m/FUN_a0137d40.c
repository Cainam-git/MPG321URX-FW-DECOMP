/* leon2m FUN_a0137d40 @ 0xa0137d40-0xa0137d6c (11 words), flags -mcpu=v8 -O3 -g.
 * Code facts: a 4-byte stack buffer is cleared with one word store, byte [0] = the u8 param, then
 * FUN_a01370dc(0x2f, 4, buf, 1). void.
 * Fix vs the autoc draft (72.73): a 4-byte buffer with an initializer (the draft's single u8 local had no word
 * clear); callee prototype void (int, int, void *, int) as in the accepted users. Aids: none.
 */
extern void FUN_a01370dc(int, int, void *, int);

void FUN_a0137d40(unsigned char param_1)
{
  unsigned char buf[4] = { param_1 };

  FUN_a01370dc(0x2f, 4, buf, 1);
}
