/* leon2m FUN_a0096598 @ 0xa0096598-0xa0096610 (30 words), flags -mcpu=v8 -O3 -g.
 * Code facts: byte 0xa802d290+0x11 = byte 0xa8025c56; FUN_a00a93bc((word 0xa802afec - 0x6c) & 0xff);
 * FUN_a00a9650(b11, 0); FUN_a00a813c(1, b11, 1) (b11 re-read after each call); FUN_a00d9764();
 * word 0xa802afec = 0x1b; FUN_a00a900c(3, 1); byte 0xa802b08f = 3. void, no params.
 * Fix vs the autoc draft (76.67): record field via struct pointer (fw sethi|or into %l0; the draft named
 * mid-record DAT_a802d2a1 as a 4-byte int), u8 prototypes, void. Aids: none.
 */
struct R290 { unsigned char pad[0x11]; unsigned char b11; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00d9764(void);

void FUN_a0096598(void)
{
  struct R290 *p = &DAT_a802d290;

  p->b11 = DAT_a8025c56;
  FUN_a00a93bc(_DAT_a802afec - 0x6c);
  FUN_a00a9650(p->b11, 0);
  FUN_a00a813c(1, p->b11, 1);
  FUN_a00d9764();
  _DAT_a802afec = 0x1b;
  FUN_a00a900c(3, 1);
  DAT_a802b08f = 3;
}
