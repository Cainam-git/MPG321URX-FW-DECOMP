/* leon2m FUN_a0140058 @ 0xa0140058 (-mcpu=v8 -O2 -g)
 * Returns bit 9 of the first halfword of the 0x2A-byte record (p & 0xff) at 0xA802E224.
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
extern byte ARR_a802e224[];

ushort FUN_a0140058(uint param_1)

{
  return *(ushort *)((param_1 & 0xff) * 0x2a + (int)ARR_a802e224) >> 9 & 1;
}