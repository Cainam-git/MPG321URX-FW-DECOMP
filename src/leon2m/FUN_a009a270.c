/* leon2m FUN_a009a270 @ 0xa009a270-0xa009a2d0 (24 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 24 words.
 * Code facts: FUN_a00a93bc((word 0xa802afec + 0xf) & 0xff); v = byte 0xa8025c55; byte 0xa802d290+0x1dd = v;
 * FUN_a00a9650(v, 2); FUN_a00a813c(1, byte +0x1dd (re-read), 1); word 0xa802afec = 0x34; tail FUN_a00a900c(0, 1).
 * Fix vs the autoc draft (75.00): v is a u8 local (the fw re-extends the loaded byte with 'and 0xff' for the
 * call while storing the raw register: the QImode local), record via struct pointer, no params (the draft
 * passed 4 junk params to the tail call; the fw sets only %o0/%o1). Aids: none.
 */
struct R290 { unsigned char pad[0x1dd]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009a270(void)
{
  struct R290 *p;
  unsigned char v;

  FUN_a00a93bc(_DAT_a802afec + 0xf);
  p = &DAT_a802d290;
  v = DAT_a8025c55;
  p->b = v;
  FUN_a00a9650(v, 2);
  FUN_a00a813c(1, p->b, 1);
  _DAT_a802afec = 0x34;
  FUN_a00a900c(0, 1);
}
