/* leon2m FUN_a00994b8 @ 0xa00994b8-0xa0099524 (27 words), flags -mcpu=v8 -O3 -g.
 * Family of FUN_a00999ec (d290 record bytes).
 * Code facts: v = byte 0xa802d290+0x17c; byte 0xa8025c56 = v; FUN_a00a813c(1, v, 0);
 * FUN_a00a900c((word 0xa802afec - 11) & 0xff, 2); word 0xa802afec = re-read rec+0x17c + 0x3c;
 * FUN_a00a9650(re-read rec+0x17c, 1); byte 0xa802b08e |= 2. void(void).
 * Fix vs the autoc draft (74.07): real base DAT_a802d290 as a struct (draft: DAT_a802d40c mid-record name),
 * kept in one pointer so the fw shares %l0. Aids: none.
 */
struct R290 { unsigned char pad[0x17c]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;

extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a00994b8(void)
{
  struct R290 *p;
  unsigned char v;

  p = &DAT_a802d290;
  v = p->b;
  DAT_a8025c56 = v;
  FUN_a00a813c(1, v, 0);
  FUN_a00a900c((_DAT_a802afec - 11) & 0xff, 2);
  _DAT_a802afec = p->b + 0x3c;
  FUN_a00a9650(p->b, 1);
  DAT_a802b08e = DAT_a802b08e | 2;
}
