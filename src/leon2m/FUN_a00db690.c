/* leon2m FUN_a00db690 @ 0xa00db690-0xa00db738 (42 words), flags -mcpu=v8 -O3 -g.
 * Code facts: v = 0 when FUN_a014bd70(0) == 1; else when FUN_a01438dc(0) == 1 and FUN_a014ba68() is 1..4 (case
 * tree rooted at 2) v = 0; otherwise v = 1 if bit 15 of word 0xa802d404 is set (sethi 0x8000 / btst), else 0.
 * Then FUN_a014e878(v) and tail FUN_a00d9120(). void(void).
 * Each path calls FUN_a014e878 with its own constant and the shared calls are cross-jumped: the fw keeps the
 * constant in %o0 per path. Case 3 shares the bit-clear block ('goto zero', the fw sends case 3 to the same
 * clr %o0 block). A v variable gives an extra mov / and 1, and if-conversion of the bit test.
 * Aids: none.
 */
extern unsigned int DAT_a802d404;
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);
extern void FUN_a014e878(unsigned char);
extern void FUN_a00d9120(void);
void FUN_a00db690(void)
{
  if (FUN_a014bd70(0) == 1)
    goto zero;
  if (FUN_a01438dc(0) == 1) {
    switch (FUN_a014ba68()) {
    case 1: FUN_a014e878(0); FUN_a00d9120(); return;
    case 2: FUN_a014e878(0); FUN_a00d9120(); return;
    case 3: goto zero;
    case 4: FUN_a014e878(0); FUN_a00d9120(); return;
    }
  }
  if (DAT_a802d404 & 0x8000) {
    FUN_a014e878(1);
    FUN_a00d9120();
    return;
  }
zero:
  FUN_a014e878(0);
  FUN_a00d9120();
}
