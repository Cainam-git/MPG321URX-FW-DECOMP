/* leon2m FUN_a0092648 @ 0xa0092648-0xa00926c8 (32 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a8ee8(word 0xa802afec - 0x23, as u8); FUN_a00a813c(0, byte 0xa802d290+0x1f, 1);
 * FUN_a00a900c(rec+0x1f, 0); word 0xa802afec = 7; FUN_a00b4144(5, 1); FUN_a00acef4(); FUN_a00a9468(1, 2);
 * FUN_a00b34d4(0, 1); tail FUN_a00af44c(0x23, rec+0x1f) (the 0x23 is set in the acef4 delay slot). void(void).
 * The record base is DAT_a802d290; the tail call takes 2 arguments.
 * Source form: the record pointer is taken after the first call (fw sethi of 0xa802d290 after it). Aids: none.
 */
struct R290 { unsigned char pad[0x1f]; unsigned char b1f; };
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00acef4(void);
extern void FUN_a00af44c(unsigned char, unsigned char);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00b4144(int, int);

void FUN_a0092648(void)
{
  struct R290 *p;

  FUN_a00a8ee8(_DAT_a802afec - 0x23);
  p = &DAT_a802d290;
  FUN_a00a813c(0, p->b1f, 1);
  FUN_a00a900c(p->b1f, 0);
  _DAT_a802afec = 7;
  FUN_a00b4144(5, 1);
  FUN_a00acef4();
  FUN_a00a9468(1, 2);
  FUN_a00b34d4(0, 1);
  FUN_a00af44c(0x23, p->b1f);
}
