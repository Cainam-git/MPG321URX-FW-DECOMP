/* leon2s FUN_a00848cc @ 0xa00848cc (-mcpu=v8 -Os -g)
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
extern int FUN_a0083ed0();
extern void FUN_a00a6c00();
extern void FUN_a00a6c98();
extern void FUN_a00a7614();
extern int FUN_a00b1794();

void FUN_a00848cc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a0083ed0(param_1);
  FUN_a00a6c00(param_1,0x21d,0x84);
  uVar1 = uVar1 & 0xff;
  FUN_a00a7614(uVar1,0x10c,0xc0);
  FUN_a00a7614(uVar1,0x18c,0xc0);
  FUN_a00a7614(uVar1,0x20c,0xc0);
  FUN_a00a7614(uVar1,0x28c,0xc0);
  FUN_a00a7614(uVar1,0x10b,0xc0);
  FUN_a00a7614(uVar1,0x18b,0xc0);
  FUN_a00a7614(uVar1,0x20b,0xc0);
  FUN_a00a7614(uVar1,0x28b,0xc0);
  FUN_a00a7614(uVar1,0x126,0x70);
  FUN_a00a7614(uVar1,0x1a6,0x70);
  FUN_a00a7614(uVar1,0x226,0x70);
  FUN_a00a7614(uVar1,0x2a6,0x70);
  FUN_a00a7614(uVar1,0x114,0x5b);
  FUN_a00a7614(uVar1,0x194,0x5b);
  FUN_a00a7614(uVar1,0x214,0x5b);
  FUN_a00a7614(uVar1,0x294,0x5b);
  FUN_a00a7614(uVar1,0x558,0xa0);
  FUN_a00a7614(uVar1,0x658,0xa0);
  FUN_a00a7614(uVar1,0x758,0xa0);
  FUN_a00a7614(uVar1,0x858,0xa0);
  FUN_a00a7614(uVar1,0x559,0x10);
  FUN_a00a7614(uVar1,0x659,0x10);
  FUN_a00a7614(uVar1,0x759,0x10);
  FUN_a00a7614(uVar1,0x859,0x10);
  FUN_a00a6c98(param_1,0xc0,0x80,0);
  FUN_a00a7614(uVar1,0x403,0x80);
  FUN_a00a6c98(param_1,0xc0,0x80,1);
  FUN_a00b1794(5);
  FUN_a00a6c98(param_1,0xc0,0x80,0);
  FUN_a00a7614(uVar1,0x403,0x80);
  FUN_a00a6c98(param_1,0xc0,0x80,1);
  FUN_a00b1794(5);
  FUN_a00a7614(uVar1,0x10c,0);
  FUN_a00a7614(uVar1,0x18c,0);
  FUN_a00a7614(uVar1,0x20c,0);
  FUN_a00a7614(uVar1,0x28c,0);
  FUN_a00a7614(uVar1,0x10b,0);
  FUN_a00a7614(uVar1,0x18b,0);
  FUN_a00a7614(uVar1,0x20b,0);
  FUN_a00a7614(uVar1,0x28b,0);
  FUN_a00a7614(uVar1,0x126,0x30);
  FUN_a00a7614(uVar1,0x1a6,0x30);
  FUN_a00a7614(uVar1,0x226,0x30);
  FUN_a00a7614(uVar1,0x2a6,0x30);
  FUN_a00a7614(uVar1,0x114,0x1b);
  FUN_a00a7614(uVar1,0x194,0x1b);
  FUN_a00a7614(uVar1,0x214,0x1b);
  FUN_a00a7614(uVar1,0x294,0x1b);
  FUN_a00a7614(uVar1,0x558,0x20);
  FUN_a00a7614(uVar1,0x658,0x20);
  FUN_a00a7614(uVar1,0x758,0x20);
  FUN_a00a7614(uVar1,0x858,0x20);
  FUN_a00a7614(uVar1,0x559,0x10);
  FUN_a00a7614(uVar1,0x659,0x10);
  FUN_a00a7614(uVar1,0x759,0x10);
  FUN_a00a7614(uVar1,0x859,0x10,param_4,param_5,param_6);
  return;
}