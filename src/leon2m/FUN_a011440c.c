/* leon2m FUN_a011440c @ 0xa011440c (-mcpu=v8 -O3 -g)
 * Returns (word 0xCF015A00) & 0xff.
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
#define _DAT_cf015a00 (*(volatile unsigned int *)0xcf015a00)

uint FUN_a011440c(void)

{
  return _DAT_cf015a00 & 0xff;
}