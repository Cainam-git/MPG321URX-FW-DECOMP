/* leon2m FUN_a008a174 @ 0xa008a174  forwarder (MATCH -mcpu=v8 -Os -g, gcc 3.4.4, autoc).
 * Tail-calls FUN_a0088724 (sibling call: mov %o7,%g1 / call / mov %g1,%o7). Last step of the main-loop task
 * FUN_a0087430.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a0088724();

void FUN_a008a174(void)

{
  FUN_a0088724();
  return;
}