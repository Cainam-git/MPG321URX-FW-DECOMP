/* leon2m FUN_a00ee188 @ 0xa00ee188  MATCH (-mcpu=v8 -O2, gcc 3.4.4, autoc)
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
extern int FUN_a00df170();
extern int FUN_a00df80c();
extern int FUN_a00e0bc0();

int FUN_a00ee188(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((0x535 < param_1) && (uVar1 = 1, 0x74a < param_1)) && (uVar1 = 2, 0x960 < param_1)) &&
     (uVar1 = 3, 0xa6b < param_1)) {
    uVar1 = 0xffffffff;
    FUN_a00df80c();
    FUN_a00e0bc0();
    FUN_a00df170(0x199ef0,param_1);
  }
  return CONCAT44(param_2,uVar1);
}