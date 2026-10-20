/* leon2m FUN_a00d5f3c @ 0xa00d5f3c-0xa00d5f9c (24 words), flags -mcpu=v8 -O3 -g.
 * Code facts: record DAT_a802d290: when byte +0x4a != 0 and word +0xb0 != 0: byte +0x4a = 0 (the clrb sits in the
 * delay slot of the +0x1f test, so it runs on both paths), then if byte +0x1f == 0: FUN_a014d474(1, 0) and
 * FUN_a014dd98(1, 0). The function ends with a real 'nop' at the join label before ret/restore. void(void).
 * Source form: the record base DAT_a802d290.
 * Compiler aid: one asm nop at the end (the fw nop is not a delay slot: it is the branch target before 'ret').
 */
struct R290 {
  unsigned char pad[0x1f]; unsigned char b1f; unsigned char pad2[0x4a - 0x20]; unsigned char b4a;
  unsigned char pad3[0xb0 - 0x4b]; unsigned int wb0;
};
extern struct R290 DAT_a802d290;
extern void FUN_a014d474(int, int);
extern void FUN_a014dd98(int, int);

void FUN_a00d5f3c(void)
{
  struct R290 *p = &DAT_a802d290;

  if (p->b4a != 0 && p->wb0 != 0) {
    p->b4a = 0;
    if (p->b1f == 0) {
      FUN_a014d474(1, 0);
      FUN_a014dd98(1, 0);
    }
  }
  __asm__ volatile ("nop");
}
