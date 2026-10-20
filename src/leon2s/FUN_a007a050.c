/* leon2s FUN_a007a050 @ 0xa007a050 (-mcpu=v8 -Os -g)
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
extern int FUN_a00b160c();

void FUN_a007a050(undefined1 param_1)

{
  
  FUN_a00a7424(1,0x14,param_1,0x2e60);
  FUN_a00a7424(1,0x10,param_1,0x2e60);
  FUN_a00b160c(100);
  FUN_a00a7424(0,0x10,param_1,0x2e60);
  return;
}