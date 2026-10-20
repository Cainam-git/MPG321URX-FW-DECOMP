/* leon2m FUN_a0093884 @ 0xa0093884-0xa0093910 (35 words), flags -mcpu=v8 -O3 -g.
 * afec family.
 * Code facts: byte DAT_a802d290 + 0x1a3 = word 0xa802afec - 0x58, word afec = 0xc5 (the fw stores afec first);
 * FUN_a00b6290(1); FUN_a00b6514(0, 1); i = byte +0x1a3: byte +0x8c = t198[i] and +0x8d = t19c[i] (both loads
 * before both stores); FUN_a00a9468(2, 1), (0, 0), (1, 3); FUN_a00b344c(0); tail FUN_a00b34d4(3, 5). void(void).
 * afec = 0xc5 is a constant store; the tail takes 2 arguments.
 * Source form: DAT_a802d290 is a struct with the two 4-byte tables as array fields (a flat byte array keeps
 * load/store/load/store); the +0x8c copy comes first in the source. Aids: none.
 */
struct R290 {
  unsigned char pad[0x8c]; unsigned char b8c, b8d; unsigned char pad2[0x198 - 0x8e];
  unsigned char t198[4]; unsigned char t19c[4]; unsigned char pad3[0x1a3 - 0x1a0]; unsigned char b1a3;
};
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a9468(int, int);
extern void FUN_a00b344c(int);
extern void FUN_a00b34d4(int, int);
extern void FUN_a00b6290(int);
extern void FUN_a00b6514(int, int);

void FUN_a0093884(void)
{
  struct R290 *p = &DAT_a802d290;

  p->b1a3 = _DAT_a802afec - 0x58;
  _DAT_a802afec = 0xc5;
  FUN_a00b6290(1);
  FUN_a00b6514(0, 1);
  p->b8c = p->t198[p->b1a3];
  p->b8d = p->t19c[p->b1a3];
  FUN_a00a9468(2, 1);
  FUN_a00a9468(0, 0);
  FUN_a00a9468(1, 3);
  FUN_a00b344c(0);
  FUN_a00b34d4(3, 5);
}
