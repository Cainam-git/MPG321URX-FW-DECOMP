/* leon2m FUN_a00e3524 @ 0xa00e3524-0xa00e3880 (215 words).
 * Same code as FUN_a00e3880, whose comment describes it, with other constants (template -> this function):
 * 0x10 -> 0x1, 0x20 -> 0x2, 0x215 -> 0x1e1, 0x216 -> 0x1e2, 0x21a -> 0x1e6, 0x21b -> 0x1e7, 0x223 -> 0x1ec, 0x224
 * -> 0x1ed, 0x228 -> 0x203, 0x229 -> 0x204, 0x231 -> 0x209, 0x232 -> 0x20a, 0x237 -> 0x1f3, 0x23a -> 0x1f1,
 * 0x82690 -> 0x8260c, 0x829a4 -> 0x8285c, 0x82bcc -> 0x82b5c, 0x82d1c -> 0x82cac
 */
extern unsigned int _DAT_a802d65c;
extern unsigned int _DAT_a802d660;
extern unsigned int _DAT_a802d664;
extern unsigned int _DAT_a802d668;
extern void FUN_a00dff94(int);
extern int FUN_a00e02ec(unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0740(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e2d8c(unsigned int, unsigned int, unsigned int, unsigned int);

extern char DAT_00082b5c, DAT_00082cac, DAT_0008260c, DAT_0008285c;

#define HOOKS() do { \
  _DAT_a802d660 = (unsigned int)&DAT_0008260c; \
  _DAT_a802d668 = (unsigned int)&DAT_0008285c; \
  _DAT_a802d664 = (unsigned int)&DAT_00082b5c; \
  _DAT_a802d65c = (unsigned int)&DAT_00082cac; } while (0)

void FUN_a00e3524(unsigned int param_1, int param_2, unsigned int param_3)
{
  int v;

  if (param_2 == 0 && param_3 == 3) {
    FUN_a00e0774(param_1, 0x1e2, 6, 1, 1);
    FUN_a00e0774(param_1, 0x1e2, 0xf0, 4, 1);
    FUN_a00e0774(param_1, 0x1f3, 0xc0, 6, 1);
  }
  FUN_a00e05d8(param_1, 0x1f0, 0x80, 0);
  FUN_a00e05d8(param_1, 0x1df, 8, 0);
  FUN_a00e0740(param_1, 0x1f0, 0x80);
  FUN_a00e0740(param_1, 0x1df, 8);
  FUN_a00e0740(param_1, 0x1e1, 8);
  FUN_a00e0740(param_1, 0x1e1, 2);
  FUN_a00e0740(param_1, 0x1e1, 4);
  FUN_a00dff94(1);
  FUN_a00e05d8(param_1, 0x1e1, 8, 0);
  FUN_a00e0740(param_1, 0x1f1, 0x2);
  FUN_a00e0740(param_1, 0x1f1, 0x1);
  HOOKS();
  FUN_a00e2d8c(param_1, 4, 4, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 5, 5, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 7, 7, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 6, 6, 0);
  v = FUN_a00e02ec(param_1, 0x209);
  FUN_a00e05d8(param_1, 0x1e1, 0xf0, 0x20);
  FUN_a00e05d8(param_1, 0x1e6, 0xff, v);
  v = FUN_a00e02ec(param_1, 0x20a);
  FUN_a00e05d8(param_1, 0x1e1, 0xf0, 0x30);
  FUN_a00e05d8(param_1, 0x1e7, 0xff, v);
  FUN_a00e05d8(param_1, 0x1f1, 0x40, 0x40);
  HOOKS();
  FUN_a00e2d8c(param_1, 1, 1, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 0, 0, 0);
  FUN_a00e05d8(param_1, 0x1f1, 0x40, 0);
  v = FUN_a00e02ec(param_1, 0x203);
  FUN_a00e05d8(param_1, 0x1e1, 0xf0, 0x80);
  FUN_a00e05d8(param_1, 0x1ec, 0xff, v);
  v = FUN_a00e02ec(param_1, 0x204);
  FUN_a00e05d8(param_1, 0x1e1, 0xf0, 0x90);
  FUN_a00e05d8(param_1, 0x1ed, 0xff, v);
  FUN_a00e0740(param_1, 0x1e1, 2);
  FUN_a00e0774(param_1, 0x1e1, 0xf0, 4, 0);
}
