/* leon2s FUN_a0086678 @ 0xa0086678-0xa00866a4 (11 words), flags -mcpu=v8 -Os -g.
 * Leaf (retl).
 * Returns bit 15 of word +0x20 of record DAT_a807a928[u8 idx] (0x28-byte records, idx*5*8): the firmware
 * loads from base + idx*0x28 + 0x20, with the base 0xa807a928 (or 0x128) as a 40-byte struct array.
 */
struct R948 { unsigned char pad[0x20]; unsigned int w20; unsigned int pad2; };
extern struct R948 DAT_a807a928[];

unsigned int FUN_a0086678(unsigned char param_1)
{
  return DAT_a807a928[param_1].w20 >> 15 & 1;
}
