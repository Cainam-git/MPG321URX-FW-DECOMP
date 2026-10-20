/* leon2m FUN_a00b0a90 @ 0xa00b0a90  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
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
extern unsigned char DAT_a802d43a;
extern int FUN_a00b0710();
extern void FUN_a00b32e4();

void FUN_a00b0a90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00b32e4(1,1,0x8a2,0,0,1,1);
  FUN_a00b32e4(1,1,0x8a2,0x27,10,1,4);
  FUN_a00b32e4(1,0,0x8a2,1,0,7,5);
  FUN_a00b32e4(1,0,0x8a2,5,10,0x22,6);
  FUN_a00b32e4(0,0,0x8a2,0,1,8,7);
  FUN_a00b32e4(0,0,0x8a2,0x27,3,7,8);
  FUN_a00b32e4(1,1,0x12aa,6,0,1,0x72);
  FUN_a00b32e4(1,1,0xa89a,0x20,1,1,0x73);
  FUN_a00b32e4(1,1,0xa89a,1,8,1,0x74);
  FUN_a00b32e4(1,1,0x592,3,1,2,0x26);
  FUN_a00b32e4(1,1,0x592,0x1f,1,1,0x28);
  FUN_a00b32e4(1,1,0x592,0x22,1,1,0x29);
  FUN_a00b32e4(1,1,0x592,6,9,1,0x2a);
  FUN_a00b32e4(1,1,0x592,0x24,9,1,0x2b);
  FUN_a00b32e4(1,1,0x592,0x25,8,2,0x2c);
  FUN_a00b32e4(1,1,0x592,0x25,9,2,0x2e);
  FUN_a00b32e4(1,1,0x9aae,8,0,0x18,0x20);
  FUN_a00b32e4(1,1,0x9aaa,0x20,0,4,0x75);
  FUN_a00b32e4(1,1,0x9aaa,0x21,1,1,0x79);
  FUN_a00b32e4(1,1,0xa29a,0x24,0,3,0x7a);
  FUN_a00b32e4(1,1,0xaaaa,0x27,0,1,0x7d);
  FUN_a00b32e4(1,1,0x9aaa,0x23,1,5,0x7e);
  FUN_a00b32e4(1,1,0x9aaa,0x23,2,5,0x83);
  FUN_a00b32e4(1,1,0x9faa,0,9,1,0x8e);
  FUN_a00b32e4(1,1,0x9faa,2,9,2,0x8f);
  FUN_a00b32e4(1,1,0x9faa,0,10,5,0x91);
  FUN_a00b32e4(1,1,0x3392,2,8,2,0x30);
  FUN_a00b32e4(1,1,0x3392,1,9,1,0x32);
  FUN_a00b32e4(1,1,0x3092,4,8,3,0x33);
  FUN_a00b32e4(1,1,0x3092,4,9,2,0x36);
  FUN_a00b0710(0,DAT_a802d43a,param_3,param_4,param_5,param_6);
  return;
}