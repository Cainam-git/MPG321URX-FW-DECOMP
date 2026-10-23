/* leon2s FUN_a00b1470 @ 0xa00b1470 (-mcpu=v8 -Os -g)
 * Code: (word 0xCF03C894) = (word 0xCF03C894) | 1 << p1.
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
#define _DAT_cf03c894 (*(volatile unsigned int *)0xcf03c894)

void FUN_a00b1470(byte param_1)

{
  _DAT_cf03c894 = _DAT_cf03c894 | 1 << param_1;
  return;
}