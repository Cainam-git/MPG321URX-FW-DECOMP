/* leon2s FUN_a0083fb8 @ 0xa0083fb8 (-mcpu=v8 -Os -g)
 * j = FUN_a0083ed0(p1 & 0xff) & 0xff; a fixed sequence of 61 FUN_a00a7718(j, r, mask, bit) and FUN_a00a7614(j, r,
 * value) calls, from FUN_a00a7718(j, 0x433, 0x10, 0) to FUN_a00a7614(j, 0x4af, 0xfd).
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
extern int FUN_a0083ed0();
extern void FUN_a00a7614();
extern void FUN_a00a7718();

void FUN_a0083fb8(unsigned char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  param_1 = param_1 & 0xff;
  param_1 = FUN_a0083ed0(param_1) & 0xff;
  FUN_a00a7718(param_1,0x433,0x10,0);
  FUN_a00a7718(param_1,0x434,1,0);
  FUN_a00a7718(param_1,0x433,0x80,0);
  FUN_a00a7718(param_1,0x550,4,0);
  FUN_a00a7718(param_1,0x650,4,0);
  FUN_a00a7718(param_1,0x750,4,0);
  FUN_a00a7718(param_1,0x850,4,0);
  FUN_a00a7718(param_1,0x550,8,0);
  FUN_a00a7718(param_1,0x650,8,0);
  FUN_a00a7718(param_1,0x750,8,0);
  FUN_a00a7718(param_1,0x850,8,0);
  FUN_a00a7718(param_1,0x11b,0x80,0);
  FUN_a00a7718(param_1,0x19b,0x80,0);
  FUN_a00a7718(param_1,0x21b,0x80,0);
  FUN_a00a7718(param_1,0x29b,0x80,0);
  FUN_a00a7718(param_1,0x11b,0x40,0);
  FUN_a00a7718(param_1,0x19b,0x40,0);
  FUN_a00a7718(param_1,0x21b,0x40,0);
  FUN_a00a7718(param_1,0x29b,0x40,0);
  FUN_a00a7718(param_1,0x551,4,1);
  FUN_a00a7718(param_1,0x651,4,1);
  FUN_a00a7718(param_1,0x751,4,1);
  FUN_a00a7718(param_1,0x851,4,1);
  FUN_a00a7718(param_1,0x555,0x80,0);
  FUN_a00a7718(param_1,0x655,0x80,0);
  FUN_a00a7718(param_1,0x755,0x80,0);
  FUN_a00a7718(param_1,0x855,0x80,0);
  FUN_a00a7718(param_1,0x554,0x80,0);
  FUN_a00a7718(param_1,0x654,0x80,0);
  FUN_a00a7718(param_1,0x754,0x80,0);
  FUN_a00a7718(param_1,0x854,0x80,0);
  FUN_a00a7718(param_1,0x550,0x10,0);
  FUN_a00a7718(param_1,0x650,0x10,0);
  FUN_a00a7718(param_1,0x750,0x10,0);
  FUN_a00a7718(param_1,0x850,0x10,0);
  FUN_a00a7718(param_1,0x550,0x20,0);
  FUN_a00a7718(param_1,0x650,0x20,0);
  FUN_a00a7718(param_1,0x750,0x20,0);
  FUN_a00a7718(param_1,0x850,0x20,0);
  FUN_a00a7614(param_1,0x4d1,0xaa);
  FUN_a00a7614(param_1,1,0xef);
  FUN_a00a7614(param_1,0x404,0);
  FUN_a00a7718(param_1,0x403,0x80,0);
  FUN_a00a7718(param_1,0x403,1,1);
  FUN_a00a7718(param_1,0x403,2,1);
  FUN_a00a7718(param_1,0x403,4,1);
  FUN_a00a7718(param_1,0x403,8,1);
  FUN_a00a7718(param_1,0x403,0x10,1);
  FUN_a00a7614(param_1,0xaf,0x94);
  FUN_a00a7614(param_1,0x4a8,0xff);
  FUN_a00a7614(param_1,0x4a9,0xfd);
  FUN_a00a7614(param_1,0x4ab,2);
  FUN_a00a7614(param_1,0x4ac,2);
  FUN_a00a7614(param_1,0x4b1,2);
  FUN_a00a7614(param_1,0x4b1,0);
  FUN_a00a7614(param_1,0x4b2,2);
  FUN_a00a7614(param_1,0x4b2,0);
  FUN_a00a7614(param_1,0x4ae,0xfd);
  FUN_a00a7614(param_1,0x4af,0xfd,param_4,param_5,param_6);
  return;
}