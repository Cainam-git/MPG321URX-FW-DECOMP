/* leon2s FUN_a0073680 @ 0xa0073680  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a00a7424();

void FUN_a0073680(undefined1 param_1)

{
  
  FUN_a00a7424(1,0x10,param_1,0x3024);
  FUN_a00a7424(0,0x10,param_1,0x3004);
  FUN_a00a7424(1,8,param_1,0x3034);
  FUN_a00a7424(0,8,param_1,0x3014);
  FUN_a00a7424(1,0x1e,param_1,0x3018);
  FUN_a00a7424(0,0x1d,param_1,0x3018);
  return;
}