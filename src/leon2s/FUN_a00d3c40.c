/* leon2s FUN_a00d3c40 @ 0xa00d3c40..0xa00d3eb0 (624 bytes, 156 words; FUN_a00d3ea8 = unreachable
 * ret/restore tail inside the range)
 * Flags: -mcpu=v8 -Os -g.
 * Runs only when the register 0xcf03c80c reads 0x99. FUN_a00d36a4(); if bit DAT_a8078c37 of DAT_a8078c36 is
 * set: FUN_a00d2d1c(), state DAT_a8078c38 = 0, writes (c37 << 16 | 0xff) to 0xd0013ffc via func_0xa0f71534,
 * return. Else: func_0xa0f724b4() == 1 -> FUN_a00d2d8c(), state 4. Otherwise DAT_a8078c24 =
 * (FUN_a00d2e00() == 1) (on 1 also FUN_a00d38a8(), then _DAT_a8078c20 = func_0xa0fc2064(), FUN_a00d2e9c());
 * with c24 == 1 and FUN_a00d2b88() == 1: _DAT_a807d54c > 1 -> FUN_a00d3364() != 0 ? (writes 0x55, state 2,
 * the calls with 0x9f1c6458 / 0x9f1cca78) : (func_0xa0f83044(0x9f1c6438, state), DAT_a8078c34 = 1); else
 * FUN_a00d2d1c(), FUN_a00d2c38(), state 1, writes 0xdd. With c24 != 1: DAT_a8078c30 bit 0 set ->
 * FUN_a00d31f8() if bit 1 too; else FUN_a00d3670() != 0 -> FUN_a00d2d1c(), FUN_a00d2c38(), state 0, writes
 * 0xff. Common tail: DAT_a8078c33 == 1 -> FUN_a00d378c(); FUN_a00d2920(); func_0xa0f71adc() (tail call).
 * Callers: no direct 'call 0xa00d3c40' in asm/leon2s (reached via a pointer/table).
 * The '== 1' test after func_0xa0f724b4 is on its return value (firmware and %o0, 0xff after the call).
 * void function without parameters (the firmware never reads %i0..%i5; both returns are tail calls /
 * plain restore).
 * Source form: the prototypes of the calls outside the image (0xa0f7xxxx/0xa0f8xxxx/0xa0fcxxxx) are the
 * ones that give the firmware bytes; func_0xa0f83044 returns int (void moves its argument set-up). Two
 * result variables (u for FUN_a00d2e00, r for FUN_a00d2b88) as in the firmware registers (one shared
 * variable gives different code).
 */
extern unsigned char DAT_a8078c37;
extern unsigned char DAT_a8078c38;
extern unsigned char DAT_a8078c24;
extern unsigned char DAT_a8078c33;
extern unsigned char DAT_a8078c34;
extern unsigned char DAT_a8078c36;
extern unsigned char DAT_a8078c30;
extern unsigned int _DAT_a8078c20;
extern unsigned int _DAT_a807d54c;
extern void FUN_a00d36a4(void);
extern void FUN_a00d2e9c(void);
extern void FUN_a00d2d1c(void);
extern void FUN_a00d2d8c(void);
extern int FUN_a00d2e00(void);
extern void FUN_a00d38a8(void);
extern int FUN_a00d2b88(void);
extern int FUN_a00d3364(void);
extern void FUN_a00d2c38(void);
extern void FUN_a00d31f8(void);
extern int FUN_a00d3670(void);
extern void FUN_a00d378c(void);
extern void FUN_a00d2920(void);
extern void func_0xa0f71534(unsigned int, unsigned int);
extern int func_0xa0f724b4(void);
extern int func_0xa0f83044(unsigned int, unsigned int);
extern void func_0xa0f71280(unsigned int);
extern unsigned int func_0xa0fc2064(void);
extern void func_0xa0f71adc(void);

void FUN_a00d3c40(void)
{
  int u, r;

  if (*(volatile unsigned int *)0xcf03c80c != 0x99)
    return;
  FUN_a00d36a4();
  if ((DAT_a8078c36 >> DAT_a8078c37) & 1) {
    FUN_a00d2d1c();
    DAT_a8078c38 = 0;
    func_0xa0f71534(0xd0013ffc, (DAT_a8078c37 << 16) | 0xff);
    return;
  }
  if ((func_0xa0f724b4() & 0xff) == 1) {
    FUN_a00d2d8c();
    DAT_a8078c38 = 4;
    goto out;
  }
  u = FUN_a00d2e00() & 0xff;
  if (u == 1) {
    DAT_a8078c24 = u;
    FUN_a00d38a8();
    _DAT_a8078c20 = func_0xa0fc2064();
    FUN_a00d2e9c();
  } else {
    DAT_a8078c24 = 0;
  }
  if (DAT_a8078c24 == 1) {
    r = FUN_a00d2b88() & 0xff;
    if (r != 1)
      goto out;
    if (_DAT_a807d54c > 1) {
      if ((FUN_a00d3364() & 0xff) != 0) {
        func_0xa0f71534(0xd0013ffc, (DAT_a8078c37 << 16) | 0x55);
        DAT_a8078c38 = 2;
        func_0xa0f83044(0x9f1c6458, 2);
        func_0xa0f71280(0x9f1cca78);
      } else {
        func_0xa0f83044(0x9f1c6438, DAT_a8078c38);
        DAT_a8078c34 = r;
      }
      goto out;
    }
    FUN_a00d2d1c();
    FUN_a00d2c38();
    DAT_a8078c38 = r;
    func_0xa0f83044(0x9f1c6480, 1);
    func_0xa0f71534(0xd0013ffc, (DAT_a8078c37 << 16) | 0xdd);
  } else {
    if (DAT_a8078c30 & 1) {
      if (DAT_a8078c30 & 2)
        FUN_a00d31f8();
      goto out;
    }
    if ((FUN_a00d3670() & 0xff) != 0) {
      FUN_a00d2d1c();
      FUN_a00d2c38();
      DAT_a8078c38 = 0;
      func_0xa0f71534(0xd0013ffc, (DAT_a8078c37 << 16) | 0xff);
    }
  }
out:
  if (DAT_a8078c33 == 1)
    FUN_a00d378c();
  FUN_a00d2920();
  func_0xa0f71adc();
}
