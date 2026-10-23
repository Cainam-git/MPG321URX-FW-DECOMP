/* leon2m FUN_a0106ba8 @ 0xa0106ba8 (-mcpu=v8 -O2 -g)
 * k = p1 & 0xff. For k <= 3 calls func_0x4008e3c4(k, 1), FUN_a0118a28(k, 1) and FUN_a00f2298(k, 0x54, 2) and
 * returns FUN_a0106920(k, 0, p3, p4, p5, p6); for k > 3 returns k without a call.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern void FUN_a00f2298();
extern int FUN_a0106920();
extern void FUN_a0118a28();
extern int func_0x4008e3c4();

int FUN_a0106ba8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff;
  if (3 < param_1) {
    return (ulonglong)param_1;
  }
  func_0x4008e3c4(param_1,1);
  FUN_a0118a28(param_1,1);
  FUN_a00f2298(param_1,0x54,2);
  uVar1 = 0;
  return FUN_a0106920(param_1,0,param_3,param_4,param_5,param_6);
}