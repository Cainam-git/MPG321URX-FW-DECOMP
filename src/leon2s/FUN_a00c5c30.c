/* leon2s FUN_a00c5c30 @ 0xa00c5c30 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. per-port register fix-up. Reads register 0x2e
 * of the port (func_0xa0fb7e98 = register read); only acts when bit 5 is set. Ports 0-1: if
 * register 0x21f bit 1 is set, or register 6 bit 1 is clear, pulse bit 1 of register 0x30
 * (set, then clear) and clear bit 5 of 0x2e (func_0xa0fb7e14 = masked write). Ports 2+: same
 * test on register 0x42, then clear bit 1 of 0x42 and rewrite 0x2e with bit 3 set and bit 5
 * cleared (func_0xa0fb7dd0 = plain write). Ghidra had lost two register reads.
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
#define CONCAT11(a, b) ((unsigned short)(((unsigned)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT13(a, b) (((unsigned)(a) << 24) | ((unsigned)(b) & 0xffffff))
#define CONCAT21(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define CONCAT22(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define SUB41(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define SUB42(x, c) ((unsigned short)((unsigned)(x) >> ((c) * 8)))
#define SUB43(x, c) (((unsigned)(x) >> ((c) * 8)) & 0xffffff)
#define SUB21(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define ZEXT14(x) ((unsigned)(unsigned char)(x))
#define ZEXT24(x) ((unsigned)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define SEXT14(x) ((int)(signed char)(x))
#define SEXT24(x) ((int)(short)(x))
#define SEXT12(x) ((short)(signed char)(x))
extern int func_0xa0fb7dd0();
extern void func_0xa0fb7e14();
extern int func_0xa0fb7e98();

void FUN_a00c5c30(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  unsigned char uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_1 & 0xff;
  uVar1 = func_0xa0fb7e98(uVar3,0x2e);
  if ((uVar1 & 0x20) != 0) {
    if (uVar3 < 2) {
      param_2 = 0x2e;
      uVar1 = func_0xa0fb7e98(uVar3,0x21f);
      if (((uVar1 & 2) != 0) || (uVar1 = func_0xa0fb7e98(uVar3,6), (uVar1 & 2) == 0)) {
        func_0xa0fb7e14(uVar3,0x30,2,1);
        func_0xa0fb7e14(uVar3,0x30,2,0);
        uVar2 = 0x2e;
        return func_0xa0fb7e14(uVar3,0x2e,0x20,0,param_5,param_6);
      }
    }
    else {
      uVar1 = func_0xa0fb7e98(uVar3,0x42);
      param_2 = 0x2e;
      if (((uVar1 & 2) != 0) ||
         (uVar1 = func_0xa0fb7e98(uVar3,6), (uVar1 & 2) == 0)) {
        func_0xa0fb7e14(uVar3,0x42,2,0);
        uVar1 = func_0xa0fb7e98(uVar3,0x2e);
        uVar2 = 0x2e;
        return func_0xa0fb7dd0(uVar3,0x2e,(uVar1 | 8) & 0xdf,param_4,param_5,param_6);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}