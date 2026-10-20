/* leon2m FUN_a00d4970 @ 0xa00d4970  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a802d2a0;
extern int FUN_a0147a14();

void FUN_a00d4970(void)

{
  byte bVar1;
  
  bVar1 = DAT_a802d2a0;
  if (100 < DAT_a802d2a0) {
    bVar1 = 100;
  }
  FUN_a0147a14(bVar1);
  return;
}