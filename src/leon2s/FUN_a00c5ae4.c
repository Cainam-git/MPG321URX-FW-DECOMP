/* leon2s FUN_a00c5ae4 @ 0xa00c5ae4  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical Ghidra C, finished by hand: int parameter cut to a byte where used; array of 16-byte records at 0xa807d5c8; returns nothing; Ghidra type names kept.
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
extern int FUN_a00ca130();
extern int func_0xa0fb6bb8();
extern void func_0xa0fb6c98();
extern int func_0xa0fb6f78();
extern int func_0xa0fb6fc0();
extern int func_0xa0fc1794();
extern unsigned int ARR_a807d5c8[][4];

void FUN_a00c5ae4(int param_1)

{
  unsigned short uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 - 4 & 0xff;
  uVar1 = func_0xa0fb6f78(uVar3,0x30);
  if ((uVar1 & 8) != 0) {
    func_0xa0fb6fc0(uVar3,0x30,8);
    func_0xa0fb6c98(uVar3,0x30,0x80,1);
    uVar1 = func_0xa0fb6bb8(uVar3,0x2a8);
    if ((uVar1 & 2) != 0) {
      func_0xa0fb6c98(uVar3,0x2a9,2,0);
      func_0xa0fb6c98(uVar3,0x226,4,1);
      func_0xa0fb6c98(uVar3,0x30,0x80,0);
      FUN_a00ca130(uVar3);
      func_0xa0fb6c98(uVar3,0x30,8,1);
      func_0xa0fb6c98(uVar3,0x30,0x80,1);
      func_0xa0fb6c98(uVar3,0x2a9,1,1);
      func_0xa0fb6c98(uVar3,0x30,0x80,0);
      func_0xa0fc1794(200);
    }
    func_0xa0fb6c98(uVar3,0x30,0x80,0);
    func_0xa0fb6c98(uVar3,0x30,0x40,1);
    ARR_a807d5c8[(unsigned char)param_1][0] |= 0x800000;
  }
}