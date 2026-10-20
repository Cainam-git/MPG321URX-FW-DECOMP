/* leon2s FUN_a007abbc @ 0xa007abbc (-mcpu=v8 -Os -g)
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

void FUN_a007abbc(undefined1 param_1)

{
  
  FUN_a00a7424(0,7,param_1,0x2178);
  FUN_a00a7424(0,7,param_1,0x2578);
  FUN_a00a7424(0,7,param_1,0x2978);
  FUN_a00a7424(0,7,param_1,0x3178);
  FUN_a00a7488(param_1,0x217c,0xffffff,0x18000000);
  FUN_a00a7488(param_1,0x257c,0xffffff,0x18000000);
  FUN_a00a7488(param_1,0x297c,0xffffff,0x18000000);
  FUN_a00a7488(param_1,0x317c,0xffffff,0x18000000);
  return;
}