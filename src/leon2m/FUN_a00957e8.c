/* leon2m FUN_a00957e8 @ 0xa00957e8-0xa009584c (25 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a8c88(); v = byte 0xa802d290+0x17b; word 0xa802afec = v + 0xed; byte 0xa8025c55 = v;
 * FUN_a00b3ac8(); FUN_a00a9650(byte +0x17b, 0); FUN_a00a9650(byte +0x17b, 1); FUN_a00a9468(1, 3);
 * tail FUN_a00b34d4(0, 4).
 * FUN_a00a8c88 takes no argument (the 'clr %i0' in its delay slot is the tail call's first argument); the tail
 * call takes 2 arguments. Source form: v is a u8 local (fw 'and 0xff' before the + 0xed while the store uses the
 * raw ldub register); no volatile on RAM. Aids: none.
 */
struct R290 { unsigned char pad[0x17b]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8c88(void);
extern void FUN_a00a9468(int, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00b3ac8(void);

void FUN_a00957e8(void)
{
  struct R290 *p;
  unsigned char v;

  FUN_a00a8c88();
  p = &DAT_a802d290;
  v = p->b;
  _DAT_a802afec = v + 0xed;
  DAT_a8025c55 = v;
  FUN_a00b3ac8();
  FUN_a00a9650(p->b, 0);
  FUN_a00a9650(p->b, 1);
  FUN_a00a9468(1, 3);
  FUN_a00b34d4(0, 4);
}
