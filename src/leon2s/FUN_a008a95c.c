/* leon2s FUN_a008a95c @ 0xa008a95c (-mcpu=v8 -Os -g)
 * Code: (word 0xCF0110E4) = p1 & 0xff.
 * Source form: Ghidra's type and symbol names are kept.
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
#define _DAT_cf0110e4 (*(volatile unsigned int *)0xcf0110e4)

void FUN_a008a95c(uint param_1)

{
  _DAT_cf0110e4 = param_1 & 0xff;
  return;
}