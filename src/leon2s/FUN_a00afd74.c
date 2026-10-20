/* leon2s FUN_a00afd74 @ 0xa00afd74  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern unsigned char DAT_a807dd2a;
extern int FUN_a00abff0();
extern int FUN_a00ac66c();
extern int FUN_a00af98c();

void FUN_a00afd74(unsigned char param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  if (param_1 != '\0') {
    return (ulonglong)param_2 << 0x20;
  }
  DAT_a807dd2a = (undefined1)param_2;
  FUN_a00abff0(0);
  FUN_a00ac66c(0);
  uVar1 = 0;
  return FUN_a00af98c(0,param_2,param_3,param_4,param_5,param_6);
}