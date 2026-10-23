/* leon2m FUN_a002a45c @ 0xa002a45c (-mcpu=v8 -Os -g)
 * Calls FUN_a002c268(0x9f000090, 0, 0x800), FUN_a002c268(0x9f020028, 0x800, 0x800), FUN_a002c25c(0x9f020034,
 * 0x800), FUN_a002c25c(0x9f00009c, 0x800), FUN_a002c268(0x9f020028, 0, 0x800) and FUN_a002c268(0x9f000090, 0x800,
 * 0x800).
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
extern void FUN_a002c25c();
extern void FUN_a002c268();

void FUN_a002a45c(void)

{
  
  FUN_a002c268(0x9f000090,0,0x800);
  FUN_a002c268(0x9f020028,0x800,0x800);
  FUN_a002c25c(0x9f020034,0x800);
  FUN_a002c25c(0x9f00009c,0x800);
  FUN_a002c268(0x9f020028,0,0x800);
  FUN_a002c268(0x9f000090,0x800,0x800);
  return;
}