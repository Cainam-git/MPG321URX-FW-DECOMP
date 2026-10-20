/* leon2m FUN_a0095430 @ 0xa0095430-0xa00954a0 (28 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches.
 * Code facts: DAT_a802b08f = 0xf; t = DAT_a8025c55; if rec[0x31] != t (rec = DAT_a802d290):
 * rec[0x31] = t, FUN_a00d7b20(). Then FUN_a00a8c88(), FUN_a00a86e8(), _DAT_a802afec = 0x7b,
 * FUN_a00a9650(1, 1), DAT_a8025c55 = rec[0x1a4]. void.
 * Fix vs the autoc draft (89.66): real base DAT_a802d290 as a plain byte array (the draft's volatile
 * constant pointer kept the rec[0x31] store out of the call delay slot); void callees. Aids: none.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d290[];
extern void FUN_a00d7b20(void);
extern void FUN_a00a8c88(void);
extern void FUN_a00a86e8(void);
extern void FUN_a00a9650(int, int);

void FUN_a0095430(void)
{
  unsigned char t;

  DAT_a802b08f = 0xf;
  t = DAT_a8025c55;
  if (DAT_a802d290[0x31] != t) {
    DAT_a802d290[0x31] = t;
    FUN_a00d7b20();
  }
  FUN_a00a8c88();
  FUN_a00a86e8();
  _DAT_a802afec = 0x7b;
  FUN_a00a9650(1, 1);
  DAT_a8025c55 = DAT_a802d290[0x1a4];
}
