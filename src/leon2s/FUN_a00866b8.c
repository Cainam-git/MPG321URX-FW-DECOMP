/* leon2s FUN_a00866b8 @ 0xa00866b8  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern byte ARR_a807cd2e[];

void FUN_a00866b8(uint param_1)

{
  unsigned short iVar1;
  
  iVar1 = (param_1 & 0xff) * 6;
  ARR_a807cd2e[iVar1] = ARR_a807cd2e[iVar1] & 0x7f;
  return;
}