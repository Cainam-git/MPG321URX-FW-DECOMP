/* leon2m FUN_a00a44f4 @ 0xa00a44f4-0xa00a454c (22 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 22 words.
 * Code facts: v = (u8)(byte 0xa802d290+0xc + 5); if v <= 0x1e: the record byte = v, FUN_a00b7674(1),
 * FUN_a00d47b0(); else the record byte = 0x1e (clamp). Then byte 0xa802b08e |= 2. void(void).
 * Fix vs the autoc draft (68.18): real base DAT_a802d290 (draft used mid-record DAT_a802d29c as a word and a
 * u16 test); the sum is a u8 local; FUN_a00b7674 takes one u8 (and %i0,0xff at its entry). Aids: none.
 */
struct R290 { unsigned char pad[0xc]; unsigned char b0c; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00b7674(unsigned char);
extern void FUN_a00d47b0(void);

void FUN_a00a44f4(void)
{
  struct R290 *p = &DAT_a802d290;
  unsigned char v = p->b0c + 5;

  if (v < 0x1f) {
    p->b0c = v;
    FUN_a00b7674(1);
    FUN_a00d47b0();
  } else
    p->b0c = 0x1e;
  DAT_a802b08e |= 2;
}
