/* leon2s FUN_a00c8688 @ 0xa00c8688  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00c7bf8();
extern int FUN_a00c80f0();

void FUN_a00c8688(uint param_1,undefined4 param_2)

{
  FUN_a00c7bf8(param_1 & 0xff);
  FUN_a00c80f0(param_1 & 0xff,param_2,0x74,0x18,8);
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}