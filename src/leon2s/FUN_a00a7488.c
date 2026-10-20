/* leon2s FUN_a00a7488 @ 0xa00a7488  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00a72c0();
extern int FUN_a00a7314();

void FUN_a00a7488(uint param_1,undefined2 param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00a7314(param_1,param_2);
  FUN_a00a72c0(param_1,param_2,uVar1 & param_3 | param_4,param_4,param_5,param_6);
  return;
}