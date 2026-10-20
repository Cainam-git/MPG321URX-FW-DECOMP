/* leon2s FUN_a008fff0 @ 0xa008fff0 (-mcpu=v8 -Os -g)
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
extern unsigned char DAT_a8078c08;

undefined1 FUN_a008fff0(unsigned char param_1)

{
  int uVar1;
  
  uVar1 = 0;
  if (param_1 == '\x01') {
    uVar1 = DAT_a8078c08;
  }
  return uVar1;
}