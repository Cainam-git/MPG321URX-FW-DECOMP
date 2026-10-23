/* leon2m FUN_a00dd614 @ 0xa00dd614 (-mcpu=v8 -O2 -g)
 * Returns (word 0xA802B0B0) & p1 & 0xff.
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
extern unsigned int _DAT_a802b0b0;

uint FUN_a00dd614(uint param_1)

{
  return _DAT_a802b0b0 & param_1 & 0xff;
}