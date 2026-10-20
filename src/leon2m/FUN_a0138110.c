/* leon2m FUN_a0138110 @ 0xa0138110-0xa0138148 (14 words), flags -mcpu=v8 -O3 -g.
 * Code facts: a 4-byte stack buffer is cleared with one word store ('clr [fp-16]', in the bne delay slot, so on
 * both paths); only when the u8 param_1 is 0 (btst 0xff) are bytes [0] = param_1 and [1] = param_2 stored and
 * FUN_a01370dc(0x5f, 4, buf, 0) called (the same message-send callee as FUN_a0137d40). Returns nothing.
 * Source form: the zero initializer comes first, the byte stores are inside the arm (a '{p1, p2}' initializer
 * puts the stb of p2 before the test). u8 params. Aids: none.
 */
extern void FUN_a01370dc(int, int, void *, int);

void FUN_a0138110(unsigned char param_1, unsigned char param_2)
{
  unsigned char buf[4] = { 0 };

  if (param_1 == 0) {
    buf[0] = param_1;
    buf[1] = param_2;
    FUN_a01370dc(0x5f, 4, buf, 0);
  }
}
