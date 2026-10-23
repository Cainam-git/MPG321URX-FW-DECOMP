/* leon2m FUN_a0101b20 @ 0xa0101b20 (-mcpu=v8 -O2 -g)
 * Code: (word 0xCF016118) = (word 0xCF016118) & 0xbf | (p1 & 0xff) << 6.
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
#define _DAT_cf016118 (*(volatile unsigned int *)0xcf016118)

void FUN_a0101b20(uint param_1)

{
  _DAT_cf016118 = _DAT_cf016118 & 0xbf | (param_1 & 0xff) << 6;
  return;
}