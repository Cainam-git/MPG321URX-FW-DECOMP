/* leon2m FUN_a00e321c @ 0xa00e321c-0xa00e3524 (194 words), flags -mcpu=v8 -O3 -g.
 * Code facts: c = (param_2 == 0 && param_3 == 3) (cmp/subx pair, andcc into %l7); if c: three
 * FUN_a00e0774 field writes (0x1c1 mask 6 / 0xf0, 0x1dc mask 0xc0, value 1). Then a fixed sequence of
 * FUN_a00e05d8 (reg rmw: dev, reg, mask, val), FUN_a00e0740 (= FUN_a00e05d8(dev, reg, m, m)) and
 * FUN_a00dff94(1). Five FUN_a00e2d8c(dev, a, a, 0) runs (a = 0, 8, 1, 7, 6), each preceded by
 * writing four hook words 0xa802d660/668/664/65c = 0x82588/0x82714/0x82aec/0x82c3c; flag word
 * 0xa802b728 = 1 (only if c) before runs 0 and 1, = 0 after them. FUN_a00e02ec(dev, 0x1d0/0x1d1/0x1d0)
 * results go to regs 0x1cc/0x1c8/0x1c7 after 0x1c0 field 0xf0 = 0x90/0x50/0x40. Tail call
 * FUN_a00e0774(dev, 0x1c0, 0xf0, 4, 0).
 * Fixes vs the autoc draft (97.42): the four hook values are link-time SYMBOL addresses (fw has a
 * separate 'sethi %hi(0x82400)' for 0x82588 and 0x82714; plain constants share one HIGH); only three
 * real parameters (dev passed unextended); the tail call has 5 args (draft passed a 6th); dropped the
 * draft's 'bVar3 = param_1' artefact; real callee prototypes (void wrappers, 5-arg FUN_a00e0774).
 * HOOKS() is a do/while(0) macro for the four repeated stores. Aids: none.
 */
extern unsigned int _DAT_a802b728;
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

extern char DAT_00082588, DAT_00082714, DAT_00082aec, DAT_00082c3c;

#define HOOKS() do { \
  _DAT_a802d660 = (unsigned int)&DAT_00082588; \
  _DAT_a802d668 = (unsigned int)&DAT_00082714; \
  _DAT_a802d664 = (unsigned int)&DAT_00082aec; \
  _DAT_a802d65c = (unsigned int)&DAT_00082c3c; } while (0)

void FUN_a00e321c(unsigned int param_1, int param_2, unsigned int param_3)
{
  int v;
  int c = param_2 == 0 && param_3 == 3;

  if (c) {
    FUN_a00e0774(param_1, 0x1c1, 6, 1, 1);
    FUN_a00e0774(param_1, 0x1c1, 0xf0, 4, 1);
    FUN_a00e0774(param_1, 0x1dc, 0xc0, 6, 1);
  }
  FUN_a00e05d8(param_1, 0x1f0, 0x80, 0);
  FUN_a00e05d8(param_1, 0x1df, 8, 0);
  FUN_a00e0740(param_1, 0x1f0, 0x80);
  FUN_a00e0740(param_1, 0x1df, 8);
  FUN_a00e0740(param_1, 0x1c0, 8);
  FUN_a00e0740(param_1, 0x1c0, 2);
  FUN_a00e0740(param_1, 0x1c0, 4);
  FUN_a00dff94(1);
  FUN_a00e05d8(param_1, 0x1c0, 8, 0);
  FUN_a00e0740(param_1, 0x1df, 0x80);
  FUN_a00e0740(param_1, 0x1df, 0x40);
  if (c)
    _DAT_a802b728 = 1;
  HOOKS();
  FUN_a00e2d8c(param_1, 0, 0, 0);
  _DAT_a802b728 = 0;
  HOOKS();
  FUN_a00e2d8c(param_1, 8, 8, 0);
  v = FUN_a00e02ec(param_1, 0x1d0);
  FUN_a00e05d8(param_1, 0x1c0, 0xf0, 0x90);
  FUN_a00e05d8(param_1, 0x1cc, 0xff, v);
  if (c)
    _DAT_a802b728 = 1;
  HOOKS();
  FUN_a00e2d8c(param_1, 1, 1, 0);
  _DAT_a802b728 = 0;
  v = FUN_a00e02ec(param_1, 0x1d1);
  FUN_a00e05d8(param_1, 0x1c0, 0xf0, 0x50);
  FUN_a00e05d8(param_1, 0x1c8, 0xff, v);
  HOOKS();
  FUN_a00e2d8c(param_1, 7, 7, 0);
  HOOKS();
  FUN_a00e2d8c(param_1, 6, 6, 0);
  v = FUN_a00e02ec(param_1, 0x1d0);
  FUN_a00e05d8(param_1, 0x1c0, 0xf0, 0x40);
  FUN_a00e05d8(param_1, 0x1c7, 0xff, v);
  FUN_a00e0740(param_1, 0x1c0, 2);
  FUN_a00e0774(param_1, 0x1c0, 0xf0, 4, 0);
}
