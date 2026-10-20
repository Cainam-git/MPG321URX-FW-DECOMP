/* leon2s FUN_a008f4ec @ 0xa008f4ec (-mcpu=v8 -Os -g)
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
extern void FUN_a00a65c4();
extern int FUN_a00a67b8();

void FUN_a008f4ec(undefined1 param_1)

{
  
  FUN_a00a65c4(param_1,0x341,0);
  FUN_a00a65c4(param_1,0x342,0x40);
  FUN_a00a65c4(param_1,0x343,0);
  FUN_a00a67b8(param_1,0x340,7,1);
  FUN_a00a67b8(param_1,0x340,6,0);
  return;
}