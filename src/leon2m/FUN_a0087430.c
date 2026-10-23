/* leon2m FUN_a0087430 @ 0xa0087430  one of the four main-loop tasks (MATCH -mcpu=v8 -Os -g, gcc 3.4.4, autoc).
 * Code: FUN_a008a210(); FUN_a009f42c(); FUN_a0085984(); FUN_a008a174(p1, p2, p3, p4, p5, p6).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a0085984();
extern int FUN_a008a174();
extern int FUN_a008a210();
extern int FUN_a009f42c();

void FUN_a0087430(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a008a210();
  FUN_a009f42c();
  FUN_a0085984();
  FUN_a008a174(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}