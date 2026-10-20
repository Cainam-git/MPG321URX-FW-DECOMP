/* leon2m FUN_a00c1608 @ 0xa00c1608  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
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
extern unsigned char DAT_a802d41d;
extern int FUN_a00b88cc();
extern int FUN_a00ba950();
extern int FUN_a00baa6c();
extern int FUN_a00bab80();
extern int FUN_a00bae38();

int FUN_a00c1608(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_1 = param_1 & 0xff;
  uVar2 = FUN_a00bae38(param_1);
  uVar1 = 0xff;
  if ((uVar2 & 0xff) < 0xc) {
    DAT_a802d41d = (undefined1)uVar2;
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1,6);
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}