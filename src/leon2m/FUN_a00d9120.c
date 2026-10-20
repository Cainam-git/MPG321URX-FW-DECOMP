/* leon2m FUN_a00d9120 @ 0xa00d9120-0xa00d91fc (55 words).
 * When FUN_a014bd70(0) returns 1, or FUN_a01438dc(0) returns 1 and FUN_a014ba68() returns 1..4:
 * FUN_a014bd0c(0) and tail FUN_a0087d5c(0). Otherwise, when byte 0xa802d290+0x15b is 4 or bit 15 of the word at
 * +0x174 is set: FUN_a014bd0c(2), func_0x4008e2a4() and FUN_a0087d5c(0); else FUN_a014bd0c(0),
 * func_0x4008e2a4() and FUN_a0087d5c(byte +0x15b). Each case has its own body (shared labels give a range test
 * instead of the firmware's case tree).
 */
struct R290 {
    unsigned char pad0[0x15b];
    unsigned char b15b;
    unsigned char pad15c[0x174 - 0x15c];
    unsigned int w174;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);
extern void FUN_a014bd0c(unsigned char);
extern void func_0x4008e2a4(void);
extern void FUN_a0087d5c(unsigned char);

void FUN_a00d9120(void)
{
  if (FUN_a014bd70(0) == 1) {
    FUN_a014bd0c(0);
    FUN_a0087d5c(0);
    return;
  }
  if (FUN_a01438dc(0) == 1) {
    switch (FUN_a014ba68()) {
    case 1: FUN_a014bd0c(0); FUN_a0087d5c(0); return;
    case 2: FUN_a014bd0c(0); FUN_a0087d5c(0); return;
    case 3: FUN_a014bd0c(0); FUN_a0087d5c(0); return;
    case 4: FUN_a014bd0c(0); FUN_a0087d5c(0); return;
    }
  }
  if (DAT_a802d290.b15b == 4 || (DAT_a802d290.w174 & 0x8000)) {
    FUN_a014bd0c(2);
    func_0x4008e2a4();
    FUN_a0087d5c(0);
    return;
  }
  FUN_a014bd0c(0);
  func_0x4008e2a4();
  FUN_a0087d5c(DAT_a802d290.b15b);
}
