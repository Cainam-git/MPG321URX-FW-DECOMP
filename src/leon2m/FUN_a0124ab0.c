/* leon2m FUN_a0124ab0 @ 0xa0124ab0 (-mcpu=v8 -O2 -g)
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
extern unsigned char DAT_a802c9f8;
extern undefined1 FUN_a012792c();
extern int func_0x4008c86c();

void FUN_a0124ab0(void)

{
  byte bVar2;
  undefined4 uVar1;
  undefined4 uVar3;
  
  if ((DAT_a802c9f8 != '\x01') && (bVar2 = FUN_a012792c(), bVar2 == 0)) {
    return 0x8000000004;
  }
  uVar1 = 4;
  uVar3 = 0x80;
  return func_0x4008c86c(4,0x80,0xfe);
}