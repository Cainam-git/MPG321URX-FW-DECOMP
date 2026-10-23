/* leon2m FUN_a0101abc @ 0xa0101abc (-mcpu=v8 -O2 -g)
 * Code: (word 0xCF01610C) = (word 0xCF01610C) & 1 | (p1 & 0xff) << 3 | (p2 & 0xff) * 2.
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
#define _DAT_cf01610c (*(volatile unsigned int *)0xcf01610c)

void FUN_a0101abc(uint param_1,uint param_2)

{
  _DAT_cf01610c = _DAT_cf01610c & 1 | (param_1 & 0xff) << 3 | (param_2 & 0xff) * 2;
  return;
}