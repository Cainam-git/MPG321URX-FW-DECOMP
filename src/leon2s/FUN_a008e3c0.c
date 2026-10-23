/* leon2s FUN_a008e3c0 @ 0xa008e3c0 (-mcpu=v8 -Os -g)
 * k = p1 & 0xff, s = (p2 & 0xff). Read-modify-writes through FUN_a00a7fd8(k, 1, r) / FUN_a00a8054(k, 1, r, ...): r
 * = 0x7c gets (v & 0xCF) | s << 4; r = 0x9a gets (v & ~3) | p2, then (v & ~8) | s << 2, then (v & 0xCF) | s << 4
 * (each masked to 8 bits).
 * Source form: Ghidra's type and symbol names are kept.
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
extern int FUN_a00a7fd8();
extern void FUN_a00a8054();

void FUN_a008e3c0(unsigned char param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00a7fd8(param_1,1,0x7c);
  uVar2 = (param_2 & 0xff) << 4;
  FUN_a00a8054(param_1,1,0x7c,(uVar1 & 0xffffffcf | uVar2) & 0xff);
  uVar1 = FUN_a00a7fd8(param_1,1,0x9a);
  FUN_a00a8054(param_1,1,0x9a,(param_2 | uVar1 & 0xfffffffc) & 0xff);
  uVar1 = FUN_a00a7fd8(param_1,1,0x9a);
  FUN_a00a8054(param_1,1,0x9a,(uVar1 & 0xfffffff7 | (param_2 & 0xff) << 2) & 0xff);
  uVar1 = FUN_a00a7fd8(param_1,1,0x9a);
  FUN_a00a8054(param_1,1,0x9a,(uVar1 & 0xffffffcf | uVar2) & 0xff,param_5,param_6);
  return;
}