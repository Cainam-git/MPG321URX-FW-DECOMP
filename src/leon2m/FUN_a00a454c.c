/* leon2m FUN_a00a454c @ 0xa00a454c-0xa00a45a8 (23 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 23 words. Down-step twin of FUN_a00a44f4.
 * Code facts: v = (u8)(byte 0xa802d290+0xc - 5); if v is outside 5..0x1e the record byte = 5 (clamp), else the
 * record byte = v, FUN_a00b7674(1), FUN_a00d47b0(). Then byte 0xa802b08e |= 2. void(void). gcc folds the range
 * test into '(u8)(b - 10) <= 0x19' (fw add -10 / and 0xff / cmp 0x19 / bleu).
 * Fix vs the autoc draft (66.67): real base DAT_a802d290 (draft: mid-record DAT_a802d29c as a word); the clamp
 * arm FIRST ('v < 5 || v > 0x1e' -> 5; the in-range-first order gives other registers, 82.61). Aids: none.
 */
struct R290 { unsigned char pad[0xc]; unsigned char b0c; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00b7674(unsigned char);
extern void FUN_a00d47b0(void);

void FUN_a00a454c(void)
{
  struct R290 *p = &DAT_a802d290;
  unsigned char v = p->b0c - 5;

  if (v < 5 || v > 0x1e)
    p->b0c = 5;
  else {
    p->b0c = v;
    FUN_a00b7674(1);
    FUN_a00d47b0();
  }
  DAT_a802b08e |= 2;
}
