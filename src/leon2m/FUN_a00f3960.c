/* leon2m FUN_a00f3960 @ 0xa00f3960 (-mcpu=v8 -O3 -g)
 * Returns (word 0xCF020008) & 0xff.
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
#define _DAT_cf020008 (*(volatile unsigned int *)0xcf020008)

uint FUN_a00f3960(void)

{
  return _DAT_cf020008 & 0xff;
}