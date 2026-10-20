/* leon2m FUN_a00f2e74 @ 0xa00f2e74 (-mcpu=v8 -O2 -g)
 * Delay loop: a byte counter runs 0..0x1F with one nop per iteration. The byte counter produces the `and %o5,
 * 0xff` mask; the nop is an explicit __asm__ statement.
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

void FUN_a00f2e74(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 0x20; bVar1++) __asm__("nop");
  return;
}
