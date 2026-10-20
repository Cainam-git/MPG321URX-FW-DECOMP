/* leon2m FUN_a014a388 @ 0xa014a388  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
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
extern int FUN_a011a848();
extern void FUN_a011acac();
extern int FUN_a011adc8();
extern int func_0x4008e6e4();

void FUN_a014a388(uint param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0xff;
  FUN_a011acac(uVar2,0);
  FUN_a011adc8(0xff,0);
  bVar1 = 0;
  do {
    func_0x4008e6e4(bVar1,0);
    FUN_a011a848(uVar2,0);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  FUN_a011acac(uVar2,1);
  FUN_a011adc8(0xff,1);
  bVar1 = 0;
  do {
    func_0x4008e6e4(bVar1,1);
    FUN_a011a848(uVar2,1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}