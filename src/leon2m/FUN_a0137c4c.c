/* leon2m FUN_a0137c4c @ 0xa0137c4c-0xa0137cac (24 words), flags -mcpu=v8 -O3 -g.
 * Code facts: stack u8 buf[4] = {0} (one word clear at %fp-16); buf[0] = 0 for mode 2, 1 for mode 3, else 0xff
 * (stb, then a ldub reload); when buf[0] != 0xff: FUN_a01370dc(0x2b, 1, buf, 1). void.
 * Fix vs the autoc draft: written as a switch with a default (if/else forms give a different block layout,
 * 54..71); word-clear initializer instead of three byte clears; void. Aids: none.
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a0137c4c(int mode)
{
  unsigned char buf[4] = {0};

  switch (mode) {
  case 2: buf[0] = 0; break;
  case 3: buf[0] = 1; break;
  default: buf[0] = 0xff; break;
  }
  if (buf[0] != 0xff)
    FUN_a01370dc(0x2b, 1, buf, 1);
}
