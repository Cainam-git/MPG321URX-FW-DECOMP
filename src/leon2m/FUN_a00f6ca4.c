/* leon2m FUN_a00f6ca4 @ 0xa00f6ca4  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
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
#define _DAT_cf00e984 (*(volatile unsigned int *)0xcf00e984)

void FUN_a00f6ca4(void)

{
  _DAT_cf00e984 = _DAT_cf00e984 & 0xffffff7f;
  return;
}