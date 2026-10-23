/* leon2m FUN_a0101b48 @ 0xa0101b48 (-mcpu=v8 -O2 -g)
 * Code: (word 0xCF016110) = p1 & 0xff.
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
#define _DAT_cf016110 (*(volatile unsigned int *)0xcf016110)

void FUN_a0101b48(uint param_1)

{
  _DAT_cf016110 = param_1 & 0xff;
  return;
}