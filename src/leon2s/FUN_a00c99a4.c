/* leon2s FUN_a00c99a4 @ 0xa00c99a4  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Block WRITE through a port's indirect register
 * window (func_0xa0fb7ee0 = register write): selects bank param_3 by writing param_3*0x11 to
 * register 4, strobes register 5 (0x80 then 0); unless param_4 is set, writes param_5/16
 * 16-bit words from buffer param_2 as byte pairs (register 6 = high, register 7 = low),
 * walking the buffer from the end. Counterpart of FUN_a00c9d28 (block read).
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

void FUN_a00c99a4(uint param_1,undefined1 *param_2, unsigned char param_3, unsigned char param_4, unsigned short param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  unsigned char uVar4;
  
  uVar3 = param_1 & 0xff;
  func_0xa0fb7ee0(uVar3,4,(unsigned char)(param_3 * 0x11));
  func_0xa0fb7ee0(uVar3,5,0x80);
  func_0xa0fb7ee0(uVar3,5,0);
  if (param_4 == '\0') {
    for (uVar4 = 0; (uVar4 & 0xff) < (uint)((param_5 & 0xffff) >> 4); uVar4 = uVar4 + 1) {
        uVar1 = (param_5 & 0xffff) >> 4;
        iVar2 = uVar1 - (uVar4 & 0xff);
        func_0xa0fb7ee0(uVar3,6,param_2[iVar2 * 2 + -1]);
        func_0xa0fb7ee0(uVar3,7,param_2[iVar2 * 2 + -2]);
    }
  }
  else if (param_4 == '\x03') {
    func_0xa0fb7ee0(uVar3,6,param_2[2]);
    func_0xa0fb7ee0(uVar3,7,param_2[1]);
    func_0xa0fb7ee0(uVar3,6,*param_2);
    func_0xa0fb7ee0(uVar3,7,0);
    uVar4 = 2;
    if (2 < (param_5 & 0xffff) >> 4) {
      do {
        func_0xa0fb7ee0(uVar3,6,0);
        func_0xa0fb7ee0(uVar3,7,0);
        uVar4 = uVar4 + 1;
      } while ((uVar4 & 0xff) < (param_5 & 0xffff) >> 4);
    }
  }
  else if ((param_4 == '\x04') && (uVar4 = 0, (param_5 & 0xffff) >> 4 != 0)) {
    do {
      func_0xa0fb7ee0(uVar3,6,0);
      func_0xa0fb7ee0(uVar3,7,0);
      uVar4 = uVar4 + 1;
    } while ((uVar4 & 0xff) < (param_5 & 0xffff) >> 4);
  }
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}