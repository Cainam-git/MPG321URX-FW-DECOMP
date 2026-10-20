/* leon2s FUN_a00d27fc @ 0xa00d27fc-0xa00d2920 (73 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: word local at %fp-12 = 0; FUN_a00d264c(); reg 0xcf011f00 |= 1; FUN_a00d25f4(byte
 * 0xa8078c37); arg byte == 0 -> func_0xa0fc15d8(0xa80779e0, 0x9f1b07d0, 0x24) (3 args: o0/o1/o2);
 * FUN_a00d24ac(); FUN_a00d2678(1); func_0xa0f72434(); FUN_a00d2210/2288/23bc/2300/2434(0, 0) in this
 * order; two read-modify-write runs local = func_0xa0f71528(reg); func_0xa0f714b8(&local, 0xb, 0,
 * 0x3ff) / (&local, 3, 0, 0xf); func_0xa0f71534(reg, local) for regs 0xd0013fa0 / 0xd0013fac;
 * func_0xa0f83044(0x9f1c6240); func_0xa0f71280(0x9f1cca78). void.
 * Fixes vs the autoc draft (97.26): BEHAVIOUR, the copy call has 3 args (draft lost the 0xa80779e0
 * destination) and the first two (0, 0) calls are d2210 then d2288 (draft swapped them); the 2nd
 * register read is a full word (draft truncated it through a uchar); the five (0, 0) callees take
 * two u8 and return int (their asm: btst 0xff on %i0, restore %g0, 1) - with (int, int) gcc sets
 * %o0 before %o1. Aids: none.
 */
extern unsigned char DAT_a8078c37;
extern unsigned char DAT_a80779e0[];
extern int FUN_a00d2210(unsigned char, unsigned char);
extern int FUN_a00d2288(unsigned char, unsigned char);
extern int FUN_a00d2300(unsigned char, unsigned char);
extern int FUN_a00d23bc(unsigned char, unsigned char);
extern int FUN_a00d2434(unsigned char, unsigned char);
extern void FUN_a00d24ac(void);
extern void FUN_a00d25f4(unsigned char);
extern void FUN_a00d264c(void);
extern void FUN_a00d2678(int);
extern void func_0xa0f71280(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, int);
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);
extern void func_0xa0f72434(void);
extern void func_0xa0f83044(unsigned int);
extern void func_0xa0fc15d8(void *, unsigned int, unsigned int);

void FUN_a00d27fc(unsigned char param_1)
{
  unsigned int local_c;

  local_c = 0;
  FUN_a00d264c();
  *((volatile unsigned int *) 0xcf011f00) = (*((volatile unsigned int *) 0xcf011f00)) | 1;
  FUN_a00d25f4(DAT_a8078c37);
  if (param_1 == 0)
    func_0xa0fc15d8(DAT_a80779e0, 0x9f1b07d0, 0x24);
  FUN_a00d24ac();
  FUN_a00d2678(1);
  func_0xa0f72434();
  FUN_a00d2210(0, 0);
  FUN_a00d2288(0, 0);
  FUN_a00d23bc(0, 0);
  FUN_a00d2300(0, 0);
  FUN_a00d2434(0, 0);
  local_c = func_0xa0f71528(0xd0013fa0);
  func_0xa0f714b8(&local_c, 0xb, 0, 0x3ff);
  func_0xa0f71534(0xd0013fa0, local_c);
  local_c = func_0xa0f71528(0xd0013fac);
  func_0xa0f714b8(&local_c, 3, 0, 0xf);
  func_0xa0f71534(0xd0013fac, local_c);
  func_0xa0f83044(0x9f1c6240);
  func_0xa0f71280(0x9f1cca78);
}
