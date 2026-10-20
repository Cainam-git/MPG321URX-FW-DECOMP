/* leon2s FUN_a00b1e30 @ 0xa00b1e30 (-mcpu=v8 -Os -g)
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
extern void FUN_a00a832c();
extern int FUN_a00b1794();

void FUN_a00b1e30(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a832c(param_1,3,3);
  FUN_a00a832c(param_1,3,7);
  FUN_a00b1794(1);
  FUN_a00a832c(param_1,3,3,param_4,param_5,param_6);
  return;
}