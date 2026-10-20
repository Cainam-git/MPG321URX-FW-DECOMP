/* leon2m FUN_a00e3880 @ 0xa00e3880-0xa00e3bdc (215 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches. Twin of FUN_a00e321c. Code facts: c = (param_2 == 0 && param_3 == 3) (cmp/subx pair);
 * if c: three FUN_a00e0774 field writes (0x216 mask 6 / 0xf0, 0x237 mask 0xc0, value 1). Then a
 * fixed FUN_a00e05d8 / FUN_a00e0740 sequence and FUN_a00dff94(1). Six FUN_a00e2d8c(dev, a, a, 0)
 * runs (a = 4, 5, 7, 6, then 1, 0), each preceded by four hook words 0xa802d664/65c/660/668 =
 * 0x82bcc/0x82d1c/0x82690/0x829a4. FUN_a00e02ec(dev, 0x231/0x232/0x228/0x229) results go to regs
 * 0x21a/0x21b/0x223/0x224 after reg 0x215 field 0xf0 = 0x20/0x30/0x80/0x90. Tail call
 * FUN_a00e0774(dev, 0x215, 0xf0, 4, 0).
 * Fixes vs the autoc draft (89.91): hook values are link-time SYMBOL addresses (fw has a separate
 * sethi %hi(0x82800) for 0x82bcc and 0x829a4); _DAT_a802d668 is a word (st, not sth);
 * FUN_a00dff94 takes 1 arg (1); FUN_a00e0774 takes 5 args (the draft passed a 6th); void callees;
 * HOOKS() source order 660/668/664/65c gives the fw store order 664/65c/660/668 (same as e321c).
 * HOOKS() is a do/while(0) macro for the four repeated stores. Aids: none.
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

extern char DAT_00082bcc, DAT_00082d1c, DAT_00082690, DAT_000829a4;

#define HOOKS() do { \
  _DAT_a802d660 = (unsigned int)&DAT_00082690; \
  _DAT_a802d668 = (unsigned int)&DAT_000829a4; \
  _DAT_a802d664 = (unsigned int)&DAT_00082bcc; \
  _DAT_a802d65c = (unsigned int)&DAT_00082d1c; } while (0)

void FUN_a00e3880(unsigned int param_1, int param_2, unsigned int param_3)
{
  int v;

  if (param_2 == 0 && param_3 == 3) {
    FUN_a00e0774(param_1, 0x216, 6, 1, 1);
    FUN_a00e0774(param_1, 0x216, 0xf0, 4, 1);
    FUN_a00e0774(param_1, 0x237, 0xc0, 6, 1);
  }
  FUN_a00e05d8(param_1, 0x1f0, 0x80, 0);
  FUN_a00e05d8(param_1, 0x1df, 8, 0);
  FUN_a00e0740(param_1, 0x1f0, 0x80);
  FUN_a00e0740(param_1, 0x1df, 8);
  FUN_a00e0740(param_1, 0x215, 8);
  FUN_a00e0740(param_1, 0x215, 2);
  FUN_a00e0740(param_1, 0x215, 4);
  FUN_a00dff94(1);
  FUN_a00e05d8(param_1, 0x215, 8, 0);
  FUN_a00e0740(param_1, 0x23a, 0x20);
  FUN_a00e0740(param_1, 0x23a, 0x10);
  HOOKS();
  FUN_a00e2d8c(param_1, 4, 4, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 5, 5, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 7, 7, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 6, 6, 0);
  v = FUN_a00e02ec(param_1, 0x231);
  FUN_a00e05d8(param_1, 0x215, 0xf0, 0x20);
  FUN_a00e05d8(param_1, 0x21a, 0xff, v);
  v = FUN_a00e02ec(param_1, 0x232);
  FUN_a00e05d8(param_1, 0x215, 0xf0, 0x30);
  FUN_a00e05d8(param_1, 0x21b, 0xff, v);
  FUN_a00e05d8(param_1, 0x1f1, 0x40, 0x40);
  HOOKS();
  FUN_a00e2d8c(param_1, 1, 1, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 0, 0, 0);
  FUN_a00e05d8(param_1, 0x1f1, 0x40, 0);
  v = FUN_a00e02ec(param_1, 0x228);
  FUN_a00e05d8(param_1, 0x215, 0xf0, 0x80);
  FUN_a00e05d8(param_1, 0x223, 0xff, v);
  v = FUN_a00e02ec(param_1, 0x229);
  FUN_a00e05d8(param_1, 0x215, 0xf0, 0x90);
  FUN_a00e05d8(param_1, 0x224, 0xff, v);
  FUN_a00e0740(param_1, 0x215, 2);
  FUN_a00e0774(param_1, 0x215, 0xf0, 4, 0);
}
