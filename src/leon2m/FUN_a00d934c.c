/* leon2m FUN_a00d934c @ 0xa00d934c-0xa00d93c8 (31 words), flags -mcpu=v8 -O3 -g.
 * Code facts: record DAT_a802d290: word +0xac |= 0x20000; bytes +0x1e and +0x20 are swapped (both read first,
 * then stb +0x1e, stb +0x20). If they were equal: return. Else FUN_a00d9238(); FUN_a01479ec(1) when word +0xa8
 * has bit 14 (0x4000); FUN_a0149978(1, byte +0x20); tail FUN_a00d5cd8(). void(void).
 * Fix vs the autoc draft: real base DAT_a802d290 (draft d2ae/d2b0/d338/d33c names; d2b0 typed as a word), byte
 * types, the tail takes no args. The test is written 'cur == old' (fold keeps the fw cmp %o4,%g1 order).
 * Aids: none.
 */
struct R290 {
  unsigned char pad[0x1e]; unsigned char b1e; unsigned char pad1; unsigned char b20;
  unsigned char pad2[0xa8 - 0x21]; unsigned int wa8; unsigned int wac;
};
extern struct R290 DAT_a802d290;
extern void FUN_a00d5cd8(void);
extern void FUN_a00d9238(void);
extern void FUN_a01479ec(unsigned char);
extern void FUN_a0149978(int, unsigned char);

void FUN_a00d934c(void)
{
  struct R290 *p = &DAT_a802d290;
  unsigned char old = p->b1e;
  unsigned char cur = p->b20;

  p->wac |= 0x20000;
  p->b1e = cur;
  p->b20 = old;
  if (cur == old)
    return;
  FUN_a00d9238();
  if (p->wa8 & 0x4000)
    FUN_a01479ec(1);
  FUN_a0149978(1, p->b20);
  FUN_a00d5cd8();
}
