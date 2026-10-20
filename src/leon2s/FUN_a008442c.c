/* leon2s FUN_a008442c @ 0xa008442c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical Ghidra C plus one fix: Ghidra lost that the first call's result replaces the
 * parameter (x = FUN_a0083ed0(x)). Still needs a real name, proper types and a description.
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
extern unsigned char FUN_a0083ed0();
extern void FUN_a00a7614();
extern void FUN_a00a7718();

void FUN_a008442c(unsigned char param_1)

{
  
  param_1 = FUN_a0083ed0(param_1 & 0xff) & 0xff;
  FUN_a00a7614(param_1,0x4ae,0xff);
  FUN_a00a7614(param_1,0x4af,0xff);
  FUN_a00a7718(param_1,0x433,0x10,1);
  FUN_a00a7718(param_1,0x434,1,1);
  FUN_a00a7718(param_1,0x433,0x80,1);
  FUN_a00a7718(param_1,0x550,4,1);
  FUN_a00a7718(param_1,0x650,4,1);
  FUN_a00a7718(param_1,0x750,4,1);
  FUN_a00a7718(param_1,0x850,4,1);
  FUN_a00a7718(param_1,0x550,8,0);
  FUN_a00a7718(param_1,0x650,8,0);
  FUN_a00a7718(param_1,0x750,8,0);
  FUN_a00a7718(param_1,0x850,8,0);
  FUN_a00a7718(param_1,0x11b,0x80,1);
  FUN_a00a7718(param_1,0x19b,0x80,1);
  FUN_a00a7718(param_1,0x21b,0x80,1);
  FUN_a00a7718(param_1,0x29b,0x80,1);
  FUN_a00a7718(param_1,0x11b,0x40,0);
  FUN_a00a7718(param_1,0x19b,0x40,0);
  FUN_a00a7718(param_1,0x21b,0x40,0);
  FUN_a00a7718(param_1,0x29b,0x40,0);
  FUN_a00a7718(param_1,0x551,4,0);
  FUN_a00a7718(param_1,0x651,4,0);
  FUN_a00a7718(param_1,0x751,4,0);
  FUN_a00a7718(param_1,0x851,4,0);
  FUN_a00a7718(param_1,0x555,0x80,1);
  FUN_a00a7718(param_1,0x655,0x80,1);
  FUN_a00a7718(param_1,0x755,0x80,1);
  FUN_a00a7718(param_1,0x855,0x80,1);
  FUN_a00a7718(param_1,0x554,0x80,0);
  FUN_a00a7718(param_1,0x654,0x80,0);
  FUN_a00a7718(param_1,0x754,0x80,0);
  FUN_a00a7718(param_1,0x854,0x80,0);
  FUN_a00a7718(param_1,0x550,0x10,1);
  FUN_a00a7718(param_1,0x650,0x10,1);
  FUN_a00a7718(param_1,0x750,0x10,1);
  FUN_a00a7718(param_1,0x850,0x10,1);
  FUN_a00a7718(param_1,0x550,0x20,0);
  FUN_a00a7718(param_1,0x650,0x20,0);
  FUN_a00a7718(param_1,0x750,0x20,0);
  FUN_a00a7718(param_1,0x850,0x20,0);
  FUN_a00a7614(param_1,0x4d1,0x55);
  FUN_a00a7718(param_1,1,0x10,1);
  FUN_a00a7718(param_1,1,8,0);
  FUN_a00a7718(param_1,1,4,0);
  FUN_a00a7718(param_1,1,2,0);
  FUN_a00a7718(param_1,1,1,0);
  FUN_a00a7718(param_1,0x404,1,0);
  FUN_a00a7718(param_1,0x404,2,0);
  FUN_a00a7718(param_1,0x404,4,0);
  FUN_a00a7718(param_1,0x404,8,0);
  FUN_a00a7718(param_1,0x404,0x10,0);
  FUN_a00a7718(param_1,0x404,0x20,1);
  FUN_a00a7718(param_1,0x403,1,0);
  FUN_a00a7718(param_1,0x403,2,0);
  FUN_a00a7718(param_1,0x403,4,0);
  FUN_a00a7718(param_1,0x403,8,0);
  FUN_a00a7718(param_1,0x403,0x10,0);
  FUN_a00a7718(param_1,0x403,0x80,1);
  return;
}