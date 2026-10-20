/* leon2m FUN_a009a198 @ 0xa009a198-0xa009a1ec (21 words), flags -mcpu=v8 -O3 -g.
 * Code facts: b = byte 0xa802d290+0x1dd; byte 0xa8025c55 = b; FUN_a00a93bc((word 0xa802afec + 0x48) & 0xff);
 * FUN_a00a8c88(); FUN_a00ac718(0xba); word 0xa802afec = b + 0xf1 (b re-read); tail FUN_a00a9650(b, 1).
 * Fix vs the autoc draft (76.19): FUN_a00ac718 takes ONE argument (the draft's 2nd arg 0xa8025c00 was a stale
 * %o1 from before the FUN_a00a8c88 call; the 'mov 1, %i1' in that call's delay slot is for the tail call);
 * no params; record field via struct pointer (draft: mid-record DAT_a802d46d as int). Aids: none.
 */
struct R290 { unsigned char pad[0x1dd]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8c88(void);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00ac718(unsigned int);

void FUN_a009a198(void)
{
  struct R290 *p = &DAT_a802d290;

  DAT_a8025c55 = p->b;
  FUN_a00a93bc(_DAT_a802afec + 0x48);
  FUN_a00a8c88();
  FUN_a00ac718(0xba);
  _DAT_a802afec = p->b + 0xf1;
  FUN_a00a9650(p->b, 1);
}
