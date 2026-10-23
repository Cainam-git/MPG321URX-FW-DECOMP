/* leon2m FUN_a008a434 @ 0xa008a434 (-mcpu=v8 -Os -g)
 * Calls FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0), FUN_a014613c(p1, p2 & 0xff, 0), FUN_a0146518(1, 0x62, 0),
 * FUN_a0146ab0(p3 & 0xffff, 0), func_0x4008e2a4() three times and FUN_a0146108(0, p2, p3, p4, p5, p6).
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
extern void FUN_a0146108();
extern void FUN_a014613c();
extern void FUN_a0146518();
extern void FUN_a0146ab0(undefined2 param_1,undefined1 param_2);
extern void FUN_a0146c40();
extern void FUN_a0146dc0();
extern void func_0x4008e2a4();

void FUN_a008a434(undefined1 param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6)

{
  FUN_a0146dc0(0,0);
  FUN_a0146c40(8,0,0);
  FUN_a014613c(param_1,param_2 & 0xff,0);
  FUN_a0146518(1,0x62,0);
  FUN_a0146ab0(param_3 & 0xffff,0);
  func_0x4008e2a4();
  func_0x4008e2a4();
  func_0x4008e2a4();
  FUN_a0146108(0,param_2,param_3,param_4,param_5,param_6);
  return;
}