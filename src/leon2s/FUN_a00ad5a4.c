/* leon2s FUN_a00ad5a4 @ 0xa00ad5a4 (-mcpu=v8 -Os -g)
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
extern unsigned char DAT_a8079312;

uint FUN_a00ad5a4(byte param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 < 2) {
    uVar1 = (int)(uint)DAT_a8079312 >> param_1 & 1;
  }
  return uVar1;
}