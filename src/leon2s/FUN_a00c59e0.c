/* leon2s FUN_a00c59e0 @ 0xa00c59e0  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void func_0xa0fb7dd0();
extern void func_0xa0fb7e14();
extern int func_0xa0fb7e98();
extern byte ARR_a807d5c8[];

void FUN_a00c59e0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_1 & 0xff;
  uVar1 = func_0xa0fb7e98(uVar3,0x71);
  if ((uVar1 & 3) == 3) {
    uVar1 = func_0xa0fb7e98(uVar3,0x2e);
    param_2 = 0x71;
    if ((uVar1 & 0x40) == 0) {
      uVar2 = 0x71;
      return func_0xa0fb7dd0(uVar3,0x71,3,param_4,param_5,param_6);
    }
    func_0xa0fb7dd0(uVar3,0x71,3);
    func_0xa0fb7e14(uVar3,0x37,4,0);
    func_0xa0fb7e14(uVar3,0x88,0x40,1);
    func_0xa0fb7e14(uVar3,0x37,1,1);
    do {
      uVar1 = func_0xa0fb7e98(uVar3,0x37);
    } while ((uVar1 & 1) == 0);
    func_0xa0fb7e14(uVar3,0x88,0x40,0);
    uVar1 = func_0xa0fb7e98(uVar3,0x71);
    if ((uVar1 & 3) != 3) {
      func_0xa0fb7e14(uVar3,0x2e,0x28,1);
      *(uint *)(uVar3 * 0x10 + (int)ARR_a807d5c8) = *(uint *)(uVar3 * 0x10 + (int)ARR_a807d5c8) | 0x800000;
    }
  }
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}