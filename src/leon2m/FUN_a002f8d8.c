/* leon2m FUN_a002f8d8 @ 0xa002f8d8  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
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
extern unsigned char DAT_a802e403;
extern int FUN_a002992c();
extern int func_0x0007e65c();
extern int func_0x0007f170();
extern int func_0x000bd194();
extern int func_0x000c4f08();
extern int func_0x000c4f44();
extern int func_0x000c5c8c();
extern int func_0x000d3e10();
extern int func_0x000d6384();
extern int func_0x000d6600();
extern int func_0x000d86e4();
extern int func_0x000d874c();
extern int func_0x000d96d8();
extern int func_0x000e0a0c();
extern int func_0x000e512c();

void FUN_a002f8d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  func_0x0007f170(0x1a6e38);
  FUN_a002992c(1);
  func_0x000c4f44();
  func_0x000e512c(0,1);
  func_0x000c4f08();
  func_0x000c5c8c();
  func_0x000d86e4();
  func_0x000d96d8();
  func_0x000e0a0c();
  func_0x000d6600(DAT_a802e403);
  func_0x000d6384();
  func_0x000d874c();
  func_0x000bd194();
  FUN_a002992c(0);
  func_0x0007e65c();
  func_0x000d3e10(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}