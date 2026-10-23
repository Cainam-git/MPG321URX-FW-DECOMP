/* leon2m FUN_a002d588 @ 0xa002d588 (-mcpu=v8 -O2)
 * Returns the halfword at 0xA802B0CA. A leaf routine without a register window.
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
extern unsigned short _DAT_a802b0ca;

undefined2 FUN_a002d588(void)

{
  return _DAT_a802b0ca;
}