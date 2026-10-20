/* leon2s FUN_a00c0b48 @ 0xa00c0b48  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00c7d5c();
extern int func_0xa0fb7fd8();
extern void func_0xa0fb8054();

void FUN_a00c0b48(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, int param_5,undefined4 param_6)

{
  unsigned char uVar1;
  
  FUN_a00c7d5c(0,param_1,param_2);
  FUN_a00c7d5c(1,param_1,param_2);
  uVar1 = func_0xa0fb7fd8(0,0,0xfa);
  func_0xa0fb8054(0,0,0xfa,uVar1 & 0xdf);
  uVar1 = func_0xa0fb7fd8(0,0,0xfa);
  func_0xa0fb8054(0,0,0xfa,uVar1 & 0xff | 0x20);
  uVar1 = func_0xa0fb7fd8(1,0,0xfa);
  func_0xa0fb8054(1,0,0xfa,uVar1 & 0xdf);
  uVar1 = func_0xa0fb7fd8(1,0,0xfa);
  func_0xa0fb8054(1,0,0xfa,uVar1 & 0xff | 0x20,param_5,param_6);
  return;
}