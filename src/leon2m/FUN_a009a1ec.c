/* leon2m FUN_a009a1ec @ 0xa009a1ec-0xa009a270 (33 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a813c(1, byte 0xa8025c55, 0); FUN_a00a93bc((word 0xa802afec + 0xf) & 0xff);
 * FUN_a00a9650(byte 0xa802d290+0x1dd, 2); FUN_a00a813c(1, byte +0x1dd, 1); word 0xa802afec = 0x34;
 * FUN_a00a900c(0, 1); FUN_a00dab08(); byte 0xa802b08e |= 2. void, no params.
 * FUN_a00a813c(1, 5c55, 0) runs BEFORE FUN_a00a93bc. Source form: the record field via a struct pointer.
 * Aids: none.
 */
struct R290 { unsigned char pad[0x1dd]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00dab08(void);

void FUN_a009a1ec(void)
{
  struct R290 *p;

  FUN_a00a813c(1, DAT_a8025c55, 0);
  FUN_a00a93bc(_DAT_a802afec + 0xf);
  p = &DAT_a802d290;
  FUN_a00a9650(p->b, 2);
  FUN_a00a813c(1, p->b, 1);
  _DAT_a802afec = 0x34;
  FUN_a00a900c(0, 1);
  FUN_a00dab08();
  DAT_a802b08e |= 2;
}
