/* leon2m FUN_a0097ad0 @ 0xa0097ad0-0xa0097b7c (43 words), flags -mcpu=v8 -O3 -g.
 * Code facts: if byte 0xa802d290+0x2f != byte 0xa8025c54 then the record byte gets that value (stb in the
 * call delay slot) and FUN_a00da254() runs (return unused); FUN_a00a93bc(word 0xa802afec - 0x7f, as u8);
 * FUN_a00a813c(1, rec+0x2f, 1); FUN_a00a9650(rec+0x2f, 0); FUN_a00a9468(1, 2); word 0xa802afec = 0x25;
 * FUN_a00a900c(2, 1); FUN_a00a9468(1, 2); FUN_a00b34d4(0, 1); byte 0xa802b08f = 5. void(void).
 * Fix vs the autoc draft (69.77): BEHAVIOUR: the record byte is written with 0xa8025c54 (the draft stored
 * FUN_a00da254's return); real base DAT_a802d290 (draft used mid-record DAT_a802d2bf); byte types; real
 * callee prototypes. Aids: none.
 */
struct R290 { unsigned char pad[0x2f]; unsigned char b2f; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c54;
extern unsigned char DAT_a802b08f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00da254(void);

void FUN_a0097ad0(void)
{
  struct R290 *p = &DAT_a802d290;

  if (p->b2f != DAT_a8025c54) {
    p->b2f = DAT_a8025c54;
    FUN_a00da254();
  }
  FUN_a00a93bc(_DAT_a802afec - 0x7f);
  FUN_a00a813c(1, p->b2f, 1);
  FUN_a00a9650(p->b2f, 0);
  FUN_a00a9468(1, 2);
  _DAT_a802afec = 0x25;
  FUN_a00a900c(2, 1);
  FUN_a00a9468(1, 2);
  FUN_a00b34d4(0, 1);
  DAT_a802b08f = 5;
}
