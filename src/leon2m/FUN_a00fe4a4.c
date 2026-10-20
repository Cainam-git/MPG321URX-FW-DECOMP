/* leon2m FUN_a00fe4a4 @ 0xa00fe4a4-0xa00fe6c8 (137 words). BYTE-EXACT: -mcpu=v8 -O3 -g,
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 137 words. void(u8 blk, u8 cls).
 * What it does: register set-up of block blk by the source class code cls (GlobalModeHandler FUN_a0131518 calls
 * it with sel and cls = byte +0x0a of the port record DAT_a802e224[src], in modes 1 and 2, before
 * FUN_a00fd594 / FUN_a00fd9a0 with 0xb1):
 *   0x51: 0xcf02dc04 &= ~0x13; 0xcf011750 = (u8)((reg & ~7) | 2); block reg 4 = 0x8a (FUN_a00f1ad4)
 *   0x61: 0xcf02dc04 &= ~0x13; 0xcf011750 = (u8)((reg & ~7) | 5); block reg 4 = 0x8e
 *   0x71: 0xcf02dc04 |= 0x13; 0xcf02dc18 |= 1; 0xcf011674 bit 0 cleared; reg 4 = 0x83; reg 3 bit 0 cleared
 *   0x81: same, but 0xcf011674 bit 0 SET and reg 3 bit 0 SET (FUN_a00f1b5c(blk, 3, 1, 1))
 *   other codes: nothing; then always: reg 0x5c bit 0 cleared (FUN_a00f1b5c(blk, 0x5c, 1, 0)), and
 *   reg 0x40 = (reg 0x40 | 1) & ~2 (FUN_a00f1e0c read, FUN_a00f1e50 write, tail call).
 * The steps depend only on the class code of the selected source (not on the rate).
 * Code facts that fix the source: the 0xcf011750 value goes through an unsigned char local (fw 'and -8; or;
 * and 0xff'; a cast of the whole expression folds to 'or; and 0xfa'); a natural switch (gcc's case tree gives
 * the fw compare order 0x61, 0x71, 0x81, 0x51). volatile only on the 0xcf... hardware registers. Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char FUN_a00f1e0c(unsigned char blk, unsigned char reg);
extern void FUN_a00f1e50(unsigned char blk, unsigned char reg, unsigned char val);

void FUN_a00fe4a4(unsigned char blk, unsigned char cls)
{
  unsigned char v;

  switch (cls) {
  case 0x51:
    R(0xcf02dc04) &= ~0x13;
    v = (R(0xcf011750) & ~7) | 2;
    R(0xcf011750) = v;
    FUN_a00f1ad4(blk, 4, 0x8a);
    break;
  case 0x61:
    R(0xcf02dc04) &= ~0x13;
    v = (R(0xcf011750) & ~7) | 5;
    R(0xcf011750) = v;
    FUN_a00f1ad4(blk, 4, 0x8e);
    break;
  case 0x71:
    R(0xcf02dc04) |= 0x13;
    R(0xcf02dc18) |= 1;
    R(0xcf011674) &= ~1;
    FUN_a00f1ad4(blk, 4, 0x83);
    FUN_a00f1b5c(blk, 3, 1, 0);
    break;
  case 0x81:
    R(0xcf02dc04) |= 0x13;
    R(0xcf02dc18) |= 1;
    R(0xcf011674) |= 1;
    FUN_a00f1ad4(blk, 4, 0x83);
    FUN_a00f1b5c(blk, 3, 1, 1);
    break;
  }
  FUN_a00f1b5c(blk, 0x5c, 1, 0);
  FUN_a00f1e50(blk, 0x40, (FUN_a00f1e0c(blk, 0x40) | 1) & ~2);
}
