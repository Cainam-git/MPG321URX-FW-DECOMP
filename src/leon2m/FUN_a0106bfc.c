/* leon2m FUN_a0106bfc @ 0xa0106bfc (-mcpu=v8 -O3 -g)
 * k = p1 & 0xff. When bits 0-1 of FUN_a00f2254(k, 0x54) are neither 2 nor 3 (two reads): for k < 4 calls
 * FUN_a00f2298(k, 0x6b, p2 & 0xff), FUN_a00f2298(k, 0x6c, p3), FUN_a00f2298(k, 0x6d, p4), func_0x4008e3c4(k, 1),
 * FUN_a0118a28(k, 1), FUN_a00f2298(k, 0x54, 2) and FUN_a0106920(k, 0); for k == 0 also FUN_a01023f4(0) and
 * FUN_a01026e8(0, v), (1, v >> 1), (2, v >> 1), (3, v >> 2) with v = (word +0x34 / 10) * halfword +0x22 of the
 * record whose address is in word 0xA802D6A4. Finally writes 0x40 to register 0xCF011658.
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
extern unsigned int _DAT_a802d6a4;
#define _DAT_cf011658 (*(volatile unsigned int *)0xcf011658)
extern int FUN_a00f2254();
extern void FUN_a00f2298();
extern int FUN_a01023f4();
extern void FUN_a01026e8();
extern int FUN_a0106920();
extern void FUN_a0118a28();
extern void func_0x4008e3c4();

void FUN_a0106bfc(uint param_1,uint param_2,undefined1 param_3,undefined1 param_4)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00f2254(param_1,0x54);
  if ((uVar1 & 3) != 2) {
    uVar1 = FUN_a00f2254(param_1,0x54);
    if ((uVar1 & 3) != 3) {
      if (param_1 < 4) {
        FUN_a00f2298(param_1,0x6b,param_2 & 0xff);
        FUN_a00f2298(param_1,0x6c,param_3);
        FUN_a00f2298(param_1,0x6d,param_4);
        func_0x4008e3c4(param_1,1);
        FUN_a0118a28(param_1,1);
        FUN_a00f2298(param_1,0x54,2);
        FUN_a0106920(param_1,0);
      }
      if (param_1 == 0) {
        param_2 = 0xa802d400;
        FUN_a01023f4(0);
        param_1 = 0xcccccc00;
        uVar1 = (*(uint *)(_DAT_a802d6a4 + 0x34) / 10) * (uint)*(ushort *)(_DAT_a802d6a4 + 0x22);
        FUN_a01026e8(0,uVar1);
        FUN_a01026e8(1,uVar1 >> 1);
        FUN_a01026e8(2,uVar1 >> 1);
        FUN_a01026e8(3,uVar1 >> 2);
      }
    }
  }
  _DAT_cf011658 = 0x40;
  return CONCAT44(param_2,param_1);
}