/* leon2m FUN_a012ce18 @ 0xa012ce18-0xa012ce24 (3 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 3 words. Leaf.
 * Code facts: returns the u16 value 0xffff, built as 'sethi %hi(0xffff0000); srl 16' (the zero-extension of a
 * HImode -1 that was split into sll/srl at expand and folded only later). A plain 'return 0xffff' gives
 * sethi/or 0x3ff. Fix vs the autoc draft (66.67): the value goes through an unsigned short local before the
 * return ('unsigned short r; r = 0xffff; return r;'); a short local or 'r = 0; r--' give the same code. Aids: none.
 */
unsigned short FUN_a012ce18(void)
{
  unsigned short r;

  r = 0xffff;
  return r;
}
