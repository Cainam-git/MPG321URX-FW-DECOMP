/* leon2m FUN_a0095afc @ 0xa0095afc-0xa0095b58 (23 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 23 words.
 * Code facts: b = byte 0xa802d290+0x15b (re-read after each call); FUN_a00a813c(1, b, 0);
 * FUN_a00a900c((word 0xa802afec - 14) & 0xff, 2); word 0xa802afec = b + 0x4e; FUN_a00a9650(b, 1);
 * byte 0xa8025c56 = b. void, no parameters.
 * Fix vs the autoc draft (78.26): the record is DAT_a802d290 field +0x15b via a struct pointer (fw sethi|or into
 * %l0; the draft named mid-record DAT_a802d3eb as a 4-byte int), u8 callee prototypes, void. Aids: none.
 */
struct R290 { unsigned char pad[0x15b]; unsigned char b15b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0095afc(void)
{
  struct R290 *p = &DAT_a802d290;

  FUN_a00a813c(1, p->b15b, 0);
  FUN_a00a900c(_DAT_a802afec - 14, 2);
  _DAT_a802afec = p->b15b + 0x4e;
  FUN_a00a9650(p->b15b, 1);
  DAT_a8025c56 = p->b15b;
}
