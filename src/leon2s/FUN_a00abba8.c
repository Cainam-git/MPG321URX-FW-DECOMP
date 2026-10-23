/* leon2s FUN_a00abba8 @ 0xa00abba8 (-mcpu=v8 -Os -g)
 * Code: (word 0xCF01143C) = (word 0xCF01143C) | 7.
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
#define _DAT_cf01143c (*(volatile unsigned int *)0xcf01143c)

void FUN_a00abba8(void)

{
  _DAT_cf01143c = _DAT_cf01143c | 7;
  return;
}