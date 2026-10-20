/* leon2m FUN_a0096bd8 @ 0xa0096bd8-0xa0096c80 (42 words), flags -mcpu=v8 -O3 -g.
 * Code facts: if byte 0xa802d290+0x1a4 != byte 0xa8025c56: FUN_a00d91fc(0), copy the byte, FUN_a00830f4(0).
 * Then copy the byte again, FUN_a00a93bc((word 0xa802afec - 0x70) & 0xff), FUN_a00a9650(b1a4, 0),
 * FUN_a00a813c(1, b1a4, 1), word 0xa802afec = 0x1c, FUN_a00a900c(4, 1), FUN_a00acef4(), byte 0xa802b08f = 3. void.
 * The constant 0x1c is stored BEFORE the FUN_a00a900c call; FUN_a00acef4 is called after it.
 * Source form: the record is a struct pointer p = &DAT_a802d290 (fw sethi|or into %l0), no volatile (RAM).
 * Aids: none.
 */
struct R290 { unsigned char pad[0x1a4]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00830f4(int);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00acef4(void);
extern void FUN_a00d91fc(int);

void FUN_a0096bd8(void)
{
  struct R290 *p = &DAT_a802d290;

  if (p->b1a4 != DAT_a8025c56) {
    FUN_a00d91fc(0);
    p->b1a4 = DAT_a8025c56;
    FUN_a00830f4(0);
  }
  p->b1a4 = DAT_a8025c56;
  FUN_a00a93bc(_DAT_a802afec - 0x70);
  FUN_a00a9650(p->b1a4, 0);
  FUN_a00a813c(1, p->b1a4, 1);
  _DAT_a802afec = 0x1c;
  FUN_a00a900c(4, 1);
  FUN_a00acef4();
  DAT_a802b08f = 3;
}
