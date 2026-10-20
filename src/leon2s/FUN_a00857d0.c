/* leon2s FUN_a00857d0 @ 0xa00857d0  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a0083ed0();
extern void FUN_a00a7718();

void FUN_a00857d0(unsigned char param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  param_1 = param_1 & 0xff;
  param_1 = FUN_a0083ed0(param_1) & 0xff;
  FUN_a00a7718(param_1,0x551,4,param_2);
  FUN_a00a7718(param_1,0x651,4,param_2);
  FUN_a00a7718(param_1,0x751,4,param_2);
  FUN_a00a7718(param_1,0x851,4,param_2,param_5,param_6);
  return;
}