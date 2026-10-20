/* leon2s FUN_a007a708 @ 0xa007a708 (-mcpu=v8 -Os -g)
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
extern void FUN_a00a7424();
extern void FUN_a00a7488();

void FUN_a007a708(undefined1 param_1)

{
  
  FUN_a00a7424(0,7,param_1,0x1178);
  FUN_a00a7424(0,7,param_1,0x1578);
  FUN_a00a7424(0,7,param_1,0x1978);
  FUN_a00a7488(param_1,0x117c,0xffffff,0x18000000);
  FUN_a00a7488(param_1,0x157c,0xffffff,0x18000000);
  FUN_a00a7488(param_1,0x197c,0xffffff,0x18000000);
  return;
}