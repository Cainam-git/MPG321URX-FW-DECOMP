/* leon2s FUN_a0086678 @ 0xa0086678-0xa00866a4 (11 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 11 words. Leaf (retl).
 * Code facts: returns bit 15 of word +0x20 of record DAT_a807a928[u8 idx] (0x28-byte records, idx*5*8).
 * Fix vs the autoc draft (72.73): BEHAVIOUR: the draft added idx*0x28 to the VALUE of word 0xa807a948 (fw: load at base+idx*0x28+0x20);
 * real base 0xa807a928 (the fw or 0x128) as a 40-byte struct array with the word at +0x20. Aids: none.
 */
struct R948 { unsigned char pad[0x20]; unsigned int w20; unsigned int pad2; };
extern struct R948 DAT_a807a928[];

unsigned int FUN_a0086678(unsigned char param_1)
{
  return DAT_a807a928[param_1].w20 >> 15 & 1;
}
