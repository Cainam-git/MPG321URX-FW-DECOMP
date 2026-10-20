/* leon2s FUN_a00a832c @ 0xa00a832c (-mcpu=v8 -Os -g)
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
extern unsigned char DAT_a00b4d30;

void FUN_a00a832c(uint param_1, unsigned short param_2,uint param_3)

{
  if ((param_1 & 0xff) < 9) {
    *(uint *)(((uint)*(ushort *)(&DAT_a00b4d30 + (param_1 & 0xff) * 2) + (param_2 & 0xffff)) * 4 |
             0xcf000000) = param_3 & 0xff;
  }
  return;
}