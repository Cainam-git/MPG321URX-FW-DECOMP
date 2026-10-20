/* leon2s FUN_a0072900 @ 0xa0072900  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a006faa8();
extern int FUN_a006fd04();
extern int FUN_a0070b7c();
extern int FUN_a00b15ac();

int FUN_a0072900(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 auStack_28 [32];
  
  FUN_a00b15ac(auStack_28,0,0x20);
  FUN_a006faa8(8,0,auStack_28,8);
  puVar1 = FUN_a006fd04(auStack_28,8);
  if (((uint)puVar1 & 0xff) != 0) {
    FUN_a0070b7c(auStack_28);
  }
  return CONCAT44(param_2,param_1);
}