/* leon2m FUN_a0095134 @ 0xa0095134-0xa00951a8 (29 words), flags -mcpu=v8 -O3 -g.
 * Code facts: old = byte 0xa802d290+0x20, t = byte 0xa8025c55; byte 0xa802b08f = 0xf; byte +0x20 = t; if old != t:
 * FUN_a00d5938(1); FUN_a00a8c88(); FUN_a00a86e8(); word 0xa802afec = 0x7a; FUN_a00a9650(0, 1); then byte
 * 0xa8025c55 = byte +0x1a4. Near-twin of FUN_a0095430.
 * Fix vs the autoc draft (76.67): BEHAVIOUR - the 0xa8025c55 = +0x1a4 copy runs AFTER FUN_a00a9650(0, 1) (draft:
 * before); old and t are unsigned int locals with the compare in its own statement before the stores (u8 locals
 * re-extend t: 63.33 / 96.55); record as byte array like FUN_a0095430; no volatile on RAM. Aids: none.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d290[];
extern void FUN_a00d5938(int);
extern void FUN_a00a8c88(void);
extern void FUN_a00a86e8(void);
extern void FUN_a00a9650(int, int);

void FUN_a0095134(void)
{
  unsigned char *p = DAT_a802d290;
  unsigned int old = p[0x20];
  unsigned int t = DAT_a8025c55;
  int changed;

  changed = old != t;
  DAT_a802b08f = 0xf;
  p[0x20] = t;
  if (changed)
    FUN_a00d5938(1);
  FUN_a00a8c88();
  FUN_a00a86e8();
  _DAT_a802afec = 0x7a;
  FUN_a00a9650(0, 1);
  DAT_a8025c55 = p[0x1a4];
}
