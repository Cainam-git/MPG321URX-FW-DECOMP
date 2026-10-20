/* leon2m FUN_a013f204 @ 0xa013f204 (-mcpu=v8 -Os -g)
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
extern byte ARR_a802e224[];

ushort FUN_a013f204(uint param_1)

{
  return *(ushort *)((param_1 & 0xff) * 0x2a + (int)ARR_a802e224) >> 7 & 1;
}