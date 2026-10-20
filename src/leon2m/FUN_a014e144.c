/* leon2m FUN_a014e144 @ 0xa014e144 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern int FUN_a010ae54();
extern int FUN_a010ae70();
extern int func_0x4008d1a0();

void FUN_a014e144(unsigned char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  if (param_1 != '\0') {
    FUN_a010ae54(0x14,param_2,param_3,param_4,param_5,param_6);
    return;
  }
  FUN_a010ae70();
  func_0x4008d1a0(0x14,param_2,param_3,param_4,param_5,param_6);
  return;
}