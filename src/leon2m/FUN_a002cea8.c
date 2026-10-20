/* leon2m FUN_a002cea8 @ 0xa002cea8 (-mcpu=v8 -O2 -g)
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
extern int FUN_a002c250();
extern int func_0x0007f170();

void FUN_a002cea8(void)

{
  undefined4 uVar1;
  int uVar2;
  
  uVar1 = FUN_a002c250(0x9f020328);
  uVar2 = FUN_a002c250(0x9f020324);
  func_0x0007f170(0x198e40,uVar1,uVar2);
  return;
}