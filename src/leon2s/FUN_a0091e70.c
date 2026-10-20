/* leon2s FUN_a0091e70 @ 0xa0091e70 (-mcpu=v8 -Os -g)
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
extern int FUN_a00a8054();
extern int FUN_a00a80cc();

int FUN_a0091e70(uint param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 < 2) {
    FUN_a00a80cc(param_1,0,0x11d,5,0);
    uVar1 = 0;
    return FUN_a00a8054(param_1,0,0x114,9);
  }
  return (ulonglong)param_1;
}