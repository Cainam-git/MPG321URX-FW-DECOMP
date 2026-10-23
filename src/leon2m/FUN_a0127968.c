/* leon2m FUN_a0127968 @ 0xa0127968 (-mcpu=v8 -O2)
 * Returns the byte at 0xA802D8A2. A leaf routine without a register window.
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
extern unsigned char DAT_a802d8a2;

undefined1 FUN_a0127968(void)

{
  return DAT_a802d8a2;
}