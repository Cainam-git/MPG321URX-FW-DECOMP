/* leon2m FUN_a0099c0c @ 0xa0099c0c-0xa0099c64 (22 words), flags -mcpu=v8 -O3 -g.
 * Code facts: b = byte 0xa802d290+0x1dd (re-read after each call); byte 0xa8025c55 = b;
 * FUN_a00a900c((word 0xa802afec - 0x34) & 0xff, 2); word 0xa802afec = b + 0xf1; FUN_a00a9650(b, 1);
 * tail FUN_a00a813c(1, b, 0). Twin of FUN_a009a020 (other field / mirror byte / offset).
 * Source form: the record is DAT_a802d290 field +0x1dd via a struct pointer (fw sethi|or into %l0); u8 callee
 * prototypes. Aids: none.
 */
struct R290 { unsigned char pad[0x1dd]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0099c0c(void)
{
  struct R290 *p = &DAT_a802d290;

  DAT_a8025c55 = p->b;
  FUN_a00a900c(_DAT_a802afec - 0x34, 2);
  _DAT_a802afec = p->b + 0xf1;
  FUN_a00a9650(p->b, 1);
  FUN_a00a813c(1, p->b, 0);
}
