/* leon2s FUN_a00ae378 @ 0xa00ae378  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00a6bb8();
extern int FUN_a00a6c00();

void FUN_a00ae378(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00a6bb8(param_1,0x40);
  FUN_a00a6c00(param_1,0x40,(uVar1 | 0xffffff80) & 0xff,param_4,param_5,param_6);
  return;
}