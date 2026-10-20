/* leon2m FUN_a00874c8 @ 0xa00874c8  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
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
extern int FUN_a014bac4();

void FUN_a00874c8(unsigned char param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  if ((param_1 & 1) != 0) {
    FUN_a014bac4(4,param_2 & 0xff);
  }
  if ((param_1 & 2) != 0) {
    FUN_a014bac4(5,param_2 & 0xff);
  }
  if ((param_1 & 4) != 0) {
    FUN_a014bac4(6,param_2 & 0xff);
  }
  if ((param_1 & 8) != 0) {
    FUN_a014bac4(7,param_2 & 0xff);
  }
  if ((param_1 & 0x10) != 0) {
    FUN_a014bac4(8,param_2 & 0xff);
  }
  if ((param_1 & 0x20) != 0) {
    FUN_a014bac4(9,param_2 & 0xff);
  }
  if ((param_1 & 0x40) != 0) {
    FUN_a014bac4(10,param_2 & 0xff);
  }
  if ((param_1 & 0x80) != 0) {
    param_2 = param_2 & 0xff;
    uVar1 = 0xb;
    return FUN_a014bac4(0xb,param_2,param_3,param_4,param_5,param_6);
  }
  return CONCAT44(param_2,param_1) & 0xffffffffff;
}