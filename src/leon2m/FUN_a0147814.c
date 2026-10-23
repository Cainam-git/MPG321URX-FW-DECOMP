/* leon2m FUN_a0147814 @ 0xa0147814 (-mcpu=v8 -O2 -g)
 * Returns the byte result of FUN_a00fca34(), zero-extended.
 * Source form: Ghidra's type and symbol names are kept.
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
extern undefined1 FUN_a00fca34(void);

int FUN_a0147814(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = FUN_a00fca34();
  return CONCAT44(param_2,(uint)bVar1);
}