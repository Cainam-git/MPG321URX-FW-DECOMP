/* leon2m FUN_a00950a8 @ 0xa00950a8-0xa0095134 (35 words), flags -mcpu=v8 -O3 -g.
 * afec family.
 * Code facts: old = byte DAT_a802d290 + 0x20; the byte = FUN_a014459c(u8 (word 0xa802afec + 0x30)) (u8 return);
 * FUN_a00d5938(1) when the new byte != old (d5938 reads its u8 arg); byte 0xa802b08f = 0xf; FUN_a00a8c88();
 * FUN_a00a86e8(); word afec = 0x7a; FUN_a00a9650(0, 1); byte 0xa8025c55 = byte +0x1a4; byte 0xa802b08e |= 2.
 * void(void). Fix vs the autoc draft: BEHAVIOUR: afec = 0x7a and b08f = 0xf are constants (the draft stored
 * call returns), d5938 takes 1, c55 gets d290[0x1a4]; real base DAT_a802d290. Aids: none.
 */
struct R290 { unsigned char pad[0x20]; unsigned char b20; unsigned char pad2[0x1a4 - 0x21]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802b08f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a86e8(void);
extern void FUN_a00a8c88(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00d5938(int);
extern unsigned char FUN_a014459c(unsigned char);

void FUN_a00950a8(void)
{
  struct R290 *p = &DAT_a802d290;
  unsigned char old = p->b20;

  p->b20 = FUN_a014459c(_DAT_a802afec + 0x30);
  if (p->b20 != old)
    FUN_a00d5938(1);
  DAT_a802b08f = 0xf;
  FUN_a00a8c88();
  FUN_a00a86e8();
  _DAT_a802afec = 0x7a;
  FUN_a00a9650(0, 1);
  DAT_a8025c55 = p->b1a4;
  DAT_a802b08e |= 2;
}
