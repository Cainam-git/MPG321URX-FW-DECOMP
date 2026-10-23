/* leon2s FUN_a0063924 @ 0xa0063924 (-mcpu=v8 -Os -g)
 * Calls FUN_a006370c() when byte 0xA8078A39 == 0.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a8078a39;
extern int FUN_a006370c();

void FUN_a0063924(void)

{
  if (DAT_a8078a39 == '\0') {
    FUN_a006370c();
    return;
  }
  return;
}