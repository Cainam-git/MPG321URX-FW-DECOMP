/* leon2m FUN_a009a020 @ 0xa009a020-0xa009a078 (22 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 22 words.
 * Code facts: b = byte 0xa802d290+0x1ee (re-read after each call); byte 0xa8025c56 = b;
 * FUN_a00a900c((word 0xa802afec - 0x34) & 0xff, 2); word 0xa802afec = b + 0xc3; FUN_a00a9650(b, 1);
 * tail FUN_a00a813c(1, b, 0). Twin of FUN_a0099c0c (other field / mirror byte / offset).
 * Required forms: the record is DAT_a802d290 field +0x1ee via a struct pointer (fw sethi|or into %l0;
 * not a mid-record DAT_a802d47e int), u8 callee prototypes (as in the callees' files). Aids: none.
 */
struct R290 { unsigned char pad[0x1ee]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009a020(void)
{
  struct R290 *p = &DAT_a802d290;

  DAT_a8025c56 = p->b;
  FUN_a00a900c(_DAT_a802afec - 0x34, 2);
  _DAT_a802afec = p->b + 0xc3;
  FUN_a00a9650(p->b, 1);
  FUN_a00a813c(1, p->b, 0);
}
