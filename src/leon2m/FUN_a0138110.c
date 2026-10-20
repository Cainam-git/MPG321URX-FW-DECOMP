/* leon2m FUN_a0138110 @ 0xa0138110-0xa0138148 (14 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 14 words.
 * Code facts: a 4-byte stack buffer is cleared with one word store ('clr [fp-16]', in the bne delay slot, so on
 * both paths); only when the u8 param_1 is 0 (btst 0xff) are bytes [0] = param_1 and [1] = param_2 stored and
 * FUN_a01370dc(0x5f, 4, buf, 0) called (the same message-send callee as FUN_a0137d40). void.
 * Fix vs the autoc draft (73.33): the zero initializer comes first, the byte stores are inside the arm
 * (the draft's '{p1, p2}' initializer put the stb of p2 before the test). u8 params. Aids: none.
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
