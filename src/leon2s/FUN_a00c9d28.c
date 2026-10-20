/* leon2s FUN_a00c9d28 @ 0xa00c9d28  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Block READ through a port's indirect register
 * window (func_0xa0fb7ee0 = write, func_0xa0fb7fa0 = read): selects bank param_3 by writing
 * param_3*0x11 to register 4, strobes register 5 (0x80 then 0), does a dummy read of register
 * 7, then reads param_4/16 16-bit words as byte pairs (register 6 = high, register 7 = low)
 * into buffer param_2, filling it from the end. Counterpart of FUN_a00c99a4 (block write).
 * Still needs a real name and proper types.
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
extern void func_0xa0fb7ee0();
extern int func_0xa0fb7fa0();

int FUN_a00c9d28(uint param_1,int param_2, unsigned char param_3, unsigned short param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  unsigned short uVar5;
  
  uVar4 = param_1 & 0xff;
  func_0xa0fb7ee0(uVar4,4,(unsigned char)(param_3 * 0x11));
  func_0xa0fb7ee0(uVar4,5,0x80);
  func_0xa0fb7ee0(uVar4,5,0);
  func_0xa0fb7fa0(uVar4,7);
  uVar5 = 0;
  if ((param_4 & 0xffff) >> 4 != 0) {
    do {
      uVar3 = (param_4 & 0xffff) >> 4;
      uVar1 = func_0xa0fb7fa0(uVar4,6);
      iVar2 = (uVar3 - (uVar5 & 0xffff)) * 2 + param_2;
      *(undefined1 *)(iVar2 + -1) = uVar1;
      uVar1 = func_0xa0fb7fa0(uVar4,7);
      uVar5 = uVar5 + 1;
      *(undefined1 *)(iVar2 + -2) = uVar1;
    } while ((uVar5 & 0xffff) < uVar3);
  }
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}