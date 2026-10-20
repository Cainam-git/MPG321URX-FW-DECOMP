/* leon2s FUN_a00ad09c @ 0xa00ad09c (-mcpu=v8 -Os -g)
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
extern int FUN_a00a6bb8();
extern int FUN_a00a6c00();

void FUN_a00ad09c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  unsigned char uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00a6bb8(param_1,0x44);
  FUN_a00a6c00(param_1,0x44,uVar1 & 0xff | 3,param_4,param_5,param_6);
  return;
}