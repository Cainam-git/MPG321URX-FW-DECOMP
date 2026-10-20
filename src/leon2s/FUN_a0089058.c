/* leon2s FUN_a0089058 @ 0xa0089058  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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


uint FUN_a0089058(byte param_1,byte param_2)

{
  unsigned char uVar1;
  
  uVar1 = 0;
  for (; param_1 <= param_2; param_1 = param_1 + 1) {
    uVar1 = 1 << param_1 | uVar1;
  }
  return uVar1 & 0xff;
}